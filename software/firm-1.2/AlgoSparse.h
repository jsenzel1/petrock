#include <stdio.h>
#include "pico/stdlib.h"
#include "jfunc.h" 
class AlgoSparse
{
	private:
		int seq[64]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

		int seqMax=0;
		int seqInd=0;

		bool played=false;

		int myWeekday;
		int cyclePos;
		int densityPercent;

	public:
        int continuity=0;
        int ID;
		int inPin; int outPin;

        int resetLED; 
        
        bool resetOn=false; 
        int resetDur=250;
        long resetOffTime=0;
        long gateStart=0;

		void init();
		void tick(int);

		AlgoSparse(int,int,int,int);
		~AlgoSparse();

};
