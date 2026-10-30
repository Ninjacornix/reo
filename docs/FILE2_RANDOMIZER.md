# File #2 randomizer port evidence

Target: SLUS-20984 NTSC-U v1.05. Date: 2026-10-28.

This port uses the File #1 selection algorithms with a separate File #2
address layout and original-function wrappers. The mappings below were checked
against the original instruction comments in generated sources and the local
ELFs. They are static evidence, not proof of every enemy's live behavior.
Raw opcode excerpts, source hashes and the target ELF hash stay in the private
`build-ninja/file2-randomizer-research/evidence.json` file.

## Native hooks

| Purpose | File #1 | File #2 | Verification |
|---|---|---|---|
| Before bonus/start-equipment grants | `5924E0` | `5B0900` | The scenario item loader `5B00A0` calls it at `5B016C`, after placed item records and metadata are loaded. Its loop uses the File #2 player stride `1100`. |
| Reload scenario enemy records | `6BAA40` | `6E80B0` | Clear of `7AFF80`, size `6000`; count store at `6E867C`. |
| Construct current room enemies | `6BB040` | `6E8710` | Room starts/counts at `6E8768..6E8788`, followed by native actor allocation and construction. |
| Per-actor target setup | `6BB9F0` | `6E9300` | Native calls at `6E897C` and `6E8E48`; reads source identity and target-selection fields. |
| Copy spawn record into actor | `6BBDA0` | `6E97C0` | Explicit record-to-actor stores at `6E97E8..6E9888`. |
| Zombie update | `696300` | `6C69D0` | Original entry sequence and type-1 callback table entry agree. |
| Dog / licker / hunter updates | `6055E0` / `61C3E0` / `60F710` | `625910` / `648FE0` / `63ADF0` | Type callback indices 3 / 1 / 17 select these original entries. |
| Read a model or motion bank | `1A9F20` | `1353E0` | Matched original routine; source path in `a1`, destination in `a2`. |
| Initialize native asset heap | `1A0D10` | `1ED8E0` | Matched original routine and heap data references `358CF8` / `358CFC`. |
| Select actor's model index | `1B92E0` | `144AA0` | Reads actor `+BD2`, family `+3` and table `3A2360`. |
| Load private enemy model | `6BA790` | `6E7E00` | Original renderer setup calls at `6E8B34` / `6E902C`; model table at `6E7E44`. |
| Set up geometry / animation | `377560` / `3777B0` | `393C40` / `393E90` | Original room constructor calls at `6E8B54` / `6E8B6C`. |

All gameplay wrappers use overlay base `58D000`, MWo3 id 3. Original routines
remain in the call path; resume labels do not reroll plans or item selections.

## Data layout

| Purpose | File #2 address / offset |
|---|---|
| Placed item pool, stride 60 | `3E1C20` |
| Item type lookup / metadata / loaded count | `7AC590` / `7ACA00` / `7ADA20` |
| Scale / priority / combination buffers | `7AC7F0` / `7AC180` / `7AD660` |
| Scenario / room | `30095A` / `30095C` |
| Spawn table, stride 96 / count byte | `7AFF80` / `4DB44E` |
| Room spawn counts / first spawn indices | `7B5F80` / `7B6000` |
| Enemy actor pool, exclusive end / stride | `44DE90`, `478AF0` / `DB0` |
| Actor model / spawn / lifecycle | `+BD2` / `+BB0` / `+BB2` |
| Actor behavior / posture / current and maximum health | `+C48` / `+BB4` / `+540`, `+542` |
| Family model table / callback-index table / callback table | `3A2360` / `766EE0` / `766FB0` |
| Animation-family slots / animation records, stride `C84` | `4DB470` / `4DF200` |
| Pose records, stride `3EC` | `4DDA70` |
| Actor animation family / animation state flag | `+54A` / `+522` |
| Native fresh-actor sentinel fields | `+CE4..+CE7`, `+CBA`, `+CBB` |

The allocator at `6E7980` explicitly clears `DB0` bytes and uses base `44DE90`.
The original constructor at `6E97C0` transfers the record's health, spawn,
model, behavior and lifecycle fields to the offsets above. File #1 actor
offsets cannot be reused by a blanket relocation.

## Selection and protection rules

The shared algorithms retain separate weapon, ammunition and common-item
categories; progression/key items, owned inventory, starting grants and explicit
exclusions remain protected. Metadata identity checks and native table capacity
checks apply before replacement. Seed decisions depend on stable scenario and
spawn/item identity, not host order or room visits.

Enemy plans reserve original room families before choosing replacements, with
the same six-family ceiling. Nonzero behavior marks a scripted source for the
entire scenario plan, so later reconstruction cannot turn it into an ordinary
cross-family replacement. Zombie appearance shuffling remains room/lifecycle
local, while a deferred replacement waits for the original entrance to finish.
Health is transferred by the existing damage ratio. Position, rotation, room,
allocated slot and intrusive links survive the native reconstruction.

File #2's original shared-model predicate is different: `5C8E10` reads the
usual mask at `765F40`, except scenarios 21 through 23 use only families 41 and
43. The core models that exception explicitly.

File #2 retains model metadata for some removed File #1 enemies. Callback index
zero is the placeholder `661120`, even when the model table has nonzero entries.
Those profiles must be rejected rather than accepted merely because the
placeholder function exists. In particular, File #1 families 9, 10, 17, 26,
27, 37 and 38 have no real File #2 callback. The File #1 Neptune workaround has
no File #2 target and is omitted. Newly introduced File #2 families require
their own validated profiles before they are added to an authored pool.

## The 96-root object-bank limit is a real native bound

The File #2 object hierarchy loader `15AFF0` builds per-root node descriptors
at `3E5820 + 9820 + root * 180`, or `3EF040 + root * 180`.
It writes per-root counters at `3E5820 + 12824 + root * 2`.
The companion material-definition loader `15B220`, at `15B268`, stores its
active object-definition count at `3F8040`.

`3EF040 + 96 * 180 = 3F8040`: a 97th root would overwrite the native count
field and following counters. Raising the launcher limit to accommodate a
larger merged bank would corrupt memory. Bank/catalogue preparation must stay
within 96 roots, preserve original progression models and provide models for
every replacement it offers.

## Native floor-model aliases

File #2 keeps its floor-model aliases in `objSnn.mat` members of
`romdata_usa.afs`, not in the 24-byte item metadata or AHI node tags alone.
The native model resolver `38EA40` compares the requested item type with the
material-definition table at `3F8104 + entry * 4`; it does not canonicalize
herbs or ammunition IDs. Callers include `5AF5F0`, `5AF740`, `5AF870`,
`5AF9A0` and `7195E0`.

The original material format has a 16-byte header with a 32-bit entry count
at offset zero. Each 8-byte entry contains a signed 16-bit item type, an
unsigned 8-bit AHI root ordinal, an unsigned 8-bit auxiliary-record count,
and a 32-bit file-relative auxiliary-data offset. Each auxiliary record is
32 bytes. `15B220` reads those fields at `15B288..15B2DC`, and its following
loop consumes the auxiliary records. The parser must retain auxiliary bytes
and remap root ordinals consistently with the merged hierarchy.

For example, original `objS06.mat` has 83 entries. Types 16, 17 and 18 use
root 5, also used by type 15; types 301 and 302 use root 33, also used by
type 300. Types 25, 159, 259, 452, 453 and 454 also have native alias
entries despite lacking distinct AHI root tags. Generating one new model
root per item ID would miss this native relationship and waste capacity.

Material definitions have a separate 96-entry ceiling: the type table at
`3F8104` has a four-byte stride, and the next table begins at `3F8284`,
exactly `96 * 4` bytes later. The per-entry auxiliary buffer has 128-byte
stride, allowing at most four 32-byte auxiliary records per entry. Both
the hierarchy-root count and material-entry count must remain within their
native bounds.

Types 315 and 317 are absent from all twelve original File #2 material
tables. The native exact-match resolver would fail for these types; their
metadata alone does not establish floor-model support. They must not enter
the global replacement pool without an independently validated authored
fallback. Existing scenario records and definitions remain protected.

## Review boundaries

The File #2 continuation uses the same owner-thread and guest-stack protocol
as File #1: an authored 160-byte frame holds the 96-byte native record and
saved position/rotation, and each asynchronous native call resumes through a
registered continuation. Source-model and spawn-identity guards are checked
before the actor is cleared. The original native constructor, target setup,
model, geometry and animation loaders are retained.

Deferred File #2 body loading also needs private scratch memory. Native texture
decoding writes at `word(30099C) + 180000`; the stock scene/UI packet workspace
starts at that same base plus `190000`. A decoded dog texture therefore
overwrote the live UI structure during a mid-frame handoff. Its later draw
routine `70AB10` submitted a null packet at `70ACC8`, leaving the original DMA
drain waiting indefinitely. An items-only control retained valid UI pointers.
The failure was reproduced with passive enqueue observations; no queue count or
packet was forced past the failure.

The 64 MiB backing now contains a 24 MiB native asset heap at `02000000` and an
exclusive 8 MiB loading workspace at `03800000`. All three native scratch
aliases (`30099C`, `303738`, `303740`) are saved in unused continuation-frame
words, redirected throughout asynchronous loading, then restored on completion
or exceptions. The secondary alias retains its native `10000` displacement.
Native decoding, model construction, DMA and rendering remain in the call path.
The pose pointer also follows the original inactive-bank check.

An independent audit decoded all 538 common NBD texture banks and checked native
TEX, AHI, AMO and optional-workspace destinations. The conservative covered end
is 3,405,824 bytes into scratch, within the reserved 8,388,608 bytes. The native
asset heap remains larger than its original 14 MiB. This bounds those original
assets, not arbitrary authored archives or whole-game peak allocation. Private
receipts: `verification-full/scratch-capacity-summary.json` and
`verification-full/scratch-ui-pixel-attribution.json` under
`build-ninja/file2-randomizer/`.

Static mapping and compilation do not establish combat compatibility, full
scenario completion or co-op replication for every supported profile. Live
validation results and exact coverage belong in the task's validation record.

## Launcher integration and validation

With an enabled randomizer, each solo or host launch draws a fresh 32-bit seed
using `RandomNumberGenerator.Fill`. Item, weapon and enemy randomizers use that
same session seed. The installed package and editable pools are unchanged.
The immediately preceding seed in the same launcher game session and the
package's saved seeds are rejected; older seeds can recur by chance. Guests
adopt the host's published seed rather than drawing another. A scenario restart
inside the running game retains its seed. Diagnostic launches can explicitly
pin a seed for reproduction. A launch with no randomizer does not draw one.

An independent runner exercised the compiled production launcher for both
games: 42 seed checks pass, including sequential launches, fresh generator
instances, forced rejection of saved/previous seeds and host/guest agreement.
Receipt: `build-ninja/file2-randomizer/verification-full/seed-audit.json`.

The launcher now imports File #2 packages into its separate mod folder, keeps
File #1 selections unchanged, checks the pinned File #2 ELF, rejects old native
executables, and transfers host randomizer settings to File #2 guests over the
same immutable protocol. Real UDP tests cover adoption of host settings and
rejection of a different game's host. The bundled example is
`examples/mods/randomizer-file2.json`; select File #2 before importing it.

Global assets are built from the player's own verified import. All 12 native
scenario banks retain every original metadata definition, referenced recipe,
model root and MAT alias/auxiliary transform. Missing definitions and models
are appended in canonical type order while fitting the original 128 metadata,
480 recipe-halfword, 96 model-root and 96 MAT-entry limits. No buffers are
expanded or overwritten. Each scenario's additions/omissions are recorded in
`global-items-file2.json`. Its `global-items-NNN.bin` catalogue contains only
missing definitions, and `global-items-NNN.floor` has an `RGIF1` header plus 600
availability bytes. Types without a usable MAT alias are excluded as both
sources and replacements, preserving unsupported original pickups unchanged.
The File #2 native loader validates these files before applying the catalogue.
Native existing definitions win over any duplicate catalogue entry.

Validation on Windows x64, 2026-10-28:

- Both native targets build. Release launcher builds without warnings.
- `cmd /c tools\cheat_check\run-file2-randomizer.bat`: 634 File #2 checks pass.
  These independently pin the File #2 data layout and cover category pools,
  deterministic seeds/variation, exclusions, full-RAM write boundaries, original
  ordinary/personal/key metadata and high recipe ranges, floor aliases,
  scripted-family preservation, damaged/dead sources, canonical spawn plans,
  reversed actor/room orders, six-family limits and bonus-scenario exceptions.
- `cmd /c tools\cheat_check\run.bat`: existing File #1 randomizer/mod fixtures,
  55 cheat checks and 76 File #2 cheat checks pass.
- Launcher `--self-test`: 707 release checks pass, including File #2 selection/import/ELF
  isolation, seed rules, MAT preservation, and real UDP host/join transfer.
- Actual-disc extraction and an independent structural audit pass all 12 asset
  sets. Native `installItemCatalogue` also passes all 12 real scenario item
  tables, retaining every original definition and referenced recipe. Native
  same-seed comparisons and category/model-eligibility checks pass each table.
  Private receipts: `build-ninja/file2-randomizer/catalogue-check/output/validation.json`
  and `build-ninja/file2-randomizer/actual-tables-validation.txt`.
- Combined native Training Ground runs loaded merged NBD/MAT banks, the
  per-scenario catalogue and a canonical enemy plan. Seed 534703871 changed all
  eight eligible placed pickups; seed 43 with exclusions `[0,309]` changed four,
  leaving the excluded handgun and first aid spray records untouched. Original
  key and starting inventory records stayed intact. Direct PrintWindow captures
  show native room rendering, movement, inventory and the original menu flow.
  Private sessions: `build-ninja/file2-randomizer/live-global-01/`,
  `live-global-02/` and `live-main-03/`. Their duration-limit supervisor stops
  terminate the owned process; these exits are not clean-close acceptance.

- Final combined Wild Things check passed for 198.7 seconds: loaded the merged
  `OBJS40.NBD`/`OBJS40.MAT`, 110 definitions and a 34-record enemy plan. Seed 43
  with exclusions `[0,309]` changed all 89 eligible pickups. Three eligible
  enemy source entries received choices; spawn 0's zombie-to-type-29 replacement
  deferred to its original entrance. RAM confirms scenario 40, room 3 and
  active gameplay; direct PrintWindow captures show the rendered zoo entrance
  and movement/camera response. Clean `WM_CLOSE`, exit 0; no fatal diagnostics,
  missing functions or device loss. Receipt:
  `build-ninja/file2-randomizer/live-wild-final/verification.json`.
  An unmodded baseline confirmed that the earlier black screens were part of
  the long opening sequence, not evidence of a mod-induced loading hang.

Extended verification on the final scratch-isolation build, SHA-256
`8c1b0870b7dd3a78339f8ef191915e533289544236d925ce71fa39eb06ae4c22`:

- Underbelly (native scenario 10), seed 10, no cheats: placed handgun handle 16
  changed from type 0 / 15 rounds to rocket launcher type 20 / one round. Normal
  controller interaction transferred ownership into Kevin's inventory. The
  original equip routine set equipped handle 16 and weapon class 20; the native
  model rendered and firing consumed the round, 1 to 0. Clean close, exit 0.
- Wild Things (native scenario 40), seed 104, unchanged example pool: entering
  room 1 completed both original zombie entrances and their deferred native
  reconstructions, `1:16 -> 2:1` and `1:9 -> 20:0`. The dog rendered, moved,
  lunged and attacked through its original `625910` callback. A no-cheat replay
  continued through combat after the scratch fix; a 900-second read-only
  observer captured scratch redirection/restoration and intact UI packet bases,
  with no null enqueue or missing-function reports.
- A separate damage/death replay enabled the native **player health and ammo**
  builtins for survival. Ordinary gunfire damaged the replacement dog
  `300 -> 1 -> -1 -> 0 HP`; its ready flag cleared in the native death state.
  The independent observer used read-only process access and recorded the same
  actor, spawn identity and callback throughout. No enemy HP was written by the
  test controller or observer. All three scratch aliases restored and the UI
  remained intact. Clean close, exit 0.

Private consolidated receipt:
`build-ninja/file2-randomizer/verification-full/verification-complete.json`.
The two item/enemy receipts record executable identity, inputs, exact checks,
cheat disclosure, captures, diagnostic scans and clean exits. The seed audit
adds 42 checks against the compiled launcher.

This establishes the shared rules and actual pickup, equip, firing, deferred
enemy reconstruction and dog combat/death paths. It does not establish every
profile, full-scenario completion, save/resume or live multiplayer combat
replication. Type 20/model 0 completed initialization, but its movement, attacks
and received damage were not established by this test.

RC0 portable replay, 2026-10-28: the LLVM/MinGW build produced by the public
File #2 kit has SHA-256
`af70de5cd3b9383328ce6bd62d07858b8c597034ef4e48b79d9229f3a3f4ea33`.
The kit manifest is
`3921c5a03f5051a42bd8c4d7fe19b5bddc51dc21300e21c77bbe00dc3ebb24dd`.
The same binary repeated the Underbelly seed-10 pickup/equip/fire check without
cheats and the Wild Things seed-104 room 3-to-1 reconstruction/combat check with
player health/ammo builtins. The dog moved and entered attack states, took
ordinary gunfire damage `300 -> 1 -> -1 -> 0`, and finished with its ready flag
cleared. A separate observer used read-only process access, observed all three
scratch aliases redirect and restore, and checked the UI packet bases remained
intact. Both runs closed through `WM_CLOSE` with exit 0 and no missing-function,
null-enqueue or fatal diagnostics. These runs used catalogues generated by the
packaged C# launcher from the owned import, rather than a developer catalogue.
Private receipt: `build-ninja/rc0/portable-mods-05/verification-complete.json`.

The extracted self-contained launcher also built and started File #2 under a
path containing spaces and non-ASCII characters, from an unrelated working
directory with a system-only PATH and isolated launcher settings. The opening
movie and title rendered. A second normal Play worked with the compiler folder
temporarily unavailable and generated source/PCH intermediates already removed.
Two enabled-Randomizer launches produced seeds 1086439559 and 1655475209 in the
launch summary, item settings, enemy settings and native hook logs; the imported
sample package remained byte-identical. The compiler was restored and verified
after the cache check. Private receipt:
`build-ninja/rc0/download-test-05/portable-result.json`.
