/*
*
* 	LOGGER.CPP
*	Logger class
*
*
*   (C) Alessio Saltarin 2001
*/


#include "logger.h"
#include <ctime>
#include <string>
#include <sstream>

using namespace std;

Logger::Logger(const char *filelog) : _logfile(filelog)
{
	fm = FileManager::Instance();
}

string Logger::formatted_time()
{
	time_t timer;
	ostringstream logstring;

	timer=time(NULL);
	logstring << ">" << asctime(localtime(&timer)) << ":" << ends;

	return logstring.str();
}


void Logger::log(const char* msg)
{
	string datetimestr = formatted_time();
	fm->AppendFile(_logfile,datetimestr.c_str());
	fm->AppendFile(_logfile,msg);
	fm->AppendFile(_logfile,"\n");
}

/*
int test()
{
	Logger *l = new Logger("log.txt");
	l->log("Prova1");
	l->log("Prova2");
	delete l;

	return EXIT_SUCCESS;
}
*/
