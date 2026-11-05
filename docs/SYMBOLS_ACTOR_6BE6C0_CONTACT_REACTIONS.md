# Actor 6BE6C0 contact reaction admission

Static File #1 US research, 2026-11-04. Two complete original bodies reviewed.
Addresses/offsets/selectors hexadecimal; explicit threshold1000 decimal.
Original reaction names remain unknown. No execution, attachment, build or replay.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6C0C80](../recomp/config/output_ovl/o2/o2_006C0C80_0x6c0c80.cpp) | `apply_actor_contact_event_and_select_primary_reaction_tuple_candidate` | High mechanics; event roles provisional | 637490(self)->event,stores7556E0/11C then dereferences required event pointer. For eventbyte2=0 and1F2 in66/67/70,668870(event) lowbyte0/2 clears13F and returns0. Otherwise6407D0(self,event,3E8) signed8 resultR, dispatches72B820[141](self,13), mirrorshealth into74F26C+60*B98,666D40(event). R=1 entersprimary4/secondary0/AFF/B0,32FF,666D00(event),return0. OtherR normalizes140 via6C0F90,CF4=640190,self and selects tuples below. |
| [o2 0x6C0F90](../recomp/config/output_ovl/o2/o2_006C0F90_0x6c0f90.cpp) | `clear_reaction_selector140_for_motion66_c8_c9_d3_unless_field148_two` | High mechanics | Byte148=2 returns unchanged. Otherwise half1F2 in66/C8/C9/D3 clears140; other motions leave it. Does not assign a return value. |

6C0C80 remaining reaction-selector behavior:

| Byte140 | Complete mutation / result |
| --- | --- |
| 0 | R=2 sets tuple8/9/A/B=(1,6,FF,0),returns1; otherRreturns0. |
| 1 | Half10=8/unsigned74F200,115 bit1 set,tuple(3,1,FF,0). R=2 overrides tuple(1,6,FF,0). Returns1. |
| 2 | Same timer/flag,tuple(3,2,FF,0);R=2 overrides(1,6,FF,0).Returns1. |
| other | Clears9 only, returns1. |

72B820 is an indirect callback table whose valid141 bounds are not checked in
this body. The reviewed dispatch is retained as a numeric dependency; this note
does not claim all possible contact handlers have been interpreted. The required
event pointer and callback index are caller/runtime data contracts, not proven
null safety. Health<=0 behavior comes from actual gates, not an invented event
type enumeration. See [actor callback](SYMBOLS_ACTOR_6BE6C0_CALLBACK.md).

Full-body owned-word audit: 2 rows, 165 verified instruction words,
zero conflicts, 12 omitted zero/NOP words, zero omitted nonzero words.
