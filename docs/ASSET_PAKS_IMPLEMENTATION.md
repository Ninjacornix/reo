# Asset packs: implementation and validation

Implemented on `feature/asset-paks`, based on issue-26 fix `b021125`, in the isolated
`C:/Users/Ninjacornix/reo-asset-paks` worktree. Unreleased. The original checkout's
unrelated uncommitted work and the issue-26 worktree are preserved.

## Implementation

`launcher/AssetPaks.cs` implements strict manifests, ZIP/loose packs, on-demand AFS
indexing, numeric or unique-name resolution, targeted original hashes, conflicts,
verified payload caches, archive-size checks and session plans. The Mods page has
import, edition filtering, enable/disable, errors and replacement counts. The Play
page shows the active count. Checked/unchecked events persist accessibility toggles
as well as ordinary input. File #1 JSON preferences remain saved when switching to
File #2, without blocking its asset packs.

`runtime/assets/virtual_afs.h` rebuilds changed recursive AFS tables with original
indices and 2048-byte alignment. It streams synthesized headers, original ranges
and replacement ranges. Names remain unchanged; a trailing name-record value is
updated only when it equals the original entry size. No effective replacements
returns original bytes, including original padding. Original streams remain open;
replacement streams open on demand to avoid exhausting CRT handles. Windows file
access uses wide extended paths.

`runtime/assets/overlay.h` revalidates the bounded binary plan, executable identity,
original/replacement hashes, numeric paths and protected targets. CDVD, asynchronous
FIO and SDK CD/direct-file syscalls share the provider. SDK patch 0109 also separates
pseudo-file sectors (`0x40000000`) from virtual archives (`0x20000000`) and physical
DVD sectors. The launcher and normal native network configuration refuse packs
with co-op. Older native builds are refused by the launcher capability check.

`asset-overlay.json` is the readable session receipt; `asset-overlay.bin` is the
equivalent bounded native input passed with `REO_ASSET_OVERLAY`. This avoids a new
native JSON dependency. Original archives/ISOs are not rewritten. Only the derived
index, replacement cache and private session files are written. Exact-byte payloads
bypass virtual repacking.

`extract_assets.py` exports native leaves with indices and read-back hashes;
`pack_assets.py` packages changed copies only. Neither decodes formats or supplies
game data. See `MODDING.md` for limits and authoring, and `PRERELEASE.md` for kit
refresh arguments and the required rebuild marker.

## Validation performed

Private owned-data receipts below are under the original checkout's ignored
`build-ninja/asset-paks-build/` directory. No game bytes are committed.

| Check | Measured result |
|---|---|
| Synthetic extraction/packer/C++ reader | Six unittest cases pass: identity with nonzero padding, smaller/larger/empty nested replacements, both tables, names/unknown metadata, nameless archives, alignment, boundary reads, determinism and bounds/protected-entry refusal. |
| Launcher synthetic cases | 32 checks for both editions, paths including Windows normalization/device aliases, malformed/duplicate manifests, ZIP duplicates/missing files, AFS extents, ambiguity, loose packs, duplicate IDs and co-op policy. |
| Self-contained launcher | All 793 self-tests pass with nonexistent .NET lookup roots and system-only PATH, including 23 original-export checks, 38 game-source checks and 27 executable-string checks. |
| Real package integration | 29 checks pass: both editions, deterministic plans, cache reuse without rewriting payloads/receipts, cache corruption at launcher/runtime, bad binary headers, duplicate targets, conflicts naming both packs, wrong base hashes, ZIP links, network refusal, Unicode cache paths exceeding 300 characters and exact-byte identity bypass. |
| Complete host/sector route comparison | All 4,920,984 replacement bytes for File #1 and 62,438 for File #2 agree with the payloads through host and CDVD sector routes. |
| Portable compilation | Both refreshed frozen kits compile all four affected C++ units with pinned LLVM/MinGW UCRT after normal owned-ELF catalogue generation: eight units pass. |
| Real launcher UI | Windows UI Automation verifies enabled controls and persisted untick/retick for both editions in isolated portable storage. |
| Full launcher launch | The self-contained launcher uses real `GameSession.Launch` to prepare/cache enabled packs, pass the plan to each native child, present a game window and close with exit 0: three replacements for File #1 and one for File #2. |

Compile the standalone native probe, then run all synthetic asset tests:

```powershell
g++ -std=c++20 -O2 -static -I . tools/assets/virtual_afs_check.cpp -o <probe.exe>
$env:REO_AFS_CHECK = '<probe.exe>'
python -m unittest discover -s tools/assets -p 'test_*.py' -v
```

`tools/assets/cdvd_routes_check.cpp` is the standalone owned-import route checker.
The launcher offers `--test-asset-paks <result.json>` and the documented pack
preparation command. Private integration receipts are in
`package-verification-final/result.json`, route logs and `portable-ui/ui-verification.json`.
`full-launcher-verification.json` records the complete launcher-to-native checks.
Those runs used private settings, hard-linked read-only import aliases and copied
saves. The temporary worktree storage locator was removed after the runs.

## Native gameplay evidence

The File #1 executable was linked from the working issue-26 graph with changed
bridge/CDVD and patched SDK objects. File #2 was linked from its developer graph
with the corresponding changed objects. These are native execution checks.

- File #1 without packs: Outbreak room 1 reached, ordinary pad movement, exit 0,
  no fatal errors or missing functions (`file1-baseline/result.json`).
- File #1 identity pack: same opening and movement pass, exit 0, no fatal errors
  or missing functions (`file1-identity-final/result.json`).
- File #1 replacements: scenario-selection artwork visibly turns green. Two
  compressed textures grow from 59,206 to 62,906 bytes and 791,508 to 805,086 bytes.
  A streamed ADX is replaced with another owned-disc ADX of a different size.
  All three replacement sources are read; room 1 and movement pass; exit 0; no
  fatal errors or missing functions (`file1-replacement-final/result.json`).
- Decoded audio: the first two movie PCM streams remain byte-identical between
  identity and replacement runs; the following two music PCM streams change and
  remain nonzero. This verifies output beyond archive loading
  (`audio-verification.json`).
- File #2: a cockpit texture grows from 58,564 to 62,438 bytes, with visibly green
  inventory artwork (`file2-visible/frame-230.png`). The final build reaches
  scenario 20's training room 1, with 23 unpaused gameplay samples, movement of
  183.77 game units, one replacement-payload read, exit 0 and no fatal errors
  (`file2-final/verification.json`).

Screenshots were visually inspected. Initial font/music candidates that the chosen
route never requested were not counted as replacement success; replacements were
changed to assets observed in the disc-read trace. These are representative opening
checks, not full-campaign or arbitrary-mod compatibility claims. PS2 memory and
native format constraints still apply.

The portable check is a runtime preflight, not a complete cold build/link of generated
games. Private kit receipts and compile logs are in this worktree's ignored
`build-ninja/asset-paks-kits/` and `asset-paks-portable-check/`. Before publishing,
run the normal complete packaging/cold-build checks for the final merged tree.

## Earlier relocation and requested extraction

`relocation_probe.py` prepared private ISOs with appended NETBIO00 archives and
shifted nested offsets. File #1 reached Outbreak room 1 with movement on the
issue-26 baseline. Its task-owned read-only mount was detached. Private receipts
remain in `build-ninja/asset-paks-t0/`. The File #2 r006 probe was prepared and
byte-checked, but not gameplay-tested; the virtual-reader checks above are separate.

The requested full NETBIO leaf extraction completed into the original checkout's
ignored `build-ninja/extracted-assets/` folder:

- File #1: 18,641 files; 4,217,165,504 payload bytes.
- File #2: 17,230 files; 2,384,632,075 payload bytes.

Every extracted file passed read-back SHA-256 comparison. Container headers and
padding, DUMMY padding, executable and code overlays are excluded. Keep these owned
game files private.

## Optional original-asset export during setup

`AssetExports.cs` writes one ZIP64-capable `original-assets.pak` per game, with
every indexed NETBIO leaf in its original native format. Numeric prefixes preserve
duplicate and missing names. `asset-reference.json` identifies the reference
archive, and `assets.json` records numeric addresses, paths, byte counts and hashes
in the existing authoring-tool format. Initially the mod loader rejected reference exports;
authors package selected changed files with `pack_assets.py` instead.

The existing WPF Game files page has an unchecked per-edition setup preference,
**Export now** for existing imports and **Open exports folder**. A newly selected
supported ISO opens this page. Both explicit setup and the normal automatic setup
path honor the preference after importing/building. Existing progress and Cancel
controls cover export, verification and checksum recording. Controls that would
change the active edition/settings are disabled during work.

The exporter checks free space, cancellation and executable identity. It writes to
a unique staging folder, hashes every payload while copying, reopens and verifies
every compressed entry, then records the whole-pack checksum before publishing.
Unchanged source/output stamps reuse completed exports; changed exports are kept
while a new version is created. Cancellation removes only this invocation's named
staging files, preserving imports and completed exports.

Follow-up evidence is in the original checkout's ignored
`build-ninja/asset-export-build/` folder:

- All 23 synthetic export checks pass, including per-edition preferences, every
  leaf and hash, duplicates/unsafe names, empty files, authoring metadata, reuse,
  preservation of edited exports, pointer confinement, cancellation, wrong ELF,
  both editions and long Unicode output paths. The full portable suite passes
  728 checks without an installed .NET lookup path.
- Real File #1: 18,641 entries, 4,217,165,504 payload bytes, a 3,611,570,825-byte
  pack. Real File #2: 17,230 entries, 2,384,632,075 payload bytes, a
  1,764,432,471-byte pack. All entry sizes/hashes match the earlier independent
  Python extractions. Both whole-pack checksums match their receipts; repeated
  exports reuse the archives without rewriting them.
- A changed File #1 font copied from the reference export was packaged with the
  Python authoring tool. All 9,280 replacement bytes agree through the native host
  and sector routes.
- Windows UI Automation checks both editions start unchecked, retain separate
  preferences across restarts, and require an imported game for **Export now**.
  Starting a real export and canceling it verifies disabled busy controls, removed
  unpublished output and preserved imported data. Separate real Import checks for
  both games confirm that ticking the setup option triggers export and canceling
  retains the completed import. These use private hard-linked import aliases,
  without modifying original game files. The compact layout was visually inspected
  using the page's existing scroll area.

Only the newly generated large test archives were removed after these checks to
recover test space. The requested raw original extractions remain in place. No
native runtime changes were needed for this launcher follow-up; the earlier
native/gameplay evidence and final-release packaging limits above still apply.

## PAK as a game source

The follow-up **Use PAK instead of ISO** switch is independent for each edition.
It changes the picker, readiness checks, explicit Import and normal Play setup.
Both source paths are retained when switching. Successful exports remember their
PAK path without enabling PAK mode automatically. The setup remains within the
existing WPF page, with keyboard-accessible controls, wrapped explanatory text and
the existing progress/cancellation area. Busy controls cannot change the source.

The complete export adds `game-data.json` and private `_game/` ranges to the
reference ZIP. The manifest describes every imported file with its length,
SHA-256 and ordered ZIP ranges. Already-exported leaf bytes are referenced rather
than duplicated. Original archive headers, padding, shared/empty ranges and all
boot files are preserved; whole-file read-back verification checks the resulting
disc data. This supersedes the earlier asset-only export's boot-file exclusion.
Those older exports must be regenerated to serve as a game source. Installable
replacement mods retain their earlier format and limits.

`GamePaks.cs` checks paths, duplicates, member/range counts, total size, edition,
executable identity and complete range coverage before preparing a cache. Fresh
imports decompress and verify all game files into an unpublished staging folder.
Matching existing imports on the same volume can be reused through verified hard
links after checking the entire PAK. Completed caches are reused by PAK checksum,
with file-size and executable checks; relocation repairs the source receipt.
Cancellation removes only the newly created staging folder. The PAK remains the
selected source, while native reads use ordinary cached files.

In PAK mode the launcher passes `REO_GAME_PAK=1`, leaves `REO_ISO` unset, and
requires `[GAME-PAK-1]` in the native image. CDVD assigns deterministic, separate
sector extents to the cached files; both search and sector reads use this map.
Bounded zero padding supports the game's read-ahead beyond short files. Existing
virtual replacement archives take precedence. ISO mode keeps its original reader.
Updating `cdvd.h` also requires rebuilding its consumers, including the HW bridge.

Evidence is in the original checkout's ignored `build-ninja/game-pak-build/`:

- The final self-contained build passes **766** checks without .NET lookup roots
  or developer tools on PATH. The 38 game-source checks cover both editions,
  fresh synthetic imports, cache reuse, moved PAKs, existing-data reuse, corrupted
  payloads even with matching existing data, traversal/device names, duplicate
  members, invalid ranges, wrong edition/ELF, old asset-only PAKs, cancellation
  after writing partial files, preserved completed imports and source preferences.
- Both complete real exports pass every reconstructed game-file SHA-256 against
  the original import manifest: File #1 has 85 files / 4,267,473,063 bytes; File #2
  has 80 files / 4,424,132,752 bytes. The complete PAKs are respectively
  3,621,060,995 and 3,693,419,214 bytes. These sizes include private boot/code data,
  so they differ from the earlier asset-only exports. No game bytes are committed.
- Both real PAKs prepare verified caches from matching owned imports, and the
  self-contained launcher launches each native game with a nonexistent ISO path,
  records `iso: null` / `gameSourceType: pak`, presents a game window and exits 0.
  Complete cold disk extraction was tested synthetically; the full owned-game
  trials use verified hard links because local free space cannot hold another
  complete data copy alongside the PAK.
- File #2 reaches training scenario 20, room 1, with 25 unpaused gameplay samples,
  movement of 183.77 game units, one replacement-payload read and exit 0. No failed
  sector reads occur. File #1 reaches Outbreak room 1, moves 900.11 game units,
  reads all three replacement payloads (including the changed music), and exits 0
  with no fatal errors or missing functions. Its scenario-selection trial enables
  the unlock option in a disposable save profile. Both screenshots were visually
  inspected; these trials do not modify the player's saves.
- The standalone synthetic C++ reader verifies file search, all 65,539 payload
  bytes, last-sector padding, read-ahead and rejected invalid reads with a missing
  ISO path. Both editions' CDVD and HW bridge units compile with the pinned
  LLVM/MinGW UCRT toolchain; both private native candidates also compile/link from
  their established MSVC-compatible graphs.
- Windows UI Automation verifies the source switch, correct picker caption,
  independent persistence and automatic-export availability for both editions.
  The compact setup view was visually inspected and the long PAK hint wraps.

These are opening and representative replacement checks, not full-campaign or
network-compatibility claims. A final release still needs refreshed kits and the
normal full cold-build/package verification described in `PRERELEASE.md`.

## Executable string reference extraction (issue #25)

`tools/assets/extract_elf_strings.py` exports an addressable editing reference
from either owned, SHA-256-verified game executable. It checks ELF32/MIPS program
headers and derives addresses from the actual file-backed PT_LOAD segment. The
executable has combined/stripped sections, so UI grouping uses a hash-locked data
range rather than claiming an ELF section provides semantic UI boundaries.

The File #1 export covers file offsets `0x150060..0x159F80`, including UI/scenario text
before the issue's reported start. It finds 980 printable NUL-terminated
candidates; 421 lie in the narrower UI/name region ending at `0x152E80`, of which
391 have matching aligned address words in the binary. Literal word matches are
static pointer candidates, not verified call sites or runtime use. Every entry
retains original bytes, spaces, line breaks, tags, encoding and a conservative
byte budget that excludes the terminator and adjacent padding.

The private output is in the original checkout's ignored
`build-ninja/executable-strings/file1-checked/`. Its 160,750-byte reference PAK
contains editable CSV/JSON plus the indexed original byte pool. All 980 entries'
bytes, addresses, terminators, encoding round trips and literal address words
were independently checked against the original executable. The issue's examples
resolve to `0x250E20` (inventory command with leading spaces), `0x250D60` (herb
prompt with line breaks/spaces), `0x250850` (floor prompt with formatting tag),
and `0x24FE60` (scenario name). Verification receipts remain beside the private
PAK. The source executable SHA-256 remains unchanged.

Four synthetic unittest cases pass for ELF bounds/mapping, duplicate strings,
encoded byte budgets, formatting, truncated/binary runs, ZIP/CSV read-back,
source identity and refusal to overwrite or export inside imported game data.
REA native tools were unavailable in this session; this is direct static ELF
byte analysis, without decompilation or game-rendering evidence. No REA client
configuration or analysis-engine installation was changed.

File #2 uses its independently inspected range `0x1554D0..0x169B80`, with the
narrower UI/name region ending at `0x159DB0`. It has 1,928 printable candidates;
671 lie in the UI region, all with matching aligned address words. The separate
private reference PAK and receipts are in `build-ninja/executable-strings/file2-checked/`.

`launcher/ElfStringReferences.cs` implements the same extraction in managed code;
the launcher needs no Python or external analysis tool. Every real launcher export
for either edition embeds the seven editing/reference files directly under
`executable-strings/` inside the existing `original-assets.pak`, alongside native
assets and boot data. `asset-reference.json` points to the string manifest. A
read-back check regenerates references from the verified original ELF and compares
every embedded payload before publishing the completed PAK. Export receipt format
3 invalidates older export caches; re-exporting preserves the old pack in place
and publishes a new version with references included.

The portable launcher passes 793 self-tests, including 27 new checks for both
edition profiles, ELF bounds, addresses, pointer words, byte budgets, tags,
encoding, duplicates, byte pools, metadata checksums, CSV, cancellation and source
identity. Private integration evidence in `build-ninja/combined-string-build/`
uses both real owned executables with small synthetic NETBIO fixtures. The C#
catalogues match the independent Python JSON entries, raw byte pools and parsed
CSV exactly for both games, including File #2's embedded CRLF line breaks.
Both single combined PAKs preserve asset/boot metadata, survive ZIP read-back,
upgrade old receipts while retaining previous exports, reuse completed results
without rewriting and restore every fixture game file byte for byte. String
references are not copied into runtime game data. These integration checks run
with system-only PATH and nonexistent .NET lookup roots. The large native assets
and runtime code are unchanged from the earlier full-game validations.

That first stage added reference extraction only. The runtime and import follow-up
below supersedes that limitation.

## Edited PAK import and executable-string runtime overrides

`ReferencePakMods` scans an edited original export imported through Mods, hashes
its indexed native payloads and compiles only changed entries and translation
fields into an ordinary replacement mod. It supports combined exports and
standalone string references, including quoted/multiline CSV. Import is asynchronous
and cancellable; staging files are published atomically. An original ISO or
unmodified complete game PAK remains the base. `_game` boot/code changes are not
compiled into mods. Export receipt format 4 refreshes the editing instructions and
runtime-support metadata while preserving earlier exports.

`ExecutableStrings` validates addresses, original hashes and exact byte budgets
against each supported ELF catalogue, enforces CP932 encoding and formatting,
detects conflicts and emits a bounded binary plan. `runtime/assets/executable_strings.h`
independently verifies the ELF hash, original file and guest-memory bytes, allowed
data ranges, terminators, formatting, overlaps and plan limits before any write.
The bootstrap applies the plan before guest execution and logs each replacement.
The disk executable is never patched. Co-op and older native binaries are refused.

The self-contained launcher passes 847 checks with system-only PATH and nonexistent
.NET lookup roots. Eleven Python asset-tool tests complete (nine pass, two optional
native-probe tests skip without their environment variables). The native string
probe verifies actual bytes, zero termination and atomic rejection of malformed
plans against both owned executables. Private evidence is under the original
checkout's ignored `build-ninja/applied-pak-build/`; no owned game data is committed.

Real edited-export imports were converted and prepared for both owned games.
File #1 replaced two compressed texture entries and a room ADX with a differently
sized original track; File #2 replaced a texture entry. Normal input reached
gameplay and movement in both editions, and screenshots show the deliberate magenta
texture changes. The decoded File #1 room-audio PCM differs from the identity
baseline while the opening movie's PCM remains identical. Both exit normally.

The File #2 item menu visibly renders `PAKTEST` in place of `COMBINE` in
`file2-final/translated-command.png`. File #1's eight and File #2's six patches
are logged and remain present in read-only live guest-memory observations.
The attempted File #1 item-menu capture did not establish visible string rendering;
do not infer that all extracted candidates are displayed or translated. Some menu
labels, including the scenario-selection title tested, are texture images.

Full `GameSession.Launch` checks with the imported mods pass for both editions:
each launcher copies the updated native build, prepares both plans, supplies their
environment variables, opens the game window and records exit code 0. This is also
tested with system-only PATH and no .NET lookup roots. Original disk ELF hashes
remain unchanged. Both updated bootstrap units compile with the exact pinned
LLVM/MinGW UCRT toolchain; linked gameplay tests reuse verified unchanged objects
with freshly compiled bootstrap units. Native string probes pass 17 File #1 and
15 File #2 checks, including no partial writes after invalid plans.

These checks establish representative texture, sound and string replacements.
New models, rooms, object behavior and complete campaign modifications have not
been exhaustively playtested; replacements must preserve their native formats and
the game's existing structural and memory constraints. This remains unreleased
and requires the final merged release's full cold-build/package checks.

## Issue #25 follow-up: verified padding and stale imports

The translator's 2026-10-29 reply requests additional NUL padding for longer
Spanish UI strings and cleanup of obsolete import folders. Both editions now
export an optional `paddingMaxBytes` budget while retaining the original
`maxBytes` and a false-by-default `usePadding` flag. JSON/CSV imports and the
Python packer honor explicit per-string opt-in. The CP932 half-width katakana
byte mappings used by custom translation fonts remain accepted unchanged.

Budgets are bounded by untouched zeros, one reserved NUL, the next 16-byte
alignment boundary, supported data-region limits and literal pointer targets
across every file-backed ELF segment, including KSEG aliases. This prevents long
zero-filled non-UI data runs being treated as free string space. Calculated and
overlay references cannot be excluded by this static check; author review and
gameplay testing remain necessary. The original string hash remains unchanged.

Strict plans stay `REOSTR1`; a plan using extra space becomes `REOSTR2` and carries
both original length and verified capacity. The native loader accepts both,
revalidates the complete plan and guest zeros, detects overlapping extents and
applies changes only after validation. The launcher checks the new native marker
before launching padded strings. Original game files are unchanged.

`StaleImports` lists only recognized completed version-1 ISO and version-2 PAK
imports under the selected game's own import directory. Selected folders and
remembered sources/executables/cards are protected. Unknown files, bad receipts,
pending imports and any nested reparse points exclude a folder. The Game files
action displays candidates and their sizes and defaults to cancellation. Cleanup
takes the same import lock as setup and repeats scope/link/selection checks before
each delete. It never runs automatically. Size is an estimate when data shares
hard links.

Validation (private evidence: original checkout `build-ninja/padding-pak-build/`
and this worktree's ignored `build-ninja/`):

- Self-contained launcher: **891 checks pass** with system-only PATH and absent
  .NET lookup roots. New checks cover padding, literal/aliased pointers, strict
  defaults, JSON/CSV opt-in, custom font bytes and cleanup of synthetic fixtures.
- Python asset tools: **13 tests complete**, 11 pass and two optional probe tests
  skip without their environment variables.
- C# and independent Python extraction match every entry, original byte pool and
  parsed CSV for both real ELFs: 980 File #1 / 1,928 File #2 candidates, with
  larger budgets for 930 / 1,763 respectively. `Unequip items.` with its three
  leading newlines expands from 17 to 31 bytes in both.
- Native probes pass 18 strict + 15 padded checks for File #1 and 16 + 16 for
  File #2. They compare the entire synthetic RAM image to expected changes,
  verify terminators/padding, reject referenced space and malformed plans, and
  establish no partial writes after rejection.
- Both updated bootstrap units compile under the exact pinned LLVM/MinGW UCRT
  compiler. Local gameplay binaries freshly compile/link those units against
  previously verified unchanged objects; this is not a fresh whole-game build.
- Edited standalone reference PAKs import into replacement mods and produce v2
  plans for both games. Both also pass full launcher launch/window/normal-exit
  checks. Real game runs reach gameplay and visibly render longer labels:
  File #1 `  RELOAD` (8 bytes) becomes `  PAKPAD OK` (11), and File #2 `EQUIP`
  (5 bytes) becomes `PAKTEST` (7). Screenshots are
  `file1-personal/padded-item-command.png` and
  `file2-personal/translated-command.png`. These test PAKs remain private.
- WPF UI checks exercise cleanup's actual review dialog, cancellation and
  confirmation. Only the stale fixture is removed; the active import, unknown
  personal files, a nested junction and its target survive. The normal Play
  action rejects an older string-v1 native binary with the rebuild message.

No release or issue comment was published by this follow-up. Final merged release
packaging and cold-build validation remain required as described in `PRERELEASE.md`.
