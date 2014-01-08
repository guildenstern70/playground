/*
*
* 	FILEMANAGER.H
*	FileManager Header
*
*	(C) Alessio Saltarin 2001
*
*/

#ifndef __FILEMANAGERH__
#define __FILEMANAGERH__

#include <string>

using namespace std;

class FileManager
{

public:

	static FileManager* Instance();
	void SaveFile(const char *nomefile, const char *contenuto);
	void AppendFile(const char *nomefile, const char *contenuto);
	string LoadFile(const char *nomefile);

protected:

	FileManager();

private:

	static FileManager* _instance;
	static const int MAXCHARSFORFILE = 15000;

};


#endif
