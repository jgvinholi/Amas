/*
 * Temperature.h
 *
 *  Created on: May 11, 2017
 *      Author: jgvin
 */

#ifndef CLASSES_TEMPERATURE_H_
#define CLASSES_TEMPERATURE_H_
#include "Sensor.h"
//#include "StellarisOW/GFDS18B20.h"
#include "StellarisOW/StellarisDS18B20.h"
#define OWPIN 27
#define MAXOW 10

class Temperature: public Sensor
{
private:

    int S_TEMP;
    void loop(),findOW(), readOW(uint8_t ROMno), saveTemperature(uint8_t ROMno), tempCMD();
    byte ROMarray[MAXOW][8];
    byte ROMtype[MAXOW];     // 28 for temp', 12 for switch etc.
    byte ROMtemp[MAXOW];
    byte result[MAXOW+5];
    byte data[12];
    byte i;
    byte addr[8];
    uint8_t ROMmax;
    uint8_t ROMcount;
    boolean foundOW;
    //DS18B20 ds(OWPIN);
public:
    Temperature(int pn);
    virtual ~Temperature();
    int setup();
};

#endif /* CLASSES_TEMPERATURE_H_ */
