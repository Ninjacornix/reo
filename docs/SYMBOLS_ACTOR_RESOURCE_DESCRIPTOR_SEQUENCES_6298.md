# Actor resource and descriptor sequences 6298E0..62A878

Static File #1 US, 2026-11-04. Eight complete original o2 bodies reviewed, including delay slots, immediate fallthrough, and animation-result narrowing. Addresses, phase/action IDs, masks, and offsets are hexadecimal; float values and stated timer lengths are decimal. No game execution, build, attachment, live memory, input, or timing. Labels describe observed operations; original action names remain candidates.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6298E0](../recomp/config/output_ovl/o2/o2_006298E0_0x6298e0.cpp) | `align_actor_then_play_descriptor2d3_and_enter_state70_candidate` | High mechanics; candidate role | Every call ORs54A mask1F and sets32=FF; consumed reset immediately cancels to base. Phase0 initializes54F=2B/D10=1, snapshots, clears root deltas, copies ABC/currentY/AC4 and AC8 into alignment target, calls alignment mode1 twice, ignoring first result. Alignment success selects phase1. Phase1 sets phase2, flags82, descriptor70FF80 with blend-10 after motion201B/C, otherwise2. Phase2 frame gate from71BA44+16*AB9+4*B99 can create ABB-bound task mode1; signed-byte animation result exactly1 selects (1,70,0,0), snapshots and saves current XZ/yaw. |
| [o2 0x629B20](../recomp/config/output_ovl/o2/o2_00629B20_0x629b20.cpp) | `play_resource_flagged_descriptor2d5_then_enter_state6d_and_turn_candidate` | High mechanics; candidate role | Every call sets54A1F/32FF/BA0 mask20000000; reset immediately cancels. Phase0 sets54F2B/D10=1, snapshots, increments phase, clears root deltas, calls5B5850(C7C,0), and if locally controlled sends37C060(10,0,0). Falls into phase1: increments phase, flags82, descriptor70FF88/blend20, bank activation, ABB-task mode4. Phase2 exact signed-byte boundary1 selects (1,6D,0,0), snapshots, subtracts8000 yaw, sends selector1, clears root deltas, flags82 and descriptor70FFA8/start0/blend0. |
| [o2 0x629D20](../recomp/config/output_ovl/o2/o2_00629D20_0x629d20.cpp) | `initialize_resource_flag_and_loop_descriptor64_candidate` | High mechanics; candidate role | Every call sets54A1F/BA4 mask40/32FF/BA0 mask20000000 and clears553. Reset sets phase0. Phase0 initializes54F2B/D10=1 and snapshot, increments, clears root deltas, sets C7C model high flag via5B5850(id,0), then falls into phase1. Phase1 increments, flags82, descriptor70FFA8/start0/blend0 and bank activation. Phase2 advances animation at1 and ignores result; unmatched phases only retain top-of-call flag writes. No local completion transition. |
| [o2 0x629E30](../recomp/config/output_ovl/o2/o2_00629E30_0x629e30.cpp) | `play_resource_release_descriptors2d7_26e_then_cleanup_candidate` | High mechanics; candidate role | Every call sets54A1F/BA4 mask40/32FF/BA0 mask20000000; reset restarts phase0. Phase0 common2B init, root clear, sets BA0 mask20000, clears resource high flag5B5850(C7C,1), falls into1. Phase1 flags82/descriptor70FF90 zero blend and ABB-task mode5. Phase2 exact signed-byte boundary1 advances3; phase3 flags82/descriptor70FFB0 zero blend, yaw-8000, enters4. Phase4 exact1 ->FF. FF calls5B9FE0(self), conditionally clears FAA for locally controlled actor, then cancels to base. |
| [o2 0x62A070](../recomp/config/output_ovl/o2/o2_0062A070_0x62a070.cpp) | `play_descriptor2d6_with_bound_task3_and_return_base_candidate` | High mechanics; candidate role | Every call sets54A1F/BA4 mask40/32FF; reset restarts0. Phase0 common2B initialization, snapshot/root clear falls into1. Phase1 increments to2, flags82, descriptor70FF98/blend20, bank activation, ABB-task mode3. Phase2 exact signed-byte boundary1 advances3; phase3 cancels to base. No BA0 mask20000000 set in this body. |
| [o2 0x62A200](../recomp/config/output_ovl/o2/o2_0062A200_0x62a200.cpp) | `snap_saved_target_and_loop_descriptor2d4_candidate` | High mechanics; candidate role | Every call sets54A1F/32FF; reset immediately cancels. Phase0 common2B initialization, snapshot/root clear, writes saved ABC/AC4 into current XZ and AC8 into yaw, falls into1. Phase1 increments, flags82, descriptor70FFA0/blend20 and bank activation. Phase2 advances at1 ignoring result; no local completion exit. Current Y is preserved. |
| [o2 0x62A360](../recomp/config/output_ovl/o2/o2_0062A360_0x62a360.cpp) | `delay_resource_release_then_descriptor348_frame16_effect_and_cleanup_candidate` | High mechanics; candidate role | Every call sets54A1F/BA4 mask40/32FF/BA0 mask20000000; reset restarts0. Phase0 common2B init/root clear, BA0 mask20000, timer C=30 when clock mode0 else15, clears C7C model high flag, local37C060(11,0,0), then falls into phase1. Nonzero signed timer decrements and advances at1; zero sets2/flags82/descriptor70FFB8 zero blend and actor sound event1. Phase2 primary frame not less than40 clears54A bit0; track1 frame16 gate at BA8 clears115 bit0 and calls5DA2C0(self,7A,0). Exact signed-byte boundary1 ->FF; FF clears54A bit0, conditionally FAA, then base cancellation. |
| [o2 0x62A5E0](../recomp/config/output_ovl/o2/o2_0062A5E0_0x62a5e0.cpp) | `align_states71_72_then_select_descriptor365_or368_and_return_base_candidate` | High mechanics; candidate role | Every call sets54A1F/32FF; reset immediately cancels. Phase0 initializes54F2C/D10=1, snapshot/root clear/target from saved transform, calls mode0 alignment once and returns without consuming result. Other unmatched phases call alignment mode0; nonzero sets phase1. Phase1 sets2/flags82; state71 creates5702F0 task ABB/mode0 and selects descriptor70FFC0, state72 creates570270 task ABB/mode0 and selects70FFC8. Blend-10 after201B/C else20. Phase2 exact signed-byte boundary1 ->3; phase3 base cancellation. Other secondary IDs leave local descriptor selector uninitialized in this body; caller admission unresolved. |

## Shared operations and reset differences

Snapshot667370 saves transform; 58C7F0 ORs primary track flags82; 5D50E0 takes an eight-byte motion descriptor, stores its halfword6 into actor520, then applies motion; 58C7B0 activates track banks. Animation58C300 is called at1 in these sequences. Completion tests narrow its return to signed byte and require exactly1, rather than any nonzero result. See [animation contracts](SYMBOLS_ANIMATION.md).

Base cancellation clears54F and halfword548 bit0, sets (primary,secondary,phase,B)=(1,0,1,0), snapshots, selects motion2050/start0/blend10, activates banks. It does not locally clear every earlier BA0/BA4 flag. Reset6673C0 immediately takes this cancellation in 6298E0/629B20/62A200/62A5E0; in 629D20/629E30/62A070/62A360 it instead clears phaseA and continues initialization in the same call. The top-of-call flags are written before the reset test.

Phase0 normally falls into phase1 after incrementing, so initialization and motion selection may occur together. Exceptions are the two alignment actions. 6298E0 phase0 calls66DD50(mode1) once while writing C4C from AC8, ignores that result, then calls it again and tests the second result. 62A5E0 phase0 calls66DD50(mode0) once and returns; subsequent alignment calls consume the result. Neither calls these alignment hooks once per global game update by contract. Alignment semantics remain in [actor actions](SYMBOLS_ACTOR_ACTIONS.md).

## Complete fixed descriptor window

All ten eight-byte records at70FF80..70FFCF have word0=10 and halfwords4/6 equal as follows. This window includes both literal targets of the 71/72 pair; it is not a guessed dynamically indexed asset table.

| Address | Halfwords4/6 |
| --- | --- |
|70FF80|2D3 / 2D3|
|70FF88|2D5 / 2D5|
|70FF90|2D7 / 2D7|
|70FF98|2D6 / 2D6|
|70FFA0|2D4 / 2D4|
|70FFA8|64 / 64|
|70FFB0|26E / 26E|
|70FFB8|348 / 348|
|70FFC0|365 / 365|
|70FFC8|368 / 368|

Full80-byte window SHA256 `1d67bb94288e05a29115339a185ce84222472f088eea7bfef1ef7895ac24b16e`.

6298E0's frame-gate address is71BA44 +16*AB9 +4*B99, not the fixed descriptor window. No local AB9/B99 bounds are imposed. A verified owned256-byte slice71BA40..71BB3F has hash `275dc54411bc0c0e54fa2b4bee71e2bd4fc480742ed86e764f1238133f61bd05`; this establishes bytes for those sixteen rows only, not the full admitted domain. Each row starts with a motion word and three floats; row1/2 third float80, rowF third float60, others in this slice0. The present reader starts at row+4. External caller/category domains remain unknown.

## Resource, task, and cleanup boundaries

5B5850(C7C,0) sets active resource model23C mask80000000; selector1 clears it. The helper gates inactive IDs and null model pointers. Its exact rendering/visibility meaning remains unproved; see [resource consumption](SYMBOLS_INVENTORY_CONSUMPTION_QUERIES.md). These actions do not replace or allocate that model themselves.

570270 creates a category0 actor-bound callback task and receives actor ABB as resource ID; modes1/3/4/5/0 are retained literally, not presumed resource enums. 62A5E0 state71 instead invokes5702F0 with the same ABB/mode0 arguments. State72 initializes local descriptor selector1, state71 selector0; neither branch initializes that selector for any other secondary. Runtime admission through the larger state dispatch must establish whether another value reaches this body. This is not a reproduced uninitialized-value failure or slowdown cause. See [callback tasks and frame gates](SYMBOLS_TASK_FLAGS.md).

629B20 locally controlled admission1B0340(self)==1 sends37C060(10,0,0); 62A360 sends37C060(11,0,0). Numeric requests are preserved without guessing the original event names. 62A360's1B8BB0(self,1) is the class-zero actor sound request in [sound routing](SYMBOLS_ACTOR_SOUND_REQUEST_ROUTING.md). Its track1 frame16 crossing is distinct from its primary animation frame40 flag clear. The two operations use separate fields and gates.

629E30 phaseFF calls5B9FE0 before its local check and base return; exact cleanup semantics are not relabeled here. 62A360 does not call that helper. Both locally controlled paths clear FAA. Function outputs are action-handler return registers, not normalized success/completion booleans, so no caller may assume every state change is accompanied by return1.

Owned o2 base570000 SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. Original asset interpretation, complete AB9/B99 domain, runtime action frequency, and performance cost remain unknown.

Full owned-body audit: 938 original instruction words verified; 52 omitted words are zero/NOP. Zero conflicting comments and zero omitted nonzero words.
