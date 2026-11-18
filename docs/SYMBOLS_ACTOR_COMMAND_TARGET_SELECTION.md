# Actor command target selection and transition entry

Static File #1 US,2026-11-04. Four complete catalog roles joining the [command/retry family](SYMBOLS_ACTOR_COMMAND_TRANSITIONS.md) and [selector publication](SYMBOLS_ACTOR_TRANSITION_MESSAGE_PACKING.md). High-confidence mechanics; original policy enums unknown. No execution/build/attachment/live memory/input/timing. Addresses/IDs/offsets hexadecimal; explicit counts/distances decimal.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x625100](../recomp/config/output_ovl/o2/o2_00625100_0x625100.cpp) | `route_actor_command_transition_result_or_retry_related_record_candidate` | High mechanics; candidate role | 625630 result0: unless BA0bit80000,FB7 nonzero resets8..B/FB8,then FB70/active1; always6257A0(actor,10A4). Result1 setsFCF3; othernonzero setsFCF4/health0/6260E0(FB5). Bothnonzero paths684810(actor,0). No ownership decision added. |
| [o2 0x6251C0](../recomp/config/output_ovl/o2/o2_006251C0_0x6251c0.cpp) | `queue_actor_command_secondary_selector_byte_candidate` | High mechanics; candidate role | Complete16B writes114C1 and low8a1 to114D,return. No delivery/callback or pose change; exact consumer enum unresolved. |
| [o2 0x6251D0](../recomp/config/output_ovl/o2/o2_006251D0_0x6251d0.cpp) | `classify_actor_command_target_active_and_saved_link_policy_candidate` | High mechanics; candidate role | a0 self/a1 candidate; candidatebyte0/1 zero ->2; else selfBA0bit80000 ->1; else candidateBA0mask1E0 nonzero ->2,zero ->0. No NULL guard/state writes/RNG. |
| [o2 0x625230](../recomp/config/output_ovl/o2/o2_00625230_0x625230.cpp) | `select_actor_command_target_by_eleven_numeric_pool_or_list_policies_candidate` | High mechanics; candidate role | SignedFCD unsigned<11 gate; pointerinitial0; complete73FD70 dispatch below. Bounded8slot pool4A5C30/10E0 or linked3B59F0/3B5900,IDFF6/distance665DC0 policies. Alwayswrites1024 includinginvalidmode/nohit0. |

625230 list iterations always advance node1C even when activebyte0 zero. Initial NULLhead tests and all branch/delay-slot entry targets verified. No repeated-inactive-node interpretation applies here. Cyclic list/invalid pointer admission and runtime cost remain unknown. Pool iterations exactly eight; same half1E2 scene filter appears only where listed.

Let d=665DC0(self,candidate38), fullXYZdistance. B is initialFD8 or literal bound; preserve COP1 comparisons rather than presumed nearest/farthest intent.

| FCD mode | Complete policy |
| --- | --- |
|0|First active pool slot,same scene,typebyte3==FF6|
|1|First active pool slot,same scene,B98==FF6|
|2|First active3B59F0 node,resourcehalfBB4==FF6; no scene filter|
|3|First active3B5900 node,typebyte3==FF6; no scene filter|
|4|Active/same-scene pool: classifier6251D0 class0 admits strictd<B and updatesB/pointer; class1 sets pointer4A5C30+10E0*unsignedselfC66 without checking indexed slot; class2 skips. B startsFD8|
|5|Active/same-scene pool,strictd>B updatesB/pointer; B startsFD8; no classifier|
|6|Active3B59F0,strictd<B updatesB/pointer; B starts10000|
|7|Active3B59F0,same strictd<B comparison but B starts0|
|8|Active3B5900,strictd<B updatesB/pointer; B starts10000|
|9|Active3B5900,strictd<B comparison but B starts0|
|A|Copy word24 without validation|
|Other,includingnegative|Pointer0|

Modes7/9 preserve zeroresult for ordinary finite nonnegative d because they require d<bound starting0. They are not called farthest based on table position: mode5 uses the actual greater-than policy. This is static mechanical evidence; caller admission, original intent and runtime impact remain unknown. No measured failed-target or slowdown cause is claimed.

625100 normal result0 clears FB7/state fields only when BA0bit80000 clear; with bit set it preserves them but still invokes related-record retry6257A0. Existing classifier625630 returns1 for its bit200/state policy and2 for bit20. The nonzero routes publish selector mode0 through684810; result2 first sends6260E0 zero payload. It does not run game/session monitoring.

Owned o2 base570000 SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. Full11-target73FD70..73FD9B: `62527C,6252DC,62533C,625380,6253C4,625464,625564,6255B8,6254C4,625518,625604`,SHA256 `d8434d28b6e717bbeef08b4026b1277b76d06e7e6066120bdaed9b6c20541123`. Pool/list storage is runtime-only, not initialized asset bytes from this overlay. Actual target identity, call rate and performance attribution unknown.

Owned-word audit:four complete catalog bodies,283 original instruction words verified,42 omitted zero/NOP words,zero conflicts and zero omitted nonzero words. Full11targettablehashed;liveannotation/note/linkchecks clean;no sharedindexmutation.
