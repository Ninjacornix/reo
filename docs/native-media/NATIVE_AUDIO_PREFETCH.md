# Native finite-file read-ahead

Ordinary native audio can now retain 64 KiB of encoded input instead of inheriting
the original 8 KiB ring size. The ordinary game adapter selects this bounded
profile for its owned immutable file extents. The default standalone profile
remains available for comparisons. This changes native buffering, not gameplay
speed, sample rate, PCM priming, volume, decoding or playback-clock rules.

The player admits sector-aligned finite extents with matching immutable view
size and bounded capacities greater than 8 KiB, up to the existing 1 MiB limit.
Malformed identity/geometry is refused before acquiring an output producer.
Sequence and live-input profiles keep their existing separate admission rules.
The asynchronous source owner and its cancellation/join fences remain in use.

Read requests retain their existing maximum of four sectors / 8 KiB. In
particular, a larger first request can pass a loop boundary before the decoder
interprets the header. Enlarging the ring does not require enlarging that initial
read. The change removes the small history limit while retaining this startup
constraint. It does not claim to have migrated the remaining guest control ABI.

Both compiler cohorts pass all 78 standalone native suites. Additional coverage
compares the first-payload decoded digests and sample counts across 8, 16, 64 and
256 KiB capacities, mono/stereo, 24/48 kHz and short/long finite sources. The loop
matrix covers 8/64 KiB, three source rates, offsets, stereo/mono, attenuation,
repeated loop reads, disabling loops, final clocks and joined retirement.

A controlled test primes the native source/output, blocks the actual asynchronous
file read, and continues service and callback rendering for 48,128 output frames
at 48 kHz. The 8 KiB comparison records 27,648 underrun frames; the 64 KiB version
records zero. Retirement stays pending while that read is blocked, then joins
after release. This models a finite source stall and demonstrates buffering
tolerance. It does not establish which component caused V29's historical
383.3659 ms shortage, guarantee resilience before priming, or eliminate arbitrary
worker/controller stalls.

Full native receipts are in
`build-native-sjuni/media-finite-prefetch-results-{llvm,gcc}-v2/receipt.json`.
The exact source cohort is pinned by
`tools/native_reconstruction/native_finite_prefetch_manifest_v1.json`.
The actual SDK131 ordinary adapter object also compiles successfully. Both
compilers pass all 28 declared-port adapter scenarios and detect all 10 injected
faults. Their actual adapter traces report the selected 65,536-byte source ring.
Evidence hashes and coverage are pinned in
`tools/native_reconstruction/native_finite_prefetch_qualification_v1.json`.
The [V31 game retest](NATIVE_MP4_CANDIDATE_V31.md) now completes opening/scenario
playback, bar gameplay and joined shutdown with the actual 64 KiB source profile
and zero recorded underruns. It does not complete Step 3 or confirm audible sync.
