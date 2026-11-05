# Recovered DNAS query payloads, output adapters and file extraction

Static File #1 US research, 2026-11-05. Owned o4/netdnas.bin, base6E0000, SHA-256 **8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16**. This review reads the complete clear owners around eleven reconstructed spans from [the bulk recovery inventory](../build-function-index/dnas-upper-recovery-inventory.json). Reconstruction is arithmetic on private copied word lists. No guest instruction, game, build, live-memory read, attachment or network operation was performed; original images and generated code remain unchanged.

These are **eleven complete local contracts**, not eleven recovered fragment entrances. Narrow proposed names deliberately retain opaque operation selectors and builder addresses. Original API names, external device meanings, runtime availability and any relationship to gameplay slowdowns remain unknown.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x747EA8](../recomp/config/output_ovl/o4/o4_00747EA8_0x747ea8.cpp) | `capture_dcd29_reply_word_and_eight_bytes_with_scratch_overwrite_candidate` | High complete joined local mechanics; selector meaning unknown | Calls74A380(local,12,DCD29); nonnegative status copies8 reply bytes and returns first word, otherwise returns0; always LCG-overwrites12 local bytes. |
| [o4 0x748078](../recomp/config/output_ovl/o4/o4_00748078_0x748078.cpp) | `capture_57709_reply_word_and_eight_bytes_with_scratch_overwrite_candidate` | High complete joined local mechanics; selector meaning unknown | Same adapter shape with selector57709; full separate owner, metadata and exact restore reviewed. |
| [o4 0x748248](../recomp/config/output_ovl/o4/o4_00748248_0x748248.cpp) | `assemble_state_one_sixteen_byte_payload_from_two_query_replies_candidate` | High complete numeric contract; payload meaning unknown | Requires word767A80==1 and two nonzero reply words; permutes8 selected bytes then zeros8 output bytes; returns16/-401/-8. Two8-byte local scratch blocks are overwritten with LCG-derived bytes. |
| [o4 0x7484F8](../recomp/config/output_ovl/o4/o4_007484F8_0x7484f8.cpp) | `build_forty_byte_output_from_sixteen_byte_query_payload_candidate` | High complete call/argument/cleanup contract; builder semantics unknown | Requires749CD8==1, creates16-byte payload, calls74F1D0 with a1=40/t0=16 and fixed parameter addresses; maps nonnegative builder result to0, otherwise-1. |
| [o4 0x748710](../recomp/config/output_ovl/o4/o4_00748710_0x748710.cpp) | `fill_state_one_thirty_two_byte_ff_payload_candidate` | High complete joined numeric contract | Requires word767A80==1; fills32 output bytes withFF and returns32; otherwise returns-8. |
| [o4 0x748828](../recomp/config/output_ovl/o4/o4_00748828_0x748828.cpp) | `build_fifty_six_byte_output_from_ff_payload_candidate` | High complete call/argument/cleanup contract; builder semantics unknown | Requires749CD8==1, creates32 FF bytes, calls74F1D0 with a1=56/t0=32; returns0 or-1. |
| [o4 0x748A40](../recomp/config/output_ovl/o4/o4_00748A40_0x748a40.cpp) | `capture_c9c69_reply_word_and_five_bytes_with_scratch_overwrite_candidate` | High complete joined local mechanics; selector meaning unknown | Calls74A380(local,9,C9C69); nonnegative status copies5 reply bytes and returns first word, otherwise0; always LCG-overwrites9 local bytes. |
| [o4 0x748C10](../recomp/config/output_ovl/o4/o4_00748C10_0x748c10.cpp) | `split_nibbles_and_reverse_selected_query_bytes_into_five_byte_payload_candidate` | High complete numeric contract; payload meaning unknown | Requires state1 and nonzero748A40 reply word; outputs{q3>>4,q3&F,q2,q1,q0}, returns5/-402/-8; zeros5 scratch bytes. |
| [o4 0x748D68](../recomp/config/output_ovl/o4/o4_00748D68_0x748d68.cpp) | `build_thirty_two_byte_output_from_five_byte_query_payload_candidate` | High complete call/argument/cleanup contract; builder semantics unknown | Requires749CD8==1, creates5-byte payload, calls74F1D0 with a1=32/t0=5; returns0 or-1; LCG-overwrites5 payload bytes. |
| [o4 0x748F80](../recomp/config/output_ovl/o4/o4_00748F80_0x748f80.cpp) | `extract_nine_literal_bytes_after_colon_from_transformed_path_file_candidate` | High complete control/data contract; file identity unknown | Opens bytes produced by747D88, reads seek-reported file size into private allocation, scans LF/colon, copies textual offsets0..3/5..7/9..10 after colon+2; returns9/-402/-8. Input bounds and separators are not fully validated. |
| [o4 0x7492B0](../recomp/config/output_ovl/o4/o4_007492B0_0x7492b0.cpp) | `build_forty_byte_output_from_nine_file_bytes_with_partial_scratch_overwrite_candidate` | High complete call/argument/cleanup contract; builder semantics unknown | Requires749CD8==1, creates9-byte file payload, calls74F1D0 with a1=40/t0=9; returns0 or-1. Original cleanup overwrites only5 of the9 local payload bytes. |

## Joined ownership and reconstruction evidence

New private [review_dnas_query_adapters.py](../tools/function_index/review_dnas_query_adapters.py) binds the owned image hash and the bulk inventory, writes an [addressed complete joined listing](../build-function-index/dnas-query-adapters-review/words.txt) and [receipt](../build-function-index/dnas-query-adapters-review/receipt.json), and leaves all inputs unchanged. It independently rereads each original entry/restore descriptor,49-entry exception lookup, and complete entry/restore argument setup, recomputes candidate words and verifies the actual restore. All **712 reconstructed words** and **470 clear continuation words**, including branch delay slots and every cleanup path, were individually read; no instruction field in that listing remains undecoded. The712 include70 preserved exception words, so642 words actually pass through transform arithmetic. Each actual restore descriptor independently produces an exact original payload restore; the helper does not assume that restore selectors are a guessed reversal. The bulk recovery and [independent primitive review](SYMBOLS_NETDNAS_THREE_ZERO_KEY_RECOVERED_LOCAL_ROLES.md) establish transform arithmetic; this notebook establishes connected local ownership and contracts.

Each clear entrance saves a balanced stack frame and its used callee-saved registers, tests entry header word0, and invokes7457C8 only when that header is zero. It then branches over skipped junk/header bytes to the literal payload start. All reconstructed paths join the clear branch at payload end; that branch skips restore metadata, and the clear glue invokes7457C8 with the independent restore descriptor and literal payload end before restoring registers and returning. No skipped header, exception metadata or catalogue fragment is treated as executable business logic. Entry mode low bit is clear and actual restore low bit is set. Exception selection uses each owned metadata record's relative_base+4*word_index; those original words are preserved in every pass.

Logical return ends below are half-open. Single trailing NOP padding exists after7484F4,748D64 and7492AC; those padding words are outside the connected-body listing. Catalogue boundaries may cut through recovered bodies, so the linked source file is evidence for its original catalogue interval, while the receipt establishes the full joined interval. Interior entries7487A4,748888,748CA0,748DC8 and749370 are not credited as additional functions. In particular748D68 is the full fourth wrapper entrance;748CA0 is an instruction inside the preceding producer.

Header writes, cache flushes1148A0(0)/(2), concurrent entry safety and the runtime header state were neither executed nor simulated. Exact payload restoration alone does not prove whole-envelope or concurrent runtime equivalence. Output pointers aliasing code/header, globals or stack storage could observe effects outside the direct local data contract; no caller alias invariant is invented here. No adapter checks caller output capacity/nullness.

## Three query adapters and two derived payloads

For747EA8/748078/748A40, caller a0 is the output pointer. Their shared local shape is:

1. Call74A380(stack,count,operation), with(count,operation)=(12,DCD29),(12,57709),(9,C9C69).
2. Initialize saved result0 in the call delay slot. If the callee result is negative, skip the direct caller-output copy. Otherwise save stack word0 as result and copy count-4 bytes from stack+4 to output.
3. Overwrite exactly count local scratch bytes with the original scaled-LCG loop, invoke the envelope restore and return the saved result.

The separately reviewed [74A380 packet family](SYMBOLS_NETDNAS_RECOVERED_DRIVER_PACKET_FAMILY.md) decodes its reply and compares a20-byte digest before a successful direct output copy; its own result is0/-1. This establishes a checked local reply path, not a claim of network authenticity or identification of the digest/provider algorithm. A zero first reply word remains distinguishable from the child call's status: these adapters return that word on success and also return0 on failure. Their derived callers intentionally admit any **nonzero** reply word, rather than testing its sign or requiring1. No query-device identity or success observed in a game session is claimed.

748248 first requires word767A80==1. Otherwise result=-8. In the admitted state it calls747EA8(A=stack0), then748078(B=stack10hex), rejecting a zero returned reply word from either with-401. With both nonzero it writes:

`out[0..7] = {B[2],B[1],B[0],A[0],A[7],A[6],A[5],A[4]}`

It then zeros out[15] down through out[8] and returns16. All paths subsequently overwrite A[0..7] and B[0..7] with two independent8-byte scaled-LCG loops. Those loops do **not** XOR or randomize the produced output. The second reply's B[2] is read in the zero-test branch delay slot even on rejection, but no direct output store precedes admission. State/query failure leaves direct caller output untouched under ordinary disjoint inputs.

748710 requires the same state1. It writes out[0..31]=FF and returns32; state failure returns-8 with no direct output store. It has no query or LCG loop.

748C10 requires state1, then calls748A40(Q=stack0). State failure returns-8; zero reply word returns-402. A nonzero reply word produces5 bytes `{Q[3]>>4,Q[3]&0F,Q[2],Q[1],Q[0]}` and returns5. The fifth captured reply byte Q[4] is not included in output. All paths zero five local bytes Q[4] down through Q[0] using literal SB zero, rather than an LCG. Q[2] is loaded in the reply-test branch delay slot on rejection. Arithmetic/output placement is established; serial/version/device interpretation is unknown.

The scaled-LCG overwrite calls74AA20 for every byte, converts its return using CVT.S.W, divides by binary32 bits4EFFFFFF(2147483520), multiplies by256(bits43800000), then uses CVT.W.S and the original >=2^31 correction before storing the low byte. Its conversion depends on the original floating-point rounding state. This is a literal local scratch overwrite, not a claim of cryptographic entropy, secure deletion or equivalence to a modern random-byte API. It occurs on failure paths too; some scratch bytes may never have received query output first.

## Four builder wrappers

Each wrapper takes caller output in a0 and starts with saved result-1. It calls749CD8 into an8-byte local source and requires returned value **exactly1**, then copies all8 source bytes to a second local buffer.749CD8's [separately reviewed contract](SYMBOLS_NETDNAS_RECOVERED_DRIVER_PACKET_FAMILY.md) returns a driver reply word from operation22799; its state/query failure path returns0 and writes only four fallback bytes. Thus these wrappers' equality test is a reply-word admission, not just a generic initialization-success flag, and the fallback partial contents are not copied onward on ordinary failure.

The wrapper next calls its payload producer, admits any nonnegative returned value, then invokes74F1D0 with the exact arguments below. Negative builder result retains-1; nonnegative sets saved result0 using SLTI/MOVZ. Separate full-owner review of74F1D0 establishes a1 as output capacity, a2 as produced-count pointer and t0 as input payload length. It computes required=align8(payloadLength)+24, matching40/56/32/40 for these four fixed producers. It may already modify caller output before a later provider failure. Every wrapper path subsequently overwrites the listed local payload byte count before envelope restoration. No wrapper rolls back a partially written builder output or guarantees atomic failure. The duplicated8-byte source and local produced-count storage are not comprehensively wiped by these local loops.

| Owner | Initial8-byte source / copied source | Payload producer / scratch | a1 capacity | a2 produced-count pointer | t0 payload count | t1 | t2 copied source | t3 | stack+0 | stack+8 | LCG overwrite |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
|7484F8|SP30 / SP20|748248 / SP10|28hex=40|SP40|10hex=16|76BC80|SP20|76BCC0|76BCE0|2|SP10..1F(16)|
|748828|SP40 / SP30|748710 / SP10|38hex=56|SP50|20hex=32|76BCA0|SP30|76BCC0|76BCE0|2|SP10..2F(32)|
|748D68|SP30 / SP20|748C10 / SP10|20hex=32|SP40|5|76BD10|SP20|76BCE8|76BD08|2|SP10..14(5)|
|7492B0|SP30 / SP20|748F80 / SP10|28hex=40|SP40|9|76BD30|SP20|76BCE8|76BD08|2|SP10..14(**5**)|

In every row a0=original caller output and a3=payload scratch. The a2 storage receives a produced count that these wrappers never inspect. Stack offsets are hexadecimal; the two explicit outgoing stack arguments are stored as64-bit values. Fixed parameter addresses above include signed ADDIU after LUI0077; they resolve to **76BCxx/76BDxx**, not77BCxx. Separate74F1D0 review identifies t1 and stack+0 as key/provider inputs and low8(stack+8) as a flag. Its74F1A0 child passes t2 as an8-byte input and splits t3's32-byte parameter structure into provider pointers at+0,+8,+16,+24 for an opaque one-block operation; these are not directly copied metadata words. No standard cipher or original request type is proven. No particular key identity is inferred merely from the addresses. The builder initializes a16-byte header, incorporates the child operation's8-byte result, copies the payload and performs further opaque provider stages; its alignment padding is not explicitly initialized. The wrappers' narrow local labels do not claim cryptographic correctness or complete output determinism.

The final wrapper's five-byte overwrite is an observed distinction: branch bound at749430 is5 despite its producer returning9. This is a static cleanup limitation, not an observed security or gameplay incident. The earlier wrappers are also not claimed to clear all sensitive state.

## File-derived nine-byte producer748F80

This full owner preserves output in s5, initializes allocation s3=0 and file descriptor s4=-1, and returns-8 when word767A80!=1. In state1 it sets result-402 and calls747D88 into24-byte local scratch. That separately reviewed helper transforms a fixed24-byte owned blob using a fixed8-byte parameter through747C68/74BCE0; no decoded string was executed or inferred. This owner nevertheless passes those resulting bytes to file-open118A70 with flags1, establishing their **path use**, not the actual pathname.

Every negative return from747D88, open, seek, read or initial close enters shared cleanup with-402. It opens, seeks118E78(fd,0,2), saves returned length, allocates exactly that length through6E99B0, rejects null allocation, seeks(fd,0,0), reads1190B0(fd,allocation,length), and closes118CF8(fd). Only read<0 is rejected: it does not require read return==requested length. A successful initial close sets fd=-1. A failed close leaves fd live and the common cleanup attempts close again. Allocation/release are existing protected callback wrappers6E99B0/6E9CE8; allocator and I/O behavior were not exercised.

It scans the allocation for LF(0A), replaces the found byte withNUL, then scans from the allocation start for colon(3A). Both scans use the original file length; the colon scan does not stop at the insertedNUL. Both read the initial byte **before** checking whether length<=0. Their loops preincrement and read a new byte before the counter<length test, so a missing delimiter can read allocation[length] before rejecting counter==length. These original bounds are preserved in this analysis; there is no claim that arbitrary/short/malformed input is safely admitted. For negative or zero sizes, unusual allocator results, pointer wrap or early delimiters, the ordinary valid-file explanation must not be extrapolated beyond the actual checks.

After a colon, it advances2 bytes, without validating the intervening separator, and invokes clear7494C8 on that pointer. Independent support-only read of7494C8..7494FC shows a NUL-terminated byte-length loop with wrapping pointer difference; no input bound is passed. It requires the unsigned returned length>=11. Let Q be colon+2. It copies exactly nine literal bytes:

`out[0..8] = {Q[0],Q[1],Q[2],Q[3],Q[5],Q[6],Q[7],Q[9],Q[10]}`

Skipped Q[4]/Q[8] are not checked; no hexadecimal conversion, date parsing or content validation occurs. It releases allocation, clears the saved allocation in the call delay slot and sets result9. Shared cleanup releases any still-held allocation, closes any nonnegative descriptor, zeros24 local scratch bytes and returns through the restore envelope. Cleanup failures do not replace the saved result. No pathname, format name or specific operating-system file identity is established. The clear length helper is a support reference, not an extra mapping credited here.

## Evidence boundaries

The original generated-comment audit applies only to the linked catalogue-owned source intervals against **original encoded/clear words**. It cannot compare reconstructed instructions directly with encoded image bytes; the private exact-restore/hash receipts supply that separate evidence. The ownership table and digests below record all eleven independent payloads and actual descriptors. None of these static findings establishes a slowdown cause, an observed session outcome or a measured improvement.

| Owner / logical return end | Payload interval | Words / preserved exceptions | Entry header / restore metadata | Actual restore JAL |
| --- | --- | --- | --- | --- |
|747EA8..748078|747F30..747FFC|51 / 2|747F1C / 74801C|748044|
|748078..748248|748100..7481CC|51 / 2|7480EC / 7481EC|748214|
|748248..7484F4|7482D4..748474|104 / 6|7482C0 / 748494|7484BC|
|7484F8..748710|748584..748694|68 / 10|748570 / 7486B4|7486DC|
|748710..748828|748784..7487C0|15 / 2|748770 / 7487E0|748808|
|748828..748A40|7488B4..7489C4|68 / 10|7488A0 / 7489E4|748A0C|
|748A40..748C10|748AC8..748B94|51 / 2|748AB4 / 748BB4|748BDC|
|748C10..748D64|748C84..748CFC|30 / 3|748C70 / 748D1C|748D44|
|748D68..748F80|748DF4..748F04|68 / 10|748DE0 / 748F24|748F4C|
|748F80..7492AC|74900C..749234|138 / 13|748FF8 / 749254|74927C|
|7492B0..7494C8|74933C..74944C|68 / 10|749328 / 74946C|749494|

All intervals above are half-open. Header and restore words are copied verbatim below; normalized schedules are independently derived from their original selectors. Metadata indices14..24 have nonempty exception records; offsets are decimal metadata offsets, not absolute guest addresses.

| Owner | Entry header5 words | Actual restore4 words | Entry inverse slots / actual restore forward slots | Metadata index / relative base / preserved offsets |
| --- | --- | --- | --- | --- |
|747EA8|`00000000 7E618F48 D6079EA4 7E618F84 00000000`|`784F816E D6079EA5 784F81A2 00000000`|0,4,7,0,1,6,6 / 6,6,1,0,7,4,0|14 / 5768 / 5784,5888|
|748078|`00000000 CCA874FC D6079F72 CCA87430 00000000`|`CCA8CF47 D6079F73 CCA8CF8B 00000000`|4,7,4,7 / 7,4,7,4|15 / 6232 / 6248,6352|
|748248|`00000000 810EF996 D607A040 810EF836 00000000`|`810699FE D607A041 8106985E 00000000`|6,1,1,7,6 / 6,7,1,1,6|16 / 6700 / 6700,6704,6728,6756,6912,7032|
|7484F8|`00000000 322AAC7A D607A108 322AAD6A 00000000`|`322AAA7C D607A109 322AAB6C 00000000`|2,7,4 / 4,7,2|17 / 7388 / 7392,7448,7468,7476,7460,7484,7492,7516,7576,7464|
|748710|`00000000 409CF065 D607A1DA 409CF059 00000000`|`409C560F D607A1DB 409C5633 00000000`|5,6,0,7 / 7,0,6,5|18 / 7900 / 7900,7904|
|748828|`00000000 3830784D D607A2AC 3830795D 00000000`|`38307D48 D607A2AD 38307C58 00000000`|5,4,0 / 0,4,5|19 / 8204 / 8280,8208,8264,8284,8292,8276,8300,8308,8332,8392|
|748A40|`00000000 7E88A9F9 D607A384 7E88A935 00000000`|`79F9A88E D607A385 79F9A842 00000000`|1,7,1,2,0,0,6 / 6,0,0,2,1,7,1|20 / 8736 / 8752,8856|
|748C10|`00000000 6F83A683 D607A452 6F83A6FB 00000000`|`6F386A38 D607A453 6F386A40 00000000`|3,0,6,2,3,0 / 0,3,2,6,0,3|21 / 9180 / 9180,9184,9204|
|748D68|`00000000 BA4DAFDA D607A51E BA4DAECA 00000000`|`BA4DAADF D607A51F BA4DABCF 00000000`|2,5,7 / 7,5,2|22 / 9548 / 9552,9608,9628,9636,9620,9644,9652,9676,9736,9624|
|748F80|`00000000 CD4F6852 D607A5F6 CD4F6A7A 00000000`|`CD4F2586 D607A5F7 CD4F27AE 00000000`|2,5,0,6 / 6,0,5,2|23 / 10084 / 10084,10088,10108,10124,10148,10168,10192,10212,10228,10416,10552,10572,10588|
|7492B0|`00000000 F9F21FE6 D607A738 F9F21EF6 00000000`|`F6EF12F9 D607A739 F6EF13E9 00000000`|6,6,7,1,2,7,1 / 1,7,2,1,7,6,6|24 / 10900 / 10976,10904,10960,10980,10988,10972,10996,11004,11028,11088|

| Owner | Complete original joined interval SHA-256 | Encoded payload SHA-256 | Reconstructed payload SHA-256 |
| --- | --- | --- | --- |
|747EA8|`d8a0ce7fc9c98448576cfd7eba9131715ae0734d21bf250ee4c3895c5540cd20`|`6f71153d26ea67291bf211a475a6ea740efd6a4b644ef1f6000c27b7c4a13e39`|`7545c03485e2b684a981e7dffb84d975fc7d32be95d20ee7f4b44829f85ec91e`|
|748078|`6767c6b8bc54517a64cc6d1908d0f15649cee25874b7f5508158b1e13dabd3f2`|`65e08dc6069b94b414b9a093671ef6296e11ae99ac0a8fd0e92ef4c5015607ad`|`4a4dc0ce0e98588e9d6d3e1dff26fc99ea1c7951559525e7015b263bd17bf423`|
|748248|`c16b32def66bb81e2c2e9109758460061fedfc478d0a297988093cb11c365044`|`a25ed04bbf4ff8d1189ea10a7d61e9c4369af0ff63a4ea1267ce2337d20f4b92`|`f4183900a5f6fd3a21fc46d0a14f09a37edc296a9d84dfb3df08425b7025238c`|
|7484F8|`24cabea7b571672c3825f8ab8395fbe021cee564b868a55f8b0e26d8d53036e5`|`683de38c02cdb1ce9caa9f066d2352a1c453548c232ae8a6bc0a4c517d74ace8`|`55e3dee56d47d9cd8d90824611d90cdc1401730f531e7f4a6a25b362a807a3f7`|
|748710|`3d45944cb033f4daf21103445143380bfe6f5c1a39c19069e302a7c35b487b1f`|`a9f58bd4580f1c363b286bc7a816867dc22a691887f9fb4e665dbb5efc0284c2`|`50bac3f28e55e30d8fddaae6a0b1d6b46710f49d43e63cf6933aae4f20333dc6`|
|748828|`d2f5d6a7269c4cf8069d03f2bf854811859c5f15abacd43df7cd47a897454a8e`|`9eb2ebf9e9ca81cefcaa19b83aef056906b6140ec46e267dbe69be4a85b66d65`|`05946d32296ee82fabf4ad65bf736b4f82d6368401dc18a855b7f390f2171866`|
|748A40|`12e8cef4fd320d5a52e2a2524cc09aafbfb8ae93c1eaf17ee3a6d6263aad23c2`|`a0824cf1dfe7f5d1b03add587454eea49f9a6eb054004d610eff7bf0cc97e528`|`90155f4c39944d66ecb152fe6220cd68259d861683e4702b60d45816b8a27ec8`|
|748C10|`bf3d1947c82776ab8a194182562bb6ca1a963682ff86a6676a12b4b0747614e5`|`139c75c4dce43c6a987b020f0191eb28da7fe67f8799d10c21d25a6ea47aed9f`|`b8b46a5c45548b9aeee52c9346cd6b8dd41ad79a0e6029fc2f981580f4d3a535`|
|748D68|`5c76d02de788bbbb4e0927d675f8d6fb19cfa145a21274a7328414115f35ccd1`|`06732b6639f9255762fc2cea1bf8fe52f16ca656e864e4c3ac293d3fbb5e5c75`|`a13316e47707f2705f44ce9690a308d433a561b72e41c5997c9cdeea2131e20c`|
|748F80|`e42566f05bfc644669138e551eab30ee6adac7a43ff16d87c489fbe3718bfbcc`|`22fa7dd8cf7cca80150f49a17c37ada85df91ffb9f77c58ba6f772a634715781`|`1696d39efc8325314be5b81c0765c95ac481f65a5706fad40c6510342b22f71f`|
|7492B0|`16bc45c2eb6a8364922660af4bf429ffdd46e0833165599569f6bcd9ae561169`|`141d840dc57252706d005f9d17f1ac2bcc1ba83960c974266136f927b5eb9410`|`14b2f470010fcf2d55a57b1294277b2ee9e6dc00f2fbb56f0905e25fa75b5da1`|

Every row has `payload_roundtrip_exact=true`, verified with its actual separately read restore descriptor. The private receipt retains all original exception words and complete addressed instruction fields. The original owned-image SHA-256 remains unchanged.
