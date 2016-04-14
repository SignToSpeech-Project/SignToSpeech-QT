#include "ThreadRecognitionDictionary.h"



ThreadRecognitionDictionary::ThreadRecognitionDictionary(mutex *mBR, mutex* mSS, bool* pg, vector<long>* bR, bool *ss) : ThreadRecognition(mBR, mSS, pg,  bR, ss)
{
}

void ThreadRecognitionDictionary::run() {

}


ThreadRecognitionDictionary::~ThreadRecognitionDictionary()
{
}
