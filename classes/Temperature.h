/*
 * Temperature.h
 *
 *  Created on: May 11, 2017
 *      Author: jgvin
 */

#ifndef CLASSES_TEMPERATURE_H_
#define CLASSES_TEMPERATURE_H_
#include "Sensor.h"

class Temperature: public Sensor
{
private:
    int S_TEMP;
    void loop();
public:
    Temperature(int pn);
    virtual ~Temperature();
    int setup();
};

#endif /* CLASSES_TEMPERATURE_H_ */
