#ifndef jfunc_h
#define jfunc_h

#include <math.h>
#include <stdlib.h>

#define abs(x) ((x)>0?(x):-(x))

#define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))

long random(long);
long random(long, long);

void randomSeed(long);

long map(long, long, long, long, long);

#endif
