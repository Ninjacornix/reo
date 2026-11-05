# Overlay o3 browser retry errors and configuration callback

Static File #1 US research, 2026-11-04. [Owned provenance and audit](SYMBOLS_O3_MENU_INPUT.md), [form/request state transitions](SYMBOLS_O3_FORM_REQUEST_TRANSITIONS.md), [request pools and history](SYMBOLS_O3_REQUEST_POOLS_HISTORY.md), [transport stub limitations](SYMBOLS_O3_TRANSPORT_REQUESTS.md). These 11 source-backed roles were reviewed directly. No game, build, replay, network traffic or live attachment. Proposed labels describe static behavior, not original symbols, handwritten translations, measured timing or incident causes.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o3 0x599590](../recomp/config/output_ovl/o3/o3_00599590_0x599590.cpp) | `classify_browser_start_error_and_build_local_html_page` | Confirmed/static mechanics; intent partial where stated | Saved+21E string length<8 returns-1. Context30 modes1/2 return0;4/5 classify exact owned102-/103- error codes into5A3AA0 category6,index0..6 plus back-link flag. Group6 is unsupported by5A3AA0 (only2/3/4/8), so the returned pointer is zero before the subsequent strcpy to saved2421; this is a static caller/callee mismatch, with runtime consequences and reachability untested. See [message lookup contract](SYMBOLS_O3_DRAW_PARSER_ARENA.md). It then builds599A80 at root4DB5C, prepares owned memory://%03d with argument0, restarts598FA0, returns1. Other modes-1. Codes and categories are detailed below; no server responses observed. |
| [o3 0x5998B0](../recomp/config/output_ovl/o3/o3_005998B0_0x5998b0.cpp) | `retry_browser_url_after_retry_flag_with_three_attempt_limit` | Confirmed/static mechanics; intent partial where stated | Requires root60DCB==1 else0. Prepares root4F7A0 URL, increments root60DCC byte; exactly3 returns0. If URL equals saved8A6DDC, calls598EC0 then598FF0, otherwise598FA0; returns2. This is one retry invocation, not a polling loop; byte wrap and repeated later calls are not proven impossible. |
| [o3 0x599980](../recomp/config/output_ovl/o3/o3_00599980_0x599980.cpp) | `retry_saved_browser_identity_request_or_open_failure_modal` | Confirmed/static mechanics; intent partial where stated | Increments root60DCC byte. Unless exactly3, calls598C10; signed-byte return1 returns1. Otherwise clears context30, sets root60DCA3, invokes599150, sets modal2=1, returns2. This general retry-failure caller is why599150 is not exclusively a pending-resource exit UI. |
| [o3 0x599A30](../recomp/config/output_ovl/o3/o3_00599A30_0x599a30.cpp) | `append_nul_terminated_segment_at_browser_html_cursor` | Confirmed/static mechanics; intent partial where stated | a0 points destination cursor,a1 source,a2 bytecount. memcpy(*cursor,source,count), advances cursor by count-1. The NUL-overwrite append convention depends on caller including a terminal NUL; no local size or count-zero guard. |
| [o3 0x599A80](../recomp/config/output_ovl/o3/o3_00599A80_0x599a80.cpp) | `assemble_browser_error_html_with_optional_return_link` | Confirmed/static mechanics; intent partial where stated | a0 destination,a1 message,a2 errorID,a3 includeBackLink. Appends fixed owned HTML prefix60C920 length332, message plus NUL, error-label60CB20 length24, errorID plus NUL; chooses footer60CAB0 length105 with mmbb://BACK_TO_MENU or60CA70 length50 without link. Uses599A30 cursor convention; no destination-capacity argument. Owned Japanese title and heading identify an error screen/game-start failure. |
| [o3 0x599B50](../recomp/config/output_ovl/o3/o3_00599B50_0x599b50.cpp) | `increase_browser_retry_interval_with_300_1800_limits` | Confirmed/static mechanics; intent partial where stated | Resident67935C signed value<300 becomes300; otherwise adds150; values>=1801 then clamp1800. No clock read, delay, sleep or unit conversion. Label interval follows surrounding retry context; real-time units unresolved. |
| [o3 0x599B90](../recomp/config/output_ovl/o3/o3_00599B90_0x599b90.cpp) | `reset_browser_retry_interval_to_300` | Confirmed/static mechanics; intent partial where stated | Stores300 to resident67935C and returns. No established return value or timing unit. |
| [o3 0x599BA0](../recomp/config/output_ovl/o3/o3_00599BA0_0x599ba0.cpp) | `map_current_session_mode_to_zero_one_or_invalid` | Confirmed/static mechanics; intent partial where stated | Reads resident6479EA: value1 returns0,2 returns1, all others-1. No request work, mutation or input polling. |
| [o3 0x59BA00](../recomp/config/output_ovl/o3/o3_0059BA00_0x59ba00.cpp) | `start_async_configuration_snapshot_controller` | Confirmed/static mechanics; intent partial where stated | Stores a0 completion callback645024, clears stage645041, sets active645040=1 and controller function645020=59BA40; returns0. No worker call or configuration copy yet; asynchronous intent established by callback state machine. |
| [o3 0x59BA40](../recomp/config/output_ovl/o3/o3_0059BA40_0x59ba40.cpp) | `advance_configuration_snapshot_controller_and_report_completion` | Confirmed/static mechanics; intent partial where stated | Active645040 gate. Stage0 clears76-byte67B914 descriptor, copies scalar fields from645480 and resident8A64F0 inputs; builds three8-byte pointer/flag descriptors referencing17-byte fields6454C2+, assigns pointer35EC48, calls1F4140 and advances stage1. Stage1 calls1F4220(out): status3 calls1F4290 and stage2; status4 calls1F4290 and callback with byte0 FF plus word8 error. Stage2 calls callback with byte0=0 and word8=0. Clears active/stage before callback. Callback receives same stack record in a0/a1; unspecified bytes are not initialized here. Other status waits for a future invocation; no inline busy wait. Exact configuration/service identity unresolved. |
| [o3 0x59BC50](../recomp/config/output_ovl/o3/o3_0059BC50_0x59bc50.cpp) | `invoke_stubbed_transport_opcode_e0_with_six_byte_payload` | Confirmed/static mechanics; intent partial where stated | Calls585D60(67CB20,E0), retains lowhalf;585DE0(buffer,a0original,6),585D90,585E00 then returns retained value. Earlier owned stub audit establishes585D60 returnsa1 while the other callees are return-only. Therefore current owned path returnsE0 without real payload serialization or sending; wrapper intent does not establish transport activity. |

Owned error-code classification in599590:

| Exact result code(s) | Message category index | Include return link |
| --- | --- | --- |
|102-0002,103-0002|0|Yes|
|102-4000,103-4000|0|No|
|102-4201,103-4201|0|Yes|
|102-4204,103-4204|1|Yes|
|102-4205,103-4205|0|Yes|
|102-4206,103-4206|2|Yes|
|102-4200|3|No|
|102-4203|4|No|
|102-8001|5|Yes|
|Other strings of length at least8 in result modes4/5|6|Yes|

These are local response-code/UI mechanics. The code meanings, live server behavior and real-world failure frequencies remain unknown. No remote URL or service was contacted.

Owned-word gap audit: `540` commented instruction words verified, zero conflicts, `23` omitted zero/NOP words, zero omitted nonzero words within catalogue intervals (`audit_note_words.py`).
