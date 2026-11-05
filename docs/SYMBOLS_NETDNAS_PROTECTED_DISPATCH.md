# Network DNAS: protected-region dispatch and tracked resize

Later update,2026-11-05: [all53 upper spans were reconstructed as copied data](STATIC_DNAS_UPPER_RECOVERY_INVENTORY.md) and reviewed through their connected owners. [The owner ledger](STATIC_DNAS_O4_OWNER_RECONCILIATION.md) records the current accounting without changing the catalogue denominator. The clear dispatcher/metadata review below remains its original scope.

Static File #1 US research, 2026-11-04. Catalogue **o4**, runtime id **5**, base **0x6E0000**, owned `netdnas.bin`, SHA-256 **8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16**. No game, build, replay, attachment, network request, live-memory read or payload transformation occurred.

Five complete clear generated intervals were independently read, including branch-likely delay slots and initial loop tests. The four dispatch routines connect the [word transforms](SYMBOLS_O4_WORD_TRANSFORMS.md) to protected regions. They explain dispatch mechanics, not the functions hidden inside transformed payloads. The remaining resize routine connects the [allocation tracker](SYMBOLS_NETDNAS_PRIVATE_ALLOCATION_TRACKER.md). No timing, slowdown cause, cryptographic correctness or original function name is established.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x743F30](../recomp/config/output_ovl/o4/o4_00743F30_0x743f30.cpp) | `resize_netdnas_tracked_unlocked_allocation_by_allocate_copy_wipe_replace` | Confirmed lifecycle/data/control flow; admission limits partial | Inputs tracker, new byte length, pointer cell. NULL cell value tails 743CE0 allocation/registration. Otherwise 7440F8 locates its 12-byte record; missing record or nonzero record+8 returns 258. Allocates 744BF8(new length), returning 258 on failure while preserving the old pointer. Copies min(new length,record+4) through 744B78, wipes all old bytes through 744B50, frees 744C88, updates caller cell and record pointer/length, returns zero. Caller ownership, alias admission and heap failure semantics remain inherited/partial. |
| [o4 0x7457C8](../recomp/config/output_ovl/o4/o4_007457C8_0x7457c8.cpp) | `dispatch_netdnas_protected_span_transform_by_metadata_id_and_mode` | Confirmed clear dispatch/data flow; protected payload semantics unknown | Inputs anchor, token A, packed transform B, packed metadata id/mode. Span=A XOR B; low mode bit selects inverse over [anchor,anchor+span) with header=anchor-14 hex, or forward over [anchor-span,anchor) with header=start-14 hex. Inverse sets header word0 to its own address; forward clears it. Calls 7458A0(id/mode>>1), then 746128 inverse or 745A00 forward with offset base=start-metadata record word0 and its exception list/count. Packed transform schedule comes from original B, not the metadata record. Calls resident 1148A0(0), then (2), consistent with the separately reviewed FlushCache wrapper candidate. No local span bounds, mapping identity validation or decoded-body meaning is established. |
| [o4 0x7458A0](../recomp/config/output_ovl/o4/o4_007458A0_0x7458a0.cpp) | `lookup_netdnas_protected_transform_relative_base_and_exception_offsets` | Confirmed lookup/data flow against all owned records | Zero id returns three zero outputs. Scans count=49 pairs at 744F2C, comparing each key>>1 with requested id; first match selects record offset relative to 7450B4. Outputs record word0 (relative base offset), word1 (exception count), and record+8 (offset list). Missing id also outputs zeros. All 49 pair/record/list intervals end exactly at 7457C8 and were independently read; no assumption that a record is a standalone original function. |
| [o4 0x745A00](../recomp/config/output_ovl/o4/o4_00745A00_0x745a00.cpp) | `apply_netdnas_forward_word_transform_sequence` | Confirmed dispatch/control flow and complete eight-slot table | Normalizes packed selector through reviewed 745998; its top nibble supplies count, then low-to-high nibbles select 767A40[0..7]. Passes unchanged start/end/offset base/exception count/list to each primitive. Initial count test occurs before any body call; loop increments once per call. Ignores primitive result and returns zero. Full schedule admission and inverse composition correctness remain unproven. |
| [o4 0x746128](../recomp/config/output_ovl/o4/o4_00746128_0x746128.cpp) | `apply_netdnas_inverse_word_transform_sequence` | Confirmed dispatch/control flow and complete eight-slot table | Same normalized low-to-high selector loop and arguments as 745A00, using 767A60 inverse primitive table. Initial count test precedes the loop; returns zero regardless of primitive results. Table designation follows the independently reviewed primitive arithmetic. No transformed payload was executed or reconstructed, and complete schedule inversion is not asserted. |

Owned forward pointers 767A40..767A5C are `745AD8 745B78 745C18 745CC8 745D78 745E50 745F10 746010`; inverse pointers 767A60..767A7C are `746200 7462A0 746340 746400 7464C0 746598 746670 746780`. All 16 entries were checked against the owned image and existing primitive notebook. The selector normalizer masks each low selector nibble to 0..7 and the high count to 0..7, substituting five when the input count is zero; no unchecked 16-way pointer-table claim is made.

The complete metadata byte interval **744F28..7457C8** hashes to **20fe6a8e5af20d93a868ad3ad4b1ac288ddb9926e8d621ac2df05bc8bf900b5b**. The following data inventory is evidence, not additional function-role rows. Offsets and exception values are hexadecimal. Exception ordering is retained exactly, including unsorted entries.

| Index | Packed key | Record | Relative base offset | Count | Exception offsets |
| --- | --- | --- | --- | --- | --- |
| 0 | `D6078F7E` | `7450B4` | `7C` | 6 | `7C 80 90 A0 B8 C8` |
| 1 | `D60791E8` | `7450D4` | `1BC` | 6 | `1BC 1C0 1D0 1E0 1F8 208` |
| 2 | `D60792D2` | `7450F4` | `2F4` | 4 | `2F4 2F8 30C 31C` |
| 3 | `D607939E` | `74510C` | `430` | 29 | `430 434 454 490 4B4 4D8 4F8 530 638 68C 694 6CC 6E8 6F0 6EC 6F4 700 720 72C 734 730 738 740 75C 798 818 890 908 980` |
| 4 | `D60794B6` | `745188` | `B04` | 11 | `B04 B08 B20 B28 B24 B2C B38 B5C B78 BB0 C28` |
| 5 | `D6079586` | `7451BC` | `D7C` | 2 | `D7C D80` |
| 6 | `D6079656` | `7451CC` | `E94` | 2 | `E94 E98` |
| 7 | `D6079720` | `7451DC` | `FA4` | 2 | `FA8 FB0` |
| 8 | `D60799C2` | `7451EC` | `108C` | 2 | `1090 1094` |
| 9 | `D6079AB4` | `7451FC` | `1174` | 2 | `1178 117C` |
| 10 | `D6079B82` | `74520C` | `125C` | 2 | `1260 1268` |
| 11 | `D6079C4C` | `74521C` | `1344` | 2 | `1348 1350` |
| 12 | `D6079D10` | `74522C` | `1458` | 1 | `1464` |
| 13 | `D6079DDA` | `745238` | `1588` | 1 | `1590` |
| 14 | `D6079EA4` | `745244` | `1688` | 2 | `1698 1700` |
| 15 | `D6079F72` | `745254` | `1858` | 2 | `1868 18D0` |
| 16 | `D607A040` | `745264` | `1A2C` | 6 | `1A2C 1A30 1A48 1A64 1B00 1B78` |
| 17 | `D607A108` | `745284` | `1CDC` | 10 | `1CE0 1D18 1D2C 1D34 1D24 1D3C 1D44 1D5C 1D98 1D28` |
| 18 | `D607A1DA` | `7452B4` | `1EDC` | 2 | `1EDC 1EE0` |
| 19 | `D607A2AC` | `7452C4` | `200C` | 10 | `2058 2010 2048 205C 2064 2054 206C 2074 208C 20C8` |
| 20 | `D607A384` | `7452F4` | `2220` | 2 | `2230 2298` |
| 21 | `D607A452` | `745304` | `23DC` | 3 | `23DC 23E0 23F4` |
| 22 | `D607A51E` | `745318` | `254C` | 10 | `2550 2588 259C 25A4 2594 25AC 25B4 25CC 2608 2598` |
| 23 | `D607A5F6` | `745348` | `2764` | 13 | `2764 2768 277C 278C 27A4 27B8 27D0 27E4 27F4 28B0 2938 294C 295C` |
| 24 | `D607A738` | `745384` | `2A94` | 10 | `2AE0 2A98 2AD0 2AE4 2AEC 2ADC 2AF4 2AFC 2B14 2B50` |
| 25 | `D607A93A` | `7453B4` | `2F88` | 10 | `2F88 2F90 2FA0 2FB0 2FD0 2FDC 2FF0 3008 3018 3030` |
| 26 | `D607AA06` | `7453E4` | `3134` | 19 | `3134 3138 3144 3158 3168 3170 316C 3178 318C 31CC 31D8 3150 31DC 31EC 31F4 31FC 3218 3248 329C` |
| 27 | `D607AAE4` | `745438` | `338C` | 3 | `33B4 33B8 33BC` |
| 28 | `D607AC26` | `74544C` | `34B8` | 4 | `34B8 34BC 34EC 3568` |
| 29 | `D607AD08` | `745464` | `3B7C` | 29 | `3BA0 3B7C 3BA8 3BB8 3C0C 3C34 3C3C 3C38 3C40 3C70 3C78 3C84 3C8C 3CA0 3CA4 3CAC 3CC8 3CEC 3D00 3D10 3D20 3D2C 3D58 3D60 3DA4 3DB0 3E30 3EA8 3F20` |
| 30 | `D607ADE4` | `7454E0` | `407C` | 7 | `40A4 40A8 40AC 40CC 40DC 40E8 40F0` |
| 31 | `D71817FC` | `745504` | `88` | 1 | `94` |
| 32 | `D718199A` | `745510` | `1B0` | 4 | `210 250 298 310` |
| 33 | `D7181A7C` | `745528` | `49C` | 10 | `4B0 4CC 500 52C 55C 638 6B0 728 7A0 818` |
| 34 | `D801D868` | `745558` | `78` | 6 | `78 7C A4 AC B8 D4` |
| 35 | `D801D9E0` | `745578` | `1DC` | 4 | `248 264 2B0 2F0` |
| 36 | `D801DB38` | `745590` | `484` | 4 | `48C 4A0 520 598` |
| 37 | `D801DC14` | `7455A8` | `708` | 16 | `708 70C 73C 748 750 764 77C 7A4 7C0 7D0 7E8 7F0 80C 830 8B0 928` |
| 38 | `D801E34C` | `7455F0` | `C10` | 11 | `C10 C14 C3C C44 C4C C70 C98 CB8 CF0 D68 DE0` |
| 39 | `D801E4A8` | `745624` | `F2C` | 4 | `F30 F3C F40 F50` |
| 40 | `D801E62E` | `74563C` | `1168` | 6 | `1194 11BC 1218 12A0 1318 1390` |
| 41 | `D801E6FA` | `74565C` | `14FC` | 10 | `1524 154C 15A8 15E0 15EC 15E4 15F0 1600 1638 16B0` |
| 42 | `D8131A32` | `74568C` | `EC` | 5 | `100 124 150 160 1D0` |
| 43 | `D8163B5E` | `7456A8` | `110` | 15 | `170 200 260 2A4 2D8 380 3A0 3A8 3A4 3AC 3B8 3E4 420 4A8 520` |
| 44 | `D8194F22` | `7456EC` | `7C` | 4 | `80 9C B0 D0` |
| 45 | `D81950F4` | `745704` | `1E4` | 9 | `238 264 280 324 338 36C 3B8 430 48C` |
| 46 | `D819524A` | `745730` | `5AC` | 7 | `5AC 5B4 5B0 5B8 5C4 5E0 618` |
| 47 | `D8195326` | `745754` | `77C` | 8 | `77C 794 7AC 7C0 7D8 7EC 800 820` |
| 48 | `D81953F4` | `74577C` | `944` | 17 | `944 970 990 9A4 9B4 9BC A0C A10 A3C A44 A50 A78 B48 BC0 C38 CB8 D30` |

The 49 even keys each occur exactly once in the aligned owned upper interval 7468A8..750700 and bind a five-word header `[0, packed transform B, key, token A, 0]`. Each derived payload is `[header+14 hex, header+14 hex+(A XOR B))`. All corresponding odd keys occur exactly once at payload end+24 hex; restore metadata starts at end+20 hex and uses a different packed transform/token pair with the same XOR span. These structural and byte checks do not decode any payload. Six common relative bases emerge: `7468A8` (31 records), `74CE60` (3 records), `74D760` (8 records), `74EEE8` (1 records), `74F1A0` (1 records), `74F818` (5 records).

For all 49/49 records the normalized restore selector list is the reverse of the normalized entry selector list. This is a measured schedule relationship; payload equivalence, correct whole-program relocation and intended function meaning remain untested.

Sample clear entry 7468A8 checks header word0, passes payload 746924/header arguments to 7457C8 and branches to the payload. At 74697C a branch skips restore metadata, then 7469AC calls 7457C8 with odd-mode key before restoring registers. Generated entry 74694C starts *inside* the protected span; its decoded-looking jumps are not independent function evidence. Entry 7478C8 and fragment 747908 similarly separate a clear wrapper from skipped data before header 747920. Catalogue interval boundaries and generated comments therefore cannot be used alone to infer original function boundaries here.

The payload union intersects 55 generated catalogue intervals and 163 source-less intervals. Intersection is a **boundary classification**, not a role annotation; clear glue outside the payload union still requires individual review. The final protected payload extends to 75059C, beyond the last local generated interval endpoint 750178. Owned bytes exist there but are not newly invented catalogue functions. All payload byte ranges and hashes below were read directly from the owned image. No function-role coverage credit is assigned by this table.

| Metadata index | Entry header | Protected payload, end exclusive | Byte length | Common relative base | Restore metadata | Owned payload SHA-256 |
| --- | --- | --- | --- | --- | --- | --- |
| 0 | `746910` | `746924..74697C` | `58` | `7468A8` | `74699C` | `0935cd53643514988a05d9cad13924e163dab645078b31d60b7a7f4556f03365` |
| 1 | `746A50` | `746A64..746ABC` | `58` | `7468A8` | `746ADC` | `ad8891f0027d5b57d4c07d5bed6850edf0423d0a5c38639d7afd980acc0acc44` |
| 2 | `746B88` | `746B9C..746BD0` | `34` | `7468A8` | `746BF0` | `f4187f3b4d283a08abe634416172c2c511cc6194ec54c915e4abb9fe76d0aff5` |
| 3 | `746CC4` | `746CD8..74727C` | `5A4` | `7468A8` | `74729C` | `173a145558228476ee64337fe552c865ed37eee338a822851a22d879cff4b494` |
| 4 | `747398` | `7473AC..747524` | `178` | `7468A8` | `747544` | `387bd819bd9618ec8bebea3ebb8deec7a8292ccdf74be728431b4d7b988c0875` |
| 5 | `747610` | `747624..747660` | `3C` | `7468A8` | `747680` | `abb56b00942b20a5456ad8d9330f1675de681f7b823a3a1f2ecdb6c42587ed11` |
| 6 | `747728` | `74773C..747778` | `3C` | `7468A8` | `747798` | `bb5926c9494c475925992e45615e1b62c13e841cd85c1ba1da740ca0762aa52e` |
| 7 | `747838` | `74784C..747864` | `18` | `7468A8` | `747884` | `8416c7c9d757e5db3103370b89ccf532f4058ca2b62d747b234dc2ce5b3a1ee1` |
| 8 | `747920` | `747934..747948` | `14` | `7468A8` | `747968` | `3efdbd62fad275deb439be880ee0403d0c086e3b3f2c004973ff669547e8f004` |
| 9 | `747A08` | `747A1C..747A30` | `14` | `7468A8` | `747A50` | `b1bb8443e11cdd75c8fb10968a2980480c66cb2f09398cf9861eebce50a080d1` |
| 10 | `747AF0` | `747B04..747B1C` | `18` | `7468A8` | `747B3C` | `65c716dab8fe508d45d578384fba2f1d291cd6108625955589f0cbac25d23174` |
| 11 | `747BD8` | `747BEC..747C04` | `18` | `7468A8` | `747C24` | `11289170ec36de13bdac8d61b856757977639ba92f15dbc6f015fdcfb0fbfd0e` |
| 12 | `747CEC` | `747D00..747D18` | `18` | `7468A8` | `747D38` | `fab3db510824218cd5b9e445fa535aa8b326464754f4d1b24a2f13ae81d39472` |
| 13 | `747E1C` | `747E30..747E44` | `14` | `7468A8` | `747E64` | `c4f6181808e1806582a7012c55165cb2aa6c358e309542bbad8a40b55cc52ead` |
| 14 | `747F1C` | `747F30..747FFC` | `CC` | `7468A8` | `74801C` | `6f71153d26ea67291bf211a475a6ea740efd6a4b644ef1f6000c27b7c4a13e39` |
| 15 | `7480EC` | `748100..7481CC` | `CC` | `7468A8` | `7481EC` | `65e08dc6069b94b414b9a093671ef6296e11ae99ac0a8fd0e92ef4c5015607ad` |
| 16 | `7482C0` | `7482D4..748474` | `1A0` | `7468A8` | `748494` | `a25ed04bbf4ff8d1189ea10a7d61e9c4369af0ff63a4ea1267ce2337d20f4b92` |
| 17 | `748570` | `748584..748694` | `110` | `7468A8` | `7486B4` | `683de38c02cdb1ce9caa9f066d2352a1c453548c232ae8a6bc0a4c517d74ace8` |
| 18 | `748770` | `748784..7487C0` | `3C` | `7468A8` | `7487E0` | `a9f58bd4580f1c363b286bc7a816867dc22a691887f9fb4e665dbb5efc0284c2` |
| 19 | `7488A0` | `7488B4..7489C4` | `110` | `7468A8` | `7489E4` | `9eb2ebf9e9ca81cefcaa19b83aef056906b6140ec46e267dbe69be4a85b66d65` |
| 20 | `748AB4` | `748AC8..748B94` | `CC` | `7468A8` | `748BB4` | `a0824cf1dfe7f5d1b03add587454eea49f9a6eb054004d610eff7bf0cc97e528` |
| 21 | `748C70` | `748C84..748CFC` | `78` | `7468A8` | `748D1C` | `139c75c4dce43c6a987b020f0191eb28da7fe67f8799d10c21d25a6ea47aed9f` |
| 22 | `748DE0` | `748DF4..748F04` | `110` | `7468A8` | `748F24` | `06732b6639f9255762fc2cea1bf8fe52f16ca656e864e4c3ac293d3fbb5e5c75` |
| 23 | `748FF8` | `74900C..749234` | `228` | `7468A8` | `749254` | `22fa7dd8cf7cca80150f49a17c37ada85df91ffb9f77c58ba6f772a634715781` |
| 24 | `749328` | `74933C..74944C` | `110` | `7468A8` | `74946C` | `141d840dc57252706d005f9d17f1ac2bcc1ba83960c974266136f927b5eb9410` |
| 25 | `74981C` | `749830..7498E0` | `B0` | `7468A8` | `749900` | `b55001ee42e3305b046fda832bfa55da3ef55fcf4091d906b4ce69005500af4d` |
| 26 | `7499C8` | `7499DC..749B4C` | `170` | `7468A8` | `749B6C` | `42edb82f205422fd3ac36279f81e9719db6ed28309d219657352495f29bc31e6` |
| 27 | `749C20` | `749C34..749C74` | `40` | `7468A8` | `749C94` | `7694522d47b8b044ae26e2a4ebafe9332d4fef39fa067e79f7b762c81e562f52` |
| 28 | `749D4C` | `749D60..749E64` | `104` | `7468A8` | `749E84` | `52e269fc898178bb11a25966e28f0bd9a132b4655babb5bb40138d98418a0123` |
| 29 | `74A410` | `74A424..74A81C` | `3F8` | `7468A8` | `74A83C` | `d7decca61a1dce9f76211f1b7d599037739889a2a3e7a0fe8553d6816e2e9b67` |
| 30 | `74A910` | `74A924..74A99C` | `78` | `7468A8` | `74A9BC` | `a8aaea1c2e71b1966ce593c52dd71ca22ca5d47835dd124c9749127e74b85525` |
| 31 | `74CED4` | `74CEE8..74CF08` | `20` | `74CE60` | `74CF28` | `9f16b1d75f7436645efc13a18a2ae596b9924c0fb50f5d41f55a681db96c74c1` |
| 32 | `74CFFC` | `74D010..74D1C4` | `1B4` | `74CE60` | `74D1E4` | `77d4ba59c0e4995860dd2c5babda99ad35ce31a2cd81fc110ce08118afdfb566` |
| 33 | `74D2E8` | `74D2FC..74D6CC` | `3D0` | `74CE60` | `74D6EC` | `a92d5756dbdd2e5d282e1280ff19910a8b553f35236f0e6438ce22458ad4364a` |
| 34 | `74D7C4` | `74D7D8..74D844` | `6C` | `74D760` | `74D864` | `bbc8f0bfc7be90bc21e25ae89f6f4743a961838c3475ea37eca8accf4c3a1ae3` |
| 35 | `74D928` | `74D93C..74DAE4` | `1A8` | `74D760` | `74DB04` | `fa9c8cec8776145096659ef57ff905845e999a6f0341c595cb457ddcaa4d40e7` |
| 36 | `74DBD0` | `74DBE4..74DD4C` | `168` | `74D760` | `74DD6C` | `6cf917b0565760a94847a7fa1418b6723ebe25a460feda113b39bc360364d7ea` |
| 37 | `74DE54` | `74DE68..74E0DC` | `274` | `74D760` | `74E0FC` | `41136738dc214b361fb234090de5c869fd9a6c988716b145b226cb79755b4c41` |
| 38 | `74E35C` | `74E370..74E594` | `224` | `74D760` | `74E5B4` | `3198c4291dd1cf9813e27372ed41b29724849b4ebf10ad9bb481fb282c3e1109` |
| 39 | `74E678` | `74E68C..74E6BC` | `30` | `74D760` | `74E6DC` | `fe2a173a2ddc10ab238fc0611a40110e61362e5f58e26b503a535d095deeb760` |
| 40 | `74E8B4` | `74E8C8..74EB44` | `27C` | `74D760` | `74EB64` | `1490f8233eacfab9fdd45222289588b6638668a06f104d81396297cd3757e8e5` |
| 41 | `74EC48` | `74EC5C..74EE64` | `208` | `74D760` | `74EE84` | `d456646e3621c7519771fb9de07ab1540bd9537ccec8c5211912e5d9f736478b` |
| 42 | `74EFC0` | `74EFD4..74F10C` | `138` | `74EEE8` | `74F12C` | `4e9db5e9c08d624df70f7bd6f2ff4c6418c2b87c9296ebf684af61ea0cef410f` |
| 43 | `74F29C` | `74F2B0..74F714` | `464` | `74F1A0` | `74F734` | `9c2ee38f8ff0560ab5d52d89f0707b6d15c790807fc8130eb6a80755e7509a22` |
| 44 | `74F880` | `74F894..74F8F0` | `5C` | `74F818` | `74F910` | `8e3c772144b5103f3456bfc392fceae34cfdf06e113618456b855541f12a4cb4` |
| 45 | `74F9E8` | `74F9FC..74FCAC` | `2B0` | `74F818` | `74FCCC` | `c315d3616862ac4034687b063ee7d690043482ba7806abccaa5cd2cf19626bb2` |
| 46 | `74FDB0` | `74FDC4..74FE84` | `C0` | `74F818` | `74FEA4` | `82041b170d03fe6862e6ad6257191973a0a1b06bb92eb2b161abb99a9f18e181` |
| 47 | `74FF80` | `74FF94..750040` | `AC` | `74F818` | `750060` | `41eb56fd16fc4e79162e802f7d380751eef44b0111736e2f83faff3d26d9e053` |
| 48 | `750148` | `75015C..75059C` | `440` | `74F818` | `7505BC` | `0f9e231a4f4d3a5e625da4982e73e2c105ff4bfdcec93c4d0e2e67f9055e524a` |
