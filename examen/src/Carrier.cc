#include "../inc/Carrier.h"

Carrier::Carrier(int carrierID, double power, int bundleID) : powerInWatts(power), carrierID(carrierID), bundleID(bundleID)
{
};

Carrier::~Carrier()
{
}
