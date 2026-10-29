# Asset replacement packs (`.pak`) — research and implementation spec

Status: **v1 implemented on `feature/asset-paks`, unreleased** (2026-10-29).
See `MODDING.md` for the supported format and `ASSET_PAKS_IMPLEMENTATION.md` for
implementation and measured validation. This document retains the research and
original acceptance plan. Implementation refinements: indices are built on demand;
only targeted original entries are hashed; recursive AFS nesting is bounded to four
levels; readable session JSON has a bounded binary companion consumed by the
runtime; exact-byte replacements bypass repacking; ZIP expansion is capped at 2 GiB.

Original audience: the agent that
implements it. Read `CLAUDE.md` first; its rules (owned data stays local, small verified
steps, report real test results) apply throughout.

## 1. Goal

Let mods replace individual game assets (text, fonts, textures, models, audio, movies)
**without a modified ISO** and without changing the verified executable. Motivating case:
issue #25, a Latin American Spanish fan translation that today edits `NETBIO00.DAT`
inside a rebuilt ISO. With this feature it ships as a small `.pak` holding only changed
entries, applied on top of the player's own disc.

Applies to **File #1 and File #2** (same container layout, section 2).

### Non-goals for v1

- Adding new entries, removing entries or reordering archives (section 2.4 explains why).
- Editing `rNNN_h.bin` name tables.
- Texture replacement by GS upload hash (PCSX2-style). That is a later, separate feature.
- Executable strings (`SLUS` rodata). Separate feature; see issue #25 part 1.
- Decoding asset formats (`.sld` compression, `.NBD`, TIM2). v1 moves bytes; editing
  tools are follow-up work.
- Co-op with asset mods (refused in v1, section 4.5).

### Design decision: index the archives, do not unpack them

The original idea was "extract the assets into `.pak` files". Unpacking everything would
duplicate ~4.2 GB per game (the NETBIO files are 99.37% of imported bytes,
`docs/IMPORT_PROFILE.md` section 3), lengthen import, and gain nothing: the runtime
must present original-format archives to the game anyway. So:

- The **player's imported archives stay as they are**. The launcher only builds an
  **index** of every entry at import.
- **`.pak` is the mod format**: a package of *replacement* entries.
- The runtime serves **virtual archives**: original bytes plus replacements, with
  rebuilt tables. Nothing large is written to disk.

Prior art for this approach on CRI titles: Sewer56's AfsFsRedir and its successor
FileEmulationFramework (`sewer56.dev/FileEmulationFramework/emulators/afs.html`) build
a virtual AFS in memory (rebuilt header plus an offset map to the original archive or
replacement files). Outbreak needs one more step: its archives are nested (section 2.2).

## 2. Verified findings

Evidence came from the player's own imported discs (File #1 `SLUS_207.65`, File #2
`SLUS_209.84`) using `tools/assets/afs_inspect.py` (read-only; run it on an import's
`data` folder with `--check`). No game data is in this repo.

### 2.1 AFS container format (as found on both discs)

- Header: `"AFS\0"`, `u32 count`, then `count` × (`u32 offset`, `u32 size`), then
  (`u32 nameTableOffset`, `u32 nameTableSize`) directly after the entry table. Offsets
  are relative to the start of the archive. Little-endian.
- All entry offsets are **0x800-aligned** (CD sector), on both discs (checked).
- Name table: `count` × 48-byte records: `char name[32]`, six `u16` (date/time), and a
  trailing `u32`. On File #1 the trailing `u32` always equals the entry size. On File #2
  it does **not** in `NETBIO01.DAT` and `NETBIO01.DAT/adxsnd_usa.afs` (1,757 records;
  values look like offsets). **Do not assume its meaning**: preserve it byte for byte
  unless T0 shows the game reads it.
- Some archives have **no name table** (pointer 0/0): entries are identified only by
  index (File #1: `bgm.afs`, `pl00_vo.afs`, `voice.afs`; File #2: `pl00_vo.afs`).
- Duplicate names exist (`DUMMY.DAT` has ten `dummy.bin`), so the stable key of an entry
  is its **index**; names are labels.

### 2.2 Disc layout: two levels of AFS

`0FLIST.DIR` is plain text naming the NETBIO files. Each `NETBIO0x.DAT` is an AFS whose
entries are mostly AFS archives themselves. Depth is exactly 2 for asset files.

**File #1**

| Outer archive | Entries (inner entry count) |
|---|---|
| `NETBIO00.DAT` (907 MB, 13) | `romdata_usa.afs` (1342: `.NBD` files starting `TEX\0`), `r001.afs` (1857), `r002.afs` (1177), `r028.afs` (986), `r035.afs` (1123), `r041.afs` (1994), `rfff.afs` (261: network HTML), each `rNNN.afs` followed by `rNNN_h.bin` |
| `NETBIO01.DAT` (1.43 GB, 10) | `adxsnd.afs` (422 ADX), `bgm.afs` (80, no names), `pl00_vo.afs` (997, no names), `voice.afs` (88, no names), `lobby.afs` (6), `s01env/s02env/s28env/s35env/s41env.afs` (5–11) |
| `NETBIO02.DAT` (1.9 GB, 5) | `movie001/002/028/035/041.afs` (14–71 movies) |
| `DUMMY.DAT` (10 MB) | ten 1 MB zero blocks named `dummy.bin` (padding; leave alone) |

**File #2**

| Outer archive | Entries |
|---|---|
| `NETBIO00.DAT` (27) | `romdata_usa.afs` (1087) and 13 rooms `r006 r010 r015 r026 r040 rfff r020 r021 r022 r023 r027 r029 r030` (263–2291 each), each with `rNNN_h.bin` |
| `NETBIO01.DAT` (3) | `adxsnd_usa.afs` (1853), `bgm.afs` (96, named), `pl00_vo.afs` (997, no names) |
| `DUMMY.DAT` (6) | padding |

Room archive entries are `.sld` files whose bytes begin like `10 04 54 49 4D 32 04 01`
(`TIM2` after one or two leading bytes), which suggests an LZ-style compressed TIM2. This
is unverified and irrelevant to v1, which moves bytes unchanged.

### 2.3 How the game finds entries (hypothesis H1, verify first)

The executable contains CRI ADX middleware file-system markers: `E2122501:AFS` at
0x239E38, a partition-name list (`ROMDATA_AFS`, `R001_AFS` … `MOVIE041_AFS`) at
0x242678, and file-name patterns (`%03d.afs`, `%02d.NBD`, `adxsnd.afs`, `bgm.afs`).
CRI's ADXF loads AFS "partitions" by reading their tables from disc at run time, and
loads nested partitions from entries of another partition.

**H1: the game locates every entry through AFS tables it reads at run time, not through
stored offsets.** If true, a rebuilt archive with new offsets and sizes works,
including replacements larger than the original. H1 is strongly suggested but **not
proven**. Task T0 must prove it before any other work.

### 2.4 `rNNN_h.bin` holds names, not offsets

For each room archive, `rNNN_h.bin` starts with two `u32` counts that sum exactly to the
archive's entry count (r001: 775 + 1082 = 1857; r002: 651 + 526 = 1177), followed by
asset names (`DEF01_NBD`, `OBJ00_06_A_00_NB…`). None of the archive's entry offsets
appear in it. So `_h.bin` maps names to entry positions, and **replacements may change
sizes but must keep every archive's entry count and order**. That is why v1 is
replace-only.

### 2.5 Runtime disc paths (all must serve the virtual archives)

1. **IOP CD/DVD file server emulation (most likely the live path).**
   `recomp/overrides/reo_hw_bridge.cpp` handles the game's libcdvd SIF RPCs:
   `search_file` lookups (around line 2928) and sector reads (`read_sectors`, around line
   2889). It is backed by `reo::CDVD` (`runtime/cdvd/cdvd.{h,cpp}`), which reads
   **sectors of the ISO** (`REO_ISO`, set in `launcher/GameSession.cs:209`) at original
   disc positions and does ISO9660 lookups.
2. **PS2Recomp CD stubs.** `third_party/PS2Recomp/ps2xRuntime/src/lib/Kernel/Stubs/CD.cpp`
   with `Helpers/Support.h`: `registerCdFile` gives each looked-up file made-up sector
   numbers (`g_nextPseudoLbn`) and its host-file size; `readCdSectors` maps those to
   `readHostRange(hostPath, offset)`. Changes here go into the PS2Recomp patch series
   (`third_party/patches/ps2recomp/`), not the dirty submodule.
3. **Host-file opens** via `reo::CDVD::resolve_path` (hw bridge around line 2717, FIO).
4. **Legacy direct readers**: `NetbioReader` (`recomp/overrides/reo_netbio.*`) in
   `reo_override.cpp` snapshot-injection code (around lines 558 and 991). The first is
   `if (false …)`; the second runs only without `REO_NATURAL`, which the launcher always
   sets (`GameSession.cs:225`). Dead in normal play; leave alone, or delete as a separate
   cleanup.

Which of 1–3 actually serves NETBIO reads in normal play must be measured (T0).
`REO_CD_LOG=1` makes the bridge log every CD RPC.

### 2.6 Existing mod and import plumbing to build on

- Mods: `launcher/Mods.cs` (`ModManifest`, validation, `Selected`, session export),
  Mods page `launcher/MainWindow.Mods.cs`. Mods are JSON today; co-op rules live in
  `Mods.Selected` and the randomizer host plan.
- Import: `launcher/DiscImport.cs::Extract` copies disc files to
  `data/imports/<game>/<hash>/data` and hashes during the copy.
- Session environment: `launcher/GameSession.cs` (`Set("REO_…")`).
- Long paths: Python build tools use `tools/local_build/long_paths.py`. C++ code must
  use wide `std::filesystem` paths.

## 3. Design

### 3.1 Entry paths

An asset is addressed by an archive path with `/` separators and the **index** of each
level, plus the name as a check:

```
NETBIO00.DAT/1/412          (r001.afs, entry 412)
```

Mod manifests may use the readable form `NETBIO00.DAT/r001.afs/r001_402.sld`, resolved
through the index. It must resolve to exactly one entry, otherwise the index form is
required (duplicate names, nameless archives: `NETBIO01.DAT/bgm.afs/#12`).

### 3.2 Asset index (launcher, at import)

After extraction, write `data/imports/<game>/<hash>/assets.json`:

- Format version, game, ELF SHA-256, and for each NETBIO file its size and SHA-256
  (already computed during extraction).
- For every entry, outer and inner: index path, name, absolute offset, size, and
  SHA-256 of the entry's bytes.

Hashing all entries reads ~4.2 GB once more. Compute it in the same streaming pass as
extraction if practical; otherwise lazily on the first use of asset mods, with progress.
Existing imports get their index built on demand. The index is derived from the
player's disc and stays local.

### 3.3 `.pak` mod package

A `.pak` is a ZIP (deflate or store) with a root `pak.json`:

```json
{
  "format": 1,
  "id": "es-la.translation",
  "name": "Traducción al español latino",
  "version": "1.0.0",
  "game": "file1",
  "elfSha256": "06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46",
  "replace": [
    { "path": "NETBIO00.DAT/r001.afs/r001_402.sld", "file": "files/r001_402.sld",
      "baseSha256": "<sha256 of the original entry>" }
  ]
}
```

Rules, enforced by the launcher (and the runtime checks the plan again):

- `path` must resolve in the import's index; leaf entries only. Never a nested `.afs` as
  a whole, never `rNNN_h.bin`, and never `DUMMY.DAT` in v1.
- `baseSha256` is optional but recommended: if it differs from the player's entry, the
  mod targets another disc revision and is refused with a clear message.
- Sizes: no fixed limit (H1). Cap each entry at 256 MiB and each virtual NETBIO file
  below 4 GiB (sizes are `u32` on disc and in AFS).
- ZIP safety: no absolute paths, `..`, links or duplicates; expanded size bounded
  (reuse the update extractor's rules in `launcher/Updates.Package.cs`).
- A loose folder with `pak.json` is accepted too, for mod development.
- Packs never contain Capcom files except a modder's own edited assets; the mod
  documentation must say so.

### 3.4 Load order and conflicts

v1 follows the cheat/patch rule: two enabled packs replacing the same entry is an error
naming both. Explicit load order can come later.

### 3.5 Session plan

When launching with asset packs enabled, the launcher writes
`<session>/asset-overlay.json`: per NETBIO file, the list of (index path, absolute path
of the extracted replacement file, size, SHA-256). Replacement files are extracted once
into a cache folder under the data folder, keyed by pack SHA-256. Pass the plan with
`REO_ASSET_OVERLAY=<path>`. No plan means exactly today's behaviour.

### 3.6 Runtime virtual archives (C++)

New module `runtime/assets/virtual_afs.{h,cpp}`:

- **Build**: for each NETBIO file in the plan, read the original outer table; for each
  outer entry either keep the original byte range, or rebuild the inner archive if it
  holds replacements. Lay out entries in original order, each 0x800-aligned, and
  rewrite the offset/size tables. Keep name tables byte for byte, except the trailing
  `u32` where File #1 proves it is a size copy (2.1). Keep everything between table and
  first entry. Output a segment list: synthesized header bytes, or (source file,
  offset, length).
- **Read**: `read(offset, length, dst)` walks the segments; gaps are zero-filled.
  Data is streamed; only tables live in memory.
- **Deterministic**: identical plan and disc give byte-identical virtual files.
- **Identity property**: with no replacements, the output must be byte-identical to the
  original file. Make this a test.

Integration (whichever paths T0 shows are live, ideally all three of 2.5.1–2.5.3):

- `reo::CDVD::search_file` returns, for a virtual NETBIO file, a **sector number past the
  end of the ISO image** (so it cannot collide with real files) and the virtual size.
  `read_sectors` serves that range from the virtual archive and everything else from the
  image as today.
- PS2Recomp stubs: `registerCdFile` uses the virtual size, and `readHostRange` is
  routed through the virtual archive. This is a new patch in the PS2Recomp patch series.
- FIO opens of a NETBIO path return a handle reading the virtual archive.

### 3.7 Launcher UI

The Mods page lists `.pak` packs next to JSON mods: name, version, game, number of
replaced entries, and validation errors. Enable/disable like other mods. The Play
page's Launch settings already shows the Mods summary. Follow the launcher palette rule
(`launcher/Palette.cs`, six colours).

### 3.8 Modder tooling (v1.1, optional but valuable)

Modders need the original entry to edit. Add `Outbreak.Launcher.exe --export-asset
<index path> <out file>` (and later a Mods-page button) that copies one entry from the
player's own import. Document it in `docs/MODDING.md`.

## 4. Implementation tasks, in order

Each task lists its acceptance check. Report real results; never claim a check that
did not run.

**T0. Prove H1 and find the live disc path (go/no-go).**
Run File #1 normally with `REO_CD_LOG=1` from title to the first room. Record which
path serves NETBIO reads (2.5) and that the game looks files up by name. Then build,
by script, a modified copy of `NETBIO00.DAT` with the **same content but shifted
layout**: insert 0x800 bytes of padding before `romdata_usa.afs` and before one inner
entry of `r001.afs`, rewriting both tables. Serve it through the live path (for the
experiment, a temporary ISO-side substitution or a test-only file override). Pass: the
game reaches the same room with correct visuals and audio. If it fails, stop: entries
are found by stored offsets, and the design must change to same-size, same-position
replacement only.

**T1. Virtual AFS library and unit tests (no game data).**
Synthetic AFS fixtures, nested two levels, with and without name tables. Tests:
identity (no replacements gives byte-identical output), smaller and larger replacements,
nested replacement updating both table levels, alignment, preserved name records,
reads that span segments, determinism.

**T2. Runtime integration.** Wire `REO_ASSET_OVERLAY` into the live paths from T0
(`reo::CDVD`, the PS2Recomp patch, FIO). Without the variable, behaviour and reads are
unchanged. Test: an identity overlay plan (every replacement equals the original
bytes) plays identically to no plan.

**T3. Launcher index, `.pak` parsing, session plan.** `assets.json` at import and on
demand; `.pak` validation per 3.3/3.4; replacement cache; `asset-overlay.json`; Mods
page. Self-test checks with synthetic packs and synthetic archives.

**T4. End-to-end on real data (player's own disc, nothing committed).**
Audible: a pack that replaces `NETBIO01.DAT/adxsnd.afs/bgm00.adx` with another ADX from
the same disc (for example `Net.adx`). The title music must change. Visible: replace a
text or font entry that the issue-#25 translator identified in `NETBIO00.DAT`. Repeat
one check on File #2 (`adxsnd_usa.afs`).

**T5. Co-op, docs, release.** Co-op refuses asset packs in v1 with a clear message.
Later: an overlay fingerprint checked like the randomizer host plan. Document packs in
`docs/MODDING.md`. The runtime change means a new build kit: the release notes need
`<!-- reo:requires-rebuild -->`.

## 5. Open questions for the implementer

- H1 (T0). Everything depends on it.
- Live disc path for NETBIO in normal play (T0).
- Does any code read the name-record trailing `u32`? File #1 stores sizes there, File #2
  partly something else.
- Do any files outside NETBIO need replacing (`BIN/*.DAT` overlays, `GCRES.BIN`,
  `HDDRC.BIN`)? Overlays are recompiled code with identity checks: keep them out of
  scope.
- `.sld` compression and the `.NBD` format, for later editing tools.
- Linux: the same runtime module should work, so keep it portable.
