# Complete native bank-session ownership boundary

Status: read-only Stage3 design from actual124 source. No new bank owner, parser,
fixture run, performance measurement, device test or gameplay validation is
claimed. This document proposes the next implementable contract. The existing
PCM backend owns CRI queues/output lifetime; it still calls the global legacy
bank helper for mixing/reset, while bank RPC producers bypass that PCM admission.

## Exact baseline and reusable implementation

Reference source is fresh full124
`build-native-sjuni/dependency-pcm-boot-reapply-v3`, upstream base
`c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f`, receipt SHA-256
`944b72d4cc977ac01d8e7a4459c601f0a331b06c8adbb5048bec45a2963f91cb`.

| Input | SHA-256 |
| --- | --- |
| `Kernel/Syscalls/Helpers/ReoSoundBanks.cpp` | `e164ba72cc002311d4811d803be2e2df9a6228d5abcaa0c4fa419a31ee09b818` |
| `Kernel/Syscalls/Helpers/ReoSoundBanks.h` | `28963da544d533ae8f04765558ff0665c4dc87c38cfba767a4828705c07616c8` |
| Actual124 `Kernel/Syscalls/RPC.cpp` | `35a31813d63b8cd7ecb5144f3044d45b933706eafde42fa866decc8ee010f8eb` |
| `ps2_iop.cpp` | `c8d942c50b4f9baa39593d23c956041ef4e65311b932b0ff50539488ab8a133a` |
| Root `runtime/audio/mixer.h` | `e846a60767732e069a67fce524a2cf1d654f86d9a8247c5be34674a21ef85b4e` |
| Root `runtime/audio/host_bridge.h` | `d2c2f3411214d5443dd65753d5ffed5655975633d92038f3b6f52bf6f59be759` |

The bank `.cpp` and `.h` are **byte-identical** in sealed V6 and actual124. V6's
RPC source is `050d63e738481ac592429a21ba317fcb28f86f8d47afe48b2ee4ed8c3dc81a9f`,
so V6 is not interchangeable with the124 RPC/PCM dispatch/startup boundary.
V6 also contains the same host mixer header. Preserve those distinctions in
source receipts and future tests; do not use the dirty active submodule as the
reference merely because its helper has the same filename.

Most of the bank implementation is already host C++ and should be reused:

- `Bank::load/record/sequence/resolve/decode/decoded` implements owned HSYN
  tables, TQ metadata and cached VAG PCM. It is not a PS2 instruction interpreter.
- `Sequence::start/tick` implements the bytecode scheduler as ordinary C++.
- `Envelope`, request allocation, sample layering, interpolation, pitch, pan and
  addition into stereo output are ordinary host synthesis code.

The first extraction should move that implementation into a session-owned state
object with typed commands/assets. Rewriting a second decoder, replacing VAG
with ADX, or translating the game sound driver again is not necessary for this
ownership cut. Original guest/RPC packet assembly and completion are a separate
remaining protocol, described below.

## Complete state inventory

| Owner/state | Current storage and behavior |
| --- | --- |
| `Bank` | Owns HD, BD and TQ byte vectors; four parsed chunk offsets; map from BD offset to shared immutable decoded samples. |
| `DecodedSample` | Owns PCM16 vector, loop start and loop flag. Shared pointers keep old sample data alive after a port replaces its bank. |
| `Sequence` | Per-request cursor, wait counter, program offset, active flag and `hasNote`; no retained external bank pointer. Each tick receives the port's current Bank. |
| `ports[14]` | Global array. Each Port owns a Bank, HD fingerprint, loaded flag, unsigned volume (default256) and sixteen Request records. |
| Request | Sequence plus index/group/priority/cancel flags; requested volume/pan/pitch; current program/volume/expression/pan/pitch; uint64 request-age counter. Default request volume/expression127, pan64, pitch0x2000. |
| `voices` | Global vector, maximum size48 at note admission. Each Voice has port/slot, note/group/velocity, copied Sample metadata, shared decoded PCM, double position/step, cached bend, ADSR phase/value/countdown/registers and active flag. |
| `requestAge`, `frameClock` | Global uint64 counters. Age drives request replacement ties; output frames drive sequence tick phase. |
| `muted`, `mono` | Global command-controlled flags. Muting does not pause scheduling or sample/envelope progress. |
| `soundMutex` | Global serialization of port/request/voice state and queries. Load/decode can deliberately run outside this lock. |
| Diagnostics | Global `unsupportedReports`; process-fixed environment-derived `pathLog`; fixed14×128 path counters; `pathMixFrames`. Report reads steady-clock time and prints after copying counters. Unsupported reports can also originate inside mixing. |
| Host gains | External `reoAudioBankGain(port,sequence,HD-fingerprint)`; category/master settings and64 stream-route atomics are owned by root host mixer globals, not by the bank helper. |

`reset()` sets ports to defaults, clears/reserves the voice vector, resets age and
frame clock, mute/mono and diagnostics. It does not change the process-fixed
`pathLog` setting, master/category levels or CRI stream-route entries. A complete
bank session must own all mutable rows above; moving only `voices` is incomplete.

Replacing a port bank stops that port's requests/voices, replaces the Bank and
fingerprint, marks loaded and reserves48 voices. Inactive voices can retain their
decoded sample pointers until periodic erasure. Unload commands generally clear
`loaded` after stopping but retain the Bank/fingerprint allocation until another
install or reset. Preserve that distinction in the first extraction.

## Every production entry and bypass

The global helper surface is `submitBank`, `submitPacket`, `mix`, `reset`,
`pendingLoads`, `portState`, `seState`, plus the private diagnostic entry
`reportAudioPaths`. `Bank` and `Sequence` are independently usable utility types;
their pure parser/test use need not create a global playback session.

| Caller | Actual124 path |
| --- | --- |
| Guest sound commands | `ps2_iop::handleRPC` -> `handleSoundDriverRpcService` -> `handleSoundDriverRpcServiceImpl` -> `handleSoundDriverCommandBuffer` -> public PCM `ensureHostOutput()` -> direct bank `submitPacket()`. |
| Sound queries | The same RPC service directly calls bank pending/port/SE queries; no PCM facade call encloses them. |
| Sound reset/adoption | `resetSoundDriverRpcStateUnlocked()` calls bank reset. Public runtime initialization/run reset and `adoptSoundDriverRuntimeUnlocked()` on runtime-cookie change reach this independently of PCM reset. |
| Legacy PCM output | `CriAudio::render` releases its PCM lock, calls bank mix, then reads master and performs final multiply/clamp. Its shutdown resets banks; ordinary PCM reset retains banks. |
| Native PCM candidate | `RuntimeServices::mix_banks/reset_banks` still call these same globals. The native PCM producer lease covers its own `ensureHostOutput()` call, not the following direct RPC bank submission. |
| Existing diagnostics | The legacy guest-side CRI report calls bank `reportAudioPaths`; the device bank mixer does not call that snapshot function. Native PCM's own report is not a replacement for those bank path counters. |
| Standalone tools | `tools/sound_bank_check`, audio mixer checks and bank cancellation checks call submit/load/parser/query/mix directly. No other production `submitBank` caller was found in the inspected124/runtime/root call set. |

The command SID is0, submit RPC number0. Query SID is1; low-byte query4 is SE
state,6 is port state,0x0C is pending loads. RPC number's high blocking bit is
handled by the existing protocol. Status-address/table requests0x12/0x13 and
their synthetic IOP arena are **not** part of the Bank object.

The command wrapper validates guest packet range within the hardcoded32MiB
window, holds `g_rpc_mutex`, ensures output and calls `submitPacket`. It ignores
the parser's boolean result and reports the command RPC as handled. Query results
are written back as guest words with the existing completion flag/result-pointer
rules. A new typed status must not silently change these acknowledgments or
introduce a legacy retry after the native session owns the command.

`SoundDriverRpcState` is still global and includes a raw runtime-cookie value,
initialized flag, IOP arena/base/status/table addresses and storage size;
`g_soundDriverIopRam` is a borrowed runtime IOP pointer. Compatibility-layout
callbacks/globals, status backfilling, DMA status transfer and semaphore/RPC
completion remain external to the proposed BankSession. Pointer-cookie equality
is not a session/incarnation proof.

## Asset ownership and the current unlocked load interval

`Bank::load` initially validates pointers and per-part sizes (HD≥0x34, TQ≥16,
nonempty BD, each≤2MiB). It copies HD into temporary storage, validates reversed
SCEI chunk signatures, then owns BD/TQ copies. It scans at most4096 Vagi entries,
eagerly decodes unique BD offsets and bounds total cached decoded PCM at8MiB per
bank. Successful playback does not read the caller's original HD/BD/TQ buffers.
The caller's memory must nevertheless remain readable/coherent **during** load.
Length checks and `g_rpc_mutex` do not themselves prove arbitrary guest/DMA
writers cannot change those borrowed buffers.

`submitBank` prepares a temporary Bank before locking playback state. Packet
load commands0x4D/0x4E derive three borrowed pointers from guest RAM and release
`soundMutex` while `Bank::load` copies/decodes. The parser also retains the borrowed
packet pointer and resumes reading it after relocking. No asset lease, session
epoch or cancellation token spans that interval.

This creates the concrete remaining lifetime gap: native PCM stop/join can fence
PCM/render calls and reset banks while a direct bank RPC producer is still inside
unlocked load/decode. That producer can later reacquire `soundMutex` and install
a bank after the reset. The RPC producer holds `g_rpc_mutex`, which serializes
ordinary sound-driver resets that also take that mutex, but native output-owner
join/reset does not take it. PCM's eleven-method admission therefore does not
prove all bank producers are stopped. This is source-level reachability evidence,
not a claim that a playtest reproduced the interleaving.

The fix must lease the entire bank producer operation, including input capture,
decode and commit. Merely adding an epoch check around `mix()` or wrapping global
bank reset is insufficient. Normal reset also needs an explicit producer-order
contract so a pre-reset staged load cannot resurrect post-reset state.

## Raw packet semantics to preserve in an adapter

The host core should receive typed commands. The guest-facing adapter must first
reproduce this packet parser's measured semantics; it is not an all-or-nothing
batch validator.

| Opcode | Source length and effect |
| --- | --- |
| 0x00..0x07 | New request. Length5 plus optional volume/pan/pitch bytes selected by low bits. Port/index/group occupy bytes1..3; trailer is program offset. |
| 0x08 | Four-byte exact masked index/group cancel. Retires matching scheduler immediately and releases its sounding envelopes. High selector bits are not wildcard cancel. |
| 0x09..0x0F | Change matching active requests; high index/group bits provide wildcard selection. Missing volume/pan/pitch use255/255/65535 sentinels. |
| 0x28,0x40 | One byte: stop all requests/voices, retaining loaded flags. |
| 0x43 | One byte: stop all and mark every port unloaded. |
| 0x29 | Three bytes: big-endian unsigned volume applied to every port. |
| 0x41 | Two bytes: mute flag is second byte!=0. |
| 0x42 | Two bytes: mono flag is second byte==0. |
| 0x47..0x49 | Two bytes: valid port stops and becomes unloaded. |
| 0x4A | Two bytes: valid port stops but stays loaded. |
| 0x4C | Four bytes: valid port receives big-endian unsigned volume. |
| 0x4D |21 bytes: force prepare/install HD/BD/TQ bank for big-endian port number. |
| 0x4E |21 bytes: prepare/install only if the port is currently unloaded. A loaded port skips descriptor validation and asset reads. |
| 0x44 | Six bytes: accepted reverb command is reported unsupported; no implemented reverb effect. |
| 0x45,0x4B | Four/three bytes: accepted global controls currently report no implemented effect. |
| 0xFF | Packet terminator; trailing bytes are ignored. End-of-buffer without a terminator is also accepted if complete commands were consumed. |

Unknown/truncated commands return false after any prior command effects. A failed
bank preparation preserves the previous installed bank, but does not undo earlier
commands in the packet. Some invalid targets are accepted no-ops; an invalid load
port is a failure. Preserve distinct typed outcomes such as accepted/no effect,
unsupported-but-consumed, malformed, asset failure and closed admission rather
than making every result a fatal whole-session error.

Each packed load descriptor uses the high address nibble of byte3 plus the first
three bytes, masks address to0x01FFFFFF, and obtains a16-byte-aligned size from
byte3's low nibble and bytes4/5. There are no guest pointers inside the proposed
typed BankAsset/Command. Keep this translation at the source-qualified adapter.
In particular, eagerly reading all asset descriptors before checking0x4E's loaded
condition would add observable reads/failures the source does not perform.

## Scheduling, synthesis, queries and gain ordering

Bank time is output-frame time:48kHz,240 sequence ticks/second, exactly200 frames
per tick. The shared `frameClock` starts at0; the first positive mix ticks all
loaded ports in increasing port and slot order before mixing that frame. Inactive
voices are erased at frame199 modulo200. Vector insertion/traversal order is
float addition order and must not be replaced by arbitrary slot sorting.

Request allocation searches slots15 down to0 for an inactive slot, then applies
priority/oldest replacement rules with their exact comparison/tie behavior. New
request flags can cancel matching flagged schedulers; targeted change/cancel has
different wildcard rules. `Sequence::tick` bounds its bytecode loop to1024 commands,
implements waits/jumps/note/program/volume/pan/pitch/expression and termination
waiting, and explicitly reports other control/extended commands. `seState` reports
**scheduler active**, not whether release-tail audio remains. Query zero after
cancel does not prove silent output or full voice retirement.

The voice cap is `voices.size()>=48`, which includes inactive records awaiting
periodic erasure. It is not simply a count of currently audible voices. Note
resolution can produce more layers than admitted voices; preserve rejection/order
behavior when extracting, rather than assuming a48-element resolution scratch
buffer is sufficient for every currently admitted bank header.

The renderer interpolates double sample positions, applies cached bend/pitch,
integer-derived volumes/crossfades, ADSR and pan, then adds float contributions to
the **existing** stereo buffer. It does not zero output or clamp the bank sum.
The surrounding pipeline remains CRI clamp -> bank addition -> master multiply ->
final clamp. Mute and zero host gain still advance sequence, envelope and sample
positions. Mono affects pan, not timing or sample ownership.

`mix(nullptr,n)` and zero-frame bank mix are immediate no-ops: no gain calls,
scheduling or headless advancement. CRI's headless/zero-frame clock selection does
not advance bank time. With no device/manual nonnull output, bank sequences can
remain active; adding automatic bank wall-clock progress would be a separate
behavior change requiring its own cases.

For every positive bank mix, source reads224 gains once in port0..13/slot0..15
order, including unloaded/inactive requests. Each gain uses that slot's sequence
index and the port's **HD-only FNV fingerprint**. Voice-bank routing uses that
fingerprint; it is not an asset identity for BD/TQ. Keep it separate from a new
content/session identity. Current host gain calls read atomic level values; a
single frozen level snapshot would be a deliberate timing change, not automatic
equivalence to224 individual source hook calls.

Current File1 category routing is UI for port0, Voice for ports4..7 and the known
selection-bank fingerprint at port12, selected NPC sequences at port13, otherwise
SFX. File2 uses its own selection fingerprint. CRI's64-entry stream routes are
independent, discovered by the guest stream-start hook, and are cleared by PCM
route reset. Bank reset must not erase them or reset launcher mixer levels.

## Current callback work that is not yet a bounded native render contract

Eager VAG decode already occurs on producers. However `tickUnlocked` constructs
temporary Event/Sample vectors during positive rendering, and note resolution can
grow them. Capacity/unsupported paths can call `fprintf` while the device thread
holds the bank and audio-system locks. These are existing source behaviors, not a
newly measured slowdown or evidence that the algorithm should be rewritten.

A native session must qualify finite scratch/diagnostic storage before promising
no callback allocations/logging. Fixed14 ports/16 requests/48 voice records do not
by themselves bound all resolution output to48. Either derive and admit a larger
complete bound from the existing byte-format limits or explicitly qualify a
narrower asset/sequence domain before publication; do not truncate layers/events
silently to make a scratch buffer fit. Numeric pitch/cast domains should also be
qualified for synthetic malformed metadata before claiming arbitrary byte inputs
are a defined arithmetic oracle.

## Minimal closed typed boundary to implement next

Introduce `BankSession` with a private State containing all playback/diagnostic
state above, and immutable prepared `BankAsset` objects. Keep existing arithmetic
and scheduler logic initially unchanged. No guest context, RAM base, raw runtime
pointer, packet address, file path, wall clock or provider call belongs in the core.

Suggested host-only types and operations:

```cpp
// Conceptual contract, not an implemented API.
PreparedBank prepare_bank(OwnedBankBytes bytes, AssetIdentity source);
BankResult install(Port, shared_ptr<const BankAsset>, LoadPolicy);
CommandResult apply(span<const BankCommand> commands); // ordered prefix effects
QueryResult port_state(Port);
QueryResult sequence_state(Port, SequenceIndex, Group);
QueryResult pending_loads(); // source-compatible synchronous value0
MixResult mix_add(span<float> stereo, BankGainProvider&);
ResetResult reset_banks();
void request_stop() noexcept;
bool join() noexcept;
```

`Port`, sequence/group selectors and command variants retain source unsigned/raw
flag semantics in the adapter; do not assume every high bit is an invalid index.
Prepared assets own the three captured byte ranges and decoded data, with an
identity/generation independent of the HD fingerprint. Port slots retain immutable
assets. Voices retain copied Sample metadata and decoded-clip leases; they need
not retain every old Bank's entire raw asset merely to finish one sample.

`OwnedBankBytes` can initially be bounded copied vectors. For actual resource
ownership, [ResourceSession](../../game/native/resources/resource_session.hpp)
provides generation-qualified handles, retained `ByteView` and transactional exact
reads; [bounded_view](../../game/native/resources/bounded_view.hpp) supplies retained
subranges. [MountedResources](../../game/native/resources_windows/mounted_resources.hpp)
and verified PinnedFile retain actual file identities/content hashes. Perform reads
and decoding on a leased producer, never in bank mix. `VirtualFileView` alone
requires externally immutable backing and is not proof of a content snapshot.

These interfaces do not yet map an arbitrary guest HD/BD/TQ pointer back to an
owned AFS/MOMO member. Existing test support can read such members, but is not a
production native AFS ownership implementation. First capture the current guest
inputs under a source-qualified read/operation lease and copy them; independently
owned file routes can replace that bridge later. Do not invent a resource identity
from a raw RAM address.

Use a producer-command serialization mutex separate from the mix-state mutex.
It preserves ordered producer semantics while allowing other banks/CRI to render
during expensive prepare/decode. Installation is a short state transaction with
generation/reset checks. Ordinary bank reset must serialize with complete producer
transactions or reject their stale commits by explicit epoch. A stopped session
refuses all new bank commands/queries without retrying globals.

The compatibility adapter may continue parsing source packets initially, but must
produce owned typed commands/assets and preserve prefix-failure semantics. It
should expose an internal status/diagnostic even where the old RPC wire deliberately
acknowledges an unsupported or rejected command. No async load is implied;
`pendingLoads()==0` currently remains true even during another synchronous
producer's unlocked decode interval.

## Aggregate audio lifetime and lock order

The next backend selection must bind PCM **and every bank facade operation** to
one AudioSession owner before first use. Extend the versioned complete backend
registration, or attach a complete bank table atomically to the same binding.
Do not install a bank owner later after its legacy globals have already played,
and do not choose legacy/native separately per bank operation.

The complete bank command admission lease spans packet/input capture, asset read,
prepare/decode, install and return. It must be retained while the submitting
wrapper temporarily leaves the bank mutex. Queries/reset/diagnostics also retain
the selected owner. An already admitted PCM render needs an internal bank render
lease/token that remains valid through its bank/master stage after stop is
signaled; it must not reenter a newly closed external bank admission gate halfway
through an accepted audio block.

Keep these source distinctions:

- Ordinary PCM reset retains independent bank voices/provider and only clears
  CRI routes/queues as specified. It must not become aggregate bank reset.
- A bank-only reset resets banks but retains CRI streams and host levels.
- Audio-session stop is terminal admission closure. Join waits all accepted
  producer/render work, fences/detaches/stops/unloads the provider, then releases
  bank/PCM resources. A false fence preserves ownership for retry.
- Bank-only startup still ensures the selected output stream before the first
  CRI queue. Ensure output happens before taking bank mix-state locks.

Current lock order is producer `g_rpc_mutex` -> PCM ensure/provider startup
(without bank lock) -> bank command lock; device audio-system lock -> callback ->
PCM state -> release PCM state -> bank mutex -> atomic host gains. Bank load drops
only the bank mutex, retaining RPC/guest context. A future aggregate join must
never hold RPC/guest, PCM or bank locks while waiting for a producer or a provider
fence. Closing admission and waiting with no such locks allows a pre-stop bank
producer to finish before the guest host threads are joined on early unwind.
The callback must never acquire a provider lifecycle or producer-command mutex.

Session join proves native bank/output ownership quiescence, not that unrelated
guest RPC completions, IOP arena writes or all guest threads have finished. Runtime
destruction still needs their separate join. The124 PCM binding deliberately does
not yet claim that broader bank/RPC lifetime proof.

An audible drain is separate from that terminal join. Source packet cancel0x08
retires the selected scheduler and puts its current voices into envelope Release;
an in-sequence AllNotesOff only releases current notes and allows the scheduler
to continue. A proposed `drain_request` must use the former scheduler-retirement
semantics, retain clip leases until release voices finish, and report tail state
separately from the source `seState` query. Unloaded/headless output does not
advance those tails automatically, and an arbitrary repeating sequence has no
natural completion guarantee. Neither stop admission nor join should wait for
an unqualified audible drain: join waits accepted calls, fences output, then cuts
and releases the remaining owned state. Do not introduce a timed wait that frees
still-used assets or call a silent headless fallback a completed device drain.

## Source-qualified fixtures required before implementation admission

Freeze the candidate session source before inspecting new expected output. Compile
the exact124 bank helper as a separate oracle with synthetic HD/BD/TQ and controlled
gain/diagnostic hooks. Keep inputs separate from observed state/float output and
use matching GCC and LLVM cohorts; libm-dependent pitch/interpolation observations
must be attributed to the toolchain, not automatically to original PS2 hardware.

Required cases for the first closed session:

1. Owned-copy independence for HD/BD/TQ; failed preparation leaves installed asset;
   replacing a bank retains old decoded sample lifetime until voices retire.
2. HSYN records, unique/overlapping Vagi cache, VAG filters/end/loop flags, TQ
   waits/loop jumps/FE/FF termination and explicit unsupported/control outcomes.
3. All packet variants and prefix effects, truncation/unknown opcode, conditional
   load skipping invalid descriptors when already loaded, force reload, every
   stop/unload/mute/mono/volume command and query encoding.
4. All16 request slots, age/priority ties and flagged replacement; cancel versus
   in-sequence AllNotesOff, exact high-bit cancel selectors versus wildcard change;
  48-record capacity including inactive entries pending tick-boundary erasure.
5. Frame0/199/200 boundaries, positive callback partitioning, null/zero no-op,
   muted progress, release tails after scheduler query becomes inactive, bank-only
   output and independent PCM/bank reset behavior.
6.224-call gain order, old HD fingerprint after unload, File1 category/master
   routing and CRI-clamp/bank-add/master-final-clamp composition with mixed signals.
7. Paused asset read/decode versus reset, stop/join and port replacement. Observe
   the old direct-global late-install interleaving separately; prove the new owner
   waits or rejects stale commit. Mark that lifecycle correction as intentional,
   not fabricated original-equivalence evidence.
8. Admission closure with a bank-only producer, already admitted PCM render in its
   bank stage, failed provider fence/retry, callback self-join refusal and all
   bank facade operations using the selected session after publication.
9. Bounded scratch/counter/diagnostic admission and allocation failures. Decode/
   preparation failures occur on producers with typed results; no silent callback
   allocation, arithmetic-domain expansion or per-operation fallback is admitted.

Existing tests provide useful transcripts, not completed new-session evidence:
`tools/sound_bank_check/main.cpp` checks owned menu/character captures and split
mixing; `tools/audio_transition_check/bank_cancel.cpp` uses authored repeating TQ
with an owned sample; `tools/audio_mixer_check/pcm_test_support.h` exercises host
category/master composition. Their asset-dependent checks were only read here,
not run. Synthetic redistributable fixtures should cover the core contract first;
optional owned capture retests must remain local and clearly identified.

The next concrete implementation is therefore **session state extraction plus
complete bank producer/query/reset admission**, retaining the existing codec and
synthesis. Guest command construction, packet/asset capture, IOP status/DMA and
completion still require their adapter proof. This is an ownership milestone;
it makes no claim of faster rendering, higher framerate or removal of those
remaining guest protocols.
