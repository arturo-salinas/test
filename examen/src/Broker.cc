#include "../inc/Broker.h"

Broker::Broker(BFX *bfxAccess) : bfxAccess(bfxAccess)
{
}

Broker::~Broker()
{
}

void Broker::add(Carrier carrier)
{
    carriers.push_back(carrier);
    configurePvScalingFactors();
}

void Broker::configurePvScalingFactors()
{
    double totalPower{0};

    for (auto carrier : carriers)
    {
        totalPower += carrier.getPowerInWatts();
    }

    for (auto carrier : carriers)
    {
        std::string error = "";
        bfxAccess->setPvScalingFactor(error, carrier.getID(), carrier.getPowerInWatts() / totalPower);
    }
}