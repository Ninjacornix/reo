# Actor script roster target following and portal transition admission

Static File #1 US research, 2026-11-04. Eight complete original bodies reviewed.
Addresses/offsets/state values hexadecimal; distances decimal. Candidate labels
describe operations; original actor and scenario names remain unresolved.
No execution, attachment, build, replay or engine changes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6BCBA0](../recomp/config/output_ovl/o2/o2_006BCBA0_0x6bcba0.cpp) | `follow_script_roster_target_with_distance_and_transition_gates_candidate` | High mechanics; action identity unknown | Writes FD8=300 float. Requires6BD380 nonzero; resolves target4A5C30+10E0*(1020-1), calls6BD4C0 then6BD550, both mechanically return1. Distance>300 calls6BD570 then idle selection unless BA0 bit80000. Distance<=300 with targetBA0 bit10000 calls6BD5D0; success exits. Otherwise distance>100 selects FB7=1/byte1=1 and6BD160(actor,target); distance<=100 selects idle. Ordered comparisons and precomputed target pointer preserved even when6BD4C0 clears1020. |
| [o2 0x6BD150](../recomp/config/output_ovl/o2/o2_006BD150_0x6bd150.cpp) | `tail_follow_script_roster_target_6bcba0` | High mechanics | Direct tail-jump6BCBA0 with NOP delay slot. No additional side effects. |
| [o2 0x6BD380](../recomp/config/output_ovl/o2/o2_006BD380_0x6bd380.cpp) | `refresh_one_based_script_roster_target_selector_candidate` | High mechanics | BA0 bit80000 uses C66+1, updating byte1020 when different; matching returns previous1020. Without flag,1020=0 calls6BD900; failure idles and clears1020. Existing target checks BA0&1E0 at4A56F0+10E0*1020, which equals selected actorBA0; set bits trigger6BD900 and the same failure cleanup. Returns byte1020. |
| [o2 0x6BD4C0](../recomp/config/output_ovl/o2/o2_006BD4C0_0x6bd4c0.cpp) | `clear_script_roster_selector_on_room_mismatch_and_return_one_candidate` | High mechanics | Resolves target by1020-1 and compares1E2. Matching returns1; mismatch idles unless BA0 bit80000, clears1020 and also returns1. Thus its caller's beqz does not reject a mismatch by return value. This is original static behavior, not reproduced malfunction. |
| [o2 0x6BD550](../recomp/config/output_ovl/o2/o2_006BD550_0x6bd550.cpp) | `test_unsigned_target_byte_54f_against_unreachable_mask_and_return_one` | High mechanics | Loads unsigned byte a1+54F, ANDs with20000000, nonzero-inverts. The byte cannot contain that bit, so result is1 for every loaded byte. No writes; a0 unused. No intended wider field or correction inferred. |
| [o2 0x6BD570](../recomp/config/output_ovl/o2/o2_006BD570_0x6bd570.cpp) | `publish_script_target_clear_if_owned_and_clear_selector_flag_candidate` | High mechanics | If681970(1,FB5) admits,684810(actor,3). Always zero1020 and clearBA0 bit80000. No claim that message is delivered. |
| [o2 0x6BD5D0](../recomp/config/output_ovl/o2/o2_006BD5D0_0x6bd5d0.cpp) | `admit_script_target_portal_or_stage_transition_points_candidate` | High mechanics; portal identity provisional | Uses selected targetAD0 as actor1154; requires581B60(1154,&kind,&selector,&third)=1. Nonzero kind requires684770(FB5,selector)>=0 and5FDE90(signedroom,signed1154)=1, setsFCF6/32=FF, stages target position through5816F0(...,t0=0), FF4, optionally626120(FB5,selector,0), motion1/626180 as needed, clearsBA0 bit80000, returns1. Zero kind follows the two-point comparison below. All failed initial admissions return0. No inferred original door or travel animation name. |
| [o2 0x6BD900](../recomp/config/output_ovl/o2/o2_006BD900_0x6bd900.cpp) | `refresh_script_target_from_625230_with_eight_tick_change_cooldown_candidate` | High mechanics; cadence unknown | Ownership681970(1,FB5) and signedFCA=0 setsFCD4,625230(actor);1024 pointer yields targetbyte3+1 or no target0 with idle selection. Changed1020 calls626180(actor,3), setsFCA8; returns selected!=0. Nonzero FCA decrements and returns0. Without ownership returns1 for nonzero1020; zero idles unless flag80000 then returns0. No global update frequency inferred. |

6BCBA0's common motion selector writes byte1=1 and FB7=0 or1 unless BA0 bit80000;
it clears8..B/FB8 only when FB7 changes. The distance thresholds are Euclidean
through665DC0. 6BD4C0's constant success and6BD550's byte/mask mismatch are
recorded without asserting bugs, fixes or observed player consequences.

6BD5D0 zero-kind continuation, fully reviewed:

- Copies targetXYZ into actorFDC/FE0/FE4;5816F0(1154,actor,destination,&angle,targetAD1),
  narrows resulting angle toFF4. Calls5816F0 again on a separate copy of targetXYZ.
- Copies that second result and offsets the copy through377460 with FF4 and160
  float. Compares actor distance to the unshifted versus shifted second point.
- When unshifted distance is strictly less, replaces FDC/FE0/FE4 andFF4 with that
  result, selects motion1/626180 if FB7 changes, clearsBA0 bit80000, returns1.
- Otherwise626180(actor,1), FCF6, FCA0,32=FF, clearsBA0 bit1000000 and returns1.
- Initial nonzero-kind success similarly selects motion1 only if FB7 differs;
  calls626180 even when flag80000 prevents local motion writes. It finally clears
  bit80000. All branch delay stores, early returns and comparison equality path
  are included; no successful transition completion is established here.

Connected callers: [sixteen-phase script](SYMBOLS_ACTOR_6BC590_PHASE_SCRIPT.md),
[position/route helpers](SYMBOLS_ACTOR_SCRIPT_POSITION_COMPLETION.md).
Original instruction words are checked against the owned o2 blob;
`build-function-index/owned-overlays/o2.bin`, base570000, SHA256
`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.

Full-body owned-word audit: eight rows, 506 verified instruction words,
zero conflicts, 35 omitted zero/NOP words, zero omitted nonzero words.
