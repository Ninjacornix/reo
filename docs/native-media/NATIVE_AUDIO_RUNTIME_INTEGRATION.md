# Complete audio candidate integration

Status: source integration and isolated component checks, 2026-11-06. A complete
new game build, successful actual capability acquisition and live audio/bank
validation remain pending. No default playback or stutter fix is established.

The private candidate joins Aggregate2, PacketAdapter3, BankSession2, the PCM
bridge/output owner, and RuntimeMemory under one SDK V2 registration. Its
[wrapper qualification](NATIVE_AUDIO_COMPOSITE_WRAPPER.md) preserves every child
callback owner and the existing admitted render call. RuntimeMemory supplies
the [actual acquisition/copy implementation](NATIVE_SOUND_RAM_MEMORY_OWNER.md).
Its protocol fixtures substitute acquisition contexts; actual acquisition still
needs the coherent candidate below.

Bootstrap records the actual CD configuration receipt, reapplies game overrides,
observes the [actual source/native file identities](NATIVE_SOUND_BUILD_IDENTITY.md),
and attempts complete installation only with exact `REO_NATIVE_AUDIO=1` in a
File1 candidate compiled with `REO_BUILD_NATIVE_AUDIO=1` and cooperating capture
flag2. It requires the native CD configuration implementation. The old standalone
PCM backend and complete audio candidate are distinct selections; preparing both
in one candidate is rejected.

The factory holds the actual outer pre-run lease across observed layout checks,
private memory preparation, inert child construction, worker registration,
publication and explicit unpublished cleanup. The child cannot start its native
output before publication. An SDK worker retained after failed publication is
inert and skips backend callbacks, so the factory explicitly joins that child
and retires Memory before releasing its setup lease. Ordinary published stop
signals only the child; successful outer drain and the child/device fence must
precede Memory retirement. A failed published fence retains the resources for
retry. The wrapper's isolated tests exercise the relay/lifetime implementation;
factory ordering is currently source-reviewed and compiled, not executed as a
live Runtime test.

`prepare_native_candidate.py --audio-backend` assembles twelve explicit audio
sources in addition to the existing resource/session candidate inputs. It
requires committed bootstrap installation and matching RAM-companion/selected-GS
profile headers from the complete public patch series. It rebuilds the runtime
from that source rather than importing an older PS2 runtime archive. Every C++
translation unit, including SDK/runtime and GPU backend units, receives the same
`REO_BUILD_NATIVE_SOUND_RAM_CAPTURE=2` definition. Conflicting old definitions
refuse preparation. Six planner tests verify runtime/backend and generated-group
inclusion, common options, idempotence and refusal before partial plan changes.
The first V9 prepared kit omitted generated source-group definitions and was
superseded before compilation. The corrected planner includes those dynamically
expanded batches; it does not assume the static unit list is the whole build.

Initial integration uses this sealed private candidate path. The ordinary
recomp CMake configuration imports a separately built runtime library; it has
no newly enabled complete-audio option that could silently pair flag2 app
headers with an unqualified old library. A general CMake/package entry needs
matching runtime-library source/build/definition evidence before activation.

The candidate's runtime environment remains independently selected. In
particular, installing sound capture never disables an actual asynchronous CD
worker to obtain its seal, changes game speed, or turns on an advanced rendering
or VU path. Unsupported actual capabilities produce an unavailable candidate
diagnostic before publication. No per-operation legacy retry replays an already
applied sound packet or transport.

After teardown the child report records real output/underrun/failure counters.
The Memory report records retirement, remaining slots/operations, per-operation
attempts/refusals and diagnostics. Its first-refusal word can include the
deliberately absent optional packet logger; it is not automatically a gameplay
failure or stutter cause. Reports must be interpreted with successful
installation and actual operation counts, not merely a requested environment
setting. No completed candidate/game observation is claimed in this document.
