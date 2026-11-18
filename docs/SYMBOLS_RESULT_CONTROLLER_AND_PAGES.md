# Result controller, registration selection and page rendering

Static File #1 US, 2026-11-04. Six complete original o2 bodies. Mechanics confidence is high; result/UI role labels are candidates. No execution, build, attachment, live memory, input or measurements. Addresses, field offsets and IDs are hexadecimal; explicitly named counts are decimal.

W=word7436F8, initialized by [result workspace loading](SYMBOLS_RESULT_WORKSPACE_AND_ROW_RENDERING.md). This maps original guest bodies, with the [font/native override boundary](SYMBOLS_FONT_OVERRIDE_BOUNDARY.md) retained. Static rendering calls do not prove those original callees run in the current native build. Complete fixed descriptor and atlas bytes are in [result descriptor tables](SYMBOLS_RESULT_SCREEN_DESCRIPTOR_TABLES.md).

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x600A40](../recomp/config/output_ovl/o2/o2_00600A40_0x600a40.cpp) | `advance_result_screen_input_selection_pages_and_exit_candidate` | High mechanics; role probable | State0 initialization; state1 exact-button interactive selection, page rendering and idle exit; state2 yields zero; state3/4 two countdown exit. Returns1 only after release completes, clears W pointer; all other paths0. No NULL admission. Inputs low16 of324210/324228 replace W8/A each call. |
| [o2 0x6013B0](../recomp/config/output_ovl/o2/o2_006013B0_0x6013b0.cpp) | `emit_result_common_frame_scene_heading_and_local_identity_candidate` | High mechanics; role probable | GS6C=0; backdrop70D4C8 twice around6EC4E0, common22+8 descriptor rows; heading70D190+12*W1CC, then W320/W360 text at70D338. Leaves GS6C unchanged at0; page caller restores1. |
| [o2 0x6014F0](../recomp/config/output_ovl/o2/o2_006014F0_0x6014f0.cpp) | `emit_result_primary_layout_identity_rank_time_registration_and_peer_panels_candidate` | High mechanics; role probable | Normal layout when signed8AA2B3==0. Fixed descriptors, five local statistic fields, three bounded peer panels, registration-capacity text and selection icons. Seven-byte rank seed FEDCBAS; identity/name, completion, rank/time, count and points formatted via original helpers. GS6C=1 at end. |
| [o2 0x601DB0](../recomp/config/output_ovl/o2/o2_00601DB0_0x601db0.cpp) | `emit_result_alternate_layout_extra_statistic_and_peer_panels_candidate` | High mechanics; role probable | Alternative main-page layout for nonzero8AA2B3. Six statistics include additional1C1F00(byte4BAE8A+A); extra label and different geometry, marker rows, points format. Same three peer panels/selection contracts. Original language/layout enum unknown. |
| [o2 0x6026B0](../recomp/config/output_ovl/o2/o2_006026B0_0x6026b0.cpp) | `emit_result_numeric_statistics_and_special_item_names_candidate` | High mechanics; role probable | Common frame, 83 fixed page descriptors and animated prompt;14 labels with rows5/6 conditionally skipped.12 numeric values from five helper bytes, converted float667F90 and six unsigned halves3B84E8..F2; first six append raw8193. Then draws byte4B9D19 item names from halves4BAC72+2*i without local coordinate-count clamp. |
| [o2 0x602A30](../recomp/config/output_ovl/o2/o2_00602A30_0x602a30.cpp) | `emit_result_completion_ratio_and_scrolled_eight_event_text_rows_candidate` | High mechanics; role probable | Common frame,41 page descriptors, conditional up/down indicators, prompt, completion heading. Pretested at most8 indices starting WBC; stops atFFFFFFFF, decodes selected scene/event through603080. Does not otherwise compare each source read against WB8. Restores GS6C=1. |

600A40 initialization searches five owned scene IDs, stores first matching index or5 in W1CC. The common header then reads a descriptor at that index; the physical index5 row overlaps the next layout and is recorded explicitly, rather than assuming an admitted sixth heading. Signed clock4BADE8 is divided by108000, then1800, then30 to W1C0/1C4/1C8. Hours>=1000 saturates to999:59:59; negative clock is not clamped. These are game-clock units, not measured host durations.

The initializer fills64 W+C0 words withFFFFFFFF, scans64 bits at3B84F8, appends selected indices, and stores total WB8/scroll WBC=0. It clears selection/count/string heads and obtains registration capacity W52C from814600. Four fixed actor slots4A5C30/stride10E0 are scanned. Active local slot (byte3 equals4BADED) fills W360/W320 through814420; other active slots fill paired peer strings W460/W3A0+40*j, slot IDs W521 and codes W530 via814640. The code assumes the local-slot invariant to fit at most three peers; no local fourth-peer rejection. After gathering it clears W360 and all three W460 string heads again, retaining W320/W3A0; the duplicate clears are actual stores. It selects audio3B for scene29, else3A, then sets state1, selected3, delay1E, idle0.

Interactive state1 decrements positive signed delay31E. Either input nonzero resets idle528. Exact half8==10 performs confirmation; combined input masks containing10 take another path. On a nonzero subpage or selected3, delay<=0 admits state3, counter318=14 and channel operation1AE3F0(0,0,A); only this confirmation path calls8146C0 once per selected peer. On primary page with a peer selected, an existing bit is removed and603290 recounts; adding rejects code1, nonpositive capacity, or signed count526>=capacity. Code2 is excluded from the counted capacity by603290. The accepted-add sound call at60102C inherits a0 rather than loading a numeric sound ID locally. No sound identity is invented for that call.

With both inputs zero, idle increments to4650 (18000 decimal calls), then requests exit without the peer-registration loop. After confirmation/idle changes state, the current invocation still executes the page branch and render. Exact half8==200 cycles page0->1->2->0, with reset selected3 on2->0. Page0 halfA bit2 has priority over bit1 and navigates peers plus selected3; page2 advances one row only when scroll+8<total, or retreats when positive. The dispatcher calls the original page's renderer even when the page byte changed during that branch. Unknown subpages emit no page renderer.

State2 immediately returns0 after initial input/font stores; this body does not advance it. State3 decrements word318 and transitions only on exact zero, sets counterA and invokes1AE1E0. State4 likewise waits for exact zero, invokes1CD080(2600,5), clears W and font state, returns1. The loader registers six keys2600..2605 but this exit passes release count5. That argument asymmetry is an observed static contract; live registry occupancy, other cleanup and a resource leak are unproven. Unexpected nonpositive countdowns are not normalized here. The outer caller is [scenario exit/result flow](SYMBOLS_SCENARIO_EXIT_MOVIE_RESULT_FLOW.md).

Both main layouts emit fixed background/label rows and up to three peer panels. Selected peer uses603200; selected3 uses603170; otherwise a static prompt. For ordinary selections0..3, exactly one selected icon/prompt advances shared animation W31C per main-page invocation. Each local rank character indexes the seven-byte FEDCBAS seed by3B8507 without a local bound. BB4!=0 resolves603110(BB4-1), with3E7 fallback; BB4==0 selects1C1E80(category). Completion uses37DEA0 low8; rank/time uses W1C0..C8; counts use4B9D19; points use3B84B4. Numeric strings shift x by minus10*strlen, capacity text by minus9*strlen. Peer names use W3A0/W460 and mapped fixed-slot identity;37D9F0 selects ALIVE/DEAD. Mask525 emits raw8159 marker; code0 empty,1 Done,2 Update, other empty. English strings establish visible text, not the original meaning of every status enum.

Primary layout emits five local statistic fields. Alternate layout emits six, adds1C1F00(byte4BAE8A+A), uses different label coordinates and point formatting (`%dpts.` instead of `%d pts.`). Both calculate remaining registration capacity as W52C minus sign8 W526 and select positive-count versus cannot-register text. Label suppliers1C1F40/1C1F00 are retained without inferring language from the runtime flag.

6026B0's14 labels use owned positions70DC60/pointer words70DCA0. Rows5/6 use alternate color and are skipped when bytes3B84F5/F4 respectively are nonzero. First seven labels use font18 decimal, remaining16. It obtains five bytes at743700 through37D7B0; that output location is outside the owned overlay file and was not read. Numeric values0..4 are those unsigned bytes,5 is CVT.W.S of667F90,6..11 are unsigned halves3B84E8..F2. All use `%3d`; first six append raw8193. Item-name loop count is unsigned byte4B9D19, positions advance4 from70DD10 and IDs are halves4BAC72+2*i through6DE290. No local table-size clamp is inferred.

602A30 emits the completion heading at70DF40 then up to eight event entries at successive XY pairs. It uses W1CC as decode page, W+C0 event IDs, and WBC scroll; only FFFFFFFF and the eight-entry loop bound stop reads locally. Up indicator requires scroll>0; down requires scroll+8<WB8. The controller's ordinary scrolling policy supports the bounded view, but these are separate contracts from arbitrary workspace corruption.

Owned o2 base570000 SHA256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. Complete bounded control tables:

| Span | Decoded values | SHA256 |
| --- | --- | --- |
|70DF90..70DFA3|Five scene words1,23,1C,2,29|61a9ef0abddabac4a58c79a2b0d41f0568457b9ee96c6e305491fac8d97d2732|
|70DFA8..70DFAE|Rank seed FEDCBAS|707612dd9c8f3b8acc67574cb27482b2ea4cfafbe1ce668146bb81ec6dd14158|
|70DFB0..70DFB6|Alternate rank seed FEDCBAS|707612dd9c8f3b8acc67574cb27482b2ea4cfafbe1ce668146bb81ec6dd14158|
|73F6B0..73F6C7|Six targets602140,6021CC,6021E4,602208,602260,602284|3f1d6c0238f91eaf17d34425bafea83a32ee0ae24c22aa138e517cee5c13e04e|
|73F6E0..73F70F|Twelve targets6028A4/B0/BC/C8/D4/E0/F8,602904/910/91C/928/934|0cbbbaae6c6aec6d1c84e0eeab5a0b2b29e6aceca39574dc043bc73c1a9d70d8|

Full original owned NUL-terminated formatting bytes (including NUL in SHA256):

| Address | Raw bytes / text | SHA256 |
| --- | --- | --- |
|73F5E8|`b'%s\x00'`|2f3a3f9b55f5df846abf81c7d13ff74998bdda8664df664173220675150020ff|
|73F5F0|`b'\x00'`|6e340b9cffb37a989ca544e6bb780a2c78901d3fb33738768511a30617afa01d|
|73F5F8|`b'%d\x81\x93\x00'`|50a34fc5af93004cef021796baf96ae401c6746b522041441d2f9786602e7cfc|
|73F600|`b'RANK %c  %02d:%02d:%02d\x00'`|29eb4c0e9be16ec385ff247584ac4ed6684684997d718a842ffad4945854b487|
|73F618|`b'%d\x00'`|0b782fc3030dbdf3756f17e7adf2ce5808dfc513ca7589adeb679c7d25eaef6f|
|73F620|`b'%d pts.\x00'`|98bd4389bdf6f0494d434297d090d2072dafb266578b67f0328de60325a83644|
|73F630|`b'You cannot register any more.\x00'`|253b00514d5b9a6a32ffbe4ca53db1c3252fcdcd902f8be5169878f82992ff83|
|73F650|`b'You can register %d players\x00'`|aa1b155d33dfc6783fbebf2c3186279392c0500fa2ea87aa4b7201b67a1fad9b|
|73F670|`b'ALIVE\x00'`|d2b154e04efb7972f9f8b425ed170382f2a74380485c88d456901088d4df344c|
|73F678|`b'DEAD\x00'`|50e2f96e2cb41a4eae7f0bee54d1531f615c1f5876c9c366fb5ecc5b1bf174ea|
|73F680|`b'\x81Y\x00'`|98dd0115ef9ac05a94e663c6eea4020e59520c1b10872090386b61646eb69d2c|
|73F688|`b'\x00'`|6e340b9cffb37a989ca544e6bb780a2c78901d3fb33738768511a30617afa01d|
|73F690|`b'Done\x00'`|8882688380a5a2bcee52823e0e456a3038c19e518272a9b4fb61b7a323f9127d|
|73F698|`b'Update\x00'`|6131266c2e687e28130984ba62e979120ce2c258ce10845f4f9fc25e812edba2|
|73F6A0|`b'%dpts.\x00'`|78e355aebfdbdab0ad3583bf6e907d8a2dac749e894f4da06be424d68fbf6527|
|73F6C8|`b'%3d\x00'`|fdff86fdfd2ee0a6929f1857e805d2e8a002e20dec2ec7620aea137409fa4048|
|73F6D0|`b'\x81\x93\x00'`|538d452d59ed971d92999a171d1a77cc4e25ba86648e25a6e73c05e7e4f02fa2|
|73F710|`b'COMPLETION RATIO     %3d\x81\x93\x00'`|4eb6df0f155e79510a3637b57186e8e314fac932794c23a0548a0acde94d5a8d|

No runtime slowdown, player-session admission, allocation lifetime, or timing cost was measured. Static counts do not establish a bottleneck.

Owned-word audit: six complete bodies, 2,067 original instruction words verified, 95 omitted zero/NOP words, zero conflicts and zero omitted nonzero words. All six IDs checked against live notebooks/current actual annotations; links and diff whitespace clean. Complete descriptor companion verifies26 bounded spans/251 rows and80 used atlas entries. No shared index mutation.
