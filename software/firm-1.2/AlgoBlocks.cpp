#include "AlgoBlocks.h"

AlgoBlocks::AlgoBlocks()
{
}

void AlgoBlocks::init(int tempInPin, int tempOutPin, int tempWeekday, int tempCycle)
{
	outPin=tempOutPin;
	inPin=tempInPin;
	myWeekday=tempWeekday+1;
	cyclePos=tempCycle;

	//TODO numblocks range 2-6 in accordance to params
	numBlocks=5;

	seqMax=numBlocks*4;

	for(int i=0; i < numBlocks; i++)
	{

		curBlock=random(8);

		for(int j=0; j<4; j++)
		{
		seq[((i*4))+j]=blocks[curBlock][j];
		}
	}
}

void AlgoBlocks::tick()
{
	if( gpio_get(inPin)>0)
	{
		if(!played)
		{
			played=true;

			if(seqInd > seqMax-1)
			{
				seqInd=0;
			}

			if(seq[seqInd]==1)
			{
				gpio_put(outPin,0);
			}

			seqInd++;
		}
	}

	if( gpio_get(inPin)==0)
	{
		played=false;
		gpio_put(outPin,1);
	}
}

AlgoBlocks::~AlgoBlocks(){}
