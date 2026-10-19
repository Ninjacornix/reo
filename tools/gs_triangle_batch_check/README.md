Isolated packet-local ordered small-triangle batching experiment. Production
GS/runtime sources and headers remain unchanged. The coordinator owns builds,
fixture execution and timing. No native gameplay gain has been established.

`python tools/gs_triangle_batch_check/generate.py` freezes the current GPU and
rasterizer copies in ignored `build-ninja/m2-gs-triangle-batch`; an existing
freeze requires deliberate `--refresh`. `source-manifest.json` records live
and generated SHA256 identities. The generic generator and `.inc` additions
are auditable; no game microcode/assets are included.

The copied parser uses a packet-scope RAII begin/end hook, so normal return,
malformed/truncated payload return and stop return cannot retain deferred
triangles. Every nonvertex raw register, nonvertex packed descriptor, PRIM/PRE,
IMAGE, local transfer, snapshot/presentation, framebuffer clear and reset
flushes pending work before observing/changing state. Nested packet processing
flushes the outer run and executes nested work immediately. Metadata never
survives an outer packet. Async queue/FIFO, byte admission and completion code
are unchanged.

At drawPrimitive's triangle/strip/fan case, the candidate copies all three
complete GSVertex records before original ADC/strip/fan consumption. It keeps
at most64 triplets and the original GS instance; no GS clone/constructor is
used. State writes are barriers, hence draw context, PRIM, TEXA/TEXCLUT/PABE/FBA
and sampler state remain immutable until joined work finishes. Nontriangle
primitives flush first. `REO_GS_TRI_BATCH=1` opts in; defaultoff. A configured
triangle probe or pipeline probe suppresses batching to avoid concurrent
mutable diagnostic aggregators.

One joined RowPool job handles a batch with at least8 triangles, aggregate
clipped bbox work4096 and17 union rows. These are experimental thresholds,
not measured native acceptance/performance evidence. Admission reuses the
existing exact texture-domain/CLUT-address proof, removing only its individual
triangle size gate. It evaluates every triangle against the entire batch's
conservative FB/Z page ranges. Supported output is CT32/CT24 with nonzero FBW,
X inside physical width, nonwrapping VRAM pages, supported Z32/Z24 if depth is
used, and no cross-domain FB/Z overlap. Every possible sampler/CLUT read must
be apart from all batch outputs, including region CLAMP coordinates, bilinear
taps, unaligned texture bases and exact palette entries. Failed proofs draw
the copied triangles serially in original order.

Each worker owns distinct physical rows and visits triangles in their original
order. A private TLS vertex pointer and row clip let the existing drawTriangle
execute its exact arithmetic, full sampler/pixel writer and tests. Triangles
whose clipped Y bounds miss the band skip setup. No whole overlapping triangle
is assigned to a separate competing worker. Per-triangle parallelism is
disabled during this reuse, so no nested RowPool occurs. Pixel depth and
palette/cache/probe TLS are scoped; palette caches remain per triangle/band.
Joining finishes before any subsequent state, transfer or capture command.

Coordinator command from the workspace root:

    tools\gs_triangle_batch_check\run.bat [runtime-build] [benchmark-packets]

The candidate's two objects link before the same runtime archive, supplying
the copied GS implementations without extracting duplicate archive objects.
The same binary runs OFF and ON. Exactly52 complete4MiB VRAM records must
match byte for byte. Fixture cases include90/169/609-pixel bboxes, overlapping
depth/blend/DATE dependencies, CT24 DATE draw rejection and separate CT24/Z24
high-byte preservation, all AFAIL modes,
frame masks, T4/T8 sampling, CSM/CSA, all CLAMP modes, live texture/CLUT-FB/Z
aliases, unsupported/wrapped outputs, state/nontriangle/IMAGE barriers,
truncated assembly continuation, fragmented IMAGE continuation, strip/fan ADC,
capture snapshots, worker reuse and real GS stop/join/reinit. Admission counters
must show useful ON work and zero OFF batches. Key-pixel and actual next-state
effects provide independent checks beside full-buffer parity.

Three test-only cancellation cases stop at triangle row boundaries. Their
timing-dependent partial outputs are independently reconstructed as valid
original primitive prefixes for every physical row, including every untouched
VRAM byte and paired raw depth. They are not compared between scheduler runs.
The private cancellation budget is zero in all normal fixtures/benchmarks;
it does not add pixel clocks, pixel logging or per-pixel counters. After each
stop, existing row workers are joined and reused, then the actual GS lifecycle
stop/join/reinit is exercised.

Four warmed benchmarks render64 small triangles per actual GIF packet with
CT32 or T8 bilinear sampling and90/609-pixel bboxes, five rounds each. Work and
final hashes must match. Setup/shade/cache costs, repeated band setup, global
pixel atomics and page proof overhead may outweigh parallel work; no result is
claimed before coordinator validation. Benchmark output excludes file I/O and
VRAM hashing from its clocked interval. It does not measure native frame rate.
