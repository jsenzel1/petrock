#include "AlgoReich.h"
#include "Jfunc.h"

AlgoReich::AlgoReich(int tempID,int tempWeekday, int tempCycle, int tempContinuity) 
{
  myWeekday=tempWeekday+1;
  cyclePos=tempCycle;
  continuity=tempContinuity;
  ID=tempID;
}

void AlgoReich:: init()
{

  //set to -1 to disable
  testVarSeqMax=-1;

  if(ID==1)
  //A
  {
      testVarSeqMax=6;
  } else {
  //B
      testVarSeqMax=7;
  }
  testVarSeqMax=-1;

  if(ID==1)
  {
      inPin=14;
      outPin=15;
     resetLED=22;
  } 

  if(ID==2)
  {
      inPin=13;
      outPin=12;
      resetLED=21;
  } 
  

  //spread=tempSpread;

  printf("\n");
  printf("ALGOOOREICH\n");

  switch (cyclePos)
  {
      //new moon
      case 0:
          seqMax=random(3,5+1);
          break;

      //waxing or waning crescent
      case 1:
      case 7:
          //seqMax=random(6,8+1);
          //3,5+1

          //assures A and B have different lengths
          //make sure to change both maps if you change
          if(ID==1)
          {
             seqMax=map(continuity,0,100,3,8+1);
          }

          if(ID==2)
          {
              int aMax=map(continuity,0,100,3,8+1);
              int bMax=0;

              do{
                  bMax=random(3,8+1);
              }while(aMax==bMax || (aMax==bMax*2) || (bMax==aMax*2));

              seqMax=bMax;
          }
          
          break;

      //first or last quarter
      case 2:
      case 6:
          //seqMax=(8,10+1);         
          seqMax=map(continuity,0,100,5,9);
          seqMax*=ID;
          break;

      //waxing or waning gibbous
          //seqMax=4;
          //seqMax=6;
          //break;
        
      case 3:
      case 5: 
          //srand(seed);
          //seqMax=6;
          //seqMax=7;
          seqMax=map(continuity,0,100,4,8);
          break;

      case 4:
          //seqMax=random(20,40+1);
          seqMax=8;
          break;

  }

  //seqMax=random(4,8);

  //SETTING VARS FOR TESTING
  //myWeekday=
  //cyclePos=


  for(int i=0; i<32; i++)
  {
    //seq[i]=random(2);
    if(random(100) < seqDensity)
    {
	    seq[i]=1;
    }
  }

  bool empty=true; 
  for(int i=0; i<seqMax; i++)
  {
      if(seq[i] != 0)
      {
          empty=false;
          break;
      }
  }
  if(empty)
  {
      int rIndex=random(0,seqMax);
      seq[rIndex]=1;
  }

  //LOG TO CONSOLE
  //

  //printf("reich cycle read: %d \n",cyclePos);

  printf("Reich Seq Density: %d \n", seqDensity);
  printf("Reich Seq Max: %d \n",seqMax);

  printf("\n");

  for(int i=0;i<seqMax;i++)
  {
	  printf("%d ", seq[i]);
  }
  printf("\n");

	  printf("");


  printf("\n");

  timer=300;
}

void AlgoReich:: tick(int inRead)
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
    //printf("got to 1 \n");
    //printf("reichTICK\n");
    if(!played)
    {
      gateStart=to_ms_since_boot(get_absolute_time());
      played=true;

      //CHECK MAX RESET
      if(seqInd > seqMax-1)
      {

        printf("seqInd:  %d \n",seqInd);

        seqInd=0;
        printf("reset\n");
        mute[muteInd]=1;
        muteInd++;

        //if(muteInd > seqMax-1)
        if(muteInd > seqMax)
        {

          //reset
          muteInd=0;

          for(int i=0; i< seqMax; i++)
          {
            mute[i]=0;
          }
          resetOn=true;
          resetOffTime=to_ms_since_boot(get_absolute_time())+resetDur;

        }
      }


      if(seq[seqInd]==1 && mute[seqInd]==1)
      {

        gpio_put(outPin,0);
        gpio_put(19,1);

        //printf("click \n");

      }

      //printf("%d\n", seqInd);
      //printf("%d\n", muteInd);
      //

      seqInd++;


    }

  }


  if(inRead==0)
  {

    if(played)
    {
        resetDur=(to_ms_since_boot(get_absolute_time())-gateStart)+200;
        printf("rest dur %d \n",resetDur);
    }

    played=false;
    gpio_put(outPin,1);
    gpio_put(19,0);
  }

}

AlgoReich::~AlgoReich(){}
