#include <stdio.h>
#include <time.h>
#include "pico/stdlib.h" 
#include "hardware/gpio.h"
#include "hardware/clocks.h"
#include "hardware/clocks.h"
#include "hardware/watchdog.h"

// this was supposed to be a generic IO class, but ended up as the input buffer system
// AND also has the code for standalone mode `cuz it was easier to implement here 

class IO
{
    public:

        long long ms=0;
        bool autoOn=false;

        //note mult values are doubled from the actual bpm X note value (Pam's style) 
        //can't remember why, just how it is sometimes pardner, do I *look* like someone who reads their own darn tootin code??
        
        int multOptions[5]={2,4,6,8,12};

        //VARS A
        int bpm1 = 120;
        int mult1 = 4*2;
        int multInd1=3;

        long pulseLen1=(60000/bpm1)/mult1;
        long long nextPulse1=1000;

        //VARS B
        int bpm2 = 120;
        int mult2 = 4*2;
        int multInd2=3;

        long pulseLen2=(60000/bpm2)/mult2;
        long long nextPulse2=1000;

        int curCycle=0;
        int curWeekday=0;

        //VARS listener
        
        int spamCount=0;
        long nextWindow=0;

        int holdTop=0;
        int holdBot=0;

        int spamTop=0;
        int spamBot=0;

        bool pluggedTop=false;
        bool pluggedBot=false;

        //which 
        int clockToShow=1;

        //switches internal clock rates
        void clockChooser(int ID)
        {
            if(!autoOn){return;}

            if(ID==1)
            {
                multInd1++;        
                if(multInd1>4)
                {
                    multInd1=0;
                }

                mult1=multOptions[multInd1];
                pulseLen1=(60000/bpm1)/mult1;
                
            }

            if(ID==2)
            {
                multInd2++;        
                if(multInd2>4)
                {
                    multInd2=0;
                }

                mult2=multOptions[multInd2];
                pulseLen2=(60000/bpm2)/mult2;
            }
        }  
       

        //listens for input sequence which starts standalone mode
        void standaloneListener()
        {
            long ms=to_ms_since_boot(get_absolute_time());
            
            //top
            
            if(gpio_get(6)==1)
            {
                if(spamTop==0 && holdTop==0)
                {
                    nextWindow=ms+10000;
                    printf("windowPlugReset");
                }

                holdTop++;
                if(holdTop==500)
                {
                    clockChooser(1);
                    spamTop++;
                    printf("spam count: %d \n",spamTop);
                }
            } else {
                holdTop=0;
            }

            //bot

            if(gpio_get(10)==1)
            {
                holdBot++;
                if(holdBot==500)
                {
                    clockChooser(2);
                }
                if(holdBot==500 && (spamTop==2 || spamTop ==3))
                {
                    spamBot++;
                    printf("spam count bot: %d \n",spamBot);
                }
            } else {
                holdBot=0;
            }

            //

            if(ms>nextWindow)
            {
                spamTop=0;
                spamBot=0;

                nextWindow=ms+10000;
                printf("window reset \n");
            }

            if(spamBot==2)
            {
                autoOn=!autoOn;

                printf("AUTO SWITCHED: %d \n",autoOn);

                spamTop=0;
                spamBot=0;
                
                //reset when coming out of standalone mode
                
                if(autoOn==false)
                {
                    watchdog_enable(1, 1);
                    while(1);
                }
                
            }

        }

        int read(int inID)
        {
            if(!autoOn)
            {
                  if(inID==1)
                  {
                    return gpio_get(14);
                  }
                  
                  if(inID==2)
                  {
                    return gpio_get(13);
                  }
            }else{
                return internalTick(inID);
            }
        }
        
        int internalTick(int ID)
        {
           ms=to_ms_since_boot(get_absolute_time());

           if(ID==1)
           {
               int tempVal1=0;

               if(ms > nextPulse1)
               {
                  tempVal1=1;
                  if(ms > nextPulse1+pulseLen1)
                  {
                      nextPulse1=ms+pulseLen1;
                      tempVal1=0;
                  }
               } 

               //write the clock to the top moon LEDs, if one of those is the real cycle, swap it for a diff one
               if(curCycle!=0)
               {
                    gpio_put(26,tempVal1);
               } else {
                    gpio_put(28,tempVal1);
               }

               if(curCycle!=1)
               {
                    gpio_put(27,tempVal1);
               } else {
                    gpio_put(28,tempVal1);
               }

               return tempVal1;
           }

           if(ID==2)
           {
               int tempVal2=0;

               if(ms > nextPulse2)
               {
                  tempVal2=1;
                  if(ms > nextPulse2+pulseLen2)
                  {
                      nextPulse2=ms+pulseLen2;
                      tempVal2=0;
                  }
               } 
               
              if(curWeekday!=6)
              { 
                   gpio_put(8,tempVal2);
              } else {
                   gpio_put(9,tempVal2);
              }

              if(curWeekday!=0)
              {
                   gpio_put(7,tempVal2);
              } else {
                   gpio_put(9,tempVal2);
              }

               return tempVal2;
           }
        }
};
