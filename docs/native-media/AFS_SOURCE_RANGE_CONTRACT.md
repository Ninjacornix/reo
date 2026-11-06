# Native AFS sector-range binding

Status: implementation contract, 2026-11-06. This reconstructs a bounded AFS
index and source-range preparation, not the asynchronous partition loader,
LSC queue, full ADXT player or an audio-device lifetime.

Original128B18/128B30 parses a header into16/32-bit sector lengths;129E18
resolves by summing those lengths from the first data sector.130478 shifts its
count argument left11 before deferred open.130B78 obtains the actual backend
sector extent and clamps start/count. Logical member bytes and the retained
sector range are distinct. The earlier source-geometry report is an inventory
boundary, not evidence that every partial ADX member needs invented padding.

Open an immutable retained parent ByteView and a checked archive subrange.
Read only a bounded header/index on the control thread, admit AFS magic/count,
and retain original logical lengths plus first-offset/rounded-length sector
geometry. Verify all nonempty raw offsets agree with the original cumulative
sector representation and all logical and rounded extents fit the archive.
Empty entries retain their original cumulative start; a raw empty offset need
not point to data. Reject gaps/overlaps, nonaligned data, truncation, oversized
counts and unrepresentable signed source extents as explicit native profile
refusals. Do not silently widen frozen Source2 or alter owned containers.

Return a bounded view over the **actual retained parent bytes** for a member's
sector range, together with its logical length. Never zero-fill a tail or read
outside that admitted range. Returned views retain immutable backing even after
the index/control object dies. No guest pointer, borrowed path, original memory
capacity sentinel, worker handle or mutable partition alias escapes.

The default open count sentinel is0xFFFFF sectors (stored0x7FFFF800 bytes).
Preserve the actual original special case that selects full backend length;
ordinary start/count clamp uses the backend sector extent. Admit nonnegative,
checked signed arithmetic only; negative/wrapped guest inputs are outside this
native range profile. This pure range result is not proof that the deferred
open, stop, close, ring or provider lifetime has completed.

Construction and view creation may allocate and return typed errors. Index and
member metadata queries are nonallocating/read-only. Do not hold native queue
or CPU/RPC locks while reading a ByteView. Failure publishes no partially built
index or view. Partial provider writes stay private during index admission.

Compare original parsed descriptors, member ranges, and deferred open/clamp
results against frozen synthetic boundary/header-window cases and35 previously
indexed real archive tables. Header I/O status/read, loader cleanup, string
library and backend open/size remain explicit original-harness hooks; no such
hook may supply a parsed table or member result. Validate actual retained-byte
reads and lifetimes separately. Actual payload decode and player integration
remain required before changing the game's source path.
