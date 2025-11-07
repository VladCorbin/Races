#pragma once
#include "Transport.h"

class AirTransport : public Transport
{
public:
	AirTransport(double speed, const std::string& name);
	virtual double getReductionCoeff(double distance) = 0;
	double calculateTime(double distance) override;
};