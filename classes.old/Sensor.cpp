/*
 * Sensor.cpp
 *
 *  Created on: 10 apr 2017
 *      Author: jgvin
 */

#include <classes/Sensor.h>
using namespace std;

Sensor::Sensor(int pn):
        P_NUMB(pn) {}

int Sensor::getP_NUMB(){
    return P_NUMB;
}

void Sensor::sWrite(const char* x){
    Serial.begin(9600);
    Serial.write(x);
    Serial.end();
}
Sensor::~Sensor()
{}

