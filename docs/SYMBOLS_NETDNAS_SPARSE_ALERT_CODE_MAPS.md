# Network DNAS: two complete sparse numeric status/alert maps

Static File #1 US research, 2026-11-04. Catalogue **o4**, runtime id **5**, base **0x6E0000**, owned `netdnas.bin`, SHA-256 **8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16**. Both complete clear bodies, all150 jump-table words and every target instruction were read and checked. No game, build, replay, target execution, network request, attachment or live-memory observation occurred.

The sparse numbers resemble SSLv3-style alert/status codes and one map has a direct incoming call from721618. Exact input/output behavior is established below; original enum names, full caller meaning, runtime use and gameplay performance remain unknown. The role labels preserve that boundary.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x71AF78](../recomp/config/output_ovl/o4/o4_0071AF78_0x71af78.cpp) | `map_sparse_numeric_status_to_alert_shaped_code_with_default_forty_six` | Confirmed complete finite mapping; enum/domain interpretation partial | Subtracts2 from64-bit input, unsigned-tests result<49; in-range selects one of49 owned u32 targets at77EB00. All targets are local JR/constant-return pairs; no writes or child calls. Out-of-domain returns46decimal. Complete decimal mapping below; no assumption all statuses arise from certificate verification or are enabled alerts. |
| [o4 0x71BFA0](../recomp/config/output_ovl/o4/o4_0071BFA0_0x71bfa0.cpp) | `normalize_sparse_alert_shaped_numeric_codes_or_return_minus_one` | Confirmed complete finite mapping; original alert enum partial | Unsigned input<101 selects one of101 owned u32 targets at77EBF0; other inputs return-1. Some inputs preserve their number, others collapse to20/40/42; most return-1. Every branch/target is independently checked below. No direct incoming edge in current catalogue, which does not prove unused. |

## Complete decimal mappings

For71AF78 the following groups cover every input in2..50. All inputs outside that interval return46. No rows or implicit ranges have been assigned additional function credit.

| Output | Input values, decimal |
| --- | --- |
|48|2,3,18,19,20,21,22|
|42|4,5,6,9,11,13,14,15,16|
|51|7,8|
|45|10,12|
|80|17|
|44|23|
|46|24..49 inclusive|
|40|50|

For71BFA0 these are all admitted nonnegative results. Every other input, including all remaining values0..100 and all out-of-domain values, returns-1.

| Output | Input values, decimal |
| --- | --- |
|0|0|
|10|10|
|20|20,21,22|
|30|30|
|40|40,49,50,51,60,70,71,80,90|
|41|41|
|42|42,48|
|43|43|
|44|44|
|45|45|
|46|46|
|47|47|

## Owned dispatch data and validation

77EB00..77EBC4 is49 little-endian u32 targets (196bytes), SHA-256 `ade8910ff92b31c80e490571e1fe8987b25f99ea72b077dbcf8c85adc8018cd1`. 77EBF0..77ED84 is101 targets (404bytes), SHA-256 `448b3307a052eeb5cfe0325c1c3c147d5db61bb709e183fe4949f39b5bbb6ac3`. The complete decoded groups above were derived from every table entry and the actual constant in its target's JR delay slot. All150 destinations exist as owned, independently reviewed instruction comments in the corresponding body. Adjacent strings/other data are outside these table intervals.

Two independent catalogue rows,63 original instruction comments. Full aligned intervals were audited against the hashed owned image: no conflicting or omitted nonzero words. All local links resolve. This is a static numeric mapping, not an alert emission, security diagnosis or engine fix.
