# Owned PCM store for Window2

Status: contract before implementation, 2026-11-06. This is a separate storage
component for future Window2, not a decoder, RNA/DTR owner or game replacement.
Original evidence is [the new lifecycle/PCM corpus](ADX_WINDOW_V2_ORACLE.md).

The store owns one or two real SJRB rings, each16,384 bytes plus192 physical
extension bytes. Construction allocates all storage and metadata. Channels have
identical initial cursor and queued byte count; synchronized batch reads and
publication preserve that geometry. Arbitrary per-channel mutation is absent.
There is at most one producer reservation and one consumer batch at a time.
They can coexist. Every ordinary operation after construction allocates nothing.
All calls and retained views require external serialization.

Actual Get(0,16384) calls acquire the output grants, in channel order. The only
write operation accepts already-decoded scalar PCM, corrected produced samples
and published samples separately. It does not run or change a codec. It checks
all channels before storing anything. Raw PCM can exceed logical grant size only
in the physical extension. Produced/published logical prefixes must fit the
actual grant, and publication cannot exceed corrected production or raw PCM.

Before copying, check every affected physical interval: raw stores, the explicit
extension-to-beginning copy for corrected produced samples, Ring publication's
beginning-to-extension mirror, and its extension-to-beginning copy. Protect all
currently queued main bytes, the queued extension prefix that a wrapped current
read can actually expose, and all held consumer physical spans. Queue prefix
mirrors that cannot currently be read through the extension are not extra
logical data. Reject an overlap, even if the proposed value equals the old one.
Extent calculations use wide arithmetic before effects.

After admission, store both raw planes at the first grant's offset, then perform
corrected-production wrap copies. For each channel: expose a bounded read-only
publication view, actual Split at the published byte count, Put(1,prefix), then
Unget(0,suffix). Preserve raw padding rather than truncating it or granting it
logical credit. Record each completed disposition; a later failure never rolls
back already accepted PCM or retries the whole transaction.

Read batches call actual Get(1,requested) for all channels, retaining each exact
physical descriptor. Their strong backing/domain lifetime does not retain the
control owner. Explicit finish on the same live owner returns actual Put(0)
credit. A lost or destroyed token does not return credit. A moved, stale or
foreign token cannot return someone else's credit. There is no reset/ID reuse.
Publication views retain storage, but are neither consumer credit nor immutable
snapshots; copied reads may observe later serialized changes. Owner destruction
invalidates reads without returning credit.

Reserve/read refusals before Get leave state unchanged. Refusal of a proposed
write occurs before PCM stores but **after reservation effects**: keep that
reservation, and allow an explicit all-channel restore only if its ledger is
still complete. Do not fall back to the original decoder. Unexpected partial
Ring failures retain the exact remaining ledger and fault the owner. Guard
observers are synchronous/read-only; transfer snapshots label in-progress
operations rather than pretending all ledgers are stable inside a Ring callback.

Stop closes new producer admission; accepted PCM and held consumer batches remain
drainable. Normal retire requires stopped admission, no producer or consumer
credit, no queued PCM and no ledger fault. It is not a device completion fence.
Emergency destruction closes the domain and retains backing through tokens; it
does not fabricate normal retirement. No provider worker or callback thread may
mutate this store outside its serialized control domain.

Qualification must cover the90 partial-tail original projections, physical
extension padding, queued/held extension conflicts, publication mirror conflicts,
wrap, simultaneous producer/consumer ownership, allocation denial, partial ledger
fault injection, stale/foreign/moved/lost tokens, stop/drain and outliving views,
under GCC and the actual bundled UCRT LLVM compiler. These checks do not replace
future complete Source2/header/loop/workspace/PCM transaction parity.
