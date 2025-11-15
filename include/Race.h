#pragma once
#include "Transport.h"
#include <vector>
#include <memory>

enum class RaceType { LAND, AIR, MIXED };

struct ParticipantResult 
{
    std::string name;
    double time;
    bool operator<(const ParticipantResult& other) const { return time < other.time; }
};

class Race 
{
protected:
    RaceType type;
    double distance;
    std::vector<std::unique_ptr<Transport>> participants;

public:
    Race(RaceType type, double distance);
    void addParticipant(std::unique_ptr<Transport> transport);
    std::vector<ParticipantResult> run();
};
