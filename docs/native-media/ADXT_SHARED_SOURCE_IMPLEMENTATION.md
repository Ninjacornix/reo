# Source2 implementation and original qualification

Status: isolated shared-source owner, 2026-11-06. No Window2 implementation,
runtime adapter, device operation, gameplay test, source replacement or default
enable is claimed. Frozen Source1/Header1/Window1 and existing workers/kernels
were not edited.

The approved [contract](ADXT_SHARED_SOURCE_CONTRACT.md) is implemented in
`game/native/adxt_shared_source/shared_source.{hpp,cpp}`. It owns one8192+36-byte
SJRB ring, one retained producer and a single move-only batch with one or two
ordered consumer grants. It reuses the frozen Source1 Backend interface and
actual AsyncReadOwner/SerialWorker implementation.

## Source identity and chronology

The native owner was authored **after** historical shared39/refill original
observations. After initial meaningful unit qualification it was frozen before
the new Source-only expected corpus or comparator. No blind-authoring claim is
made. All new files use LF bytes.

| Artifact | SHA256 |
| --- | --- |
| `shared_source.hpp` | `cf6b8b7cbc2dff1f619e8f242332cf109ebbad1c810c463f7a3e068967fcf6a9` |
| `shared_source.cpp` | `6327fff621f01afb59506290bf710953f0423b20e46aea58ed2ff99439b55a21` |
| `frozen_identity.json` | `a1eb49209edf71ee13911f556a67be18ae271f658949e2335f33c64fb819f631` |
| Inputs-only C++ transport | `878a1d98d5530f5edad21983bea381581ace41fd906e79c04824427ba9ce695f` |
| Comparator | `8730a447a7f61b85882b479d6dcf84024ee43ca52351a2a172a6566df6b17038` |

The frozen identity also pins the unchanged SJRB, Source1 backend, resource I/O,
resource session and worker source/header dependencies. Its `unit_inputs` and
receipts preserve the pre-comparator test cohort; later comparison files do not
rewrite that history.

## Public service is lifecycle plus refill

`SharedEncodedSource::service()` implements the complete original
**130B78→130800** lifecycle/refill boundary, including deferred stop/close and
service-request flags. It is not a raw130800-only entry point.

The first new original cohort deliberately exposed a mismatch in this boundary.
`oracle/v2` executed raw130800; after a request it preserved source `+43=1`,
whereas the established complete owner service cleared it to0. The first
comparison correctly failed on `state.source[7]:0/1`. The frozen native core was
not changed and the field was not omitted or normalized.

The corrected new input cohort explicitly names130B78 for every service action,
before its original expected replay. Real130800 and its file-target callback
still execute within that wrapper. Historical raw evidence and the first failed
receipt remain:

- `build-native-sjuni/adxt-shared-source-oracle/v2/expected.json`, SHA256
  `aab2da951dea1a66ffebb2a17bcd9a1799f5cbcdfa7050c44022a5e2623471e3`.
- That directory retains exact `oracle-source.py`, SHA256
  `516ac1d92e3882814b92d86a064e698b2e85ac0a67969379aa2a39e0655f8914`.
- `build-native-sjuni/adxt-shared-source-parity/gcc-v1` retains its failed receipt,
  runner binary, observations and exact then-authored comparator/transport files.

Window2 must use the complete public lifecycle contract. A raw-refill-only
integration would require a separately reviewed API/cohort.

## Owned credit and loop behavior

ReadBatch exposes only count/offset/bytes and bounded reads. It retains a fixed
LeaseDomain and actual Chunk storage, rather than the whole provider owner.
Dropping or moving a token never returns credit or joins a worker. Closed/stale
identity refuses reads; outstanding storage remains real and strongly retained.
The enclosing pipeline must keep the Source control owner alive until explicit
drain/fence. A lost token keeps that owner's ledger busy.

All four finish plans preflight identity, counts, complete ordered positive
Unget position equations and conservation before the first actual disposition.
Zero grants use the real Ring's immediate no-op semantics. After each actual
step, the real Ring snapshot must match the preflight postcondition; a
`Ring.completed` result alone is insufficient. The original Ring can diagnose
an Unget-position mismatch while still returning completed.

Stable accounting includes data+free+producer-remaining+consumer0+consumer1.
Producer reservation and remaining credit are separate: the original descriptor
can remain present through publication microstates while a known prefix is
already published. Fixed transfer metadata distinguishes those microstates.
Unexpected post-effect failure retires only known completed transfers, retains
remaining ledger, disables unsafe batch reads and faults further admission.
No whole-plan replay, automatic destructor return or ring reset follows it.

Canonical LoopControl owns current loop geometry and decoder sample limit. A
single private WindowLink is reserved for
`reo::native::adx_window::v2::StreamWindowOwner`; no generic user mutator or Ring
escape is provided. Its configuration is permitted between serialized source
operations, including while a producer is pending, and refused during source
reentry.

The internal file-loop action runs after accepted-prefix publication/progress
and reservation clearing, before later terminal decisions. Enabled looping
sets only clamped floor(start-byte/2048) file progress. Disabled looping writes
canonical sample limit-1, then source target`INT32_MAX`. Cumulative accepted
bytes, queued encoded bytes, consumer grants and predictor state remain intact.
A read-only target observation can also exist with no typed mutation action.
Observers cannot mutate the serialized owner or choose dispositions.

The current geometry is used at the eventual publication boundary, including a
typed admitted geometry update while I/O is pending. It is not an arm-time copy.
Configured keys and saved loop history remain Window2 responsibilities.

## New independently authored original corpus

The new `tools/native_reconstruction/adxt_shared_source_oracle.py` writes and
freezes independently authored API client inputs before original replay. It
does not import or run native Source2 code. Consumer requests/disposition plans
are authored commands, not counts extracted from shared39 expected results.

The final cohort is `build-native-sjuni/adxt-shared-source-oracle/v3`:

| Artifact | SHA256 |
| --- | --- |
| `inputs.json` | `eb358b57da388fcfe54bc0e233c80d64c5cec50223e21dbf5153c685da6da9cd` |
| `input-manifest.json` | `8598ffc6894c960be7cc93000821b6b1b252f2007fd6e589de8f4bcb082e8b23` |
| `expected.json` | `f6ab00eb1f0f88ad35fb3215e826d2f59471e70e4f240289d9f1c05f3a3c6446` |
| Oracle support source | `b53af19a63a7f5f8f7627f025b16fa5de82c1d6bb6cae08ea3efb61bf5546021` |

Authority is owned File1 ELF SHA256
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
The unchanged original ISA/ring/refill engines execute complete actual130B78,
130800, SJRB Get/split/Put/Unget,133AB8 and1305C0 bodies. Function bytes are
checked against the existing163-body identity set; loading all those bodies is
not a claim that all are reached in these Source-only clients.

The30 complete clients produce133 stable observations, execute12,570 original
operation instructions plus14,958 setup instructions, record238 actual Ring
guard events and10 target boundaries. One hundred independent published-view
proofs execute200 actual original SJRB Get/Unget calls on cloned state, totaling
9,228 additional instructions and verifying restored credit. Expected grants
are never calculated by a native ring algorithm.

Coverage includes all four finish plans; two positive/zero/mixed grants; pending
full, partial and error producers with two consumers; source wrap/mirror;
read-only target without action; enabled/disabled physical end; pending loop
toggle/current geometry; stop/close/pause; zero/declined requests; retry terminal;
and repeated publication preserving cumulative bytes. The physical-end pair
reaches progress2: enabled returns progress0/state2; disabled leaves progress2,
sets limit-1 and then reaches state3. Both retain accepted cumulative2048.

Loop geometry and limit are explicit prepared typed client inputs. No
header-parser, codec, FP coefficient or full ready-configuration result is
substituted or claimed by this Source-only setup.

## Paired native comparison and ownership checks

The C++ runner receives only those authored inputs and immutable file bytes.
It uses actual Source2 APIs, owned result staging, real Batch reads and explicit
finish plans. Expected output never sets a candidate ring/counter/grant. Both
compilers match all133 records,238 Ring guard snapshots,10 target before/after
boundaries, and184,424 observed published/held bytes. The byte total includes
repeated observation; it is not unique stream length or audio played.

The exact earlier authored8192 refill case also matches its independent frozen
Source1 original fixture: three source/ring/read-only-target observations.
The other28 prior cases use2048/4096 capacities and receive explicit new
before-effects unsupported-geometry constructor refusals. They are not counted
as equivalent original behavior or as newly tested pending-reset handling.

Final comparison receipts:

| Compiler | Receipt under `build-native-sjuni/adxt-shared-source-parity` | SHA256 |
| --- | --- | --- |
| GCC15.2 | `gcc-v2/receipt.json` | `789956965d79ae604e7a1b9a085171e20173bd4ebed0866a96bc0a4d8f3e9f3a` |
| Clang21.1.8 | `llvm-v2/receipt.json` | `6db590d1b057f9ebae83d45f4cec914770d2ca5c8d4c45bd8023f7de4bda9496` |

Before the new expected corpus/comparator, both compilers passed239 meaningful
ownership assertions plus10 deterministic post-effect fault assertions. A
private variant removing the error check fails those same fault assertions.
Checks include invalid-last-plan zero effects, zero no-op credit, move/foreign/
lost/closed tokens, actual Ring.completed mismatch evidence, ID/admission bounds,
canonical target timing, and source owner metadata allocation denial with a
pre-staged backend.

The real unchanged AsyncReadOwner is tested with a deterministically blocked
ByteView. Stop/close returns without waiting or suppressing accepted publication,
two positive consumers coexist with the producer, actual success/error retires
the producer correctly, and real provider join releases the retained view only
after consumers return. These are real host provider/lifetime checks, not an
original filesystem cancellation-equivalence claim.

Unit receipts under `build-native-sjuni/adxt-shared-source`:
GCC`gcc-v4/receipt.json` SHA256
`d950af366809919adece6c89bfe30a46313eb5c2d1c44dd48f77dbb1a9464265`;
LLVM`llvm-v4/receipt.json`
`a91299b7bb0a00f116252c6d99c4d77631c0c7345a0fb594f37a81444c7801b9`.
Eight original-evidence unittest checks also pass. All frozen core/dependency
and comparison-source postchecks remain empty.

The standalone GCC Release CMake/Ninja project builds and CTest passes1/1;
receipt `build-native-sjuni/adxt-shared-source/cmake-gcc-v2/receipt.json`, SHA256
`772dd8b026a1178bc7616a049c56e2d5eeff30058afac454000a82d8c2060e96`.
This is the isolated component build, not a game/dependency runtime build.

The parent `game/native` Release projects also build the unchanged owner and
pass the selected `adxt_shared_source_owner` test with GCC15.2 and the bundled
UCRT LLVM21.1.8. Source2 and the separate raw integer clock bring that project
to30 standalone suites. These counts do not measure full-player migration.

Owner metadata/copy/disposition paths do not allocate after construction.
The unchanged backend still has its own bounded submission/result/exact-read
allocations and explicit failure policy; the owner does not claim those are
allocation-free or that completed-result destruction never frees memory on the
control thread. No audio-callback thread placement is admitted here.

## Remaining composition gates

The historical shared39 full header/ready/decode/loop/seamless transactions
remain **future Window2** proof. Their original observed consumer prefixes were
not smuggled into this inputs-only Source2 comparison. Larger/smaller source
geometry, wrapped/unbounded counters, partial final sectors, SJMEM mode2,
filename/LSC replacement, RNA/DTR/device credit, scheduler clocks and real game
asset shape remain outside this qualification.

Window2 must stage actual shared grants into preallocated workspace, use
post-loop key/history/input, preserve the two physical span boundaries, and
perform concrete original-order first/repeat/seamless transitions. The private
link can mirror admitted partial/deferred header geometry before credit-return
observations. If a partially changed header has invalid geometry, leaving the
old target action running would be wrong: that pending-source fault/retirement
policy needs review before admission. Current Source2 has no generic external
fault/action-poison callback, and does not claim to close that Window2 domain.

There is no live reset/replacement API. Stop is not join; terminal finalization
requires no accepted request, producer credit, active batch, ledger fault or
enclosing operation. An unexpected lying backend retains credit and cannot be
declared retired from a status guess. Emergency control-thread teardown and
actual backend fence are separately labeled policy, never storage reuse or
original fallback after effects.
