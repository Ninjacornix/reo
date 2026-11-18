# Recovered o5 DNAS queries and transition-table record transforms

Static File #1 US o5/runtime7/base6E0000,2026-11-05. Owned SHA-256 `97174f5d367cd90bedd5ba397c6492e9fb4bbd0ec7d6021c2be524c49925d38e`. Six existing Partial owners refined through complete clear/recovered/restore/return review. Hexadecimal addresses/offsets; spelled byte counts decimal. No guest execution/emulation,game,build,network,attachment or owned-input mutation occurred.

Authoritative imported roles remain in [protected entries](SYMBOLS_DNAS_PROTECTED_ENTRIES.md). The Reviewed tables below retain supporting evidence without creating duplicate annotation IDs. A private import of all notebook annotations passed after this separation.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| Reviewed [o5 0x701BF8](../recomp/config/output_ovl/o5/o5_00701BF8_0x701bf8.cpp) | `run_reverse_block_workflow_with_owned_eight_byte_parameters` | Confirmed complete recovered adapter mechanics | Copies owned711880[8] to SP0 using original LDL/LDR/SDL/SDR pairs. Calls7056D0(originala0,SP0,originala1,originala2),preserves its result through restore/epilogue. Higher provider semantics remain delegated. |
| Reviewed [o5 0x701D18](../recomp/config/output_ovl/o5/o5_00701D18_0x701d18.cpp) | `query_twelve_byte_driver_reply_dcd29_and_copy_eight_byte_payload` | Confirmed complete recovered query/copy/cleanup flow |703D70(SP0,12,DCD29);negative returns0 without writing caller a0. Nonnegative returns scratch word0 and copies8 scratch+4 bytes to caller. Always overwrites12 scratch bytes through704410 float scaling before restore. |
| Reviewed [o5 0x701EE8](../recomp/config/output_ovl/o5/o5_00701EE8_0x701ee8.cpp) | `query_twelve_byte_driver_reply_57709_and_copy_eight_byte_payload` | Confirmed complete recovered query/copy/cleanup flow | Same exact12-byte local shape as701D18,but RPC selector57709. Negative returns0,no caller copy;nonnegative word0 result/copy8bytes. Always12-byte scratch overwrite and paired restore. Not merely an alias to the other query. |
| Reviewed [o5 0x7020B8](../recomp/config/output_ovl/o5/o5_007020B8_0x7020b8.cpp) | `compose_sixteen_byte_record_from_two_driver_query_payloads` | Confirmed complete recovered composition | Calls701D18(SP0),701EE8(SP10);either result0 yields-401 without caller output. Otherwise writes output[0..7]={second[2],second[1],second[0],first[0],first[7],first[6],first[5],first[4]},zeros output8..15,returns16. Always overwrites both eight-byte scratch payloads before restore. |
| Reviewed [o5 0x702350](../recomp/config/output_ovl/o5/o5_00702350_0x702350.cpp) | `apply_byte_transition_table_selected_cipher_steps_then_final_transform` | Confirmed complete recovered table/control/argument flow | Inputs parameter-table a0/in-place record a1/final key a2/final IV a3/byte transition-table t0/auxiliary parameters t1. Initial opcode=LBU(table0);dispatches through owned711890 for0..7,performs selected705758/705B58 calls with count15hex. After each nonzero opcode reads next opcode from tableBase+opcode;zero ends loop after its selected work. Final705758(record,finalKey,record,finalIV,15) maps nonnegative to0,negative to-1. No step cap or table-extent validation. |
| Reviewed [o5 0x7027A8](../recomp/config/output_ovl/o5/o5_007027A8_0x7027a8.cpp) | `construct_transform_and_export_thirty_two_bytes_from_driver_derived_record` | Confirmed complete recovered record orchestration; provider/format qualified | Input output a0. Copies32 owned7118B0 plus8-byte7118D0/7118D8 views into stack. Requires70B7F0==1 else-8. Derives parameters/transition bytes via705758/701BF8,gets16-byte driver record via7020B8,builds168-byte repeated/reordered record,transforms/digests it and runs702350. Success copies final32bytes to caller,returns0;stage failure-401. Always overwrites all listed scratch areas before restore; no output on local failure. Full construction below. |

702350 uses a transition table, **not a linear bytecode cursor**. Its exact target list at711890 is[702418,70243C,70243C,70243C,702494,702470,702494,702494]. Let R=record a1,K=parameter table a0,A=auxiliary t1,i=current opcode. Define F=705758 and B=705B58; calls use final numeric count15hex:

| Opcode | Selected calls before next-opcode decision |
| --- | --- |
|0|B(R,A,R,A+8,15),then F(R,K+8,R,K,15)|
|1,2,3|F(R,K+16*i+8,R,K+16*i,15)|
|4,6,7|B(R,K+16*i,R,K+16*i+8,15)|
|5|F(R,A+4,R,A+C,15),then B(R,K+50,R,K+58,15)|
|8..255|No selected provider call; still reads tableBase+i for next opcode|

Any selected negative result returns-1 after restore. Opcode0 performs its two selected calls before terminating; it does not mean immediate no-work termination. Repeated/self-referential nonzero table values have no explicit iteration limit. No such cycle was run or observed. Final F uses original a2/a3 after a zero step. The direct jump table was checked against the full joined owner's instruction regions.

Workflow count units are preserved literally.705758/705B58 delegate to704DC8/705530,which expand their count by low32 shift-left3 before generic provider update and require its produced value equal that expanded count. Thus15hex expands toA8hex,10hex to80hex,4 to20hex and1 to8. Earlier dependency labels use bit_count; this review does not infer a new unit solely from that spelling. The surrounding buffers and copy loops here establish explicit byte extents independently.

7027A8 complete record flow:

1. SP0[32] copies7118B0,SP20[8] copies7118D0,SP40[8] copies7118D8.705758(SP0,SP40,SP1B0,SP20,4) derives32-byte scratch parameter area.701BF8(SP40,SP30,1) derives eight transition bytes. Either negative ->-401.
2.7020B8(SP180) must nonnegative. Copy16 bytes to SP50. Copy four bytes from SP18C to SP60,SP188 to SP64,SP184 to SP68,SP180 to SP6C. Copy the resulting SP50[32] to SP70,SP90,SPB0,SPD0,then its first8 to SPF0. This fully materializes SP50[168].
3.705758(SP50,SP1C0,SP100,SP1C8,10hex) derives128 bytes of workspace by the connected expanded-count contract.7060B8(SP50,A8,SP190) computes20 bytes,its return ignored.702350(SP100,SP50,SP1B0,SP1B8,SP30,SP190) must nonnegative. Success copies SPD8[32]—the last32 bytes of the168-byte record—to caller output,returns0.
4. Common cleanup always overwrites SP50[168],SP1B0[32],SP100[128],SP180[16],SP30[8],SP190[20] with scaled704410 bytes. Non-ready and earlier failure paths still traverse these overwrite loops,including unfilled scratch. Exact local result is preserved through actual700B18 restore and full register/float epilogue. No entropy/security guarantee follows from these deterministic overwrites.

These six rows refine the existing [protected entries](SYMBOLS_DNAS_PROTECTED_ENTRIES.md). No interior entry, byte cut, literal or descriptor receives independent credit. [Driver service](SYMBOLS_DNAS_RECOVERED_DRIVER_SERVICE_OWNERS.md) establishes703D70's bounded request/decode/digest/copy contract; [cipher workflows](SYMBOLS_DNAS_CIPHER_WORKFLOWS.md) retain constructor/provider limitations.

Reproduce `python tools/function_index/recover_dnas_o5_family_inventory.py`,then `python tools/function_index/review_dnas_o5_service_owners.py`. The [unique owner checker](../tools/function_index/review_dnas_o5_service_owners.py) verifies original/candidate identities,exact entry guards,actual restore bindings,keyed exceptions,round trips and branch targets. Its [receipt](../build-function-index/dnas-o5-services-review/receipt.json) retains every candidate word and whole-owner hash; [listing](../build-function-index/dnas-o5-services-review/words.txt) includes complete clear envelopes. The [original transform support review](STATIC_DNAS_O5_TRANSFORM_FAMILY_SUPPORT_REVIEW.md) is independent of payload plausibility. No recovered instruction was executed.

Retained identities:owner/span intervals are half-open;words/exceptions are decimal. Original/candidate whole-owner hashes and all words regenerate from the repository helper.

| Owner envelope | Payload | Words / exceptions | Actual restore call | Candidate SHA-256 |
| --- | --- | ---: | --- | --- |
|701BF8..701D14|701C90..701CA8|6/1|701CF0|`034d8117fc8de8c4408f3a0646e6ef713d64c412b9a313a9c82a5883e95ce007`|
|701D18..701EE8|701DA0..701E6C|51/2|701EB4|`d57189279c0b316a9692b65ba6e250841e5d27267592559ef3e0af4e51a44dee`|
|701EE8..7020B8|701F70..70203C|51/2|702084|`36b16a63bff31452a7b633fc37a965591c814e5f09446de45e66e7c813648faa`|
|7020B8..70234C|702144..7022CC|98/4|702314|`c27f479f1f1ee76ebbe4a43f86454ea0695a59c56ed156d5099c603fe431db91`|
|702350..702574|7023F0..7024F4|65/7|70253C|`b163ab2ea1633ac54faae12974d83e56414f2a4884554e5edafe44b8b298ebe7`|
|7027A8..702EF0|7028C4..702E60|359/14|702EA8|`315deeac46ca395f472cc685afcb29d57584341c6e34638499f3d4eb571831ee`|

Original generated-source audit before marking these detail rows Reviewed (the authoritative source rows remain in protected entries): 6 existing owner rows, 228 verified words, 14 omitted zero padding words, zero conflicts and zero omitted nonzero words. This is separate from joined recovered-body verification.
