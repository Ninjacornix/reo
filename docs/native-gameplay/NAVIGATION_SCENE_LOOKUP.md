# Native condition-based scene lookup

2026-11-10. Complete819FF0 and81A080 are qualified native components. Stage4
remains incomplete and the installed game remains V39.

Both helpers first resolve the requested condition through complete81A0E0.
They compare the scene record's **signed** ordinal byte to resolved index+1.
A rejected condition resolves-1 and therefore searches for ordinal zero; it
does not automatically return no match. Byte128 is negative and cannot match
positive128. The candidate-list helper preserves supplied order; the global
helper walks the shared pool newest to oldest. Neither adds geometry, activation
or busy checks. Native candidate IDs reject stale/foreign records explicitly.

The canonical scene record now owns `condition_ordinal`, original3F. The full
allocator zeroes this byte, and the full room initializer sets base records to
their authored ordinal+1. The parser supplies that initial value; generated
helper records retain zero. Existing owner snapshot44 and extra45 remain
separate. Script/control and collision-projection edits preserve the ordinal.

Both compilers pass67935384 identical navigation checks, including13825
candidate-list and4608 global original comparisons. These cover all256 ordinal
bytes, condition0/1/127, applicability/actor changes, reordered and empty lists.
Five tracked refusal profiles and a separate negative-condition refusal cover
missing admission and stale/foreign input. Actual Owner tests use the existing
actor room, AI-control and Bank and the same script-owned scene records.

The refreshed complete room initializer comparison passes259706 checks and58566
original calls per compiler over64 controlled and166 owned rooms/2144 authored
records. It checks canonical ordinal values on both base and generated helpers.
The strict profile admits163 rooms and retains the same three authored-model
refusal rooms; the separately qualified authored-absence correction is not
silently selected. Both parent builds and ten integration tests also pass.

The first room build caught accidental removal of unrelated extra45 metadata.
That field was restored beside the distinct ordinal3F, and both complete source
closures were rerun. Failed/superseded v1 evidence remains retained. Production
has no guest-addressed state or generated-function dispatch.

Evidence: `build-native-sjuni/navigation-lookup-{llvm,gcc}-v2/receipt.json`,
`navigation-lookup-room-{llvm,gcc}-v2/receipt.json`, both parent/test v1 logs,
and `native_navigation_scene_lookup_qualification_v1.json` (SHA256
`3c9fbc2981f507b006ed5e1901be4a36ae129a3754e80217229a3851375ffc11`).

Full812540 observations, AI goals/actions, remaining stock VM/input/network/save
owners, real loading/provider binding and coherent native gameplay acceptance
remain open. No game was launched or performance change measured for this work.
