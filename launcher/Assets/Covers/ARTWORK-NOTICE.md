# Cover and disc artwork sources

The launcher downloads NTSC-U retail scans on first normal launch, caches them
locally, and applies them to the background and DVD selectors. Image files are not shipped in the
repository or launcher package. File #1 uses a back/spine/front sheet; File #2
uses matching front, back and spine images. Downloads are pinned by size and
SHA-256 in `GameArtwork.Download.cs`. The crop layout for File #1 is authored
metadata included in code.

The DVD selectors use matching North American disc labels from LaunchBox's
[Outbreak gallery](https://gamesdb.launchbox-app.com/games/images/3728-resident-evil-outbreak)
and [File #2 gallery](https://gamesdb.launchbox-app.com/games/images/3729-resident-evil-outbreak-file-2).
The annular meshes, reflective edges and lighting are authored in code.

| Local file | Source |
| --- | --- |
| `file1-ntsc-u-wrap.jpg` | https://psxdatacenter.com/psx2/images2/hires/SLUS-20765/SLUS-20765-F-ALL.jpg |
| `file2-ntsc-u-cover.jpg` | https://images.launchbox-app.com/r2_926a0694-7890-456a-a9f0-cf4b84571e2c.jpg |
| `file2-ntsc-u-back.jpg` | https://images.launchbox-app.com/5e85cd55-a093-4159-a297-c45ad2ca7671.jpg |
| `file2-ntsc-u-spine.jpg` | https://images.launchbox-app.com/8c4509ac-8d5e-4d4c-a226-0a4355806ac8.jpg |
| `file1-ntsc-u-disc.png` | https://images.launchbox-app.com/047fbc2e-e4b4-4273-a826-985c64ec9218.png |
| `file2-ntsc-u-disc.png` | https://images.launchbox-app.com/ebf484e8-03b3-4f91-8b0b-a50328338fe3.png |

Cover artwork and Resident Evil branding belong to their respective rights
holders, including Capcom. These images are not licensed under the project's GPL
code license. Hosting on an artwork website is not a grant of redistribution permission.
This notice records provenance and does not establish a license from the rights
holders. No artwork was fetched from The Cover Project.

Personal disc labels in `artwork` override the download cache; use `file1-disc.png`,
`file2-disc.png`, a regional name such as `file2-pal-disc.png`, or a serial such as
`SLUS-20984-disc.png` (JPEG is also supported). A simple DVD placeholder appears
when no label can be loaded. No game data is downloaded.
