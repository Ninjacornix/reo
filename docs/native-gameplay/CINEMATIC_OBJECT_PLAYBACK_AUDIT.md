# Cinematic object/model/motion composition audit

Status: paired native audit completed; unresolved profiles remain. This is not
an installed-game test or complete-original scene comparison. Step4 is incomplete.

Both cinematic-object-playback-audit-{llvm,gcc}-v2 runs read the548 owned0950
descriptors and use actual native object construction, archive models and object
motion banks. The per-pair TSV evidence matches exactly between compilers.
Each unique authored object motion key is activated separately, with other
objects inactive, for17 controlled model updates under clock modes0 and1.
Scene-pose time stays0; authored scene sequencing/actor parents are not projected.

Of1,356 model/motion/clock pairs,1,162 complete all seventeen updates.20,109
individual updates complete, including prefixes before later refusals. There
are no missing object banks, motion slots or skeletons among these pairs.
Twelve descriptors retain the known missing named-model requests.

The audit exposes194 unresolved pair cases:

- 118 refuse track cardinality:25 model nodes versus4 clip tracks,4 versus25,
  10 versus4, or13 versus14. Both too-short and too-long inputs occur. This
  does not authorize guessing aliases, dropping nodes or weakening cardinality.
  Candidate descriptor reachability and the original matching behavior remain open.
- 74 hit the current native sine/cosine admission bound of one revolution.
  Observed parameter magnitudes range above one revolution to76.600601 radians.
  The complete original reduction routine must be compared before extending it.
- Two clock variants of dm3100A group0/motion0 refuse nonfinite clip data.
  Which data the original actually consumes still needs investigation.

Evidence: `tools/native_reconstruction/native_cinematic_object_playback_audit_v1.json`.
The original components have separate qualified comparisons, but this audit does
not independently prove full-scene behavior, actual clock cadence or player
acceptance. These are reconstruction/integration findings, not newly recorded
slowdown causes. No game, window, audio, device or power action was used.
