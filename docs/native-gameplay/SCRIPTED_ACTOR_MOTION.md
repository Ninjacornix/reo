# Native scripted actor motion consumer

`gameplay_world::ScriptedActorMotion` now consumes the admitted linked-family
67BFF0 behavior through the canonical World Actor, native Playback and owned
motion banks. It selects a scene bank, configures real poses, advances full
models or ordered tracks, and applies the independent pending track-two request.
There is no original ABI/context, guest memory, callback executor or successful
placeholder provider in this production consumer.

The complete source distinction between rate and resource selection matters.
Signed B40 exactly1 selects the mode-one bank. Any other value selects the other
bank. Zero uses a full update step and unscaled blend duration; every nonzero
byte uses half step and double duration. B44 supplies blend duration, with frame
zero at configuration. BA4 mask2 consumes/reset that duration. Phase0 sets
phase1, motion class14hex, rate1 and the selected resource before configuration.
Phase1 advances it. Other phases skip animation, then still consider the
pending track-two request. Every call ORs contact mask17hex.

The single-track linked path adopts the qualified whole-model playback.
Multiple tracks configure in ascending order and advance the secondary tracks
before the base track. The wrapper restores literal loop/restart metadata after
per-track configuration. Its current admission uses strided scene banks;
sparse scene wrappers and primary-family temporary track-ID changes remain
unavailable. Track-two configuration uses the existing general bank consumer
and can consume a sparse bank. Model kind1 deliberately leaves a pending
track-two request intact. Required missing actors, models, known bank bindings
or clip metadata fail visibly. An unused phase requires none of those unused
resources. No legacy retry follows a partially applied invocation.

The constructor's fresh playback now explicitly starts with channel count0 and
three known absent bank bindings, matching the cleared original actor. A later
scene owner must supply its actual bank/count. Generic model binding alone
still makes no claim about those producer-owned values. This corrects the
temporary default Playback count5 in the new scripted constructor before game
installation. The owned constructor regression passes330 real constructions
and406 model/skeleton imports on both compilers.

Both compiler World cohorts pass896,630 checks, executing5,341,442 original
calls. New coverage includes768 cases across all256 B40 patterns,3,840 complete
scripted updates,86 positive real track-two configurations and776 explicit
refusals. Two actual scene banks and matching owned skeletons exercise the
whole-model route. A controlled two-track scene container holds actual owned PC
clips to exercise the multiple-track route. Comparisons include all channel
records, both model banks, sampled parameters/caches/matrices, root-history
buffers, resource selection, status masks and pending requests. Original bank
arrays overlap, so the fixture populates only consumed slots. Production banks
have independent owned identities and lifetimes.

Five parent tests pass on each compiler. The source/build/evidence seal is
`tools/native_reconstruction/native_scripted_actor_motion_qualification_v1.json`.
Reproduce with `animation/verify_world_playback.py`, the owned animation corpus
and a fresh output directory, then the native actor asset, target metrics,
collision worker, cooperative Update and AI owner CTest entries. The verifier
uses the current SDK header and actual current World/resource dependencies.

The outer6BA880 cutscene displacement, pose composition, scene bank-loading
caller, native cutscene scheduling and game installation remain open. Source
6BBBA0 owns the linked callback pass and also performs a further65E4A0 unless
the actor's C94 mask4 suppresses it. The renderer's linked traversal is a
different pass. Those caller boundaries need their own composition checks.
Step4 remains incomplete and no performance improvement is claimed measured.
