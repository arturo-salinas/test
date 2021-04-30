#pragma once
#include <string>

class BFX
{
public:
    virtual void setPvScalingFactor(std::string error, int carrierID, double factor) = 0;
};
