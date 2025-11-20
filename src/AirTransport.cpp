#include "AirTransport.h"

AirTransport::AirTransport(double speed, std::function<double(double)> coefficientFunc)
    : Transport(TransportType::Air, speed), coefficientFunc(coefficientFunc) {}

double AirTransport::calculateTime(double distance) const 
{
    double coeff = coefficientFunc(distance);
    double adjustedDistance = distance * (1.0 - coeff);
    return adjustedDistance / speed;
}
