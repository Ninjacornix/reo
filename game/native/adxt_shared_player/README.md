# Native compressed player using shared output

One actual decoder/source/control graph owns one exclusive output producer.
Per-stream retirement fences that producer and its source while peers and the
shared provider remain active. Rendering never references the player/decoder.

See the [contract](../../../docs/native-media/ADXT_SHARED_PLAYER_CONTRACT.md)
and [implementation evidence](../../../docs/native-media/ADXT_SHARED_PLAYER_IMPLEMENTATION.md).
Build `adxt_shared_player_tests` or run verify.py for the actual-provider source
model and controlled negative checks. Asset validation reuses one session across
the finite owned corpus. All device primitives are modeled; no game/device or
runtime selection is performed. Full pause/clocks, LSC, banks and PAK tails remain.
