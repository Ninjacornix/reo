# HTTP response body modes and chunk orchestration

Static File #1 US research, 2026-11-04. Catalogue **o6**, runtime id **6**, base **0x6E0000**, owned **nethttp.bin**, SHA-256 **68dbc8f16c5d0cc8a43205beb86ddac405a12c1d6b843b5961211bbe6ec30117**. [Response framing](SYMBOLS_HTTP_RESPONSE_FRAMING.md),[request/worker primitives](SYMBOLS_HTTP_REQUEST_RESPONSE.md),[owned identities](FUNCTION_INDEX.md). The complete original instruction window0x6E1D88..0x6E2CBF was reviewed in three slices. No game,build,network request,attachment,live-memory read or timing test occurred.

This is one large catalogue function. Internal branches/labels are not counted as additional mapped functions. Its broad orchestration role and literal contracts below are established;opaque transport/callback behavior and some exceptional buffer ownership remain unresolved.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o6 0x6E1D88](../recomp/config/output_ovl/o6/o6_006E1D88_0x6e1d88.cpp) | `receive_http_response_body_to_memory_file_or_chunk_callback_candidate` | Probable response role; full body/control flow reviewed | Allocates work buffer with signed clamp of chunk+84 into512..32768,parses initial status/headers0x6E1620,handles connection policy,HEAD/status body suppression,Content-Length and exact chunked transfer selection. Nonchunked path copies buffered prefix then receives fixed or unknown length,with memory growth or output callback. Chunked path accumulates size line,parses hexadecimal count,receives count+2 bytes,emits payload to optional chunk callback,owned memory append or output callback,and reads trailer headers after leading-zero termination. Tracks progress/expected count/partial flag at+100/+118/+108,retains body pointer+F8. Deadline/cancel/error cleanup and final return differ;detailed contracts below. No standards conformance,runtime reachability or performance cost is asserted. |

## Admission and output modes

- Context+CC is captured as output handle. **-1 selects owned memory**. Other values call output function+D0 with saved GP+D4,handle,bytes,count,user argument+17C. Default+D0 is the separately reviewed resident [file RPC write0x119310](SYMBOLS_FILE_RPC.md);the callback must return the exact requested count or engine error-1014 is stored.
- Method2 is HEAD,corroborated by the owned method table. HEAD,exact statuses204/205/304,and parsed Content-Length0 bypass body reception. Content-Length absence/invalid returns-1 from its helper and follows unknown-length handling here.
- Connection:close sets state mask10. Connection:keep-alive can parse a Keep-Alive header's timeout/max fields into context+30/+34. Missing connection metadata can set both to-1 for a specific version pair. Original full-name comparisons and version-word packing are retained.
- Header `Transfer-Encoding` is found by full-name lookup. Only value exactly casefolded `chunked` selects chunk processing;lists/extensions are not normalized here. The nonmatching-value branch is discussed below.
- Memory capacity and wire work-buffer capacity are separate. Positive known length uses a corresponding body allocation;unknown length starts with the derived work capacity and can double the body capacity. Sentinel and mixed32/64-bit comparisons remain original guest behavior,not an idealized unsigned-size API.

## Fixed and unknown-length bodies

Already buffered bytes are copied or written before further reads. Known-length paths cap consumption at the remaining body count. Unknown-length paths may grow memory and receive until transport returns nonpositive or a configured limit/deadline stops work. Reallocation failure can retain and publish a partial result;it is not uniformly propagated as an immediate allocation error.

Body progress at context+100 is stored64-bit. Callback+78,GP+80,arg+7C is used for threshold notifications when method!=PUT;threshold advancement uses chunk+84 and guest SLT comparisons. Callback behavior is not timed or executed. Positive step-size assumptions are not enforced by all local inner loops.

Shared helper0x6E1BF0 can mark context+108 on deadline expiry and return a partial count. This orchestrator distinguishes that flag from socket/worker state masks and engine errors. A known positive length with remaining bytes can set error-1015;over-consumption state below-1 is also handled as-1015. No wall-clock or game-update rate is inferred from any count.

## Chunk path

The line accumulator0x6E1190 handles fragmented size lines. The code cuts a semicolon at the first occurrence,skips leading spaces/tabs,and parses hexadecimal digits with guest32-bit shifts/adds. It does not implement a general chunk-extension grammar or overflow check.

The first nonspace size-line byte being ASCII **0** takes the terminating/trailer path before parsing remaining digits. This literal admission therefore includes leading-zero strings;the map does not silently replace it with an ideal numeric-zero test. That path calls0x6E1620 with first-status flag0 to collect trailers.

Positive parsed count requests scratch capacity **count+2** and handles an already buffered suffix or calls0x6E1BF0 for the remainder. Payload consumers receive count bytes;the trailing two bytes are consumed without a locally explicit CRLF-content test. The modes are:

- Nonnull context+120 callback receives context,scratch payload,count,arg+124 under saved GP+128. Its return is ignored. Subsequent code does not free that scratch buffer on this branch;callback ownership remains unresolved.
- Otherwise output handle-1 appends payload to owned memory,allocating/reallocating by accumulated count. A size bound or failed growth can mark the partial flag.
- Other output handles call+D0 and require exact returned count. Scratch is freed on ordinary noncallback completion before the next size line.

Progress callbacks and stored body-size fields are updated separately from payload ownership. The final body pointer goes to context+F8 and received count to+100. Error cleanup calls response-state destructor0x6E05F8 on some paths,whereas partial-result paths can retain body storage for the caller.

## Static follow-up boundaries

At0x6E2004,a nonzero comparison against `chunked` branches back to0x6E1FE0. That redoes the same full-name lookup from the response-list head and reuses the same expected value,without a locally advancing header cursor or value mutation. With an unchanged admitted nonchunked Transfer-Encoding node,this is a potential nonprogress loop. External mutation/admission and live execution are not established;it is not attributed to a gameplay incident.

At0x6E2368..0x6E2378,the partial size-line path tests a byte at current cursor+remaining count when remembering a CR prefix,not the last byte at minus1 used by the separate header accumulator. Buffer extent and caller data determine whether this read is admitted. It is recorded as a boundary concern,not a reproduced invalid access.

These observations are held for the implementation phase after the user's updated100% mapping milestone. No fix,benchmark or controlled retest was performed.
