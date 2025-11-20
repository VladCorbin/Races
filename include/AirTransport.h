#pragma once
#include "Transport.h"

class AirTransport : public Transport 
{
public:
    AirTransport(double speed, std::function<double(double)> coefficientFunc);
    double calculateTime(double distance) const override;

private:
    std::function<double(double)> coefficientFunc;
};
