# Launcher artwork and documentation images

## Official game covers (not GPL)

The launcher uses the original North American covers of Resident Evil Outbreak
and Resident Evil Outbreak File #2. Artwork belongs to Capcom and its respective
rights holders. It is not covered by this project's GPL license, and its display
does not imply endorsement. Wikimedia identifies these as non-free cover art;
availability there does not grant a general redistribution license.

Sources used by `GameArtwork.cs`:

- File #1: https://en.wikipedia.org/wiki/File:Re_outbreak_a.jpg
  Image: https://upload.wikimedia.org/wikipedia/en/a/ad/Re_outbreak_a.jpg
- File #2: https://en.wikipedia.org/wiki/File:Resident_Evil_Outbreak_File_2.jpg
  Image: https://upload.wikimedia.org/wikipedia/en/9/9c/Resident_Evil_Outbreak_File_2.jpg

Downloads go directly to Wikimedia and are cached under
`%LOCALAPPDATA%/OutbreakRecomp/launcher/artwork`. No ISO, save, account information
or telemetry is sent. Cached covers work offline. Without available cover art,
the UI uses a plain background and empty cover slots. Procedural replacement
illustrations have been removed. Full cover images are not embedded in the
executable or bundled in release archives.

## Documentation screenshots

`docs/images/launcher-play.png` and `docs/images/launcher-online.png` are actual
captures of the current launcher displaying these official covers. These images
illustrate the launcher and identify the supported games. The cover artwork
visible in them remains the property of its rights holders and is not GPL.
The surrounding original interface is GPL-3.0-only. Capture commands are in
`docs/BUILDING.md`. Screenshots contain no gameplay, account credentials or saves.

The brightness/gamma room preview is loaded from the user's local settings
folder. It is game-derived material and is neither embedded nor distributed.
