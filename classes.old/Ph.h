/*
 * Ph.h
 *
 *  Created on: 17 apr 2017
 *      Author: jgvin
 */

#ifndef CLASSES_PH_H_
#define CLASSES_PH_H_
#define SensorPin A0            //pH meter Analog output to Arduino Analog Input 0
#define Offset 0           //deviation compensate
#define LED 78
#define samplingInterval 20
#define printInterval 800
#define analysisInterval 5000
#define ArrayLenth  40

#include "Sensor.h"

class Ph: public Sensor
{
private:
    int S_PH;
    unsigned int loop();
    unsigned long samplingTime,printTime,analysisTime;
    float pHValue,voltage;
    double averagearray(int* arr, int number),avg;
    int i,max,min;
    long amount;
    int pHArray[ArrayLenth];

public:
    Ph(int pn);
    virtual ~Ph();
    unsigned int setup();
};

#endif /* CLASSES_PH_H_ */
