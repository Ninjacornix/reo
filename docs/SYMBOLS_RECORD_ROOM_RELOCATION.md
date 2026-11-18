# Record room relocation selection and position candidates

Static File #1 US research, 2026-11-04. Six complete original bodies reviewed.
Addresses and offsets are hex unless marked decimal. Record R and separate work
record W retain their observed contracts; original subsystem/action names remain
candidates. No game execution, live memory, network sending or engine changes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6CEA50](../recomp/config/output_ovl/o2/o2_006CEA50_0x6cea50.cpp) | `initialize_record_relocation_wait_and_resource_refresh_timers_candidate` | High mechanics; probable role | a1W,a0 ignored. Consumes random-low16%decimal100,subtracts four owned731528 pair weights until negative;W14=selected duration*(3243CC==0?decimal60:30). Sets W16=(3243CC==0?2400:1200),returns0. Owned(duration,weight) decimal(10,20),(20,50),(40,20),(60,10),sum100. No wall-clock timer claim. |
| [o2 0x6CEB20](../recomp/config/output_ovl/o2/o2_006CEB20_0x6ceb20.cpp) | `try_record_room_relocation_from_priority_presence_and_occupancy_candidate` | High mechanics; probable role | a0R,a1W. Signed4BADF8 nonzero or R2E0 returns0. Positive W16 predecrements;expiry calls5D0940(R22) and resets long timer if true. W14 always predecrements;post>0 returns0. Counts other type1B records in74F250 stride60 up to unsigned4BAE8E whose byte4 is enabled in bitset4BAA30 and room22<decimal36. Builds per-room flags from owned731510 candidates passing5D0980 and occupancy<2:bit1 when5B5E80(room,3200) signed-lowbyte>0;participating same-room actor adds bit2 unconditionally via branch delay,plusbit4 when BA0bit2 set. Actor scan bound is signed word4BAEA0 and requires signed-active byte0 and666080(actor,0)==0. Chooses first owned prioritymask731530 with any candidate containing all bits,then random candidate within that group. Seeds weighted W14 before selected-room/current-room and final policy/capacity rechecks.5D05A0(room,priorityIndex) lowbyte gives point index;its following bltz cannot reject unsignedFF.5D08C0 signed-lowbyte point validation still gates. Success5A7A70(R,room,XYZ,point),prioritybit1 resetsW16,prioritybit2 absent setsW14=(3243CC==0?1800:900),returns1. Other paths0. Publishing helper can suppress updates by ownership/mode; this routine does not independently confirm publication. |
| [o2 0x5D05A0](../recomp/config/output_ovl/o2/o2_005D05A0_0x5d05a0.cpp) | `choose_room_position_candidate_nearest_resource_actor_or_random_candidate` | High mechanics; probable role | a0 lowbyte room,a1 signed-lowbyte policy. Null pointarray730400[room] ->FF. Policies0/1 scan256 records3C5630 stride3C,requiring active,owner0,flags18bit1,group1==room,content6==3200;select nearest candidate across all admitted resources. Policy2 scans active actors4A5C30 stride10E0 in same room with BA0bit2;policy3 same room active actors without bit requirement. Both actor scans use signed byte4BAEA0 count. Candidate count is signed byte7303D0[room],strict bestdistance initialized decimal10000;ties keep first,absenceFF. Other policies return random-low16%count maskedFF,without zero-count guard. No occupancy filtering in this helper. |
| [o2 0x5D08C0](../recomp/config/output_ovl/o2/o2_005D08C0_0x5d08c0.cpp) | `copy_room_position_candidate_when_signed_index_in_range_candidate` | High mechanics; probable role | a0XYZout,a1lowbyte room,a2signed-lowbyte index. Negative or index>=signed count7303D0[room] returns0 without write;else copiesXYZ from730400[room]+C*index,returns1. No independent null array or room bounds check after count admission. |
| [o2 0x5D0940](../recomp/config/output_ovl/o2/o2_005D0940_0x5d0940.cpp) | `remove_first_room_unowned_resource_3200_if_nonzero_slot_candidate` | High mechanics; probable role |5B5E80(a0 group,3200) lowbyte0 ->0;nonzero calls5B5DE0(resourceID),returns1. Finder's slot0/no-match ambiguity remains. Removal/finalization effect follows existing resource helper contract. |
| [o2 0x5D0980](../recomp/config/output_ovl/o2/o2_005D0980_0x5d0980.cpp) | `reject_room_1b_or_nonvariant_two_room20_in_mode_zero_candidate` | High mechanics; probable role |1B02D0 false ->0. When true,low16 a1==1B ->1. Otherwise lowbyte a0==2 ->0;remaining variants return1 only a1==20,else0. Numeric IDs and exact comparison widths retained. |

Owned731510 positive room list, in decimal:
2,4,5,6,7,8,9,10,11,12,14,16,22,24,25,26,27,28,30,31,32,then-1.
Owned prioritymask bytes731530 are3,1,6,2,0. Flags are matched by(mask&flags)==mask;
zero therefore serves as final unrestricted priority, not list termination.

All48 countbytes7303D0 and corresponding730400 pointers were checked. Twenty-one
rooms above have34 total XYZ candidates,all pointers within owned file bytes;
remaining counts0. Positive counts by decimalroom:2:1,4:2,5:1,6:1,7:1,8:1,
9:3,10:1,11:2,12:2,14:2,16:1,22:3,24:1,25:2,26:2,27:1,28:3,30:2,31:1,32:1.
Every selected count*12-byte vector interval was read; no runtime table contents
are invented. Original room/player meaning is supported by the mapped R22 and
actor1E2 comparisons but not assigned scenario names here.

The6CF030 adapter is documented in
[adjacent bootstrap notebook](SYMBOLS_ACTOR_6CF0C0_BOOTSTRAP.md),but calls these
record/work queries; its previous actor-pair wording has been corrected.
Related [record publishing](SYMBOLS_RECORD_EVENT_SERIALIZATION.md) and
[resource finder](SYMBOLS_RESOURCE_EFFECTS_AUX_LISTS.md).
