# Actor 6BE6C0 paired-joint oscillator work

Static File #1 US research, 2026-11-04. Two complete original bodies reviewed.
Addresses, offsets and state values hexadecimal. Scalar iteration counts decimal.
Bone anatomical names are unknown. No execution, attachment, build or replay.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6C1020](../recomp/config/output_ovl/o2/o2_006C1020_0x6c1020.cpp) | `initialize_sixteen_paired_joint_oscillator_records_candidate` | High mechanics; anatomy unknown | a0 unused. Sixteen records755360 stride1C:statebyte0=0,bonebyte1A=72FCF0[i],half2/4=0,half6=666,velocityhalfE=18A*unsigned74F200,half16=0. Eight even ordinals0,2,..14 receivebyte1=(2+12*k)/factor and byte1D=same,setting paired nextrecordbyte1. Count loops and division entry reviewed. |
| [o2 0x6C1120](../recomp/config/output_ovl/o2/o2_006C1120_0x6c1120.cpp) | `tick_joint_angle_oscillator_six_phase_record_candidate` | High mechanics | a0 overwritten/unused, a1 lowbyte indexes global755360 stride1C. Recordstatebyte0<6 dispatches740E90;otherwise return. Signed anglehalf6,velocityhalfE,accelerationhalf16 and signedbyte1 timer implement all six cases below. No local index bound or original frequency inferred. |

| State | Complete record update |
| --- | --- |
| 0 | Predecrement signedbyte1;positive returns. Otherwise state=1 and falls through state1 in same call. |
| 1 | angle+=velocity, narrowshalf; ifangle>=71D,state++,acceleration=-14*factor. |
| 2 | angle+=velocity,velocity+=acceleration, each narrowshalf; ifangle>=18E3,state++,negatevelocity,negateacceleration then clearacceleration0. The final zero is retained. |
| 3 | angle+=velocity,velocity+=acceleration;angle<9F4 incrementsstate. |
| 4 | angle+=velocity;angle<666 resetsstate1,velocity=18A*factor. |
| 5 | Predecrement signedbyte1;positive returns,otherwise state1 without same-call state1 update. |

Owned72FCF0 length10 bone bytes(decimal):
`[9,10,4,5,6,7,21,22,24,25,27,28,31,32,34,35]`;
SHA256`e2141ed8a3edd79099b8561ad758bb55b641399d403a5ea86373e488377bf388`.
Owned740E90 length18 state targets:
`[6C1164,6C1190,6C1200,6C1280,6C12E4,6C1340]`;
SHA256`45a551e7545c6f0b51ff952c029d889e98dd349abf263539f1a06012604087b8`.
The [owning callback](SYMBOLS_ACTOR_6BE6C0_CALLBACK.md) updates only odd
records, applies their quaternions through58C750, then mirrors them onto even
records by negating the first three quaternion components. The records are shared
global work; exclusive access and per-frame invocation are not established here.
Original factors, narrowing, signed comparisons and timer division are preserved.

Owned image `build-function-index/owned-overlays/o2.bin`,base570000,
SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.

Full-body owned-word audit: 2 rows, 207 verified instruction words,
zero conflicts, 7 omitted zero/NOP words, zero omitted nonzero words.
