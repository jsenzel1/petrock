# Pet Rock

Pet Rock is a eurorack synthesizer module, which generates 1 new rhythm every 24 hours. Rhythm generation is influenced by the current real phase of the moon. Additionally, at the start of every complete moon cycle the overall rhythm generation algorithm changes, between 4 different algorithms. It is the slowest self changing piece of music technology ever created (to my knowledge, please discredit me on this - if something slower exists I will be very happy and have a million questions) 

Pet Rock is sold at cost of production (no profit) 

contact me at jsenzel1@gmail.com with any inquiries 

# Design Elements of interest 

## *How does it keep track of real time?* 

Pet Rock keeeps track of real time with a small real time clock, powered by a battery - similar to a wristwatch without a screeen. I use the pcf8523 because it is cheap, and I'm not that concerened with accuracy (I generally need to tell what day it is, drifting by minutes isn't a big deal) This component is always on, even when everything is powered off. It keeps track of the date and time. I designed the circuit around the adafruit breakout board for the pcf8523 

## *How does it keep track of the moon phase?* 

I had initially implemented some not so complex moon phase tracking formulas into the code (you can calculate the rough moon phase with simple math if you have the date) but I found that every once in a while, it would get something wrong - I'm not sure if that was my fault or the formula, or a slew of other things, but eventually I got tired of all that and realized that there was a beautifully dumb and genius solution. I have plenty of memory on my board, and I realized that downloading the moon phase for every day in the next 100 years would only take about 100k, so I just scraped 100 years of moon data from a website for moon phases, and formatted it into a list which I look at when I need the corresponding day. It's a stupid solution, but it saved time and effort, and is more surefire, so its smarter. 

## *How do you set the clock with no buttons? (besides the resest button which you can't use for input)



//bugs 

- startup delay - in cmakelists
- clock battery insert properly, use good batteries - maybe direct switching
- intialize variables to zero, always, 


tips 
- sending interrupt to reset pico
  
