#pragma once
#include "Race.h"

class AirRace : public Race 
{
public:
    AirRace(double distance) : Race(RaceType::AIR, distance) {}
};
