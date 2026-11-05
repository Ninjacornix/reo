# Scoped CD-worker candidate validation

2026-11-05. Status: revised separate candidate built and three bounded controlled
sessions completed. This record covers the worker lifetime pilot, not
a migrated native resource provider or complete cvFs backend.

The first coherent runtime/backend/game build (v2) used source commit
`a54c6f3efe052c21be8df0c8a38034d44a530604`, manifest
`24ec65e6e517db093638ac9b729c2a29157b1254926acad63bc37637f6fc506e`
and the fully reapplied 121-patch dependency receipt
`2b8088a430a63517ad2a77910970e37bccf9658e3c7c91ac6525a70b1db0cca8`.
It failed compiling the CD owner: bundled libc++ does not implement
`atomic<shared_ptr<Session>>`. No v2 executable or gameplay validation resulted.
The retained log/result are under `build-native-sjuni/candidate-work-v2`.

Local fix commit `f5b5ff115f1395087fc460f3ec26975decc24392` uses a short owner
registry mutex and narrows admission to 2048-byte sectors, matching packet
pointers, zero head/tail edge-copy counts and no overlap with callback metadata.
It rechecks edge-copy counts under guest execution before dispatch. Unexpected
post-publication metadata is diagnosed without replay; recovery remains open.
Fourteen host scenarios and actual-header object compilation pass with GCC 15.2
and the pinned LLVM-MinGW 20251216 compiler. Receipts are under
`build-native-sjuni/cd-owner-checks` and `cd-owner-checks-llvm`.

The isolated validation revision
`f2a51ba5824891702290ea453b0c00092267c01c`
(`test/native-cd-owner-v2c`) applies the identical production adapter fix to the
v2 baseline. The checkout stays on `fix/cri-async-cd-read`; later resource-source
changes are deliberately excluded from this worker-only comparison. The v2c
manifest is `30232539ff70457a20a7e0bb2c5eed0270c7e107cb32e073c2f44ce99ba7dce0`.
Comparing manifests confirms only the production adapter and provenance records
changed; every source header is identical. A preliminary v2b preparation included
changed mock test headers and was not built or used as cache validation.

V2c uses a fresh work/output directory and seeds only verified object/receipt
pairs from the failed v2 build. Ordinary compilation recomputes every signature;
no runtime archive, precompiled header, generated source or build-input marker
is copied. Toolchain/sysroot and sealed inputs are fully verified again.
Detailed cache evidence is in the private work directory. The build passed in
307.594 seconds: 2,352 units, 2,258 signature-verified cache hits and 94 freshly
compiled objects, with newly created archives and link output. Executable SHA:
`7b3d9368d250db173c726ddcbe307df8966feab85261c29640044732a54c765d`.

## Controlled sessions

All runs used a private copied image, fresh test card, process creation identity
and logs under `build-native-sjuni/playtests`. All three received identity-checked
ordinary `WM_CLOSE`, exited with code 0, were already exited when supervisor
cleanup ran, and had no classified fatal diagnostics. No player build/save or
Windows Firewall policy was changed.

| Session | Explicit mode and observed scope |
| --- | --- |
| `cd-original-gameplay-v2c` | Native CD owner off, SJUNI off; 114.797 seconds. Gameplay reached at 50.045 seconds, measured actor movement to the interaction, message, inventory, pause/quit, results and fresh main-menu proof. |
| `cd-native-gameplay-v2c` | Native CD owner on, SJUNI off; 147.031 seconds. Gameplay at 53.320 seconds; same input-only interaction/return flow, at least 256 dispatcher callback returns and session-joined proof. Renderer frames show loading and the returned main menu. |
| `cd-native-pak-v2c` | Native CD owner on, SJUNI off; 252.579 seconds in actual imported PAK mode with intentionally unavailable ISO launch path. Gameplay at 53.455 seconds, movement/interaction soak in room 1, read-only actor snapshot and renderer frames showing the bar/characters. At least 256 callback returns, session-joined proof and no explicit owner failure. |

The PAK run's source ISO was checked only for import provenance before launch;
the game received a nonexistent path inside its private working directory and
`REO_GAME_PAK=1`. The existing facade reported its actual PAK mode. This scopes
the observation to that run; it does not establish every edition/scenario's
direct-disc independence or remove the compatibility runtime.

The audio counters report zero underrun frames in all three runs. Signal frames
were 517,188 / 525,348 / 9,581,827 respectively, with host output ready in every
reported window. These are output counters, not waveform or subjective audio
equivalence. GPU readback was enabled only in the two native runs to obtain
unoccluded images; the runs are not a controlled performance comparison.

Desktop captures were obscured by other windows, including Windows Firewall's
network-access prompt. They are retained as occluded observations and are not
visual correctness proof. Direct renderer captures are independent of that
prompt. The offline tests did not require accepting network access.

Each completed session has `cd-owner-analysis.json`, source/log hashes,
`run.json`, input exercise notices and a window-close request receipt. The
analyzer accepts native records concatenated after another logger's missing
newline while preserving the full source line. Owner-specific exceptions,
missing continuations, dispatch-limit and metadata-change failures are checked
separately from the generic fatal classifier.

Remaining validation includes repeated scenario loading, actual room transitions,
longer media coverage and output equivalence, stop/close/reuse under controlled
I/O pressure, co-op and File #2. The new verified mount/reader is not compiled
into v2c. These results do not establish general mid-game buffer lifetime,
native resource-consumer migration or speedup.
