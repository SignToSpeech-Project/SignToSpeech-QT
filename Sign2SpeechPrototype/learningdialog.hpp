	#pragma once

#ifndef LDIALOG_H
#define LDIALOG_H
#include <QWidget>
#include <string>
#include <iostream>
#include "ui_learningdialog.h"
#include "ThreadLearningDictionary.h"
#include "ThreadLearningHandTools.h"
#include "recordingdialog.hpp"

using namespace std;





class learningDialog : public QWidget {
	Q_OBJECT

public:
	learningDialog(QWidget * parent = Q_NULLPTR);
	recordingDialog* getRD() { return rD; }
	bool * getPg() { return &program_on; }
	bool * getPgr() { return &program_on_recording; }
	string * getMeaning() { return &meaningWord; }
	int * getNbGestures() { return &nbGestures; }
	std::mutex * getMutexW() { return &mBufferW; }
	vector<vector<pair<string, long>>> * getBufferWrite() {	return &bufferWrite; }
	condition_variable * getCondGui() { return &cond_var_gui; }
	condition_variable * getCondDico() { return &cond_var_dico; }

	~learningDialog();
	
	void setParent(QWidget* p) { parent = p; }

private slots:
	void on_pushButtonValidation_clicked();
	void on_pushButtonQuit_clicked();
	void closeEvent(QCloseEvent *event);

private:
	QWidget* parent;
	Ui::learningDialog ui;
	void  static threadHandTools(learningDialog * rD);
	void static threadDico(bool *program_on, std::mutex* mBufferW, vector<vector<pair<string, long>>>* bufferWrite, condition_variable *cond_var_dico);

	std::thread* tHandTools = new std::thread(threadHandTools, this);
	std::thread* tDico = new std::thread(threadDico, &program_on, &mBufferW, &bufferWrite, &cond_var_dico);


	//Items for threads
	bool program_on = true; //to stop threads
	bool program_on_recording = false; //To know when the recording dialog is running
	std::mutex mBufferW; //Buffer of symbols chain you need to add to the dictionary ( Learning mod ON)
	vector<vector<pair<string, long>>> bufferWrite;
	condition_variable cond_var_gui; //To tell to threads when the GUI is ready
	condition_variable cond_var_dico; //To tell to Dictionary when a word ready to be added in the Dictionary
	recordingDialog* rD; //Windows to show informations
	string meaningWord;
	int nbGestures;
};
#endif