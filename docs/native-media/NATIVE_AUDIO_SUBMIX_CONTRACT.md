# Native players in an externally owned output callback

The native output/control/instance owners now have an explicit device-free
composition constructor. It retains the same private player, queue, clock and
service implementation, but exposes a render-only `Submix` lease. It opens no
audio provider. Calling start admits that private submix; it does not attest to
an actual device or callback binding.

The lease adds private stream PCM to the outer owner's existing stereo buffer.
Its scratch space is bounded and allocated during construction. Stereo copies,
rendering, per-stream retirement and whole private shutdown use the same data
mutex. A whole private join closes admission and fences in-flight private PCM
access before clearing the core. A retained lease can outlive the control owner;
closed calls preserve the outer buffer and cannot access cleared PCM state.

This private fence is reported separately from device retirement. External mode
never claims `provider_joined`. The outer owner remains responsible for actual
callback attachment, its existing PCM consumers, bank rendering, master gain
and the real device stop/join. Native submix construction rejects a bank mixer
because those tails belong to that outer callback exactly once.

This boundary permits one canonical native Session for migrated streams without
opening a second audio device. It does not authorize a second producer for the
same stream. A game binding must stop original decoding/queue publication for
each migrated consumer, retain exact mixed-source ordering and establish which
remaining legacy PCM voices can be active. It must bind the render lease into
the actual callback and qualify provider/source/output shutdown order.

Required checks include bit-identical private PCM against the ordinary output
path before adding the same prior stereo mix, peer output after individual
retirement, real mono/stereo source workers through the instance owner, no
claimed external device fence, and safe retained callbacks after private owner
destruction. A model caller is not proof of actual callback integration or A/V
equivalence. Game consumers and the coherent backend remain stage-3 work.

The output configuration can retain a pure, bounded `StreamGains` provider.
Each producer carries an opaque route key chosen by its controller, rather
than a guest pointer. The actual rendering call refreshes factors for all
active native streams. Every finite factor and combined native/host gain must
be within the qualified PCM range [0,8]; all factors are checked before any
voice changes or samples are consumed. A failure closes private admission and
records a render fault. The external submix preserves the complete prior
buffer; the ordinary standalone renderer returns silence. Neither blocks on
guest service, allocates nor invokes the controller. The provider must not
reenter these owners or perform I/O, and lives at least as long as the render
lease. Outer settings polling and the bank/master tails retain their owners.

Guest volume uses a separate unsigned integer control, forwarded through the
player, Session and stable instance. It preserves the PCM expression
`min(volume,256)/256.0f/32768.0f * gain`; converting it into a second float gain
would change rounding. Raw values above 256 remain observable and clamp only
for rendering, matching the existing core. Volume latches while an instance
is idle or retiring and applies before its replacement is serviced. Destroy
and recreate resets it to 256, while stale keys cannot change the new voice.
Producer reuse also resets the scalar gain and binds the new opaque key.
This is a qualified control boundary, not proof of a live guest API binding.
