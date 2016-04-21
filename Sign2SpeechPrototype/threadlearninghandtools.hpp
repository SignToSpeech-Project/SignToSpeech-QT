#pragma once
#ifndef THL_H
#define THL_H
#include <qthread.h>
#include "ThreadApp.h"
#include "ConsoleTools.h"
#include "pxchanddata.h"
#include "pxcmetadata.h"
#include "service/pxcsessionservice.h"

#include "pxchanddata.h"
#include "pxchandconfiguration.h"
#include "pxcsensemanager.h"
#include "ThreadLearning.h"

#include "learningdialog.hpp"

class learningDialog;

class ThreadLearningHandTools : public QThread, public ThreadLearning
{
	Q_OBJECT
private:
	PXCHandModule *g_handModule;
	PXCHandData *g_handDataOutput;
	PXCHandConfiguration *g_handConfiguration;

	vector<pair<string, long>> learningGesture;

	string * wordMeaning; //Word that will be added
	int * nbGestures; //Nb Gestures for this word
	bool * program_on_recording = false; //To prevent unexpected end of recordingDialog

	condition_variable *cond_var_gui; //To know where the GUI is ready

	learningDialog * lD; //Windows to show informations

public:
	ThreadLearningHandTools(learningDialog* ld);
	void static handle_message(const std::string & message);
	void pushMessage(string msg);
	~ThreadLearningHandTools();

protected:
	virtual void run();

signals:
	void signalGUI(int);

};
#endif 
