# Primary-clip sound crossings in67D440

Static File #1 US, 2026-11-05. One complete original o2 body reviewed, including every clip comparison, ordered request and delay slot. Clip IDs, frames and event IDs below are hexadecimal; f12 is caller float step. No execution, build, attachment, live memory, input or timing. Original animation/sound names remain unknown.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x67D440](../recomp/config/output_ovl/o2/o2_0067D440_0x67d440.cpp) | `request_sound_crossings_for_primary_clip67d440_family_candidate` | High mechanics; candidate role | a0actor,f12step. Readsunsignedclip1F2,preservesstepinf20,selectsliteralclipcasesbelowandissues5A9250(frame,actor,event,width). Unknownclipreturnswithoutrequest. Restoresf12beforefollowingcalls;doesnotadvanceanimationorchangegamespeed. |

Everyrequestusesentryactorasa1,eventasa2,widthasa3. [Framecrossing/varianthelper](SYMBOLS_ANIMATION_SOUND.md)retainsitsownadmissionandRNGsemantics;thefirsttupleelementisaframe,notasoundID. Width0stillallowsbaseevent. Everymulti-requestpathrestoresoriginalstepfromf20beforeeachlaterrequest.

| Clip1F2 | Ordered(frame,event,width)requests |
| --- | --- |
|68|(0,8,2);(40,8,2)|
|69|(46,8,2)|
|96|(A,0,2);(1A,0,2);(3A,0,2)|
|97|(14,0,2);(20,0,2);(2A,0,2);(36,0,2);(40,0,2);(50,0,2);(5C,0,2)|
|98,99|(8,0,2);(12,0,2);(20,0,2);(2C,0,2)|
|9A|(A,0,2);(16,0,2);(22,0,2)|
|9B,9C|(6,0,2);(C,0,2);(18,0,2);(20,0,2)|
|9D,9F,A0,A1|(2,3,0)|
|9E|(4,2,0)|
|A2,A5,A7,A9|(0,E,0)|
|A4|(0,2,0)|
|AB,AC,AD|(14,2,0)|
|AE|(10,0,2);(1A,0,2);(22,0,2);(30,0,2);(3C,0,2);(42,0,2)|
|C8|(A,0,2);(18,0,2);(24,0,2);(2E,0,2);(3A,0,2)|
|C9|(10,0,2);(1A,0,2);(24,0,2);(2E,0,2);(3C,0,2)|
|FA|(6,A,0)|
|FC|(38,2,0)|
|FD|(28,C,0)|
|136,141|(4,4,0)|
|137|(1A,2,0)|
|138|(22,4,0)|
|139|(14,2,0)|
|13B|(A,7,0)|
|13C|(46,7,0)|
|192|(32,C,0)|
|196|(4,A,0)|
|1F6|(1E,C,0)|
|1FE|(0,A,0)|

Thisisthecompletebranchedrequestschedule,notasamplecountorperformanceestimate.Repeatedrequestsareeligibleframecrossingsratherthanunconditionalplayback;thecalleeownsthatpolicy.Callerclipadmission,stepvalues,audibilityandcostremainunmeasured.Ownedo2base570000SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. Full owned-body audit: 451 original words verified; 32 omitted words all zero/NOP; zero conflicts and zero omitted nonzero words.
