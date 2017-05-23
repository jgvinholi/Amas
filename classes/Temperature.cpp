/*
 * Temperature.cpp
 *
 *  Created on: May 11, 2017
 *      Author: jgvin
 */

#include <classes/Temperature.h>

Temperature::Temperature(int pn) : Sensor(pn)
{
    S_TEMP = getP_NUMB();
    pinMode(S_TEMP, INPUT_PULLUP);
}

int Temperature::setup(){
    sWrite("Sensor Temperatura.\n");
    loop();
    return 0;
}

void Temperature::loop(){

}
Temperature::~Temperature()
{

}

