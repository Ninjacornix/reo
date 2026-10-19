# Licensing and attribution

This fork's original contributions and launcher artwork are provided under **GPL-3.0-only**; see [LICENSE](LICENSE). Existing third-party code retains its own license and notices. This document does not relicense game content.

| Component | License / source |
| --- | --- |
| REO upstream | MIT, copyright 2026 sp00nz. Full notice: [LICENSES/REO-upstream-MIT.txt](LICENSES/REO-upstream-MIT.txt). Source: https://github.com/sp00nznet/reo |
| PS2Recomp | GPLv3; retain its `LICENSE` and the local patch sources. Source: the URL and revision in `.gitmodules` / Git's submodule entry |
| paraLLEl-GS-derived files | LGPL-3.0-or-later; [license](LICENSES/LGPL-3.0-or-later.txt), with original Arntzen Software AS and contributor notices retained in `tools/parallel_gs_backend/resident_gs/` |
| `runtime/gs/stb_image_write.h` | Dual public-domain/MIT terms; the full notice is inside the header |
| Embedded launcher artwork | Original procedural graphics, GPL-3.0-only. [Provenance](launcher/Assets/PROVENANCE.md) and editable generators are included |
| Locally cached game covers | Publisher artwork, not GPL. Downloaded separately for local display; excluded from source and release archives. Sources and attribution are in the asset provenance |
| openSNAP server patch | AGPL-3.0, for the separately installed server; [patch and provenance](network/server/README.md). No server account database or binary is bundled |
| Documentation launcher screenshot | Rendered from this project's interface using its original fallback artwork; no downloaded publisher covers or game screenshots |

Downloaded dependencies, including ELFIO, fmt, rabbitizer, toml11, raylib, Granite and Vulkan components, carry their own notices. Binary distributors must include the notices and corresponding source required by the exact components they build. This table is not a substitute for auditing a particular binary's dependency set.

Resident Evil, Outbreak and related game content belong to their respective owners. This project is unofficial and is not endorsed by Capcom or Sony. The source distribution excludes discs, BIOS, extracted assets, generated game code, save data and proprietary captures. Users supply their own game data locally.

Ignoring or untracking files does not remove them from old commits. Review the complete history before making an existing development repository public; publishing a clean source snapshot avoids carrying private development history into a new repository.

The GPU presentation path optionally uses SMAA by Jorge Jimenez, Jose I. Echevarria, Belen Masia, Fernando Navarro and Diego Gutierrez. Its shader and lookup tables retain their upstream MIT notices; see [LICENSES/SMAA-MIT.txt](LICENSES/SMAA-MIT.txt) and tools/parallel_gs_backend/smaa/upstream/SOURCE.json.
