#pragma once
#ifndef TRD_H
#define TRD_H

#include "ThreadRecognition.h"
#include "recordingdialog.hpp"

class recognitionDialog;

class ThreadRecognitionDictionary : public ThreadRecognition
{
public:
	ThreadRecognitionDictionary(mutex *mBR, mutex* mSS, bool* pg, bool* br, vector<long>* bR, bool *ss, recognitionDialog* rd, condition_variable *cD);
	void run();
	~ThreadRecognitionDictionary();

private:
	recognitionDialog* rD;
	bool * program_on_room = false; //To prevent unexpected end of roomDialog
};
#endif 

