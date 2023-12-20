# PET ROCK 

for questions and concerns email me at petrockjonah@gmail.com
 
might take a bit for me to accept any PRs, it's my first time hosting open source code, so I need to get used to the workflow of doing changes to a codebase

rough directory:

main.cpp - handles . . . way too much, big ole jumble of all the main functions of the modules - selecting and running the algorythms, resetting the module at midnight, pointing to all different stuff like when to check/set the clock etc. etc. Glues everything else together messily

Clock.h/.cpp - handles reading and setting the real time clock 

FileSystem.h - handles the internal long term filesystem, used to check if the clock needs to be set on startup

Light.h - handles leds, including the RGBLED

IO.h - handles clock input and standalone mode

PhaseData.h - stores the lookup table for the moon phase data

manager.h - for now just handles the actual table lookup for moon phase 

Rhythm Generation Algorythms ("mood") used in the official firmware

(red)    AlgoPlain.h/.cpp
(blue)   AlgoReich.h/.cpp
(yellow) AlgoSparse.h/.cpp
(green)  AlgoVari.h/.cpp

jfunc - some helper functions (jonah's functions)


## DEPRECATED

Moon.h - old moon phase calulator

Unused moods
AlgoBlocks.h/.cpp
AlgoCulture.h/.cpp
AlgoOver.h/.cpp
AlgoWonk.h/.cpp


## ATTN: Rough seas ahead, threat level high, forest fire risk level: red, etc. etc. (some guy broke into my house and wrote all this shitty code, don't blame me, he seemed crazy)

I wasn't really thinking at all about this code being open sourced, or read by other people, let alone understood or edited/contributed to. It's also my first project in c/c++, and a lot of the code was ported over from arduino with big ole find and replaces when I switched from using an arduino to rpi pico and then a custom rp2040 board.

My coding philosophy in a nutshell: does it work? if yes, I don't care about how shitty it is. This whole project is a massive string of things that I have glued together enough to work, then tested if they do in fact work in some different situations, then called it a day. If I didn't do things that way it wouldn't exist - if I didn't do things that way I should be back in college getting a real CS degree and not taking 2 CS classes, I should be getting an EE degree for the custom hardware, blah blah blah. I don't really believe in learning the principles, the big picture, and then doing project specifics later once you've "accumulated enough base knowledge". I learn exactly the one things I need to learn for any given problem, and then I move on to the next problem, in a string of fun little puzzle problems, until the project is done. This really allows me to punch above my weight when it comes to making something bigger than my knowledge should allow me too. So there's lots of basic stuff I probably don't know (especially when it comes to the electronics/hardware side of things) bear with me. 

 
