# Actor audio callbacks and category dispatch boundary

Static File #1 US research, 2026-11-04. Three complete original bodies
reviewed. Addresses/offsets hex unless marked decimal. No execution, build,
attachment or engine changes. Original actor categories and script IDs unknown.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6FA930](../recomp/config/output_ovl/o2/o2_006FA930_0x6fa930.cpp) | `tick_actor_height_threshold_crossing_audio_callback_candidate` | High mechanics; probable role | Phase0 searches first active signed-byte0 nonzero actor in3B5854/next1C whose byte30 matches half73C918[task5][task4]. Missing match setsphase2;found storesactor24,previousY74,threshold70=73C908[task5],phase1 andfalls through. Phase1 computes soundpoint actor1F0 matrixtranslation+actorXYZ; ifcurrentY<=threshold andpreviousY>threshold,randomlowbit selects positionalaudio2E/2F. AlwaysupdatespreviousY. Phase2 deletes573740. No identity or material enum guessed;original list admission unknown. |
| [o2 0x6FAAD0](../recomp/config/output_ovl/o2/o2_006FAAD0_0x6faad0.cpp) | `tick_actor_scalar_admission_audio_callback_candidate` | High mechanics; probable role | Phase0 first-active actor search matchesbyte30 to half73C928[task4],stores24/phase1 ormissing->2. Phase1extracts actor1F0 translation,then ifactorfloat214>=owned742F20 (~0.5882353),randomlowbit positionalaudio39/3A. It has no prior-value comparison or once-only latch: each admitted invocation mayplay. Extracted soundpoint is local matrixtranslation without adding actorXYZ, unlikeA930. Phase2deletes. No claim that repeated admission occurs or causes a slowdown. |
| [o2 0x6FABF0](../recomp/config/output_ovl/o2/o2_006FABF0_0x6fabf0.cpp) | `dispatch_actor_category_using_session_mode_and_flag_100_candidate` | High routing | a0actor.1B02D0()==1 andbyte100nonzero selectsunchecked73C9A0[byte2];otherwise73C940[byte2]. Both tableshave22 observedslots. Alternate0uses6FAC80;alternate1..20use5B93B0;alternate21uses6FFAB0. Ordinarytablehasdistinctactor handlers listed below. No category enum namesinvented. |

Owned73C908 thresholds are decimal-300,-290,-300 before a zero word;
73C918 contains pointers73C8F0/73C8F8/73C900 before a zero word. Their
matching ID semantics and supported task5 range require caller evidence.

Ordinary73C940 slots0..21 point to6FAC80,6FAFE0,6FB7A0,6FB7B0,6FBA20,
6FC580,6FC890,6FC950,6FC9F0,6FD060,6FD140,6FDCE0,6FDE00,6FE8E0,
6FEEE0,6FEFD0,6FF3D0,6FF710,6FF910,6FF9A0,6FFA40,5B93B0.
Two zero words separate it from alternate73C9A0; bytes immediately after
the alternate22 pointers belong to other data, not additional handler slots.
The original code has no explicit category range check. Reviewing dispatch
does not count these destinations as reviewed; their bodies require separate work.
