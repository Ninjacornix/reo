# Native AI steering and turning

The native steering helper at `0x81BB80` writes to the existing actor input
frame. It preserves the original signed mode range, 16-bit turn thresholds,
button masks, release clearing, and two analog values. The analog branch
requires the caller's camera heading. The other branches use actor state
alone.

The Update Owner dispatches active-room actions 0 and 1. Action 1 starts
the reference-facing transition, stores its heading, and produces steering
until the actor reaches the authored turn window. The position-to-position
heading uses the same Z bias as the native navigation destination query.
Camera-relative steering uses the existing X-biased heading contract. The
session update gate remains an explicit input to the active-room dispatcher.

Both compilers pass 393,220 steering and 65,542 active-room dispatch
comparisons. The reference executes the complete steering and active-room
bodies and uses the previously qualified native heading math for the two
heading calls. The fresh navigation comparisons include 15,884 destination
cases executing the complete position-heading chain. All thirteen parent
tests pass on each compiler. See
`native_gameplay_ai_steering_qualification_v1.json`.

The other active-room actions, waypoint table, off-room actions, real camera
and session gate producers, and game acceptance remain open.
