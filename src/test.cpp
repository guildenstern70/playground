/*
*
* TEST ALL
* by Alessio Saltarin (2001)
*
*/

#include "filemanager.h"

int main(int, char**)
{
	FileManager *fm = FileManager::Instance();
	fm->SaveFile("newtext.txt","Prova\nProva\n");
	fm->AppendFile("newtext.txt","Aggiunta!!!\n");
	cout << fm->LoadFile("newtext.txt");
	exit(0);
	return 0;
}