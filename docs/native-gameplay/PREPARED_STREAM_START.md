# Prepared stream readiness and start release

The cinematic controller now calls concrete native prepared_ready, release_start
and stop_preserving_state. Their complete original helper policies1AE910,
1AE9A0/1AE740 and1AEB00 execute independently in the comparison. There is no
successful default readiness or start-release provider. Older StreamBackend
implementations return explicit unbound for the three new capabilities.

Readiness first applies the existing feature gate, handles a missing native
instance, then reads the engine prepared/start byte. A zero byte returns1.
Otherwise the real backend reads the canonical source playback.started state,
matching the signed132E20 byte getter for the admitted native0/1 states. A pending
replacement returns0 while the new source is unopened. An independent engine
started_ request bit does not replace the actual source observation.

Start release clears engine start_wait, changes the actual instance's inhibit
through Owner.run and Instances.set_start_inhibit, restores volume from maximum,
then clears the engine started byte. Paused stays unchanged. This differs from
ordinary resume_current, which restores current level and calls native pause.
The complete helper comparison corrected both initial assumptions before the
final source freeze. Preserving stop keeps the whole engine channel record;
it applies the original gate and optional-instance test, then uses the real
native stop/retirement owner. File1 feature helper1B82A0 returns zero and the
reached12A8E8 callback is an audited mechanical return.

Both strict LLVM/GCC helper cohorts pass1,400,838 checks over73,728 cases and
289,647 original calls. Cases vary all three channels, absent/present instances,
signed getter bytes, prepared flags, start-wait/pause state and gain values.
Legacy backends and invalid channels explicitly refuse. Original attenuation
and decoder stop remain declared primitive observations in this focused cut.

Fresh paired real StreamInstances cohorts additionally exercise an owned ADX
through a declared bounded AFS fixture, actual off-controller source loading,
pre-start inhibit inheritance, blocked reentrant owner admission, native playback
readiness, release without unpause, preserving stop and closed/invalid guards.
Both produce real decoded PCM into a device-free submix at the fixed game tick
1000 with zero underruns. Wall-time test service/render counts may differ; neither
background pumping nor native PCM decoding advances the game controller frame.

[The qualification seal](../../tools/native_reconstruction/native_prepared_stream_qualification_v1.json)
retains complete word audits, source identities, both helper receipts, both real
instance receipts and the current paired controller integration. The later
[scene voice preparation qualification](SCENE_VOICE_PREPARATION.md) adds the
complete single-cue/playlist policies and actual two-source native Queue/Loader
path. Movie engine lifecycle, scene entry and installation still require their
actual native owners; Stage4 is open.
