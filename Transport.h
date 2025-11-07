#pragma once
#include <string>

class Transport
{
protected:
	double speed;
	std::string name;
	bool isAir;

public:
	Transport(double speed, const std::string& name, bool isAir);
	virtual bouble calculateTime(double distance) = 0;
	const std::string& getName() const;
	double getSpeed() const;
};