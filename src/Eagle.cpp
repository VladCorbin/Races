#include "Eagle.h"

Eagle::Eagle() : AirTransport(8.0, [](double) -> double { return 0.06; }) {}

std::string Eagle::getName() const { return "Îğ¸ë"; }
