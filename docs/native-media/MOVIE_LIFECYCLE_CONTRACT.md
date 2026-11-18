# Native movie lifecycle

The native module separates original numeric orchestration (`Policy`) from
physical resource ownership (`Session`, `PreparedGraph`). Neither API uses guest
RAM, simulated registers or a global display-frame clock. Neither is selected
by the production game. Scheduler/game command binding remains explicit work.

## Original policy

The owned File #1 constructor, registry scan, start, reset, stop/rebuild and
destroy bodies run in the original oracle. Child initialization/cleanup and
installed component methods are declared ports. Real nine-component broadcast
and indexed dispatch bodies execute; only their installed virtual-method targets
are ports. The oracle compares numeric state, 100 current/saved properties,
normalized eight-slot owner identities, callback sequence and callback-entry
state. Guest workspace bytes, pointers, arena alignment and subordinate codecs
are outside this value API.

Creation admits a nonnull source and workspace budget at least 0x2ba0, selects
the first free registry slot, clears values and installs defaults. Stream
construction failure prevents later work. The component initializer status is
ignored, whereas the construction broadcast returns the first component error.
Successful construction publishes actual/requested state 1 only after callbacks.
Native allocations must additionally enforce their own typed bounds.

Start selects request 3 only when property 0x2f is exactly 1; otherwise request 4.
It sets pending without claiming that actual playback has started. Reset invokes
component 7 command 7 only in actual state 4 and propagates its failure before
publishing actual/requested 1. Stop skips reconstruction in actual state 1;
otherwise it resets and rebuilds inside the optional tag-1 hook pair. Reuse is
forced to 1 and then 0, rather than restored to an arbitrary prior value.

Rebuild optionally snapshots component 0 command 9. Its first status is ignored
but the returned snapshot word must actually have been written. Header/source
cleanup precedes destroy command 4, which publishes actual/requested zero before
callbacks. Saved properties are copied after destroy callbacks and restored to
both current and saved arrays after constructor callbacks. The second snapshot
status and command-10 reconciliation status are checked. Snapshot word 0x14 is
opaque; it is not assigned an invented byte-offset or clock interpretation.
Missing/unwritten required snapshots return an undefined native result rather
than manufacturing the original caller's uninitialized stack value.

Destroy deliberately ignores the stop/rebuild result, repeats cleanup/destroy
and removes every matching registry identity. It returns the final destroy
status. This logical policy does not itself prove that workers or GPU readers
have stopped. The native physical layer supplies that stronger lifetime fence.

## Native physical ownership

`Session` owns a retained graph, byte-source recipe and factory. Every successful
construction has a fresh monotonic incarnation and an opaque weak-owner key.
Foreign/stale keys, exhausted generations, callback-time mutation and concurrent
control are refused. Public operations retain the owner through callbacks.

Stop/rebuild immediately closes publication and signals graph stop. Poll retains
the old graph and source until actual source/audio/video retirement succeeds.
Rebuild then constructs the replacement and returns its new key. Partial graph
construction and retirement failures retain their physical obligations for retry;
they do not admit another generation. Destructor cleanup uses explicit STOP
drains. Native physical rebuild is a distinct operation from the original
logical stop policy; their scheduler/command adapter has not been claimed.

`PreparedGraph` composes a bounded positioned `AsyncReadOwner`, native audio
Session stream, shared timing Context and retained video backend. Bytes accepted
by a backend are transferred once; pending feed/end must refuse before effects.
One owned read/output buffer bounds backpressure. An optional audio route takes
an independently demuxed ADX ByteView, indices, shared audio Session and actual
service-tick provider. It does not open or shut down the shared audio device.
The Context begins in actual/requested 1; real scheduler observations must drive
later states. A start request is not fabricated playback progress.

On stop, source shutdown suppresses late publication. A teardown join thread
waits for the actual reader worker, so the graphics/control thread can continue
polling real video fences. A refused join is an error, never completion. Native
audio retirement removes only the movie's stream. Video retirement keeps its
producer/reader obligations. Timing queries detach only after all retirements.
Final STOP drains may block while actual owned source work finishes; they do not
invent cancellation of an active provider read.

The same-device `NativeVideoGraph` uses the existing bounded program/elementary
parser and hardware reference-surface protocol. Reference pictures remain
unpublished until a later reference watermark or genuine EOF allows them.
PTS zero is already ordered at the minimum of the nonnegative prepared domain.
This is reorder admission, separate from the shared playback clock. Every
picture requires observed 90 kHz PTS in the prepared signed-32-bit domain.
Missing/out-of-domain timing, unavailable references and provider failures close
the path rather than synthesize timestamps or switch decoder after effects.
Original IPU thresholds are not inferred: this prepared graph uses explicit
zero thresholds. Future game admission must bind actual controls and timing.

## Limits

The original comparison establishes lifecycle orchestration with declared child
ports; ownership tests separately exercise actual native source/audio/frame
owners. The optional native audio route requires an independently demuxed ADX
view. The existing MPEG parser selects video PES and ignores audio/private PES;
it is not a complete standalone Sofdec audio demuxer. Whole-stream timestamp
reconstruction, codec skip/recovery, logical-to-physical scheduler binding,
game transitions and audible A/V synchronization remain required. Stage 3 is
open, and no compatibility components have been removed.
