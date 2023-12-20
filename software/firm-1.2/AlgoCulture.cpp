#include "AlgoCulture.h"

AlgoCulture::AlgoCulture()
{

}

void AlgoCulture::init(int tempInPin, int tempOutPin, int tempWeekday, int tempCycle)
{
	inPin=tempInPin;
	outPin=tempOutPin;
	myWeekday=tempWeekday+1;
	cyclePos=tempCycle;

	//TODO
	//cultural rhythm should be determined by phase of the moon
	//(1 rhythm for each phase of the moon
	//will still be dif every time bc of randomness adding
	whichRhythm=myWeekday;
  printf("rhyth\n");
  printf("%d\n", tempWeekday);

	for(int i=0; i<32; i++)
	{
		switch(whichRhythm)
		{
			case 1:
				seq[i]=r1[i];
			break;

			case 2:
				seq[i]=r2[i];
			break;

			case 3:
				seq[i]=r3[i];
			break;

			case 4:
				seq[i]=r4[i];
			break;

			case 5:
				seq[i]=r5[i];
			break;

			case 6:
				seq[i]=r6[i];
			break;

			case 7:
				seq[i]=r7[i];
			break;

			case 8:
				seq[i]=r8[i];
			break;
		}
	}


	extraSteps=random(-8,8);
	//extraSteps=-5;
	seqMax=16+extraSteps;
	//TODO
	//make extra steps possible to be random
	//so that you can end up with the original rhythm or with shortened version of the original rhythm
	//could also do something along the lines of:
	//rather than randomly generating extra beats at the end
	//the extra beats are steps taken from another culturally significant pattern
	//this would reallly be way easier though if arrays were assignable - maybe I should try that
	//could also have a smaller range of length and also
	//roll whether step is random or preset
	//could even work with a preset length

	for(int i=15; i<seqMax; i++)
	{
		seq[i]=random(2);
	}
}


void AlgoCulture::tick()
{
	if( gpio_get(inPin)>0)
	{
		if(!played)
		{
			played=true;

			if(seqInd > seqMax-1)
			{
				seqInd=0;
				printf("cultureReset\n");
			}

			if(seq[seqInd]==1)
			{
				gpio_put(outPin,0);
				printf("cultureTrig\n");
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

AlgoCulture::~AlgoCulture(){}
