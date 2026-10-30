# Local game font in the launcher

The current `perf/background-video-composition` launcher uses the regular
20-dot Gothic glyphs in the owned game's `d20go04.bin`. This replaces the earlier
chunky `sfont.tm2` choice and the unsuccessful stroke-thinning experiment.
`FONT8_8.TM2` and the serif `s20le04.bin` are other confirmed local font assets.

All launcher-rendered text uses the shared game font: navigation, descriptions,
headings, controls, settings, paths, logs, status messages, tooltips and storage
progress. Windows-managed title bars and dialogs retain Windows fonts. Text inside
artwork is unchanged. Characters outside the generated ASCII subset use WPF font
fallback. No game font or generated typeface ships in source or release packages.

## Owned assets and decoding

The font lives at `NETBIO00.DAT/0/553` in supported File #1 NTSC-U and
`NETBIO00.DAT/0/581` in supported File #2 NTSC-U. Both are 780,800 bytes;
the ASCII glyphs match even though other parts of the tables differ.

- File #1 SHA-256: `f0bbf9de1d7a2a96617ca96b7051f8f0de11691c9ab996383c05e28efec5e2d1`.
- File #2 SHA-256: `1afb94d38e1bb5b7506479a48e7484f8d6d8b10f24fccf6f090d2fd0f3011df8`.

`GameFont` validates archive extents, exact lengths and hashes. Each table contains
7,808 20-by-20 glyphs at 100 bytes per glyph: four-level, 2-bit coverage, most
significant samples first. Double-byte Shift-JIS order skips trail byte 0x7f.
ASCII is mapped to its full-width equivalents, with ideographic space and curly
quote mappings; observed slots include A=220, a=252 and 0=203.

`FontContours` uses marching squares on the four coverage levels to generate
interpolated contours. Counters retain opposite winding; diagonal strokes remain
connected. These contours approximate the original antialiasing boundary rather
than treating each pixel as a rectangle. `BitmapTypeface` writes a deterministic
TrueType with native horizontal/vertical proportions and proportional advances.
No synthetic bold, erosion or horizontal squashing is applied.

The private cache is `<storage>/game-fonts/dialogue-gothic-v2.ttf`, with family
`Outbreak Dialogue UI`. Extraction needs no full PAK export, Python, additional
download or system font installation. Missing or unsupported data uses Segoe UI.
Older small caches are harmless and unused.

## Verification

Verified on Windows, 2026-10-29, against both owned supported imports:

- Release launcher build passed with zero warnings/errors.
- **17 dedicated checks passed**: Shift-JIS slot mapping, spaces/quotes/paths,
  all four coverage values and bit order, truncated/oversized tables, whitespace,
  contour counters/winding, deterministic TrueType and checksum, actual WPF loading,
  ASCII mappings, unsupported-character fallback and cache reuse for both games.
- Independent Python decoding exactly matched all 95 C# ASCII glyph coverage maps
  for both games. FontTools decoded every generated TrueType table; each font is
  35,692 bytes, 96 glyphs including .notdef, 1,280 units per em.
- All 11 pages were visited and 1,474 instantiated text objects inspected with
  no font-family mismatches. Live Play and Graphics screenshots were checked.
- Before pushing, a fresh checkout of the staged source built via
  `launcher/build.ps1`, including the native controller adapter, movie probe and
  preview shader. Its complete `--self-test` passed **765 checks**. The earlier
  artwork failure log was stale; it is not a current suite failure.

Ignored probes, decoded font previews, private font outputs and verification
receipts live under `build-ninja/launcher-game-font/`. None should be published as
project font assets. Original game artwork remains outside the project's GPL grant.
