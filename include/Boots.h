#pragma once
#include "GroundTransport.h"

class Boots : public GroundTransport
{
public:
    Boots();
    std::string getName() const override;
};
