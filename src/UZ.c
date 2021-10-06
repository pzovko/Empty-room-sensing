#include "myLib.h"

volatile unsigned long start_time = 0, end_time = 0;

void InitUZ()
{
    pinMode(UZ_pin_trig, OUTPUT);
    pinMode(UZ_pin_echo, INPUT);
    digitalWrite(UZ_pin_echo, LOW);
    digitalWrite(UZ_pin_trig, LOW);
    attachInterrupt(digitalPinToInterrupt(UZ_pin_echo), UZ_interrupt, CHANGE);
}

unsigned long UZ_measure()
{
    digitalWrite(UZ_pin_trig, HIGH);
    delayMicroseconds(10);  
    digitalWrite(UZ_pin_trig, LOW);
    delay(100);
    return GETDIST((end_time-start_time));
}
void UZ_disable()
{
    detachInterrupt(UZ_pin_echo);
}

void UZ_interrupt()
{
    if(digitalRead(UZ_pin_echo) == HIGH)
    {
        start_time = micros();
        end_time = 0;
    }   
    else
        end_time = micros();       
}