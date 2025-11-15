#include "RaceManager.h"
#include "LandRace.h"
#include "AirRace.h"
#include "MixedRace.h"

std::unique_ptr<Race> RaceManager::createRace(RaceType type, double distance) 
{
    switch (type) 
    {
    case RaceType::LAND:   return std::make_unique<LandRace>(distance);
    case RaceType::AIR:   return std::make_unique<AirRace>(distance);
    case RaceType::MIXED: return std::make_unique<MixedRace>(distance);
    }
    return nullptr;
}

bool RaceManager::isValidParticipant(const Transport& transport, RaceType raceType) 
{
    if (raceType == RaceType::LAND && transport.isAir) return false;
    if (raceType == RaceType::AIR && !transport.isAir) return false;
    return true;
}
