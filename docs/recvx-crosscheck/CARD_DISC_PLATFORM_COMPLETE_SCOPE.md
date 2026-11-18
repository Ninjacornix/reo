# Complete card and disc-platform comparison scope

Static review, 2026-11-05. **All120 available definitions across the four
transferred C files, plus all four matching headers, have a full-source
applicability disposition.** No game, card, file operation, build, replay,
native/runtime change or process attachment was performed.

Reference is the clean pinned `AshfordFamily/recvx-decomp` commit
`657b0c0c9489943116c71f151804ad7304fca975`. Outbreak is File #1 US
SLUS_207.65 SHA-256
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.

The [per-function ledger](../../build-function-index/recvx-card-disc-platform-complete-scope.json)
records source hashes, exact symbol/line/body bounds, full reference bodies,
source calls and fields, applicability, concrete compared Outbreak IDs or
bounded nonmatch reasons, API implementation availability and owned evidence.
Every source identity reconciles with the shared complete manifest by
path+symbol+start_line/body hash. All four headers contain declarations/types,
with no additional function bodies or assembly placeholders.

Reproduce with
`python tools/function_index/review_recvx_card_disc_platform_complete_scope.py`.
The [offline helper](../../tools/function_index/review_recvx_card_disc_platform_complete_scope.py)
only writes its private ledger. No shared annotations, catalogue database,
`review.json`, generated crosswalk or runtime code is changed.

## Exact accounting and provenance

| File | Bodies | Game-specific excluded | Bounded concept/algorithm comparison | No demonstrated counterpart | Stub | Stub-dependent |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| ps2_MemoryCard..c |55|40|12|1|2|0|
| ps2_McSaveFile.c |44|41|3|0|0|0|
| ps2_sg_gd.c |13|1|3|4|5|0|
| gdlib.c |8|2|2|3|0|1|
| Total |120|84|20|8|7|1|

The120 functions are inspected source bodies, not120 interchangeable library
functions. The84 exclusions were reviewed individually: they operate CVX save
fields, paths, selection UI, custom indexed-disc data or GD bookkeeping. The20
comparisons identify bounded common concepts or differences; **no original
Outbreak API alias or new mapping address is admitted** from this scope.

The source paths are under `src/ps2/veronica/prog/` and matching headers under
`include/ps2/veronica/prog/`. Raw source SHA-256 values:

| Source | SHA-256 |
| --- | --- |
| ps2_MemoryCard..c |`d4538c45d74d36e66d8e92fa5cdef8f74a1f311b3677c12074cdc1104a63de9e`|
| ps2_McSaveFile.c |`4be85e7b5cd64c71e80f946eff42f590700e9ddfb19cff624641f51d879f2e9d`|
| ps2_sg_gd.c |`0aafb4d81a486023e754f170f5800e1277407662d82dbd8587130a65a9a72102`|
| gdlib.c |`6e9e1429a6206b2acfec4be91168ca3452253b35bee993fee69c935682b33058`|

The ledger retains all four header hashes and the supporting `types.h`
record-layout excerpt at lines838..968, whose full-file SHA-256 is
`6f65149488a5bae9ae931bfbaa218ee8881845e0edc86fd94c11435f8ec40305`.
The icon title in ps2_McSaveFile.c contains legacy non-UTF8 bytes. The complete
manifest's decoded-body hash uses replacement characters; raw file and
raw source line-span hashes additionally preserve the actual bytes. No
corrupted decoded title is promoted to a game string or written back.

**41 complete original Outbreak intervals** were hash/word checked:
2,241 instruction-comment words,128 omitted zero words,zero conflicts and
zero omitted nonzero words. This validates the source evidence used for
comparison; it does not establish runtime parity or successful storage.

## Useful shared platform and algorithm boundaries

| Reference body | Outbreak evidence | Supported finding and limit |
| --- | --- | --- |
| mcCreateIconInit |1C13C0; owned2351A0..2352C0 constants| Shared icon.sys layout:6 line-break offset,C transparency,10 background colors,50 light directions,80 light colors,B0 ambient,C0 title,104/144/184 view/copy/delete names. This supports field interpretation, not identical initialization. |
| mcGetFreeCapacitySize |1C12C0| Both round nonnegative file bytes to1KiB allocation units. CVX counts15 saves+config+icon metadata+icon data and adds11; Outbreak considers five enabled manifest entries, then adds `(count+1)/2+2`. Signed guest rounding/overflow domains and schemas differ. |
| MemoryCardGetSum |1C56A0/1C5760; inline filename sums13CD38/13D6D8| CVX variable-length unsigned-byte sum differs from Outbreak's save codec. Only ordinary byte-sum algebra is shared with the unrelated filename checksum; no shared save format follows. |
| MemoryCardFileRead/Write |1BFB40/1BFE00,181230/181310,181D28| Both distinguish request acceptance from completion and retain caller buffers. Their sign-only completion checks do not prove exact requested bytes transferred. CVX uses SDK file descriptors and its own substates; Outbreak uses libmc2 path/device requests and separate metadata preflight. |
| Device-info/list/mkdir helpers |1BF840,1C02A0,1BFC00 and their libmc2 producers| Related operation categories only. Five-retry/blocking SDK wrappers do not match the owned three-retry/polled error classifiers or their enum values. |
| mcReadIconData / ReadFileEx |1C58C0 /18D820| Related whole-asset reads with sector rounding. CVX GD blocking/read return0 conventions differ from Outbreak ADXF polling and resident explicit-byte read/boolean1. Buffer capacity and error handling remain caller requirements. |
| gdFsGetDirInfo/Open/Read |139828,13A910,135930,139A50,18D820,139D00| Common uppercase lookup, pooled handle or disc-read concepts. CVX indexed GD directory/first-free handle and blocking absolute-sector loops differ from CVFS device resolution, DVCI last-free records and request admission. No GDFS ABI/layout identity. |
| GetFileSize |18DAB0/135FB8| CVX looks up its custom index; Outbreak resolves provider metadata or opens/seeks/closes. Zero/missing ambiguity is related, but negative seek results and return conventions differ. |

The icon.sys field comparison refines the existing
[1C13C0 row](../SYMBOLS_CARD_PROFILE_REQUESTS_AND_MANIFESTS.md): its label now
includes **lighting**, and directions, light colors, ambient, background colors,
transparency and view/copy/delete filename offsets are explicit. The original
instructions confirm those writes. CVX clears all0x3C4 bytes and writes PS2D,
a fixed title and constants; Outbreak mutates a borrowed asset, does not clear
the object or write its signature, and writes profile-dependent constants.
The compared light/ambient/background values differ; the helper records all
seven owned spans rather than asserting matching defaults.

No error was demonstrated in the existing Outbreak snapshot codec mapping.
CVX SAVEFILE is0x838 bytes with a32-bit byte checksum at0x834; CONFIGFILE is0x34
bytes with checksum at0x30. Outbreak's container is0x3FCC0 bytes, magic0x5963,
seeded XOR transform, fixed0x1FE5C halfword sum modulo0x10000 and separate header.
For a simple pure-data witness, bytes00,01 sum to1 as CVX bytes but represent
little-endian halfword0100 (256). No game payload was generated, decoded or
executed for this arithmetic comparison. Copying the CVX save routine would
change Outbreak's format and RNG/restore contract.

## Source availability and implementation gaps

Direct implementations of the10 referenced `sceMc*` APIs are absent from the
available pinned source manifest; these files only call them. The six
referenced `sceCd*` implementations are absent too. Callsite types and wrapper
control flow are useful evidence, but they cannot reconstruct the SDK worker,
RPC transport or physical card/disc behavior. In particular, seeing
`sceMcFormat` in CVX does **not** bind Outbreak's numeric libmc2 command3/4 to
that API. Existing qualified command names remain unchanged.

| Available reference stub | Actual body |
| --- | --- |
| MemoryCardUnFormat |return0, no unformat SDK call|
| DeleteMemoryCard |return0, no delete SDK call|
| gdFsGetDrvStat |return2, no drive query|
| gdFsReqDrvStat |return0, no status request|
| gdFsSetDir |return0, no directory mutation|
| gdFsLoadDir |return0, no directory load|
| gdFsEntryErrFuncAll |empty, no callback registration|

`CheckOpenTray` is separately **stub-dependent**: it tests states6/9, but the
provided gdFsGetDrvStat always returns2. Its periodic status-request call also
does no work in this source. This implementation cannot establish a real tray
state or serve as an owned drive-status replacement.

CVX MemoryCardFileOpen accepts a nonnegative completion result without storing
it into `lOpenFileNumber`. A bounded named-field assignment scan over the
available reference C corpus finds only the initialization to0 in
CreateMemoryCard; close/read/write consume that stored field. This is a
source-completeness/behavior boundary, not a reproduced CVX failure or proof
that external aliases cannot write it. It prevents assuming this source is a
complete portable memory-card backend.

The eight nonmatch records remain explicit:

- ChangeMemoryCardDir: no demonstrated equivalent client working-directory API
  in the reviewed Outbreak profile/libmc2 path layer.
- gdFsClose,gdFsCreateDirhn,gdFsFinish,gdFsGetFileSize: custom record clearing,
  global directory pointer,SDK-only shutdown or field getter does not establish
  an owned GDFS object/API identity.
- InitGdSystem,InitGdSystemEx,ExitGdSystem: CVX allocator/workspace/table and GD
  lifecycle are not the independent Outbreak CRI filesystem lifecycle.

CVX GD init builds its directory from `dvd_image_data` and linked filename
tables, with custom header/sector indexing and unbounded search/read retries.
It is not an implementation of Outbreak's independently reviewed CRI archive
layer. gdFsOpen also has no explicit failure return at the end of its supplied
C body. Those source limits must not disappear behind a generic filesystem
name. The allegedly128-attempt outer setup does not bound an inner endless
search/read loop.

CVX McState's0xA0-byte context, BASLUS-20184 paths,0/1/2/4/5/7/17 states and
9/10/12/13/15/18 completion conventions differ from Outbreak's0xAC-byte profile
context, owned manifests and queued backend. The supplied card files contain
no matching OSD/BCD clock-conversion implementation; Outbreak's
[timestamp/OSD adjustment](../SYMBOLS_OSD_CONFIGURATION_AND_BCD_CLOCK.md)
remains independently established. Save UI, inventory/room fields, message IDs,
title bytes and fixed icon resource sizes remain CVX-specific exclusions.

This closes the assigned120-body source/applicability review with the gaps
preserved. It establishes no binary equivalence, ready native card/disc backend,
successful save, reproduced slowdown or gameplay fix.
