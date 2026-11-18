# Native bank session implementation

Status: implemented isolated core in
[game/native/audio_banks](../../game/native/audio_banks/session.hpp), followed by
the allocator-budgeted v2 pilot described below. Both pass independent full-source
regression comparisons. Standalone CMake checks are integrated; no game dependency,
bootstrap, preparer or existing PCM wiring changed, and no backend installation,
device/game run or performance claim is made. The initial core was frozen before
viewing original expected observations; v2's later allocation-policy changes
explicitly record that those observations had already been seen.

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

The independent original comparison subsequently passed with both compilers,
without changing any of the seven frozen candidate files. The separately
authored qualified124 source oracle covers18 cases/252 actions. Comparison is
exact for13,004 rendered float words,12,768 gain-call records, request/voice/
envelope/frame-clock state, all observed sample metadata, clip ownership IDs and
parser/load/query results. This admits the exercised standalone domain; it does
not prove every possible bank or packet.

`compare_original.py` verifies all candidate and oracle identities before reading
expected observations. It reuses the original binary input reader and JSON
observer formatting. `native_transport.hpp` translates the original raw packet
inputs into public typed Session calls outside the core; Session owns all bank
loads, commands and renders. A test-only access-control shim reads State for the
observer, with all candidate source included in one translation unit to avoid
differing class declarations across translation units. No expected value drives
DSP, mutation, ordering or normalization. Low-level parser/VAG/TQ probes invoke
the candidate's unchanged source-derived utility classes.

The source's unsupported-report counts match, but original observation does not
include diagnostic-kind events. The transport maps packet-opcode/load-id reports
to typed `global_control`, so event-kind parity is expressly not admitted. Its
packet parser also preserves an accepted invalid-port0x4C as a no-op without a
report; invalid-port0x47–0x4A instead report globally. Gain-domain errors, lifecycle
and budget policies continue to be independent native contracts tested above.

Receipts are
`build-native-sjuni/audio-bank-original-comparison/{gcc,llvm}/receipt.json`,
SHA256 `b0764f73f6bda487a9616af4adbb7e83eb1dad36ab93c41558a3e61a32ca81c0`
and `7b9d31fdc60affbc0fbc5dc00a4cfcc6a302a6cad7bfe474881536151820912f`.
Both have zero differences and empty postcheck changes. Reproduce:

```powershell
python game/native/audio_banks/compare_original.py `
  --cxx C:/msys64/mingw64/bin/g++.exe `
  --output build-native-sjuni/audio-bank-original-comparison/gcc
```

The complete bank RPC/queries/reset facade, runtime/session identity,
selected-owner registration, whole-session prepared-asset budget, guest asset
capture and actual provider shutdown remain to be integrated and rebuilt
coherently. These isolated checks establish neither those boundaries nor faster
gameplay. No game or audio device was run for these comparisons.

## Allocator-accounted v2 pilot

`game/native/audio_banks/v2` is a separately identified, isolated allocation and
admission cohort. The original v1 implementation, `frozen_identity.json`, unit
freeze and comparator remain unchanged; their committed baseline is
`384a0cb036a34ca3578376b036d143902332412a`. Original expected observations were
already available when v2 was implemented. Its comparison is a regression check,
not a second blind implementation claim. Nothing selects v2 in the runtime.

`derive.py` mechanically derives the four v2 algorithm/session files from the
seven checked v1 hashes. It changes namespace, asset container allocators,
shared allocation, capture/preparation admission and resource-preserving decoded
buffer clearing. The numerical source expressions, event/request order and
shared scheduler/mix include files remain unchanged. The generator refuses a
changed baseline or an unexpected substitution count; v2 verification refuses
generated-file drift. Upstream attribution and GPLv3 license remain those in the
parent directory.

The session now exposes `capture(submission, BankSizes)` before any internal raw
buffer allocation. It acquires an asset-count admission, then allocates writable
HD/BD/TQ staging buffers through the session asset allocator. An adapter fills the
returned spans while retaining its complete Submission, then moves the capture
into `prepare`. Caller-created unaccounted vectors cannot be passed to this API.
The spans are borrowed until their capture is moved/destroyed; capture does not
establish guest-memory identity, coherence or an asynchronous borrow lease.

Config defaults are64MiB of asset allocation requests and128 asset admissions.
They are explicit pilot limits, not observed game requirements. Each source part
retains the original2MiB guard. Exceeding either budget returns `capacity`; source
allocation failure returns `no_memory`. Neither result installs anything or
falls back to the legacy owner. Invalid format, foreign owner and stale epochs
retain explicit errors. Reset/stop cannot publish a late capture/preparation.

The byte domain includes:

- Writable staging vectors, the temporary header and Bank-owned HD/BD/TQ vector
  capacities, including overlapping old/new buffers during reallocation.
- Decoded PCM vector capacities, cache map nodes/buckets and their metadata.
- AssetData, DecodedSample and asset-admission `allocate_shared` control-block
  requests, including contained objects, allocator state and ABI padding.
- Unsuccessful/transient preparations, caller-retained PreparedBank aliases and
  decoded clips retained by old voices, retirement storage or weak observers.

These are the actual `n * sizeof(rebound allocation type)` requests made by
containers/control blocks, reserved under one session budget before the owned
upstream allocator is called. They are not estimates from raw sizes or logical
PCM length. In-flight reservations stay charged until allocation fails or is
freed. Both byte and count checks are shared across concurrent preparations.
The upstream heap's hidden bookkeeping/fragmentation is outside this requested
byte measure. Fixed bounded scheduler workspace, Session/Budget administration,
caller-owned input storage and test-observer output are separate domains; this
is not a cap on total process resident memory.

Every asset allocator itself retains strong Budget and asset-admission owners.
Its rebound shared-control-block allocator therefore remains valid after the
containing object is destroyed. The upstream allocation source also has a
strong owner. Asset count is refunded by the final admission control-block's
deallocator after its upstream free returns, rather than by its object
destructor. This covers weak-control-block retention and the final free's
in-flight interval. No TLS/global allocator replacement is used. Custom
AllocationSource implementations are control-side providers and must honor the
symmetric aligned allocation/deallocation contract.

The existing fixed48-entry retirement path remains responsible for callback
last-free avoidance. Current-bank caches retain current clips; old clips move
to retirement storage and release on control drain. Reset, join and replacement
release collected owners outside the data lock. Budget/upstream calls occur on
producer/control paths; normal mix does not acquire the budget lock or allocate
or deallocate asset storage. Refusal before install preserves the previous bank.
Fixed scheduler allocation bounds remain those of v1.

V2 unit checks compile with warnings as errors on GCC15.2 and Clang21.1.8 and
pass218 assertions. They exercise measured exact/one-byte-under capture and
preparation limits, refusal before upstream allocation, every preparation
allocation failing in turn, complete refunds, retained captures/assets, reset
against genuinely paused capture/preparation, concurrent count/byte admission,
old-voice callback retirement, and strong resource lifetime through final weak
control-block destruction. A paused final upstream free confirms count cannot
be reused early. Asset-allocation guards observe no callback allocate/free;
the unchanged v1 scheduler was independently checked with whole-allocation
guards before this cohort.

Both compiler regressions then matched the frozen original corpus exactly:
18cases/252actions,13,004 float words and12,768 gain-call records, plus the
complete observed metadata/clip/request/voice/envelope/clock/query state. Both
unit and regression receipts have empty source postcheck changes. This supports
the exercised DSP domain after the new allocation policy; budget refusal cases
are independent native-policy checks, not claimed original behavior.

Receipts are under
`build-native-sjuni/audio-bank-budget-v2/{gcc-unit,llvm-unit,gcc-original,llvm-original}`.
Reproduce with the analogous bundled LLVM path or:

```powershell
python game/native/audio_banks/v2/verify.py `
  --cxx C:/msys64/mingw64/bin/g++.exe `
  --output build-native-sjuni/audio-bank-budget-v2/gcc-unit
python game/native/audio_banks/v2/compare_original.py `
  --cxx C:/msys64/mingw64/bin/g++.exe `
  --output build-native-sjuni/audio-bank-budget-v2/gcc-original
```

This closes the standalone Session's externally retained prepared-asset budget
gap. Whole-call RPC/asset capture identity, aggregate bank/PCM selection and
shutdown admission remain separate integration work. Packet capture and adapter
queues must acquire their own declared bounded storage before allocation; they
cannot be assumed covered merely because a later bank capture is charged.

### LF cohort normalization

Commit `89f8acadb3c72506889c3c667b9a75bcd1ac38f3` stored the generated v2
algorithms/session files and synthetic fixture helper with LF endings, while the
original private `cf5e4299...` cohort had Windows CRLF bytes. The C++/fixture
differences were solely line endings; all seven historical v1 frozen files
already matched their committed LF bytes and remain unchanged.

The separately issued `budget-v2-lf-1` identity is
`77b6c1bc20f6c1ea261ea19df9bcde3a5fa516c94e7b2c7d8d6503ca0f7aefca`.
Its byte map records old private hashes and committed LF hashes. `derive.py`
now writes deterministic LF bytes, as do generated observer/receipt outputs.
Standalone source identity covers the explicit C++/Python inputs; root-owned
CMake wiring belongs to its separate build cohort. This corrects reproducibility
without a DSP or allocator C++ expression change.

The old private cohort, input sources and four receipts were preserved under
`build-native-sjuni/audio-bank-budget-v2-normalization-20261105/old-cf5e4299`;
the original four test directories were not overwritten. The normalization
audit and `check_cohort()` passed without compilation. After the requested
game-test quiet period ended, fresh LF-cohort checks passed on GCC15.2 and
Clang21.1.8:218 unit assertions each and zero original-regression differences
across252actions/13,004 float words/12,768 gain records. All four postchecks are
empty. Their new directories are `{gcc,llvm}-{unit,original}-lf-1` under the
budget-v2 scratch root; none replaced the original evidence. Receipt SHA256s:

- GCC unit: `048a878472fad6193593b9de21562f64ebcae63e2b799be0670e17f8fcc4cde5`.
- LLVM unit: `b604fa85a10d6aec2489716404a14dcd2e6158fbe3cb6282d620efc4e5fff138`.
- GCC original: `c267c958a7cfb203743f6390fcd5da84128bd738b09e4600868df993d860bde4`.
- LLVM original: `94cfb9cfcd0388f27eff61fe7dbd73f4404f3d1847691866882818566f8b71db`.
