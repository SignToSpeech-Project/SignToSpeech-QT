#include "ThreadLearningHandTools.hpp"
#include <windows.h>
#include <winsock.h>
#include <sstream>
#include "Debugger.h"
#include "HandTools.h"



ThreadLearningHandTools::ThreadLearningHandTools(learningDialog* ld) : ThreadLearning(ld->getMutexW(), ld->getPg(), ld->getBufferWrite(), ld->getCondDico())
{
	lD = ld;
	wordMeaning = lD->getMeaning();
	cond_var_gui = lD->getCondGui();
	nbGestures = lD->getNbGestures();
	program_on_recording = ld->getPgr();
	int i;
}


/** Display incoming message from the subtitling channel **/
void ThreadLearningHandTools::handle_message(const std::string & message) {
	std::stringstream out;
	out << ">>> " << message;
	Debugger::debug(out.str());
}

void ThreadLearningHandTools::pushMessage(string msg) {
	if (*program_on_recording) lD->getRD()->pushMessage(QString::fromStdString(msg));
}


void ThreadLearningHandTools::run() {

	ConsoleTools ct;

	// try to start RealSense SDK

	HandTools h(this);

	// SDK initialisation

	ct.setSession(PXCSession::CreateInstance());
	if (!(ct.getSession()))
	{
		Debugger::error("Failed Creating PXCSession");
		return;
	}

	ct.setSenseManager(ct.getSession()->CreateSenseManager());
	if (!(ct.getSenseManager()))
	{
		ct.releaseAll();
		Debugger::error("Failed Creating PXCSenseManager");
		return;
	}

	ct.getSenseManager()->EnableStream(PXCCapture::STREAM_TYPE_DEPTH, 640, 480, 60);

	if ((ct.getSenseManager())->EnableHand() != PXC_STATUS_NO_ERROR)
	{
		ct.releaseAll();
		Debugger::error("Failed Enabling Hand Module");
		return;
	}

	g_handModule = (ct.getSenseManager())->QueryHand();
	if (!g_handModule)
	{
		ct.releaseAll();
		Debugger::error("Failed Creating PXCHandModule");
		return;
	}

	g_handDataOutput = g_handModule->CreateOutput();
	if (!g_handDataOutput)
	{
		ct.releaseAll();
		Debugger::error("Failed Creating PXCHandData");
		return;
	}

	g_handConfiguration = g_handModule->CreateActiveConfiguration();
	if (!g_handConfiguration)
	{
		ct.releaseAll();
		Debugger::error("Failed Creating PXCHandConfiguration");
		return;
	}

	g_handConfiguration->EnableStabilizer(true);
	g_handConfiguration->SetTrackingMode(PXCHandData::TRACKING_MODE_FULL_HAND);

	// Apply configuration setup
	g_handConfiguration->ApplyChanges();


	if (g_handConfiguration)
	{
		g_handConfiguration->Release();
		g_handConfiguration = NULL;
	}
	// End of initialisation

	pxcI32 numOfHands = 0;

	// First Initializing the sense manager
	if ((ct.getSenseManager())->Init() == PXC_STATUS_NO_ERROR)
	{
		Debugger::info("\nPXCSenseManager Initializing OK\n========================\n");


		bool saved = false;

		while (*program_on) {
			std::mutex m;
			std::unique_lock<std::mutex> lock(m);

			if ((!*program_on_recording) || saved) {
				cond_var_gui->wait(lock); //Waiting signal from system to start
			}

			saved = false;
			if (*program_on && (*program_on_recording)) {


				int firstFrame = 0;

				long lastSymbolRead = -1; //Used to know what was the last gesture the user did

				int cpt_Gesture = 1; //Used on learning mode to know which gesture we are doing at this time

				vector<long> completeGesture; //Used on learning mode : Vector of the serie of gestures the user did


				h.learningMode(*nbGestures);

				Debugger::info("Learning mode is starting in 5 secondes, be ready !");
				pushMessage("Learning mode is starting in 5 secondes, be ready !");
				for (int i = 5; i > 0; i--) {
					Debugger::info(to_string(i));
					pushMessage(to_string(i));
					Sleep(1000);
				}
				Debugger::info("------------------------PLEASE, DO YOUR FIRST GESTURE DURING 3 SECONDES------------------------");
				pushMessage("------------------------PLEASE, DO YOUR FIRST GESTURE DURING 3 SECONDES------------------------");



				// Acquiring frames from input device
				while ((ct.getSenseManager())->AcquireFrame(true) == PXC_STATUS_NO_ERROR && (*program_on) && (*program_on_recording) && (!saved))
				{

					//(ct.getSenseManager())->AcquireFrame(true);

					// get and display depth image
					PXCCapture::Sample *sample = (ct.getSenseManager())->QuerySample();
					lD->getRD()->setDepthImage(sample->depth);

					// Get current hand outputs
					if (g_handDataOutput->Update() == PXC_STATUS_NO_ERROR)
					{

						PXCHandData::IHand *hand;
						for (int i = 0; i < g_handDataOutput->QueryNumberOfHands(); ++i)
						{
							g_handDataOutput->QueryHandData(PXCHandData::ACCESS_ORDER_BY_TIME, i, hand);
							std::string handSide = "Unknown Hand";
							handSide = hand->QueryBodySide() == PXCHandData::BODY_SIDE_LEFT ? "Left Hand" : "Right Hand";

							// display in window
							lD->getRD()->setRecognizedPoints(hand, ((i == 0) ? Qt::blue : Qt::red));

							//LEARNING MODE---------------------------------------------------------------------------------
							long symbol = h.analyseXGestures(hand);
							if (symbol != -1) {
								emit signalGUI(cpt_Gesture); //Asking user if he want to continue
								if (lD->getRD()->getAnswer() == NULL) {
									cond_var_gui->wait(lock);
								}
								if (*program_on_recording) {
									bool answer = lD->getRD()->getAnswer();
									if (!answer) {  //If the user want to do again his gesture
										h.learningMode(*nbGestures + 1 - cpt_Gesture);
									}
									else {
										if (!h.getLearning()) {
											pair<string, long> temp(*wordMeaning, symbol);
											learningGesture.push_back(temp);
											mBufferW->lock();
											bufferWrite->push_back(learningGesture);
											mBufferW->unlock();
											cond_var_dico->notify_one();
											learningGesture.clear();

											Debugger::info("------------------------WORD SAVED------------------------");
											pushMessage("------------------------WORD SAVED------------------------");
											saved = true;
											emit signalGUI(-1); //Signaling GUI word is saved
										}
										else {
											pair<string, long> temp("", symbol);
											learningGesture.push_back(temp);
											cpt_Gesture++;
											string msg = "------------------------BE READY FOR THE GESTURE NUMERO " + to_string(cpt_Gesture) + " IN 5 SECONDES------------------------";
											Debugger::info(msg);
											pushMessage(msg);
											for (int i = 5; i > 0; i--) {
												Debugger::info(to_string(i));
												pushMessage(to_string(i));
												Sleep(1000);
											}
											Debugger::info("------------------------Do your gesture NOW during 3 secondes------------------------");
											pushMessage("------------------------Do your gesture NOW during 3 secondes------------------------");
										}
									}
									lD->getRD()->setAnswer(NULL);
								}
							}


						}

					} // end if update
					(ct.getSenseManager())->ReleaseFrame();

					lD->getRD()->displayDepthImage();
				} // end while acquire frame
			}
		}
	} // end if Init
	else
	{
		ct.releaseAll();
		Debugger::error("Failed Initializing PXCSenseManager");
		emit signalGUI(-2);
		return;
	}


	ct.releaseAll();


#ifdef _WIN32
	WSACleanup();
#endif
}

ThreadLearningHandTools::~ThreadLearningHandTools()
{
}
