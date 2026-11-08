# Larger owned LSC source buffers

Status: isolated implementation and qualification. This profile is not selected
by the game adapter and does not close Step 3.

V22's read-only capture measures LSC capacities 53,248 and 272,384 bytes. The
earlier native input accepted only 8192, including limits in the shared ring,
read-worker factory and decoder staging. Raising a queue threshold alone could
not supply the corresponding physical storage.

An explicit sector profile now admits 2048..1,048,576 bytes, aligned to 2048.
The existing shared-source and worker APIs keep their 8 KiB defaults. The new
worker budget still allows one accepted request, retains its provider and
private result, and requires the real completion/join protocol. The source keeps
the same positive-grant ledger and finish preflight. No unread slot is overwritten
or credit invented to accommodate a larger read.

The decoder window allocates its corresponding staging span before constructing
the source. An explicit workspace span profile permits the larger stable input;
PCM output bounds, requested work, ADPCM arithmetic, marker rules and history/key
updates are unchanged. Unknown profiles and out-of-range spans refuse. The
existing four-argument workspace entry retains its original physical ceiling.
The ordinary file/immutable-sequence player profiles do not automatically admit
larger source rings. LSC source identity, capacity, thresholds, request limits,
sector count and explicit profile must match the retained native input.

Input profile preflight runs before taking its one-use backend binding. Tests
submit a wrong capacity and wrong profile, verify no source binding or output
publication, then successfully open the same input with correct arguments.
Allocation/worker failures retain their explicit existing failure disposition;
preflight does not grant resource authority or guarantee a later allocation.

Both compilers pass all 78 suites from a fresh 404-input cohort. The manifest
now includes all tracked native C++ sources, headers, include files and CMake
files, including leaf tests absent from the earlier manifest. Historical
manifests remain unchanged. The first larger-buffer cohort compiled but exposed
the remaining 8 KiB worker-factory bound in its new input test. Its failed
receipts and exact source snapshot remain retained; the new worker entry and
fresh complete cohort qualify the correction.

The actual async source/decoder/output tests enqueue clips of 500,003 and 120,001
sample frames. Their complete decoded payload digests and 620,004 frames match
the existing 8 KiB path for mono at 53,248/45,056 capacity/minimum, stereo at
272,384/51,200, and both channels at the 1 MiB upper bound. Raw and attenuation
profiles pass with no skipped samples or output underruns. These are real private
worker tests with a declared output provider, not an audible game test.

Separately, the unchanged native SJRB core matches the owned original words at
both measured capacities: 36 compared calls, 360 state words, 9216 descriptor
bytes, 56 guard events and 5,862,672 physical backing-byte observations. Cases
rotate by capacity minus twenty, cross the mirror, split a grant, return a
suffix, consume the remaining bytes and reset. Only synthetic harness bounds
and buffer/descriptor/stack addresses expand. Original words, native core and
the prior comparator remain unchanged; command transcripts contain authored
inputs only. This does not compare original IOP scheduling or grant a live
guest buffer capability.

Both compilers also run the actual factory and ordinary adapter against the new
archives, with production SDK131 header/object checks. The game-facing LSC
enqueue/start/query/repeat/callback/restart/retirement binding remains separate.
Actual game movie graph ownership, full A/V transitions and the reported stutter
also remain open. The last completed game test is the earlier V22 route fix.

Exact sources, receipts and limits are recorded in
`tools/native_reconstruction/lsc_capacity_qualification.json` and
`native_lsc_capacity_manifest_v3.json`.
