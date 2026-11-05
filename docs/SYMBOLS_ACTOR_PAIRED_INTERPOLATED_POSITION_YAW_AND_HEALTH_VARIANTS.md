# Paired position, yaw and health response variants

Static File #1 US owned o2 review, 2026-11-05. Full bodies649850..649EB3,649EC0..64A6CB and64A6D0..64AD9B were read with every branch, delay slot and exit; original instruction audit follows. [Identity](FUNCTION_INDEX.md). No runtime activity or performance measurements. Addresses, states, masks and motion IDs are hexadecimal; durations, vectors and blend values decimal.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x649850](../recomp/config/output_ovl/o2/o2_00649850_0x649850.cpp) | `update_paired_eight_step_position_alignment_yaw_and_two_health_events_candidate` | High complete mechanics; original action unknown | Partner action6, position interpolation toward transformed (140,0,0), stepped yaw correction, health selectors18/19, signal63 release. |
| [o2 0x649EC0](../recomp/config/output_ovl/o2/o2_00649EC0_0x649ec0.cpp) | `update_paired_directional_health_escape_and_terminal_motion_variants_candidate` | High complete mechanics; original action unknown | Partner actionA, direction-dependent entry, health selectors1A/1B, health==1 terminal route, motion-sensitive partner cancellation and extra escape phases. |
| [o2 0x64A6D0](../recomp/config/output_ovl/o2/o2_0064A6D0_0x64a6d0.cpp) | `update_paired_directional_offset_interpolation_yaw_and_health_events_candidate` | High complete mechanics; original action unknown | Partner action17, direction-dependent position/yaw targets and descriptors, selectors28/29, release without a separate ending descriptor. |

Shared notation: E is `42EB00+D90*byte(74F251+60hex*B1D)` for nonzero A. Snapshot=667370; publish=67E230(actor,1); tick=58C300(actor,1), testing signed low8. Immediate idle clears54F/548bit1, selects action1/0/1/0, snapshots, selects2050/start0/blend10 and activates58C7B0. All three set54A ORC and32=FF; nonzero6673C0 immediately idles. Changed A after cancellation publishes before phase dispatch. Unknown phases only perform the prelude. No common partner-offset copy exists in these three bodies.

Common phase0 setup: setA1,54F=B0,D10=1, snapshot, clearB22/B1E/B9F, resolve663350(148,149). Missing partner immediately idles. Success sets own B24/B1D; E.B1C/B1E=1,E.B1D=own3,E.B24=own, clears root4E4/4E8/4EC. Each body's extra writes are below. Phase0 returns rather than starting its descriptor. Phase1 increments A then **falls through phase2**, which increments A again: entering phase1 finishes withA3. All FF phases set cooldown32=60 if3243CC==0 else30 before immediate idle.

## 649850

Nonzero A resolves E. Null computed E setsFF but is followed by classification/accesses; no safe null guarantee. Class0/E.C26!=own3 forcesFF for every phase. Classification63EF30(E)==0 or ownB1E==6 forcesFF only when A<5, retaining higher phases.

| A | Complete behavior beyond common contracts |
| --- | --- |
| 0 | Set E.B20=6. |
| 1/2 | Phase2 increments A; clear halfwordsE/10;58C7F0; selectD0/start0/blend10 whereD[i]=711690+8*(2*B99+i). Transform vector(140,0,0) by E matrix50, add E translation80/84/88; save as C34XYZ, own currentXYZ asC40XYZ. Set signed-half10=8;665E60 interpolates ownXYZ fromC40 toC34 using elapsed8-counter,duration8. Decrement nonzero counter; activate. First interpolation elapsed0, counter becomes7. |
| 3 | Repeat interpolation using elapsed8-counter,duration8; decrement nonzero signed counter. If signed-halfE!=0 decrement it and add signedC4E to yaw. Otherwise call573480(actor,0;f12=0,f13=1); on nonzero result setE=10 if3243CC==0 else5, C4E=signed16(E.yaw-own.yaw)/E using signed integer division. Then tick; result exactly2 applies6681C0 selector18 and increments A. |
| 4 | Tick; result exactly2 applies6681C0 selector19. SignalB1E63 clears signal and increments A; no advance based solely on tick completion. |
| 5 | E.B1E=4;58C7F0; incrementA; selectD1/start0/blend10 without activation. |
| 6 | Tick; positive setsFF. |

Yaw preparation is skipped while the yaw countdown is nonzero. Interpolation does not itself advance phase3. The helper's result exactly2 is distinct from generic positive completion; both health events can therefore depend on original motion event semantics.

## 649EC0

Cancellation computes an invalid flag from null E, E.byte0==0,63EF30(E)==0, ownB1E==6, or (class0, E.C26!=own3,A>=2). Null E skips subsequent E checks. For nonnull E, the byte0 flag does not skip later classification/accesses. Invalid phase2 forcesFF. Invalid phase4 switches to action3/10/0/0, snapshots and publishes, **only** when (B99==0 and motion1F2==1) or (B99==1 and motion1F2==33); otherwise it retains phase4. All other phases retain their A. This is not a general automatic partner-cancellation reset.

DefineD[i]=7116B0+8*(6*B99+i). No local B99 range check.

| A | Complete behavior beyond common contracts |
| --- | --- |
| 0 | E.B20=A. |
| 1/2 | Phase2 increments A; clearE/10,58C7F0. B=boolean65F410(actor,E,0); own yaw=E.yaw+(B==0 ?8000:0). SelectD0 whenB0 elseD5, start0/blend10; activate. |
| 3 | Tick; only result exactly1 continues. B0 selectsD1/start0/blend10. B!=0 subtracts8000 from own yaw and selectsD1/start0/blend0. Activate,incrementA,apply6681C0 selector1A. |
| 4 | Tick; result exactly2 appliesselector1B. If health544==1: clearB1E,setA9,selectD3/start0/blend10, no activation. Otherwise signal63 clears signal and incrementsA. |
| 5 | If E nonnull setE.B1E4;58C7F0;selectD2/start0/blend10,incrementA; no activation. |
| 6 | Tick; positive setsFF. |
| 7 | IncrementA; if E nonnull setE.B1E5;selectD4/start0/blend10, no58C7F0 or activation. |
| 8 | Tick; positive setsFF. |
| 9 | Tick; positive incrementsA. |
| A | Clear BA0bit40000; health544=0. Class1 calls5F6800(actor,0),sets54F=A0,action4/0/A/0,snapshots,publishes. Other classes delegate65FBA0(actor). |

Phases7/8 are admitted by dispatch but not selected by another local phase in this function. This does not prove they are unreachable globally. Phase4's terminal path requires **exactly1** health, not <=1.

## 64A6D0

Cancellation is identical in policy to649850: class0 ownership mismatch forcesFF regardless of phase; invalid63EF30 or signal6 only forcesFF when A<5. Null computed E setsFF but does not prevent later accesses.

| A | Complete behavior beyond common contracts |
| --- | --- |
| 0 | E.B20=17; B=boolean65F410(actor,resolvedE,0); E.B1F=B. |
| 1/2 | Phase2 incrementsA; clearE/10,58C7F0. D[i]=711710+8*(2*B99+i). SelectD1 whenB0 elseD0,start0/blend10. Transform vector7117F0+12*(B&1) by E.matrix50 then add E.translation80/84/88; saveC34target/C40start. Setcounter10=8; interpolate elapsed8-counter,duration8, decrement nonzero counter, activate. |
| 3 | Same interpolation and countdown as649850. Nonzero yaw countdownE decrements and addsC4E. Otherwise573480(actor,0;0,1) nonzero setsE=10 or5 by3243CC; target yaw is E.yaw+8000 whenB0 else E.yaw; signed16(target-own)/E becomesC4E. Tick result exactly2 applies6681C0 selector28 and incrementsA. |
| 4 | Tick result exactly2 appliesselector29. SignalB1E63 clears signal and incrementsA. |
| 5 | E.B1E=4;58C7F0;setA=FF. No new descriptor and no same-call idle selection. |

Signed-half counters decrement whenever nonzero; negative values are not clamped and can run until halfword wrap. B99 bounds, actor/node lifetime and global update cadence require caller evidence. The code preserves the original arithmetic/conversion/division instructions; these notes do not propose replacing them or increasing game speed.

Owned data: all listed descriptor banks have halfwords0/2=60/0 and equal last two halfwords.711690[32] IDs{1,2,33,34}, SHA-256 `aa3ebbe411bef7556f0cca6848d5ac1695cd72600d8226e94a736d88889c9600`;7116B0[96] IDs{9,1,2,3,6,5,3B,33,34,35,38,37}, SHA-256 `594975772e86402d8a6478d3165b2e032b6c03d110dbfedccf762e2b2eea21c4`;711710[32] IDs{1,3,33,35}, SHA-256 `2f4b7fd8cf1991bce98a75252677546746f3966fad4de185a65bb4f367d334aa`. No packed fields are assigned original asset meanings without decoder proof.

7117F0[24] vectors are (20,0,75),(50,0,70), SHA-256 `8677e298e7eae58f8c5d1e08e947365988461ad5effd3284197f0594caa217d5`.711070[4] is binary32(10), SHA-256 `80c8a717ccd70c8809eb78e6a9591c003e11c721fe0ccaf62fd592abda1a5593`. Health selector records18..1B at72F780[16]=`18180000191900001a1a00001b1b0a00`, SHA-256 `5f90df0054a0a6c825cac54ae14badde79e1308a6c4f2ab0fab8c0033f8ab523`;1B has probability byte0A. Selectors28/29 at72F7C0[8]=`2828000029290000`, SHA-256 `86430b7b273f2604ddf7defed697641b7cadccb7696eaf9cce43dbe337f5da7a`.

[Health/gauge implementation](SYMBOLS_ACTOR_PAIRED_HEALTH_GAUGE_APPLICATION_AND_CONTROL_EVENTS.md), [interpolation helpers](SYMBOLS_ACTOR_ACTIONS.md), [classification/snapshot contracts](SYMBOLS_ACTOR_SNAPSHOT_AND_SHARED_CONTROL_HELPERS.md), and [preceding paired responses](SYMBOLS_ACTOR_PAIRED_HIDDEN_TERMINAL_AND_REPEATED_HEALTH_RESPONSE.md) provide supporting context. No action was observed, no health loss measured, and no bottleneck or fix confirmed.
