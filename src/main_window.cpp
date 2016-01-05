// Copyright (C), 2016 Jan Kowalewicz.

#include "main_window.hpp"
#include <QMainWindow>
#include <QObject>
#include <QWidget>

namespace stc
{

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent, Qt::CustomizeWindowHint)
{
	// TODO: (jan) Setup menu bar, setup menus and setup the layout.
	this->initMenuBar();
}

MainWindow::~MainWindow()
{
	// TODO: (jan) Is this required?
}

//////////////////////////////////////////////////////////////////////////
void MainWindow::initMenuBar()
{
	menu_bar = new QMenuBar(this);
	file_menu = new QMenu(translator->getWord( "file_menu_name" ), this);
	edit_menu = new QMenu(translator->getWord( "edit_menu_name" ), this);
	view_menu = new QMenu(translator->getWord( "view_menu_name" ), this);
	document_menu = new QMenu(translator->getWord( "document_menu_name" ), this);
	window_menu = new QMenu(translator->getWord( "window_menu_name" ), this);
	help_menu = new QMenu(translator->getWord( "help_menu_name" ), this);

	menu_bar->addMenu(file_menu);
	menu_bar->addMenu(edit_menu);
	menu_bar->addMenu(view_menu);
	menu_bar->addMenu(document_menu);
	menu_bar->addMenu(window_menu);
	menu_bar->addMenu(help_menu);

	this->setMenuBar(menu_bar);
}

} // namespace stc