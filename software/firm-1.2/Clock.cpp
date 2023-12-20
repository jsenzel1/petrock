//Clock cpp class
#include "Clock.h"

/*
Clock::Clock()
{

}
*/


void Clock:: reset() {
    // Two byte reset. First byte register, second byte data
    // There are a load more options to set up the device in different ways that could be added here
//    uint8_t buf[] = {0x00, 0x58};
//    i2c_write_blocking(i2c_default, 0x68, buf, 2, false);
//
     //Set caps to higher val, everything else to 0
     uint8_t buf1[] = {0x00, 0x80};
     i2c_write_blocking(i2c_default, 0x68, buf1, 2, false);

     //uint8_t buf2[] = {0x00, 0x00};
     
     //A0 - 'direct' battery backup on, low power read disabled!
     uint8_t buf2[] = {0x02, 0xA0};

     i2c_write_blocking(i2c_default, 0x68, buf2, 2, false);
}

void Clock:: initClock(){

    i2c_init(i2c_default, 400 * 1000);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
    gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);
    // Make the I2C pins available to picotool
    bi_decl(bi_2pins_with_func(PICO_DEFAULT_I2C_SDA_PIN, PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C));

}
//add temp vars here
void Clock:: writeClock(int tWeekday,int tDay,int tMonth,int tYear, int tHour,int tMinute, int tZone) {
    // buf[0] is the register to write to
    // buf[1] is the value that will be written to the register
    uint8_t buf[2];

    int timeZone=tZone;
    int weekday=tWeekday;
    int second=50;
    int day=tDay;
    int month=tMonth;
    int year=tYear;

    int hour=tHour;
    int minute=tMinute;

    uint8_t current_val[7] = {bin2bcd(second), bin2bcd(minute), bin2bcd(hour), bin2bcd(day),bin2bcd(weekday), bin2bcd(month),bin2bcd(year)};

    for (int i = 3; i < 10; ++i) {
        buf[0] = i;
        buf[1] = current_val[i - 3];
        i2c_write_blocking(i2c_default, 0x68, buf, 2, false);
    }
}

void Clock:: readClock() {
    
    // For this particular device, we send the device the register we want to read
    // first, then subsequently read from the device. The register is auto incrementing
    // so we don't need to keep sending the register we want, just the first.

    // Start reading acceleration registers from register 0x3B for 6 bytes
    
    uint8_t val = 0x03;
    i2c_write_blocking(i2c_default, 0x68, &val, 1, true); // true to keep master control of bus
    i2c_read_blocking(i2c_default, 0x68, raw_time, 7, false);

    //DO WE NEED THIS SLEEP?
    //uncomment maybe 
    //sleep_ms(500);
    second = (10 * (int) ((raw_time[0] & 0x70) >> 4)) + ((int) (raw_time[0] & 0x0F));

    second = (10 * (int) ((raw_time[0] & 0x70) >> 4)) + ((int) (raw_time[0] & 0x0F));
    minute = (10 * (int) ((raw_time[1] & 0x70) >> 4)) + ((int) (raw_time[1] & 0x0F));
    hour = (10 * (int) ((raw_time[2] & 0x30) >> 4)) + ((int) (raw_time[2] & 0x0F));
    day = (10 * (int) ((raw_time[3] & 0x30) >> 4)) + ((int) (raw_time[3] & 0x0F)); 
    weekday = (int) (raw_time[4] & 0x07);
    month = (10 * (int) ((raw_time[5] & 0x10) >> 4)) + ((int) (raw_time[5] & 0x0F));
    year = (10 * (int) ((raw_time[6] & 0xF0) >> 4)) + ((int) (raw_time[6] & 0x0F));

    /*
    printf("second: %d \n",myClock.second);
    printf("hour: %d \n",myClock.hour);
    printf("minute: %d \n",myClock.minute);
    printf("day: %d \n",myClock.day);
    */
}

void Clock:: pcf8520_convert_time(int conv_time[7], const uint8_t raw_time[7]) {
    // Convert raw data into time
    conv_time[0] = (10 * (int) ((raw_time[0] & 0x70) >> 4)) + ((int) (raw_time[0] & 0x0F));
    conv_time[1] = (10 * (int) ((raw_time[1] & 0x70) >> 4)) + ((int) (raw_time[1] & 0x0F));
    conv_time[2] = (10 * (int) ((raw_time[2] & 0x30) >> 4)) + ((int) (raw_time[2] & 0x0F));
    conv_time[3] = (10 * (int) ((raw_time[3] & 0x30) >> 4)) + ((int) (raw_time[3] & 0x0F));
    conv_time[4] = (int) (raw_time[4] & 0x07);
    conv_time[5] = (10 * (int) ((raw_time[5] & 0x10) >> 4)) + ((int) (raw_time[5] & 0x0F));
    conv_time[6] = (10 * (int) ((raw_time[6] & 0xF0) >> 4)) + ((int) (raw_time[6] & 0x0F));
}

//Clock::~Clock(){};
//Clock:: Clock(){};
