#pragma once
#include <QWidget>
#include "ui_normaldialog.h"

class normalDialog : public QWidget {
	Q_OBJECT

public:
	normalDialog(QWidget * parent = Q_NULLPTR);
	~normalDialog();
	void setParent(QWidget* p) { parent = p; }

private slots:
	void on_pushButtonEnter_clicked();
	void on_pushButtonQuit_clicked();
	void closeEvent(QCloseEvent *event);


private:
	Ui::normalDialog ui;
	QWidget* parent;
//	void reject();
};
