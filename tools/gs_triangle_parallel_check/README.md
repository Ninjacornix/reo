The coordinator builds and runs this checker after the game has stopped. It uses
the ignored prototype at `build-ninja/m2-triangle-parallel/ps2_gs_rasterizer.cpp`
without editing the runtime source or its headers.

```bat
tools\gs_triangle_parallel_check\run.bat [PS2Recomp-build-dir] [rasterizer-source] [benchmark-count] [palette-cache-0-or-1]
```

Defaults: existing Release runtime build, ignored prototype source,16 benchmark
triangles, palette caching enabled, early rejection disabled. For a second cache
configuration, reuse the executable with `REO_GS_TRI_PALETTE_CACHE=0`; no rebuild
is needed. Each process latches the triangle parallel flag once, so serial and
parallel variants must be separate processes.

The checker records79 complete4MiB VRAM images per variant and `compare.py`
compares every byte. Expect approximately632MiB total temporary disk space.
Independent assertions cover constant source colors for all six texture formats,
both filters, FST/STQ, physical CLUT formats/selection/origins, varying Z,
primitive ordering, destination alpha/depth tests, blending, framebuffer masks
and alpha-fail write selection. A coordinate-coded texture also has a separate
analytic STQ interior-pixel assertion.

Large eligible triangles follow the generic interpolation and pixel writer.
Before indexed cases, an existing parallel sprite fills worker TLS with a
different palette; triangle output must still use the new palette. Serial
fallback cases cover cross-row FB/Z alias, narrow FBW, wrapped depth, live
texture/frame/depth and CLUT aliases, TEXCLUT origins moving entries into
outputs, unsupported output formats, and mixed/nonfinite Q. Resolved region
coordinates beyond declared TW/TH and unaligned texture base are also exercised.

The benchmark repeats a large T8 bilinear triangle with depth testing. It reports
wall time and complete-VRAM hash; native gameplay benefit is not assumed. The
unchanged per-pixel atomic counters and per-triangle dispatch can limit scaling.

Coordinator validation: both cache modes pass79 complete VRAM comparisons and129 independent assertions. With caching disabled,16 benchmark triangles take101.036ms serial and21.598ms parallel with the same hash. This is a synthetic large-triangle result; native room improvement is pending. Production integration is patch0063, default disabled. See docs/M2_GS_TRIANGLE_PARALLEL.md.
