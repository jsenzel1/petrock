#include "AlgoWonk.h"

AlgoWonk::AlgoWonk()
{

}

void AlgoWonk::init(int tempInPin, int tempOutPin, int tempWeekday, int tempCycle)
{
	outPin=tempOutPin;
	inPin=tempInPin;
	myWeekday=tempWeekday+1;
	cyclePos=tempCycle;

	densityPercent = map(myWeekday,1,7,30,60);

	//seed pattern with 1 filled  step
	seq[random(0,32)]=1;

	for(int i=0; i<32; i+=4)
	{
		if(random(100) <densityPercent)
		{
			seq[i]=1;
			stepsPlaced++;
		}

	}
	stepsToWonk = map(cyclePos,1,7,2,stepsPlaced);
 	int stepsWonked=0;

	while(stepsWonked < stepsToWonk)
	{
		int chosenStep = random(32);

		if(seq[chosenStep]==1)
		{
			stepsWonked+=1;
			seq[chosenStep=0];

			if(random(100)<50)
			{
				seq[chosenStep+1]=1;
			} else {
				seq[chosenStep-1]=1;
			}
		}
	}
}

void AlgoWonk::tick()
{
	if( gpio_get(inPin)>0)
	{
		if(!played)
		{
			played=true;

			if(seqInd > 31)
			{
				seqInd=0;
				printf("wonkReset\n");
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

AlgoWonk::~AlgoWonk(){}
