#pragma once
#include "LandTransport.h"

class CamelFast : public LandTransport 
{
public:
    CamelFast() : LandTransport(40, "Верблюд-быстроход", 10, { 5, 6.5, 8 }) {}
};
