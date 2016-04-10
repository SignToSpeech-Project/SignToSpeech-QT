#include "sign2speechprototype.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Sign2SpeechPrototype w;
	w.show();
	return a.exec();
}
