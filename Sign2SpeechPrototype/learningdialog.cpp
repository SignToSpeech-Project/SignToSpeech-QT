#include <qmessagebox.h>
#include <windows.h>
#include <thread>
#include "learningdialog.hpp"






void learningDialog::threadDico( bool *program_on, std::mutex* mBufferW, vector<vector<pair<string, long>>>* bufferWrite, condition_variable *cond_var_dico) {
	ThreadLearningDictionary d( mBufferW, program_on, bufferWrite, cond_var_dico);
	d.run();
}

	
void  learningDialog::threadHandTools(learningDialog* rD) {
	ThreadLearningHandTools t(rD);
	t.run();
}


learningDialog::learningDialog(QWidget * parent) : QWidget(parent) {
	ui.setupUi(this);
}

learningDialog::~learningDialog() {
	
}


void learningDialog::closeEvent(QCloseEvent *event) //If the user press the "X" close button
{
	parent->show();
	program_on = false;
	cond_var_gui.notify_all();
	cond_var_dico.notify_all();
	tHandTools->join();
	tDico->join();
	free(tHandTools);
	free(tDico);
}

void learningDialog::on_pushButtonValidation_clicked() {
	QString temp = ui.lineEditWord->text();
	if (temp == "") {
		QMessageBox msgBox;
		msgBox.setText("PLEASE, enter a validate word");
		msgBox.exec();
	}
	else {
		meaningWord = temp.toStdString();
		nbGestures = ui.spinBoxGestures->value();

		rD = new recordingDialog();
		rD->show();
		rD->setParent(this);
		rD->manageThreads(&cond_var_gui,&program_on_recording);
		this->hide();
	}
}

void learningDialog::on_pushButtonQuit_clicked() {
	this->close();

}
