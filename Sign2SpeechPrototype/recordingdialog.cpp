#include "recordingdialog.hpp"

recordingDialog::recordingDialog(QWidget * parent) : QWidget(parent) {
	ui.setupUi(this);
}

recordingDialog::~recordingDialog() {
	
}

void recordingDialog::pushMessage(QString msg) {
	/*if (ui.textBrowser != NULL) {
		ui.textBrowser->append(msg);
	}*/
}

void recordingDialog::displayDepthImage(PXCImage* image) {
	if (!image) return;

	//EnterCriticalSection(&cs);
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
		
		QImage temp((unsigned char*)data.planes[0], iinfo.width, iinfo.height, QImage::Format_RGB888);
		QPixmap pixmap = QPixmap::fromImage(temp.rgbSwapped());
		ui.label->setPixmap(pixmap);

		/*HRESULT hr = E_FAIL;
		if (this->bitmap) {
			D2D1_SIZE_U bsize = this->bitmap->GetPixelSize();
			if (bsize.width == iinfo.width && bsize.height == iinfo.height) {
				hr = this->bitmap->CopyFromMemory((const D2D1_RECT_U*)&D2D1::RectU(0, 0, iinfo.width, iinfo.height), data.planes[0], data.pitches[0]);
				if (SUCCEEDED(hr)) UpdatePanel(this->bitmap);
			}
		}
		if (FAILED(hr)) {
			D2D1_BITMAP_PROPERTIES properties = D2D1::BitmapProperties(D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_IGNORE));
			CComPtr<ID2D1Bitmap> bitmap1;
			HRESULT hr = context2->CreateBitmap(D2D1::SizeU(iinfo.width, iinfo.height), data.planes[0], data.pitches[0], properties, &bitmap1);
			if (SUCCEEDED(hr)) UpdatePanel(bitmap1);
		}*/
		image->ReleaseAccess(&data);
	}
	//LeaveCriticalSection(&cs);
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
