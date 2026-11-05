# Actor 6C3FB0 parity callback, idle and wandering

Static File #1 US research, 2026-11-04. Six complete original bodies reviewed,
including merged6C4180. Addresses/offsets/selectors hexadecimal; random ranges,
time divisors and scalar values decimal where stated. No execution, attachment,
build, replay or engine changes. Original actor identity unresolved.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6C3FB0](../recomp/config/output_ovl/o2/o2_006C3FB0_0x6c3fb0.cpp) | `tick_actor_parity_primary_dispatch_and_optional_post_collision_candidate` | High mechanics | SavesXYZ/rotationto44..4C/A0..A6;54A=14,BA5=0,32FF,C94|301. (byte8&1) indexes730490,callsselectedcallback;C82=0 then65E3A0(self),otherwise no postcall. No local8bounds needed becauseparitymask. |
| [o2 0x6C4060](../recomp/config/output_ovl/o2/o2_006C4060_0x6c4060.cpp) | `initialize_actor_parity_idle_motion64_and_shape_candidate` | High mechanics | Incrementsbyte8,byte1=1,553=0,F0=1float,C80=0. Fourfloats pointed7304B0 ->C70..7C,copied1AC..1B8/1BC..1C8.190=20FFFF,194=0,Eulerbasis50,9/A/B=0,5A85F0(self,64,start0,blend0),58C7B0. |
| [o2 0x6C4160](../recomp/config/output_ovl/o2/o2_006C4160_0x6c4160.cpp) | `dispatch_idle_wander_secondary_and_tick_random_idle_motion_candidate` | High mechanics | Byte9uncheckedindexes730498;0targetsmerged6C4180. A0 C=(RNG1low16%180+120)/factor thenfallsA1. A1setsA2,E=(next%60+60)/factor,selectsmotion64+(next&1)via6C4500,58C7B0. A2predecrementsC;post<0 writes9=1,A0;thenpredecrementsE;post<0 writesA1 evenafterpreviouswrite. Stepanimation1float. OtherAreturns. |
| [o2 0x6C42D0](../recomp/config/output_ovl/o2/o2_006C42D0_0x6c42d0.cpp) | `tick_random_yaw_wander_motion66_with_surface_reaction_candidate` | High mechanics | A0->1,C=(RNG1low16%180+120)/factor,E=(next%30+30)/factor,10=0,6C4500(self,66),58C7B0,9A0;16CnonzeroE0. A1C--,post<0 resets9/A0 butcontinues;10=0and16CnonzeroE0. E-- expiredwith16Cnonzero sets9A=+800 unless fullRNG1returnzero then-800,E=30/factor,10=1;otherwise9A=((RNG1low16&1FF)-FF)*4,E=(next%60+60)/factor,10=0. Adds9Atoyaw92,stepsbaserate. OtherAreturns. |
| [o2 0x6C4500](../recomp/config/output_ovl/o2/o2_006C4500_0x6c4500.cpp) | `blend_motion_when_requested_differs_but_write_current_id_to520_candidate` | High mechanics | Comparefulla1requestedagainstunsigned1F2. Differentwritescurrent1F2to520,then58BF40(self,requested,start0,blend10);same58C300(rate1). Does not write requested ID to520 in thisbody;calleecontract matters. |
| [o2 0x6C4550](../recomp/config/output_ovl/o2/o2_006C4550_0x6c4550.cpp) | `dispatch_motion66_audio_with_520_duplicate_marker_candidate` | High mechanics | Only1F2=66. Signedhalf520differentfrom66 writes520=66 and5A9250(frame0,event2,count3,step). Always5A9250(frameC,event0,count2,step). Othermotionsreturn. Markerwriteoccursbeforeframegate, so local marker doesnotprove soundplayback. |

Factor=unsigned74F200 (existing1/2 setting). Base rate=float728FF0+12*BA1.
The full RNG return zero test in the blocked-surface branch is preserved; it is
not replaced with a guessed50/50 random bit. Timer decrements and same-call
fallthrough remain explicit, including the laterA1 assignment overridingA0.

Owned dispatch/shape spans and digests below come from
`build-function-index/owned-overlays/o2.bin`,base570000,SHA256
`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.

| Span | Values / SHA256 |
| --- | --- |
| 730490 length8 | [6C4060,6C4160]. `2681df087cedf64767fa8a9ff758dce25944bb77e3ebf7d058c345482c653148` |
| 730498 length8 | [6C4180,6C42D0]. `6ef037bebe73bef8dfc3af0717a1824490967e00e8e95a7e56a3d5b9d38d7d81` |
| 7304B0 length4 | Pointer7304A0. `7866c4c2e84b8899cd7074c459a98bf25c07200b727f48a9ba47074800c0075e` |
| 7304A0 length10 | Floats(0,0,0,18) decimal. `d4582f00b853a4601bceb7aad852eb77af9028e8658ac9fd9ff44a9a3c79b9b5` |

Full-body owned-word audit: 6 rows, 368 verified instruction words,
zero conflicts, 17 omitted zero/NOP words, zero omitted nonzero words.
