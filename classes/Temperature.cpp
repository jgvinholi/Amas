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
    DS18B20 ds(OWPIN);
    loop();
    return 0;
}

void Temperature::loop(){

}

void Temperature::findOW(void)
{
 byte addr[8];
 uint8_t i;
 ROMmax=0;  ///////////////////////////////////////////////////////
 while (true){  //get all the OW addresses on the buss
   i= ds.search(addr);
   if ( i<10) {
      Serial.print("ret=(");
      Serial.print(i);
      Serial.print(") No more addresses.\n");
      ds.reset_search();
      delay(500);
      return;
    }
   Serial.print("R=");
    for( i = 0; i < 8; i++) {
       if (i==0)  ROMtype[ROMmax+1]=addr[i];  // store the device type

      ROMarray[ROMmax+1][i]=addr[i];

      if (addr[i]<16) Serial.print("0");
      Serial.print(addr[i], HEX);
      Serial.print(" ");
    }
    ROMmax++;
  Serial.print ("\t(OW");
    Serial.print (ROMmax,HEX);
    Serial.print (") Type=");
    Serial.println (ROMtype[ROMmax],HEX);
 }
}
Temperature::~Temperature()
{

}

