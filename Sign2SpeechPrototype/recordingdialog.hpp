﻿#pragma once
#include <QWidget>
#include <mutex>
#include <vector>
#include "ui_recordingdialog.h"
#include "pxcimage.h"
#include "pxchanddata.h"
#include "qpainter.h"
#include "qscrollbar.h"
#include "reviewdialog.hpp"

using namespace std;

class recordingDialog : public QWidget {
	Q_OBJECT

public:
	recordingDialog(int nbGesture, QWidget * parent = Q_NULLPTR);
	void manageThreads(condition_variable *cond_var, bool *program_on_recording);
	void setParent(QWidget* p) { parent = p; }
	void pushMessage(QString msg);
	void setDepthImage(PXCImage* image);
	void setRecognizedPoints(PXCHandData::IHand *hand, QColor color);
	void displayDepthImage();
	void askValidation(int i);
	bool getAnswer() { return answer; }
	void setAnswer(bool a) { answer = a; }
	Ui::recordingDialog getUi() { return ui; }
	~recordingDialog();

	private slots:
	void on_pushButtonDoAgain_clicked();
	void on_pushButtonContinue_clicked();
	void closeEvent(QCloseEvent *event);

private:
	Ui::recordingDialog ui;
	bool answer = NULL;
	QWidget* parent;
	QPixmap currentPixmap;
	QMatrix reverse;
	bool *program_on;
	vector < reviewDialog* > t;
	condition_variable * conditionVar;

	mutex mUIWrite;
};
