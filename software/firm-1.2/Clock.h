//RTC handler header

#include <stdio.h>
#include <string.h>

#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"

#include "hardware/i2c.h"

//#ifdef i2c_defaults

class Clock
{


private:


  #define PICO_DEFAULT_I2C_SDA_PIN 16
  #define PICO_DEFAULT_I2C_SCL_PIN 17

  bool writeTime = false;

  // By default these devices  are on bus address 0x68
  //static int addr = 0x68;

  static uint8_t bcd2bin (uint8_t val) { return val - 6 * (val >> 4); };
  static uint8_t bin2bcd (uint8_t val) { return val + 6 * (val / 10); };

public:
  
  void reset();

  void initClock();

  void writeClock(int,int,int,int,int,int,int);

  void readClock();

  void getPublic();

  void pcf8520_convert_time(int conv_time[7], const uint8_t raw_time[7]);

  bool timeChecked;
  
  uint8_t raw_time[7];

  int second=0;
  int minute=0;
  int hour=0;
  int day=0;
  int weekday=0;
  int month=0;
  int year=0;

  Clock(){};
  //~Clock();

};
