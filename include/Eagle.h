#pragma once
#include "AirTransport.h"

class Eagle : public AirTransport 
{
public:
    Eagle() : AirTransport(8, "Îð¸ë") {}
    double getReductionCoeff(double distance) override { return 0.06; }
};
