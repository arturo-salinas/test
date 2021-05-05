#include "../inc/CarrierFactory.h"
#include <algorithm>

int CarrierFactory::lastID = 0;
std::list<int> CarrierFactory::ids = {};

Carrier *CarrierFactory::Create(double power, int bundleID)
{
    int i = 1;
    std::list<int>::iterator it;
    bool isFreeID = false;
    for (it = ids.begin(); it != ids.end(); ++it)
    {
        if (i == *it)
        {
            i++;
        }
        else
        {
            isFreeID = true;
        }
    }
    if (isFreeID)
    {
        ids.insert(it, i);
        return new Carrier(i, power);
    }
    else
    {
        ids.push_back(++lastID);
        return new Carrier(lastID, power);
    }
}

void CarrierFactory::Destroy(Carrier *carrier)
{
    auto it = std::find(ids.begin(), ids.end(), carrier->getID());
    if (it != ids.end())
        ids.erase(it);
    if (ids.size() == 0)
        lastID = 0;
    delete carrier;
}