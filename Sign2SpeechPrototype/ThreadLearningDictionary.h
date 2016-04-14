#pragma once
#include <mutex>
#include <vector>
#include "ThreadLearning.h"

using namespace std;

class ThreadLearningDictionary : public ThreadLearning
{
public:
	ThreadLearningDictionary(mutex *mBW, bool* pg, vector<vector<pair<string, long>>>* bW, condition_variable *cD);

	//Start the thread
	void run();
	~ThreadLearningDictionary();
};

