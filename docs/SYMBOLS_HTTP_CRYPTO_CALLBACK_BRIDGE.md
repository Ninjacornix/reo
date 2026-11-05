# HTTP overlay crypto callback bridge and complete default registrations

Static owned File #1 o6 `nethttp.bin`, runtime ID6/base6E0000, SHA-256 `68dbc8f16c5d0cc8a43205beb86ddac405a12c1d6b843b5961211bbe6ec30117`. All57 original catalogue bodies below and complete59-entry selector table reviewed, including branch-likely and tail-call paths. No target execution, crypto tests, files/connections opened or build. All numbers in evidence/table hexadecimal; decimal selector numbers appear only in proposed identifiers. These are complete bridge contracts; target internals and original API names are separate questions. [Descriptor adapters](SYMBOLS_HTTP_X509_DESCRIPTOR_AND_VERIFY_ADAPTERS.md).

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o6 0x6FC5F8](../recomp/config/output_ovl/o6/o6_006FC5F8_0x6fc5f8.cpp) | `initialize_crypto_bridge_flags_and_default_callback_bindings` | Confirmed complete registration sequence | Resets742230 block, sets both option flags1, registers defaults listed below; ignores all setter returns and returns1. Last selector38 is rejected by6FC9E8, so its attempted72C538 registration has no effect. Selector1C valid but not installed. |
| [o6 0x6FC9A0](../recomp/config/output_ovl/o6/o6_006FC9A0_0x6fc9a0.cpp) | `clear_crypto_bridge_flags_and_callback_storage` | Confirmed full tail-call | memset742230,0,E8; clears two flags plus callback storage. No registration/destruction callbacks. |
| [o6 0x6FC9B8](../recomp/config/output_ovl/o6/o6_006FC9B8_0x6fc9b8.cpp) | `set_crypto_bridge_boolean_option_by_index` | Confirmed full branch tree | Index0 writes742230;index1 writes742234, returns1. Other indices return0. Value stored unchanged, not normalized to boolean. |
| [o6 0x6FC9E8](../recomp/config/output_ovl/o6/o6_006FC9E8_0x6fc9e8.cpp) | `set_crypto_bridge_callback_by_validated_selector` | Confirmed entire59-entry table and store targets | Unsigned(selector-1)<3B range; selectors14/38/39/3A reject0, all others store pointer unchanged into table-selected global and return1. Null callback allowed; no invocation/ownership/refcount or supported-signature check. Complete binding table below. |
| [o6 0x6FCCB8](../recomp/config/output_ovl/o6/o6_006FCCB8_0x6fccb8.cpp) | `get_crypto_bridge_option_by_index_or_minus_one` | Confirmed full branch tree | Returns flag742230 for0,742234 for1; other indices-1. |
| [o6 0x6FCCF8](../recomp/config/output_ovl/o6/o6_006FCCF8_0x6fccf8.cpp) | `invoke_crypto_bridge_selector_1_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector1,global740238: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function84/reasonE). |
| [o6 0x6FCD40](../recomp/config/output_ovl/o6/o6_006FCD40_0x6fcd40.cpp) | `invoke_crypto_bridge_selector_2_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector2,global74023C: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback tail-calls error logger; no explicit scalar default (lib1A/function70/reasonE). |
| [o6 0x6FCD88](../recomp/config/output_ovl/o6/o6_006FCD88_0x6fcd88.cpp) | `invoke_crypto_bridge_selector_3_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector3,global740240: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function96/reasonE). |
| [o6 0x6FCDD0](../recomp/config/output_ovl/o6/o6_006FCDD0_0x6fcdd0.cpp) | `invoke_crypto_bridge_selector_4_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector4,global740244: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function6E/reasonE). |
| [o6 0x6FCE18](../recomp/config/output_ovl/o6/o6_006FCE18_0x6fce18.cpp) | `invoke_crypto_bridge_selector_5_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector5,global740248: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function6A/reasonE). |
| [o6 0x6FCE60](../recomp/config/output_ovl/o6/o6_006FCE60_0x6fce60.cpp) | `invoke_crypto_bridge_selector_6_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector6,global74024C: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function69/reasonE). |
| [o6 0x6FCEA8](../recomp/config/output_ovl/o6/o6_006FCEA8_0x6fcea8.cpp) | `invoke_crypto_bridge_selector_7_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector7,global740250: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback tail-calls error logger; no explicit scalar default (lib1A/function88/reasonE). |
| [o6 0x6FCEF0](../recomp/config/output_ovl/o6/o6_006FCEF0_0x6fcef0.cpp) | `invoke_crypto_bridge_selector_8_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector8,global740254: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function77/reasonE). |
| [o6 0x6FCF38](../recomp/config/output_ovl/o6/o6_006FCF38_0x6fcf38.cpp) | `invoke_crypto_bridge_selector_9_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector9,global740258: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function95/reasonE). |
| [o6 0x6FCF80](../recomp/config/output_ovl/o6/o6_006FCF80_0x6fcf80.cpp) | `invoke_crypto_bridge_selector_10_or_report_missing_callback` | Confirmed complete slot/argument/error flow | SelectorA,global74025C: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function72/reasonE). |
| [o6 0x6FCFC8](../recomp/config/output_ovl/o6/o6_006FCFC8_0x6fcfc8.cpp) | `invoke_crypto_bridge_selector_11_or_report_missing_callback` | Confirmed complete slot/argument/error flow | SelectorB,global740260: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function78/reasonE). |
| [o6 0x6FD010](../recomp/config/output_ovl/o6/o6_006FD010_0x6fd010.cpp) | `invoke_crypto_bridge_selector_12_or_report_missing_callback` | Confirmed complete slot/argument/error flow | SelectorC,global740264: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function75/reasonE). |
| [o6 0x6FD058](../recomp/config/output_ovl/o6/o6_006FD058_0x6fd058.cpp) | `invoke_crypto_bridge_descriptor_slot_13_and_unpack_on_nonzero` | Confirmed full dispatch/result/output contract | SlotD callback receives(originala0,stackDescriptor), result propagated. On ANY nonzero (including negative), writes descriptor type0 to originala1, pointer10 to originala2,64-bit length8 to originala3. Outputs mandatory locally; missing callback logs1A/76/E and returns0. |
| [o6 0x6FD0E8](../recomp/config/output_ovl/o6/o6_006FD0E8_0x6fd0e8.cpp) | `invoke_crypto_bridge_descriptor_slot_14_and_unpack_on_exact_one` | Confirmed full dispatch/result/output contract | SlotE receives(a0,stackDescriptor), result propagated. Only EXACT1 writes type0/pointer10/length8 to originala1/a2/a3. Missing logs1A/73/E returns0. No output-null guards. |
| [o6 0x6FD180](../recomp/config/output_ovl/o6/o6_006FD180_0x6fd180.cpp) | `invoke_crypto_bridge_descriptor_slot_15_and_unpack_on_exact_one` | Confirmed full dispatch/result/output contract | SlotF same packing/exact1 gate as slotE; missing logs1A/74/E,returns0. No output-null guards. |
| [o6 0x6FD218](../recomp/config/output_ovl/o6/o6_006FD218_0x6fd218.cpp) | `invoke_crypto_bridge_selector_16_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector10,global740274: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function82/reasonE). |
| [o6 0x6FD260](../recomp/config/output_ovl/o6/o6_006FD260_0x6fd260.cpp) | `invoke_crypto_bridge_selector_17_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector11,global740278: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback tail-calls error logger; no explicit scalar default (lib1A/function7C/reasonE). |
| [o6 0x6FD2A8](../recomp/config/output_ovl/o6/o6_006FD2A8_0x6fd2a8.cpp) | `invoke_crypto_bridge_selector_18_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector12,global74027C: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function7A/reasonE). |
| [o6 0x6FD2F0](../recomp/config/output_ovl/o6/o6_006FD2F0_0x6fd2f0.cpp) | `invoke_crypto_bridge_selector_19_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector13,global740280: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function81/reasonE). |
| [o6 0x6FD338](../recomp/config/output_ovl/o6/o6_006FD338_0x6fd338.cpp) | `invoke_crypto_bridge_selector_21_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector15,global740284: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function79/reasonE). |
| [o6 0x6FD380](../recomp/config/output_ovl/o6/o6_006FD380_0x6fd380.cpp) | `invoke_crypto_bridge_selector_22_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector16,global740288: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function7D/reasonE). |
| [o6 0x6FD3C8](../recomp/config/output_ovl/o6/o6_006FD3C8_0x6fd3c8.cpp) | `invoke_crypto_bridge_selector_31_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector1F,global74028C: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function83/reasonE). |
| [o6 0x6FD410](../recomp/config/output_ovl/o6/o6_006FD410_0x6fd410.cpp) | `invoke_crypto_bridge_name_cache_slot_23_and_unpack_on_exact_one` | Confirmed full dispatch/result/output contract | Slot17 receives(a0,stackDescriptor). Only exact1 writes descriptor pointer10 to originala1 and64-bit length8 tooriginala2. Missing logs1A/80/E and0. No output-null guards. |
| [o6 0x6FD498](../recomp/config/output_ovl/o6/o6_006FD498_0x6fd498.cpp) | `invoke_crypto_bridge_selector_24_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector18,global740294: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function7F/reasonE). |
| [o6 0x6FD4E0](../recomp/config/output_ovl/o6/o6_006FD4E0_0x6fd4e0.cpp) | `invoke_crypto_bridge_selector_25_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector19,global740298: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function7E/reasonE). |
| [o6 0x6FD528](../recomp/config/output_ovl/o6/o6_006FD528_0x6fd528.cpp) | `invoke_crypto_bridge_signature_slot_26_and_optionally_unpack_two_descriptors` | Confirmed full dispatch/result/output contract | Slot1A receives(a0,&stack0,&stack20); result propagated. Only exact1 optionally exports six outputs from descriptor0/20 type0,pointer10,length8 into originala1/a2/a3 andt0/t1/t2. Null outputs skipped. Missing logs1A/7B/E and0. |
| [o6 0x6FD618](../recomp/config/output_ovl/o6/o6_006FD618_0x6fd618.cpp) | `invoke_crypto_bridge_signature_descriptor_first_half` | Confirmed full dispatch/result/output contract | Calls6FD528 preserving first four args but zeroes t0/t1/t2; returns result. Selects first descriptor output group. |
| [o6 0x6FD640](../recomp/config/output_ovl/o6/o6_006FD640_0x6fd640.cpp) | `invoke_crypto_bridge_signature_descriptor_second_half` | Confirmed full dispatch/result/output contract | Moves originala1/a2/a3 to t0/t1/t2,zeroes a1/a2/a3, calls6FD528. Selects second descriptor output group. |
| [o6 0x6FD670](../recomp/config/output_ovl/o6/o6_006FD670_0x6fd670.cpp) | `invoke_crypto_bridge_selector_35_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector23,global7402A4: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function94/reasonE). |
| [o6 0x6FD6B8](../recomp/config/output_ovl/o6/o6_006FD6B8_0x6fd6b8.cpp) | `invoke_crypto_bridge_selector_36_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector24,global7402A8: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback tail-calls error logger; no explicit scalar default (lib1A/function92/reasonE). |
| [o6 0x6FD700](../recomp/config/output_ovl/o6/o6_006FD700_0x6fd700.cpp) | `invoke_crypto_bridge_selector_37_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector25,global7402AC: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function67/reasonE). |
| [o6 0x6FD748](../recomp/config/output_ovl/o6/o6_006FD748_0x6fd748.cpp) | `invoke_crypto_bridge_selector_38_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector26,global7402B0: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function68/reasonE). |
| [o6 0x6FD790](../recomp/config/output_ovl/o6/o6_006FD790_0x6fd790.cpp) | `invoke_crypto_bridge_selector_39_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector27,global7402B4: nonnull callback invoked with unchanged argument registers, result returned. Missing callback returns0 WITHOUT error log. |
| [o6 0x6FD7C0](../recomp/config/output_ovl/o6/o6_006FD7C0_0x6fd7c0.cpp) | `invoke_crypto_bridge_selector_27_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector1B,global7402A0: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function93/reasonE). |
| [o6 0x6FD808](../recomp/config/output_ovl/o6/o6_006FD808_0x6fd808.cpp) | `invoke_crypto_bridge_selector_40_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector28,global7402B8: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function99/reasonE). |
| [o6 0x6FD850](../recomp/config/output_ovl/o6/o6_006FD850_0x6fd850.cpp) | `invoke_crypto_bridge_selector_41_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector29,global7402BC: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback tail-calls error logger; no explicit scalar default (lib1A/function8F/reasonE). |
| [o6 0x6FD898](../recomp/config/output_ovl/o6/o6_006FD898_0x6fd898.cpp) | `invoke_crypto_bridge_selector_42_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector2A,global7402C0: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback tail-calls error logger; no explicit scalar default (lib1A/function98/reasonE). |
| [o6 0x6FD8E0](../recomp/config/output_ovl/o6/o6_006FD8E0_0x6fd8e0.cpp) | `invoke_crypto_bridge_selector_43_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector2B,global7402C4: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback tail-calls error logger; no explicit scalar default (lib1A/function89/reasonE). |
| [o6 0x6FD928](../recomp/config/output_ovl/o6/o6_006FD928_0x6fd928.cpp) | `invoke_crypto_bridge_selector_44_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector2C,global7402C8: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns-1 (lib1A/function66/reasonE). |
| [o6 0x6FD970](../recomp/config/output_ovl/o6/o6_006FD970_0x6fd970.cpp) | `invoke_crypto_bridge_selector_45_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector2D,global7402CC: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function8A/reasonE). |
| [o6 0x6FD9B8](../recomp/config/output_ovl/o6/o6_006FD9B8_0x6fd9b8.cpp) | `invoke_crypto_bridge_selector_46_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector2E,global7402D0: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function91/reasonE). |
| [o6 0x6FDA00](../recomp/config/output_ovl/o6/o6_006FDA00_0x6fda00.cpp) | `invoke_crypto_bridge_selector_47_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector2F,global7402D4: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function8E/reasonE). |
| [o6 0x6FDA48](../recomp/config/output_ovl/o6/o6_006FDA48_0x6fda48.cpp) | `invoke_crypto_bridge_selector_48_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector30,global7402D8: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function8C/reasonE). |
| [o6 0x6FDA90](../recomp/config/output_ovl/o6/o6_006FDA90_0x6fda90.cpp) | `invoke_crypto_bridge_selector_49_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector31,global7402DC: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback tail-calls error logger; no explicit scalar default (lib1A/function90/reasonE). |
| [o6 0x6FDAD8](../recomp/config/output_ovl/o6/o6_006FDAD8_0x6fdad8.cpp) | `invoke_crypto_bridge_selector_50_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector32,global7402E0: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function8D/reasonE). |
| [o6 0x6FDB20](../recomp/config/output_ovl/o6/o6_006FDB20_0x6fdb20.cpp) | `invoke_crypto_bridge_selector_59_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector3B,global7402E4: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function8B/reasonE). |
| [o6 0x6FDB68](../recomp/config/output_ovl/o6/o6_006FDB68_0x6fdb68.cpp) | `invoke_crypto_bridge_selector_29_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector1D,global7402EC: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function6F/reasonE). |
| [o6 0x6FDBB0](../recomp/config/output_ovl/o6/o6_006FDBB0_0x6fdbb0.cpp) | `invoke_crypto_bridge_selector_30_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector1E,global7402F0: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function64/reasonE). |
| [o6 0x6FDBF8](../recomp/config/output_ovl/o6/o6_006FDBF8_0x6fdbf8.cpp) | `invoke_crypto_bridge_selector_32_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector20,global7402F4: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function6D/reasonE). |
| [o6 0x6FDC40](../recomp/config/output_ovl/o6/o6_006FDC40_0x6fdc40.cpp) | `invoke_crypto_bridge_selector_33_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector21,global7402F8: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function85/reasonE). |
| [o6 0x6FDC88](../recomp/config/output_ovl/o6/o6_006FDC88_0x6fdc88.cpp) | `invoke_crypto_bridge_selector_34_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector22,global7402FC: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function71/reasonE). |
| [o6 0x6FDCD0](../recomp/config/output_ovl/o6/o6_006FDCD0_0x6fdcd0.cpp) | `invoke_crypto_bridge_selector_52_or_report_missing_callback` | Confirmed complete slot/argument/error flow | Selector34,global740300: nonnull callback invoked with unchanged argument registers and result propagated. Missing callback logs then returns0 (lib1A/function87/reasonE). |

Complete owned selector table73BAF0,59words, SHA-256 `ae5e39353a2b337250f51da6e12b391c3aaa7e6657c5a7d8f429c3d3100be271`. Every store target reviewed. Registration defaults represent what initializer attempts, not observed initialized runtime state.

| Selector | Global slot | Default callback attempted by6FC5F8 |
| --- | --- | --- |
|1|740238|7326E8|
|2|74023C|7327A0|
|3|740240|72D2E0|
|4|740244|72D408|
|5|740248|7323E8|
|6|74024C|7324C8|
|7|740250|732780|
|8|740254|72C578|
|9|740258|72C078|
|A|74025C|72C0A0|
|B|740260|72C0B0|
|C|740264|72C360|
|D|740268|6FC230|
|E|74026C|6FC3A0|
|F|740270|6FC408|
|10|740274|6F0DF0|
|11|740278|6F0E88|
|12|74027C|72D3A8|
|13|740280|72C210|
|14|REJECTED|none|
|15|740284|72C0D0|
|16|740288|6F0B38|
|17|740290|6FC470|
|18|740294|72ECE8|
|19|740298|72EE00|
|1A|74029C|6FC4F0|
|1B|7402A0|72CB80|
|1C|7402E8|none|
|1D|7402EC|6FC298|
|1E|7402F0|6FC2C8|
|1F|74028C|6F08F0|
|20|7402F4|72D150|
|21|7402F8|70BA40|
|22|7402FC|72D348|
|23|7402A4|72C8D0|
|24|7402A8|72C9B8|
|25|7402AC|72D5D8|
|26|7402B0|72D548|
|27|7402B4|6FC558|
|28|7402B8|72CFB8|
|29|7402BC|72D008|
|2A|7402C0|72D088|
|2B|7402C4|72D0C0|
|2C|7402C8|72CEE0|
|2D|7402CC|72CF30|
|2E|7402D0|72CF78|
|2F|7402D4|72CFB0|
|30|7402D8|72CF20|
|31|7402DC|72CF38|
|32|7402E0|72CF40|
|33|740308|6FF5E0|
|34|740300|728D40|
|35|740304|728DA8|
|36|74030C|6FC568|
|37|740310|728D60|
|38|REJECTED|72C538|
|39|REJECTED|none|
|3A|REJECTED|none|
|3B|7402E4|72CF48|

Reset covers742230..742317. Function-pointer stores do not prove callback availability at any observed session; wrappers preserve original arguments except the explicit descriptor adapters. Missing-callback void/tail-call wrappers intentionally have no invented return0 contract. Descriptor stack output is not precleared locally, so callbacks own its initialization.

Audit:1426 verified instruction words, zero conflicts,49 omitted zero words (NOP padding), zero omitted nonzero words.
