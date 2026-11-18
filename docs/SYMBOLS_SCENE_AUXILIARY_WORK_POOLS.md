# Scene auxiliary work pool and actor sequence reset helpers

Static File #1 US research, 2026-11-04. Six complete original bodies reviewed.
Addresses/sizes/offsetshex; countsmarkeddecimal. ThecallingmainSPK/SPMloader
uses7720asreset,butthesebodiescontainnofilenames. No executionorenginechanges.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6B7480](../recomp/config/output_ovl/o2/o2_006B7480_0x6b7480.cpp) | `set_scene_auxiliary_work_bit_by_signed_index_candidate` | High mechanics; probable role | Setsbitinword74E828+4*trunc(a0/32),shiftlow5ofsignedremainder;negativearithmeticretained. No boundscheck/atomicoperation. DoesnotreadSPK/SPMtables. |
| [o2 0x6B74D0](../recomp/config/output_ovl/o2/o2_006B74D0_0x6b74d0.cpp) | `clear_scene_auxiliary_work_bit_by_signed_index_candidate` | High mechanics; probable role | Samewordselectionas7480,ANDcomplementofshifted1. Noallocationorloadercall. |
| [o2 0x6B7610](../recomp/config/output_ovl/o2/o2_006B7610_0x6b7610.cpp) | `clear_scene_auxiliary_work_state_and_reset_actor_sequence_fields_candidate` | High mechanics; probable role | Zeros74E6C0sizeA3C,then7810. Sets32words74E7A4..E820=-1,1000decimal4-byterecords74CD10half(-1,0),74CD00/74CCF80. Forunsignedword4BAEA0actors4A5C30+10E0*i,zerosDB0word,DB4word,DB8word,DBC/DBEhalves,DC0/DC1bytes,DC2half,DC4..DC7bytes. Initialblockclearcovers74F0B8/CC/E0SPK/SPMpointerarraysand74F0F4mapping. |
| [o2 0x6B7720](../recomp/config/output_ovl/o2/o2_006B7720_0x6b7720.cpp) | `reset_scene_auxiliary_work_pools_preserving_primary_state_block_candidate` | High mechanics; probable role | Calls7810,sets32wordslots74E7A4..E820=-1,1000half(-1,0)records74CD10,74CD00/74CCF80;zerosameactorDB0..DC7fieldsetas7610. Omitsinitial74E6C0sizeA3Cclear. No fileloadingorSPK/SPMpointerbinding. |
| [o2 0x6B7810](../recomp/config/output_ovl/o2/o2_006B7810_0x6b7810.cpp) | `zero_scene_auxiliary_sixteen_record_pool_and_two_pointer_banks_candidate` | High mechanics; probable role | Memset74DD40size980and74DD30size2. Zeros2banks16wordseach74DCB0/74DCF0. No activeactoriterationorresourcefileaccess. |
| [o2 0x6B7890](../recomp/config/output_ovl/o2/o2_006B7890_0x6b7890.cpp) | `allocate_first_free_scene_auxiliary_152_byte_record_candidate` | High mechanics; probable role | Scans16decimalrecords74DD40+98*i;firstsignedhalf0zero:setsit1,clearsrecordhalf2,half8,byteD,half60,returnspointer. Full->0. Doesnotzeroentirerecordorclaimheapallocation. Stride98hex=152decimal. |

Sixteen98hexrecordslotsfill980hexbytes;thewordbanksareeach40hexbytes.
Allocationinitializesonlylistedfields. Arrayruntimecontentswerenotread.
The32-wordresetand1000-recordresetloopswerereadfrominitialentrythrough
exitbranch;noinferredpredecrementunderfloworunboundedruntimeclaim.

Theallocationroledoesnotestablishwhatall98bytesmean;7930anditsdownstream
consumersremainconnectedgaps. ActorDB0..DC7fieldidentitiesareunresolved.
See[SPK/SPMtableconsumers](SYMBOLS_SPK_SPM_TABLE_CONSUMERS.md).
