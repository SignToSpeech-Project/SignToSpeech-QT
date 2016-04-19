#pragma once
#include <QWidget>
#include "ui_roomdialog.h"
#include "pxcimage.h"
#include "pxchanddata.h"
#include "qpainter.h"
#include "qscrollbar.h"
#include <mutex>
using namespace std;

class roomDialog : public QWidget {
	Q_OBJECT

public:
	roomDialog(QWidget * parent = Q_NULLPTR);
	~roomDialog();
	void setInfo(QString s) { info = s; ui.labelRoom->setText(info); }
	void setParent(QWidget* p) { parent = p; }
	void pushMessage(QString msg);
	void setDepthImage(PXCImage* image);
	void setRecognizedPoints(PXCHandData::IHand *hand, QColor color);
	void displayDepthImage();
	void manageThreads(condition_variable *cond_var, bool *program_on_recording);

private slots:
	void on_pushButtonLeave_clicked();
	void closeEvent(QCloseEvent *event);

private:
	QString info;
	Ui::roomDialog ui;
	QWidget* parent;
	QPixmap currentPixmap;
	QMatrix reverse;
	bool *program_on;
};
