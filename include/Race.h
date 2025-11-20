#pragma once
#include <vector>
#include <string>
#include "Transport.h"

struct RaceResult 
{
    std::string name;
    double time;
};

class Race 
{
public:
    enum class Type { Ground, Air, Mixed };

    Race(Type type, double distance);
    bool registerTransport(const Transport* transport);
    std::vector<RaceResult> start() const;

private:
    Type type;
    double distance;
    std::vector<const Transport*> participants;
};
