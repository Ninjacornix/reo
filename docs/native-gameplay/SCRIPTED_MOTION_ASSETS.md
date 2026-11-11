# Native scripted motion asset loading

`ScriptedMotionAssets` now reads the admitted body, face and head motion
requests from the retained File1 NETBIO00 archive and prepares real immutable
MotionBanks. This is the asset preparation behind1D1CC0, not an installed
cutscene lifecycle or a completed Step4.

The original ROM alias table at2322C0 contains1342 unique full-path aliases.
The native profile extracts all89 matching dNN, dNNface and hdNN motion members
with exact archive ordinals. AFS display filenames repeat across scenarios;
selecting the first d00.bin would load unrelated scene content. The profile
retains scenario/clip/kind/member identity and verifies original loading,
dispatch, default archive setup and normalization instructions against the
owned ELF. The current owned table has79 body and10 head entries and no face
entry. Missing face lookup remains explicit; no generated substitute is used.

Preparation runs outside the synchronous simulation call. Each of three files
is attempted independently. A successful strided load copies the previous
immutable bank before replacing populated slots. Thus absent rows preserve
their prior blocks, and missing/read-failed/malformed files retain the prior
bank while later files still run. The returned per-file statuses distinguish
those outcomes. Input bytes and live banks remain immutable; no resource token,
guest scratch area or in-place source memoization is retained. Malformed data
is refused with its previous bank intact, a bounded native admission rule.

Both compiler cohorts pass13,209 checks, including89 actual member loads and
750 nonempty block slots compared byte-for-byte against independently located,
hash-checked archive extents. Contract checks exercise duplicate filenames,
independent read failure, omitted-row retention, malformed files and invalid
archive ownership/profile. A real owned body bank is passed through actual
ActorAssets, ScriptedActorConstruction, Update Owner, LinkedActorUpdates and
LinkedModelPass for16 updates with native animation and published model poses.
The initial consumer fixture expected a published skeleton immediately after
the actor callback; its failed run exposed the missing separate model pass in
that fixture. It was corrected by invoking the real qualified pose owner.

The complete original1D1CC0 runs128 additional controlled routing cases across
three independent read results, scenario/clip values, exact paths and ordered
bank construction calls. Sprintf, file reads and1D1960 construction are declared
observation ports in this routing check. It does not claim to execute original
I/O or replace the parser qualification with a successful stub. Actual asset
reads and native construction run separately in the same executable. Six parent
CTest entries also pass on both compilers.

The profile can be regenerated with generate_scripted_motion_profile.py and a
fresh output directory; existing different profile bytes are rejected. Run
verify_scripted_motion_assets.py with the selected compiler, native CMake build,
imported File1 data root and a fresh output directory. Its receipt binds actual
member hashes, original instruction words, generated test surroundings, current
native source copies, compiler/binary hashes and observed results. The aggregate
seal is native_scripted_motion_assets_qualification_v1.json.

The original common-player-bank guard clear belongs to the scene lifecycle,
not this off-thread preparation operation. Actual transition admission must
perform that state change at the original point, supply the prepared banks and
actor channel count, run cinematic callbacks and the separate model pass, and
join teardown. Those real callers, other callback families and game installation
remain open. This work launches no game and measures no performance improvement.
