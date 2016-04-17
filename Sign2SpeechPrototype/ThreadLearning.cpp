#include "ThreadLearning.h"



ThreadLearning::ThreadLearning(mutex *mBW, bool* pg, vector<vector<pair<string, long>>>* bW, condition_variable *cD) : ThreadApp(pg,cD)
{
	this->mBufferW = mBW;
	this->bufferWrite = bW;
}


ThreadLearning::~ThreadLearning()
{
}
