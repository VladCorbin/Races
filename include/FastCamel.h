#pragma once
#include "GroundTransport.h"

class FastCamel : public GroundTransport 
{
public:
    FastCamel();
    std::string getName() const override;
};
