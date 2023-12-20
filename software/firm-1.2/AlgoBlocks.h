 

#include <stdio.h>
#include "pico/stdlib.h"
#include "jfunc.h" 
class AlgoBlocks 
{
	private: 
		//[ 8 types of rhyth][4 steps each]
		int seq[32]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
		int blocks[8][4]=
		{
			{0,0,0,0},
			{1,0,0,0},
			{1,0,1,0},
			{1,0,0,1},
			{1,1,1,0},
			{1,0,1,1},
			{0,0,1,0},
			{1,1,1,1}
		};
		//length 2-6
		////length 2-6 blocks
		//
		int numBlocks=0;
		int seqInd=0;
		int seqMax=0;

		int curBlock=0;

		bool played=false;
		int myWeekday=0;
		int cyclePos=0;
	public:
		int inPin; int outPin;

		void init(int,int,int,int);
		void tick();

		AlgoBlocks();
		~AlgoBlocks();
};
