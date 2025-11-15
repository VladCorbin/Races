#include "Transport.h"

Transport::Transport(double speed, const std::string& name, bool isAir)
    : speed(speed), name(name), isAir(isAir) {}

const std::string& Transport::getName() const { return name; }
double Transport::getSpeed() const { return speed; }
