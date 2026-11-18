# Large actor motion-event schedule dispatchers

Static File #1 US research, 2026-11-04. This closes the large callers of the
[animation crossing event adapters](SYMBOLS_ANIMATION_CROSSING_EVENTS.md).
No game,build,replay,attachment,live-memory inspection or runtime code change
was performed. Counts explicitly named here are decimal; IDs/addresses/masks
and frame constants in schedules are hexadecimal. Research names describe
routing and sideeffects; original animation names and individual sound names
remain unknown.

The large5965A0 entry was reviewed through its original instruction structure,
all memory accesses,all branch targets,all call targets and exceptional local
conditions. Repeated straight-line argument construction was classified across
the full body;individual numeric schedules are not assigned guessed original
interaction names. This is a semantic router mapping,not a rewritten dispatcher
or verified performance optimization.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x596550](../recomp/config/output_ovl/o2/o2_00596550_0x596550.cpp) | `spawn_node41_effect_on_bank_one_animation_crossing_candidate` | Probable role; full body reviewed | a0signedtargetframe,a1actor,f12step. Calls573480(actor,1,float(target),step);nonzerocallsreviewed5DE4C0(actor),whichattemptsnodepositioneffect41. No additionalactivity/nullcheck or animationadvance;no RNGhere. |
| [o2 0x5965A0](../recomp/config/output_ovl/o2/o2_005965A0_0x5965a0.cpp) | `dispatch_actor_two_motion_banks_audio_and_effect_frame_schedules_candidate` | Probable router role; complete original structure and side effects reviewed | a0actor,f12step savedf20. Firstunsignedmotion1F2 selects12 twoeventbank0audio schedulesvia595C00,thenindependentlyunsignedmotion212 selects223 equality-branchschedules. Thosecallsroute595B70/595C90/595D30/595DD0audio,596060actioneffectflags,596180node/resourceeffects,595FA0nodeaudio,596470control,595E30callbackcreation;commonfinish59EBB0(actor,originalstep). Complete4,024-instructioninventoryhasno nonstackwrites,nobackwardbranches,sevennonstackreads(listbelow)and625staticJALsites. Onlythreeadditionalconditionsoutsideprimarymotioncomparisons:category2byte!=0choosesalternateaudio at597448;byte54F==39admits596060at598194;word719A60+44*halfCA8bit20admitslateaudioat59A794. Numericper-motionvisual/soundnamesunknown. Callsitecountisnotcallsperupdate. |
| [o2 0x59EBB0](../recomp/config/output_ovl/o2/o2_0059EBB0_0x59ebb0.cpp) | `dispatch_additional_bank_one_motion_audio_and_effect_schedules_candidate` | Probable router role; full body reviewed | a0actor,f12step. Unsignedmotion212comparedagainst53numericIDsthroughforwardequalities;no matchingIDreturnwithoutcallbacks. Exactbodyhas85JALsites595B70,5sites595C90,3sites596060,2sites596000,1site596180;no directnonstackwritesorbackwardbranches. CaseF2nodeeffectatframe1A(kind0,nodeC,profile1);F3frame0audio3/4andframeAeffect7A;F6bank1audio24/4A/6E/A2plusaudio/effectpairsat14/2A IDs15andC9/CA. Cases352frame20positionevent41,395frame0event3D. Sharedcrossinggateperformseachscheduleadmission;no originalaudioenumoractornameinferred. |

The5965A0 first-bank schedules all call595C00(actor,kind0) for these frames:

| Motion1F2 | Two targetframes |
| --- | --- |
| A0/A1 | E,2E |
| A2/A3 | 18,34 |
| A4 | 12,32 |
| A5 | 28,46 |
| A6 | 1E,3E |
| A7 | 24,40 |
| AF | 1,1F |
| B0 | 19,41 |
| 17A | 12,24 |
| 17B | 4,A |

Complete5965A0 memory-access inventory outside the local stack:unsignedhalf
1F2 at5965B8;unsignedhalf212at59664C/59682C;unsignedbyte2at597444;
unsignedbyte54Fat59818C;unsignedhalfCA8at59A770;indexedword719A60+44*CA8
at59A78C. No store targets actor/global memory directly;all such effects are
through reviewed helper calls. The onlyoperations outside constant argument
construction,stack save/restore,motion comparisons and calls are the final
profile-address multiply/add/bitmask sequence. Every conditional and
unconditional local branch goes forward;the original dispatch bodies have no
local count loop.

Static JAL inventory inside5965A0:

| Destination | Static callsites |
| --- | --- |
| 595B70 | 437 |
| 595C90 | 65 |
| 596060 | 33 |
| 595DD0 | 31 |
| 595C00 | 24 |
| 596180 | 23 |
| 596470 | 5 |
| 595FA0 | 4 |
| 595D30 | 1 |
| 595E30 | 1 |
| 59EBB0 | 1 |

These totals describe code layout. A path selects one schedule per motionbank,
and helper frame admission may suppress its effects;the totals establish
neither per-framework nor a measured bottleneck. Sourcecommentwords are checked
against the owned o2 artifact. Artifact identities are recorded in
[the central index](FUNCTION_INDEX.md);no runtime timing or controlled retest
is claimed.
