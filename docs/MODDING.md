# Creating a simple Outbreak mod

Gameplay mods use a JSON file; asset replacement mods use a `.pak` ZIP. Anyone can create and share a mod; an existing compatible game build does not need rebuilding when enabling a new package. Asset packs support both File #1 and File #2 in solo play. Gameplay JSON mods support both games; each package targets one edition. Lua scripts, DLL plugins and PS2 instruction patches are unsupported.

## Asset replacement packs

Import a `.pak` from **Mods**, then tick it. The page shows packs for the selected
game, their versions and replacement counts. Switching games preserves each game's
enabled packs. The Play page shows the active asset-pack count. Disable packs before
hosting or joining co-op. An older native game build is refused with a rebuild message.

An asset pack replaces existing native game files, including textures, models, text,
audio and movies. It does not convert formats, enable PCSX2 texture packs or add frame
interpolation. Use suitable format-specific editing tools. Game memory limits still
apply; accepting a large file does not guarantee the game can load it.

The ZIP needs root `pak.json` and replacement files:

```json
{
  "format": 1,
  "id": "example.translation.file1",
  "name": "Example translation",
  "version": "1.0.0",
  "game": "file1",
  "elfSha256": "06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46",
  "replace": [
    {"path": "NETBIO00.DAT/0/551", "file": "files/edited-font.tm2"}
  ]
}
```

For File #2 use `game: "file2"` and executable SHA-256
`5c0411a26247ef9974cd94b844ac5aecbcbf4705db543f51814aeed89da0fd8d`.
IDs must be unique across installed packs. Each replacement may specify `baseSha256`;
a mismatch rejects the pack rather than applying it to the wrong original asset.

Paths address zero-based archive entry indices. Unique names can also be used, or
mixed with numeric indices, for example `NETBIO00.DAT/romdata_usa.afs/#551`. Numeric
paths are recommended: File #2 has many sound entries named `SOUN`. Replacing an
entire nested AFS, a room's `_h.bin` name table, DUMMY padding, code overlays or the
executable is unsupported. Entries cannot be added, removed or reordered. Two enabled
packs replacing the same resolved entry are rejected, naming both packs.

Each payload is limited to 256 MiB, each ZIP to 10,000 members and 2 GiB expanded,
each pack to 4,096 replacements, and the session to 4,096 replacements. Virtual AFS
files must remain below 4 GiB. ZIP paths cannot be absolute or contain `..`, links,
duplicate members, Windows device names, or components ending with dots/spaces.
A loose development folder with the same `pak.json` layout
can be placed in the launcher's data folder under `mods/assets/`.

Original imports stay archived and unchanged. The launcher builds a small metadata
index on demand, hashes targeted original entries, and caches ZIP payloads under
`asset-cache/<pack-sha256>/`. Later launches reuse verified cache files. Loose packs
are read again so edits apply on the next launch. The session's `asset-overlay.json`
is a readable receipt; `asset-overlay.bin` is its bounded, versioned native input,
passed using `REO_ASSET_OVERLAY`. The runtime checks executable and payload identities
again and streams virtual archives from original ranges plus replacement files.
No enabled packs leaves the original disc path active. Exact-byte replacements also
leave their original archives intact.

### Exporting original assets

After choosing an ISO, open **Game files** and tick **Export original assets to
.pak files during setup** before importing. This optional setting starts off
unchecked and is saved separately for File #1 and File #2. **Export now** also
works with an already imported game. **Open exports folder** opens the results.

Each game exports **one `original-assets.pak` containing all original NETBIO leaf
assets**, including textures, models, audio, movies and reference name tables.
The files keep their native formats; this does not convert everything to a common
texture/model/audio format. Updated exports also include private game boot data
and archive metadata so the PAK can be selected as a game source. These additional
files are separate from the editable leaf index and must not be distributed.

For **both File #1 and File #2**, the same PAK automatically includes an
`executable-strings/` folder with editable CSV/JSON, original encoded bytes,
addresses and byte limits. No separate script or second PAK is needed. Re-export
older packs with **Export now** to add these references; previous exports are kept.

Results live under the selected storage folder at
`asset-exports/<game>/<source-identity>/single/`. Export requires extra disk space
and time to compress and verify every file. The launcher checks available space
first and shows progress with **Cancel setup**. Canceling or failing an export keeps the
imported game and completed exports. Completed exports are reused when the source
and output size/timestamps still match. If an export was edited, a fresh version
goes into a new folder and the previous export is kept.

To apply edits, keep your original ISO or unmodified game PAK as the game source.
Edit a copy of the exported PAK: replace selected native asset payloads or fill in
string translation fields, preserving their original metadata. Open **Mods → Import
mod**, choose the edited PAK, then tick the imported pack. The launcher scans the
export and creates a replacement mod containing only changed assets and translations;
this needs no Python. Import runs in the background and supports cancellation.
An unchanged export has nothing to install. Protected name tables and code remain
unsupported. Keep full original and edited game exports private.

Alternatively, unzip the reference pack and copy selected files into a separate
edited folder, preserving their relative paths. Use the packer below to produce
an installable replacement pack suitable for sharing your own changes.

Alternatively, extract assets from your own existing import using Python:

```powershell
python tools/assets/extract_assets.py "<import>/data" "<new-reference-folder>"
```

### Playing from PAK instead of ISO

In **Game files**, turn on **Use PAK instead of ISO**, then **Choose PAK** and
select your exported `original-assets.pak`. Press **Import** or **Play**. Each
game remembers its own source switch and paths, so switching back to ISO keeps
your previous selection. A completed launcher export also remembers its PAK path,
so you can simply turn on the switch afterward. An older asset-only export or a replacement mod PAK
cannot boot the game; export again with the updated launcher.

First use verifies the PAK and prepares ordinary game files under
`imports/<game>/pak-<checksum>/`. Matching existing imports on the same local
NTFS drive are verified and reused through hard links, avoiding another full
copy. Otherwise, setup needs space for the complete uncompressed game data.
Completed caches are reused. Canceling an import keeps completed game data.

PAK mode needs an updated native game build; the launcher tells you to rebuild
if it lacks support. The game reads sectors from the prepared files, and does
not open or require an ISO. This is a game-source option, separate from enabling
replacement mods; the same replacement-pack restrictions still apply. Keep the
full game PAK private, just like your ISO.

Copy selected files into an edited folder, preserving the extracted relative paths.
After editing, package only changed files:

```powershell
python tools/assets/pack_assets.py "<reference>/assets.json" "<edited-folder>" "translation.pak" --game file1 --id example.translation.file1 --name "Example translation"
```

The packer skips unchanged and absent files and includes original entry hashes.
Keep all extracted originals private. Distribute only the changed assets you have
permission to distribute; do not include full game archives, ISOs or executables.

Developers can prepare and validate packs without starting a game:

```powershell
Outbreak.Launcher.exe --prepare-asset-paks file1 "<import>/data" "<pack-folder>" "<new-session-folder>"
```

## Executable-string references

Launcher game-to-PAK exports automatically include executable string references
for the selected edition under `executable-strings/`. For a smaller, standalone
editing reference, the Python tool supports both original executables:

```powershell
python tools/assets/extract_elf_strings.py "<import>/data/SLUS_207.65" "<new-private-reference-folder>"
```

Use `SLUS_209.84` for File #2; the supported executable hash selects the profile,
or specify `--game file1` / `--game file2` to enforce an edition.
`executable-strings-<game>.pak` contains `ui-strings.csv` / `ui-strings.json`, a
broader candidate catalogue, original bytes and verification metadata. Entries
include ELF-mapped addresses, file offsets, encoded byte budgets, formatting tags
and locations of literal address words. The UI grouping is a location heuristic;
SDK diagnostics and other non-display strings also occur in the broader list.
Keep original identity fields and bytes intact, and enter translations separately.

Fill the `translation` column in CSV or the `translation` field in JSON, retaining
the original JSON references alongside CSV. JSON also accepts `translationBytesHex`
for verified encoded byte mappings. Import the edited reference PAK through **Mods**
and enable it. Both games support these overrides in updated native builds, in solo
play. The Python packer also reads edited reference files in the edited folder.
Conflicting translations, changed original identities, invalid CP932 sequences,
embedded NULs and translations exceeding `maxBytes` are rejected. Preserve all
formatting tags and printf arguments. Byte limits exclude the terminating NUL.
Font glyph coverage still needs manual checking.
An empty CSV cell means no edit; JSON `translation: ""` explicitly clears a string.

### Optional verified string padding

The strict default remains the original `maxBytes`. New references also export
`paddingMaxBytes` and `usePadding: false`. Set **`usePadding` to `true`** for a
specific translated row in JSON or CSV to permit the larger exported budget.
Keep the original `maxBytes`, original text and identity fields unchanged in the
reference. For example, `\n\n\nUnequip items.` has 17 original bytes and a verified
31-byte budget in both supported editions. Re-export older references to obtain
the padding metadata; previous exports are preserved.

Padding stops at the first nonzero byte, the next 16-byte alignment boundary, the
supported string-region boundary or an aligned literal address reference,
whichever comes first. References in all file-backed ELF load segments are
checked, including KSEG0/KSEG1 aliases. At least one terminating NUL remains.
The launcher recalculates the budget from the original ELF; it does not trust an
edited reference's claimed budget. The runtime independently checks original file
and live guest zero bytes, pointer references, alignment and overlapping patches
before writing anything. This is a conservative static check, not proof that no
computed pointer or overlay can ever use a byte; review and playtest translations.

In hand-authored `pak.json` string entries, `usePadding: true` permits `maxBytes`
between the original length and the verified `paddingMaxBytes`. `baseSha256`
still hashes only the original string bytes. Padded plans require an updated
native build with `[EXECUTABLE-STRINGS-2]`; the launcher requests a rebuild for
older binaries. Strict-only plans retain their existing format and capability.

Custom-font mappings in CP932's single-byte half-width katakana range, including
`A6`–`B6`, remain accepted through `translationBytesHex` / `bytesHex`. They are not
normalized or changed into Latin Unicode characters; the replacement font supplies
the intended accented glyphs.

### Cleaning old imports

In **Game files → Clean up old imports...**, review the older completed imports
for the selected game and confirm deletion. Nothing is deleted automatically when
an ISO changes. The selected imports for both games, remembered source ISO/PAK
paths, saves, exports and mods are protected. Unknown files, incomplete imports,
malformed receipts and linked files/folders are left alone. Cleanup shares setup's
lock and rechecks each target before deleting it. Estimated sizes are logical file
sizes; shared hard-linked files can free less physical disk space. Keep an older
game revision's source if you want to import that revision again later.

Installable `pak.json` may contain a `strings` array alongside or instead of
`replace`. Each entry needs `address`, `maxBytes`, `baseSha256` (the original
string bytes' SHA-256) and either `text` or `bytesHex`. The launcher validates these
against the supported original executable catalogue. The runtime rechecks the
original ELF and guest bytes before applying the complete plan to guest memory;
the original executable on disk stays unchanged. Session receipts are
`executable-strings.json` and `executable-strings.bin`.

Selecting an edited full game PAK directly as the game source still requires its
original checksums; apply changes through **Mods**. Text baked into textures needs
a texture edit rather than a string override. Existing models, rooms, sounds and
scenario data can be replaced in their native formats; adding new archive entries,
code or arbitrary campaigns is not implemented. Keep original game references private.

## Randomizer

The launcher supports **Randomizer** packages for File #1 and File #2: weapons, ammunition, common items and enemy spawns. Weapon pickups receive other weapons, ammunition receives ammunition, and common items receive common items. Starting equipment, owned items, scenario keys, Daylight and the lighter stay unchanged. Enemy choices persist across rooms. Start a fresh scenario. The mod remains experimental; full scenario completion is unverified.

1. Select the game and open **Mods**. Its matching **Randomizer** package appears automatically, initially disabled. Existing packages and selections are preserved. Deleting the package keeps it removed; use **Import mod** with `examples/mods/randomizer.json` or `examples/mods/randomizer-file2.json` to restore it.
2. Tick **Randomizer** and launch for solo play or hosting. Joining players adopt the matching game's host settings automatically; cross-game configurations are rejected.
3. Open **Options** below the mod. **New seed each launch** is the default. Choose **Custom seed** and enter a whole number from **0 to 4294967295** to repeat a run with the same game and mod settings. A Randomizer package uses that seed for both its item and enemy randomizers. Start a fresh scenario to use the new layout.
4. The launcher shows the actual seed while running and records it in that session's `launch.json` and `mods.json`. Joining players always adopt the host's published configuration and seed, regardless of their local preferences.

Mod options are saved separately for each game and mod ID in launcher settings; configuring a seed does not rewrite the installed JSON package or its pools. Turning a mod off preserves its options, and switching back to automatic seeds remembers the previous custom value. Invalid custom-seed drafts show an inline error and prevent launching an enabled mod until corrected or switched to automatic. Configuration is locked while the game is launching or running.

Existing installations automatically consolidate the old combined, item, weapon, zombie and enemy samples into Randomizer. An enabled randomizer stays enabled, preserving the combined package's seeds and enemy pool when available. Practice Mode is removed. Original JSON files are kept under the mods folder's `retired-samples` subfolder, outside the active list. Unrelated custom mods are preserved.

Changes apply on the next launch. Untick the mod to disable it. Use its **Delete** action to confirm removal to the Recycle Bin. Deleting the last package for a mod also clears its enabled state and saved configuration for the selected game; the other game's package and preferences are preserved. Missing entries and invalid JSON packages can be removed from the same page. Effects on saved gameplay are not automatically undone. Imports never overwrite existing packages.

File #2 uses its own imported disc, mod folder, selections and enemy roster. Its
global candidates come from the five main scenarios and are fitted separately
for all 12 gameplay banks. Every original metadata entry, referenced recipe,
model and material alias stays intact. Only missing definitions/models are
appended, within the native limits of 128 metadata entries, 480 recipe halfwords,
96 model roots and 96 material aliases. Global additions therefore vary by
scenario; `global-items-file2.json` records additions and omissions. Definitions
without a floor-model alias cannot become replacement pickups; unsupported
original pickups stay unchanged.

Both games share the same seeded selection and exclusion algorithms. Scripted
enemies keep their original family for their entire seeded lifetime, room plans
reserve at most six animation families, and dead or unsupported sources remain
untouched. Removed File #1 enemy families are excluded from the File #2 sample;
their leftover model metadata is insufficient to make them playable. File #2
requires a new native executable with `MOD-FILE2-1`; an older build is rejected
before launch. See [File #2 implementation and validation](FILE2_RANDOMIZER.md).

## Shared randomizer sessions

The hosting launcher publishes an immutable snapshot when the host presses Play.
Joining launchers fetch its seeds, complete enemy pool, source behaviors and item
exclusions automatically. They ignore local mod selections for that session and
leave installed packages/preferences unchanged. An unmodded host supplies an empty
snapshot, which also clears guest randomizers. No mod installation is needed on
the guest for these data-only randomizers; both sides need updated game builds.

Keep the hosting launcher open and allow UDP 10129 (also used for discovery).
The host must launch before guests. Invalid or unavailable settings block launch;
there is no silent local fallback. Session ID and configuration are checked again
before starting the game; a changed host session during play closes the guest
session with a relaunch message. Settings are recorded in `randomizer-session.json`
and its SHA-256 receipt beside `mods.json`. This protocol currently targets games
hosted through the updated launcher, not legacy servers without this responder.

375 launcher checks currently pass, including the actual join resolution path over
UDP with conflicting local mods and an unmodded host. A two-client native test
produced identical initial layouts for all 80 eligible item records, but froze in
mixed-enemy loading. That failed run is not evidence of working enemy co-op.

The multiplayer audit on 2026-10-23 found that the old room-family reservation filter depended on actor construction order: the same 56-profile pool and seed 534703871 produced 13 different selections out of 16 when ordinary source spawns were processed in reverse order (`build-ninja/global-randomizer/multiplayer-order-audit.txt`). Version 3 fixes this by preparing the complete scenario enemy plan from the synchronized host seed, original spawn identities and original room-family requirements before actor construction. Room-family limits are applied in canonical spawn-ID order. Actual actor loading order, later resource flags and room visits cannot reroll the stored choices. The original spawn records remain unchanged by planning.

Both launcher protocol 3 and native `MOD-SESSION-3` support are required; old independently rolled sessions are rejected. The existing real UDP transfer tests confirm that clients adopt the host's seeds and full pool, replacing conflicting local selections. Native regression fixtures cover reversed actor and room orders, different actor allocations, resource availability changes, seed variation, scripted/dead source exclusions, six-family limits and no writes to guest RAM during planning. Full live multiplayer gameplay remains a separate validation requirement.

Local version-3 validation used two independent native processes with seed 534703871. Both produced the same complete plan for 33 eligible enemies from 62 scenario records, plus identical replacements for all 68 eligible items, and exited normally without missing callbacks or crashes. The first ran for 180 seconds; the second previewed the room for 80 seconds. The previously failing five-seed order reproduction now has zero mismatches. These native runs are independent sequential sessions, combined with the separate real UDP transfer tests, rather than a live network gameplay trial (`build-ninja/global-randomizer/seed-plan-validation.json`).

A separate live network trial on 2026-10-23 connected two native clients to the same private loopback server and observed 314.8 seconds in the first Outbreak room. Both clients shared player/enemy movement, the counter item's pickup ownership and floor removal, duplicate-pickup prevention and ammunition consumption. **Combat consistency failed:** spawn 2 remained at 550 HP on the host and 570 HP on the guest for the last 79.6 seconds; its maximum-HP fields also differed. Remote player HP sometimes updated several seconds late. Synced seeds establish choices, not reliable ongoing combat replication. This initial failure was investigated in the follow-up below. Enemy deaths, cross-species replacements in later rooms, separate-PC networking and full scenario completion remain unverified. Evidence: `build-ninja/global-randomizer/live-sync-test-v3/verification.json`, input events, read-only state samples and both clients' captures. The clients were deliberately stopped after observation.

The follow-up isolated a randomizer regression: after a scripted entrance, native network reconstruction can recreate one peer's actor with behavior zero. That peer incorrectly received the editable profile's 700 maximum HP while its partner kept the original shuffled 580 HP. The scenario plan now stores each spawn's original scripted identity and prevents that late profile application. A 419.9-second two-client repeat with the same seed and no cheats had no maximum-HP disagreements, and all observed enemy damage converged. Native grab/escape updates still produced temporary HP differences lasting up to 18.4 seconds; this fix does not make the original networking instantaneous. Evidence: `build-ninja/global-randomizer/coop-combat-fixed1/combat-verification.json`. A fresh final-binary network run additionally picked up/equipped the seed-43 rocket launcher and observed matching negative HP, collapse and subsequent scripted recovery on both peers. That controlled firing run used built-in health/infection/ammunition options in disposable sessions to keep the players alive; it does not validate multiplayer cheat replication. Permanent death/removal across other enemy families and later-room mixed-species combat remain unverified.


## Make your own

### Enemy spawn randomizer (experimental)

The **Randomizer** package (`randomizer.json`) combines the item/gun pool with
the enemy spawn mode described here.

The `enemyTypes` mode intercepts original actor construction and makes seeded
choices from the manifest's weighted `pool`. Profiles specify numeric `type`,
`model`, `health`, `behavior`, `posture` and `weight`. The expanded sample contains
56 profiles across 19 native families, including zombie models, Cerberus, lickers,
hunters, crows, spiders, moths, wasps, leeches, G creatures and bosses. The source
model must also occur in the pool. `sourceBehaviors: [0,9,24,33]` includes ordinary
and supported scripted zombie sources; named variant 85 stays excluded.

Scripted zombie spawns retain their original family for their whole scenario
lifetime: later scenario commands can still address their native zombie states
after an entrance finishes. Their models and health are shuffled before native
construction using the enemy seed, within the original room/lifecycle groups.
Ordinary behavior-zero sources can receive a weighted choice of another species.
The same allocated actor is then rebuilt with
the chosen species' native model, animation resources, collision state and AI.
The handoff preserves its current position, orientation, spawn ID and list links.
It does not insert an enemy, change trigger records, wait for a hardcoded timer,
or teleport a creature into view. Damage already taken is preserved proportionally;
dead actors are not revived. Prerendered cutscenes retain their original cast.

Each eligible scenario spawn makes an independent weighted choice. Its key uses
scenario, original spawn ID and original type/model; current room, actor slot,
construction order and frame timing do not enter the roll. The chosen profile is
cached until a new scenario, so room changes do not reroll existing enemies.
Independent choices can match by chance.

The manifest profiles define the allowed enemy pool, not fixed encounter layouts.
The runtime uses a versioned 32-bit pseudorandom generator: item locations use a
seeded choices within separate global weapon, ammunition and common-item pools,
and ordinary enemy spawns use weighted seeded rolls. Native animation resources
limit each room to six reserved enemy families; later choices in that room use
those available families. Scripted sources retain their native family. The launcher
chooses a fresh full-range 32-bit seed for each solo/host launch and applies it to
all enabled randomizers. It rejects the immediately previous launch seed and the
installed manifest seeds. Installed JSON files, enemy pools and exclusions remain
unchanged; joining clients use the host's immutable seed. The native generator is
deterministic for a given seed, scenario and configuration, including native test
runs supplied with an explicit seed. Nothing rerolls merely because a room is revisited.

Local follow-up to v1.0.15: a longer manual first-room session exposed a later
zombie script command (`10/1`) reaching a replacement hunter's null state callback.
The main game thread returned while audio and presentation continued. The earlier
three-minute movement checks did not cover that transition. Scripted sources now
retain zombie-family state compatibility and use the seeded profile shuffle
before construction. This correction is included in v1.0.16.

The corrected build passed a seven-minute running/combat trial in the first
room (`build-ninja/release-v115/local-script-fix-validation.json`). An independent
read-only monitor collected 1,619 samples with no active game-counter stall;
the steady sample measured 29.90 updates/s. Seed 2031 changed five of eight
eligible scripted profiles, and the first three zombies continued moving through
many states after the cutscene. This covers the reported room transition, not
complete-scenario progression or multiplayer compatibility.

Expanded-roster diagnostics on 2026-10-23 separately initialized the native families in the editable sample. Follow-up runs verified actual player damage from free-flying crows, wasps and active G embryos (`build-ninja/global-randomizer/roster-flight-fixed/results.json`). G-type and both Thanatos variants completed their native grab reactions after the original missing overlay entry and resume points were registered; the foreign-room Neptune remained alive and updated on the room's floor (`build-ninja/global-randomizer/roster-boss-resumes/results.json`). These isolated tests add a temporary diagnostic actor; ordinary launches only replace eligible original spawns. Full scenario, boss and multiplayer compatibility remain unverified.

Enemy-type mods request an additional 32 MB native asset bank. The original game
heap, stack, save data and kernel-reported RAM size remain in the original 32 MB.
This addresses the exhausted 14 MB asset allocator found in mixed-family tests.
A three-minute native run with seed 2031 passed after this change: original spawn
0 became a dog and spawns 1 and 2 became hunters, all initialized and kept moving
until exit. The unchanged original spawn table and complete handoffs are checked
in `build-ninja/enemy-independent-bank2-verification.json`; the actual post-break-in
capture is `build-ninja/randomizer-images/independent-bank2-145s.png`. The six
native animation-family slots still apply. Exceeding them is an explicit error,
not a reroll or silent zombie fallback. Invalid models and missing callbacks are
excluded. Ordinary shared zombie models retain the original variant in this mode;
use `zombieProfiles` for the separate appearance shuffle.

Edit the seed, weights or profiles to make your own package. Profile IDs in the
community [model reference](https://outbreak-research.github.io/Documentation/3D/)
are starting points; arbitrary models, bosses and other scenarios require gameplay
validation. Only one enemy randomizer may be enabled. Updated native capabilities
`MOD-ENEMY-SPAWN-1`, `MOD-SESSION-2` and `MOD-ENEMY-ASSETS-1` are required.

The following captures and receipts describe the **previous room-family version**;
they do not establish mixed-species or multiplayer support in the new version.

The three-minute licker run `20261022-134117-911` replaced original spawns 0, 1
and 2. All three initialized with callback `0061C3E0`, continued updating and moved
through multiple positions/states. The three-minute hunter run
`20261022-134617-611` replaced original spawns 0 and 2 with callback `0060F710`;
both moved through 14 distinct sampled positions. Actual post-break-in captures
are `build-ninja/randomizer-images/lickers-seed-2032.png` and
`build-ninja/randomizer-images/hunters-seed-2039.png`. Both runs exited normally
without missing-function warnings, and their original scenario spawn tables
matched the unmodded baseline exactly. Receipts are
`build-ninja/enemy-room-2032.json` and `build-ninja/enemy-room-2039.json`.
The seven-minute combined item/enemy run `20261022-134948-351` used the installed
1.3.0 sample with seed 2031. Original spawns 1 and 2 became Cerberus with native
callback `006055E0`, each with 136 AI samples and 90/93 distinct positions. Both
continued updating through the end; the process exited normally without missing
guest functions. Its 300-second screenshot clearly shows both dogs at the broken
doorway: `build-ninja/randomizer-images/dogs-seed-2031.png`. The item randomizer
also changed 57 of 64 eligible placements. Receipt:
`build-ninja/enemy-room-2031-long.json`. All three enemy verification results are
saved in `build-ninja/enemy-spawn-verification.json`.
These tests establish this encounter, not complete scenario progression or
save/resume compatibility.

Run `python tools/check_enemy_spawn_session.py <baseline-receipt> <mod-receipt>`
to verify the selected pool/seed, unchanged original records, completed handoffs,
native callbacks, continued updates and movement. Screenshots require visual review.
The old guarded all-zombie run correctly fails this verifier. Developer arguments
`--test-enemy-combat --test-enemy-long` run the original input route for seven minutes.

### Optional zombie-profile mode for mod authors

Randomizer uses `enemyTypes` by default. Authors can replace its `enemyRandomizer`
configuration with `zombieProfiles` to shuffle only zombie appearances and health:

```json
"itemRandomizer": { "seed": 2027 },
"enemyRandomizer": { "seed": 2031, "mode": "zombieProfiles" }
```

The enemy mode permutes supported ordinary zombie model variants together with their current/maximum health, within each room and lifecycle group. It preserves each room's original model set and total health supply. Spawn positions, enemy count, activation flags, routes and behavior parameters remain unchanged. Special variant 85 and all other enemy species are excluded. This is **zombie-profile randomization, not cross-species enemy replacement**. Hunters, lickers, bosses and flying enemies are not substituted into zombie encounters. Unsupported mode names are rejected.

Use a fresh offline File #1 scenario; save/resume and complete-scenario progression are unverified. The launcher requires the native `MOD-ZOMBIE-RANDOMIZER-1` capability marker. Seeds are unsigned 32-bit integers; repeated seeds reproduce the permutation for the same original spawn table. Small groups and identical profiles can remain unchanged.

Implementation evidence for NTSC-U v2.00: original `6BAA40` builds 96-byte records at `74F250`, with count at `4BAE8E`. `6BB040` instantiates room enemies; `6BBDA0` transfers record variant byte `+3` to actor `+BBA`, and record health halfwords `+1C/+1E` to actor `+544/+546`. Type 1 actors use original update callback `696300`. The mod shuffles once before `6BB040`, rearming when `6BAA40` initializes a new scenario, and writes only those five bytes per eligible record. Room-local mode 0 and tracked mode 1 entries are shuffled separately; unknown modes and invalid/dead/injured records are excluded.

Validation on 2026-10-22: seed 2031 changed 32 of 46 eligible profiles in the first scenario. All 62 baseline/randomized records differed only at the allowed variant/health bytes; excluded records were identical. Changed spawn IDs 1, 2, 5, 6 and 7 reached live zombie actors with the expected profiles and original AI callbacks. The window zombies visibly exchange appearances in actual captures `build-ninja/randomizer-images/enemies-baseline.png` and `enemies-randomized.png`. Player HP also fell during the three-minute native run; that observation alone does not prove a specific bite animation. Baseline receipt: `build-ninja/enemies-baseline-spawn.json`; randomized receipt: `build-ninja/enemies-randomized.json`.

Reproduce with launcher smoke flags `--test-enemies --test-no-mods` for a baseline and `--test-enemies --test-mod <your-zombie-profile-mod-id>` for the mod. `--test-enemy-combat` additionally approaches the first room's entrance through ordinary controller input and then waits; it never grants damage or spawns enemies directly. Verify receipts with `python tools/check_enemy_randomizer_session.py <baseline.json> <randomized.json>`. This checks exact write boundaries, supply conservation, actor initialization and AI updates, and reports damage separately from bite or completion proof.

The combined package also passed a three-minute combat run (`build-ninja/enemies-combined-combat.json`, session `20261022-122257-942`): 57/64 item pickups and 32/46 zombie profiles changed. Modified zombie spawns 1 and 2 moved into the bar; original enemy updates recorded their changed variants 13 and 12. Kevin's HP fell from 2300 through 2140, 1590 and 790 to 80. Actual combat captures are `enemies-combat-damage.png` and `enemies-combat-room.png` under `build-ninja/randomizer-images`. `build-ninja/enemy-combined-verification.json` passes spawn, AI, conservation and byte-boundary checks. These observations establish active combat and damage, not completion or a separately proven bite animation.

### Item Randomizer

The default `itemRandomizer` section uses `"mode": "global"`. Weapons replace weapons (including melee and throwing weapons), ammunition replaces ammunition, and common items replace common items. Each eligible pickup receives a seeded choice different from its original type and a quantity within the replacement's capacity. Handles, placement and ownership stay unchanged. The launcher builds the catalogue from the player's imported File #1 data; no game data is distributed with the mod. Guns are included; adding a separate `weaponShuffle` conflicts with this mode.

The global catalogue merges item metadata and combination recipes from all five scenarios, preserving existing metadata indices and progression recipes. Original personal-equipment records, owned items, progression-flagged items, keys, Daylight (312) and the lighter (450) are excluded. Personal tools are excluded from replacement supplies; personal weapons can appear as additional weapon pickups. The item section does not change doors or puzzle logic and does not promise that every seed is completable. Use a fresh File #1 scenario. The executable must advertise `MOD-GLOBAL-ITEMS-1`, `MOD-GLOBAL-MODELS-1` and `MOD-ITEM-RANDOMIZER-1`; old builds are rejected. Diagnostics list every original/replacement pair. Omitted mode or `"mode": "shuffle"` retains the legacy scenario-supply permutation for existing custom manifests; its historical cross-category checks below do not describe the new default.

Global mode also merges floor models from the player's imported scenario object banks. Meshes retain their pairing with hierarchy roots; only used materials and textures are loaded, preserving space in the native material pool shared with characters and rooms. Five inventory-only ammunition definitions use ordinary ammunition-box floor models while retaining their actual inventory icon, quantity and weapon compatibility. The private coverage check verifies a floor model for all 78 eligible replacement types in every scenario bank, including original key models and geometry preservation (`build-ninja/global-randomizer/global-models-validation.json`).

```json
"itemRandomizer": { "seed": 2027, "mode": "global" }
```

Local global-mode validation on 2026-10-23: all five original item tables fit the native metadata/recipe capacities with protected progression data unchanged. Determinism and category-preservation fixtures passed. The live first-scenario run with seed 534703871 changed all 68 eligible pickups, acquired a randomized weapon through normal interaction, and returned through the original quit/results flow to the main menu (`build-ninja/global-randomizer/smoke-global-pickup.json`). Weapon firing, save/resume and full-scenario completion remain separate checks.

The corrected model-loading build also passed the seed-43 rocket-launcher pickup and native return-to-menu route (`build-ninja/global-randomizer/preview-bank-fixed.json`). The earlier merged-bank prototype loaded unused materials until the shared native pool was exhausted, corrupting character and room textures; the compact bank removes those unused allocations. A separate preview confirms the rocket-launcher floor geometry is visible. An additional input-only trial equipped that randomized launcher through the original inventory menu and fired it: the pickup record's rounds fell from 1 to 0, Kevin visibly held the launcher, and gameplay/movement continued afterward (`build-ninja/global-randomizer/fire-test-v2/weapon-use-validation.json`). These checks cover the starting room and this weapon, not every scenario or every weapon's use.

The final local bank passed a 180-second starting-room trial with both seeds set to 534703871. Adjacent unpaused gameplay intervals measured 29.79 updates/s over 115.6 seconds, with no active-counter stall longer than 0.71 seconds and a maximum of 393/600 native material slots used. The intentional pause/options interval is excluded from that speed calculation. Exit was clean, no extra diagnostic enemy was spawned, and the later room capture retained normal character and room textures (`build-ninja/global-randomizer/soak-final-analysis.json`, `soak-final-room.png`).

Mod authors can preserve selected ordinary items with an optional decimal ID list:

```json
"itemRandomizer": { "seed": 2027, "mode": "global", "excludeItemTypes": [0, 309] }
```

This example keeps standard handguns (ID 0) and first aid sprays (ID 309 / hexadecimal `0135`) at their original locations. Every record of an excluded type stays untouched and its contents are removed from the shuffle pool, so exclusions cannot duplicate supplies. IDs must be distinct integers from 0 through 399. Omit the list or use `[]` for the original unrestricted pool. Exclusions change the seeded permutation; they are recorded in the session's `mods.json`. Builds lacking `MOD-ITEM-EXCLUSIONS-1` are rejected when the list is nonempty. This is an author-controlled way to protect specific supplies, not a progression solver.

`--test-room-preview` selects the first scenario and leaves the controller neutral on room entry for before/after captures. Window captures should be taken from the actual game window; the internal presentation-frame capture is unavailable with some renderers.

Live visual validation on 2026-10-22: seed 2027 selected 64 ordinary pickups and changed 57. Counter handle 3 (`003C56E4`) changed from handgun type `0000`, quantity 15, to type `0135`, quantity 1. Actual game-window captures show the handgun replaced by a spray can in the same counter location: `build-ninja/randomizer-images/vanilla.png` and `randomized.png`. The other room-entry state and camera were left to the original game; captures were not edited. Receipts: `build-ninja/items-preview-off-capture.json` and `items-preview-on.json`. Launcher tests pass 299 checks; native fixtures verify cross-category swaps, deterministic seeds, quantity conservation, metadata consistency and unchanged excluded records. This verifies initialization and visible model replacement, not pickup/use, save/resume or complete-scenario progression.

Follow-up pickup validation: the test now approaches `(8460,13014)`, at the accessible counter boundary, and retries normal interaction press/release edges. Session `20261022-115741-359` acquired randomized handle 3 into Kevin's inventory slot 0 with type `0135`, quantity 1, metadata 9, owner 1 and world flag 0, then returned through the original quit/results flow to the main menu. The follow-up inventory capture `build-ninja/randomizer-images/randomized-inventory.png` identifies it in-game as **FIRST AID SPRAY**. The pickup route now holds the inventory open for 15 seconds for screenshots. This supersedes the earlier failed pickup attempts; item use, save/resume and full-scenario progression remain unverified.

Run `python tools/check_randomizer_session.py <smoke-receipt.json>` after a randomizer pickup test. It checks the selected seed, complete shuffle log, conserved supply, exclusions, changed-item inventory transfer and main-menu return; missing proof returns a failing exit code even when the game exited normally. The earlier visual-only run correctly fails this stronger check. Launcher checks now pass 306 assertions; native checks also cover exclusion parsing and preservation.

Live exclusions validation (session `20261022-120202-677`): seed 2027 with `[0,309]` produced 53 eligible pickups and 48 changes. The pool exactly matched the unrestricted run minus those types, conserved supplies, and kept counter handle 3 as handgun type 0 with 15 rounds. The normal controller route acquired that unchanged handgun and returned to the main menu. Local report: `build-ninja/item-exclusions-verification.json`. The temporary diagnostic package was removed after testing.

### Optional weapon-only mode for mod authors

The loader also supports a `weaponShuffle` section for custom gun-only packages. Remove `itemRandomizer` before adding it. This mode changes gun pickup placement using the scenario's existing supply. Each gun travels with its original ammunition quantity; it does not replenish ammunition or change health. Personal weapons, melee weapons, keys, owned items and scripted grants are excluded.

Copy `randomizer.json`, give it your own ID/name, remove `itemRandomizer` and add:

```json
"weaponShuffle": { "seed": 2027 }
```

Seeds accept integers from 0 through 4294967295. The same seed and original item table produce the same permutation; the game's own difficulty/item-table variation still applies. A permutation can leave some pickups unchanged. Enable only one shuffle package at a time. The launcher requires a native executable advertising `MOD-WEAPON-SHUFFLE-1`; older executables show an update error.

The native hook runs at scenario item initialization, after item metadata is loaded and before bonus items are granted. It swaps type, quantity and metadata reference while preserving each pickup's handle, placement and ownership. It does not run every frame. Existing saves are not converted or restored by toggling this mod; use a fresh scenario when comparing seeds. Avoid combining it with inventory/item-pool data patches.

Native diagnostics record the seed, eligible/changed counts and each before/after item in `[MOD-WEAPON-SHUFFLE-1]` rows. A randomizer-only session does not need `cheats.txt`. Developer checks can use `--test-mod <your-weapon-only-mod-id> --test-pickup --display-test --test-room --test-memory-card` with `--smoke-launch <game-exe> <result.json>`. `--test-no-mods` supplies an explicit baseline. The pickup route uses controller inputs and records the acquired type/quantity; it does not by itself prove firing or a complete scenario.

**Validation status: experimental.** Native fixtures verify deterministic seeds, seed variation, preservation of the complete weapon/ammo supply, matching metadata, and no writes outside the permitted fields of eligible items. Launcher tests cover seed limits, package selection, conflicting shuffles and old-build rejection. A live first-scenario run with seed 2027 selected 12 guns and changed 9, including handle 3 from type `0000`/15 rounds to `000B`/7 rounds. The 120-second run exited normally. The input-only test reached the counter but did **not** produce pickup/inventory proof; firing, save/resume and full-scenario completion remain unverified. Do not treat process exit 0 as a gameplay acceptance pass. Local receipt: `build-ninja/weapon-shuffle-verified-on.json`, session `20261022-113349-279`.

The matching mod-disabled route also stalled at interaction without pickup proof (session `20261022-113724-503`, `build-ninja/weapon-shuffle-baseline.json`). Its selected package list was empty and no shuffle hook was installed. A read-only item-pool sample retained handle 3 as type `0000`, quantity 15 and metadata 36. This comparison does not establish that pickup or firing works with the mod; that acceptance check remains open.

### Effect and data-patch samples

`examples/mods/no-infection.json` is a minimal authoring example for the effect format. It can be imported for offline play.

Copy the example and change `id`, `name`, `version`, and `description`. IDs use lowercase letters, digits, dots and hyphens, up to 80 characters. Each installed mod must have a unique ID. The `format` must be `1` and `elfSha256` must match the example's supported NTSC-U v2.00 executable. Unknown JSON properties are rejected so typos do not silently change behavior.

The `effects` array accepts:

| Effect | Behavior |
| --- | --- |
| `infection` | Keep the living local player's infection gauge at zero. |
| `health` | Restore the living local player to their existing maximum health. |
| `ammo` | Keep eligible carried firearms loaded to their normal capacity. |

Combine effects, for example `"effects": ["health", "infection"]`. These use the same implementation as built-in cheats, without requiring the Cheats switch to be enabled.

Built-in cheats require both **Enable cheats** and the individual cheat selections; changes apply on the next launch. The Randomizer does not enable them. Full health restores a living character each guest frame: it does not suppress enemy hit reactions or revive a dead character. Brief damage/virus/ammunition values can exist between the original action and the next restoration. Cheats remain restricted to offline play.

File #2 (SLUS-20984 v1.05) supports **Full health**, **No infection**, **Infinite ammunition**, **Unlock everything**, **Max results points**, **Infinite escape time** and the same subset of imported `.pnach` data writes. Select File #2 before importing or enabling cheats; its files and selections are separate from File #1. An older File #2 executable without the cheat hook is rejected when cheats are selected.

**Max results points**, available for both games, keeps the spendable Collection balance at the original game's cap of **999,999,999**. It works in menus as well as gameplay and refills the wallet after purchases. Lifetime earnings, scenario scores, ranks and completion records remain unchanged. Normal in-game saving can retain the balance after the cheat is disabled; the launcher does not edit save files directly.

**Infinite escape time**, available for both games, freezes the engine's active 30 Hz countdown timers and prevents their expiry flags from firing. Inactive and already expired countdowns are not restarted. Ordinary script waits, total play time, menus, rendering and other game updates continue. The override applies only to the verified gameplay overlay's countdown service, retaining the original service when this cheat is disabled.

Both selections use the existing offline-only, next-launch cheat workflow. The launcher checks `CHEATS-POINTS-1` and `CHEATS-ESCAPE-1` capability markers before launching, so an older executable cannot silently ignore a selected cheat. Native checks include exact wallet write boundaries for both games and controlled execution of their original generated purchase and countdown routines. Research receipts are under `build-ninja/points-cheats/`; those controlled checks do not represent a full scenario playthrough.

**Unlock everything** grants the five File #1 scenarios, Easy/Normal/Hard/Very Hard, costumes, NPC characters and purchased collection extras (including Lone Wolf and Infinity availability). It applies in menus as well as gameplay, so no living character is required. It does not add key items, change inventory, grant points or fabricate completion records. Selecting a game mode still uses the original menus. Unlocks are applied to the loaded progression data; the game's normal save operation can retain them after the cheat is disabled. Existing saves are not edited directly by the launcher. An older native executable without `CHEATS-UNLOCK-1` is rejected before launching this selection.

For File #2, **Unlock everything** grants main and extra scenario availability, all four difficulties, costumes, NPC characters, bonus-mode availability and all valid entries in the five collection banks. Direct unlock writes preserve reward points, active options and unrelated data; the original menus can update normal records when processing owned extras. Select **File #2 → Cheats → Enable cheats → Unlock everything**, then **Play alone**. Use the game's normal save operation to retain changes; the launcher does not replace or edit a memory card. File #2 requires the separate `CHEATS-UNLOCK-FILE2-1` native capability marker, so existing File #2 builds must be rebuilt or updated. Original-code evidence, live menu results and verification limits are documented in [FILE2_UNLOCKS.md](FILE2_UNLOCKS.md); save/reload persistence remains unverified.

Validation on 2026-10-23 compared fresh private test cards: the unchanged build listed one scenario, while the enabled build listed IDs 0â€“4 and accepted navigation through all five. Native menus exposed all four difficulties, Kevin Type-C, the MAC NPC and owned gallery/Extra entries. Fifty-five native cheat checks include a complete RAM comparison proving unlock writes stay within the progression bitsets and preserve other records and settings; 375 launcher checks include the exported selection and master-switch behavior. Private receipts and original opcode-reader excerpts are under `build-ninja/global-randomizer/unlock-investigation/` and `unlock-validation.json`. This does not establish full scenario completion or save/reload persistence.

Live verification on 2026-10-23 found and fixed an ammunition-category bug: the old hexadecimal item-ID range refilled personal guns but ignored ordinary guns with decimal IDs below 100. The corrected check uses weapon/ammunition metadata and excludes common items, ammunition boxes, keys and melee. In an isolated offline test with all three built-ins enabled, the randomized one-round rocket launcher completed five firing cycles and returned to one round; sixteen native damage events were followed by restored 2300/2300 HP, and infection reset to zero. The matching old-build test left the rocket empty after one shot. Native regression fixtures pass 48 cheat checks, including real firearm and excluded-item categories. Private evidence: `build-ninja/global-randomizer/cheats-validation.json`. This is a first-room offline check, not a full-scenario or multiplayer-cheat validation.

Advanced authors can add `patches` with this structure:

```json
{ "when": "frame", "address": "004A5C40", "size": 2, "value": "0000" }
```

This demonstrates the syntax only, **not a recommended gameplay patch**. Choose addresses from your own verified research. Addresses and values are hexadecimal strings without `0x`; `size` is 1, 2, 4 or 8 bytes. Writes are little-endian. `when` is `boot` (once before runtime execution) or `frame` (on the guest service callback before its original function). Boot writes may be overwritten during game initialization. Frame writes are unconditional; they are not scenario-aware and are not necessarily called once per rendered frame.

The entire write must fit within `[0x370000, 0x1FD0000)`, excluding `[0x570000, 0x900000)`. These are the existing cheat subsystem's coarse permitted ranges, not a guarantee that an address is meaningful or safe in every game state. Code patches and overlay-bank writes remain unavailable. Mod authors are responsible for validating their data addresses and behavior.

Packages are limited to 1 MB and 4096 patches; selected mods and cheats share a combined 4096-write limit. Byte overlap between declarative mod patches (including within a package) or with selected cheat writes blocks launch. Built-in effect writes are dynamic and are **not** included in this overlap detection; do not combine custom writes to health/inventory/infection fields with their corresponding built-in effects.

## Installation and diagnostics

Installed files live in `data/mods/file1` beside the launcher (or `mods/file1` inside your selected storage folder). You can copy JSON files there directly and press Reload. Invalid packages show an error. Missing, invalid or duplicate enabled IDs block launch until repaired or disabled.

Effects and arbitrary data patches remain restricted to **Play alone**. The launcher now allows the host to publish item/enemy randomizer settings; mixed-species multiplayer gameplay verification remains in progress. A session records the complete selected manifests in `mods.json` and the combined native effects/data writes in `cheats.txt` beside its logs. The original ISO and imported game files are not edited.

The example reuses an existing native effect. The initial loader's automated checks validate package parsing, import, selection, conflicts and launch-manifest generation; they do not establish new end-to-end gameplay validation for every custom patch.

For a developer gameplay check of an installed sample, the launcher's existing smoke runner accepts `--test-mod example.no-infection` alongside `--smoke-launch <game-exe> <result.json> --display-test --test-room --test-memory-card`. This uses an offline settings snapshot with cheats disabled, enables mod diagnostics, and closes the game after the bounded room check. Inspect the session's `mods.json`, `cheats.txt` and `[CHEATS]` gameplay diagnostics as well as the smoke result; a process remaining alive is not proof of gameplay success.
