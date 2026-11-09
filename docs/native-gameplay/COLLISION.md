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

The `object_lifetime` companion now owns typed Entity-derived room-object
instances in a borrowed native scene-instance domain. Logical ObjectId, native
EntityId, authored model slot and physical object ordinal remain distinct.
It constructs and publishes pose/material state, reconciles actual shared proxy
handles in source release/create order, processes6AEBE0motion completion and
6B1010request reset, and implements enable/first-disable with dynamic rebuilding.
Model lookup/binding is an explicit native service. Instance1F0XYZ is the
translation row of basis1C0, not a second previous-position field; hidden-instance
updates publish position200XYZ into that native pose translation.

Both compilers pass87,478checks with zero error:21room/variant cases,33instances,
264updates,21first-disables,14retained top proxies,153dynamic rebuild comparisons
and21full64-instance pool cases. Seven retail resource sets plus capacity/
direction and missing-model variants execute unchanged constructor,64resource
pool,128proxy pool, movement, disable and rebuild bodies. Floor, model-binding,
scalar matrix and previously qualified trace surroundings are declared providers.
Owner-derived center caches are compared after the original publish operation.

The source disable retires proxies0/1/2without clearing their record handles and
does not retire slot3. Native retains those tokens and the old top proxy, while
generation checks reject stale ownership. Raw repeated-release/reuse after that
point is not claimed as defined equivalence. Explicit native scene close releases
retained handles and only this component's instances, preserving unrelated scene
occupancy. This is an owned native scene boundary; canonical SceneOwner/game-loop
installation and directional approach/occupancy consumers remain separate work.
Qualification: `native_gameplay_object_lifetime_qualification_v1.json`.

The `object_queries` companion now covers padded static-mask checks, four leading
edges, actor-combined occupancy admission, direction classes, elevated lookup,
entry/exit height and capacity rules, approach coordinates, transformed probes
and nonexplicit height offsets. Canonical combined occupancy is passed by
reference and changes only after the source admission gates. Native object
identity and full authored selector tokens remain separate.

Both compilers pass1,275,110checks over2112queries in seven retail resource sets
plus seven positive-capacity/direction variants, with zero error and no unknown
mask reads in this corpus.1056blocked-entry comparisons correct a prior notebook
claim:6AF8F0clears v0 in the unconditional branch delay slot, so6AF8B0returns zero
when transitioning or already at capacity, not an inherited selector. A separate
31-object fixture proves the source49.5-height case: positive height band but
failed elevated lookup leaves unsignedFF, which resolves physical31and can
decrement its count. The native result flags that fallback explicitly.

Out-of-owned-mask or unrepresentable positions have explicit capability statuses;
this corpus does not claim parity with unrelated out-of-bounds source reads.
Scalar probe transforms and the previously qualified actor occupancy provider
are declared math surroundings. Actual canonical game consumers remain the
integration owner's work. Qualification:
`native_gameplay_object_queries_qualification_v1.json`.

The `actor_views` companion now supplies the ordered32-entry body solver and
auxiliary boundary through direct scalar references. Generic XYZ refs accept
different native vector types without casts; byte flags bind the existingC53and
10A9fields without introducing duplicate contact/boundary state. Shape definitions,
priorities, counters, native peer identity and summaries can bind canonical actor
components while model-joint poses remain borrowed for the synchronous call.
Caller admits live identity-qualified views and retains their owner/pose leases;
the registry validates required IDs, unique roster identity and joint ranges
before writes, then retains only registration IDs until its drain point.

Both compilers pass the generic81,831-check corpus:1000four-actor solves,
200ordered boundary cases and three explicit generic-vector/byte-flag cases.
The separate canonical World corpus passes49,080checks on each compiler using
World-spawned actors and strong leases:1000four-actor solves,200boundary cases
and a retirement/replacement case. Position, previous and candidate direction,
body definitions/priority/counter/peer/summary, C53room_marker and10A9transient_marker
are direct canonical bindings. Missing old-generation admission refuses writes
to the replacement while an existing lease keeps the retired actor alive.

All compared outputs match unchanged original actor solver/boundary bodies with
the existing declared scalar shape/math surroundings. Pose/shape data is admitted
synthetic content in this corpus; a stock model-pose importer and actual game-loop
installation are separate responsibilities. The historical owning Actor API and
its source cohort remain unchanged. Qualification:
`native_gameplay_actor_views_qualification_v1.json`.

## Standalone actor metadata

`actor_metadata.hpp/.cpp` implements the separate `6F14F0` post-pose summary through the same borrowed native actor view. A missing definition preserves the old summary. A sphere stores its sampled X/Z with exactly zero half-length and heading; this differs from the registry's `6F1430` sphere heading convention. Capsules retain the original midpoint, horizontal half-length narrowing and heading conversion. This path never consumes the registry's accumulated push.

The LLVM and GCC cohorts each compare 8,000 cases and 27,766 checks against the unchanged, owned-byte-audited original body and qualified shape samplers: 3,765 spheres, 3,764 capsules and 471 absent definitions, with zero error. The cases include nonpositive radii, paired joints, root centers and nonzero stale registry scratch. Native production keeps actor fields by reference. Synthetic pose admission is qualified; stock model/pose import and installation in the running actor schedule remain separate gates. Evidence: `tools/native_reconstruction/native_gameplay_actor_metadata_qualification_v1.json`.

## Secondary actor ground pass

`secondary_ground.hpp/.cpp` ports the separate `637740/637860/6379D0` consumer through borrowed native actor fields. The native scene owner supplies live identity-qualified entries in original reverse-list order; the pass does not add an activity filter or retain references. Controls bit `20` adds the canonical saved displacement; the other branch invokes a required native wall provider. Subtypes `1/29/2D` select separate signed probe-state bytes, while other types use ordinary secondary floor publication. This is distinct from the primary actor surface/rollback policy.

Floor publication retains height, normal, type, material and attributes, requeries type 1 when selected, and snaps Y only when byte BA5 (bits 8..15 of the canonical auxiliary status word) is zero. Probe states -1/0 rotate local Z -18/+18 through the full actor Euler basis, add only rotated X/Z and retain current world Y. State 1 probes the current position. The classifier first requires a type-1 floor, then obtains the unfiltered floor's basis. The unchanged owned `371480` body confirms that its unit-Y direction is the supplied normal. Exact zero X uses the owned epsilon, then heading conversion, signed-turn delta and strict `3000/5000` thresholds select -1/0/1. This is a heading classification, not a physical slope-angle test.

LLVM and GCC each pass 179,001 checks with zero error: 1,600 four-actor ordered passes, every 16-bit heading, all 183 owned floor resources and 4,144 triangle-centroid classifications/offset probes. Full original pass, surface wrappers, floor selection/relocation/lookup and basis construction execute unchanged against owned instruction words. Euler/direction math is a declared port bound to the independent full-original transform cohort; wall response is a declared provider whose production solver has its own qualification.

The 253 incoming state bytes outside {-1,0,1} lead to uninitialized probe coordinates in the original. Native code keeps the already-performed floor updates, returns `uninitialized_source_probe` and does not invent coordinates or overwrite the classification. Those refusal tests are separate from original defined-case comparisons; stock runtime reachability is unknown. Native secondary scene ownership, admitted stock state/pose content and actual game scheduling remain integration gates. Evidence: `tools/native_reconstruction/native_gameplay_secondary_ground_qualification_v1.json`.

## Canonical contact response core

`contact_component.hpp` is supplemental canonical actor data, installed once as `World::Actor.contact`. Existing `HitActor` fields still own damage/progression/pending fields, reaction kind, response flags and source identity. `Actor.normalized_marker` is the original byte32 cooldown; `Actor.character` is B98; `HitActor.slot` is byte3. None is duplicated by the contact component. Component IDs reference the native actor owner, while authored byte6 and class-specific identity tokens retain their original separate meaning.

`delivery.hpp/.cpp` implements native borrowed-view preparation (`5DC3A0`), provenance (`578F60/5790E0`), response probability/code changes (`578EA0/578F10`), category-pair selection (`57B650`), multiplier rules (`6683E0`) and both contact-value calculators (`5A87A0/5A8A50`). It preserves serial byte wrap, aliased source/recipient cases, the source's asymmetric related-recipient identity selection, exact base-zero and forced multiplier gates, RNG and vibration admission order, integer weight division before signed16 narrowing, distance boundaries, selected ID boost, and the two different special-ID policies. Unadmitted category content returns an explicit status.

LLVM/GCC each pass 968,675 original-body checks: 16,000 provenance/alias cases, 40,000 numeric value cases, 12,000 probability/RNG cases, 1,536 cooldown/queue cases, and every one of 65,536 actor-category pairs. Original RNG executes against its own copied state; native code uses the canonical session RNG. Source helpers execute unchanged after owned image/word verification, with declared scalar distance and authority/vibration surroundings. This is a core qualification using synthetic admitted native tables; actual stock table/descriptor import, ordered scanner delivery and packet lifetime/effect services remain separate consumers. Evidence: `tools/native_reconstruction/native_gameplay_delivery_core_qualification_v1.json`.

## Ordered contact scan delivery and explicit direction candidate

`contact_scan.hpp/.cpp` connects qualified segment/margin/angular geometry to canonical `HitActor` and `Actor.contact` response writes in original traversal order. Repeated recipient IDs remain repeated visits. Per-actor segment queries choose the nearest region; margin/angular queries use the first hit. Global paths retain a separate selected actor and last-scanned actor, including filtered entries. Damage accumulation remains on the selected actor, while the original global clamp reads and writes the last-scanned actor's own word138. Strict new-distance comparison preserves first equal/unordered hits. Recipient/scene mask belongs to packet19 (copied from descriptorC), not template byte5.

The response sequence preserves pending-byte wrap, category/value/random branches, retained multiplier, accumulator clamp, priority overwrite, stochastic flags, recorded identities, asymmetric provenance, point/vector space, region and response-code conversion. Typed synchronous services own occlusion, authority/vibration, class2 C94bit1000 and traced-mark emission. `5719D0` receives read-only point/direction inputs for an effect; it does not nudge the caller's endpoint. An unknown uninitialized caller point refuses that effect after retaining known preceding response writes. No production code creates guest-address packets or calls generated senders.

The default `DirectionPolicy::require_known_tail` preserves the global margin/angular admission limit: after numeric/priority/provenance/point writes, the original reads queryStart minus the advanced final actor-region pointer. Inline AEC storage can put that address at B1C/B20/B24, including unrelated behavior state/pointer bits. Native Regions owns the actual used points and cannot invent a tail. The default returns `unknown_advanced_direction` without later region/code writes.

An explicit, opt-in `selected_region_repair` candidate uses queryStart minus the saved selected region center, following the per-actor geometric pattern. It is a deliberate source bug repair, not original parity or a measured slowdown fix. Every unaffected final field and RNG/service order is checked against the original, while repaired direction is checked against complete original `191D80` on the selected center. Future running-game use requires explicit candidate selection and controlled acceptance.

Both compilers pass 133,529 checks across 2,402 full scan cases: 2,166 default complete cases, 236 separately checked source-unknown prefixes, 536 separately checked candidate cases, 1,507 distinct selected/last-scanned cases and 472 traced-mark calls. Inline arrays use 0/1/3/4 regions, changing tail values/pointer-shaped bits, equal actor/region ties and zero selected-center direction. These are original-body/native library tests, not a live game run. The coincident directed point case also exposed a zero denominator in the previous native helper: native `directed::contact` now uses a finite maximum scale as the original inline `6F127C` guard does. Refreshed directed cohorts execute complete `191D80` and pass 110,933 checks each, with zero error. Evidence: `tools/native_reconstruction/native_gameplay_contact_scan_qualification_v1.json` and refreshed `native_gameplay_directed_qualification_v1.json`.

The pure spatial strict-comparison correction is qualified below. Stock contact-content import, packet pool/lifetime/shape consumers, real native effect providers and canonical game-loop installation remain concrete work.

## Pure spatial strict nearest revision

The callable pure `spatial::scan` now uses the private `nearest.hpp` first-hit/strict-less policy. The previous negated non-strict comparison had the same finite ordering but replaced a selected hit on unordered distances, whereas the original `57A268/57A2F8/57B238` branches retain the first hit. The full ordered contact delivery path already had the correct strict comparison.

The refreshed complete spatial cohorts pass LLVM 209,839/GCC 209,886 checks, including 7,003 primitive cases, 2,000 finite scans, 4,096 policy cases and 67,089 owned edges, with zero error. A separate fixture drives complete original scanner control flow with controlled geometry outputs and compares the exact private policy used in production: both compilers pass 146,425 checks across 16,384 cases, 3,474 first-NaN deliveries, 5,280 equal-distance retentions and four empty cases. Controlled geometry is explicit; this does not assert those nonfinite points arise from stock poses or from every primitive. No test-only public geometry API or runtime mode was added.

Directed and full response-scanner dependent receipts were refreshed against the changed source dependency. Evidence: `tools/native_reconstruction/native_gameplay_spatial_selection_qualification_v1.json` and refreshed spatial/directed/contact-scan qualifications.

## Owned native contact content

`contact_content.hpp/.cpp` supplies an immutable native `Catalog` of typed shapes, response definitions and value tables. The build-time `import_gameplay_contact_content.py` reads the user's ISO `BIN/2.DAT` directly, verifies the decoded o2 hash and writes a 69,234-byte `REOCNT01` asset. Runtime parsing needs no Python, original addresses, original instructions, relocation or private analysis folders. Named values and native indices replace descriptor pointers; individual strong definition leases survive catalog retirement. Input bytes are copied into owned native data, and partial/invalid archives refuse before publication.

The source-bound physical descriptor windows are bank0 `71BDE0..71FDDF` (512 records), bank1 `714710..71586F` (139), and bank2 `709980..709A1F` (5). All 656 are converted, including reserved zero-lifetime records; 320 are active. Referenced shape selectors cover 655 non-null geometry records across segment, sweep, margin and angular shapes. The bank2 zero-lifetime/null geometry entry stays inactive. Physical windows are not invented valid runtime caller ranges.

Converted numeric content includes the literal 100 strided multiplier fields, 128 signed weights, 72 physical category roots with 19 owned 128x3 value tables and 53 null fallbacks, the flat 128x3 table, and 89 exact signed random selectors carried by active descriptors whose two read windows lie in owned data. It does not import all readable overlay bytes as a damage table. Bases -2400 and 9999 remain valid generic descriptor scalars and are covered by ordinary category/flat calculations; their combination with pair1/3 random-table routing would read original text/outside owned data and stays explicitly unadmitted until source caller admission is established. No stock execution of those combinations is claimed.

LLVM and GCC each pass 157,631 checks: full original `5DA040/5DA0D0/5DA2C0` initialization/attachment agrees with every native bank definition, 655 shape records retain exact float/joint fields, 138,240 original value-helper cases use the converted stock tables and 1,280 stock multiplier/RNG cases match. Definition lifetime and truncated/trailing archive checks also pass. This qualifies immutable content, not native packet lifetime, shape/event scheduling, real model pose ownership or actual game integration. Evidence: `tools/native_reconstruction/native_gameplay_contact_content_qualification_v1.json`.

## Native contact packet ownership

`contact_packets.hpp/.cpp` owns the 64 live attack packets in a private native entity domain. Opaque generation-qualified packet IDs replace original record addresses. Insertion and unlink preserve the original head/tail order; packet attachment retains a strong immutable content definition and the actual native source/related actor IDs. Full capacity drops an attachment without altering the list. Retirement refuses stale or foreign IDs while an invocation lease safely retains its old record. Closing the owner retires all active packets and leaves any retained lease disabled; it cannot allocate again.

LLVM and GCC each pass 1,099,412 checks against the complete unchanged `5DA040/5DA0D0/5DA1C0/5DA2C0` bodies: 5,698 mixed allocation/release operations, all 656 stock attachments and 2,297 retirement cases. Comparisons include every active bidirectional link, head/tail order, free count, initial typed state, packet fields and repeat/foreign/closed identity refusal. Original repeated release after retirement is unsafe; native refusal is checked separately and does not claim parity with that undefined ownership violation. No gameplay was launched. Packet update/geometry/effect services and canonical running-game installation remain separate work. Evidence: `tools/native_reconstruction/native_gameplay_contact_packets_qualification_v1.json`.


## Packet update service and route batching

`packet_service.hpp/.cpp` implements the ordered `5DA720` pass on the native packet owner and canonical actor/session views. It walks tail-to-head and reads the next predecessor after callbacks, allowing a newly inserted head to participate in the same pass. Source inactivity/notice release, disabled/pause reset, startup, lifetime and cooldown retain separate byte arithmetic and order. Clock mode selects the original one/two decrement; 255 lifetime remains infinite. Shape queries precede provenance restoration, sound and route effects; contact counters use the original strict maximum test. The required route consumer runs before target enrollment is cleared. Partial provider refusal retains preceding mutations and the unconsumed queue instead of replaying an original implementation.

LLVM/GCC each pass 947,771 checks: 17,536 complete original pass cases include all 256 startup/lifetime/cooldown values under both clock modes, 1,487 routed contacts, 256 mixed head/tail insertion cases with synchronous new-head creation, and separate native query/close/finalizer refusal cases. The complete unchanged pass, pool and provenance bodies run against owned words. Shape handlers, sound, authority, room masks and route finalization are declared controlled providers for this cohort; this does not claim stock geometry or actual game installation. Evidence: `tools/native_reconstruction/native_gameplay_packet_service_qualification_v1.json`.

`contact_routes.hpp/.cpp` implements the complete `680B40` batching policy. It reads only pending indices 0..23, keeps accumulators intact, performs live room/mask rereads and related-control destination rereads after effects, and stops immediately when ten entries are accumulated. Full destination fields index the mask before argument/serialization narrowing. Related lookup has an explicit admitted-empty result distinct from an unavailable owner. A retained native target rechecks its canonical identity on destination reads. Only authority result exactly 1 permits native typed batch submission; no guest-address packet is created.

LLVM/GCC each pass 6,756,003 checks across 12,000 complete original-body comparisons, including 4,898 full batches, 6,000 changing-target cases, negative/zero pending values, high room/edge bits, callback room/mask changes and separately checked unavailable provider cases. Original scene durability/flags, related-control lookup and event send are controlled surroundings in this cohort. The actual SceneControls adapter composition, shared canonical FlagState and native durability/effect consumers remain explicit integration work; no network send or game run occurred. Evidence: `tools/native_reconstruction/native_gameplay_contact_routes_qualification_v1.json`.
