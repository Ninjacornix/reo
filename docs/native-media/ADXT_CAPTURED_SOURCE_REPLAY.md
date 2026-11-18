# Captured ordinary ADXT sources

Step 3 remains open. This checkpoint records a real original-call capture and
offline native playback of its sources. It does not activate the native ADXT
guest adapter or prove original gameplay PCM, timing, summation-order or audible
A/V equivalence.

## Coherent V17 candidate and capture

V17 builds committed revision `7f1b268f6dfe3d06a016ab36a5cd49ff7a9ad37e`
against the audited 130-patch SDK and bundled LLVM toolchain. All 2,408 units
compile with no object-cache reuse, and the executable links. The kit manifest
is `8586eba0f065967dc06d0842eae659b3d8703a1a0b4834e3370034839f659a58`;
the executable is
`18ea4ce55c2601841325450b90f045530a7467fb391f55dc8de6eb4bbca02fb8`.
The later source-profile helper is outside this kit. The complete audio backend
uses its V2 **original-source** route (`native_sources=0`).

The first private `adxt-observe-v17` launch correctly refused observation:
`REO_CRI_SYNC_LOG` installs a different `132DF0` entry. Its admission checks
require exact original entries. Removing the variable entirely allowed the
second run; assigning `0` would still enable that older presence-based option.
Both runs closed normally with exit code zero. No observation is claimed for
the first run.

The successful private `adxt-observe-v17b` run lasted 809.828 seconds, including
menus/operator waits and the opening. Its identity-checked owned image ran as
PID 211884, creation FILETIME 134385764092614739. Kevin/normal selection proceeded
through the CG opening into the visible in-engine Jack's Bar scene. Ordinary
window close joined output and sources. Audio reported 37,990,080 callback
frames, 36,000,497 signal frames, zero underrun frames, zero hard failures and
zero queue rejections. This was an observation run, not a controlled speed or
stutter comparison. Movie-work capture retained 4,158 records and dropped
19,462; it cannot establish complete movie-work attribution.

The original-call recorder exported 2,005 events, with zero dropped records and
a completed closed export. It observed three valid constructors: channels
2, 2 and 1 at C4 slots 0, 1 and 2. The game sets each service divisor to 30.
It observed 62 public ordinary AFS starts and 62 matching lower file starts,
71 stops, 297 volume controls, 66 pause controls and six wait-start controls.
Every ordinary recipe used `netbio01.dat`, backend argument zero and a bounded
sector range. All 62 ranges match independently inventoried ADX assets exactly.
No LSC starts, external-SJ starts, nonzero before-PCM callbacks or destructors
were observed. These absences do not establish support or unreachability in
other routes. Full counts and evidence line references are retained in the
offline observer findings.

## Native replay

`verify_adxt_captured_sources.py` checks the completed zero-drop trace, inventory,
finite PCM baseline, actual File1 import, compiler and existing native archives.
It generates a replay plan only from post-call `133490` recipes, excluding the
duplicate lower-start observations. It resolves each range through
`prepare_file_source` on the immutable import and plays it through canonical
native `Instances`, using the captured channels and service divisor.
The V2 replay also preserves the raw game loop-control byte for every source,
including finite headers without loop metadata. Its separate effective-loop
flag selects bounded test termination only. The retained V1 replay normalized
that control to zero on finite headers; V2 closes that exact control-input gap.

Both LLVM and GCC pass all 62 source starts with the stable three-instance
construction and replacement path. All 57 finite clips match the independently
qualified native PCM sample counts and byte digests; terminal raw clocks match
their declared total/rate. Five looping starts complete at least two actual
loop iterations. Each source stops with its output fenced and real worker
joined; the canonical session also joins. Imported file stats and import
manifest remain unchanged. No game, audio device or original gameplay timing
is exercised by this replay.

The fixture deliberately plays one source at a time. Its explicit instance order
is a fixture choice, not original mixing-order evidence. Loop digests describe
the bounded native observation only; no finite baseline is invented for loops.
The native encoded ring remains 8 KiB; the original captured constructor rings
are 133 sectors for stereo and 26 sectors for mono. This replay verifies the
bounded native pipeline's payloads, not exact original buffering geometry.

See [qualification](../../tools/native_reconstruction/adxt_captured_sources_qualification.json)
for source, build, capture and receipt hashes. Actual ordinary guest binding,
broader lifecycle/error/LSC/callback cases, movie scheduling and whole-game
validation still gate Step 3.
