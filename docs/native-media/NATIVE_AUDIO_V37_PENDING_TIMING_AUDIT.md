# V37 pending-state freshness audit and timing correction

The two long V37 native-source pending spans are supported by **distinct, fresh
source observations**, rather than repeated cached source rows. The separate
V38 cold-case cache observation does not invalidate this V37 evidence. The old
reported durations nevertheless used controller timestamps and overstate strict
source-timestamp spans by **1.2 and 0.6 microseconds**, respectively. The corrected
source spans are **1,466.9548 ms** and **2,199.9560 ms**.

This is a statement about the native source retaining an outstanding request
without publishing new encoded bytes. Neither span measures an operating-system
read's execution time or proves that a backend task remained unready throughout.
The [original incident document](NATIVE_AUDIO_V37_INPUT_INCIDENT.md), its
qualification and original analysis remain unchanged. This
[new qualification](../../tools/native_reconstruction/native_audio_v37_pending_timing_audit_qualification.json)
records the precision correction and the source-cache limitation explicitly.

## Why controller rows can repeat cached source state

In the sealed V37 `ordinary_runtime.cpp`, `AudioTrace::observe` (line 80) copies
a source inspection and stamps `source_observed_ns`. `AudioTrace::record` (line
87) independently copies the last cached `sources` array beside the current
output/controller snapshot. Export at lines 100–104 requires matching source
generation and a nonzero source timestamp, but imposes **no freshness age limit**.
`source_known=1` therefore does not by itself establish a new inspection.

`Binding::inspect` (line 202) obtains the source through the canonical native
owner before updating that cache. The inspection chain is:

`Instances::inspect` (134) → `Session::inspect` (150) →
`Player::snapshot` (293) → `StreamWindowOwner::snapshot` (76) →
`SharedEncodedSource::snapshot` (106).

The last step reads the current native source state/ring; it is not another
timestamped telemetry cache. An active source inspection is distinct from the
later cached copy into the CSV. All eight inspected implementation files are
bound to the actual V37 input-kit manifest and package in the new qualification.

## Actual V37 request observations

Session: `20261109-051101-488`, native slot 0/generation 3.

| Request | Rows / distinct source timestamps | Controller minus source age | Correct source-timestamp span | Old controller-endpoint span |
| --- | ---: | ---: | ---: | ---: |
| 50,826 | **89 / 89** | 300–2,300 ns | **1,466.9548 ms** | 1,466.9560 ms |
| 50,828 | **133 / 133** | 200–1,600 ns | **2,199.9560 ms** | 2,199.9566 ms |

All timestamps increase strictly, all rows retain `source_known=1` and
`source_in_flight=1`, and each request's cumulative published-byte counter stays
fixed. The maximum gap between distinct source observations is 17.4998 ms for
50,826 and 17.6171 ms for 50,828. These spans contain **no repeated source-cache
timestamps**.

The exact source endpoints are:

- 50,826: `292675756167200..292677223122000` ns. Encoded bytes fall from
  51,824 to 20 while published bytes remain 9,408,512.
- 50,828: `292677256280200..292679456236200` ns. Encoded bytes fall from
  12,924 to zero while published bytes remain 9,437,184.

Across the aggregate shortage interval, all **155 affected-source rows have 155
distinct source timestamps**, with maximum source age 1,600 ns. The original
aggregate result remains 107,328 underrun frames in 134 increase windows over
23,919 deduplicated controller observations, with zero drops, invalid rows or
counter/time resets. Empty encoded/PCM queues, stalled decoded/copied progress
and late/skipped catch-up remain measured evidence.

## What the pending field does and does not prove

`SharedEncodedSource::service` (line 233) polls its backend and leaves the native
request outstanding on `pending`/`idle`; successful completion clears it while
publishing bytes. Its request ID is monotonic within that source. In V37,
`AsyncBackend::poll` (45) maps `AsyncReadOwner::poll` to this completion protocol.
The asynchronous owner's internal task phases are not exported in this CSV.

A **freshly inspected native outstanding request** is therefore a valid
completion/publication boundary observation. It cannot identify time spent in
the read queue, provider/file lock, file call, OS scheduling, result publication
or delay before native code next polls/consumes an already-ready result. There
is no per-request task-start/read-end trace here. Source inspection timestamps
are not per-poll timestamps. The original wording “source polling continues”
must be read with that distinction: continuing source inspection is directly
measured; individual backend poll timing is not.

Analyses of other incidents must check timestamp freshness and deduplicate
`source_observed_ns` before inferring source-state spans. Repeating a cached
pending row extends the CSV/controller observation period, not the measured
source pending period. A freshness check is required even when drops are zero.

The bounded resident preparation/refill design removes future file/read-worker
waits for prepared admitted sources, independently demonstrated by the controlled
blocked-provider component tests. Actual V38 acceptance results are separate
evidence. This audit does not prove the historical physical cause, attribute a
same-build causal benefit specifically to residency, reopen a mandatory game
test gate, or declare Step 3 complete.
