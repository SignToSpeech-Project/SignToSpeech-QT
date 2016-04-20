#pragma once
#ifndef TRD_H
#define TRD_H

#include "ThreadRecognition.h"
#include "recordingdialog.hpp"
#include "normaldialog.hpp"

class normalDialog;

class ThreadRecognitionDictionary : public ThreadRecognition
{
public:
	ThreadRecognitionDictionary(normalDialog* nd);
	void pushMessage(string msg);
	void run();
	~ThreadRecognitionDictionary();

private:
	normalDialog *nD;
};
#endif 

