#include "Transport.h"

Transport::Transport(TransportType type, double speed) : type(type), speed(speed) {}

TransportType Transport::getType() const { return type; }
double Transport::getSpeed() const { return speed; }
