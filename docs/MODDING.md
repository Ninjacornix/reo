# Creating a simple Outbreak mod

The first mod format is a single JSON file. Anyone can edit and share one; no compiler or game rebuild is needed when enabling a mod in an existing compatible build. This version supports seeded items, zombie profiles, a bounded experimental enemy-species mode, existing native gameplay effects and bounded EE data patches. Lua scripts, DLL plugins, asset replacement and PS2 instruction patches are not supported yet.

## Randomizer

The launcher has one **Randomizer** package for items, guns, ammunition and enemy spawns. Guns are included in the ordinary item pool; no separate gun shuffle is needed. Personal equipment and scenario keys stay unchanged. Enemy choices include supported zombie, Cerberus, licker and hunter profiles and persist across rooms. Start a fresh File #1 scenario. The mod remains experimental; full scenario completion is unverified.

1. Open **Mods > Import mod** and choose `examples/mods/randomizer.json` (also included with the launcher build).
2. Tick **Randomizer** and launch File #1 for solo play or hosting. Joining players adopt the host's settings automatically.
3. To change the layout, edit the installed JSON's `itemRandomizer.seed` and `enemyRandomizer.seed`, then reload and start a fresh scenario.

Existing installations automatically consolidate the old combined, item, weapon, zombie and enemy samples into Randomizer. An enabled randomizer stays enabled, preserving the combined package's seeds and enemy pool when available. Practice Mode is removed. Original JSON files are kept under the mods folder's `retired-samples` subfolder, outside the active list. Unrelated custom mods are preserved.

Changes apply on the next launch. Untick the mod to disable it. To remove it, untick it, open the mods folder, delete its JSON file and reload the list. Effects on saved gameplay are not automatically undone. Imports never overwrite existing packages.

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

363 launcher checks currently pass, including the actual join resolution path over
UDP with conflicting local mods and an unmodded host. A two-client native test
produced identical initial layouts for all 80 eligible item records, but froze in
mixed-enemy loading. That failed run is not evidence of working enemy co-op.

## Make your own

### Enemy spawn randomizer (experimental)

The **Randomizer** package (`randomizer.json`) combines the item/gun pool with
the enemy spawn mode described here.

The `enemyTypes` mode intercepts original actor construction and makes seeded
choices from the manifest's weighted `pool`. Profiles specify numeric `type`,
`model`, `health`, `behavior`, `posture` and `weight`. The sample contains ordinary
zombie models, Cerberus (`2:1`), licker (`0:0`) and alpha hunter (`22:0`). The source
model must also occur in the pool. `sourceBehaviors: [0,9,24,33]` includes ordinary
and supported scripted zombie sources; named variant 85 stays excluded.

Scripted zombies keep their original entrance until their own AI state machine
hands control to normal movement. The same allocated actor is then rebuilt with
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

The `itemRandomizer` section in `examples/mods/randomizer.json` mixes the ordinary scenario pickup pool across weapons, ammunition, healing, melee and supplies. A weapon location can receive a non-weapon item. Each item carries its original quantity and metadata reference; handles and placement remain at their original locations. Edit `"itemRandomizer": { "seed": 2027 }` to choose another permutation. Guns are already included; adding a separate `weaponShuffle` conflicts with this pool.

This mode includes valid ordinary item IDs below 400. Personal equipment and the scenario-key ID range are excluded. The item section does not change enemies, doors or puzzle logic (the combined package handles enemies separately), and does not promise that every seed is completable. Use a fresh offline File #1 scenario. The native executable must advertise `MOD-ITEM-RANDOMIZER-1`; old builds are rejected. Diagnostics list every original/replacement pair under that tag.

Mod authors can preserve selected ordinary items with an optional decimal ID list:

```json
"itemRandomizer": { "seed": 2027, "excludeItemTypes": [0, 309] }
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

Advanced authors can add `patches` with this structure:

```json
{ "when": "frame", "address": "004A5C40", "size": 2, "value": "0000" }
```

This demonstrates the syntax only, **not a recommended gameplay patch**. Choose addresses from your own verified research. Addresses and values are hexadecimal strings without `0x`; `size` is 1, 2, 4 or 8 bytes. Writes are little-endian. `when` is `boot` (once before runtime execution) or `frame` (on the guest service callback before its original function). Boot writes may be overwritten during game initialization. Frame writes are unconditional; they are not scenario-aware and are not necessarily called once per rendered frame.

The entire write must fit within `[0x370000, 0x1FD0000)`, excluding `[0x570000, 0x900000)`. These are the existing cheat subsystem's coarse permitted ranges, not a guarantee that an address is meaningful or safe in every game state. Code patches and overlay-bank writes remain unavailable. Mod authors are responsible for validating their data addresses and behavior.

Packages are limited to 1 MB and 4096 patches; selected mods and cheats share a combined 4096-write limit. Byte overlap between declarative mod patches (including within a package) or with selected cheat writes blocks launch. Built-in effect writes are dynamic and are **not** included in this overlap detection; do not combine custom writes to health/inventory/infection fields with their corresponding built-in effects.

## Installation and diagnostics

Installed files live in `%LOCALAPPDATA%\OutbreakRecomp\launcher\mods\file1`. You can copy JSON files there directly and press Reload. Invalid packages show an error. Missing, invalid or duplicate enabled IDs block launch until repaired or disabled.

Effects and arbitrary data patches remain restricted to **Play alone**. The launcher now allows the host to publish item/enemy randomizer settings; mixed-species multiplayer gameplay verification remains in progress. A session records the complete selected manifests in `mods.json` and the combined native effects/data writes in `cheats.txt` beside its logs. The original ISO and imported game files are not edited.

The example reuses an existing native effect. The initial loader's automated checks validate package parsing, import, selection, conflicts and launch-manifest generation; they do not establish new end-to-end gameplay validation for every custom patch.

For a developer gameplay check of an installed sample, the launcher's existing smoke runner accepts `--test-mod example.no-infection` alongside `--smoke-launch <game-exe> <result.json> --display-test --test-room --test-memory-card`. This uses an offline settings snapshot with cheats disabled, enables mod diagnostics, and closes the game after the bounded room check. Inspect the session's `mods.json`, `cheats.txt` and `[CHEATS]` gameplay diagnostics as well as the smoke result; a process remaining alive is not proof of gameplay success.
