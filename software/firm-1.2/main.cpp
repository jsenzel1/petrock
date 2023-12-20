//set to -1 to disable
int testVarCycle=-1;
int testVarEpoch=-1;
int testVarWeekday=-1;
bool testVarStandalone=false;
// - - - - - - - - TEST VARS
bool usbWait=false;
//change above to true and below to 10000 to allow USB console to print setup vars
#define PICO_STDIO_USB_CONNECT_WAIT_TIMEOUT_MS 0000

bool clockWrite=false;
bool testDayOffSet=false;

// true=random rolls on startup
bool testVarRandom=false;
int testVarSeed=1275;

int curEpoch=0;
int seedOffset=1;

int randVals[250]; 

//disable runtime bug throws (I think?) 
//never got this working anyway, if you got runtime errors to succesfully print in the console with rpi pico/rp2040, without swd hardware, using minicom or similar, email me! 
#define PARAM_ASSERTIONS_ENABLE_ALL 0

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "pico/stdlib.h"
#include "tusb.h"
#include "Manager.h"
#include "AlgoPlain.h"
#include "AlgoReich.h"
#include "AlgoSparse.h"
#include "AlgoVari.h"
#include "AlgoCulture.h"
#include "AlgoBlocks.h"
#include "AlgoWonk.h"
#include "AlgoOver.h"
#include "Moon.h"
#include "Clock.h"
#include "Light.h"
#include "PhaseData.h"
#include "FileSystem.h"
#include "IO.h"

#include "hardware/gpio.h"
#include "hardware/clocks.h"
#include "hardware/watchdog.h"

//STARTUP
int loopCounter=0;

//PINS

//Pin 1 is always the top pin, Pin 2 is bottom

int inPin1 = 14;
int inPin2 = 13;

int outPin1=15;
int outPin2=12;

int ledPin1=19;
int ledPin2=20;

//Blue leds
int resetLED1=22;
int resetLED2=21;

//These pins tell you if there is a cable plugged in to the inputs
int inPlugCheck1=6;
int inPlugCheck2=10;

int plugNoiseTimer=0;

// TIME VARS

bool timeChecked;

int today=6;
int curMonth=12;
int curYear=22;

int curWeekday=3;
int cycle=0;

long todaySeed=0;

int clockWeekday,clockToday,clockMonth,clockYear,clockHour,clockMinute,clockZone;

//midnight vars

long msTillMidnight=0;
int midnightAnimCounter=500;
int midnightAnimDelay = 500;

//ins/standalone mode vars

int in1Val=0;
int in2Val=0;

bool autoOn=false;
bool noCables=false;

long long msSinceBoot=0;
long long nextPlugCheckTime=0;

//Utilities Classes

Clock *myClock;
Moon myMoon;
Light myLight;
PhaseData myPhaseData;
FileSystem myFileSystem;
Manager myManager;
IO myIO;

//Algo Classes
//(* initializes it as a pointer, so it doesn't take up a bunch of RAM, I think)

AlgoCulture *myCulture1;
AlgoCulture *myCulture2;

AlgoReich *myReich1;
AlgoReich *myReich2;

AlgoPlain *myPlain1;
AlgoPlain *myPlain2;

AlgoSparse *mySparse1;
AlgoSparse *mySparse2;

AlgoBlocks *myBlocks1;
AlgoBlocks *myBlocks2;

AlgoWonk *myWonk1;
AlgoWonk *myWonk2;

AlgoOver *myOver1;
AlgoOver *myOver2;

AlgoVari *myVari1;
AlgoVari *myVari2;

// this should probably be in jfunc, teehee, oopsies
void shuffleArray(int * array, int size)
{
  int last = 0;
  int temp = array[last];
  for (int i=0; i<size; i++)
  {
    int index = random(size);
    array[last] = array[index];
    last = index;
  }
  array[last] = temp;
}

void setup()
{

    int i;
    for (i = 0; i < 100; i++) 
    {
    randVals[i] = rand();
    }

  // get noisy seed (actually random)
  // please email me telling me it's not actually random 
  // (I know it's not actually random)
  // (or wait is it??)
  // (it kinda should be right)
  
  testVarSeed= to_us_since_boot(get_absolute_time());

  printf("\n----------\n Hello from Setup!\n----------\n");
  printf("fourth index: %d ",myPhaseData.phaseDataArray[4]);

  //prep all our ins and outs guys gals (and non binary pals - and in fact, non binary enemies should also probably include this code as well)

  gpio_init(inPin1);
  gpio_init(inPin2);

  gpio_set_dir(inPin1,GPIO_IN);
  gpio_set_dir(inPin2,GPIO_IN);

  gpio_init(outPin1);
  gpio_init(outPin2);

  gpio_set_dir(outPin1,GPIO_OUT);
  gpio_set_dir(outPin2,GPIO_OUT);

  gpio_init(inPlugCheck1);
  gpio_init(inPlugCheck2);

  gpio_set_dir(inPlugCheck1,GPIO_IN);
  gpio_set_dir(inPlugCheck2,GPIO_IN);

  gpio_set_pulls(inPlugCheck1,false,false);
  gpio_set_pulls(inPlugCheck2,false,false);

  gpio_init(ledPin1);
  gpio_init(ledPin2);

  gpio_set_dir(ledPin1,GPIO_OUT);
  gpio_set_dir(ledPin2,GPIO_OUT);

  gpio_init(resetLED1);
  gpio_init(resetLED2);

  gpio_set_dir(resetLED1,GPIO_OUT);
  gpio_set_dir(resetLED2,GPIO_OUT);

  //yeah, initialize the clock here, why not, who knows why
  myClock = new Clock;
  
  //no idea what this is but too lazy to read the schematic right now
  gpio_init(3);
  gpio_set_dir(3,GPIO_OUT);

}

void fileSetup()
{

    myFileSystem.init(); 

    //Leaving this old comment from a previous bug in case it's useful to have and because then I don't have to press backspace, which is covered in tiny spikes on my keyboard
    
    //this code writes clock correctly, something wrong with file system to clock write pipelin
    /* 
    myClock->initClock();
    myClock->reset();
    myClock->writeClock(1,1,1,23,11,59,7);
    */
   
    //Taking the values from the file system and putting them in some local variables, for some reason, which was legit when I wrote the code, probably
    
    printf("filenum %d \n", myFileSystem.fileWeekday);

    clockWeekday=myFileSystem.fileWeekday;

    clockToday=myFileSystem.fileToday;
    clockMonth=myFileSystem.fileMonth;
    clockYear=myFileSystem.fileYear;

    clockHour=myFileSystem.fileHour;
    clockMinute=myFileSystem.fileMinute;
    clockZone=myFileSystem.fileZone;


    if(myFileSystem.shouldSetClock==true)
    {
        printf("filenum %d \n", clockWeekday);
        printf("filenum %d \n", clockToday);
        printf("filenum %d \n", clockMonth);
        printf("filenum %d \n", clockYear);
        printf("filenum %d \n", clockHour);
        printf("filenum %d \n", clockMinute);
        printf("filenum %d \n", clockZone);
    }
}

//Basic phase lookup
void phaseCheck(long days)
{
    printf("corresponding value in array: %d \n", myPhaseData.phaseDataArray[days]);
    cycle=myPhaseData.phaseDataArray[days];

    //if it's a key phase
    //open time array
    //check if calculated time is pre/post midnight (if its less than zero/greater than 23)
    //push accordingly 
    //check to make sure that these are not duplicate and also - if it's tomorrow, how do I tell that to the system?
    //^ maybe check if yesterdays or tomorrow's phase is a key phase
}

//Initialize the Real Time Clock
void clockSetup()
{
    myClock->initClock();
    myClock->reset();

    if(myFileSystem.shouldSetClock==true)
    {

        //All Lights on to show clock is set
        int dayLedPins[7]={7,1,0,2,11,9,8};
        int moonLedPins[8]={26,27,28,29,25,24,18,23};   

        for(int i=0; i<7; i++)
        {
            gpio_init(dayLedPins[i]);
            gpio_set_dir(dayLedPins[i],GPIO_OUT);
            gpio_put(dayLedPins[i],1);
        }

        for(int i=0; i<8; i++)
        {
            gpio_init(moonLedPins[i]);
            gpio_set_dir(moonLedPins[i],GPIO_OUT);
            gpio_put(moonLedPins[i],1);
        }

      //Write to the clock
      myClock->writeClock(
              clockWeekday,
              clockToday,
              clockMonth,
              clockYear,
              clockHour,
              clockMinute,
              clockZone
              );
      printf("WROTE CLOCK \n");
      
      printf("filenum %d \n", myFileSystem.fileWeekday);
      printf("filenum %d \n", myFileSystem.fileToday);

    }
   
    //Read the clock and populate the main file variables 
    myClock->readClock();

    curWeekday = myClock->weekday;

    if(testVarWeekday!=-1)
    {
        curWeekday=testVarWeekday;
    }

    printf("weekday: %d \n", myClock->weekday);

    today = myClock->day;
    curMonth = myClock->month;
    curYear = myClock->year;

    //for testing - adds a day to the date on reset
    if(testDayOffSet==true)
    {
        myFileSystem.offSetIncrement();
        int offSet=myFileSystem.dayOffSet;

        today=offSet%30;
        if(today > 30){
            today=1;
        }

        curWeekday=(curWeekday+offSet)%7;
        curMonth = curMonth + ((int)(offSet/30));
    }

    //print the time
    printf("%d : %d : %d \n",myClock->hour,myClock->minute,myClock->second);
    printf("date: %d / %d, %d \n",curMonth, today, curYear);

    //adding 20 seconds as a buffer/precuation - 
    //if somehow the pico ms since boot is off from the rtc time, will create an annoying infinite boot bug
   
    //How many milliseconds until midnight? hours converted to ms + minutes converted to ms + seconds converted to ms 
    msTillMidnight = ((23-(myClock->hour))*60*60*1000)+((59-(myClock->minute))*60*1000)+((59-(myClock->second))*1000);
    msTillMidnight = msTillMidnight + 20000;
   
    //use as test value` 
    //msTillMidnight = 1000*5;

    struct tm tm = {0};
    time_t time1, time2;
    struct tm date1 = {0}, date2 = {0};

    // set the two dates
    date1.tm_year = 20+100; // year - 1900
    date1.tm_mon = 1 - 1; // month (0-11)
    date1.tm_mday = 1; // day of the month
    time1 = mktime(&date1);

    date2.tm_year = curYear+100;
    date2.tm_mon = curMonth - 1;
    date2.tm_mday = today;
    time2 = mktime(&date2);

    // get the difference in seconds
    long diff = difftime(time2, time1);

    // convert to days
    long days = (int) (diff / (60 * 60 * 24));

    // time is measured in days since jan 1 2020, since that is the first value in the lookup table
    printf("days since jan 1 2020: %d ",days);

    // run the lookup table check and set
    phaseCheck(days);

    if(testVarCycle > -1)
    {
        cycle=testVarCycle;
    }

    printf("cycle: %d \n",cycle);
    int cyclesPassed = 0;

    // old comment, not sure if its relevant, wont delete, am scaredy cat
    // +1 here? to detect right on the new moon? does that create a problem the day before the new moon? test it?
    
    // Goes through all the moon data, when it sees a new moon counts it as one cycle passed 
    for(int i=0; i<days+1; i++)
    {
        if(myPhaseData.phaseDataArray[i]==0)
        {
            cyclesPassed=cyclesPassed+1;
        }
    }

    printf("cycles passed %d \n",cyclesPassed);

    //change to +3 (the +3 is just an offset so that it started on the "first" algo on launch day
    curEpoch= (cyclesPassed+3) % 4;

    //old way of checking current moon with calculations
    //curEpoch=myMoon.calcEpoch(curYear+2000,curMonth,today);
    
    if(testVarEpoch > -1)
    {
        curEpoch=testVarEpoch;
    }

    printf("epoch: %d",curEpoch);

}

//handles selecting which "algo" (mood) we are using based on the "epoch" (another term for mood)
void algoSetup()
{
  printf("Reached algo setup \n");
  printf("\n");
  printf("----------\n");

   int myContinuity=random(0,100);

  switch(curEpoch)
  {
	case 0:
	printf("CURRENT: Plain Algo\n");
	printf("cycle read: %d \n",cycle);

    //first constructor argument is the ID of the object - 1 for the A section, and 2 for the B section

    //continuity is the name of a variable that A and B object share, so that they can calculate random variables that will be the same for both of them, or related to the other objects value (ie, a random value, but B's is always half of A's)
    
    myPlain1 = new AlgoPlain(1,curWeekday,cycle,myContinuity);

    //if full moon, use the same exact random seed for both A and B
    if(cycle==4){srand(todaySeed);}

    myPlain2 = new AlgoPlain(2,curWeekday,cycle,myContinuity);

    myPlain1->init();
    if(cycle==4){srand(todaySeed);}
    myPlain2->init();

    break;

	case 1:
		printf("CURRENT: Reich Algo\n");

    myReich1 = new AlgoReich(1,curWeekday,cycle,myContinuity);
    if(cycle==4){srand(todaySeed);}
    myReich2 = new AlgoReich(2,curWeekday,cycle,myContinuity);

    myReich1->init();
    if(cycle==4){srand(todaySeed);}
    myReich2->init();

    break;

  case 2:

    printf("CURRENT: Sparse Algo\n");

    mySparse1 = new AlgoSparse(1,curWeekday,cycle,myContinuity);
    if(cycle==4){srand(todaySeed);}
    mySparse2 = new AlgoSparse(2,curWeekday,cycle,myContinuity);

    mySparse1->init();
    if(cycle==4){srand(todaySeed);}
    mySparse2->init();

    break;


	case 3:

    printf("Current: Algo Vari \n");

    myVari1 = new AlgoVari(1,curWeekday,cycle);
    if(cycle==4){srand(todaySeed);}
    myVari2 = new AlgoVari(2,curWeekday,cycle);

    myVari1->init();
    if(cycle==4){srand(todaySeed);}
    myVari2->init();
    
    break;


  case 4:

      printf("CURRENT: Blocks Algo\n");

      myBlocks1 = new AlgoBlocks;
      myBlocks2 = new AlgoBlocks;

      myBlocks1->init(inPin1,outPin1,curWeekday,cycle);
      myBlocks2->init(inPin2,outPin2,curWeekday,cycle);

      break;

  case 5:

		printf("CURRENT: WONK\n");

    myWonk1 = new AlgoWonk;
    myWonk2 = new AlgoWonk;

    myWonk1->init(inPin1,outPin1,curWeekday,cycle);
    myWonk2->init(inPin2,outPin2,curWeekday,cycle);

    break;

  case 6:

		printf("CURRENT: ALGO OVER\n");

    myOver1 = new AlgoOver;
    myOver2 = new AlgoOver;

    myOver1->init(inPin1,outPin1,curWeekday,cycle);
    myOver2->init(inPin2,outPin2,curWeekday,cycle);

    break;

  case 7:
    printf("CURRENT: Culture Algo\n");

    myCulture1 = new AlgoCulture;
    myCulture2 = new AlgoCulture;

    myCulture1->init(inPin1,outPin1,1,4);
    //Culture1->init(inPin1,outPin1,curWeekday,cycle);
    myCulture2->init(inPin2,outPin2,curWeekday,cycle);

    break;
    }
}

void midnightCheck()
{

  msSinceBoot= to_ms_since_boot(get_absolute_time());

  if(msSinceBoot > msTillMidnight)
  {
    //if past midnight, start the light animation
    
    long long elapsed = msSinceBoot - msTillMidnight;

    if(elapsed > midnightAnimCounter)
    {
        //set lights to a random color and speed up the animation
        myLight.setLights(1,curWeekday,cycle,curEpoch);
        midnightAnimCounter = elapsed + midnightAnimDelay;
        midnightAnimDelay *= .925;
    }

    if(midnightAnimDelay < 100)
    {
        //Reset the pico (once animation is fast enough and therefore done)
        watchdog_enable(1, 1);
        while(1);
    }

    //swelling pwm and maybe rainbow 
    //or smooth transition through all rainbow colors
    
  }
}

void loop()

{

  
  //this writes the status pins
  //its opposite because of the reverse circuitry
  
  gpio_put(ledPin1,!gpio_get(outPin1));
  
  
  if(cycle!=0)
  {
    //if new moon, don't light b
    gpio_put(ledPin2,!gpio_get(outPin2));
  } else {
    gpio_put(ledPin2,0);
  }

  if(!timeChecked)
  {
    //mama mia, spaghetti 
    //this is because there is a specific order that things def have to be done in, and also because I am bad
    algoSetup();
    timeChecked=true;
    myIO.curWeekday=curWeekday;
    myIO.curCycle=cycle;

    if(testVarStandalone==true)
    {
        myIO.autoOn=true;
    }
  }

  if(timeChecked)
  {
    //get values from the IO object for input 
    //this buffering steps lets us more easily switch to standalone mode because we can make up input values internally 
    
    in1Val = myIO.read(1);
    in2Val = myIO.read(2);

    //this seems a bit too busy so it's commented out for now
    //if(myIO.autoOn)
    if(false)
    {
        if(in1Val && in2Val ==1)
        {
            printf("both \n");
            myLight.setLights(5,0,0,0);
        } else if(in1Val==1) {
            myLight.setLights(3,0,0,0);
        } else if(in2Val==1) {
            myLight.setLights(4,0,0,0);
        }
    }

  	switch(curEpoch)
  	{
      
  	case 0:
  		myPlain1->tick(in1Val);
        if(cycle != 0){myPlain2->tick(in2Val);}// if it's a new moon don't run B
     break;

  	case 1:
  		myReich1->tick(in1Val);
  		if(cycle != 0){myReich2->tick(in2Val);}
     break;

  	case 2:
  		mySparse1->tick(in1Val);
  		if(cycle != 0){mySparse2->tick(in2Val);}
     break;

  	case 3:
  		myVari1->tick(in1Val);
  		if(cycle != 0){myVari2->tick(in2Val);}
      break;

  	case 4:
  		myBlocks1->tick();
  		if(cycle !=0){myBlocks2->tick();}
      break;

  	case 5:
  		myWonk1->tick();
  		if(cycle !=0){myWonk2->tick();}
      break;

    case 6:
      myOver1->tick();
  	  if(cycle !=0){myOver2->tick();}
    break;

    case 7:
      myCulture1->tick();
  	  if(cycle !=0){myCulture2->tick();}
    break;

    }
  } 

}

void autoClockManager()
{
    /*
    if(gpio_get(inPlugCheck1)==0 && gpio_get(inPlugCheck2==0)
    {
        plugNoiseCheck++;
    }

    if(plugNoiseCheck>10)
    {
        noCables=true;
    }
    */

    /*
    printf("nextPlug: %lld \n",msSinceBoot);
    
    if(gpio_get(inPlugCheck1)==1 || gpio_get(inPlugCheck2==1))
    {
        noCables=false;
        myIO.autoOn=true;
    }

    if(msSinceBoot>nextPlugCheckTime)
    {
        if(noCables)
        {
            myIO.autoOn=true;

        } else {

            myIO.autoOn=false;
        }
        nextPlugCheckTime=msSinceBoot+5*1000;
        printf("nextPlug %lld",nextPlugCheckTime);
        noCables=true;
    }
    */
    myIO.standaloneListener();

    if(myIO.autoOn)
    {
        myIO.internalTick(1);
        myIO.internalTick(2);
    }
}

int main(){

    stdio_init_all();

    //if we're using usb for printing, wait to start until connected so that we get the first values
    if(usbWait)
    {
    while (!tud_cdc_connected()) { sleep_ms(200); }
    }

        fileSetup();
        setup();

        clockSetup();
        todaySeed=today+curMonth+curYear+seedOffset;

        if(!testVarRandom)
        {
            srand(todaySeed);
        } else {
            srand(testVarSeed);
        }

        myLight.setLights(0,curWeekday,cycle,curEpoch);

        if(myFileSystem.shouldSetClock==true)
        {
            int dayLedPins[7]={7,1,0,2,11,9,8};
            int moonLedPins[8]={26,27,28,29,25,24,18,23};   

            for(int i=0; i<7; i++)
            {
                gpio_init(dayLedPins[i]);
                gpio_set_dir(dayLedPins[i],GPIO_OUT);
                gpio_put(dayLedPins[i],1);
            }

            for(int i=0; i<8; i++)
            {
                gpio_init(moonLedPins[i]);
                gpio_set_dir(moonLedPins[i],GPIO_OUT);
                gpio_put(moonLedPins[i],1);
            }
        }

        printf("\n\n");
        printf("hello petrock epoch %d \n",curEpoch);
        printf("hello petrock cycle %d \n",cycle);

        printf("XOSC startup var read: %d \n", PICO_XOSC_STARTUP_DELAY_MULTIPLIER);
        printf("timeout read: %d \n", PICO_STDIO_USB_CONNECT_WAIT_TIMEOUT_MS);


    while(true)
    {
    loop();
    midnightCheck();
    autoClockManager();
    //currently running this as a "tight loop" didn't see heat performance improvement when I tried adding a delay
    //maybe could do another go around testing that though
    }
    //return 0;
}
