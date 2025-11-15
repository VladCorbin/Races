#include "AirTransport.h"

AirTransport::AirTransport(double speed, const std::string& name)
    : Transport(speed, name, true) {}

double AirTransport::calculateTime(double distance) 
{
    double coeff = getReductionCoeff(distance);
    double adjustedDistance = distance * (1 - coeff);
    return adjustedDistance / speed;
}
