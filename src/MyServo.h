#pragma once
#include "Sensor.h"
#include "Global_Includes.h"
#include <Servo.h>

class MyServo : 
    public Sensor
{
    private:
        int up(), down(), downmid(), mid(), left(), right();
        Servo *angularServo, *radialServo;
    public:
        MyServo(int pn);
        int init(), goKcl(), goPh(), goCleaning();
};