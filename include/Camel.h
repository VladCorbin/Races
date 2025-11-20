#pragma once
#include "GroundTransport.h"

class Camel : public GroundTransport 
{
public:
    Camel();
    std::string getName() const override;
};
