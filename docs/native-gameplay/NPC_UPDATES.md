# Native NPC callback and Update worker

`CommonActorFrame` implements the complete shared 66A2E0 callback used by NPC
construction. It clears the actual per-frame response/notice fields, resets the
shared counter, conditionally enables movement, filters only nonselected primary
input when authority filtering applies, and clears the contact cooldown. It then
calls the required native behavior stage and performs concrete root integration
and pose rebuilding. Generational identity checks stop a retired actor from being
used after a synchronous provider. Failure retains preceding mutations; guards
are released on both normal and exceptional returns.

The fields below have distinct consumers and must stay independent:

| Source field | Canonical native field |
| --- | --- |
| Actor + 32 | `normalized_marker`, the contact cooldown byte |
| Actor + C53 | `room_marker`, preserved by this callback |
| Actor + 198 | `collision.pose_ready` |
| Actor + 553 | `movement_enabled` |

`NpcActorUpdates` implements the full 6833C0 head-to-next auxiliary pass through
the actual ten-slot owner. Inactive, invisible, camera-suppressed or inhibited
actors explicitly lose pose validity. Admitted actors run the real callback,
then publish pose validity and request active attachment work. Camera suppression
uses complete 5C0870 selector 1 and its 191D10 distance: raise the actor probe by
100, then compare ordered FP32 Euclidean distance strictly below the owned
threshold 80. Nonzero cinematic pause bypasses that distance gate. There is no
host delta-time scaling or presentation-count clock.

Camera position and the independent inhibition byte must be borrowed from real
native scene owners; the API supplies no guessed defaults. They are read at the
actual actor position in traversal, so changes from earlier callbacks affect
later NPCs. The precise external producer of the inhibition byte remains part
of scene migration; its numeric role has not been given a speculative meaning.

Allocation claims at 3B59D8 and renderer attachment activity at 3E82F0 are distinct
owners. The pass does not infer an active renderer attachment from a claimed
slot. A present attachment requires its renderer owner even to determine whether
it is active. Completed update work, absent attachments and missing/failing
owners are represented separately. Rendering implementation remains Step 5.

The pool now distinguishes traversal from list mutation. Whole-pool reset/close
is blocked during a pass; bounded allocation/release retains the existing list
semantics, with generation checks on callback continuation. A World has one NPC
update owner. The pass and common callback protect World closure and reject
recursive execution. Source callback families outside the admitted constructor
remain unavailable rather than becoming successful empty callbacks.

`NpcActorWorkers` consumes the actual `auxiliary_actors` position in the existing
native Update owner. Other workers and phase effects keep their required owners.
The adapter exposes only completed or explicit failed pass evidence; exceptions
leave no stale successful report. It verifies World ownership and supports joined
closure. A paused outer Update does not call this ordinary worker, while direct
cinematic invocation retains the source callback's own pause semantics.

Current paired World comparisons pass 2,799,371 checks and 8,216,138 original
calls per compiler. New coverage includes 4,096 full shared callbacks, 8,192 camera
gate cases, 256 complete ten-slot traversals, 1,404 actual callback invocations
and 560 attachment requests. Six refusal cases cover missing/retired identities,
throwing behavior, closed worlds and absent/failed attachment completion. Pool
comparisons include inhibition changes during callbacks and independent active
attachment masks. Complete root and pose bodies execute in the original fixture;
behavior dispatch and renderer attachment calls are declared observation ports.
The existing 233 skeleton / 12,475-node, scene descriptor, parameter, animation,
movement, command and track comparisons remain in the same current-source run.

Both owned constructor/scene cohorts and all eleven parent tests pass with the
current production sources. The native Update integration exercises worker order,
visibility, inhibition, pause, failed behavior, recovery under explicit caller
control, reentrant closure/reset and foreign-World refusal. Its first fixture
omitted required script programs and initialized motion scale; those fixture
inputs were corrected. GCC also caught misleading indentation in a reference
test. Failed receipts are retained.

Both current native behavior cohorts additionally pass all32,768 original
behavior comparisons /2,572,551 trace words and the actual NPC pool -> common
callback -> BehaviorFrameServices -> update_behavior -> root/pose composition.
Action/effect providers remain declared in that separate composition. Its first
link attempt exposed missing current SceneResources dependencies in the old
verification helper; adding the actual native scene-resource/template units
fixed the comparison build. No production behavior workaround was introduced.

Actual motion bank/content producers, all action/scene/rendering providers, the
11-NPC capacity conflict, full scene lifecycle, coherent game installation and
full Step 4 acceptance remain open. The installed game is still V39. No game,
audio device or visible test window was opened for this work.

Reproduce the paired World cohorts with animation/verify_world_playback.py,
the current owned scene/constructor/parent cohorts with
verify_cutscene_npc_construction.py, and the current native behavior composition
with verify_gameplay_behavior.py. Use explicit compiler/build/data paths and
fresh output folders. The combined source/evidence seal is
native_npc_updates_qualification_v1.json. No historical source pins are used.
