#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H
#include <cstdlib>        // provides srandom, random (which we pretend are thread-safe, even though they aren't)
#include <time.h>
class RandomGenerator 
{
	public:
		RandomGenerator(){
			srand(time(NULL));
		}
	unsigned int getNextInt(unsigned int l, unsigned int h){
			return rand()%(h-l)+l;
		}
	bool getNextBool(double h){
		int c = rand()%10;
		if (c<= h*10) return true;
		else return false;
		}
};

		

#endif
