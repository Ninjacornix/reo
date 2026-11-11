# EMD runtime actor field binding and callback traversal

Static File #1 US research, 2026-11-04. Four complete original bodies reviewed.
Addresses, offsets and state values are hexadecimal; explicit counts are decimal.
The labels describe observed operations, not recovered original enemy names.
No game execution, attachment, build, replay or engine changes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6BB9F0](../recomp/config/output_ovl/o2/o2_006BB9F0_0x6bb9f0.cpp) | `initialize_actor_four_priority_selectors_from_emd_policy_candidate` | High mechanics; policy meaning provisional | Reads priority byte at 74F292+60*actor.B98. BA4=0/2 selects four bytes from 72F830/72F880+5*priority into BB6..BB9. BA4=1 uses 72F858: leading 4 changes BA4 to 2 and copies bytes1..4; other leading values copy bytes0..3. Other BA4 returns. Priority index admission remains an asset/caller contract. |
| [o2 0x6BBBA0](../recomp/config/output_ovl/o2/o2_006BBBA0_0x6bbba0.cpp) | `tick_scenario_actor_expiry_records_and_reverse_node_callbacks_candidate` | High mechanics; cadence unknown | Calls 6409C0/6409D0, sets 74F200 to 1 when 3243CC=0 and otherwise 2, clears four bytes755350. A change in 4BAE02 against 3B5040 decrements signed byte37FD80; post-value<=0 resets5 and admits the periodic record pass. That pass scans 256 bytes3B5050: non-FF entries decrement, zero becomes FF and calls5A74F0(record74F250+60*i). Walks tail3B5900 through prev1C; active nodes clear runtime byte45 bit10, call node14, call65E4A0 unless C94 bit4, initialize C8B through376DB0 once, then clear C98. Does not establish per-second cadence or runtime expense. |
| [o2 0x6BBDA0](../recomp/config/output_ovl/o2/o2_006BBDA0_0x6bbda0.cpp) | `bind_expanded_emd_record_to_actor_runtime_fields_candidate` | High mechanics; semantic field names provisional | a0 actor N, a1 expanded record R. Copies identity, health, position, motion and policy fields; resolves descriptor scale, numeric masks, randomized timer tables and selected actor binding as detailed below. Calls6EFAF0 and main RNG1AEC80 twice. Parent6BB040 invokes6BB9F0 after this binder. No allocation or file read. Final N24 assignment replaces an earlier encoded target binding; original behavior preserved without asserting a fault. |
| [o2 0x6BC210](../recomp/config/output_ovl/o2/o2_006BC210_0x6bc210.cpp) | `resolve_emd_route_selector_into_signed_record_route_index_candidate` | High mechanics | a0 record. Default result -1; nonnull6D45A0 route data is passed with signed R22 to6D4650. Narrows result to signed byte and replaces negative values with -1; stores R40. Route asset validity remains caller-owned. |

BBDA0 field binding, with N=actor and R=expanded 60-byte runtime record:

| Source / computation | Actor destination |
| --- | --- |
| R0; halfR1C/R1E; R20; signed byteR21 | B98; health544/546; BA3; B9E |
| signed wordsR10/R14/R18 converted to float | position38/3C/40 |
| wordsR8/RC narrowed; literal0 | rotation90/92; rotation94 |
| literals1/0/0 | byte553/wordAA8/byte54D |
| R3/R4 | halfBBA/byteBA9 |
| actor+AEC | word1DC |
| R29/R2A/R2B/R3A/R26/R2D | BA7/C2B/B9C/B9D/B9A/BAA |
| ten bytesR2F..R38 | BAC..BB5 |
| R7 low nibble | C26 |
| R7 bit80 set | C25=1, word24=417090+1170*(C26 modulo 10 decimal) |
| R7 bit80 clear | C25=0, word24=4A5C30+10E0*(C26&3) |
| literals0; 6EFAF0(N) result | BA6/C2E; byte199 |
| descriptor387E90[N3].pointer+10*BBA, float8 | scalesB4/B8/BC |
| nonzero R57/R58/R59 divided by 100 decimal | corresponding scale overrides |
| R46/R47; R53 | bytes4/5; BA1 |
| R50/R51/R52 | C86/C87/C88 |
| word72B170[R4C]; word72B190[R4D] | C8C; C90 numeric policy masks |
| float72B1B0[R4A/R4B] | BCC/BD0 |
| R48/R49 | C89/C8A |
| signed half72BC20+10*R54+2*(RNG stream0&7) | BDA |
| signed half72BCA0+10*R54+2*(next RNG stream0&7) | BDC |
| literals1/0/0/0 | C20/C21/C22/C23 |
| byte72BE20[N3] | C24 |
| R55/R56/R4E/R4F | C27/C28/C2A/C85 |
| literal3; R5A | C84; BA4 |
| final unconditional 4A5C30+10E0*byte4BADED | word24, overwriting the earlier encoded target address |

Owned o2 bytes were read from `build-function-index/owned-overlays/o2.bin`,
base570000, SHA256
`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.
The physical spans below are reviewed evidence, not proof of every valid index.

| Span | Owned values / SHA256 |
| --- | --- |
| 72F830 length78 | 24 five-byte rows in three eight-row banks. Bank0 rows[0,1,2,3,FF],[3,2,1,0,FF],[1,3,0,2,FF],[2,1,3,0,FF], repeated; bank2 matches. Bank1 first four rows use those four permutations followed by4; next four prepend4 to those permutations. `53f61bcc3e303bf5691cbe1566456eb43a296b2ab5be7cd83a91219c2a825f3d` |
| 72B170 length20 | Eight words[3FFC,5550,5FFA,6AA4,71C0,8000,9FF6,0]. `81f453b75816371a3f5a9718f10399266707ee9db194fd74b055e6123a08d936` |
| 72B190 length20 | Eight words[1554,1FFE,2AA8,3FFC,71C0,8000,9FF6,0]. `a40944893ded37f97581cbaa464e300706e34992bd3a66de307875fc931cb0f6` |
| 72B1B0 length20 | Eight floats[0,100,200,300,400,500,600,700] decimal. `806951f11e33fc4a0e8676a480a8ba5645d86dadb78b30c4f04c87cc932e5695` |
| 72BC20 length80 | Eight physical rows of eight signed halves; first row eight copies of728 decimal. `dc6561022bb0d366cb2c1db4204334b5c2646e8f86f20ad781a87148e67ddeea` |
| 72BCA0 length180 | 24 physical rows of eight signed halves; first row eight copies of728 decimal. `bed39e81477c0da2fc20d15dbd85648c2e3064a51fb90dc3c638cfccd738da52` |
| 72BE20 length40 | Nonzero value8 at indices1,16,17,1D,2B; other reviewed bytes0. `41404dd93df2fed25b7acfb3086a65e65afb2170ff3abef5e82075222ec1b144` |

The mask tables establish that C8C is a numeric policy value. The earlier
[target admission note](SYMBOLS_ACTOR_TARGET_SCORE_ADMISSION.md) has been corrected
accordingly. Record expansion and callback class bindings are in
[EMD installation](SYMBOLS_EMD_ACTOR_RECORD_INSTALLATION.md); route lookup mechanics
are in [route dispatch](SYMBOLS_RUNTIME_ROUTE_POINT_NEIGHBORS.md).

Full-body owned-word audit: four rows, 521 verified instruction words,
zero conflicts, 18 omitted zero/NOP words, zero omitted nonzero words.
