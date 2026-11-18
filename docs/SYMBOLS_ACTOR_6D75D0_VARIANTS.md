# Actor 6D75D0 four-variant response family

Static File #1 US research, 2026-11-04. Sixteen full original bodies reviewed;
all five variant dispatch tables and primary table checked in owned bytes.
Addresses/offsets are hexadecimal; explicit counts decimal. No game/build/replay,
attachment or live-memory inspection. Object identity, original state names and
animation enums remain unknown. Effect/response roles are candidates grounded
in descriptor, lifetime, health and model-table operations.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6D75D0](../recomp/config/output_ovl/o2/o2_006D75D0_0x6d75d0.cpp) | `update_actor_6d75d0_response_state_dispatch_candidate` | Probable role; full body reviewed | Sets54A=13,BA5=1; unsignedstate8 indexes7328C0 fourtargets7660/78A0/7A20/7F00 withoutlocalrangeguard. Aftercallback, missing1A8 or signed544<=0 sets54Abit4, then6347D0(actor). Initclampsvariant4,notthisstateindex. |
| [o2 0x6D7660](../recomp/config/output_ovl/o2/o2_006D7660_0x6d7660.cpp) | `initialize_actor_6d75d0_transform_descriptors_and_variant_candidate` | Probable role; full body reviewed | Initializesmatrix50,rotates90/92/94,translatesrootXYZ;byte32=FF,C94\|1707,snapshotsXYZ44/48/4C andfouranglehalvesA0..A6. Clears551/552,BE8[4bytes],C[8bytes]. Clampsunsignedvariant4>=3 to3;7328D0 variantinitcall. Sets1A8 from732958[BAF],1D8from7329E8[BAE], noindexchecks. Signed544>0 choosesstate8=1 else3;clears9/A/B. |
| [o2 0x6D77D0](../recomp/config/output_ovl/o2/o2_006D77D0_0x6d77d0.cpp) | `initialize_actor_6d75d0_variant_zero_interval_candidate` | Probable role; full body reviewed | Setsstate1=1,553=0. Globalunsigned4BAE8A0/1/2/3 storesBAC=3C/3C/5A/78 respectively;otherglobalvaluesleaveBACunchanged. Exactnumericdifficulty/modeidentityunassigned. |
| [o2 0x6D7840](../recomp/config/output_ovl/o2/o2_006D7840_0x6d7840.cpp) | `initialize_actor_6d75d0_variant_one_resource_pair_candidate` | Probable role; full body reviewed | state1=0,553=0,BB5=2D,BB0=BB1=FF. No actualresourcequeryyet. |
| [o2 0x6D7860](../recomp/config/output_ovl/o2/o2_006D7860_0x6d7860.cpp) | `initialize_actor_6d75d0_variant_two_flag_id_candidate` | Probable role; full body reviewed | state1=1,553=0,BB5=2C. DoesnotclearBB0/BB1. |
| [o2 0x6D7880](../recomp/config/output_ovl/o2/o2_006D7880_0x6d7880.cpp) | `initialize_actor_6d75d0_variant_three_disabled_fields_candidate` | Probable role; full body reviewed | Clearsstate1,553,BAC/BAF/BAE/BAD and544. Descriptorlookupsin7660thereforeuseindex0afterthiscallback. |
| [o2 0x6D78A0](../recomp/config/output_ovl/o2/o2_006D78A0_0x6d78a0.cpp) | `tick_actor_6d75d0_active_variant_and_health_response_candidate` | Probable role; full body reviewed | byte32=0; variant4 indexes7328E0 activehandler. Ifbyte13Fnonzero,7328F0 secondaryhandler. Signed544<=0 thenstate8=2,clears9/A/B. Tables:active[80E0,7930,80E0,80E0],secondary[79C0,79C0,79C0,80E0]. No branchon13Fmeaningguessed. |
| [o2 0x6D7930](../recomp/config/output_ovl/o2/o2_006D7930_0x6d7930.cpp) | `tick_actor_6d75d0_active_resource_pair_visibility_candidate` | Probable role; full body reviewed | OnA==0 setsA=1,resolves581830(0/1) toBB0/BB1. Eachcallnon-FFBB0setsbyte49F790[id]=1;non-FFBB1sets0. Theseareindexedresourcebytes,notprovenactoractiveflags; nopointerownershipinference. |
| [o2 0x6D79C0](../recomp/config/output_ovl/o2/o2_006D79C0_0x6d79c0.cpp) | `admit_actor_6d75d0_resource_flag10_terminal_response_candidate` | Probable role; full body reviewed | Requiresword138>0, unsigned142<3F andword[719A60+44*142]bit10. Then544=0 and5A6B20(actor,8). Othersreturn. Singleboundedtablelookup, no allocationhere. |
| [o2 0x6D7A20](../recomp/config/output_ovl/o2/o2_006D7A20_0x6d7a20.cpp) | `dispatch_actor_6d75d0_response_and_tick_variant_zero_candidate` | Probable role; full body reviewed | Setsbyte32=FF;732900 variants[internal7A50,7B90,7D70,80E0]. Internal7A50 fullbodyincludedunderthiscatalogowner. Aphase0 setsA=1,544=0,state1=1;effect5DE3E0(root+(0,-35,0),mode0,scale1). BAD>0 clears115bit1,5DA2C0(actor,BAD,1),E=byte714711+20*BAD;nonzero3243CChalvesE,trunctowardzero. BAD0 E=0. Phase1predecrements signedE;negativechoosesstate8=3,clears9/A/B,sets115bit1. No blocking countdownloop. |
| [o2 0x6D7B90](../recomp/config/output_ovl/o2/o2_006D7B90_0x6d7b90.cpp) | `tick_actor_6d75d0_variant_one_response_and_resource_pair_flip_candidate` | Probable role; full body reviewed | Aphase0 setsA=1,544=0,state1=0;5DE3E0(root+(200,50,-50),mode1,scale2) and6B25B0(position). BADresponse/timeras7A50. NonzeroBB5checks4B9C00bitsetand5703E0(BB5,1)ifclear. ResolvesBB0/BB1through581830(0/1). Phase1decrementsE;negativechoosesstate3,clears9/A/B,sets115bit1. Everypathfinallynon-FFBB0sets49F790[id]=0,BB1sets1. Distinctfrom7930reverseassignments. |
| [o2 0x6D7D70](../recomp/config/output_ovl/o2/o2_006D7D70_0x6d7d70.cpp) | `tick_actor_6d75d0_variant_two_response_and_event_flag_candidate` | Probable role; full body reviewed | Aphase0 setsA=1,544=0,state1=0;5DE3E0(root+(0,100,-150),mode1,scale2),6B25B0(position),sameBADresponse/timer. NonzeroBB5notyetsetin4B9C00 calls5703E0(BB5,1). Phase1predecrementsE;negativechoosesstate3,clears9/A/B,sets115bit1. Unlike7B90 noBB0/BB1resourcequeriesorassignments. |
| [o2 0x6D7F00](../recomp/config/output_ovl/o2/o2_006D7F00_0x6d7f00.cpp) | `dispatch_actor_6d75d0_recovery_and_tick_variant_zero_candidate` | Probable role; full body reviewed | byte32=FF;732910 variants[internal7F30,8010,80B0,80E0]. Internal7F30includedunderthisowner. Aphase0 setsA=1,state1=1,544=0;BAC>0 E=BAC*(3243CC?30:60),elseA=2. Phase1decrementsE;negativecopies546->544,calls5A6B20(actor,8). If544>0 choosesstate8=1,clears9/A/B. Timerunitisguestinvocationshere, notwallclockseconds. |
| [o2 0x6D8010](../recomp/config/output_ovl/o2/o2_006D8010_0x6d8010.cpp) | `tick_actor_6d75d0_variant_one_terminal_resource_pair_candidate` | Probable role; full body reviewed | A==0 setsA=1,state1=0,544=0,resolves581830(0/1) toBB0/BB1. Everycallnon-FFBB0sets49F790[id]=0,BB1sets1; no responseeffectortimer. |
| [o2 0x6D80B0](../recomp/config/output_ovl/o2/o2_006D80B0_0x6d80b0.cpp) | `tick_actor_6d75d0_variant_two_terminal_once_candidate` | Probable role; full body reviewed | A==0 incrementsA,clearsstate1and544. Subsequentcallsreturnunchanged. Noresources,emissionorcountdown. |
| [o2 0x6D80E0](../recomp/config/output_ovl/o2/o2_006D80E0_0x6d80e0.cpp) | `actor_6d75d0_variant_callback_original_noop` | High; original words verified | Originaljrra pluszero/NOPdelayslot. Sharedbyallfourvarianttables;onlyonecatalogrowcounted. |

Primary7328C0 isinit/active/response/recovery by observed operations, not guessed
original enum spelling. All four variant domains0..3 are closed; init clamps
variant>=3 to3, while later dispatchers rely on that invariant. Internal7A50
and7F30 are not counted as independent functions. Lifetime halving and interval
multipliers are original guest behavior; this mapping makes no speed changes.

Owned o2 SHA-256:45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226.
Original words and omitted-NOP gaps verified against file-backed o2, base570000.
