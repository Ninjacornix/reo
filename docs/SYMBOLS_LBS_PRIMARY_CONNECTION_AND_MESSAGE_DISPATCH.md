# LBS primary connection and message dispatch

Static File #1 US main ELF,2026-11-05. Six complete primary-state bodies, full28-row message selector and21-target subphase table. [Identity](FUNCTION_INDEX.md). No connection, DNS request, update, game or build was executed. Literal transport status and state numbers are not measured progress percentages.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x1F6800](../recomp/config/output/sub_001F6800_0x1f6800.cpp) | `begin_lbs_primary_state_and_select_custom_destination_kind` | Confirmed full primary/kind transition | Sets status88=1,primary0=1,detail90=0. If kind35EAF0!=0 and caller output3557C0!=NULL changes kind to2. Returns0; does not open socket or clear context error8C. |
| [0x1F6850](../recomp/config/output/sub_001F6850_0x1f6850.cpp) | `advance_lbs_default_host_dns_tcp_open_and_call_count_connection_deadline` | Confirmed complete four-subphase controller | Subphase0 copies owned defaults259B40/B80 to33C6F0/33CC60,option33C7F8=100decimal, publishes host237420=259AF0 and port237428=278Fhex, advances1. Subphase1 resolver1C92F0 error->state7/code-1,pending0,done->2. Subphase2 opens resolved contextC with swapped port, saves socket10; negative state7/code2, success->3 and signed16 timer4=708hex. Subphase3 decrements timer each invocation; expiry closes/releases and state7/code3; status-query error closes/releases and code4. Normalized status4 advances primary to2,status88=2,subphase0,timer reset708. No seconds/millisecond assertion. |
| [0x1F6B10](../recomp/config/output/sub_001F6B10_0x1f6b10.cpp) | `service_lbs_tcp_receive_match_message_handler_and_drive_outbound_subphase` | Confirmed complete timeout/receive/tables/error paths | Decrements call-count timer; expiry closes/releases with error5. Status query negative closes/releases error6; normalizedstate!=4 closes/releases error7.1F4600 returns0->wait,-1->error8 without local close; other results reset708 timer and continue message dispatch. Matches first non-skipped table row by received bytes2/3/4, invokes its callback. Negative callback result stores error/state7; result1 advances primary unless already7 and returns. Other results then drive21-target outbound subphase table. Full tables below. |
| [0x1F6F50](../recomp/config/output/sub_001F6F50_0x1f6f50.cpp) | `close_lbs_tcp_endpoint_and_select_completion_resolution_state` | Confirmed complete cleanup transition | Detail90=61hex,1D6B50(socket10),1D6B80(&socket10),primary0=6,subphase1=0,timer4=0,returns0. Ignores child cleanup results. Does not publish final status3 itself. |
| [0x1F6FC0](../recomp/config/output/sub_001F6FC0_0x1f6fc0.cpp) | `finalize_lbs_request_with_optional_secondary_host_resolution` | Confirmed complete kind/resolver/status phases | Subphase0 detail62hex:kind0 jumps2;kind1/2 advances1;other kind stays. Clears resolver phase2/timer4. Subphase1 resolves33CC60 into33CC58; failure error-1/state7,done->2,pending waits. Subphase2 detail64hex,status88=3,error8C=0,returns0 without changing primary6. No timeout imposed around resolver or proof of imported patch validity. |
| [0x1F7100](../recomp/config/output/sub_001F7100_0x1f7100.cpp) | `publish_lbs_error_status_and_packed_received_header_identifier` | Confirmed full error/no-error branches | If error8C==0 switches primary6,clears subphase/timer,returns0. Else packs received header byte2/3/4 into return bits16..23/8..15/0..7 and sets status88=4. Does not close socket or clear context error. No host HRESULT or global process-exit meaning. |

## Incoming message selector

Row index decimal; remaining numbers hexadecimal. Class8 rows are skipped. First matching nonNULL handler is called; no second matching handler is visited. Type is received header2,opA=header3,opB=header4. Entire selector112-byte pointer table2373B0 hash`55d1551b69f87b7575a5df65401e66b691f5c5a5d476c906ea14b0f53509aa21`.

| Row | Class | Type | opA | opB | Handler |
| --- | --- | --- | --- | --- | --- |
|0|8|1|1|1|0|
|1|1|1|10|1|1F4DA0|
|2|8|2|10|1|0|
|3|1|1|10|2|1F4E30|
|4|8|2|10|2|0|
|5|8|1|10|4|0|
|6|1|2|10|4|1F5030|
|7|1|10|10|4|1F5040|
|8|1|10|10|5|1F5050|
|9|1|10|60|1|1F50F0|
|10|8|1|60|2|0|
|11|1|2|60|2|1F5310|
|12|8|1|62|1|0|
|13|1|2|62|1|1F59C0|
|14|8|1|62|2|0|
|15|1|2|62|2|1F5C20|
|16|1|10|62|10|1F5E30|
|17|8|1|61|1|0|
|18|1|2|61|1|1F60B0|
|19|1|10|61|10|1F6210|
|20|8|1|61|2|0|
|21|1|2|61|2|1F6420|
|22|8|1|63|1|0|
|23|1|2|63|1|1F67D0|
|24|8|1|64|1|0|
|25|1|2|64|1|1F54F0|
|26|8|1|64|2|0|
|27|1|2|64|2|1F56D0|

Each four selector arrays is28bytes. opA237330 hash`51bf90be348bb0c4d4ba3dfe894fe3137690c821f91afd3f274b6abb733bcc43`;opB237350 `bb7552af7c0f9f4b6e172007fa74f0dc37278e0f2a723172e9c672b00c2f6ea5`;class237370 `bdcc751997d2548c58832b4f55795c9376c6b3bff895e485ca2cbfb518ea2f07`;type237390 `0e05072f1076e7f8a5d1d59bb4931730bb63072b9b2deb494f27efb67f07eed3`. These are full bounded data reads; no generated aliases are substituted for table ownership.

## Outbound subphase selector

Signed subphase is admitted via unsigned<21; negative values skip table. Full21-pointer table259BA0,84bytes SHA-256 `2e625fca4750386350eb16df0420582776fa3d41494d19e7bdaa5d1da1f358c4`:
`1F6DFC,1F6E08,1F6E14,1F6E28,1F6E34,1F6F08,1F6E44,1F6F08,1F6E54,1F6E68,1F6E74,1F6E8C,1F6E98,1F6EB0,1F6EBC,1F6ED4,1F6EE0,1F6F08,1F6EF0,1F6F08,1F6F08`.

| Subphase hexadecimal | Effect |
| --- | --- |
|0/1/3/9/B/D/F| Detail90=10/14/1E/3C/50/28/32 respectively; no outbound call. |
|2|1F51F0 primary range request, then detail18. |
|4/6|1F5450 enumeration /1F5600 group chunk request. |
|8|1F5900 secondary enumeration,detail37. |
|A|Detail46,1F5B50 secondary group chunk request. |
|C|Detail22,1F5F70 path metadata request. |
|E|Detail2C,1F6350 path chunk request. |
|10|1F65D0 report. |
|12|Detail5A,1F4FB0 control send,then subphase14hex. |
|5/7/11/13/14| No outbound work. |

After outbound dispatch, negative returned result becomes context error8C and primary7 with cleared subphase/counters. Details are UI/protocol status codes, not elapsed milliseconds. No-op1F45C0 after receive is kept mechanically classified and contributes no validation. Service can process a newly available fragment without an independent global game update. Lower adapters normalize original TCP results; status alone does not prove a remote response or active native implementation.

Related [workspace](SYMBOLS_RESIDENT_PROFILE_VALIDATION_AND_PLATFORM_REQUEST_WORKSPACE.md), [framing](SYMBOLS_LBS_STYLE_RECORD_SERIALIZATION_AND_TCP_RECEIVE.md), [primary transfer](SYMBOLS_LBS_RESPONSE_TEXT_ID_AND_PRIMARY_DOWNLOAD.md), [group transfer](SYMBOLS_LBS_GROUPED_RESOURCE_ENUMERATION_AND_CHUNKS.md), [path/report](SYMBOLS_LBS_PATH_DOWNLOAD_CONFIGURATION_AND_REPORT.md). All owned instruction comments match; omitted aligned words are zero.
