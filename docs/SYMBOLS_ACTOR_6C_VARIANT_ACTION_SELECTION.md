# Actor 6C variant action and contact selection

Static File #1 US research, 2026-11-04. Six complete catalog bodies reviewed,
including merged internal entry6C99D0 in6C9990. Addresses/offsets/states hex;
policy threshold decimal400 and routecomparisonFA retained exactly. Actor identity,
original response enums and runtime frequency unknown. No target execution.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6C9990](../recomp/config/output_ovl/o2/o2_006C9990_0x6c9990.cpp) | `save_actor_6c_state_and_dispatch_variant_default_action_candidate` | High mechanics; probable role | Saves8/9toBE8/BE9,clearsA/B;taildispatch730650[unsigned4]. Twoownedentries merged99D0 and9A80. Merged99D0:BA3=1/2forcesBA0=0;otherwisefirstRNG&1nonzero->0;else secondRNG&3nonzero->1,zero->8. Sets8=1,9=BA0,9F70,C36=1. DistinctRNGcalls retained. |
| [o2 0x6C9A80](../recomp/config/output_ovl/o2/o2_006C9A80_0x6c9a80.cpp) | `choose_actor_6c_primary_one_secondary_e_and_reset_timers_candidate` | High mechanics; probable role | BA0=E,8=1,9=BA0,9F70,C36=1. DoesnotclearA/Bor savestateitself;9990callerdoes. |
| [o2 0x6C9AD0](../recomp/config/output_ovl/o2/o2_006C9AD0_0x6c9ad0.cpp) | `choose_actor_6c_path_action_by_selected_route_value_and_alignment_candidate` | High mechanics; probable role | Requires24nonnull;savesstate. Reads signedhalfBF8+14*C25+2*C26. Value<FA->9990;otherwiseBA0=3ifBA3=1else2,8=1,9=BA0,A/B0,9F70,C36=1. NegativehalvesarebelowFA. No nearesttargetcomputationhere. |
| [o2 0x6C9B90](../recomp/config/output_ovl/o2/o2_006C9B90_0x6c9b90.cpp) | `save_actor_6c_state_and_dispatch_variant_contact_action_candidate` | High mechanics; probable role | Requires24nonnull;saves8/9,clearsA/B,indirect730658[unsigned4](actor). Ownedtwoentries9BF0/9D70. No localindexcheck. |
| [o2 0x6C9BF0](../recomp/config/output_ovl/o2/o2_006C9BF0_0x6c9bf0.cpp) | `select_actor_6c_contact_action_from_route_and_response_policy_candidate` | High mechanics; probable role | Relatedpointer24readwithoutguard. Selectedroutehalf<FA ->1/10. Otherwise5A62D0(actor,10000,18,f12=decimal400). Codes3/4:relatedBA0&2000178orprimary5->1/4;else2/(RNG&1?0:1). Codes1/2/default:priorBE8=1andBE9=4->1/F,else1/4. Allpaths9F70,C36=1. No A/Bclearhere;B90callerprovidesit. |
| [o2 0x6C9D70](../recomp/config/output_ovl/o2/o2_006C9D70_0x6c9d70.cpp) | `select_actor_6c_variant_contact_action_after_peer_policy_gate_candidate` | High mechanics; probable role | 635640(actor,FA)==0->9ED0(actor,1,E). Otherwisecalls5A62D0(actor,10000,18,f12=decimal400)withrelated24. Onlycode4:relatedBA0&2000178orprimary5->1/E;else2/(RNG&1?0:1). Code3 andallothercodes:RNG&3nonzero->1/E,zero->1/F. Then9F70,C36=1. No state-save/phaseclearhere;B90callerdoes. |

Owned730650 two callbacks6C99D0/6C9A80;730658 two6C9BF0/6C9D70.
The physicalcatalog interval9990..9A7B contains both thetaildispatcher andits
merged defaulttarget,reviewed as onecatalogbody. No duplicate rowfor99D0.
Timers/state initialization9F70 is [mapped separately](SYMBOLS_ACTOR_6C_MOTION_CONTROLS.md).
The response helper5A62D0 has [its own policy mapping](SYMBOLS_ACTOR_RESPONSE_RECORD_EVENTS.md);
its numeric codes are not assumed to be original action names. Code3 follows
contact handlingin9BF0 but randomE/Fselectionin9D70;this difference is preserved.
