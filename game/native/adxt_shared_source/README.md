# Shared encoded source

Source2 owns one8192+36-byte SJRB ring, one retained private-result producer and
one move-only consumer batch with one or two actual grants. It reuses the frozen
refill backend. It does not implement Window2, decode, audio devices, runtime
hooks, filename replacement, live reset or SJMEM.

`service()` is the complete original130B78 lifecycle wrapper reaching130800
refill, including accepted-result drain and deferred stop/close. It is not a
raw130800-only API. A concrete typed file-target action mutates canonical
LoopControl limit/progress at publication before terminal checks. Arbitrary
mutating callbacks and private Ring access are unavailable.

ReadBatch retains identity and actual storage, not the provider. The surrounding
control owner must remain alive through explicit provider drain/fence. Destructors
return no consumer credit. Finish plans are entirely checked before effects,
including every positive Unget position; zero grants are true noops. Unexpected
post-effect failures retain the remaining ledger and fault admission.

The source was authored after historical shared-window evidence and frozen
before a new30-case original Source-only expected corpus and comparator.
`frozen_identity.json` preserves that history and unchanged dependencies. See
[implementation and qualification](../../../docs/native-media/ADXT_SHARED_SOURCE_IMPLEMENTATION.md)
for exact receipts, the preserved raw-refill mismatch and limits.

```powershell
python game/native/adxt_shared_source/verify.py --cxx <compiler> `
  --output build-native-sjuni/adxt-shared-source/NEW
python game/native/adxt_shared_source/compare_original.py --cxx <compiler> `
  --output build-native-sjuni/adxt-shared-source-parity/NEW
```

The standalone CMake project builds the component and its meaningful ownership
checks, including actual blocked AsyncReadOwner stop/publication/join. No game
or device is launched by these commands.
