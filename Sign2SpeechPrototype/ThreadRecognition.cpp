#include "ThreadRecognition.h"



ThreadRecognition::ThreadRecognition(mutex *mBR, mutex* mSS, bool* pg, vector<long>* bR, bool *ss, condition_variable *cD) : ThreadApp(pg,cD)
{
	this->mBufferR = mBR;
	this->mSymbolSent = mSS;
	this->symbolSent = ss,
	this->bufferRead = bR;
}


ThreadRecognition::~ThreadRecognition()
{
}
