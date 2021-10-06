#include <Arduino.h>
#include <avr/wdt.h>
#include <avr/sleep.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "UZ.h"
#include "7seg.h"

#define DEBUG

#define CE_PIN   9
#define CSN_PIN 10
#define RADIO_PIPELINE  0xF0F0F0F0FFLL

#define STATIC_DIST         150
#define STATIC_TOLERANCE    10

#define LOW_POINT  (STATIC_DIST-STATIC_TOLERANCE)

#define ROOM_EMPTY(x) ((x>LOW_POINT)? 0 : 1)


void ReprogramWDT();
void Sleep();
void DisableBOD_and_ADC();
void InitRadio();
bool RadioSend(short*);