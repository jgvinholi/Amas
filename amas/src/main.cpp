/*
 Name:		amas.ino
 Created:	6/4/2017 10:52:12 PM
 Author:	jgvin
*/
// the setup function runs once when you press reset or power the board
#include "Arduino.h"
#include "Global_Includes.h"
#include "Sensor.h"
#include "Ph.h"
#include "Thermo.h"
#include "SecureDigitalCard.h"
#include "MyServo.h"
#include <string.h>

Ph* ph_sensor;
Thermo* t_sensor;
SecureDigitalCard* sdc;
MyServo* mechanicArm;
String Word;
void setup() {
	sdc = new SecureDigitalCard(4); // CS = 4
	mechanicArm = new MyServo(8);
	ph_sensor = new Ph(14); // ADC0
}

// the loop function runs over and over again until power down or reset
void loop() {
	mechanicArm->init();
	mechanicArm->goKcl();
	mechanicArm->goPh();
	String ph_v(ph_sensor->setup());
	mechanicArm->goCleaning();
    delay(3*MS_TO_S);
    //String t_v(t_sensor->init());
	Word = "Ph = " + ph_v + ". Temperatura = "/* + t_v */ + "Amas está ativo há " + millis()/(60.0*1000.0) + "minutos.\n";
	
	//Word = "Teste2";
	sdc->init(Word.c_str());
	Sensor::sWrite(Word.c_str());
}
