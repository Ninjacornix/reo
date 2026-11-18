# Owned LSC filename queue and control

Status: contract before native implementation. The original-word corpus froze
53 cases /339 operations before the native queue existed. It executes enqueue,
clear, start/stop, flags, queries, thresholds, poll, retirement and head service.
Lower file operations, strlen, diagnostics and the notification dispatch are
explicit external boundaries. This is not a claim about file I/O or a complete
audio/movie consumer.

The native core owns sixteen records, ring indices, count and source-control
state. Each filename is a retained immutable bounded byte string; no borrowed
filename may change underneath the checksum. A retained range descriptor is
metadata, not permission to read a file. Resource identity and actual segment
worker lifetime must be supplied by the later source owner.

Preserve the original sequence allocation from the preceding physical slot,
including INT_MAX to zero wrap, stale-slot query order, byte-sum checksum,
three unchanged range parameters and exact status/progress units. Clearing the
stopped queue resets indices/count, not all record contents. Starting an active
queue first stops it and discards its pending entries; stopped queued entries
survive an inactive stop. Pause admits exactly argument1. Repeat stores the low
byte and retirement repeats only signed byte1.

Service admits once for pause!=1, state2 and positive count. It polls head status1,
reloads the head, retires status2, reloads the head again and starts status0.
It must not turn this into an arbitrary drain loop or restart admission between
those stages. Empty notification occurs before state becomes1. The notification
may enqueue, stop/start, pause, change repeat or withdraw the lower handle.
Capture the retiring descriptor only if repeat was1 before notification; reload
repeat afterward. Enabling repeat during a callback without a captured descriptor
does not invent one. Current source admission must be explicit at that boundary.

The lower port receives the original ordered stop/close/open-range/limit/
threshold/position/start requests. Poll status2 publishes measured lower progress;
status3 publishes the configured sector limit and completion status2; status4
sets input state3. These are separate from decoder, output and game clocks.
Port methods do not reenter the queue. All calls require external serialization.
Reentrant service itself refuses; supported notification mutations remain usable.

Construction allocates bounded metadata. Enqueue accepts a prepared immutable
name, and ordinary service/repeat need no allocation. A private state copy is
available for evidence; no mutable slot/name alias escapes. The global notification
relationship is supplied through a shared retained notification port, not a hidden
per-player replacement for the original module callback.

Independent native comparisons must reproduce all admitted original control
projections, callback ordering, lower requests and stale-slot observations. Also
check bounded names, full queues, record retention and callback service reentry.
Unsafe borrowed-name mutation, corrupt indices/counts and unowned file workers
are outside admission. Actual retained segment reads, asynchronous retirement,
seamless decoder transitions and consumer integration remain stage3 work.
