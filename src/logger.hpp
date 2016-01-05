// Copyright (C), 2016 Jan Kowalewicz.

#ifndef __logger_hpp__
#define __logger_hpp__

#include <QString>

namespace stc
{

class Logger
{
public:
	Logger(QString _log_file_path);
	~Logger();

	void reportError(QString function, QString description);
	void reportWarning(QString function, QString description);
	QString reportInfo(QString function, QString description);

protected:
	void write(const QString content);
	bool logFileExists();
	QString log_file_path;
};

} // namespace stc

#endif // __logger_hpp__