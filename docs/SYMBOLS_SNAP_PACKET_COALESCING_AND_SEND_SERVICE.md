# SNAP packet coalescing and send service

Static File #1 US main-ELF research,2026-11-04. Five complete bodies including every compatibility, allocation, acknowledgement and send branch. [Owned identity](FUNCTION_INDEX.md). No socket, game, benchmark, emulated service or native replacement was executed.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x1DB4B8](../recomp/config/output/sub_001DB4B8_0x1db4b8.cpp) | `add_snap_acknowledgement_word_to_host_or_wire_order_record_header` | Confirmed complete two-order update | Tests packet flag2000. Set: converts payload half0 from wire order, OR4000, converts back; writes reversed a1 to headerC. Clear: OR4000 and write a1 directly. Uses packet+2C; does not allocate, grow payload or validate that a16-byte header exists. |
| [0x1DB598](../recomp/config/output/sub_001DB598_0x1db598.cpp) | `combine_snap_low_six_packet_flags_by_ordered_compatibility_rules` | Confirmed complete ordered mask matrix | Takes low16 a0/a1, initializes result-1 and applies six independent first-mask tests in order1,2,4,20,8,10. Every matching second-mask rule overwrites prior result; this is neither bitwise union nor a symmetric general set operation. Complete rule table below. |
| [0x1DB914](../recomp/config/output/sub_001DB914_0x1db914.cpp) | `coalesce_compatible_ready_snap_packets_preserving_acknowledgement_and_pool_ownership` | Confirmed full multi-pass algorithm; caller admission partial | With ready queue count<2 returns0. Transfers pending acknowledgement marker1000 toward first packet, optionally removes/recycles marker-only nodes200. Stops if first already wire-converted2000 or marker-only200. Pre-scans compatible following packets, optionally grows first allocation, appends compatible payloads while releasing their nodes, updates combined low6 flags and marks first header0800 for selected coalesced modes. Full ordering and limits below; list/allocator failures may leave partial mutations. |
| [0x1DC1E8](../recomp/config/output/sub_001DC1E8_0x1dc1e8.cpp) | `append_snap_acknowledgement_control_record_to_pending_packet` | Confirmed complete reserve/header write | Reserves16bytes at packet tail; failure returns0 without write. Success half0=6010, word4=context44, word8=0, half2=0, wordC=packet24. Bytes not explicitly assigned remain untouched. The return is inherited from the last helper before stores, not a stable Boolean success contract. |
| [0x1DC298](../recomp/config/output/sub_001DC298_0x1dc298.cpp) | `coalesce_send_one_snap_datagram_and_transfer_packet_to_retry_or_free_pool` | Confirmed complete one-packet service; send observation limited | Empty ready queue exits. Coalescer error latches context50C=1F5. Pops one ready packet, adds pending ack/header when flagged1000, computes pacing from length/context40, assigns sequence and retry fields when flag8000, converts header and appends wire trailer once, then calls1E930C sendto. Returned length mismatch latches1F4. Successful flag8000 moves packet to retry queue context58+8; other packets return to context520 pool. Updates ready schedule time only after that ownership step succeeds. One invocation sends at most one packet; no measured packet rate or game tick linkage. |

## Ordered compatibility rules

Starting result=-1, apply every row whose first-mask bit is set, top to bottom. Within a row the right-hand conditions run in the displayed order. A later assignment replaces earlier assignments. Values hexadecimal.

| First-mask bit | Second-mask condition and assigned result |
| --- | --- |
| 1 | Any1/20 ->20; then any2/4/8 ->8. |
| 2 | Any2/4 ->4; then any8/10 ->10. |
| 4 | Any2/4 ->4; then any8/10 ->10. |
| 20 | Any1/20 ->20; then any2/4/8 ->8. |
| 8 | Any2/4 ->8. |
| 10 | Any2/4 ->10. |

Bits outside this set have no direct effect. Multi-bit inputs retain ordered overwrite behavior, so reducing the implementation to a single-type enum without checking actual callers would change its contract.

## Coalescer ownership and bounds

The first pass finds the first1000 acknowledgement marker in queue order when the head lacks it, copies packet24 to head, sets head1000 and clears source1000. If source also has200, it unlinks and returns that node to the pool. A marker-only head can similarly transfer its marker to the following unmarked packet and be removed. These are distinct mutations with checked unlink/pool-return errors.

The size pass starts extra=4, skips nodes200/2000, stops at1000, incompatible flags or `candidateLength+extra+headLength>=380hex`, and accumulates candidate lengths otherwise. The strict limit admits at most895bytes in this expression. It tests head tail capacity for low16 extra. If insufficient and head pool class!=2, it requests a larger pooled allocation for low16(headLength+extra), requiring a strictly greater allocated size. It inserts the replacement after head, clones head preserving the replacement allocation, then unlinks/releases the old head. Allocation/size rejection leaves the old head; later copy/list failures can occur after insertion.

The merge pass again skips marker-only/wire-converted nodes, stops at acknowledgement or incompatible flags, and appends through1F3694. Its special-1F3Ehex capacity result ends merging; other nonzero results return. Success unlinks/releases the merged node, replaces head low6 flags with the combined result, and restarts traversal from head. The earlier extra quantity is a loop-enable value, not a decremented merge count. Selected final flag20/4/8/10 modes OR0800 into first record half0. Structural count/cycle admission is inherited from intrusive-list owners.

## One-packet send and retry transfer

Pacing is `q=unsigned(length+context40+31)/context40`, floored to at least17decimal; context40==0 reaches the original divide trap and is not rejected here. The result is stored in ready-service word4. This arithmetic is not assigned a physical bandwidth unit without the configuration producer.

For packet8000 and not already2000, it finds a record with header8000, allocates the next context58 sequence, stores packet28 and increments context58 word4. In the embedded-record branch it copies an unchanged16-byte local header back after updating packet metadata; it does not patch the copied header's word8 with the new sequence. This literal distinction needs upstream format/producer review before treating it as a defect. Retry packet18 becomes the supplied time; packet14 becomes q+context510. Previously wire-converted packets keep their payload conversion and sequence.

For packets lacking2000, converts record byte order1F39E8, appends four bytes from reversed BA476611, and sets2000. The append result is ignored locally. Sends payload pointer/length to context48 address using logical descriptor context0. The [socket adapter](SYMBOLS_SNAP_SOCKET_DESCRIPTORS_AND_DATAGRAM_SERVICE.md) may normalize backend results, so matching the returned length alone does not prove delivery or a remote acknowledgement. A failed send occurs after the ready pop and has no local reinsertion/reclamation in this body.

Five bodies /962 instruction words. Original low-level error handling, partial publication and uninitialized padding are preserved as research limits. Related [queue/options](SYMBOLS_SNAP_SEND_QUEUE_AND_CONNECTION_OPTIONS.md), [pool/list](SYMBOLS_SNAP_PACKET_LISTS_AND_POOL_ALLOCATION.md), [byte order](SYMBOLS_SNAP_PACKET_COPY_AND_HEADER_BYTE_ORDER.md), [retry fields](SYMBOLS_SNAP_PACKET_BUFFER_AND_RETRY_FIELDS.md). All owned instruction comments match; omitted aligned words are zero. No observed leak, packet loss, slowdown or native fix is claimed.
