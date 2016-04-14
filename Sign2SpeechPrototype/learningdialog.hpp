#pragma once
#include <QWidget>
#include <string>
#include <iostream>
#include "ui_learningdialog.h"
#include "ThreadLearningDictionary.h"
#include "ThreadLearningHandTools.h"

using namespace std;





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
	void  static threadHandTools(string * s, int * v, bool *program_on, bool *program_on_recording, std::mutex* mBufferW, vector<vector<pair<string, long>>>* bufferWrite, condition_variable *cond_var_gui, condition_variable *cond_var_dico,recordingDialog* rD);
	void static threadDico(bool *program_on, std::mutex* mBufferW, vector<vector<pair<string, long>>>* bufferWrite, condition_variable *cond_var_dico);

	std::thread* 	tHandTools = new std::thread(threadHandTools, &meaningWord, &nbGestures, &program_on, &program_on_recording, &mBufferW, &bufferWrite, &cond_var_gui,&cond_var_dico, rD);
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
