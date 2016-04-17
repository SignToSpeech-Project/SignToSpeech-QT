#pragma once
#include <mutex>
#include <vector>
#include "ThreadApp.h"

using namespace std;

class ThreadRecognition : public ThreadApp
{
protected:

	mutex*mBufferR; //Mutex for the Reading buffer
	mutex* mSymbolSent; //Mutex for the boolean SymbolSent 
	bool* symbolSent; //To know if the Dictionnary sent a word on WebRTC
	vector<long>* bufferRead; //Buffer of words that will be sent on WebRTC

public:

	//Start the thread
	//virtual void run() = 0;
	ThreadRecognition(mutex *mBR, mutex* mSS, bool* pg, vector<long>* bR, bool *ss);
	~ThreadRecognition();
};

