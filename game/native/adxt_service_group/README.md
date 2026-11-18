# Native audio group dispatch

Owned, live decoder/player/RNA tables with explicit child boundaries and strong
per-call leases. The shared service word belongs to the same retained clock
context. This reconstructs dispatch envelopes; child protocols are separate.

See the [contract](../../../docs/native-media/ADXT_SERVICE_GROUP_CONTRACT.md)
and [evidence](../../../docs/native-media/ADXT_SERVICE_GROUP_IMPLEMENTATION.md).
The original inputs were frozen before `service_group.cpp` existed. No game,
device, production selector or compatibility runtime was changed.
