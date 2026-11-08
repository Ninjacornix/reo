# Native media launcher preparation checkpoint

The launcher preparation integration is committed locally on
`fix/launcher-progress-overlay`, commit `700d5a7d`. Its isolated checkout is
`C:/Users/Ninjacornix/reo-launcher-native-media`; the media branch retains the
runtime/helper and private packaging tool. Neither branch has been pushed.

The launcher recognizes an exact game/helper pair declared by versioned
`native-media.json`. It verifies the actual private game-image hash and retains
a read-only verified helper handle throughout preparation. A fixed environment
selects the coherent native resources/ADX/audio/movie routes; it does not alter
game speed or VU experiments. Missing declarations leave existing builds on
their existing media selection. Declared but broken packages fail explicitly.

Preparation uses the existing pinned converter and native Windows helper, not
Python or developer tools at runtime. It completes before the game launches,
reports through existing asynchronous progress, and retains stdout/stderr.
Cancellation joins only the preparation helper/converter process tree. Playback
status stays at starting until the actual native owner selection log arrives.

The .NET 10 shared library and Windows Avalonia desktop build succeed. A private
Windows dependency lock is used because the existing desktop lock targets
macOS; the checked-in lock is preserved. Thirteen tests pass, including actual
owned subprocess success/error and cancellation of a helper with a child.

The production .NET preparation method runs the actual qualified helper against
the owned File #1 import. It verifies/reuses all 201 references (200 unique
prepared movies), with zero conversions and the expected complete manifest hash
`ed9d30df807201eeafa43477e43298c14f5df8593c66fffb92e8a4e8fc942bd0`.
The fixture links existing immutable MP4 payloads and copies stamps, avoiding
another 617 MB payload copy. The original cache remains unchanged.

Private evidence is under `build-native-sjuni/launcher-native-prep-v1`:
`protocol-tests.json`, `logs/native-movie-launcher-preparation.json`, preparation
logs and fixture metadata. `native-media-game-v27` contains the identified game,
runtime/shader files, helper and profile, with no extracted movie/audio payloads.
The packaging receipt and the game build receipt identify the exact cohort.

This first packaging contract supports a direct game folder. A normal release
SDK must declare its locally compiled image after its verified build completes;
that integration remains. Actual UI-launched native gameplay, broader resource/
room transitions, active-movie error/pause controls, audible synchronization and
retirement of the remaining media bridges still keep Step 3 open.
