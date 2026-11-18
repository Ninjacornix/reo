# Actor type1E fixed-pool activation and received-command admission

Static File #1 US,2026-11-04. Four complete original o2 bodies. High-confidence mechanics; activation roles candidates. No target execution/build/attachment/live memory/input/timing. Addresses,IDsandfieldoffsetshexadecimal;explicitcounts/distancesdecimal. Thesecloseconnectedpool/received-commandhelpersfor [actor60BD20](SYMBOLS_ACTOR_60BD20_ROOT_PRIMARY_ONE_CROSSINGS.md),beforethenextactorroot60F710.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x60F530](../recomp/config/output_ovl/o2/o2_0060F530_0x60f530.cpp) | `test_any_type1e_primary_five_record_in_fifty_slot_actor_pool_candidate` | Confirmed mechanics; role probable | Scans50fixedD90Bslotsstarting42EB00;requiresbyte0!=0,byte3==1E,primary8==5. Returns1firstmatch,else0. Doesnotreadactivebyte1orwalklinkedlist. |
| [o2 0x60F5A0](../recomp/config/output_ovl/o2/o2_0060F5A0_0x60f5a0.cpp) | `activate_first_type1e_primary_five_pool_record_at_position_yaw_countdown_candidate` | High mechanics; role probable | a0XYZpointer,a1yaw,a2countdown. Same50slotpredicate;firstmatchC2B=1,XYZ38copyfroma0,yaw92=low16a1,E=low16a2,returns1. No state/timerinitializer,ownershipcheck,runtimepolicy mirrororeventrequest;miss0. |
| [o2 0x60F630](../recomp/config/output_ovl/o2/o2_0060F630_0x60f630.cpp) | `admit_actor_60bd20_received_command_by_state_distance_and_yaw_candidate` | High mechanics; role probable | RequiresCC2==1,CC3<8andfull8-target73FB80tableadmits1..7,rejects0. WritesCB0=CA4-position,CC0=CBE-yawbeforetest. Distance>=500reject0;shorterCCA=0when<=200,else1,andreturns1. CCAretainedonreject. |
| [o2 0x60F6F0](../recomp/config/output_ovl/o2/o2_0060F6F0_0x60f6f0.cpp) | `set_actor_60bd20_primary_one_received_interpolation_secondary_eight` | Confirmed mechanics | Sets8=1,9=8,A/B=0;doesnotsaveBE8/9,reseedtimers,clearCBCorcallanimation. Consumer60CA40performs20tickinterpolation. |

Bothpoolloopsarepretestedbycount<50andadvanceD90everyrejectedslot. Theydonotdependonapointerterminatoranddonotallocateanewrecord. SlotbytesandinputXYZwerenotreadfromliveRAM;42EB00isanoriginalruntimepooladdress,notaclaimofownedfiledata. Byte0aloneadmitsanentryevenwhenbyte1==0;thehiddenprimary5stateusespreciselythatseparateactivebyte.

TheactivationsetterwritesC2BthenXYZ/yaw/E;itdoesnotinvoke60E870,nordoesitsetthematchingruntime74F27Apolicybyte. Thesearestaticallyseparateproducer/consumercontracts,notaprovenmissingnotification:primary5handler60E3B0laterobservesC2Bandcountdowntostartanotherstate. Originalownerandcalleradmissionremainunknown.

Commandadmissionusesorderedfloatlengthcomparison. CC0andCB0arepreparedbeforethe500distancegate,soreject0doesnotmeanactorwasunchanged. CC3switchtable0jumps60F6E0,1..7jump60F678. Theboundedread73FB80..73FB9Fcontains[60F6E0,60F678,60F678,60F678,60F678,60F678,60F678,60F678],SHA256 `0b513ca967311599abc8889d8ea4391c8f1840dd7a8f11695c8dbf081484b16a`. Itisnotthe15-entrypolicyusedbytheprioractor60B520.

Owned o2 base570000 SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. Noexecutionfrequency,livecontrolpacket,slowroomadmission,performancecostorincidentcausewasmeasured.

Owned-word audit:four complete bodies,103 original instruction words verified,11 omitted zero/NOP words,zero conflicts and zero omitted nonzero words.Full8-targetcommandtablehashed.CurrentliveIDs/actualannotations/links/diffclean; no shared index mutation.
