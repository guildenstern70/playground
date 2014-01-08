/*
*
* 	LOGGER.H
*	Logger class
*
*	(C) Alessio Saltarin 2001
*
*/

#ifndef __LOGGERH__
#define __LOGGERH__

#include "filemanager.h"

#include <string>

using namespace std;

class Logger
{
public:

	Logger(const char* filelog);
	void log(const char *msg);

private:
	string formatted_time();
	FileManager *fm;
	const char *_logfile;

};

#endif


