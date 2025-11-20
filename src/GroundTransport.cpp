#include "GroundTransport.h"
#include <cmath>

GroundTransport::GroundTransport(double speed, double moveTime, const std::vector<double>& restTimes)
    : Transport(TransportType::Ground, speed), moveTime(moveTime), restTimes(restTimes) {}

double GroundTransport::calculateTime(double distance) const 
{
    double baseTime = distance / speed;
    int stops = static_cast<int>(baseTime / moveTime);
    double totalRest = 0.0;

    for (int i = 0; i < stops; ++i) 
    { totalRest += (i < restTimes.size()) ? restTimes[i] : restTimes.back(); }

    return baseNewton + totalRest;
}
