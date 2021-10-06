#include "myLib.h"

RF24 radio(CE_PIN, CSN_PIN); 

void ReprogramWDT()
{
  cli(); 
  WDTCSR  = (1<<WDCE | 1<<WDE);
  WDTCSR  = (1<<WDIE) | (1<<WDP3)|(0<<WDP2) | (0<<WDP1) | (0<<WDP0);
  sei();        
  wdt_reset();
}
void Sleep()
{
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  cli();
  sleep_enable();
  sei();
  DisableBOD_and_ADC();
  sleep_cpu();
}

void DisableBOD_and_ADC()
{
  ADCSRA &= ~(1<<ADEN);
  MCUCR |= (1<<BODS) | (1<<BODSE);
  MCUCR &= ~(1<<BODSE); 
}

void InitRadio()
{
  radio.begin();
  radio.setPayloadSize(2);
  radio.openWritingPipe(RADIO_PIPELINE);
  radio.startListening();
}

bool RadioSend(short* data)
{
  radio.stopListening();
  bool ok = radio.write(data, sizeof(short));
  radio.startListening();

  if (ok)
    return true;
  else
    return false;
}
