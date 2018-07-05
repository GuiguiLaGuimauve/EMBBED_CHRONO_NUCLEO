#include "mbed.h"
#include "TextLCD.h"

#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
#include <math.h>

TextLCD lcd(D9, D8, D7, D6, D5, D4); // rs, e, d4, d5, d6, d7

DigitalOut led(LED1);

DigitalIn reset(D15);
DigitalIn	start_stop(D14);

void display_time(int result) {
	
	
	lcd.cls();
	lcd.locate(0,0);
  lcd.printf("%02d:%02d:%02d",result/3600, result/60, result%60);
	wait_ms(10);
}

void chrono() {
	time_t start, newtime;
	double stop = 0.0;
	double result = 0.0;
	bool isPaused = true;
	bool isStarted = false;
	
	while (1) {
		if (!isPaused) {
			newtime = time(NULL);
			result = difftime(newtime, start) + stop;
		}
		if (!start_stop) {
			if (isStarted) {
				if (isPaused) {
					isPaused = false;
					stop = result;
					start = time(NULL);
				}
				else
					isPaused = true;
			} else {
				start = time(NULL);
				isPaused = false;
				isStarted = true;
			}
			wait_ms(500);
		}
		
		if (!reset && isPaused) {
			isStarted = false;
			isPaused = true;
			result = 0.0;
		}
		display_time((int)result);
	}
}
int main()
{
	lcd.cls();
	chrono();
}
