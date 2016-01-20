
#include <iostream>
#include <stdio.h>
#include <time.h>
//#include <unistd.h>
//#include <signal.h>
//#include <err.h>
//#include <stdbool.h>

#include "mraa.hpp"

#define GPIO14 36
#define GPIO15 48
#define HIGH 1
#define LOW  0


unsigned long pulse_width;
unsigned long pTime,count;
unsigned long cTime;
int timeOut = 0;
#define TIMEOUT 1000
int main()
{
	mraa::Gpio* trigger_pin = NULL;
	mraa::Gpio* monitor_pin = NULL;
	trigger_pin = new mraa::Gpio(GPIO14);
	monitor_pin = new mraa::Gpio(GPIO15);
	trigger_pin->dir(mraa::DIR_OUT);
	monitor_pin->dir(mraa::DIR_IN);
	while(1)
	{
		count = 0;
		pTime = clock();
		if(monitor_pin->read() == HIGH)
		{
			while(monitor_pin->read() == HIGH)
			{
				//count++;
			}
			cTime = clock();
			pulse_width = cTime - pTime;//count;
			if(pulse_width != 0)
			{
				pulse_width = pulse_width/10;
				std::cout << pulse_width << std::endl;
			}
		}


		sleep(0.5);

	}
}

