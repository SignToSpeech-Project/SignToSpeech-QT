#pragma once
#include <QWidget>
#include "ui_learningdialog.h"

class learningDialog : public QWidget {
	Q_OBJECT

public:
	learningDialog(QWidget * parent = Q_NULLPTR);
	~learningDialog();

	void setParent(QWidget* p) { parent = p; }

private slots:
	void on_pushButtonValidation_clicked();
	void on_pushButtonQuit_clicked();
	void closeEvent(QCloseEvent *event);

private:
	QWidget* parent;
	Ui::learningDialog ui;
};
