# Network DNAS: primary protection dispatcher and boundary inventory

Later update,2026-11-05: [all63 primary spans were reconstructed as copied data](STATIC_DNAS_PRIMARY_RECOVERY_INVENTORY.md), then reviewed within their connected owners. [The owner ledger](STATIC_DNAS_O4_OWNER_RECONCILIATION.md) preserves the current partition accounting. The metadata and hashes below remain the original evidence; this earlier boundary investigation itself assigned no decoded payload credit.

Static File #1 US research, 2026-11-04. Catalogue **o4**, runtime id **5**, base **0x6E0000**, owned `netdnas.bin`, SHA-256 **8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16**. No game, build, replay, attachment, network request, live-memory read, payload unpacking, transformation or execution occurred.

Four complete **clear dispatcher** bodies were independently read. This is a second dispatch family, distinct from [upper protection metadata](SYMBOLS_NETDNAS_PROTECTED_DISPATCH.md), and connected to [reviewed word primitives](SYMBOLS_O4_WORD_TRANSFORMS.md). Exception helper70BBF8 and selector normalizer70BC38 already have exact-body annotations and are not duplicated here. **All encoded payloads below receive zero semantic mapping credit.** Original catalogue denominator and all source-less intervals are preserved; a metadata boundary does not recover an original function or validate generated disassembly.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x70BA68](../recomp/config/output_ovl/o4/o4_0070BA68_0x70ba68.cpp) | `dispatch_primary_netdnas_protected_span_by_metadata_id_and_mode` | Confirmed full clear dispatch/data flow; encoded payload meaning unknown | Span=originala1 XOR originala2; packed originala3 lowbit chooses inverse interval[anchor,anchor+span) or forward[anchor-span,anchor). Header start-14hex becomes selfpointer forinverse orzero forforward. Lookup70BB40(packedid>>1) supplies relativebase/count/list; calls70C3C8 inverse or70BCA0 forward, passing offsetbase=start-relativebase and originala2 packedselector. Calls resident1148A0(0),(2) afterward. No local bounds/admission or decoded payload meaning; packed transform schedule is not taken from exception count. |
| [o4 0x70BB40](../recomp/config/output_ovl/o4/o4_0070BB40_0x70bb40.cpp) | `lookup_primary_netdnas_protection_relative_base_and_exception_list` | Confirmed full clear dispatch/data flow; encoded payload meaning unknown | Zero id clears three outputs; otherwise scans52 key/offsetpairs70CB4C, comparing key>>1. Firstmatchoffset added to70CCEC recordbase yields word0 relativebase,word1count,record+8list. Missing id also clearsoutputs. All52 pairs/records/lists fullyread below; lists need not be sorted and do not define function boundaries. |
| [o4 0x70BCA0](../recomp/config/output_ovl/o4/o4_0070BCA0_0x70bca0.cpp) | `apply_primary_netdnas_forward_word_transform_schedule` | Confirmed full clear dispatch/data flow; encoded payload meaning unknown | Normalizes original packedselector70BC38; top count controls low-to-high nibble dispatch through eight pointers764A78. Forwards unchanged start/end/offsetbase/exceptioncount/list to each primitive, ignoresresult, returns0. Initialcount test precedesbody. Normalizer masks nibbles0..7/count0..7, substituting5when countbitszero. No payload transformation performed. |
| [o4 0x70C3C8](../recomp/config/output_ovl/o4/o4_0070C3C8_0x70c3c8.cpp) | `apply_primary_netdnas_inverse_word_transform_schedule` | Confirmed full clear dispatch/data flow; encoded payload meaning unknown | Same independently read normalized schedule/initialtest/argument flow as70BCA0, table764A98; ignoresprimitive result,returns0. All16 pointers are reviewed word primitives. This proves static schedule routing, not payload semantics, runtime execution or a mathematically validated arbitrary caller contract. |

Full forward table764A78..764A98: `70BD78 70BE18 70BEB8 70BF68 70C018 70C0F0 70C1B0 70C2B0`. Inverse764A98..764AB8: `70C4A0 70C540 70C5E0 70C6A0 70C760 70C838 70C910 70CA20`. All16 pointers checked against owned bytes and existing primitive rows. Labels describe primitive direction only, not a decoded payload.

## Complete primary exception metadata

Count52, pairbase70CB4C, recordbase70CCEC, complete end70D3F4. Entire70CB48..70D3F4 SHA-256 `0130ded6b040e4b777fa76d3135f68854a3dcc70e918a3dcafc0f7821221449e`. Counts are decimal, addresses/offsets hexadecimal; ordering retained exactly. These are data evidence, not function rows.

| Index | Packed key | Record | Relative base | Count | Exception offsets |
| --- | --- | --- | --- | --- | --- |
| 0 | `741AF344` | `70CCEC` | `530` | 6 | `564 568 5A4 5A8 5C0 5D4` |
| 1 | `741BD100` | `70CD0C` | `B0` | 2 | `B0 B4` |
| 2 | `741BD2E0` | `70CD1C` | `1B0` | 2 | `1B0 1B4` |
| 3 | `741BD710` | `70CD2C` | `4C8` | 2 | `4C8 4CC` |
| 4 | `741BD87C` | `70CD3C` | `5C8` | 2 | `5C8 5CC` |
| 5 | `741BD9EC` | `70CD4C` | `6C8` | 2 | `6C8 6D0` |
| 6 | `741BDB68` | `70CD5C` | `7A8` | 2 | `7A8 7AC` |
| 7 | `741BDCE6` | `70CD6C` | `8A8` | 2 | `8A8 8B0` |
| 8 | `741BDE66` | `70CD7C` | `988` | 2 | `988 990` |
| 9 | `741BDFE8` | `70CD8C` | `A68` | 2 | `A68 A70` |
| 10 | `741BE16C` | `70CD9C` | `B48` | 2 | `B48 B4C` |
| 11 | `741BE2F2` | `70CDAC` | `C48` | 3 | `C48 C4C C50` |
| 12 | `741BE718` | `70CDC0` | `F4C` | 1 | `F74` |
| 13 | `741BE9D8` | `70CDCC` | `11C0` | 3 | `11C0 11C4 11C8` |
| 14 | `741BECA0` | `70CDE0` | `13B0` | 2 | `13B0 13B8` |
| 15 | `741BEE1E` | `70CDF0` | `1490` | 2 | `1490 1498` |
| 16 | `741BEFAA` | `70CE00` | `157C` | 1 | `15A4` |
| 17 | `741BF28C` | `70CE0C` | `17F8` | 2 | `188C 1890` |
| 18 | `750E230E` | `70CE1C` | `90` | 61 | `90 94 D4 E0 E8 104 130 154 18C 190 1DC 1E0 22C 230 27C 280 2BC 2C0 304 308 34C 350 38C 390 3CC 3D0 41C 42C 46C 470 4BC 4C0 514 518 564 568 5B8 5CC 60C 610 65C 660 6BC 6C0 6E4 6F0 724 728 754 794 798 7D4 7D8 814 818 824 838 840 860 854 864` |
| 19 | `750E24E0` | `70CF18` | `A7C` | 4 | `A9C AA0 AAC AB4` |
| 20 | `750E8150` | `70CF30` | `B8C` | 25 | `BAC BB0 BBC BC4 C0C C10 C1C C24 C64 C68 C74 C7C CB4 CB8 CC4 CCC CF4 CF8 CFC D0C D10 D1C D24 D38 D40` |
| 21 | `75113690` | `70CF9C` | `F8` | 5 | `130 134 154 180 1F8` |
| 22 | `75113862` | `70CFB8` | `360` | 5 | `360 368 38C 3B8 480` |
| 23 | `75113A1C` | `70CFD4` | `5E8` | 4 | `614 618 620 628` |
| 24 | `75113BB2` | `70CFEC` | `71C` | 4 | `744 748 750 75C` |
| 25 | `75113D48` | `70D004` | `89C` | 6 | `8B4 8B8 8C4 8CC 8DC 8E8` |
| 26 | `75113EDC` | `70D024` | `B20` | 3 | `B20 B2C B30` |
| 27 | `75114076` | `70D038` | `C24` | 1 | `C7C` |
| 28 | `7511420C` | `70D044` | `D70` | 3 | `D70 D7C D80` |
| 29 | `751A35F6` | `70D058` | `334` | 15 | `3F4 3F8 3FC 400 46C 470 4F4 4F8 57C 580 604 608 68C 690 6B4` |
| 30 | `751A381A` | `70D09C` | `AD0` | 10 | `AF4 AF8 B04 B34 B38 B48 B6C B70 B7C B8C` |
| 31 | `751A39FC` | `70D0CC` | `1764` | 3 | `1784 1788 1790` |
| 32 | `751A3BC2` | `70D0E0` | `2838` | 3 | `286C 2870 287C` |
| 33 | `751A3D7A` | `70D0F4` | `2AB4` | 29 | `2BF4 2BF8 2BFC 2C00 2C7C 2C80 2D44 2D48 2E0C 2E10 2ED4 2ED8 2F94 2F98 2FB4 2FB8 2FC0 2FE0 3010 301C 3040 304C 3054 3078 3090 30A8 30B8 30CC 30F8` |
| 34 | `751E395C` | `70D170` | `714` | 3 | `73C 740 744` |
| 35 | `751E3B58` | `70D184` | `898` | 7 | `8E4 8E8 8F8 944 948 94C 8A0` |
| 36 | `751E3D16` | `70D1A8` | `A2C` | 3 | `A5C A60 A64` |
| 37 | `751E3ED8` | `70D1BC` | `B9C` | 3 | `BCC BD0 BD4` |
| 38 | `751E409E` | `70D1D0` | `CB0` | 3 | `CDC CE0 CE4` |
| 39 | `751E4260` | `70D1E4` | `DC0` | 3 | `DEC DF0 DF4` |
| 40 | `751E4426` | `70D1F8` | `F48` | 21 | `FD8 FD0 FF8 F48 F4C F8C F90 FB8 FC0 FCC FD4 FDC FE4 103C 1040 1068 1070 10BC 10C0 10E8 F54` |
| 41 | `751E45F2` | `70D254` | `11B0` | 3 | `11DC 11E0 11E4` |
| 42 | `751E47DA` | `70D268` | `1294` | 3 | `12C4 12C8 12CC` |
| 43 | `751E49AC` | `70D27C` | `1380` | 3 | `13B4 13B8 13BC` |
| 44 | `751E4B78` | `70D290` | `16A8` | 3 | `16D4 16D8 16DC` |
| 45 | `751E4D44` | `70D2A4` | `17C8` | 3 | `17FC 1800 1804` |
| 46 | `751E4F10` | `70D2B8` | `18D4` | 3 | `1904 1908 190C` |
| 47 | `751E50E0` | `70D2CC` | `1ED0` | 19 | `1ED4 1ED8 1EDC 1EE0 1F1C 1F20 1F24 1F2C 1F38 1F6C 1F70 1F74 1F88 1F8C 1FD4 1FD8 1FDC 1ED0 1F28` |
| 48 | `751E52B4` | `70D320` | `20E8` | 3 | `210C 2110 2114` |
| 49 | `751E548A` | `70D334` | `2200` | 15 | `2200 2204 2208 220C 2210 224C 2250 2254 225C 2260 226C 22A4 22A8 22AC 22C0` |
| 50 | `751E565A` | `70D378` | `23B0` | 24 | `23B0 2410 23B4 23B8 23BC 23C0 2404 2408 240C 2414 2420 2454 2458 245C 2474 2478 24BC 24C0 24C4 24D0 24D8 251C 2520 2524` |
| 51 | `751E584C` | `70D3E0` | `2658` | 3 | `267C 2680 2684` |

## Anchored payload header inventory, without decoding

Each entry below is anchored to an actual owned JAL70BA68 and a nearby literal LUI/ADDIU pair constructing a0=payloadstart. Five header words at start-14hex must be `[0,B,key,A,0]`; span=A XOR B. All63 qualifying starts are unique:52 keys have the metadata above and11 key0 callers intentionally take the zero-id/no-exception lookup. For every range, adjacent four restore-data words at end+20hex are `[B2,key+1,A2,0]`, A2 XOR B2 equals entry span, and normalized B2 selector sequence reverses normalized B. This is complete original-data comparison only. An odd-key adjacent descriptor alone does **not** prove its restore path is called; not all callers contain a direct clear restore call.

Payload ranges are half-open. Payload SHA-256 covers original encoded bytes only. Metadata index `none` means explicit key0, not a missing guessed function. Common-base is start minus metadata relativebase; key0 has no relativebase. Header arguments are shown as B/A (span operands), not host executable code.

| Entry call | Header | Packed key | B / A | Payload start..end | Metadata index | Common base | Encoded payload SHA-256 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| `6E1554` | `6E157C` | `741AF344` | `E2AC5F08 / E2AC5FA4` | `6E1590..6E163C` | 0 | `6E1060` | `dc969c19dec8d9168d74c1c2b45893912c19513786e81d4628e28e3d51d5053e` |
| `6E2A3C` | `6E2A64` | `741BD100` | `ADBA40A5 / ADBA4089` | `6E2A78..6E2AA4` | 1 | `6E29C8` | `ecb8bae772ae559f324ce1d9cdfffd95201df62fc9646b0e80c228c773c85eb3` |
| `6E2B3C` | `6E2B64` | `741BD2E0` | `D009C2BC / D009C290` | `6E2B78..6E2BA4` | 2 | `6E29C8` | `e82ef8850792a3b0b2a4ee6418de1f0c84d34576172e8378ff03405a7690611a` |
| `6E2C48` | `6E2C70` | `00000000` | `D6202A62 / D6202A42` | `6E2C84..6E2CA4` | none | `none` | `187ae592931499152a06aa179c67c4bca303f35226c62d2521a0ea8683ec0b7f` |
| `6E2D50` | `6E2D78` | `00000000` | `B6011450 / B6011478` | `6E2D8C..6E2DB4` | none | `none` | `0e8c45baa47c3f6908e43167e87abacbcc07d72a56b817e91953d2775324b2b4` |
| `6E2E54` | `6E2E7C` | `741BD710` | `A8F3335F / A8F33373` | `6E2E90..6E2EBC` | 3 | `6E29C8` | `daa0def427d6e044ce617d21d2b61e2a5473dfb7d266fb773507b0be049637fa` |
| `6E2F54` | `6E2F7C` | `741BD87C` | `7DF46DD2 / 7DF46DFE` | `6E2F90..6E2FBC` | 4 | `6E29C8` | `807dc9988a20343ee9c2703e8b8324180ac39d4e4d718431b17b2d2bea0af2a2` |
| `6E3054` | `6E307C` | `741BD9EC` | `A7E05FCF / A7E05FC3` | `6E3090..6E309C` | 5 | `6E29C8` | `21a38b575320e9fc816651a2e01a5248731468ceb0fb306d0612e0f177c3606d` |
| `6E3134` | `6E315C` | `741BDB68` | `C8208B6B / C8208B47` | `6E3170..6E319C` | 6 | `6E29C8` | `d0fb684b58c2879d501f0103a6542648da6a3f2cbc30e84dce23e0346619e60c` |
| `6E3234` | `6E325C` | `741BDCE6` | `5E50514D / 5E505141` | `6E3270..6E327C` | 7 | `6E29C8` | `06bf1a4b74270c968fbccf4c4e8bdf525205ecd54f8888ab0f84b4dff8ee5635` |
| `6E3314` | `6E333C` | `741BDE66` | `FDD07D3C / FDD07D30` | `6E3350..6E335C` | 8 | `6E29C8` | `0157dbf1fc94705de2ed5ec3eef33d382654b77619a612e2d378e889fb880d11` |
| `6E33F4` | `6E341C` | `741BDFE8` | `4FD8D9D6 / 4FD8D9DA` | `6E3430..6E343C` | 9 | `6E29C8` | `16be01e5f2423329f8d75da3fd8a3ffc6ba1d8152e06d3258431d6c2c074f100` |
| `6E34D4` | `6E34FC` | `741BE16C` | `4E7FFB2B / 4E7FFB07` | `6E3510..6E353C` | 10 | `6E29C8` | `6e27c5a6a7d4a8935e230590813ebdc4cb900eb757d6bf55dcc104b4930784b6` |
| `6E35D4` | `6E35FC` | `741BE2F2` | `54334B2D / 54334B39` | `6E3610..6E3624` | 11 | `6E29C8` | `0baadfa5e583661f114570a18923a42e4db7f1a168eef36d2c8b38741487c5e4` |
| `6E36C4` | `6E36EC` | `00000000` | `6AF26D8A / 6AF26DAE` | `6E3700..6E3724` | none | `none` | `3696a85ac6a5fea3347a8167c38adf0c99b6c4f51aeba6d571d116ce8d671fc2` |
| `6E37CC` | `6E37F4` | `00000000` | `D366C146 / D366C162` | `6E3808..6E382C` | none | `none` | `72d0406c512b38965205ed0ab0be3e662f51989b9461983bc36ae83a7aa1953c` |
| `6E38D8` | `6E3900` | `741BE718` | `666FFCE7 / 666FFC67` | `6E3914..6E3994` | 12 | `6E29C8` | `4ad84dac2743eb502629f447c12f4eb3703e6e87f6097b015da47a718bfeec3f` |
| `6E3A3C` | `6E3A64` | `00000000` | `221E048A / 221E04BE` | `6E3A78..6E3AAC` | none | `none` | `b72713b09cb343636143a4e44d1533f20ce16c492f04f42eb1a8687a6004ffae` |
| `6E3B4C` | `6E3B74` | `741BE9D8` | `3C2E54F8 / 3C2E54EC` | `6E3B88..6E3B9C` | 13 | `6E29C8` | `6720f5f845db3a08b3d0e19542ee502b50b7f8afa8201bddb27c57148b507a41` |
| `6E3C3C` | `6E3C64` | `00000000` | `CD34C1C4 / CD34C1E0` | `6E3C78..6E3C9C` | none | `none` | `77f85de6745e69958c92998531950ab42ea3eab6d6d07325141d3aa301fac1f3` |
| `6E3D3C` | `6E3D64` | `741BECA0` | `D560468E / D5604682` | `6E3D78..6E3D84` | 14 | `6E29C8` | `0a550ac41f6ad9ef592763013e9179922b868a35f0f58113c7874cdd738ca1e7` |
| `6E3E1C` | `6E3E44` | `741BEE1E` | `0C137844 / 0C137848` | `6E3E58..6E3E64` | 15 | `6E29C8` | `df8a15ddfcdf185f237e7a1197a4d362f97b0b22be945a210eb82ce92bd41856` |
| `6E3F08` | `6E3F30` | `741BEFAA` | `A16E4B94 / A16E4B14` | `6E3F44..6E3FC4` | 16 | `6E29C8` | `1686c59f6a10cd0781d0d4cca2b8836ccdfa38f1cd94e0cc89ae038b54a8b2d4` |
| `6E406C` | `6E4094` | `00000000` | `E2F35A89 / E2F35ABD` | `6E40A8..6E40DC` | none | `none` | `38c6078ab3aa4e2de049a026b5726a4326766fe93c2c22a3b1f393710597559d` |
| `6E4184` | `6E41AC` | `741BF28C` | `D2672D06 / D2672DEE` | `6E41C0..6E42A8` | 17 | `6E29C8` | `0d3f60c9874a5d7e4cac45e0c3e1973fa2949fa5cf1b6cb062d26c00dff40f10` |
| `6E4364` | `6E438C` | `750E230E` | `A7268BB4 / A7268C6C` | `6E43A0..6E4B78` | 18 | `6E4310` | `c71cf8c26f48471bbe9af10a5dfc17ffd9207e8f24bbb98402c048c933f99482` |
| `6E4D50` | `6E4D78` | `750E24E0` | `2BCB35A2 / 2BCB35E6` | `6E4D8C..6E4DD0` | 19 | `6E4310` | `658733152c139b6e5b9bcf901bae9beb4f17a05a1b1aeb0958c39c94f45e4d8a` |
| `6E4E60` | `6E4E88` | `750E8150` | `7898EDEE / 7898EC2E` | `6E4E9C..6E505C` | 20 | `6E4310` | `eebdfd103f5c23bc2199b7c9f8085bdf178dd2e33cef0fb9be301fa4d944affc` |
| `6E52AC` | `6E52D4` | `00000000` | `7FF6AC4D / 7FF6AC7D` | `6E52E8..6E5318` | none | `none` | `1a4b03f36df4b0193459002664c75540826187c2834f805ce8cc136cd0788dc8` |
| `6E604C` | `6E6074` | `75113690` | `DDDD08E5 / DDDD09B1` | `6E6088..6E61DC` | 21 | `6E5F90` | `796e2afa79f4e17fa5252f40a763e09c02d340fdefe9aa6e528d9cbe5e11e8f1` |
| `6E62B4` | `6E62DC` | `75113862` | `451B3A01 / 451B3B75` | `6E62F0..6E6464` | 22 | `6E5F90` | `ba8f8bbe6d8d373392a6c0da4134a6fd81884a0c7d6aae9ede233607fdbf360a` |
| `6E653C` | `6E6564` | `75113A1C` | `7A48CF00 / 7A48CF4C` | `6E6578..6E65C4` | 23 | `6E5F90` | `e3f2693bec9698b6847dcee2e67e7f3dd75f8a6c492d63c3916dca430259c770` |
| `6E6670` | `6E6698` | `75113BB2` | `A618FADC / A618FA90` | `6E66AC..6E66F8` | 24 | `6E5F90` | `6cbd66ed22a26be01ec411d87d19f2cfb213f5584211666787e55fc27eb6719c` |
| `6E67F0` | `6E6818` | `75113D48` | `5AE44659 / 5AE44601` | `6E682C..6E6884` | 25 | `6E5F90` | `62adf126e508c5a83ba4f0b3ab9864af9741581cc990184bd9ac6c95058f8dcb` |
| `6E6A74` | `6E6A9C` | `75113EDC` | `631D2609 / 631D2615` | `6E6AB0..6E6ACC` | 26 | `6E5F90` | `8383e013ceae3304df36c79ded08444ffd2e8df50440c149be0a62294854bccd` |
| `6E6B78` | `6E6BA0` | `75114076` | `7A33BDFC / 7A33BD94` | `6E6BB4..6E6C1C` | 27 | `6E5F90` | `55aa90c4dbcec4afa7087234d6a7d4a15ae2a8c9e1ada6e7408d4943f0d9fb2c` |
| `6E6CC4` | `6E6CEC` | `7511420C` | `888FCD8D / 888FCD91` | `6E6D00..6E6D1C` | 28 | `6E5F90` | `aa565ebb4b9d387696736b2c7113d4b8bb6e75b589dab7608311c1b955f40be8` |
| `6E7060` | `6E7088` | `00000000` | `DD9A0D87 / DD9A0DD3` | `6E709C..6E70F0` | none | `none` | `f1bab5cd07300b705cf1bdf191e81c5e21e9e99e7af6b7460c17e1e79a0e3ca1` |
| `6E722C` | `6E7254` | `00000000` | `F53148B8 / F53148FC` | `6E7268..6E72AC` | none | `none` | `0e6b5a9af76ef81c6062cc330b5adb492149e3f3086822239918a3762e9e59c9` |
| `6E7580` | `6E75A8` | `00000000` | `C0B0395A / C0B0390E` | `6E75BC..6E7610` | none | `none` | `777917fda3260131584ed39f48d4c0ae82b37ac367b27fda9943650bea940135` |
| `6E8238` | `6E8260` | `751E395C` | `385677E7 / 385677DF` | `6E8274..6E82AC` | 34 | `6E7B60` | `013400c08a4f8b761a7973e019e761b5243de4240e4003c2b231d4331c8b8c05` |
| `6E83B8` | `6E83E4` | `751E3B58` | `4F9C026C / 4F9C02A4` | `6E83F8..6E84C0` | 35 | `6E7B60` | `3b5d9b316605e41dd2745bcdf8fafc88fabc76e155bdf3cdb00087d7e4e4d46b` |
| `6E8550` | `6E8578` | `751E3D16` | `FB00D393 / FB00D3D3` | `6E858C..6E85CC` | 36 | `6E7B60` | `bebf92c57b2391b931f259ffa338b2d05c2ecfcaff53685d2b879f6ff6c09e6f` |
| `6E86C0` | `6E86E8` | `751E3ED8` | `CAD6CBB5 / CAD6CBF5` | `6E86FC..6E873C` | 37 | `6E7B60` | `455bb7ae97e5f685724768f2e9eb62ffa944ea04775b81ed808fc0807840aa78` |
| `6E87D4` | `6E87FC` | `751E409E` | `B3A2FB38 / B3A2FB04` | `6E8810..6E884C` | 38 | `6E7B60` | `b15d6615133d9e08de2d9822574d0f8bd36f476b7e613e2c3579e910aab580ea` |
| `6E88E4` | `6E890C` | `751E4260` | `886C1DD2 / 886C1DEE` | `6E8920..6E895C` | 39 | `6E7B60` | `29dce4ce966d782c269ec81fe4c1d396bf40cf326455c1e23fa7c84662281b5e` |
| `6E8A6C` | `6E8A94` | `751E4426` | `4A17BE3E / 4A17BF96` | `6E8AA8..6E8C50` | 40 | `6E7B60` | `358bb954d853ae48c1b7711d79ea1b7d2092037e00dd957b360118f68bf37a81` |
| `6E8CD4` | `6E8CFC` | `751E45F2` | `30C0D30B / 30C0D337` | `6E8D10..6E8D4C` | 41 | `6E7B60` | `6620387debd210228ebc0c38fd89b8b42eceb90146dbc01b73da50c349efcb31` |
| `6E8DB8` | `6E8DE0` | `751E47DA` | `E96BCF58 / E96BCF18` | `6E8DF4..6E8E34` | 42 | `6E7B60` | `cc4b6d62d05bed060b5dfb4b026db51cb7f75060091b41f2c7972aea9849510a` |
| `6E8EA4` | `6E8ECC` | `751E49AC` | `ED733247 / ED733203` | `6E8EE0..6E8F24` | 43 | `6E7B60` | `18c93e54b9f5d5c4b960a832e1f97f81b719b86de710a4820b97c60e707d7949` |
| `6E91CC` | `6E91F4` | `751E4B78` | `68D5E78F / 68D5E7B3` | `6E9208..6E9244` | 44 | `6E7B60` | `c7ba5486476f1361dd71c004566ae857bcc8b2347185d59027a0f12dcd8ff841` |
| `6E92EC` | `6E9314` | `751E4D44` | `F6EFA930 / F6EFA974` | `6E9328..6E936C` | 45 | `6E7B60` | `432cef149fbc58aabdc215fb9878995779f5704cf470942e09d158c4c56355f9` |
| `6E93F8` | `6E9420` | `751E4F10` | `B94094F4 / B94094B4` | `6E9434..6E9474` | 46 | `6E7B60` | `658b0843b38a6e29f034e9a754407450b1da3f2e311d666a323fd2b3a95bc31e` |
| `6E99F4` | `6E9A1C` | `751E50E0` | `00FFCA0C / 00FFCB2C` | `6E9A30..6E9B50` | 47 | `6E7B60` | `2fb743764dba57855d8503ca0fa0ea2d5a29a117acb7bd050bab24df03bc155d` |
| `6E9C0C` | `6E9C34` | `751E52B4` | `BA57CC74 / BA57CC40` | `6E9C48..6E9C7C` | 48 | `6E7B60` | `a02377d4b51ac85c1b95963341da901f2a6ca9702547c69765aac01a6354871f` |
| `6E9D24` | `6E9D4C` | `751E548A` | `DE5A9598 / DE5A954C` | `6E9D60..6E9E34` | 49 | `6E7B60` | `2934eb11ac495065d3138788f5004ca28cf5f92798ed0c734badc3842a9ab6ec` |
| `6E9ED4` | `6E9EFC` | `751E565A` | `CD227A2F / CD227BA7` | `6E9F10..6EA098` | 50 | `6E7B60` | `85cf19ec51803c67bce05b15d931da534f987385db23113347e46e7bedfe025b` |
| `6EA17C` | `6EA1A4` | `751E584C` | `5B30C67E / 5B30C64A` | `6EA1B8..6EA1EC` | 51 | `6E7B60` | `2f55b0f641acc7c7617b3abae5b848a880befc6fd4e0f7fe8ec76807cf87f934` |
| `6EA600` | `6EA628` | `751A35F6` | `FC6241F7 / FC624253` | `6EA63C..6EA9E0` | 29 | `6EA308` | `ef26ecdfcef765e1ba0ce5e7b04e6d0010bb0839ce7d61012192503c592911aa` |
| `6EAD9C` | `6EADC4` | `751A381A` | `7F735535 / 7F7355F1` | `6EADD8..6EAE9C` | 30 | `6EA308` | `88abc10f9bcc8b8e8d8cb94a6eebbc12f075f6724dde2e921b3bc825f587b222` |
| `6EBA30` | `6EBA58` | `751A39FC` | `C9B2FFBE / C9B2FF8A` | `6EBA6C..6EBAA0` | 31 | `6EA308` | `f7124e17239ecb1d1e3c03d226259e167ab56384a82cedb95a7accba67faa7a1` |
| `6ECB04` | `6ECB2C` | `751A3BC2` | `EEC6BF38 / EEC6BF74` | `6ECB40..6ECB8C` | 32 | `6EA308` | `f40b31bcbce1714c2a1ceb87dbd7474cf716dcb16e92c4ad869c8553b2174a91` |
| `6ECD80` | `6ECDA8` | `751A3D7A` | `DCC2BAFC / DCC2BCAC` | `6ECDBC..6ED40C` | 33 | `6EA308` | `cadd1992898bce495deebf1cde930cbabe2651997c408bb631c6a50b905fd937` |

The63 primary payload ranges intersect **55 generated catalogue intervals and142 source-less intervals**. The independently recorded49 upper payload ranges intersect another55 generated/163 source-less intervals; disjoint primary/upper addresses give110 generated and305 source-less interval intersections in total. These are boundary counts, **not mapped-role counts**, and include partial entry overlaps, catalogue fragments and the six earlier explicitly partial low wrappers. Additional clear glue outside a payload needs its own review; source-less bytes and metadata remain data/unknown. Remaining33 source-less intervals are outside these payload unions and retain existing source-boundary classification. No interval is removed from the2389-entry/2051-generated catalogue denominator.

Examples show why owned-byte agreement is insufficient for a semantic claim:6E2A08 prologue clearly loads a protected header then branches into transformed bytes;6E2A8C is merely a generated one-word interval inside that payload. Neither becomes a meaningful translated function from its emitted instruction comments. The11 zero-id headers are equally real even though they do not appear among the52 exception records.
