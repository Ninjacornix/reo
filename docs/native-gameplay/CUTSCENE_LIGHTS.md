# Cinematic light tracks

CutsceneLights borrows the canonical World/controller frame, Lighting, Fog and
RoomResources. It owns the original32 physical light bindings and auxiliary mirror
binding over Lighting's existing primary/auxiliary pools. A private registration in
the existing opaque LightDomain rejects a second owner without changing Lighting's
public size or NativeSession's layout. Destruction unregisters only its own binding;
pool lifetime remains with Lighting.

Complete6B3830 selects bank0, creates its32 room entries through existing6B2020,
selects Fog0, allocates32 additional primary mode3 records and one auxiliary mirror.
Every allocation is independent, including missing handles; there is no invented
rollback or all-or-nothing admission. Source6B38D0 clears only32 authored start/end
pairs and does not release physical light records. Lighting reset invalidates the
physical binding epoch, matching its actual global pointer-bank clear.

PreparedLightTracks imports the real48-byte extension streams from0950 descriptors.
Complete5EF640 advances at most one record per stream for the current frame bucket.
Half6 selects start versus end binding. Complete6B3900 normalizes the two RGB triples,
initializes point/radius/extra and obtains the material through the real retained
room floor. Missing or retired room/light identities refuse at the reached boundary.

Complete6B3BB0 samples position from the authored quadratic. Colors, radius and extra
accumulate once per visit using duration, halved when the canonical clock mode is
nonzero. They are not recomputed as linear samples from the current frame. Existing
W lanes survive evaluation. Mode2 mirrors material and52 descriptor bytes to the
canonical auxiliary record before an end marker may clear local extra. Generation
checks prevent a callback from retargeting a newly reused light slot.

The sole CutscenePlayback owns an accepted light worker and executes5EF640/6B3BB0 at
the actual two callback positions. Foreign state/World, duplicate and active binds
refuse without moving caller ownership. Its inline busy guard aliases the worker's
actual running flag. World closing and controller mutation therefore also refuse
when callers visit the borrowed worker directly between controller ticks. There is
no second activity record, frame counter, light pool or successful renderer default.

Both compilers pass7,863,780 isolated policy checks over131,072 cases,524,288 updates,
261,604 mirrors and4,718,052 original calls. Complete6B38D0/6B3900/6B3BB0 and the
616F60/371600/370420 wrappers execute.617000 is an explicit numeric material seam
in that isolated policy cohort; it does not claim original grid execution.

The real-owner v7 pair passes62,179,928 checks per compiler using actual NativeSession
r0417300, SessionRooms and its retained floor graph. All548 admitted descriptors run
over496,687 frames with3,429 bindings,820,556 samples and76,425 triangle hits in
822,497 original wrapper queries.822,498 native provider guards include light
retirement/reuse refusal and destructor rebinding. It executes29 complete original
bodies with2,003 matched instruction words and3,668,763 calls. The native Grid is
independently qualified and is the declared617000 seam here.

That owner cohort copies and verifies59 exact SessionRooms v6 native archives and
their matching headers, then compiles complete current Lighting.cpp and the new
units. Current whole-controller v23 separately compiles current source after the
coherent Update ABI change:2,874,128 checks,512 bound light ticks,608 floor guards,
32,201 callback guards and529,908 original calls on each compiler. Its retained
owned-grid fixture is a controller component check, not a claim of full room entry.

Development snapshots are retained. Owner v1 exposed an incorrect assumption about
the parent's archive-copy directory; v2/v3 exposed missing oracle macros/HI-LO fields
and strict indentation warnings. V4 correctly rejected a changed cached archive.
Later runs use the earlier private archive copy whose digests match the successful
parent receipt. No production fallback was substituted for these failures.

The current CMake light-assets v3 pair passes3,544,261 checks per compiler over all
548 descriptors,493,298 frames,3,426 bindings,809,810 samples and811,748 callback
guards. It constructs the actual NativeSession/SessionRooms with the current Update
ABI and final ScenarioArchive correction. Current parent28 v1 passes on both
compilers with no source drift. Light-assets v1 retained successful runtime output
but rejected source drift; v2 exposed the newly registered trail's missing canonical
link dependency. V3 includes the completed current link closure.

Reached archive tracing also corrected the earlier ordinary descriptor loader:
mode0 genuinely misses the separate1,342-key default catalogue, while nonzero modes
read actual AFS sector storage. Both compilers pass14,591,013 corrective loader
checks and714,870 actual-sector fullscreen-workspace checks. The earlier logical
prefix/mode0 fixture claims are explicitly superseded in
[scene visibility and fullscreen color](CUTSCENE_VIEW_CONTROLS.md).
The [scoped seal](../../tools/native_reconstruction/native_cutscene_lights_qualification_v1.json)
records the exact fourteen comparison/current-integration receipts and superseded
loader claims, including the explicit primitive boundaries.

Full room transitions, remaining cinematic frame workers, movie merge/lifecycle,
projection renderer installation and complete session/game acceptance remain open.
No game, desktop window, audio device or power action is performed by these tests.
