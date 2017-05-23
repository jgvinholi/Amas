#include "Energia.h"

#line 1 "/home/vinholi/workspace_v7/AMAS/AMAS.ino"
#include "classes/Ph.h"
void setup();
void loop();

#line 2
const int B_RESET = PUSH2;
const int B_ENABLE = 2;
const int S_COLOR = 29;
const int S_TERMOMETER = 28;
const int S_PH = 30;

void setup() {
  
    pinMode(B_RESET, INPUT_PULLUP);
    pinMode(B_ENABLE, INPUT_PULLUP);
    Ph* ph_sensor = new Ph(S_PH);
    ph_sensor->setup();
}

void loop() {
  
}



