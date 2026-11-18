# Compressed players using shared native output

One player owns one actual Source2/Window2-R2/PCM/control graph and consumes one
exclusive producer from the shared output session. Rendering holds only shared
output state and never a player/source/decoder alias. Control and shared key
contexts remain externally serialized; source workers publish private results.

The admitted decoder domain remains tag0, mono/stereo,24/44.1/48kHz, zero pitch
and neutral mono/hard-left/right stereo routing. LSC/seamless, downmix, complete
pause/clock APIs and runtime selection remain outside this version. The output
session's actual start/readiness and final provider join belong to the caller.
Service calls are not game updates or audio frames; ticks are supplied explicitly.

Construction consumes a fresh producer with matching channels, no queued data
and no playing voice. It keeps that producer outside the decoder state until
decoder construction succeeds. Allocation/validation/construction failure
explicitly retires the consumed producer, preventing silent slot orphaning.
An input producer transferred into this constructor is not returned on failure.

Source service, decoder service, one-time ready configuration, bounded PCM copy
and one playback-state service preserve the prior composition's order. The
player copies real PCM read leases into fixed staging, accepts the complete
channel batch in the shared session, then returns decoder credit. Failure after
borrowing retains that real lease and mutes only this producer. An accepted
output copy and consumed/presented samples remain distinct observations.

Per-stream retirement first executes the shared producer's actual synchronous
copy/render fence. Only afterward does it return held decoder credit, explicitly
cut queued PCM, stop decoding and join its actual source worker. A blocked
source remains pending while the output producer is retired and peers continue
rendering. No per-stream path can access the shared provider's join/reset API.
Natural completion leaves padding; explicit manual stop cuts remaining audio.

The order coordinator receives a const producer identity, not mutable output
operations. The caller supplies actual reconstructed summation order when the
session requires it. A player does not manufacture a private device callback
slot or open a separate provider. Whole-session closure can retire all output
records before their source players finish; each player then joins its own
source without treating shared output closure as a source fence.

Qualification requires finite/short-tail/rate/channel cases, actual output-copy
refusal retaining its decoder lease, constructor rollback, peer survival and a
blocked actual source whose peer continues rendering. An additional fixture
must combine two actual native decoder workers with the actual native stream
provider/static slot and reviewed raylib functions using declared model device
primitives. Actual-device, original scheduling/whole-player parity, bank output
and packaged-game selection remain separate.

The actual-asset cohort reuses one output session across every finite payload,
checking copied sample counts/digests against the independently qualified native
decoder. Per-resource source joins and producer retirement are separate from
the one final model-provider detach/stop/unload. Owned ISO views do not satisfy
the final imported-PAK-only requirement; logical source tails remain required.
