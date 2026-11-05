# Paired response with partner-relative alignment

Static File #1 US, 2026-11-05. Complete original o2 interval6427C0..643293 reviewed, including dispatch delay slots and phase transitions. No target execution, build, attachment, live memory, input or networking. Addresses, states and descriptor IDs are hexadecimal; explicit durations are decimal. Original action names remain unknown.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6427C0](../recomp/config/output_ovl/o2/o2_006427C0_0x6427c0.cpp) | `update_paired_response_partner_offset_alignment_and_terminal_signals_candidate` | High mechanics; candidate role | a0 actor. Links partner, waits for62, aligns position toward rotated partner offset over16/8 calls, approaches partner-relative yaw, processes animation/actor-effects and63/2/3/4 signals, with release and terminal branches. Four-entry descriptor banks vary with B/B99. Partner lifetime, original subtype and descriptor meanings remain unproven. |

Prelude ORs54A bitsF, sets byte32=FF, and uses positive6673C0 to perform the common immediate idle reset: clear54F/548 bit1, action1/0/1/0, snapshot, select2050 at start0/blend10, activate bank, return. For nonzero A, partner E is computed as42EB00+D90*byte(74F251+60*B1D); the fixed-pool addition's null test is not an index bound. False63EF30(E), or own B1E6, preserves phases A/B/1E/1F/32; phase1 changes toFF only when1B02D0()==1; other phases becomeFF. Class0 and E.C26!=source3 preserves0/1/A/B/1E/1F/32, forcing other phasesFF. Any change from entry A is serialized by67E230(actor,1) BEFORE the newly selected phase body runs.

Let D[i] be descriptor711270+8*(4*B99+i) if B=0, or7112B0+8*(4*B99+i) otherwise. No B99 bound is checked locally. Animation tick is58C300(actor,1); completion comparisons are literal signed low-byte results.

| Phase A | Concrete work |
| --- | --- |
| 0 | A1,54FB0,D101,snapshot, zeroB22/B1E/B9F. Resolve663350(148,149); null selects idle2050/blend10. Success links ownB24/B1D and partnerB1C/B1E1/B1D/sourceB24, clears partnerB28/2C/30; B=bool65F410(source,E,0), E.B1F=B and E.B20=D. C=60 if3243CC zero else30; clear rootXYZ,58C7F0, select2051 start0/blend10, activate bank. No yaw store here. |
| 1 | Pretest signed C: zero sets AFF; otherwise predecrement. B1E62 clears B1E, sets A2, selects D0 start0/blend0, clears rootXYZ, then rotates vector711788=(0,0,35) by partner unsigned yaw92 and adds partnerXYZ into ownC34/38/3C; current XYZ savedC40/44/48. Timer10=16 if3243CC zero else8. Without62 tick animation and clear rootXYZ. A decrement reaching zero expires on the next call. No explicit bank activation after this D0 selection. |
| 2 | If timer10 nonzero, predecrement and interpolate665E60(sourceXYZ,C40,C34,step=total-post,total=16/8). Approach target yaw with665FC0 factor1/2: partner92 when B!=0, partner92+8000 otherwise. Tick animation; positive completion sets A3, D1 start0/blend0, activate bank,6681C0(actor,A). Always clear rootXYZ. |
| 3 | Same yaw approach, tick; result2 calls6681C0(actor,B). Health<2 sets A1E. B1E63 clears B1E and sets A1E irrespective of health. |
| A | Set AB, partnerB1E4, select D2 start36.0/blend10. Clear54A bit1 after selection; prelude sets it again next call. |
| B | Clear54A bit1, tick; positive completion sets AFF. |
| 1E | A1F, ORBA0 bit40000, partnerB1E3. Rotate711798=(0,0,35) by partner yaw/add partnerXYZ intoC34..3C and immediately copy endpoint into ownXYZ. Ownyaw=partner92 when B!=0, otherwise +8000. Select D3 start0/blend10. |
| 1F | Tick; positive completion OR B1E2 clears B1E, sets health0 and A32. |
| 32 | ORBA0 bits120,5F6800(actor,0),54FA0, action4/6/0/0, snapshot; ORBA0 bit1000,67E230(actor,1), clear rootXYZ. No local clear of BA0 bit40000. |
| FF | Byte32=60/30 by3243CC, idle2050 start0/blend15. |
| Other | No own phase body after prelude/admission work. |

Unlike adjacent paired responses, there is no common copy of CF4..CFC to partnerB28..B30 at exit. Phase0's resolver target and local partner variable differ; phase0 has no such exit operation. The phase1 timeout path uses the live FF dispatch argument at642BBC; phaseA uses the dispatch-computed A+1. Neither branch was inferred from a high-level switch alone.

Owned descriptor windows each contain two physical four-entry banks, without proving B99 admission. 711270..7112AF (64 bytes), SHA256`d7f805e2230b352a903772fc7ab1887b0c341ba6cc97351df09df1e21564c61d`: half0=60 and half2=0 throughout; half4/6 pairs bank0=1F,20,22,21; bank1=51,52,54,53. 7112B0..7112EF (64 bytes), SHA256`12e90ce0c93942994667d3305f3d896dc44cebba594b957e2304654ca73b0465`: half0=60; half2=5 in each bank's first entry, zero otherwise; half4/6 pairs bank0=1D,1E,23,1B; bank1=4F,50,55,4D. These are literal packed halfwords, not guessed model/start/end fields.

Owned vectors711788..711793 and711798..7117A3 each contain floats(0,0,35), SHA256`8805febbd291becbc8ade7e27ae9de94eba435b24a2bf509e29b70952ffcbfe3`. Yaw conversion uses owned740188 float6.2831854820251465, word40C90FDB. No runtime wait, partner lifetime, sound playback, performance cost, slowdown or root cause was measured. Original o2 base570000 SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.

Full owned-body audit: 638 original words verified; 55 omitted words all zero/NOP; zero conflicts and zero omitted nonzero words.

Correction from complete child review:6681C0 applies difficulty/RNG-indexed health and BAC changes with optional secondary actor effect;it is not a sound request. Numeric selectors above are actor-effect selectors. No audio playback is established by this child.
