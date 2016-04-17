#pragma once

#include "ConsoleTools.h"
#include "easywsclient.hpp"
#include "pxchanddata.h"
#include "pxcmetadata.h"
#include "service/pxcsessionservice.h"

#include "pxchanddata.h"
#include "pxchandconfiguration.h"
#include "pxcsensemanager.h"
#include "ThreadRecognition.h"
#include "normaldialog.hpp"

using easywsclient::WebSocket;
 
class ThreadRecognitionHandTools : public ThreadRecognition
{

private:

	PXCHandModule *g_handModule;
	PXCHandData *g_handDataOutput;
	PXCHandConfiguration *g_handConfiguration;

	string *address;
	string *room;
	normalDialog *nD;

public:
	ThreadRecognitionHandTools(mutex *mBR, mutex *mSS, bool* pg, bool * bro, vector<long>* bR, string *ad,string *r, bool *sS, condition_variable *cD, normalDialog *nd);

	static WebSocket::pointer webSock;

	void static handle_message(const std::string & message);

	//Start the thread
	void run();
	~ThreadRecognitionHandTools();
};

