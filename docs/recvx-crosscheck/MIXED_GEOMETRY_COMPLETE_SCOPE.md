# Complete CVX mixed collision and facial utility boundary review

Static review, 2026-11-05. Pinned CVX revision `657b0c0c9489943116c71f151804ad7304fca975`; owned Outbreak File #1 US ELF SHA-256 `06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`. This finishes the explicitly transferred five-file scope: **70/70 real, nonempty reference definitions**, with exact file/body hashes and bounds reconciled to the shared manifest.

The review finds **one related geometric predicate**, `bhInOutCheck` versus `o2:616BD0`, with material arity/normalization differences. It establishes no new original API identity or mapping credit. The other 69 dispositions preserve precise game-state, object-format, global-result or missing-complete-counterpart boundaries. These are scoped source/owned-candidate comparisons, not proof that no equivalent arithmetic exists anywhere in the binary.

The classifications are 39 reference game-state/ATR-format contracts, 23 Ninja facial-format contracts, one Ninja model-format contract, six explicit geometry utilities and one global hit-state getter. Every reference body was parsed in full; large room-response bodies were classified from their full-body dependencies and concrete state/format witnesses, without pretending that their gameplay branches were translated into Outbreak actors. Explicit reusable geometry/format candidates received direct body comparisons. No game, target instructions, emulation, build, replay, process attachment, memory capture or input was run. Original inputs and shared mapping outputs were not changed.

## Reproduction and evidence

Run `python tools/function_index/review_recvx_mixed_geometry_complete_scope.py` from the checkout. The [offline helper](../../tools/function_index/review_recvx_mixed_geometry_complete_scope.py) checks all 70 function identities/bounds/body hashes against `build-function-index/recvx-complete-source-inventory.json`, checks all five raw reference file hashes, retains function signatures/calls and exact state/format witness lines, and writes `build-function-index/recvx-mixed-geometry-complete-scope.json`. Optional `--reference` and `--output` select another copy of the same pinned sources or a private output path. A source hash mismatch fails the audit.

Ten complete owned candidate intervals were checked against the original main ELF and hashed o0/o2 images: **2,146 instruction-comment words, zero conflicts, 67 omitted words verified to be zero**. Complete geometry candidates were read through returns/delay slots; model-format contrasts use the existing complete conversion reviews plus their owned dispatch/copy contracts. No host geometry routine was executed as a substitute for original instructions.

| Reference file | Definitions | Raw SHA-256 |
| --- | ---: | --- |
| `src/ps2/veronica/prog/hitchk.c` | 30 | `2b67779559c8f6123c94a376d371190196362b76f1c72de963a07996de997612` |
| `src/ps2/veronica/prog/hitchkl.c` | 11 | `6a8efd16093e6e03f0b90b39c0b5f24dda459abe8115d3540e51b0ce3ff43757` |
| `src/ps2/veronica/prog/rutchk.c` | 2 | `76ddb7c481692c70cb2460df1732934a0df0e8b40aef8d2022bbfd1fd9107e71` |
| `src/ps2/veronica/prog/face.c` | 4 | `12ac46d8aff3766173f6aa8d532e8c07e4a60510441d6b9ede27ada84d6fdf76` |
| `src/ps2/veronica/prog/face_bh.c` | 23 | `8579fa4d9b9d54fad1f5082f257bd8a9f1a469f13d333f9ac999a2ab037974b5` |

## Concrete reusable candidates and limits

`bhInOutCheck(p, vertices, normal?, count)` rejects count<3, computes a normal if absent, then tests every closed edge using `normal dot ((next-current) cross (point-current)) < 0`. Boundary values are admitted. `o2:616BD0` performs the related predicate for exactly three XYZ vertices and an obligatory reference vector, but obtains each edge cross through `o0:370640`, which **normalizes** the vector. The latter derives `(point-next) cross (current-next)`, algebraically the same edge cross for finite arithmetic; normalization, operation ordering, zero edges and guest NaN behavior prevent unrestricted equivalence. The caller ignores the normal helper's zero-normal return. This supports a qualified related predicate, not renaming the Outbreak function `bhInOutCheck` or assuming generic convex-polygon safety. The original contract in [collision-grid notes](../SYMBOLS_COLLISION_GRID.md) needs no correction.

`bhCheckInnerP4` is an explicit four-point scanline footprint with caller ordering, three Y bands and **half-open** Y/X admission. Outbreak `o0:370B00` is a three-vertex oriented-area/winding classifier with triangle boundaries accepted; `o0:370C70` sums guest `cvt.w.s` winding and a signed-eight-bit fan score. They are not complete counterparts. The misleading `bhCheckInnerTriangle*` names are not generic triangle utilities at all: they consume ATR_WORK shape IDs, signed dimensions, actor extents and a `rom->h` fallback.

`bhCollisionCheckL2PL` admits front-facing intersections only, checks forward dot and strict distance<length, invokes the polygon predicate, and only on success mutates the second endpoint and global `PLANE`. Outbreak `o2:579300` uses a stored triangle normal/plane, optional side-byte gates, writes an intersection even on later failure, uses angle-sum containment and shifts accepted output by0.001 toward the start. `o2:6169B0` returns crossing classes and has asymmetric zero-denominator output handling. Neither is the same complete CVX line/polygon/global-result protocol. The XZ/XY/YZ rectangle helpers have inclusive rectangle bounds and no *additional local* forward/length gate after `njDistanceL2PL`; do not import the polygon helper's gates into them. `bhGetHitCollisionNormal` reads the associated global, so a generic three-float copy cannot establish its identity.

`_fmGetVChunkType` is a potentially reusable **Ninja-format** lookup, not evidence that Outbreak uses its opcodes. Its offsets/stride are counts of32-bit words. In particular numeric37 (`0x25`) selects four words per vertex in CVX, while Outbreak Clay `0x25` uses seven words/28bytes. Outbreak Clay `0x35` and `0x135` do not appear as those CVX cases. The Ninja routine also ORs facial mode1 for some cases rather than clearing it for others. No case-label, facial mode, vertex stride or model-part identity is transferred. See [Clay conversion](../SYMBOLS_CLAY_RESOURCE_CONVERSION.md) and [raw-mesh import](../SYMBOLS_RAW_MESH_IMPORT_AND_SKIN_WEIGHTS.md).

| CVX vertex type (decimal) | vtop / ntop / stride (words) | mode effect |
| --- | --- | --- |
| 33 | 2 / 6 / 8 | unchanged |
| 34 | 2 / 2 / 3 | OR1 |
| 32,35..40 | 2 / 2 / 4 | OR1 |
| 41 | 2 / 5 / 6 | unchanged |
| 42..47 | 2 / 5 / 7 | unchanged |
| 48 | 2 / 5 / 4 | OR1 |
| 49,50 | 2 / 5 / 5 | OR1 |
| 51 | 16 / 20 / 8 | OR1 |
| default | 2 / 2 / 0 | OR1 |

`bhCollisionCheckL2MDL` parses Ninja vlist/plist and uses aligned `sys->memp` scratch. `fmCnkInitContext` patches counted MASK adjacency, connection, jaw/tongue and keyframe sections into live pointers and binds Ninja face/tooth/eye objects. The other facial functions depend on those formats or CVX actor extensions. Shared matrix, normal, interpolation and VU instructions are already separately reviewable math operations; they do not establish matching complete facial systems or authorize copying BH_PWORK offsets into Outbreak.

## Every reference definition

`G` = reference game-state/ATR format; `F` = Ninja facial format; `M` = Ninja model format; `U` = explicit geometry utility; `H` = global hit-result ownership. All rows are `no-demonstrated-counterpart` within the stated boundary/candidate search, except the explicitly marked related/different predicate. The JSON preserves the full exact machine disposition and witnesses; the following summaries are per complete function, not selected examples.

### hitchk.c

| Reference function / lines | Class | Complete-body disposition and boundary |
| --- | --- | --- |
| `bhCheckWall` 12..638 | G | Resolves actor movement against combined room walp and dynamic mwalp ATR_WORK sets; room height/floor elevations and player/effect/stair flags participate. BH_PWORK/ATR_WORK ownership and response branches are reference-game contracts, not the Outbreak triangle-list ABI. |
| `bhCheckWallEx` 641..1273 | G | Extended room/dynamic ATR wall response mutates actor/player movement and effect flags; uses rom->h and removes temporary step walls. No whole Outbreak actor/ATR layout correspondence established. |
| `bhCheckWall2Box` 1276..1936 | G | Actor box response against room/dynamic ATR walls, with floor-height and signed shape dimensions. Explicit actor and room ownership prevents a generic box-box function identity from its name. |
| `bhCheckWallType` 1939..2043 | G | Returns an admitted room/dynamic ATR wall record after type/height/shape gates. Outbreak grid/triangle queries use another record/filter representation, not a demonstrated identical wall-type enum. |
| `bhCheckWallType2` 2046..2175 | G | Variant room/dynamic ATR shape admission using actor radius/height and bounding-sphere/triangle helpers. Return-record and room height contracts remain CVX-specific. |
| `bhCheckWallRefAngle` 2178..2901 | G | Full wall response traverses room/dynamic ATR records and calculates reference angles after shape-specific adjustments. Not a standalone angle or line-distance library helper. |
| `bhSetWallRefAngle` 2904..3554 | G | Single supplied ATR wall response still uses rom->h, actor fields and CVX shape/attribute encoding. No correspondence to an Outbreak angle-control field is inferred. |
| `bhGetGroundPosition` 3557..3696 | G | Searches room/dynamic ATR walls for ground height and publishes selected record in sys->htp; room height fallback and shape IDs are part of its complete contract. |
| `bhCheckInnerTriangle` 3699..3893 | G | ATR_WORK signed width/depth, id-selected triangular footprint, actor width/height and rom->h fallback; may delegate expanded footprint to bhCheckInnerP4. This is not arbitrary three-vertex point containment. |
| `bhCheckInnerTriangle2` 3896..4090 | G | ATR_WORK triangular footprint variant using separate box extents plus vertical overlap and rom->h fallback. Name similarity does not transfer generic triangle API or record layout. |
| `bhCheckInnerTriangle3` 4093..4136 | G | ATR_WORK id-selected triangular footprint plus vertical interval using hp->h or rom->h. Consumes encoded bounding shape rather than three explicit XYZ vertices. |
| `bhCheckBox` 4139..4324 | G | Mutates query position/angle through CVX ATR dimensions, corner flags, height fallback and radius response. Not equivalent to a stateless AABB predicate. |
| `bhCheckBox2Box` 4327..4422 | G | ATR box/actor extents response with signed dimensions and rom->h fallback. Complete record/response contract differs from Outbreak triangle geometry helpers. |
| `bhCheckInnerP4` 4425..4585 | U | Pure four-point X/Y scanline footprint: requires caller ordering, accepts Y in [p0.y,p3.y), chooses three Y bands, swaps interpolated X endpoints and accepts [min,max). Outbreak o0 triangle/fan helpers use oriented areas/winding and inclusive triangle boundaries; no complete same ordered-quad half-open body demonstrated. |
| `bhCheckExmAtari` 4588..4962 | G | Scans room/dynamic etc ATR interactions and mutates player modes, doors, camera, input, messages and interaction flags. Geometry is embedded in CVX gameplay state transitions. |
| `bhSetUseKaidanFlag` 4965..5002 | G | Binds actor kdnp/kdnidx to room/dynamic stair ATR records and changes paired record flags. Reference stair ownership/index convention is not a reusable geometry API. |
| `bhClrUseKaidanFlag` 5005..5047 | G | Uses actor stored stair pointer/index to clear paired room/dynamic ATR flags. No Outbreak actor offset/flag identity follows. |
| `bhSetDansaLimitAtari` 5050..5213 | G | Scans step ATR records and appends temporary barriers to sys->mwalp while changing actor step state and sys->dla_n. This is reference room-state construction, not generic polygon generation. |
| `bhCheckDansaAtari` 5216..5242 | G | Returns an active type2 step ATR matching floor and inclusive XZ bounds from room/dynamic etc sets. Specific type/parameter encoding remains reference-only. |
| `bhCheckFloorP` 5245..5388 | G | Floor/step response combines actor/player state, room/dynamic floor ATRs, sound/effect fields and sys callback flags. No whole Outbreak collision/actor contract established. |
| `bhCheckDansa` 5391..5431 | G | Clears/sets actor stflg bit20000 from room/dynamic step ATR and actor mode gates. Not a standalone geometric containment predicate. |
| `bhCheckFloorSound` 5434..5471 | G | Selects prm0 sound value from type1 floor ATRs, with actor stflg10 and attr1 priority behavior; floor tables and attribute semantics belong to CVX. |
| `bhCheckFloorEnemy` 5474..5500 | G | Returns first active type2 floor ATR containing XZ at selected floor; room/dynamic list layout is a concrete reference format boundary. |
| `bhCheckFloorEffect` 5503..5529 | G | Returns first active type3 floor ATR containing XZ at selected floor. Shared box arithmetic does not identify an Outbreak floor-effect record. |
| `bhCheckWater` 5532..5558 | G | Selects active type3/prm0=1 floor ATR by inclusive XYZ volume; its water classification comes from CVX floor format, not a shared triangle type enum. |
| `bhCheckL2Water` 5561..5626 | G | Tests line against upper Y plane of type3/prm0=1 floor ATRs with forward strict dot, segment-distance gate and XZ bounds; returns ATR pointer. Format/list ownership differs from raw plane helpers. |
| `bhResetAtariAttr` 5629..5709 | G | Rewrites wall/etc/floor ATR attributes across room and dynamic tables, including ceil-based room/floor interpretation. No generic geometry or Outbreak record correspondence. |
| `bhCheckPlayer` 5712..5785 | G | Actor/player cylindrical push response reads BH_PWORK flags, offsets and EXP_WORK pose, mutates both actor coordinates/status. Not a reusable vector or distance function identity. |
| `bhCheckEnemies` 5788..5878 | G | Iterates sys enemy work array, tests BH_PWORK cylinders and averages accepted displacement candidates. Actor table/layout and admission flags are reference-game contracts. |
| `bhCheckWallAttrB89` 5881..5907 | G | ATR attribute bits and sys->st_flg choose wall admission. No cross-game identity for those numeric bits is demonstrated. |

### hitchkl.c

| Reference function / lines | Class | Complete-body disposition and boundary |
| --- | --- | --- |
| `bhCollisionCheckLine` 12..46 | G | Scans room walp plus sys dynamic mwalp ATRs and dispatches full shape-specific line routine. Return ATR and input endpoint mutation belong to CVX room format. |
| `bhCollisionCheckLine2` 49..83 | G | Variant admission over combined room/dynamic wall ATRs before same line-shape dispatcher. No transferred shape flags or Outbreak grid-cell correspondence. |
| `bhCollisionCheckLine3` 86..120 | G | Further room/dynamic wall admission variant; complete wrapper depends on ATR flags and CVX room list ownership, not just a generic segment loop. |
| `bhCollisionCheckLineMain` 123..630 | G | Shape/type-dispatching ATR line collision with hp->h fallback to rom->h, reconstructed faces and CVX attributes. The Outbreak precomputed triangle/plane record and one-sided gates differ. |
| `bhCollisionCheckL2PL` 633..679 | U | Explicit polygon, but front-face dot<0, forward dot>=0, strict distance<segment length and bhInOutCheck gates precede mutation of p2 and global PLANE. Outbreak579300 instead uses optional side byte, precomputed triangle plane, strict opposite endpoint direction, angle-sum containment and accepted0.001 backoff; not the same full function. |
| `bhInOutCheck` 682..732 | U | **Related/different**: Related oriented-edge halfspace predicate: num<3 returns0, optional reference normal else computed normal, every closed polygon edge rejects n dot(edge cross(point-vertex))<0. Outbreak616BD0 fixes three edges and normalizes each cross via370640 before dot; related finite nondegenerate triangular mechanics, different arity, fallback and degenerate/NaN behavior. No original API-name identity established. |
| `bhCollisionCheckL2MDL` 735..788 | M | Ninja NJS_CNK_MODEL vlist/plist interpretation, transformed center/radius broadphase, aligned sys->memp scratch and polygon index traversal. Outbreak Clay/raw-mesh formats and scratch/resource ownership are different; shared matrix/line calls do not identify the mesh parser. |
| `bhCollisionCheckL2XZPL` 791..828 | U | Builds signed Y-normal plane, calls njDistanceL2PL and tests inclusive XZ rectangle, then changes p2 and global PLANE. No additional explicit forward/length gate locally. Outbreak6169B0 returns side classes and has asymmetric zero-denominator writes; no same rectangle/global-result API. |
| `bhCollisionCheckL2XYPL` 831..868 | U | Signed Z-normal plane with inclusive XY rectangle and global PLANE/p2 mutation; no local additional forward/length gate. Related plane arithmetic does not supply an identical Outbreak complete body. |
| `bhCollisionCheckL2YZPL` 871..908 | U | Signed X-normal plane with inclusive YZ rectangle and global PLANE/p2 mutation; no local additional forward/length gate. Outbreak plane crossing helper has another output/classification protocol. |
| `bhGetHitCollisionNormal` 911..916 | H | Copies three components from file-global PLANE written by the line helpers. Outbreak579300/6169B0 publish via caller outputs; no connected same global hit-state getter/setter contract demonstrated. Generic three-float copy is insufficient function identity. |

### rutchk.c

| Reference function / lines | Class | Complete-body disposition and boundary |
| --- | --- | --- |
| `bhCheckRoute` 5..44 | G | Resolves current/next route box IDs, indexes rom->ruttp[rut_n*next+current], and writes selected rom->rutp ATR box center. Reference room route lookup/format, not a generic graph solver. |
| `bhCheckRouteID` 47..63 | G | Scans rom->rutp ATR boxes with inclusive XYZ bounds and returns byte ordinal orFF. No Outbreak route table or ATR layout correspondence inferred from shared containment arithmetic. |

### face.c

| Reference function / lines | Class | Complete-body disposition and boundary |
| --- | --- | --- |
| `bhInitMask` 7..76 | G | Allocates actor exp0/exp1 MASK_WORK/exp2 LIP_WORK, binds actor mskp/ML_WORK and hardcoded parts6..14, initializes face/lip state. No complete Outbreak actor extension or facial-part correspondence established. |
| `bhControlMask` 79..245 | G | Actor exp0 state machine, sys game/loop gates, frame/lip selection and hardcoded jaw/eye/tongue object angles. Ninja facial parameter processing is embedded in CVX actor scheduling. |
| `bhSetMask` 248..289 | G | Selects size-prefixed sys->mspp mask entry with sentinel/actor ID rules and stages actor exp0 frame/pointer/flags. No demonstrated Outbreak serialized facial block format identity. |
| `bhSetLip` 292..329 | G | Selects size-prefixed sys->lspp lip entry into actor exp0/exp2 state with sentinel rules. No transferred lip index or actor layout. |

### face_bh.c

| Reference function / lines | Class | Complete-body disposition and boundary |
| --- | --- | --- |
| `fmSetLipSyncParam` 9..64 | F | LIP_WORK timing/sequence selects PARAM_WORK facial muscle interpolation with mask and transient fade state. Complete format/state contract is not a generic interpolation routine. |
| `_fmSetObjP` 67..107 | F | Clones/rebinds Ninja object tree into ML_WORK arrays using bhGetFreeMemory and fixed sibling stack. No complete Outbreak scene/actor tree ABI demonstrated. |
| `_fmCnkSearchObject` 110..181 | F | Model-bearing DFS ordinal lookup excludes child traversal for selected MASK_WORK eye/tooth/tang IDs. Not an unfiltered generic object-tree lookup. |
| `_fmGetVChunkType` 184..269 | F | Ninja first-u16 vertex opcode selects vtop/ntop/vofs in32-bit words and sometimes ORs mode1. Numeric37(dec=25hex) has4-word stride here versus7-word Outbreak Clay25hex; Clay35/135hex are not this table. No shared opcode identity. |
| `_fmCnkSetFaceObject` 272..291 | F | Clones selected Ninja model header, allocates/copies mutable vertex stream using count*vofs+128 words and installs into facial object. Distinct from Clay DMA/VIF conversion. |
| `_fmCnkSetEyeballObject` 294..374 | F | Builds/relinks facial eye Ninja objects and matrices from selected model/root transforms and MASK_WORK eye slots. No original Outbreak eye-part layout established. |
| `_fmCnkSetTangObject` 377..427 | F | Clones/relinks Ninja tongue object/model and mutable vertex storage into MASK_WORK. Format ownership is specific to facial context, not shared raw mesh import. |
| `_fmCnkSetToothObject` 430..461 | F | Relinks/copied Ninja tooth object into MASK_WORK facial subtree. No matching complete Outbreak object-edit contract found. |
| `_fmCnkSetJaw` 464..516 | F | Reads facial source vertex stride/indices, derives jaw orientation with atan/inverse-square-root and constructs Ninja matrices/object state. Pure math subexpressions do not identify complete jaw routine. |
| `fmCnkInitContext` 519..599 | F | Patches MASK blob counted adjacency/index lists into destination vertex pointers, binds face/tooth/tongue/nine eye IDs, jaw lists and PARAM_WORK frames, and rebuilds ML_WORK arrays. This establishes a reference serialized format boundary. |
| `fmCnkSetParam` 602..605 | F | Copies one whole PARAM_WORK into MASK_WORK.param; no original Outbreak same parameter size/layout or connected producer established. Generic memcpy is not new mapping credit. |
| `fmCnkSetParamLip` 608..627 | F | Copies masked32 muscles and lip/jaw/tongue fields, converting integer-reinterpreted angles by0.005493164f. It is not a generic float tuple setter. |
| `fmCnkSetInterParam` 630..678 | F | PARAM_WORK flag selects linear/square/sqrt/half-cos/zero rate, masked32 muscles and jaw/tongue level scaling, unscaled eye interpolation. No whole same Outbreak parameter structure proven. |
| `fmCnkSetInterParamLip` 681..728 | F | Same rate family but integer-reinterpreted lip-angle interpolation with0.005493164f and no eye update. Not interchangeable with ordinary PARAM_WORK interpolation. |
| `fmCnkSetCurrentFrame` 731..758 | F | Scans PARAM_WORK frame keys by unsigned-cast query, snaps endpoints or calls context interpolation. No zero-count protection; this is facial-key format handling, not generic game-clock mapping. |
| `fmCnkGetLastFrame` 761..764 | F | Reads face[fnum-1].frame without local count guard. No same Outbreak facial-key owner/structure established; one indexed load alone cannot prove identity. |
| `_fmCnkCalcMuscle` 767..930 | F | MASK connection/vertex lists and32 muscle influence arrays drive in-place Ninja vertices through scalar and EE/VU macro instructions. Generic vector arithmetic does not establish same facial data/opcode pipeline. |
| `_fmCnkCalcJaw` 933..1104 | F | Uses facial jaw influence lists, Ninja vertex stride, object matrices and jaw angle/translation with EE/VU macro operations. No Outbreak jaw-index or modelpart contract established. |
| `_fmCnkCalcEye` 1107..1221 | F | MASK eye slots/context transforms and Ninja vertex data drive eye orientation/deformation, including atan/inverse-square-root. No same complete pipeline or model part ownership proved. |
| `_fmCnkCalcTang` 1224..1318 | F | Facial tongue list/object transforms and parameter angles update Ninja vertices using EE/VU macro operations. No cross-game tongue format mapping from the name. |
| `_fmCnkCalcNormal` 1321..1364 | F | Facial adjacency/VLIST_WORK normal-pointer pairs accumulate polygon normals then normalize into Ninja vertex records. Outbreak normalized triangle helper is shared arithmetic only, not this adjacency/stride body. |
| `fmCnkCalcFace` 1367..1381 | F | Dispatches muscle,jaw,tongue,eye calculations and conditionally normals based on MASK mode1. Not an Outbreak render/actor frame scheduler. |
| `fmCnkSetMode` 1384..1401 | F | On0->1 copies stored normal quadwords in8-word-stride Ninja vertex records then assigns MASK mode. No same mode bit/stride transition established in Clay conversion. |

## Owned candidate identity receipt

These entries are comparison evidence, not 10 newly mapped functions. Existing authoritative labels and full contracts remain in their original notebooks.

| Owned interval | End exclusive | Original interval SHA-256 | Verified words / omitted zero words |
| --- | --- | --- | ---: |
| `main:18A260` | `18B2BC` | `2bead31948e7cd59fe836977a7eb5b76ba9e8fee173f20727bb09d290b7971ca` | 1000 / 47 |
| `main:1A45A0` | `1A4C68` | `26b02ef3118372d2e1465ea571d0b7b50c996a732e87f4ced1748c5ccd6d43be` | 427 / 7 |
| `o0:370640` | `3706D0` | `23bc3e38da3cb083db4dc5ca577badf8ee969a69186cdb9f2148ccf6c89804b7` | 36 / 0 |
| `o0:370AC0` | `370AF4` | `d74ba16cd1ef6de8bdd90cbc4b4a6c0f3221a9f2e2f2ac3ed26ce85722db3ecb` | 13 / 0 |
| `o0:370B00` | `370C6C` | `e85bfb8d313c0917b7e99f44312aa5a24f5e6ba57d9c462833da50d665b471bd` | 91 / 0 |
| `o0:370C70` | `370DD0` | `0fbfd247378b4eae36fc8d00711b4bcf6ed1607e4a4becc4a312483dd9449b1e` | 86 / 2 |
| `o2:579300` | `5795DC` | `8b5d6870749ab312ab0610d74ad88889886057f0c213cc1323142c3cc01429d3` | 180 / 3 |
| `o2:6169B0` | `616BC4` | `3fc8d1fddb911cb324c9e710e96bcb38f4ccee05d71b43c7673ebc7da7a8324e` | 127 / 6 |
| `o2:616BD0` | `616CB4` | `5ba3916a6940469c9636956512c0383dfa51515078813aeaa5e5999d9bdd2eb5` | 57 / 0 |
| `o2:616CC0` | `616ECC` | `38f09260144b68e20b510f74aa9ea9e7a293cbdf3cc7fd3e29e9f0c76ec5c445` | 129 / 2 |

No material error in the existing Outbreak geometry/model annotations was proven by these comparisons. Remaining gaps are precise: no same ATR/RDT/BH_PWORK route/collision ownership; no connected same PLANE global-result protocol; no same ordered-quad half-open body; and no same Ninja MASK/vlist facial format in the inspected Clay/raw-mesh consumers. These findings preserve room for another original caller/body to supply stronger evidence later.
