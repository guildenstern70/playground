/*
*
* 	FILEMANAGER.CPP
*	FileManager class
*
*	(C) Alessio Saltarin 2001
*
*/


#include "filemanager.h"
#include "require.h"

#include <string>
#include <fstream>
#include <iostream>


FileManager::FileManager()
{
}

FileManager* FileManager::_instance=0;

FileManager* FileManager::Instance()
{
	if (_instance==0)
	{
		_instance = new FileManager;
	}

	return _instance;
}

void FileManager::SaveFile(const char *nomefile, const char *contenuto)
{
	ofstream out(nomefile);
	assure(out, nomefile);
	out << contenuto;
}

void FileManager::AppendFile(const char *nomefile, const char *contenuto)
{
	ofstream out(nomefile,ios::app);
	assure(out, nomefile);
	out << contenuto;
}

string FileManager::LoadFile(const char *nomefile)
{

	char buf[MAXCHARSFORFILE];
	string outstring;

	ifstream in(nomefile);
	assure(in, nomefile);


	while(in.getline(buf, MAXCHARSFORFILE))
	{
	    outstring += buf;
	    outstring += "\n";
	}

	return outstring;

}

