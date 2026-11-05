# Collision proxy interaction phase and room-transition publication

Static File #1 US research, 2026-11-04. Four complete original bodies reviewed. P is proxy, D the separate descriptor P.word40 where stated, A=P.word34. Hexadecimal field offsets/IDs, decimal float168. Confidence is high for local mechanics, probable for semantic labels. Original room enum names, valid authored selector ranges and runtime execution remain unknown.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x5C27D0](../recomp/config/output_ovl/o2/o2_005C27D0_0x5c27d0.cpp) | `collision_proxy_publish_kind_one_interaction_and_optional_room_transition_candidate` | High mechanics; role probable | P=a0,A=P34. Class0 AD0=low8(P40+10), class1/2 AD0=low8 P40; these classes set AD1=FF,AB8=1,ABA=1,AB9=70A750[P6C]. Only class0 with1B0340(A)!=0 publishes room-transition globals; class1 instead writes102D=P48,115C=P44. All classes reach selector pose cases and optional local-actor one-shot flag helper described below. |
| [o2 0x5C2D40](../recomp/config/output_ovl/o2/o2_005C2D40_0x5c2d40.cpp) | `collision_proxy_publish_kind_zero_interaction_and_optional_room_transition_candidate` | High mechanics; role probable | P=a0,D=P40,A=P34. Class1 exits. Class0 requires A3==4BADED; publishes mode5 room transition and room half4B9E22 bit only when1B0340(A)!=0, then always ACC=168,AB9=70B190[P54]+1F,AB8=ABA=1,AD0=D40,AD1=FF. Class2 sets AB9=7,AB8=1,ACC=168,AD1=FF, retaining AD0/ABA. Other classes skip classification. Admitted paths write AC8=(D58-8000)&FFFF and ABB=D4C, then optional one-shot flag using D73/74. |
| [o2 0x5C2F00](../recomp/config/output_ovl/o2/o2_005C2F00_0x5c2f00.cpp) | `collision_proxy_mark_kind_zero_scene_slot_and_actor_transition_flag_candidate` | High mechanics; role probable | D=P40,A=P34. Class0 with1B0340(A)!=0 ORs current-room half4B9E22 with low16(1<<D40), ORs actor BA4 bit20000. Regardless that predicate,1B02D0()==1 also ORs class0 BA4 bit20000. All actor classes then set byte4A3622+60*D40=1. No AB8/AB9/pose writes or Boolean result. |
| [o2 0x5C3F40](../recomp/config/output_ovl/o2/o2_005C3F40_0x5c3f40.cpp) | `set_missing_session_flag_or_notify_missing_primary_flag_candidate` | High mechanics; role probable | a0 bankSelector,a1 ID low16. Selector0 tests word4B9C00+4*(ID>>5),bit(ID&1F); if absent calls5703E0(ID,1), otherwise no work. Nonzero selector tests word4B9A80+4*(ID>>5) and ORs missing bit directly; no callback in that branch. No bounds validation or normalized return. |

5C27D0 class0 and1B0340(A)!=0 writes byte4BAE05=low8 P48,byte4BAE07=2,half3243E0=half3243DA,half3243E2=low16 P44. Selector P.word6C is tested unsigned<9 only **after** the class0/1/2 phase-table byte lookup. The nine owned jump words select:

| Selector | Additional writes |
| --- | --- |
| 0 | Clear halfAEA; AC8=P68,ABC=P5C XYZ,ACC=168.0. |
| 1 | AC8=P68; rotate XYZ from70B1C0+12*A.B99 by P68 yaw, add P5C XYZ into ABC. AEA/ACC retained. |
| 2,4 | AC8=P68; rotate70B1E0+12*A.B99 and add P5C into ABC; ACC=168.0. |
| 3,5 | Same offset/ACC contract as2/4 in another physical case branch. |
| 6 or >=9 | No pose-case writes. |
| 7 | AC8=P68,ABC=P5C,ACC=168.0; AEA retained because entry skips5C2928 clear. |
| 8 | Clear halfAEA; AC8=P68,ABC=P5C,ACC=0.0. |

No selector case copies ABC into actor38 or writes half92. After the case, only actor class0 with A3==4BADED and signed P.byte88==1 changes that byte toFF and calls5C3F40((P.half84&F000)>>12,P.half84&1FF). Thus the callback can consume a one-shot even when the target flag was already set; it does not prove a room load completed.

5C2D40 uses D=P40 rather than inline fields for room endpoints. Class0 local actor and1B0340 nonzero writes half3243E0=3243DA,half3243E2=D44,byte4BAE05=D48,byte4BAE07=5,then ORs current room half4B9E22 with low16(1<<(D40&1F)). After classification AC8/ABB writes, only class0 local actor with signed D.byte73==1 clears it toFF and calls5C3F40((D.half74&F000)>>12,D.half74&1FF). Class0 nonlocal and class1 exit before all those shared writes; other classes reach AC8/ABB without classification.

Owned o2 SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`, base570000.73E8A0..73E8C3 words:5C2928,5C2984,5C29E0,5C2A40,5C29E0,5C2A40,5C2A9C,5C292C,5C2958; SHA256 `e2d38fd0e24bf1d4e055ccf07884fd4c13d69a3c39633d6a105cfc0ef7162e67`.70A750..70A758 phase prefix hexadecimal7,8,14,17,1B,1C,7,2D,7; SHA256 `f043e1109bff8c0dbefefb85d0006d5b75d0e474190fca3600bf2e8d0dc25448`. The ninth byte extends the eight-selector prefix used by580A10, not a contradiction in [pose offset data](SYMBOLS_INTERACTION_POSE_OFFSETS.md).

The32-byte physical spans70B1C0..70B1DF and70B1E0..70B1FF each contain float words0,0,-50,0,0,-50,0,0 and share SHA256 `87ed2ca956be9f741f1b8a1eb892db03d9bb2fffdb14d5d8b468638944052a30`. Callbacks index these bases by12*A.B99 without a local bounds check; the physical32-byte spans are **not** claimed complete runtime vector tables or valid index counts. The larger containing blocks are preserved in pose offset data. No malformed authored indices or incident are observed.

[Linked query tables](SYMBOLS_LINKED_INTERACTION_PROXY_QUERIES.md) connect these callbacks to point selection. [Pose bank handlers](SYMBOLS_INTERACTION_POSE_BANKS.md) consume the published AD0/AB9/AB8 state later; their pose calculation is not performed synchronously by every callback path. Original/native override boundaries remain distinct from original guest semantics.

Owned-word audit:4 rows,394 distinct instruction words verified,19 omitted zero/NOP words,0 conflicts and0 omitted nonzero words. Full aligned original intervals audited.
