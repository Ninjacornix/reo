# Network DNAS: declared MD2 word-state implementation and substitution table

Static File #1 US research, 2026-11-04. Catalogue **o4**, runtime id **5**, base **0x6E0000**, owned `netdnas.bin`, SHA-256 **8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16**. No game, build, replay, attachment, network request, live-memory read or digest execution occurred.

Five complete clear bodies, all256u32substitution entries, the complete18word method descriptor, registry names and implementation label were independently read. [Existing descriptor factory](SYMBOLS_NETDNAS_METHOD_FACTORIES.md) binds MD2 and callbacks706948/706998/706CC0. Sixteen-byte blocks, a16-byte checksum represented as16u32, a48word18-round compression scratch and repeated-length padding support structural MD2 identity. Known-answer parity, corrupted-state admission and complete cryptographic correctness remain untested. No timing, performance claim or gameplay slowdown cause is established.

Context layout is buffered bytecount0,16byteinputbuffer4..13,16u32checksum14..53,16u32chainingstate54..93. Descriptor private-size98hex admits these fields. The substitution table has256distinctu32 values, all0..255, so initialization and valid XOR/table recurrence maintain byte-valued words. This observed invariant is not a validation guard for arbitrary caller-corrupted context. All streaming loop entries and unrolled compression iteration counts were checked explicitly.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x706938](../recomp/config/output_ovl/o4/o4_00706938_0x706938.cpp) | `get_netdnas_md2_integer_implementation_label` | Confirmed owned string identity; implementation parity untested | Returns77D448terminatedASCII`md2(int)`. This is a label getter,notmethoddescriptoror digestexecution. |
| [o4 0x706948](../recomp/config/output_ovl/o4/o4_00706948_0x706948.cpp) | `initialize_netdnas_declared_md2_count_checksum_state_and_input_buffer` | Confirmed initialization/data flow; all-input parity untested | Zeroscount0,64bytesat54chainingstate,64bytesat14checksum,16bytesat4inputbuffer. Doesnotcleartrailingdescriptorpadding94..97orallocate. |
| [o4 0x706998](../recomp/config/output_ovl/o4/o4_00706998_0x706998.cpp) | `update_netdnas_declared_md2_partial_and_complete_sixteen_byte_blocks` | Confirmed streaming/control flow; admission/parity untested | Length0exits. Ifbufferedcountnonzero,fillsthe16bytebufferorcompletesandcompresses706A98;updatesinput/remainingandclearscount. Initialbulkbranchgoestoremaining>=16testbeforeblockcall/decrement,sozero/shortcountsdo notunderflow. Processesfullblocks,thenmemcpytaillength<16tobuffer4andstorescount. Rawu64length,copiedlow32tail,corruptedbufferedcount,aliasandNULLadmissionremainpartial;returnv0notnormalized. |
| [o4 0x706A98](../recomp/config/output_ovl/o4/o4_00706A98_0x706a98.cpp) | `compress_netdnas_declared_md2_block_with_checksum_and_eighteen_substitution_rounds` | Confirmed full recurrence/table/loop structure; parity untested | For16inputbytesbuilds48u32scratch[state16,message16,messageXORstate16];updateschecksum[i] XORtable[message[i]XORpreviouschecksum],startingchecksum15. StartingT0,18roundsvisitall48wordswithword XORtable[T],T=word,thenT=(T+roundindex)&FF. Innerunroll8/startcounter40/decrement8/testafterbodyexecutes6groups=48wordsperround. Copiesfirst16scratchwordstostate54,wipes192bytescratch. Noexternalcallsbesideswipe;inputbufferunchanged. Invalidword>T255canindexbeyondtableunlesscallerstateinvariant holds. |
| [o4 0x706CC0](../recomp/config/output_ovl/o4/o4_00706CC0_0x706cc0.cpp) | `finalize_netdnas_declared_md2_length_padding_checksum_block_and_output` | Confirmed padding/checksum/store flow; parity untested | Padvalue16-bufferedcount fillsremaininginputbufferbytesto16;compressesbuffer. Copieslowbyteofeach16checksumwordintobuffer,compresseschecksumblock,outputs16lowbytesofchainingwords54..93. No fullcontextwipe/countreset/outputcapacity/invalidcountguardlocally;genericfinalizer702448maywipeprivateworkspaceaftercallback. |

Owned method762FA0..762FE7 is `[00000003,00000007,00000010,00706948,00706998,00706CC0,00716A28,007168F0,00000006,00000013,00000000,00000000,00000000,00000010,00000098,00000000,00000000,00000000]`. Owned registry id3 names77E380=`MD2`,77E378=`md2`; its six words at7637F0 are `[0077E380,0077E378,00000003,00000008,00763536,00000000]`. No signature callbacks or digests were executed.

The complete1024byte substitution interval763110..76350F hashes to **ebedb0768ff0c654c08c1bf9b2e2f0b15edea36b2c8a590ed6b0ca20a1dedc4e**. All entries are retained below as data evidence, not more function roles.

| Table address | Eight u32 values, decimal |
| --- | --- |
| `763110` | `41 46 67 201 162 216 124 1` |
| `763130` | `61 54 84 161 236 240 6 19` |
| `763150` | `98 167 5 243 192 199 115 140` |
| `763170` | `152 147 43 217 188 76 130 202` |
| `763190` | `30 155 87 60 253 212 224 22` |
| `7631B0` | `103 66 111 24 138 23 229 18` |
| `7631D0` | `190 78 196 214 218 158 222 73` |
| `7631F0` | `160 251 245 142 187 47 238 122` |
| `763210` | `169 104 121 145 21 178 7 63` |
| `763230` | `148 194 16 137 11 34 95 33` |
| `763250` | `128 127 93 154 90 144 50 39` |
| `763270` | `53 62 204 231 191 247 151 3` |
| `763290` | `255 25 48 179 72 165 181 209` |
| `7632B0` | `215 94 146 42 172 86 170 198` |
| `7632D0` | `79 184 56 210 150 164 125 182` |
| `7632F0` | `118 252 107 226 156 116 4 241` |
| `763310` | `69 157 112 89 100 113 135 32` |
| `763330` | `134 91 207 101 230 45 168 2` |
| `763350` | `27 96 37 173 174 176 185 246` |
| `763370` | `28 70 97 105 52 64 126 15` |
| `763390` | `85 71 163 35 221 81 175 58` |
| `7633B0` | `195 92 249 206 186 197 234 38` |
| `7633D0` | `44 83 13 110 133 40 132 9` |
| `7633F0` | `211 223 205 244 65 129 77 82` |
| `763410` | `106 220 55 200 108 193 171 250` |
| `763430` | `36 225 123 8 12 189 177 74` |
| `763450` | `120 136 149 139 227 99 232 109` |
| `763470` | `233 203 213 254 59 0 29 57` |
| `763490` | `242 239 183 14 102 88 208 228` |
| `7634B0` | `166 119 114 248 235 117 75 10` |
| `7634D0` | `49 68 80 180 143 237 31 26` |
| `7634F0` | `219 153 141 51 159 17 131 20` |
