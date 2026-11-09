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

The `trace` companion now implements segment/triangle angle-sum containment,
rejected-branch partial outputs, strict endpoint admission, the0.001 startward
inset, repeated-cell sample order, nearest-in-list selection, endpoint shortening,
first-hit queries and two-sided floor query/type filters. Both compilers pass
482,015 checks with zero difference across all366 stock resources and22,363
triangles. The full original wrappers are compared, including their distinct
first-successful-list versus progressively-shortened behavior. Sampling exposes
capacity/nonprogress errors rather than overflowing an unbounded output buffer;
all tested stock traversals fit the original scratch. Scalar math/acos/vector
surroundings are declared ports. Qualification:
`tools/native_reconstruction/native_gameplay_collision_trace_qualification_v1.json`.

Further companions below qualify the authored footprint, full postmove policy,
room geometry and actor hit-region traces. Radius-grid/directed-volume traces and
actual native actor/scenario integration remain separate work. No isolated
module claims that the whole Stage4 is complete.

The `room_objects` companion is a distinct native32-record scenario owner,
reserving allocator slot0 and separating external IDs from object identity.
It imports allthree stock object-type files andthree placement files, plus the
seven owned RDTsectionE rooms containing those objects. Both compilers pass
15,903 checks with zero difference against unchanged original allocation,
placement, footprint, occupancy, cached mapping and classification bodies.
There are11unique placements; the27placement observations repeat them across
room cases. Ten immutable source footprint profiles are individually retained.
The four native occupancy layers, first containing object, type/flag defaults,
2100in-grid height classifications, and C2..C7-facing typed helper contracts
are covered. Actual bytecode-handler integration is qualified by its own owner.
See `native_gameplay_room_objects_qualification_v1.json`.

This owner does not yet construct model instances/proxies, rebuild dynamic
triangles or actor occupancy, or replace every room-object interaction caller.
Odd/missing original height-layer indices and missing outside-floor providers
are explicit unknown capabilities; the comparison does not claim parity with
uninitialized original table reads. The footprint companion is qualified below.
These distinctions keep the resource
owner, geometric solver and complete game consumer migration separately visible.

The `footprint` companion now implements the full57C0B0 movement policy using
the native room-object owner: radius49.5/20 selection, original initial-object
escape side order, room-boundary admission, exact next-cell boundary selection,
ordered five/front and three/fallback probes, directional rollback and bounded
four-pass correction. Both compilers pass19,037 checks over6335cases, including
3385nontrivial elevated slide cases, with zero difference. The elevated platforms
are source-admitted synthetic inputs; actual-object checks use allseven stock
room-object sections. Native capability failures remain explicit when a source
classification depends on an absent height layer or floor provider. This is a
qualified solver boundary, not proof that every native actor now invokes it.
See `native_gameplay_footprint_qualification_v1.json`.

The `regions` companion imports all164nonempty authored-region sections across
the five stock scenario archives, retaining944regions and278auxiliary records.
It owns native integer vertices and caches the six original normalized planes;
selection retains Y+10, strict highest priority and first equal-priority record.
Both compilers pass25,771checks including8496queries with identical outcomes.
The actual source importer and geometry/selection bodies remain unchanged in the
oracle. Zero-category fixtures additionally correct an older mapping mistake:
573DE0 jumps to573E84 and573F00 before entering either category loop. They are
pretested loops; a zero category does not process a spurious record. The old
SYMBOLS_TASK_FLAGS.md do/while statement is incorrect. Qualification:
`native_gameplay_regions_qualification_v1.json`.

The `postmove` companion now supplies the full6636D0 native actor collision/height
policy. It composes the qualified wall, floor, authored-region and footprint
providers through typed state, preserving eligibility, disabled-wall center
refresh, special mask admission, displacement timing, source surface arithmetic,
route-height gates, material/region selection and pose flags. In particular,
kind14uses joint2and skips ordinaryheightcopy;616F60publishes the floor material
byte via t1, independently of its height return. Both compilers pass36,010checks
across2400controlcases using actual first-room assets, with zero difference:
1857eligible,101contacts and371joint2specialpaths. The unchanged full caller uses
separately-qualified native child-provider ports in this fixture. Qualification:
`native_gameplay_postmove_qualification_v1.json`.

Actual native actor-loop adaptation remains the integration owner's work.
Room-object model instances/proxies, dynamic triangle rebuilding, actor occupancy
and radius/contact-packet traces remain concrete collision consumer gaps. The
qualified components do not claim those consumers have been retired in game.

The `room_geometry` companion constructs expanded/paired/exact object quads,
typed instance-owned proxy descriptions, combined actor occupancy and the bounded
31-triangle dynamic prism set. Both compilers pass131,791checks with zero
difference across39quad cases,41proxy records,400occupancy cases and8dynamic
builds. The actual retail data supplies27object observations in seven rooms;
12synthetic admitted variants additionally cover rotations, all ten footprint
profiles, explicit shapes, capacity/request gates and the31-triangle partial sink.
The synthetic12object build matches96attempts and65drops; no retail overflow
incident is claimed. The four90-unit side probes preserve their order and
previously-admitted dynamic geometry. Original geometry/occupancy/prism/sink
bodies use declared scalar Y-matrix and qualified trace-provider ports.

Two distinct identities remain deliberate: the proxy snapshot is the object's
physical ordinal from native instance metadata, while the authored external ID
and native EntityId generation serve separate purposes. Proxy heights use the
native instance's currentY, not the room origin. The API emits descriptions;
actual native model-instance lifetime and moving-object interaction consumers
must own and reconcile those descriptions with the shared proxy owner.
See `native_gameplay_room_geometry_qualification_v1.json`.

The `spatial` companion owns segment/sphere, margin and overlap queries, the
original sphere/edge admission rule, recipient masks and ordered actor hit-region
selection. LLVM passes209,839checks and GCC209,886checks, both with zero error:
7003primitive cases,4096policy cases,2000original scan cases and67,089edges from
all366stock grid resources. Synthetic scan targets exercise global-nearest versus
per-actor selection, first versus nearest regions, exclusions and controlled
occlusion. Each fixture executes unchanged original scan bodies with declared
scalar math, neutral damage and controlled occlusion ports. The differing check
totals reflect compiler-specific argument evaluation order in randomized primitive
input generation; both run the same fixed case counts and source comparisons.

Contacts carry opaque EntityId references independently of authored category and
contact ID. Overlap output is tagged as a zero-origin vector because the original
57AB70 does not produce a world point. Last-scanned identity is distinct from
selected-target identity. The original global margin response can read an
advanced one-past-region pointer for its later direction; that direction remains
explicitly unknown here. The spatial module does not mutate canonical HitActor
effects, invoke generated senders or manufacture guest packets. Region pose,
enrollment and radius-grid/directed-volume contracts remain separate work.
Qualification: `native_gameplay_spatial_qualification_v1.json`.

The `hit_regions` companion now owns bounded terminated20-byte region definitions,
retained native spheres and model-joint versus actor-basis pose transforms. A
missing descriptor preserves the previous sphere count; an immediate sentinel
publishes an empty set. Missing native joints fail before pose publication.
It supplies the64-entry native identity queue and prepares canonical HitActor
damage/progression/pending fields alongside a supplemental ContactState holding
cooldown, priority and serial. Reset occurs before cooldown/capacity admission;
FF remains permanent, and1-to0 skips enrollment for that update. The caller owns
traversal order, queue reset and pose scheduling independently of enrollment.

Both compilers pass149,044checks over3000pose and1536queue cases with zero
difference against unchanged5DC1B0,5DC2A0and5DC3A0bodies. The matrix-vector product
is an explicitly declared scalar port, not a new VU execution equivalence claim.
These fixtures are synthetic admitted actor definitions, not live gameplay.
Qualification: `native_gameplay_hit_regions_qualification_v1.json`.

The `radius` companion now owns57D960list and57DC70grid radius traces. It retains
partial rejected-plane point writes, direct/offset-plane/three-edge order,
list-local nearest selection, repeated segment cell lists, the original four-cell
endpoint stencil even for large radii, dynamic-last order and first successful
list behavior. Both compilers pass613,230checks with zero defined-output error:
44,727list cases and22,363wrapper cases over all366owned collision grids. Floor
grids are admitted as geometry in this corpus; no stock floor-radius caller is
claimed. The quadrant table70EF10is verified against the owned overlay.

The source has a concrete undefined point case:371070writes no point, and the
two preceding plane attempts can reject before writing. A backface edge overlap
then consumes uninitialized stackXYZ. Seeded-scratch list comparisons preserve
the exact defined source behavior; the normal native call reports
`uninitialized_point` and withholds an invented nearest point.319generated stock
geometry probes reach that unknown capability. They are offline synthetic
queries, not measured retail incidents or evidence that a live caller reaches
the case. No closest-point repair is silently introduced. Qualification:
`native_gameplay_radius_qualification_v1.json`.

The `directed` companion now implements6F0FE0directed-volume geometry and the
full57B6F0ordered region selection policy. Two positive extents feed
atan2(second,first); the original1921B0and18F570bodies execute unchanged in the
private comparison to establish pair order and the owned polynomial. Atan2 and
ordinary finite float SIMD are declared math surroundings; no original libc or
PS2 hardware execution equivalence is claimed. The coefficient bytes22FE30are
verified against the owned main executable.

Both compilers pass110,933checks with zero error:18,003primitive,18,000trig-pair
and1000full scan cases. Synthetic inputs exercise both world-point surface and
zero-origin side-boundary outputs; the native result tags them distinctly.
Per-actor mode retains the first region, global mode retains strict nearest
selection, and occlusion/class/exclusion rules retain source order. The advanced
region pointer used by later global response direction remains explicitly
unknown, as in the other spatial cohort. Native canonical HIT consumption and
actual actor-loop installation remain separate responsibilities. Qualification:
`native_gameplay_directed_qualification_v1.json`.

The `postmove_view` companion now provides direct synchronous references to
canonical actor fields. VectorRef borrows individual XYZ scalars without casting
unrelated vector types, while FlagRef supports the original byte553flag and bool
fixtures without normalizing an untouched nonzero byte. Disabled-wall state is
derived from controls; the dynamic-kind gate is a derived value. The historical
owning-State API remains unchanged for its frozen comparison.

Both compilers pass72,010checks, including2400actual native World::Actor views
and the unchanged full6636D0oracle with separately qualified child providers.
There are1857eligible cases,101wall contacts and371special joint2routes, all with
zero error. Position/previous, health/status flags, controls, room, surface fields
and byte flags bind directly; only derived collision data uses a component.
This verifies the reusable native actor boundary, not its installation into a
running game. Qualification: `native_gameplay_postmove_view_qualification_v1.json`.

The `object_interactions` companion now mutates the existing canonical32-record
owner through one restricted friend, with checked mutable access and ordinal
resolution kept private. It implements capacity counts, transition admission,
primary requests, secondary claims, decay, signed-selector transfers and type
parameter queries. Authored selector equality precedes masking, so33and1retain
distinct transfer behavior even when they address the same physical record.
The parameter fallback3C4CC8is exactly physical record31.type, while native
ObjectIds retain domain checks independently of those source ordinals.

Both compilers pass622,794checks across45,640actions in seven retail resource
sets plus seven synthetic type/direction variants. Seven explicit alias-transfer
cases and14signed request wraps are compared against unchanged original bodies.
The private-access addition also passes the unchanged import/occupancy corpus
on both compilers:15,903checks, seven rooms and2100classifications. Prior
qualifications preserve their recorded source cohorts; this refreshed cohort
records the additive private owner interface. Instance lifetime, directional
occupancy/approach consumers and game installation remain separate work.
Qualification: `native_gameplay_object_interactions_qualification_v1.json`.
