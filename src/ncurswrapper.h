/*
*
* 	NCURSWRAPPER.H
*	Header for the class NCursWrapper
*
*   (C) Alessio Saltarin 2001
*
*/

#ifndef __NCURSWRAPPER__
#define __NCURSWRAPPER__

#include "logger.h"
#include "gamelogic.h"
#include <ncurses.h>    // must be the last one. 'curses::erase' conflicts with 'vector::erase'

typedef unsigned int UINT;


/*
* The class sets and defines the NCURSES windows geometry
*/
class NCursGeometry
{
public:
	void initgeometry();

protected:
	UINT terminal_cols;
	UINT terminal_rows;
	UINT rows_play;
	UINT cols_play;
	UINT begy_play;
	UINT begx_play;
	UINT rows_stat;
	UINT cols_stat;
	UINT begy_stat;
	UINT begx_stat;
	UINT rows_feed;
	UINT cols_feed;
	UINT begy_feed;
    UINT begx_feed;
};



/*
* The class manages the three NCURSES windows for play
*/
class NCursWindows : public NCursGeometry
{
public:
	void create_windows();
	void erase_all();
	void play_refresh();
	void all_refresh();
	void play_drawPedine(UINT y, UINT x);
protected:
	WINDOW *playground, *statusbar, *feedbackbar;
	void print(WINDOW* win, const char* message);
private:
	void disegnapedina(char pedina, unsigned short x, unsigned short y);
	void draw_panels();
};


/*
* The class wraps everything between game and NCURSES terminal
*/
class NCursWrapper : public NCursWindows
{
public:

	NCursWrapper();

	void initialize();
	int go();
	void finalize(int sig);
	~NCursWrapper();

protected:
	GameLogic* game;
	Logger* log;
	int _oldcursor;

	void creaomino(char omino, WINDOW *win);
	void gameloop();
	bool fetchMovement(int tasto); // true, if a command movement is issued
	void fetchCommand(int tasto);

};



#endif

