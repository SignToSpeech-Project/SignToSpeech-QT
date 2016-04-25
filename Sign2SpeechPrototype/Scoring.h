#pragma once
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Scoring {
public:

	//Return the amount of difference of the fingers between 2 symbols following the function : 10 * eg + 3 * em + es + nbdif;
	static int calculateScore(long s1, long s2) {
		int nbdif = 0; //Nb errors
		int eg = 0; //nb of major errors
		int em = 0; //nb of medium errors
		int es = 0; //nb of simple errors
		int fs1; //Finger x of s1
		int fs2; //finger x of s2
		int diffFingers;

		//Fingers difference
		for (int f = 0; f <= 4; f++) {
			fs1 = (s1 >> (2 * f)) & 0b11;
			fs2 = (s2 >> (2 * f)) & 0b11;
			diffFingers = abs(fs1 - fs2);
			if (diffFingers == 1) {
				es++;
				nbdif++;
			}
			else if (diffFingers == 2) {
				em++;
				nbdif++;
			}

			else if (diffFingers == 3) {
				eg++;
				nbdif++;
			}

		}

		int trajectorie1 = (s1 >> 11) & 0b11111111; //Trajectorie of s1
		int trajectorie2 = (s2 >> 11) & 0b11111111; //Trajectorie of s2

													//Checking if we have a static geasture
		if ((trajectorie1 == 0) || (trajectorie2 == 0)) {
			if (trajectorie1 != trajectorie2) {
				eg++;
				nbdif++;
			}
		}

		//Else, checking trajectories differences
		else {

			int t11 = (s1 >> 11) & 0b1; //Horizontal right bit
			int t21 = (s2 >> 11) & 0b1; //Horizontal right bit
			int t12 = (s1 >> 12) & 0b1; //Horizontal left bit
			int t22 = (s2 >> 12) & 0b1; //Horizontal left bit
			int t13 = (s1 >> 13) & 0b1; //Vertical right bit
			int t23 = (s2 >> 13) & 0b1; //Vertical right bit
			int t14 = (s1 >> 14) & 0b1; //Vertical left bit
			int t24 = (s2 >> 14) & 0b1; //Vertical left bit
			int t17 = (s1 >> 17) & 0b1; //Full ellipse bit
			int t27 = (s2 >> 17) & 0b1; //Full ellipse bit
			int t18 = (s1 >> 18) & 0b1; //Partial ellipse bit
			int t28 = (s2 >> 18) & 0b1; //Partial ellipse bit


			if ((t11 == 1 && t22 == 1) || (t12 == 1 && t21 == 1)) {
				em++;
				nbdif++;
			}

			if ((t13 == 1 && t24 == 1) || (t14 == 1 && t23 == 1)) {
				em++;
				nbdif++;
			}

			if ((((t11 == 1) || (t12 == 1) || (t13 == 1) || (t14 == 1)) && ((t27 == 1) || (t28 == 1)))
				|| (((t21 == 1) || (t22 == 1) || (t23 == 1) || (t24 == 1)) && ((t17 == 1) || (t18 == 1)))) {
				eg++;
				nbdif++;
			}

			if ((t11 == 1 && t23 == 1) || (t13 == 1 && t21 == 1)) {
				es++;
				nbdif++;
			}

			if ((t11 == 1 && t24 == 1) || (t14 == 1 && t21 == 1)) {
				es++;
				nbdif++;
			}

			if ((t12 == 1 && t23 == 1) || (t13 == 1 && t22 == 1)) {
				es++;
				nbdif++;
			}

			if ((t12 == 1 && t24 == 1) || (t14 == 1 && t22 == 1)) {
				es++;
				nbdif++;
			}

			if ((t17 == 1 && t28 == 1) || (t18 == 1 && t27 == 1)) {
				em++;
				nbdif++;
			}
		}

		return 10 * eg + 3 * em + es + nbdif;
	}
};