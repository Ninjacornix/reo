# Launcher artwork

Launcher text uses the regular Gothic glyphs in `d20go04.bin`, extracted locally
from the user's supported NTSC-U game import. Archive ranges and exact source
hashes are checked for both editions. Interpolated contours are converted into a
private TrueType cache at `game-fonts/dialogue-gothic-v2.ttf` inside the selected
storage folder. No original font data or generated typeface ships in source or
release packages. These glyphs remain the original rights holder's artwork,
outside the project's GPL grant. Missing or unsupported game data uses Segoe UI;
unsupported characters and Windows-managed dialogs retain normal system fallback.
See `docs/LAUNCHER_GAME_FONT.md` for formats, source hashes and validation.

`app-icon.svg`, `app-icon.png` and `app-icon.ico` are original project artwork,
licensed under GPL-3.0-only. They depict a generic open doorway and contain no
publisher logos or game assets. Regenerate the raster sizes with
`tools/build_app_icon.ps1`.

Retail cover images are not bundled with source or release packages. On first
normal launch, the launcher downloads verified NTSC-U cover scans into the
selected data folder's `artwork/downloaded/` cache. It does not download game
executables, assets from the disc, or BIOS files. Missing artwork uses placeholders.
Image source URLs and separate rights notices are recorded in
[ARTWORK-NOTICE.md](Covers/ARTWORK-NOTICE.md).

Users may optionally supply their own local `file1-cover.jpg` and
`file2-cover.jpg` in the selected data folder's `artwork/` directory. Exact disc
serials and regional covers are also supported; see [cover selection](Covers/README.md).
The local brightness/gamma preview is `room-preview.png` in the settings folder.
User-supplied files remain local. Cover artwork is not covered by this
project's GPL grant; its original rights and any separate licenses still apply.

Earlier cover-art documentation screenshots and the generated GPU instruction
translations have been removed from published sources. Removing published
content does not grant copyright permission or recall copies already downloaded.
