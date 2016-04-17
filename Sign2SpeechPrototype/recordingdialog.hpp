#pragma once
#include <QWidget>
#include "ui_recordingdialog.h"
#include "pxcimage.h"
#include "pxchanddata.h"
#include "qpainter.h"
#include <mutex>
using namespace std;

class recordingDialog : public QWidget {
	Q_OBJECT

public:
	recordingDialog(QWidget * parent = Q_NULLPTR);
	void manageThreads(condition_variable *cond_var, bool *program_on_recording);
	void setParent(QWidget* p) { parent = p; }
	void pushMessage(QString msg);
	void setDepthImage(PXCImage* image);
	void setRecognizedPoints(PXCHandData::IHand *hand, QColor color);
	void displayDepthImage();
	Ui::recordingDialog getUi() { return ui; }
	~recordingDialog();

	private slots :
	void closeEvent(QCloseEvent *event);

private:
	Ui::recordingDialog ui;
	QWidget* parent;
	QPixmap currentPixmap;
	QMatrix reverse;
	bool *program_on;

	mutex mUIWrite;
};
