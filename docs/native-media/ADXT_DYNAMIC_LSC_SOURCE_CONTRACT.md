# Dynamic LSC encoded-source ownership

Status: implemented bounded live queued source, undergoing final ownership and
regression qualification. It runs through the real native read worker, encoded
ring, decoder, player and shared output owner. No production game selection or
audible device test is claimed. The original-qualified LSC core remains the
queue authority; this new transport is an explicit native replacement boundary.

Use one existing owned encoded ring through the complete source/decoder graph.
Do not reset that ring or publish into a new incarnation while a worker still
owns a request. Live filenames are sealed prepared-asset keys, never permission
to reopen an arbitrary path. A bounded immutable catalogue maps admitted name
and range metadata to independently validated retained clip views. Legacy LSC
sequence IDs remain metadata queries, not resource capabilities.

An append-only native origin defines a fixed bounded virtual byte domain. Its
size is an address budget, explicitly distinct from a physical file length or
currently readable extent. Committed ranges retain actual immutable assets;
unavailable ranges are never fabricated as zero bytes. Only its exclusive native
backend may translate an admitted request into a private immutable read snapshot.
The old file/loop source profile must remain distinct from this transport.

The backend checks exact origin identity, source offset, available published
mapping and one pending request before I/O. It can accept a positive sector
prefix ending at the active clip's actual extent, or decline unavailable work
without an error. Each accepted request retains its exact underlying view/range
until the real worker finishes. The worker sees that immutable snapshot only,
not the mutable queue, journal, decoder or ring. Completion returns bytes to the
existing source owner's ordinary accepted-prefix publication path.

An actual backend completion is not ring publication. Per-file status/progress
and next-file admission must use copied observations from the real private
source after publication. Never advance progress when merely queuing a job,
receiving a callback or obtaining a private completion buffer. The lower LSC
port preserves ordered stop/close/open/limit/threshold/position/start requests.
`130E18` writes capacity/request limit at+14 and minimum threshold at+18; the
native backend must preserve the resulting strict occupied-byte admission.
The queue's completion progress retains its configured sector-limit value,
including the original full-file sentinel; it is not silently replaced with a
physical byte count.

Maintain a bounded journal of admitted clip byte/sample boundaries. Retire a
journal entry only after actual encoded consumption and decoder transition
observations no longer need it, while outstanding read snapshots retain their
own providers. No mutable source/decoder alias or caller-supplied progress value
may update that ledger. Append, decode lookahead, queue service and output-copy
phases remain externally serialized; workers and rendering use private retained
state. A one-use binding prevents two players from owning the same live input.

Before a seamless transition, distinguish a pending queued next header from a
confirmed empty/completed source. Wait for actual publication when more source
work remains. Once the admitted source is complete and the queue has no next
entry, execute the original end-record/search/termination path. Late restart,
stop/close replacement and general error continuation require their own explicit
incarnation/consumer admission; none is inferred from an empty queue alone.

Normal stop must preserve the established accepted-work disposition. Per-player
output retirement fences copying before decoder/source shutdown, and the actual
worker joins before ordinary source retirement succeeds. A blocked or failed
join retains the graph and reports pending/error. Destructor emergency cleanup
is separate. Private read snapshots cannot publish into a later source epoch.

Bound bytes, samples, journal entries, catalogue metadata and outstanding reads
before effects. Current signed source/clock domains remain explicit; numeric
exhaustion refuses without resetting counters or inventing progress. Repeating
LSC names must use the actual exact-one repeat and notification semantics of the
qualified queue, not reuse a decoder's regular file-loop flag.

Required evidence: real blocked/partial/error reads, old-provider retention,
next-header waits, queued/repeated names, sparse/unavailable request refusal,
stale/foreign/duplicate binding controls, actual per-clip waveform/clock checks,
no lost accepted credit, shared-output peer survival and complete worker/output
fences. Preserve original lower-file envelopes as explicit boundaries until their
remaining EOF/error/replacement paths are independently closed. Bank/packet
output, movies, game integration and stages4–6 remain separate requirements.

The default profile uses an8192-byte capacity and6553-byte minimum. An explicit
owned sector profile admits2048..1048576 bytes with a default minimum of eight
tenths of capacity. Source, one-request worker and staging budgets must match.
Explicit original queue minimum controls admit0..capacity for the next lower-file open; signed invalid values diagnose without
changing that queue minimum. An already opened lower file and accepted request
retain their preceding thresholds. Zero preserves strict occupied-byte admission
and therefore admits no refill. Clips must use the sealed non-looping ADX profile,
with matching channels/rate/pan and actual sector-backed tails. The catalogue
contains at most 8192 assets, the queue 16 names, and the journal 2–16 boundaries.
Regular decoder loops remain a separate input mode. Byte/sample exhaustion is
reported before appending; counters never wrap or reset to keep repeating.

Each input has one lifetime and one backend binding. A bound input retires through
its session key so output is fenced before source shutdown. Bare bound stop,
restart, arbitrary threshold changes and recovery after a source error are refused.
Fresh playback requires a fresh input. Queue pause/repeat controls preserve the
original exact-one and low-byte rules. Source/LSC service currently precedes the
qualified audio service group; this is not a reconstruction of the complete
original global audio/file/LSC scheduler.
