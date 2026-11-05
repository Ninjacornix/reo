# HTTP overlay X509 extension search adapters

Static owned o6 `nethttp.bin`, runtime ID 6/base `6E0000`, SHA-256 `68dbc8f16c5d0cc8a43205beb86ddac405a12c1d6b843b5961211bbe6ec30117`. Four complete catalogue bodies reviewed, including post-index normalization and loop-entry tests. Values are hexadecimal. No target execution or malformed-input tests.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o6 0x72DC80](../recomp/config/output_ovl/o6/o6_0072DC80_0x72dc80.cpp) | `count_optional_x509_extension_pointer_array_or_return_zero` | Confirmed full nullable count and certificate caller | Null list0, otherwise returns list0 signed word. Certificate72C398 passes info24. No capacity/negative normalization. |
| [o6 0x72DC98](../recomp/config/output_ovl/o6/o6_0072DC98_0x72dc98.cpp) | `find_next_x509_extension_by_numeric_object_identifier` | Confirmed full resolver/search composition | Resolves numeric identifier a1 through709018. Missing object returns-2; otherwise delegates72DCE8(list,object,previousIndex) and propagates result. |
| [o6 0x72DCE8](../recomp/config/output_ovl/o6/o6_0072DCE8_0x72dce8.cpp) | `find_next_x509_extension_with_equal_object_identifier_after_index` | Confirmed complete normalization/compare loop | Null list returns-1. Starts signed index=previous+1, resets to0 if this result<=-1. Tests index<count before reading, compares each extension0 OID with target using709A00, returns first equal index or-1. Previous-index addition uses32-bit arithmetic; no capacity/type admission. |
| [o6 0x72DD90](../recomp/config/output_ovl/o6/o6_0072DD90_0x72dd90.cpp) | `find_next_x509_extension_matching_critical_boolean_after_index` | Confirmed complete normalization/halfword predicate | Null list returns-1; starts previous+1 normalized as72DCE8. Extension signed halfword4 nonzero matches any nonzero requested critical flag; zero matches requested zero. Returns first index or-1. No OID filtering, parsing or trust decision. |

Audit: 95 verified instruction words, zero conflicts, 3 omitted zero words (NOP padding), zero omitted nonzero words.
