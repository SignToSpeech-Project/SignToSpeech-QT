#include <algorithm>
#include "HandTools.h"
#include "Debugger.h"


HandTools::HandTools(ThreadLearningHandTools * h) {
	tLHT = h;
}
/** Calculate the time diffence between two times **/
int diffMilliseconds(SYSTEMTIME t1, SYSTEMTIME t2) {
	return ((t2.wMinute * 60000 + t2.wSecond * 1000 + t2.wMilliseconds) - (t1.wMinute * 60000 + t1.wSecond * 1000 + t1.wMilliseconds));
}

/** Print in binary an integer **/
void HandTools::printBinary(uint32_t a, int nbBits) {
	for (int b = nbBits; b >= 0; b--) {
		printf("%d", (a >> b) & 0x1);
	}
}

/** Calculate the Hamming distance between two numbers   **/
/** on nBit with a different step						 **/
/** If the step is 2, it will check if each set of 2bits **/
/** are differents										 **/
int HandTools::calculateHammingDistance(uint32_t a, uint32_t b, int nBit, int step) {
	int dist = 0;
	uint32_t one = 0x0;
	for (int i = 0; i < step; i++) {
		one = one << 1 | 0b1;
	}
	for (int i = 0; i < nBit / step; i++) {
		if (((a >> (step * i)) & one) != ((b >> (step * i)) & one)) {
			dist++;
		}
	}
	return dist;
}

vector<uint32_t> HandTools::removeOutValues(vector<uint32_t> v) {
	//Median 
	std::sort(v.begin(), v.end());
	int t = v.size();
	float median;
	if ((t % 2) == 0) {
		int rank1 = (t / 2) - 1;
		int rank2 = t / 2;
		median = (v.at(rank1) + v.at(rank2)) / 2.0;
	}
	else {
		int rank = t / 2;
		median = v.at(rank);
	}

	//quartet1 and quartet3
	float quartile1;
	if ((t % 4) == 0) {
		int rank1 = (t / 4.0) - 1.0;
		int rank2 = t / 4.0;
		quartile1 = (v.at(rank1) + v.at(rank2)) / 2.0;
	}
	else {
		int rank = t / 4.0;
		quartile1 = v.at(rank);
	}

	float quartile3;
	if ((t % 4) == 0) {
		int rank1 = (12 / (4.0 / 3.0)) - 1;
		int rank2 = 12 / (4.0 / 3.0);
		quartile3 = (v.at(rank1) + v.at(rank2)) / 2.0;
	}
	else {
		int rank = t / (4.0 / 3.0);
		quartile3 = v.at(rank);
	}

	//Interquartile range
	float  interquartileRange = quartile3 - quartile1;

	//inner fences
	float innerFenceMin = quartile1 - 1.5 * interquartileRange;
	float innerFenceSup = quartile3 + 1.5 * interquartileRange;

	//outer fences
	float outerFenceMin = quartile1 - 3 * interquartileRange;
	float outerFenceSup = quartile3 + 3 * interquartileRange;

	vector<uint32_t> result;

	//removing strange values : use outerFence or innerFence, your wish. At this time we use outer fences
	for (vector<uint32_t>::iterator it = v.begin(); it != v.end(); ++it)
	{
		if ((outerFenceMin <= (*it)) && ((*it) <= outerFenceSup))	result.push_back((*it));
	}

	return result;
}

/** Convert a hand to an encoded representation based on our encoding **/
uint32_t handToInt(PXCHandData::IHand *hand) {
	PXCHandData::FingerData fingerData;
	uint32_t avg = 0x0;
	for (int f = 0; f < 5; f++) {
		if (hand->QueryFingerData((PXCHandData::FingerType)f, fingerData) == PXC_STATUS_NO_ERROR) {
			if (fingerData.foldedness < 50) {
				if (fingerData.foldedness < 25) {
					avg |= (0b00 << (2 * f));
				}
				else {
					avg |= (0b01 << (2 * f));
				}
			}
			else if (fingerData.foldedness >= 50) {
				if (fingerData.foldedness < 75) {
					avg |= (0b10 << (2 * f));
				}
				else {
					avg |= (0b11 << (2 * f));
				}
			}
		}
	}
	return avg;
}

/** Calculate an average of a set of frames, on length **/
uint32_t HandTools::calculateAverage(PXCHandData::FingerData handData[1000][5], int length) {
	uint32_t avg = 0x0;

	// calculate the gesture average
	for (int f = 0; f < 5; f++) {
		uint32_t sumFold = 0;
		vector<uint32_t> v;
		for (int i = 0; i < length; i++) {
			v.push_back(handData[i][f].foldedness);
		}

		vector<uint32_t> vResult = this->removeOutValues(v);
		if (vResult.size() == 0) vResult = v;
		for (vector<uint32_t>::iterator it = vResult.begin(); it != vResult.end(); ++it) {
			sumFold += (*it);
		}
		sumFold /= vResult.size();

		// transform the foldedness into our encoding
		if (sumFold < 50) {
			if (sumFold < 25) {
				avg |= (0b00 << (2 * f));
			}
			else {
				avg |= (0b01 << (2 * f));
			}
		}
		else if (sumFold >= 50) {
			if (sumFold < 75) {
				avg |= (0b10 << (2 * f));
			}
			else {
				avg |= (0b11 << (2 * f));
			}
		}
	}
	return avg;
}

long HandTools::analyseGesture(PXCHandData::IHand *hand) {
	// increment frame number
	frameCounter++;

	PXCHandData::BodySideType side = hand->QueryBodySide();
	int *nbReadFrame;
	int *nbFrame;
	PXCHandData::FingerData(*handData)[5];
	string sideStr = "";
	switch (side) {
	case PXCHandData::BodySideType::BODY_SIDE_LEFT:
		nbReadFrame = &nbReadFrameLeft;
		nbFrame = &nbFrameLeft;
		handData = leftHandData;
		sideStr = "LEFT";
		break;
	case PXCHandData::BodySideType::BODY_SIDE_RIGHT:
		nbReadFrame = &nbReadFrameRight;
		nbFrame = &nbFrameRight;
		handData = rightHandData;
		sideStr = "RIGHT";
		break;
	default:
		nbReadFrame = &nbReadFrameRight;
		nbFrame = &nbFrameRight;
		handData = rightHandData;
		sideStr = "RIGHT";
		break;
	}

	bool writeAllowed = true;
	bool doAverage = false;

	if (*nbFrame == 0) {
		GetSystemTime(&gestureStart);
	}

	if (*nbFrame < MAXFRAME) {

		// empty the hand array if at least 250ms has passed
		SYSTEMTIME currentTime;
		GetSystemTime(&currentTime);
		if (diffMilliseconds(currentTime, gestureStart) >= 250) {
			GetSystemTime(&gestureStart);
			*nbReadFrame = 0;
			*nbFrame = 0;
		}

		// check if the previous set of frames is not too different from the new frame 
		// each 10 frames
		if ((*nbFrame) % 10 == 0 && (*nbFrame) != 0) {
			uint32_t avgTmp = calculateAverage(handData, *nbReadFrame);
			if (analyseMovement(massCenterCoordinates, *nbReadFrame) != analyseMovement(currentMassCenters, 9)) {
				if (*nbReadFrame > 40) {
					Debugger::debug("\t Gestures are differents - Only keep the previous gesture");
					writeAllowed = false;
					doAverage = true;
					(*nbReadFrame) -= 10;
					//(*nbFrame)++;
				}
			}
			if (writeAllowed && calculateHammingDistance(avgTmp, handToInt(hand), 10, 2) >= 4) {
				//if (*nbReadFrame < (MAXFRAME / 3)) {
				//	// remove all the previous gesture
				//	Debugger::debug("Remove the previous gesture");
				//	*nbReadFrame = 0;
				//	*nbFrame = 0;
				//}
				//else if (*nbReadFrame > 2*(MAXFRAME / 3)) {
					// we only keep the previous gesture

				if (*nbReadFrame > 40) {
					Debugger::debug("Only keep the previous gesture");
					writeAllowed = false;
					doAverage = true;
					//(*nbFrame)++;
				}
				//}
			}
		}

		if (writeAllowed) {
			// add a new entry into the table
			PXCHandData::FingerData fingerData;
			for (int f = 0; f < 5; f++) {
				if (hand->QueryFingerData((PXCHandData::FingerType)f, fingerData) == PXC_STATUS_NO_ERROR) {
					handData[*nbReadFrame][f] = fingerData;
				}
			}
			// add the coordinates of the mass center into the table
			massCenterCoordinates[*nbReadFrame] = hand->QueryMassCenterWorld();
			currentMassCenters[(*nbReadFrame)%10] = hand->QueryMassCenterWorld();
			(*nbReadFrame)++;
		}
		(*nbFrame)++;
	}
	if(*nbFrame >= MAXFRAME || doAverage) {

		Debugger::info("\t\t\tDo Average");

		uint32_t average = calculateAverage(handData, min(MAXFRAME, *nbReadFrame));
		uint8_t movement = analyseMovement(massCenterCoordinates, min(MAXFRAME, *nbReadFrame));
		average |= movement << 10;

		printf("[%ld]\t", frameCounter);
		printBinary(average, 17);
		printf("\n");

		*nbReadFrame = 0;
		*nbFrame = 0;
		return average;
	}
	return -1;
}


/***********************************************/
/* *************** Trajectories ************** */
/***********************************************/

uint8_t HandTools::analyseMovement(PXCPoint3DF32 massCenter[1000], int nbFrame) {

	// coordinates of the first point of the movement
	PXCPoint3DF32 p0 = massCenter[0];

	// coordinates of the middle point of the movement
	PXCPoint3DF32 pm = massCenter[(int)(nbFrame/2)];

	// coordinates of the last point of the movement
	PXCPoint3DF32 pf = massCenter[nbFrame - 1];

	uint8_t temp = 0b0 ;

	if (isStatic(massCenter, nbFrame, &temp)) {
		return temp;
	}
	else if (isStraight(p0, pm, pf, &temp)) {
		// do things with temp and symb
		return temp;
	}
	else if (isElliptic(massCenter, p0, pm, pf, &temp, nbFrame)) {
		// do things with temp and symb
		return temp;
	}
	return 0;
}

bool HandTools::isStatic(PXCPoint3DF32 massCenter[1000], int nbFrame, uint8_t *out) {
	int i;
	int cpt = 1;
	PXCPoint3DF32 p0 = massCenter[0];
	PXCPoint3DF32 p_current;

	for (i = 1; i < nbFrame; i++) {
		p_current = massCenter[i];
		if ((abs(p0.x - p_current.x) <= NBMETERS_STATIC) && (abs(p0.y - p_current.y) <= NBMETERS_STATIC)) {
			cpt++;
		}
		p0 = p_current;
	}
	//cout << cpt << endl;
	if (cpt > ((float)nbFrame)*0.92) {
		Debugger::debug("STATIQUE");
		return true;
	}
	else {
		return false;
	}
}

bool HandTools::isHorizontal(PXCPoint3DF32 p0, PXCPoint3DF32 pm, PXCPoint3DF32 pf) {
	if (/*(abs(p0.x - pf.x) > VALID_HOR) && */(abs(p0.y - pf.y) <= ERR_VERT)) {
		Debugger::debug("STRAIGHT HORIZONTAL");
		return true;
	}
	return false;
}

bool HandTools::isVertical(PXCPoint3DF32 p0, PXCPoint3DF32 pm, PXCPoint3DF32 pf) {
	if (/*(abs(p0.y - pf.y) > VALID_VER) && */(abs(p0.x - pf.x) <= ERR_HOR)) {
		Debugger::debug("STRAIGHT VERTICAL");
		return true;
	}
	return false;
}

bool HandTools::isStraight(PXCPoint3DF32 p0, PXCPoint3DF32 pm, PXCPoint3DF32 pf, uint8_t *out) {
	// y = ax + b ; a is the slope, b is the intercept
	float a, b;
	if ((pf.x - p0.x) == 0) {
		a = 0.0;
	}
	else {
		a = (pf.y - p0.y) / (pf.x - p0.x);
	}
	b = p0.y - a*p0.x;

	// does it respect the equation of a straight line & is it horizontal?
	if (abs(pm.y - (a*pm.x + b)) < ERR_STRAIGHT_HOR && isHorizontal(p0, pm, pf)) {
		// which direction: left or right?
		if (p0.x - pf.x > 0) {
			Debugger::debug("\tRIGHT");
			*out |= 0b1;
			/*printBinary(*out, 7);
			printf("\n");*/
			return true;
		}
		else {
			Debugger::debug("\tLEFT");
			*out |= (0b1 << 1);
			/*printBinary(*out, 7);
			printf("\n");*/
			return true;
		}
	}
	else if (abs(pm.y - (a*pm.x + b)) < ERR_STRAIGHT_VER && isVertical(p0, pm, pf)) {
		// which direction: top or bottom?
		if (p0.y - pf.y > 0) {
			Debugger::debug("\tBOTTOM");
			*out |= (0b1 << 3);
			/*printBinary(*out, 7);
			printf("\n");*/
			return true;
		}
		else {
			Debugger::debug("\tTOP");
			*out |= (0b1 << 2);
			/*printBinary(*out, 7);
			printf("\n");*/
			return true;
		}
	}
	// not horizontal nor vertical: it's a normal straight line!
	else if (abs(pm.y - (a*pm.x + b)) < ERR_STRAIGHT) {
		// if p0.y < pf.y -> to the top
		if (p0.y < pf.y) {
			*out |= (0b1 << 2);
			if (p0.x - pf.x > 0) {
				Debugger::debug("\tNORMAL TOP RIGHT");
				*out |= 0b1;
				/*printBinary(*out, 7);
				printf("\n");*/
				return true;
			}
			else {
				Debugger::debug("\tNORMAL TOP LEFT");
				*out |= (0b1 << 1);
				/*printBinary(*out, 7);
				printf("\n");*/
				return true;
			}
		}
		// if p0.y > pf.y -> to the bottom
		else if (p0.y > pf.y) {
			*out |= (0b1 << 3);
			if (p0.x - pf.x > 0) {
				Debugger::debug("\tNORMAL BOTTOM RIGHT");
				*out |= 0b1;
				/*printBinary(*out, 7);
				printf("\n");*/
				return true;
			}
			else {
				Debugger::debug("\tNORMAL BOTTOM LEFT");
				*out |= (0b1 << 1);
				/*printBinary(*out, 7);
				printf("\n");*/
				return true;
			}
		}
	} // end if "it respects the equation of a straight line"
	else {
		return false;
	}
}

bool HandTools::isElliptic(PXCPoint3DF32 massCenter[1000], PXCPoint3DF32 p0, PXCPoint3DF32 pm, PXCPoint3DF32 pf, uint8_t *out, int nbFrame) {
	// center coordinates pc(xc, yc)
	PXCPoint3DF32 pc;

	// NOT FULL ELLIPSE if the distance between first and last point > NBMETERS_FULLELLIPSE
	if (sqrt(pow(pf.x - p0.x, 2) + pow(pf.y - p0.y, 2)) > NBMETERS_FULLELLIPSE) {
		pc.x = (pf.x + p0.x) / 2.0;
		pc.y = (pf.y + p0.y) / 2.0;

		// a is the distance between pf(pf.x, pf.y) and pc(pc.x, pc.y)
		float a = sqrt(pow(pf.x - pc.x, 2) + pow(pf.x - pc.y, 2));
		// b is the distance between pm(pm.x, pm.y) and pc(pc.x, pc.y)
		float b = sqrt(pow(pm.x - pc.x, 2) + pow(pm.y - pc.y, 2));

		// chose 1 point, different from p0, pm and pf, to see if it respects the ellipse eq
		PXCPoint3DF32 p1 = massCenter[(int)(nbFrame / 3)];
		if ((abs(pow(p1.x - pc.x, 2) / (a*a) + pow(p1.y - pc.y, 2) / (b*b)) - 1) <= ERR_ELLIPSE) {
			Debugger::debug("NOT FULL ELLIPSE");
			*out |= (0b1 << 7);
			return true;
		}
		else {
			return false;
		}
	}

	// FULL ELLIPSE if distance between first and last point <= NBMETERS_FULLECLIPSE
	else if (sqrt(pow(pf.x - p0.x, 2) + pow(pf.y - p0.y, 2)) <= NBMETERS_FULLELLIPSE) {
		// pm is the point in the middle of the point list. Therefore, it is p0's symetrical to the center 
		pc.x = (pm.x + p0.x) / 2.0;
		pc.y = (pm.y + p0.y) / 2.0;

		// a is the distance between pf(pf.x, pf.y) and pc(pc.x, pc.y)
		float a = sqrt(pow(pf.x - pc.x, 2) + pow(pf.x - pc.y, 2));
		
		// pm2 is the point at the first quarter of the point list (the middle of the first half of the list)
		PXCPoint3DF32 pm2 = massCenter[(int)(nbFrame / 4)];

		// b is the distance between pm2(pm2.x, pm2.y) and pc(pc.x, pc.y)
		float b = sqrt(pow(pm2.x - pc.x, 2) + pow(pm2.y - pc.y, 2));

		// chose 2 points, different from p0, pm, pm2 and pf, to see if they respect the ellipse eq
		PXCPoint3DF32 p1 = massCenter[(int)(nbFrame / 3)];
		PXCPoint3DF32 p2 = massCenter[(int)(2*nbFrame / 3)];
		if ( ((abs(pow(p1.x - pc.x, 2) / (a*a) + pow(p1.y - pc.y, 2) / (b*b)) - 1) < ERR_ELLIPSE)
		&& ((abs(pow(p2.x - pc.x, 2) / (a*a) + pow(p2.y - pc.y, 2) / (b*b)) - 1) < ERR_ELLIPSE) ) {
			Debugger::debug("FULL ELLIPSE");
			*out |= (0b1 << 6);
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

/***********************************************/
/* ************ Automatic learning *********** */
/***********************************************/

long HandTools::analyseXGestures(PXCHandData::IHand* hand) {
	long avg;
	long readSymbol = -1;
	uint8_t trajectory;

	if (firstFrame == 0) start = time(0);
	
	// add a new entry into the table
	PXCHandData::FingerData fingerData;
	for (int f = 0; f < 5; f++) {
		if (hand->QueryFingerData((PXCHandData::FingerType)f, fingerData) == PXC_STATUS_NO_ERROR) {
			handData[nbFrame][f] = fingerData;
		}
	}
	// add the coordinates of the mass center into the table
	massCenterCoordinates[nbMassCenter] = hand->QueryMassCenterWorld();
	nbFrame++;
	nbMassCenter++;
	firstFrame = 1;


	if (difftime(time(0), start) >= 3.0) {
		trajectories.push_back(analyseMovement(massCenterCoordinates, nbMassCenter));
		nbGesture++;
		firstFrame = 0;
		nbMassCenter = 0;

		if (nbGesture < 3) {
			tLHT->pushMessage("----> Repeat the same gesture in 5 seconds... <----");
			for (int i = 5; i > 0; i--) {
				tLHT->pushMessage(to_string(i));
				Sleep(1000);
			}
			tLHT->pushMessage("----> NOW <----");
		}

		else {
			tLHT->pushMessage("----> Please wait... <----");

			// average of the vector composed of the 3 repeated gestures
			avg = calculateAverage(handData, nbFrame);
			trajectory = averageTrajectory(trajectories);
			readSymbol = avg | (trajectory << 10);
			nbGesture = 0;
			nbFrame = 0;
			trajectories.clear();
			currentGestComposee++;
			
			if (currentGestComposee == nbMotCompose) learning = false;
			
		}
	}
	return readSymbol;
}


uint8_t HandTools::averageTrajectory(vector<uint8_t> trajectories) {
	uint8_t t0 = trajectories.at(0);
	uint8_t t1 = trajectories.at(1);
	uint8_t t2 = trajectories.at(2);

	if (t0 == t1) {
		return t0;
	}
	if (t0 == t2) {
		return t0;
	}
	if (t1 == t2) {
		return t1;
	}

	// if the trajectories are all different, return the last one
	return t2;
}
