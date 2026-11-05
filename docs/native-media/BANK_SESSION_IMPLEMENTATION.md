# Native bank session implementation

Status: implemented isolated core in
[game/native/audio_banks](../../game/native/audio_banks/session.hpp). No dependency,
bootstrap, preparer, CMake or existing PCM changes; no backend installation,
device/game run or performance claim. The independent full-source oracle
comparison is pending. New original expected observations were not read or
generated while implementing this candidate.

The [boundary audit](BANK_SESSION_NATIVE_BOUNDARY.md) remains the complete caller
and guest-protocol inventory. This implementation owns host bank playback state;
it does not yet close the direct RPC producer path identified there.

## Source identity and attribution

The copied algorithms come from actual124
`build-native-sjuni/dependency-pcm-boot-reapply-v3`, dependency base
`c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f`, complete reapply receipt
`944b72d4cc977ac01d8e7a4459c601f0a331b06c8adbb5048bec45a2963f91cb`.
Reference `ReoSoundBanks.cpp` is
`e164ba72cc002311d4811d803be2e2df9a6228d5abcaa0c4fa419a31ee09b818`,
header `28963da544d533ae8f04765558ff0665c4dc87c38cfba767a4828705c07616c8`.
These two files are identical in sealed V6 and124; their surrounding RPC/runtime
ownership is not. The dirty active dependency checkout is excluded.

Bank/Sequence/VAG and envelope/request/mix bodies were mechanically extracted
from that source. [extract_reference.py](../../game/native/audio_banks/extract_reference.py)
checks both source identities before producing the checked-in algorithm/record/
member/mix files. [ATTRIBUTION.md](../../game/native/audio_banks/ATTRIBUTION.md)
identifies the reused code, and `LICENSE-PS2Recomp` retains the upstream GNU GPLv3
license verbatim. This is reuse of existing host C++, not a second PS2 interpreter
or a newly inferred implementation of the sound format.

The core was frozen before new independent expected output was inspected:

| Candidate file | SHA-256 |
| --- | --- |
| `session.cpp` | `8c0dc8a47dfcb57771edf8d05b70e263c280a2a86a5c2a1471c8c45d1d19559e` |
| `session.hpp` | `69d14f54e7de6d80ccfb0a6b35868bff0dcf33c3aa36a65fbb2bfc6cd7d881e8` |
| `algorithms.cpp` | `f0c88569224e1c8c2c5ce117e3296118f96a4b891a09a000ca2707c24fd9b923` |
| `algorithms.hpp` | `3b324870afdc42282910fe52f58e1fb3dd137f0550d590d547fd58e8ebd401e9` |
| `source_members.inc` | `15a9255f036a2658b173ada284a12385e929b66731618f227fe4770eb63c7f71` |
| `source_mix.inc` | `d28e10cdcc91cd4ae2941dd018c17ee902953c92d24a0fdc109fac3ec291f328` |
| `source_records.inc` | `44ea539c47bfd2dc31271c0aa96b9876d73818c9923a9739edae50127287dc0a` |

The same identities and reference hashes are recorded in
[frozen_identity.json](../../game/native/audio_banks/frozen_identity.json).

## Typed public boundary

`Session` owns14 ports, sixteen requests per port,48 voice records, sequence
clock/age, mute/mono and diagnostics. There are no playback globals or singleton.
The core includes no runtime/device/guest memory, raw packet decoder, file paths,
I/O, worker, environment lookup or supplied wall clock.

| Operation/type | Contract |
| --- | --- |
| `begin_submission()` | Move-only generation-qualified producer lease. Acquire before a future adapter captures guest inputs or reads assets; retain through prepare/install/apply and release after the complete producer operation. |
| `OwnedBankBytes` | Three owned HD/BD/TQ vectors. Move into preparation after capture; no borrowed RAM pointer is retained. |
| `prepare(submission,bytes)` | Producer-side source Bank load/decode. Returns an immutable PreparedBank qualified by this session identity and reset epoch. Allocation failures return `no_memory`; invalid source banks return `invalid_asset`. |
| `install(submission,port,asset,policy)` | Validates token/asset/session/epoch before port effects. Force replaces the bank; if-unloaded returns `skipped` without consulting an invalid asset when the valid port is already loaded. |
| `apply(commands)` / `apply(submission,commands)` | Typed ordered command effects. Stop at a native command error and return the applied prefix; no rollback or legacy retry. The convenience overload owns a short producer lease. |
| Queries | Source-compatible port state/count, exact masked sequence/group scheduler-active query, synchronous pending-load value0; typed closed/error status is separate. Closed port query leaves its caller's count output unchanged. |
| `mix_add(output,frames,gains)` | Add to an existing stereo48kHz buffer. Positive nonnull render is bounded; null/zero are source no-ops. No zeroing or final master clamp is introduced. |
| `reset()` | Invalidates preparation epoch, clears playback/diagnostics and resets clock/age. Pending old-epoch preparations can finish computation but cannot commit. This is distinct from terminal stop. |
| `request_stop()` / `join()` | Atomic admission closure; control-side wait for all accepted calls and whole producer leases, then clear owned state. No provider fence or whole-RPC retirement is claimed. |
| `drain_retired()` | Producer/control-side reclamation of deferred old decoded clips, outside state locks. |

Commands are a `std::variant` of StartRequest, ChangeRequest, CancelRequest,
StopAll/StopPort with explicit unload flags, global/port volume, mute, mono and
unsupported controls. Raw request selector/flag bytes retain their source
semantics. There is no pointer-shaped command or packet address. Native invalid
port commands return a prefix error; the future packet adapter must map source
accepted invalid/no-effect packet cases explicitly rather than blindly using that
error policy for every legacy opcode.

The future packet decoder must preserve the source's byte-order/conditional-load/
prefix-failure behavior. In particular,0x4E's already-loaded test must happen
before capturing/reading its otherwise unused asset descriptors. This core's
separate prepare/install calls do not magically make a future packet adapter's
conditional reads atomic. That adapter still needs its serialized producer
transaction and source-qualified fixture comparison.

## Admission, epochs and lifetime

State is strongly retained by producer Submission objects. Their preallocated
slots have generation-qualified reuse; foreign, moved-from, retired and stale
tokens are rejected. Prepared assets carry weak session identity plus an epoch,
so a foreign session or new post-reset token cannot adopt an old staged asset.
Preparation checks token validity before and after source load/decode; install
checks again under state serialization.

Reset increments the epoch without waiting for the resetting caller's own token.
This deliberately closes the old unlocked-load late-commit gap. It is a new
session lifetime rule, not a claim that the direct-global source had this rule.
Counter exhaustion closes admission rather than recycling an epoch. Request age
and frame-clock arithmetic otherwise retain the source unsigned behavior.

Stop is an atomic signal; it never waits for decode, joins a worker or resets
playback. Join waits complete producer tokens as well as current mix/control
calls without holding the data mutex. The caller must first release its **own**
Submission objects: join is not safe while the calling thread retains a token
whose destruction it is waiting for. Callback/current-operation join is detected
and returns false after signaling stop. Gain hooks are pure/no-session-reentry
apart from the separately safe stop signal.

Keep the Session alive through its calls and stop/join before destruction.
Prepared immutable data may outlive the session, but cannot be installed elsewhere
using a stale identity. A retained producer token is not proof that an unrelated
guest memory mapping, asset provider or runtime remains alive; a future adapter
must retain those actual owners for its complete capture/read/reply work.

## Render allocation and last-release handling

Construction preallocates48 voices,1,025 Events and65,025 resolved Sample records.
The Event bound is **1,025**, since the1,024-command TQ loop can append a final
Unsupported or terminal AllSoundOff+End event. Resolution has at most255 program
regions times255 sample references per matching set. This bound follows the
existing byte fields; it is not a guess that all notes have at most48 layers.

All source voice traversal, tick phase,48-record admission and removal order are
preserved. Current-port assets are immutable and strongly owned under the render
lock. A voice's immutable asset serial identifies whether that current cache
still guarantees a decoded clip owner. Releasing a current-cache Voice pointer
therefore cannot destroy the clip/cache control block during render.

Every old-asset Voice clip lease is moved into fixed48-entry retire storage.
There is no racy `use_count()` shortcut: an external asset holder could disappear
between a count check and release. Render preflights the entire old-voice demand
against remaining retire capacity before gain calls or frames.

Install collects prior retirement and replaces the port in **one** data-lock
transaction, then destroys collected clips/old assets on the control thread after
unlock. Draining before taking the install lock would leave a race in which an
intervening render consumed that retirement budget; the implementation avoids
that gap. Reset/join similarly move assets/clips to bounded control-side garbage
before clearing records. There is no background reclaimer thread.

The unit allocation guard observes zero ordinary heap allocations **and zero
deallocations** during tested positive renders, including48 old clip retirements,
full layer/Event scratch and current-cache removals. This is a core plus pure-gain
hook claim, not proof about arbitrary user gain callbacks or the still-global
legacy bank renderer used by today's PCM integration.

Producer preparation remains allocating work. Per-part2MiB/raw and8MiB decoded
limits are preserved. Maximum concurrent Submission slots and render-frame count
are configured, but externally retained PreparedBank results are not globally
capped by this first API. A caller can prepare multiple assets per token. There
is no claim that14 installed ports bound total caller-retained asset memory; an
aggregate asset budget is a separate pre-integration admission choice.

## DSP/gain compatibility and deliberate differences

The reused source implements VAG decode, cached sample ownership, TQ waits/jumps/
termination, request priority/cancel policy, ADSR, interpolation, pitch, crossfade,
pan and addition. Source224 gain-hook calls remain in port/slot order before
every positive bank block, including inactive/unloaded requests. Fingerprint
remains the source HD-only FNV value. The bank frame clock advances only for
nonnull positive output; mute/zero category gain still advances audio state.

No master gain, CRI clamp, device clock or automatic headless progress is added.
The eventual aggregate pipeline must retain CRI clamp -> bank addition -> master
multiply/final clamp. Cancel retires the scheduler and releases its current tails;
queries can become inactive before tails finish. Terminal join cuts residual owned
state after accepted operations finish; it does not promise an audible drain.

Explicit new policies outside an unqualified equivalence claim:

- Source callback `fprintf`/environment-based diagnostics become bounded typed
  counters and the first32 diagnostic events, with no callback I/O. Path totals
  are optional Config data and reset with Session reset. Snapshot does not mimic
  the old print-and-clear report's timing or formatting.
- Gain values must be finite in[0,8]; all224 reads occur before an invalid batch
  faults/ closes admission without rendering frames.
- The source floating-to-unsigned pitch conversion is guarded against nonfinite
  or out-of-uint32 values before the conversion. Within its defined domain the
  original operation order is retained. Outside it returns `numeric_domain`,
  closes admission and promises no rollback of a partly rendered prefix.
- Native token/epoch/capacity/error statuses are explicit. No per-command legacy
  fallback, implicit callback allocation or stale-load resurrection is permitted.

## Validation completed and still required

Both GCC15.2 and bundled Clang21.1.8 compile with warnings as errors and pass123
meaningful unit assertions. Cases cover owned-copy independence, bad preparation
preserving an installed asset, conditional skip, null/zero and muted progress,
cancel tail/query separation, foreign/stale assets, complete producer join wait,
reset against preparation paused at its actual allocation boundary, native prefix
errors, invalid gain and callback self-join refusal. The retirement tests observe
actual deferred destruction on control drain as well as empty retire storage.

Scratch tests exercise65,025 layers and1,025 Events with allocation guards. Other
guards cover current-cache removal,48-entry old-clip retirement and another port
replacement after a full retirement budget. They test ownership/bounds rather
than embedding a second copy of the synthesis formula as an expected oracle.

Receipts:
`build-native-sjuni/audio-bank-session-checks/{gcc,llvm}/receipt.json`.
They record compiler/command/all authored identities and the original pre-oracle
freeze. Reproduce using an existing compiler:

```powershell
python game/native/audio_banks/verify.py `
  --cxx C:/msys64/mingw64/bin/g++.exe `
  --output build-native-sjuni/audio-bank-session-checks/gcc
```

Independent full-source fixtures and float/state/order comparison remain required
before any parity admission. Then the complete bank RPC/queries/reset facade,
runtime/session identity, selected-owner registration, guest asset capture and
actual provider shutdown must be integrated and rebuilt coherently. These unit
checks do not establish those missing boundaries or faster gameplay.
