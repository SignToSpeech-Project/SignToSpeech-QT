#ifndef SIGN2SPEECHPROTOTYPE_H
#define SIGN2SPEECHPROTOTYPE_H

#include <QtWidgets/QMainWindow>
#include "ui_sign2speechprototype.h"

class Sign2SpeechPrototype : public QMainWindow
{
	Q_OBJECT

public:
	Sign2SpeechPrototype(QWidget *parent = 0);
	~Sign2SpeechPrototype();

private slots:
	void on_pushButtonRecognition_clicked(); 
	void on_pushButtonLearning_clicked();

private:
	Ui::Sign2SpeechPrototypeClass ui;
};

#endif // SIGN2SPEECHPROTOTYPE_H
