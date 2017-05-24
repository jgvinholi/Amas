/*
 * Temperature.cpp
 *
 *  Created on: May 11, 2017
 *      Author: jgvin
 */

#include <classes/Temperature.h>
DS18B20 ds(OWPIN);

Temperature::Temperature(int pn) : Sensor(pn)
{
    S_TEMP = getP_NUMB();
    pinMode(S_TEMP, INPUT_PULLUP);
    ROMmax = 0;
    ROMcount = 0;
    foundOW = false;
}

char* Temperature::setup(){
    sWrite("Sensor Temperatura.\n");
    findOW();
    displayOW();
    char* temp;
    temp = loop();
    return temp;
}

char* Temperature::loop(){
    char temp[ROMmax];
    tempCMD();
    for (i=1; i<ROMmax+1; i++){
        if(ROMtype[i] == 0x28){
            readOW(i);
            saveTemperature(i);
        }
    }
    for (i=1;i<ROMmax+1;i++){
      if (ROMtype[i]==0x28) {
          foundOW=true;
          temp[i] = result[i];
          Serial.print("OW");
          Serial.print(i);
          Serial.print("=");
          Serial.print(result[i]);
          Serial.print("C ");
      }
    }
    char* temp_p = temp;
    return temp_p;
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

void Temperature::displayOW(void)
{
  uint8_t i;
  Serial.println ("From array");
  for (ROMcount=1; ROMcount<ROMmax+1; ROMcount++) {
  ds.reset();
    for( i = 0; i < 8; i++) {
      if (ROMarray[ROMcount][i]<16) Serial.print("0");
      Serial.print( ROMarray[ROMcount][i], HEX);
      Serial.print(" ");
    }
    Serial.println("");
  }
}

void Temperature::readOW(uint8_t ROMno)
{
   uint8_t i;
   ds.reset();
   ds.select(ROMarray[ROMno]);
   ds.write_byte(0xBE);         // Read Scratchpad
   for ( i = 0; i < 9; i++) {   // need 9 bytes
      data[i] = ds.read_byte();
    #if TEST
          if (data[i]<16) Serial.print("0");
          Serial.print(data[i], HEX);
          Serial.print(" ");
    #endif
   }
}
void Temperature::saveTemperature(uint8_t ROMno){
    int32_t newtemp32;
    uint8_t i;
    newtemp32=data[1]<<8;
    newtemp32=(newtemp32+data[0])>>4;
    result[ROMno]=byte(newtemp32);
    i=(data[0] & 0x0F)* 625/1000;
    if (i>=5)  result[ROMno]++;
}


void Temperature::tempCMD(void){      //Send a global temperature convert command
  ds.reset();
  ds.write_byte(0xcc);  // was ds.select(work); so request all OW's to do next command
  ds.write_byte(0x44);  // start conversion, with parasite power on at the end
  delay(1000);
}
Temperature::~Temperature()
{

}

