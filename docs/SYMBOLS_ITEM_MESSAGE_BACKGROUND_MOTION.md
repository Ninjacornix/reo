# Item/message bounded background motion and status palette

Static File #1 US research, 2026-11-04. Five complete original bodies reviewed.
Addresses/offsets hexadecimal. No game/build/replay/attachment/live-memory
inspection. These are screen UI cache slots, not game actor motion or global
updates. Status meaning from5F6FB0 remains unassigned.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6DD0A0](../recomp/config/output_ovl/o2/o2_006DD0A0_0x6dd0a0.cpp) | `refresh_background_motion_count_and_palette_on_status_change_candidate` | Probable role; full body reviewed | Cache755D78;5F6FB0(local4BADED)status0/1/2/3sets58Ccount4/16/24/32,otherstatusesleaveoldcount;storesstatus590. Onlyifcountchanged,recolors15CLUTentriesat1C+84,RGBfrom734200[status],preservingalpha. Noindexguardforunexpectedstatusorcache-nullguard. |
| [o2 0x6DD190](../recomp/config/output_ovl/o2/o2_006DD190_0x6dd190.cpp) | `initialize_background_motion_count_and_status_palette_candidate` | Probable role; full body reviewed | Clearscache84drawcount. Sameindependentlyreviewed5F6FB0status->58C/590mappingasD0A0,butalwaysrewrites15CLUTRGBentries,preservingalpha. Doesnotgenerate32slotpositionshere. |
| [o2 0x6DD270](../recomp/config/output_ovl/o2/o2_006DD270_0x6dd270.cpp) | `clamp_background_motion_slot_to_rectangle_and_reflect_velocity_candidate` | High mechanics; probable role | a0index;cache755D78slot8bytepositions32C/330,basevelocities12C/130. IfX<=522clamps522andnegatesXvelocity;Y<=334clamps334/negatesY;X>=580clamps580/negatesX;Y>=392clamps392/negatesY. Independentorderedcomparisons,nomotionintegrationorindexguard. |
| [o2 0x6DD380](../recomp/config/output_ovl/o2/o2_006DD380_0x6dd380.cpp) | `tick_thirty_two_background_motion_slots_with_bounded_phase_updates_candidate` | Probable role; full body reviewed | RequirescacheandlocalactorBB6/BB8/BBAhalvesallzero. Every32slotsincrementsphase42C&3F,subphase4AC&F. Every16callsupdatesangleACby+/-1000fromdirectionbyte56C,sine(angle)*base12C/130->velocity22C/230. Every64callsrandomizesdirectionandhalf-amplitudesviasine/cosineof1AEC80(1). Integratespositions32C/330thenD270clamp. Fixed32-slotloop;noglobalgame-clockadvance,actorvelocityorVUprogrammutation. |
| [o2 0x6DD650](../recomp/config/output_ovl/o2/o2_006DD650_0x6dd650.cpp) | `append_background_status_panel_and_selected_motion_slot_sprites_candidate` | Probable role; full body reviewed | Requires4BAE7EnonzeroandlocalactorBA4bit1000clear;D380advancesmotion. Fourtemplates734170in24strides:0/3directC5E0,1copies36bytesandsetscolorfrom734210[status590],2emits58CmotionpositionsroundedtohalfwordswithC5E0. Countisstatus-dependent4/16/24/32underobservedinitializers;nocountclamphere. NoactualGPUenqueueorwait. |

Motion rate is original per-invocation arithmetic. Its wall-clock frequency and
performance impact were not measured, and diagnostics/game speed are untouched.

Owned o2 SHA-256:45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226.
Original words and omitted-NOP gaps verified against file-backed o2, base570000.
