The coordinator builds/runs this isolated sampler candidate after native gameplay
has stopped. It does not edit the production rasterizer or any header.

```bat
tools\gs_sampler_check\run.bat 16 9 0 0 validation-packed1
tools\gs_sampler_check\run.bat 16 9 1 1 validation-packed-cache-parallel
```

Arguments are triangle count, in-memory timing rounds, existing palette-cache
flag, existing triangle-parallel flag, and unique output label. The first run
matches the current cache-disabled serial pixel path. The second exercises
cached sampling and reused row workers. Each compares frozen original and
candidate sources compiled with identical `/O2 /fp:precise` options. The source
is included in the oracle translation unit to expose its actual anonymous
`lerpChannel`; no API wrapper changes the production source.

The inline-only first candidate is frozen as
`build-ninja/m2-gs-sampler/ps2_gs_rasterizer.inline.cpp`, and its existing
`validation1` artifacts are unchanged. Its measured gain was only 0.84%.

The stronger candidate packs the four RGBA interpolation lanes into SSE2,
preserving separate subtraction, multiplication and addition in exactly the
original scalar order. All four texels are still fetched in original
c00/c10/c01/c11 order before channel arithmetic. No texture, CLUT, TEXA,
framebuffer or depth state is changed. The packed path requires finite fx/fy in
[0,1], computed lanes in [0,255], SSE2, and masked host FP exceptions. All other
inputs/platforms retain the original four scalar calls.

Rounding truncates each finite nonnegative lane, subtracts the exactly
representable integer, and increments when its fraction is >=0.5. It never
adds 0.5 to the float. CVTT can introduce a precision sticky flag not generated
by arithmetic; the candidate saves post-arithmetic MXCSR and restores it when
precision was not already sticky. This assumes CRT lroundf does not introduce
additional precision flags, and validation explicitly compares against the
actual CRT rather than treating the assumption as proven. No MXCSR/fenv flag
readers were found in guest/runtime source, but this candidate still requires
exact per-input host flags and control parity. The scalar fallback protects
callers with unmasked exceptions.

The fixture copies the existing 79-case triangle oracle and its 129 independent
color/depth checks. Its benchmark repetition is extended, and the dump guard
uses `is_open()` so a timing-only invocation does not write an unopened stream. Every byte of all
79 complete 4-MiB VRAM images is compared, including live framebuffer/texture,
depth and CLUT aliases, indexed/direct formats, FST/STQ, CLAMP modes, TEXA,
alpha/depth tests, framebuffer masks, blending, sequential primitives, wrapped
address fallbacks, negative/mixed/nonfinite Q and reused sprite worker TLS.
Expect approximately 632 MiB of dump files per configuration.

Additionally, 37,232 direct RGBA calls (148,928 channel outputs) compare the actual channel helper against an
independent scalar SSE operation sequence and integer IEEE-float rounding
oracle. The latter rounds away-from-zero ties from the final float's bits,
without `lroundf` or a floating `+0.5`. Inputs cover every byte-range half-integer,
adjacent float weights, full-range gradients, signed zero, subnormal weights,
endpoints and finite extrapolation/clamping controls. All four MXCSR rounding
modes and both FTZ/DAZ configurations are exercised; the caller's MXCSR control
bits must remain intact. Direct output bytes and the complete per-input MXCSR are compared across variants and against the original four scalar calls. Both clean and pre-existing exception flags are covered, plus nonfinite-weight and exact unmasked-precision fallback controls.

Nine repeated timing intervals draw 16 large indexed T8 bilinear triangles each
using the actual rasterizer and depth writer. Setup, hashing, logging, numeric
checks and dump I/O are outside the timed intervals. Ordered benchmark final
VRAM hashes must match. This measures a synthetic in-memory workload, not native
game FPS. Baseline timing always precedes candidate timing; reverse-order or
additional matched native validation is needed before game-speed claims.

Frozen baseline SHA256:
`C4606121DE765DF6D5F8357B05E623CEAFC51C3D8038FB0C45CFFD4AC0BA80E3`

Candidate SHA256:
`2E64A557E61421B661BCE9CDDF271914EAF6D06C23B203DCF2BB334B9EA4E29C`

After correctness passes, inspect the isolated Release object's sampler to
confirm separate MULPS/ADDPS and no CRT rounding calls on the bounded packed
path. Scalar fallback CRT calls remain. Synthetic gains require a matched
native run before game-speed claims; production integration is not authorized
by the isolated fixture alone.

Coordinator validation of the packed candidate is complete in two configurations.
Both pass 79 complete 4-MiB VRAM comparisons, 129 independent pixel/depth
assertions, 148,928 direct channel outputs and 37,232 exact per-input MXCSR pairs.
With serial triangles and palette cache disabled, nine rounds of 16 T8 bilinear
triangles have median 95,054 us baseline versus 90,844 us candidate (1.0463x,
4.43% lower measured wall time). With triangle parallelism and palette cache
enabled, medians are 19,178 us versus 21,521 us (0.8911x, 12.22% higher measured
wall time). These are synthetic configuration-dependent results; no native
game-speed gain is established and the candidate is not integrated.

The compiled packed path preserves separate MULPS/ADDPS. Its sampler uses two
STMXCSR instructions and conditional LDMXCSR for precision-flag preservation.
Relative to the baseline object, its stack reservation grows from 208 to 248
bytes and one additional nonvolatile XMM register is saved. Those are concrete
overheads, but the timings do not isolate their individual costs. No subsequent
tests or source changes are implied by this validation record.
