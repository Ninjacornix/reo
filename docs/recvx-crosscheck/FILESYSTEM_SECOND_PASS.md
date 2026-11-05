# Filesystem, archive and provider comparison: second pass

Static comparison, 2026-11-05. This pass corrects one callback-argument claim,
adds a qualified legacy file-count role, adopts two supported candidate names,
and separates several version-specific contracts that must survive a native rewrite.
It does not execute either game or prove binary equivalence to Code Veronica.

The clean reference is AshfordFamily/recvx-decomp at commit
`657b0c0c9489943116c71f151804ad7304fca975`. Outbreak is the owned File #1 US
SLUS_207.65, SHA-256
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
The [offline checker](../../tools/function_index/review_recvx_fs_second_pass.py)
records 34 complete original function intervals, 1,159 matching instruction
comments and 34 omitted zero words; no conflicts or omitted nonzero words.
It retains 25 complete CVX function bodies, eight source/header identities,
both original 26-word provider tables and structured crosswalk additions in
the [private receipt](../../build-function-index/review_recvx_fs_second_pass.json).
Run `python tools/function_index/review_recvx_fs_second_pass.py` to reproduce it;
`--reference` accepts another clean checkout at exactly that commit.

## Corrections and candidate identities

| Outbreak entry | Evidence and resulting documentation change |
| --- | --- |
| 136578 | The entire legacy path matches CVX private `getNumFiles`: strlen, input-length prefix comparison across 32 registry records, first callable method44, and default zero. This supports `cvfs_device_file_count_legacy_route_with_optional_selector4_candidate` in [SYMBOLS_CRI.md](../SYMBOLS_CRI.md). It does not prove all public `cvFsGetNumFiles` behavior: CVX's public wrapper accepts NULL to sum all devices; Outbreak's reviewed function directly calls strlen and has no aggregation/default-device path. |
| 136578 callback ABI | Earlier notes said `method44(originalName)`. Actual 136630 loads the member, 13663C calls it, and intervening/delay words set no arguments. The preceding 136F98 calls another lookup and can set a0=0 before probing its optional callback. Original argument registers are therefore unpromised, not a guaranteed filename argument. Both the [earlier residual](../STATIC_MAIN_122700_13FFFF_REMAINING_CONTRACTS.md) and [provider follow-up](../STATIC_CVFS_136578_PROVIDER_BOUNDARY_FOLLOWUP.md) now correct that claim. CVX's private helper calls `GetNumFiles()` without explicit arguments too. |
| 136688 | Candidate name refined to `cvFsLoadDirInfo_candidate`: full split/default lookup, original three-argument dispatch, +48 slot and identical copied IsExistFile diagnostic agree with CVX. Outbreak adds 136FE8 scratch-path rewriting but forwards original a0/a1/a2, not its rewritten buffer. No output-record schema is inferred. |
| 135EF0 | Existing [SYMBOLS.md](../SYMBOLS.md) row refined from `cri_poll_backend_callbacks` to `cvFsExecServer_candidate`. Complete 32-slot scan and interface/method0 guards match CVX. Owned callbacks service 40 disc or 13 host handles; the interface identity does not imply cheap or field-only work. |
| 135C80 | Close clears the wrapper only after its backend method returns. Missing method takes the diagnostic tail without clearing it. This condition is now explicit in the authoritative row and agrees with CVX. |
| 1363A8 | The wrapper still inherits provider behavior. Both owned Outbreak providers establish bytes, completed-count shifted11 only in state1; the upper row now states this concrete contract instead of leaving owned-provider units unspecified. |
| 129168 | Refined existing wording: it reconfigures an existing stream at handle+4 through1304E8. CVX `adxf_SetAfsFileInfo` assigns a newly opened stream. Both resolve archive members and derive padded bytes from sectors; stream ownership/setup differs. |
| 129C08 | Clarified the refresh condition: cached count>FFFFE triggers the extra130FE8/status guard, but every remaining valid path calls130E40 and refreshes the sector count. It is not only large files that query stream size. |

136578's additional branch remains deliberately bounded. Capability136F98
nonzero chooses method60 with `(stack,4,0,0)`; only stack+4 is populated with
the original name, while stack+0 is uninitialized locally. Capability zero
chooses the legacy method44 route. This differs from path rewrite136FE8,
which requires capability exactly1. Both owned provider tables have method44
NULL, method48 NULL, capability64 disabled, and selector4 unsupported. Their
zero does not prove an empty directory or define an extension result unit.
The candidate identifies the legacy interface family from full cross-version
structure; custom-provider implementation and optional-selector4 semantics
remain unknown. No new concrete provider behavior is claimed.

## Version differences that prevent direct source substitution

| Contract | Pinned CVX source | Original Outbreak instructions |
| --- | --- | --- |
| SetSctLen | Public signature includes sector length; source callback receives only backend object. | 136350 replaces a0 with backend object and leaves a1/a2/a3 unchanged before JALR. Preserve caller-supplied length/register behavior. |
| OptFn1/2 | Public four-argument wrappers call the member with just backend object in C. | 136AA8/136B10 replace only a0 and preserve remaining registers. Selectors and additional parameters must survive. |
| Concrete GetNumTr | dvCi/htCi return `req_nsct*2048` without a state guard. Their Seek assigns that same field and Tell returns it, so it represents the current sector cursor in this version. | 139FE8/13BBE8 return completed-sector fields +14/+28 shifted11 only when state1. Do not transplant a cursor getter as a completion counter. |
| Ordinary filename size | CVX GetFileSize/GetFileSizeEx return a Sint32 through +8/+5C and explicitly return after missing-interface diagnostics. | 135FB8/136078 use the newer resolver. Their missing-interface diagnostics can return into +8/+5C loads from NULL. Existing documentation's returning-error-callback caveat remains material. |
| Host size width | CVX htCiGetFileSize directly returns Sint32 cached/open/seek-end/close result. | Public interface +8 is 13B308, which sign-extends low32 of 13B330. Wider optional-size routes call13B330 through13BC38; uncached path preserves the seek-end result in a 64-bit register, while the cache size is a signed word. |
| File size as sectors | CVX ADXF_GetFsizeSct returns its cached field. | 129C08 queries stream bytes, signed-divides toward zero by2048, caches and returns -5 above FFFFE; may first force a metadata/status refresh. |
| File size as bytes | CVX ADXF_GetFsizeByte returns the fsize field and NULL -3 unchanged. | 129CA8 shifts the entire 129C08 result left11 in 32-bit arithmetic. NULL -3 becomes -6144; -5 becomes -10240. It is not an exact unpadded byte-length getter or a sentinel-preserving alias. |
| Archive ranges | CVX ADXF_GetFnameRangeEx walks linked additive partitions then a cumulative Uint16 table. | 129E18 uses descriptor+F to choose Uint16 or 32-bit lengths, adds descriptor+114 sector base and returns parent identity+110. It does not contain CVX's linked additive-partition loop. Existing typed output/units mapping is retained. |

The CVX header itself has inconsistent prototypes: SetSctLen lacks the public
length parameter in one typed table; OptFn1/2 lack public optional parameters;
LoadDirInfo's typed second parameter differs from the public pointer; another
table uses old-style unspecified argument lists. These are reference-source
boundaries, not evidence that Outbreak's extra registers are unused. A source
comment claiming a byte-matching object has not been independently validated
against a CVX executable in this pass.

## The newer composed 64-bit queries

The [two recently mapped routes](../SYMBOLS_CVFS_64BIT_FILE_SIZE_QUERY_ROUTES.md)
were rechecked against original words and actual disc/host implementations.
No corresponding CA..CD route or optional implementation exists in the
inspected CVX CVFS/disc/host sources, so source similarity does not establish
an original public name for them.

- 137138 splits/resolves the name, then calls optional CA and CB with original
  name, resolved path and zero parameter. Missing method returns0; NULL
  interface is not guarded before the method load.
- 1371F0 calls135560 with newly allocated, locally uninitialized stack input
  before the later path split. A nonnull interface permits CC/CD using
  original name, resolved path and original second argument. The reference's
  safer lookup sequence cannot replace this observed ordering as a claim.
- Both combine low32(high-query)<<32 with unsigned low32(low-query).
  Disc CA/CC return0; CB/CD return metadata byte size. Host CA/CC and CB/CD
  select arithmetic high32 and low32 of filename size. CD is a low-size
  branch, distinct from constant1 capability12B. Separate calls are not an
  atomic snapshot, and zero can also mean an unsupported method/provider.

## Reproducible source identities and remaining gaps

Raw worktree source/header SHA-256 values follow. The receipt also retains
each exact Git-blob hash and checks normalized LF equality against the pinned
commit; the clean Windows checkout has CRLF conversion in some files.

| Reference basename | Source SHA-256 | Header SHA-256 |
| --- | --- | --- |
| cri_cvfs | `ad74c6302b6d8b9a08db647f9fcab7f4874ea9a6a0bf2cc573cbcdb7e92cba35` | `85a92f9ed9d0a135b00c49cc259406dde249507eeaf5cf09b97f01e1f3415ebc` |
| dvci | `e687a562fa22ad88ffbc5446773341b646ba404e6ebf5b385ff08ec1779af13d` | `70f6d540003e28a83081fa23ed27b91c89b638230f92cd00c137326ca9066559` |
| htci | `031074520a98613f8cf39add1c2e2337df4c63fe010b4cbfe7f8e6e9c3cc27b3` | `7b3fa3b062a9214dece86c8cf1d0b76e3e6c2de108354b6ea235cd937e0e5aa7` |
| adx_fs | `09bccb9ddde64ef894279ca8cc35242382c8681f711ddef07119f9132e33abaf` | `a3c76643d9d29410864a4b887bd130bf3fad81d6c32374706971fac9fae55a47` |

Sources are under `src/cri/mwlib/ee/lib/libadxe/`, matching headers under
`include/cri/mwlib/ee/lib/libadxe/` in the
[pinned repository](https://github.com/AshfordFamily/recvx-decomp/tree/657b0c0c9489943116c71f151804ad7304fca975).
The receipt records exact function line bounds and body hashes. Original
provider-table SHA-256 values remain
`110e07237b9879134ef9aa44289116e0a63f2ff0392b117f842bebb325692d8a`
(disc21CBF8) and
`40df6d55908bd06ecee4d4c144c3a30a7a3b2aed1f0afcd9202dd43ffd3f2a00`
(host21DA88).

Open gaps: method44/custom-provider implementations; selector4 request layout
beyond the stored name; LoadDirInfo output-record schema; intended admission
for1371F0; custom provider contracts; and whether any reviewed distinction
currently causes a gameplay incident. This is static reconstruction evidence,
not a performance measurement or an implemented engine change.
