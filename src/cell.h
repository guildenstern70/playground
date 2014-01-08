#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

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

#endif // CELL_H_INCLUDED
