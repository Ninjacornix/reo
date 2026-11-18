# Complete CRI stream/filesystem reference scope

Static review, 2026-11-05. **All 286 available C function bodies in the assigned
24 reference files and all 24 matching headers have a recorded disposition.**
This completes this source-comparison scope. It does not mean every body has an
Outbreak equivalent, every comparison is binary equivalence, or either game has
been translated to native code. No game, build, replay, RPC, DMA, process attach
or native/runtime change was performed.

Reference: clean `AshfordFamily/recvx-decomp` commit
`657b0c0c9489943116c71f151804ad7304fca975`. Owned Outbreak: File #1 US,
SLUS_207.65 SHA-256
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.

The [per-file/per-symbol ledger](../../build-function-index/recvx-streamfs-complete-scope.json)
retains every source SHA, raw-CRLF body hash, exact line/offset bounds, complete
body, source calls/fields, available header text/hash, disposition, bounded
search or concrete Outbreak IDs, and the associated authoritative original
mapping contracts. Its identities reconcile exactly with the root
`recvx-complete-source-inventory.json` by path+symbol+start_line. There are no
assembly placeholders or header-defined function bodies in these 24 files.

Reproduce with
`python tools/function_index/review_recvx_streamfs_complete_scope.py`.
The [helper](../../tools/function_index/review_recvx_streamfs_complete_scope.py)
only reads the clean reference, owned ELF, read-only catalogue and notebooks;
it writes its private ledger. It does not change shared annotations, index,
`review.json`, or generated crosswalk reports. Header imports outside this
available reference tree remain dependency boundaries, not recovered bodies.
The [frozen prior-comparison baseline](../../tools/function_index/recvx_streamfs_prior_comparisons.json)
preserves72 earlier comparison rows for70 distinct source bodies, so later
crosswalk expansion does not change the prior/new accounting on reproduction.
It records the exact original `review.json` hash; it is comparison evidence,
not a second symbol annotation database.

## Exact accounting

| Disposition | Reference bodies | Meaning |
| --- | ---: | --- |
| Already compared | 70 | Previous curated source/body comparisons retained and rechecked against current authoritative notes and original words. |
| Newly compared | 197 | Complete source bodies compared with existing typed Outbreak contracts, preserving version differences. These are additional comparisons, not 197 new game-function mappings. |
| No demonstrated counterpart | 17 | Full body inspected, related operations and searched boundary recorded, but no one-to-one owned contract admitted. |
| Source unimplemented/empty | 2 | Empty LSC registration hooks; no semantic credit manufactured from emptiness. |
| Total | 286 | Every available source definition in the assigned files. |

The original integrity check covers **275 distinct catalogue intervals**:
267 compared entries plus eight supporting dependencies, with **9,381 original
instruction-comment words, 190 omitted zero words, zero conflicts and zero
omitted nonzero words**. Those counts are integrity evidence, not an automatic
proof of each semantic comparison. Multiple reference versions/helpers can
relate to one owned implementation; the ledger keeps those distinctions.

All reference paths below are under `src/cri/mwlib/ee/lib/libadxe/`, with headers
under `include/cri/mwlib/ee/lib/libadxe/` at the same pinned revision.

| File stem | Bodies | Prior | New | No demonstrated counterpart | Empty |
| --- | ---: | ---: | ---: | ---: | ---: |
| adx_fcch | 1 | 0 | 1 | 0 | 0 |
| adx_fs | 40 | 5 | 29 | 6 | 0 |
| adx_fsvr | 1 | 0 | 0 | 1 | 0 |
| adx_sudv | 4 | 0 | 4 | 0 | 0 |
| adx_suht | 4 | 0 | 4 | 0 | 0 |
| cri_cvfs | 45 | 18 | 25 | 2 | 0 |
| dtr | 8 | 0 | 8 | 0 | 0 |
| dtx | 17 | 12 | 5 | 0 | 0 |
| dvci | 20 | 1 | 18 | 1 | 0 |
| dvci_sub | 9 | 0 | 9 | 0 | 0 |
| htci | 24 | 2 | 18 | 4 | 0 |
| htci_sub | 10 | 0 | 10 | 0 | 0 |
| lsc | 20 | 0 | 20 | 0 | 0 |
| lsc_crs | 2 | 0 | 2 | 0 | 0 |
| lsc_err | 2 | 0 | 2 | 0 | 0 |
| lsc_ini | 4 | 0 | 2 | 0 | 2 |
| lsc_svr | 4 | 0 | 4 | 0 | 0 |
| sjr_clt | 13 | 0 | 13 | 0 | 0 |
| sjx | 8 | 0 | 8 | 0 | 0 |
| sj_crs | 3 | 0 | 0 | 3 | 0 |
| sj_mem | 15 | 0 | 15 | 0 | 0 |
| sj_rbf | 16 | 16 | 0 | 0 | 0 |
| sj_uni | 15 | 15 | 0 | 0 | 0 |
| sj_utl | 1 | 1 | 0 | 0 | 0 |

## Corrections and additional shared contracts

Three current authoritative entries were refined without adding an address or
changing the denominator:

- **SJMEM capacity13F7D0:** the old explanation called offset1C current
  availability. Availability is **C**; offset1C is the error callback. Original
  getter returns capacity18, and reset/count/reserve plus the CVX layout agree.
  Corrected [SJMEM row](../SYMBOLS_SJMEM_BORROWED_MEMORY_READ_VIEW.md).
- **ADXF service129A60:** the central note still called its subtype unknown.
  Complete guarded scan of the16 ADXF records, their constructors/close, and
  child129998 establish the file-handle service. CVX ADXF_ExecServer supplies a
  supported candidate spelling. Existing row is now `ADXF_ExecServer_candidate`
  in [SYMBOLS.md](../SYMBOLS.md).
- **LSC progress13D2C0:** existing lower-service writers establish **sector
  progress**, not an unspecified unit. While reading13D800 copies130608's
  sector-progress word54; completion copies the configured sector limit2C.
  CVX LSC_GetStmRdSct independently agrees with the role. Clarified the
  [LSC row](../SYMBOLS_LSC_INSTANCE_LIFETIME_AND_QUEUE_SERVICE.md).

The old [SJX/RPC inventory](../SYMBOLS_CRI_SJX_BRIDGE_AND_RPC_BOUNDARIES.md)
also still presented eight wire operations as currently uncredited despite the
later [owned IOP server review](../SYMBOLS_CRI_SJRMT_OWNED_IOP_SERVER_CONTRACTS.md).
It is now explicitly historical and points to those authoritative rows.
All13 matching CVX SJRMT wrappers are compared in the new ledger; no duplicate
mapping rows were added.

The SJMEM UUID is now checked from the C initializer against owned23DA08:
`41ee9edd7916d211936c0060089448bc`. The helper also rechecks existing matching
SJRB/SJUNI UUIDs at23DA58/23DA78. Shared interfaces do not erase layout or
default-error differences: CVX SJMEM/SJRB/SJUNI default errors spin forever,
whereas the owned defaults forward diagnostics and can return.

Earlier [filesystem corrections](FILESYSTEM_SECOND_PASS.md) remain in force:
136578's method44 has no explicitly restored filename argument; the file-count
legacy role is qualified; optional selector4 remains unbound; and the newer
CA..CD64-bit routes preserve their original admission/lookup flaws. The70
previously compared reference bodies across the filesystem and earlier stream
reviews are not counted as newly discovered work.

## Material version differences

| Family | Comparison that a native reconstruction must preserve |
| --- | --- |
| LSC filename ownership | CVX copies40-byte names into64-byte queue records and has8 instances. Outbreak has16 instances and32-byte queue records holding borrowed pointers plus byte-sum checksums. Replacing one with the other changes lifetime, capacity, stale-name and pointer-return behavior. |
| LSC file lifetime | CVX EntryFname opens/closes immediately to determine sectors; owned13CD10 enqueues with default FFFFF limit and defers opening. CVX stop/retire closes per-file streams; Outbreak retains a supplied stream and reconfigures it. Repeat retains a borrowed name pointer instead of copying to static scratch. |
| LSC guards | CVX guards the whole service scan, destructor and module finish. Owned13D040,13CCB8,13D618 do not contain equivalent outer guards. Token-pointer wrappers do not create an independent lock. |
| SJX generation | CVX receive callback checks command.xid against binding.xid; owned140F18 filters command type and uses the pool byte without comparing generation. CVX Reset increments xid and sends RPC2; owned1415D0 only increments the local16-bit halfword. These are observed differences, not reproduced stale-packet failures. |
| SJX lifetime/capacity | CVX has16 bindings and Finish only decrements a counter. Owned has32 bindings, and final141418 destroys DTX and releases owned IOP heap/reference. |
| SJRMT availability reply | Both inspected client versions request ONE response word for IsGetChunk but also read responseword1. The owned server writes two words, yet the EE transport copy refreshes only one. Shared source confirms the static stale-output concern; it is not a measured incident. |
| DTR stop | CVX stop ungets selected spans without the owned wait-for-DMA path. Owned138BE0 waits for completion and returns source/destination spans using PutChunk to their completed pools. Service pool size is16 versus owned32. |
| DTR accounting | Both service sources clear saved chunk length before adding it to the total. This literal zero increment was not a notebook typo and was not silently repaired during comparison. |
| ADXF setup/seek | CVX creates a record with streamNULL and opens during setup; owned128F80 constructs an actual stream first. CVX Seek calls a stream-offset setter after clamping; complete owned129AC0 changes cursor/logs without that call. |
| ADXF size/range | CVX size getters are cached fields and ranges include linked additive/Uint16 partitions. Owned size query refreshes bytes, signed-divides to sectors and shifts even negative sentinels in its byte adapter; ranges select16/32-bit lengths and add an explicit base. |
| Setup descriptors | CVX ADXT_SPRM is a28-byte fname/fpc/size/mode structure. Owned DVD setup consumes a20-byte prefix/mode/option descriptor; host setup uses16-byte prefix/reopen/64-bit-option/lock fields. Cache loading uses a separate16-byte descriptor. Matching wrapper names do not justify copying offsets. |
| File-list records | CVX embeds140-byte disc/268-byte host records. Outbreak splits8-byte metadata pairs from variable-width name storage, retaining capacity/width registration fields and different returned storage accounting. |
| Host name/open policy | CVX uses strcasecmp for cache names; owned13C008 preserves case and normalizes only slash direction. CVX open-mode0 remains0, whereas owned13C9E8 maps all non1 arguments, including0, to8001. |
| Provider progress | CVX disc/host GetNumTr returns the Seek/Tell cursor times2048 without a state guard. Owned getters expose completed sectors only in state1; high/low optional host counts additionally clamp to true byte length. |
| Provider completion | CVX direct disc sync/read and host ioctl/seek/read stages differ from owned SRD request objects and flags. Related backend API names do not establish identical polling, waits or fields. |
| Guard implementation | CVX SJCRS only changes a global nesting counter; owned shared SJ/LSC wrappers delegate callback-backed CRI tagged guards. Copying the trivial CVX counter would remove behavior. |
| SJRB/SJUNI | Prior differences remain: owned SJRB256*64-byte records versus CVX64*48, added totals/shifted callbacks, and signed owned SJUNI work-size division versus CVX unsigned cast. Shared UUIDs do not permit structural casts. |

Complete header inspection also retains the known CVFS prototype inconsistencies
around SetSctLen, OptFn and LoadDirInfo. Source C signatures are comparative
evidence, not a reason to discard owned argument registers. No external CRI
header body or CVX executable was invented to fill a gap.

## Seventeen bounded unmatched cases and two empty hooks

Every unmatched record includes the full body and the specific searched
Outbreak boundary in the JSON; these are not unnamed leftover rows.

| Reference file | Functions without a demonstrated one-to-one counterpart | Search/result boundary |
| --- | --- | --- |
| adx_fs | adxf_LoadData; ADXF_LoadPartition; ADXF_LoadPartitionEx; ADXF_LoadPartitionNw; ADXF_AddPartition; ADXF_GetPtinfoSize | Reviewed128620..129F70 partition family. Blocking/asynchronous roles and newer adapters relate, but signatures/state/layout differ. No linked-additive API established. Do not alias128F10 to GetPtinfoSize: original returns member count+8, not descriptor size. |
| adx_fsvr | ADXT_ExecFsSvr | CVX directly calls cvFs,ADXF,ADXSTM services; owned group scheduler distributes phases. No matching single public facade admitted from the related callees alone. |
| cri_cvfs | cvFsGetNumFiles; getNumFilesAll |136578 matches private getNumFiles only. Public NULL aggregation/sum and zero-result diagnostic behavior are not present there; no aggregation body demonstrated in the reviewed family. |
| dvci | dvci_wait | CVX32768-iteration disc backoff has no independent matched owned body in1395C8..13A248 and stop helpers. |
| htci | htci_is_one_excute; htci_is_all_excute; htci_wait_io; htci_wait_by_fd | Owned13AFF8/13B048/SRD updater are related but have different predicate, descriptor/request, loop and completion contracts. An any-active-read predicate is not an all-ioctl-completed predicate. |
| sj_crs | SJCRS_Init; SJCRS_Lock; SJCRS_Unlock | Simple global-counter operations are not admitted as identities for owned callback-backed guard chains or unrelated bookkeeping counters. |

`lsc_EntrySvrInt` and `lsc_DeleteSvrInt` are empty bodies in the available CVX
source. Return-only owned13D588/13D590 remain mechanical evidence without
semantic credit. Header declarations for them do not supply an implementation.

These limits leave concrete reconstruction work: preserve Outbreak's ownership,
ABI, guards and provider selection; design tests for the recorded edge cases;
and only then select shared algorithms for native implementations. This report
establishes static comparison coverage, not runtime parity or a slowdown fix.
