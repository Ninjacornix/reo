# Native AI off-room waypoint movement

The off-room action dispatcher now advances ordinary waypoints using the
actor's canonical navigation route. It uses the original character, actor
class, and motion-dependent movement coefficients at `0x829500` to compute
the travel counter. The Session clock mode selects the original extra
division by two. The code preserves the original word conversion and signed
countdown interpretation.

A positive counter decrements once per AI frame. On ordinary arrival, the
actor takes the selected waypoint position and node. The final room and node
mark completion. Otherwise, the current graph supplies the first matching
edge action for the next node. Missing graph data or an unavailable scripted
arrival keeps the position and current node intact. The six scripted arrival
entries still require their room-transition or relocation consumers.

Both compilers pass 147,456 timing comparisons and 4,096 complete ordinary
waypoint-dispatch comparisons. These exercise the full original XYZ distance
and countdown code, the complete motion-byte domain, all eight character
columns, both clock paths, and the original first-match edge order. The
1,024-profile full AI frame and all thirteen parent tests also pass. See
`native_gameplay_ai_waypoints_qualification_v1.json`.

Live scheduling, scripted arrival effects, first-phase off-room resource
requests, and native game acceptance remain open.
