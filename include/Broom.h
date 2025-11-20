#pragma once
#include "AirTransport.h"

class Broom : public AirTransport
{
public:
    Broom();
    std::string getName() const override;
};
