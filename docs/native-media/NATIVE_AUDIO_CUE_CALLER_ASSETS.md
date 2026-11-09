# Native queued audio: owned caller assets

2026-11-09. This narrows content admission using the real game name lookup;
it does not claim that every named scene has been played.

The five owned o2 scene-name tables contain 323 rows and 236 unique audio
basenames. All resolve through the resident 422-entry complemented name table
to the exact corresponding top-level `adxsnd.afs` member. Each is stereo at
48 kHz, has no enabled inline loop, and passed the previously qualified native
preparation worker's metadata checks. Name normalization preserves the DEMO
prefix and resident table index. Matching inventory basenames alone would not
establish the game's lookup or archive index.

All 69 indexed o1 gallery records and both special movie setups are also
checked. The longest gallery list contains four names; its four-item variant
includes `s359900a.adx`, which is absent both from the original resident lookup
table and from the named archive inventory. The original caller skips an
unsuccessful lookup. At most three names resolve in one gallery list. Existing
entries in each gallery list have compatible channel/rate formats. The E3 and
`demo/s414000a.adx` special paths also resolve and pass native admission.

Across these scene/gallery families, 245 distinct actual audio members resolve;
none is among the 89 inline-loop assets refused by the finite queue profile.
The scene lists' runtime descriptor lengths/order remain separate evidence:
this name-table audit does not establish a universal 16-item capacity bound or
exclude other indirect callers. It does not weaken the admission guard.

`audit_queued_cue_callers.py` verifies both owned overlay hashes, the main ELF,
the corresponding original instruction words, original table/string bytes,
resident sound lookup indices, and the earlier native admission evidence hashes.
Its final report is `build-native-sjuni/queued-cue-caller-tables-v3/receipt.json`,
with per-scene/gallery results in `callers.json`. The qualification manifest is
`tools/native_reconstruction/queued_cue_caller_asset_qualification_v1.json`.
Earlier attempts and source snapshots remain in the private evidence folders.
No game, audio device, asset conversion or save write is involved in this audit.

The first coherent V32 opening/scenario/bar run installed the 22-entry binding
and joined its owners, but accepted zero queued preparations. V33's first
minimized close retest also accepts zero. A separate unlocked test card is used
for the subsequent real gallery caller test; it does not validate natural
progression unlocks or change the player's card. Step 3 remains incomplete.
