#pragma once
#include "Race.h"

class LandRace : public Race 
{
public:
    LandRace(double distance) : Race(RaceType::LAND, distance) {}
};
