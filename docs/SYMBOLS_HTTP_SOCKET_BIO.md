# HTTP overlay socket BIO and retry gate

Static owned File #1 o6 `nethttp.bin`, runtime ID6/base6E0000, SHA-256 `68dbc8f16c5d0cc8a43205beb86ddac405a12c1d6b843b5961211bbe6ec30117`. Complete original catalogue intervals and branch/delay-slot flow reviewed. No target execution, files opened through target code, connections, build or runtime changes. Numbers hexadecimal except ordinary prose; labels proposed static roles. Companion [BIO dispatch](SYMBOLS_HTTP_BIO_DISPATCH_AND_CHAINS.md).

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o6 0x6FB010](../recomp/config/output_ovl/o6/o6_006FB010_0x6fb010.cpp) | `get_socket_bio_method_table` | Confirmed full getter/table binding | Returns735228, type505 and owned name socket; table binds callbacks listed below. |
| [o6 0x6FB020](../recomp/config/output_ovl/o6/o6_006FB020_0x6fb020.cpp) | `create_socket_bio_and_bind_descriptor_with_close_policy` | Confirmed complete wrapper | Allocates via6FB010/6F3888; calls6F3E50(BIO,68,original policy,original descriptor), which passes descriptor through a stack word pointer. Ignores control result and returns BIO; allocation failure0. |
| [o6 0x6FB088](../recomp/config/output_ovl/o6/o6_006FB088_0x6fb088.cpp) | `initialize_socket_bio_flags_descriptor_and_state` | Confirmed complete constructor | Clears flags14/initializedC/descriptor1C/opaque20 and returns1. No socket acquisition occurs. |
| [o6 0x6FB108](../recomp/config/output_ovl/o6/o6_006FB108_0x6fb108.cpp) | `read_socket_bio_and_classify_nonpositive_result_for_retry` | Confirmed full call/result/flags | Null output returns0. Clears current errno through resident1D96E0, invokes1D9DA0(descriptor1C,output,count,0), clears retry flags. Nonpositive result invokes726720, setting read9 if classified. Returns signed LOW32 actual result. No local initialized/count gate. |
| [o6 0x6FB1A8](../recomp/config/output_ovl/o6/o6_006FB1A8_0x6fb1a8.cpp) | `write_socket_bio_and_classify_nonpositive_result_for_retry` | Confirmed complete callback | Clears resident errno, calls1DA080(descriptor1C,source,count,0), clears retry flags; nonpositive result726720 may set writeA. Returns signed LOW32 result. No local null-source or complete-send loop. |
| [o6 0x6FB230](../recomp/config/output_ovl/o6/o6_006FB230_0x6fb230.cpp) | `control_socket_bio_descriptor_close_policy_and_unsupported_mode_request` | Confirmed full branch tree | 1/B/C/80 return1 without I/O;8/9 get/set closePolicy10 lowbit.68 calls6FB0A0 on prior state, reads descriptor through pointer, publishes1C/initC=1/policy.69 returns-1 if uninitialized, else descriptor and optional output.66 delegates724020, which only logs unsupported request and returns0. D and all other commands0, including85: branch6FB2F0 goes unconditionally to zero-result6FB374 despite85 in delay slot. No successful nonblocking-mode claim. |
| [o6 0x6FB398](../recomp/config/output_ovl/o6/o6_006FB398_0x6fb398.cpp) | `write_nul_terminated_string_to_socket_bio` | Confirmed complete wrapper | strlen followed by6FB1A8; no local null guard or newline append. |
| [o6 0x726720](../recomp/config/output_ovl/o6/o6_00726720_0x726720.cpp) | `classify_socket_retry_only_for_minus_one_or_zero_result_and_current_errno` | Confirmed full gate/lookup | Unsigned(result+1)<2 admits exactly-1 or0; then gets resident current errno1D96E0 and delegates726760. Other results return0. Exact numeric classifier admits4/B/47/77/78; portable errno equivalence not assumed. |
| [o6 0x724020](../recomp/config/output_ovl/o6/o6_00724020_0x724020.cpp) | `log_unsupported_socket_mode_control_and_return_zero` | Confirmed complete error-only stub | Ignores incoming descriptor/mode, calls704230 with constants10/6D/E/0/0 and returns0. No socket mode change or syscall occurs in this body. |

Owned735228 ten words, name73BA58 `socket`:

```
00000505 0073BA58 006FB1A8 006FB108 006FB398
00000000 006FB230 006FB088 006FB0A0 00000000
```

Destructor6FB0A0 and numeric retry classifier726760 already have [exact shared-body aliases](SYMBOLS_SHARED_BODIES.md), so are not duplicated. Destructor calls resident1DA200(fd,2) TWICE when initialized and close policy enabled, then clears flags/init. These calls are preserved rather than silently replaced with an assumed close operation. [FD adapter](SYMBOLS_HTTP_FILE_BIO_CONTROLS.md) uses a distinct errno provider and same numeric retry set. No runtime connection state or network failure observed.

Audit: 240 verified instruction words, zero conflicts, 2 omitted zero words (NOP padding), zero omitted nonzero words.
