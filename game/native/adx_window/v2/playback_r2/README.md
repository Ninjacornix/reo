# Window2 playback R2

This revision adds a guarded silence/data port for the native playback control.
Its class header/layout differs from frozen Window2 and ready-flag R1. Select
this header in every client and link **only** this v2 owner implementation in an
executable. Never mix the three class definitions or static libraries.

Source2's actual private friend remains this concrete v2 class. No mutable
store/source alias escapes. Existing decoder/header/source methods are preserved
mechanically, apart from constructing the new bridge and suppressing codec-only
publication observers for silence. The inherited unit-test file is an exact
copy so its quoted include resolves to this header.

The [composition contract](../../../../../docs/native-media/ADXT_PLAYER_COMPOSITION_CONTRACT.md)
and [player verifier](../../../adxt_player/verify.py) record the bounded scope,
source freeze and original comparisons. Production selection remains separate.
