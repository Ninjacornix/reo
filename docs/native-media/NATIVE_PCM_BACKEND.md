# Candidate complete native PCM runtime binding

Status: binding and isolated checks implemented, 2026-11-05. This work does not
show an installed native backend in a running game, actual audio-device output,
whole-game domain admission or completed bank/RPC migration. Bootstrap/build
wiring and a matching full build remain integration requirements. The
reconstructed123 boot-order blocker below now has the independently checked
[explicit pre-run reset transaction](PCM_BOOT_SETUP.md) in public patch0123;
actual game activation still needs the coherent rebuilt124 runtime/provider.

The public entry is `reo_native_pcm::install(PS2Runtime&,const ProfileProof&)`
in [runtime_adapter.h](../../recomp/overrides/native_pcm/runtime_adapter.h).
It remains off unless `REO_NATIVE_PCM` is **exactly** `1`; the entry checks this
even when a bootstrap already checked it. The supplied profile is an explicit
record of actually observed configuration, not permission inferred from a game
name or a saved setting. Construction alone installs no callback or facade.

## Composition and complete interface

One runtime-owned backend strongly retains the bounded
[bridge Session](../../game/native/pcm_bridge/session_bridge.hpp) and host
services. The bridge owns the only native PCM queue/voice state. Host services
retain one immutable [output Owner](AUDIO_OUTPUT_OWNER.md), constructed before
publication, which retains the [real stream provider](NATIVE_STREAM_PROVIDER.md)
and a renderer with a **weak** backend reference. Each callback obtains a
temporary strong backend lease before using its bridge. The host/service path
does not retain the backend strongly, so this graph has no reference cycle.

The versioned runtime table binds all eleven existing facade operations:
`ensureHostOutput`, `queue`, `configure`, `consumed`, `render`, `discard`,
`drain`, `release`, `queuedSamples`, `reset` and `shutdown`, plus the nonblocking
stop/join lifecycle pair. Publication uses the actual runtime's complete-table
installation API; there is no per-operation legacy retry. Unsupported operations
cannot mutate unrelated legacy queues after native selection.

Default runtime services reuse `reoAudioPoll`, `reoAudioStreamGain`,
`reoAudioMasterGain`, `reoAudioResetStreams`, `ps2_reo_sound::mix` and
`ps2_reo_sound::reset`. Bank mixing follows CRI rendering after the bridge's PCM
data locks are released, then master gain/final clamp follow. Null-output
advancement skips bank mixing, preserving the source behavior. Guest execution,
RPC callbacks and guest memory reads do not belong on the device callback.

## Admission, readiness and shutdown

An atomic closed-bit/count gate covers every delivered data operation and
device-render entry. Nonblocking `request_stop` only closes this gate, records
the stop request and signals the output Owner's atomic gate. It does not lock
the bridge, wait, detach, unload or reset storage. The bridge's own admission is
closed later by outside `join`, which drains admitted producer/callback leases
before invoking bridge shutdown. Self-join from an admitted operation/callback
is refused and counted, leaving cleanup for an outside owner thread.

Host `output_ready` reads an atomic cached clock reservation; it **never** calls
provider status or acquires provider control under a PCM data lock. An ensure
mutex serializes cache reservation/start/failure restoration outside PCM locks;
callbacks never take it. The cache reserves frame-clock suppression before
start can publish/play a callback. A failed no-publication attempt restores
headless readiness; an already active stream remains reserved until the real
fence, including during stop. `ever_started` separately records successful
stream startup. This avoids the lock cycle where attach holds provider control
while waiting for an audio callback whose PCM path tries provider control.

After its own admission drain, bridge shutdown calls the output Owner's actual
detach/stop/unload sequence with no registry, PCM, bank or guest lock held. Only
a successful real provider fence clears cached readiness; the bridge then resets
PCM/routes and finally resets banks. Failed join retains state and returns
incomplete. A joined result proves this owner's quiescence; it does not erase a
previous behavioral fault or certify unrelated producers.

The runtime destructor's early-unwind path can join ExternalWorkers before
guest threads. The native gate prevents new PCM facade work and drains its own
admitted users, so it does not rely on normal guest-thread exit ordering.
Independent bank/RPC commands do **not** all enter this gate. Existing bank
globals/mutexes remain source-owned; a bank reset is not proof that every bank
producer has retired or that bank/RPC lifetime migration is complete.

## Exact narrow profile and memory cost

`ProfileProof::from_observed_file1` accepts only:

| Configured field | Accepted value |
| --- | --- |
| RPC SID | `0x90000200` |
| object range | `[0x001E0000,0x001EFF00)` |
| stride | `0x20` |
| function/object table bases and dispatcher | zero |

The bootstrap must pass an actual configured layout snapshot and independently
identify the current supported File #1 build. The planned outer checks include
the compiled File #1 path, `SLUS-20765` serial and entry `0x100008`; private build
and launch receipts retain ELF/executable hashes. The profile proof validates
these exact layout values, not their provenance or future immutability.

Inside `install`, a guest-execution scope checks non-stopping runtime state,
normal 32 MiB backing and two loaded original audio text windows using the
existing native-geometry SHA helper. The owned source ELF has SHA-256
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`:

| Loaded interval | Bytes | SHA-256 |
| --- | --- | --- |
| DTX init prefix `0x1392F8..0x139338` | 64 | `48af9491776a966a35a3dd46ed6122d2aa237c85f2a1967c38f204a488517be8` |
| service interval `0x135078..0x135170` | 248 | `a6ac3b23bfac0c9862d0facae8e02be99f08a69e6e20cb2dda05a10ffd3813bd` |

These checks are bounded identity evidence, not a full runtime-ELF hash or a
guest handle-incarnation proof. No instruction words are published by this work.

The range contains 2040 possible nonzero numeric IDs. Channel storage admits
2040 records and voice storage admits 2041, including raw voice zero where the
original facade supports it. Zero channel references remain missing channels;
queue key zero retains its original false result. Nonzero IDs outside the exact
range/stride are explicit candidate faults. Queries for allowed but unknown IDs
retain bridge/source ticking and zero/no-op semantics.

The fixed PCM sample arena costs **391,680,000 bytes** (391.68 decimal MB,
about 373.54 MiB), plus **4,194,304 bytes** of declared map metadata (two MiB per
map), voice/order/gain arrays, core bookkeeping and allocator overhead. This
production-sized construction passes both supported test toolchains. Allocation
failure before publication returns a construction error; this is not a promise
that arbitrary map histories cannot exhaust finite metadata later.

The domain still refuses same-voice stereo aliasing, oversized manual render
requests and unsupported metadata/gain/core states. Public manual rendering is
capped at 16384 frames; the qualified device callback remains capped at 512 by
the actual source reader. An oversized render is diagnosed **before touching
its output pointer**, including `UINT_MAX` with a one-float sentinel. Valid
bounded buffers are cleared before a stopped/refused backend render and again
after a render fault. The existing stopped dispatch can suppress delivery of a
public void-render call entirely; this binding does not change that facade
policy. Actual device callbacks use the output Owner, whose closed gate writes
silence for qualified bounded requests.

These declarations are not proof that every whole-game input falls within them.
Guest raw-ID reuse, alias reachability, unrestricted render sizes and finite
metadata remain candidate admission limits. They must not be presented as a
proven complete replacement for the original game's entire PCM domain.

## Failures and execution evidence

Ordinary invalid/full queue requests return false with unchanged end watermark,
as the source does. Unsupported domains, aliasing, gains, metadata/core failures
and render-cap violations latch a structured first diagnostic, close admission
and retain the selected native owner; they never fall back to legacy. Void
facade calls therefore produce an explicit failed-candidate diagnostic rather
than pretending the refused behavior succeeded. Runtime services emit the first
diagnostic outside the callback with named operation/status. A callback fault
only updates atomics and silence; reporting is deferred to a producer/control
call or join. Expected closed-after-stop results are not new hard faults.

Successful installation logs once, only after actual dispatch publication.
Successful cleanup logs one `[NATIVE-PCM-REPORT]` line. Repeated join does not
repeat it. Its fields distinguish:

- `method_attempts` and `method_completed`, in the emitted `method_order`, for
  the eleven delivered backend methods. Attempts include later backend refusal;
  completed totals require an `ok` bridge result. Shutdown completion records
  the first successful cleanup reached through the table's shutdown operation.
  Facade validation/stopped calls suppressed before table delivery are absent.
- `device_callback_attempts`, `device_frame_requests` and
  `device_callbacks_completed`, distinguishing callback requests from successful
  native renders. They describe entries reaching this backend, not every
  miniaudio invocation rejected earlier by the output Owner's stopped gate.
- `frames`, `signal_frames` and `underrun_frames`, actual PCM-core statistics
  preserved through reset/shutdown. They include admitted headless advancement
  or manual renders and measure the CRI PCM component before independent bank
  mixing. Zero callbacks/frames does not prove absence of underruns during play.
- `host_output_started`, `stream_fence_joined` and `output_owner_joined`, keeping
  a never-opened headless owner distinct from a completed stream fence. Started
  means the valid provider's play call completed; actual callback/frame counts
  provide separate evidence of subsequent use.
- Hard faults, legitimate queue rejections, stop requests, join attempts at
  report time and self-join refusals. A completed fence with hard faults remains
  a failed behavioral candidate, even though lifetime cleanup succeeded.

## Source identity, pre-run setup and checks

The isolated verification uses reconstructed124 based on PS2Recomp
`c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f`, with fresh receipt SHA-256
`944b72d4cc977ac01d8e7a4459c601f0a331b06c8adbb5048bec45a2963f91cb`:

| Input | SHA-256 |
| --- | --- |
| complete patched `CriAudio.cpp` | `c27f088eab74a7a914ddcb32efbda4923d0b174c059f9c5029e6ec20f8096580` |
| `CriAudioBackend.h` | `b2e6cc5101ebd34fca4194c0987cd872f7fb740218a20602b1dec07227094560` |
| `CriAudioDispatch.h` | `4137a159817f22f109fc21a6a3a72e73a1a9eb7f95037ac7d64eefe32ee8d8c1` |

In123, layout clear/set called the public PCM reset and sealed legacy selection
before bootstrap installation. Public patch0123 adds the separately qualified
[pre-run reset transaction](PCM_BOOT_SETUP.md). In124, clear/set supplied the
actual runtime try `resetBeforeRuntimeRun` under a runtime-issued setup lease.
While the PCM registry is untouched/unselected and installation has not won,
this resets the same legacy routes/maps/clock without selecting an owner.
The registry reservation excludes first use during reset; runtime run sealing
waits for setup leases. Reset hooks run outside registry/runtime mutexes.
The existing RPC containers and their locking remain separately source-owned.

The combined binding regression now executes exact extracted layout clear/set
and snapshot bodies, exact runtime lease/run-seal bodies and complete patched
facade/dispatch. It forms the proof from that snapshot, installs this binding,
seals run, exercises all eleven methods and a callback, and successfully joins.
The ordinary public reset still selects legacy and refuses later installation;
there is no late switch from an already used legacy owner. Calls without an
admitted actual runtime setup phase retain ordinary reset behavior. The separate
boot suite qualifies nine lease/first-use/install/run/stop race scenarios;
fake integration surroundings here are not a replacement for that proof.

[The verifier](../../tools/native_reconstruction/native_pcm_backend/README.md)
passes with GCC 15.2.0 (MSYS2 Rev8) and bundled Clang 21.1.8: a production object
compiles against actual124 runtime/backend/raylib headers, and 20 isolated
cases per compiler exercise the complete patched facade/dispatch with fake
runtime/device/bank surroundings. Cases cover all eleven completed methods,
gain/mix/watermark order, callback delivery, headless advancement, paused producer
and callback drains, synchronous callback during play/startup, no reference
cycle after join, legitimate queue capacity, unsupported alias/domain/gain,
oversized-render sentinel safety, actual install API, changed text/64 MiB
refusal, five nonexact environment values, qualified boot setup followed by
complete binding execution, and ordinary public-reset refusal.

Receipt: `build-native-sjuni/native-pcm-backend-124/receipt.json`. No device, full
runtime library, guest execution, game test or full candidate build is performed
by these checks. Actual provider qualification is separately covered by
[NATIVE_STREAM_PROVIDER.md](NATIVE_STREAM_PROVIDER.md); matching rebuilt provider
objects, real lifecycle/audio/movie validation and whole-domain evidence remain
necessary for an integrated candidate.
