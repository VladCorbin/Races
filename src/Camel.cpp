#include "Camel.h"

Camel::Camel() : GroundTransport(10.0, 30.0, { 5.0, 8.0 }) {}

std::string Camel::getName() const { return "Верблюд"; }
