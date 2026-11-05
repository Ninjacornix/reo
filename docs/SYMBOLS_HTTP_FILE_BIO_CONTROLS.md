# HTTP overlay stdio-style and file-descriptor BIO controls

Static owned File #1 o6 `nethttp.bin`, runtime ID6/base6E0000, SHA-256 `68dbc8f16c5d0cc8a43205beb86ddac405a12c1d6b843b5961211bbe6ec30117`. Fourteen complete catalogue bodies, two complete136-entry jump tables and ten method-table words reviewed. No file opened/closed/read/written, target execution, network activity or build. Offsets, commands and constants hexadecimal. Companion [generic BIO dispatch](SYMBOLS_HTTP_BIO_DISPATCH_AND_CHAINS.md).

Owned getter6FA190 binds FILE-DESCRIPTOR table7351D8 (type504, name `file descriptor`) to controls6FA740. The adjacent stdio-style6FA2A8 body is a separate implementation; its runtime method binding is unresolved. Existing exact aliases1B8/218/258/510/5D0 in [shared bodies](SYMBOLS_SHARED_BODIES.md) are not duplicated.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o6 0x6FA070](../recomp/config/output_ovl/o6/o6_006FA070_0x6fa070.cpp) | `request_bio_explicit_path_mode_control_136_and_convert_nonzero_to_success` | Confirmed complete packing/result wrapper | Packs arguments1/2 as two stack words, calls6F3E70(BIO,88,1,&pair). Returns-1 iff control result0, otherwise1 (including negative control errors). Actual selected method decides pair interpretation; no file open is performed directly. |
| [o6 0x6FA0B8](../recomp/config/output_ovl/o6/o6_006FA0B8_0x6fa0b8.cpp) | `create_default_fd_bio_then_request_explicit_path_mode_pair` | Confirmed full creation/request/cleanup | Gets6FA190 FD method, allocates6F3888, passes original pair through6FA070. Positive wrapper result returns BIO, otherwise destroys it and returns0. Does not independently validate initialized state, descriptor, mode, or low-level control success. |
| [o6 0x6FA128](../recomp/config/output_ovl/o6/o6_006FA128_0x6fa128.cpp) | `create_default_fd_bio_and_issue_noop_control_106_with_opaque_input` | Confirmed full wrapper and owned control binding | Creates same FD BIO, calls control6A with original second arg as integer and first arg as pointer, IGNORES result, returns BIO. Owned FD6A target6FA9E8 is no-op success; actual descriptor setter68 is not invoked here. No input-binding or open success claim. |
| [o6 0x6FA190](../recomp/config/output_ovl/o6/o6_006FA190_0x6fa190.cpp) | `get_file_descriptor_bio_method_table` | Confirmed complete getter/table binding | Returns7351D8; all ten words below bind write6C0/read628/putsAA08/getsAA50/control740/create5B8/destroy5D0. This is not a stdio FILE-pointer method identity. |
| [o6 0x6FA1A0](../recomp/config/output_ovl/o6/o6_006FA1A0_0x6fa1a0.cpp) | `initialize_stdio_style_bio_handle_and_state_fields` | Confirmed complete stores; runtime binding unresolved | Clears opaque handle20/initializedC/number1C, returns1. Does not clear flags14. Nearby stdio callback contracts do not prove this constructor is selected by6FA190. |
| [o6 0x6FA2A8](../recomp/config/output_ovl/o6/o6_006FA2A8_0x6fa2a8.cpp) | `control_stdio_style_bio_seek_handle_mode_open_close_policy_and_flush` | Confirmed full switch/mode/failure flow; method binding unresolved | Commands1/80 seek handle20 by integer offset from start, return1 or-1;2 returns stream flags+C bit5;3/85 delegate position.6A closes prior handle per policy then stores pointer directly20/init1/closePolicy=integer&1;6B optionally stores handle through pointer.6C derives mode from flags8 append,2 read,4 write: a+/a/r+/w/r;88 uses explicit pair path/mode. Both close prior handle before105738 open, update policy, publish handle/init only success; failure logs errno plus fopen data.8/9 get/set close policy, B flush returns1/-1,C returns1; others0. No strict mode/path/null or transaction rollback checks. |
| [o6 0x6FA570](../recomp/config/output_ovl/o6/o6_006FA570_0x6fa570.cpp) | `write_nul_terminated_string_through_stdio_style_bio_callback` | Confirmed full wrapper | strlen then6FA258(BIO,text,length); returns callback result. This is distinct from table-bound FD puts6FAA08. No null-source guard or newline append. |
| [o6 0x6FA5B8](../recomp/config/output_ovl/o6/o6_006FA5B8_0x6fa5b8.cpp) | `initialize_fd_bio_flags_descriptor_and_state` | Confirmed complete table-bound constructor | Clears flags14/initializedC/descriptor1C/opaque20 and returns1. Does not acquire/open a descriptor or set initialized1. |
| [o6 0x6FA628](../recomp/config/output_ovl/o6/o6_006FA628_0x6fa628.cpp) | `read_fd_bio_and_set_retry_read_flags_for_classified_nonpositive_result` | Confirmed full call/result/flag path | Null destination returns0. Clears global errno through104EF0, calls1190B0(fd1C,buffer,count), clears retry flags, and for result<=0 invokes726688; classified retry sets9 through6F3788. Returns actual read result. No local BIO initialized/null/count gate; generic dispatcher supplies separate initialized check. |
| [o6 0x6FA6C0](../recomp/config/output_ovl/o6/o6_006FA6C0_0x6fa6c0.cpp) | `write_fd_bio_and_set_retry_write_flags_for_classified_nonpositive_result` | Confirmed complete callback | Clears errno, calls119310(fd1C,buffer,count), clears retry flags; result<=0 classified726688 setsA through6F3798. Returns actual result. No local null-source/positive-count/initialized guard or complete-write loop. |
| [o6 0x6FA740](../recomp/config/output_ovl/o6/o6_006FA740_0x6fa740.cpp) | `control_fd_bio_seek_descriptor_binding_flags_and_path_open` | Confirmed full switch/initial branches; direct-open flags partial |1 seeks0/start;80 seeks supplied integer/start, returns1 iff actual offset equals request else-1.3/85 query current position.68 closes prior per policy, reads descriptor through pointer, stores1C/init1/policy.69 returns descriptor and optionally stores it, or-1 if uninitialized.6C chooses SCE flags203/202/3/602/1 from append/read/write bits and enters open path.88 copies explicit pair to stack40/44 but does NOT initialize stack48 open flags, which common path passes118A70. Common open closes prior per policy, prewrites1C from pointer firstword, then publishes actual fd/init on nonnegative result.8/9 get/set policy;B/C/2/6A return1 with no I/O; all others0. No runtime admission or unintended-open claim. |
| [o6 0x6FAA08](../recomp/config/output_ovl/o6/o6_006FAA08_0x6faa08.cpp) | `write_fd_bio_nul_terminated_string_by_length` | Confirmed full table-bound wrapper | strlen(source), calls6FA6C0, returns result. No newline append or local null guard. |
| [o6 0x6FAA50](../recomp/config/output_ovl/o6/o6_006FAA50_0x6faa50.cpp) | `read_fd_bio_line_by_bulk_read_and_seek_back_to_consumed_boundary` | Confirmed complete read/scan/seek flow | Unconditionally writes output[0]=0 even when capacity<=0; nonpositive then returns0. Queries current position118E78, reads capacity-1 bytes1190B0, scans via10B0D8 with owned LF delimiter73B830, optionally includes LF and writes NUL. Returns strlen of text if reposition to oldPosition+consumed succeeds, otherwise0. No explicit NUL at raw bulk-read length before scan in this body; scan admission/delegate safety unresolved. No retry-flag propagation. |
| [o6 0x726688](../recomp/config/output_ovl/o6/o6_00726688_0x726688.cpp) | `classify_fd_retry_only_for_minus_one_or_zero_result_and_current_errno` | Confirmed complete result gate | Unsigned(result+1)<2 admits EXACT-1 or0; otherwise returns0. Admitted route reads current errno104EF0 and delegates exact numeric classifier7266C8. Existing alias classifies4/B/47/77/78 as retry; no portable errno-name equivalence assumed. |

Method7351D8 words:

```
00000504 0073B310 006FA6C0 006FA628 006FAA08
006FAA50 006FA740 006FA5B8 006FA5D0 00000000
```

Complete jump-table interpretation (all136 indices1..88):

| Table / command indices | Target PC |
| --- | --- |
| stdio73B360:1,80 |6FA2FC|
| stdio:2 /3,85 /8 /9 /B /C |6FA314 /6FA324 /6FA4BC /6FA4C4 /6FA4D0 /6FA4E4|
| stdio:6A /6B /6C /88 |6FA334 /6FA4AC /6FA354 /6FA400|
| stdio:every other index1..88 |6FA4EC|
| FD73B610:1 /80 /3,85 |6FA790 /6FA794 /6FA7B8|
| FD:2,6A /8 /9 /B,C |6FA9E8 /6FA9C8 /6FA9D0 /6FA9DC|
| FD:68 /69 /6C /88 |6FA934 /6FA958 /6FA7D0 /6FA97C|
| FD:every other index1..88 |6FA9E4|

Owned jump-table SHA-256s: stdio136words `9539a083a23ea4b67580251215687a8154fcfe58a8ef30f6af65f161612ef04a`; FD136words `4e2e8110cd181ec1b7af981e3ee79efddcc58c8006d51005646c365000d3a982`. Mode literals73B320/328/330/338/340 are a+/a/r+/w/r; FD diagnostic strings identify SCE flags. These are preserved call/ownership observations; unbound stdio code, numeric command mismatches, and stack-field initialization limits are not claims of a reproduced file failure or gameplay slowdown.

Audit: 590 verified instruction words, zero conflicts, 4 omitted zero words (NOP padding), zero omitted nonzero words.
