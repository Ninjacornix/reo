# Network DNAS: declared MD5 streaming implementation and compression tables

Static File #1 US research, 2026-11-04. Catalogue **o4**, runtime id **5**, base **0x6E0000**, owned `netdnas.bin`, SHA-256 **8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16**. No game, build, replay, attachment, network request, live-memory read or digest execution occurred.

Five complete clear bodies, all64round constants, all48message-index bytes and the owned endian probe were independently read. The [owned descriptor and MD5 registry identity](SYMBOLS_NETDNAS_HANDSHAKE_MESSAGE_ADAPTERS.md) independently bind initialization706DB0/update706E00/finalization707340. The compression loop has four16round groups with the expected choose/majority-like/parity/inverted Boolean forms, indexed word schedules and rotation groups. **Structural MD5 identity is well supported; full input-domain correctness and known-answer parity were not tested.** No timing, throughput improvement or gameplay slowdown cause is established.

Context layout: four32-bit chaining words0..C, bitcount low10/high14,64-byte block18..57,buffered bytecount58. Declared workspace96bytes admits this layout but does not prove arbitrary corrupted-state safety. The bulk-loop initial branch goes to the count test before the decrementing branch-likely delay slot; count0 does not underflow through a block operation.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x706DB0](../recomp/config/output_ovl/o4/o4_00706DB0_0x706db0.cpp) | `initialize_netdnas_declared_md5_state_counters_and_block_buffer` | Confirmed state/data flow; all-input digest parity untested | Stores67452301/EFCDAB89/98BADCFE/10325476at0/4/8/C,zerosbitcounts10/14andbuffered58,tailmemset64bytesat18. Completecontextinitialization,nomemoryallocationorinputprocessing. |
| [o4 0x706E00](../recomp/config/output_ovl/o4/o4_00706E00_0x706e00.cpp) | `update_netdnas_declared_md5_stream_bitcount_buffer_and_blocks` | Confirmed streaming/count/control flow; admission/parity untested | Length0skipsallwork. Addslen<<3tosplit32bitcountwithcarry/highpart. Existingpartialbufferfilledorcompleted;completeblock706FC8. Remaining>=64guard precedessubtract64andfullblockcopy/compression;tail<64copiedandcount58set. Rawcalleru64lengthvsAPIzeroextended32length,corruptedbufferedcount,alias/NULL/negativecountandcounteroverflowdomainsnotadmitted. Returnv0notnormalizedtosuccess. |
| [o4 0x706FC8](../recomp/config/output_ovl/o4/o4_00706FC8_0x706fc8.cpp) | `compress_netdnas_declared_md5_block_with_four_sixteen_round_groups` | Confirmed full round/table/rotation structure; parity untested | Reads4statewordsand16inputwords. Ownedprobe77D5B0=[1,0,0,0]makeslw==lbu,skippingalternate16wordinplacebyteswapbranchfororiginalownedvalue. Four16roundgroupsuseowned64constants;round1messageindex0..15,rounds2..4owned48byteindices;rotations7/12/17/22,5/9/14/20,4/11/16/23,6/10/15/21. ApplieschooseF,conditionalG,XORH,invertedIformswith32bitadd/rotate/permutation,addsoriginalchainingwordsback. No externalcalls. No transformedinputimmutabilityclaimonalternateprobevalueor vector/overflowparitytest. |
| [o4 0x707340](../recomp/config/output_ovl/o4/o4_00707340_0x707340.cpp) | `finalize_netdnas_declared_md5_padding_bit_length_and_sixteen_byte_output` | Confirmed padding/length/store flow; all-input parity untested | Writespadding80atbufferedindex;whenbuffered>=56zeroestoblockendandcompresses,resetsfillindex0. Zeroestofinaloffset56,writessplitbitcountlittleendianat56/60,compresses,writes4chainingwordslittleendianintocaller16byteoutput,setsbuffered58=0. Doesnotwipefullcontextoradmitinvalidbufferedcount/outputcapacity;genericfinalizer702448laterwipesprivateworkspacewhenusedthroughthatAPI. |
| [o4 0x7074F8](../recomp/config/output_ovl/o4/o4_007074F8_0x7074f8.cpp) | `pack_netdnas_sixty_four_input_bytes_as_little_endian_words_then_compress_md5` | Confirmed four-by-four word packing/call flow; parity untested | Fouriterationsread16bytesandexplicitlyassemblefourlittleendianu32intostack64bytes;then706FC8(originalcontext,stackwords). Loopsinitialcount4anddecrementsafterfirstread;exactly64bytesloaded. No inputextent/NULLadmissionorbufferwipe. Not a standalone digest or gameVUprogram. |

Complete owned interval77D480..77D5B3 hashes to **c512d1c60d70d8d712df55eacb2783d914e89e570859d55504c88b1d17f41721**. The data below is evidence, not additional function roles.

| Constant address | Eight u32 constants |
| --- | --- |
| `77D480` | `D76AA478 E8C7B756 242070DB C1BDCEEE F57C0FAF 4787C62A A8304613 FD469501` |
| `77D4A0` | `698098D8 8B44F7AF FFFF5BB1 895CD7BE 6B901122 FD987193 A679438E 49B40821` |
| `77D4C0` | `F61E2562 C040B340 265E5A51 E9B6C7AA D62F105D 02441453 D8A1E681 E7D3FBC8` |
| `77D4E0` | `21E1CDE6 C33707D6 F4D50D87 455A14ED A9E3E905 FCEFA3F8 676F02D9 8D2A4C8A` |
| `77D500` | `FFFA3942 8771F681 6D9D6122 FDE5380C A4BEEA44 4BDECFA9 F6BB4B60 BEBFBC70` |
| `77D520` | `289B7EC6 EAA127FA D4EF3085 04881D05 D9D4D039 E6DB99E5 1FA27CF8 C4AC5665` |
| `77D540` | `F4292244 432AFF97 AB9423A7 FC93A039 655B59C3 8F0CCC92 FFEFF47D 85845DD1` |
| `77D560` | `6FA87E4F FE2CE6E0 A3014314 4E0811A1 F7537E82 BD3AF235 2AD7D2BB EB86D391` |

| Round | Complete16message indices |
| --- | --- |
| 2 | `1 6 11 0 5 10 15 4 9 14 3 8 13 2 7 12` |
| 3 | `5 8 11 14 1 4 7 10 13 0 3 6 9 12 15 2` |
| 4 | `0 7 14 5 12 3 10 1 8 15 6 13 4 11 2 9` |

Owned endian probe77D5B0..77D5B3=`01 00 00 00`. Shipped probe value is an observed constant, not a live-memory measurement.

The independently read connected one-shot adapter is recorded separately below; the five streaming/compression bodies above remain the algorithm core.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x7075F8](../recomp/config/output_ovl/o4/o4_007075F8_0x7075f8.cpp) | `compute_netdnas_declared_md5_once_with_optional_global_output` | Confirmed lifecycle/data/control flow; known-answer parity untested | Inputsdataa0,lengtha1,outputa2. NULLoutputselectsguestglobal7F1D98;initializesstackcontext706DB0,updates706E00,finalizes707340,zeros5Chexcontextbytes,returnsoutputpointer. No callerbufferextent,sharedglobalconcurrencyorfullalgorithmparityproof;no digest executed. |
