Coordinator only; no agent compilation, test execution or native launch.

```bat
tools\gs_clut_hit_check\run.bat 16 9 1 0 validation-cache1-serial
tools\gs_clut_hit_check\run.bat 16 9 0 0 validation-cache0-serial
tools\gs_clut_hit_check\run.bat 16 9 1 1 validation-cache1-parallel
```

Arguments are triangle count, timing rounds, existing palette-cache flag,
existing triangle-parallel flag, and a unique output label. Each configuration
compiles frozen original/candidate sources with identical Release options and
links the existing runtime archive. Production code and headers are untouched.

The candidate derives from C460 GS baseline, with no packed bilinear math or
rounding change. It captures the existing per-band/primitive triangle palette
pointer once per sampleTexture call. After the original live index-texel read
and sprite-cache priority, only an existing state2 entry returns its already
decoded safe color locally. State0 misses and state1 aliased entries call the
complete original lookupCLUT with the exact original parameters. Nothing
survives a primitive boundary. No new alias proof, cache, address memoization,
destination-page handling or invalidation rule is introduced. All four
bilinear texels are fetched in their original order.

The 79 full-VRAM cases and 129 independent pixel/depth assertions are copied
unchanged from gs_sampler_check's triangle fixture. Benchmark repetition and
its corrected is_open dump guard are retained. The full 4-MiB VRAM image for
each case is compared byte-for-byte, including live texture/CLUT aliases,
all six texture formats, nearest/bilinear, FST/STQ, TEXA/CLAMP, depth/alpha
tests, blending/masks, wrapped addresses and reused sprite worker TLS.
Expect approximately 632 MiB of dump files per configuration.

An additional 208 independent assertions directly exercise the actual
primitive-scoped palette cache: both T4/T8, nearest/bilinear, CSM0/CSM1,
and CT32/CT24 palette formats. They check state0-to-state2 promotion and
cached repeats, pointer restoration, a changed palette reloaded in a later
primitive, aliased state1 reads observing a real intervening writePixel
fragment, and live reads with no triangle cache. The test constructs public
GSContext values matching its register writes; it changes no public API.

Nine in-memory timing rounds draw 16 large indexed T8 bilinear triangles
using the actual rasterizer, pixel/depth writer and existing cache flag.
Setup, checks, hashing, logging and dump I/O are outside each interval;
ordered benchmark full-VRAM hashes must match. Cache1/serial measures the
intended safe-hit workload. Cache0/serial checks the extra miss branch's
fallback behavior/cost. Parallel validation checks band-local cache views.
These are synthetic timings; native improvement remains unproven.

Frozen baseline SHA256:
`C4606121DE765DF6D5F8357B05E623CEAFC51C3D8038FB0C45CFFD4AC0BA80E3`

Candidate SHA256:
`22C63DB277EEA8136FF06EF7DD76B4013D0EAD32E9924A745068AD2E19463CA8`

After correctness passes, inspect the candidate object's texel fetch lambda
to confirm state2 hits bypass lookupCLUT calls. The cache-disabled native
profile's 18/80 CLUT leaves does not establish a cached-hit cost or benefit.
Results and production integration are pending coordinator review.
