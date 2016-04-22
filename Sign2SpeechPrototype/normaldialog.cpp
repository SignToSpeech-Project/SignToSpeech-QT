#include "normaldialog.hpp"
#include "ThreadRecognitionDictionary.h"
#include "ThreadRecognitionHandTools.h"

normalDialog::normalDialog(QWidget * parent) : QWidget(parent) {
	ui.setupUi(this);
}

normalDialog::~normalDialog() {

}



void  normalDialog::threadDico(normalDialog * nD) {
	ThreadRecognitionDictionary d(nD);
	d.run();
}
void normalDialog::threadHandTools(mutex *mBR, mutex *mSS,mutex *mPM, bool* pg, bool * bro, vector<long>* bR, string *ad, string *r, bool *sS, condition_variable *cD, normalDialog * nD) {
	ThreadRecognitionHandTools t(mBR,mSS,mPM,pg,bro,bR,ad,r,sS,cD, nD);
	t.run();
}


void normalDialog::on_pushButtonEnter_clicked() {
	QString message = "Welcome ";
	message += ui.lineEditUser->text();
	message += "      You are now in the ";
	message += ui.lineEditRoom->text();
	message += " room at ";

	QString adresse = QString::number(ui.spinBox_1->value());
	adresse += ".";
	adresse += QString::number(ui.spinBox_2->value());
	adresse += ".";
	adresse += QString::number(ui.spinBox_3->value());
	adresse += ".";
	adresse += QString::number(ui.spinBox_4->value());

	address = adresse.toStdString();
	message += adresse;

	room = ui.lineEditRoom->text().toStdString();

	rD = new roomDialog();
	rD->setInfo(message);
	rD->setParent(this);
	rD->show();
	rD->manageThreads(&cond_var_gui, &program_on_room);
	this->hide();
}

void normalDialog::closeEvent(QCloseEvent *event) //If the user press the "X" close button
{
	parent->show();
	parent->show();
	program_on = false;
	cond_var_gui.notify_all();
	tHandTools->join();
	tDico->join();
	free(tHandTools);
	free(tDico);
}

void normalDialog::on_pushButtonQuit_clicked() {
	this->close();	
}