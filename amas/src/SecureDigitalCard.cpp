#include "SecureDigitalCard.h"
SecureDigitalCard::SecureDigitalCard(int pn) : Sensor(pn){}

int SecureDigitalCard::init(const char* text)
{
	Serial.begin(115200);
	while (!Serial) {}
	Serial.println("Inicializando SD.");
  SD.begin(4);
	Serial.println("Inicializado com sucesso.");
	Serial.println(text);
	Serial.end();
	loop(text);
	return 1;
}

void SecureDigitalCard::loop(const char* text_tobe_written)
{
  Serial.begin(115200);
	File log = SD.open("log.txt", FILE_WRITE);
	if (log) {
		Serial.println("Iniciando escrita ao arquivo 'log.txt'.");
		log.println(text_tobe_written);
		log.close();
		Serial.println("Feito");
	}
	else {
		Serial.println("Houve algum erro ao abrir 'log.txt'.");
		return;
	}
	return;
}


SecureDigitalCard::~SecureDigitalCard()
{
}
