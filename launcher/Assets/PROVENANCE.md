# Original launcher artwork

SPDX-License-Identifier: GPL-3.0-only

The four edition PNGs are original procedural artwork for this launcher. The artwork uses geometric shapes and gradients. It contains no game screenshots, cover scans, official logos, extracted textures, font outlines, or external image inputs.

Editable sources:

- `../tools/New-Artwork.ps1`: generates both background and poster variants.

These sources and their generated artwork are distributed under GNU GPL version 3 only. The complete license is in `LICENSE.txt`. This asset notice does not change licenses on other repository components.

The build embeds only these original PNG resources. Publisher cover art is fetched separately for local display, not embedded in the executable or included in release archives. Downloads are cached in `%LOCALAPPDATA%/OutbreakRecomp/launcher/artwork`; an unavailable network leaves the original illustrations visible. Existing cached covers work offline.

## Publisher cover art (not GPL)

Resident Evil Outbreak covers belong to Capcom and their respective rights holders. They are not licensed by this project's GPL grant. Their display does not imply endorsement. Do not copy the local cache into source or release archives without the necessary rights.

Cover sources used by `GameArtwork.cs`:

- File #1: https://en.wikipedia.org/wiki/File:Re_outbreak_a.jpg — image https://upload.wikimedia.org/wikipedia/en/a/ad/Re_outbreak_a.jpg
- File #2: https://en.wikipedia.org/wiki/File:Resident_Evil_Outbreak_File_2.jpg — image https://upload.wikimedia.org/wikipedia/en/9/9c/Resident_Evil_Outbreak_File_2.jpg

Each game's cover is used on its card and as its faded background. Image requests go directly to Wikimedia's image host; no ISO, save data, settings or telemetry are sent. Availability of these images online is not a redistribution license.

The game names shown in the interface identify the supported games. They do not imply endorsement by their publisher. This provenance covers the launcher artwork, not a legal review of the game recompiler, dependencies, executable, or game data.

The brightness/gamma room preview is loaded separately from the user's local launcher settings directory. It is game-derived local material, is not covered by this original-artwork grant, and is not embedded or distributed with the launcher.


## Documentation screenshots

`docs/images/launcher.png` and `docs/images/launcher-coop.png` are captures of
this project's launcher with `--screenshot --original-artwork`. They show the
original procedural fallback artwork, not downloaded publisher covers or
gameplay. The interface and original artwork retain this project's GPL-3.0-only
license. Capture commands are documented in `docs/BUILDING.md`.
