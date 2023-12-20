#include "AlgoOver.h"

AlgoOver::AlgoOver()
{
}

void AlgoOver:: init(int tempInPin, int tempOutPin,int tempWeekday, int tempCycle)
{
	printf("ALGOO OOVVEERR\n");


	outPin=tempOutPin;
	inPin=tempInPin;
	myWeekday=tempWeekday+1;
	cyclePos=tempCycle;

	densityPercent=50;

	int seedStepInd=random(0,seqMax);
	seqMax=8;
	seqInd=0;
	swap=false;

  shuffleArray(seqSwitch,seqMax);
  //shuffleArray(seqSwitch,32);
//
//  for(int i=0; i<seqSwitch; i++)
//  {
//    printf("%d\n", seqSwitch[i]);
//  }

	for(int i=0; i<seqMax; i++)
	{
		if(random(100) < densityPercent)
		{
			seqa[i]=1;
		}
	}


	for(int i=0; i<seqMax; i++)
	{
		if(random(100) < densityPercent)
		{
			seqb[i]=1;
		}
	}

	for(int i=0; i<seqMax; i++)
	{
		seql[i]=seqa[i];
	}
	//TESTING


	printf("Seq A:\n");
	for(int i=0; i<seqMax;i++)
	{
		//seqa[i]=0;
		printf("%d\n", seqa[i]);
	}
	printf("");
	printf("Seq B:\n");

	for(int i=0; i<seqMax;i++)
	{
		//seqa[i]=1;

		printf("%d\n", seqb[i]);
	}
}

void AlgoOver:: tick()
{
	//printf("TICK OVER\n");
	if( gpio_get(inPin)>0)
	{

		if(!played)
		{
		//printf(".");

			played=true;
			//printf("%d\n", seqInd);
			if(seqInd > seqMax-1)
			{
				seqInd=0;
				//printf("OverReset\n");
				//ADVANCE SWITCH
				//CHECK SWITCH WRAP
				int overwriteInd = seqSwitch[switchInd];

				switchInd++;

				if(switchInd>seqMax-1)
				{
					switchInd=0;
					swap=!swap;
				}

				if(!swap)
				{
					seql[overwriteInd]=seqb[overwriteInd];
				}else {
					seql[overwriteInd]=seqa[overwriteInd];
				}

				printf("");

				for(int i=0; i<seqMax;i++)
				{
					printf("%d\n", seql[i]);
				}

				printf("switchInd: ");
				printf("%d\n", switchInd);
			}

			if(seql[seqInd]==1)
			{
				gpio_put(outPin,0);
			}

			//printf("%d\n", seqInd);
			seqInd++;

		}


	}
				if( gpio_get(inPin)==0)
			{
				played=false;
				gpio_put(outPin,1);
			}
}

AlgoOver::~AlgoOver(){}
