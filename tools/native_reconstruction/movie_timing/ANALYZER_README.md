# Analyze completed movie-work evidence

`../analyze_movie_work.py` reads schema1 and schema2 output from the optional movie timing
recorder and a completed `FrameTrace`. It opens no process, runs no game and
does not sample threads or execute a GPU fence.

```powershell
python tools/native_reconstruction/analyze_movie_work.py `
  --session build-native-sjuni/playtests/<completed-private-session>
```

This writes `movie-work-analysis.json` and a short Markdown companion inside the
validated session. It first applies `analyze_sjuni_playtest`'s completed,
single-player owned-process provenance checks, including private executable hash
and process creation identity. `REO_MOVIE_TIMING_FILE` and, when present,
`REO_FRAME_PACING_FILE` must be absolute paths inside that session, without
symlink/junction/reparse traversal. Missing output is reported as unknown; paths
that escape are rejected before file contents are read. Parsed output bytes get
their own lengths and SHA-256s alongside session/run/stderr provenance hashes.

Each appended timing section retains an independent ID, epoch, owner-start time,
line references, all aggregates, valid detail rows, metadata and validation
issues. Unsupported schemas, corrupt rows, incomplete metadata or truncated
tails do not discard later sections. The parser validates known boundary names,
unsigned64 fields, interval arithmetic, retention bound, aggregate consistency,
trailer counts, and saturation/loss metadata. It checks completion timestamp
order within an owner; nested spans can begin earlier than the preceding row.
Owner epochs/times may restart in a later section and are not merged.

Schema1 retains its original first4096/drop-counter interpretation. Schema2
validates the recent4096/longest64 union, positive strictly increasing completion
sequence IDs, retention-source flags, contiguous recent sequence window,
longest-set ranking relative to retained recent rows, unique/missing counts and
separate sequence saturation/exactness metadata. A `recent+longest` event is one
row; duplicate sequence rows are corruption and cannot create extra correlations.
Unknown source rows/flags and corrupt sections retain explicit issues rather
than being counted twice. Correlations carry sequence and retention identity.

`retention_summary` distinguishes declared unique retention, valid rows actually
present in the artifact, and recorder missing count. Partial/corrupt exports can
have fewer valid artifact rows than the recorder declared. Sequence exhaustion
makes missing count unknown; aggregate-sum saturation alone leaves an independent
exact event count intact. Neither an empty recent set nor a filled longest set
establishes that every visible hitch was measured.

`owner_complete=1` only establishes a serialized trailer. The analyzer separately
checks stderr's `exported owner` lines by path, epoch and counters. Repeated
epochs with indistinguishable counters remain ambiguous rather than being
matched by their apparent position. Export failure messages do not contain an
owner ID, so they remain unattributed even if only one file section survived:
another owner's failure may have left no section. Unmatched success receipts,
other-path receipts, malformed diagnostics and failure line references remain
in JSON. A reused path may contain older sections; uncertain receipts do not
make those current-process evidence.

For valid completed frame evidence, the analyzer lists CPU presentation-return
intervals of at least50ms. For every intersecting retained work event, it records
exact nanosecond overlap with that interval and with the interval between its
endpoint capture spans. The join retains section ID, original generation/serial,
CSV lines, integrity and export status. Intervening capture rows are counted;
the area between endpoints must not automatically be called idle/unobserved.
Frame record loss is preserved. A missing or invalid frame file leaves work
evidence intact and correlation unavailable.

An illustrative **synthetic** nested example, with timestamps chosen for a unit
test rather than measured from a game:

| Retained event | Begin ns | End ns | Overlap with return gap12..100000012ns |
| --- | ---: | ---: | ---: |
| Batch fence, generation4/output event8 |20|60000020|60000000ns|
| Enclosing owner control, generation4/serial0 |15|70000015|70000000ns|

The fence row is appended first because it completes first. Both overlaps are
reported separately. They are not added into130ms of responsibility inside the
100ms return interval. Elapsed spans include descheduling; overlap does not prove
that the GPU, decoder, disk or an individual callback caused a hitch. A complete
zero-detail section means no recorded span crossed that recorder's threshold,
not that playback was smooth: queue delays, uninstrumented boundaries, short
repeated polls, dropped/invalid rows or repeated movie pictures remain gaps.

Useful JSON fields are `movie_work.sections[*].integrity/export_status/issues`,
`metadata` (including loss, invalid intervals and saturation), `aggregates`,
`events`, `exporter_log`, `frame_trace`, and `correlation.gaps/overlaps`. Aggregates
remain per owner and boundary; the analyzer never sums nested work or assigns a
root-cause verdict. Valid rows from an invalid/partial section can still be
correlated, with their uncertain section status attached to every join.

```powershell
python -m unittest discover -s tools/native_reconstruction `
  -p test_analyze_movie_work.py -v
```

The lightweight tests cover both schemas, rolling/top union and duplicates,
counter exhaustion, sum saturation with exact missing counts, complete/corrupt/truncated/reset sections, nested
completion ordering, counter/loss/saturation checks, exact and touching overlap,
ambiguous epochs, trailer-with-failed-export, private completed-session admission,
output hashes and missing/invalid evidence. Fixtures are synthetic and never
executed as a game. No new V7 playback measurement is claimed by these tests.
The recorder README separately pins the completed legacy schema1 retention-loss
evidence that motivated schema2; the current sealed V7 binary is unchanged.
