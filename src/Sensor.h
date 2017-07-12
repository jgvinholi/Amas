#pragma once
/*
* Sensor.h
*
*  Created on: 10 apr 2017
*      Author: jgvin
*/

#ifndef CLASSES_SENSOR_H_
#define CLASSES_SENSOR_H_
#include "Global_Includes.h"
class Sensor
{
private:
	int P_NUMB;
public:
	Sensor(int pn);
	virtual ~Sensor();
	int getP_NUMB();
	static void sWrite(const char* x);

};

#endif /* CLASSES_SENSOR_H_ */

