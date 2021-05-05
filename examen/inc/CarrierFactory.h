#include "Carrier.h"
#include <list>

class CarrierFactory
{
private:
    static std::list<int> ids;
    static int lastID;
public:
    static Carrier* Create(double power, int bundleID);
    static void Destroy(Carrier* carrier);
};
