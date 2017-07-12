#pragma once
#include "Sensor.h"
#include "Global_Includes.h"
#include <OneWire.h>
#include <DallasTemperature.h>

class Thermo :
	public Sensor
{
private:
	char* loop();
	char temp[16];
	const int OW_BUS = 2;
	int pn;
	OneWire* ow;
	DallasTemperature* dt;
public:
	char* init();
	Thermo(int pn);
	~Thermo();
};

