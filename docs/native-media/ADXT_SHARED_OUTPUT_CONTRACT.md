# Shared native stream output ownership

One session owns one native PCM mixer, actual provider owner and actual stable
callback slot. Up to16 exclusive producers each use one mono/stereo voice and
private8192-sample channels. All backing/PCM handle pools allocate at session
construction. Opening a producer allocates its token before observable effects.
The chosen16-slot bound is an admitted profile, not a whole-game reachability
proof. Device, bank-mixing and original scheduling qualification remain separate.

The supplied slot must be the provider's actual slot. In the existing runtime,
`native_stream_callback_slot()` has static process lifetime and is required by
`NativeStreamProvider`. Passing a shared reference to a private substitute does
not satisfy that provider. The renderer strongly retains session state and slot;
the published slot retains the audio Owner. Failed provider fences retain the
registered graph. Successful join removes publication and breaks this retention.

Every producer has a private slot/generation capability. No PCM channel/voice
handle or independently mutable mixer escapes. Copy admits a complete planar
batch in64-byte quanta under the same outer mutex used by rendering. Every
channel/counter/capacity preflight precedes the first enqueue; frame-clock mode
does not advance during copy. An unexpected partial failure mutes/faults the
affected producer before unlocking. The caller explicitly returns decoder
credit after a completed copy. This component cannot certify a source lease.

Per-producer stop-transfer fences synchronous accepted copies. Per-producer
retire disables/releases that voice, cuts its channels and resets its DSP
incarnation, under the render mutex. Other producers' queues, voices, relative
mix order and provider remain live. Slots reuse only after explicit retirement;
old generations cannot copy/play into replacements. Producer snapshots retain
pre-clear evidence. Stream-relative byte counts subtract their captured channel
origins; absolute PCM counter budgets remain session-wide across reuse.
Destroying an unretired producer does not silently recycle its record. Its
orphaned bounded record remains observable until whole-session join.

More than two playing producers require an explicit full active-producer order.
The private PCM permutation includes inactive reserved voices too. Retire/reopen
rebuilds that permutation before unlocking, preserving current peers' order;
new membership requires a fresh explicit order before a third voice starts.
The order comes from the caller's reconstructed mix traversal, not slot number
or a presumed original map order. Finite gains use the unchanged PCM algorithm.
Order selection accepts only const producer identities; a player need not expose
mutable producer operations to the session's order coordinator.

The callback holds only the session state and never a decoder/player alias. No
allocation, I/O, provider call, guest call or control reentry belongs inside
render. The outer/session mutex always precedes the PCM core's mutex. Provider
detach/stop/unload/join run outside both. A renderer preflight failure records
its actual core status, closes admission and outputs silence without claiming
that queued input was consumed.

Whole-session stop closes new producer/copy admission. Actual provider join
must succeed before clearing any live queue or resetting PCM. Failed provider
steps preserve all state for retry. Joining a session is separate from stopping
a particular producer and from joining a compressed source worker. This core
does not install a runtime adapter, start a game, open a device, replace the
existing bank aggregate, or qualify a full native ADXT player.

Qualification includes exact mixed float words against the unchanged PCM core,
an order-sensitive cancellation case, per-stream peer survival, stale generation
refusal, counter/capacity admission, pending provider fence, orphan detection,
concurrent stereo copies/render and explicit renderer failures. An additional
fixture links the actual NativeStreamProvider to its actual static slot and
hash-qualified raylib source functions with model device primitives. That fixture
does not establish actual-device output or a matching packaged runtime binary.
