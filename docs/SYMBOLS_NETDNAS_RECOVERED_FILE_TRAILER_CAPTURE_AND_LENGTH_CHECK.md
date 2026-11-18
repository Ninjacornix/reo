# Recovered file-block digest aggregation and checked trailer comparison

Static File #1 US research, 2026-11-05. Owned o4/netdnas.bin, runtime5, base6E0000, SHA-256 **8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16**. This notebook joins the complete original clear entrance/continuation to one272-word reconstructed payload from the [bulk copied-data inventory](STATIC_DNAS_UPPER_RECOVERY_INVENTORY.md). It adds one supported local role, not a role for every encoded catalogue cut. No guest instructions were executed or emulated; no game, network, build, attachment, live-memory access, original-image change or generated/runtime-code edit occurred.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x7500B8](../recomp/config/output_ovl/o4/o4_007500B8_0x7500b8.cpp) | `check_file_block_digest_xor_and_length_against_provider_decoded_trailer_candidate` | High complete joined local control/data flow; digest/provider mathematics and original file format partial | Queries file length, folds256-byte prefix-block digests over length-160 through74F960, reads trailing32+128 bytes through74FF00, transforms32-byte header via74FD38, checks8 fixed header bytes. Derives provider parameters and requires24 output bytes, compares their first20 to block-digest XOR aggregate and last4 as BE32 against length-160. Returns-1 on child/length failure,0 on checked mismatch,1 on final equality; always performs470 local scratch-byte overwrite calls before code restore. No local minimum-file-size, NULL, extent, stable-file or cryptographic-authenticity guarantee. |

## Complete ownership and copied-data evidence

New isolated [review_dnas_final_owner.py](../tools/function_index/review_dnas_final_owner.py) reads the hash-bound owned image, independently checks original descriptors,49-entry exception lookup, literal entry argument setup, restore argument setup and actual-selector arithmetic. It writes a [complete addressed joined listing](../build-function-index/dnas-final-owner-review/words.txt) and [receipt](../build-function-index/dnas-final-owner-review/receipt.json). All **272 candidate words and56 clear words** were individually read, including every branch delay slot, all five overwrite loops and the balanced return. No instruction field in that listing remains undecoded. Seventeen original exception words are preserved passwise;255 words undergo arithmetic transforms. Actual independently read restore metadata reproduces all272 original payload words exactly.

The owner reserves270hex/624decimal stack bytes, saves S0..S7/FP/RA and F20..F22, captures original path a0 in S0, initializes S2=0 and saved result S3=-1. Header750148 word0 gates the original transform call750120; a nonzero header skips it. Both paths branch750128 to payload75015C, skipping750130..75015C junk/header bytes. All payload paths join75059C, whose branch skips7505A4..7505CC to clear restore setup. Call7505E4 uses literal payload end75059C and the independently read descriptor7505BC. The saved result is moved to V0 at7505EC, all saved registers are restored and JR750624/deallocation delay750628 return;75062C is trailing NOP padding, not a second logical operation.

Catalogue source7500B8 ends750178 inside the reconstructed body. This notebook credits only the complete normal entrance7500B8, with independently traced logical interval7500B8..75062C. Interior catalogue cuts and skipped metadata receive no additional mappings. Encoded-source call edges beyond the clear entrance do not establish a valid recovered call graph.

| Item | Original evidence |
| --- | --- |
| Entry header750148 | `00000000 F789F674 D81953F4 F789F234 00000000` |
| Payload, end exclusive |75015C..75059C,272words|
| Actual restore metadata7505BC | `F476F987 D81953F5 F476FDC7 00000000` |
| Entry inverse slots / actual restore forward slots |4,7,6,7,1,0,7 / 7,0,1,7,6,7,4|
| Exception record |index48 at74577C; relative_base2372decimal; offsets2372,2416,2448,2468,2484,2492,2572,2576,2620,2628,2640,2680,2888,3008,3128,3256,3376decimal|
| Encoded payload SHA-256 |`0f9e231a4f4d3a5e625da4982e73e2c105ff4bfdcec93c4d0e2e67f9055e524a`|
| Reconstructed payload SHA-256 |`95c6b5424ec0679db84c1ad23a9037135ad9f2d2a02e4818cebed7567819e794`|
| Complete joined original interval SHA-256 |`703c7c16226881d067fe83f77fb89ff61f2e480bed92abbc2102ec2e1815dc87`|

Both span operands XOR to440hex/1088decimal. Entry selector low mode bit0 chooses inverse; actual restore low mode bit1 chooses forward. The independent helper selects exceptions with relative_base+4*word_index, rereads both schedules rather than inventing a reverse selector, recomputes the candidate and verifies exact restoration. These are copied integer-data checks, not a guest execution or proof of thread/cache/header-state equivalence. Original header writes/cache flushes are not invoked; arbitrary aliasing into code/header/control state is not admitted by the local contract.

## File acquisition and header gate

Input a0 is used as a path by the reviewed file helpers. Call74F818(path) obtains a seek-derived file length through open/seek-end/close. Negative result keeps-1 and enters cleanup. Otherwise S1 becomes length-160 using32-bit ADDIU, then74F960(path,S1,SP20) produces a20-byte candidate from the file prefix. Its negative result keeps-1. This caller has **no independent length>=160 check**. File size is a guest integer result, not a host64-bit size claim.

Separate full74F960 review establishes an **XOR of independently calculated fixed-block digests**, not a standard streaming hash: it zeros the20-byte caller output, reads each full256-byte block exactly, calls74C6C8(block,256,localDigest20) and XORs those20 bytes into output. A positive final remainder is read into a freshly zeroed256-byte buffer and all256 bytes are digested before XOR, so the last partial block is zero-padded to256. Zero/negative counts perform no reads and leave the aggregate zero if open/close succeed. It still opens and closes in that case; I/O failures return-1 and can leave a partially folded aggregate. Its local256+20 scratch overwrite and possible close retry belong to the child, additional to this owner's470 stores. The inherited digest's exact mathematical standard is unresolved.

Next74FF00(path,SP0,SP170) queries length again and reads32 bytes at its length-160 and128 bytes at its length-128, requiring exact reads and successful close for0; negative result keeps-1. Its separate file operations can produce partial local output on failure. This owner does not prove stable file length/content across the initial query, prefix capture and second trailer acquisition.

Next74FD38(SP0) transforms the32-byte local header in place. Separate full-child review establishes: first74BCE0(76BF78,76BF70,childSP0,1block), then74C168(originalHeader,childSP0,originalHeader,76BF70,4blocks); negative either stage returns-1, otherwise0. It always overwrites8 child scratch bytes. Provider algorithm/direction is unproved and no rollback is promised. Parent7500B8 rejects a negative returned status before inspecting header fields.

It compares exactly8 signed bytes at SP8..SPF to owned76BF80..76BF87. This is bounded equality, not a NUL-string compare: embedded zero is included, and signed subtraction is used only to detect inequality. S2 starts0; the equality loop avoids reading byte8 after eight matches. Header mismatch sets result0 and joins cleanup. A match proceeds to the parameter/provider stage. No other header field is locally interpreted here.

The [file-size route](SYMBOLS_NETDNAS_RECOVERED_PREFIX_DIGEST_AND_FILE_SIZE.md) and the independently reviewed trailer/header helpers supply inherited behavior; none was exercised by this analysis. The literal used as a comparison marker does not by itself identify a file format, content type or security boundary.

## Provider result, capture comparison and length match

For a matching header it copies162 bytes from76BF90 to SPC0. It invokes74BCE0(SPC0,76BF88,SPC0,6blocks), setting saved result=-1 in the call delay slot. Six eight-byte blocks transform48 bytes of the copied162-byte object, not all162 bytes and not a provider mode number. Negative result returns-1 through cleanup.

It then invokes:

`74CCB0(input=SP170,inputLength=128,parameters=SPC0,parameterLength=162,output=SP40,capacity=128,produced*=SP1F0)`

The [previously reviewed padded128-byte provider](SYMBOLS_NETDNAS_UPPER_DIGEST_AND_PADDED_OPERATION.md) retains its mathematical uncertainties. This owner requires status>=0 and produced word **24decimal**; other results keep-1. The produced word is loaded in the status-test branch delay slot even when that status is negative, without being admitted for comparison.

For24 produced bytes it compares first20 bytes SP40..SP53 to the XOR-of-block-digests aggregate SP20..SP33. Initial bytes are loaded once; subsequent signed-byte equality checks advance until the twentieth byte and do not overread byte20. A mismatch sets result0. If all20 match, the final4 produced bytes SP54..SP57 are assembled as BE32:

`word = (SP54<<24) | (SP55<<16) | (SP56<<8) | SP57`

This guest word is XORed against saved length-160, then SLTIU(result,1) yields1 iff equal,0 otherwise. The expected file-size subtraction and constructed word both follow original32-bit guest arithmetic/sign extension; this is not an unrestricted host-size comparison. Result1 therefore means all **local** header/status/produced-length/capture/length checks passed, under inherited admitted inputs. It is not a proof of a particular signature, hash standard, cipher, trusted provenance or absence of file changes.

| Owned input | Bytes / SHA-256 | Static use |
| --- | --- | --- |
|76BF80|8: `7cc9c56668b3bd00`; SHA `7492b471ea21820b29d87e11deef17d350d53bdd2f1b1e54812d6007670b379b`|Header8-byte equality marker after74FD38 succeeds|
|76BF88|8: `f70cdd77be05f067`; SHA `88366de6838771a385c311df860976c659e355b51a1c2aaccb59fc8b55ddbb56`|Fixed parameter passed to74BCE0 for six blocks|
|76BF90|162; SHA `9e5144c60e621ab51e52847f28349e0f2461a398b4dd9d0ba23c1f9485bd6038`|Full object copied toSPC0, first48 transformed, all162 passed onward|

All owned input bytes above were read as immutable data. An ASN.1-like tail or familiar byte count is insufficient to name the provider mathematics; this notebook makes no such inference.

## Common cleanup and reporting limits

Every normal exit, including early file failures, executes five original scaled-LCG byte overwrite loops:

| Scratch region | Byte count | Purpose when reached successfully |
| --- | --- | --- |
|SP0..1F|32|Transformed trailer header|
|SP20..33|20|XOR-of-block-digests prefix aggregate|
|SP40..BF|128|Provider output workspace; only24 admitted as produced|
|SPC0..161|162|Copied/partially transformed provider parameters|
|SP170..1EF|128|Second trailer block|

This is **470 local74AA20 calls/stores** per normal invocation, not a measured timing claim. Base pointers for all loops are established on the early exits too: SP20 is assigned in the first status branch delay slot; SP170 is assigned before/after the prefix-capture branch; SPC0/FP is assigned in the common cleanup-entry branch delay slot. Thus an early failure can overwrite scratch that was never populated by the skipped children. The produced-count word SP1F0 and frame gaps are not included in these five loops.

Each byte follows CVT.S.W, division by binary32 bits4EFFFFFF, multiplication by256(bits43800000), CVT.W.S and the original >=2^31 subtract/convert/OR80000000 correction, then a low-byte store. FP rounding semantics are retained; no secure-erasure or cryptographic-randomness guarantee is asserted. The saved result survives the loops and actual code restore. No caller-output buffer is published by this one-argument owner; external effects are inherited file/provider/envelope effects.

The source-comment audit checks only original catalogue-owned encoded/clear words, separately from the recovered candidate checks. No slowdown was reproduced or attributed, and no performance improvement or runtime fix is claimed.
