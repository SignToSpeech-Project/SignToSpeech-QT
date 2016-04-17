#include "ThreadApp.h"

ThreadApp::ThreadApp(bool* pg, condition_variable* cD) {
	this->program_on = pg;
	this->cond_var_gui = cD;
}