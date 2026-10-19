Candidate2 extends the root-validated untextured candidate 0075 in a separate
file: `build-ninja/m2-gs-sprite-depth-parallel/ps2_gs_rasterizer.candidate2.cpp`.
It does not change the frozen first candidate, its harness, production files or
headers. Root performs compilation and execution after the active native run.

```
tools\gs_sprite_depth_parallel_check\run-textured.bat 16 9 1 0 textured-validation1
```

Baseline for this comparison is the validated first candidate, SHA256
`87FEF269240306EC9D6DB7BEE9F5D0883E509329AC3D7D6585DE0E6235B31A3B`.
Both executables enable `REO_GS_SPRITE_DEPTH_PARALLEL=1`. The second executable
adds textured depth/DATE bands to the same opt-in setting. The original fast
paths and all serial fallbacks are retained.

Every texture/palette read must be outside BOTH complete framebuffer and Z
page ranges, even for masked depth. The existing CLAMP-resolved coordinate
domain covers repeat, clamp, region clamp and region repeat, including every
possible resolved bilinear tap beyond TEX0.TW/TH. Format-specific page strides
cover CT32/24/16/16S, T8 and T4, including nonaligned TBP spill pages. Actual
palette addresses are enumerated with CPSM, CSM, CSA and TEXCLUT stride/origin;
the proof does not approximate palette placement from CBP alone.

Finite texture endpoints are conservatively bounded to magnitude 1000000 so
interpolated FST/STQ float-to-integer conversions remain valid. Unproven states
use the original serial sampler. The band keeps original texel fetch order and
full pixel writer, disables retained palette/decoded caches during the new
parallel path, installs raw second-vertex Z, and restores worker TLS. Every
primitive joins all bands before returning.

The planned 128 full 4-MiB pairs include the original 57 cases plus nearest and
bilinear sampling in six texture formats and all four CLAMP modes, actual
startup T4 region2/2 / TEST 5000F-compatible masked GE depth and framebuffer 0/112
with Z 224, finite STQ, raw overflow, all CPSM palette formats and both CSM modes.
Independent complete-image oracles use constant textures/palettes with separate
16-bit decode expectations. Live texture/frame/Z feedback, including masked Z,
CLAMP-induced T4 aliases, unaligned T8 page spill, actual palette-origin/stride
aliases, nonfinite endpoints, zero T8 width and VRAM wrap verify serial fallback
against complete baseline images and predicate assertions.

Before drawing, the harness primes retained workers with deliberately wrong
palette/decoded colors and depth. Correct outputs and restored retained TLS
check isolation. Three monotonic partial-stop cases include untextured, T4 and
T8 bilinear region-clamped sampling; each independently reconstructs the whole
VRAM image from complete rows and checks exact attempted-pixel counts. Post-stop
draws verify worker reuse. Cancellation timing is not compared across processes.

Expected counts: 128 complete-VRAM cases, 435 baseline / 508 candidate assertions.
The synthetic benchmark measures live T4 bilinear region2/2 masked-GE sprites
of 512x448 with the actual framebuffer/Z placement. Initialization, hashing and
file output are excluded. No native speed or visual claim before root testing.
No compilation, execution or benchmark was performed by this agent.
