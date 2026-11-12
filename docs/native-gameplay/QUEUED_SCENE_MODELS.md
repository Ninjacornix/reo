# Queued cinematic model continuation

PrimaryActorModels now distinguishes intermediate queued-scene continuation from
final cinematic exit. Source5EE680 calls5ED340, then5EB8B0 and5ECF90 for the next
request. The selected descriptor-model releases belong to the later5ED770 exit.
Requiring those final releases at every intermediate reset prevented the native
model owner from representing consecutive scenes.

continue_scene_models ends the old scene epoch after its temporary actors have
been reset. It preserves the physical cache rows and restores model bindings only
for ordinary actors that already had the required native capability. The next
scene can then clone selected actors before the actual5F0C00 retirement and fresh
initialization. return_scene_models keeps its existing final-release requirement.
Both routes retain domain, epoch, identity, reset, allocation and reentrancy checks.
Read-only bound_to accessors let lifecycle composition reject foreign World owners.

Fresh LLVM and GCC snapshot cohorts each pass153,076 owned-asset checks and7,413
fixture checks. Each exercises56 consecutive scene transitions,56 retained old
model leases and136 continuation refusal cases. Old actor generations and old
scene scopes refuse after reset/continuation; retained old models remain usable.
The next construction and5F0C00 entry execute in their source order. The existing
complete original model/cache/entry comparisons remain included, with441 entry
comparisons and32,878 original calls in the owned run.

The complete5EE680 and5ED770 bodies are word-audited static ordering evidence in
this cohort. Their complete native scene lifecycle is not newly established by
these tests. Existing model/resource/initializer observation boundaries remain
explicit. Each build compiles an immutable source snapshot; unrelated later live
edits are listed in its receipt and cannot change the compiled proof. Development
v1 retained a qualifier metadata-key error; v2 retained an old copied test helper
using the superseded B40 field name. V3 uses the canonical current helper.

[The qualification seal](../../tools/native_reconstruction/native_queued_scene_models_qualification_v1.json)
records exact scoped source hashes, both receipts and observed results. No game,
device, installation or full Stage4 completion is claimed.
