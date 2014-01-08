/*
*
*
*  RANDGENERATOR.CPP
*
*   (C) Alessio Saltarin 2001
*
*/

#include "randgenerator.h"

#include <sys/types.h>
#include <unistd.h>
#include <cstdlib>

RandGenerator::RandGenerator()
{
	unsigned int xpid = static_cast<unsigned int>(getpid());
	setseed(xpid);
	srand(_seed);
}

int RandGenerator::randint(unsigned int max)
{
	int randvalue = 1 + static_cast<int>( static_cast<float>(max) * rand() / (RAND_MAX+1.0) );
	return randvalue;
}

void RandGenerator::setseed(unsigned int seed)
{
	_seed = seed;
}

/* test

int main(int, char**)
{
	RandGenerator *rnd = new RandGenerator;
	for (int j=0; j<=100; j++)
	{
		cout << rnd->randint(250) << endl;
	}

	return 0;
}

*/

