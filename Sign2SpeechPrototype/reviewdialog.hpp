#pragma once
#include <QWidget>
#include <qdialog.h>
#include "ui_reviewdialog.h"

class reviewDialog : public QDialog {
	Q_OBJECT

public:
	reviewDialog (bool * as, QWidget * parent = Q_NULLPTR);
	~reviewDialog();

private:
	Ui::reviewDialog ui;

	bool *answer;

private slots :
	void on_pushButtonDoAgain_clicked();
	void on_pushButtonContinue_clicked();
};
