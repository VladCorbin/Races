#pragma once
#include "Transport.h"

class GroundTransport : public Transport 
{
public:
    GroundTransport(double speed, double moveTime, const std::vector<double>& restTimes);
    double calculateTime(double distance) const override;

private:
    double moveTime;
    std::vector<double> restTimes;
};
