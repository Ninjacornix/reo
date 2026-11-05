# Recovered platform startup, inline names and proxy/secure connection

Static File #1 US review, 2026-11-05. Owned o4/netdnas.bin, runtime5, base6E0000, SHA-256 **8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16**. This notebook supports the **two authoritative refined rows in [platform transport](SYMBOLS_NETDNAS_PLATFORM_TRANSPORT.md)**, at6EA4C0 and6EACE0. It adds no duplicate import rows, string functions or source-less fragment credit. No guest execution/emulation, game, build, network request, live-memory read, attachment, owned-image change or generated/runtime-code edit occurred.

New isolated [review_dnas_primary_start_connect.py](../tools/function_index/review_dnas_primary_start_connect.py) independently rereads52 primary metadata entries, each actual descriptor, both schedules, exceptions and literal entry arguments; reconstructs copied words and verifies exact original payload restoration. It binds the actual forward calls, including the noncanonical argument setup in the second owner. It saves an [addressed joined listing](../build-function-index/dnas-primary-start-connect-review/words.txt) and [receipt](../build-function-index/dnas-primary-start-connect-review/receipt.json). All717 listed words were individually read:282 reconstructed words and435 clear words. Of the282,196 are explicitly skipped inline binary/text data and86 are instructions/padding. Twenty-five exception words are preserved passwise. All54 direct branch targets and eight indirect-switch targets lie in reviewed instruction regions; no instruction field remains undecoded. The original generated-source catalogue remains unchanged.

## Ownership and actual restore paths

| Owner, logical interval end exclusive | Payload | Original payload SHA-256 | Candidate SHA-256 |
| --- | --- | --- | --- |
|6EA4C0..6EAA5C|6EA63C..6EA9E0,233words|`ef26ecdfcef765e1ba0ce5e7b04e6d0010bb0839ce7d61012192503c592911aa`|`733b7f4cee15d22bdee0e4b2e937c0ea2c5b198f623ac66f7109a504b5435954`|
|6EACE0..6EB320|6EADD8..6EAE9C,49words|`88abc10f9bcc8b8e8d8cb94a6eebbc12f075f6724dde2e921b3bc825f587b222`|`3a92f68e12735def43f9c3af23ca164624d6e655fd0daae40f0bb01fc3d62dd6`|

Startup complete original interval SHA-256 `4217fb9a29c62ca505d19e02853109140f262ff76367e8b8840d9d7e2b417015`; connect complete original interval SHA-256 `63d26edd3cf260623f6fa10914948d36a7cc71a503619092d2daf36e95c8ffc8`. Both owners have balanced integer/FP saved-register restoration and stack deallocation. The original entry header-word gate conditionally invokes70BA68, then branches over junk/header bytes to the reconstructed body. Payload-end branches skip their paired restore descriptors. Skipped header words, DER/string bytes and padding are not treated as newly discovered function entrances.

Startup entry6EA600 loads header6EA628 `[0,FC6241F7,751A35F6,FC624253,0]`; span3A4hex and inverse schedule7,7,1,4,2,6,4. Its normal payload end6EA9E0 branches to6EAA10; actual forward call6EAA28 loads descriptor6EAA00 `[F7F1426C,751A35F7,F7F141C8,0]`, literal end6EA9E0 and schedule4,6,2,4,1,7,7. However an inner provider-NULL branch returns to6EA59C and exits with-610 **without reaching that restore**. Exact arithmetic round trip therefore does not establish that all runtime exits restore encoded bytes.

Connect entry6EAD9C loads header6EADC4 `[0,7F735535,751A381A,7F7355F1,0]`; spanC4hex and inverse schedule5,3,5,5,3,7,7. Its payload end6EAE9C branches to6EAECC. The descriptor6EAEBC `[7535537F,751A381B,753553BB,0]` is loaded intoV0 there; a0=end6EAE9C,a3=descriptor+4,a1=descriptor+8. Interleaved S5/S0/S3/F22 initialization leaves those arguments and V0 unchanged. Actual forward JAL6EAEFC loads a2=descriptor+0 in its delay slot, using schedule7,7,3,5,5,3,5. This individually binds the inventory's previously noncanonical restore. Every admitted proxy string-construction path reaches it before formatting; direct-endpoint paths bypass that protected island entirely.

These checks concern original static paths. Header-self-pointer writes/cache calls, concurrent entries and live header state were not performed or simulated. Arbitrary code/header/stack aliases are not admitted by the local contracts.

## Startup6EA4C0

Initial result is-625(-271hex). It clears connected word761778, creates semaphore6EA3F8(0,1) into761780 and returns that failure status when creation is negative. Otherwise it gets current thread ID114510 and passes it to1DA310. Negative registration result maps-625. The admitted nonnegative registration result is saved inS2; later successful startup returns that value, without locally normalizing it to0.

Raw mode761788==0 skips secure setup and the protected island, records current thread ID in76177C and returns saved registration result. Secure mode stores allocator callbacks6E99B0/6E9E88/6E9CE8 in7F1140/44/48 and installs them through7108C8. It invokes library initialization71D130 and lazy method717228, constructs context71E408 and stores76178C. NULL context yields-610(-262hex). It sets numeric control71DF00(context,20hex,FFFF,NULL), backend configuration71E800(context,5,0) and configuration callback71E7F0(context,6ECD20,0). These helper results are not checked here. Their [reviewed lifecycle contracts](SYMBOLS_NETDNAS_SECURE_LIFECYCLE.md) retain provider/method uncertainties.

The reconstructed body contains six branch-skipped DER-style name objects. It installs their pointers at offset0 of six20-byte records beginning7616F8. Original offset4 lengths and other fields are read from the immutable image, rather than guessed from spacing. It then iterates exactly six records, placing the pointer on the local stack and calling:

`6FC998(NULL,&localPointer,record.word4)`

Each returned pointer is stored at record+10hex. A NULL immediately selects-610 through6EA59C and returns, retaining already stored earlier record results and context/semaphore state; no local rollback or forward code restore occurs on that inner failure. All six nonNULL results reach the actual restore and current-thread recording coda. The separately reviewed [6FC998 wrapper](SYMBOLS_NETDNAS_BACKEND_CALLBACKS.md) delegates to slot7F1B10 or reports missing and returns0. Its backend operation remains unknown. The argument shape/data supports a DER name-decoding candidate, **not a locally proved full-certificate parser or trust validation**. A separate global cleanup owner releases nonNULL record+10 values later.

| Record | Inline pointer / exact bytes | Identifying embedded name text | Data SHA-256 |
| --- | --- | --- | --- |
|7616F8|6EA64C /172|DNAS CA|`9cc78123172b3130971b37dc749ce7f32dc498572d0430906c6b2e53749e29bf`|
|76170C|6EA720 /78|ROOT TEST CERT (root512)|`77fccfa128b0c6e1a0d00dde6ba1ce53db17d236be61e6a52d6006fc3f692e96`|
|761720|6EA790 /97|Class1 Public Primary Certification Authority|`ac32449657f109305721abacca32a25eac940b9728098e82e64789ed68791fa4`|
|761734|6EA818 /97|Class2 Public Primary Certification Authority|`cc65e1533e1b9c64765060b0addba6e3c3b9770c7fd18d5612b244f181a46657`|
|761748|6EA8A0 /97|Class3 Public Primary Certification Authority|`a940566938cb34d52da577f7621730e9ed8120747fab4b6aca5686bca76ead33`|
|76175C|6EA928 /97|Secure Server Certification Authority|`bd7c7838911dfb510c886829cbaa90546e89c8e9d3acec188cd89a6e1840fc30`|

The private helper checks definite TLV bounds and extracts printable/IA5 string fields within those exact copied-data lengths. It does not execute a decoder, validate a certificate chain or fetch any named authority. The six original records' +8 fields are0 and+C fields126/5E/A2/A2/A2/9Ehex; this owner neither fills nor interprets those values beyond using+4 as the provider length. Original literals and their current cryptographic validity are distinct questions; no operational recommendation follows from this static data inventory.

## Connection6EACE0 and optional CONNECT request

Nonzero connected word761778 returns-1 before beginning a guard or transfer. Otherwise it saves6EA340's optional scheduling-guard result; a negative guard result does not itself abort the connection. G is750FB0. If G+404==0 it connects7F1150/u16 at7F1350 through the fully reviewed [resolver/socket helper6EAA60](SYMBOLS_NETDNAS_PROTOCOL_OBSERVERS_AND_CONNECT.md). If G+404!=0 it first connects proxy textG+204 and u16 portG+408. Either initial connection failure returns the saved error, cancelling the original guard only when its result>=0.

The proxy branch's protected island copies literal `CONNECT ` to stack0 using bound9 and literal `:443 HTTP/1.0` to stack10hex using bound18. It appends literal CRLF twice to that second string, each append bound18. These source literals are skipped data at6EADE8,6EAE24 and6EAE68; the skipped regions are not instructions. The destination hostname text is7F1150; the tunnel's port suffix is **fixed443**, independently of the configured direct endpoint's u16 port. After actual code restoration it formats global7F1358 using owned format77C180 `%s%s%s` and the three local/host/suffix arguments. No local sprintf output bound or hostname-length admission is present.

It overwrites local9+18 bytes with the original scaled-LCG loop, measures the formatted global string and calls1DA080(socket,buffer,length,0). It accepts any nonnegative send result without an exact count comparison. On both send success and failure, it overwrites538 bytes beginning7F1358 before proceeding. A negative send result is translated through1D96E0/6EB868 and enters common close cleanup. On nonnegative send it calls6EB9C8(socket), requiring200. Any other **positive** response becomes-602(-25Ahex); nonpositive is preserved and the same close path runs. Thus a returned zero from that response helper also closes but can propagate integer0; this caller's zero alone is not a proof that all paths leave a connected transport. The response helper's deeper parsing contract belongs to its separate review.

On accepted proxy200 or successful direct connection it writes761778=1 before considering secure mode. Raw mode returns0 after cancelling an admitted original guard. Proxy formatting/overwrite work is absent on the direct path. These are static original requests, not a network operation performed by this investigation.

## Secure session and exact handshake switch

Secure mode sets context control71DF00(context,20hex,40000hex,0), constructs session71D6E8(context) into761790, and defaults saved error-610. NULL session takes common close cleanup. It installs6EBF30 via71F1D8(session,+C0),6EC4B0/0 through71F1E0(session,+C4/+C8), and initializes client state71EEC8. It wraps the existing socket6FA638(socket,0), rejectsNULL, stores stream callback6ED490 through6F3320 and assigns that stream as both session input/output through71DAC0. No pointer ownership or protocol meaning beyond the already reviewed [stream/session helpers](SYMBOLS_NETDNAS_SESSION_ACCESSORS_AND_CONTROLS.md) is invented.

Each iteration invokes71EE28(session), then classifies its result through71EC90(session,result). The owned eight-pointer table77C190 is:

| Numeric classifier | Target / local action |
| --- | --- |
|0|6EB270: set completion flag1, proceed to accepted completion|
|1,2,3,4,5,7|6EB278: inspect pointed adapter error;113decimal translates through6EB868, otherwise-610|
|6|6EB298: with initial completion flag0, loop back6EB238|
|Unsigned value>=8|Same error path6EB278|

The parent completion flag starts0 and is set only by case0. There is no local sleep, yield, retry count or direct wall-time test in the case6 loop. Child handshake/transport calls and the optional external timeout mechanism own any actual waiting, progress or cancellation behavior. Numeric6 is described by its observed routing, not assigned a familiar external error-enum name. Existing [secure result/handshake contracts](SYMBOLS_NETDNAS_SECURE_OPERATIONS.md) retain method/backend uncertainties.

Accepted completion cancels the original guard when result>=0 and returns0. Common error cleanup cancels it directly only when result **>0** (BLEZ skips zero), then invokes6EB5F8, which owns its own close/guard behavior, and returns saved status. This threshold differs from success/early-connection error paths; no universal cancellation guarantee is inferred. The close helper clears761778 and releases secure session/raw socket using its independently reviewed contract. Balanced restoration returns all saved S0..S7/RA/F20..F22 with stack144decimal.

The overwrite loops use74AA20, CVT.S.W, division by binary32 bits4EFFFFFF, multiplication by256, CVT.W.S and the original2^31 subtract/convert/OR correction before low-byte stores. FP rounding is retained. No secure-erasure, cryptographic-randomness, actual handshake success, measured network stall or gameplay slowdown cause is claimed. Source-comment auditing checks the authoritative original rows separately from reconstructed code/data and actual restore proofs.
