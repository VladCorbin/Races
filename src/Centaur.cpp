#include "Centaur.h"

Centaur::Centaur() : GroundTransport(15.0, 8.0, { 2.0 }) {}

std::string Centaur::getName() const { return "Кентавр"; }
