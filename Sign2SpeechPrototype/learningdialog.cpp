#include <qmessagebox.h>
#include <windows.h>
#include <thread>
#include "learningdialog.hpp"
#include "recordingdialog.hpp"





void threadDico(Ui::learningDialog ui) {
	Sleep(2000);
	ui.lineEditWord->setText("J'ai attendu 2 secondes");
}


////// TEST THREAD T
//TODO A CHANGER : on les sauvegarderas en attribut de la classe (ou celle d'après) et une fois fini il faudra les free
//Thread managing the camera and the gestures recognization
void  threadHandTool(Ui::learningDialog ui) {
	Sleep(5000);
	ui.spinBoxGestures->setValue(10);
	}

void lancementThread(Ui::learningDialog ui) {
	std::thread *tHandTools = new std::thread(threadHandTool,ui);
	std::thread *tDico = new std::thread(threadDico,ui);
}

learningDialog::learningDialog(QWidget * parent) : QWidget(parent) {
	ui.setupUi(this);
	lancementThread(ui);



}

learningDialog::~learningDialog() {
	
}


void learningDialog::closeEvent(QCloseEvent *event) //If the user prexx the "X" close button
{
	parent->show();
}

void learningDialog::on_pushButtonValidation_clicked() {
	QString temp = ui.lineEditWord->text();
	if (temp == "") {
		QMessageBox msgBox;
		msgBox.setText("PLEASE, enter a validate word");
		msgBox.exec();
	}
	else {
		recordingDialog *d = new recordingDialog();
		d->show();
		d->setParent(this);
		d->manageThreads(ui.lineEditWord->text(), ui.spinBoxGestures->value());
		this->hide();
	}
}

void learningDialog::on_pushButtonQuit_clicked() {
	this->close();

}
