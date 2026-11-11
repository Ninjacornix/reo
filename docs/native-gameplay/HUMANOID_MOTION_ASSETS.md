# Native shared humanoid motion preparation

`HumanoidMotionAssets` reads the actual File 1 common and character motion files
through exact ROM ordinals. The reproduced profile identifies 90 common PC files
and eight PLxx_PC_000 character files, totaling 128,323,332 owned bytes. It checks
the 1,342-member common archive, exact member names and bounded extents before
building native immutable motion banks. Asset preparation performs no game calls,
source mutation, device access or simulation-clock advancement.

The immutable publication preserves the actual shared bank destinations:

| Original owner | Native publication view |
| --- | --- |
| 4BC810, cutscene body | `scripted().mode_one` |
| 4BBB80, cutscene face | `scripted().track_two` |
| 4E8970, ordinary common and cutscene head | `scripted().other_modes`, also NPC style 0 |
| 4E6A20, alternate common | `alternate_style()`, also NPC style 1 |
| 4D7000 + 1F44 * character | `character(index)` |
| 4EA8C0, primary initial bank | explicit known initial-clear bank, type zero |

The ordinary common and cutscene head destinations are one bank, not independent
copies named after their consumers. A scene head load changes the same bank later
used by style-0 NPCs. A common overlay subsequently changes that same destination
back to its sparse profile. Snapshots share unchanged banks, retain overwritten
block leases, and preserve absent prior rows exactly as the native sparse/strided
constructors already specify.

`base()` supplies the initial 1D1A80 / 1D19D0 defaults: PC_000, sparse tables 8 and
168, mode 0. Character and cutscene body/face bindings remain explicitly absent.
`overlay(index, characters, previous)` supplies 1D1B10: common sparse mode 1,
then PLxx_PC_000 sparse mode 1 for the explicitly selected characters. It does
not guess a roster. All admitted files and all eight selected-character banks
are compared, including preservation across overlays.

The publication also owns the default-loaded gate. A scene request clears it
even when every requested file is missing. `ensure_base(previous)` returns an
already loaded publication directly; otherwise it applies PC_000 mode 0 over
the current common banks while preserving body, face, character and unrelated
row/block leases, then marks defaults loaded. A failed preparation never mutates
a previously published snapshot. Missing input and default result status stay
explicit rather than claiming loaded content.

`npc_bindings()` supplies actual constructor references from this one coherent
publication. It requires a real cutscene body bank and character banks 3/5 as
well as both common styles. Missing resources are refused. The two admitted
constructor examples use real N103 and HN88 models, actual prepared motion banks,
and the canonical auxiliary pool/model/animation owners. These examples verify
binding; they do not execute every action or decode/play every curve.

Both compiler cohorts pass 267,802 native checks plus 13,350,478 original checks.
They execute 919 bank comparisons and 427,296 original calls, covering 90 common
loads, 720 selected-character loads, 94 snapshot transitions and 66,048 loader
name/gate cases. Complete source-word-audited default, overlay, scene and sparse/
strided constructor bodies execute. Comparisons include all 2,000 physical slots,
logical-row maps, lookup formulas and raw block provenance. Original acquisition,
work-buffer and resource packing/heap handles are declared ports; the native
reader uses actual independently hashed retained archive members.

The complete shared-bank sequence is compared using actual PC_001, r001/d02,
r001/hd02, PC_000 restoration and PC_002 inputs. It verifies the default-loaded
flag, body/head bank contents, alternate and character preservation, the
ordinary/head alias, missing-scene preservation and default restoration. The
source filename checks cover all 16-bit common indices, all byte character
indices and all byte startup-flag values. Native content admission remains the
98 known File 1 aliases; other combinations fail explicitly.

All twelve parent tests passed on both compilers at this checkpoint. The seal
checked the then-unchanged World and behavior production hashes. Subsequent
[live publication work](HUMANOID_MOTION_PUBLICATION.md) changes those consumers
and requires its own current-source regression evidence. Historical receipts
remain evidence for their captured sources. No game was launched and no
performance change is claimed.

Reproduce with `generate_humanoid_motion_members.py` and
`verify_humanoid_motion_assets.py`, explicit compiler/CMake/build/data-root paths
and fresh output folders. Receipts are `humanoid-motion-assets-{llvm,gcc}-v3`;
the combined seal is `native_humanoid_motion_assets_qualification_v1.json`.

The live-publication follow-up supplies explicit NPC/scripted binding updates.
The [retirement follow-up](MOTION_BANK_RETIREMENT.md) additionally supplies
shared character release/reload and the exact primary initial-clear type.
Scene loading/caller ownership,
remaining actions, every curve/event consumer, the 11-NPC capacity conflict,
coherent native game installation and full Step 4 acceptance remain open. The
installed game is still V39. Preparing a bank does not migrate its live callers.
