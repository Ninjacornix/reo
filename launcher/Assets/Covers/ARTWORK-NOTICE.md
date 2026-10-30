# Cover artwork sources

The launcher downloads NTSC-U retail scans on first normal launch, caches them
locally, and applies them to the cases. Image files are not shipped in the
repository or launcher package. File #1 uses a back/spine/front sheet; File #2
uses matching front, back and spine images. Downloads are pinned by size and
SHA-256 in `GameArtwork.Download.cs`. The crop layout for File #1 is authored
metadata included in code.

| Local file | Source |
| --- | --- |
| `file1-ntsc-u-wrap.jpg` | https://psxdatacenter.com/psx2/images2/hires/SLUS-20765/SLUS-20765-F-ALL.jpg |
| `file2-ntsc-u-cover.jpg` | https://images.launchbox-app.com/r2_926a0694-7890-456a-a9f0-cf4b84571e2c.jpg |
| `file2-ntsc-u-back.jpg` | https://images.launchbox-app.com/5e85cd55-a093-4159-a297-c45ad2ca7671.jpg |
| `file2-ntsc-u-spine.jpg` | https://images.launchbox-app.com/8c4509ac-8d5e-4d4c-a226-0a4355806ac8.jpg |

Cover artwork and Resident Evil branding belong to their respective rights
holders, including Capcom. These images are not licensed under the project's GPL
code license. Hosting on an artwork website is not a grant of redistribution permission.
This notice records provenance and does not establish a license from the rights
holders. No artwork was fetched from The Cover Project.

The normal cases display the original spines and rear artwork. Placeholders are
used only for missing faces or unavailable downloads. No game data is downloaded.
