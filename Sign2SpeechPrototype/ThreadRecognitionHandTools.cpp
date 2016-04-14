#include "ThreadRecognitionHandTools.h"

WebSocket::pointer ThreadRecognitionHandTools::webSock = NULL;

ThreadRecognitionHandTools::ThreadRecognitionHandTools(mutex *mBR, mutex *mSS, bool* pg, vector<long>* bR, char *ad, char *r, bool *sS) : ThreadRecognition (mBR, mSS, pg,  bR, sS)
{
	address = ad;
	room = r;
}

void ThreadRecognitionHandTools::run() {

}
ThreadRecognitionHandTools::~ThreadRecognitionHandTools()
{
}
