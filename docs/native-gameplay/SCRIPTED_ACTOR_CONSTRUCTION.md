# Native scripted actor construction

`ScriptedActorConstruction` supplies the admitted6BA5C0 construction policy
through the actual World-owned50-node linked actor pool, immutable ActorAssets
and Update material scheduler. It prepares asset reads separately, constructs
independent mutable model/playback instances, publishes native actor state and
requests5D0C90 only for class27. There are no original callback addresses,
guest model pointers or extra actor/task pools in production.

Request arguments retain the source's low-byte interpretation. The scale comes
from the ordinary class row selected by definition_index54D. The model comes
from variantBBA in the alternate bank only when54D==1. The shadow selector
always comes from the ordinary variant row, including when the model uses the
alternate bank. These selectors must remain distinct. Native actor model groups
are logical identities; every actor owns its mutable model independently.

The actor starts inactive/invisible, category2, with motion multiplierF0=1.
`ScriptedActorState` owns its model group, four color channelsCCC..CCF,
alpha modeCA0=-1, alphaCA1=255 and admitted per-part visibility. This family
does not reuse primary actor fade/control components with different meanings.
The typed rendering request retains model, texture, construction mode and
signed shadow metadata. Step5 owns actual texture/mesh/shadow conversion and
submission. The return-only1D1F40/3777B0 bodies need no native replacement.

All mutable allocations finish before publishing an actor. Missing or malformed
assets and unadmitted metadata fail preparation without changing the World.
This deliberately replaces the original loader's partial failure behavior.
Pool exhaustion returns full without scheduling work. A full material scheduler
still returns the constructed actor and separately reports its dropped task,
matching the original ignored573890 result. Retiring/replacing actors cannot
retarget old tasks, model snapshots or retained assets.

The complete6BA5C0 body executes in the original comparison fixture. The child
asset and shadow calls are declared observation ports, checking full arguments
and order. Actual1D1F40 and573890 execute; the task allocator is the existing
declared32-entry port. Construction tests compare admitted low-byte selectors,
scale, opacity, colors, per-part visibility, model/render metadata and material
task requests. Actor and task exhaustion are tested independently. These checks
qualify the reviewed constructor policy, not its original resource loader or
rendering internals.

Both compiler owned-asset cohorts pass5,678 checks, including52 synthetic
constructions and330 constructions from actual owned bundles. All406 loaded
models still import and rebuild their real native skeletons. Another76 asset
combinations lack an admitted ordinary scale row for alternate constructor
mode1. They remain explicit constructor-profile refusals. Three FF model
definitions retain known absence. E03_01.NBD remains absent from owned content.
Per-part visibility currently admits at most32 parts; owned admitted bundles
have1..31. No content is silently substituted.

The full scenario comparisons and five parent integration tests pass on LLVM
and GCC. Source/build/evidence identities are recorded in
`tools/native_reconstruction/native_scripted_actor_construction_qualification_v1.json`.
Reproduce using the full scenario verifier, `verify_actor_assets.py`, and the
native actor asset, target metrics, collision worker, cooperative Update and AI
owner CTest entries. Scripted motion callbacks, room/cutscene construction
orchestration and game installation remain open. Step4 remains incomplete.
