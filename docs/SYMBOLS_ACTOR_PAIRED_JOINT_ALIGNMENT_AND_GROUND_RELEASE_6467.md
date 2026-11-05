# Paired joint alignment and ground release variants

Static File #1 US owned o2 analysis, 2026-11-05. Complete bodies6467D0..646F8B and646F90..647407; all branches and exits reviewed. No game execution, attachment, live memory, builds or runtime tracing. Hexadecimal offsets/states/descriptors; counts explicitly decimal. Original action names remain unknown.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6467D0](../recomp/config/output_ovl/o2/o2_006467D0_0x6467d0.cpp) | `update_paired_opposite_yaw_joint_alignment_then_recoil_and_directional_release_candidate` | High full-body mechanics; action meaning candidate | PartnerB20=12, three-descriptor bank7114C0, horizontal-distance blend/150, alignment to partner model node1D, health/gauge selectors22/23, signal63 release, descriptorCB attachment, then1042 recoil with signed timer and movement-factor ramp. Full phases below. |
| [o2 0x646F90](../recomp/config/output_ovl/o2/o2_00646F90_0x646f90.cpp) | `update_paired_same_yaw_two_descriptor_ground3_release_candidate` | High full-body mechanics; action meaning candidate | PartnerB20=15, two-descriptor bank7114F0, phase0 falls through descriptor initialization, completion lowersY to184-160, alternateFF selects ground3-dependent recovery. No63EF30/B1E cancellation prelude in this variant. |

Both OR54A and set32=FF (6467D0 maskC,646F90 mask1F), save incoming phaseA, consume6673C0. Nonzero result immediately uses idle:54F=0,548 bit1 clear,action1/0/1/0,667370 snapshot,2050 start0/blend10,58C7B0 activation. Partner for nonzeroA is `E=42EB00+D90*byte(74F251+60hex*B1D)`; class0 with E.C26!=source3 forcesFF. The computed pointer's nonzero test is not a valid-index/lifetime proof. Changes from savedA publish67E230(actor,1) before phase dispatch.

6467D0 additionally calls63EF30(E): zero while A<5 forces5. B1E==6 and A==4 with frame1E4 not less than1EC also forces5.6470 variant has neither check. Both phase0 setA1,54F=B0,D10=1,snapshot,clearB22/B1E/B9F,resolve663350(148,149); failure uses idle. Success links ownB24/B1D and partnerB1C/B1E1,B1D=source3,B24=source,B20=12/15, clears own4E4/4E8/4EC.6467D0 returns after linking,6470 sets own yaw=partner yaw and falls through phase1 and2 initialization.

For6467D0, D[i]=7114C0+8*(3*B99+i); for646F90 D[i]=7114F0+8*(2*B99+i). Descriptor arguments start0/blend0 except where stated. No B99 bound is local.

##6467D0 phases

| A | Complete phase behavior |
| --- | --- |
|1|A++ then falls through2.|
|2|A++,58C7F0,Ehalf=0; forms horizontal partnerXYZ-ownXYZ (Y explicitly zero), sqrt(length squared)/150 clamped only above1, normalizes this temporary vector. Calls5D56D0(actor,D0,D1,f12=1-weight), activates. Aligns XYZ with665E60(current,current,partner node(model34+894).XZ with currentY,elapsed1,duration2) and wrapped yaw with665FC0(current,current,partnerYaw+8000,1,2). The normalized temporary is not used by these later calls locally.|
|3|A++,5D57D0(actor,1,actor1F8),6681C0 health/gauge selector22,then same position/yaw alignment as2.|
|4|5D57D0(actor,1,1F8); low result byte2 applies6681C0 health/gauge selector23. Copies ownX/Z directly from partner node894 translation30/38. Signal B1E63 clears it and advancesA; otherwise stays. Always interpolates yaw toward partner+8000.|
|5|PartnerB1E=4,58C7F0,A++,yaw=partner+8000,D2/start0/blend0. Clears115 bit1 and attaches descriptorCB/bank0.|
|6|58C300(actor,1), positive signed low-byte result advancesA.|
|7|A++,1042/start0/blend10,115 bit1 set. C=40 decimal if3243CC0 else20, C8=-16, D4=C8/C; immediately C8-=D4,E0=C8,C--.548 bit1 set,B90=0,B94=1/(1E8 if3243CC0 else1E8/2),then5DE4C0(actor). No zero-frame-length guard locally.|
|8|58C300(actor,1); positive signed result setsA=FF, but still processes current timer. If C!=0 predecrements/narrows; new0 subtracts allremainingC8,otherwise subtractsD4; storesC8/E0. Next invocation performsFF policy.|
|FF|Cooldown32=60 decimal if3243CC0 else30;668520(actor) directional/health response and state publication.|
|other|No phase-local writes beyond common prelude.|

No common partner-offset copy follows6467D0; each phase returns after the listed operations. In particular phase0 success does not initialize descriptor/motion until another call.

##646F90 phases

| A | Complete phase behavior |
| --- | --- |
|0|Successful link falls through1 and2 as described above.|
|1|A++ and falls through2.|
|2|A++,58C7F0,D0/start0/blend0,yaw=partnerYaw,58C7B0; returns.|
|3|A++ and falls through4.|
|4|Tick58C300(actor,1); positive signed low-byte result advancesA.|
|5|A++,Y=actor184-160 decimal,58C7F0,D1/start0/blend-32.|
|6|Tick; positive selects action1/4A/0/0 and snapshots.|
|FF|Cooldown32=60/30 by3243CC,616F20(XYZ,byteout,mask3). Returned type3 selects action1/4A/0/0 and snapshot, regardless returned height. Other types use immediate idle2050/start0/blend10.|
|other|No phase-local operation beyond prelude.|

Owned7114C0[48] SHA-256 `7e4791cb9a2d5db79c24c438c2e90a24b938fa96b6c6adda5d7a382fdc89f9c1`: six8-byte records have half0=60,half2=0,half4=half6={1,2,3,33,34,35}. Owned7114F0[32] SHA-256 `aa3ebbe411bef7556f0cca6848d5ac1695cd72600d8226e94a736d88889c9600`: same literal shape, IDs{1,2,33,34}. These physical two-bank windows do not prove runtime B99 admission or interpret packed field names.

Connected [preceding paired variants](SYMBOLS_ACTOR_PAIRED_REPEATED62_AND63_RELEASE_645A.md), [alignment math](SYMBOLS_ACTOR_ACTIONS.md), [state classification](SYMBOLS_ACTOR_SNAPSHOT_AND_SHARED_CONTROL_HELPERS.md), [directional release](SYMBOLS_ACTOR_CONTACT_MULTIPLIER_AND_RESPONSE_GATES.md), [motion helpers](SYMBOLS_ANIMATION.md) and [effect41 constructor](SYMBOLS_EFFECT_BURST_CONSTRUCTION.md). Signal63, health/gauge requests and animation completion do not establish an observed interaction, duration or slowdown. Original o2 SHA-256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226` at base570000.
