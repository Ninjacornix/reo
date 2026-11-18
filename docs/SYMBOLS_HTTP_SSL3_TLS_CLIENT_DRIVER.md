# HTTP overlay SSL3/TLS client handshake driver

Static owned o6 `nethttp.bin`, runtime ID6/base `6E0000`, SHA-256 `68dbc8f16c5d0cc8a43205beb86ddac405a12c1d6b843b5961211bbe6ec30117`. Entire original 7F4-byte catalogue interval reviewed, including every state admission, resumed-session split, early-completion option, buffer flush retry, callback and common depth exit. No target execution, network traffic, timing or crypto tests. Numeric values are hexadecimal. Workers have independently bounded roles where linked; unmapped worker semantics remain identified by entry rather than inferred from call placement alone.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o6 0x7201D0](../recomp/config/output_ovl/o6/o6_007201D0_0x7201d0.cpp) | `drive_ssl3_tls_client_handshake_states_with_resumption_flush_and_early_completion_modes` | Confirmed complete local dispatch, flags and callback flow | Seeds byte provider,clears errors/errno,selects info callbackC0/parent7C,increments depth1C. State3004 marks renegotiation28=1,parent50++,then initializes like1000/1003/4000/5000:role24=0,notify10/1,pending wrapper800 if absent,record buffers71A550,auxiliaryBIO71E5A8(connection,0),two transcript digests71B5A0,parent4C++,state1110. Dispatch and success transitions below. Common state-change path conditionally flushes writeBIO when E0nonzero unless reusable-message168 or one-iteration skip flag; retry stores continuation workspace164 and old state34,uses1100. Unsupported state logs14/84/FF,-1. Every terminal route reaches common depth decrement; optional terminal info1002/result,except completed state3 with absent info callback skips directly to decrement. No local iteration/time budget. |

| Driver state(s) | Called worker and successful transition |
| --- | --- |
| 1110/1111 |7209C8 ClientHello ->1120,attaches auxiliary buffer BIO above write chain if needed. |
| 1120/1121 |720C30 ServerHello ->11D0 if resumed5C,else1130. |
| 1130/1131 |720F20 peer certificates unless selected cipher flags100 set; either successful path ->1140. |
| 1140/1141 |721320 worker ->1150,then722778 setup must succeed. |
| 1150/1151 |721AF8 worker ->1160. |
| 1160/1161 |721EB0 worker ->1170 when workspace16Cnonzero,else1180. |
| 1170..1172 |722570 worker ->1180. |
| 1180/1181 |721F38 worker ->1190 when workspace16C==1;otherwise11A0 and clears workspace100. |
| 1190/1191 |722390 worker ->11A0,clears workspace100. |
| 11A0/11A1 |719D50 ChangeCipherSpec; commits selected15C to cachedAC,invokes auxiliary+8 key-block setup,then+10(connection,12) cipher-state installation; ->11B0. |
| 11B0/11B1 |719B78 Finished with auxiliary inline client label20/length34; continuation depends on resumption/options below. |
| 11D0/11D1 |719C48 peer Finished ->11A0 if resumed,else3. |
| 1100 |Queries writeBIOcontrol3;positive pending triggers flushB with I/O18=2. Nonpositive flush yields-1; success18=1. Restores continuation workspace164. |
| 3 |Completion branch described below. |

After sending Finished, clears workspace flags bit4. Resumed route normally continues3,fresh route11D0; if E0zero stores that continuation in workspace164 and uses state1100. Resumed option400000 forces state3 and flags4; fresh option800000 forces state3 andflags14; both clear workspace8. Fresh flags10 means state3 skips ordinary cleanup/publication while leaving later handshake work represented in workspace; no claim that peer Finished has already been verified in this option mode.

Ordinary state3 (workspace flags10clear) wipes/frees temporary key block71ADE8,frees pending wrapper,detaches auxiliaryBIO unless flags4,clears pending40/renegotiation28,publishes cache71E058(connection,1),updates parent hit70/completion54. Always installs callback20=71D198,notifies completion20/1 when callback present,returns1. State notifications temporarily expose old state30 during1001/1 callback and restore the next state afterward. Partial allocation/child callback outcomes inherit their reviewed contracts; no whole-driver transactional rollback or verified protocol/security claim.

See [Hello/Finished framing](SYMBOLS_HTTP_SSL3_HANDSHAKE_MESSAGES_AND_HELLOS.md),[peer certificate path](SYMBOLS_HTTP_SSL_PEER_CREDENTIALS.md),[record buffers/reset](SYMBOLS_HTTP_SSL_RECORD_BUFFERS_AND_RESET.md),[cache publication](SYMBOLS_HTTP_SSL_INITIALIZATION_AND_CACHE_PUBLICATION.md),[protocol-specific key setup](SYMBOLS_HTTP_SSL3_KEY_BLOCK_AND_CIPHER_STATE.md). This records source responsibilities and unresolved child semantics; it does not attribute a slowdown to network or cryptographic work.

Audit: 493 verified instruction words, zero conflicts, 16 omitted zero words (NOP padding), zero omitted nonzero words.

The previously entry-only worker roles are now independently reviewed in [server parameters and certificate requests](SYMBOLS_HTTP_SSL3_SERVER_PARAMETERS_AND_CERT_REQUEST.md), [client certificates and key exchange](SYMBOLS_HTTP_SSL3_CLIENT_CERTIFICATE_AND_KEY_EXCHANGE.md), and [pending-cipher credential checks](SYMBOLS_HTTP_SSL3_PENDING_CIPHER_CREDENTIAL_CHECK.md). Their local retry-state and error-return qualifications remain explicit.
