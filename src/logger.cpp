// Copyright (C), 2016 Jan Kowalewicz.

#include "logger.hpp"
#include <QString>
#include <QTextStream>
#include <QFileInfo>

namespace stc
{

Logger::Logger(QString _log_file_path) : log_file_path(_log_file_path)
{
	if (!logFileExists())
	{
		// TODO: Create a log file.
		// INFO: Normally the log file is automatically created during call of write().
		// TODO: Dive a little bit more into this.
	}
}

Logger::~Logger()
{

}

void Logger::reportError(QString function, QString description) { this->write("ERROR: <" + function + ">, " + description); }
void Logger::reportWarning(QString function, QString description) { this->write("WARNING: <" + function + ">, " + description); }
QString Logger::reportInfo(QString function, QString description)
{
	// The description could also be an informative message to the user.
	this->write("INFO: <" + function + ">, " + description);
	return description;
}

//////////////////////////////////////////////////////////////////////////
void Logger::write(const QString content)
{
	QFile f(log_file_path);
	if (f.open( QIODevice::Append ))
	{
		QTextStream wr(&f);
		wr << content << endl;
	}
}

//////////////////////////////////////////////////////////////////////////
bool Logger::logFileExists()
{
	QFileInfo check(log_file_path);
	return check.exists();
}

} // namespace stc