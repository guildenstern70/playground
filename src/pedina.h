/*
*
*
*  PEDINA.H
*
*
*
*/

#ifndef __PEDINAH__
#define __PEDINAH__

enum Direzione
{
	N, S, W, E, NW, NE, SW, SE
};

class Pedina
{
public:
    virtual ~Pedina() {}
	virtual void muove(Direzione d) = 0;
	unsigned short getX() { return _x; }
	unsigned short getY() { return _y; }
	void setposition(unsigned short xx, unsigned short yy) { _x=xx; _y=yy; }
	void setmaxX(unsigned short mX) { maxX=mX; }
	void setmaxY(unsigned short mY) { maxY=mY; }
protected:
	char simbolo;
	unsigned short colore;
	unsigned short maxX;
	unsigned short maxY;
	unsigned short _x;
	unsigned short _y;
};

#endif
