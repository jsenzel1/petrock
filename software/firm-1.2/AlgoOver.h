

#include <stdio.h>
#include "pico/stdlib.h"
#include "jfunc.h" 
class AlgoOver
{
  private:

  
	  int seqa[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};	 
	  int seqb[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	  int seqSwitch[32] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};
	  int seql[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	  
	  int switchInd=0;
	  int seqMax=0;
	  int seqInd=0;
	  bool swap=false;

	  bool shouldPlay=false;
	  bool played=false;
	  int myWeekday=0;
	  int cyclePos=0;
	  int seqDensity=0;
	  void shuffleArr(int *, int);

	  bool stepVal=0;

	  int densityPercent=0;

  public:

				void shuffleArray(int * array, int size)
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

			
	  int inPin; int outPin;

	  void init(int,int,int,int);
	  void tick();
	  AlgoOver();
  	  ~AlgoOver();
};




