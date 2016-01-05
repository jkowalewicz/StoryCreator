// Copyright (C), 2016 Jan Kowalewicz.

#include "helper.hpp"
#include "logger.hpp"
#include "main_window.hpp"
#include <QApplication>

using namespace stc;

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	MainWindow window;
	window.show();

	// TEST TEST TEST
	INIFile *inifile = new INIFile("C:\\Users\\Jan\\Desktop\\test34.abcdef");
	// window.setWindowTitle( inifile->getValue("window_title") );
	// inifile->writeValue("window_title", "Hallo Welt!");
	// window.setWindowTitle( inifile->getValue("window_title") );

	Logger *logger = new Logger("C:\\Users\\Jan\\Desktop\\app.log");
	// logger->reportError("main(int , char *)", "This is an error message!");
	// logger->reportWarning("main(int , char *)", "This is a warning!");
	// window.setWindowTitle( logger->reportInfo("main(int , char *)", "Very informative message!"));

	int ret = app.exec();
	return ret;
}