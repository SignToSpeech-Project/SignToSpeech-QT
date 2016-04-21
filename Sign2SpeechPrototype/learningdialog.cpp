#include <qmessagebox.h>
#include <windows.h>
#include <thread>
#include "learningdialog.hpp"






void learningDialog::threadDico( bool *program_on, std::mutex* mBufferW, vector<vector<pair<string, long>>>* bufferWrite, condition_variable *cond_var_dico) {
	ThreadLearningDictionary d( mBufferW, program_on, bufferWrite, cond_var_dico);
	d.run();
}

void learningDialog::setButtons(int i) {
	if (i == -2) {
		ui.pushButtonValidation->setEnabled(false);
	}
	else {
		if (program_on_recording) rD->askValidation(i);
	}
}
learningDialog::learningDialog(QWidget * parent) : QWidget(parent) {
	ui.setupUi(this);
	tHandTools= new ThreadLearningHandTools(this);
	tHandTools->start();
	QObject::connect(tHandTools, SIGNAL(signalGUI(const int&)), this, SLOT(setButtons(const int&)));
}
	
learningDialog::~learningDialog() {
	
}


void learningDialog::closeEvent(QCloseEvent *event) //If the user press the "X" close button
{
	parent->show();
	program_on = false;
	cond_var_gui.notify_all();
	cond_var_dico.notify_all();
	tHandTools->wait();
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

		rD = new recordingDialog(nbGestures);
		rD->show();
		rD->setParent(this);
		rD->manageThreads(&cond_var_gui,&program_on_recording);
		this->hide();
	}
}

void learningDialog::on_pushButtonQuit_clicked() {
	this->close();

}
