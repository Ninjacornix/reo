# Actor initial and alternate authority category banks

Static File #1 US research, 2026-11-04. Ten complete original bodies reviewed. Addresses/offsets/selectors hexadecimal; probe quantities explicitly decimal. No execution, attachment, build, replay or engine changes. Category/default terminology follows dispatch structure and doesnotclaimoriginalenemyenum names.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6A8DA0](../recomp/config/output_ovl/o2/o2_006A8DA0_0x6a8da0.cpp) | `save_actor_prior_state_then_route_initial_authority_bank_candidate` | High mechanics; control role probable | Alwayssave8/9->BE8/BE9,clearA/Bbefore640640. Authorityfalse category6 ->1/18,9 ->1/19,other1/0,then6AA530. Truecalls719820[category4],passingactor;no localcategory/nullguard. No explicitC36callinfalsebranch. |
| [o2 0x6A8E60](../recomp/config/output_ovl/o2/o2_006A8E60_0x6a8e60.cpp) | `choose_actor_probe_or_random_incline_initial_state_candidate` | High mechanics; control role probable | Probe6175E0(actor,XYZ(0,110,120),yaw92,&output40,&output30). Result1 ->6AA3C0(actor,1,12). Other ->randomlow16oddchoice0;evenD45signed1choice2,-1choice3,otherchoice1. WriteslowbyteBA0=choice,8=1,9=choice,then6AA530+6AC640(0). Upper24bitsBA0retained;phaseA/Bnotresetbythisbody. |
| [o2 0x6A8F60](../recomp/config/output_ovl/o2/o2_006A8F60_0x6a8f60.cpp) | `choose_actor_random_incline_initial_state_without_surface_probe_candidate` | High mechanics; control role probable | Randomlow16oddchoice0;evenD45signed1choice2,-1choice3,otherchoice1. WritesonlylowbyteBA0and8=1/9=choice;6AA530then6AC640(0). No previous-state orphase reset,unlikeowner6A8DA0. |
| [o2 0x6A9000](../recomp/config/output_ovl/o2/o2_006A9000_0x6a9000.cpp) | `choose_actor_initial_substate_from_nonzero_d60_candidate` | High mechanics; control role probable | SignedhalfD60nonzerochoice1,zerochoiceA. WriteslowbyteBA0,8=1,9=choice;6AA530+6AC640(0). No phase reset orD60rangevalidation. |
| [o2 0x6A9060](../recomp/config/output_ovl/o2/o2_006A9060_0x6a9060.cpp) | `choose_actor_initial_substate_from_home_circle_admission_candidate` | High mechanics; control role probable | Circle7193E0+8*unsignedBA7,signedX0/Z4/radius6. ActualXZdistance>signedradius ->choice14,else0. WriteslowbyteBA0,primary1/subchoice,6AA530+6AC640(0). NoBA7/circlecountadmission, Yunused. |
| [o2 0x6A9140](../recomp/config/output_ovl/o2/o2_006A9140_0x6a9140.cpp) | `choose_actor_probe_or_random_incline_state_with_substate_a_default_candidate` | High mechanics; control role probable | Sameprobe(0,110,120)atyaw92;result1 ->6AA3C0(1,12). Elseoddchoice0;evenD45signed1 ->2,-1 ->3,otherA. LowbyteBA0,8=1,9=choice;6AA530+6AC640(0). Differsfrom6A8E60default1. |
| [o2 0x6A9230](../recomp/config/output_ovl/o2/o2_006A9230_0x6a9230.cpp) | `choose_actor_initial_substate_nineteen_or_one_a_by_random_low_bit_candidate` | High mechanics; control role probable | Randomlow16oddchoice19,even1A. WriteslowbyteBA0,8=1,9=choice;6AA530+6AC640(0). No phase/previous-state reset. |
| [o2 0x6A92A0](../recomp/config/output_ovl/o2/o2_006A92A0_0x6a92a0.cpp) | `choose_actor_probe_or_b9a_dependent_random_initial_state_candidate` | High mechanics; control role probable | Probe(0,110,120)/yaw92,result1 ->6AA3C0(1,12). ElseB9Anonzero:randomodd0/even20. B9A0:randomoddD45{1->2,-1->3,other1},even0. LowbyteBA0,primary1/subchoice;6AA530+6AC640(0). B9Areadaswholeunsignedbyte. |
| [o2 0x6A93C0](../recomp/config/output_ovl/o2/o2_006A93C0_0x6a93c0.cpp) | `route_actor_authority_to_alternate_control_bank_or_local_default_candidate` | High mechanics; control role probable | 640640falseonly:saveprior8/9,clearA/B,category6 ->1/18,9 ->1/19,other1/0,6AA530. Truecalls719850[category4]passingactorwithoutpre-reset. No category/nullhandlerguard. Differsfrom6A8DA0unconditionalpre-resetand719820bank. |
| [o2 0x6A9480](../recomp/config/output_ovl/o2/o2_006A9480_0x6a9480.cpp) | `enter_actor_primary_one_substate_four_adapter_candidate` | High mechanics; control role probable | Tail6AA3C0(originalactor,1,4). Inheritsprior-state save,counterinitializationandC36publication;noadditionaladmission. |

The lowbytewriteatBA0doesnotclear thefull32-bitBA0flagsword;upperbitsremain. Thatchoicebyteiscopiedintosubstate9before6AA530. ThehelpersdonotallclearA/BorBE8/BE9;onlytheircallingentrymaydosothereforeinputstateownershipmustremainexplicit.

Allnonnulltargetsinthefollowingphysicaltablesareclosed,includingexisting [category control](SYMBOLS_ACTOR_AUTHORITY_CATEGORY_CONTROL.md)and[target regions](SYMBOLS_ACTOR_TARGET_REGIONS_CONTACT_ROUTING.md). SlotBnullandcategoryrangeadmissionremainunknown;thereisnofunction-localboundscheck.

| Category4 | Initial719820 target | Alternate719850 target | Target-oriented719880 target |
| --- | --- | --- | --- |
| 0 | 6A8E60 | 6A9550 | 6A9550 |
| 1 | 6A9780 | 6A9780 | 6A9780 |
| 2 | 6A9AB0 | 6A9AB0 | 6A9AB0 |
| 3 | 6A8F40 | 6A8F40 | 6A8F40 |
| 4 | 6A8F60 | 6A9480 | 6A9C80 |
| 5 | 6A9000 | 6A9DC0 | 6A9DC0 |
| 6 | 6A9EE0 | 6A9EE0 | 6A9EE0 |
| 7 | 6A9060 | 6A9F80 | 6A9F80 |
| 8 | 6A9140 | 6A9550 | 6A9550 |
| 9 | 6A9230 | 6AA130 | 6AA130 |
| A | 6A92A0 | 6A9550 | 6A9550 |
| B | 0 | 0 | 0 |

Owned719820..71984F12wordSHA256 `b881a1670d03301060767642d494067a5c0dc2b6045c6c469f43dc591a1a9c25`;719850..71987F SHA256 `138a62c1f3397fd1e1c452777a40f52518a43fc3e36331de056c5389213c557e`.719880..7198AFhashisin [authority response helpers](SYMBOLS_ACTOR_RESPONSE_TIMERS_AUTHORITY.md). Owned o2 base570000/SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.

Thesearethreephysicaldispatchbankswith repeatedtargets,not36newfunctions. Thetablesestablishconnection,not invocationfrequencyororiginalenum meaning. Probe6175E0return1isrecordedasanadmissionvaluewithoutinventingasurface/climbtypename. Thehomecircleandwaypointselectorvalidrangesremaincallers/assetquestions. [Boundedmotionsequences](SYMBOLS_ACTOR_BOUNDED_MOTION_SEQUENCES.md)calltheinitialreset;[state initialization](SYMBOLS_ACTOR_ACTION_STATE_INITIALIZATION.md)definescountereffects.

Full-body owned-word audit: 10 rows, 407 verified instruction words, zero conflicts, 17 omitted zero/NOP words, zero omitted nonzero words.
