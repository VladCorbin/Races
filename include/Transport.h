#pragma once
#include <string>

enum class TransportType { Ground, Air };

class Transport 
{
public:
    Transport(TransportType type, double speed);
    virtual ~Transport() = default;

    TransportType getType() const;
    double getSpeed() const;
    virtual double calculateTime(double distance) const = 0;
    virtual std::string getName() const = 0;

protected:
    TransportType type;
    double speed;
};
