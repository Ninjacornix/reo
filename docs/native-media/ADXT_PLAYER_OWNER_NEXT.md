# Remaining ADXT player ownership

Status: owned File #1 static investigation, 2026-11-06. This inventory adds no
game run, device observation or instruction replay. The tag0 window already has
separate original-word and typed-core qualification; it is not a complete ADXT
player. Addresses and layout offsets below are hexadecimal; counts in prose are
decimal unless prefixed `0x`.

The smallest next complete owner is **one encoded-file refill reservation and
its later accepted-prefix publication**, including stop/reset/lifetime evidence.
It must share the actual encoded ring with the decoder. Header initialization,
mutating loop callbacks, time authority and output credits remain separate
closures, rather than effects to hide inside a codec callback.

## Evidence and existing qualification

The executable authority is `game_data/SLUS_207.65`, SHA-256
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
Function boundaries come from `recomp/config/outbreak_ghidra_functions.csv`.
The inspected generated audit companion is
`build-native-sjuni/candidate-work-v6/project/recomp/config/output`; its
instruction comments were checked against ELF words, not treated as a substitute
for executable identity or a required production source layout.

This pass audited 14 complete bodies: 1,707 unique commented words and 42 omitted
zero words, with no omitted nonzero word. The most useful full-body identities
are below (exclusive end). This is static matching, not execution coverage.

| Interval | SHA-256 |
| --- | --- |
| `130800..130B78` refill | `6cfad8d4401354f40242f504a2ac458bd57dd07871097a8f2b4c1ff60c137bc4` |
| `130B78..130D44` file lifecycle service | `2ee7db321ad02af1eb0bf4187b827490cda2b2a8d39b7fe6465cd6f3d437c347` |
| `1249E8..124CD4` tag0 header | `abd26f34e1ee76095d22edc9b9343598ad81058013d7d2761d6e1a897250b982` |
| `12CCE0..12CEB8` outer header admission | `3027230bd9bdc3f8478350ce97813f064a4c36da9006bcea571457c9f34cea7d` |
| `133FE0..1343B8` ready/header configuration | `f9941b835b679c4b519c42abc05d1d83674bb0c9899242d5277110bc48ca87da` |
| `132C08..132CD8` guarded owner scan | `43db19323e027bbf709017798f6c8c374ecd387009f8cef9d87e5b273693da9e` |
| `134C58..134D1C` ADXT state dispatcher | `0673986478c825d7b8c00b3293bb693a95ad2a0dbee8043f018cdc03901a92b6` |
| `132160..132454` estimated position | `0cc14f50f6d6a355d7ae5240bcbfb6252e43bb6cc138ece27b0e718c82e41648` |
| `138650..1389CC` DTR queue transfer | `d45d830741d0e8a0e0c4eb2bc9c268fb45666c67b006438525992c7f120c86ab` |
| `13EEE8..13EF58` RNA service | `587707490c36f3fd597837097dbe2b57689db681b1238844ffaf6a8d3caabc90` |

Reuse [SJRB original/core qualification](SJRB_ORACLE.md),
[window original qualification](ADX_WINDOW_ORACLE.md), and
[typed window limits](ADX_WINDOW_IMPLEMENTATION.md). The current native window
owns private rings, stages real codec output before its first observable borrow,
and admits read-only callbacks. This is valuable proof for that domain, not
proof of the shared asynchronous source lifecycle below.

## Owner graph and ordering

| Boundary | Actual source relationships and remaining contract |
| --- | --- |
| Construction | `1315E0` creates an ADXT record with ADXB `+4`, file `+8`, RNA `+C`, original/current input `+10/+14`, PCM rings `+18[]`, LSC `+94`. PCM capacity is **16,384 bytes/channel**, extension **192 bytes**, physical `0x40C0`; the constructor first stores halfword geometry then shifts it to bytes for SJRB. Encoded capacity is sector-rounded, extension 36 bytes. Its unchecked channel/effective-workarea cases need explicit native admission. |
| Start/header | `131C50` configures file range, requests stop/close/open/start, then `131B60` resets PCM queues and starts ADXB header state. `12D638→12CCE0→124CD8→1249E8` admits tag0 header from a real data borrow and returns consumed prefix/unread suffix. Short/unsupported headers may already have selective field effects; generic transactional rollback is not original behavior. |
| Decode/publication | `12D590→12CFD8→125698`, real reserve `12CEB8`, budget `125370`, predictor `135078`, result/wrap `125518`, then `12D338` publishes encoded and PCM prefixes and acknowledges. This is the qualified window, subject to its narrower limits. |
| Source/refill | `130B78→130800`: open/lifecycle gating, a free-ring borrow, seek/read request, outstanding reservation, and later status-driven publication. It is not a synchronous copy into an unrelated ring. |
| ADXT control | Guarded `132C08` first scans ADXB via `12D678`, then sixteen active ADXT records through `134C58`, then `12C798→13EEE8` RNA service. `134C58`: state1→`133FE0`, 2→`1343B8`, 3→`134530`, 4→`1345F0`, 5→`1347F8`, then always `134BC0` and `134B40`. |
| Output | PCM SJRB→`138650` DTR→paired local SJUNI→SJX/DTX→SJRMT/IOP→selected PCM sink. Queue transfer, credit return and audible playback are separate events. |
| Stop/destroy | `131E38` coordinates file/LSC and stop callback, then `131D98` stops desired audio/decoder state; only memory-source mode2 destroys current input. `131918` destroys distinct children and file lifecycle waits. Per-stream stop must not reset the shared PCM/bank session. |

`132CD8` is a tail facade to `132C08`, not a tick increment. Direct resident
callers of `132C08` are `12A130`, `12A1A8`, `12C078`, `12C138`, `132CD8`,
`133058`. `12A178` orders audio, file, then LSC service; this does not establish
one call per game frame. Tick `20F3C4` increments in `12A130` and `12BDB8`.

## Integration blockers that must remain visible

1. **Request and total bounds.** Initializer `12A1E8` calls `1328A8(60)`;
   constructor copies global `21B758` to `+38`. `133FE0` derives request size
   from frequency `R`, divisor `D`, and block samples `B`: no loop uses
   `trunc(3*trunc(R/D)/2)`, loop uses `3*trunc(R/D)`, then source rounding
   `trunc((request+2B)/(2B))*(2B)`. A source-derived example `R=44100,D=60,B=32`
   yields **1152 samples without loop, 2240 with loop**, beyond the frozen
   native window maximum **256**. Ordinary header totals can exceed its
   **4096** total-sample limit. These are static examples, not observed requests.
   Expand and qualify the complete accounting/storage domain before integration;
   clipping requests or resetting every 4096 samples changes semantics.
2. **An outstanding free grant is legitimate.** `130800` keeps an encoded-ring
   free span while decoder consumers can use existing data. Therefore
   `data+free<capacity` is valid. Native window's current exclusive-ring
   conservation admission and `feed_encoded` copy API do not represent this
   state. A unified source owner or explicitly qualified retained write-lease
   ledger is required; a second ring is not equivalent.
3. **Loop callbacks mutate decoder state before admission.** `133FE0` installs
   `133870→133928`, or seamless `133D10`, via `12D738`. They can change limits,
   counters, input and key/history from inside `12CFD8`. Current native window
   stages decode before its read-only limit callback. Binding these callbacks
   directly violates that contract. Close owned loop transitions and staging
   together before admitting them.

## Header, loop and drain closures

Header children `126798/126918/126898/126990/126AC8/126D28` cover base,
version/control, filter, history, loop and extension/AINF. `1250A0` selects key
material; `124558` uses original table `239360..239B60` (1024 halfwords), SHA
`eb7433da1be18cc81b0523fafbf76266e10b915311bff270bba75090103a3740`.
`134F28` key and `134ED8` history are distinct from `134EB0→126510`
coefficient generation, including actual cosine `1223D0` and math fallback
`122708`. The integer oracle does not qualify EE floating-point conversion,
sqrt/trig/exception behavior. Supplied coefficients cannot prove full header
initialization. See [header mapping](../SYMBOLS_ADXT_HEADER_LOOP_AND_DRAIN_TRANSITIONS.md).

`133870` snapshots history/key via `12DA38→124F70`, resets accounting and
installs `133928`. That callback consumes padding; memory mode resets SJMEM and
consumes a start prefix; `12DA50→124FB0` restores saved history/key. File rewind
`133AB8→1305C0` is separate. Seamless `133D10` can consume multiple spans while
finding the next aligned `8000` header after `8001`; failure does not roll back
already consumed bytes. LSC `13D9B8` reloads queue head between poll/retire/start;
repeat callbacks may mutate it and filenames remain borrowed. See
[LSC lifetime](../SYMBOLS_LSC_INSTANCE_LIFETIME_AND_QUEUE_SERVICE.md).

`1343B8` starts buffered output using PCM occupancy/free/decoder-ended tests;
inhibit `+70`, started `+71` and paused `+72` differ. `134530` enters drain when
all queues have less than 64 bytes. `1345F0` publishes silence with minimum
channel grants but terminates using maximum remaining PCM plus RNA occupancy
minus `+A8`. This is not DAC completion. `1348F0` has recovery logic, but this
pass found no resident direct caller, literal function pointer or short
LUI/ADDIU/ORI construction; that does not prove it unreachable. It is **not** a
direct edge of the complete `134C58` dispatcher.

## Clock and output-credit authority

`132028` combines decoded count, RNA occupancy, output queue halfwords, `+A4`
and base `+88`; terminal state uses header total/depth. `132160` selects raw or
tick-based estimated position, rebases after ±60ms drift, and can publish the
old estimate on the rebasing call. Pause `132E50` and discard/service `133058`
change timing authority. Float/NaN/high unsigned paths need their own oracle.
`131F60→12C718→13ECA0` returns a fixed 0/48000 clock pair, not measured DAC
position. Movie `165778→165B08`, clock slot `165B48`, and `165C08` combine
ADXT position with external timing through `177EB0`. The qualified native
`16F338` position publisher does not replace these authorities. See
[clock mapping](../SYMBOLS_ADXT_SAMPLE_POSITION_AND_ESTIMATED_CLOCK.md) and
[movie boundary](MOVIE_CLOCK_NATIVE_BOUNDARY.md).

`138650` retains source and target chunks until transfer completion, in
64-byte units. `139198` accepts DTX completion only after a strictly newer signed
sequence; payload copy is not credit retirement. SJX EE completion does not
itself check the descriptor generation. Stop waits have no local timeout.
Original accounting quirks must be preserved or separately changed with proof.
The owned IOP server is available and mapped: `DRIVE.DAT` member9
SHA `456f07cb55a5bed66643fd95ca6ef64874265b578630b905a9328346e01aefb7`,
module-relative addresses. Its `20..2A` handlers are distinct from EE `400+`
wire operation numbers. Do not repeat older unresolved-remote-server claims.
See [IOP contract](../SYMBOLS_CRI_SJRMT_OWNED_IOP_SERVER_CONTRACTS.md).

Existing native PCM ownership and source-watermark qualification can be reused,
but original pending replies/raw handle incarnations and whole-SJ reply identity
remain explicit protocol obligations. Accepted payload and consumed source-byte
credits must not be collapsed into one counter.

## Next controlled oracle: encoded refill

Execute complete `130800` plus actual SJRB get/put/unget/count/split words,
with prepared bounded already-open file records. Execute available control
helpers and lifecycle service rather than simulating ring or stop state.
Only cvFs I/O, guard and observation boundaries may be scripted externally;
record exact accepted sectors, destination, status progression and physical
writes. Freeze the input transcript before collecting expected observations.

Test partial/zero/negative acceptance, pending and error statuses, wrap/suffix,
backpressure, zero-sector requests, target callbacks, pause/stop while pending,
and reset/reuse with a late external write. `ReqRd` return is the published
prefix authority, not an invented actual-byte result. Even a synchronous provider
requires a later service pass to publish. Reset `130620` is not cancellation:
it can clear reservation fields without returning them or joining an external
writer. A synthetic late-write transcript may demonstrate that ordering; it
cannot establish a real provider fence or a new original generation mechanism.

The future typed owner must retain storage through accepted I/O and a proven
provider completion/stop fence, then publish or suppress according to its
separately specified incarnation policy. Resource `AsyncReadOwner` already owns
results/views, but its cancel does not abort an active read and does not close
the original ADXF/SJ reservation contract. Header/refill/loop/clock/RNA coverage
remains incomplete until the controlled cases above and their separate native
contracts are qualified.
