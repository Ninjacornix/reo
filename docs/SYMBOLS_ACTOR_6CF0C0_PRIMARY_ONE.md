# Actor 6CF0C0 primary-one wait, pursuit and turn states

Static File #1 US research, 2026-11-04. Six complete original bodies reviewed.
Addresses and offsets are hex unless marked decimal. Actor identity and original
state names unknown. No target execution, engine changes or slowdown claim.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6CF7E0](../recomp/config/output_ovl/o2/o2_006CF7E0_0x6cf7e0.cpp) | `advance_actor_6cf0c0_idle_wait_on_animation_result_two_candidate` | High mechanics; probable role | Phase0->1,descriptor0/frame0,58C7B0. Phase1 advances at1. Signed-lowbyte result exactly2 predecrements signed E;post<=0 calls1700. Other results only when timer12==0 permit635640(actor,FA),nonzero then17C0. Result2 branch does not run that admission even while E positive. |
| [o2 0x6CF8C0](../recomp/config/output_ovl/o2/o2_006CF8C0_0x6cf8c0.cpp) | `advance_actor_6cf0c0_default_locomotion_wait_and_probe_candidate` | High mechanics; probable role | Phase0->1,descriptor1/frame0,58C7B0,C=decimal10/factor. Phase1 predecrements E;post<0 calls1700. Otherwise timer12==0 and635640(FA) nonzero calls17C0. Remaining BA30 paths predecrement C;post<0 and byte16C nonzero calls1BB0(actor,1,2). Otherwise37A0 accepted ->1/6;rejected ->2E10 steering. All phase1 paths finally advance7290F0[3*BA1],including after state-selection calls. |
| [o2 0x6CFA40](../recomp/config/output_ovl/o2/o2_006CFA40_0x6cfa40.cpp) | `advance_actor_6cf0c0_random_direction_turn_wait_candidate` | High mechanics; probable role | Phase0->1: Bnonzero descriptor7 and signed9A=-decimal204*factor;Bzero descriptor8 and+204*factor;58C7B0. Phase1 adds9A to yaw,predecrements E;post<0 calls1700. Otherwise timer12==0 and635640(FA) nonzero calls17C0. Always advances animation at1 after phase1 selection. Direction semantics remain numeric. |
| [o2 0x6CFB70](../recomp/config/output_ovl/o2/o2_006CFB70_0x6cfb70.cpp) | `advance_actor_6cf0c0_descriptor_zero_timed_target_retry_candidate` | High mechanics; probable role | Phase0->1,descriptor0/frame0,58C7B0. Phase1 predecrements E;post<0 calls17C0,then58C300 at1 regardless whether selection changed state. Unlike7E0,E advances every phase1 invocation and expiry uses<0. |
| [o2 0x6CFC10](../recomp/config/output_ovl/o2/o2_006CFC10_0x6cfc10.cpp) | `advance_actor_6cf0c0_target_locomotion_and_limited_yaw_candidate` | High mechanics; probable role | Phase0->1,descriptor1/frame0,58C7B0. Phase1 predecrements E;post<0 or BD4<BBC calls17C0. Otherwise37A0 accepted selects1/6 via1BB0;else2E10 tries steering;only rejected steering adds634B20(signedBD8,16C) to yaw. Finally advances7290F0[3*BA1] on all phase1 branches,including after transitions. |
| [o2 0x6CFD40](../recomp/config/output_ovl/o2/o2_006CFD40_0x6cfd40.cpp) | `turn_actor_6cf0c0_toward_peer_until_bearing_or_timer_threshold_candidate` | High mechanics; probable role | Every callC821. Phase0->1,descriptor7 when signedBD8<0 else8,frame0;sets positive signed9A=decimal204*factor,58C7B0. Phase1 predecrements E;post<0 or BD8 in inclusive-7FF..7FF calls17C0. Otherwise adds634B20(BD8,signed9A) to yaw. Always phase1 animation advance at1. No forced final yaw snap. |

Owned7290F0 four twelve-byte float records are decimal
(0.3,0.3,0.3),(0.5,0.5,0.5),(0.8,0.8,0.8),(1,1,1). These two locomotion
states read only the first float at byteBA1 index. Caller index range remains
unproven. The timer factor is original byte74F200, not a new frame-rate estimate.

Primary-one secondaries6/7/8 are reviewed in
[alignment transitions](SYMBOLS_ACTOR_6D_ALIGNMENT_TRANSITIONS.md).
Related [bootstrap](SYMBOLS_ACTOR_6CF0C0_BOOTSTRAP.md),
[state selection](SYMBOLS_ACTOR_6D_STATE_SELECTION.md), and
[surface probes](SYMBOLS_ACTOR_6D_SURFACE_PROBES.md).
