# ADXT buffering and drain control boundary

This cut reconstructs `1343B8..1347F8`, with actual decoder getters, RNA
sample-count getters and play/transfer/through setters. It does not reconstruct
DTR DMA or an audio device. The independent original-word harness executes the
real SJRB operations; its only external transport assumption is that each
`138BE0` stop has completed. The native output port must supply an actual fence
or return pending. A request flag never proves completion.

The bounded native domain has one or two matching PCM channels, even byte
queues, request sizes 1..8192 samples, positive block sizes 1..8192, and one
serialized control owner. Output counts are samples per channel in 0..8192.
All native ownership remains separate from a game frame or device clock.

Buffering starts when queued output reaches twice the request, output free
space is no greater than one decoder block, or the decoder has ended. Start
inhibition suppresses the phase/play transition but still sets the original
started byte: the branch at134438 goes directly to its store at134478. This
byte is not proof that playback began. Paused start still enters playing and
sets started, but leaves play and clock origins unchanged. Otherwise play is
enabled, estimate base becomes zero, and tick base records the supplied original
tick. Ended buffering also appends up to request * channels silence samples
**per channel**, independently of inhibition/start. This is not drain padding.

Playing enters draining only when the decoder has ended and every channel has
fewer than 64 queued bytes. It resets the drain-padding word. Draining appends
a common bounded zero prefix of up to one request per channel, then compares
max(PCM data samples) + output queued samples - accumulated padding, with
original modulo-32-bit word arithmetic and signed comparison. A positive result
remains draining. Otherwise transfer stop, play off and through on precede ended.

Pending native transfer stop retains the draining phase and retries the actual
stop without publishing more padding. Port failures retain effects and fault
the controller; there is no original-call fallback or replay after failure.
Reentry refuses. A PCM busy result before effects may retry; a busy result after
starting playback retains a fault because the original transaction has already
changed observable state. The two prepared flag setters are not the full ADXT
pause/clock API.

The concrete StorePcm bridge uses the unchanged phased PCM owner. It reserves
all free credit, stages a bounded zero prefix, publishes it and restores its
unused suffix. Intermediate reservation sizes/guard observations differ from
the original capped Get. Final queue positions, all four traffic totals and
every physical backing byte are comparison targets, without a byte mask. Failed
transactions retain their actual token. Active read leases refuse padding.
Uneven-channel original observations remain recorded; this bridge cannot create
or admit those states.

This is a complete playback-control cut with a real PCM storage bridge, not a
complete compressed player. The existing Window2 keeps its PCM owner private.
A reviewed composition must connect silence and output copy/consumption credits
without exposing an independently mutable alias. LSC source replacement, native
output routing, full pause/clock integration and game/device validation remain.
