#include "ThreadRecognitionDictionary.h"
#include "Dictionary.h"
#include "Parser.h"
#include "Debugger.h"
#include "ThreadRecognitionHandTools.h"



ThreadRecognitionDictionary::ThreadRecognitionDictionary(normalDialog* nd) : ThreadRecognition(nd->getMBufferR(), nd->getMSymbolSent(), nd->getPG(), nd->getPGR(), nd->getBufferRead(), nd->getSymbolSent(), nd->getCondGui())
{
	nD = nd;
}

void ThreadRecognitionDictionary::run() {

	//Dictionary Initialisation-------------------------------------------------------------------------
	Dictionary d;

	Parser p("output.json");

	//Vector of vector used to store all the pairs
	vector< vector< pair<string, long> > > res;

	//parse the JSON file
	Debugger::debug("Parsing Json file...\n");
	res = p.ReadJsonFile();
	Debugger::debug("Parsing > OK");

	//Insert all vectors of pairs in the dictionary
	for (vector<vector<pair<string, long>>>::iterator it = res.begin(); it != res.end(); ++it) {
		d.insertList((*it));
	}

	time_t start = time(0);

	while (*program_on) {

		while (*program_on_room) {

			double seconds_since_start = difftime(time(0), start);

			if (seconds_since_start > 2) { //TIMEOUT to refresh Dictionary pointer node
				string currentSymbol = d.refreshDictionary();
				if ((currentSymbol != "") && (currentSymbol != "0x1 : root")) {
					Debugger::info("Sending: " + currentSymbol);
					nD->getRD()->pushMessage(QString::fromStdString("Sending: " + currentSymbol));
					ThreadRecognitionHandTools::webSock->send("{\"content\":\"" + currentSymbol + "\"}");
					mSymbolSent->lock();
					*symbolSent = true;
					mSymbolSent->unlock();
					if (ThreadRecognitionHandTools::webSock->getReadyState() != WebSocket::CLOSED) {
						ThreadRecognitionHandTools::webSock->poll();
						ThreadRecognitionHandTools::webSock->dispatch(ThreadRecognitionHandTools::handle_message);
					}
				}
				start = time(0);
			}


			if (bufferRead->size() != 0) { //If there is a word to send on WebRTC
				mBufferR->lock();
				vector<long>::iterator it = bufferRead->begin();
				string currentSymbol = d.read(*it);
			std:stringstream out;
				out << "Reading : " << (*it) << " Signification : " << currentSymbol << endl;
				Debugger::debug(out.str());
				//nD->getRD()->pushMessage(QString::fromStdString(out.str()));
				if ((currentSymbol.find("0x0 : Not final word") == std::string::npos) && (currentSymbol != "0x1 : root") && (currentSymbol != "")) {
					Debugger::info("Sending: " + currentSymbol);
					nD->getRD()->pushMessage(QString::fromStdString("Sending: " + currentSymbol));
					ThreadRecognitionHandTools::webSock->send("{\"content\":\"" + currentSymbol + "\"}");
					mSymbolSent->lock();
					*symbolSent = true;
					mSymbolSent->unlock();
					if (ThreadRecognitionHandTools::webSock->getReadyState() != WebSocket::CLOSED) {
						ThreadRecognitionHandTools::webSock->poll();
						ThreadRecognitionHandTools::webSock->dispatch(ThreadRecognitionHandTools::handle_message);
					}
				}
				bufferRead->erase(it);
				start = time(0);
				mBufferR->unlock();
			}
		}
		std::mutex m;
		std::unique_lock<std::mutex> lock(m);
		cond_var_gui->wait(lock); //Sleep until roomWindows is on

	}
}


ThreadRecognitionDictionary::~ThreadRecognitionDictionary()
{
}
