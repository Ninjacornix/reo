# Isolated CLUT shadow diagnostics

Status: SOURCE_FINAL, not compiled or run by its author. No live GS source/header was changed. The frozen GS triangle candidate/fixture was not edited. The generator writes only ignored copies in `build-ninja/m2-clut-shadow-proposal`, with a hash manifest and pristine baselines.

The shadow never replaces a sampled color, changes a register, modifies VRAM, submits commands, or waits on the guest/GS queue. It diagnoses the separation between local VRAM palette sources and retained GS internal palette state. Existing triangle/sprite optimization caches are unchanged.

## Coordinator commands

```powershell
python tools/gs_clut_shadow_check/generate.py
# --refresh intentionally rebases existing frozen copies.
tools\gs_clut_shadow_check\run.bat [runtime-build]
```

`run.bat` compiles/runs a synthetic logical model fixture, then a synthetic actual GS fixture OFF/ON and compares **16 complete4MiB VRAM records**. It does not launch the game. Dependencies match other GS fixtures. The coordinator owns running this script. Python syntax and source generation were checked; there are no compiler, fixture PASS, or performance claims yet.

## Model scope

The model has512 raw16-bit words, per-word certainty/load serial/source byte offset/load CSM, and two remembered CBPs with explicit certainty. It preserves untouched internal banks and splits CT32 values into low/high planes. It tracks TEX0 and TEX2 loads and shared palette use across contexts. TEXA stays outside the raw palette model.

Covered documented combinations: CSM1 CT32/CT16/CT16S, T4 CSA0â€“15/0â€“31, T8 CSA0; CSM2 CT16/CSA0/nonzero CBW and horizontal COU*16. CLD0 retains;1 reloads;2/3 reload and remember CBP0/1;4/5 compare and update the corresponding pointer when loading. Nonindexed formats do not change remembered pointers. Conditional loading before a remembered pointer is witnessed stays uncertain; initial CBP contents are not guessed zero.

Nonzero-CSA T8 load/read clamping, CT24 palettes, CSM2 CT32/16S or nonzero CSA/zero CBW, invalid CSA, reserved CLD6/7, unavailable VRAM, and CSM reinterpretation without reload are explicitly uncertain. Unsupported permitted loads invalidate certainty instead of inventing which banks survive. PCSX2 supports hardware-observed extensions beyond this manual-based scope; an independent oracle is needed before implementing them here.

Official basis: Sony GS User's Manual v6.0 sections2.7/3.4.7 and TEX0 table describe a1KB temporary palette, loads on TEX0/TEX2, preservation of other banks, fixed CSM1 sources, CSM2 horizontal CT16 entries, and CSA/CLD control. [Archived Sony manual](https://github.com/ninjadynamics/PS2Docs/blob/main/GS_Users_Manual.pdf). The downloaded/extracted copy stays ignored. Reference checks: [PCSX2 GSClut](https://github.com/PCSX2/pcsx2/blob/master/pcsx2/GS/GSClut.cpp), [Play! GSHandler](https://github.com/jpd002/Play-/blob/master/Source/gs/GSHandler.cpp). The model is newly written; tracked files contain no copied emulator implementation or game microcode.

`Reason` values:0 none;1 no-load;2 unsupported index;3 reserved CLD;4 unknown initial CBP;5 unsupported format;6 invalid CSA;7 unsupported CSM2;8 T8 offset;9 unavailable source;10 unknown entry;11 CSM reinterpretation.

## Bounded primitive logging

Enable `REO_GS_CLUT_SHADOW=1`; default off. False path has only a configuration branch: no palette copies, model allocation, primitive packing, clocks, or logging. Reset establishes session state/timing. Loads are tracked before the comparison window so earlier palettes are retained. Tracking stops at262144 load events; a clock check every256 events enforces the window even if no relevant primitive is reached. Finishing disables both loads and comparisons. Reinitialize/reset clears certainty, counters and load history.

| Option | Default | Bound/meaning |
|---|---:|---|
| `REO_GS_CLUT_SHADOW_AT` |70| Seconds from printed GS-reset epoch ns |
| `REO_GS_CLUT_SHADOW_SECONDS` |60|0.001â€“60s window |
| `REO_GS_CLUT_SHADOW_COUNT` |512|1â€“4096 eligible comparisons |
| `REO_GS_CLUT_SHADOW_LOG_LIMIT` |64|1â€“128 evidence lines |
| `REO_GS_CLUT_SHADOW_ZBP` |224| Room depth-buffer filter |

Relevant primitives: plain T4/T8 textured triangles/strips/fans/sprites, FBP0/112, configured ZBP, finite screen-space bbox intersecting `(143,0)â€“(359,130)` in the512Ã—448 first-room view. Bbox relevance is **not coverage or pose proof**. Camera/menu changes invalidate visual interpretation. Clock/palette reads occur only at primitive boundaries on the GS producer before row workers. No pixel clocks/logs. Each comparison reads at most256 entries (16 for reached T4). It compares retained raw words with the existing live-lookup formula, separately from the hardware source formula.

Logs include event serial/generation, context/primitive/frame/test/Z/alpha/clamp/TEX0/TEXCLUT/TEXA, bbox, unknown count/reason, full-palette hashes and first differing index/raw values/load serial/source offsets. The128-entry load-record ring reports `load_record_known=0` if metadata was evicted. Every eligible primitive counts; first/mismatch/unknown evidence lines print within the cap. A difference proves potential palette divergence, **not that its index was sampled or caused the lamp dropout**. The explicit verdict is `potential_full_palette_not_used_indices`. Summary counts distinguish no eligible primitives from no differences; cap/window endings are explicit.

## Minimal integration guidance

The isolated GPU delta includes the private helper, resets after drain/GS state ownership, and calls the loader after both existing TEX0/TEX2 parses. The rasterizer calls inspection once from `drawPrimitive` before row jobs. No public headers/API/layout/sampler/writer/queue semantics change. Its baseline contains the root-integrated triangle batch source; state barriers flush earlier triangles before a new shadow load. The fixture disables batching; batch+diagnostic compatibility has not been executed.

After review/fixtures, root may apply these hook sites and private helper selectively. Native evidence should accompany an already changed build rather than another unchanged boot. Use stationary first camera and printed epoch, with cache/parallel/pace settings fixed. Observer cost is not a frame-rate improvement.

Optional `ps2GsClutShadowStateJson(gs)` exports raw words, certainty, CBP certainty, generation and per-entry provenance. It is **not automatically wired into0060**. Call only at its immutable worker publication marker under GS state ownership. `finished=true` denotes a stopped historical shadow. Complete Aâ†’Bâ†’C replay still requires all renderer/GIF/transfer start state and every ordered command between selected same-FBP markers. Truncated history, unknown words, unsupported combinations or omitted buffers prevent faithful replay claims. See `build-ninja/m2-room-flicker-clut-audit/audit.md`.

## Fixture coverage

`core.cpp` uses an independent logical reader and manually specified diagram coordinates. Controls cover T4 8Ã—2/CSA bank preservation; T8 index8=(0,1),16=(8,0),255=(15,15); CLD0â€“5; same/different CBPs; nonindexed suppression; unknown initial CBP; unavailable source; raw16/32 storage; CSM2 COU*16 horizontal addressing; unsupported transitions and reset.

`integration.cpp` submits actual PACKED A+D, IMAGE transfers and original vertex kicks. A known rendered pixel must still use current live color while the shadow disagrees. OFF/ON16-record full-VRAM equality verifies observation leaves drawing unchanged. Controls cover initial unknown palette, post-load IMAGE overwrite+CLD0, conditional same/different pointers, TEX2 reload, shared contexts, CSM1 TEXCLUT independence, CSA bank/source separation, reserved controls, undocumented CSM2/CT24, documented CT16 CSM2 horizontal sources, CT16S last bank, T8-offset uncertainty, initial conditional-pointer uncertainty, and GS stop/join/reinitialize. Statistics assert actual hook reach and expected differences/uncertainty; OFF must remain zero. These expected outcomes are not observed until the coordinator runs them.

A production retained-CLUT correction would intentionally change old live-fetch alias expectations and needs separate semantic controls. Existing cache optimization parity does not establish hardware fidelity.

## First validation and source-only fixture repair

Coordinator validation1: core51 checks PASS; integration OFF16 records/49 checks PASS, ON one failed divergence assertion in case10. All OFF/ON full-VRAM records were equal. The original logs/records remain at `build-ninja/m2-clut-shadow-proposal/{off,on}.{log,vram}` and the root transcript is `build-ninja/m2-clut-shadow-validation1.log`.

The failure was a fixture precondition, not evidence against the model: CT16 IMAGE upload currently falls through the renderer's linear row writer. Its16 words of0x8421 were at0x2EEA40, while all16 intended GS CSM2 source addresses0x2EE888..0x2EE8BE remained zero. Thus both shadow and live palettes correctly read zero in that setup. Exact existing-record evidence is `validation1-case10-address-evidence.json`. This also exposes a separate CT16 upload semantic defect in production; this diagnostic does not repair it or claim that original room geometry reaches it.

Cases10/11 now seed known raw16-bit VRAM words at independent diagram-derived byte offsets and assert initialization; case10 independently checks the current live entry8 source stays zero. They retain the expected divergence. The actual CT32 IMAGE mutation/control still uses submitted packets. Core/model/hook/candidate sources are unchanged. Revised integration expectation is16 records/52 checks, pending the coordinator's run.

`run.bat` now writes executables/logs/VRAM/parity into a **new** results directory, default `build-ninja/m2-clut-shadow-proposal/validation2`; existing directories are refused so prior failures remain intact. An explicit second argument selects a fresh directory:

```bat
tools\gs_clut_shadow_check\run.bat third_party\PS2Recomp\out\build build-ninja\m2-clut-shadow-validation2
```

Do not regenerate candidate copies merely to update fixture hashes. Their existing baseline/diagnostic identities remain frozen; the manifest records updated fixture identities and the validation1 repair note. No repaired fixture has been compiled/run by this agent.
