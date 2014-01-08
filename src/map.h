/*
*
* 	MAP.H
*	Map & Cell class
*
*	A Map is a container of an array of Cell objects and functions to
*   retrieve one cell properties.
*	A Cell is a container of properties, such as speed, food.
*
*   (C) Alessio Saltarin 2001
*
*/

#ifndef __MAPH__
#define __MAPH__

#include <string>
#include <sstream>
#include <vector>

using namespace std;

typedef unsigned int UINT;

class Cell
{
public:
	Cell(UINT xx, UINT yy, UINT color, UINT value) : _x(xx), _y(yy), _color(color), _value(value) {}
	UINT getColor() { return _color; }
	UINT getValue() { return _value; }
	UINT getX() { return _x; }
	UINT getY() { return _y; }
	const char* tostring() const;

private:
	UINT _x;
	UINT _y;
	UINT _color;
	UINT _value;

};

typedef std::vector<Cell*> ArrayList;
typedef ArrayList::iterator Iterator;

class Map
{
public:
	Map(UINT sizex, UINT sizey);
	~Map();
	Cell* getCell(UINT x, UINT y) const;
	void create();
	bool iscreated();
	void serialize(const char *filename);
	void deserialize(const char *filename);
private:
	ArrayList cells;
	bool _created;
	UINT _rowsize;
	UINT _colsize;

};



#endif
