# Actor route score reset, timer and relocation descriptor utilities

Static File #1 US research, 2026-11-04. Three complete original bodies reviewed.
Addresses/offsets/constantshex; explicit rowdata decimal. No target execution.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6344C0](../recomp/config/output_ovl/o2/o2_006344C0_0x6344c0.cpp) | `lookup_record_relocation_descriptor_by_two_keys_and_slot_candidate` | High mechanics; probable role | a0/a1low16keys,a2low16slot;tablebaseword32446C,8-byteheaders. Matchingbyte0/byte1returnsbase+headerhalf4+14*slot;nofullmatchreturns0. LiteralinitialsentinelFFisoverwrittenwith0atbranchdelay634520oneachtest;subsequentheaderscomparebyte0against0. Nobounds/sizechecks. Datapopulation/callercontractunknown,notaclaimofincorrectsentinel. |
| [o2 0x6349C0](../recomp/config/output_ovl/o2/o2_006349C0_0x6349c0.cpp) | `sample_factor_scaled_actor_timer_from_eight_value_row_candidate` | High mechanics; probable role | Randomlow16&7selectssignedhalf72BB80+10*(a0&FF)+2*choice;dividesbyunsignedbyte74F200,narrowssigned16,exactzero->1. Negativeresultsretained. No rowbounds/factorzeroguard. Ownedfirstfourrowsall[1,2,2,3,3,3,4,4];noarbitrarytotalrowcountassigned. |
| [o2 0x6367C0](../recomp/config/output_ovl/o2/o2_006367C0_0x6367c0.cpp) | `clear_actor_two_by_ten_route_score_halves_and_hold_timer_candidate` | High mechanics; probable role | ZerosBF8+14*row+2*column,row0/1,column0..9;zerosC30inreturndelayslot. FortycontiguousbytesBF8..C1FplusseparateC30. DoesnotclearC32/C25/C26/24orrelatedtargetpointer. |

6344C0'sinitialbranch6344D4->634514and634520delayslotwereexplicitly
reviewed;nosentinelnormalizationorenginechange. Actual32446Ctablecontentis
unknown,so this note does not assert a hang, bad lookup or slowdown.
Ownedtimerrowbytesverifiedino2;factor/runtimeheaderswerenotreadlive.
Related [actor6Crelocation](SYMBOLS_ACTOR_6C_RELOCATION_RESUME.md).
