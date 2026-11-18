# Prepare native movie assets

`reo-prepare-movies` is a native Windows preparation helper. It reads the owned
File #1 import, converts its SFD movies into ordinary H.264 MP4s and publishes a
native cache manifest. It does not launch or attach to a game. Conversion belongs
before game launch, never on a game/render thread. The helper needs the existing
launcher-cached pinned FFmpeg executable, with the same SHA-256 check; it neither
downloads tools nor requires Python, an SDK or an administrator service at runtime.
The LLVM helper is linked with its C++ runtime statically; its imported DLLs are
Windows OS components.

Build with CMake from this directory, then run:

```text
reo-prepare-movies <import-data> <cached-ffmpeg.exe> <movie-cache>
```

`--only <source-sha256>` prepares an explicit partial cache for private checks.
Its manifest says `complete_catalogue:false`. Normal game preflight must require
the complete profile. Automatic launcher invocation and distribution of this
helper remain integration work; the code alone does not install that workflow.

The helper verifies the supported imported ELF and each source movie's content
hash through retained read-only source handles. Only one temporary extracted
source is needed at a time. Each conversion preserves every decoded picture at
the declared30000/1001 cadence; repeated/jumping SFD demux PTS are normalized,
not relabeled preserved. The actual encoder completion count must match the
independently inventoried source picture count. Output MP4/hash stamps publish
before the final manifest. Failed conversions leave no successful completion
claim. The helper removes only its exact temporary extracted source after success;
it never recursively deletes imported data.

Subsequent preparation verifies/reuses existing output hashes instead of encoding
again. A cache lease prevents competing preparation. A source and output copy
reserve is checked per movie. The child converter runs at below-normal priority,
has a per-movie deadline and responds to cancellation of this helper. Logs remain
private in the cache. Game content is generated locally and is not a release asset.

`file1_movies.inc` is import-only metadata, including source archive extents and
identities. It contains no game payload. `make_file1_catalogue.py` regenerates it
from the earlier hash-verified inventory and independent picture-count evidence;
that Python script is a developer tool, not a runtime requirement.

The complete run prepares201 references,200 unique movies and216,998 pictures.
Its output is618,385,602 bytes counted by reference (one shared asset is counted
twice); physical MP4 storage is slightly smaller. It takes341.234s on this PC,
with200 conversions and one shared-cache reuse. A second full run performs zero
conversions and reuses all201 references. Native Windows decoding independently
validates every reference's picture count and normalized cadence in86.703s.
This is finite offscreen decoder evidence, not paced game playback or audible sync.

This covers the inventoried File #1 SFD catalogue. The separate numbered
`eff_mov/*.mov` texture-animation path is not converted by this helper. Its
shared initialization/IPU dependencies must be audited before removing common
movie support. File #2 and replacement-mod conversion are not claimed.

Receipts under `build-native-sjuni/host-movie`:

- `full-file1-llvm-v1/receipt.json`: complete conversion and output hashes.
- `full-file1-reuse-llvm-v1/receipt.json`: full verified reuse without encoding.
- `full-native-decode-v1/receipt.json`: all native decoded counts/timestamps.

`tools/native_reconstruction/native_movie_asset_cache_qualification.json`
records the current authored source and evidence identities. Step3 remains open.
