# Paired timed-turn response and release645220

Static File #1 US, 2026-11-05. Complete original interval645220..6459FF reviewed, including delay-slot timer writes, early directional response and exit partner-offset copy. No target execution, build, attachment, live memory, input or networking. Addresses, phases and descriptor IDs are hexadecimal; explicit durations are decimal. Original action name remains unknown.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x645220](../recomp/config/output_ovl/o2/o2_00645220_0x645220.cpp) | `update_paired_timed_turn_wait62_response_with_three_release_branches_candidate` | High mechanics; candidate role | a0 actor; partnerB20=4, initial16/8-call wait plus10/5-call yaw stepping,62 or1F1 bit40 admission, sound12/13, health terminal and partner4/5 releases. Five-descriptor bank7113C0. Phase0 reads yaw from local s1==0 before resolving partner; caller/state admission and gameplay significance are unknown. |

Prelude OR54A bitsC, byte32FF. Positive6673C0 immediately uses idle reset: clear54F/548 bit1, action1/0/1/0, snapshot667370,2050 start0/blend10, activation58C7B0, return. Entry initializes local partner s1=0. Nonzero A resolves E=42EB00+D90*byte(74F251+60*B1D), without local bounds; class0 E.C26!=source3 forcesFF.

False63EF30(E) or ownB1E6: phases0/1 becomeFF; phases3/4 call668520(actor) and return unless ownB1E63; all other phases retain A. The phase3/4 handler is independently [mapped](SYMBOLS_ACTOR_CONTACT_MULTIPLIER_AND_RESPONSE_GATES.md) as directional response/zero-health selection plus notification. This early return skips common partner-offset copy. Any other change from entry A is serialized67E230(actor,1) BEFORE running the newly selected phase.

Let D[i]=7113C0+8*(5*B99+i), with no local B99 bound. Animation ticks are58C300(actor,1); completion tests use signed low-byte result.

| Phase A | Exact operations |
| --- | --- |
| 0 | A1,54FB0,D101,snapshot; clearB22/B1E/B9F. E timer=10 if3243CC zero else5. Compute signed16((halfword(s1+92)+8000)-own unsigned yaw92)/timerE intoC4E. IMPORTANT: s1 remains zero at this instruction; see boundary below. Then663350(148,149) and assign result to s1. Null -> immediate idle reset. Success links ownB24/B1D and E.B1C/B1E1/B1D=source3/B24=source/B20=4, clears E.B28/2C/30; timer10=16/8 by3243CC; clear own rootXYZ. |
| 1 | Read signed timer10, store10-1 unconditionally in branch delay slot. If pre-value0: advance2, force yaw=partner92+8000,58C7F0,D0 start0/blend10, no explicit activation. Otherwise if timerE!=0 predecrementE, add signedC4E to ownyaw, and on E reaching0 force partner92+8000. Timer10 expiry occurs after16/8 nonzero passes plus the zero-test call; the zero call stores-1 before leaving phase1. |
| 2 | Tick; ownB1E62 OR own1F1 bit40 clearsB1E, advances3, zeroC,58C7F0,D1 start0/blend10, activate bank. No generic positive-completion transition. |
| 3 | Tick; exact2 emits sound12 and advances4. |
| 4 | Tick; exact2 emits sound13. Health<2 setsA9 and skips the63 test; otherwise B1E63 clears it and advances5. |
| 5 | Advance6, partnerB1E4,58C7F0,D3 start0/blend-8. |
| 6 | Tick; positive completion setsAFF. |
| 7 | Advance8,58C7F0,D4 start0/blend-8, partnerB1E5. |
| 8 | Tick; positive completion setsAFF. |
| 9 | AdvanceA, partnerB1E4, set ownhealth0,58C7F0,D2 start0/blend10. |
| A | Tick; positive completion clearsBA0 bit40000. Class1 invokes5F6800(actor,0),54FA0, action4/0/A/0, snapshot and serialization67E230(actor,1). Other classes65FBA0(actor,A). |
| FF | Cooldown32=60 if3243CC zero else30; idle2050 start0/blend10, skipping partner-offset exit. |
| Other | No own phase body; then partner-offset exit. |

Common exit6459C8 copies ownCF4/CF8/CFC floats to E.B28/B2C/B30 if E!=null. Immediate idle, phase0-null, FF and early668520 paths skip this. Phase0 success fills s1 and therefore takes the offset copy in that same call, unlike variants that keep the resolver target only in v0.

## Phase0 low guest-address read boundary

Exact observed instructions:64523C `daddu s1,zero,zero`;6452BC phase0 branch skips nonzero-phase partner lookup;645488 `lh a0,92(s1)` precedes6454C4 call663350 and6454CC `daddu s1,v0,zero`. Thus the first computed yaw step is based on guest address92 rather than the newly resolved partner. The later phase1 endpoint uses resolved partner yaw and overwrites the stepped yaw when E expires. This is a static dataflow observation. Whether phase0 is admitted, what guest memory92 contains, and whether the transient orientation has any player-visible effect remain unknown; it is not evidence of a host null-pointer crash or a measured slowdown.

Owned7113C0..71140F80-byte window contains two physical five-entry banks, literal half0=60/half2=0 throughout and half4/6 pairs: bank0=5,1,2,3,4; bank1=37,33,34,35,36. SHA256`df8d30bc00bd5590dec540fe32cd706654613e81bdf7d69346f0fefeeda51a0a`. Halfword meaning and all admitted B99 indices remain unresolved. Original o2 base570000 SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. No sound playback, elapsed cost, incident reproduction, root cause or controlled fix was measured.

Full owned-body audit: 473 original words verified; 31 omitted words all zero/NOP; zero conflicts and zero omitted nonzero words.
