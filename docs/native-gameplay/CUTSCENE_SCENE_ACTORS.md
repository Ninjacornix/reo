# Cinematic scene actor composition

CutsceneSceneActors composes the existing canonical World, Update, model cache,
motion owner and primary, NPC, scripted and cinematic object constructors. It owns
the actual registered actor and object tracks. It borrows the controller preference
and frame state, and rejects model or motion owners from another World.

Construction preserves the source order: selected ordinary models are cloned before
5F0C00 retirement, then scene actors initialize against the published motion banks.
Cinematic objects reserve physical records at5F0610; their later model acquisition
is a separate operation. Scripted actors retain their source-prescribed inactive
state and cold room field. Missing skeletons remain valid absent instances.

Reset clears the real track bindings and temporary records. Intermediate queued
continuation preserves the physical model cache for the next scene. Final exit
releases only the selected first16 descriptor models before strict model return.
A partially mutated construction latches its prefix and refuses a blind retry.
Preparation failures before mutation preserve canonical bindings.

LLVM and GCC private v10 cohorts each pass3,415 checks:30 owned0950 descriptors,
two construction epochs each,52 primary,52 NPC,148 scripted and74 object creations,
30 queued transitions,152 refusal checks and326 retained model leases. All16 actor/
object presence combinations are represented. Two additional selected descriptors
refuse their missing obj07_01_a_00.nbd and obj99_99_a_00.nbd models explicitly.
This samples the wider536 model-complete0950 descriptor profile; it does not claim
all536 were constructed by this owner. Existing complete original model/cache/
initializer comparisons remain separate inherited component evidence.

Fresh current CMake cohorts also pass the same3,415 checks on both compilers with
no source drift. These compile the current shared schema and canonical transitive
libraries, rather than relying on the older immutable private snapshot schema.
Development v1-v4 exposed incomplete private archive closure; v5-v8 corrected
fixture assumptions about bank publication, room fields and activation; v9 retained
the actual missing-model preparation refusal. All failed cohorts remain available.

This is a concrete actor/model lifecycle component. Complete5ECF90/5ED340/5ED770
resource, room, renderer and media orchestration still requires its real owners.
The qualification does not claim a game run, installation or full Step4 completion.
[The seal](../../tools/native_reconstruction/native_cutscene_scene_actors_qualification_v1.json)
records the scoped source identities and four exact receipts.
