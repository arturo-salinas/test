Power Scaling
==

BFX block will assign a power portion per carrier. This is done through a set
of power scaling registers.

```
PV_ant = PV_cb0 * BfxScaleCarrier[0] + PV_cb1 * BfxScaleCarrier[1] + .. + PV_cb<n> * BfxScaleCarrier[n]
```
Where PV_ant is Power Value per antenna and PV_cb\<n\> are the reported 
values to Baseband.

The numbers "0 .. n" correspond to the carrier IDs and shall be consecutive.

Some carriers are bundled because they share the same power characteristics 
(numerology).

Scaling factors are recalculated whenever a carrier is added or removed.

Carriers without bundling
---

```cpp
BfxScaleCarrier[n] = P_n / totalPower
```
Where _totalPower_ is the total power of all the carriers.

Carriers with bundling
---

```cpp
BfxScaleCarrier[n] = P_n / totalPowerInBundle
```
Where _totalPowerInBundle_ is the total power of all the carriers inside a
bundle.

The code is supposed to run in a multithread environment.
