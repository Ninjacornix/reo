# Phased PCM store qualification

Status: independent native phase/credit core qualified, 2026-11-06. This closes
the PCM storage phase gate for future Window2, **not the complete Window2 owner,
game integration or a stutter fix**.

The frozen [v1](ADX_PCM_STORE_IMPLEMENTATION.md) remains unchanged. V2 in
[`game/native/adx_pcm_store/v2`](../../game/native/adx_pcm_store/v2/pcm_store.hpp)
mechanically retains its storage, token, physical ownership and credit code,
while exposing `stage` separately from `publish`, as described in the
[v2 contract](ADX_PCM_STORE_V2_CONTRACT.md). The prototype and contract preceded
qualification; the new original phase capture and comparator followed the v2
implementation freeze. Prior final-backing observations had already been seen.

Stage stores raw PCM and performs corrected-production wrap without returning
credit or publishing output. Full producer grants remain held and the snapshot
reports `staged`. The caller can update its decoder state and return Source2
input credit. Publish then emits the callback and actual Split/Put/Unget per
channel. Other PCM mutations refuse while staged; held read views remain valid.
Losing that token blocks normal completion rather than rolling back raw effects.

## Qualification

Both GCC15.2 and actual bundled UCRT LLVM21.1.8 pass:

- **3,601 unit assertions**, including all prior v1 checks and the explicit
  intermediate boundary. Guarded post-construction paths make zero allocation
  attempts. Construction allocation failure is tested separately.
- Private post-first-prefix failure, ignored-error negative and ID-exhaustion
  controls, retaining actual partially accepted credit as in v1.
- **90 original storage clients**, with exact final backing/callback/counter
  equality and30 actual intermediate PCM captures before encoded Put(0).
  The other60 backpressure clients make no storage operation or capture.
- The parent Release build and selected `adx_pcm_store_v2` CTest. The standalone
  parent now contains32 suites; those counts do not describe native migration.

The new read-only original replay executes **283,160 instructions** per compiler
from the already frozen90 inputs. It captures PCM backing and Ring state at
actual entry `13FBF8` for encoded-ring Put(0), with its real pointer/pool arguments.
Every complete original operation transcript remains exactly equal to the prior
full replay; instrumentation supplies no result and changes no instruction.
Both compilers produce the same captured-phase hash:
`0f19cc406384320f9bc457748a608c36dfb83ba2597f261ee3c5457d13991c85`.

A separate negative control makes the input-credit observation see pre-store
PCM. **All90 final storage/callback observations still match**, while all30
accepted intermediate observations differ. Thus final-state parity alone would
miss this ordering error. This is a private storage-observation mutant, not an
integrated Source2 game test or a production source edit.

Original decoded PCM remains supplied input in this **storage-only** proof.
Native scalar parity is a different existing workspace qualification. Full
Window2 must still connect actual header, canonical loop mutations, source
leases, codec state, encoded-credit return and this store in the correct order.

## Local identities

V2 freeze: `e22f24ad5d74a228ec031483ae7442a74c8a6435fa9d72a81983c5561020fbbc`.
Local artifacts under `build-native-sjuni/adx-pcm-store/v2/`:

| Receipt | SHA-256 |
| --- | --- |
| Unit/fault GCC | `a2f8dd9f39b58ace1f69f3b3f880f62ade749808b641fcc113d6d5b86f9315bf` |
| Unit/fault bundled LLVM | `d891a9e0baa02db0d2bcfb12906bac105a53098b9cd6814ad927c5f03ebc3bcf` |
| Phase input manifest | `6fb23e134140e0aa9102bc8d14804e9243251eba334a7b48d5652470bd53d511` |
| Original phase GCC | `a7ea02d37d2b3eda1d24458f6928dedcaae7ef53cc8b149a78f76825b1295736` |
| Original phase bundled LLVM | `5cd818df6883a16019e05789ecec7fa1dae99244768e8b6c32757e28bd2006db` |
| Native phase/final GCC | `72e4683a96646f596ac06709773f076752c83ff1e686b28a6e93cf8b97854de9` |
| Native phase/final bundled LLVM | `865fd2464b33b214601a386646fc964953f59ec6dc859cdb0fb4436630fee4f1` |
| Late-observation negative GCC | `9717dd94931e0b79361d1e7a4588266ae89d66af38ad617e61ca3532dabc6f77` |
| Late-observation negative bundled LLVM | `7b9d1a66a46f4fd9860f31f8de3649074cb14ec8e48b7144c319d9fb4d4bb220` |

`verify.py`, `capture_original.py`, `compare_original.py` and `negative_phase.py`
retain scoped fresh outputs. The original capture has a separate `--freeze`
stage before `--frozen ... --compiler gcc|llvm`. The final PCM projection remains
the frozen v1 `original-v1` input, not regenerated native data.

No new game process, device, runtime SDK change or default setting was involved.
The next work remains the complete Source2/header/loop/workspace/PCM owner.
