# Actor action state entry and parameter initialization

Static File #1 US research, 2026-11-04. Three complete original bodies reviewed against owned o2 words. Addresses/offsets/state selectors hexadecimal; numerical timer formulas below explicitly decimal. No execution, attachment, build, replay or engine changes. Counters are per-call state values; elapsed seconds and global update frequency remain unknown.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6AA3C0](../recomp/config/output_ovl/o2/o2_006AA3C0_0x6aa3c0.cpp) | `save_previous_actor_state_enter_requested_state_and_initialize_parameters_candidate` | High mechanics; initialization role probable | a0 actor,a1 primary,a2 substate. Savesold8/9->BE8/BE9; writesnew8/9,A=B=0; calls6AA530. Uses originalrequestedlow8 primary/substate forC36event:requested2/sub0..2or8 ->6AC640(actor,5);elsepreviousprimary4/previoussub8/A/B ->selector4;previousprimary4other ->3;other ->0.6AA530mayitselfchangecurrent9/A;doesnotreplacepreservedrequestedarguments. |
| [o2 0x6AA4C0](../recomp/config/output_ovl/o2/o2_006AA4C0_0x6aa4c0.cpp) | `randomize_actor_primary_one_substate_d_counter_when_related_and_phase_zero_candidate` | High mechanics; initialization role probable | Requiresnonnullrelated24,phaseA==0,primary8==1,sub9==D. Calls1AEC80(1),writeshalfC=low16random&7. Otherpathsunchanged. Invokedafterbroader6AA530initialization. |
| [o2 0x6AA530](../recomp/config/output_ovl/o2/o2_006AA530_0x6aa530.cpp) | `initialize_actor_state_counters_and_category_response_parameters_candidate` | High mechanics; initialization role probable | AlwayshalfC=E=0. Primary1 uses full substate counter table below,includingdivisionsbyunsigned74F200. Primary2/sub0or1 C=4+(randomlow16&3). Primary4 type6 E=634880(actor,C2A);othercategorycanremapsub0/2->7whenB9Bmask1andhealth<0,orinitializeEfor sub0/2/9 byhealth/634880. Primary3skipstodirect6AA4C0;allotherexitsalso6AA4C0. Noprimary/activity/nulladmission. |

For6AA530 primary8=1, let u=unsignedbyte74F200 and r=low16(1AEC80(1)). A new r is obtained at every random call. C/E are signed halfword storage; formulas show untruncated integer arithmetic before storage. All numeric constants within formula cells decimal. Substate IDs remain hexadecimal.

| Substate9 | halfC | halfE |
| --- | --- | --- |
| 0 or19 | 0 | result634AB0(1) |
| 1 or1A | 0 | (300+r%600)/u |
| 2,3,7,8 | 0 | 2+(r&1) |
| D | 0 initially;6AA4C0mayoverwrite | (2+(r1&1)) OR((r2&7)<<8) |
| 6 | 60/u | 60+30*(r&3) |
| 1C | 180/u | 120+30*(r%5) |
| 4 | r1&7 | 2+(r2&1) |
| A | r1&7 | 90+30*(r2&3) |
| 18 | 0 | 30 |
| 1D | actorhalf9A | 0 |
| 1F | 120/u | (60+60*(r&3))/u |
| 24 | 0 | 120/u |
| Other | 0 | 0 |

There is no local u!=0 check on the divisions. The shared-factor initialization and valid range must be established before interpreting that omission as a fault. The helper neither waits for the timer nor executes a loop for that many updates. These are initialization formulas, not evidence that timer scaling changes game speed or that a slowdown was observed.

Primary2/sub0or1 getsC=4+(r&3),E=0. Otherprimary2substatesretainzeroC/E. Primary4/type4=6 always calls634880(actor,unsignedC2A)->E. Otherprimary4categories:

1. If B9B mask1, signedhealth544<0, andsub9=0or2: phaseA=oldsub/2,sub9=7; E remains0.
2. Otherwise sub0,2,9: health>0 calls634880(actor,C2A)->E; nonpositivehealth setsE=-1.
3. Other substates retainzeroC/E.

The final6AA4C0 runs aftereverypath;its phase0/related/primary1/subDgate maywriteC independently of the table.6AA3C0first saves prior primary/substate and then initializesthe requested state; its C36selector choice uses the saved predecessor and original requested arguments even if6AA530remapscurrent9. Event publications6AC640 are mapped in [action admission](SYMBOLS_ACTOR_ACTION_ADMISSION_TURN.md). Motion wrappers and variant response setters are in [motion and incline helpers](SYMBOLS_ACTOR_MOTION_RESPONSE_INCLINE.md). 634AB0and634880weresubsequentlyfullyreviewedin [response timers](SYMBOLS_ACTOR_RESPONSE_TIMERS_AUTHORITY.md),withfixedrandomtables,difficulty/actorparametersandglobalfactordivision;originalinjury/AIenum namesremainunresolved.

Full-body owned-word audit: 3 rows, 340 verified instruction words, zero conflicts, 32 omitted zero/NOP words, zero omitted nonzero words.
