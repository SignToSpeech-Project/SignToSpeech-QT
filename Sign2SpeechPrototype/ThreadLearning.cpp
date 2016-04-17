#include "ThreadLearning.h"



ThreadLearning::ThreadLearning(mutex *mBW, bool* pg, vector<vector<pair<string, long>>>* bW, condition_variable *cD) : ThreadApp(pg)
{
	this->mBufferW = mBW;
	this->bufferWrite = bW;
	this->cond_var_dico = cD;
}


ThreadLearning::~ThreadLearning()
{
}
