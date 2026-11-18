# Native animation frame crossings and prelude step

The native `crosses_frame` implements the complete owned File1 573480 body. It observes a channel without advancing it, suppresses flag10 before reading numeric operands, doubles the supplied step only for clock mode1, and preserves the original half-open interval and single-wrap rules. Negative steps are passed through; this does not invent reverse playback semantics. Nonlooping channels do not read unused end/restart values.

Both LLVM and GCC passed 4,194,304 comparisons against the complete original body (8,388,611 checks each), including all256 raw loop bytes, all256 flags, four clock modes, two channel layouts and eight numeric shapes. Used exceptional arithmetic is explicitly refused. This is the audited finite SDK arithmetic profile, not physical PS2 exceptional parity.

The World animation prelude now receives the exact step supplied to `tick`/`tick_blended`. Previously its interface omitted that argument, although original58C300/5D57D0 forward it to573430. It must not be replaced with Actor.motion_rate. Fresh paired World cohorts passed186,708 checks each and compare forwarded step bits for negative, zero and fractional inputs against the complete original caller bodies.

The first GCC World cohort executed all comparisons successfully but failed the final source-stability assertion because a shared ModelReference header changed during the run. That folder remains preserved. The fresh paired v2 cohorts use the same current header snapshot; they do not qualify the unrelated typed-reference feature under development.

These are native source/original-body comparisons, with immutable inputs and receipts recorded in `native_animation_frame_events_qualification_v1.json`. No game was run, installed or benchmarked. Full573430 family dispatch, concrete audio/effect/resource consumers and native game installation remain separate gates.
