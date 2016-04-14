#pragma once
#include <vector>
#include <mutex>
#include "ThreadApp.h"

using namespace std;

class ThreadLearning : public ThreadApp
{
protected:

	mutex * mBufferW; //Mutex for the Writting buffer
	vector<vector<pair<string, long>>>* bufferWrite; //Buffer of words that need to be added in the Dictionnary
	condition_variable *cond_var_dico;



public:
	ThreadLearning(mutex *mBW,bool* pg, vector<vector<pair<string, long>>>* bW, condition_variable *cD);
	//virtual void run() = 0; //Start the thread
	~ThreadLearning();
};

