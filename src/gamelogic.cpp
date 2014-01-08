/*
*
* 	GAMELOGIC.CPP
*	GameLogic class
*
*	(C) Alessio Saltarin 2001
*
*/


#include "gamelogic.h"
#include "omino.h"

// This class holds object, geometry and commands from the game

GameLogic::GameLogic(unsigned short cols, unsigned short rows)
{
	_viewcols = cols;
	_viewrows = rows;

	last_command = "";
	_endturn = false;
	_endgame = false;

	omino = new Omino(_viewcols,_viewrows);
	mappa = new Map(_viewcols,_viewrows);
	mappa->create();

}

GameLogic::~GameLogic()
{
	delete omino;
	delete mappa;
}

Cell* GameLogic::getcurrentcell() const
{
	return mappa->getCell(omino->getX(),omino->getY());
}

UINT GameLogic::getcurrentvalue()
{
	return getcurrentcell()->getValue();
}

UINT GameLogic::getcurrentcolor()
{
	return getcurrentcell()->getColor();
}

void GameLogic::muoviomino(Direzione d)
{
	omino->muove(d);
}

void GameLogic::setboard(UINT cols, UINT rows)
{
	_boardcols = cols;
	_boardrows = rows;
}

void GameLogic::setview(unsigned short cols, unsigned short rows)
{
	_viewcols = cols;
	_viewrows = rows;
}

void GameLogic::command(const string& cmd)
{
	last_command = cmd;

	if (last_command=="esci")
		_endgame = true;
}

bool GameLogic::isended()
{
	return _endgame;
}

bool GameLogic::turnended()
{
	return _endturn;
}
