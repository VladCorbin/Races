#pragma once
#include "LandTransport.h"

class Camel : public LandTransport 
{
public:
    Camel() : LandTransport(10, "Верблюд", 30, { 5,8 }) {}
};
