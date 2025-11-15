#pragma once
#include "LandTransport.h"

class Centaur : public LandTransport 
{
public:
    Centaur() : LandTransport(15, "Кентавр", 8, { 2 }) {}
};
