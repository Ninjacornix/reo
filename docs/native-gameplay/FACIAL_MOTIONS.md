# Native cinematic facial motions

`FacialMotions` owns the original eight-instance facial population, eight MAT
keys, 32 LIP metadata entries and bounded asset workspace. The existing sole
`CutscenePlayback` owns it through a guarded `unique_ptr` binding. A refused bind
preserves caller ownership. Direct worker visits participate in the controller's
busy flag, including the real `World::close` refusal during a Source callback.
The owner adds no Actor fields, second actor pool or controller clock.

The implemented chain is `67C250` reset, `67C2E0` preload, `67C590` claim and
`67C2D0 -> 67C6D0` update, using the independently qualified complete `67C990`
matrix chain. Native instance track ID 4 is the source node `+C6` discriminator;
the result replaces node world matrices through `Instance::patch_world_poses`.
Local pose, parameters and prior leased snapshots survive these patches.

## Asset provenance and workspace

`File1FacialAssets` parses the retained File1 default AFS, validates the actual
1342-entry profile and reads the complete matching namespace: 18 HP/HN MAT files
and 33 LIP files. Typed paths absent from that complete subset genuinely miss.
Every read retains its actual sector padding. MAT logical length is 3072 bytes,
while its physical read is 4096 bytes and its destination stride remains 3072.
The backing workspace therefore preserves overlap and survives bookkeeping
resets; it is not a set of fabricated disjoint matrix banks.

The static bootstrap authority `1BAEC0` clears its full `5C0000` allocation, then
suballocates through `1AF910/1AF970`. Face slice `324434` aliases the `18000`
allocation `324424 + 8000`, leaving 64 KiB. LIP storage starts at relative `6000`.
The complete actual `5F0B50` preload inventory over 548 descriptors establishes
at most two requests/keys per scene. Bounding the available character suffixes
for each actual scenario/cue/voice gives maximum scene LIP storage `7800`, hence
maximum relative end `D800`. The largest individual clip occupies 22528 physical
bytes; multiplying that global maximum by an arbitrary request count would not
establish the actual caller bound.

Matrix identity follows the literal actor producer: primary category 0 uses
character B98 and speaker suffix character+1; NPC category 1 uses model variant
BB4 and speaker suffix 0. Both require model class 54D equal to 1. NPC motion
character 3/5 is not its facial model variant. The source MAT reload flag
accumulates **any** actor/key mismatch, including when another earlier key
matches; conventional deduplication would change this behavior. Stored facial
keys truncate to a byte, while matching compares the input low halfword.

## Curves, claims and caller integration

Claims select the first inactive instance. A missing match preserves that
instance's prior matrix/channel references, then still establishes active,
frame 0 and actor reference. Missing reads preserve old workspace bytes while
appending the source metadata/count prefix. Unsupported or unavailable reached
data is reported; no valid clip is invented from absent bytes.

The five channels retain their claim-time origins and read live workspace
values. Their instance cursor is the actual separate source `+1C`, advancing by
2 per visit. Interpolation uses `frame - (first_time - 1)` and the source
multiply/divide/add order. Residual is sequential `100 - w0 - ... - w4`, clamped
below zero, then all six weights divide by 100. No normalization is added.
On reaching the first negative terminal key, the instance retires, its actor
reference clears, and the **whole eight-instance pass returns** before matrix
application or later instances. This is not an ordinary per-instance continue.

The actual outer caller is `5FF1B0 @ 5FF390`, after `6BBBA0`. This facial tick
belongs there, not in the controller's 16-callback table. Full outer phase
orchestration remains a separate integration task.

Speech opcode 3 in `5EEC50` reads `38ECD0`, which is canonical
`request.current.area` (controller offset `30`), for its voice/face cue. The
prior controller bridge passed `current.scene`; the facial caller regression
corrects that bridge. Actor tracks mark World busy during commands, so the
claim leaf admits that traversal while keeping its own running, closed and sole
binding checks. Reset, preload and tick retain the World-idle guard. A rejected
voice backend still permits the source-ordered facial claim prefix; it does not
make the complete speech command successful.

## Qualification boundaries

The independent curve comparison executes complete `67C6D0` over all 33 real
clips plus 65536 eight-slot masks: both compilers pass 5,166,787 checks. Its
model-node count is explicitly zero, and its matrix child is a throwing
unentered boundary; the later owner proof closes that geometry boundary.

The concrete File1 reader passes 421,715 checks on each compiler, comparing all
419840 actual sector bytes and 51 retained leases against independent archive
reads. Its source authority is the pinned compiled catalogue inventory; it does
not re-execute SDK scheduling.

The owner comparison executes complete reset, preload, claim, update and matrix
math bodies against actual native skeleton/model instances. It compares retained
workspace bytes, metadata, cursor positions and every node after each visit.
It also exercises the original whole-pass terminal behavior, eight-slot pressure,
nonstandard reload rule, real missing paths, foreign binding refusal, stale-ID
prefix refusal and real Source callback guards. Formatter and SDK sector transfer
remain explicitly identified fixture ports using actual independently read bytes.
The command regression additionally executes full `5EEC50` for opcode 3.

Final private v6 passes 2,968,252 checks on each compiler: 100 preload visits,
43 claims, 21656 frames, 150234 node patches, 105 guarded Source callbacks and
1825103 original calls. Twelve complete bodies contribute 1351 matched owned
instruction words. The exact current CMake target independently passes
4,715,696 checks per compiler over all 33 clips, 21649 frames and 129696 node
patches. Its final graph includes the canonical Actor sound/CF2 metadata, linked
full-clear producer, World controller accessor and auxiliary timer consolidation;
older immutable archive graphs are retained as their own historical identities.

Finite consumed FP32 inputs/intermediates and increasing nonterminal clip times
are admitted. All 33 owned clips satisfy that profile. HP03 and HN39 have
nonfinite garbage in unused matrix ordinal 6; their actual base models have six
facial nodes and do not consume it. Arbitrary replacement data, metadata-bank
overflow/aliasing, physical PS2 exceptional arithmetic, complete scene entry,
movie/renderer services and the full Step 4 host are not established here.
