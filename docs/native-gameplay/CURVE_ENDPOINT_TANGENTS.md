# Unused curve endpoint tangents

Status: qualified on both compilers; uninstalled. Step4 remains incomplete.

Native curve import previously required finite incoming and outgoing tangents
on every multi-key cubic/mixed key. A segment uses its first key's outgoing and
second key's incoming tangent. The first incoming and final outgoing tangent
are never operands, including when playback loops or samples outside the range.
The owned R041 B31 clip has NaNs in these unused fields. Import now skips those
operands, while preserving finite checks on tangents that can actually be used.
Original bytes remain unchanged in the retained motion block.

The earlier used-tangent refusal fixture injected a first incoming tangent,
which was not actually used. It now tests the outgoing/incoming operands of an
actual interior cubic segment. This corrects a test admission assumption.

Both curve-endpoint-tangents-{llvm,gcc}-v2 comparisons pass275,815 checks:
78 clips,1,486 curves,68,196 original sample comparisons and34,051 complete
channel/quantization/cache comparisons. They include the actual affected owned
clip, twelve ignored-tangent cases and twelve used-tangent refusals. Complete
original packing and sampling execute. V1's stream-iterator EOF fixture mistake
is corrected; its failed evidence remains retained.

Both broad playback regressions pass7,762,899 checks, and all five CMake parents
pass. The actual object/model/motion audit now completes1,238 of1,356 controlled
pairs, with zero clip-import refusals and21,046 completed individual updates.
118 track-cardinality pairs and12 missing-model descriptor requests remain open.
This audit still does not project full scene cadence or actor parents.

Evidence: `tools/native_reconstruction/native_curve_endpoint_tangents_qualification_v1.json`.
No game, renderer, audio, input, device or power action was used. This fixes a
native admission restriction, not a newly measured in-game slowdown cause.
Full Step4 gameplay and installation acceptance remain open.
