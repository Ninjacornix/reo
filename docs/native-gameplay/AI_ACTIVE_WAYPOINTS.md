# Native AI active-room waypoints

The active-room dispatcher now handles the default waypoint action. It
synchronizes the canonical route action with the selected edge action.
A changed low byte clears the four action phases when the transition lock
allows the change. An unchanged low byte can still update the high byte.
A completed waypoint resets the high-level action.

For ongoing movement, the actor takes its heading from the selected waypoint.
The ordered wall trace checks the segment to that waypoint. A qualifying hit
within 55 units sets the second steering flag when the actor is facing its
previously recorded contact normal within the original turn limit. The hit
point and recorded normal are distinct inputs. The same canonical actor input
frame receives the generated buttons and analog values. A caller supplies the
camera heading when the analog branch needs it.

Both compilers pass the refreshed 1,024-frame comparison, including 120
active-room waypoint frames, 53 waypoint wall hits, and 47 contact-flag
writes. The fixture resumes the original indirect tail jump at its selected
handler and checks its unchanged return address. The complete reached
waypoint bodies and contact angle predicate run in the reference. The ordered
wall trace and heading calls use declared, independently qualified native
ports. All thirteen parent tests pass. See
`native_gameplay_ai_active_waypoint_qualification_v1.json`.

Condition-specific waypoint handlers, the live camera and session gate
producers, live scheduling, and native game acceptance remain open.
