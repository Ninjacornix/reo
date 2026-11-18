# SPK/SPM resource table binding and SPK pointer lookup

Static File #1 US research, 2026-11-04. Three complete original bodies reviewed.
Addresses/offsets/constantshex. Filename identity comes from reviewedmainloader,
notfromtheseconsumerbodies. No filesloaded,gameexecution or engine changes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6B7350](../recomp/config/output_ovl/o2/o2_006B7350_0x6b7350.cpp) | `bind_actor_or_common_spk_subtables_and_spm_pointer_candidate` | High mechanics; filename identity crosslinked | a0loadeddata,a1mode,a2slot. Mode0 storesdata+word10to74F0CC[slot],data+word14to74F0B8[slot];nonzeromode storesdatato74F0E0[slot]. Unlessslot==4,actorB98at4A67C8+10E0*slot maps74F0F4[B98]=slot. Noallocation,magiccheck,lengthcheckorfilesreadhere. |
| [o2 0x6B73F0](../recomp/config/output_ovl/o2/o2_006B73F0_0x6b73f0.cpp) | `lookup_scene_auxiliary_resource_index_from_rdt_scenario_row_and_room_candidate` | High mechanics; filename identity crosslinked | RDTbaseword324424,word60pointer. Null->-1;elsecounts32-bitoffsetsuntil-1. Count<selectedbyte4B9D15->-1;otherwisebyteatRDTbase+offset[selected]+unsignedroom3243DC. Equalcountisnotrejectedbytheliteralpredicate;tableresidency/validselectionunknown. Nofileaccess. |
| [o2 0x6B7520](../recomp/config/output_ovl/o2/o2_006B7520_0x6b7520.cpp) | `resolve_spk_actor_or_common_relative_record_pointer_candidate` | High mechanics; filename identity crosslinked | a0entityselector,a1recordindex,a2bankselector. Selector8common:a2nonzerochoosesword74F0DC,zero74F0C8. Othersmapslot=74F0F4[a0],a2nonzero74F0CC[slot],zero74F0B8[slot]. Missingtableorzerooffsetentryreturns0. Commonresult=word324438+50000+entryoffset;actorresult=base+6000+12800*slot+entryoffset. No dereferenceof74F0E0SPMtablehere. Noa0/a1/slotboundscheck. |

[Main1D41F0](SYMBOLS_SCENARIO_AUXILIARY_RESOURCE_LOADING.md) readsnamed
SPKfilesandcalls7350mode0,SPMfilesmode1. ItsactorSPKdestinationstride12800
andcommon50000match7520relativebasearithmetic. Slot4isthecommonbank;
selector8inthelookupisadifferentnumericcontract. No originalrecordformat,
audiosampleorfunctionsemanticisclaimedfromfileextensionsalone.

74F0B8/CC/E0arrays,74F0F4map,RDTpointer,selectedindexandresourcebaseare
outsideownedo2filedataandwerenotinspectedlive. Theloader'scachepublication
recordsattemptedrefreshratherthanprovingeverytablevalid. Related
[auxiliaryreset](SYMBOLS_SCENE_AUXILIARY_WORK_POOLS.md).
