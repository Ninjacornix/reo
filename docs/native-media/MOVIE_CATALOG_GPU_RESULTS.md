# File #1 movie catalogue: complete offscreen GPU validation

All 201 hash-verified File #1 SFD members completed the native source, parser,
timestamp, D3D11 decoder and Vulkan reader path on the RX 570: 216,998 pictures
decoded and presented. Independent Python selected-E0-payload extraction,
including picture headers split across PES packets, matches every asset's
counts: 12,471 I, 60,729 P and 143,798 B pictures. All six observed geometries
pass. Each movie includes rebuild blocked by an actual unsignaled reader fence,
retirement, and identical first-frame pixels across two graph incarnations.

This is finite unpaced offscreen evidence. No game window, audio device, screen
scanout, cadence, full-stream reference pixels or audible A/V equivalence was
tested. File #2, interlaced material, in-owner rate/dimension changes, embedded
audio, late-frame skip/recovery and corrupt input are not admitted by this run.
File #1 audio requires its separate game ADX/output route.

The first title test failed at EOF: reference time 315000 was presented before
the earlier B-picture at 314000 (denominator 29970). Its producer fence was not
ready when the reference picture became available. `NativeVideoGraph` now
publishes one earliest eligible pending picture, retaining that publication
until its consumer fence retires. This rule also applies at EOF. No timestamp
clamp, picture omission or decoder/reference change hides the failure.

All 316 actual title parser/accounting inputs also match independently executed
owned timestamp/timecode routines: 153,887 instructions, zero complete native
state differences. This checks arithmetic for those inputs, not independent
proof of the parser's accounting provenance. Failed title scopes and pre-fix
source snapshots remain in the ignored evidence directory.

| Receipt below `build-native-sjuni` | SHA-256 |
| --- | --- |
| `movie-pipeline/clean-build-llvm-v2/receipt.json` (70 suites) | `588dd97462d1fa70470bea73e14eeaf6ce1aed5e4653f7d75a19aa098be97789` |
| `movie-matrix/title-v3/receipt.json` | `1faad1a5a10bd2d49f0d82a675d8053e01305ad3bd428d6f9f1acb62b5203311` |
| `movie-matrix/catalog-v1/receipt.json` | `1b34ca947a08bb58761e779fbe04119418db086768d18cbb4379e91071a2a3ab` |
| `movie-matrix/catalog-counts-v1/counts.json` | `c255a4c59bd5fd6e9f6fbadf0092a41b38d4afc22d079287a3755ecfaa6d11bd` |

The catalogue receipt retains all payload/log identities and per-asset results.
`run_movie_matrix_gpu.py` checks an explicit sealed kit, exact compiler, reviewed
allocator provider, CSC shader and clean native libraries. The catalogue runner
reuses that exact qualified binary and verifies each payload before use.
`check_movie_catalog_counts.py` independently counts retained source pictures.
`dump_movie_timestamps.cpp` and `replay_movie_timestamps.py` reproduce the title
timestamp comparison. These tools live in `tools/native_reconstruction`.

The historical 70-suite source cohort is `movie_pipeline_manifest.json` there.
Later scheduler work extends it explicitly. [Stage 3 remains open](STAGE3_CLOSURE.md).
