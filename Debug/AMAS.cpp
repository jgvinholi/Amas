#include "Energia.h"

#line 1 "/home/vinholi/workspace_v7/AMAS/AMAS.ino"
#include <OneWire.h>
#include "classes/Ph.h"
#include "classes/SecureDigitalCard.h"
#include "classes/Temperature.h"
void setup();
void loop();

#line 5
const int B_RESET = PUSH2;
const int B_ENABLE = 2;
const int S_COLOR = 29;
const int S_THERMOMETER = 28;
const int S_PH = 30;
unsigned int ph_v;
char* t_v;
SecureDigitalCard* sdc;
Temperature* t_sensor;
Ph* ph_sensor;

void setup() {
  
    pinMode(B_RESET, INPUT_PULLUP);
    pinMode(B_ENABLE, INPUT_PULLUP);
    ph_sensor = new Ph(S_PH);
    sdc = new SecureDigitalCard();
    t_sensor = new Temperature(S_THERMOMETER);
}

void loop() {
    ph_v = ph_sensor->setup();
    t_v = t_sensor->setup();
    sdc->writeToLog(ph_v,t_v);
}



