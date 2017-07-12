#pragma once
#include "Sensor.h"
#include "Global_Includes.h"
#include <SPI.h>
#include <SD.h>

class SecureDigitalCard :
	public Sensor
{
private:
	void loop(const char* text_tobe_written);
public:
	int init(const char* text);
	SecureDigitalCard(int pn);
	~SecureDigitalCard();
};

/* 
The circuit:
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4 (for MKRZero SD: SDCARD_SS_PIN)
 */
