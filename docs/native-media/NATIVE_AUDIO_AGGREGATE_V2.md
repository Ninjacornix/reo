# Aggregate2: grouped bank capture contract

Status: inert mechanical composition and isolated checks, 2026-11-06. No actual
Runtime RAM factory, capability issuance, bootstrap/preparer/CMake wiring,
game/device run or full runtime link. Existing original observations were known
before this derivation; Aggregate2 was frozen before its own new joint comparison
run. Aggregate1, packet adapter3 and their earlier identities remain unchanged.

[derive.py](../../recomp/overrides/native_audio/v2/derive.py) validates the frozen
Aggregate1 identity `bc33ed692ea0be697dcd0b8d3950e534c8dca3226dc62b119b8dfd3d1523a8db`
and all identified parent sources, plus its input-only transport, before deriving
the new files. The complete implementation/test changes are:

- Namespace `reo::native::audio_aggregate::v2`.
- Packet alias `bank_packets::v3`.
- Packet adapter/status/test fixture includes point to `native_banks/v3`.
- A generated-file provenance comment.

No PCM/bank numerical expression, provider behavior, clock, render sequence,
admission or lifecycle expression changes. The verifier separately updates SDK
surroundings to the fully matched final126 cohort. `derive.py --check` detects
any generated-source drift. [Header](../../recomp/overrides/native_audio/v2/aggregate.h)
and [implementation](../../recomp/overrides/native_audio/v2/aggregate.cpp) remain
inert until an external complete owner registers them.

Frozen [identity](../../recomp/overrides/native_audio/v2/identity.json) SHA-256:
`f6e7c65162da526eeb65e8a6a71335ddad83f09f5937a517eee82eeb7cb11012`.

| Core file | SHA-256 |
| --- | --- |
| `aggregate.h` | `0db1359408f489830e05d30bd98ad2867e858d3d1b32d1a82a1fc16082b37ec9` |
| `aggregate.cpp` | `45b6a0d977f21f1306da9a47df87e93c9fb077fef4de0df64eca3a9b77c85d59` |

The production PCM declaration stays2040 channels,2041 voices and391,680,000
sample bytes, plus4MiB raw-map metadata. Small synthetic domains remain explicit
test construction only. All11 PCM and8 bank callbacks are complete. The same
admitted SoundCall reaches render and its bank half; no new admission is acquired
between them. Initial stop leaves inner PCM/packet/bank admission open until
outer drain; output fence failure retains resources for retry. Callback execution
adds no C++ ordinary/aligned allocation/free or I/O. See the unchanged
[Aggregate1 lifecycle contracts](NATIVE_AUDIO_AGGREGATE.md) for the shared scope
and accounting limits.

The new injected QualifiedCaptureProvider uses adapter3 types and its explicit
`copy_parts_v1` contract. Derived tests/oracle use adapter3's **synthetic immutable
fixture batch override**; this is not actual Runtime/canonical RAM authority.
No arbitrary direct host asset borrow becomes qualified by changing its type.
The required runtime factory and complete wrapper remain separate work described
in [the runtime capture design](NATIVE_SOUND_RAM_RUNTIME_CAPTURE.md).

## Verification

GCC15.2 and pinned Clang21.1.8 each passed all12 fresh-process unit/lifecycle
modes and a separate actual126 production object,14 checks per compiler. Modes
retain complete callback coverage, paused PCM-to-bank stop continuation,
pre-table producer continuation, callback/self-join refusal, failed-fence retry,
synchronous attach callback, headless clock, weak-cycle lifetime and oversized
output refusal. No game or device is opened.

The tests use exact final126 facade/bank headers and source with declared fake
worker/device surroundings from the qualified companion suite. The actual
production object uses real final126 headers without those fake header paths.
Full reapply proof:
`2de11297c268e453888341b7f3ed44012ae51bdd10c9baa39a168e5cade97ec0`.
Actual `CriAudioBackend.h`:
`551d122b4195bf8a25346c1a9b6ad7b72c985f9e7cb834b8633a5e9f555125e4`;
separate `CriAudioRamCapture.h`:
`2505ea1838df71edd5bf6c87f88934cf303d2c533e8bd3e24dee3a2c7fea3147`.
The published V2 layout is unchanged; the new header's friend declaration and
companion are from the same verified final126 tree. Old/new headers are not
mixed. No companion RAM provider is selected in these tests.

After freezing, both joint comparators ran identical frozen original inputs:
21 cases /287 actions,9,316 exact PCM float words and10,052 ordered hooks,
including9,856 bank gains. Applicable PCM/bank state, clock, sample and hook
observations agree. **Raw comparison status is `different`**, with the same14
declared terminal-query policy differences as Aggregate1. They remain in the raw
`differences.json` files; no observation was normalized or expected value changed.

All14 differences are `$[20].actions[9].state.bank.ports[i][3]`, ports0..13:
`shutdown_both` terminal action9. Original legacy writes count0 to the observer;
closed V2 refuses portState and preserves its count sentinel999. This is an
explicit refusal, not a successful query reporting999 active requests. No other
raw difference occurred. Both compilers' actual observations are byte-identical
to the earlier Aggregate1 comparison, SHA-256
`59b21562284768df2736c1273f8837e2cb04485ffb12becd295fbb2ef0899afe`.

Final receipts under ignored `build-native-sjuni/native-audio-aggregate-v2`:

| Receipt | SHA-256 |
| --- | --- |
| `gcc-v1/receipt.json` | `84ff80ba74adfacc2e14e4039180fb85c560e98db9f8a254719ab62a961f91eb` |
| `llvm-v1/receipt.json` | `256c75673e0d28d34d4c6ce1504e3a914190da2f0581c1aff2329f872e17fb46` |
| `gcc-original-v1/receipt.json` | `d459bb5d9d1931c4e14e1a7e0a39f69dfa6d6c134a083972b38237d78b12d7d2` |
| `llvm-original-v1/receipt.json` | `67a852f96fbc83ed5c739e2fce6b158dee70a53bd7074e0c8899bf044d280d58` |

The [qualification summary](../../recomp/overrides/native_audio/v2/comparison_qualification.json)
SHA-256 is
`4a95c48320280050d04fa0ed92a5a246bca27efc6212d668b5541369cb2ac9cd`.
It preserves raw-result identities and distinguishes applicable equality from
terminal differences. Each actual object has11 identified project inputs,
verified against its unit receipt or full final126 source proof; system headers
are outside that project-input list and compiler executables are separately
hashed. Authored-source postchecks and frozen-core checks are empty.

No capture qualification, audible-output/device validation, performance
improvement, unrestricted game profile or whole Stage3 completion follows from
these mocks, source regressions or header objects.
