#include "roomdialog.hpp"

roomDialog::roomDialog(QWidget * parent) : QWidget(parent) {
	ui.setupUi(this);

	// instantiate the Recognition software
}


void roomDialog::closeEvent(QCloseEvent *event) //If the user press the "X" close button
{
	parent->show();
}

void roomDialog::on_pushButtonLeave_clicked() {
	this->close();

}

roomDialog::~roomDialog() {
	
}
