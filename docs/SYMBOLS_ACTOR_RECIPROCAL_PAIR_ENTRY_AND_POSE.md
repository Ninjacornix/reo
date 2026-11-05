# Reciprocal actor-pair entry and pose composition

Static File #1 US, 2026-11-04. Three complete original o2 bodies reviewed with all branch targets and delay slots. Addresses, fields, states, masks, IDs, and pointer selectors are hexadecimal; float values and stated timer lengths are decimal. No execution, build, attachment, live memory, input, or timing. Cooperative gameplay names and runtime frequencies are not assumed.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x62CC30](../recomp/config/output_ovl/o2/o2_0062CC30_0x62cc30.cpp) | `enter_reciprocal_actor_pair_control_with_alignment_and_dual_motion_candidate` | High mechanics; candidate role | Concrete primary-one secondaryA1 target at712ED4. Resolves partner666AF0, consumes reset, validates later-phase link and selected class1 partner state/health, sets pair BA0 mask80000 and own54A4000. Phases0/1 idle2051 with timeout;2 builds relative target and selects paired descriptors;3 advances both and interpolates ownXYZ/both yaw;4 copies partner height/angles and composes pose correction;5 waits positive partner boundary while applying correction;6 resets paired base descriptors and quarter-turns self;FF enters (1,98,0,0). Complete ordering and table limitations below. |
| [o2 0x6328C0](../recomp/config/output_ovl/o2/o2_006328C0_0x6328c0.cpp) | `compose_related_actor_pair_node0d_pose_correction_from_timer_candidate` | High mechanics; candidate role | Resolves partner without local null guard, zeroes signed16 XYZ-angle triple, caps nonzero signed timerC above60 (clockmode!=0) or120 (clockmode0), then decrements. SelfB99=0/partnerB99=1 composes Z angle cvt(0.5+65536*(360-15/n)/360). SelfB99=1/partnerB99=0 composes Y angle cvt(0.5+65536*(31/n)/360), except partnerclass1/BB4=1D skips. Other combinations with selfscaleB8>=owned1.05 and partnerB8<1.05 use first Z formula. n=current signedC or1 if0; guest CVT.W.S then low16. Calls58C720(self,D,angles); no automatic reset of prior basis. |
| [o2 0x58C720](../recomp/config/output_ovl/o2/o2_0058C720_0x58c720.cpp) | `compose_actor_model_node_basis_from_signed16_angle_triple_candidate` | High mechanics; candidate role | a0 actor,a1 node selector low8,a2 pointer to three signed16 angles. Loads model actor34, node pointer model820+4*selector; tail-calls o0 370220 with signed angles a0/a1/a2 and matrix at node40. This composes existing XYZ basis (including guest turn16 conversion), not an identity rebuild or world-position store. No local model/node/output bounds guards. |

## Entry validation and flag ownership

Owned primary-one table word712ED4 contains62CC30, indexA1 from712C50. This connects the handler's final state98 with the [reciprocal command policy](SYMBOLS_ACTOR_RECIPROCAL_CONTROL_627770.md). The table pointer is static caller evidence, not a claim that the player exercised this state.

62CC30 resolves p=666AF0(self) before prefix54A1C and reset6673C0. Consumed reset takes base cancellation with blend10. If phase>=2 and p is null, it takes base cancellation with blend0. Null partners are permitted in phases0/1, whose paths only use own state. Thus later partner dereferences are guarded by this local phase/link admission; no missing-guard defect is alleged.

For nonnull category1 partner, selected self ID equal to4BADED requires signed partnerFCF in1/2. Failure clears BA0 mask80000 on both, selects own (1,0,0,0), snapshots and sends selector1, then takes normal base cancellation (another snapshot, phase1). Independently partner signed health544==0 clears both flags and base-cancels without that preceding message. Other partner categories bypass these two category1 checks. After admission it ORs own54A4000 and BA080000; phase>=3 also ORs partner BA080000.

Base cancellation clears54F/548 bit0, selects (primary,secondary,phase,B)=(1,0,1,0), snapshots, requests2050/start0/blend as stated, activates banks. Not every cancellation clears both actors' pair flags; preserve each original branch.

## Phase graph

| Phase | Complete local work |
| --- | --- |
|0|Sets phase1, visual54F16/D10=1, snapshots, clears root deltas; timerC=300 for clockmode0 or150 otherwise; flags82, motion2051/start0/blend10, activates banks, falls into phase1.|
|1|Advances own animation at1. Nonzero signed C decrements and returns, including oldC=1 becoming0. OldC=0 clears own BA080000 then normal base cancellation. It does not locally activate phase2; external phase writer/caller is required.|
|2|Sets partner BA080000, own32=120 for clockmode0 or60 otherwise. Locally controlled self with partnercategory0 sends37C060(5,partnerB98,0). Sets own phase3/visual16/D10=1. Computes heading self->partner, builds relative target, saves ownXYZ and both starting yaw, sets partnerB=2 if partnerB9B==2 else3, own timer12=20 for clockmode0 or10 otherwise. Flags82 on both, selects paired descriptors/blend10, clears both root deltas.|
|3|Advances both animations at1 and clears both root deltas. Nonzero signed timer12 decrements first, then curve-interpolates ownXYZ, own yaw and partner yaw; returns even if new timer is0. On a later call with oldtimer0 it sets phase4, timerC=60 for clockmode0 or30 otherwise, snaps ownXYZ and both yaw to targets.|
|4|Sets phase5, copies partnerY and signed angles90/94 into self, then calls6328C0 pose correction.|
|5|Advances both animations at1; partner's signed-byte result>0 increments own phase6 (own result ignored). Clears both root deltas and calls6328C0 even on the advancing call.|
|6|Applies default self descriptor710150 and partner7101A0 with start0/blend0; activates both banks. Self yaw-=4000, sets phaseFF, calls6328C0.|
|FF|Selects own (1,98,0,0) and snapshots. If ownID differs from selected4BADED, additionally reapplies default self710150/start0/blend0, activates own banks, and calls6328C0. Selected actor skips those extra operations.|

Other phase IDs retain the admitted common flag writes, then return. Return registers are not a normalized Boolean protocol.

## Relative target and descriptor evidence

Phase2 heading uses o0 376E70 with its exact zero-deltaX epsilon contract. Owned vector7103A0..7103AB is approximately(-33.21,0,10.11), bytes`0ad704c2000000008fc22141`, SHA256`d3bb35468db5e327544eeae3320cd18e78ae32490a5d74a7615f18422768ffb0`. It rotates by low16(heading-4000) using owned73FFB8 float6.2831854820251465 divided65536, adds partnerXYZ, then explicitly overwrites targetY with partnerY. Partner target yaw is own target heading-4000. Existing [overlay math](SYMBOLS_OVERLAY_MATH.md) and [alignment interpolation](SYMBOLS_ACTOR_ACTIONS.md) define these helpers; no host lerp substitution is inferred.

Owned selector bytes710390..71039B are six U16 values8,6,9,7,7,6; SHA256`ab36aae3721acac60081a954724ec0affdd3ba9c66a55915c3b423f3978c839f`. Own selector reads710390+4*partnerB99+2*bool(partnerBA0&8); partner selector reads710398+2*bool(partnerBA0&8). B99 is not range checked here; the two-row interpretation only covers B99=0/1, not every possible byte value.

Full160-byte owned descriptor window710150..7101EF SHA256`3ac692e5b04516c3f078a688a3fb4a8fb544a3c81ede056570993390d3875ff7`. Ten self entries at710150..71019F all have word0=70010 and paired halfwords4/6 AB,AC,AD,AE,AD,AD,AA,AA,A9,B1. Eight partner entries7101A0..7101DF have word0=70010 and paired halfwords BB,BC,BD,BE,BD,BD,BA,B9. Remaining literal adjacent7101E0/7101E8 have word0=10, halfwords64/21C. No consumer of those last two is claimed in this handler.

## Pose correction and timer arithmetic

6328C0 composes model nodeD's existing basis through58C720 and o0 370220; it does not rebuild an identity or necessarily replace earlier rotations. The selected triple is signed16 X/Y/Z. The first/third policies set Z, the second sets Y; other components remain0. Conversion order is original single-precision arithmetic, guest CVT.W.S, then halfword truncation. Both original zero-timer paths use divisor1: the first retains a0=1 from its partner-B99 comparison; the later paths explicitly select1. Negative nonzero timer values remain signed divisors after decrement, without local lower clamping.

The second policy skips partnercategory1 with halfwordBB4=1D. The scale fallback tests selfB8 not less than owned73FFA8 float1.0499999523162842 and partnerB8 strictly less than that constant. The correction helper has no local null-partner guard, so its direct caller contract matters;62CC30's correction phases are protected by the phase>=2 null check. Other callers, original physical intent, and runtime bone-state invariants are unknown.

Owned o2 base570000 SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. Static pair-state mechanics do not establish a slowdown root cause or a tested optimization.

Full owned-body audit: 708 original words verified; 39 omitted words all zero/NOP. Zero conflicts or omitted nonzero words.
