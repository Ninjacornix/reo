# Synchronous keyed mono block kernel

This independent C++ kernel implements the bounded typed contract recovered from
the complete File #1 mono keyed integer body. It is not wired into a game/player
and passes the bounded original-word comparisons described below. It does not use the
standalone `media/adx` class, a standard-codec library or the new original-word
oracle algorithm. The original ADXB/SJ/ADXT/RNA owner remains outside this target.

`decode_keyed_mono(encoded, requested_blocks, initial_state, parameters, limits)`
borrows immutable encoded bytes for one synchronous call and returns newly owned
PCM16, state and a typed admission status. Other channel/layout/codec variants
are not representable by this API. Counts use the original caller's sign-extended
32-bit domain; coefficients/history/multiplier/addend are explicitly signed
halfwords and the initial key is an unsigned halfword. Coefficients are supplied,
not recreated with unproved host floating point/trigonometry.

Every normal block is two big-endian header bytes followed by sixteen payload
bytes, producing 32 samples, high nibble then low nibble. The raw header's `8000`
bit is an early marker **before** key XOR/advancement. Scale is
`((header XOR old_key) & 1FFF) + 1`; the key advances once per decoded block with
signed multiplier/addend, low-word addition and `7FFF` mask before samples.

For each sample, the two signed coefficient/history products contribute their
low words. Their sum wraps to 32 bits **before** arithmetic right shift by twelve.
The signed nibble is multiplied by scale before addition to that prediction.
The signed word result clamps to PCM16; history advances newest/previous with the
clipped samples. Unsigned word operations and explicit bit reinterpretation avoid
host signed-overflow and signed-shift ambiguity. A wider mathematical predictor
sum would differ at extreme halfword inputs.

Normal completion returns the original requested count and publishes final
history. Nonpositive counts still return that signed count and publish unchanged
history, without inspecting encoded bytes or advancing key. An early marker
returns completed blocks and retains preceding PCM/key effects, **but does not
publish the local history pair**: `state.history` remains the initial pair and
`history_committed` is false. A marker needs only its two header bytes. Its
`encoded_bytes_inspected` includes those bytes while `encoded_bytes_consumed`
does not. Extra bytes after the last requested block are not inspected.

Preflight scans only the required header/payload extents and checks the output
sample limit before decoding/allocating. Short input, output-limit refusal and
allocation failure return empty PCM, initial state and uncommitted history; no
partial native result escapes. This transactional refusal differs deliberately
from attempting an out-of-bounds original call. An admitted marker remains the
original asymmetric partial-success result. The default limit is 131,072 PCM
samples. Input storage must remain alive and unchanged throughout preflight and
decode; no pointer is retained. Scalars are passed by value and output is newly
allocated, eliminating caller output/history/key aliasing inside this API. Any
future temporary guest bridge must independently reject unsupported raw aliases
and establish the compressed borrow's lifetime.

The complete kernel has no original calls; its only external lookup is the
sixteen-word signed-nibble table. Owned static evidence, read without execution:

| Source | SHA-256 |
| --- | --- |
| File #1 US ELF | `06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46` |
| `1276D8..1278B3`, 476 bytes | `f68258d902ba372da0e477288c3a3b98a396a07b3c43bb28e55fb5805348b115` |
| Signed-nibble table `239BE8..239C27`, 64 bytes | `67ec51eb0fd90d668661957e826ec5f7834c84c2e7a586f9cf185e0ec7d4808f` |

The table is `[0,1,2,3,4,5,6,7,-8,-7,-6,-5,-4,-3,-2,-1]`.
Instruction evidence: input/argument halfword interpretation `1276DC..127738`,
raw marker `127744..127768`, scale/key `12776C..1277A0`, predictor/nibbles/clipping
`1277A8..127868`, normal history publication `12787C..127884`, and marker bypass
to epilogue `127888`. No original scheduler yield, register frame or MAC/HI/LO
observation is exposed as native ABI. The native algorithm was frozen before
the independently generated original-word fixtures were inspected, and matched
them without an algorithm change.

Standalone checks exercise all nibbles, scale mask and limits, signed prediction,
word wrap, clipping, key advancement, marker history asymmetry, nonpositive
counts, every short-block extent, transactional refusal and allocation failure.
They use synthetic bytes only; no audio/game/owned asset is run.

```powershell
cmake -S game/native/adx_block -B build-native-sjuni/adx-block-cmake -G Ninja
cmake --build build-native-sjuni/adx-block-cmake
ctest --test-dir build-native-sjuni/adx-block-cmake --output-on-failure
```

Direct GCC and LLVM builds require only the implementation and its test source,
C++20, and `-Wall -Wextra -Wpedantic -Werror`. GCC and LLVM each pass 201 synthetic
checks in six groups.

## Independent original-word comparison

[`compare_adx_block.py`](../../../tools/native_reconstruction/compare_adx_block.py)
compiles this actual C++ implementation and compares independently generated
synthetic original-word fixtures. It does not import the oracle or implement the
decoder arithmetic in Python. Both GCC and LLVM pass all 104 cases, comparing
4,032 PCM samples. The fixture exercises all 119 original body instruction PCs
over 97,057 steps; this is finite instruction coverage, not exhaustive inputs.

The implementation was frozen with source SHA-256
`14a93abdd07a9fb029575c952b66055a2c4c3431818a6c0901e5dd2b27460495`
and header SHA-256
`eb671ed8071ebb4e6065ba2ec3fbb41706dcdb0935c6a53c162ad233759db195`.
The reviewed fixture SHA-256 is
`11785ce1d02f0355e54c38df58216911ca33d1ca8fbeaa6a2528c539a27eb6bb`.
Neither algorithm file changed after fixture inspection. Receipts are generated
under `build-native-sjuni/adx-block-compare/{gcc,llvm}/receipt.json` and pin source,
compiler, probe, fixture and oracle-source identities.

Comparisons cover defined return values, complete PCM capacity including unused
sentinel samples, ordered PCM prefix stores, completed block count, history/key,
history publication, unchanged encoded bytes and test publication guards. The
publication plane is a test adapter for owned native output; its guard does not
prove a future guest bridge's memory safety. Original register cursors and MAC
accumulators are excluded as non-ABI observations. Fixtures use disjoint synthetic
input/output/state storage, signed 32-bit requests and at most sixteen blocks.

```powershell
python -B tools/native_reconstruction/compare_adx_block.py --cxx C:/msys64/mingw64/bin/g++.exe --output build-native-sjuni/adx-block-compare/gcc
```

These checks do not establish playback, loop, stop, SJ ownership, stereo/float
kernels, media-clock or performance parity. No game/player integration is enabled.
