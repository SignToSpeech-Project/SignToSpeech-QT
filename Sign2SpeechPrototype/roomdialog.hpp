#pragma once
#include <QWidget>
#include "ui_roomdialog.h"

class roomDialog : public QWidget {
	Q_OBJECT

public:
	roomDialog(QWidget * parent = Q_NULLPTR);
	~roomDialog();
	void setInfo(QString s) { info = s; ui.labelRoom->setText(info); }
	void setParent(QWidget* p) { parent = p; }

private slots:
	void on_pushButtonLeave_clicked();
	void closeEvent(QCloseEvent *event);

private:
	QString info;
	Ui::roomDialog ui;
	QWidget* parent;
};
