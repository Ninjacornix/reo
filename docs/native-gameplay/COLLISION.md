# Native gameplay collision

The native proxy-query boundary is implemented and independently compared with
owned File #1 code. The complete Stage 4 actor/world collision migration remains
in progress. No game or live process was accessed for this work.

`game/native/gameplay_collision/collision.hpp` exposes ordinary typed positions,
integer polygons, room-generation IDs and owned proxy descriptions. Its library
has no generated-function, guest-register, guest-memory or PS2-runtime dependency.
The native actor owner supplies position, actual heading and query class; the
native scenario owner supplies object/slot admission state and consumes the
selected native proxy ID. It must apply scenario/door effects separately. Query
selection does not itself execute the original proxy callback.

Implemented proxy rules retain exact integer wrapping/orientation/fan winding,
fixed coordinate truncation, kind-0 polygon containment without radius expansion,
kind-80/81 radius tests (inclusive segment interior, strict endpoint radius),
kind-85 actor-position selection, class/content filters, active/busy flags,
asymmetric 200-unit vertical admission, and strict priority comparison.
Creation order is explicit: original allocation appends, but query starts at the
tail and follows the previous link. Equal priorities consequently favor the
newest creation, including derived proxies. It would be incorrect to favor the
lowest room-record index.

`import_proxy_section` reads the actual section-A relative-offset directory and
bounded B0-byte records. It imports geometry, basic activation and typed door
destinations; it does not resolve model references, generate model-derived
84/85 proxies, or replace all fourteen scenario callback families. Imported
kind-2 activation honors the special scenario-1/room-1 initial disable. Native
callers must preserve creation order when adding derived/runtime objects.

LLVM and GCC each pass 85,403 checks. The verifier checks every instruction word
in seven complete original bodies against owned o0/o2 images, then compiles the
unchanged generated bodies into an isolated test-memory harness. Comparisons
cover full-width integer wrapping, exact edges, fractional positions, radius
strictness, height slack and 600 multi-proxy configurations. Subtraction and
scenario admission/dispatch are declared test ports; their game state machines
are not claimed compared by those cases. The real J's Bar section-A fixture
imports 39 records and all three doors, including the room-4 destination.
Failed compiler/fixture attempts remain in the private evidence directories.

Qualification: `tools/native_reconstruction/native_gameplay_collision_qualification_v1.json`.
Reproduction uses a fresh private output directory:

```powershell
python tools/native_reconstruction/verify_gameplay_collision.py --compiler llvm --output build-native-sjuni/gameplay-collision-llvm-new
python tools/native_reconstruction/verify_gameplay_collision.py --compiler gcc --output build-native-sjuni/gameplay-collision-gcc-new
```

Sphere contact, horizontal pair displacement and contact-extrema helpers have
focused mathematical checks; complete original actor-registry and response
comparisons remain separate work. The public proxy-query API is not proof of
all movement collision, all authored room objects or a live game replacement.

The separate `response.hpp/.cpp` companion now implements full original
capsule/capsule parallel and nine endpoint/interior regions, capsule/sphere,
floor selection and metadata, collision masks/dynamic-slot filters, and immutable
grid import. Both compilers pass 205,015 identical focused checks, with zero
contact-vector difference against the original bodies using declared scalar
vector-math surroundings. Component division order matters: replacing each
original division with multiplication by a reciprocal caused a measurable
correction mismatch and was corrected before qualification.

All 366 named stock wall/floor assets across the five retail scenario archives
are imported: 183 wall and 183 floor resources, 1,697,820 independently hash-checked
bytes. Every native cell's ordered triangle bodies match the actual original
relocation initializer. Every floor cell is additionally queried at heights 0
and 1000 through native and original floor selection. No original asset is
modified: the original initializer operates only on a test-memory copy.
Twelve complete original intervals are byte-audited. Scalar vector arithmetic,
square root/normalization and cell-list selection are declared oracle ports;
the original PS2 vector unit is not reproduced by the native library or fixture.
See `tools/native_reconstruction/native_gameplay_collision_response_qualification_v1.json`.

The `sweep` companion now implements one-sided triangle admission, six-contact
capacity, ordered shared-edge rejection, correction extrema and original movement
clamping. Both compilers pass 489,117 checks, with zero difference on the defined
original paths. The 72,876 owned wall queries cover all183 wall resources using
all-inclusive, human, special human and enemy masks. 184 probes (46 per mask)
reach an original uninitialized face-list index. The native resolver retains the
creating face identity and uses it only where the original index is missing.
These repaired paths are checked for finite deterministic bounded results and
are explicitly separate from original-result parity. One synthetic case also
exceeds the original eight-entry scratch; the native scratch is bounded64.
The probes are not proof that those positions occur during gameplay. Detailed
reproduction inputs remain in the receipt's JSONL evidence. Qualification:
`tools/native_reconstruction/native_gameplay_collision_sweep_qualification_v1.json`.

The `actors` companion builds sphere/capsule centers from retained native joint
poses and source descriptors, resolves the deepest admitted candidate in exact
registration order, applies original horizontal movement/priority/repeated-hit
rules, and publishes typed contact peers and shape summaries. Both compilers
pass81,808 checks with zero difference:1000 varied four-actor cases and200
auxiliary boundary cases. Boundary lookup preserves its source order even when
the registered boundary is itself a roster actor. It uses the actual native
EntityStore/EntityId API; lifecycle ownership remains the actor-store owner's
separate qualification. Math, mode and model transformation surroundings are
declared fixture ports. Qualification:
`tools/native_reconstruction/native_gameplay_collision_actors_qualification_v1.json`.

The `ownership` companion supplies native bounded128-slot proxy ownership,
prepend/append order, domain/generation handles, retirement/reuse checks, mutable
activation, retained EntityId owner/snapshot and typed source/door associations.
Repeated selections reuse a cached immutable query snapshot until a mutation.
Model-derived84/85 regions, middle-corner reprojection and80..83 owned constructors
are implemented from the original local rules. The native5DA420 caller preserves
current/previous transformed centers, refreshes cached center while disabled,
passes exact masks/class gates, updates only actorX/Z, and represents unwritten
contact outputs as optionals. Both compilers pass344,728 checks with zero
difference across1500 pool sequences,1200 model poses,200 caller cases and owned
constructor checks. Its scalar inverse/translation/vector operations and the
already-qualified sweep result are declared ports around the unchanged original
bodies. Degenerate inverse geometry or the original no-near-depth invalid index
is rejected. Qualification:
`tools/native_reconstruction/native_gameplay_collision_ownership_qualification_v1.json`.

Remaining collision contracts: segment/radius traces and sampled grid-list
ordering; authored room-object footprint clipping57C0B0; full6636D0 postmove
height/surface rules and scenario callback dispatch; actual native actor/scenario
integration. The modules above do not claim those consumers have been replaced
in a running game, nor that the whole Stage4 is complete. Further companions
preserve the qualified cohorts.
