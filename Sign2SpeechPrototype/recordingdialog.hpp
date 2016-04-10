#pragma once
#include <QWidget>
#include "ui_recordingdialog.h"

class recordingDialog : public QWidget {
	Q_OBJECT

public:
	recordingDialog(QWidget * parent = Q_NULLPTR);
	void manageThreads(QString word, int nbGesture);
	void setParent(QWidget* p) { parent = p; }
	~recordingDialog();

private slots :
	void closeEvent(QCloseEvent *event);

private:
	Ui::recordingDialog ui;
	bool program_on = true;
	QWidget* parent;
};
