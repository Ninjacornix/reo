# Regular file-loop player profile

This extends the actual phased player/control owner to regular ADX file loops.
It does not enable seamless/header concatenation or LSC. The decoder's original-
qualified first-snapshot/repeat and source-rewind policies remain unchanged.
Runtime loop control is a serialized boolean source flag, distinct from header
loop metadata. A finite header does not become a repeating file merely because
the caller sets that flag.

The positive header profile requires enabled halfword1, a positive sample span
within the declared total, block-aligned start sample, sector-aligned start byte,
and exact encoded geometry: start=headerBytes+(startSample/32)*18*channels;
end=headerBytes+ceil(endSample/32)*18*channels. The end lies within the actual
retained source extent. Its rounded target sector must still be ahead of the
actual source progress when ready is configured. A late/already-passed target
refuses before configuration; no rewind, fabricated prefix or synthetic padding
is used to conceal that unsupported layout. All89 owned loop references meet
the static geometry profile; live target admission remains measured per player.

The original first/repeat callbacks set decoder per-span progress/position via
`12D758`(+40), `12D768`(+44) and `12D6E8`(+34). They do not reset the cumulative
decoded word+2C read by `12D6E0`. Regular-loop clock observation therefore keeps
that actual cumulative counter and offset0. The main A4 accumulation belongs
to the separate seamless restart at `133D10`; it is not invented for every loop.
Existing signed counter/extent admission limits remain in force.

The controller stays active while the real source repeats. Whole-session output
is not reset, restarted or reconfigured per cycle. Turning the runtime flag off
uses the retained source's actual target callback to remove limits; it does not
reset predictor/PCM state or synthesize EOF. Native retire remains a separate
per-stream fence/join operation.

Qualification must run the actual private owner and output-copy pipeline through
two complete cycles of each distinct owned loop payload. A verification-only
post-acceptance observer hashes raw copied PCM at sample boundaries: skip the
intro, then measure the two declared loop spans. Those complete hashes/counts
must match the previous independently qualified decoder cycles. Partial later
cycle bytes and iteration/service counts remain explicit variable observations.
No callback invocation count substitutes for copied samples or completion.

The observer belongs only to derived verification sources. Production copying
has no new callback. Source bytes, crypto/predictor behavior, queue credits and
provider/source fences remain actual. Model buffered consumption is not audible
or real-time proof. Game selection, bank/packet output, LSC/seamless, movies and
controlled media transitions remain required before stage3 can complete.
