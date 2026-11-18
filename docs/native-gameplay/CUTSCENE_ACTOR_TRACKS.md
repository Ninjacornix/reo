# Native cutscene actor stream dispatch

The Update Owner now binds and runs CutsceneActorTracks, the admitted5EEB00
seven-stream dispatcher, through actual native actor commands. Programs own
immutable copied records and checked native actor bindings. No relocated asset
pointers, register context or guest RAM exists in production.

Each call visits groups and their seven streams in order. It rereads the low
frame halfword and canonical clock mode for each stream. Nonzero mode compares
the halved unsigned frame values. A match consumes at most one record, including
when the next event has the same timestamp. It does not catch up skipped events
or advance the simulation clock. The complete5EE680 controller aliases7434C8
to38ECA0; its+8 is global38ECA8, so event dispatch and pose evaluation borrow
the same simulation counter in that real calling path. Component tests with
independent inputs qualify the consumer rather than imply two original clocks.
Kinds0/1/2 dispatch actor commands, including a
known null actor; other signed kinds skip the command and still advance. The
followingFFFF timestamp ends that stream. The eighth section is a separate
header, not an eighth event stream.

The owned [descriptor inventory](CUTSCENE_DESCRIPTOR_INVENTORY.md) exposed
single-terminal streams. Native import now admits those as idle records. If a
caller actually reaches their sentinel timestamp and there is no bounded next
record, the owner reports unavailable before an out-of-asset read. The ordinary
scene-frame behavior is compared with the complete original. A lone nonterminal
record and missing terminal extents still refuse import.

Native group capacity is32, covering the measured0950 file declarations; total
retained records are bounded at65,536. Groups have distinct native storage.
Original model/descriptor pointer aliases are not recreated. Controlled original
dispatcher comparisons use0..16 groups, while a separate32-group native contract
tests the expanded owner. This does not claim original32-group RAM alias
behavior or affected-scene game acceptance has been reproduced.

Only one track owner binds a World. Installation validates all required actor
identities before publication and preserves the previous program on refusal.
An active invocation protects the canonical World and linked pool, so closure,
reset, replacement and reentrant updates report busy. The Update Owner's close
preflight also checks World.busy, covering a separately invoked scene owner.
Frame/mode/scene changes from an earlier command remain visible to subsequent
streams. Program replacement stays serialized at the invocation boundary.

A required provider failure or thrown command latches failure after retaining
the preceding effects. A later tick does not automatically replay that record.
Explicit valid reinstall clears failure. Closing joins the synchronous pass,
releases the registration and retained records, and admits a replacement owner.

Both compiler World cohorts pass2,561,142 checks with7,556,161 original calls.
The new dispatcher coverage includes257 configurations,2,056 timeline calls,
9,067 original command dispatches and1,915 terminal-only streams. It compares
all stream positions, aggregate results, ordered actor effects, ignored kinds,
null actors, repeated/missed frames, low-halfword wrap and mode0..255. Existing
command, animation, movement, expiry and model comparisons remain in that same
current-source cohort.

Both compiler owned-content cohorts pass13,269 checks. Actual prepared actor
and motion assets now receive their three records through the Update-owned
dispatcher, followed by16 cinematic actor/model passes and an ordinary worker
pass. Native parent contracts also test voice callbacks changing frame/mode/scene,
all busy fences, no duplicate queued voice after failure, failed reinstall,
immutable imports, null actors, terminal bounds,32 groups and closure. All six
parent CTest entries pass on both compilers.

Current original ordering regression passes2,048 worker and4,096 phase cases
per compiler. Full scenario regression passes425,306,758 checks per compiler,
with355 ordinary/327 offline bindings. Original child/provider ports remain
declared in their respective ordering/voice fixtures. No game was launched or
new speedup measured.

Reproduce with animation/verify_world_playback.py, verify_scripted_motion_assets.py,
verify_gameplay_update.py, gameplay_scenario/verify.py and the six parent tests,
explicit compilers, owned content and fresh directories. The evidence seal is
native_cutscene_actor_tracks_qualification_v1.json. Descriptor import and actor
assignment, remaining cutscene stream families, actual voice/facial owners,
outer cinematic lifecycle and installed game acceptance remain open.
Step4 remains incomplete and the PC stays awake.
