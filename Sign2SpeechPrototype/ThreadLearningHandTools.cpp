#include "ThreadLearningHandTools.h"
#include <windows.h>
#include <winsock.h>
#include <sstream>
#include "ThreadHandTools.h"
#include "Debugger.h"
#include "HandTools.h"



ThreadLearningHandTools::ThreadLearningHandTools(mutex *mBW, bool* pg, bool* pgr, vector<vector<pair<string, long>>>* bW, string * s, int * nb, condition_variable *cS, condition_variable *cD, learningDialog* ld) : ThreadLearning(mBW, pg, bW, cD)
{
	wordMeaning = s;
	cond_var_gui = cS;
	nbGestures = nb;
	lD = ld;
	program_on_recording = pgr;

}


/** Display incoming message from the subtitling channel **/
void ThreadLearningHandTools::handle_message(const std::string & message) {
	std::stringstream out;
	out << ">>> " << message;
	Debugger::debug(out.str());
}


void ThreadLearningHandTools::run() {

	ConsoleTools ct;

	// open a WebSocket channel with the negotiation server
	// we don't need this for learning
	/*#ifdef _WIN32
	INT rc;
	WSADATA wsaData;

	rc = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (rc) {
	printf("WSAStartup Failed.\n");
	return;
	}
	#endif*/


	// try to start RealSense SDK
	
	HandTools h;

	Sleep(5000);

	// SDK initialisation 
	ct.setSession(PXCSession::CreateInstance());
	if (!(ct.getSession()))
	{
		Debugger::error("Failed Creating PXCSession");
		lD->getRD()->pushMessage("Failed Creating PXCSession");
		return;
	}

	ct.setSenseManager(ct.getSession()->CreateSenseManager());
	if (!(ct.getSenseManager()))
	{
		ct.releaseAll();
		Debugger::error("Failed Creating PXCSenseManager");
		lD->getRD()->pushMessage("Failed Creating PXCSenseManager");
		return;
	}

	ct.getSenseManager()->EnableStream(PXCCapture::STREAM_TYPE_DEPTH, 640, 480, 60);

	if ((ct.getSenseManager())->EnableHand() != PXC_STATUS_NO_ERROR)
	{
		ct.releaseAll();
		Debugger::error("Failed Enabling Hand Module");
		lD->getRD()->pushMessage("Failed Creating Hand Module");
		return;
	}

	g_handModule = (ct.getSenseManager())->QueryHand();
	if (!g_handModule)
	{
		ct.releaseAll();
		Debugger::error("Failed Creating PXCHandModule");
		lD->getRD()->pushMessage("Failed Creating PXCHandModule");
		return;
	}

	g_handDataOutput = g_handModule->CreateOutput();
	if (!g_handDataOutput)
	{
		ct.releaseAll();
		Debugger::error("Failed Creating PXCHandData");
		lD->getRD()->pushMessage("Failed Creating PXCHandData");
		return;
	}

	g_handConfiguration = g_handModule->CreateActiveConfiguration();
	if (!g_handConfiguration)
	{
		ct.releaseAll();
		Debugger::error("Failed Creating PXCHandConfiguration");
		lD->getRD()->pushMessage("Failed Creating PXCHandConfiguration");
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
		lD->getRD()->pushMessage("\nPXCSenseManager Initializing OK\n========================\n");

		while (*program_on) {
			std::mutex m;
			std::unique_lock<std::mutex> lock(m);

			if (!*program_on_recording) {
				cond_var_gui->wait(lock); //Waiting signal from system to start
			}

			if (*program_on && (*program_on_recording)) {


				int firstFrame = 0;

				long lastSymbolRead = -1; //Used to know what was the last gesture the user did

				int cpt_Gesture = 1; //Used on learning mode to know which gesture we are doing at this time

				vector<long> completeGesture; //Used on learning mode : Vector of the serie of gestures the user did


				h.learningMode(*nbGestures);

				Debugger::info("Learning mode is starting in 5 secondes, be ready !");
				lD->getRD()->pushMessage("Learning mode is starting in 5 secondes, be ready !");
				for (int i = 5; i > 0; i--) {
					Debugger::info(to_string(i));
					Sleep(1000);
				}
				Debugger::info("------------------------PLEASE, DO YOUR FIRST GESTURE DURING 3 SECONDES------------------------");
				lD->getRD()->pushMessage("------------------------PLEASE, DO YOUR FIRST GESTURE DURING 3 SECONDES------------------------");


				bool saved = false;

				// Acquiring frames from input device
				while ((ct.getSenseManager())->AcquireFrame(true) == PXC_STATUS_NO_ERROR && (*program_on) && (*program_on_recording) && (!saved))
				{

					//(ct.getSenseManager())->AcquireFrame(true);

					// get and display depth image
					PXCCapture::Sample *sample = (ct.getSenseManager())->QuerySample();
					lD->getRD()->displayDepthImage(sample->depth);

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
							lD->getRD()->displayRecognizedPoints(hand);

							//LEARNING MODE---------------------------------------------------------------------------------
							long symbol = h.analyseXGestures(hand);
							if (symbol != -1) {
								if (!h.getLearning()) {
									pair<string, long> temp(*wordMeaning, symbol);
									learningGesture.push_back(temp);
									mBufferW->lock();
									bufferWrite->push_back(learningGesture);
									mBufferW->unlock();
									cond_var_dico->notify_one();
									learningGesture.clear();

									Debugger::info("------------------------WORD SAVED------------------------");
									lD->getRD()->pushMessage("------------------------WORD SAVED------------------------");
									saved = true;
									Sleep(2000);
								}
								else {
									pair<string, long> temp("", symbol);
									learningGesture.push_back(temp);
									cpt_Gesture++;
									string msg = "------------------------BE READY FOR THE GESTURE NUMERO " + to_string(cpt_Gesture) + " IN 5 SECONDES------------------------";
									Debugger::info(msg);
									lD->getRD()->pushMessage(QString::fromStdString(msg));
									for (int i = 5; i > 0; i--) {
										Debugger::info(to_string(i));
										Sleep(1000);
									}
									Debugger::info("------------------------Do your gesture NOW during 3 secondes------------------------");
									lD->getRD()->pushMessage("------------------------Do your gesture NOW during 3 secondes------------------------");
								}
							}


						}

					} // end if update
					(ct.getSenseManager())->ReleaseFrame();
				} // end while acquire frame
			}
		}
	} // end if Init
	else
	{
		ct.releaseAll();
		Debugger::error("Failed Initializing PXCSenseManager");
		lD->getRD()->pushMessage("Failed Initializing PXCSenseManager");
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
