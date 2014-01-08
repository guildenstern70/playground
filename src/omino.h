/*
*
*
*  OMINO.H
*  (C) Alessio Saltarin 2001
*
*
*/

#ifndef __OMINOH__
#define __OMINOH__

#include "pedina.h"

class Omino : public Pedina
{
public:
	Omino(unsigned short maxX, unsigned short maxY);
	void muove(Direzione d);
};

#endif
