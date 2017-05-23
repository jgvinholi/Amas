#include "classes/Ph.h"
#include "classes/SecureDigitalCard.h"
const int B_RESET = PUSH2;
const int B_ENABLE = 2;
const int S_COLOR = 29;
const int S_TERMOMETER = 28;
const int S_PH = 30;
unsigned int ph_v;

void setup() {
  // put your setup code here, to run once:
    pinMode(B_RESET, INPUT_PULLUP);
    pinMode(B_ENABLE, INPUT_PULLUP);
    Ph* ph_sensor = new Ph(S_PH);
    SecureDigitalCard* sdc = new SecureDigitalCard();
    ph_v = ph_sensor->setup();
    sdc->writeToLog(ph_v);
}

void loop() {
  
}
