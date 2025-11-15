#pragma once
#include "Race.h"

class MixedRace : public Race 
{
public:
    MixedRace(double distance) : Race(RaceType::MIXED, distance) {}
};
