# Actor room-object coordinate publication

Status: qualified on LLVM and GCC; uninstalled. Stage4 remains incomplete.
InstalledV39 is unchanged and no game was launched.

Selector9 reads the actor's room-object ordinal and signed X/Z from the existing
canonical32-record RoomObject Owner. That owner already supplies geometry,
occupancy and scenario commands. UpdateOwner and StatePublication borrow it;
there is no copied coordinate table. The admitted physical ordinal0..31 is
distinct from an external object ID or a generation-checked native capability.
Initialized inactive cells retain their actual coordinates. Missing initialization
and ordinals32..255 return unavailable, with no index masking or invented object.

The typed message captures ordinal and coordinates before room lookup. A callback
may replace the imported owner and change actor/mode while the captured payload
remains unchanged. Publication uses the normal shared gates and delivery paths,
without reading gauge state or changing actor status/suppression. The observed
type9/length8/dispatch4 framing does not establish a wire encoding; the final
untouched stack byte is omitted from the typed value.

Both compiler cohorts execute complete67E230 with actual gate/dispatch helpers.
655,361 new cases include every signed coordinate pair, all32 records, partial
populations, inactive cells, primary/category1 routes, lookup replacement and
mode mutation. They produce323,826 messages and131,074 lookups, with eleven
capability/lifetime refusal groups. Prior contact-snapshot, contact-alignment/math
and cooperative/message matrices also run:88,870,413 identical combined checks.
All eight parent integration checks pass per compiler. Evidence:
`native_actor_room_object_message_qualification_v1.json`.

Messages3/8/11, incoming application, actual queue/receiver/transport, remaining
action callers, semantic saves and game installation/acceptance remain open.
