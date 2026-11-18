# Resource instance callbacks, delayed activation and contact admission

Static File #1 US research, 2026-11-04. Original identities are recorded in
[the central index](FUNCTION_INDEX.md). This closes connected callbacks from
[resource instance pooling](SYMBOLS_RESOURCE_INSTANCE_POOL.md). Only owned static
files were inspected; no game, build, replay, attachment, live-memory inspection
or implementation change was performed.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x592DF0](../recomp/config/output_ovl/o2/o2_00592DF0_0x592df0.cpp) | `set_definition_resource_flag400_and_mirror_instance_candidate` | Confirmed/static mechanics | a0 signed definition ID resolves592900,requires active record and signed byte3 nonzero. Full a1 nonzero sets record flags18 bit400;zero clears. Mirrors same bit in attached instance23C if1C nonnull. No owner,room,quantity or template admission;does not create/release objects. |
| [o2 0x592E90](../recomp/config/output_ovl/o2/o2_00592E90_0x592e90.cpp) | `schedule_unowned_definition_resource_instance_activation_candidate` | Probable role; full body reviewed | Definition lookup592900 must active and signed byte3 nonzero. ORs record flags1 even if no subsequent allocation. Only absent1C,record byte1==current room3243DC and owner0 clear flag200000 then allocate591400(content,original a1 delay). On success writes instance240=selfID and record1C=instance. Failure retains earlier flag changes. Does not build a world instance immediately. |
| [o2 0x592FD0](../recomp/config/output_ovl/o2/o2_00592FD0_0x592fd0.cpp) | `test_resource_contact_actor_selector_and_expected_boolean_candidate` | Confirmed/static mechanics | a0 contact descriptor,a1 actor must nonnull,else0. Descriptor half44 selector0 returns1 unconditionally. Selector1 computes actor byte3==descriptor half46;selector2 computes actor B98==half46. Returns1 iff computed boolean equals unsigned descriptor half48. Other selectors leave original full actor pointer in comparison operand and compare it to half48;no implicit default boolean is supplied. No activity/room/resource admission. |
| [o2 0x5931F0](../recomp/config/output_ovl/o2/o2_005931F0_0x5931f0.cpp) | `publish_actor_resource_contact_candidate_and_height_band_candidate` | Probable role; full body and constants reviewed | Null descriptor ignored;actor=descriptor34 passed592FD0. Rejected filter with descriptor half4A!=FFFF calls570120(id,3C,3). Accepted writes actorC78=1,C7A=low8 descriptor word40. C79 selects first of strict thresholds40,90,175,185 at71B830 above float((word20+word24)*0.5)-actorY,otherwise4. Then593060(actor byte3,descriptor byte40) failed content admission setsC78=3. No actor null guard after a successful filter,inventory insertion or pickup completion. |
| [o2 0x5932F0](../recomp/config/output_ovl/o2/o2_005932F0_0x5932f0.cpp) | `update_resource_instance_owner_visibility_and_world_matrix_candidate` | Probable role; full body reviewed | Null/inactive node ignored. Starts byte1=1;flag80000000 clears it. Flag20000 resolves logical owner-1 signed16:negative hides,0..3 fixed actor,>=4 linked682F80. Missing/inactive owner or ownerBA0&5E0 releases via5B1A90(ID) and returns;different room1E2 or owner byte1 zero hides. Fixed owners also apply global4B9D10/11 selected-actor visibility rules;accepted copies owner byte175 to instance241. Non20000 path:flag800 without400 ticks5925C0;flag100000 calls592770 (whose own admission is40000000),then rereads flags;flag80000 rebuilds matrix1C0 from unsigned angles21C/21E/220 via191F80/1904A0 and scales through190020 with22C. No unconditional transform refresh on owner-attached path. |
| [o2 0x593550](../recomp/config/output_ovl/o2/o2_00593550_0x593550.cpp) | `activate_delayed_resource_instance_only_at_exact_zero_counter_candidate` | Probable role; full body reviewed | Always byte1=0,then decrements signed half10 and narrows16. Only exact result0 proceeds;initial0 becomes-1 and waits through wrap. Instance240 resolves logical record;inactive returns without freeing instance. Matching room byte1 and owner0 calls591620(record),then clears record200000 if set and,if still unowned,rebuilds591860. Off-room or owned path only clears record200000. Does not locally retire/free delayed node in skipped paths;world recreation may release/reuse it through591620. |

The update walker `0x590EA0` reads a node's next link after its callback.
`0x593550` can replace its own attached instance through `0x591620`; that helper
returns the old object to the pool and allocates a replacement at the list tail.
Thus linked-list mutation/reuse is part of the static callback contract and must
be considered when changing traversal. No controlled runtime case establishes
the frequency, visible effect or performance cost of this sequence.

All six source links and original instruction words were checked against the
owned o2 blob. Contact and visibility labels are candidate roles; no reproduced
incident, original symbol recovery or verified fix is claimed.
