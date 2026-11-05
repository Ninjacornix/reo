# Actor placement packet application and resource node binding

Static File #1 US research, 2026-11-04. Two complete original bodies reviewed. Hexadecimal addresses/fields/strides; explicit32/64-byte sizes decimal. Local mechanics high confidence; placement/resource interpretation probable. No game execution, live memory, attachment, builds or engine fixes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x662C90](../recomp/config/output_ovl/o2/o2_00662C90_0x662c90.cpp) | `install_actor_placement_records_and_apply_uninitialized_slots_candidate` | High mechanics; role probable | a0 packet:word0 count->4B8E78,copy count<<5 bytes from packet4 to4B8A70 via18DBB0. Iterates unsigned8 index while<word4BAEA0; active actor4A5C30+10E0*i,slot state4B9D00+3*i==0,BA0&5E0==0. Placement index byte4B9D02+3*i selects32-byte record; sets XYZ from signed words0/14/4,yaw half92=word8,half90/94=0,state1,BA4 bit1. No packet/copycount/placement-index bounds or validation. Fullword actor limit with8-bit loop counter retained; valid input limits unknown. |
| [o2 0x662DB0](../recomp/config/output_ovl/o2/o2_00662DB0_0x662db0.cpp) | `bind_resource_instance_matrix_to_actor_node_with_metadata_offset_candidate` | High mechanics; role probable | a0 actor,a1 resourceID low8,a2 full nodeIndex. Requires ID nonzero, resource pointer word3C564C+3C*ID, actor34 model and model820+4*node nonnull. Copies64 bytes node matrix into resource1C0,normalizes its3 basisXYZ separately. Derives metadata via5F1F40(originala1),scaled position/rotation fields by actorB99, optional mirrored nodeF and special54F80/resourcekindC paths below. Publishes resource200 translation from final matrix; no renderer submission. |

662C90 copies payload before checking any actor slot. Actor limit is fullword4BAEA0 while loop index wraps with&FF; no local count clamp. This is an admission gap, not proof the game supplies an excessive limit. Per-actor state4B9D00 is set only after transform publication; BA0 blockers5E0 preserve its prior0. WorldX comes from signed placement word0,Zword4,Yword14. Input count remains4B8E78 even when actor entries skip.18DBB0 is the existing copy operation, not parser verification.

662DB0 permits full a1 for metadata lookup5F1F40 but resource-instance selection uses only low8ID. Metadata R=719A60+44*low16 lookup result; subsequent R!=0 test does not validate content bounds. CategoryB99 selects floatXYZ atR10+12*category and three unsigned angle halfwords atR28+8*category; XYZ scales componentwise by actorB4/B8/BC. NodeindexF negates X of this scaled vector. Valid node/category/metadata ID domains remain caller obligations.

Special branch when actor.byte54F==80 and metadata for actor.halfCA8 has byte5==C:

| Actor substate9 | Matrix work |
| --- | --- |
| 0 or7 |191280(resource1C0,resource180,resource1C0); extract final translation to resource200; early return. Metadata XYZ/rotation adjustment bypassed. |
| Other |1902D0 creates offset rotation from owned floats740468/460/458;translation740450/448/440. If nodeF negate X components at temporary matrix0/10/20.191280(resource1C0,temporary,resource1C0),extract resource200. |

General branch: unsigned angle halfwords multiply owned2pi/divide65536,1902D0 builds offset rotation; scaledXYZ copied to temporary translation30/34/38. NodeF negates temporary matrix0/10/20.191280(resource1C0,temporary,resource1C0),1900E0(resource200,resource1C0). Each original actor-node basis was normalized before composition, without zero-vector guard. Matrix order retained as argument expressions, without guessing row/column convention. No extra world translation or renderer/GPU calls occur here.

Owned o2 base570000 SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`:whole56-byte physical span740440..740477 SHA256 `7ce21fae45e072b675cd885483a3ec18315fb051c97cf266894e58b80baf228e`. Consumed float words (intervening4-byte words zero):740440=6.085999965667725,448=-6.9019999504089355,450=-6.245999813079834,458=0.2105216234922409,460=-0.9082518815994263,468=-0.22048744559288025,470=6.2831854820251465. Fixed offsets do not identify an original item by themselves.

[CDD contact helpers](SYMBOLS_ACTOR_CDD_CONTACT_REDUCTION.md) share actor metadata fields but do not call this binding body. [Render math](SYMBOLS_RENDER_MATH.md) defines matrix/vector primitives. No root cause, frame cost, successful resource publication or runtime bounds failure is claimed.

Owned-word audit:2 rows,298 distinct instruction words verified,9 omitted zero/NOP words,0 conflicts and0 omitted nonzero words. Full aligned original intervals audited.
