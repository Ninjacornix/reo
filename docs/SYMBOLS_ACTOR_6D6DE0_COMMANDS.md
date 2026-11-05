# Actor 6D6DE0 command dispatcher and scenario-16 sequence

Static File #1 US research, 2026-11-04. Fifteen full original bodies reviewed,
including every primary table arm and scenario16 substate. Addresses/offsets
are hexadecimal, explicit counts decimal. No game/build/replay/attachment or
live-memory inspection. This actor remains address-identified; no original
character, creature, action or room names are claimed.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6D6DE0](../recomp/config/output_ovl/o2/o2_006D6DE0_0x6d6de0.cpp) | `update_actor_6d6de0_primary_command_dispatch_candidate` | Probable role; full body reviewed | SignedFCF range0..7 dispatches owned7410C0:0->6D6ED0,1->6D6F70,2->6D6FE0,3->6D6FB0,4->6D6FD0,5->6D6F90,6->6D6FA0,7->6D6FC0. Other values skiphandler. Everypath then66B850(actor),626190(actor),5BE2D0(actor),6261C0(actor). These are guest actor callbacks, not independent host threads. |
| [o2 0x6D6ED0](../recomp/config/output_ovl/o2/o2_006D6ED0_0x6d6ed0.cpp) | `initialize_actor_6d6de0_command_fields_candidate` | Probable role; full body reviewed | Sets halfword22\|9 in390210+78*unsignedFB5. ClearsFD0..3,actor8..B,FB7/FB8;FCF=1. UnlessBA0bit80000, selectsFB7=0,state1=1. RedundantFB7test after clearing is retained as original code, not a new failureclaim. |
| [o2 0x6D6F70](../recomp/config/output_ovl/o2/o2_006D6F70_0x6d6f70.cpp) | `start_actor_6d6de0_related_record_retry_candidate` | Probable role; full body reviewed | FCF=2,state1=1; tailcalls6257A0(actor,actor+10A4). Doesnotclear workbuffer locally. |
| [o2 0x6D6F90](../recomp/config/output_ovl/o2/o2_006D6F90_0x6d6f90.cpp) | `actor_6d6de0_saved_transform_restore_adapter_candidate` | High adapter; candidate role | Original tailjump625930; NOP delay slot. Preserves allarguments. |
| [o2 0x6D6FA0](../recomp/config/output_ovl/o2/o2_006D6FA0_0x6d6fa0.cpp) | `actor_6d6de0_route_transfer_adapter_candidate` | High adapter; candidate role | Original tailjump625C50; NOP delay slot. Preserves allarguments. |
| [o2 0x6D6FB0](../recomp/config/output_ovl/o2/o2_006D6FB0_0x6d6fb0.cpp) | `actor_6d6de0_command_transition_poll_adapter_candidate` | High adapter; candidate role | Original tailjump625670; NOP delay slot. Preserves allarguments. |
| [o2 0x6D6FC0](../recomp/config/output_ovl/o2/o2_006D6FC0_0x6d6fc0.cpp) | `actor_6d6de0_related_record_retry_adapter_candidate` | High adapter; candidate role | Tailjump6257A0 and delay-slot a1=actor+10A4. UnlikeF70 doesnotwriteFCF/state1. |
| [o2 0x6D6FD0](../recomp/config/output_ovl/o2/o2_006D6FD0_0x6d6fd0.cpp) | `actor_6d6de0_primary_four_original_noop` | High; original words verified | jrra pluszero/NOP delay slot; no statewrite. |
| [o2 0x6D6FE0](../recomp/config/output_ovl/o2/o2_006D6FE0_0x6d6fe0.cpp) | `tick_actor_6d6de0_normal_or_command_transition_candidate` | Probable role; full body reviewed | Calls625630. Result0 runs6D7060(actor) then6257A0(actor,10A4). Result1 setsFCF=3; other nonzero setsFCF=4,544=0,publishes6260E0(FB5). Both nonzero branches684810(actor,0). No inferred cause behind numeric classifier. |
| [o2 0x6D7060](../recomp/config/output_ovl/o2/o2_006D7060_0x6d7060.cpp) | `dispatch_actor_6d6de0_scenario16_sequence_candidate` | Probable role; full body reviewed | Actor1E2==16 dispatches word1150:0->6D7190,1->6D7230,2->6D7350,3->selectFB7=0/state1=1 unlessBA0bit80000. Other phases return. Other1E2 values selectsame idle numericstate. No loop/wait inside dispatcher. |
| [o2 0x6D7170](../recomp/config/output_ovl/o2/o2_006D7170_0x6d7170.cpp) | `advance_actor_6d6de0_scenario_sequence_clear_substates` | High; full body reviewed | ClearsFD0/FD2/FD3 andincrementsword1150. FD1 is deliberately not cleared here. |
| [o2 0x6D7190](../recomp/config/output_ovl/o2/o2_006D7190_0x6d7190.cpp) | `tick_actor_6d6de0_scenario16_wait_for_flag_candidate` | Probable role; full body reviewed | FD2phase0 selectsFB7=0/state1=1 unlessBA0bit80000 thenincrementsFD2. Phase1 (also enteredimmediatelyafterinitialization) tests global4B9C0Cbit2000000 andcalls7170 ifset. OtherFD2 valuesreturn. State persistsacrossinvocations, no busywait. |
| [o2 0x6D7230](../recomp/config/output_ovl/o2/o2_006D7230_0x6d7230.cpp) | `tick_actor_6d6de0_approach_fixed_scenario_position_candidate` | Probable role; full body reviewed | Copies owned731E28 floatXYZ=(8482,310,7535) into1124/28/2C;6BD270(actor,&XYZ), selectsFB7=1/state1=1 unlessBA0bit80000. Uses665DC0 Euclideandistance; unless20<=distance, setsFF4=5780,FCC=1,selectsFB7=D/state1=1 unlessflag80000, then7170. Exact orderedcomparison retained; no inferredanimationname. |
| [o2 0x6D7350](../recomp/config/output_ovl/o2/o2_006D7350_0x6d7350.cpp) | `finish_actor_6d6de0_scenario_sequence_after_fcc_clear_candidate` | Probable role; full body reviewed | SignedFCCnonzero returns. Oncezero,5703E0(7A,1),7170(actor),73A0(actor). State1150advances2->3 inthiscaller; no automaticcutsceneidentityclaim. |
| [o2 0x6D73A0](../recomp/config/output_ovl/o2/o2_006D73A0_0x6d73a0.cpp) | `save_actor_6d6de0_transform_and_sequence_to_record_candidate` | Probable role; full body reviewed | Record390210+78*unsignedFB5 receives rootXYZ at8/C/10,yawhalf14,low8(actor1E2) atbyte1,word1150at28. No local indexbound orflush; filepersistence notestablished. |

The complete8-slot primary table is checked from owned o2 bytes; no slot is
filled by analogy. Shared transition mechanics are recorded separately in
[Actor command transitions](SYMBOLS_ACTOR_COMMAND_TRANSITIONS.md).

Owned o2 SHA-256:45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226.
Original words and omitted-NOP gaps verified against file-backed o2, base570000.
