# Final o2 actor action adapters

Static File #1 US research, 2026-11-04. Three complete original bodies reviewed.
Addresses and offsets are hex unless marked decimal. No target execution or
engine changes; original action identity and player-facing purpose unresolved.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x7082D0](../recomp/config/output_ovl/o2/o2_007082D0_0x7082d0.cpp) | `enter_actor_action_one_substate_e1_and_publish_selector_three_candidate` | High mechanics; probable role | Writes action1/substateE1/phases0/0, calls667370 to save actor XYZ/yaw, then67E230(actor,3). No animation, geometry or rendering work in this adapter. |
| [o2 0x708320](../recomp/config/output_ovl/o2/o2_00708320_0x708320.cpp) | `return_zero_o2_terminal_adapter` | Confirmed/static narrow mechanics | Two-word body returns v0=0 in the jr delay slot. No memory writes or calls; original caller role unknown. |
| [o2 0x708330](../recomp/config/output_ovl/o2/o2_00708330_0x708330.cpp) | `advance_actor_alignment_then_resource_flag_motion_action_candidate` | High mechanics; probable role | ORs54A mask1F and32FF.6673C0 reset request clears54F/548bit1, sets1/0/1/0, saves pose and selects motion2050/frame0/blend decimal10 plus58C7B0. Then phases:0 writes54F43/D101, saves pose, clears root4E4..4EC, takes targetC34/C3C fromABC/AC4 with currentY toC38, yawC4C fromAC8, calls66DD50(actor,0), returns without writing phase. Unknown phases call66DD50 and set A1 on nonzero result. Phase1 enters2,54F43,BA8=1,58C7F0, motion descriptor73DD88/frame0/blend20, then5B5850(resource C7C,0) sets its model high flag. Phase2 advances at BA8 and enters3 only for positive signed-byte result. Phase3 clears that model flag via5B5850(C7C,1), clears54F/548bit1, restores1/0/1/0, saves pose and selects2050/frame0/blend20 plus58C7B0. The reset path proceeds into phase dispatch in the same invocation. |

5B5850's mapped contract is model flag23C bit80000000 on an active resource;
visibility semantics are not proven here.5D50E0 reads descriptor half+6 as
motion code. These three entries close the o2 catalog tail through70852B;
this is a coverage statement for reviewed source, not an executed scenario.

Related [actor actions](SYMBOLS_ACTOR_ACTIONS.md),
[interactions](SYMBOLS_ACTOR_INTERACTIONS.md), and
[animation](SYMBOLS_ANIMATION.md).
