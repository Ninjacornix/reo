# Phased native finite-player contract

This composes the actual qualified Source2/WindowR2, playback control, live clock
and synchronous stereo output-copy binding behind the original-qualified group
dispatcher. The initial profile is finite File1 tag0, mono/stereo, ordinary pan,
24/44.1/48kHz and no seamless/downmix/pitch/loop control. Unsupported headers
refuse before output configuration. It is not a complete guest ADXT ABI.

Source polling remains an explicit separate control operation. The group's
decoder visit services the actual window once. A player visit reads phase once;
ready configures the real decoder/output but does not also run buffering in
that visit. Buffering/playing/draining invoke the unchanged playback controller
without hidden source polling, decoding or PCM pumping. All players finish
their control visits before any transfer work.

The RNA visit primes a configured, initially empty native producer. The DTR
child then runs the already qualified atomic planar copy and returns actual
decoder credit only after the synchronous output-copy fence. This is an
explicit native replacement for hardware transport: one mono/stereo producer
transaction, not a claim to reproduce original per-channel DMA/RPC spans or
device-completion messages. No transfer runs before priming or after transfer
closure. A DTX service visit does not consume PCM or advance a device clock.

Four separately retained ports bind one native player into decoder, stream,
RNA and DTR tables. Their indices are explicit and independent; no guest-array
index correspondence is inferred. Port construction allocates before table
publication. Every port strongly retains its actual player, preventing dangling
control callbacks after the caller drops its reference. Ports must be removed
on the control owner before final ordinary retirement/reuse. Stopping a player
closes all its ports; it never resets or joins the shared output provider.

Per-player phase methods and clocks use the same serialized control owner and
busy guard. The caller supplies an original-unit tick; service visits are not
ticks. The real shared clock service word belongs to the outer group. The
currently unowned discard/global-service branch continues to refuse until a
service coordinator owns its complete callback/identity/lifetime boundary.

Finite native sources retain complete immutable views with known byte extent.
Header/sample-limit ownership closes decoding in the qualified finite profile;
native input/error tails expose its actual fault state rather than fabricated
guest file/RPC state. General ADXF/LSC EOF/error continuation, loop/seamless,
bank/packet mixing and movie consumers remain separate. These ports are not
evidence that opaque original child protocols have become native.

Actual source reads stay on the real bounded worker. The audio callback retains
only shared output state. No resource I/O, decompression, player alias, join or
global scheduling runs on that callback. Output retirement fences only this
producer; source retirement joins its actual worker afterward. Other players
and the shared provider remain live.
