
/*
*
* 	GAMELOGIC.H
*	GameLogic class
*
*	(C) Alessio Saltarin 2001
*
*/

#ifndef __GAMELOGICH__
#define __GAMELOGICH__

#include "omino.h"
#include "map.h"

#include <string>

using namespace std;

// To do: singleton?

class GameLogic
{
public:
	GameLogic(unsigned short cols, unsigned short rows);
	~GameLogic();
	Omino* getomino() { return omino; }
	Cell* getcurrentcell() const;
	UINT getcurrentvalue();
	UINT getcurrentcolor();
	void muoviomino(Direzione d);
	unsigned int getboardcols() { return _boardcols; }
	unsigned int getboardrows() { return _boardrows; }
	unsigned short getviewcols() { return _viewcols; }
	unsigned short getviewrows() { return _viewrows; }
	void setboard(UINT cols, UINT rows);
	void setview(unsigned short cols, unsigned short rows);
	void command(const string& cmd);
	bool isended();
	bool turnended();

protected:
	Omino *omino;
	Map *mappa;

	unsigned int _boardcols;
	unsigned int _boardrows;
	unsigned short _viewcols;
	unsigned short _viewrows;

	bool _endturn;
	bool _endgame;

	string last_command;

};

#endif
