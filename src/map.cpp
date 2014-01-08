/*
*
* 	MAP.CPP
*	Map & Cell class
*
*   (C) Alessio Saltarin 2001
*
*/



#include "map.h"
#include "randgenerator.h"


Map::Map(UINT sizex, UINT sizey)
{
	_rowsize = sizey;
	_colsize = sizex;
	_created = false;
}

Map::~Map()
{
	if (_created)
	{
		// free up memory
		for(Iterator j = cells.begin(); j != cells.end(); j++)
		    delete *j;
	}
}

void Map::create()
{
	enum
	{
		MAX_COLOR_VALUE = 10,
		MAX_VALUE_VALUE = 50
	};

	UINT tmpcolor;
	UINT tmpvalue;

	if (!_created)
	{

		RandGenerator *rnd = new RandGenerator;

		// Initialize ArrayList of Cells
		for (UINT rowx=0; rowx<_rowsize; rowx++)
		{
			for (UINT coly=0; coly<_colsize; coly++)
			{
				tmpcolor = rnd->randint(MAX_COLOR_VALUE);
				tmpvalue = rnd->randint(MAX_VALUE_VALUE);
				cells.push_back(new Cell(rowx,coly,tmpcolor,tmpvalue));
			}
		}

		delete rnd;

	}


	_created = true;
}

bool Map::iscreated()
{
	return _created;
}

void Map::serialize(const char *filename)
{
	// to do...
}

void Map::deserialize(const char *filename)
{
	// to do...
}

Cell* Map::getCell(UINT x, UINT y) const
{
	// x e y cominciano con 0
	return cells[_colsize*y+x];
}


/*  TEST
int main(int, char**)
{

	Map *map = new Map(20,20);

	if (!map->iscreated())
	{
		map->create();
		Cell *tmpcell;

		for (int j=0; j<20; j++)
		{
			for (int k=0; k<20; k++)
			{
				tmpcell = map->getCell(j,k);
				cout << tmpcell->tostring() << endl;
			}
		}

	}

	delete map;

	return 0;
} */




