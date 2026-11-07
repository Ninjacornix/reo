# Stable ADXT instances and replaceable native sources

The native `adxt_instances::Instances` facade owns one canonical control/output
Session and up to sixteen stable instance records. It separates construction
from source start, and instance lifetime from file/sequence/LSC source lifetime.
This is a native ownership API, not an implemented general guest ADXT ABI.

Construction reserves each instance's decoder, stream, RNA and transfer indices
even while idle. An opaque key binds owner, slot and incarnation; destruction
invalidates it before the slot can address a later instance. No underlying
Session key or mutable player/clock/output object escapes.

A start either opens an actual native player or retains one unopened replacement
until the old source and output retire. A newer start replaces that unopened
request, with no worker or decoder side effect for the superseded source. Stop
cancels a pending replacement but preserves the instance and peers. Destroy
also releases its indices after retirement. Failed joins retain their state;
there is no timeout-based resource reuse or legacy fallback after effects.
An explicit whole-session stop/join is separate from individual stop/destroy.

Gain and pause may latch while idle or retiring and apply to the next source.
Queries and controls for an active source use that same canonical Session.
More than two prospective active sources requires an explicit permutation of
all constructed keys, including idle instances; the facade projects the active
sources into the real output order. No order is inferred from slot numbers.
Retirement can progress without a new mix order when it leaves at most two
prospective sources. Clock ticks come only from the caller's original-unit
argument, never from source pumping or callback counts.

All control methods require one serialized control owner. Rendering remains
inside the underlying output owner and retains its own state. The facade does
not construct a second output session per source, reset peer banks, or expose
resources to a device callback. Its statuses describe this native API, not
invented original error-code or public-handle parity.

Qualification must cover actual source workers, pause/gain before header,
stop/restart with a stable instance, stale-key rejection after slot reuse,
required three-source order, peer rendering during a blocked source's stop,
and replacement supersession before the old worker joins. The output provider
in these isolated tests is an explicit callback/fence model, not a real device.
The parent source/decoder/control implementations retain their existing
independent original comparisons. Game ABI/source/control consumers, full
live output and A/V validation remain separate stage-3 gates.
