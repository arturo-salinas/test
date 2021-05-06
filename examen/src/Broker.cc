#include "../inc/Broker.h"

#include <map>

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
    std::map<int, double> bundlesPower;

    for (auto carrier : carriers)
    {
        if (carrier.getBundledID() != 0)
        {
            auto search = bundlesPower.find(carrier.getBundledID());
            if (search != bundlesPower.end())
            {
                bundlesPower[carrier.getBundledID()] += carrier.getPowerInWatts();
            }
            else
            {
                bundlesPower.insert({carrier.getBundledID(), carrier.getPowerInWatts()});
            }
        }
        else
            totalPower += carrier.getPowerInWatts();
    }

    for (auto carrier : carriers)
    {
        std::string error = "";
        if (carrier.getBundledID() == 0)
            bfxAccess->setPvScalingFactor(error, carrier.getID(), carrier.getPowerInWatts() / totalPower);
        else
            bfxAccess->setPvScalingFactor(error, carrier.getID(), carrier.getPowerInWatts() / bundlesPower[carrier.getBundledID()]);
    }
}