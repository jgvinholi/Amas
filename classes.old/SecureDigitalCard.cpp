/*
 * SecureDigitalCard.cpp
 *
 *  Created on: May 11, 2017
 *      Author: jgvin
 */

#include <classes/SecureDigitalCard.h>
static unsigned int AccStringLength;

SecureDigitalCard::SecureDigitalCard()
{
    AccStringLength = 0;
    pinMode(PUSH2, INPUT_PULLUP);
}

SecureDigitalCard::~SecureDigitalCard()
{
    // TODO Auto-generated destructor stub
}

/* Stop with dying message */
void SecureDigitalCard::die ( int pff_err  )
{
   Serial.println();
   Serial.print("Failed with rc=");
   Serial.print(pff_err,DEC);
   for (;;) ;
}

void SecureDigitalCard::printDec(uint32_t ui)
{
   Serial.print(ui/10, DEC);
   Serial.print(".");
   Serial.print(ui%10, DEC);
}

/*-----------------------------------------------------------------------*/
/* Program Main                                                          */
/*-----------------------------------------------------------------------*/
void SecureDigitalCard::writeToLog(const unsigned int ph_v, const char* t_v)
{

    PFFS fat = PFFS();
    StringLength = 0;
    counter = 0;
    Serial.begin(9600);
    fat.begin(cs_pin);

    #if DEBUG
    Serial.println();
    Serial.println("Opening log file to write temperature(LOG.txt).");
    delay(100);
    #endif

    rc = fat.open("LOG.TXT");
    if (rc) die(rc);
    delay(100);
    bw=0;
    sprintf(buf, "pH = %u, T = %c Celsius. AMAS está rodando há %lu horas.\n\n", ph_v, t_v, millis()/(1000*3600));
    //sprintf( buf, "%u Current temperature is %lu.%lu\r\n", counter, ui32_ReadTemp/10, ui32_ReadTemp%10 );
    counter++;
    StringLength =  strlen(buf);
    Serial.println(buf);

    #if DEBUG
    Serial.print(StringLength, DEC);
    Serial.println();
    Serial.print(AccStringLength, DEC);
    #endif

    rc = fat.lseek( AccStringLength );
    if (rc) die(rc);
    AccStringLength =  AccStringLength + 512;
    rc = fat.write(buf, StringLength,&bw);
    if (rc) die(rc);
    rc = fat.write(0, 0, &bw);  //Finalize write
    if (rc) die(rc);
    rc = fat.close();  //Close file
    if (rc) die(rc);
    /*   #if READ
    delay(100);
    Serial.println();
    Serial.println("Read Temp data from the log file (LOG.txt).");
    delay(100);
    rc = fat->open("LOG.TXT");
    if (rc) die(rc);
    delay(100);
    for (;;) {
    rc = fat->read(buffer, sizeof(buffer), &br);    // Read a chunk of file
    if (rc || !br) break;            // Error or end of file
    for (uint16_t i = 0; i < br; i++)        // Type the data
    Serial.print(buffer[i]);
    delay(100);
    }
    if (rc) die(rc);
    #endif
    */
   // Log delay
    delay(LOG_DELAY);
    Serial.print("Arquivo escrito com sucesso.\n");
    Serial.end();
}

