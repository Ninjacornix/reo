# Actor snapshot, identity and shared control helpers

Static File #1 US, 2026-11-05. Thirteen complete original o2 bodies reviewed with delay slots and initial loop-entry branches. No execution, attachment, build, timing, input or live-memory capture. Offsets/addresses/flags are hexadecimal; explicit array counts and arithmetic constants below are decimal. Original actor-class names and shared-byte purposes remain unknown.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x63ED80](../recomp/config/output_ovl/o2/o2_0063ED80_0x63ed80.cpp) | `resolve_active_entity_for_snapshot_and_mark_same_room_update_candidate` | High mechanics; candidate role | a0 snapshotR. Setting3243D2==1 or R1==FF returnsnull. Scans 50 entities42EB00+D90*i for signedbyte0!=0 and entityB98==R0; first match only. Different current-room3243DC versus R22 converts signed R10/14/18 to entity floatXYZ then returnsnull. Same room requires entity8!=0; writes C98=1 and returns entity. Snapshot R1 is only sentinel-gated, not used as entity index here. |
| [o2 0x63EE90](../recomp/config/output_ovl/o2/o2_0063EE90_0x63ee90.cpp) | `bind_actor_target_from_packed_group_and_slot_byte_candidate` | High mechanics; candidate role | a0 actor,a1 packedbyte. Always C26=low7bits. Bit80 sets C25=1 and24=417090+1170*(C26%10); otherwiseC25=0 and24=4A5C30+10E0*(C26&3). Stores full low7identity inC26 despite bounded canonical pointer. No activity/room/slot-consistency validation. |
| [o2 0x63EF30](../recomp/config/output_ovl/o2/o2_0063EF30_0x63ef30.cpp) | `classify_actor_state_tuple_for_snapshot_policy_candidate` | High mechanics; candidate role | Requires actor8==2. Classbyte3 dispatches literal states9/A below; most admitted tuples return1, others0. Class1A returns raw CE8, not Boolean-normalized. No mutations, allocation or send. Original meaning of policy result unresolved. |
| [o2 0x63F2D0](../recomp/config/output_ovl/o2/o2_0063F2D0_0x63f2d0.cpp) | `copy_actor_pose_advance_destination_state_and_refresh_snapshot_candidate` | High mechanics; candidate role | a0 source,a1 destination. Increments destinationbyte9, copies floatXYZ38..40 and four signedhalves90/92/94/96. Selects destination snapshot74F250+60*B98, then literally converts destinationX38 THREE times into R10/R14/R18. This does not serialize destinationY/Z; caller/runtime consequences untested. No snapshot yaw store. |
| [o2 0x63F370](../recomp/config/output_ovl/o2/o2_0063F370_0x63f370.cpp) | `store_shared_control_byte_by_low8_index_candidate` | High mechanics; candidate role | a0index,a1value; writes lowbytevalue to74F180+low8(index) in return delay slot. No local array-length bound or semantic enum recovered. Concrete shared-state store, not a no-op. |
| [o2 0x63F390](../recomp/config/output_ovl/o2/o2_0063F390_0x63f390.cpp) | `draw_difficulty_bucket_value_into_actor_owner_control_slot_candidate` | High mechanics; candidate role | a0 actor,a1low8bucket. RNGstream1 draw low3 selects one of eight bytes in owned72B910+64*(runtime4BAE8A&3)+8*bucket. Writes selected byte to runtime3B5050[actorB98]. Bucket not locally bounded. |
| [o2 0x63F410](../recomp/config/output_ovl/o2/o2_0063F410_0x63f410.cpp) | `draw_difficulty_bucket_value_into_explicit_owner_control_slot_candidate` | High mechanics; candidate role | Same draw/table contract as63F390, but a0low8 is direct destination index3B5050[index]; no actor dereference. a1low8bucket still unbounded. Distinct concrete argument contract. |
| [o2 0x63F490](../recomp/config/output_ovl/o2/o2_0063F490_0x63f490.cpp) | `apply_local_motion_offset_through_actor_orientation_and_scale_candidate` | High mechanics; candidate role | a0 actor. Identity matrix, compose angles90/96/94 (96,not92). Unless54A bit8 set, composes scale(B4,1,BC). Always clears54A bit8, rotates localXYZ4E4, multiplies result byF0 and adds toXYZ38..40. No collision/ground resolution or snapshot refresh. |
| [o2 0x63F5A0](../recomp/config/output_ovl/o2/o2_0063F5A0_0x63f5a0.cpp) | `dispatch_contact_effect_for_stored_reference_and_clear_target_class_word_candidate` | High mechanics; candidate role | a0actor,a1low8effectmode. 637490 existing reference ->11C, dispatch selected72B820 callback with(actor,effectmode),then666D40(reference). Table0 is mechanical return-only635630;1..21 is mapped effectproducer635010. Target clear helper itself ignoresnull and nonzero class. No fresh target search or damage call here. |
| [o2 0x63F610](../recomp/config/output_ovl/o2/o2_0063F610_0x63f610.cpp) | `mark_actor_contact_flag_and_draw_clock_scaled_duration_candidate` | High mechanics; candidate role | a0actor. Sets C94 bit20 before RNGstream2 row=low2bits,stream0 column=low3bits. Selected byte72BA10+8*row+column times signed16(60/runtime74F200), final result narrowed signed16. Full bounded4x8 table verified. Does not store timer itself; flag mutation precedes return. |
| [o2 0x63F6B0](../recomp/config/output_ovl/o2/o2_0063F6B0_0x63f6b0.cpp) | `find_first_active_player_index_from_actor_bb6_slot_list_candidate` | High mechanics; candidate role | a0actor. Scans four bytes BB6..BB9 in order. Each resolves playerpool4A5C30+10E0*byte and tests signedbyte0!=0; returns first admitted INDEX, else0. Does not return pointer. Index0 success is indistinguishable from no match; no localFF or index<4 guard. |
| [o2 0x63F720](../recomp/config/output_ovl/o2/o2_0063F720_0x63f720.cpp) | `compare_actor_snapshot_room_with_current_room_candidate` | High mechanics; candidate role | a0actor. Unsignedhalf currentroom3243DC unequal to byte74F272+60*actorB98 yields1, equal0. No actorroom1E2 comparison in this helper. |
| [o2 0x63F760](../recomp/config/output_ovl/o2/o2_0063F760_0x63f760.cpp) | `pulse_and_reset_actor_c39_counter_after_clock_scaled_threshold_candidate` | High mechanics; candidate role | a0actor. Failed640640 roomauthority returns0 without store. Otherwise increments C39 modulo256; if unsignedpostbyte > signed quotient60/runtime74F200 clearsC39 andreturns1, else0. Strict greater-than, not greater-or-equal. No divisor validation here; known clockfactor writer6BBBA0 supplies1/2 but not all-writer/init-order proof. |

63ED80's search checks the count before the first item and advances on inactive/nonmatching entries. Its first matching active B98 record ends the search; a later candidate cannot rescue a same-owner record failing room/state admission. Off-room XYZ copying occurs before returningnull, so null does not mean no local work. Same-room active record with byte8==0 returnsnull without setting C98. State names and whether room switching admits each path remain external.

63EF30 returns0 unless actor8==2. Its class/state acceptance matrix is fully numeric, preserving original branch polarity rather than guessing archetypes:

| Class3 | State9 | StateA requirement / return |
| --- | --- | --- |
| 00 | 3 | A<3 ->1 |
| 01 | 0,1,2,8 | Any A ->1 |
| 02 | 2 | A<4 ->1 |
| 0C,1E,23 | 1 | A<3 ->1 |
| 10 | 3,5,7 | A<4 ->1 |
| 12 | 3 | A<4 ->1 |
| 12 | 5 | A<6 ->1 |
| 12 | 7 | A<5 ->1 |
| 14 | 2 | A<3 ->1 |
| 17 | 2 | A<4 ->1 |
| 17 | 4,6 | A<5 ->1 |
| 1B | 2,3 | A<6 ->1 |
| 24 | 3 | StateA<0A ->1 |
| 05 | 2 | A<5 ->1 |
| 3B | 1 | Any A ->1 |
| 1A | Any | Raw byteCE8, may exceed1 |
| All other tuples | — | 0 |

For63F390/410 the complete statically bounded difficulty span72B910..72BA0F is256 bytes, SHA256`ba6fce2ab79d22a8b4bc4679a3026a65b7403062ee3be06f05ab6d9d44a02841`. Four64-byte rows each comprise eight8-byte buckets when bucket0..7 is supplied. These functions do not enforce that bucket range; hashing this owned span does not prove all runtime accesses stay within it. Selected output is a shared control value, with units/domain unresolved; it is not labeled health, damage or milliseconds.

63F610 has fully bounded table72BA10..72BA2F,32 bytes SHA256`c10d137112951c35486eb54b0b4a2c5986f78bd0a032c8c2fb8b85ef4b99695d`. Decimal row values:

```text
20 22 24 28 30 32 34 36
40 40 42 44 44 46 48 48
80 84 88 90 92 94 96 100
120 124 128 132 136 140 146 150
```

Callback table72B820's physical extent is22 pointers to72B877, then zero. Slot0=635630 and1..21=635010; full88-byte SHA256`14b15ab10fd756d54d7f23f8515b590e2ed90f6eae5cf72ef622841766ac8ad1`. This reuses [contact routing](SYMBOLS_ACTOR_TARGET_REGIONS_CONTACT_ROUTING.md) and [effect producer](SYMBOLS_ACTOR_CONTACT_EFFECT_EMISSION.md) evidence, without admitting unbounded actor141 or promoting635630 to semantic progress. [666D40 target clear](SYMBOLS_ACTOR_RESPONSE_TIMERS_AUTHORITY.md) has its own null/class guard. 63F5A0 itself only stores a possiblynull reference11C before effect dispatch.

Return-only63F590 is mechanically visible at [original source](../recomp/config/output_ovl/o2/o2_0063F590_0x63f590.cpp); its JR RA/zero delay word has no newly recovered caller contract. It is deliberately outside the reviewed-role table and counts. Pose copying63F2D0's repeatedX snapshot stores are literal observations; no player execution or downstream divergence was measured. [Message codec](SYMBOLS_ACTOR_STATE_MESSAGE_CODEC.md) distinguishes snapshot mutation from publication. [Runtime binding](SYMBOLS_EMD_ACTOR_RUNTIME_FIELD_BINDING.md), [RNG streams](SYMBOLS_SESSION_SETTINGS_RNG.md), and [matrix helpers](SYMBOLS_OVERLAY_MATH.md) preserve dependent contracts. No rootcause, performance cost or engine change is claimed.

Owned o2 base570000 SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. Runtime snapshot/control arrays were not read. Full owned-body audit: 582 original words verified, 58 omitted words all zero/NOP; zero conflicts and zero omitted nonzero words. Mechanical63F590 is outside these totals.
