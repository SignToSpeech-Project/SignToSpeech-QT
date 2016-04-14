#pragma once

#include "pxchanddata.h"
#include "pxchandconfiguration.h"
#include "pxcsensemanager.h"
#include "ThreadRecognition.h"

#include "easywsclient.hpp"

using easywsclient::WebSocket;
 
class ThreadRecognitionHandTools : public ThreadRecognition
{

private:

	PXCHandModule *g_handModule;
	PXCHandData *g_handDataOutput;
	PXCHandConfiguration *g_handConfiguration;

	vector<pair<string, long>> learningGesture;

	char *address;
	char *room;
public:
	ThreadRecognitionHandTools(mutex *mBR, mutex *mSS, bool* pg, vector<long>* bR, char *ad, char *r, bool *sS);

	static WebSocket::pointer webSock;

	void static handle_message(const std::string & message);

	//Start the thread
	void run();
	~ThreadRecognitionHandTools();
};

