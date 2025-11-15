#pragma once
#include "LandTransport.h"

class Boots : public LandTransport 
{
public:
    Boots() : LandTransport(6, "Ботинки-вездеходы", 60, { 10, 5 }) {}
};
