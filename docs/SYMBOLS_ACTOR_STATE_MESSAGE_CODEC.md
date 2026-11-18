# Actor state message construction, bit codec and gated publication

Static File #1 US, 2026-11-05. Eight complete original o2 bodies reviewed, including all branches, loops and delay slots of the large 637C10 dispatcher. No execution, build, attachment, input, network traffic or live memory. Addresses, offsets, opcodes and flags below are hexadecimal; bit widths and explicit array counts are decimal. These are observed serialization roles, with original protocol/message names unknown.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x637C10](../recomp/config/output_ovl/o2/o2_00637C10_0x637c10.cpp) | `construct_actor_state_message_by_opcode_and_update_snapshot_candidate` | High mechanics; candidate role | a0 actor, a1 full opcode, a2 byte counter pointer. Rejects B9C==1, or B9A!=0 with room1E2 unequal to runtime snapshot22. Otherwise increments caller byte, writes shared scratch header/type length/owner, dispatches the cases below and updates selected snapshot fields. Unknown opcodes still increment/header-write. No send, queue, allocation or publication call in this body; no defined success return. |
| [o2 0x63ABB0](../recomp/config/output_ovl/o2/o2_0063ABB0_0x63abb0.cpp) | `publish_shared_actor_message_after_owner_admission_candidate` | High mechanics; candidate role | a0 actor. Class3 chooses publication mode3 for 34/2B/1D/14/13, otherwise mode2. B9A!=0 requires 681970(2,B98)!=0; B9A==0 requires runtime4BADED equal to 1B0240(room1E2). Admitted call1AFDD0(8,74F210,0,mode), with scratch opcode32 forcing mode4. Does not construct or clear the scratch message. Mode meanings and actual backend delivery remain separate. |
| [o2 0x63FE10](../recomp/config/output_ovl/o2/o2_0063FE10_0x63fe10.cpp) | `append_low_order_integer_bits_to_byte_stream_candidate` | High mechanics; candidate role | a0 integer value, a1 current destination, a2 signedlow8 bit offset, a3 signedlow8 bit width, t0 output-offset pointer. Requires nonnull destination, width1..32 and offset0..7. Appends low bits least-significant-first across bytes, preserves bits below initial offset, clears bits above each written fragment, arithmetic-shifts input between fragments; returns advanced byte pointer and writes final offset. Rejection returns original pointer without writing output offset. No capacity check. |
| [o2 0x63FF40](../recomp/config/output_ovl/o2/o2_0063FF40_0x63ff40.cpp) | `read_low_order_integer_bits_from_byte_stream_candidate` | High mechanics; candidate role | a0 output word pointer, a1 current source, a2 signedlow8 offset, a3 signedlow8 width, t0 output-offset pointer. Same source/width/offset admission as writer. Reads fragments least-significant-first into zero-based word, returns advanced pointer and stores final offset. Does not sign-extend extracted fields. Rejected input leaves output word/offset untouched. No source-length/output-pointer validation. |
| [o2 0x640050](../recomp/config/output_ovl/o2/o2_00640050_0x640050.cpp) | `encode_float_xyz_as_three18bit_integer_fields_candidate` | High mechanics; candidate role | a0 float XYZ, a1 destination, a2 initial bit offset, a3 output-offset pointer. Original guest cvt.w.s on each coordinate followed by three width18 writes63FE10, carrying pointer/offset. Returns final byte pointer and stores final offset. This is integer quantization and low-bit packing, not writing IEEE float bytes. No explicit range clamp. |
| [o2 0x6400E0](../recomp/config/output_ovl/o2/o2_006400E0_0x6400e0.cpp) | `decode_three_signed18bit_xyz_fields_to_integer_words_candidate` | High mechanics; candidate role | a0 destination three words, a1 source, a2 initial bit offset, a3 output-offset pointer. Three width18 reads63FF40, bit20000 sign extension by ORFFFC0000, writes signed integer words. Returns final byte pointer and stores offset. It does not convert results to float. Depends on admitted helper inputs; no independent error propagation. |
| [o2 0x640210](../recomp/config/output_ovl/o2/o2_00640210_0x640210.cpp) | `decrement_actor_c2e_timer_when_global_tick_bit_is_set_candidate` | High mechanics; candidate role | a0 actor. Nonzero signedhalfC2E and runtime word4BADE8 bit1 admit decrement; narrows/store then clamps post<=0 to0. Zero or cleared global bit makes no store. Original timer name and producer of global tick flag unresolved. Concrete countdown behavior, not a generic return stub. |
| [o2 0x640250](../recomp/config/output_ovl/o2/o2_00640250_0x640250.cpp) | `retain_top_four_target_scores_and_emit_compact_rank_words_candidate` | High mechanics; candidate role | a0 actor, a1 four output halfwords. C20 enables four BF8 scores; C21 enables ten C0C scores. Inserts nonzero signed scores into four descending temporary ranks, later equal score before earlier rank. Clears both ten-entry source rows, restores retained scores masked1FF0, and emits maskScore OR slotIndex OR group<<13. Zero temporary ranks skip destination stores; destination is not cleared. Alters actor score matrix as part of serialization. |

For 637C10 let `A` be actor, `B=74F210` shared message scratch, and `R=74F250+60*A.B98` (60 hexadecimal = 96 bytes). `Q` means three guest cvt.w.s conversions of A38/3C/40, stored as signed words R10/14/18; `Y` means signed yaw92 stored as wordRC; `H` means signed health544 stored as halfR1C. A notation `Bxx<-Ayy` denotes a literal byte/halfword copy as stated, not an original field name. Existing [actor response record wrappers](SYMBOLS_ACTOR_RESPONSE_RECORD_EVENTS.md) call construction and then 63ABB0 only when their counter is nonzero; [direct record events](SYMBOLS_RECORD_EVENT_SERIALIZATION.md) also reuse the XYZ codec and scratch. That connection supports message construction/publication roles, without assigning original protocol names.

Admission happens before the counter/header stores. B9A nonzero compares unsignedhalf A1E2 against byte `R22`; B9A zero skips this room comparison. Admitted work increments `*a2` modulo256, sets B0=lowbyte(a1), B1=owned710640[a1], B3=A.B98. B2 is untouched. Length lookup uses full a1 before dispatch, with no local range check. Case51 and unknown cases perform no payload stores after the header. Caller contracts must supply valid opcode, scratch serialization and actor/snapshot lifetimes.

All dispatcher targets and payload families were reviewed. This table deliberately retains numeric opcodes; independent message names have not been recovered. Widths following a slash are decimal bits.

| Opcode(s) | Original case PC | Observed payload and snapshot operations |
| --- | --- | --- |
| 00 | 637EF4 | Q,Y,R20=BA3; action bytes8..B to B4..7, timersC/E to B8/A, yaw to BC. Starting BE: XYZ/18 each, BA3/4, four BF8/13 then four C0C/13. B26=C26 with class1 bit80 from pointer24; B27=R45; R7=B26; clear R45 bit20. |
| 01 | 638124 | Q,Y,R20=BA3; same action/timer/yaw prefix and BE XYZ/18,BA3/4, but only four BF8/13. B1C=C26 with class1 bit80 from pointer24; B1D=R45; R7=B1C; clear R45 bit20. |
| 02 | 638310 | Q,Y,H; same action/timer/yaw prefix, BE=health544, B10/11=149/14B, B1D=R45. Starting B12: XYZ/18,148/5,14A/5,140/3,141/5,B1F/3,C2E/10. Signed C2E>=400 clamps to3FF; negative values keep low bits. Clear R45 bit20. |
| 06 | 63852C | Q,Y,R20=BA3; action8..B toB4..7; E toB8,yaw toBA; D00/04/08 each multiplied1.5 then cvt.w.s/byte toBC/D/E. Starting B10: XYZ/18,BA3/2,four BF8/13,six C0C/13. BF=C26 with bit80 iff C25==1; B28=R45; R7=BF; clear R45 bit20. |
| 07 | 638784 | Same Q/Y/R20/prefix and scaledD00/04/08 as06; startingB10 XYZ/18,BA3/2,four BF8/13 only. BF=C26 with class1 bit80 from pointer24; B1E=R45,R7=BF; clear R45 bit20. |
| 08 | 63899C | H; signed health544 to B4 half. |
| 09 | 6389B4 | R21=B9E; B4=runtime3B5050[B98],B5=B9E. |
| 0A | 6389E8 | Q,Y,H,R20=BA3; actions8..B toB4..7,timersC/E toB8/A,yaw toBC,health toBE,B18=R45; startingB10 XYZ/18 and BA3/4. Does not clear R45 here. |
| 0E | 638B5C | Q,Y; four signed BF8 halves toBC..12; XYZ lowhalves toB4/6/8,yaw toB14,E toB16; bytes9,D21,C9B,D23,D24 toB18..1C. |
| 11 | 638C7C | Q,Y,H; XYZ lowhalves B4/6/8; A10,D16,yaw,health,C2E halves toBC/E/10/12/14; bytes9/140/148/149/14A/14B/141/B1F/13E/D22/D25 atB16..20 in the literal body order; C26 toB21 only when D16!=0. |
| 12 | 638DE4 | Q,Y; XYZ lowhalves B4/6/8,yaw BC; bytesD21/D25/C26/D26 toBE/F/10/11. |
| 13 | 638EB0 | Q,Y; XYZ lowhalves B4/6/8,yawBC; four BF8 halves toBE..14; byte9 toB16,C26 toB17. |
| 14 | 638FA0 | Only converted X lowhalf toB4; no Q snapshot update. |
| 18 | 638FB8 | Actions8..B toB4..7; four BF8 halves toBC..12; timersC/E toB8/A. |
| 19 | 639044 | Actions8..B toB4..7. First loop also writes four halves C/E/10/12 toB8/A/C/E; second loop rewrites C/E toB8/A. StartingBC packs four BF8/13 then six C0C/13, overwriting part of first-loop temporary payload. |
| 1C | 639160 | Q,Y; timerE toB4,byte9 toB6,CE7 toB7. |
| 1D | 6391CC | Q,Y,H; XYZ lowhalves B4/6/8,yawBC,healthBE,CE4 B10; bytes148/149/14A/14B/141 toB12..16. |
| 1E | 6392C4 | Converts C44/48/4C toR10/14/18 instead of actorXYZ; R2A=C2B,BB=C2B; codec640050(C44vector,B4,0,out). |
| 1F | 639338 | Q,Y,H,R39=D7B; action/timer prefixB4..B,yawBC,healthBE; B18=R43,B19=R45,B1A=R39; startingB10 XYZ/18 thenBA3/4. |
| 20 | 639478 | Same Q,Y,H,R39=D7B and prefix as1F, B18=R43,B19=R45; startingB10 XYZ/18 thenBA3/4. Does not write B1A. |
| 21 | 6395AC | Y,H; action/timer prefixB4..B,yawBC,healthBE,B10=R45. |
| 22 | 639658 | Actions8..B toB4..7,yawB8; codec640050(actorXYZ,BA,0,out). No Q/Y snapshot writes. |
| 28 / 2B | 6396BC / 63970C | 28 first Q,Y,R20=BA3 then falls through shared2B payload; 2B skips those snapshot updates. Two actions8/9 toB4/5,timersC/E toB6/8,yawBA; XYZ/18 thenBA3/4 and four BF8/13 startingBC. B1A=A.B,B1B=C26,class1 bit80 from pointer24; B1C=R45; R7=B1B; clear R45 bit20. |
| 29 / 2C | 63988C / 6398DC | 29 first Q,Y,R20=BA3 then falls through2C payload; 2C skips these snapshot writes. Same two-action/timer/yaw/BC bit prefix as2B, plus six C0C/13 after four BF8/13. B24=A.B,B25=C26,B26=R45. Class1 branch literally ORs bit80 into B1B, not B25; R7 gets B25; clear R45 bit20. |
| 2A / 2D | 639AA0 / 639AE4 | 2A first Q,Y; 2D skips Q/Y; both H,R20=BA3. Action/timer prefixB4..B,yawBC,healthBE; B10/11=14B/149,B1D=B1E,B1E=R45. StartingB12: XYZ/18,BA3/4,148/5,14A/5,140/3,141/5,B1F/1,C2E/10 with same upper clamp3FF. Clear R45 bit20. |
| 2E / 2F | 639CE8 / 639D30 | 2E first Q,Y; 2F skips Q/Y. Two action/timer prefix,yawBA; startingBC XYZ/18,B1F/2. B14=B1E,B15=C26 with bit80 from B24 pointer's class1 (different pointer from cases00/01/07/2B). R7=B15. |
| 32 | 639E54 | B4=A6,B5=C2B,R2A=B5. |
| 34 | 639E7C | B4=A6,B5=runtime74F289+60*B98 (same R39); R39=B5. |
| 35 | 639EC0 | Q; codec640050(actorXYZ,B4,0,out). |
| 37 | 639F20 | R7=B1D; actions8..B toBA..D; timerC toB4,timer12 toB6,C26 toB8 with bit80 iff C25==1. |
| 38 | 639FA8 | C9B/C9A toB4/5. |
| 3B | 639FC4 | Q,Y; XYZ lowhalves B4/6/8,yawBC,E toBE,8/9/C9B toB10/11/12; top-four score encoder640250(actor,B14) also mutates score matrix. |
| 3C | 63A0A4 | Q,Y; XYZ lowhalves B4/6/8,yawBC,8/9 toB10/11; class3==2B additionally signedhalfD56 toBE. Other classes leaveBE untouched. |
| 3D | 63A174 | Q,Y; XYZ lowhalves B4/6/8,yawBC,E toBE,8/9 toB10/11. |
| 3E | 63A234 | Q,Y,H; XYZ lowhalves B4/6/8,yawBE,healthB10,C2E B12,9 toB14; status148/149/14A/14B/141/B1F/13E toB16..1C. |
| 3F | 63A350 | Q,Y,H; healthB4,status148/149/14A/14B/141/B1F/13E toB6..C. |
| 40 | 63A400 | Q,Y,H; XYZ lowhalves B4/6/8,yawBC,healthBE,E toB10,8/9/zero/B/C26 toB1A..1E; top-four score encoder640250(actor,B12). |
| 41 | 63A508 | Q,Y; XYZ lowhalves B4/6/8,yawBC,timer12 toBE,9/C9B toB10/11; class3==2B additionally D22 toB12,otherwise retains priorB12. |
| 42 | 63A5E4 | Q,Y,H; sets R45 bit1,CE8 toB4. |
| 43 | 63A64C | Q,Y,H; XYZ lowhalves B4/6/8,yawBC,9 toBE. |
| 44 | 63A6FC | Q,Y; C9B/C9A toB4/5. |
| 45 | 63A75C | Q,Y,H; same literal health/status payload as3F. |
| 46 / 59 | 63A80C | Q,Y; writes actor health544=-1 AND R1C=-1. B4=9,B5=140,status148/149/14A/14B/141/B1F/13E toB6..C. This case changes source health as well as serializing. |
| 47 | 63A8CC | Q,Y,H; XYZ lowhalves B4/6/8,yawBC,8 toBE,AD0 toBF. |
| 48 | 63A988 | 8/9 toB4/5. |
| 4A | 63A9A4 | Q,Y; XYZ lowhalves B4/6/8,yawBC,timer12 toBE,9/CF2 toB10/11. |
| 50 | 63AA64 | Lowbyte room1E2 toB4,AD0 toB5. |
| 51 | 63AB8C | Header and caller counter only; direct return. |
| 57 | 63AA80 | Q,Y; XYZ lowhalves B4/6/8,yawBC,8/9 toB16/17; A.B first writes B18 then D6F overwrites B18; C26 toB19; top-four score encoder640250(actor,BE). |
| 58 | 63AB6C | C26 toB4,old R45 toB5,then clear R45 bit20. |
| Other | 637EEC | Header/counter already changed, no payload work; return via63AB90. No local unsupported-opcode error flag. |

The complete owned length lookup window710640..710699 for opcodes00..59 is 90 bytes, SHA256`55b047ee2670559890b0dfef4265037a59d40b87f74c7ce2be5e86cc1982fc2a`. Literal lengths by ascending opcode, decimal:

```text
00..0F: 40 30 30 42 42 42 42 32 6 6 26 42 42 42 30 42
10..1F: 42 34 18 24 6 42 42 42 20 30 42 42 8 24 12 28
20..2F: 26 18 18 16 42 42 42 42 30 40 32 30 40 32 22 22
30..3F: 42 42 6 14 6 12 6 14 6 6 16 28 18 18 30 14
40..4F: 32 20 6 16 6 14 14 16 6 6 18 16 12 16 16 14
50..59: 6 6 10 10 6 8 10 26 6 14
```

The maximum declared length here is42 decimal, but this is a lookup contract, not a capacity validation: neither writer nor dispatcher checks caller destination capacity or upper opcode bounds. Case00 packs four C0C scores, whereas06/19/2C pack six and640250 considers ten when C21 admits. Those are actual separate layouts, not evidence of interchangeable score-row counts.

63FE10 uses chunks `min(8-offset,remainingBits)`; entry jumps to the count test before the first chunk. Width0/negative/>32 or invalid initial offset exits untouched. For valid inputs each iteration progresses, and reaching offset8 advances pointer then resets offset0. Writing a partial byte keeps only prior low bits below offset, then ORs the new fragment: high unused bits become zero. This explains why appending fields must carry the returned pointer AND offset. 63FF40 reverses this low-first layout but yields an unsigned low-width word; signed18 conversion belongs to6400E0, not the generic reader.

640250 ranks up to four group0 slots and ten group1 slots only when their enable bytes C20/C21 are nonzero. Temporary rank score is unsignedhalf on load, incoming source score is signedhalf; negative scores cannot outrank initialzero. Equal positive scores insert ahead of prior rank, shifting triples to rank3. It clears both ten-half source rows before restoring only retained masked scores. Each nonzero rank emits `(score&1FF0)|slotIndex|(group<<13)`. A score1..F can therefore survive ranking but become zero in the restored matrix, while its emitted identity bits may remain nonzero. Empty ranks leave corresponding destination halfwords untouched. This is destructive top-four reduction and encoding, not a read-only visualization of all scores.

Literal differences needing caller/consumer admission evidence include case2C's bit80 store toB1B while its target identity isB25, case57's deliberate sequential overwrite ofB18, source-health mutation in46/59, and untouched fields in class-conditional cases3C/41. They are documented as mechanics, not confirmed defects or slowdown causes. Large inbound dispatcher63ACA0 and the main1AFDD0 implementation remain separate review work; this pass does not prove transport delivery, packet admission, thread safety, cost or any runtime fault.

Original o2 base570000 SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. Shared storage74F210/R records are beyond the owned file-backed end743100; their initialization/contents were not read. Full owned-body audit: 3,456 original words verified, 75 omitted words all zero/NOP; zero conflicts and zero omitted nonzero words.
