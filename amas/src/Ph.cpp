/*
* Ph.cpp
*
*  Created on: 17 apr 2017
*      Author: jgvin
*/

#include "Ph.h"
//Store the average value of the sensor feedback
int pHArrayIndex = 0;

Ph::Ph(int pnumb) : Sensor(pnumb)
{
	S_PH = pnumb;
}

double Ph::setup() {
	pinMode(LED, OUTPUT);
	Serial.begin(115200);
	Serial.println("Sensor PH.\n");
	const unsigned int loop_r = loop();
	return loop_r;
}

double Ph::loop() {
	for(int i = 0; i<10; i++){
		voltage += analogRead(14)*5.0/1024.0 ;
		delay(500);
	}
	voltage = voltage/10.0;
	pHValue = 7.0 + ((2.5 - voltage) / 0.18);
	return pHValue;
}

/*double Ph::averagearray(int* arr, int number) {
	amount = 0;
	if (number <= 0) {
		Serial.println("Error number for the array to averaging!/n");
		return 0;
	}
	if (number<5) {   //less than 5, calculated directly statistics
		for (i = 0; i<number; i++) {
			amount += arr[i];
		}
		avg = amount / number;
		return avg;
	}
	else {
		if (arr[0]<arr[1]) {
			min = arr[0]; max = arr[1];
		}
		else {
			min = arr[1]; max = arr[0];
		}
		for (i = 2; i<number; i++) {
			if (arr[i]<min) {
				amount += min;        //arr<min
				min = arr[i];
			}
			else {
				if (arr[i]>max) {
					amount += max;    //arr>max
					max = arr[i];
				}
				else {
					amount += arr[i]; //min<=arr<=max
				}
			}//if
		}//for
		avg = (double)amount / (number - 2);
	}//if
	return avg;
}
*/
Ph::~Ph()
{
	// TODO Auto-generated destructor stub
}
