# Native actor AI initialization

2026-11-10. Complete8120C0 is qualified for admitted canonical actor components.
Stage4 remains incomplete; installed gameplay remains V39.

Initialization always clears the Bank's mutable first runtime header byte.
The immutable SGL import retains its validated version as provenance. Binding
a different admitted asset initializes runtime byte24; rebinding the same asset
preserves its current value. The byte's broader semantic role remains unnamed.
No immutable shared asset or on-disk file is modified.

Disabled AI then leaves all other state untouched and needs no execution/route
component. Enabled AI registers type0/actor-slot control and publishes zero as
the exact initial four-byte payload. It sets the actual route selection/refresh
fields, clears inhibition/reaction state, sets the periodic counter60, room
memoFFFF and forced priority-1, then uses the real goal/action/profile primitives.
Previous goal/action derive from their old fields. Other route state and combined
weights remain unchanged. Registration/queue capacity outcomes are reported
without skipping the later resets that the original still performs.

An enabled actor needs existing execution and route components. Missing native
capabilities refuse after the known header clear, before further effects; the
function does not fabricate old goals or routes. A closed Bank refuses. These
are explicit native lifetime/admission boundaries, not matching original
invalid-pointer behavior or a completed native actor-construction path.

Both compilers pass80542165 identical checks, including3072 complete initializer
comparisons across all256 actor slots, AI-control0/1/255 and four control-table/
queue profiles.1024 disabled cases change only the header.1024 enabled cases
exercise full registrations or full queues while preserving subsequent resets.
Whole actor projections, canonical controls/pending bytes and header effects
compare. Three missing-state/closed-owner refusals remain explicit.

Both parent builds and twelve integration tests pass. Actual Owner tests cover
disabled clear without components, missing state, canonical previous/current IDs,
unchanged route/weight state, shared Session control publication, repeat init,
full-queue completion and retirement/closure. The initial v1 comparison fixture
incorrectly included a cost member in the cost-free RouteProjection aggregate.
v2 corrects the fixture type without changing production behavior; failed
evidence remains retained.

Evidence: `gameplay-ai-initialize-{llvm,gcc}-v2/receipt.json`, corresponding
parent/test v1 logs and `native_gameplay_ai_initialize_qualification_v1.json`
(SHA256 `356e14ea0a9e291840ed37cf97883e59ae0d954d0382d24ad0e3a0ce4fd5aa86`).

Actual actor/component construction, mode producers, outgoing control service/
frame reset, full observations/goal/action dispatch, remaining stock VM/input/
network/save ownership and coherent native gameplay acceptance remain open.
No game was launched, slowdown reproduced or performance change measured.
