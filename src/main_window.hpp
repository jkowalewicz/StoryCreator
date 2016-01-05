// Copyright (C), 2016 Jan Kowalewicz.

#ifndef __main_window_hpp__
#define __main_window_hpp__

#include "helper.hpp"
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QMenuBar>
#include <QMenu>

namespace stc
{

class MainWindow : public QMainWindow
{
public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

	Translator *translator;

	QMenuBar *menu_bar;
	QMenu *file_menu;
	QMenu *edit_menu;
	QMenu *view_menu;
	QMenu *document_menu;
	QMenu *window_menu;
	QMenu *help_menu;

private:
	void initMenuBar();
};

} // namespace stc

#endif // __main_window_hpp__