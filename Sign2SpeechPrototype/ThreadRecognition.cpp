#include "ThreadRecognition.h"



ThreadRecognition::ThreadRecognition(mutex *mBR, mutex* mSS, bool* pg, vector<long>* bR, bool *ss) : ThreadApp(pg)
{
	this->mBufferR = mBR;
	this->mSymbolSent = mSS;
	this->symbolSent = ss,
	this->bufferRead = bR;
}


ThreadRecognition::~ThreadRecognition()
{
}
