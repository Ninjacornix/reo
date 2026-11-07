# Native picture timestamp reconstruction

This module reconstructs File #1 temporal/timecode policy from the owned
instructions. It does not use elapsed host time, counted display frames or an
assumed fixed-rate timeline. Rate tables, drop tables and irregular conversion
constants retain the original values. No standards-correction change is mixed
into reconstruction.

`reconcile` joins a valid packet accounting value and a picture temporal reference
in the original 22,500-unit domain. It latches the baseline, compares only the
cached value word, preserves the B-picture initial offset, and carries the prior
maximum reference across explicit discontinuities. Original 32-bit wrapping and
signed clamps remain observable. Invalid table indices refuse before effects.

`publish` joins the original timecode gate, reconstruction, cached-GOP advance,
first baseline and latest/current publication. Missing PES timestamps are valid
inputs. The incoming picture includes the MPV rate code, temporal reference,
coding type, raw GOP timecode and GOP-header count. A packet accounting record
is supplied only when the actual picture prefix falls within a timestamped
payload interval. The packet parser's stored clock is the original packed
33-bit PTS with two low bits discarded, not raw 90 kHz PTS.

The first baseline uses reference zero. Current time can go backwards for a
B-picture while latest time remains unchanged. A GOP-header-count change drives
the original cached-reference-plus-one advance when no new timestamp is present.
Normal timecode conversion, drop reconstruction and drop conversion retain their
distinct arithmetic; the original 59.94 coefficients and literal two-frame
advance adjustment are preserved. No standard SMPTE equivalence is claimed.

The joined profile admits rate codes 1-8, drop values 0/1, no external header
snapshot and fresh native state. Arithmetic reflects finite original inputs;
the software-double rounded conversion has independent owned-word comparisons.
The narrower temporal helper also admits original rate-code zero's denominator
one. Unsupported inputs are explicit refusals, not synthesized timestamps.

The MPEG parser retains sequence rate and raw GOP components for each picture.
Its optional synchronous payload observer reports actual packet identity,
payload extent and timestamps; the legacy constructor leaves that observer off.
The native video graph owns a bounded timestamp ledger, processes proposed
timecode state before enqueue and commits it only after actual decode admission.
Backpressure leaves that state and the compressed picture intact. Native queue
time uses the original published fraction; conversion to the existing bridge's
90 kHz identity field is only a tracking representation. Mid-generation rate
changes require a new timing generation.

Original comparisons qualify numeric policy and state effects. Real-source
parsing, full-stream hardware decode, reordering, audio demux and scheduler/game
binding require their separate receipts. Stage 3 completion is not inferred from
these standalone comparisons.
