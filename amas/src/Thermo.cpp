#include "Thermo.h"
#include <stdio.h>
Thermo::Thermo(int pn) : Sensor(pn)
{
	this->pn = pn;
}

Thermo::~Thermo()
{
}

char* Thermo::init()
{
	sWrite("Iniciando termômetro.\n");
	ow = new OneWire(OW_BUS);
	dt = new DallasTemperature(ow);
	dt->begin();
	char* result = loop();
	return result;
}

char* Thermo::loop()
{
	sWrite("Solicitando temperatura.\n");
	dt->requestTemperatures();
	sWrite("OK.\n Temperatura é: ");
	sprintf(temp, "%.2f", dt->getTempCByIndex(0));
	sWrite(temp);
	sWrite("C.\n");
	return temp;
}



