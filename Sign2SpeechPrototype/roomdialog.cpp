#include "roomdialog.hpp"

roomDialog::roomDialog(QWidget * parent) : QWidget(parent) {
	ui.setupUi(this);
}


void roomDialog::closeEvent(QCloseEvent *event) //If the user prexx the "X" close button
{
	parent->show();
}

void roomDialog::on_pushButtonLeave_clicked() {
	this->close();

}

roomDialog::~roomDialog() {
	
}
