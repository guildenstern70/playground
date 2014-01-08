/*
*
*
*  OMINO.CPP
*  (C) Alessio Saltarin 2001
*
*
*/

#include "omino.h"
#include "randgenerator.h"


Omino::Omino(unsigned short maxX, unsigned short maxY)
{
	RandGenerator *rnd = new RandGenerator;

	_x=rnd->randint(maxX);
	_y=rnd->randint(maxY);
	setmaxX(maxX);
	setmaxY(maxY);

	delete rnd;
}

void Omino::muove(Direzione d)
{
	switch (d)
	{
		case N:
			if (_y>1) _y--;
			break;

		case S:
			if (_y<maxY-2) _y++;
			break;

		case W:
			if (_x>1) _x--;
			break;

		case E:
			if (_x<maxX-2) _x++;
			break;

		case NW:
			if (_y>1) _y--;
			if (_x>1) _x--;
			break;

		case NE:
			if (_y>1) _y--;
			if (_x<maxX-2) _x++;
			break;

		case SW:
			if (_y<maxY-2) _y++;
			if (_x>1) _x--;
			break;

		case SE:
			if (_y<maxY-2) _y++;
			if (_x<maxX-2) _x++;
			break;
	}
}
