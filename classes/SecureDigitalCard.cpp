/*
 * SecureDigitalCard.cpp
 *
 *  Created on: May 11, 2017
 *      Author: jgvin
 */

#include <classes/SecureDigitalCard.h>

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
void die ( int pff_err  )
{
   Serial.println();
   Serial.print("Failed with rc=");
   Serial.print(pff_err,DEC);
   for (;;) ;
}

void printDec(uint32_t ui)
{
   Serial.print(ui/10, DEC);
   Serial.print(".");
   Serial.print(ui%10, DEC);
}

/*-----------------------------------------------------------------------*/
/* Program Main                                                          */
/*-----------------------------------------------------------------------*/
void SecureDigitalCard::writeToLog(const unsigned int ph_v)
{
    StringLength = 0;
    counter = 0;
    Serial.begin(9600);
    FatFs.begin(cs_pin);
    #if 0
    Serial.println();
    Serial.println("Press button to start...");
    while(digitalRead(PUSH2)==1){}
    delay(100);
    while(digitalRead(PUSH2)==0){}
    #endif

    #if DEBUG
    Serial.println();
    Serial.println("Opening log file to write temperature(LOG.txt).");
    delay(100);
    #endif

    rc = FatFs.open("LOG.TXT");
    if (rc) die(rc);
    delay(100);
    bw=0;
    sprintf(buf, "PH = %u. AMAS está rodando há %lu horas.\n\n", ph_v, millis()/(1000*3600));
    //sprintf( buf, "%u Current temperature is %lu.%lu\r\n", counter, ui32_ReadTemp/10, ui32_ReadTemp%10 );
    counter++;
    StringLength =  strlen(buf);
    Serial.println(buf);

    #if DEBUG
    Serial.print(StringLength, DEC);
    Serial.println();
    Serial.print(AccStringLength, DEC);
    #endif

    rc = FatFs.lseek( AccStringLength );
    if (rc) die(rc);
    AccStringLength =  AccStringLength + 512;
    rc = FatFs.write(buf, StringLength,&bw);
    if (rc) die(rc);
    rc = FatFs.write(0, 0, &bw);  //Finalize write
    if (rc) die(rc);
    rc = FatFs.close();  //Close file
    if (rc) die(rc);
    /*   #if READ
    delay(100);
    Serial.println();
    Serial.println("Read Temp data from the log file (LOG.txt).");
    delay(100);
    rc = FatFs.open("LOG.TXT");
    if (rc) die(rc);
    delay(100);
    for (;;) {
    rc = FatFs.read(buffer, sizeof(buffer), &br);    // Read a chunk of file
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

