Isolated untextured sprite depth/DATE row parallel candidate. No production or
public-header change. Root/coordinator performs all compilation and execution.

Frozen baseline is current GS0073+0071:
`81CCB7CFB1C6D025BB11390DAE536CD2B498C9BC3DF9376728892C956C2328E2`.
Candidate lives in `build-ninja/m2-gs-sprite-depth-parallel`.

Run after the active native game ends:

```
tools\gs_sprite_depth_parallel_check\run.bat 16 9 1 0 validation1
```

The opt-in `REO_GS_SPRITE_DEPTH_PARALLEL=1` affects only untextured slow sprites
with depth/DATE, at least 32768 clipped pixels, and the original fast paths
enabled. Complete CT32/24 framebuffer and Z32/24 page ranges must fit VRAM and
be disjoint. X must fit the nonzero physical framebuffer row width. All other
draws use the original complete pixel writer serially. Each row band installs
the raw second-vertex Z in TLS, retains the per-row stop check, and joins before
the next primitive. No pixel counters are batched or removed.

The fixture compares every byte of complete 4-MiB VRAM images and exact attempted,
scissor and alpha counter deltas. Independent complete-image oracles cover Z
NEVER/ALWAYS/GE/GT, equality/rejection, raw sprite Z24 overflow, masked Z,
CT32/24, DATE/DATM, alpha-test fail actions, partial/full framebuffer masks,
full-alpha blending, reversed/clipped rectangles, both actual logo framebuffer
bases, and repeated worker reuse with changing raw Z. Alias, wrap, zero FBW,
16-bit formats and row crossing exercise serial fallback parity and the candidate
page predicate. Additional direct invalid-domain checks bound the proof.

Three partial-stop cases substitute only the existing stop-query symbol in the
fixture translation unit. A monotonic latch activates after half the attempted
pixels. The complete resulting image must equal an independently reconstructed
set of whole completed rows, with both color and Z transactions correct and
exact attempted-pixel counts. Cancellation row counts may differ between runs;
they are not compared across processes. Subsequent complete draws verify reused
worker TLS and stop-latch reset. No production stop API or synchronization is
changed. This is a row-guard oracle, not a replacement for native shutdown tests.

Benchmarks reuse memory and draw 512x448 untextured ZALWAYS/write-enabled sprites
with FBW 8, framebuffer 0 and Z 224, framebuffer mask 1. They exclude initialization,
image hashing and file output. No game performance claim before native evidence.
Neither candidate nor fixture has been compiled or executed by this agent.
