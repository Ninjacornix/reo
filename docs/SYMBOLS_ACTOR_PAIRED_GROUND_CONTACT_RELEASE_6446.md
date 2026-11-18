# Paired actor offsets and ground-contact terminal release

Static File #1 US, 2026-11-05. Two complete original o2 bodies reviewed,644620..644BB3 and644BC0..645213. No target execution, build, attachment, live memory, input or networking. Addresses, phases and descriptor IDs are hexadecimal; explicit cooldowns are decimal. Original action names remain unknown.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x644620](../recomp/config/output_ovl/o2/o2_00644620_0x644620.cpp) | `update_paired_response_offset_minus47_192_ground3_terminal6_candidate` | High mechanics; candidate role | PartnerB20=11; two-descriptor bank711380, yaw/local offset(-47,134.6,192), sound1E/1F,63 transition, ground-code3/Y gate then1048 completion to action4/6/0/0. Abort returns action1/4A/0/0. |
| [o2 0x644BC0](../recomp/config/output_ovl/o2/o2_00644BC0_0x644bc0.cpp) | `update_paired_response_two_offsets_ground3_terminal4_candidate` | High mechanics; candidate role | PartnerB20=13; bank7113A0, initial offset(-20,-50,209), release offset(-35,128,211), sound20/21,63 transition and ground-code3/Y gate then1048 completion to action4/4/0/0. Abort chooses action1/4A or idle by ground code. |

Both take a0 actor. Prelude OR54A bits1F and byte32FF; stack ground-code byte starts0. Positive6673C0 immediately aborts:644620 sets action1/4A/0/0 and snapshots, whereas644BC0 clears54F/548 bit1, sets action1/0/1/0, snapshots,2050 start0/blend10 and activates bank. Nonzero A resolves partner E=42EB00+D90*byte(74F251+60*B1D), without local bounds; class0 E.C26!=source3, false63EF30(E), or ownB1E6 forces AFF. Changed A versus entry is serialized67E230(actor,1) BEFORE executing new phase.

Both phase0 setA1,54FB0,D101, snapshot, clearB22/B1E/B9F and resolve663350(148,149). Failure uses the immediate abort above. Success links ownB24=E/B1D=E.B98; E.B1C/B1E1,B1D=source3,B24=source,B20=11 or13; clears source rootXYZ. No partner-offset tail exists and the resolver's phase0 target need not populate local E.

Let D[i] be bankBase+8*(2*B99+i), base711380 or7113A0. No B99 bound is checked. Both use58C7F0 before descriptor selection; these descriptors use start0/blend0. At every offset application, copy E.yaw92 to source92 then64ADA0(E,&sourceXYZ,&localOffset) transforms by partner yaw and position. No continuous offset application occurs in phases4/6 unless the specified branch takes it.

| Phase | Shared operations and exact differences |
| --- | --- |
| 1/2 |1 increments2 then falls through;2 increments3, selects D0, applies initial offset:644620(-47,134.60000610351562,192);644BC0(-20,-50,209). Activate bank. |
| 3 | Advance4, sound1E or20, FALL THROUGH to phase4 tick this same call. |
| 4 | Tick58C300(actor,1); signed low byte2 emits sound1F or21. If B1E63, clear B1E, setA6 (skip5),58C7F0, selectD1, apply release offset.644620 repeats its initial offset;644BC0 uses(-35,128,211). No activation call here. |
| 5 | PartnerB1E4, incrementA6,58C7F0, D1, release offset as above; return without phase6 fallthrough. |
| 6 |616F20(&XYZ,&groundCode,3) returns candidate ground height. If code==3 AND sourceY<=height, advance7 and skip animation tick. Otherwise tick animation, ignoring result; phase remains6. |
| 7 | Advance8,58C7F0, select1048 start0/blend10, activate bank. |
| 8 | Tick; positive signed low byte: ORBA0 bits120,5F6800(actor,0),54FA0, action4/6/0/0 (644620) or4/4/0/0 (644BC0), snapshot, serialize67E230(actor,1), clear rootXYZ. Only644620 also ORsBA0 bit1000 before serialization. |
| FF | Cooldown32=60 if3243CC zero else30.644620 action1/4A/0/0+snapshot.644BC0 calls616F20; code3 sets action1/4A/0/0+snapshot WITHOUT a Y<=height test. Other codes use idle2050 reset/blend10 and activation. |
| Other | No own phase body after prelude/admission. |

Owned banks each contain two physical two-entry banks; half0=60 and half2=0 throughout, half4/6 match.711380..71139F32 bytes: pairs1,2 and33,34, SHA256`aa3ebbe411bef7556f0cca6848d5ac1695cd72600d8226e94a736d88889c9600`.7113A0..7113BF32 bytes:4,5 and36,37, SHA256`4f232ea1e67f62fc8a3ecce1bec0bdb96b46a84e8a3dc7dca2be3815c9645eaf`. Literal packed fields are not decoded as model/start/end. Physical banks do not establish admitted B99 range.

Owned740180 float134.60000610351562 SHA256`8c7f83ef2d2dcacd918972c3b47b75bb05dae89cbcf39a42fb8a96f32208e4d5`;7117A8 float-50 SHA256`a97cf0fa225d26c645ef856658b3c6f65cce62a7e6abd2bff40b87f59a2950ac`. The phase6 gate is a measured instruction contract, not a measured wait or proof of a stuck actor. Partner index/lifetime and admitted terrain states remain unknown. No sound playback, elapsed cost or slowdown was measured. Original o2 base570000 SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.

Full owned-body audit: 702 original words verified; 60 omitted words all zero/NOP; zero conflicts and zero omitted nonzero words.
