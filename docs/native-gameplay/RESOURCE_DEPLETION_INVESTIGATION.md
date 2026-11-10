# Resource depletion follow-up: source investigation

This is a source investigation, not an installed or qualified implementation.
It identifies the next consumers after the native outer item-effect dispatcher.
No game or physical audio device was launched for this investigation.

The5B4AD0 replacement path checks active/owned descriptor state, template bits1
and80000, nonpositive quantity and a nonnegative signed alternate content ID.
If an existing primary has visibility byte exactly1, it requests5DF2A0 and the
actor cue5 before replacement. It then replaces content, initializes quantity
and refreshes the actual weapon resource owner. The existing content, quantity,
native audio frontend and weapon resource owners can be reused; the reached
visual consumer must also be implemented.

5DF2A0 selects content6E -> part0/effectBF,6A or6F -> part1/effectC0,
and74 -> part2/effect5A followed by part3/effect5B. Other contents request
nothing.5DF340 creates work category1B, initializes children with652E20,
copies resource-model orientation, and combines its model translation with a
transformed part-specific offset. Flags are8193. Work allocation and children
must use the existing shared168/256 domains, including natural capacity failure.

A signed immediate matters here: the stored update address is **58FBC0**,
not59FBC0. Likewise its offset table is **70B860**, not71B860. The sequence
`lui59` plus signed`FBC0` addresses58FBC0; `lui71` plus signed`B860` addresses
70B860. The owned o2 bytes at70B860 encode four offsets: (-60,0,0),
(-40,0,0), (0,0,0), (0,0,0). These corrections prevent implementing the wrong
callback or importing unrelated metadata.

The58FBC0 phase table at709538 contains58FBE0,58FD10 and58FE50. Initialization
makes the work visible, copies initial/current/previous positions and consumes
five RNG requests. One angular component is forced to zero after its RNG request;
a sampled Z velocity is also overwritten by zero. Preserve those RNG advances.
It sets X velocity from low3 random bits minus3.5, Y velocity5, gravity from
73E0B0 (raw BF7AE148), delay5 and fade step from73E0B8 (raw3D4CCCCD).

58FD10 adds the angular increments with signed-halfword wrapping, publishes the
previous position, advances position and velocity, then decrements the delay.
After delay becomes negative, it subtracts alpha and enters retirement phase2
only when alpha is below zero (zero survives that check). It always performs the
floor-segment query57D560 afterward, including after the fade transition. A hit
also hides it and selects phase2.58FE50 releases children and retires the same
shared visual identity. No bounce response was observed in these routines.

The existing native `gameplay_collision::trace::floor` is the qualified candidate
for57D560. It requires an actual room geometry lease; a positive no-op collision
provider would not close this consumer. The58FD10 query ignores the reported hit
point/normal and only uses the boolean result. Rendering submission remains a
Stage5 concern, but native output must still preserve the relevant pose, scale,
alpha, visibility and lifetime fields for the renderer.

Next implementation work: add a typed ballistic lifetime to the canonical visual
owner with actual room access and exact RNG/state order; compare complete
5DF340/58FBC0/58FD10/58FE50 plus their constructors on owned effects and floor
geometry; then compose5B4AD0 and5B2590 with actual audio and weapon refresh.
The original draw callback371EF0 and all imported constants must be audited
before deciding their native output contract.
