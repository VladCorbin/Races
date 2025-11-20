#include "Carpet.h"

Carpet::Carpet() : AirTransport(10.0, [](double distance) -> double 
    {
    if (distance < 1000) return 0.0;
    if (distance < 5000) return 0.03;
    if (distance < 10000) return 0.1;
    return 0.05;
    }) {}

std::string Carpet::getName() const { return "Ковёр-самолёт"; }
