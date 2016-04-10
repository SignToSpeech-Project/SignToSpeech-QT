#include <qmessagebox.h>
#include "learningdialog.hpp"
#include "recordingdialog.hpp"

learningDialog::learningDialog(QWidget * parent) : QWidget(parent) {
	ui.setupUi(this);
}

learningDialog::~learningDialog() {
	
}


void learningDialog::closeEvent(QCloseEvent *event) //If the user press the "X" close button
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
