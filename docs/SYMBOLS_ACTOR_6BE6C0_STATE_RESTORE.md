# Actor 6BE6C0 saved-state displacement and interpolation

Static File #1 US research, 2026-11-04. Four complete original bodies reviewed.
Addresses/offsets/selectors hexadecimal; distances and step counts decimal.
Original restoration trigger remains unresolved. No execution, attachment,
build, replay or engine changes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6C1380](../recomp/config/output_ovl/o2/o2_006C1380_0x6c1380.cpp) | `prepare_saved_state_displacement_when_cc2_one_and_within_500_candidate` | High mechanics | Requires6C1420. VectorCB0=CA4-XYZ,191CC0 length;CC0=CBE-currentyaw. Unlessdistance<500 returns0. OtherwiseCCA=0 when distance<=200,else1,returns1. CC0 is written even for failed distance gate. |
| [o2 0x6C1420](../recomp/config/output_ovl/o2/o2_006C1420_0x6c1420.cpp) | `test_saved_primary_cc2_equals_one` | High mechanics | UnsignedbyteCC2 XOR1 then unsigned<1;returns1 exactlywhenCC2=1. |
| [o2 0x6C1430](../recomp/config/output_ovl/o2/o2_006C1430_0x6c1430.cpp) | `enter_primary_five_saved_state_interpolation_candidate` | High mechanics | Settuple8/9/A/B=(5,0,0,0). No validity check or coordinate writes. |
| [o2 0x6C1450](../recomp/config/output_ovl/o2/o2_006C1450_0x6c1450.cpp) | `interpolate_twenty_actor_steps_then_restore_saved_transform_and_state_candidate` | High mechanics | Always54A=5,C82=1. A0->1,CBC=14 (20 decimal), divides CB0/4/8 and signedCC0 by20;CCA!=0 choosesmotion6,elseentrya1=5 selects motion5,then58C7B0,returns. A1stepsanimationrate1float,addsdisplacementtoXYZ andCC0toyaw,predecrementsCBC. Positive returns;expiredsnapsXYZ=CA4/8/C,yaw=CBE,restoresbytes8..B fromCC2..5 andhalfC/E fromCC6/8. OtherAreturns. No total wall-clock duration inferred. |

The [actor callback](SYMBOLS_ACTOR_6BE6C0_CALLBACK.md) performs additional
post-dispatch position/collision work. This note establishes the original local
interpolation contract; it does not claim to explain visible network correction,
a particular hitch, or how the snapshot fields were populated.

Full-body owned-word audit: 4 rows, 151 verified instruction words,
zero conflicts, 6 omitted zero/NOP words, zero omitted nonzero words.
