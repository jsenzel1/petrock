

#include <stdio.h>
#include "pico/stdlib.h"
#include "jfunc.h" 
class AlgoWonk
{
	private:
		int seq[32]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

		int seqInd=0;
		bool played=false;
		int myWeekday;
		int cyclePos;
		int densityPercent=0;
		int stepsToWonk=0;
		int stepsPlaced=0;
		
	public:
		int inPin; int outPin;
		void init(int,int, int, int);
		void tick();

		AlgoWonk();
		~AlgoWonk();

};
