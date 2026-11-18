# Paired response release variants6432A0..64461B

Static File #1 US, 2026-11-05. Three complete original o2 bodies reviewed. No execution, build, attachment, live memory, input or networking. States, descriptor IDs and addresses are hexadecimal; explicit durations are decimal. Proposed roles are descriptive candidates, not recovered original names.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6432A0](../recomp/config/output_ovl/o2/o2_006432A0_0x6432a0.cpp) | `update_paired_response_yaw_alignment_actor_effect_and_release_branches_candidate` | High mechanics; candidate role | Links partner with B20=8; phases1/2 initialize descriptor0 and10/5-call interpolation toward unchanged position and partner yaw+8000; actor-effect selectorsC/D, signal63, partner4/5 release branches and three-descriptor bank7112F0. No common offset-copy tail. |
| [o2 0x643930](../recomp/config/output_ovl/o2/o2_00643930_0x643930.cpp) | `update_paired_response_two_descriptor_actor_effect_and_signal_release_candidate` | High mechanics; candidate role | Links partner with B20=7; selects two-entry bank711320, applies actor-effect selectorsE/F around exact animation return2 and waits63; phases5/6/7/8 provide alternate partner4 and completion release. No position/yaw alignment or common offset-copy tail. |
| [o2 0x643E30](../recomp/config/output_ovl/o2/o2_00643E30_0x643e30.cpp) | `update_paired_response_partner_model_point_blend_and_terminal_branch_candidate` | High mechanics; candidate role | Links partner with B20=5; initial horizontal distance/150 selects blend of bank711340 descriptors0/1, follows partner model point index14, actor-effect selectors10/11,63 release, alternative health/probe descriptor3 or terminal1043 branch. Exact original action and blend-helper interpretation remain unresolved. |

All three take a0 actor and use byteA as phase. Prelude OR54A bitsC, byte32=FF. Positive6673C0 performs immediate idle reset (clear54F and548 bit1, action1/0/1/0,667370 snapshot,2050 start0/blend10,58C7B0 activation) and returns. Nonzero phase resolves partner E=42EB00+D90*byte(74F251+60*B1D), without local bounds. Class0 partnerC26!=source3 setsAFF. When A changes versus entry,67E230(actor,1) publishes BEFORE executing the new phase. Fixed-pool null tests do not establish valid indices or lifetime.

Phase0 in every body sets A1,54FB0,D101, snapshot, clearsB22/B1E/B9F, resolves663350(148,149); failure returns to immediate idle2050/blend10. Success stores ownB24=E/B1D=E.B98; partnerB1C/B1E1, partnerB1D=source3/B24=source, then B20 as above; clears source rootXYZ4E4/4E8/4EC. Phase0 does not initialize the local E variable used by later phases, but has no partner-dependent tail. Phase1 increments to2 and falls through initialization; direct phase2 follows the same initialization, incrementing to3. Unknown phases only receive prelude/admission work. FF resets to idle2050/blend10 with byte32=60 if3243CC zero else30. Animation ticks below use58C300(actor,1); comparison2 or positive means signed low byte except the explicit5D57D0 low-byte comparison noted below.

## 6432A0: yaw alignment and two release options

False63EF30(E) or B1E6 changes phases below5 to5, preserving higher phases including FF.

| Phase | Exact body |
| --- | --- |
| 1/2 | Advance to3, zeroE/10,58C7F0, select descriptor0 start0/blend10 and activate bank. Both endpointC34..3C and startC40..48 copy current XYZ, so this initialization does not create a translational target. C4C=partner92+8000, C4E=own92; timer12=10 if3243CC zero else5. |
| 3 | If timer12!=0, predecrement,665E60(XYZ,C40,C34,total-post,total),665FC0(yaw,C4E,C4C,total-post,total), clear rootXYZ; on reaching0 force exact endpointXYZ and yawC4C. Then tick animation. Exact result2 emits6681C0(actor,C) and advancesA4. Animation may advance before interpolation finishes. |
| 4 | Tick, exact2 applies6681C0(actor,D); then B1E63 clears B1E and advancesA5. |
| 5 | PartnerB1E4,58C7F0, advanceA6, select descriptor1 start0/blend10. No activation call here. |
| 6 | Tick; positive completion setsAFF. |
| A | AdvanceAB,58C7F0, partnerB1E5, select descriptor2 start0/blend10. |
| B | Tick; positive completion setsAFF. |

## 643930: two-descriptor signal release

False63EF30(E) or B1E6 changes phases below5 toFF, rather than entering phase5.

| Phase | Exact body |
| --- | --- |
| 1/2 | Advance3, zeroE/10,58C7F0, select descriptor0 start0/blend10, activate bank, 6681C0(actor,E). |
| 3 | Tick; exact2 applies6681C0(actor,E) and advances4. |
| 4 | Tick; exact2 applies6681C0(actor,F). B1E63 clears B1E and setsA6, skipping5. |
| 5 | PartnerB1E4,58C7F0, setA6, FALL THROUGH and tick phase6 in this call. |
| 6 | Tick; positive completion increments to7. |
| 7 | Advance8,58C7F0, select descriptor1 start0/blend10. No activation call. |
| 8 | Tick; positive completion setsAFF. |

## 643E30: blend and model-point following

False63EF30(E) changes phases below5 to5. Independently B1E6 changes phase4 to5 only when NOT(own float1E4 <1EC), so unordered float comparison also takes this transition. It does not force lower phases to5 on signal6 alone.

| Phase | Exact body |
| --- | --- |
| 1/2 | Advance3, zeroE/10,58C7F0. Compute delta partnerXYZ-sourceXYZ, zero deltaY, length191CC0 then absolute1920A0; ratio=length/150, replace with1 when NOT(ratio<=1). Normalize delta via191D80, though no subsequent local delta use is evident. Call5D56D0(actor,descriptor0,descriptor1,f12=1-ratio). Get partner model-work+820 point pointer at index word711078, take point+30/+38 for X/Z and current sourceY; interpolate own XYZ halfway toward it via665E60 with1/2. Activate bank. |
| 3 | Advance4;5D57D0(actor,1,actor1F8), repeat halfway interpolation toward same partner model point, 6681C0(actor,10). |
| 4 |5D57D0(actor,1,actor1F8); low byte==2 applies6681C0(actor,11). Copy partner model point X/Z directly to own X/Z, preserving ownY. B1E63 clears B1E and advances5. |
| 5 | PartnerB1E4,58C7F0, advance6, select descriptor2 start0/blend10. |
| 6 | Tick; positive completion setsA8 and skips later health test. Otherwise health<2 leaves6. Health>=2 calls573480(actor,0,f12=21.0,f13=1); nonzero advances7,58C7F0, descriptor3 start0/blend10. |
| 7 | Tick; positive completion setsAFF. |
| 8 | Advance9,5D6ED0(actor,0),58C7F0, select1043 start0/blend10. |
| 9 | Tick; positive completion clearsBA0 bit40000. Class1 calls5F6800(actor,0),54FA0, action4/0/A/0, snapshot, serialize67E230(actor,1). Other classes call65FBA0(actor,A). |

No body has the CF4..CFC partner-offset exit copy found in earlier paired responses. Model-point pointers and B99 indices have no local bounds/validity guards; caller admission and runtime lifetime are unknown. These are observed static access contracts, not confirmed faults or slowdown causes.

##  Owned data and evidence limits

All three banks use packed 8-byte descriptors. Literal half0=60 and half2=0 throughout; half4 and half6 match. Physical two-bank windows do not establish admitted B99 range, and halfword meanings are not guessed.

| Window | Physical banks: half4/6 pairs | SHA256 |
| --- | --- | --- |
|7112F0..71131F,48 bytes | two triplets:8,2,5 and3A,34,37 |`098c17ac61a6f2195e51537139f9147e72485e123e0a0a2ed68d1874079af15e` |
|711320..71133F,32 bytes | two pairs:1,2 and33,34 |`aa3ebbe411bef7556f0cca6848d5ac1695cd72600d8226e94a736d88889c9600` |
|711340..71137F,64 bytes | two quartets:4,1,2,3 and36,33,34,35 |`40033e158d6e39109efb855d9538b72958947df2d3f31546631b82278c24be18` |

711078 is owned word14 (decimal20), SHA256`447e12701a0d03cf90a4ad7f02f1a045b35d284e26fe520440edb116d76bf700`. Math helpers are independently mapped in [render math](SYMBOLS_RENDER_MATH.md); animation/descriptor ownership remains in [animation](SYMBOLS_ANIMATION.md). Original o2 base570000 SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. No gameplay reproduction, elapsed cost, active transition, sound playback, root cause or controlled fix was measured.

Full owned-body audit: 1,146 original words verified; 95 omitted words all zero/NOP; zero conflicts and zero omitted nonzero words.

Correction from complete child review:6681C0 applies difficulty/RNG-indexed health and BAC changes with optional secondary actor effect;it is not a sound request. Numeric selectors above are actor-effect selectors. No audio playback is established by this child.
