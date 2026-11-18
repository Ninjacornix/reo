# Local SJUNI contract and native adapter proposal

2026-11-05. Contract based on File #1 original words. The
[independent core](../../game/native/sjuni/README.md) and
[portable bridge](../../game/native/sjuni_adapter/queue_bridge.h) are implemented
for an explicit admitted domain; complete player-path replacement is pending.
The [inventory and validation status](README.md) supply consumers, identity and
test evidence. The [original contract notebook](../SYMBOLS_CRI_SJUNI_LINKED_CHUNK_POOLS.md)
remains authoritative for guest behavior outside that domain.

## Observed contract

SJUNI is a fixed metadata-node pool serving four FIFO lists of borrowed spans.
Creation claims a free object from 64 slots and converts signed work bytes to
node count by division by 16, truncating toward zero. It allocates no payload.
The known paired caller supplies 256 node bytes, producing 16 nodes, and later
publishes 16,384 borrowed payload bytes. The sizes describe different resources.

The guest object's fields are:

| Offset | Meaning | Mutators / observers |
| --- | --- | --- |
| `00` | SJ vtable | Create, destroy, all retained interface consumers. |
| `04` / `05` | Active byte / mode byte | Object-pool scan; only mode exactly 1 selects splitting/merging. |
| `08` | UUID pointer | Create, UUID query, destroy. |
| `0C` / `10` | External node array / signed node count | Create, reset, destroy. |
| `14` | Free-node head | Reset, whole get, nonmerged put/unget, free-node query. |
| `18..24` | Four queue heads | Reset, queue operations/queries, destroy. |
| `28` / `2C` | Error callback / context | Create, callback registration, error branches, destroy. |

Each 16-byte node has next at `00`, an untouched word at `04`, borrowed payload
pointer at `08` and signed byte length at `0C`. Reset must preserve word `04`.
Whole get pushes the consumed node onto the free list without clearing its old
payload fields. Those details matter if guest node storage remains observable.

| Operation | Behavior that a replacement must preserve |
| --- | --- |
| Reset | Rebuild free list in node-array order, clear payload words, clear four heads. No payload ownership transfer or deallocation. Constructor-reachable zero/negative node counts still write the first node in the original; they are not established safe inputs. Raw corrupted count `INT32_MIN` has different wrapping behavior. |
| Get | Invalid selector reports -3 and empties output; empty queue gives empty output. Signed request at least head length removes the whole span, even if the request is larger. Smaller request splits only in mode 1; other modes return empty and leave state unchanged. |
| Put | Invalid selector reports -3 before span admission. Null pointer or signed nonpositive length is ignored. Mode 1 merges an adjacent tail; otherwise consumes a free node and appends. A merge can succeed with no free nodes. |
| Unget | Same selector/span admission as put; mode 1 merges before the head when adjacent, otherwise consumes a free node and prepends. No check that the span came from the latest get. |
| Byte sum | Sum selected queue lengths with original 32-bit wrap behavior. Invalid selector reports -3 and returns zero. This is neither free-node count nor queued-node count. |
| Availability | Always initializes available-length output to zero. On a nonempty valid queue exposes full head length. Mode 1 returns signed `head.length >= request`; other modes require exact equality, even though whole Get accepts a larger request. |
| Queued-node count | Counts linked nodes; original selector is unchecked. Do not silently turn this into a byte count or infer safe out-of-range inputs. |
| Free-node count | Counts free-list nodes without modifying them. |
| Error registration | Replace callback/context immediately; default emits the SJUNI diagnostic through the shared reporting path. |
| Destroy | Null is ignored; otherwise clears the 48-byte object. No node-array or payload free. Pool-reference release is separate from object destruction. |

See [error and synchronization ordering](SYNCHRONIZATION_AND_ERRORS.md) before
implementing callbacks. Invalid selector and pool exhaustion share error code -3
but occur at different synchronization boundaries. Queries/reset/lifecycle are
not made thread-safe by the SJUNI body itself.

Signed negative requests, zero-size splitting, 32-bit pointer/length wrap,
callback mutation of the same object and aliased output descriptors require
explicit admission rules. The replacement must not introduce C++ signed overflow,
undefined pointer arithmetic or a silent clamp while claiming equivalence.

## Proposed independent native interface

Use a native `StreamPool` owning a fixed allocation of metadata nodes and four
list heads. Configure node capacity at creation, allocate metadata once and
perform no payload allocation or copy during queue operations. Stream identity
and generation belong to a separate owner; lifetime does not follow a channel's
reservation flag. Reusing a released instance must invalidate stale native handles.
A sidecar generation alone cannot distinguish stale and new identical raw guest
addresses after slot reuse. Existing guest tokens need an independently proved
lifetime rule or a generation-bearing owner before claiming stale-token rejection.

The core interface should expose these operations with units in their names:

```text
create(node_capacity, mode, error_handler) -> stream
reset(stream)
take(stream, queue, requested_bytes, output_span)
append(stream, queue, borrowed_span)
prepend(stream, queue, borrowed_span)
queued_bytes(stream, queue) -> wrapped_32_bit_count
head_availability(stream, queue, requested_bytes, output_head_bytes) -> boolean
queued_nodes(stream, admitted_queue) -> node_count
free_nodes(stream) -> node_count
set_error_handler(stream, handler)
destroy(stream)
```

This is the design sketch. The [compiled C++ API](../../game/native/sjuni/sjuni.hpp)
uses `Pool::get/put/unget` for take/append/prepend and explicit preflight results;
those results are not original guest ABI status values. Keep the
separate descriptor-splitting helper out of the first entry-point redirection.
It has independent MPEG/file/audio callers with different admission needs.

Represent a borrowed span by a native backing-region identity, byte offset and
signed 32-bit length. Region identity must retain the correct address domain and
borrowed lifetime without making the core depend on guest RAM. Only the adapter
converts guest numeric tokens into registered native regions. A region may be
an opaque IOP-storage resource; the queue core never dereferences its contents.
This avoids casting arbitrary IOP numeric addresses to host pointers.

For the initial admitted domain, split and merge require representable lengths
and offsets within a registered region. The original merges by wrapped numeric
adjacency, including potential allocation boundaries; native region equality is
**not** already proved equivalent. The adapter must establish an adequate region
model or keep that entire stream on the original implementation. Unsupported
inputs discovered after native mutations cannot simply be sent to an out-of-date
original object. Any fallback needs an exact synchronized state transfer first.

The core must not include PS2Recomp headers, register contexts, guest syscall
wrappers, fixed guest addresses or a simulated CPU/memory implementation. The
core accepts a synchronization/error policy whose invocation points preserve the
reviewed contract. The temporary adapter supplies the remaining CRI hooks and
guest callbacks. Introducing a native lock is a separate design decision that
requires callback-reentry and cross-worker ordering validation.

## Temporary adapter and ownership

The proposed first integration retains guest object addresses and vtables.
A registry maps each admitted guest object to a native stream and generation.
Replace only known local SJUNI entries; generic SJRB/SJMEM and remote RPC entries
retain their own implementations. Registry lookup must verify edition, object
membership, activity, generation and the established implementation identity.
No unchecked host-pointer storage in a 32-bit guest field is permitted.

The adapter owns four conversions:

1. Guest object/token to native handle, including initialization and last-reference
   teardown of the shared pool.
2. Payload token to borrowed region/offset and back, preserving EE/IOP domain.
3. Native node IDs to the exact caller-supplied guest node addresses, including
   free-list order, stale payload fields and untouched node word `04`.
4. Guest callback/context invocation and the shared CRI scheduling hooks, with
   writes visible at the same points as the original when callbacks reenter.

The implemented bridge imports the complete guest representation for each
operation, uses a single authoritative native working state during that call and
mirrors the complete externally observable queue representation at boundaries. If
remaining consumers can directly mutate nodes/heads between operations, import
and reconcile those mutations explicitly or migrate those accesses before
enabling the instance. Mirroring only the four byte counts is insufficient.

Destroy/reset/reference-release paths must reconcile outstanding DTR/SJX
reservations and callback lifetimes. Preserve existing behavior until quiescence
is demonstrated; do not fix an assumed teardown issue by reordering calls during
the equivalence migration. A separate change can address a confirmed defect.

## Independent comparison and acceptance cases

The comparison harness runs identical admitted operation sequences
against the preserved original and independent native core. A second copy of the
new algorithm is not an independent oracle. Pin ELF/build/compiler identity and
compare outputs, list/node order, free-node ownership, mirrored bytes, errors,
callback entry state and scheduling-hook traces after each operation.

At minimum cover:

- All four queues, empty queues, one node, sixteen nodes and pool exhaustion.
- Mode 1 partial and whole reads, overlarge requests, mode 0/other-mode reads,
  and the different availability comparison for non-mode-1 requests.
- Adjacent and nonadjacent append/prepend, merging with an exhausted pool,
  multiple consumers reserving spans and return in a different order.
- Reset with outstanding borrowed spans, instance destruction, reservation
  release/reuse and first/last shared reference transitions.
- Invalid selectors, ignored null/nonpositive spans, null error handler,
  returning/reentrant error handlers and numeric admission boundaries.
- Original output-alias and signed-edge cases once their supported domains are
  established; otherwise record why the instance remains on the original path.
- The real `13ED28` consolidation sequence and DTR/SJX completion ordering, then
  audio/movie transitions, pause/resume, repeated loading and shutdown.

The admitted isolated comparisons and standalone core build have passed; exact
counts and limitations are in the [validation status](README.md). Real-consumer
integration, original scheduler/device behavior and complete lifetime migration
remain pending. Timing requires a separate controlled baseline/retest and is not
implied by native correctness in the isolated domain.
