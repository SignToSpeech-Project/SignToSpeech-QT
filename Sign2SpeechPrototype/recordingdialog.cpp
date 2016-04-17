#include "recordingdialog.hpp"

recordingDialog::recordingDialog(QWidget * parent) : QWidget(parent) {
	ui.setupUi(this);

	// initialize a matric to reverse the pixmap
	reverse = reverse.scale(-1, 1);
}

recordingDialog::~recordingDialog() {

}

void recordingDialog::pushMessage(QString msg) {
	/*if (ui.textBrowser != NULL) {
	ui.textBrowser->append(msg);
	}*/

}

void recordingDialog::setDepthImage(PXCImage* image) {
	if (!image) return;

	PXCImage::ImageData data = {};
	PXCImage::Rotation rotation = image->QueryRotation();
	pxcStatus sts = image->AcquireAccess(PXCImage::ACCESS_READ, PXCImage::PIXEL_FORMAT_RGB32, rotation, PXCImage::OPTION_ANY, &data);
	if (sts >= PXC_STATUS_NO_ERROR) {
		PXCImage::ImageInfo iinfo = image->QueryInfo();
		if (rotation == PXCImage::ROTATION_90_DEGREE || rotation == PXCImage::ROTATION_270_DEGREE)
		{
			int w = iinfo.width;
			iinfo.width = iinfo.height;
			iinfo.height = w;
		}

		QImage temp((unsigned char*)data.planes[0], iinfo.width, iinfo.height, QImage::Format_RGB32);
		//mUIWrite.lock();
		currentPixmap = QPixmap::fromImage(temp);
		//ui.label->setPixmap(currentPixmap);
		//mUIWrite.unlock();
		image->ReleaseAccess(&data);
	}
}

void recordingDialog::setRecognizedPoints(PXCHandData::IHand *hand, QColor color) {
	PXCHandData::FingerData fingerData;
	PXCHandData::JointData nodes[PXCHandData::NUMBER_OF_JOINTS] = {};
	PXCHandData::ExtremityData extremitiesPointsNodes[PXCHandData::NUMBER_OF_EXTREMITIES] = {};

	PXCHandData::JointData jointData;

	//QPixmap pixmap = currentPixmap.copy();
	QPainter paint(&currentPixmap);
	paint.setPen(QPen(color, 3, Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin));

	//Iterate Joints
	for (int j = 0; j < PXCHandData::NUMBER_OF_JOINTS; j++)
	{
		hand->QueryTrackedJoint((PXCHandData::JointType)j, jointData);
		nodes[j] = jointData;
	}

	for (int j = 0; j < PXCHandData::NUMBER_OF_EXTREMITIES; j++)
	{
		hand->QueryExtremityPoint((PXCHandData::ExtremityType)j, extremitiesPointsNodes[j]);
	}

	int wristX = (int)nodes[0].positionImage.x;
	int wristY = (int)nodes[0].positionImage.y;

	int originX = wristX;
	int originY = wristY;

	for (int j = 1; j < PXCHandData::NUMBER_OF_JOINTS; ++j)
	{
		if (nodes[j].confidence == 0) continue;

		int x = (int)nodes[j].positionImage.x;
		int y = (int)nodes[j].positionImage.y;

		if (j == 10) {
			originX = nodes[1].positionImage.x;
			originY = nodes[1].positionImage.y;
		}

		paint.drawLine(originX, originY, x, y);

		if (j == 1 || j == 5 || j == 9 || j == 13 || j == 17 || j == 21){
			originX = wristX;
			originY = wristY;
		}
		else {
			originX = x;
			originY = y;
		}

	}//end for joints

	paint.setPen(QPen(color, 8, Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin));
	for (int j = 1; j < PXCHandData::NUMBER_OF_JOINTS; ++j)
	{
		if (nodes[j].confidence == 0) continue;

		int x = (int)nodes[j].positionImage.x;
		int y = (int)nodes[j].positionImage.y;

		paint.drawPoint(x, y);
	}

	paint.end();
}

void recordingDialog::displayDepthImage() {
	currentPixmap = currentPixmap.transformed(reverse);
	ui.label->setPixmap(currentPixmap);
}

void recordingDialog::manageThreads(condition_variable *cond_var, bool *program_on_recording) {
	program_on = program_on_recording;
	*program_on = true;
	cond_var->notify_one(); //To notify ThreadHandTools that it can start recording
}

void recordingDialog::closeEvent(QCloseEvent *event) {
	*program_on = false;
	parent->show();

}
