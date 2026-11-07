# Stable native compressed-audio instances

Stable construction/stop/restart handles over the canonical native ADXT Session.
See the [ownership contract](../../../docs/native-media/ADXT_INSTANCE_OWNERSHIP_CONTRACT.md).
This does not enable a production selector or implement the guest ADXT ABI.

The CMake test uses actual native source workers and a model output provider.
`verify.py` requires an exact native build receipt and checks deliberate
ownership failures against those same library/compiler identities.
