# Actor state12 root alignment and descriptor sequence

Static File #1 US research, 2026-11-04. Three complete original bodies reviewed.
Addresses, offsets and state selectors hexadecimal; distances/blends decimal.
No execution, attachment, build, replay or engine changes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6C1B20](../recomp/config/output_ovl/o2/o2_006C1B20_0x6c1b20.cpp) | `enter_primary_one_secondary12_save_transform_and_publish_selector_three` | High mechanics | Tuple8/9/A/B=(1,12,0,0),667370 saveXYZ/yaw,67E230(self,3). Routing does not prove delivery. |
| [o2 0x6C1B70](../recomp/config/output_ovl/o2/o2_006C1B70_0x6c1b70.cpp) | `enter_primary_three_secondary13_save_transform_and_publish_selector_three` | High mechanics | Tuple(3,13,0,0),667370,67E230(self,3). No other local state preparation. |
| [o2 0x6C1BD0](../recomp/config/output_ovl/o2/o2_006C1BD0_0x6c1bd0.cpp) | `tick_state12_target_alignment_and_three_descriptor_root_sequence_candidate` | High mechanics; interaction name unknown | Always54A|1D,32FF.6673C0 consumed reset clears54F/548bit1,sets(1,0,1,0),savestransform,selects2050(start0,blend10),58C7B0,then continues case dispatch from updatedA. Full A cases below. No original interaction enum inferred. |

| A | Complete local behavior |
| --- | --- |
| 0 | 54F=7,D10=1,saveXYZ/yaw,clear4E4/8/C;targetC34/C3C=ABC/AC4,C38=currentY,C4C=AC8lowhalf. Distance<=40 setsA1,else66DD50(self,0). Returns this call. |
| 1 | A2,54F7,BA8=1,58C7F0,5D50E0 descriptor72FE70(start0,blend10). SavescurrentXYZ toC40..48,yawC4E;timer12=20 when3243CC=0,otherwise10. Reads model34->824 through1925C0(start0,end20),rotates resulting vector aboutY using191BC0 at unsignedC4C*owned2pi/65536,and adds to targetC34..3C. |
| 2 | If timer12 nonzero,predecrement;665E60 interpolatesXYZ(C40->C34) and665FC0 yaw(C4E->C4C) withelapsed/total20or10;clearrootdeltas. Onzero snapsto targetXYZ/yaw. Always58C300(rateBA8);positive signed8result incrementsA. |
| 3 | A4,58C7F0,descriptor72FE78(start0,blend10),58C7B0,C48=abs(ACC). |
| 4 | Steprate1,C48-=abs(rootdelta4EC);ifresult<=0 incrementsA. |
| 5 | Steprate1;positive signed8result incrementsA. |
| 6 | A7,58C7F0,descriptor72FE80(start0,blend10). |
| 7 | Steprate1;signed8result exactly1 setsA=FF. |
| 8,FF | 5A26D0(self),54F0,548bit1clear,tuple(1,0,1,0),saveXYZ/yaw,2050(start0,blend10),58C7B0. |
| other | 66DD50(self,0);nonzero setsA1. |

Owned descriptor halves at72FE70/78/80, eachlength8:
`[10,0,2DD,2DD]`,`[10,0,2DE,2DE]`,`[10,0,2E1,2E1]`.
Their SHA256 respectively:
`a524ffd561705da72fb06b040a51933ca8f32222dfc4d7b0cad19e77640eeb6c`,
`dabc06b7f01fc41ded20fab25f8f42338e9f764dc9c45ff414564660ddcc379d`,
`bc48fe202f50489453e98a983602adc4355b3435e029314a8013b5f625f5ed04`.
Owned740EB0 float6.2831854820251465,SHA256
`12d85026b5109a3119231704608d5991a63d8d397d2867a9fc522305810ddb76`.
Owned image `build-function-index/owned-overlays/o2.bin`,base570000,SHA256
`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.

6C1BC0 is the already-known `return0` two-instruction body; no new semantic row
is added solely for another identical body. See shared actor alignment contracts
in [actor actions](SYMBOLS_ACTOR_ACTIONS.md) and descriptor interpretation in
[animation](SYMBOLS_ANIMATION.md).

Full-body owned-word audit: 3 rows, 337 verified instruction words,
zero conflicts, 9 omitted zero/NOP words, zero omitted nonzero words.
