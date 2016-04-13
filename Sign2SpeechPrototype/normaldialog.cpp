#include "normaldialog.hpp"
#include "roomdialog.hpp"

normalDialog::normalDialog(QWidget * parent) : QWidget(parent) {
	ui.setupUi(this);
}

normalDialog::~normalDialog() {

}


void normalDialog::on_pushButtonEnter_clicked() {
	QString message = "Welcome ";
	message += ui.lineEditUser->text();
	message += "      You are now in the ";
	message += ui.lineEditRoom->text();
	message += " room at ";
	message += QString::number(ui.spinBox_1->value());
	message += ".";
	message += QString::number(ui.spinBox_2->value());
	message += ".";
	message += QString::number(ui.spinBox_3->value());
	message += ".";
	message += QString::number(ui.spinBox_4->value());

	roomDialog  *r = new roomDialog();
	r->setInfo(message);
	r->setParent(this);
	r->show();
	this->hide();
}

void normalDialog::closeEvent(QCloseEvent *event) //If the user press the "X" close button
{
	parent->show();
}

void normalDialog::on_pushButtonQuit_clicked() {
	this->close();

}