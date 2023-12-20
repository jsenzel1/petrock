#include <stdio.h>
#include "pico/stdlib.h"
#include "jfunc.h" 
class AlgoPlain
{
  private: 	
	  int seq[64]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
		
	  int seqMax=0;
	  int seqInd=0;
	  
	  bool played=false;

	  int weekday;
	  int cyclePos;

  public:

      int continuity=0;

	  int ID=0; 
	  int resetLED=0; 

      bool resetOn=false;
      int resetDur=250;
      long resetOffTime=0;
      long gateStart=0;

      int inPin=0;
      int outPin=0;

	  void init();
	  void tick(int);

	  bool stepVal;

      //ID ledpin, weekday, cycle,seed
	  AlgoPlain(int,int,int,int);

	  ~AlgoPlain();
};
