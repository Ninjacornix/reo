# Native finite media control session

One externally serialized control owner holds the actual phased players, the
five service tables, shared clock/key contexts and one output session. Native
callback rendering retains output state only. This is a finite native-media
profile, not a game adapter, bank/movie owner or general guest ADXT ABI.

Open validates all four explicitly supplied table indices and resource/session
capacity before constructing a player. Every port allocates before publishing
any membership. Occupied indices refuse without replacing a peer. Failures
retire a consumed output producer and retain existing peers unchanged. The
returned key binds session identity, record slot and generation. No mutable
player, output producer, clock, table or source alias escapes.

Service first polls each admitted actual source in record order, then runs the
qualified decoder/player/RNA/DTR/DTX group order with the supplied tick. A source
fault does not prevent peers' service in that pass. Calls do not invent game
ticks or device progress. More than two live streams require an explicit full
key permutation after membership changes; service refuses before polling if it
is missing. The corresponding const producer identities feed the qualified
output owner's mix-order operation.

Retire closes and removes only that key's four ports, fences its output producer,
then joins its actual source. A pending source retains its record and occupied
indices, preventing overlapping reuse. The final copied snapshot preserves the
actual fence evidence. Only completed retirement frees indices and advances the
generation. Old or foreign keys cannot address a replacement. Per-stream retire
does not reset/join the provider or other streams.

Whole-session stop closes new work and all ports. Join retires every source,
retaining pending/error state, before joining the one actual output provider.
Failed provider fences remain retryable. Successful join is idempotent. The
destructor provides the existing emergency control-thread teardown and is not
evidence of ordinary bounded completion. No method belongs on the audio callback.

CRI/RNA/chunk guards retain exact nesting/order under the single serialized
control owner; they are not a claim about original thread-priority scheduling.
Finite native transport uses the already qualified synchronous planar copy;
DTX visits have no device clock effect. The canonical owner supplies the private
[serviced-clock binding](ADXT_SERVICE_BINDING_CONTRACT.md); the raw player API
continues to refuse unowned service. Game selection, bank/packet mixing, complete
loop/LSC/seamless playback, movie consumers and actual media validation remain.
