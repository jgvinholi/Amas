/*
 * SecureDigitalCard.h
 *
 *  Created on: May 11, 2017
 *      Author: jgvin
 */

#ifndef CLASSES_SECUREDIGITALCARD_H_
#define CLASSES_SECUREDIGITALCARD_H_
#define cs_pin      18             // chip select pin P3_0
#define read_buffer 128             // size (in bytes) of read buffer
#define LOG_DELAY   5000          // 5000ms -> 5sec
#include "Global_Includes.h"
class SecureDigitalCard
{
private:
    PFFS* fat;
    unsigned short int bw, br;
    char buffer[read_buffer], buf[128];
    int rc;
    DIR dir;
    FILINFO fno;
    uint32_t counter;
    static uint32_t AccStringLength;
    uint8_t StringLength;
    void die(int pff_err), printDec(uint32_t ui);
public:
    SecureDigitalCard();
    virtual ~SecureDigitalCard();
    void writeToLog(const unsigned int ph_v);
};

#endif /* CLASSES_SECUREDIGITALCARD_H_ */
