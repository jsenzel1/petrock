#include "stdlib.h"
#include "jfunc.h"

void randomSeed(long seed)
{
  if (seed != 0) {
    srandom(seed);
  }
}

long random(long howbig)
{
  if (howbig == 0) {
    return 0;
  }
  return random() % howbig;
}

long random(long howsmall, long howbig)
{
  if (howsmall >= howbig) {
    return howsmall;
  }
  long diff = howbig - howsmall;
  return random(diff) + howsmall;
}

long map(long x, long in_min, long in_max, long out_min, long            out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) +        out_min;
}

void shuffle(int * array, int size)
{
    int last = 0;
    int temp = array[last];
    for (int i=0; i<size; i++)
    {
        int index = random(size);
        array[last] = array[index];
        last = index;
    }
       array[last] = temp;
}
