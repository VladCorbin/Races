#include "FastCamel.h"

FastCamel::FastCamel() : GroundTransport(40.0, 10.0, { 5.0, 6.5, 8.0 }) {}

std::string FastCamel::getName() const { return "Верблюд-быстроход"; }
