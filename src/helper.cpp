// Copyright (C), 2016 Jan Kowalewicz.

#include "helper.hpp"
#include "logger.hpp"
#include <QString>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QFileInfo>

namespace stc
{

const QString settings_file_path(QDir::currentPath() + "/ApplicationSettings.ini");

// INIFile
INIFile::INIFile(QString _file_path) : file_path(_file_path)
{
	logger = new Logger(QDir::currentPath() + "/Default.log");
	if (!iniFileExists())
	{
		logger->reportError("INIFile(QString)", "The INI file was not found.");
		// TODO: (jan) The file doesn't exists. What now?
	}
}

INIFile::~INIFile()
{
	logger->reportInfo("~INIFile()", "Destructor called.");
}

QString INIFile::getValue(QString keyword)
{
	return this->_getValue(keyword);
}

bool INIFile::writeValue(QString keyword, QString new_value)
{
	return this->_writeValue(keyword, new_value);
}

//////////////////////////////////////////////////////////////////////////
bool INIFile::iniFileExists()
{
	QFileInfo check(file_path);
	return check.exists();
}

//////////////////////////////////////////////////////////////////////////
QString INIFile::_getValue(QString keyword)
{
	QFile f(file_path);
	if (f.open ( QIODevice::ReadOnly ))
	{
		QTextStream in(&f);
		while (!in.atEnd())
		{
			QString line = in.readLine();
			QString _keyword(keyword + " = ");
			int keyword_position = line.indexOf(_keyword);
			if (keyword_position >= 0)
			{
				return line.mid(keyword_position + _keyword.length());
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////
bool INIFile::_writeValue(QString keyword, QString new_value)
{
	// KISS: Simply open the file, read content, get old value
	// replace old value with new and write back.
	QString content;
	QString old_value = this->_getValue(keyword);
	QFile f(file_path);
	if (f.open( QIODevice::ReadWrite ))
	{
		QTextStream rd(&f);
		content = rd.readAll();
	}
	f.resize(0);
	f.close();

	QString old_line_we_want(keyword + " = " + old_value);
	QString new_line_we_want(keyword + " = " + new_value);
	content.replace(old_line_we_want, new_line_we_want);
	if (f.open( QIODevice::ReadWrite ))
	{
		QTextStream wr(&f);
		wr << content;
		return true;
	}
}

// Translator
QString Translator::getWord(QString id)
{
	QString language_file_path(":/" + this->getCurrentLanguage() + ".lang");
	INIFile *ini_file = new INIFile(language_file_path);
	return ini_file->getValue(id);
}

//////////////////////////////////////////////////////////////////////////
QString Translator::getCurrentLanguage()
{
	// Simply load that from the settings file.
	INIFile *ini_file = new INIFile(settings_file_path);
	return ini_file->getValue("language");
}

}