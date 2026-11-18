# Cooperative object motion and completion

Static File #1 US, 2026-11-05. Two complete original o2 bodies reviewed with all loop entry/exit branches and delay slots. Addresses, fields, action IDs, and masks are hexadecimal; float displacement/blend values and participant count formula are decimal. No execution, build, attachment, live memory, input, or timing. Cooperative object movement is a candidate subsystem role supported by same-object actor coordination and object-coordinate stores; original object/action names remain unknown.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x62EF00](../recomp/config/output_ovl/o2/o2_0062EF00_0x62ef00.cpp) | `advance_shared_room_object_by_participant_scaled_root_motion_candidate` | High mechanics; candidate role | Primary-one B2 target712F18. Prefix54A D/32FF; reset clearsBA004000000/base blend10; invalid CB0 object clearsflag/base blend0. Phase0 visual8/D10=1/clears saved transform/root clear falls into1;phase1 sets2 then leader registers direction/selects710200/sends9/sound1B/mutates object offset, follower synchronizes motion/frame/axis from flagged same-object actors. Phase2 advances animation by1+matching other actors; leader accumulates rootZ to50 and sends9 onphase3, follower synchronizes and observes leaderphase/secondary. Phase3 holds. Full side effects, clipping and scan policies below. |
| [o2 0x62F6E0](../recomp/config/output_ovl/o2/o2_0062F6E0_0x62f6e0.cpp) | `finish_shared_room_object_request_then_loop_descriptor21b_candidate` | High mechanics; candidate role | Primary-one B4 target712F20. Prefix54A D/32FF; reset clearsBA004000000/base blend10; invalidobject clearsflag/base blend0. Phase0 visual8/D10=1/clear saved transform/root clear, sets1; only if leaderflag set calls6B05F0(CB0),6B0780(CB0),sends67E230 selector9, then falls into1. Phase1 sets2, yaw=(yaw+2000)&C000, flags82/710208 start0/blend20/banks. Phase2 advances at1 then clears root deltas unconditionally; no local completion exit. |

Both validate runtime object record `3C4580 + 3C*unsigned(CB0)` before phases: active signed byte0!=0, flags24 bit1, pointer28 nonnull. No local index bound. Reset/invalid cancellations clear ownBA004000000, clear54F/548 bit0, select (primary,secondary,phase,B)=(1,0,1,0), snapshot, request2050/start0/blend10 for reset or0 for invalid, activate banks. Runtime record values are not file-backed observations.

Owned primary-one pointers712F18=62EF00 (B2) and712F20=62F6E0 (B4) are checked directly; B3's separate pointer is not mislabeled as this completion body. [Shared-object command policies](SYMBOLS_ACTOR_SHARED_ROOM_OBJECT_COMMANDS.md) route phase3 toB4 and arbitrate the same flag.

## B2 phase1 leader/follower initialization

The leader predicate is ownBA0 mask04000000, not actor ID or activity. Phase0 initializes visual8/D10=1, calls6673A0 to clear saved transform (not snapshot), clears root deltas and falls into1. Phase1 increments2 before choosing its branch.

Leader calls6B0510(CB0,unsignedYaw92), flags82, descriptor710200/start0/blend10, bank activation, copies rootZ4EC into C48, sends67E230 selector9, then requests bank2 sound1B at object record8 with tag6B0FC0(CB0). Cardinal yaw0/4000/8000/C000 updates object pointer28 coordinate208+=Z,200+=Z,208-=Z,200-=Z respectively, where Z is current rootZ4EC. Other yaw values skip these stores. Object helper and sound contracts remain in [room-object interaction](SYMBOLS_ROOM_GRID_OBJECT_INTERACTION.md) and [sound routing](SYMBOLS_SCENARIO_SOUND_REMAP.md).

Follower scans the actor pool in index order for any BA004000000 actor with matching CB0. There is no explicit primary/secondary/activity check or self-index exclusion. For each match, it flags82, applies the same descriptor at the candidate's primary frame1E4 (blend10), activates banks, copies candidate C48, and copies candidate Z for yaw0/8000 or X for4000/C000. It does not break after a match; later matches overwrite earlier choices. Finally it clears all own root deltas.

## B2 phase2 participant scaling and displacement boundary

It first counts other pool entries matching CB0 AND primary8 AND secondary9, skipping index==own byte3. The count does not require visual8, activity, phase equality, or leader flag, and is truncated to eight bits. It advances own animation at float `1 + count`; the original guest unsigned-conversion branches are retained even though the masked count is nonnegative. This is existing cooperative animation scaling, not a proposed speed change or measured slowdown explanation.

Leader then adds current rootZ4EC to C48 and stores the sum. If the ordered test `sum < 50` is false, it reduces rootZ by `sum-50`, increments phase3, and sends selector9. That path returns before the local object-coordinate translation stores; it does not store C48=50. If sum<50, the same cardinal coordinate updates from phase1 execute. Runtime post-handler root-motion application and its effects on the clipped final delta are outside this pass; no movement defect is claimed.

Follower scans flagged same-CB0 actors, again without explicit self/activity admission. It copies the appropriate candidate X/Z axis. If candidate secondary differs from own secondary OR candidate phase differs from own phase, it increments own phase3, clears roots and exits the scan; otherwise continues. End-of-scan also clears roots. It does not locally change own leader flag.

Phase3 and unmatched phases have no animation/translation work after the shared validation. The separate command policy can selectB4. B4's phase0 leader-only operations decay/clear the direction request6B05F0, publish object center6B0780, then notify selector9; it does not simply set the record inactive. Phase2 holds descriptor21B while clearing roots after advancement.

## Original tables, transport and unknowns

Fixed sixteen-byte descriptor window710200..71020F: both word0=10, halfwords4/6 are21A and21B. SHA256`e746f648e7d5e2bf4053d8f4f051359920a92312fe7aa6f073775385c0834fbf`. Animation, snapshot/clear and message selection remain separate [contracts](SYMBOLS_ANIMATION.md). Message calls are original guest operations; no external monitor was started or sampled.

All actor scans use pool4A5C30/stride10E0 and unsigned runtime bound4BAEA0, with eight-bit loop counters. Phase1 synchronization rereads bound per iteration, phase2 counting caches it, phase2 synchronization rereads it. Pool size/domain and leader uniqueness require runtime writers/caller evidence; no oversized count, stale flag, or stall was observed. No global clock, rendering-path, or engine changes were made.

Owned o2 base570000 SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. Runtime frequency, participants, original object identity, frame cost, and root cause remain unknown.

Full owned-body audit: 611 original words verified; 41 omitted words all zero/NOP. Zero conflicts or omitted nonzero words.
