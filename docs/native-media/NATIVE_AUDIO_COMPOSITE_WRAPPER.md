# Complete audio wrapper: isolated qualification

Status: source review, isolated structural execution, and complete production
object compilation. No game was launched and no audio device was opened for
these checks. No confirmed wrapper defect was found within this scope.

The production owner is
[`composite_backend.cpp`](../../recomp/overrides/native_sound_ram/composite_backend.cpp).
It joins the unchanged Aggregate2 registration and the real RuntimeMemory owner
under the same SDK registration owner. The SDK supplies the actual admission and
outer-drain protocol; this fixture does not implement that protocol.

## What was exercised

The fixture uses the actual wrapper constructor, fields, queue staging, callback
tables, and join implementation. Its child registration records arguments and
returns distinct statuses. Its Memory stand-in owns a fixed PCM staging array,
records companion arguments, and can refuse retirement while a fixture token is
active. Neither stand-in supplies real Runtime/RAM authority or emulates DSP.

Both GCC and bundled LLVM passed 73 assertions across five fresh-process modes:

| Mode | Assertions | Observation |
| --- | ---: | --- |
| Relays | 45 | All 11 PCM and 8 bank methods reach the child owner, preserve arguments/results, and preserve the admitted render `SoundCall` address. |
| Companion | 13 | All eight companion callbacks forward the same call/token and exact runtime, backing, operation spans, address spaces, offsets, lengths, and diagnostic values. |
| Lifecycle | 8 | Stop retains Memory; failed child join retains Memory; active token refuses retirement; release/retry succeeds; successful join is idempotent. |
| Staging refusal | 3 | Refused staging never calls the child queue and preserves the caller's end position. |
| Lifetime | 4 | SDK registration strongly retains wrapper, Memory, and child; successful join and final registration release expire all weak references. |

For successful PCM queueing, the child sees copied bytes in the Memory-owned
array after the fixture's copy pin has ended, with the operation lifetime still
active. In the production call chain, child `Aggregate::queue` calls the unchanged
PCM bridge, whose `Session::queue` may ensure output. The wrapper thus stages
before entering that child operation. The fixture does not open the provider or
exercise its device mutex. Wrapper render, bank mix, and admitted-render relays
also execute under allocation/deallocation counters; the fixture observes none
in those wrapper paths. This does not measure allocation behavior inside real
DSP or a device callback.

Three independent private negative controls compile and fail as intended:

1. Forwarding the wrapper pointer instead of the child owner exits 41.
2. Replacing the admitted render call with a fresh empty `SoundCall` exits 42.
3. Retiring Memory during `request_stop` fails the lifecycle assertion (exit 1).

## Exact fixture boundary

Windows GCC retained otherwise unused factory references despite section garbage
collection. The fixture therefore mechanically omits three complete scopes from
its private source copy: the anonymous `RuntimeHooks`/layout helper scope, the
static installation factory, and the exported installation function. The tested
constructor, queue, callback tables and join remain verbatim source text, with
ordinary newline decoding. The copied public header only rebases two relative
includes. Each omitted scope and the final fixture have recorded hashes.

The fixture substitutes only `runtime_memory.h`, uses the actual SDK V2 and RAM
companion types, and defines the destructor of an **empty** `SoundCall`. Pointer
identity checks do not acquire or prove a real accepted SDK call. No actual
aggregate/provider implementation is replaced to make this fixture link.

Separately, **both compilers compiled the complete unmodified production
wrapper**, including its factory and RuntimeHooks, against the real
`runtime_memory.h`. Those object checks consume the fully reapplied 127-patch SDK
and sealed V8 graphics/raylib headers, validate all consumed project inputs, and
link no libraries. They cover 28 project source/header inputs per compiler. The
fixture omissions do not apply to these objects.

## Installation and teardown source review

The full original factory is checked for the following source order:

`actual PreRunSetup → RuntimeMemory::prepare → unpublished cleanup guard →
provider allocation → inert aggregate creation → wrapper allocation → SDK
publication → explicit child join on publication refusal → installed flag`.

The setup variable encloses preparation, publication and local failure cleanup.
The SDK registration owns the wrapper, while callback relays invoke the retained
child owner. Companion callbacks use the same wrapper context to reach its
Memory owner. `render_admitted` forwards its existing reference, without
reacquiring admission. `request_stop` and `shutdown` forward to the child and
do not retire Memory. Wrapper join first requires the child join to succeed,
then requires Memory retirement; either refusal permits a retry. Only successful
retirement marks the wrapper joined.

Publication failure explicitly joins the unpublished child. Its join result is
currently discarded before the unpublished Memory guard runs. The current
factory constructs an inert aggregate: output-owner construction does not attach
the provider, and an unpublished SDK worker does not execute the backend. The
review found no source path that starts this child's device before publication.
Consequently a fake child's injected failed fence is useful for testing normal
wrapper join retention, but is not evidence of a reachable prepublication
device-fence failure. Future eager-start behavior would require revisiting this
abort assumption rather than reusing this qualification.

These factory observations are source inspection and compile checks. They do not
execute real setup exclusion, worker registration, publication races, abort
cleanup, guest-memory copying, or Runtime destruction. Actual SDK/RuntimeMemory
protocol tests remain separate evidence. In particular, the fixture cannot prove
GuestScope ownership, CD/GS seal validity, fair Pad-writer exclusion, alias rules,
or device fencing. No raw all-game correctness or performance claim follows.

## Reproduction and pinned evidence

Drivers are under
[`audio_composite_wrapper`](../../tools/native_reconstruction/audio_composite_wrapper).
Run each compiler with fresh output directories:

```powershell
python tools/native_reconstruction/audio_composite_wrapper/verify.py --cxx <compiler> --output build-native-sjuni/audio-composite-wrapper/<fresh-unit>
python tools/native_reconstruction/audio_composite_wrapper/objects.py --cxx <compiler> --output build-native-sjuni/audio-composite-wrapper/<fresh-objects>
```

Authoritative SDK: `dependency-gs-sound-profile-reapply-v4`, full127 receipt
`909917fc2f766c8a43a10abbc0b94189fa24254ecfaa7f710e4eb24dc941b58a`.
Sealed V8 build-kit manifest:
`435ae2791088c3061ffd2caa3617924daa9d1b8815eb441512f4c9f50e5b4ea0`.
The object driver also pins the compile plan and owned generated-catalogue
receipt; no active SDK or loose build-folder headers are admitted.

| Private result directory | Receipt SHA-256 |
| --- | --- |
| `gcc-unit-final` | `88da459b8c1a1e97bafae5ec26e7a1a18c46a812e495312443c76b7e9f5614d8` |
| `llvm-unit-final` | `b9f574578f76b4f015d1a7a41b17c7b3d045ee95e0dfe130ee0d7cdd870ac585` |
| `gcc-objects-v1` | `335eb47aeee00dfdc55dc493a35f5388ea6ce149ab7751571e39135996791f60` |
| `llvm-objects-v1` | `61fe215adf953fdb9aa34b5821b308f9550514618be2ed0dc5358b3f790704e8` |

All four are beneath `build-native-sjuni/audio-composite-wrapper`. Both final
unit receipts contain 13 successful/expected-exit checks, including dependency
qualification, four compiler invocations, five normal modes and three negative
runs. All recorded input/postcheck lists are clean. Failed intermediate cohorts
and the earlier passing fixture trials remain preserved separately. The
[`cohort_identity.json`](../../tools/native_reconstruction/audio_composite_wrapper/cohort_identity.json)
and `qualification.json` record the exact production and helper hashes plus the
four receipts. Production source was not edited by this review.
