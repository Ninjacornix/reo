# Eligible cinematic roster preparation

Status: qualified native roster/visibility projection and World publication on
both compilers. Uninstalled; Step4 remains incomplete.

`prepare_cutscene_roster` projects5ED340's eligible character, original-slot and
status arrays from a captured eight-actor frame. It preserves tail entries, hides
every visited actor before status filtering, applies mode4/5 and mode6 room rules,
and remaps the original one-based preference into the compact list. It treats the
authored primary population, eligible count, physical character entries and source
slot metadata as distinct state. Scene mode is independent of online/offline mode.

The scenario23hex/mode6/one-eligible branch finds the first authored actor in
room13hex and appends its character, original slot and status. It can append an
actor excluded by the ordinary mask or duplicate the already eligible actor.
Those literal source rules are preserved; the module does not rename them into
an inferred story or change their selection policy.

`CutsceneRosterPreparation::apply` captures canonical World actors, the session's
authored population/scenario and actual ActorPlacements request rooms. It publishes
the visibility/roster result under the World guard. Missing inputs, invalid counts
and unowned placement-room reads refuse before any live stores. Busy/closed owners
refuse explicitly. It does not substitute zeros for missing actor state.

Both `cutscene-roster-preparation-{llvm,gcc}-v2` receipts pass7,954,785 checks across
414,728 cases:396,845 full-body comparisons,17,883 explicit unavailable/invalid
cases and the two targeted special branches. Coverage varies every population0..8,
preference0..8, all256 status masks, ten modes, room/slot permutations, signed status
words and preserved tails. The whole5ED340 body matches the pinned owned words and
executes with its resource/graphics/pool cleanup calls declared as observation ports.
Only roster/visibility projection is admitted by this comparison.

Both `primary-roster-world-{llvm,gcc}-v1` cohorts pass124,408 focused checks,
including365 World-backed original roster comparisons and43 missing/unsupported/
closed cases. Existing construction cleanup callbacks also verify the publisher
refuses busy and preserves its input. The actual placement-request owner supplies
mode6 data; reads beyond its four records remain unavailable when required. The
source's selected actor bypass can legitimately avoid that room-table read.

No pool reset, model/resource release, bank header reset or complete5ED340 lifecycle
is performed by the roster publisher. Those remain separate scene-phase work.
Temporary model-cache admission is closed. No game was run, installed or claimed
faster, and no slowdown cause is inferred from these development tests.
