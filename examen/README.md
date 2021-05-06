Power Scaling
===

BFX block will assign a power portion per carrier. This is done through a set
of power scaling registers.

```C++
PV_ant = PV_cb0 * BfxScaleCarrier[0] + PV_cb1 * BfxScaleCarrier[1] + .. + PV_cb<n> * BfxScaleCarrierBr<n>
```
Where PV_ant is Power Value per antenna and PV_cb<n>are the reported values 
Baseband.

Some carriers are bundled because they share the same power characteristics (numerology).

Scaling factors are recalculated whenever a carrier is added.

Carriers without bundling
---

```C++
BfxScaleCarrier[carrierID] = P[carrierID] / totalPower
```

Carriers with bundling
---

```C++
BfxScaleCarrier[carrierID] = P[carrierID] / totalPowerInBundle
```
Where _P\_Bundled_ is the total power of all the carriers inside a bundle.


