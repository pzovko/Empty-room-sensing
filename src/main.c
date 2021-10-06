#include "myLib.h"
short savedState = 0;
unsigned long counter = 0;

void setup() {
  Serial.begin(9600);
  ReprogramWDT();
  InitUZ();
  InitRadio();
}

void loop() {

  unsigned long distance = UZ_measure();
  short roomState = ROOM_EMPTY(distance);//true-puna false-prazna

    if(roomState == savedState)
    {
      #ifdef DEBUG
      Serial.println("sleep on");
      #endif

      counter++;

      #ifdef DEBUG
      Serial.println(counter);
      delay(100);
      #endif
      
      delay(500);

      if(counter == 10)
      {
        counter = 0;
        while(!RadioSend(&savedState));
        delay(50);
      }
      
      UZ_disable();
      Sleep();
    }
    else 
    {
      counter = 0;
      savedState = roomState;

      #ifdef DEBUG
      Serial.print("stanje se promijenilo, trenutno je ");
      Serial.println(savedState);
      #endif

      while(!RadioSend(&savedState));
      delay(50);
    }
}
 
ISR (WDT_vect)
{
  sleep_disable();
}