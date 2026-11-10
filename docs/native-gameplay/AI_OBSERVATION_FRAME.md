# Native AI observation frame

The File #1 observation routine at `0x812540` now runs through the native
Update Owner. It uses the actor's navigation route, shared scene records,
the pre-actor World target cache, canonical inventory descriptors, and Session
RNG. The result carries the scene candidates for the later goal pass.

The current navigation node is published before the room check. The observer
clears forward-wall history outside the current room, when the motion gate
blocks the probe, or when the probe misses. A 150th consecutive hit clears
the counter and resets both action and goal. Motion class 8 also resets the
action and goal in the current room.

The companion comparison reads the cached primary distances. The observer
publishes the linked target count before filtering candidates by wall, floor,
and target flags. The threat score keeps the original tier and priority
ordering and applies the authored bonus to the combined weights. The inventory
override uses the descriptor's attachment ID, with carried slots preceding
storage slots. The observation frame and existing inventory caller share that
lookup.

Reference events preserve the distinct cooldown, probability, and scheduling
rules. Rejected probability checks still start the cooldown on events 2, 4,
and 8 when the attempt is reached. Event 4 schedules independently of that
decision. Event 8 uses the room gate. Periodic and auxiliary-status events
replace earlier event selections in source order. At the end of the frame, the
observer preserves a matching room memo and clears a different memo to
`0xFFFF`.

The comparison runs the full original observation body and nine audited
children against canonical native state. Both compilers pass 4,096 original
profiles and 131,859 checks, including 2,479 wall probes with 495 hits and
371 resets. It covers all four threat bands and candidate rows with zero
through 49 entries at the tested counts. Two native refusal checks cover a
full 50-entry row without the source sentinel and an invalidated cache.
The test uses a single navigation node, empty scene records, and controlled
wall geometry. The navigation selector, empty scene scan, forward transform,
wall trace, and eight-byte clear are declared fixture ports. The independent
[navigation](NAVIGATION_VISIBILITY.md) and [scene scan](NAVIGATION_SCENE_CANDIDATES.md)
comparisons supply broader evidence for those child paths.

All thirteen parent tests pass on each compiler. The source-identified
comparison and build receipts are indexed in
`native_gameplay_ai_observation_frame_qualification_v1.json`. The original
outer AI caller, goal/action dispatch, actual room/model loading, and a
coherent native gameplay candidate remain open.
