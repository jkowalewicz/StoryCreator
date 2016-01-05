// Copyright (C), 2016 Jan Kowalewicz.

// TODO: learn off-stream more about const :D

#ifndef __helper_hpp__
#define __helper_hpp__

#include "logger.hpp"
#include <QString>

namespace stc
{

class INIFile
{
public:
	INIFile(QString _file_path);
	~INIFile();

	Logger *logger;

	QString getValue(QString keyword);
	bool writeValue(QString keyword, QString new_value);

protected:
	bool iniFileExists();
	QString file_path;

private:
	QString _getValue(QString keyword);
	bool _writeValue(QString keyword, QString new_value);
};

class Translator
{
public:
	QString getWord(QString id);

protected:
	QString getCurrentLanguage();
};

} // namespace stc

#endif // __helper_hpp__