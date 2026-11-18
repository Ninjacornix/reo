# Native AI off-room actions

The AI frame now selects the off-room dispatcher using the original transient
marker. The dispatcher synthesizes the actor's motion class from its canonical
action, waypoint action, and steering button state before running the handler.
The seven reset entries share the original action reset. The post-publication
request phases for actions 4, 5, and 6 preserve their reset and wait behavior.
Phase zero still requires a real request producer. It stays pending when that
producer is unavailable.

Both compilers pass 196,608 motion comparisons across the complete waypoint
halfword domain and 2,557 off-room dispatch comparisons. The refreshed full
frame comparison includes 100 off-room frames and all 331 gated frames.
The original off-room dispatcher and reached handlers execute in the fixture.
All thirteen parent tests pass. See
`native_gameplay_ai_off_room_qualification_v1.json`.

The timed waypoint action, first-phase resource requests, live gameplay
scheduling, and native game acceptance remain open.
