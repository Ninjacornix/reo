# Actor 6F18A0 directional responses and recovery

Static File #1 US research, 2026-11-04. Four complete original bodies reviewed, including merged6F6FE0. Addresses/offsets hex unless marked decimal. Directional response is a candidate role from B1F banks and saved response state; original action/actor identity unconfirmed. No execution, build, attachment or engine edits.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6F6F80](../recomp/config/output_ovl/o2/o2_006F6F80_0x6f6f80.cpp) | `dispatch_actor_6f18a0_primary_three_and_tick_basic_directional_response_candidate` | High mechanics; probable role | OR resource byte74F295+60*B98 with10,cache actor11C in75A100,taildispatch73C180[9]. Internal6FE0 handlesA0/FF: A0 first63F5A0(actor,actor3); if motionCC and frame>=40 decimal, yaw-=8000,reset actor34->824+40 basis18FE20, select descriptor73C238[B1F]; else73C228[B1F]. Selectframe0/blend10. FF alsoC363E;setA1. A1 advances;1F1bit40 setsC3658 ifC94bit20 then77E0. No effect interpretation assigned to response resourcebit10. |
| [o2 0x6F7140](../recomp/config/output_ovl/o2/o2_006F7140_0x6f7140.cpp) | `tick_actor_6f18a0_alternate_directional_response_candidate` | High mechanics; probable role | Same A0/FF setup, conditional motionCC/frame>=40 yaw flip and basis reset, FF C363E, A1 animation/recovery as merged6FE0; normal descriptor bank is73C230 instead of73C228, flipped bank73C238. Current owned normal eight-byte banks are identical, but each function/address and all writes/calls remain distinct. |
| [o2 0x6F72A0](../recomp/config/output_ovl/o2/o2_006F72A0_0x6f72a0.cpp) | `tick_actor_6f18a0_primary_three_fixed_descriptor_ten_candidate` | High mechanics; probable role | Everycall32FF. A0/FF performs same motionCC/frame>=40 yaw flip/basis reset, selectsdescriptor10/frame0/blend10; unlike6FE0/7140 does not call63F5A0 onA0. FF C363E,thenA1. A1 advances;1F1bit40 optionallyC3658 viaC94bit20,then77E0. No directional bank read here. |
| [o2 0x6F73C0](../recomp/config/output_ovl/o2/o2_006F73C0_0x6f73c0.cpp) | `tick_actor_6f18a0_primary_three_staged_response_and_hold_candidate` | High mechanics; probable role | Everycall32FF. A0first63F5A0; A0/FF sameconditional motionCC/frame>=40 yaw flip/basis reset,descriptorC/frame0/blend10,58C780,A1;FF C363E. A1 nonzero animation ->A2/descriptor13. A2 nonzero ->A3,634880(actor,C2A) return->timer10,descriptor19. A3 advances and predecrements signed10;post<=0 ->A4/descriptor18 and58C780. A4 advances until1F1bit40 then77E0. Different completion tests (nonzero versus bit40) retained. |

Owned73C180 has six entries: internal6FE0,7140,7140,72A0,73C0,6FE0.
Motion comparison half73C59E=CC. Descriptor banks73C228/73C230 each contain
C,B,8,9,9,A,D,C;73C238 contains9,A,A,C,C,B,8,9. Bank indices come from
B1F, quantized in [shared response controls](SYMBOLS_ACTOR_6F18A0_SHARED_CONTROLS.md).
The source contains no new bounds check; original caller/state admission is
required. Equal owned bank contents do not prove a whole-function equivalence
or justify changing response timing. No measured performance claim.
