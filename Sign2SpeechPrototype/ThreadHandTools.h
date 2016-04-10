#pragma once

#include "ThreadApp.h"
#include "ConsoleTools.h"
#include "easywsclient.hpp"
#include "pxchanddata.h"
#include "pxcmetadata.h"
#include "service/pxcsessionservice.h"

#include "pxchanddata.h"
#include "pxchandconfiguration.h"
#include "pxcsensemanager.h"

using easywsclient::WebSocket;

class ThreadHandTools : public ThreadApp {

private :

	PXCHandModule *g_handModule;
	PXCHandData *g_handDataOutput;
	PXCHandConfiguration *g_handConfiguration;

	vector<pair<string, long>> learningGesture;

	char *address;
	char *room;

public:
	ThreadHandTools(mutex *mBR, mutex *mBW, mutex *mSS, bool* pg, vector<long>* bR, vector<vector<pair<string, long>>>* bW, char *ad, char *r, bool *sS);

	static WebSocket::pointer webSock;

	void static handle_message(const std::string & message);

	//Start the thread
	void run();	
};