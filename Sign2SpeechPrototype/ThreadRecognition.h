#pragma once
#include <mutex>
#include <vector>
#include "ThreadApp.h"

using namespace std;

class ThreadRecognition : public ThreadApp
{
protected:
	bool * program_on_room = false; //To prevent unexpected end of roomDialog
	mutex*mBufferR; //Mutex for the Reading buffer
	mutex* mSymbolSent; //Mutex for the boolean SymbolSent 
	mutex* mPushMessage; //Mutex to prevent threads to write at the same time in the GUI
	bool* symbolSent; //To know if the Dictionnary sent a word on WebRTC
	vector<long>* bufferRead; //Buffer of words that will be sent on WebRTC
	condition_variable * cond_var_gui;

public:

	//Start the thread
	//virtual void run() = 0;
	ThreadRecognition(mutex *mBR, mutex* mSS, mutex* mPM, bool* pg, bool* bro, vector<long>* bR, bool *ss, condition_variable *  cg);
	~ThreadRecognition();
};

