# Complete available-source Code Veronica comparison

Completed static audit, 2026-11-05. The available pinned reference source has now been inventoried and reconciled at function level, including shared libraries, platform code, graphics/math/format helpers and reusable utilities embedded inside game files. Each admitted definition has an explicit comparison, version/ownership boundary, missing-counterpart or unavailable-implementation disposition. Remaining CVX-specific gameplay/UI definitions have function-level eligibility reasons.

**This completes the available-source audit. It does not establish equivalence for missing SDK/library implementations, every unpaired utility, every original Outbreak function or a native replacement.** No game, build, codec execution, replay, target process, input, audio device or live memory was used. All work concerns source and owned on-disk original bytes.

## Exact coverage

| Accounting | Count |
| --- | ---: |
| Reference source files inventoried | 229: 228 C and one startup assembly file |
| Named C definitions individually accounted for | 4,599 |
| Shared/platform/utility/availability definitions with detailed scope dispositions | 1,817 |
| Remaining CVX gameplay/integration definitions excluded by function-level dependency review | 2,782 |
| Alternate assembly declarations with implementing bodies absent | 223, separate from the C definitions |
| Independently reconciled detailed scopes | 13 |
| Curated Outbreak main-image address comparisons | 620 |

The initial residual eligibility screen was partitioned into 1,850 actor/effect definitions and 1,102 other definitions. Their exact identity sets are disjoint and union to 2,952. It admitted 37 actor-local utilities, 76 other utilities/framework adapters and 57 sound adapters for additional review. No filename alone establishes that all functions in a file are game-specific: these carve-outs were checked separately. The remaining 2,782 exclusions preserve their individual type, global-state, authored-policy or transitive ownership reasons.

The curated address crosswalk has 237 supported-role, 378 related/different, three name-candidate and two concept-only rows. These are comparison results, not 620 new mappings. Many-to-many, overlay-only, uncertain and narrow suboperation comparisons remain in the detailed ledgers instead of being forced into a single main-image alias. A source name or an equal table does not upgrade a mapping to binary/output equivalence.

## Detailed scope ledgers

| Scope | Reference definitions | Report |
| --- | ---: | --- |
| CRI audio/core and encoder data | 375 | [Audio/core](AUDIO_COMPLETE_SCOPE.md) |
| CRI stream/filesystem/providers | 286 | [Stream/filesystem](STREAM_FS_COMPLETE_SCOPE.md) |
| Ninja/math/model/graphics libraries | 397 | [Ninja](NINJA_COMPLETE_SCOPE.md) |
| Graphics packet/OT/cache support | 43 | [Graphics support](GRAPHICS_SUPPORT_COMPLETE_SCOPE.md) |
| Platform/compiler/allocator/input/sound support | 193 | [Platform](PLATFORM_COMPLETE_SCOPE.md) |
| TIM2/CLUT/GS upload utilities | 16 | [TIM2](TIM2_COMPLETE_SCOPE.md) |
| Movie/PSS/input-buffer adapters | 85 | [Movie platform](MOVIE_PLATFORM_COMPLETE_SCOPE.md) |
| Memory-card/disc wrappers | 120 | [Card/disc](CARD_DISC_PLATFORM_COMPLETE_SCOPE.md) |
| Mixed geometry/facial/model helpers | 70 | [Mixed geometry](MIXED_GEOMETRY_COMPLETE_SCOPE.md) |
| Reference skeletons/alternate hooks and two UI graphics helpers | 62 | [Availability](REFERENCE_AVAILABILITY.md) |
| Utilities/framework helpers inside non-actor game files | 76 | [Non-actor eligibility audit](EXCLUSION_AUDIT.md) |
| Utilities inside actor/effect files | 37 | [Actor eligibility audit](ACTOR_UTILITY_ELIGIBILITY_AUDIT.md) |
| SDK-facing sound adapters | 57 | [Sound adapters](SOUND_ADAPTER_COMPLETE_SCOPE.md) |
| **Total detailed dispositions** | **1,817** | |

Both sides of the research are retained: reference file/symbol/body boundaries and hashes, and independently identified Outbreak image/address/source evidence. Word audits establish that the recorded original instructions match the owned files; the authored comparisons explain the contracts and limitations. The reports distinguish a direct body comparison from source applicability screening or a failed counterpart search.

## Corrections and refinements

The earlier [second-pass findings](SECOND_PASS_FINDINGS.md) recorded the ADX loop field base+0x18 tobase+0x14 correction, unsupported CVFS filename-argument claim, predictor-history correction, remote audio drain-mode interpretation and ambiguous hexadecimal byte sizes. The full pass additionally corrected or clarified:

- **SJMEM main13F7D0:** availability comes from object+0x0C. The earlier+0x1C description selected the error callback field. The complete original getter and the reference layout establish the correction.
- **ADXF main129A60:** the central descriptive subtype-unknown label is refined to the qualified ADXF service role, retaining its actual original handle scan and version-specific work.
- **LSC main13D2C0:** progress units are now explicit sectors through the actual local providers, with ownership/lifetime differences from the older reference.
- **PS2 icon.sys main1C13C0:** lighting direction/colour and shared header-field meanings are distinguished from the earlier generic colour wording; the complete file layout is not inferred from one shared field.
- **Source coverage tooling:** the balanced inventory retains multiline and debug-metadata definitions missed by the earlier lexical screen. Combined notebook rows now select the generated-source anchor and proposed label for the actual compared address rather than blindly using the first linked entry.

Authoritative notes and the annotation index were reconciled. This pass adds comparison evidence and fixes interpretation; it does not introduce native implementations or claim new original public symbols. The function-map denominator remains 17,916 and reviewed annotation count remains 17,069. The earlier 95.27% metric is role-label coverage, not the completion metric for this comparison audit.

## Important shared evidence and incompatible contracts

Positive evidence includes exact 16-byte SJUNI/ring UUIDs; all 32 entries of both compared GS 4/8-bit block tables and the inverse32-bit coordinate construction; 528 float-table words,1,000 attenuation words and256 mu-law halfwords; the ADX padding/producer/parser chain; and twelve concrete movie-buffer comparisons. These support the stated suboperations and interfaces while retaining the surrounding state/layout differences.

Meaningful differences include:

- CVX LSC copied 40-byte names/eight instances versus Outbreak borrowed checksum-checked names/sixteen instances.
- SJX reset and generation handling: the reference sends a remote reset and checks receive identity; the inspected Outbreak reset advances a local halfword and its receive path has a different admission contract.
- Ring counters, error-callback offsets, DTX submission gates and acknowledgement-dependent teardown.
- Sony/PSS buffer restart ordering and interrupt restoration: optional semaphore, queued-state and unconditional-versus-conditional EI behavior must retain the actual Outbreak path.
- Trigonometric algorithms, signed fractional extraction, matrix argument/overlap/W semantics, alpha rounding and turn16 half-turn ties.
- GS/TIM2 transfer ownership: CVX immediate GIF-DMA/scratch/OT paths differ from Outbreak caller-buffer VIF DIRECTHL chains, chunking and bounded versus unbounded waits.
- Memory-card asynchronous request acceptance versus completion, save checksum algorithms and game-specific save/state structures.
- Missing callback/provider implementations, compiler dependencies and source stubs. Nonvoid empty/missing-return source does not establish a valid portable return contract.

These differences are not automatically Outbreak bugs. They are evidence that copying a corresponding-looking function can change behavior. No slowdown frequency, root cause, instruction/output parity or frame-rate improvement was measured.

## Unavailable comparisons and completion boundary

The pinned reference does not supply implementations for the queried standard C/compiler primitives, most kernel/card/controller/RPC interfaces, or the substantial binary-only/private libraries called by its wrappers. Its 223 alternate INCLUDE_ASM bodies are absent; 60 debug/alternate-hook definitions have no behavioral implementation. Source callsites cannot validate those missing bodies.

Outbreak SN@P/SNIOP, HTTP/security/DNAS and its larger private Sofdec/MPEG and FLLib/Clay paths still require independently identified implementing reference evidence before a one-to-one CVX comparison is possible. Generic math/graphics/interface similarities are recorded at their actual depth. No original actor layout, script opcode, asset format, VU program or game-specific scheduling contract was imported based on similar names.

Completion here means all available source identities and all identified non-game-specific candidates have recorded outcomes, with exact exclusion/availability accounting. It does not mean every mapping is proved correct or that missing counterpart source has been reconstructed. The result is a bounded, reproducible audit rather than a promise of universal shared code.

## Files and reproduction

- [Complete function coverage CSV](complete-function-coverage.csv): every reference C definition, scope/status, evidence depth, owned evidence identities and report.
- [Complete file coverage CSV](complete-file-coverage.csv): all 229 reference source identities and data/assembly boundaries.
- [Structured complete ledger](../../build-function-index/recvx-complete-comparison-coverage.json): every disposition plus hashes, exact residual-partition checks and source references.
- [Curated crosswalk](CROSSWALK.md), [curation input](review.json) and [provenance](provenance.json).
- [Shared inventory helper](../../tools/function_index/recvx_scope_inventory.py), [complete reconciliation](../../tools/function_index/reconcile_recvx_complete_scope.py), and [curated merge](../../tools/function_index/merge_recvx_complete_curated.py).

Each detailed scope report names its offline evidence helper. The default audio-curation baseline is frozen at the prior 170 addresses; expanding the shared crosswalk does not silently change its selection/exclusions. Re-run the thirteen scope helpers against the clean pinned checkout, then reconcile, merge curated proposals, refresh annotations and regenerate crosswalk/provenance. No game or reference build is needed for these checks.

Reference source: AshfordFamily/recvx-decomp at `657b0c0c9489943116c71f151804ad7304fca975`; enhanced-renderer context is separately pinned to `2fa8a14224ebb92d0103a8c828e6a032c338d6d4`. The owned File #1 ELF SHA-256 is `06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`. Upstream source matching claims were not independently tested against a CVX executable.

