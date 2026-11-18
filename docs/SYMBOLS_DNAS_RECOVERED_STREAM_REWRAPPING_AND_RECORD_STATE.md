# O5 DNAS buffered stream rewrapping and record state

Static File #1 US review, 2026-11-05. Catalogue o5 is runtime overlay7, base6E0000, owned `insdnas.bin`, SHA-256 `97174f5d367cd90bedd5ba397c6492e9fb4bbd0ec7d6021c2be524c49925d38e`. Names describe supported local mechanics, not recovered original APIs or an identified gameplay path. No game, target instruction, build, replay, network request or process attachment ran.

Two existing partial rows in [the protected notebook](SYMBOLS_DNAS_PROTECTED_ENTRIES.md) are refined in place. This continues [the tagged-record and prefix-size review](SYMBOLS_DNAS_RECOVERED_TAGGED_RECORD_CHAINS.md). The [copied-data inventory](STATIC_DNAS_O5_RECOVERY_INVENTORY.md) and [reproducible joined checker](../tools/function_index/review_dnas_o5_large_owners.py) retain all original/candidate words, exception offsets and actual entry/restore bindings. The two connected owners below account for **1,163 recovered words in13 spans**. Across all five large owners the checker retains **3,248 recovered words,1,959 clear instruction/padding words and458 checked direct branch targets/delay positions**, with zero unknown admitted instruction fields. Skipped protection-envelope data is separately marked; it is not treated as executed instructions. The [private receipt](../build-function-index/proxy-dnas-o5-large-owner-review.json) and addressed `proxy-o5-owner-6fdc20.txt` / `proxy-o5-owner-6ff5b0.txt` listings can be regenerated from the fixed owned image after regenerating the inventory.

| Existing owner, end exclusive | Refined role | Complete local contract |
| --- | --- | --- |
| `6FDC20..6FF5B0` | `read_rewrapped_container_bytes_with_numbered_tags_and_digest_validation` | Originala0 is **destination**, originala1 requested output bytes. Drives stored reader, constructs a buffered prefix, initializes paired block contexts, calls6FF5B0 for body bytes, validates a numbered digest trailer, releases contexts, and advances record progress. Normal full completion returns original requested count; zero request returns0. Returns actual mismatching reader/helper results or selected-10201/-10202/-299 errors; output/workspace may already have changed. |
| `6FF5B0..7005F8` | `refill_rewrapped_record_output_with_block_padding_and_tag_state` | Originala0 destination, originala1 requested output bytes. Selects a0x154-byte record by global index, drains existing buffered output, then consumes reader input through reverse context, updates digest state, rearranges body/tag/padding bytes and feeds forward context into the output buffer. Normal result is requested minus remaining bytes; errors can return a raw delegated status after partial output. Does not roll back workspace, input consumption or output. |

## Shared workspace and admission limits

Let **W=7703C0**. The prefix probe6FD230 clears this global workspace and installs the reader. These consumers are not reentrant independent stream objects: reader, offsets, context handles, digest block and counters are global. Concurrent-use safety is not established.

| Offset or derived address | Supported use |
| --- | --- |
| `W+FC` | Current record index.6FDC20 increments it on one completion path, admitting the increment only while unsigned index<6; otherwise returns-299. |
| `W+100+0x154*index` | Record chosen by6FF5B0. **0x154 is340 decimal**, from `(5*index+80*index)*4`; the old partial prose must not be read as a0x340-byte stride. |
| `W+E88` | Buffered output bytes. |
| `W+10E88`, `W+10E8C` | Buffered read and write/end offsets. Drain resets both when exhausted. Offset/capacity validation is not comprehensive here. |
| `W+10E90`, `W+10EA0`, `W+10EB0` |16-byte reverse key/IV material and reverse context handle. |
| `W+10EB4`, `W+10EC4`, `W+10ED4` |16-byte forward key/IV material and forward context handle. |
| `W+10ED8`, `W+10EE8` | Incoming16-byte block buffer and consumed/fill cursor. |
| `W+10EEC`, `W+10EFC` | Outgoing16-byte block assembly buffer and assembly count. |
| `W+10F00`, `W+10F40` |64-byte digest block and fill count. |
| `W+10F44` | Reader function pointer installed by6FD230. |

6FDC20 keeps **R0=W+100** in its saved register across its own loop.6FF5B0 independently computes **R=W+100+0x154*W[FC]** on each call. The code does not refresh the caller's savedR0 merely because it incrementsW[FC]. This distinction is preserved literally; no assumption is made that all six records are initialized identically or that arbitrary repeated calls are safe. The original source and mapped callers are the next evidence for resolving that broader format/state contract.

`7073B0`/`7076C0` create forward/reverse masked contexts. `707410`/`707720` update them with a literal count interpreted as16-byte units, checking delegated produced count. `707490`/`7077A0` finalize/release them. These child contracts are documented in [the masked-block notebook](SYMBOLS_DNAS_MASKED_BLOCKS.md); their names do not prove a particular external cipher standard. The caller sometimes ignores digest helper706360's return, so this note does not invent error propagation that the instructions lack.

## 6FDC20: reader prefix, context setup and trailer

Zero requested bytes branches directly to the common count return before protection work. For nonzero demand, the first recovered span copies16 fixed bytes7117E8 to **7705C9=R0+109**. IfR0[0] is nonzero it skips prefix initialization and goes to buffer drain. Otherwise it storesR0[0]=1 **before** reader/validation work, so failure can leave the record marked active.

The prefix initialization performs four exact128-byte reader calls: three buffered destinations and one128-byte local atSP+100. It advances global buffered end offsets between successful reads; a mismatch returns that reader result. It obtains32 bytes through7027A8, constructs32 local bytes plus a16-byte fixed tag711800, and invokes709170 to emit a128-byte forward-transformed block into the buffered prefix. It copies the generated key/IV halves intoW+10EB4/+10EC4 and calls7073B0 to store the forward context atW+10ED4. Original temporary contexts are overwritten with deterministic generator bytes after use.

Three more exact128-byte reads and an exact512-byte read complete the probed0x580-byte incoming prefix. The last numbered83 block is decoded with706A48 intoSP+80, checked against711788 at output+20, and its first32 bytes saved toSP+1C0.7091D0 transforms a128-byte block from the assembled prefix intoSP+80, zeroes saved context, and checks7117A0 at output+A. Output bytes0,4,5 become later numbered selectors and output byte2 is stored atR0+C0.

Further numbered decodes check7117D0 and literal native version20005, then7117B8. The version mismatch returns the preceding zero transform status without completing setup. After the final tag, the first four output bytes are copied natively toR0+A8 and output bytes8/9/A are retained in the record. These drive aligned region lengths:

| Record field | Exact use established by producer and consumer |
| --- | --- |
| `R0+A8` | Native payload length, copied from decoded first four bytes. |
| `R0+B8` and `R0+BC` | First block-prefix count, original and remaining, from decoded byte8. |
| `R0+B9` | Decoded byte9, retained as a format field; no stronger name required here. |
| `R0+BA` and `R0+BD` | Second block count, original and remaining, from decoded byteA. |
| `R0+A4` | `round_up_16(length +16*byte8 +16)` using32-bit arithmetic. |
| `R0+B4` | `round_up_16(length +16*byteA +16)`. |
| `R0+BE` | Alignment padding used in the second calculation, stored as a byte. |
| `R0+C0` | Numbered-record selector used for the trailing128-byte record. |
| `R0+0C..2B` |32 bytes decoded from the localSP+100 numbered record after711818 tag admission. |

The owner copies the first/second16-byte halves ofR0+0C intoW+10E90/+10EA0 and creates the reverse context7076C0 atW+10EB0. It overwrites the source scratch and key/IV copies with deterministic bytes after creating the context. It sets digest flagR0+8C=1, remaining transformed outputR0+4=R0+B4 and record byte progressR0+8=0.

The main loop first drains buffered prefix bytes to the caller, decrementing requested remaining count and incrementing read offset. WhenR0[0]==1, R0+4==0 and no buffered bytes remain, it zeroes the first four record bytes, incrementsW[FC], and continues only for index<6; otherwise returns **-299**. Otherwise it asks6FF5B0 for the lesser of requested remaining and record remaining. It requires that helper result to equal the requested subcount; any other value is returned verbatim, including a positive value. Caller output/reader progress already performed is retained.

When the record body is exhausted, it reads exactly128 bytes intoSP, decodes with the stored selectorR0+C0, checks711830 at output+14, and finalizes the streaming20-byte digest with706360 flag4, stateR0+8D and total lengthR0+A4. It compares that20-byte state to the decoded output: mismatch selects **-10202**. Fixed-tag mismatches select **-10201**. It releases nonzero forward/reverse context handles, clears each stored handle only after successful release, reads another exact128-byte block into the buffered output, restores this final protected span, and resumes until the caller request is filled. Buffer construction, counter changes and earlier output are not rolled back on any failure.

## 6FF5B0: block refill and byte-state transitions

The complete helper returns0 on zero request. It otherwise drains buffered bytes first and only refills while the request remains. The current record is selected by0x154 stride at entry; no local index<6 check is added here. Normal completion returns original request minus remaining, or original request when the drain fills it exactly. A short reader result, nonzero context status, invalid padding counter(-1) or failed fixed tag(-10201) returns directly through the balanced epilogue, even if earlier output was copied.

Before the ordinary body loop:

1. IfR+BC is nonzero, read an exact16-byte input block intoW+10ED8, append its bytes to the64-byte digest accumulator, and invoke706360 whenever full usingR+8C as flags; after a full block set that flag to2. Run one reverse-context update in place, decrement the byte-sizedR+BC and advance record progressR+8 by16. Repeat through the common drain/refill loop.
2. IfR+BC is zero butR+BD is nonzero, generate16 deterministic bytes atW+10EEC, run one forward-context update into the buffered output, append16 output bytes and decrementR+BD. This path emits generated padding rather than reading an extra input block.

For ordinary input, while unsignedR+8<R+A4, read exactly one byte, incrementR+8, append to the incoming16-byte assembly and to the64-byte digest block. The first byte at/past `R+A8+16*R+B8` can setR+108 from0 to1 and capture the current incoming-block cursor as a local split limit. After source exhaustion, R+BF is admitted only while<17; it supplies bounded additional filler using up to16 fixed bytesR+109 and then generator bytes. An out-of-range value returns-1. These are literal local checks, not a whole malformed-record safety proof.

Once the incoming block is16 bytes, it applies the reverse context in place whileR+108<3. It then uses the following state to assemble the outgoing block and tag scratch. Two structurally similar loops cover an existing partial outgoing block and leftover reverse bytes after the first output block; both were read, including branch-likely delay slots.

| `R+108` | Supported byte routing and transition |
| --- | --- |
|0 | Copy ordinary reverse-transformed input bytes fromW+10ED8 intoW+10EEC while advancing incoming and outgoing cursors. |
|1 | Before the captured split limit, preserve reverse bytes. Beyond it, consume reverse bytes intoR+C4 using countR+104 while emitting fixedR+109 bytes followed by generator bytes as replacement padding. A partial collected tag at a block boundary promotes the state to2. |
|2 | Continue collecting reverse bytes intoR+C4 and emitting replacement padding. At exactly16 collected bytes, compareR+C4 to fixed16-byte711848; mismatch returns-10201, equality sets state3. The three protected ranges include the two copies of this exact tag check; neither is a new function. |
|3 | Emit replacement padding from the fixed16-byte pool and then generator bytes; the source tag has already been admitted. |

The fixed-pool cursorR+14C and tag countR+104 are distinct; they are not game-frame counters. `R+BB` can retain a pending input cursor when the16-byte block is finished, andW+10EFC tracks a partial outgoing block. Every completed outgoing block calls707410 with count1 into the buffered output and advances its end offset by16. The helper continues until it has copied the requested number of output bytes or a delegated/local error exits. It neither finishes/releases the contexts nor compares the20-byte trailer digest;6FDC20 owns those steps.

## Limits and static identity

The helper verifies the actual canonical restore calls for all13 spans in these two owners; prior-stage errors may bypass those calls and leave a descriptor active. Full5-owner byte reconstruction is reproducible using the independently reviewed original operator families and exact exception membership. Recognized instruction fields and branch-target containment support the static review; they are not execution tests or a proof of all possible caller states.

Original joined SHA-256:6FDC20..6FF5B0=`30a0e82fc865127f8fea950939f72843a94d1d7b1e255e1e786306b862fa421b`;6FF5B0..7005F8=`295f9bf76e99f6aa947decf82e2e142c2dd9e7ac15f1df03e73325f92817d100`.

Remaining unknowns include the original container/protocol name, full multi-record initialization contract, buffer-capacity invariants, delegated cryptographic conformance and whether these installation/service paths run during ordinary offline gameplay. No rendering, VU optimization, source translation or performance fix is implemented by this mapping.
