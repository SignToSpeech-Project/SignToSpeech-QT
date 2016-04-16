#pragma once
#include "ThreadApp.h"
#include "ConsoleTools.h"
#include "pxchanddata.h"
#include "pxcmetadata.h"
#include "service/pxcsessionservice.h"

#include "pxchanddata.h"
#include "pxchandconfiguration.h"
#include "pxcsensemanager.h"
#include "ThreadLearning.h"

#include "recordingdialog.hpp"


class ThreadLearningHandTools : public ThreadLearning
{

private:
	PXCHandModule *g_handModule;
	PXCHandData *g_handDataOutput;
	PXCHandConfiguration *g_handConfiguration;

	vector<pair<string, long>> learningGesture;

	string * wordMeaning; //Word that will be added
	int * nbGestures; //Nb Gestures for this word
	condition_variable *cond_var_gui; //To know where the GUI is ready
	bool * program_on_recording = false; //To prevent unexpected end of recordingDialog

	recordingDialog * rD; //Windows to show informations

public:
	ThreadLearningHandTools(mutex *mBW, bool* pg, bool* pgr, vector<vector<pair<string, long>>>* bW, string * s, int * nb, condition_variable *cV, condition_variable *cD,recordingDialog* rd);

	void static handle_message(const std::string & message);

	//Start the thread
	void run();
;
	~ThreadLearningHandTools();
};
