# Bounded native audio-control observations

V28 measures 120,448 source-underrun frames despite regular native movie
publications. Its final totals cannot locate those underruns in time or identify
the responsible source. This optional trace supplies the next missing evidence;
it is not a fix or a retrospective diagnosis of V28.

`REO_NATIVE_ADXT_TRACE_FILE` enables at most 32,768 controller snapshots in the
ordinary native ADX adapter. Each service visit reuses the snapshot already
obtained for native clock publication. A steady-clock interval brackets that
snapshot. Records include the game tick, output/signal/underrun counters, and
each active native stream's slot/generation, queue depths, playing/draining
state, late/skipped samples, volume, gain and frequency. Native stream slots
correspond to the adapter's admitted ADXT stream domain; they must not be
confused with file-descriptor or raw PCM traversal slots.

Storage is reserved before gameplay. Recording copies value records under the
existing serialized canonical controller admission. It adds no output-callback
instrumentation, file writes, allocations, guest writes or source scheduling
policy. Full storage drops observations and increments an explicit counter.
The default remains off.

A separate export worker registers after the source/output workers. Export
requires the source owner to have joined, which closes and drains accepted
controller writers. It reads only retained native snapshots, never game RAM.
Output creation is exclusive: an existing report is preserved. Allocation,
registration and export failures produce diagnostics rather than stopping the
game or claiming successful capture. The explicit launcher diagnostic route
selects `native-audio-control.csv`; normal launches do not enable this trace.

Both compilers pass 78 native suites, 27 adapter scenarios and ten injected
fault checks. The added cases exercise real worker/control shutdown with guest
RAM protected `PAGE_NOACCESS`, bounded storage (32,768 retained, two dropped),
prior-file preservation and refusal before join. Parsed CSV fixtures verify all
18 columns and retained queue/underrun/late-sample values. The changed adapter
also compiles against actual audited SDK131 headers with LLVM. No game or
audio device runs in these checks.

Evidence identities are recorded in
`tools/native_reconstruction/audio_control_trace_qualification.json`.
The fresh native source cohort is
`tools/native_reconstruction/native_audio_trace_manifest_v1.json`.
Actual game capture remains required. Controller observations bound an interval;
they do not timestamp an individual output callback or establish whether missing
service, source work or host scheduling caused a shortage. Correlate with native
movie delivery and retained per-stream state before proposing a controlled fix.
Step 3 remains open.

The version-2 extension (`control_snapshots=2`) adds timestamped native source
state: encoded ring availability/capacity, in-flight request ID, sector/byte
progress, decoded samples and copied samples. Existing source inspection already
obtains these values. Copies remain under canonical controller admission; a
generation mismatch exports unknown source detail rather than another source's
cached state. The analyzer accepts both versions and retains source timestamps.
Five focused diagnostic/lifetime cases pass on each compiler, including stale
generation refusal; an actual SDK131 object check and eight analyzer tests pass.
These are additional focused checks, not a second claim of the complete earlier
regression suite. See `audio_control_trace_v2_qualification.json`.
