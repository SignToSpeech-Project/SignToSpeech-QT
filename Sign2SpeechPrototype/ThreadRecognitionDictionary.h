#pragma once
#include "ThreadRecognition.h"
class ThreadRecognitionDictionary : public ThreadRecognition
{
public:
	ThreadRecognitionDictionary(mutex *mBR, mutex* mSS, bool* pg, vector<long>* bR, bool *ss);
	void run();
	~ThreadRecognitionDictionary();
};

