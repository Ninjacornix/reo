# Paired hidden terminal and repeated health response

Static File #1 US owned o2 analysis, 2026-11-05. Full bodies 648BA0..649013 and 649020..64984B, including all branch targets, delay slots and exits, were reviewed against owned instructions. [Binary identity](FUNCTION_INDEX.md). No game execution, build, live process access or timing measurement. Addresses, states, masks and motion IDs are hexadecimal; blend values and counters are decimal unless marked.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x648BA0](../recomp/config/output_ovl/o2/o2_00648BA0_0x648ba0.cpp) | `update_paired_hidden_wait_partner_follow_and_terminal_response_candidate` | High complete mechanics; original action unknown | Partner action 1A, hidden wait for signal62, descriptor selection followed by partner transform copying, then terminal health/state transition. Complete contract below. |
| [o2 0x649020](../recomp/config/output_ovl/o2/o2_00649020_0x649020.cpp) | `update_paired_directional_repeated_health_response_and_release_candidate` | High complete mechanics; original action unknown | Partner action14, timed signal62 admission, direction-dependent descriptor banks, repeated health/gauge selectors24..27, signal63/health escape and peer offset publication. Complete contract below. |

For both entries, E denotes the computed partner `42EB00 + D90 * byte(74F251 + 60hex * B1D)` on nonzero A. This arithmetic and its nonzero test do not establish valid index/lifetime or a safe null guard: both bodies continue using E after their null branch sets A=FF. Snapshot means 667370, state publication means 67E230(actor,1), animation tick means 58C300(actor,1) with signed low-byte completion result. Root XYZ means 4E4/4E8/4EC.

## 648BA0

Prelude sets 54A OR1F and 32=FF. Nonzero 6673C0 switches to action1/4A/0/0, snapshots and returns, retaining 54F/548 and without selecting an idle motion. For nonzero A, class0 with E.C26 != own3, 63EF30(E)==0 or own B1E==6 forces FF. If this prelude changes A from its incoming value, state is published before dispatch.

| A | Full phase behavior |
| --- | --- |
| 0 | A1,54F=B0,D10=1; snapshot; clear B22/B1E/B9F. Resolve 663350(148,149). Failure switches to action1/4A/0/0 and snapshots. Success links own B24/B1D and E.B1C/B1E=1, E.B1D=own3, E.B24=own, E.B20=1A; clears root XYZ and **falls through phase1 in the same call**. |
| 1 | Increment A, call58C7F0, select motion1010 with start0/blend2; no activation call. |
| 2 | Hide render byte1 every call. Wait B1E==62; on match increment A, show render byte1, call58C7F0 and select descriptor7115D0+8*(2*B99+1), start `2/(3243CC==0 ? 2 : 1)`, blend0. Copy E position and yaw directly. Signal62 remains set. |
| 3 | Tick. Nonpositive result copies E position/yaw. Positive result hides actor, sets health544=0, BA0 OR120, calls5F6800(actor,0), sets54F=A0, switches action4/8/0/0 and snapshots, BA0 OR1000, publishes state, clears root XYZ. |
| FF | Set cooldown32=60 if3243CC==0 else30; query616F20(XYZ,mask3). Type3 switches action1/4A/0/0 and snapshots, retaining54F/548 and no idle selection. Other types clear54F and548bit1, switch action1/0/1/0, snapshot, select2050/start0/blend10 and activate58C7B0. |
| other | Prelude only. |

There is no common partner-offset copy. Owned7115D0[32] holds four packed eight-byte descriptors, halfwords (60,0,B,B),(60,0,C,C),(60,0,3D,3D),(60,0,3E,3E); SHA-256 `fd6d2f6ccc38e31ad3a26b8ae539fcf177cb4fe6b7b815eedfc64552ad8f767b`. B99 is not locally bounded; the body uses only the second descriptor in each two-record window.

## 649020

Prelude sets54A ORC and32=FF. Nonzero6673C0 uses immediate idle: clear54F/548bit1, action1/0/1/0, snapshot,2050/start0/blend10 and activation. For nonzero A, invalid classification63EF30(E)==0 or B1E==6 retains phaseB; phase1 forcesFF only when1B02D0()==1 (session mode zero); other phases forceFF. Class0/E.C26 mismatch forcesFF only when current A>=2. Prelude changes publish before dispatch.

Define D[i] as `(B==0 ? 7115F0 : 711640) + 8*(5*B99+i)`. Descriptor selection uses5D50E0. No local B99 bound or descriptor membership validation is present.

| A | Full phase behavior |
| --- | --- |
| 0 | A1,54F=B0,D10=1; snapshot; clearB22/B1E/B9F; resolve663350(148,149). Failure uses immediate idle. Success links own B24/B1D and E.B1C/B1E=1,E.B1D=own3,E.B24=own; clears E.B28/B2C/B30. Set B to boolean65F410(actor,E,0); yaw=bearing own->E plus8000 when B!=0. E.B1F=B,E.B20=14; C=60 if3243CC==0 else30; clear rootXYZ,58C7F0,select2051/start0/blend10 and activate. |
| 1 | Refresh same bearing-dependent yaw. If signed C==0 setFF and leave. Otherwise decrement C. Signal62 increments A, clears signal, selectsD0/start0/blend10 and activates. Without signal tick and clear rootXYZ. |
| 2 | Refresh same yaw, tick. Positive result increments A, sets signed-half E=byte7110A0 (6), and signed-half10=1. The halfword E is initialized but not consumed elsewhere in this body. |
| 3 or5 | Increment A. Read byte7110A0+signed-half10; zero selectsD1, nonzero selectsD2. Select start0/blend0 and activate. Neither table index nor counter sign is locally bounded. |
| 4 | Set A6; apply6681C0 selector24 when B0 else26, then execute phase6 tick/escape checks immediately. |
| 6 | Tick. Positive result increments signed-half10, setsA5, applies6681C0 selector25 when B0 else27. Then health544<2 setsA=A. SignalB1E==63 clears signal and setsA=A. If1B0310()==1 and A==A, publish state; class1 temporarily ORs BA0 with10000000 for that publication and clears the bit afterward. |
| A | Increment toB; set E.B1E=4. SelectD3/start0/blend10, without activation. |
| B | Tick; positive result setsFF. |
| FF | Set cooldown32=60 if3243CC==0 else30; immediate idle with2050/start0/**blend15** and activation. This exit bypasses partner-offset copy. |
| other | Prelude and common partner-offset copy only. |

After ordinary phase exits, a nonzero E receives own CF4/CF8/CFC into E.B28/B2C/B30. This also occurs on phase1 timeout and after the terminal/escape phase updates; immediate reset, partner-resolution failure and FF idle exits bypass it. No claim is made that the fixed-pool prelude validates E for this write.

Owned7115F0[80] has ten descriptor records, halfword0=60,halfword2=4 throughout and equal last two halfwords with IDs{1,2,3,4,9,33,34,35,36,3B}; SHA-256 `88a4304d526d3cd57b1cddd4277112df0870c87612c156cdaabf5b9394445f5d`. Owned711640[80] has IDs{5,6,7,8,9,37,38,39,3A,3B}, halfword2=5 except indices4/9 which are4; SHA-256 `96ecd7f276d3649ee789a1baf62524be8d66d30e441164ab53478d0c8aa633e4`. The reviewed literal prefix7110A0[16] is `06000100010001ff06000100010001ff`, SHA-256 `afa395d29904d124190e7bae0cf21a0810d4f395076b67a1d4d4f22ee70bb772`; FF is treated as nonzero by this body, not as a local termination sentinel. The bounded prefix does not prove the counter remains inside it. Health/gauge selector records24..27 at72F7B0[16] are `24240000252500002626000027270000`, SHA-256 `2111ea0403ca2550a2b6eaf1982845bb518221b5f498a14838fc0111e54a3742`.

[6681C0 health/gauge application](SYMBOLS_ACTOR_PAIRED_HEALTH_GAUGE_APPLICATION_AND_CONTROL_EVENTS.md) establishes these are health/gauge requests, not sound calls. [Snapshot and classification helpers](SYMBOLS_ACTOR_SNAPSHOT_AND_SHARED_CONTROL_HELPERS.md) and [adjacent paired fall responses](SYMBOLS_ACTOR_PAIRED_JOINT_FALL_AND_TERMINAL_RESPONSE_6474.md) provide supporting contracts. Original character/action names, runtime reachability, update cadence and cost remain unknown; this static review confirms no slowdown cause or fix.
