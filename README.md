# *!!! Open Source code and schematics coming soon, just need to clean it up to be a bit more publically readable !!!*

## Pet Rock technical details 
(this doc is a work in progress, just threw together the most commonly asked questions, and some fun lessons I learned, will continue updating)

contact me at jsenzel1@gmail.com with any inquiries 

# Design Elements of interest 

## *How does it keep track of real time?* 

Pet Rock keeps track of real time with a small real time clock, powered by a battery - similar to a wristwatch without a screen. I use the pcf8523 because it is cheap, and I'm not that concerened with accuracy (I generally need to tell what day it is, drifting by minutes isn't a big deal) This component is always on, even when everything is powered off. It keeps track of the date and time. I designed the circuit around the adafruit breakout board for the pcf8523 

## *How does it keep track of the moon phase?* 

I had initially implemented some not so complex moon phase tracking formulas into the code (you can calculate the rough moon phase with simple math if you have the date) but I found that every once in a while, it would get something wrong - I'm not sure if that was my fault or the formula, or a slew of other things, but eventually I got tired of all that and realized that there was a beautifully dumb and genius solution. I have plenty of memory on my board, and I realized that downloading the moon phase for every day in the next 100 years would only take about 100k, so I just scraped 100 years of moon data from a website for moon phases, and formatted it into a list which I look at when I need the corresponding day. It's a stupid solution, but it saved time and effort, and is more surefire, so its smarter. 

## *How do you set the clock with no buttons?* 

This was kind of a difficult problem. Pet rock has no buttons (the reset button on the back directly interfaces with the hardware, you can't use it as a programmable button) so how was I going to set the clock? One answer is to use the trigger input, and listen for a series of audio pulses that could be a binary code communicating the current time - but how would I even enter this calibration mode? maybe listen for a bit on every start up for a "start clock settting" code? This solution started getting complicated, and my module is designed to receive eurorack voltage triggers, not listen to line level audio coming from a computer.

I thought about including the current time in the source code somehow, but how would the user access/change this. You don't simply load source code onto the module, but rather a *binary* file, which isn't human readable or editable by normal means. Binary files are a mess of unreadable numbers - but, one thing you can pull out of them are words, or "strings" which is the programming term for a word. Words are stored as strings of numbers that refer to each letter in a row, so you can sift through the binary file and pick out a given word. Once you pick out this word, you can replace it with a different word, without effecting any other part of the binary file. So i created a code word, in this case "nanoplanktons" that was 13 letters long - and I replaced it with a sequence of numbers written as text. The numbers were as follows

digit 1   - today's day of the week
digit 2-3 - today's day of the month
digit 4-5 - current month 
digit 6-7 - current year
digit 8-9 - current hour (24 hour time)
digit 10-11 - current minute
digit 12-13 - time zone

(note, time zone isn't used right now, working on implementing it, only effects accuracy of which phase it is by 1 day, ocassionally) 

So the website reads your computer's clock, and prepares this 13 letter word that is the encoded time. Then it searches through the binary file which is on the website for the word "nanoplanktons" and replaces it with this coded time word

When pet rock starts, it can read this code and set the clock. So how does it know not to set the clock to that value every time, after its been done once? When the module completes a clock set, it stores the encoded time string in long term memory (which exists even when you upload new firmware to the module) Every time the modules starts up, it compares the long term storage value with the current value, and if they're different, it sets the clock, and store the new value in long term storage. 

# bugs fixed (that may be useful to you)

## clock startup delay

When using the rp2040 and a smallish crystal, you may find, like I did, that you have a high number of board failures that will perfectly accept a flashed program, but then fail to turn on again, or turn on 50% of the time, etc. That's because the board is trying to start up but the crystal hasn't stabilized yet, so it fails to boot. To fix this, you have to modify the variable "PICO_XOSC_STARTUP_DELAY_MULTIPLIER" which must be done in the CmakeLists.txt file as follows:

- startup delay - in cmakelists

     target_compile_definitions(test PRIVATE
    PICO_XOSC_STARTUP_DELAY_MULTIPLIER=173
    )

This is normal, the official pico sdk reflects this in the [adafruit](https://github.com/raspberrypi/pico-sdk/blob/master/src/boards/include/boards/adafruit_feather_rp2040.h) board files, noting "On some samples, the xosc can take longer to stabilize than is usual" but that info can be kind of hard to find, and confusing. 

## RTC batteries

I've had a lot of touchiness with RTC batteries. Note: they must be fully pushed in to the battery holder to work correctly, also I've had bad luck with cheap chinese batteries scrambling the clock. I think maybe it's also a good idea to wait a minute or two after installing a battery to test the module/turn it on, but that might be supersition (the thinking is similar to the main crystal, that the rtc crystal might need to stabilize on its own before being read, but I think realistically that probably happens in a fraction of a second, so this is probably wrong and based on vibes)

## C variable initializing

didn't know, in C/C++ you must initialize variables to 0 if you want them to be 0. Unlike other programming language, C doesn't default to zero for variable values. If you don't assign a variable any value, and then try to call it/use it/increment it, it could be any value, including a value that causes bugs etc.  

# rp2040 remote resest (works on rpi pico, and other rp2040 boards)

this isn't really a bug, but a good tip that took me a while to figure out

If you read the rp2040 and pico documentation, you'll really get the impression that the only way generally to reset the pico for flashing is to unplug it replug it in, while while holding down the bootsel button (or shorting the bootsel to ground in some other way). When you're iterating on software, that can be really annoying, you have to constantly unplug and plug it in, like a million times every time you're working on code. You can actually just send pico a 'magical baud rate' to put it in bootsel mode. Baudrate is the rate of data transmission, and setting it to a specific, low value (in this case 1200) makes the pico instantly stop and reboot into bootselect mode (where it acts like a flash drive)

on macos use this terminal command to do so (probably works the same on linux, windows you have to figure it out on your own somewhere else)

sudo stty -f /dev/(ls /dev/ | grep cu.usb) 1200 $argv


and then to automatically *make* and copy the build back onto the pico, I use this command from the build folder

make &&
sudo cp *.uf2 /Volumes/RPI-RP2 &&
sudo stty -f /dev/(ls /dev/ | grep cu.usb) 115200 $argv;

I've glued this two commands together as well so that I can just make a change, and then type one command and reboot the pico, and reupload the new code, all remotely (note, you have to add a delay in between the two commands of like 1.5 seconds minimum to wait for the pico to reboot before trying to upload) To do this, you'll also need to have USB enabled  
