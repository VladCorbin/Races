#pragma once
#include "Race.h"
#include <memory>

class RaceManager 
{
public:
    static std::unique_ptr<Race> createRace(RaceType type, double distance);
    static bool isValidParticipant(const Transport& transport, RaceType raceType);
};
