#include "recordingdialog.hpp"

recordingDialog::recordingDialog(QWidget * parent) : QWidget(parent) {
	ui.setupUi(this);
}

recordingDialog::~recordingDialog() {
	
}


void recordingDialog::manageThreads(QString word, int nbGesture) {
	//TODO : Start thread, on leur passera l'ui pour qu'il mette à jour l'affichage et créer les buffer écriture
	//Joindre le thread handtools (une fois qu'on a fini d'enregistrer tout les gestes , ou validation à chaque geste).
	ui.textBrowser->setText("Please, wait");
}

void recordingDialog::closeEvent(QCloseEvent *event) {
	//TODO : Mutex
	program_on = false;
	//Joindre threads.
	parent->show();
	
}
