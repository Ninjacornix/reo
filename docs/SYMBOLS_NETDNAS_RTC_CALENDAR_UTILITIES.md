# Network DNAS: RTC-shaped calendar utilities

Static File #1 US research, 2026-11-04. Catalogue **o4**, runtime id **5**, base **0x6E0000**, owned `netdnas.bin`, SHA-256 **8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16**. No game, build, replay, attachment, network request or live-memory read occurred.

Five full clear bodies were independently read. These are wall-calendar shaped utilities; their caller context does not establish an original-game update clock, active gameplay timing or slowdown cause. Resident101D08 is an unreviewed static provider boundary, so the RTC label is a proposed role rather than proof of current hardware/runtime behavior. These functions are distinct from the already mapped [private calendar](SYMBOLS_NETDNAS_PRIVATE_TIME.md) and [external time](SYMBOLS_NETDNAS_EXTERNAL_TIME_CODECS.md) APIs.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x724748](../recomp/config/output_ovl/o4/o4_00724748_0x724748.cpp) | `read_bcd_calendar_fields_and_convert_to_epoch_relative_seconds_candidate` | Confirmed arithmetic/control flow; provider/calendar limits retained | Calls resident101D08 into stack; requires nonzero return and byte0==0, otherwise-1. BCD offsets7/6/5/3/2/1 become year+100, month-1, day, hour, minute, second; year absolute=2000+BCD. Computes day-of-year724810 then724880 on a tm-shaped stack. Exact RTC source, timezone and failure contract of resident provider remain partial. |
| [o4 0x7247F0](../recomp/config/output_ovl/o4/o4_007247F0_0x7247f0.cpp) | `decode_one_packed_decimal_byte_without_nibble_validation` | Confirmed arithmetic/control flow; provider/calendar limits retained | Returns10*(byte>>4)+(byte&Fhex). Accepts all256 values; no BCD admission check. |
| [o4 0x724810](../recomp/config/output_ovl/o4/o4_00724810_0x724810.cpp) | `calculate_one_based_gregorian_day_of_year_from_month_table` | Confirmed arithmetic/control flow; provider/calendar limits retained | Selects ordinary/leap row77F358 using divisible-by4 and century100/400 exceptions, returns u16 table[month]+day. Full26 halfwords read below. No month/day bounds or timezone processing. |
| [o4 0x724880](../recomp/config/output_ovl/o4/o4_00724880_0x724880.cpp) | `normalize_tm_month_and_clamp_seconds_then_convert_from_year_1970` | Confirmed arithmetic/control flow; provider/calendar limits retained | Reads sec0/min4/hour8/dayC/month10/year14. Signed division normalizes month by12, including negative-remainder correction and year carry. Gregorian month-table row; seconds clamped0..59. Builds reference tm year70/day-of-year0/time0; passes target year, computed zero-based day-of-year, hour/minute/clampedsec and reference to724998. No local month-day validity or timezone adjustment. |
| [o4 0x724998](../recomp/config/output_ovl/o4/o4_00724998_0x724998.cpp) | `compute_gregorian_tm_relative_second_difference_from_year_and_day` | Confirmed arithmetic/control flow; provider/calendar limits retained | NULL reference returns1. Uses target/ref tm-year, day-of-year18, hour8, minute4, second0; constructs365*year delta plus leap/century corrections and day delta, then*24+hour,*60+minute,*60+second using64-bit shifts. Gregorian difference role follows the connected epoch wrapper and table; full negative-year/overflow correctness remains untested. Does not mutate input or consult game clock. |

Complete owned month table77F358..77F38C (52 bytes), little-endian u16, SHA-256 `a75b72daa85f22e39550ca6180f18943ab0ae58eda137ee40b048ae92889125b`:

```text
ordinary: 0 31 59 90 120 151 181 212 243 273 304 334 365
leap:     0 31 60 91 121 152 182 213 244 274 305 335 366
```

No platform time call, epoch sample, date test vector or runtime sampling was performed. Original symbol spelling and complete calendar validity remain unknown.
