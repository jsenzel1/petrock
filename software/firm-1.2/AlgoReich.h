#include <stdio.h>
#include "pico/stdlib.h"
#include "jfunc.h" 
class AlgoReich 
{
  private:
    int testVarSeqMax=-1;
    
    int seq[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int mute[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    int muteInd=0;
    int seqMax;
    int seqInd=0;
    
    int timer;

    bool shouldPlay;
    bool played;

    int myWeekday;
    int cyclePos;

    
    int spread;

    //new vars
    int seqDensity=50;
    
   
    
  public:

   int inPin=0;  
   int outPin=0;  

   int ID=0;

   int resetLED=0;
   bool resetOn=false;
   int resetDur=250;
   long gateStart=0;
   long resetOffTime=0;

   int continuity=0;
   void init();
   
   void tick(int);
   bool stepVal;


   //ID, weekday, cycle, seed //[maybe]spread
   AlgoReich(int,int,int,int);
   
   ~AlgoReich();
 };
