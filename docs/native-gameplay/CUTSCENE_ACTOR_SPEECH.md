# Native cutscene actor speech

`CutsceneActorSpeech` supplies the actual opcode 3 speech/face frontend to the
sole `CutscenePlayback`. Playback owns the adapter through a guarded unique
binding, and actor-track work uses that owned adapter before the external speech
fallback. A refused bind retains the candidate. Unbound operations refuse;
copying is disabled. World and target controller outlive an unbound candidate;
after binding, borrowed access expires at unbind or controller destruction.
Its real activity flag participates in Playback's close/reentry guard.

This introduces no second actor, facial instance, stream, queue or clock owner.
Facial claims resolve the current Playback-owned `FacialMotions` each time and
preserve the original full-pool return. The source actor-track traversal remains
admitted while World is updating.

## The actual fixed lookup

Source `5EEC50` formats `VO%03d%02d%02d_%01d.adx` from canonical scenario,
request area byte `38ECD0`, signed voice halfword and signed character suffix.
It calls `1ADB30` on channel 2 before `67C590` claims the face instance.

`1ADB30` first calls `1AB2F0`. That entry passes **literal table `2337C0` and
literal count 422** to `1AB050`; it does not pass a selected SDK archive or
mutable instance catalogue. The existing native `gameplay_bank_loading` owns
that complete normalized sound-alias table and first-match lookup. The only
VO-prefixed entries in this pinned File1 table are `VO00100_AFS` through
`VO00107_AFS` and `VOICE_AFS`; there are no generated `VO..._ADX` entries.
The authored opcode 3 names therefore genuinely miss this catalogue before any
SDK playback child is reached. This is a catalogue miss, rather than a claim
that a similarly named file cannot exist in another nested archive.

Archive and scene preparation were traced before adopting this result:

- `1AB450` uses the same fixed lookup to resolve a VO archive, then activates
  SDK slot 5+party slot into workspace `324468`.
- `6D73F0` resolves the separate DEMO scene source and calls `1AE7D0`, which
  again queries `1AB2F0` before consulting the selected player state.
- `6D7470` playlist preparation calls `1AE9F0`, which also uses that fixed lookup.

The executable lookup qualification activates eight archives and prepares two
positive DEMO sources through complete original `1AB450`, `1AE7D0`, `1ADFD0`
and `1AE6D0` bodies with nonzero SDK handles. All 422 table/string payloads remain
unchanged. Its 24 SDK primitives are explicit fixture boundaries, not an SDK
archive/decoder implementation claim. Subsequent authored VO lookups still reach
no SDK child, and any such unexpected call throws. Existing ordinary actor
archive and concrete decoder qualifications remain separate evidence.

The native adapter executes the real `sound_member` query. A genuine miss
completes this source call and lets the facial claim proceed; it does not report
that audio was queued or played. An unexpected positive lookup refuses its
unprovided media branch. No decoder, source time or successful playback primitive
is manufactured. Ordinary `1BA250` actor voices and the separate DEMO scene
playlist continue to use their existing owners.

## Evidence and limits

The fixed-lookup/preparation comparison passes 8,330 checks on each compiler,
with all 422 aliases as positive controls, 77 actual descriptor request tuples
times nine suffixes plus 64 signed boundaries (757 VO misses), and 1,475,425
original calls. Standard string helper bodies execute as original code too.
The first fixture compilation failure for its missing vector include is retained.

The ownership/caller comparison combines the actual `5EEC50` and `1ADB30` lookup
with the complete facial reset/preload/claim/update and matrix chain. It checks
all 693 actual typed cue/suffix requests, direct Playback-owned dispatch with a
failing external speech fallback, refused foreign binding, unbound admission,
exclusive lifetime, real Source callback guards, prior snapshots/local poses and
all actual model nodes. Earlier fixture failures incorrectly expected an actor
track cursor to remain at its terminal record; the real track owner correctly
retires that cursor, and those failed receipts remain preserved.

Final v6 ownership/caller proofs pass 2,970,596 checks on each compiler. The
fresh corpus uses descriptor-header scenario identity: 22 request rows stored in
an R002 archive actually load scenario 1. Current CMake speech asset runs pass
4,715,864 checks per compiler over all 33 clips, 21649 frames and 129696 model
patches, with the external speech provider absent. Their same source cohort
passes all 31 parent CTests without source drift. The scoped qualification seal
is `tools/native_reconstruction/native_cutscene_actor_speech_qualification_v1.json`.

This is the pinned USA File1 catalogue/caller profile. Arbitrary replacement
catalogues, other locales, the unexpected positive VO-name media branch, complete
scene entry and the full cinematic/application lifecycle are not established by
this adapter. The existing actual DEMO source preparation is not replaced by
these missing-name results.
