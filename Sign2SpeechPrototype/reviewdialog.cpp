#include "reviewdialog.hpp"

reviewDialog::reviewDialog(bool * as,QWidget * parent) :QDialog(parent) {
	ui.setupUi(this);
	answer = as;
}


void reviewDialog::on_pushButtonDoAgain_clicked() {
	*answer = false;
	this->close();
}


void reviewDialog::on_pushButtonContinue_clicked() {
	*answer = true;
	this->close();
}

reviewDialog::~reviewDialog() {
	
}
