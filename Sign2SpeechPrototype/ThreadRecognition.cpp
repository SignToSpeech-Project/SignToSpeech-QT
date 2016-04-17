#include "ThreadRecognition.h"



ThreadRecognition::ThreadRecognition(mutex *mBR, mutex* mSS, bool* pg, bool* bro, vector<long>* bR, bool *ss, condition_variable * cg) : ThreadApp(pg)
{
	this->mBufferR = mBR;
	this->mSymbolSent = mSS;
	this->symbolSent = ss,
	this->bufferRead = bR;
	this->program_on_room = bro;
	this->cond_var_gui = cg;
}


ThreadRecognition::~ThreadRecognition()
{
}
