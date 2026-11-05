# HTTP overlay provider, key-policy and vector adapters

Static owned o6 `nethttp.bin`, runtime ID 6/base `6E0000`, SHA-256 `68dbc8f16c5d0cc8a43205beb86ddac405a12c1d6b843b5961211bbe6ec30117`. Four complete original catalogue intervals reviewed, including optional key resolution, failed allocation and branch-likely stores. Values are hexadecimal. No target execution. [Pointer-array lifetime family](SYMBOLS_HTTP_POINTER_ARRAY_LIFETIMES.md) supplies the constructors and releases.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o6 0x728B58](../recomp/config/output_ovl/o6/o6_00728B58_0x728b58.cpp) | `get_ssl_auxiliary_provider_callback_table_at_739750` | Confirmed getter and lifetime/extra-data consumers | Returns739750. Session/parent constructors, destructors and cached-session lifetimes use the table for provider/extra-data callbacks. Getter performs no initialization or availability test. |
| [o6 0x728B68](../recomp/config/output_ovl/o6/o6_00728B68_0x728b68.cpp) | `query_key_effective_bits_unless_dsa_disabled_by_global_ssl_policy` | Confirmed full policy/type/query flow | Type74 requires global policy bit2 through71E818; disabled returns0. Every other type and enabled74 delegates70B130 generic RSA/DSA key bit query unchanged. No key null guard or enable check for other types. |
| [o6 0x728EE0](../recomp/config/output_ovl/o6/o6_00728EE0_0x728ee0.cpp) | `set_pointer_array_comparator_and_invalidate_sorted_flag_only_when_changed` | Confirmed full setter and clone consumer | If vector comparator10 differs from a1, clears sorted flag8; always writes comparator10=a1. No sort or ownership operation. |
| [o6 0x728EF8](../recomp/config/output_ovl/o6/o6_00728EF8_0x728ef8.cpp) | `shallow_clone_pointer_array_capacity_count_flags_and_comparator` | Confirmed complete allocation/copy; failure cleanup partial | Allocates vector through728F90(source comparator10); failure returns null. Reallocates clone backing store to source capacityC*4 with70FF80; failure returns null without releasing newly allocated vector/store in this body. Success copies source count0*4 pointer bytes, count0, sorted flag8, capacityC, comparator10. Elements remain shared; no deep-copy callbacks or count<=capacity admission. |

The cipher-rule compiler clones its ordered vector through728EF8, then changes comparator through728EE0 to create a separately sorted/searchable ID view. These adapters do not establish element lifetime or thread safety.

Audit: 64 verified instruction words, zero conflicts, 1 omitted zero word (NOP padding), zero omitted nonzero words.
