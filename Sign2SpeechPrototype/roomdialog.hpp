#pragma once
#include <QWidget>
#include <mutex>
#include "ui_roomdialog.h"

using namespace std;

class roomDialog : public QWidget {
	Q_OBJECT

public:
	roomDialog(QWidget * parent = Q_NULLPTR);
	~roomDialog();
	void setInfo(QString s) { info = s; ui.labelRoom->setText(info); }
	void setParent(QWidget* p) { parent = p; }

	void manageThreads(condition_variable *cond_var, bool *program_on_recording);

private slots:
	void on_pushButtonLeave_clicked();
	void closeEvent(QCloseEvent *event);

private:
	QString info;
	Ui::roomDialog ui;
	QWidget* parent;
	bool *program_on;
};
