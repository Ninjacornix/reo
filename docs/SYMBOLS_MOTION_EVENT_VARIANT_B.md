# Alternate actor motion-event schedule dispatcher

Static File #1 US research, 2026-11-04. This completes the sibling of
[5965A0 and59EBB0](SYMBOLS_MOTION_EVENT_DISPATCH.md),using the same
[reviewed crossing-event adapters](SYMBOLS_ANIMATION_CROSSING_EVENTS.md).
No game,build,replay,attachment,live-memory inspection or runtime change was made.
Counts are decimal; fields,IDs,masks and addresses are hexadecimal. The complete
original body was structurally reviewed through all instruction classes,
branches,memory accesses and callee targets; no original per-motion names are
invented.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x59A820](../recomp/config/output_ovl/o2/o2_0059A820_0x59a820.cpp) | `dispatch_alternate_actor_two_motion_bank_frame_schedules_candidate` | Probable router role; complete original structure and side effects reviewed | a0actor,f12stepsavedf20. Firstunsignedmotion1F2 selects14bank0schedulesincludingA0..A7/AF/B0/BF/C0/17A/17B;thenindependentlyunsignedmotion212 selects241forwardequalitybranches. Usesreviewedcrossing/audio/actioneffect/resource/controladapters,thenalways59EBB0(actor,originalstep).4,075originalinstructions,no nonstackstores,nobackwardbranches,sixnonstackreadsbelow. Exceptionsoutside motioncomparisons:54F==39admitsframe1effectC8andframe64flagkind3;word719A60+44*CA8bit20admitsframeAevent7. Compared5965A0,additionalBF/C0bank0cases,differentprimary/secondarytargetframes,andno actorcategorybyte2conditional.628staticJALsitesarecodeinventory,notper-updatecallsorameasuredbottleneck. |

Complete nonstackmemoryread inventory:unsignedhalf1F2 at59A838;
unsignedhalf212at59A8E4/59AA88;unsignedbyte54Fat59C3B4;
unsignedhalfCA8at59EB10;indexedword719A60+44*CA8at59EB2C. All localstores
savearguments/registers onthestack;calleehelpersownactor/globalwrites.
All255equalitybranches,242unconditionalbranchesandtwootherconditionalbranches
areforward. Beyond constantargumentconstruction,stacksave/restoreandcalls,
onlythefinalprofile-addressmultiply/add/bitmasksequence remains. Thus this
body is an unrolled schedule router with boundedlocalcontrolflow;that says
nothing about the cost or boundedness of a called helper.

| Destination | Static callsites |
| --- | --- |
| 595B70 | 444 |
| 595C90 | 66 |
| 596060 | 33 |
| 595DD0 | 30 |
| 595C00 | 25 |
| 596180 | 18 |
| 596470 | 5 |
| 595FA0 | 4 |
| 596000 | 1 |
| 595E30 | 1 |
| 59EBB0 | 1 |

This separately reviewed body must not be aliased to5965A0 solely because
its structure and callees resemble it. Exact numeric schedule differences
remain in the linked source; no calls were removed,collapsed or retimed.
Originalinstructionwordswerecheckedagainsttheownedo2blob. Artifactidentity
is recorded in [the central index](FUNCTION_INDEX.md). No runtime timing,
slowdown reproduction or controlled fix/retest is claimed.
