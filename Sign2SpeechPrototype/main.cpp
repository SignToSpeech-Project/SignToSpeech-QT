#include "sign2speechprototype.h"
#include <QtWidgets/QApplication>
#include <Windows.h>
#include <iostream>

int main(int argc, char *argv[])
{
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	QApplication a(argc, argv);	
	Sign2SpeechPrototype w;
	w.show();
	return a.exec();


}
