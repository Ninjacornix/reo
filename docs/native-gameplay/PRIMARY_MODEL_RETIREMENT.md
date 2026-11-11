# Native primary CPU model retirement and reconstruction

`PrimaryActorModels::capture_release` prepares the admitted5EC270 operation for
a canonical primary EntityId. A valid cache row releases its old character bank,
detaches both mutable CPU model banks, clears visibility and invalidates both
cache bytes. CharacterFF or classFF is the source's no-op gate, including a
previously loaded EP model with class255. Release does not require the asset-
loading mode:5EC270 has no such branch and performs no asset read.

Playback remains the actor-owned component after detachment. It retains channel
records, transition deltas, resource bindings, progress, the secondary-bank policy
and previous root history. The history has one active owner: the attached model,
or detached storage while no model exists. Reconstructed models receive that
history and fresh node/clip bindings. Operations requiring a model refuse before
advancing timing while detached. The loading/scene phase must finish reconstruction
before resuming model-dependent gameplay; active actor state is not silently
changed to hide a missing model.

Canonical actor model/asset/pose access is revoked under the existing World guard.
Already-retained model and constraint leases remain valid independently, so host
heap reclamation can outlive original resource retirement. Existing constraint
state is available for the actual initializer to retarget later. No stale model
is submitted through the canonical actor. Rendering-resource retirement and HP
auxiliary render work remain explicit Stage5 boundaries.

An explicit release before entity retirement permits the same slot to receive a
new EntityId generation and fresh model. Skipping that release still refuses
implicit cache transfer. Old entity/model leases cannot become the new actor.
Requests retain the domain, generation, bank revision and expected selection checks.

Both compilers pass92,609 focused checks:256 retirements/reconstructions,257
no-op releases,256 attempts to advance detached playback,513 complete original
release comparisons and a positive generation handoff. Existing cache and scene
comparisons remain:1,280 cache cases and1,196 primary-scene cases. Source-word-
audited5EC270/5EC010 execute; shared-bank release, registry/HP-resource retirement
and archive acquisition remain the declared ports already documented for the
focused cache fixture. Actual native CPU/model/bank consumers run separately.

Both current full initializer cohorts pass39,664,817 checks and all fifteen
parents. Playback passes2,949,346 checks including72 live replacements and264
continuations. Current World comparisons pass2,799,371 checks and8,216,138 original
calls on each compiler. Evidence is `primary-model-retirement-{llvm,gcc}-v1` and
`primary-retirement-{initialization,playback,world}-{llvm,gcc}-v1`, sealed in
`native_primary_model_retirement_qualification_v1.json`.

The complete5F0C00 scene-entry caller and its shared family release, earlier actor
assignment/cloning, primary cinematic playback and game acceptance remain open.
The next audit must replace the old1B1DF0 work-buffer port with its real partial
bank release. The installed game remains V39; no game was launched and Step4
remains incomplete.
