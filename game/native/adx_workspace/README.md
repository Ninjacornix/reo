# Allocation-free ADX scalar workspace

`adx_workspace.hpp/.cpp` implement ordinary typed mono, stereo and 7/10 downmix
arithmetic into caller-owned PCM spans. Admission scans stable encoded bytes and
checks physical extents/byte overlap before effects; execution takes the admitted
view, state and parameters by value, without allocation, callback or refusal.
The caller owns storage and serializes its lifetime. This module does not own
source leases, PCM queues, workers, loop transitions or clocks.

See [contract](../../../docs/native-media/ADX_WORKSPACE_CONTRACT.md) and
[implementation/evidence](../../../docs/native-media/ADX_WORKSPACE_IMPLEMENTATION.md).
`frozen_identity.json` honestly records authorship after original-oracle exposure
and a freeze before the new comparator. Frozen existing codecs were not edited
or linked as expected implementations.

```powershell
cmake -S game/native/adx_workspace -B build-native-sjuni/adx-workspace-NEW
cmake --build build-native-sjuni/adx-workspace-NEW
ctest --test-dir build-native-sjuni/adx-workspace-NEW --output-on-failure

python game/native/adx_workspace/original_cases.py `
  --output build-native-sjuni/adx-workspace-original-NEW
python game/native/adx_workspace/compare_original.py `
  --fixture build-native-sjuni/adx-workspace-original-NEW `
  --output build-native-sjuni/adx-workspace-parity-NEW --compiler g++
python game/native/adx_workspace/validate_projection.py `
  --fixture build-native-sjuni/adx-workspace-original-NEW `
  --output build-native-sjuni/adx-workspace-original-NEW/projection-validation.json
```

Use new artifact paths. Qualification scripts preserve existing evidence. The
original generator imports unchanged owned-word engines, freezes input media and
state first, then obtains expected observations. The comparator transports only
inputs into the compiled native probe. The projection audit independently reads
actual media at the original codec entry during Window1/Shared39 replay.

GCC 15.2 and LLVM 21.1.7 each pass **284 unit assertions, zero allocation
attempts, standalone CTest 1/1, and 901/901 original comparisons**. Of those,
890 are admitted codec cases and 11 deliberately refuse the physical profile.
The admitted cases compare 437,440 PCM halfwords. Actual original-entry capture
matches all 234 projected codec calls across 72 original transcripts. These are
synthetic checks, not game/audio/performance validation or full-player proof.

An additional run with the launcher's **bundled UCRT LLVM 21.1.8**, compiler SHA
`f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3`,
also passes 284 units, zero allocations, 901/901 parity and CTest 1/1. Every
child PATH starts with its bundled bin directory. Receipts are under
`build-native-sjuni/pinned-adx-qualification-v1/workspace`; see the implementation
document for exact identities. The earlier PATH LLVM 21.1.7 cohort remains
unchanged and is not the bundled toolchain.
