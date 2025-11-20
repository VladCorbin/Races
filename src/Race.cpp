#include "Race.h"
#include <algorithm>

Race::Race(Type type, double distance)
    : type(type), distance(distance) {}

bool Race::registerTransport(const Transport* transport) 
{
    if ((type == Type::Ground && transport->getType() != TransportType::Ground) ||
        (type == Type::Air && transport->getType() != TransportType::Air)) 
    { return false; }

    for (const auto* t : participants) 
    { if (t->getName() == transport->getName()) return false; }

    participants.push_back(transport);
    return true;
}

std::vector<RaceResult> Race::start() const 
{
    std::vector<RaceResult> results;
    for (const auto* transport : participants) 
    { results.push_back({ transport->getName(), transport->calculateTime(distance) }); }

    std::sort(results.begin(), results.end(), [](const RaceResult& a, const RaceResult& b) 
        { return a.time < b.time; });
    return results;
}
