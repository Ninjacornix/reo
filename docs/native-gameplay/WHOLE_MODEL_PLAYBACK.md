# Whole-model scripted motion playback

`animation::Playback::configure_whole` and `advance_whole` implement the
admitted58C970/58CC80 paths through immutable native motion banks and actual
mutable model instances. They bind/sample the full model in authored traversal
order, preserve the original game-step clock factors and publish root motion
without guest memory, original execution or host elapsed-time catch-up.

This path has important differences from per-track playback. Configuration
clears mask0x8 while preserving0x10, zeroes the output/saved root deltas, and
initializes transition fields without capturing a secondary pose or advancing
the per-track transition blender. Its frame end and loop metadata remain the
literal clip values, with negative restart clamped to zero. It does not apply
the per-track odd-end/loop adjustments. The separate unblended delta at4F0
remains untouched. Previous whole-model root position belongs to the existing
Instance root-reference owner, corresponding to508.

Ordinary advancement samples the whole model and publishes its root difference.
A wrap to nonzero frame combines the tail and head differences in source order.
A wrap to zero resets the prior root reference. All other channel records and
the independent secondary model stay intact. Missing tokens preserve the old
state. Negative source rows and incompatible bank layouts refuse explicitly.
The current admission requires a single-track strided bank beginning at track0.

Both LLVM and GCC pass2,873,829 checks, executing13,037,813 complete original
calls. New coverage includes768 full-model configurations,9,216 advances,768
missing-token cases and768 explicit negative-row refusals. It uses two actual
owned whole-model banks with matching owned skeletons and two independent raw
looping clips with odd frame end5 and positive/negative restart. Comparisons
include all channel records, both model banks, sampled parameters/caches,
matrices, root outputs and independent root-history buffers. Existing per-track,
plain binding, frame events, blend and software-double complement checks remain
in the same cohort. Five parent gameplay tests also run on each compiler.

The verifier now uses the current checked SDK conversion header rather than a
historical private build directory. Reproduce with
`python tools/native_reconstruction/animation/verify_playback.py --compiler <compiler> --corpus build-native-sjuni/animation-owned-corpus-v2 --output build-native-sjuni/<fresh-directory>`.
Evidence identities are recorded in
`tools/native_reconstruction/native_whole_model_playback_qualification_v1.json`.

Tracing the caller also corrected the previous B44 initial-frame label.
Scripted67BFF0 supplies a scaled blend duration to5D1F20. That wrapper moves
incoming f12 to f20, starts the selected animation at frame zero, and passes the
duration through f13. Its BA4 mask2 branch forces zero duration. The original
scripted-motion notebook now records this correction. Actual scripted callback
consumption, scene motion-bank loading and native game installation remain open.
This is a component checkpoint and Step4 remains incomplete.
