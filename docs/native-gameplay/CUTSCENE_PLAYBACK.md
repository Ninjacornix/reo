# Cinematic playback controller

CutscenePlayback reconstructs complete5EE680 and5EE260 over the canonical native
World/session, request queue, flag owner and three StreamChannels. A World admits
one controller; construction refuses a second live binding, and destruction
releases only its own binding. World.close refuses during controller callbacks
without setting the broader World.busy gate needed by scene construction. The controller owns the original38ECA0 state once.

At every5EE680 visit, the original writes7434C8=38ECA0. Consequently pointer+8
and global38ECA8 name the same frame; event tracks and pose evaluation in this
calling path share one simulation counter. The frame advances modulo32 by1 in
clock mode0 or2 in any nonzero mode, after all admitted frame consumers. The end
comparison uses the signed32 interpretation. Media timestamps, display pacing
and elapsed time do not advance this counter. Request.mode is the same byte as
controller+2F and38ECCF; it is not a second independent skip flag.

The outer owner retains source phase order: initial admission, playback substate,
queued-request completion/fade, then actual queue collection and scene teardown,
reset and load. The inner owner retains voice readiness/start release, movie
state2 admission, per-frame consumers, peer acknowledgement and completion cleanup
order. Offline acknowledgement accepts any nonzero mask. Online acknowledgement
counts the original participant loop with modulo32 shifts; zero participants
therefore completes immediately. Signed phase/subphase bytes preserve wrapping.

Actor and object callback slots call the already registered native
CutsceneActorTracks and CutsceneObjectTracks owners directly. Missing owners
refuse; a generic callback cannot manufacture their success. Other frame slots,
prepared scene audio, movie controls, display controls and scene construction
remain explicit required services with no successful default. In particular,
cue collection alone does not implement5F0380's renderer/room route; select_scene
must perform the actual371AD0/371B70 and6DE590/6DE480 effects. This component does
not establish complete scene entry5ECCA0, cleanup5ED340, movie engine admission,
all remaining track consumers, game installation or Stage4 completion.

The comparison executes complete original5EE680/5EE260, real queue collection,
variant selection, acknowledgement, channel stop/resume and the literal callback
table. The test-only bounded reference exposes merged entry1B0310 with an entry
label while preserving its audited instruction body. Every source body is word
audited against pinned SLUS20765/o2 inputs; production contains no register
context, original addresses, addressed RAM or recompiled function execution.
Independent component qualifications remain valid for separately supplied frame
arguments; those tests do not establish two original controller clocks.

Fresh independent LLVM and GCC v11 cohorts pass identically:2,457,907 checks,
56,173 complete outer visits,9,363 inner visits,9,984 acknowledgement patterns,
256 populated actor/object controller ticks and372,259 original calls. Native
contracts additionally cover duplicate-owner refusal, destructor rebind, closed
World, missing required track owner and all13 primitive failure prefixes. Both
receipts attest unchanged source, including141,152 real World.close callback
refusals per compiler. Earlier v1..v10 development runs remain on disk;
reference entry/tail-wrapper/constant fixture errors were corrected before the
final pair. The reproducible summary is
[the qualification seal](../../tools/native_reconstruction/native_cutscene_playback_qualification_v1.json).
