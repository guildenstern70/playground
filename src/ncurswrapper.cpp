/*
*
* 	NCURSWRAPPER.CPP
*	NCursWrapper class
*
*   (C) Alessio Saltarin 2001
*
*/

#include "ncurswrapper.h"
#include "signal.h"
#include "omino.h"
#include <string>
#include <sstream>

//#define DEBUG
#define WITH_LOG

#define FOREVER	for(;;)

using namespace std;


/********************************** NCURSGEOMETRY ************************************/

void NCursGeometry::initgeometry()
{
	terminal_cols = COLS;
	terminal_rows = LINES;

	rows_play = terminal_rows-4;
	cols_play = terminal_cols-22;
	begy_play = 0;
	begx_play = 0;

	rows_stat = 4;
	cols_stat = terminal_cols-22;
	begy_stat = begy_play+rows_play;
	begx_stat = 0;

	rows_feed = terminal_rows;
	cols_feed = 20;
	begy_feed = 0;
	begx_feed = begx_play+cols_play+1;
}

/********************************** NCURSWINDOWS ************************************/

void NCursWindows::create_windows()
{
	playground  = newwin(rows_play, cols_play, begy_play, begx_play);
	statusbar   = newwin(rows_stat, cols_stat, begy_stat, begx_stat);
	feedbackbar = newwin(rows_feed, cols_feed, begy_feed, begx_feed);

	draw_panels();
}

void NCursWindows::erase_all()
{
	werase(playground);
	werase(statusbar);
	werase(feedbackbar);
}

void NCursWindows::play_refresh()
{
	box(playground,ACS_VLINE,ACS_HLINE);
	wnoutrefresh(playground);
	doupdate();
}

void NCursWindows::all_refresh()
{
	box(playground,ACS_VLINE,ACS_HLINE);
	wnoutrefresh(statusbar);
	wnoutrefresh(feedbackbar);
	wnoutrefresh(playground);  // MUST BE THE LAST ONE!
	doupdate();
}

void NCursWindows::play_drawPedine(UINT y, UINT x)
{
	disegnapedina('@',y,x);
}

void NCursWindows::disegnapedina(char pedina, unsigned short y, unsigned short x)
{
	mvwaddch(playground,y,x,pedina|COLOR_PAIR(3));
}

void NCursWindows::draw_panels()
{

	erase_all();

	wnoutrefresh(stdscr);

	box(playground,ACS_VLINE,ACS_HLINE);
	wnoutrefresh(playground);

	box(statusbar,ACS_VLINE,ACS_HLINE);
	wnoutrefresh(statusbar);

	box(feedbackbar,ACS_VLINE,ACS_HLINE);
	wnoutrefresh(feedbackbar);

	doupdate();

	print(statusbar,"STATUS");
	print(feedbackbar,"COMMANDS");

	play_refresh();

}

void NCursWindows::print(WINDOW* win, const char* message)
{
	mvwaddstr(win,1,1,(char *)message);
}



/********************************** NCURSWRAPPER ************************************/

NCursWrapper::NCursWrapper()
{
	playground = NULL;
	statusbar = NULL;
	feedbackbar = NULL;

	terminal_cols = 0;
	terminal_rows = 0;

#ifdef WITH_LOG
    const char* logfile = "execlog.txt";
    const char* initmsg = "Inizializzato NCursWrapper.";
	log = new Logger(logfile);
	log->log(initmsg);
#endif

}

NCursWrapper::~NCursWrapper()
{
#ifdef WITH_LOG
	log->log("Distrutto NCursWrapper.");
	delete log;
#endif

}

void NCursWrapper::finalize(int sig)
{
	curs_set(_oldcursor);
	delwin(playground);
   	delwin(statusbar);
   	delwin(feedbackbar);
	endwin();
	delete game;
}

void NCursWrapper::initialize()
{

    initscr();      		/* initialize the curses library */
    nonl();         		/* tell curses not to do NL->CR/NL on output */
    cbreak();       		/* take input chars one at a time, no wait for \n */
    noecho();         		/* echo input - in color */
    _oldcursor = curs_set(0);	/* invisible cursor */
#ifdef WITH_LOG
	ostringstream logstr;
	if (_oldcursor==ERR)
		logstr << "Cannot set invisibile cursor on this terminal " << ends;
	else
		logstr << "Invisible cursor set. " << ends;
	log->log(logstr.str().c_str());
#endif

  	initgeometry();

#ifdef DEBUG
	ostrstream playstr;
	playstr << "Playground: " << rows_play << "," << cols_play << "," << begy_play << "," << begx_play << ".";
	ostrstream statstr;
	statstr << "Statistics: " << rows_stat << "," << cols_stat << "," << begy_stat << "," << begx_stat << ".";
	ostrstream feedstr;
	feedstr << "Feedback  : " << rows_feed << "," << cols_feed << "," << begy_feed << "," << begx_feed << ".";

	log->log(playstr.str());
	log->log(statstr.str());
	log->log(feedstr.str());
#endif

    create_windows();

    keypad(playground, TRUE);   /* enable keyboard mapping on playground */

    if (has_colors())
    {
        start_color();

        init_pair(1, COLOR_RED,     COLOR_BLACK);
        init_pair(2, COLOR_GREEN,   COLOR_BLACK);
        init_pair(3, COLOR_YELLOW,  COLOR_BLACK);
        init_pair(4, COLOR_BLUE,    COLOR_BLACK);
        init_pair(5, COLOR_CYAN,    COLOR_BLACK);
        init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(7, COLOR_WHITE,   COLOR_BLACK);
    }

    // Initializing game
    game = new GameLogic(cols_play,rows_play);
    game->setboard(cols_play,rows_play);

}


void NCursWrapper::gameloop()
{

	long c=0;
	int keypressed;
	char conta[50];
	char doveomino[20];
	char cella[20];

	play_drawPedine(game->getomino()->getY(),game->getomino()->getX());

	FOREVER
	{

		c++;

		sprintf(conta,"Mossa : %ld",c);
		sprintf(doveomino,"Omino : (%2d,%2d)",game->getomino()->getX(),game->getomino()->getY());
		sprintf(cella,"Cella: [%2d,%2d]",game->getcurrentcolor(), game->getcurrentvalue());

		mvwaddstr(statusbar,2,1,conta);
		mvwaddstr(feedbackbar,3,1,doveomino);
		mvwaddstr(feedbackbar,6,1,cella);

		all_refresh();

		keypressed = wgetch(playground);

		if (fetchMovement(keypressed))
		{
				werase(playground);
				play_drawPedine(game->getomino()->getY(),game->getomino()->getX());
		}

		fetchCommand(keypressed);

		if (game->isended())
			break;

		play_refresh();

	}

#ifdef WITH_LOG
	log->log("Game is ended.");
#endif
	print(statusbar,"Game is ended.");
	all_refresh();

}

bool NCursWrapper::fetchMovement(int tasto)
{

	bool movement_command = false;
	Direzione where;

	switch (tasto)
	{
		case KEY_UP: case '8':
			movement_command = true;
			where=N;
			break;

		case KEY_DOWN: case '2':
			movement_command = true;
			where=S;
			break;

		case KEY_LEFT: case '4':
			movement_command = true;
			where=W;
			break;

		case KEY_RIGHT: case '6':
			movement_command = true;
			where=E;
			break;

		case KEY_HOME: case '7':
			movement_command = true;
			where=NW;
			break;

		case KEY_PPAGE: case '9':
			movement_command = true;
			where=NE;
			break;

		case KEY_END: case '1':
			movement_command = true;
			where=SW;
			break;

		case KEY_NPAGE: case '3':
			movement_command = true;
			where=SE;
			break;
	}

	if (movement_command)
		game->muoviomino(where);

	return movement_command;

}

void NCursWrapper::fetchCommand(int tasto)
{

	switch (tasto)
	{
		case 'q':
			game->command("esci");
			break;
	}
}



void NCursWrapper::creaomino(char omino, WINDOW *win)
{
 	mvwaddch(win,10,10,omino|COLOR_PAIR(3));
}


int NCursWrapper::go()
{

	initialize();

	gameloop();

   	wgetch(playground);
   	finalize(0);

   	return 0;
}

