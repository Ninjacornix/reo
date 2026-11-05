# HTTP overlay remaining key-capability and implementation-description adapters

Static owned o6 `nethttp.bin`, runtime ID 6/base `6E0000`, SHA-256 `68dbc8f16c5d0cc8a43205beb86ddac405a12c1d6b843b5961211bbe6ec30117`. Both complete original catalogue intervals and full description literal reviewed. Values are hexadecimal. No target execution or crypto tests.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o6 0x715478](../recomp/config/output_ovl/o6/o6_00715478_0x715478.cpp) | `get_rc4_implementation_description_literal_rc4_i_f` | Confirmed complete getter/literal; external API reachability unknown | Returns73D598 NUL-terminated `rc4(i f)`. No cipher processing, initialization or CPU-feature probe. No indexed direct caller or owned aligned pointer reference found. |
| [o6 0x728E78](../recomp/config/output_ovl/o6/o6_00728E78_0x728e78.cpp) | `compose_certificate_key_capabilities_using_optional_supplied_or_bridge_key` | Confirmed complete null/bridge/query/delegate sequence | Null certificate returns0. Uses supplied a1 key or resolves6FD010(certificate); null key0. Gets certificate query/type6FCEF0 and calls728DB0(query,key), propagates literal capability bits. Does not free resolved key or perform certificate verification locally. |

Description bytes73D598..73D5A1 including NUL, SHA-256 `a38f02e79ad1aa8950d158ee0e62621bda05b544d833a7c44ff0d85d6eb89fe5`. [Capability composer](SYMBOLS_HTTP_SSL_KEY_CLASSIFICATION_AND_ALERTS.md) defines the returned bit construction; bridge callback selection and ownership remain independent.

Audit: 2 rows, 28 verified owned instruction words; 1 omitted interval word is zero/NOP; 0 omitted nonzero words.
