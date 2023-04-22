#ifndef RANDOM_H_INCLUDED
#define RANDOM_H_INCLUDED

#include <cstdlib>
#include <time.h>

class Random{
public:
    inline static void init() {srand(time(NULL));}
    inline int randRange(int min, int max) {return rand() % (max-min+1) + min; }
    inline bool randBool() {return rand()&0x1;}
};

#endif // RANDOM_H_INCLUDED
