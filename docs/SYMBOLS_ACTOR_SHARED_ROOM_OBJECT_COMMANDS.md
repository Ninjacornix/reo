# Shared room-object actor command policies

Static File #1 US, 2026-11-04. Seven complete original o2 bodies connect the related-actor command protocol to room-object selection and shared actor flags. Addresses, IDs, masks, and field offsets are hexadecimal; ordinary float values are decimal. No game execution, build, attachment, live-memory capture, input, or timing was performed. Original action names and runtime admission remain unknown.

[Room-object classifier and signed type parameters](SYMBOLS_ROOM_GRID_OBJECT_INTERACTION.md), [related-ID packing and resolution](SYMBOLS_ACTOR_ACTIONS.md), [snapshot/message helpers](SYMBOLS_DISPATCH.md), [animation selection](SYMBOLS_ANIMATION.md), [session-mode predicate](SYMBOLS_NEIGHBORS.md), and [RNG](SYMBOLS_SESSION_SETTINGS_RNG.md) establish the referenced contracts. Original bodies and native overrides must be considered separately.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x628360](../recomp/config/output_ovl/o2/o2_00628360_0x628360.cpp) | `route_related_actor_release_and_state_ad_request_candidate` | High mechanics; candidate role | Resolves related actor; null selects self (1,AD,FF,0)/snapshot/1. Category 0 polls 64F110 before the AD hold check. Partner primary !=1 or secondary DD/B5/A2 selects self (1,AD,0,0)/snapshot/1. Otherwise self states A3..AB share an F78-mask gate: mask E3F nonzero either serializes C64=2/C65=4/C66=packed partner ID with selector 8, clears C64, and selects own AD; or directly selects partner (1,A2,0,0). Both return 1. No reciprocal-link validation here. |
| [o2 0x628550](../recomp/config/output_ovl/o2/o2_00628550_0x628550.cpp) | `route_room_object_request_count_and_direction_states_candidate` | High mechanics; candidate role | CB0 zero cancels to base motion. Clears B34 if B35 differs from DA7. B34=1 consumes signed object parameters and count+1; out-of-range cancels, admitted count selects (1,AF,0,0)/snapshot/1. B34=2 consumes direction classifier: 0/2/3/4 cancel, 1 selects AF, other results hold. Other B34 decrements nonzero signed C timer and returns 0, or cancels when zero. Detailed cancellation and count bounds below. |
| [o2 0x6289A0](../recomp/config/output_ovl/o2/o2_006289A0_0x6289a0.cpp) | `route_shared_room_object_flag_owner_and_phase3_direction_candidate` | High mechanics; candidate role | CB0 zero cancels to base motion. Scans other actor slots for BA0 mask 04000000 and equal CB0, with exact first-match policy below. If none and phase A=3, direction classifier 0 sets own mask 04000000 and selects B2; 1 selects B0; 2/3/4 select B1; other result holds. All selections primary 1, A/B=0, snapshot, return 1. |
| [o2 0x628D40](../recomp/config/output_ovl/o2/o2_00628D40_0x628d40.cpp) | `arbitrate_shared_room_object_flag_by_lower_actor_id_candidate` | High mechanics; candidate role | CB0 zero cancels. If own BA0 mask 04000000 set, scans other slots for same mask and CB0; any candidate with byte3 less than own byte3 clears own flag. Scan continues. Phase A=3 then selects (1,B4,0,0)/snapshot/1; other phase returns 0 even if arbitration changed the flag. |
| [o2 0x628EA0](../recomp/config/output_ovl/o2/o2_00628EA0_0x628ea0.cpp) | `route_shared_room_object_flag_owner_while_f80_bit1_held_candidate` | High mechanics; candidate role | CB0 zero cancels. F80 bit1 clear selects B1. While held, scans flagged same-CB0 actors with same first-match secondary B2 / visual-state8 policy as 6289A0, without that helper's preliminary direction test. If none, immediately classifies own direction without phase gate: 0 sets flag/selects B2, 1 selects B0, 2/3/4 select B1. All selections snapshot/return1; hold returns0. |
| [o2 0x629180](../recomp/config/output_ovl/o2/o2_00629180_0x629180.cpp) | `sample_phase3_rng_and_emit_request16_or17_candidate` | High mechanics; candidate role | Category0 polls 64F110; handled result returns1. Only phase A=3 advances RNG 1AEC80(1), tests low bit: even increases BB0 by 15 with upper cap100, then calls 570080(16); odd zeros BB0 and calls 570080(17). Returns0 even after float mutation/request. Other phase holds0. Request gameplay meanings unresolved. |
| [o2 0x632FA0](../recomp/config/output_ovl/o2/o2_00632FA0_0x632fa0.cpp) | `count_other_visual_state8_actors_sharing_room_object_id_candidate` | High mechanics; candidate role | a0 actor. Scans 4A5C30 + 10E0*unsigned-byte index while index < unsigned 4BAEA0; skips index equal to self byte3. Counts candidates with byte54F=8 and matching CB0; return and incremented loop index are masked to low8. No activity/BA0 test, null test, or caller-bound proof. Pure field reads; no mutation. |

## Related-actor release protocol

628360 resolves p=666AF0(self) once and checks null before dereferencing it. Its initial null path uses phase FF; later partner-rejection and normal release paths use phase 0. After the category-0 control-request poll, self secondary AD returns 0 before partner state inspection. Unlike the preceding reciprocal helper, this function does not demand 666AF0(p)==self.

The nine-target table 73FDD0..73FDF3 admits self states A3..AB; every entry targets 628498, the common `(F78 & E3F)!=0` path. In session submode 1 or 2 (1B0310==1), it sets C64=2, C65=4, C66=666B70(p), sends selector 8 through 67E230, clears C64, selects own AD, snapshots, and returns 1. Otherwise it directly writes partner primary 1, secondary A2, A/B=0 and returns 1. That direct partner write has no local partner snapshot/message call.

Owned table SHA256: `b546de42ae3db6f50880cb8dbb29938a6890a0bdcf1ae0c1eb64fa474874b63f`.

## Common cancellation and count gate

Cancellation clears byte54F and bit0 of halfword548 (mask FFFE), selects primary/secondary/phase/B=(1,0,1,0), snapshots through 667370, requests motion2050 with start frame0/blend10 through 5D4CF0, activates animation banks through 58C7B0, and returns1. CB0-zero entry cancellation does not clear BBD. Later cancellations in 628550 additionally clear BBD.

628550 first invalidates nonzero B34 when B35 != DA7. For B34=1, it clears B34, requires signed byte result 6B0F70(CB0) <= (low8(632FA0(self))+1), then requires (low8(632FA0(self))+1) <= signed byte result 6B0F20(CB0). It calls the count helper twice, retaining the original call order. Either failed comparison cancels; successful comparison selects AF. For B34=2, it clears B34 and maps signed-byte direction result 1 to AF, 0/2/3/4 to cancellation, and other results to return0. Other B34 values use signed timer C: any nonzero value decrements by one and returns0; zero cancels. No local lower-bound clamp is inserted in this interpretation.

## Shared flag admission and first-match behavior

6289A0 and 628EA0 scan the actor pool at 4A5C30 with stride10E0. They skip an index matching self byte3 and require candidate BA0 mask04000000 and candidate CB0==self CB0. They do not require candidate primary1 or an explicit activity flag. 6289A0 first classifies the object's interaction with self: results1/2/3 immediately select own B1; 0/4/other results inspect the candidate. 628EA0 omits that preliminary classifier.

For the first qualified candidate, secondary B2 is copied into own secondary; otherwise candidate byte54F !=8 selects B1. Candidate byte54F==8 returns0 immediately, without inspecting later candidates or falling through to the own-direction fallback. Selected own states use primary1, phase/B0, snapshot, return1. With no candidate, 6289A0 only runs the own-direction fallback in phase3; 628EA0 runs it regardless of phase after its F80-bit1 gate. Fallback result0 sets BA0 mask04000000 and selects B2; result1 selects B0; 2/3/4 select B1; other results hold.

628D40 uses the same object/mask pool but chooses whether to clear its own flag based on candidate byte3 < self byte3, without early exit. It then selects B4 only in phase3. Thus return0 does not imply that arbitration made no field changes.

Loop counters and count return values are explicitly truncated to eight bits. Bounds come from runtime word4BAEA0 (cached on entry by the read/count helpers, reread each iteration by 628D40). The ordinary pool-size invariant and all runtime writers are outside this pass; no out-of-range iteration or stall is claimed.

## Phase-3 RNG request

629180 calls 570080 with numeric request16 or17 after advancing RNG stream1. The original o2 adapter 570080 forwards a0 to 570140 while fixing a1=2, a2=0, a3=3C, t0=1. The request's gameplay/audio meaning is unresolved here; this is a separate overlay entry from identically addressed functions in o1/o3. BB0 changes in steps of15 on even draws, capped above at100, and resets to0 on odd draws. This function still returns0 afterward. Its category-0 control-request preemption returns1.

Owned image: o2 base570000, SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. All seven bodies and their branch delay slots were reviewed. Runtime input rates, actor population, animation cost, and slowdown responsibility remain unknown.

Full owned-body audit: 925 original instruction words verified; 51 omitted words are zero/NOP. Zero conflicting comments and zero omitted nonzero words.
