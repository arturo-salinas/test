#pragma once

#include "Carrier.h"
#include "BFX.h"

#include <vector>

class Broker
{
private:
    std::vector<Carrier> carriers;
    BFX* bfxAccess;
    void configurePvScalingFactors();
public:
    Broker(BFX* bfxAccess);
    ~Broker();
    void add(Carrier carrier);
};
