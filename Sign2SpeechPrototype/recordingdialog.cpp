#include "recordingdialog.hpp"

recordingDialog::recordingDialog(QWidget * parent) : QWidget(parent) {
	ui.setupUi(this);
}

recordingDialog::~recordingDialog() {
	
}


void recordingDialog::manageThreads(condition_variable *cond_var, bool *program_on_recording) {
	program_on = program_on_recording;
	*program_on = true;
	cond_var->notify_one(); //To notify ThreadHandTools that it can start recording
}

void recordingDialog::closeEvent(QCloseEvent *event) {
	*program_on = false;
	parent->show();
	
}
