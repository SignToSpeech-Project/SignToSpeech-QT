#pragma once
#ifndef NDIALOG_H
#define NDIALOG_H

#include <QWidget>
#include <vector>
#include <mutex>
#include "roomdialog.hpp"
#include "ui_normaldialog.h"

using namespace std;

class normalDialog : public QWidget {
	Q_OBJECT

public:
	normalDialog(QWidget * parent = Q_NULLPTR);
	~normalDialog();
	mutex * getMBufferR() { return &mBufferR; }
	mutex * getMSymbolSent() { return &mSymbolSent; }
	bool * getSymbolSent() { return &symbolSent; }
	bool * getPG() { return &program_on; }
	bool * getPGR() { return &program_on_room; }
	condition_variable * getCondGui() { return &cond_var_gui; }
	vector<long> * getBufferRead() { return &bufferRead; }
	roomDialog * getRD() { return rD; }
	void setParent(QWidget* p) { parent = p; }

private slots:
	void on_pushButtonEnter_clicked();
	void on_pushButtonQuit_clicked();
	void closeEvent(QCloseEvent *event);


private:
	Ui::normalDialog ui;
	QWidget* parent;


	void  static threadDico(normalDialog * rD);
	void static threadHandTools(mutex *mBR, mutex *mSS, bool* pg, bool * bro, vector<long>* bR, string *ad, string *r, bool *sS, condition_variable *cD);

	std::thread* tHandTools = new std::thread(threadHandTools, &mBufferR, &mSymbolSent, &program_on, &program_on_room, &bufferRead, &address, &room, &symbolSent, &cond_var_gui);
	std::thread* tDico = new std::thread(threadDico, this);


	mutex mBufferR; //Mutex for the Reading buffer
	mutex mSymbolSent; //Mutex for the boolean SymbolSent 
	bool symbolSent; //To know if the Dictionnary sent a word on WebRTC
	vector<long> bufferRead; //Buffer of words that will be sent on WebRTC
	string address;
	string room;

	bool program_on = true; //to stop threads
	bool program_on_room = false; //To know when the recording dialog is running

	condition_variable cond_var_gui; //To tell to threads when the GUI is ready

	roomDialog * rD;




//	void reject();
};
#endif