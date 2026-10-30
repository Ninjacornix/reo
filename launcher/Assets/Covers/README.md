# Cover and DVD artwork downloads

Cover images are not shipped in the repository or launcher package. On a normal
first launch, the launcher automatically downloads the NTSC-U retail cover scans and DVD labels
listed in `ARTWORK-NOTICE.md`. A progress bar appears at the bottom. Verified
images are cached in the selected data folder under `artwork/downloaded/` and
applied to the background and 3D DVD selectors without restarting. Later launches reuse this cache.

Offline, failed or canceled downloads keep placeholders (or existing local art).
Failed transfers are retried on the next launcher launch. Partial files are never
used as textures. Game setup and launching do not depend on artwork downloading.

Personal artwork may be placed in the data folder's `artwork/` directory:

- Exact serial: `SLUS-20765-cover.jpg` or `SLES-51589-cover.png`.
- Region: `file1-ntsc-u-cover.jpg`, `file1-pal-cover.jpg`, `file1-ntsc-j-cover.jpg`;
  use `file2` for File #2.
- Generic fallback: `file1-cover.jpg` or `file2-cover.jpg`.
- DVD labels: use the same prefixes with `-disc.png` or `-disc.jpg`, such as
  `file1-disc.png` or `SLUS-20984-disc.png`. Personal disc labels always override
  the downloaded labels, even when the personal name is less specific.

The installed ISO's SYSTEM.CNF chooses the serial and region; absent or unknown
metadata defaults to NTSC-U. Artwork detection does not add playback support for
another region or revision. Personal images take priority over matching cached
images. Missing regional images fall back to the available NTSC-U artwork.

Full back/spine/front sheets use `-wrap.jpg` or `-wrap.png`, with optional matching
`-wrap.json` crop metadata (`front`, `back`, `spine`: `[x,y,width,height]` in source
pixels). Without metadata the layout is back/spine/front at DVD proportions.
Separate images use `-cover`, `-back`, and `-spine` suffixes with the same prefix.
All suffixes accept JPG and PNG. Invalid crops and unreadable files are skipped.

Images placed in this source directory are excluded from build/publish output;
legacy copies in output folders are removed during build and publish.
