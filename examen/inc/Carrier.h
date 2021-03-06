#pragma once

class Carrier
{
private:
    double powerInWatts;
    int carrierID;
    int bundleID;  // 0 indicates this carrier is not bundled
public:
    Carrier(int carrierID, double power, int bundledID);
    ~Carrier();
    inline double getPowerInWatts() {
        return powerInWatts;
    };
    inline int getID() {
        return carrierID;
    };
    inline int getBundledID() {
        return bundleID;
    }
};