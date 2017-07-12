#include "MyServo.h"

MyServo::MyServo(int pn) : Sensor(pn){
    angularServo = new Servo();
    radialServo = new Servo();
    angularServo->attach(8);
    radialServo->attach(9);
}
int MyServo::init(){
    angularServo->write(80);
    Sensor::sWrite("Angular: 80\n");
    delay(4000);
    radialServo->write(55);
    Sensor::sWrite("Radial: 55\n");
    delay(4000);
    return 1;
}
int MyServo::up(){
    radialServo->write(58);
   // const char* r = (const char*)radialServo->read();
    //const char* a = (const char*)angularServo->read();
    delay(4000);
    Sensor::sWrite("Radial:58\n");

    Sensor::sWrite("Up\n");
    return 1;
}

int MyServo::down(){
    radialServo->write(35);
    //const char* r = (const char*)radialServo->read();
    //const char* a = (const char*)angularServo->read();
    Sensor::sWrite("Radial:35");
    //Sensor::sWrite(r);
   // Sensor::sWrite("\n");
    //Sensor::sWrite("Angular:");
   // Sensor::sWrite(a);
    //Sensor::sWrite("\n");
    Sensor::sWrite("Down\n");
    delay(4000);
    return 1;
}

int MyServo::downmid(){
    radialServo->write(20);
    //const char* r = (const char*)radialServo->read();
    //const char* a = (const char*)angularServo->read();
    Sensor::sWrite("Radial:20\n");
    //Sensor::sWrite(r);
   // Sensor::sWrite("\n");
    //Sensor::sWrite("Angular:");
   // Sensor::sWrite(a);
    //Sensor::sWrite("\n");
    Sensor::sWrite("Down\n");
    delay(4000);
    return 1;
}

int MyServo::mid(){
    angularServo->write(80);
 //   const char* r = (const char*)radialServo->read();
  //  const char* a = (const char*)angularServo->read();
 //   Sensor::sWrite("Radial:");
 //   Sensor::sWrite(r);
//    Sensor::sWrite("\n");
    Sensor::sWrite("Angular: 80\n");
//    Sensor::sWrite(a);
//    Sensor::sWrite("\n");
    Sensor::sWrite("Mid\n");
    
    delay(4000);
    return 1;
}

int MyServo::left(){
    angularServo->write(45);
//    const char* r = (const char*)radialServo->read();
//    const char* a = (const char*)angularServo->read();
 //   Sensor::sWrite("Radial:");
 //   Sensor::sWrite(r);
//    Sensor::sWrite("\n");
    Sensor::sWrite("Angular: 45\n");
//   Sensor::sWrite(a);
 //   Sensor::sWrite("\n");
    Sensor::sWrite("Left\n");
    
    
    delay(4000);
    return 1;
}

int MyServo::right(){
    angularServo->write(110);
  //  const char* r = (const char*)radialServo->read();
 //   const char* a = (const char*)angularServo->read();
 //   Sensor::sWrite("Radial:");
 //   Sensor::sWrite(r);
 //   Sensor::sWrite("\n");
    Sensor::sWrite("Angular: 110");
  //  Sensor::sWrite(a);
   // Sensor::sWrite("\n");
    Sensor::sWrite("Right\n");
    
    delay(4000);
    return 1;
}

int MyServo::goKcl(){
    if(!up())
        return 0;
    delay(4000);
    if (!left())
        return 0;
    delay(4000);
    if (!down())
        return 0;
    delay(4000);
    Sensor::sWrite("Braço em KCl.\n");
    return 1;
}

int MyServo::goPh(){
    if(!up())
        return 0;
    delay(4000);
    if (!mid())
        return 0;
    delay(4000);
    if (!downmid())
        return 0;
    delay(4000);
    Sensor::sWrite("Braço medindo pH.\n");
    delay(30*MS_TO_S);
    return 1;
}

int MyServo::goCleaning(){
    if(!up())
        return 0;
    delay(4000);
    if (!right())
        return 0;
    delay(4000);
    if (!down())
        return 0;
    delay(5*MS_TO_S);
    if (!up())
        return 0;
    delay(5*MS_TO_S);
    if (!down())
        return 0;
    delay(5*MS_TO_S);
    if(!up())
        return 0;
    delay(4000);
    Sensor::sWrite("Sensor limpo.\n");
    return 1;
}