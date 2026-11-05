# HTTP overlay DES parity and schedule adapters

Static owned o6 `nethttp.bin`, runtime ID 6/base `6E0000`, SHA-256 `68dbc8f16c5d0cc8a43205beb86ddac405a12c1d6b843b5961211bbe6ec30117`. Both full catalogue intervals and the entire referenced parity table were reviewed. No target execution or cryptographic test. The underlying expansion and CBC routines are in [DES schedules](SYMBOLS_HTTP_DES_CBC_AND_KEY_SCHEDULES.md).

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o6 0x7243C0](../recomp/config/output_ovl/o6/o6_007243C0_0x7243c0.cpp) | `normalize_eight_des_key_bytes_to_owned_odd_parity_table` | Confirmed entire loop and 256 table entries | Replaces exactly eight bytes in place using `73EFA0[inputByte]`; first iteration is unconditional, then unsigned pointer comparison against original pointer+8. All 256 owned table entries preserve the upper seven bits and yield odd bit parity. No null or pointer-wrap admission. |
| [o6 0x724898](../recomp/config/output_ovl/o6/o6_00724898_0x724898.cpp) | `expand_des_key_schedule_through_existing_optional_check_entry` | Confirmed complete forwarding wrapper | Calls already mapped `7244B0` with all argument registers unchanged and returns its result. Adds no validation or transformation. |

Owned table `73EFA0..73F0A0` (256 bytes), SHA-256 `ba347f0da6d742f7fdcc4710305b97ea02ab6ff39d89fb93be853b03a82757ff`. Table arithmetic was checked offline against all byte values; that check does not prove the cipher implementation or runtime use.

Audit: 18 verified instruction words, zero conflicts, 3 omitted zero words (NOP padding), zero omitted nonzero words.
