# Roster-triggered direct state handoffs

Static File #1 US owned o2 analysis, 2026-11-05. Three complete original bodies; [identity](FUNCTION_INDEX.md). No game or process accessed. Offsets and IDs hexadecimal; timer numerators and roster stride decimal.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6A59E0](../recomp/config/output_ovl/o2/o2_006A59E0_0x6a59e0.cpp) | `wait_roster_trigger_while_motion_zero_then_direct_state_one_21` | High complete local mechanics | Common54A5,32FF,BA51,C94OR209. A0->1,visible1,clip0/0,activate. A1 tick1; trigger74F27E nonzero setsA2/E=60*74F291/unsigned74F200,without request here. A2 tick1/predecrementE;<=0 calls6AC7D0(actor,0),then writes8=1,9=21,A=B=0 directly,without initializer. Other phases only common flags. |
| [o2 0x6A5B60](../recomp/config/output_ovl/o2/o2_006A5B60_0x6a5b60.cpp) | `hold_motion_33_until_roster_delay_then_direct_state_one_22` | High complete local mechanics | Common54A5,32FF,C94OR209; noBA5write. A0->1,visible1,6AB600(33,0),without activation. A1 tick0; trigger74F27E nonzero setsA2/E=60*74F291/unsigned74F200. A2 tick0/predecrementE;<=0 writes1/22/A=B=0 directly. No6AC7D0 or state initializer anywhere in body. |
| [o2 0x6A5CC0](../recomp/config/output_ovl/o2/o2_006A5CC0_0x6a5cc0.cpp) | `hold_motion_32_until_roster_delay_then_direct_state_one_23` | High complete local mechanics | Complete body separately reviewed. Same local phase policy as6A5B60, but initial6AB600(32,0) and final direct1/23/A=B=0. Common flags, zero-rate animation advancement, lack ofBA5write/request/initializer retained. |

R=74F250+96 decimal*unsignedactorB98; triggerR2E and durationR41 correspond to74F27E/74F291. E is signed halfword after original narrowing; predecrement stores before signed comparison. Divisor is unsigned byte74F200 with no local zero guard. These are per-call phase handlers, not blocking waits. Tick0 is an explicit original rate argument; this mapping does not change original game speed.

[Motion contracts](SYMBOLS_ACTOR_MOTION_RESPONSE_INCLINE.md), [request/state initialization](SYMBOLS_ACTOR_ACTION_ADMISSION_TURN.md), and [related triggered holds](SYMBOLS_O2_ACTOR_696300_ROSTER_TRIGGERED_HOLD_AND_INTERACTION.md) define connected behavior. Narrative meanings of numeric states21..23 remain unknown; no runtime slowdown diagnosis is asserted.
