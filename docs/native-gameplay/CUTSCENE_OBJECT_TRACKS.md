# Authored cinematic object streams

Status: component qualification passed on both compilers; not installed.
Step4 remains incomplete.

CutsceneObjectTracks implements5EF120's seven streams over the actual fixed
sixteen-object pool. Each stream processes at most one matching record per tick,
including repeated timestamps and low16 media-frame/half-rate aliases. It advances
exactly one36-byte record and clears the cursor when the next timestamp isFFFF.
Media-event time comes from the caller's native media view; this consumer does not
advance that clock or substitute scene-pose time.

Commands0/1/2/3 now update native pose/activation, semantic visibility, full-word
motion requests and attachments. Kind0 retains a typed copy of the adjacent pose
keys; it does not retain a relocated pointer. Unknown kinds consume the matching
record without inventing an effect. Kind3 with node0 skips parent lookup, matching
the source. Other attachments resolve current native actor/object/model leases
and preserve full node ordinals. Object-parent scale is immutable construction
metadata supplied at installation; absence remains a visible required-data error.
An arbitrary unit scale is not admitted.

Install validates physical object binding, actor identities, capacity and record
bounds before replacing current streams. Failed required commands leave their
cursor in place and mark the owner failed. Explicit reinstallation is required
before retry. Exceptions preserve prior command effects and release traversal
guards. Generation reset or parent retirement cannot redirect a stale binding to
a new occupant. Close-time stream destruction is also protected against recursive
World/owner closure.

Both cutscene-object-tracks-{llvm,gcc}-v2 cohorts pass13,276,674 checks, including
256 object-stream cases,2,048 ticks and17,451 processed records. They execute full
original5EF120 and5717C0 plus their owned math bodies. Controlled inputs cover all
command kinds, both parent lookup paths, noncanonical visibility byte values,
repeated/half-rate frames, retained pose keys and exact cursor/terminal behavior.
Five native refusal cases cover missing metadata, capacity, full-width node
exceptions, stale actors and stale object generations. All726 object groups from
the548 owned descriptors also import with exact record bytes retained. This checks
real stream input, not complete original scene playback. Current model-lifetime
regressions pass150,804 checks and all five dependent parents pass on both compilers.

The header/load audit now also includes complete5ECF90. It publishes the descriptor's
destination scenario/room/subroom before5F0610 formats object paths. The request
sequence remains distinct. Accounting for that destination increases candidate
named model matches from452 to671 of726 occurrences, leaving55 unresolved.
Aliases, merged-scene admission and actual loading must still be established;
descriptor filenames are only candidate request identities in this static audit.

Evidence: tools/native_reconstruction/native_cutscene_object_tracks_qualification_v1.json.
Actual object construction, model-work metadata admission, scene-phase/media
selection, reaction/secondary pose work, full entry/exit and installed native game
acceptance remain open. No game was launched or speedup measured.
