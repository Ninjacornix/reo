# Native cutscene actor commands

`apply_cutscene_actor_command` now consumes the complete admitted5EEC50
command policy through the canonical World Actor and ScriptedActorState.
The original36-byte authored records remain asset data; production executes
native code and stores no original addresses, register contexts or guest RAM.

All nonnull admitted actors first become active, enter primary state6, set
cue phase2 and OR the command bit with the original low-five-bit shift rule.
Kinds0..6 then apply positions/degree turns, motion controls/scales, related
actor requests, voice/facial requests, movement enable, command angles or
counted displacement. Unknown kinds clear cue phase but retain that prefix.
Known null actors read no record. Stale actors, missing cutscene state and
malformed record extents refuse; no successful callback substitute is used.

Motion mode0 computes the selector from the record group and character, writes
scale_lock/request_phase and converts the signed duration word to float.
Nonzero mode selects mode1, preserves those two controls and optionally adds
100 decimal to the narrowed selector for nonzero motion style. B44 is blend
duration, as established by the earlier caller correction. Scale selector0
uses units; nonzero uses actual player, NPC or linked definition metadata.
Native constraint creation follows the scale publication and then cue phase1.

The NPC scale expression differs from the existing height-correction path:
5EEC50 reads716458+20*BB4, while the earlier profile uses716444+20*BB4.
The separate immutable profile preserves the new caller's actual operands for
126 admitted identities, including0, and the eight complete player triples.
The linked branch reuses the ordinary definition and model_pose_class54D.
Unknown scale metadata refuses rather than supplying a guessed unit value.

Relationship requests retain checked canonical EntityIds, an explicit known
null, separate mode/options/offset/parameter state and no guest pointer. Their
selector is checked against actual scene bindings. Kind6 writes forward step,
two finite truncated angles, yaw increment and remaining count, which the
existing CutsceneActor callback now consumes. The source's unusual X/Y record
ordering and signed/byte narrowing are retained.

Voice/facial work requires an explicit provider and known scenario identity.
The consumer queues voice before facial animation, attempts facial work even
when voice fails, and reports failure. It revalidates the actor and rereads the
scene reference and record voice/facial values after queuing voice. A controlled
mutation case compares that ordering against the complete original body. The
provider in the differential fixture is an observation seam, not real audio
output or facial-resource reconstruction. Those actual providers remain gates.

Both compiler World cohorts pass2,419,981 checks, executing7,545,038 original
calls. New coverage includes71,163 command invocations, all65,536 signed degree
patterns on each angle, independent motion-mode/class/scale combinations,
257 speech argument cases, one explicit voice-to-face mutation and seven
profile/provider refusals. Original helper bodies and owned jump tables,
voice literal and scale operands are sealed in the receipts. Nonfinite and
out-of-range integer conversions remain outside the admitted finite profile.

Both owned asset cohorts pass13,269 checks. Three authored record consumers
replace manual control-field setup in the real constructor/bank/Update/model
chain, followed by16 cinematic updates and one ordinary worker pass. Current
full scenario regression passes425,306,758 checks on each compiler, with355
ordinary/327 offline qualified bindings. All six parent CTest entries pass.
The first GCC cohort rejected misleading fixture indentation; the final cohorts
keep warnings as errors and retain the failed output separately.

Reproduce with animation/verify_world_playback.py, verify_scripted_motion_assets.py,
gameplay_scenario/verify.py and the six native gameplay parent tests, using
explicit compilers, owned content and fresh directories. Regenerate the scale
include with generate_cutscene_command_scales.py; differing existing bytes
refuse overwrite. The aggregate source/build seal is
native_cutscene_actor_commands_qualification_v1.json.

The seven-stream frame dispatcher, descriptor importer, real voice/facial
providers, other actor callbacks and actual game installation remain open.
No game was launched and no speedup measured. Step4 remains incomplete.
