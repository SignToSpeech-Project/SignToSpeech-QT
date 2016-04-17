#include "roomdialog.hpp"

roomDialog::roomDialog(QWidget * parent) : QWidget(parent) {
	ui.setupUi(this);

	// instantiate the Recognition software
}


void roomDialog::manageThreads(condition_variable *cond_var, bool *program_on_recording) {
	program_on = program_on_recording;
	*program_on = true;
	cond_var->notify_all(); //To notify ThreadHandTools that it can start recording
}

void roomDialog::closeEvent(QCloseEvent *event) //If the user press the "X" close button
{
	parent->show();
}

void roomDialog::on_pushButtonLeave_clicked() {
	*program_on = false;
	this->close();

}

roomDialog::~roomDialog() {
	
}
