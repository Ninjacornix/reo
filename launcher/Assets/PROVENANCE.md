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

Controls displays the original DualShock sprite
from the supported game's `demo_com.tex` menu atlas. `GameControllerArtwork.cs`
reads the owner's imported NETBIO00.DAT, verifies the source member and decoded
pixels, and stores a private PNG cache under `controller-artwork/` in the selected
storage folder. File #1 uses OB-LZ77-compressed TIM2 pictures; File #2 adds a MOMO
member table. The controller remains the original rights holder's
artwork, outside the project's GPL grant. No source or release package includes
these images. Without a supported import, editable text bindings remain available.

Graphics displays Kevin's original `P00_00.nbd` model from the owner's indexed
`original-assets.pak`, or the existing supported import when no asset export is
available. `GamePreviewAssets.cs` checks the exact model SHA-256 before decoding
its four mesh parts, two TIM2 textures, AHI hierarchy and skin weights. Both
supported games contain the same model payload. This model, texture and skeleton
data remains local and outside the project's GPL grant; none ships in source or
release packages. The decoding schema was checked against the primary format
implementation [Fothsid/libthanatos](https://github.com/Fothsid/libthanatos),
particularly `OBMesh`, `OBNode`, `OBTStripList` and `OBTextureList`.

The live preview plays Kevin's original paired 120-frame idle tracks from the
owner's `PL00_pc_000.bin` animation bank, read from the same asset pack or import.
`GamePreviewAnimation.cs` verifies each edition's exact bank hash, decodes its
packed Hermite keyframes, and applies them to the original hierarchy and weights.
No original motion data ships in source or release packages. Model-only packs
without the original motion bank leave the preview unavailable.
When present, the original standard-handgun model (root 0 in `OBJS01.NBD` for
File #1 or `OBJS06.NBD` for File #2) is attached to animated hand joint 32 using
a calibrated grip-local transform. The shared preview uses the complete original
relaxed idle100 for both body trees; its arms stay lowered instead of holding the
earlier two-handed ready400 stance. The native parent-scale
compensation and incoming/outgoing key order are preserved. No generated idle,
substitute torso/head curves, or authored head-look offset is applied. Weapon geometry, textures
and motion data are read locally and are not distributed with the launcher.
The preview room geometry and procedural wall/floor textures are
project-authored renderer code. It is a separate preview renderer, not a running
game session or a captured movie.

`app-icon.svg`, `app-icon.png` and `app-icon.ico` are original project artwork,
licensed under GPL-3.0-only. They depict a generic open doorway and contain no
publisher logos or game assets. Regenerate the raster sizes with
`tools/build_app_icon.ps1`.

Retail cover and disc-label images are not bundled with source or release packages. On first
normal launch, the launcher downloads verified NTSC-U cover scans and DVD labels into the
selected data folder's `artwork/downloaded/` cache. It does not download game
executables, assets from the disc, or BIOS files. Missing artwork uses placeholders.
Image source URLs and separate rights notices are recorded in
[ARTWORK-NOTICE.md](Covers/ARTWORK-NOTICE.md).

Users may optionally supply their own local `file1-cover.jpg` and
`file2-cover.jpg` in the selected data folder's `artwork/` directory. Exact disc
serials and regional covers are also supported; see [cover selection](Covers/README.md).
Any legacy user-supplied `room-preview.png` remains local. Cover artwork is not covered by this
project's GPL grant; its original rights and any separate licenses still apply.

Earlier cover-art documentation screenshots and the generated GPU instruction
translations have been removed from published sources. Removing published
content does not grant copyright permission or recall copies already downloaded.
