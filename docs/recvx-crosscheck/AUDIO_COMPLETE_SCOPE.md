# Complete CRI audio/core reference scope

Static review, 2026-11-05. Pinned `recvx-decomp` commit
`657b0c0c9489943116c71f151804ad7304fca975`; owned Outbreak File #1 US ELF SHA-256
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
All **375 actual function definitions in the22 assigned function-bearing files**
have a recorded disposition. The additional assigned `adx_qtbl.c` is data-only.
This closes this reference scope, not every function in either game or all
library-version differences. No target, game, codec vector, build, replay,
attachment, live memory, input, audio device or RPC was used.

The machine ledger is
[`build-function-index/recvx-audio-complete-scope.json`](../../build-function-index/recvx-audio-complete-scope.json).
Each function record retains its exact reference path/symbol/start line,
end line, file SHA-256, complete-body SHA-256, implementation shape, calls,
disposition, original Outbreak IDs, complete original-body hashes/word audits,
authoritative note rows and limitations. A related phase or candidate is
identified as such; the ledger does not turn source-name resemblance into
original symbol recovery.

| Reference file stem | Actual definitions |
| --- | ---: |
| adx_amp | 17 |
| adx_baif | 7 |
| adx_bau | 8 |
| adx_bsc | 43 |
| adx_bsps | 4 |
| adx_bwav | 7 |
| adx_crs | 3 |
| adx_dcd | 6 |
| adx_dcd3 | 5 |
| adx_errs | 7 |
| adx_fini | 2 |
| adx_inis | 6 |
| adx_mps2 | 11 |
| adx_rnap | 29 |
| adx_sjd | 47 |
| adx_stmc | 41 |
| adx_tlk | 54 |
| adx_tlk2 | 5 |
| adx_tsvr | 13 |
| adx_xpnd | 15 |
| ps2_rna | 41 |
| rna_crs | 4 |
| **Total** | **375** |

All paths in this table are under `src/cri/mwlib/ee/lib/libadxe/`. Counting uses
the shared balanced definition inventory, including static functions and pointer
return types. There is no inferred twenty-third function file: `adx_qtbl.c`
contains three constant arrays and zero definitions.

## Dispositions and open boundaries

There are **57 already-compared**, **136 newly-compared**, **168
version-different**, **5 no-demonstrated-counterpart**, and **9
source-no-implementation** function records. “Newly compared” means a qualified
static role/body match, not a new mapping, native translation or parity test.
“Version different” records contain concrete context/layout/ABI, admission,
arithmetic, error, lifecycle or call-order differences. They are not168 bugs.
There are no silently unclassified definitions or invented matches for empty
stubs.

The five negative dispositions have bounded searched evidence:

| Reference function | Examined Outbreak evidence and remaining boundary |
| --- | --- |
| `ADXPS2_RestoreVsyncCallback` | CVX installs a GS Vsync callback and saves the previous hook. Outbreak12BDB8/12BEE0 are the service callback/adapter; complete12B638 worker initialization installs other CRI hooks. No matching GS-callback installation entry was established. |
| `ADXSTM_Finish` | CVX calls `cvFsFinish`. Outbreak130100 is return-only; full12A388 shutdown manages dependencies and calls this no-op. No equivalent stream-specific finish operation was demonstrated. |
| `ADXT_SetPauseBuf` | CVX returns16384. The remaining Outbreak ADXT leaves132FE0/FE8 and133010/018/020/028/030/038 are return-only or zero; constructor pause/work fields supply no matching bound API. Adjacency cannot establish identity. |
| `PS2RNA_Flush` | CVX prints and spins permanently. Nearby Outbreak13F150 simply returns; neither a matching diagnostic nor a typed caller/registration identifies it as Flush. |
| `PS2RNA_IsPlySwOff` | CVX combines first-channel occupied<=0 with DTR-stop flag==1. Outbreak13ED28 uses a different deferred-start algorithm;13ECB0 is only the occupied query. No complete equivalent predicate was identified. |

These are scoped search results, not claims that no computed callback, alternate
library build or unowned code can contain such functionality.

Nine complete reference bodies are actually empty:
`ADXPS2_SetupUsvr`, `ADXPS2_Shutdown`, `ADXRNA_ClearBuf`,
`ADXRNA_SetPcmType`, `ADXRNA_SetTotalNumSmpl`, `ADXRNA_SetWavFname`,
`ADXSTM_Reset`, `ADXSTM_EntryErrFunc`, and `adxt_stat_playend`.
Their source declarations do not justify naming one of Outbreak's neighboring
return-only leaves. Separately, RNACRS Init/Finish can be compared with the two
byte-identical Outbreak clear entries13F1F8/13F208 as a pair; admitted callers
still do not distinguish the historical initialization/shutdown name of each.

## Corrections and newly useful contracts

The earlier [audio second pass](AUDIO_SECOND_PASS.md) caught the material
**126AC8 loop-offset mapping error**: original final load126CCC is
`input + loop_base + 0x14`, not `+0x18`. The source pointer trace, exact PCs and
writer correspondence remain in that report and its reproducible receipt.
The corrected version-dependent loop base is a separate quantity:0x20 for
version4,0x14 otherwise. Both reference and Outbreak read the final field at
base+0x14. No parser/writer mismatch follows from the old documentation error.

That pass also corrected125248's fields28..2F to predictor histories and resolved
13EC58/type8 as remote thru queue-discard mode using the owned IOP receiver and
consumer. This complete pass additionally corrects the remaining “desiredaux53”
phrase in [the DTR service note](../SYMBOLS_CRI_DTR_STREAM_DMA_AND_PS2RNA_SERVICE.md):
13ED28 clears the desired **thru/drain** request immediately before starting the
admitted DTR channel. It is not an untyped auxiliary byte or a hardware drain
acknowledgement.

The two [peak-meter accessors](../SYMBOLS_PCM_PEAK_METER_POOL_AND_WINDOW_SERVICE.md)
122E30/122E38 can now be described as **frame-period metadata** instead of an
untyped auxiliary duration. The full17-function ADXAMP family, its constructor,
two duration fields and extraction worker correspond; CVX explicitly names the
matching field `frm_prd` through `ADXAMP_SetFrmPrd`/`GetFrmPrd`. Neither reviewed
worker consumes that field. Its configuration identity is supported; a pacing,
window-size or scheduler effect is not. The actual extraction window multiplier
is the different field24. These are refinements of existing rows, with no new
mapping credit.

Curation also corrected one sentence in the machine ledger:134C58 dispatches only states1..5, then calls134BC0 and134B40. The latter can promote state6; there is no state6 dispatcher branch. Optional-format source-end notifications belong to134BC0. The original authoritative mapping already stated1..5 correctly.

Other especially useful complete comparisons preserve unusual original behavior:

- CVX's WAVE “four-bit” worker assembles byte pairs into16-bit samples just as
  Outbreak126270 does. The API spelling is not evidence of an ADPCM algorithm.
  SPSD's unconditional common16-bit geometry fallthrough also exists in CVX.
- CVX's numeric error formatter really writes raw remainder bytes into one
  pointer and then reverses a different static scratch. It does not justify
  replacing128198 with ordinary `itoa`. Two-number1282A0 retains its unusual
  literal second capacity and full-string pointer.
- AIFF sample-rate extraction differs: CVX reads a full16-bit exponent,
  Outbreak's original calculation uses its low byte. AIFF/AU offset admission
  differs too: CVX checks the narrowed length multiplied by1024, whereas the
  Outbreak wrappers use the documented offset-left16 condition. Invalid inputs
  must retain their own behavior.
- Outbreak's file-stream API has separate create/request/open/pump/stop/close
  phases. Several CVX open-and-allocate wrappers therefore map only to a group
  of related phases, not an identical one-entry API. Read service130800 also
  has later open/close/inflight/partial-sector semantics absent from the older
  `adxstmf_stat_exec` implementation.
- CVX's peak Start merely clears positions/state; Outbreak122948 additionally
  resets/zeroes borrowed SJ storage. Outbreak's stopped/draining RNA worker is
  also a different algorithm from CVX's zero-padding worker. Pure RNA Lock and
  Unlock counters remain counters, not mutexes.
- The older float predictor dispatcher cannot replace Outbreak's keyed integer
  dispatcher. The already reviewed stereo partial-budget threshold differs;
  so do transfer activation, diagnostic-only unsupported APIs, pool sizes,
  object layouts, callback groups, service order and source-error promotion.

AINF text/application schema, optional AHX/formatF callback implementations and
Sofdec internal stream-flag purposes remain outside what these older reference
files establish. The complete comparison does not erase those explicit gaps.

## Data comparison and reproducibility

All three arrays in data-only `adx_qtbl.c` match owned Outbreak bytes word for
word:16 float values at23A4E8,256 high-nibble values at23A528 and256 low-nibble
values at23A928. These are data identities, not528 new functions or an output
parity result. The1000 uint32 attenuation words from CVX `ps2_rna.c` likewise
match220498 exactly (SHA-256
`ba7a4e40b40741d52daddb3e80bf6c55d0ddcf93df46580ba6de9ad8c5e9c138`).
All256 mulaw halfwords from `adx_bau.c` match20B738 (SHA-256
`3dab54339e520bb2c924826e3b72a917a2b612e9fd12fc867500f1d983a75827`).
The receipt includes every table hash and zero mismatch lists.

Reproduce with
`python tools/function_index/review_recvx_audio_complete_scope.py`.
The [helper](../../tools/function_index/review_recvx_audio_complete_scope.py)
requires the parent's exact
[`recvx-complete-source-inventory.json`](../../build-function-index/recvx-complete-source-inventory.json),
reparses every definition and checks its path/name/start/body hash against that
inventory. It asserts an explicit disposition for each nonempty definition and
compares every referenced original instruction comment with the owned ELF:
**378 complete Outbreak intervals,11,885 verified comment words, zero conflicting
or omitted nonzero words**. It never writes the shared index or old crosswalk.

Both changed authoritative notebooks pass their full original-word audits, and
a private import passes with17,069 unique annotations. The current pass adds no
runtime changes, generic-stub mapping credit or claim of a measured slowdown
cause.

## Curated crosswalk proposals

The [audio curator](../../tools/function_index/curate_recvx_audio_complete_scope.py)
records an explicit reviewed one-owner selection in
`build-function-index/recvx-audio-curated-additions.json`: **243 distinct Outbreak
addresses in50 notebook/reference-file groups**, comprising130 supported-role
and113 related/different comparisons. Each proposal retains exact reference
hashes/bounds, the original owned-body receipt and a freshly read authoritative
note row. The shared170-row baseline contains none of these243 addresses.
These are comparison rows, with **zero new semantic mapping credit**. The original170-address baseline and raw review SHA are frozen in `tools/function_index/recvx_audio_curation_baseline.json`; default curation never reads live review.json. Later shared-review expansion therefore cannot change the selected243 addresses or baseline exclusion classifications. Optional `--review` only adds current-overlap reporting.

The other132 reference definitions remain fully dispositioned in the exhaustive
ledger. Existing comparisons are not duplicated. Multi-owner open/allocate
phases, shared-owner wrappers, indistinguishable RNACRS Init/Finish names,
unsupported/return-only identities and mechanically uninformative bookkeeping
remain outside this curated selection. In particular,1264F8 uses the original
combined lock/unlock authoritative row; no separate annotation was invented.
Root owns shared crosswalk integration; neither helper writes review.json,
annotations, the index or generated runtime code.
