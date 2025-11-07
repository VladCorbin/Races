#pragma once
#include "Transport.h"

class LandTransport : Transport
{
protected:
	double driveTime;
	std::vector<double> restTimes;

public:
	LandTransport(double speed, const std::string& name, double driveTime, 
		const std::vector<double>& restTimes);
	double calculateTime(double distance ) override;
};