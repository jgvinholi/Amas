#pragma once
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <SD.h>
#include <SPI.h>
const int MS_TO_S = 1000UL;