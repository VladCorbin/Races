#include "Broom.h"
#include <cmath>

Broom::Broom() : AirTransport(20.0, [](double distance) -> double 
    { return 0.01 * static_cast<int>(distance / 1000.0); }) {}

std::string Broom::getName() const { return "Метла"; }
