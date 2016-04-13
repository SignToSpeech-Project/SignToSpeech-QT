#include "sign2speechprototype.h"
#include "normaldialog.hpp"
#include "learningdialog.hpp"
#include <iostream>

Sign2SpeechPrototype::Sign2SpeechPrototype(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

Sign2SpeechPrototype::~Sign2SpeechPrototype()
{

}



void Sign2SpeechPrototype::on_pushButtonRecognition_clicked() {
	normalDialog *d = new normalDialog();
	d->setParent(this);
	this->hide();
	d->show();
}

void Sign2SpeechPrototype::on_pushButtonLearning_clicked() {
	learningDialog *d = new learningDialog();
	d->setParent(this);
	this->hide();
	d->show();
}