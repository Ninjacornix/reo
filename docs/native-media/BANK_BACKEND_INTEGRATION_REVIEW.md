# Bank backend selection, whole-call fence and asset-budget review

Status: source-only integration design. The isolated bank core stays frozen for
independent comparison. No dependency/runtime/bootstrap mutation, build, game,
device test or new performance claim is made here.

Use the [bank boundary inventory](BANK_SESSION_NATIVE_BOUNDARY.md) for every
opcode/state field and [bank implementation](BANK_SESSION_IMPLEMENTATION.md) for
the current typed core. That core is implemented but not wired into the124
sound-RPC facade. This review specifies the missing selected-owner wrapper,
producer fence and memory admission before such wiring is safe to claim.

## Qualified source and actual caller closure

Reference is actual124
`build-native-sjuni/dependency-pcm-boot-reapply-v3`, base
`c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f`, receipt SHA-256
`944b72d4cc977ac01d8e7a4459c601f0a331b06c8adbb5048bec45a2963f91cb`.
Bank CPP/H hashes are respectively
`e164ba72cc002311d4811d803be2e2df9a6228d5abcaa0c4fa419a31ee09b818` /
`28963da544d533ae8f04765558ff0665c4dc87c38cfba767a4828705c07616c8`.
Actual124 RPC CPP is
`35a31813d63b8cd7ecb5144f3044d45b933706eafde42fa866decc8ee010f8eb`.
The bank algorithms also match sealed V6, while the RPC/selection/startup paths do
not; an old V6 runtime library cannot satisfy the new interface.

Relevant exact locations in that source snapshot:

| Source location | Ownership significance |
| --- | --- |
| `RPC.cpp:211..238` | `resetSoundDriverRpcStateUnlocked` resets banks; runtime-cookie adoption can call it before any packet access. |
| `RPC.cpp:459..483` | Command wrapper validates RAM range, ensures output, then directly calls global `submitPacket`; `ensureHostOutput`'s lease has already ended when submit starts. |
| `RPC.cpp:486..550` | Recognizes sound submit, pending/port/SE queries and status-address/table requests. Queries write guest output; address requests can adopt/reset runtime state. |
| `RPC.cpp:1318..1321` | Public sound-driver reset holds `g_rpc_mutex` and calls the reset helper. |
| `RPC.cpp:1814..1825` | Outer SIF wrapper calls `iop().handleRPC`, then performs nowait-completion processing. |
| `ps2_iop.cpp:22..43` | Borrowed runtime/RDRAM bridge into sound-RPC service. |
| `ps2_runtime.cpp:3288` | Actual direct runtime reset caller: `run()` setup, after external-worker run sealing. No direct initialize-time call was found in this124 file. |
| `ReoSoundBanks.cpp:433..496` | Direct bank submission/packet path; producer drops `soundMutex` during prepare/decode and later installs unconditionally. |
| `ReoSoundBanks.cpp:499..553` | Device/output mix,224 gain reads and frame-driven internal tick. |
| `ReoSoundBanks.cpp:558..599` | Diagnostics, reset and three query methods. |
| `CriAudio.cpp:201,321` | Legacy composite bank mix and bank reset on shutdown. Ordinary PCM reset retains banks. |
| Native PCM `RuntimeServices::mix_banks/reset_banks` | Current candidate still calls those same globals; complete PCM admission is not complete bank command admission. |

`applyMatching()` clears the sound compatibility layout, but that setter merely
assigns layout. Do not invent a bank-reset initialization call there. DTX layout
clear/set is a separate PCM reset path handled by0123. A future embedding that
needs an unselected bank initialization reset must use an explicit runtime-issued
pre-run setup transaction; a generic reset or empty-state heuristic must not
become another implicit selection exemption.

## One selection for PCM, banks and sound control

Extend the versioned complete audio backend transaction to include the full bank
surface. Use one shared registry decision:
`unselected -> legacy` or `unselected -> native(AudioSessionIdentity)`.
Publication includes complete PCM and bank capabilities, one output owner,
bank/core state and runtime worker ownership. A partial/mismatched registration is
refused before publication. No late bank-only install after legacy banks played,
per-operation switch, independent bank singleton or mixed native/legacy queue
fallback is admitted.

The legacy implementation must be callable privately after selection. Every
public facade wrapper takes a strong selected-owner snapshot under a short
registry lock and invokes/destroys outside it. Ordinary first use, including
public reset, seals legacy if no native owner is published. Public first-use
calls wait an explicit boot-reset reservation; installer publication cannot race
such a reset. Preserve the0121/0123 stop, publication-loss and inert-worker rules.

Pure `Bank`/`Sequence` utility use in standalone tools does not select a playback
session. Playback facade methods do. The complete surface is:

| Entry | Selected-owner requirement |
| --- | --- |
| `submitBank` | Acquire whole producer admission before source load/copy/decode. Capture owned typed bytes, prepare and install into the chosen session. |
| `submitPacket` | Acquire before packet capture/parse. Decode typed ordered effects; retain one producer token across asset reads/decode/install and all prefix effects. |
| `pendingLoads` | Selected query, retaining the source synchronous value0; admission/closed status is separate. |
| `portState`, `seState` | Selected queries with source masking/scheduler semantics; no hidden tick and no legacy retry. |
| `mix` | Add under the already admitted composite render scope, preserving source gain/order/frame timing. Do not reacquire a newly closed outer gate halfway through a render. |
| Internal tick | Remains part of the selected bank positive-mix operation. There is no separate guest-update/global tick facade to invoke once per arbitrary callback. |
| `reset` | Selected bank-only reset/epoch invalidation. It does not reset PCM routes, host levels or the provider. |
| `reportAudioPaths` / diagnostics | Selected owner snapshot; typed native counters can be consumed on control side. Old print/reset semantics are not automatically native parity. |
| Sound-driver reset/adoption | Must perform its bank reset through the same selected context, never reach private global state while native selection is active. |

One possible internal interface is `SoundCall` plus typed operations over it:
`capture_packet`, `apply_commands`, `prepare/install_bank`, three queries,
`reset_banks(reason)`, `mix_under_render_scope` and diagnostics. `SoundCall` retains
the selected AudioSession, runtime/session identity and the outer whole-call
admission obligation. It is not a raw guest pointer or an independently chosen
backend. Its destructor releases the count outside registry/state locks.

Keep original public signatures as compatibility wrappers where required, but
pass this context explicitly through internal RPC functions. Avoid implicit TLS
fallback that accidentally starts a new selected operation while an already
admitted one is completing. The packet decoder remains outside the frozen core.

## Acquire before the first bank-affecting side effect

Classification can use SID/RPC primitive arguments before guest reads. Recognize
exactly the existing service scope: SID0/RPC0 submit; SID1 low-byte4/6/0x0C queries;
SID1/RPC0x12/0x13 status/address requests. Unrecognized service traffic returns
`not_covered` before audio selection, source reads or side effects.

For a recognized call, acquire aggregate audio admission **before**:

1. `checkSoundDriverMemoryUnlocked()` / runtime adoption and their possible bank
   reset;
2. reading query input, packet bytes or packed asset descriptors;
3. original command logging/capture;
4. provider ensure/start;
5. copying, parsing, decoding or committing a bank;
6. bank queries and accepted-call guest response publication.

Acquiring only inside `submitPacket()` is too late: adoption may already have
reset the global bank owner. Acquiring only around `ensureHostOutput()` is the
current incomplete fence. Status/address RPCs also matter even though their
returned synthetic IOP pointers are not part of the bank core: checking their
arena can adopt/reset the runtime before returning it.

After admission, retain the existing appropriate RPC/guest read context while
capturing. `g_rpc_mutex` serializes sound producers but is not an independently
proven immutability lease against every guest/DMA writer. Capture ownership and
capture coherence are distinct. Owned copied bytes close the core's borrowed
pointer lifetime; they do not by themselves prove the original assets were not
changing during that copy.

For recognized closed/foreign/failed-owned calls, return a distinct owned result;
do not return `not_covered` and restart legacy I/O. A rejected entry must not
capture new guest bytes or mutate bank state. The RPC adapter must explicitly map
its wire completion/cancellation outcome. Existing command RPC ignores parser
false and reports handled; queries use result words/result pointer/nowait flag.
Preserve admitted-call behavior and test the new closed-call policy rather than
inventing a successful zero result that can hang an awaiting guest.

Accepted-call leases should span their guest result writes. Outer SIF completion
and unrelated status/DMA processing remain separate runtime protocol. Rejecting
a bank call does not prove every outer guest semaphore or client-field access has
ended. Native audio join must not claim whole guest-RPC retirement from its own
bank count alone.

## Rendering, pause and shutdown

The frozen bank core can be integrated without changing its mix API to admit
post-stop work. Use this aggregate ordering:

1. Stop atomically closes **outer AudioSession** admission and signals the output
   Owner to refuse new callbacks. It does not immediately close the inner bank
   core while already admitted outer renders may still need their bank stage.
2. Control join waits every accepted outer call, including bank producer capture/
   decode/commit and CRI -> bank -> master render completion. It holds no RPC,
   guest, PCM, bank, producer-command or provider-system lock while waiting.
3. With no accepted outer calls remaining, fence/detach/stop/unload the actual
   provider using its source-qualified lifetime implementation. Failure retains
   owner/resources for retry; no joined claim or device-close permission follows.
4. Close/join the inner bank core and release prepared/retired assets on control
   side; shut down PCM state in the aggregate's specified order. A final reset
   must not call a public bank wrapper that reenters the closed gate or selects
   legacy. Runtime destruction still joins guest threads before freeing RAM.

Every live inner Submission must be scoped inside an accepted outer call; do not
return one from a runtime facade or retain it after that call exits. Immutable
prepared assets can have a longer budgeted lifetime, but producer tokens cannot
escape and make inner join wait forever after outer count reached zero.

This ordering preserves the bank half of an accepted render after stop was
signaled. Alternatively, a future explicitly admitted internal render token could
be added, but changing the frozen core for that purpose is unnecessary here.

Current mute/mono are source commands. Mute advances notes/envelopes/clock;
absence of output callbacks does not. `mix(nullptr,n)` and zero-frame bank mix do
not advance. CRI headless ticks must not be reused to advance banks automatically.
No new pause/resume API is implied; output pause, mute, bank-only reset, ordinary
PCM reset and terminal admission stop remain distinct operations.

Cancel retires a scheduler and releases its current tails; AllNotesOff can leave
a scheduler capable of new notes. Audible drain is not terminal join. Looping
sequences, long release envelopes or absent output cannot supply an unqualified
drain deadline. Retain tail clip ownership until actual retirement or a fenced
terminal cut.

Bank-only menu startup must still ensure the single chosen output before taking
bank state locks. Device mix uses audio-system lock -> native render -> PCM state
(released) -> bank state -> atomic host gains. No callback acquires provider
lifecycle, command-serialization or budget-allocation locks. Asset read/decode
stays on producers; callback diagnostics remain bounded, with no file/console I/O.

## Concrete whole-session asset budget

The frozen standalone core bounds each raw part, decoded payload and active
Submission slots, but callers can retain arbitrarily many PreparedBank outputs.
That is explicitly unqualified for runtime integration. A runtime adapter must
not publish those uncapped shared outputs as its public asset API.

Use a session-owned bounded AssetRegistry with generation-qualified opaque
handles. A handle identifies an entry and session identity, not a guest address
or content hash. Count all installed, prepared, in-progress and unreclaimed asset
entries against a declared finite count. Retire/reuse entries only after their
actual outstanding ownership has ended; reset invalidates handles but does not
refund memory that remains alive.

Define separate finite budget terms:

| Charge | Release point |
| --- | --- |
| Captured packet and HD/BD/TQ staging buffers | Actual producer-side buffer destruction after parse/prepare/cancel. |
| Prepared/installed raw Bank storage and metadata | Actual allocator deallocation after the last owning asset is released on control side. |
| Decoded PCM and its shared ownership/container storage | Final decoded-clip/control-block reclamation, including voices and render-retire queues that outlive the original Bank object. |
| Temporary decode/cache construction and replacement peak | Actual temporary release; cannot borrow anticipated savings from the still-installed old bank. |
| Fixed session scratch/slots/retirement tables | Reserved at construction and reported separately from asset budget. |

14 ports is not a14-asset memory bound: staged replacements, external prepared
handles and old sounding/retired clips add ownership. Likewise the source8MiB
decoded limit counts logical PCM **size**, not vector capacity or map/control
allocation overhead. Do not label that sum an exact physical-memory budget.

Recommended enforceable implementation after DSP comparison: use a shared
counting memory domain/allocator for captured buffers and every prepared Bank/
decoded/container allocation. Atomically reserve bytes and an asset slot before
the relevant allocation; refuse if either finite limit would be exceeded.
Allocation failures unwind on producers with typed status. Charge actual requested
allocation sizes, including container capacities/metadata/control blocks; report
this as allocator-accounted memory, not process RSS or OS commitment.

The allocator domain must outlive old decoded clips, not merely their parent Bank.
Use retained allocator/domain ownership in asset and decoded shared allocations,
or an equivalent explicit budget lease on each retained clip. Refunding a whole
Bank when its port is replaced while voices still hold PCM would undercount live
memory. No refund occurs just because a reset invalidated an opaque handle.

The current source-derived containers use ordinary allocators, so a wrapper that
only reserves `raw sizes+8MiB` cannot enforce this complete allocation budget.
Allocator parameterization/usage reporting is a necessary future change with a
new identity freeze and independent source comparison. Preserve scheduler/DSP
order while making that ownership change; do not mutate the present frozen core
in anticipation of expected results.

Budgeted last releases must follow the existing core's control-side reclamation
rule. Current-cache voice releases are safe only while the owning immutable cache
remains strongly held under bank state serialization; old clip leases move into
bounded retirement storage. Asset replacement and retire collection happen in
one lock transaction, then final destruction and allocator refund occur after
unlock on producer/control side. Never acquire a global budget mutex or destroy a
last asset/clip from device mix. External opaque-handle drops should be cheap
generation/registry operations; actual resource reclamation is scheduled on the
same control path.

For0x4E already-loaded skip, do not reserve/read/prepare unused assets. For a real
load, admit its old+new peak before capture/decode/install effects. Prefix commands
already applied earlier in the packet are not rolled back by budget refusal.
Do not infer a packet limit from the diagnostic8KiB dump cap: source packet range
admission is the remaining32MiB RAM window. Any smaller native packet/capture
limit is a declared candidate restriction requiring actual-profile evidence.

No numeric runtime budget is proven by current playtest silence or by a default
port count. Select and publish count/byte/peak limits only after observed owned
asset usage plus source worst-case accounting fit them. Failure to establish the
declared profile refuses installation before publication. Runtime budget pressure
returns a typed load refusal with old asset/prefix semantics and diagnostics;
after ownership publication it cannot retry against global legacy banks.

## Refusal and fallback contract

| Condition | Disposition |
| --- | --- |
| Unrecognized sound SID/RPC | Not covered before selection/read; existing other RPC service may handle it. |
| Native registration incomplete, wrong runtime/build, budget construction failure | Refuse before publication; legacy is available only if no native owner/output/effects were exposed. |
| Publication lost after worker registration | Preserve inert worker, no native callback/device activity; existing selection wins. |
| Invalid/malformed packet, bad asset or expected budget pressure after native publication | Owned failure with source-compatible prefix/old-bank behavior, explicit diagnostic/wire mapping; no legacy retry. |
| Stale reset epoch or foreign runtime/session | Owned rejection before install/reset side effects; no pointer-cookie adoption of another session. |
| Gain/numeric domain or retirement invariant failure | Explicit fault policy, closed admission where required and bounded callback-safe diagnostics; no guessed recovery. |
| Provider fence failure | Keep resources and return not-joined for control retry; never free them because a timeout elapsed. |

The existing HD-only FNV fingerprint remains mixer routing data. It is not a
BankAsset content identity, runtime identity or memory-budget ownership token.
Master/category levels and CRI route atomics remain host controls with their own
retained lifetime; bank reset cannot clear unrelated routes/levels.

## Required review gates before a patch

1. Finish independent full-source bank DSP/state/gain-order comparison against the
   frozen candidate, with deliberate diagnostic/lifetime-policy differences
   separated from parity findings.
2. Implement/qualify bounded packet adapter and allocator-accounted asset registry
   without modifying source packet prefix/conditional-load semantics silently.
3. Patch the entire facade and recognized sound-RPC/adoption/reset path into one
   versioned owner selection; verify no private global bank caller remains live
   while native mode is selected.
4. Test paused capture/decode/adoption versus stop/reset/publication and provider
   teardown. Include accepted render paused between CRI and bank stages, every
   query/reset caller, closed-call wire handling and old decoded clips surviving
   replacement under an exhausted budget.
5. Fresh full dependency reapplication and matching library/game rebuild, then
   controlled actual bank-only/mixed audio and shutdown retest. Isolated corpus
   agreement and allocation guards do not substitute for these integration checks.

Remaining outside this ownership cut: guest sound command construction, source
asset coherence during capture, generic SIF semaphore/client completion, the
synthetic sound-status IOP arena/backfill/DMA bridge, and the separate LIBSD/audio
backend path. Complete BankSession ownership must not be reported as complete
native ownership of those guest protocols or every audio device voice.
