# Typed Actor ownership snapshots

Status: qualified on both compilers. Uninstalled; Step4 remains incomplete.

`copy_actor_owned` prepares an unregistered native Actor snapshot on the serialized
simulation owner. Ordinary values, optional capabilities, vector state and native
EntityId references copy as values. Immutable assets, clips, bank resources and
programs can remain shared. Model, playback and constraint state receive independent
mutable owners, preserving aliases within the copied Actor. The helper refuses
an inconsistent canonical Actor.model/Playback.model pair and reports allocation
failure without changing the source.

Constraints can intentionally retain an older model while the canonical model is
detached or awaits phase-dependent reconstruction. The snapshot preserves that
relationship with a separately copied older model; it does not silently retarget
those contexts to a new skeleton. Constraints bound to the primary or secondary
playback model instead bind to that corresponding copied model.

`Constraints::clone_for_model` preserves every context, callback binding, floor
height and solved state for the exact same authored skeleton. Fresh reconstruction
continues to use the existing, more restricted `replacement` route; it does not
gain permission to recreate unknown extra contexts on another topology.

Both `constraints-ownership-copy-{llvm,gcc}-v2` receipts pass720,664 checks,
512 copied solver continuations against complete original bodies,512 isolation
cases and four absent/foreign-topology refusals. Actual owned skeletons and all
seven context slots participate, including additional active contexts2..6.
Both `primary-model-actor-copy-{llvm,gcc}-v1` receipts pass108,885 focused checks:
515 Actor copies and256 inconsistent-model refusals, alongside existing complete
cache/scene-entry/retirement comparisons. Real owned model assets supply normal,
detached, secondary-alias and model-without-playback cases. V1 constraints receipts
retain the unchanged-behavior baseline; V2 contains the new copy assertions.

This helper does not register a World identity, apply5F1400's scene-specific stores,
retire a main model, publish scene bindings or transfer physical model-cache rows.
The existing primary model adapter still refuses temporary actor identities.
Actual construction/handoff remains the next scene-owner work. No game was run,
installed or claimed faster.
