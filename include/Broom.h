#pragma once
#include "AirTransport.h"

class Broom : public AirTransport 
{
public:
    Broom() : AirTransport(20, "Метла") {}
    double getReductionCoeff(double distance) override { return (distance / 1000.0) * 0.01; }
};
