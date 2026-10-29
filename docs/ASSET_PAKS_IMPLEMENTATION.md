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
| Self-contained launcher | All 766 self-tests pass with nonexistent .NET lookup roots and system-only PATH, including 23 original-export checks and 38 game-source checks. |
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
in the existing authoring-tool format. The mod loader rejects reference exports;
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
