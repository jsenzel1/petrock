#include <stdio.h>
#include "pico/stdlib.h"
#include "jfunc.h" 
class Manager
{
	public:
		int howManyEpochs=6;
	int calcEpoch(int32_t myJD)
	{
		//week currently starts on sundays
		double myDoubleJD=myJD;
		double weeks=(myDoubleJD+2)/7;
		printf("weeks\n");
		printf("%d\n", weeks);
    int32_t myEpoch=(int32_t)weeks%(int32_t)howManyEpochs;
    printf("%d\n", myEpoch);
		//return (int)(weeks%howManyEpochs);
		return 1;
	}

};
