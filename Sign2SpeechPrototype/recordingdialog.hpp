#pragma once
#include <QWidget>
#include "ui_recordingdialog.h"
#include <mutex>
using namespace std;

class recordingDialog : public QWidget {
	Q_OBJECT

public:
	recordingDialog(QWidget * parent = Q_NULLPTR);
	void manageThreads(condition_variable *cond_var, bool *program_on_recording);
	void setParent(QWidget* p) { parent = p; }
	void pushMessage(QString msg);
	~recordingDialog();

private slots :
	void closeEvent(QCloseEvent *event);

private:
	Ui::recordingDialog ui;
	QWidget* parent;

	bool *program_on;
};
