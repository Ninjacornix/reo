# Native timed video frames

The native `VideoFrames` owner joins one prepared picture pool to one retained
movie timing Context. `NativeVideoFrames` and `NativeFrameSurface` adapt the
existing same-device D3D11/Vulkan movie bridge. The core does not use guest RAM,
CPU registers, decoder-device headers, wall-clock thresholds or display FPS.
Production-game selection, complete movie construction/rebuild and scheduler
binding remain separate work.

The owned original pool bodies establish first idle/unreferenced reservation,
ready states 2/4, strict signed raw-numerator ordering and stable ties. Timestamp
scales are not used to reorder that pool. Public release changes ready-reference
state 4 to held state 3; demotion and explicit reference counts remain separate.
The typed API adds opaque owner/incarnation keys and refuses foreign/stale keys.
A pool has at most 16 slots and a Context has one live video owner.

Advance requires actual state 4 and at least two ready pictures. Selector 0
bypasses the clock gate; otherwise the second earliest picture is tested through
the same Context admission/hysteresis path. Public acquire permits actual states
3/4 and tests the first picture. Original public get publishes the previous
picture pair before admission, even when output is held. Its ready-count and
selection guard phases remain separate. Only one current public borrow exists.
`skip_if_due` is an explicit bounded caller request: one advance predicate then
one get/release. It does not infer codec-reference retirement or skip B-picture
decode. Full original decode-skip/recovery policy is outside this queue scope.

Frame stepping uses the existing Context audio/counter controls. Presentation
continues to observe the original cached clock. A normal clock tick refreshes
that cache under its existing pause gates; video never substitutes the raw counter
or an independent host timer. Already-due pictures can remain due while paused,
as in the original policy. A frame-step does not silently invalidate the cache.

Decoded surfaces stay reserved until the actual producer fence completes.
Rendering submission is separate from queue acquire and display completion.
Logical release cannot reuse physical storage while a producer/renderer fence
or original reference obligation remains. Polling performs nonblocking fence
checks. Close refuses new work and retains pending surfaces for retry; destructor
cleanup uses the surface's explicit blocking STOP drain. No resource is declared
retired after elapsed time or a poll-count threshold. Callback-time mutation and
cross-context reentry are refused before effects; owners retain themselves and
the timing Context through callbacks.

The GPU adapter retains the actual bridge and exact texture ticket. A slot is
leased exclusively; legacy timestamp/consumer/release paths cannot consume that
lease. Native consumers record all reads in the bridge's Generic command stream;
its last real consumer fence covers earlier reads in that stream. Producer and
consumer fences must both complete before native release. MPEG reference
surfaces remain with the decoder. STOP/error drain retains scoped real fences;
no CPU/original fallback follows native GPU side effects.

Original queue and public-frame comparisons cover semantic pool fields, timing
state and admission. Primitive pool checks omit pure guard observations; joined
public-frame checks include guard/callback snapshots. Legacy public payload and
guest-pointer layout are not a native pixel API. Surface/decoder/reference
ownership is validated separately. Actual image submission and a real monitor
presentation are distinct observations; tests must state which they exercised.
