# Resource reservation tags and ownership assignment

Static File #1 US research, 2026-11-04. Original identities are recorded in
[the central index](FUNCTION_INDEX.md). Only owned static files were inspected;
no game, build, replay, attachment or live-memory inspection was performed.
This closes the six resource-record helpers before the separately mapped
[instance lifecycle family](SYMBOLS_INVENTORY_QUANTITY.md).

Byte2A in each sixty-byte record at3C5630 behaves as a reservation/claim tag,
separate from owner halfword28. Zero is unclaimed; ordinary caller actor index
is encoded as low8 index+1 with a byte store. The original concurrency or
network ownership model is unknown; these are guest state writes, not locks.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5B15D0](../recomp/config/output_ovl/o2/o2_005B15D0_0x5b15d0.cpp) | `set_active_resource_claim_tag_from_actor_index_candidate` | Confirmed/static mechanics | Active low8 a0 resource only: byte2A=(low8 a1)+1 via byte store. Input actorFF therefore stores0 after byte wrap. No existing-claim, owner, quantity or compare-and-swap check; can replace another tag. |
| [o2 0x5B1610](../recomp/config/output_ovl/o2/o2_005B1610_0x5b1610.cpp) | `clear_resource_claim_tag_for_actor_or_ff_candidate` | Confirmed/static mechanics | Active low8 resource only. Clears byte2A if existing unsigned tag equals full(low8 a1+1), or low8 a1==FF clears unconditionally. FF compares against100 before explicit unconditional branch; it does not first narrow the sum. Other mismatching actor leaves tag unchanged. |
| [o2 0x5B1670](../recomp/config/output_ovl/o2/o2_005B1670_0x5b1670.cpp) | `test_resource_claimed_by_different_actor_candidate` | Confirmed/static mechanics | Active low8 resource required, else0. Tag0 returns0. Otherwise returns1 iff unsigned tag differs from full(low8 a1+1),else0. With actorFF every nonzero byte tag differs from100; this query has no FF override. No record mutation. |
| [o2 0x5B16D0](../recomp/config/output_ovl/o2/o2_005B16D0_0x5b16d0.cpp) | `clear_all_active_resource_claim_tags_candidate` | Confirmed/static mechanics | Scans all256 records, zeroes2A only for signed activity byte0 nonzero. Leaves inactive record tags and all owner/content/quantity state unchanged. |
| [o2 0x5B1710](../recomp/config/output_ovl/o2/o2_005B1710_0x5b1710.cpp) | `clear_active_resource_claim_tags_matching_actor_candidate` | Confirmed/static mechanics | Scans256 active records; clears2A when unsigned tag equals full(low8 a0+1). ActorFF produces100, which cannot match any byte tag, so this routine does not clear all as5B1610's explicit override does. No actor bounds or owner test. |
| [o2 0x5B1760](../recomp/config/output_ovl/o2/o2_005B1760_0x5b1760.cpp) | `assign_resource_owner_after_content_admission_and_release_instances_candidate` | Probable role; full body reviewed | Active low8 a0 resource only. ORs record18 flag1 before593060(a1 actor index,original a0 ID); rejection returns2 retaining flag write. Success owner28=low16 actor index+1,byte3=0,flags18 OR800 and clear400;byte2C=template signed byteC+2. Releases pointer1C through590D80 then clears it, pointer20 through5C12A0 then clears it; returns1. Does not insert actor inventory slots, clear claim2A, save old owner, check unowned state, quantity or free-slot capacity. Caller must complete broader pickup semantics. |

The FF behaviors deliberately differ: setting wraps to0, per-resource clearing
has an explicit wildcard, conflict testing treats100 as a distinct owner value,
and bulk clearing by actor cannot match100. These are observed numeric contracts,
not interchangeable convenience APIs.

All six entries' source links and original instruction words were checked against
the owned o2 blob. Reservation interpretation remains a candidate role; no
performance measurements, gameplay bug reproduction or code change is claimed.
