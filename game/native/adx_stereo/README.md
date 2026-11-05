# Synchronous keyed stereo and downmix kernels

This independent native C++ target implements the complete integer contracts of
File #1's keyed stereo (`127C80`) and downmix (`1278B8`) bodies. It is isolated
from game/player integration. The frozen mono target is unchanged. Both GCC and
LLVM pass the bounded independent original-word comparisons recorded below.

`decode_keyed_stereo(encoded, requested_blocks, state, parameters, mode, limits)`
borrows immutable encoded bytes for one synchronous call and returns owned,
separate left/right PCM16 vectors. State contains two independent history pairs
(newest, previous) and an unsigned 16-bit key. Coefficients, multiplier and addend
are explicit signed 16-bit values; coefficients are not recomputed with host
floating point. Mode is either separate channels or duplicated `7/10` downmix.
An invalid enum value is refused. No global selector or scheduler is accessed.

The signed 32-bit requested block count is divided by two, truncating toward
zero. Each whole pair is eighteen bytes left then eighteen bytes right, yielding
32 samples per output. Normal completion returns the original requested count,
including odd counts whose unpaired block is not read. Counts below two decode
nothing and commit unchanged histories; negative values retain their return.

Both headers are checked for raw `8000` markers before either payload is decoded.
A left marker returns twice the number of completed pairs with no current-pair
key advance. A right marker returns the same count but retains the left header's
key advance. Both retain preceding PCM/key effects and bypass publication of
**both** local histories, so the returned histories remain the initial values.
The right marker needs only twenty bytes of its pair; its right payload is not
read. `encoded_bytes_consumed` counts completed pairs; inspected additionally
includes the two-byte left or twenty-byte right-marker prefix. No next header is
read after the last requested pair.

For each nonmarker header, scale is `((header XOR old_key) & 1FFF)+1`, then key is
`(old_key * signed_multiplier + signed_addend) & 7FFF`, with low-word arithmetic.
The right channel uses the key advanced by the left header. Samples are high
nibble then low, mapping `0..15` to `0..7,-8..-1`. The signed coefficient/history
products' low words are added modulo 32 bits **before** arithmetic right shift by
twelve. Nibble times scale is then added with word semantics and clipped to
signed 16 bits. Each channel's clipped sample advances its own history.

Downmix occurs after both channel samples are clipped:
`clamp16(trunc_toward_zero(7*(left+right)/10))`. The same mixed value goes to both
outputs. Histories retain individual channel samples, not mixed samples. All
intermediate downmix values fit signed 32 bits; original shift/subtract word
multiplication by seven is therefore identical within this typed domain.

Preflight validates all required extents and the per-channel sample limit before
allocation or decode. Short input, output limit, invalid mode or failure of
either output allocation returns empty vectors and initial state, without a
partial result. This refusal is deliberately distinct from an invalid original
pointer call. An admitted marker remains the original partial-success contract.
The default bound is 131,072 samples per channel (two owned PCM buffers). Input
must remain alive and immutable for the complete call; nothing is retained.
Scalars are values and outputs are owned, so raw guest pointer aliasing is not
represented. A future bridge must separately admit borrows, alignment, capacity,
and all output/history/key/input aliases.

## Original evidence and independent implementation freeze

The complete generated instruction comments were compared against original ELF
words. The sole omitted generated word is padding NOP `127C7C`. No original calls
exist inside the two kernels; their sole lookup is the signed nibble table.

| Original range | Bytes | SHA-256 |
| --- | ---: | --- |
| File #1 US ELF | whole file | `06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46` |
| Downmix `1278B8..<127C80` | 968 | `ba4c2a7edde8846857e2896a173718fc82cd846d1203a4882cbf7d3a63088369` |
| Separate stereo `127C80..<127FC8` | 840 | `4a4e6da9bbda1a2a0b83c2f7bb31e777aeeb912c751b0a8a0694ce16c366f9ff` |
| Selector `127FC8..<128038` | 112 | `5aea6cbb34fbefae1bf0c40ffd7fceb604766e1fe011b46c9aaad5ed5dd8439e` |
| Nibble table `239BE8..<239C28` | 64 | `67ec51eb0fd90d668661957e826ec5f7834c84c2e7a586f9cf185e0ec7d4808f` |

Count and input setup: stereo `127C80..127D04`, downmix `1278B8..127940`.
Header/key/marker sequence: `127D08..127DD0` and `127948..127A10`.
Stereo predictor/sample loop: `127DD8..127F60`; downmix individual prediction,
division and duplication: `127A18..127C1C`. Normal history commits are
`127F80..127F98` and `127C34..127C4C`; marker branches jump past them. Selector
`127FC8` sign-extends arguments and selects stereo for global `20C7A8==0`, downmix
otherwise. The typed mode represents that choice without reading/mutating it.

Before any new original-word oracle or fixture inspection, the native algorithm
was frozen at source SHA-256
`3a323a108772aa844594fb2d4e34fb56ef0a522006d90d8b825ead7bd168d55f`
and header SHA-256
`6cf5c13f765c60b36cf13ac7c9fd74fd0bc09f3ea106f4d640f98bbff157df8b`.
The separate oracle fixtures matched this unchanged implementation. Synthetic
native checks alone do not establish original parity.

## Standalone checks

GCC and LLVM each pass 140 synthetic checks in six groups: channel/nibble
geometry, signed/wrapped predictor and key, downmix arithmetic and unmixed
histories, both marker positions after prefixes, count/length/capacity admission,
and first/second allocation failure rollback. No original oracle algorithm is
imported or duplicated in these tests.

```powershell
cmake -S game/native/adx_stereo -B build-native-sjuni/adx-stereo-cmake -G Ninja
cmake --build build-native-sjuni/adx-stereo-cmake
ctest --test-dir build-native-sjuni/adx-stereo-cmake --output-on-failure
```

This target does not establish ADXB/SJ/ADXT/RNA ownership, wrapper admission,
looping, stop/reset, media clocks, floating-point/unkeyed formats, audible quality
or performance equivalence. No game, audio device or user asset is run.

## Independent original-word comparisons

[`compare_adx_stereo.py`](../../../tools/native_reconstruction/compare_adx_stereo.py)
validates/transports fixtures to a probe compiled with the actual native source.
It neither imports the oracle nor implements decoder arithmetic. GCC and LLVM
each pass all **522 cases / 36,096 PCM halfwords** from the independently generated
fixture, SHA-256
`a02fc85b996feb650751407a5a2e5fc9cd8104fd1c5d9fe4278864cf4027f6b0`.
No native algorithm/header change was required after the independent freeze.

The original fixture records 931,435 steps and 476/479 body instruction words.
The three unvisited words are the downmix division-by-zero BREAK instructions
`127ACC`, `127BCC` (divisor is the locally fixed ten), and unreachable selector
padding NOP `128014`. The fixture's downmix body excludes padding NOP `127C7C`,
giving `1278B8..<127C7C`, 964 bytes, SHA-256
`fece7d5c5d7dc0148717351d200c67d845e0242f5e7b93c01cfc19db7c2687ab`.
This agrees with the larger original range above after excluding its final zero
word. The comparator pins all three exact body ranges, the nibble table, fixture
and generator/engine source hashes without importing or executing the oracle.

Comparisons cover defined return, full left/right capacity (including untouched
sentinels), each plane's ordered prefix stores, completed pair count, both history
pairs, key, selective history publication and key-advance count. Input bytes stay
unchanged. Test-only publication planes initialize capacity and guards before
copying the owned native prefix; guards therefore check that adapter and result
extent, not a hypothetical guest bridge. Cross-plane store interleaving is not
observable through disjoint owned result vectors and is not claimed equivalent.
Original frame/register/MAC observations are not exposed as native ABI. Selector
cases compare explicit typed mode selected from zero/nonzero flag, including
poisoned halfword arguments and nonzero original MAC state; no native global or
guest wrapper is installed.

The corpus is finite, with signed requests through sixteen blocks (eight pairs)
and disjoint aligned synthetic original regions. It includes all nibble pairs,
scale/key/predictor extremes, signed/odd counts, both marker positions and
prefixes, downmix division/clipping and selector paths. It does not prove every
possible scalar/input/alias combination or any device/scheduler behavior.

```powershell
python -B tools/native_reconstruction/compare_adx_stereo.py --cxx C:/msys64/mingw64/bin/g++.exe --output build-native-sjuni/adx-stereo-compare/gcc
```

Detailed receipts are generated at
`build-native-sjuni/adx-stereo-compare/{gcc,llvm}/receipt.json`, including compiler,
probe, fixture, frozen/current source/header identities and per-case checks.
