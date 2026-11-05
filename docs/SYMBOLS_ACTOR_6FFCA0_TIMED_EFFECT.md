# Actor 6FFCA0 timed effect and inactive states

Static File #1 US research, 2026-11-04. Thirteen complete original bodies
reviewed, including two separate empty primary entries and the small no-store
link observer. Addresses/offsets hex unless marked decimal. No execution,
attachment, build or engine changes. Original actor/effect identity unknown.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6FFCA0](../recomp/config/output_ovl/o2/o2_006FFCA0_0x6ffca0.cpp) | `tick_actor_6ffca0_saved_pose_primary_state_and_event_candidate` | High mechanics; probable role | Saves currentXYZ38..40to44..4C androtation90/92/94/96toA0/A2/A4/A6;54A=10,C82/C360;5A9EF0(actor,actor24),C29=BA3. Callsunchecked73CBA0[8]. TailC94|20B,54A|25,BA5=1,32FF,5A6B20(actor,signedC36). Tailflagsapplyevenwhenprimaryhandlerchangedthem;noidentity/hotspotclaim. |
| [o2 0x6FFD70](../recomp/config/output_ovl/o2/o2_006FFD70_0x6ffd70.cpp) | `initialize_actor_6ffca0_room_admitted_state_and_shape_defaults_candidate` | High mechanics; probable role | Buildsmatrix50fromrotation;byte1=0,F0float1,C800,520=-1,C2E0,C9A/BFF,190=20FFFF,194/1A8=0,1D8=72F8B0;clears four bytes at BE8 and eight bytes at C..13. Resourcebyte74F272+60*B98differentfrom3243DC ->8/9=5/1,A/B0;matchingroom+C2Bnonzero ->5/C2B,A/B0. Otherwise1/0,A/B0,700160,C36=1. Doesnotclearwholeactorrecord. |
| [o2 0x6FFEA0](../recomp/config/output_ovl/o2/o2_006FFEA0_0x6ffea0.cpp) | `dispatch_actor_6ffca0_primary_one_wait_secondary_candidate` | High routing | Uncheckedtaildispatch73CBB8[actor9]. Ownedslot0=6FFEC0,slot1zero;observedcontentsare nota newrangeguard. |
| [o2 0x6FFEC0](../recomp/config/output_ovl/o2/o2_006FFEC0_0x6ffec0.cpp) | `tick_actor_6ffca0_wait_timer_then_enter_primary_two_candidate` | High mechanics | Predecrements signedhalfE;post<=0 calls7000F0(actor,2,0). Post>0returnswithouttransition. |
| [o2 0x6FFF00](../recomp/config/output_ovl/o2/o2_006FFF00_0x6fff00.cpp) | `dispatch_actor_6ffca0_primary_two_effect_sequence_candidate` | High routing | Uncheckedtaildispatch73CBC0[9];ownedslot0=6FFF20,slot1zero. Noanimationtickinginwrapper. |
| [o2 0x6FFF20](../recomp/config/output_ovl/o2/o2_006FFF20_0x6fff20.cpp) | `tick_actor_6ffca0_effect_sound_and_collision_descriptor_sequence_candidate` | High mechanics; probable role | A0->1,E90decimal,C10,5E0070(matrix50,zeroXYZ),6B2760(actor,XYZ),randomlowbitpositional1B8A10(XYZ,18/19). A1predecrementsEclamped0;predecrementsC,post<=0->A2,B1E0,clears115bit1,5DA2C0(actor,6F,1). A2predecrementsE;post<=0sets115bit1and7000F0(actor,1,0). Otherphasesreturn;timerspercall,notglobalupdates. |
| [o2 0x700080](../recomp/config/output_ovl/o2/o2_00700080_0x700080.cpp) | `actor_6ffca0_primary_three_noop` | High narrow mechanics | OriginalbodyjrraandNOPonly. Nooutputregisterassignmentorstatewrite;functionidentityanddispatchslotretained. |
| [o2 0x700090](../recomp/config/output_ovl/o2/o2_00700090_0x700090.cpp) | `actor_6ffca0_primary_four_noop` | High narrow mechanics | DistinctoriginalentryjrraandNOPonly. Noinventedrender/physicsaction. |
| [o2 0x7000A0](../recomp/config/output_ovl/o2/o2_007000A0_0x7000a0.cpp) | `dispatch_actor_6ffca0_primary_five_inactive_secondary_candidate` | High routing | Uncheckedtaildispatch73CBC8[9],bothownedslots7000C0. Noindependentvalidation. |
| [o2 0x7000C0](../recomp/config/output_ovl/o2/o2_007000C0_0x7000c0.cpp) | `set_actor_6ffca0_inactive_status_fields_candidate` | High mechanics; probable role | Byte1=0,54A=5,BA5=1,32FF,C94|9. Doesnotdeleteactororcallresourcecleanup;callerupdatetailcanORadditionalflagsafterward. |
| [o2 0x7000F0](../recomp/config/output_ovl/o2/o2_007000F0_0x7000f0.cpp) | `save_actor_6ffca0_prior_state_and_reset_new_pair_candidate` | High mechanics | Copies8/9toBE8/BE9;storesa1/a2lowbytesasnew8/9,clearsA/B;700160seedswaittimersandcalls140;C36=1. Noautomaticrestorationofsavedpairinthisbody. |
| [o2 0x700140](../recomp/config/output_ovl/o2/o2_00700140_0x700140.cpp) | `observe_actor_6ffca0_link_and_phase_without_state_change` | High narrow mechanics; output contract unknown | Loadsactor24intov1;ifnonzeroalsoactorAintov1;returnswithoutwritingv0ormemory. Noportablebooleanqueryreturncanbeinferredfromthisentry. |
| [o2 0x700160](../recomp/config/output_ovl/o2/o2_00700160_0x700160.cpp) | `seed_actor_6ffca0_wait_timer_for_primary_one_secondary_zero_candidate` | High mechanics; probable role | ClearsC/E. Only8/9=1/0seedsE:byteBACnonzero ->10*BAC,else240decimal/74F200. Allpaths tailjump700140. Nootherstatepairtimerorindependentfactorzeroguard. |

Owned primary table73CBA0 contains6FFD70,6FFEA0,6FFF00,700080,700090,
7000A0.73CBB8 and73CBC0 each containonefunctionpointerfollowedbyzero;
73CBC8 containstwo7000C0pointers. Tableownershipandboundswerekept
separatefromadjacenttablecontents.

The update performs no58C300 call itself. The effect sequence advances
throughexplicitcallcounttimersandresource/helpercalls;itmustnotbe
labelledagenericactoranimationtickororiginalglobalgameupdate. No
measuredrootcauseoroptimizationclaimfollowsfromthesestaticcontracts.
