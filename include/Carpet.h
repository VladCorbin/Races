#pragma once
#include "AirTransport.h"

class Carpet : public AirTransport 
{
public:
    Carpet() : AirTransport(10, "Ковёр-самолёт") {}
    double getReductionCoeff(double distance) override 
    {
        if (distance < 1000) return 0.0;
        else if (distance < 5000) return 0.03;
        else if (distance < 10000) return 0.1;
        else return 0.05;
    }
};
