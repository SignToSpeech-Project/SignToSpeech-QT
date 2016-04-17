#pragma once
#ifndef NDIALOG_H
#define NDIALOG_H

#include <QWidget>
#include <vector>
#include <mutex>
#include "ui_normaldialog.h"

using namespace std;

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

	mutex mBufferR; //Mutex for the Reading buffer
	mutex mSymbolSent; //Mutex for the boolean SymbolSent 
	bool symbolSent; //To know if the Dictionnary sent a word on WebRTC
	vector<long> bufferRead; //Buffer of words that will be sent on WebRTC
	string address;
	string room;


//	void reject();
};
#endif