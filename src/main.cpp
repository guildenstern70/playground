/*
*
* PLAYGROUND.CPP
* by Alessio Saltarin (2001)
*
* Framework for intelligent games
*
*/

#include "ncurswrapper.h"

int main(int, char** )
{
	NCursWrapper *curses = new NCursWrapper();
	curses->go();
	delete curses;

	return 0;
}
