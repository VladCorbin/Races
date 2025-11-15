#include "Race.h"

Race::Race(RaceType type, double distance) : type(type), distance(distance) {}

void Race::addParticipant(std::unique_ptr<Transport> transport) 
{ participants.push_back(std::move(transport));}

std::vector<ParticipantResult> Race::run()
{
    std::vector<ParticipantResult> results;
    for (const auto& participant : participants)
    {
        results.push_back
        ({
            participant->getName(),
            participant->calculateTime(distance)

        });
    }
    std::sort(results.begin(), results.end());
}