#include "AlgoPlain.h"
#include "jfunc.h"
#include "hardware/clocks.h"

AlgoPlain::AlgoPlain(int tempID, int tempWeekday, int tempCycle, int tempContinuity)
{
    //ID - 1 is A and 2 is B, using integers makes it easier to do a bit of math stuff sometimes 
    
    ID = tempID;

    //sets proper pins for A or B
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

	weekday=tempWeekday;
	cyclePos=tempCycle;
    continuity=tempContinuity;
}

void AlgoPlain::init()
{
    //note I'm leaving in some older random value ranges to see what I experimented with in the past
    
    //Randomly populate rhythm
    //this may seems weird/cheesy, but as I note in the manual - I decided to focus on one and only one translated elements for the moon cycle, which is the length relationship of A and B - I found through practice that the random population of steps actually produces great results, the key is how many steps you use, and the relationship between the 2 step lengths. The interesting difference is comparing for example a pair of 8 step rhythms, vs a 7 step rhythm, and a 15 step rhythm being played against each other - this is the "meta movement" of the rhythmic flavor, in every algo/mood
    

	for(int i=0; i<64; i++)
	{
		seq[i]=random(2);
	}

    switch (cyclePos)
    {
        //new moon
        case 0:
            seqMax=random(5,6+1);
            break;

        //waxing or waning crescent
        case 1:
        case 7:
            //seqMax=random(7,9+1);
            seqMax=random(4,16+1);
            break;

        //first or last quarter
        case 2:
        case 6:
            //seqMax=random(10,12+1);
            seqMax=map(continuity,0,100,6,12+1);
            seqMax*=ID; // B is Double A
            break;

        //waxing or waning gibbous
        case 3:
            seqMax=12;
        case 5:

            //srand(seed);
            //seqMax=random(13,15+1);
            seqMax=16;
            break;
	    
        //full moon
        case 4:
			//seqMax=random(20,40+1);
            seqMax=16;
            break;

    }

	//seqMax=random(4,24);

    printf("random num %d \n",map(5,0,10,0,100));
	printf("-----\n Max: ");
	printf("%d \n", seqMax);

	for(int i=0; i<seqMax; i++)
	{
		printf("%d ", seq[i]);
	}

    printf("\n -----");
}

void AlgoPlain:: tick(int inRead)
{
	//printf("gp %d \n", gpio_get(inPin));
    
    if(resetOn)
    {
        gpio_put(resetLED,1);

        if(to_ms_since_boot(get_absolute_time())>resetOffTime)
        {
            resetOn=false;
            gpio_put(resetLED,0);
        }
    }

    //if(ID==2){if(gpio_get(10)<1){inPin=14;}else{inPin=13;}}
    //int state=gpio_get(inPin);

    if(inRead>0)
    {
        if(!played)
        {
           gateStart=to_ms_since_boot(get_absolute_time());

           if(seq[seqInd]==1)
           {
               printf("blip\n");
               gpio_put(outPin,0);
           }

           seqInd++;

           if(seqInd>seqMax-1)
           {
               //RESET
               seqInd=0;

               resetOn=true;
               resetOffTime=to_ms_since_boot(get_absolute_time())+resetDur;
               printf("reset\n");
           }

           played=true;
        }

    } else {
        if(played)
        {
            resetDur=(to_ms_since_boot(get_absolute_time())-gateStart)+200;
            printf("rest dur %d \n",resetDur);
        }
        played=false;
        gpio_put(outPin,1);
    }

}

AlgoPlain::~AlgoPlain(){}
