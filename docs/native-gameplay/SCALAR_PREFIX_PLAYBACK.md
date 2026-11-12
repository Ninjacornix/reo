# Scalar playback with trailing clip tracks

Status: qualified on both compilers; uninstalled. Step4 remains incomplete.

The original standalone cinematic binder,58C810 through192BF0/192D10/192C80,
consumes one clip track per matched model node. It never requires exhaustion of
the clip's trailing tracks. The native scalar path now preserves that behavior
through an explicit prefix binding operation. Ordinary actor/channel binding
retains its exact-cardinality contract. Too few clip tracks still refuse before
mutation; this change does not authorize reading beyond a clip.

Both compilers pass7,853,723 playback checks, including64 bindings with one to
eight extra tracks,256 continuation ticks and64 ordinary-bind refusals. Complete
original packing, sampling and local pose publication execute. An unused last
track extends the clip's end time to17 while consumed tracks end at5, verifying
that whole-clip timing metadata is preserved. World comparisons pass13,276,674
checks, and all five CMake parent tests pass on both compilers.

The actual object/model/motion composition audit now completes1,296 of1,356
controlled pairs, with22,032 updates, zero clip-import refusals and60 too-few-track
refusals. This admits58 additional pairs.12 missing-model descriptor requests
remain unresolved. Actual resource-path identity and scene reachability need
confirmation before interpreting those remaining mismatches. No alias or track
padding is inferred from an asset's display name.

Evidence: `tools/native_reconstruction/native_scalar_prefix_playback_qualification_v1.json`.
The composition audit uses controlled activation and clocks; it does not model
complete original scene cadence or actor parents. No game, audio, renderer,
input, device or power action was used. This removes a native admission
restriction; it does not establish an in-game slowdown cause or Step4 acceptance.
