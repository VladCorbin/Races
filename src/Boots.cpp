#include "Boots.h"

Boots::Boots() : GroundTransport(6.0, 60.0, { 10.0, 5.0 }) {}

std::string Boots::getName() const { return "Ботинки-вездеходы"; }
