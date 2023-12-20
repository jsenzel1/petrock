#include "AlgoSparse.h"
#include "hardware/clocks.h"

AlgoSparse::AlgoSparse(int tempID, int tempWeekday, int tempCycle, int tempContinuity)
{
    continuity=tempContinuity;
    ID=tempID;

    if(ID==1)
    {
        inPin = 14;
        outPin= 15;
        resetLED=22;
    }

    if(ID==2)
    {
        inPin = 13;
        outPin= 12;
        resetLED=21;
    }    

    myWeekday=tempWeekday;
    cyclePos=tempCycle;
}


void AlgoSparse::init()
{

	switch (cyclePos)
	{
			//new moon
			case 0:
					seqMax=random(10,20);
					break;

			//waxing or waning crescent
			case 1:
			case 7:
					seqMax=random(15,30+1);
					break;

			//first or last quarter
			case 2:
                    if(ID==1)
                    {
                        seqMax=32;
                    }

                    if(ID==2)
                    {
                        seqMax=64;
                    }
			case 6:

                    if(ID==1)
                    {
                        seqMax=24;
                    }

                    if(ID==2)
                    {
                        seqMax=48;
                    }
					//seqMax=(20,32+1);
					break;

			//waxing or waning gibbous
			case 3:
					seqMax=32;
					break;
			case 5:
					seqMax=24;
					break;
			//full moon
			case 4:
					//seqMax=random(20,40+1);
					seqMax=64;
					break;

	}

	printf("sparse week\n");
	printf("%d\n", myWeekday);

	//densityPercent = map(myWeekday,1,7,5,15);
    densityPercent=10;

    //percents should prob be changed per cycle
    //10 works well for waxing gibbous
    
	printf("Density %\n");
	printf("%d\n", densityPercent);

    //seqMax = random(20,31);
	printf("Seq Max\n");
	printf("%d\n", seqMax);
	//seqMax=32;
	//seqMax should def sometimes be set at 32 or 16, either
	//randomly or in response to time vars
	int seedStepInd = random(0,seqMax);
	printf("%d\n", seedStepInd);

	seq[seedStepInd]=1;

	for(int i=0; i< seqMax; i++)
	{
		if(random(100) < densityPercent)
		{
			//printf("step marked\n");
			//printf("%d\n", i);
			//printf("%d\n", random(100));
			seq[i]=1;
		}
	}

		printf("Seq %d: \n",ID);
		printf("/ / / / / / / /\n",ID);

	for(int i=0; i<32; i++)
	{
		printf("%d ", seq[i]);

        if((i+1)%8==0){printf("\n");}
	}

		printf("\n / / / / / / / /\n",ID);
		printf("\n",ID);
}

void AlgoSparse::tick(int inRead)
{
    if(resetOn)
    {

        gpio_put(resetLED,1);

        if(to_ms_since_boot(get_absolute_time())>resetOffTime)
        {
            resetOn=false;
            gpio_put(resetLED,0);
        }
    }

    //if(ID==2){if(gpio_get(10)==0){inPin=14;}else{inPin=13;}}

	if(inRead>0)
	{
    //printf("ON\n");
		if(!played)
		{
            gateStart=to_ms_since_boot(get_absolute_time());
			played=true;

			if(seqInd > seqMax-1)
			{
				seqInd=0;
				printf("sparseReset\n");
                resetOn=true;
                resetOffTime=to_ms_since_boot(get_absolute_time())+resetDur;
                printf("resetTime: %ld",resetOffTime);
                printf("resetTime: %ld",to_ms_since_boot(get_absolute_time()));
			}

			if(seq[seqInd]==1)
			{
				gpio_put(outPin,0);
				printf("sparseTrig\n");
			}
			seqInd++;
		}
	}

	if(inRead==0)
	{
        if(played)
        {
            resetDur=(to_ms_since_boot(get_absolute_time())-gateStart)+200;
        }
		played=false;
		gpio_put(outPin,1);
	}

}

AlgoSparse::~AlgoSparse(){}
