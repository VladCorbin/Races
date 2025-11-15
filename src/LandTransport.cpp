#include "../include/LandTransport.h"

LandTransport::LandTransport(double speed, const std::string& name, double driveTime, const std::vector<double>& restTimes)
    : Transport(speed, name, false), driveTime(driveTime), restTimes(restTimes) {}

double LandTransport::calculateTime(double distance) 
{
    double baseTime = distance / speed;
    int fullCycles = static_cast<int>(baseTime / driveTime);
    double totalRest = 0.0;

    for (int i = 0; i < fullCycles; ++i) 
    {
        if (i < restTimes.size()) 
        { totalRest += restTimes[i]; }
        else { totalRest += restTimes.back(); }
    }
    return baseTime + totalRest;
}
