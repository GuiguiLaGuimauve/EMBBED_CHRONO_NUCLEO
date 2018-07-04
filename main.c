#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

DigitalIn  button1(D0);
DigitalIn  button2(D1);

void display_time();

int main()
{
    time_t  start, newtime;

    bool    hasStarted = false;
    bool    isPaused = false;
    double  result;

    while (1)
    {
        resultat = difftime(start, newtime) ; 

        if (button1)
        {
            if (hasStarted == false)
                debut = time(NULL);
            else if (isPaused == false)
                isPaused = true;
            else
                isPaused = false;
        }
         if (button2) // reset button
        {
            debut = time(NULL);            
            hasStarted = false;
        }   
        ////////////
        if (!isPaused)
        {
            wait(0.01);
            newtime = time(NULL);
        }
        display(result);
    return 0;
}

void display_time(double res)
{
    printf("euh t'as moyen de faire ça :D");
}