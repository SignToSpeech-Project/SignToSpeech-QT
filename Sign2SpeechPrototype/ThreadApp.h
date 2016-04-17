#pragma once
#include <mutex>
#include <vector>

using namespace std;

//General thread for the Application. 
//Starting with the run function

class ThreadApp {

protected:

	bool* program_on; //To stop the thread
	condition_variable *cond_var_gui; //To know where the GUI is ready

public :
	ThreadApp(bool* pg);
	
	//Start the thread
	virtual void run() = 0 ;


};