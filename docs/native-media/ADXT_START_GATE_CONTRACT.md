# Native wait-for-play-start control

The game-facing ADXT setter at `132DF0` stores an arbitrary low byte at C4+70.
The reviewed `1343B8` control checks that byte before leaving buffering. Its ready
flag C4+71 still becomes one when the queue condition is met, including while
start is inhibited. This control is separate from pause: setting it during
already active playback does not stop the voice or clear its clock baseline.

The existing native Playback core already owns this behavior. The phased player,
canonical session and stable instance facade now expose it. A request made before
the header is ready is applied when Playback is constructed; a request made after
readiness updates that same Playback instance. The stable property persists
through stop/replacement and resets on destruction/recreation.

An eventual guest adapter must preserve the raw guest byte and pass its nonzero
interpretation to this native Boolean control. The native snapshot reports the
requested flag even before header readiness. Clearing the gate lets the existing
playback policy choose the supplied original service tick for start. A paused
voice may enter the playing phase without starting output; its subsequent resume
retains the qualified pause/clock behavior.

Required checks include a buffered inhibited source beside a rendering peer,
ready-without-start behavior, release at an exact original tick, setting the gate
on a playing source, retention across replacement, pause interaction, stale keys
and fresh defaults. No host-time clock or game-speed change belongs to this
control. Exposing this API does not install the actual guest hook.
