#ifndef RandomGenerator_H
#define RandomGenerator_H

#include <cstdlib>

class RandomGenerator
{
private:
	int seed;
public:
	RandomGenerator(int seed);
	bool randomBool();
	
};

#endif // !RandomGenerator_H