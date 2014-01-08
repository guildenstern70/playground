/*
*
*  RANDGENERATOR.H
*
*  (C) Alessio Saltarin 2001
*
*/

#ifndef __RANDGENERATORH__
#define __RANDGENERATORH__


class RandGenerator
{
public:
	RandGenerator();
	int randint(unsigned int max);
private:
	void setseed(unsigned int seed);
	unsigned int _seed;
};


#endif
