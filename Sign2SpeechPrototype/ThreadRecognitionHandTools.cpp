#include "ThreadRecognitionHandTools.h"
#include "HandTools.h"
#include "Debugger.h"
#include <sstream>
#include <algorithm>

WebSocket::pointer ThreadRecognitionHandTools::webSock = NULL;

ThreadRecognitionHandTools::ThreadRecognitionHandTools(mutex *mBR, mutex *mSS, bool* pg, bool * bro, vector<long>* bR, string *ad, string *r, bool *sS, condition_variable *cD, normalDialog *nd) : ThreadRecognition (mBR, mSS, pg, bro,  bR, sS, cD)
{
	address = ad;
	room = r;
	nD = nd;
}


/** Display incoming message from the subtitling channel **/
void ThreadRecognitionHandTools::handle_message(const std::string & message) {
	std::stringstream out;
	out << ">>> " << message;
	Debugger::debug(out.str());
}

void ThreadRecognitionHandTools::run() {
		ConsoleTools ct;

		HandTools h;

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

			while (*program_on) {


				std::mutex m;
				std::unique_lock<std::mutex> lock(m);
				if ((!*program_on_room)) cond_var_gui->wait(lock); //Sleep until roomWindows is opened

				if (*program_on && (*program_on_room)) {

					// open a WebSocket channel with the negotiation server
#ifdef _WIN32
					INT rc;
					WSADATA wsaData;

					rc = WSAStartup(MAKEWORD(2, 2), &wsaData);
					if (rc) {
						printf("WSAStartup Failed.\n");
						return;
					}
#endif
					std::stringstream webSocketAddress;
					webSocketAddress << "ws://" << *address << "/ws/subtitle/" << *room;

					ThreadRecognitionHandTools::webSock = WebSocket::from_url(webSocketAddress.str());

					// if the connection has been done correctly
					// try to start RealSense SDK
					if (ThreadRecognitionHandTools::webSock != NULL) {
						Debugger::info("Connected to the WebSocket server " + webSocketAddress.str());

						int firstFrame = 0;

						time_t start;
						long lastSymbolRead = -1; //Used to know what was the last gesture the user did

						// Acquiring frames from input device
						while ((ct.getSenseManager())->AcquireFrame(true) == PXC_STATUS_NO_ERROR &&  (*program_on) &&(*program_on_room))
						{
							if (*symbolSent) {
								Sleep(500);
								mSymbolSent->lock();
								*symbolSent = false;
								mSymbolSent->unlock();
							}

							//(ct.getSenseManager())->AcquireFrame(true);

							// get and display depth image
							PXCCapture::Sample *sample = (ct.getSenseManager())->QuerySample();
							nD->getRD()->setDepthImage(sample->depth);

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
									nD->getRD()->setRecognizedPoints(hand, ((i == 0) ? Qt::blue : Qt::red));

									//RECOGNITION MODE-------------------------------------------------------------------------------
									long symbol = h.analyseGesture(hand);
									if ((symbol != -1) && (symbol != lastSymbolRead)) {
										mBufferR->lock();
										bufferRead->push_back(symbol);
										mBufferR->unlock();
										lastSymbolRead = symbol;  //Allow the user to keep for example his "fist" gesture during some seconds without changing the dictionary reading level
									}
								}

							} // end if update
							(ct.getSenseManager())->ReleaseFrame();

							nD->getRD()->displayDepthImage();
						} // end while acquire frame
					} // end if Init
					else {
						Debugger::error("Unable to connect to the WebSocket server " + webSocketAddress.str());
					}
					delete ThreadRecognitionHandTools::webSock;
				}
			}
		}
		else
		{
			ct.releaseAll();
			Debugger::error("Failed Initializing PXCSenseManager");
			return;
		}
	


	ct.releaseAll();


#ifdef _WIN32
	WSACleanup();
#endif

}
ThreadRecognitionHandTools::~ThreadRecognitionHandTools()
{
}
