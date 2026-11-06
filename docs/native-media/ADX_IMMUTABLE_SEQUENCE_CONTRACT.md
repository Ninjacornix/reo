# Immutable ADX sequences and seamless playback

Status: contract before implementation. This closes a bounded same-source
seamless profile; it is separate from live LSC queue insertion and replacement.
No game path is selected by preparing a sequence.

Prepare two to sixteen retained immutable sector-backed ByteViews. Freeze their
order and offsets, without copying payloads, reopening paths or manufacturing
sector padding. Before admission, parse each real header with the qualified
header core, check the actual end record and require zero trailing sector bytes.
All clips must share admitted channel count, rate, zero pitch and the existing
neutral/hard-left-right pan profile. Regular loop metadata is excluded. Header
size is at most2048 bytes, so a sector-aligned clip header fits a single actual
encoded-ring grant including its physical extension. Total bytes and cumulative
samples must remain in the existing signed counter domain.

The prepared object itself is the immutable sequence view. A player can enable
seamless mode only with this sealed preparation, the exact same view identity,
matching channels and default bounded source geometry. Raw arbitrary views with
the seamless flag remain refused. The preparation is not file-read authority:
backing views and their identity/immutability contract still come from resources.

Before crossing a known clip boundary, wait for the actual published source
counter to cover the entire next header. Do not interpret an unfinished async
read as absence of a next file, skip the header search, manufacture a prefix or
perform hidden source I/O in the decoder pass. Source polling remains explicit.
The existing owned seamless search, selective reset, history/key parsing and
credit disposition still execute against the real shared encoded ring.

Keep the same output producer, queue and playback origin across clips. Raw clock
observations include the decoder's actual seamless-sample accumulation; neither
rendered frames nor callback counts substitute for that state. Evidence digest
limits must cover the entire prepared sample sequence, without unsigned
underflow when a later clip has a smaller header total.

Qualification must split accepted output copies at declared clip sample
boundaries and compare each complete payload with the earlier finite decoder
baseline. Include partial-block totals, different clip lengths, actual pending
next-header reads, pause/raw clocks, no output reset/reconfiguration, failures
before playback admission, and source/output lifetime fences. Buffered model
output does not establish audible playback or performance. Dynamic LSC segment
ownership, complete bank/movie integration and stages4–6 remain open.
