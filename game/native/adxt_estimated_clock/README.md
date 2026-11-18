# Estimated ADXT clock

Independent prepared-observation core; game and audio-device integration remain
open. See the [contract](../../../docs/native-media/ADXT_ESTIMATED_CLOCK_CONTRACT.md)
and [qualification](../../../docs/native-media/ADXT_ESTIMATED_CLOCK_IMPLEMENTATION.md).

`Clock` keeps stream origins/pause state and references externally serialized
shared controls. Its read-only event hooks cannot operate a device. Constructor
and transactions allocate no storage. The caller supplies coherent integer
queue observations and a modulo32 original tick observation.

The finite FP profile refuses zero divisors before effects; the unchanged raw
integer query may return an unused zero denominator. The unowned worker service
path is excluded. Reentry detection is not a cross-thread synchronization policy.

The standalone CMake target and parent native suite build without PS2Recomp.
`verify.py` compares typed state/output/control boundaries with frozen original
evidence and runs two privately compiled expression/control negatives.
