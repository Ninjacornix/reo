# HTTP overlay SSL3 method controls and temporary key slots

Static owned o6 `nethttp.bin`, runtime ID6/base `6E0000`, SHA-256 `68dbc8f16c5d0cc8a43205beb86ddac405a12c1d6b843b5961211bbe6ec30117`. Four complete catalogue intervals plus all twelve/sixteen jump-table words reviewed, including size thresholds, clone failures, existing-slot release and ignored list-push results. No target execution or cryptographic/network tests. Numbers are hexadecimal. [Credential capability masks](SYMBOLS_HTTP_SSL_CIPHER_CAPABILITIES_AND_CERTIFICATE_TYPES.md) consume temporary slots; [generic controls](SYMBOLS_HTTP_SSL_CONNECTION_CONTROL_AND_CIPHER_INPUT.md) dispatch to these method-specific entries.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o6 0x71B9E0](../recomp/config/output_ovl/o6/o6_0071B9E0_0x71b9e0.cpp) | `control_ssl3_connection_renegotiation_counters_flags_and_certificate_array` | Confirmed complete12-entry table | Command8 gets workspace11C,9 gets/clears11C,A gets118,B returns signed low32 workspace u64flags0.11 ensures connection88 pointer array, appends pointer arg3; positive push retains certificate6FCEA8 and returns1, failed push0.12 destroys array88 with certificate-release callback and clears88, returns1 even absent. Other commands0. No generic connection/certificate null validation; array allocation/publication precedes append. |
| [o6 0x71BAF0](../recomp/config/output_ovl/o6/o6_0071BAF0_0x71baf0.cpp) | `clone_and_prepare_dh_parameters_then_replace_temporary_wrapper_slot` | Confirmed complete clone/prepare/replace flow | Args(slotCell,sourceDH). Duplicates702C68, then requires702B48(duplicate) nonzero. Failure errors14/D6/805 and0; a nonnull duplicate that fails prepare is not locally released. Success releases old *slotCell7028D8 ifnonnull, stores duplicate, returns1. Preparation's own bind-result limitations remain delegated; not proof of a new key pair or usable cryptographic operation. |
| [o6 0x71BB78](../recomp/config/output_ovl/o6/o6_0071BB78_0x71bb78.cpp) | `clone_rsa_payload_then_release_and_replace_temporary_slot` | Confirmed complete clone/failure/replacement | Args(slotCell,sourceRSA). Clones7164D0; null errors14/D7/804 and0. Success releases old *slotCell715C50 then stores clone, returns1. Underlying attribute-copy failure ownership remains separate; no slot/caller alias validation. |
| [o6 0x71BBF0](../recomp/config/output_ovl/o6/o6_0071BBF0_0x71bbf0.cpp) | `control_ssl3_parent_temporary_rsa_dh_callback_slots_and_owned_certificate_array` | Confirmed complete16-entry table and thresholds | Uses parentA0 credentials, supplied object/callback in arg3; ignores arg2. All commands below read in full. Unknown command0. Temporary key/callback setters do not clear credential mask-valid word8 here; downstream revalidation policy remains outside this interval. Pointer-array commandC returns1 after push regardless of child push result, and adds no retain. |

| Parent command | Exact behavior |
| --- | --- |
| 1,D | If RSA slot24 exists,0; else no pair0 key44 ->1; else0 when signed signatureCapacity<41,1otherwise. |
| E | Same query using RSA slot28 and threshold81. |
| 2,F | Require suppliedRSA. If `(RSA byteCapacity<<3)<201`, clone into24 and also20 if20 absent; otherwise clone into20. Checked clone failure0, otherwise1. |
| 10 | Require suppliedRSA, clone into28, return boolean clone status. |
| 3 | Require suppliedDH. If `(DH byteCapacity<<3)<201`, clone/prepare into30 and also2C if2C absent; otherwise into2C. Checked failure0, otherwise1. |
| 4 | Store supplied callback pointer at credentials38, return1, no retain/free. |
| 5 | Store supplied callback pointer at credentials3C, return1, no retain/free. |
| C | Ensure parent110 pointer array, append supplied pointer, return1 regardless of append result; allocation failure0. Parent destructor releases payloads through certificate bridge6FCD40. |
| 6..B and outside1..10 | Return0. |

Owned connection table `73DC70..73DCA0`,12 words,SHA-256 `9bfb150e2c281ba48c08aeeb4399c3df3ad774a5d66cbb153ec70fd2710a0758`; parent table `73DCA0..73DCE0`,16 words,SHA-256 `31e8a8259c38fd64c17e6b4fc4233e9d3a250b8758d17a8daf23ef1ba69acc73`. Every destination reviewed inside its original body. Numeric thresholds and partially validated capacities are literal rules, not assurances of key strength or runtime availability.

Audit: 257 verified instruction words, zero conflicts, 8 omitted zero words (NOP padding), zero omitted nonzero words.
