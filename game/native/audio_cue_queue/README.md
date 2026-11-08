# Native audio cue controller

`Queue` binds once to a stable native audio instance. It takes immutable resource
views and native cue IDs, prepares headers on a shared bounded loader, and feeds
ready clips to the native queued player. Accepted next clips hold its header
boundary while preparation is pending. No guest addresses, original LSC objects,
emulated registers, RPC, or original file producers are part of this controller.

Operations run inside the same serialized native instance-owner borrow as its
player. The controller never waits for a source read or joins a worker there.
Stop cancels preparation tickets and requests actual source retirement; a pending
retirement remains explicit. A replacement stays pending until the old read and
output fences complete. Close/stop before destroying the controller; its bound
instance owner remains responsible for final source join. The shared loader is
closed/joined only after all accepted controller operations have drained.

The queue holds at most 16 outstanding cues. Preparation errors, incompatible
channels/rates and unsupported clip headers remain errors. An invalid preload
does not stop an existing ordinary source that this controller has not submitted.
Playback repeat is explicit queue control, separate from embedded ADX loop
metadata. The latter remains outside this finite-clip profile.
The stable instance's ordinary inline-loop preference is retained across finite
playlist playback. It does not turn a finite queue into an infinite stream;
returning to an ordinary source reapplies that preference.

The game adapter resolves checked File #1 AFS descriptors into native retained
extents and binds enqueue/start/count/repeat/reset/stop to this controller. The
temporary game ABI is an adapter, not the controller's data model. Its independent
header-worker finalizer follows canonical source/device teardown and never reads
game RAM. Selection and live game validation remain separate gates from the
standalone native and declared-port tests.
