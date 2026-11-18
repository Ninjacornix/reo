# Network DNAS: protocol observers and address-list socket connection

Static File #1 US research, 2026-11-04. Catalogue **o4**, runtime id **5**, base **0x6E0000**, owned `netdnas.bin`, SHA-256 **8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16**. Four complete clear bodies, 870 owned instruction words, all208 owned dispatch targets and three protocol strings were independently read. No game, build, replay, target execution, attachment, network request or live-memory inspection occurred.

These routines connect [platform transport](SYMBOLS_NETDNAS_PLATFORM_TRANSPORT.md), [session state accessors](SYMBOLS_NETDNAS_SECURE_LIFECYCLE.md), [protocol labels](SYMBOLS_NETDNAS_SECURE_OPERATIONS.md) and [primitive delay/callback routines](SYMBOLS_NETDNAS_PRIMITIVE_CODECS.md). Static network-related code was inspected without opening sockets or invoking any endpoint. These are descriptive roles, not recovered original names or measured performance findings.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x6EAA60](../recomp/config/output_ovl/o4/o4_006EAA60_0x6eaa60.cpp) | `resolve_address_candidates_and_connect_netdnas_socket_with_service_error_translation` | Confirmed complete address/socket/retry/error flow; resolver ABI partial | Builds16-byte family2 address and converted low16-bit port1D9690; calls1D96B0(host,&address). Zero result uses1D9AA0(host) between SignalSema/PollSema on761780, requires returned record+C<5 and copies four bytes from first address at record10. Creates socket1D97F0(2,1,0) into761774 and calls1D98A0(socket,&address,16). On failure translates pointed1D96E0 error; cancellation -601 or nonzero initial conversion ends retries, otherwise advances resolver address list, closes failed socket and retries until NULL. Error path closes nonnegative socket and resets-1; success returns0. No retry wall-time bound, live DNS result or complete resolver ownership guarantee. |
| [o4 0x6EB8E8](../recomp/config/output_ovl/o4/o4_006EB8E8_0x6eb8e8.cpp) | `translate_resolver_status_or_last_platform_error_to_netdnas_status` | Confirmed complete six-slot mapping and fallback | Unsigned(input+1)<6 selects owned table77C3B0; input-1 translates pointed1D96E0 through6EB868 and remaps -625 to -615. Inputs0..4 map respectively -615,-611,-612,-613,-614; other values -615. No external errno/resolver symbolic name assigned. |
| [o4 0x6EBF30](../recomp/config/output_ovl/o4/o4_006EBF30_0x6ebf30.cpp) | `observe_protocol_name_and_handshake_state_for_legacy_trace_buffers` | Confirmed complete state mapping, cleanup and delay gates; timing unmeasured | Maps71EF50 string SSLv2/SSLv3/TLSv1 to7F1574 values2/3/1, others-1; queries71F228, compares/stores previous state7F1778, calls empty6ED690 with mapped stage codes below. Handles configured positive761794/761798/7617A0 counters and optional6ED610 when7617A8==3, clears selected 256-byte buffers/counters and a50-byte buffer. Repeated identical state clears761794/7F1578 only when nonzero and skips ordinary transition path. No measured callback frequency, delay duration or slowdown attribution. |
| [o4 0x6EC4B0](../recomp/config/output_ovl/o4/o4_006EC4B0_0x6ec4b0.cpp) | `observe_alert_event_bits_and_clear_legacy_protocol_trace_state` | Confirmed complete event gate, dual101-slot tables and cleanup flow; event direction partial | Requires original a1 bit0x4000; bit8 and bit4 separately dispatch original a2 low byte when<=100 to empty6ED690 trace codes. Bit8 indices2/41 additionally set76179C=1. Then protocol marker2 conditionally clears50-byte buffer7F1780/counter7617A0; other markers select256-byte7F1578/counter761794 for bit4 or7F1678/counter761798 for bit8. Positive counter paths may6ED610 when mode7617A8==3. Input session a0 is unused. No actual log output, user-visible event or active delay is established. |

## Owned names and resolver table

Owned NUL-terminated strings are **77C3C8 `SSLv2`**, **77C3D0 `SSLv3`**, **77C3D8 `TLSv1`**. They match the separately reviewed version getter’s texts; no negotiated connection is implied. Resolver table **77C3B0..77C3C8** has all six targets `6EB918 6EB960 6EB940 6EB948 6EB950 6EB958`, SHA-256 **0ee005e833ebae56a32e8a6b6457050d9fe32c8ff7373747668c57dd2d504eaa**.

The connection retry loop enters socket creation before trying another address. On a failed numeric-conversion path it does not dereference a missing resolver record: the nonzero conversion-result branch exits before address-list advancement. The list terminator is the retry boundary; there is no independently imposed candidate count. Address record+C is checked only for unsigned value<5, while four bytes are copied regardless of its admitted length. Null host/record/address admission and actual socket blocking behavior remain provider responsibilities. SignalSema-before/PollSema-after is recorded literally, not named as a wait/lock pair.

## Complete handshake-state event mapping

All following values are hexadecimal. A pair `X/X+1` includes both states. Unlisted states produce no6ED690 call in this observer. State1090 also produces no trace-code call.

| State or states | Trace code |
| --- | --- |
|1010/1011|30|
|1020/1021|31|
|1030/1031|32|
|1040/1041|33|
|1060/1061|34|
|1070/1071|35|
|1091|36|
|1110/1111,1210/1211|20|
|1120/1121|21|
|1130/1131|22|
|1140/1141|25|
|1150/1151|23|
|1160/1161|24|
|1180/1181|26|
|1190/1191|27|
|11A0/11A1|10|
|11B0/11B1|28|
|11C0/11C1|11|
|11D0/11D1|29|

## Complete alert dispatch inventory

Tables **77C3E0..77C574** and **77C580..77C714** each contain101u32 targets, indexed by the low byte0..64hex. SHA-256 values are respectively **f591ab11e83adda068236b98bb7efed6590c0f9289f9e1ce43fa2069f391b547** and **937627c053877f581343484c8ad9f47e1e94cf454070de2659adc5975912bfdd**. All28 nondefault indices and their complete targets/codes follow. The other73 indices use first-table default6EC6C8 and second-table default6EC8B0; exact default intervals are `03,05,07..09,0B..13,17..1D,1F..27,34..3B,3D..45,48..4F,51..59,5B..63`. Inputs above64hex skip their table.

| Index hex | Bit8 target | Code | Bit4 target | Code |
| --- | --- | --- | --- | --- |
|00|6EC508|40|6EC6F8|50|
|01|6EC680|60|6EC878|70|
|02|6EC690|61|6EC888|71|
|04|6EC6B0|62|6EC898|72|
|06|6EC6C0|63|6EC8A8|73|
|0A|6EC518|41|6EC708|51|
|14|6EC528|42|6EC718|52|
|15|6EC5C0|80|6EC7B8|90|
|16|6EC5D0|81|6EC7C8|91|
|1E|6EC538|43|6EC728|53|
|28|6EC548|44|6EC738|54|
|29|6EC558|45|6EC748|55|
|2A|6EC560|46|6EC758|56|
|2B|6EC570|47|6EC768|57|
|2C|6EC580|48|6EC778|58|
|2D|6EC590|49|6EC788|59|
|2E|6EC5A0|4A|6EC798|5A|
|2F|6EC5B0|4B|6EC7A8|5B|
|30|6EC5E0|82|6EC7D8|92|
|31|6EC5F0|83|6EC7E8|93|
|32|6EC600|84|6EC7F8|94|
|33|6EC610|85|6EC808|95|
|3C|6EC620|86|6EC818|96|
|46|6EC630|87|6EC828|97|
|47|6EC640|88|6EC838|98|
|50|6EC650|89|6EC848|99|
|5A|6EC660|8A|6EC858|9A|
|64|6EC670|8B|6EC868|9B|

The primitive6ED690 is an empty return, so its code arguments are evidence of intended trace categories rather than evidence of emitted records. The separately reviewed6ED610 contains counted NOP loops, not a clock measurement. Both observer bodies can invoke it under configuration/counter gates, but this static review does not show those gates enabled during gameplay. All870 generated instruction comments match owned bytes; aligned omissions are zero. No incident or performance claim is made.
