# Canonical native serviced-clock binding

The private control session binds its retained actual clock, group and target
player to the qualified serviced-discard completion. A caller supplies only its
session/generation key and original-unit tick. It cannot substitute a service
port, player, shared clock, queue observation or busy word.

Paused-zero calls retain the existing prepared no-service behavior. Paused
nonzero calls first admit the current mix membership, create the entire retained
port before effects, and invoke the completion. The port runs the actual private
group once with supplied tick values and then captures the actual target stream
and queue state. It deliberately performs no source poll: original `133058`
calls the group, while file service is elsewhere. Decoder/RNA/transfer visits
can progress; their actual source worker remains separately owned.

The outer session call excludes registration/retirement and external control
reentry. The target player's per-method busy flag is not held across group
service, so its real children can run. The completion's shared in_call guard
refuses recursive clock queries. Successful completion publishes into that same
actual player's canonical clock and synchronizes its playback origins. Failure
retains real group effects without publishing an invented baseline.

The service port strongly retains its actual target and is scoped to the owning
session call. Its clock identity is the same retained object used to construct
the private group and every player. The private player publication method is
callable only by the control session. Metadata matching is backed by this concrete
construction/lifetime path, not used as a substitute for it.

Group visits and discard diagnostics are explicit report counters, not device
frames, game ticks or performance measurements. Other player faults do not
invent an early exit from the original group sequence. An actual target fault,
invalid post-service observation or FP refusal remains an explicit failure.
The raw phased-player API without this owner keeps its unowned branch refusal.

Qualification must include actual decoder/source workers, unchanged source-poll
counts during discard, canonical clock publication, peer survival, pre-header
and nonboolean paused state, and a declared external model callback between group
completion and queue capture. Original replay of measured queues is evidence at
that observation cut; it does not execute or prove original individual decoder/
DMA/RPC children. No default game selector, speed or experimental path changes.
