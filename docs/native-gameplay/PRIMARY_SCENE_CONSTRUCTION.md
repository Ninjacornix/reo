# Native cinematic player construction

Status: admitted CPU construction and main-model retirement qualified on both
compilers; uninstalled. Step4 remains incomplete.

`PrimaryActorModels::construct_scene_primary` now applies one prepared choice to
the separate temporary player pool. It checks the current first-inactive slot and
all eight roster entries before copying. A matched canonical actor supplies the
typed state; an unmatched request preserves the old inactive record's state.
Both routes use independent mutable model/playback/constraint ownership.

Construction preserves the physical temporary index, activates the actor, hides
it, selects primary action6, clears the other three action bytes, clears the
authored control region, resets BB4 and assigns character/class/current room.
Fields outside that prefix remain copied, including command-angle history and
primary state. Matched class1 executes actual main-model retirement and shared
bank publication before changing that scene-roster entry toFF.

A new generation replaces the inactive record. Old identities stop resolving;
retained old Actor leases keep their previous values. Allocation/capacity refusal
before publication preserves the inactive slot and roster. One guard covers
temporary publication, bank/model retirement and final roster stores. Retained
destination/resource leases drop only after complete publication while reentrant
public calls still see busy. No public nested-call bypass was introduced.

A resource failure after publication returns failure together with the created
ID and incomplete retirement flags. The scene owner must latch that prefix; it
must not report a ready actor. The exit-release flag describes cache/resource
policy, not ownership of native allocations, which always retain normal lifetime.

Both `primary-scene-construction-{llvm,gcc}-v3` receipts pass117,002 focused checks,
258 original construction comparisons,258 construction refusals and three
cleanup-callback guards. Coverage spans all temporary and main slots, both class
branches, pause states and unknown/resident/archive loading modes. Cases also
cover unmatched requests, preserved inactive state, stale choices, entity capacity
and failed publication caused by an unrelated incomplete actor. Existing515 Actor
copies,385 scene entries and1,196 assigned-header cases still pass.

Complete5F1400/5EC270/5EC010 bodies match owned words and execute. Constructor
comparisons use an explicit selected-field/control schema and separate output
metadata; this is not a claim that every native Actor field has an original raw
layout. Bounded fill/copy and graphics/resource-helper observations remain ports;
actual native bank retirement and independent pose ownership run separately.
V2's GCC receipt preserves a fixture indentation warning; V3 fixes braces and
passes both compilers.

Temporary model-cache admission remains closed. Physical model-slot handoff,
fresh/reuse initialization of temporary identities, primary cinematic playback,
sixteen category10 objects, traversal and complete entry/exit still need adoption.
No game was launched, installed or claimed faster.
