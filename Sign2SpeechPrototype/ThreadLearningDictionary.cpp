#include "ThreadLearningDictionary.h"
#include "Dictionary.h"
#include "Parser.h"
#include "Debugger.h"



ThreadLearningDictionary::ThreadLearningDictionary(mutex *mBW, bool* pg, vector<vector<pair<string, long>>>* bW, condition_variable *cD) : ThreadLearning(mBW, pg, bW, cD)
{
}


void ThreadLearningDictionary::run() {
	//Dictionary Initialisation-------------------------------------------------------------------------
	Dictionary d;

	Parser p("output.json");

	//Vector of vector used to store all the pairs
	vector< vector< pair<string, long> > > res;

	//parse the JSON file
	Debugger::debug("Parsing Json file...\n");
	res = p.ReadJsonFile();
	Debugger::debug("Parsing > OK");

	//Insert all vectors of pairs in the dictionary
	for (vector<vector<pair<string, long>>>::iterator it = res.begin(); it != res.end(); ++it) {
		d.insertList((*it));
	}

	time_t start = time(0);
	while ( (*program_on) || (bufferWrite->size() != 0) ) {

		if (bufferWrite->size() != 0) { //If there is a word to add to the Dictionnary
			mBufferW->lock();
			vector<vector<pair<string, long>>>::iterator it = bufferWrite->begin();
			d.insertList((*it));
			bufferWrite->erase(it);
			mBufferW->unlock();

		}
		else {
			std::mutex m;
			std::unique_lock<std::mutex> lock(m);
			cond_var_dico->wait(lock); //Sleep until a word is added to bufferWrite
		}
	}


	//Creating JSON File-------------------------------------------------------------------------

	vector<vector<pair<string, long>>> v = d.createVectorDictionary(); // Create vector of vectors of pairs from the dict

	p.WriteJsonFile(v);
}


ThreadLearningDictionary::~ThreadLearningDictionary()
{
}
