# Native player with live clock observations

Independent shared-output decoder/player plus the unchanged original-qualified
integer/estimated clock. Actual pause precedes baseline capture; nonboolean
argument behavior and modulo/tick rules are retained. No device time or service
count substitutes for a supplied tick.

See the [contract](../../../docs/native-media/ADXT_CLOCKED_PLAYER_CONTRACT.md)
and [qualification](../../../docs/native-media/ADXT_CLOCKED_PLAYER_IMPLEMENTATION.md).
The two standalone CMake targets cover live controls and inherited composition.
`verify.py` freezes measured inputs before replaying original words and checks
a controlled callback schedule plus a stale-snapshot negative. No game/audio
device or production adapter is run. Global service, LSC, banks and PAK tails
remain open.
