# Paired repeated62 and63 release variants

Static File #1 US, 2026-11-05. Complete original o2 bodies645A00..646133 and646140..6467C7 reviewed. No execution, build, attachment, live memory, input or networking. Addresses, states and descriptor IDs are hexadecimal. Original action names remain unknown; labels describe verified mechanics.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x645A00](../recomp/config/output_ovl/o2/o2_00645A00_0x645a00.cpp) | `update_paired_same_yaw_two62_stages_then63_release_candidate` | High mechanics; candidate role | Links partnerB20=B, copies partner yaw, six-descriptor bank711410; requires62 twice, sounds14/15, health or63 selection, partner4/5 releases and terminal class transition. Positive animation result triggers sound15 while phase3 may persist. |
| [o2 0x646140](../recomp/config/output_ovl/o2/o2_00646140_0x646140.cpp) | `update_paired_opposite_yaw_one62_stage_then63_terminal_candidate` | High mechanics; candidate role | Links partnerB20=C, yaw partner+8000, five-descriptor bank711470; one62 stage, sound16/17,63 jumps to phase7 which zeroes health, plus alternate partner4/5 releases. No local health gate before that phase7 entry. |

Both take a0 actor, OR54A bitsC and set byte32FF. Positive6673C0 immediately clears54F/548 bit1, sets action1/0/1/0, snapshots667370, selects2050 start0/blend10 and activates58C7B0. For nonzero A, partner E=42EB00+D90*byte(74F251+60*B1D) with no local bounds; class0 E.C26!=source3 forcesFF. Changed A is published67E230(actor,1) BEFORE the selected phase body.

Invalid-partner-policy/B1E6 differs:645A00 forces phases0/1/2 toFF and phase3 toFF unless B1E63; higher phases retain A.646140 forces0/1 toFF, and2/3 toFF unless B1E63; higher phases retain A. Fixed-pool arithmetic's null test is not an index/lifetime guarantee.

Phase0 in both setsA1,54FB0,D101,snapshot, clearsB22/B1E/B9F and counterC;663350(148,149) assigns local E. Failure uses immediate idle. Success stores ownB24/B1D and E.B1C/B1E1,B1D=source3,B24=source,B20=B/C, clears E.B28/2C/30, copies E.yaw92 directly (645A00) or +8000 (646140), clears own rootXYZ,58C7F0 and selects D0 start0/blend0 without explicit activation. Local E is populated, so the common offset exit also runs during phase0 success.

D[i] means711410+8*(6*B99+i) or711470+8*(5*B99+i); no local B99 bound. Ticks use58C300(actor,1), and result tests are signed low byte. All descriptor selections below have start0, with blend shown.

##645A00

| A | Exact body |
| --- | --- |
| 1 | Tick. B1E62 clears it, advances2,58C7F0,D1/blend0,activate. |
| 2 | Tick. B1E62 clears it, advances3,58C7F0,D2/blend0,activate,sound14. No generic completion transition. |
| 3 | Tick; ANY positive completion emits sound15, without automatically advancing. Health<2 setsA8 and skips63 test. Otherwise B1E63 clears it and advances4. |
| 4 | Advance5, partnerB1E4 (live v1=4 from dispatch),58C7F0,D4/blend8. |
| 5 | Tick; positive setsFF. |
| 6 | Advance7,58C7F0,D5/blend8,partnerB1E5. |
| 7 | Tick; positive setsFF. |
| 8 | Advance9,health0,partnerB1E4,58C7F0,D3/blend10. |
| 9 | Tick; positive clearsBA0 bit40000. Class1 invokes5F6800(actor,0),54FA0,action4/0/A/0,snapshot,serialize67E230(actor,1); other classes65FBA0(actor,A). |

##646140

| A | Exact body |
| --- | --- |
| 1 | Tick. B1E62 clears it, advances2,58C7F0,D1/blend0,activate,sound16. |
| 2 | Tick; result2 emits sound17. B1E63 clears it and setsA7, skipping3..6. No health test on this transition. |
| 3 | Advance4,partnerB1E4 (live a1=4 retained through dispatch),58C7F0,D3/blend-8. |
| 4 | Tick; positive setsFF. |
| 5 | Advance6,58C7F0,D4/blend-8,partnerB1E5. |
| 6 | Tick; positive setsFF. |
| 7 | Advance8,health0,partnerB1E4,58C7F0,D2/blend10. |
| 8 | Tick; positive clearsBA0 bit40000, then same class-specific terminal transition as645A00 phase9. |

Both FF branches set cooldown32=60 if3243CC zero else30, select immediate idle2050/blend10, and skip partner-offset copy. Other body exits copy ownCF4/CF8/CFC to E.B28/B2C/B30 when E!=null. Unknown phases have no own body beyond prelude/admission and offset copy.

Owned711410..71146F96-byte bank window: half0=60,half2=0,half4=half6; six-entry banks A,B,C,D,E,F and3C,3D,3E,3F,40,41. SHA256`bfd18044e864843c57e0200474fd274dcaff6b7627022638026566961a657a5a`. Owned711470..7114BF80-byte window: same literal half0/2 equality; five-entry banks14,15,16,17,4 and46,47,48,49,36. SHA256`32423b9f86507e0bc334def7c6f1c80c0e9c557e82347b051ca182d367d92c0f`. These packed halfwords are not guessed model/start/end fields; physical two-bank windows do not prove B99 admission.

Repeated positive-animation sound15 is the actual call predicate in645A00, not proof of repeated playback. Signal values and terminal-health behavior do not establish the original animation/action meaning. No runtime wait, partner lifetime, audio playback, elapsed cost, slowdown, root cause or controlled fix was measured. Original o2 base570000 SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.

Full owned-body audit: 828 original words verified; 51 omitted words all zero/NOP; zero conflicts and zero omitted nonzero words.
