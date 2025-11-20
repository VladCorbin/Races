#pragma once
#include "AirTransport.h"

class Carpet : public AirTransport 
{
public:
    Carpet();
    std::string getName() const override;
};
