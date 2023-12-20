#include <stdio.h>
#include <math.h>
#include <time.h>

#include "pico/stdlib.h"
    
#include "jfunc.h"

class Moon
{
  public:


    int epoch=0;

    //THIS FUNCTION DEPRECATED, BECAUSE IT RELIES ON CALCULATED MOON PHASE
    
    int calcEpoch(int y, int m, int d) {
      
      struct tm tm = {0};

//      tm.tm_year = y - 1900;
      tm.tm_year = y + 100;

      tm.tm_mon = m-1;  // months are zero-indexed
      tm.tm_mday = d;

      time_t now = mktime(&tm);


      double difference = difftime(now, (time_t)978307200);
      double days = difference / 86400;
      double lunars = 0.20439731 + (days * 0.03386319269);

      //THIS LINE ONLY COMMENTED WHILE TESTING!!!!
      epoch = (int)lunars%3;
      return epoch;
    }


    int cyclePos(int y, int m, int d) {
      
      struct tm tm = {0};

      tm.tm_year = y - 1900;

      tm.tm_mon = m-1;  // months are zero-indexed
      tm.tm_mday = d;

      time_t now = mktime(&tm);


      double difference = difftime(now, (time_t)978307200);
      double days = difference / 86400;
      double lunars = 0.20439731 + (days * 0.03386319269);

      //THIS LINE ONLY COMMENTED WHILE TESTING!!!!
      //epoch = (int)lunars%8;
      //
      
      //printf("\n Current Epoch: ");
      //printf("Epoch %d\n", epoch);

      double pos = fmod(lunars, 1);
      int index = floor(pos * 8 + 0.5);

      //printf("\n and seven value: %d \n",index & 7);

      switch (index & 7) {
        case 0: printf( "New Moon"); break;
        case 1: printf( "Waxing Crescent"); break;
        case 2: printf( "First Quarter"); break;
        case 3: printf( "Waxing Gibbous"); break;
        case 4: printf( "Full Moon"); break;
        case 5: printf( "Waning Gibbous"); break;
        case 6: printf( "Last Quarter"); break;
        case 7: printf( "Waning Crescent"); break;
      }
      printf("\n");

      //printf("\n XXXX END MONTH %d XXXX \n \n",m);

      return (index & 7);
    }

/*
    const char* phase(double pos) {
      int index = floor(pos * 8 + 0.5);
      switch (index & 7) {
        case 0: return "New Moon";
        case 1: return "Waxing Crescent";
        case 2: return "First Quarter";
        case 3: return "Waxing Gibbous";
        case 4: return "Full Moon";
        case 5: return "Waning Gibbous";
        case 6: return "Last Quarter";
        case 7: return "Waning Crescent";
      }
      return "";
    }
*/


};
