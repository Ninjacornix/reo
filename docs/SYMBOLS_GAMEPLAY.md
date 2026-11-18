# Outbreak function mapping: gameplay, animation and graphics

Static investigation, 2026-11-03, following [the first mapping pass](SYMBOLS.md).
This pass adds 44 guest entry mappings. These are research labels, not recovered
original symbols, tested replacements, or a complete map of the game.

No game process, build, replay, benchmark, debugger attachment, or new capture
was started. Existing source and historical notes were read; only Markdown
documentation was changed. The user's ongoing playtest was not attached to,
controlled, or used as a new measurement source.

## Target and reading rules

Same File #1 US ELF identity as the first pass:
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
Working checkout has existing local edits; original instruction comments and
emitted operations are the static evidence used here. Historical native/PCSX2
observations are attributed to their source documents and were not repeated.

`o0` and `o2` below identify generated source partitions and their associated
overlay maps, not an assertion that they equal the runtime overlay ID. Existing
scenario notes associate common `BIN/0.DAT` with runtime ID 1 and `BIN/2.DAT`
with runtime ID 3. Keep image identity, load base and entry together when binding.
See [scenario runtime notes](SCENARIO_RUNTIME.md).

**Confirmed/static** means instructions establish the narrow behavior stated.
**Probable** describes a supported subsystem interpretation. **Speculative**
marks a guess that should not be used to change execution yet. All proposed
names remain local documentation; no Ghidra symbols or generated functions were
renamed. A sampled PC inside a function is not automatically a new entry point.

## 1. Scenario state, room requests and scripts

| Guest entry / source | Proposed label | Confidence | Evidence and limits |
| --- | --- | --- | --- |
| [o2 0x5FE360](../recomp/config/output_ovl/o2/o2_005FE360_0x5fe360.cpp) | `scenario_task_callback` | Probable | Calls initializer `0x5FE3C0` and state dispatcher `0x5FE440`. Historical task investigation identifies slot 4 at `0x3163D0`, callback +4. Exact task scheduling frequency is not established by this wrapper alone. |
| [o2 0x5FE440](../recomp/config/output_ovl/o2/o2_005FE440_0x5fe440.cpp) | `dispatch_scenario_phase` | Confirmed/static | Reads signed phase byte `0x4BADD0`, bounds-checks against 16, then dispatches via table `0x73F260`. Direct branches call phase handlers including `0x5FE7C0`, `0x5FEA30`, and `0x603C20`. This is a substantially broader boundary than one actor input callback. |
| [o2 0x5FEA30](../recomp/config/output_ovl/o2/o2_005FEA30_0x5fea30.cpp) | `scenario_active_phase_service` | Probable; phase association supported | Phase-2 target of dispatcher. Contains UI/request gates and changes `0x4BADE8`: a +1 path at `0x5FEAE8..0x5FEB00` and a separate +0x96 path around `0x5FEB50`. Therefore entry count and raw counter delta must not be assumed to equal unique gameplay updates. Candidate coverage boundary for later investigation, not an approved clock hook. |
| [o2 0x603C20](../recomp/config/output_ovl/o2/o2_00603C20_0x603c20.cpp) | `opening_cinematic_and_initial_load_state` | Probable | State 0xE; substate handling calls movie/audio services and room/script services. Historical instruction analysis identifies Start skip branches, a 90-guest-frame wait, and transition to loading substate 6. Covers opening prerecorded movies; not established as the handler for every in-engine cutscene. |
| [o2 0x5EBE30](../recomp/config/output_ovl/o2/o2_005EBE30_0x5ebe30.cpp) | `ensure_room_resources_for_cache_key` | Probable | Compares cached scenario/room/variant bytes near `0x7434B0`; calls room/background/script/collision setup and memory-routing helpers. Cache identity and resource ownership must be recovered before considering reuse across room changes. |
| [o2 0x5F0380](../recomp/config/output_ovl/o2/o2_005F0380_0x5f0380.cpp) | `consume_scene_request_queue` | Confirmed/static queue; probable scene role | Reads the 16-entry ring at `0x3B26D0`, stride 16, using queue indices `0x3B27D0/0x3B27D8`; publishes request fields near `0x38ECCF..0x38ECE0`. Different request types call `0x371AD0/0x371B70` and `0x6DE480/0x6DE590`. Exact semantic names for every request field remain provisional. |
| [o2 0x68C660](../recomp/config/output_ovl/o2/o2_0068C660_0x68c660.cpp) | `run_room_script_channel` | Probable; indirect dispatch explicit | Uses per-channel instruction/continuation state around `0x4BACE0/0x4BACF8`, handler table `0x717830`, and indirect call at `0x68C728`. Handler return codes control continuation/yield behavior. A script yielding intentionally is not evidence of an unimplemented opcode. |
| [o2 0x68C850](../recomp/config/output_ovl/o2/o2_0068C850_0x68c850.cpp) | `start_primary_room_script_channel` | Confirmed/static | Sets channel selector `0x4BAD10=0`, loads initial pointer through `0x324424`, stores it at `0x4BACE0`, and tail-calls `0x68C660(0)`. Suitable for identifying script start, not all subsequent script progress. |
| [o2 0x68C7B0](../recomp/config/output_ovl/o2/o2_0068C7B0_0x68c7b0.cpp) | `tick_eight_script_countdowns` | Confirmed/static | Visits eight signed-halfword timers at `0x4BAD88 + 2*i`; decrements only positive values. On reaching zero, reads action at `0x4BAD98 + 2*i`, uses bit 0x8000 to choose `0x5705F0` or `0x5703E0`, passes low 15-bit id. Broader than the existing override's escape-timer label: each slot's purpose is not yet known. |

Supporting historical source:
[scenario investigation](M2_SCENARIO_INVESTIGATION.md). Generated instruction
implementations were inspected in this pass; exact runtime callback registration
and all dynamic table targets were not independently revalidated.

## 2. Room data setup and loading

| Guest entry / source | Proposed label | Confidence | Evidence and limits |
| --- | --- | --- | --- |
| [0x1D1F50](../recomp/config/output/sub_001D1F50_0x1d1f50.cpp) | `select_room_background_resource_bank` | Probable | When mode byte `0x3243D7` permits, packs three byte-sized identifiers, toggles byte `0x5697B8`, selects alternating base 0x1800/0x1880, and calls `0x1CDE10`. This is a selector/setup wrapper; actual transfer may occur below it. |
| [0x1D0A70](../recomp/config/output/sub_001D0A70_0x1d0a70.cpp) | `load_room_object_resources_candidate` | Probable | Selected by room loader; calls `0x1CD1C0`, allocates through `0x1B2A70`, reads through `0x1CE110`, and initializes object-related state. Exact binary format and post-load ownership remain unproven. |
| [0x1D0C80](../recomp/config/output/sub_001D0C80_0x1d0c80.cpp) | `load_room_script_and_event_data` | Probable | Calls resource selection/read/allocation helpers, then populates counts/pointers. Historical filename evidence identifies `%sr%03d/e%03d%02d%02d.bin`; a zero read can leave counts unset. No assumption that successful allocation implies successful room initialization. |
| [0x1D25A0](../recomp/config/output/sub_001D25A0_0x1d25a0.cpp) | `room_collision_load_adapter` | Probable role; confirmed routing | Tail-calls `0x1CE3F0`. Historical caller/filename evidence associates this path with ST_HIT wall/ground data. Body alone does not establish the collision file parser or all allocations. |

Do not merge the room-cache check, request queue, host file read, byte relocation,
and scene activation into one presumed synchronous load. Those boundaries can
carry different lifetimes and completion conditions.

## 3. Animation, skeletons and shared math

| Guest entry / source | Proposed label | Confidence | Evidence and limits |
| --- | --- | --- | --- |
| [0x18EEB0](../recomp/config/output/sub_0018EEB0_0x18eeb0.cpp) | `find_animation_key_interval` | Probable animation meaning; interval mechanics explicit | Follow-up verifies signed16 cubic keys, eight-byte spacing, signed time at +2 and relative pointer from descriptor +4 plus global 0x294160. Clamps first/last endpoints and exact keys to one output pointer; otherwise walks backward/forward from a clamped signed16 cache hint to a strict bracketing pair. No count-zero/order/finite-time validation. See the six-format family in [animation notes](SYMBOLS_ANIMATION.md); a replacement still needs arithmetic and malformed-input admission checks. |
| [0x18E710](../recomp/config/output/sub_0018E710_0x18e710.cpp) | `sample_short_key_animation_channel` | Probable | Signed16 cubic sampler: calls 0x18EEB0, stores selected index to halfword cache. Singleton value +0 converts signed16 to float; pair values/time at +0/+2 and outgoing +6/incoming next +4 tangent candidates go to 0x18F260. Quantization scaling belongs to caller. This mutates cache, unlike a pure sample lookup; see [animation notes](SYMBOLS_ANIMATION.md). |
| [0x18F260](../recomp/config/output/sub_0018F260_0x18f260.cpp) | `evaluate_cubic_hermite_segment` | Probable; polynomial structure strongly supported | VU0 macro instructions compute normalized time and cubic basis terms from supplied values, frame positions and tangents. Six-format dispatch review confirms float and signed16 cubic/mixed callers; historical asset work independently associates Hermite root-motion sampling. Preserve reciprocal Q, guest operation order and interval-zero behavior before host replacement. Later routines share the source file: isolate this catalogue interval. |
| [0x192B70](../recomp/config/output/sub_00192B70_0x192b70.cpp) | `clear_animation_links_in_selected_subtree` | Confirmed/static tree operations | Compares node id +0xC6; clears animation pointers +0xD4/+0xD8 and follows parent/sibling/child links at +0xC8/+0xCC/+0xD0. The initial body returns at `0x192BE8` (including its delay slot); adjacent routine begins `0x192BF0` and makes calls. Treating the whole generated file as one routine would misattribute those calls. |
| [0x193140](../recomp/config/output/sub_00193140_0x193140.cpp) | `sample_animation_for_node_tree` | Probable | Works with animation pointers +0xD4/+0xD8 and node id +0xC6, copies ten floats +0xDC to +0x104, calls `0x193C80/0x1939A0`, then recursively processes child +0xD0 and sibling +0xCC. Sampled PC `0x193178` is the ten-float copy loop, not a function entry. Exact pose-component meanings remain unknown. |
| [0x18F570](../recomp/config/output/sub_0018F570_0x18f570.cpp) | `sincos_with_original_range_reduction` | Probable trig meaning; range-reduction operations explicit | Compares input with constants, uses VU0 VI registers and coefficient tables, produces a pair consumed by rotation helpers. Existing divergence notes describe a corrected VI2 transfer. Do not substitute host `sin/cos` without checking PS2 arithmetic and edge cases. |
| [0x190A10](../recomp/config/output/sub_00190A10_0x190a10.cpp) | `rotate_matrix_xyz_euler_candidate` | Probable convention; three successive axis stages explicit | Corrected in pass 4: the initial X stage continues into Y and Z stages before the first return at 0x190B98. Calls `0x18F570` with f12, then f13 at 0x190A98, then f14 at 0x190B18; each stage updates the first three matrix vectors through VU0 macro instructions. A separate entry starts at 0x190BA0. Multiplication side, angle units and floating-point contract still need verification; see SYMBOLS_DISPATCH.md. |

Example structure for later reconstruction, not executable replacement code:

```text
sample_channel(track, time, cached_interval):
    find the original one-key or two-key interval
    update cached_interval as the original does
    if one key: return float(signed_short(key.value))
    otherwise: evaluate original Hermite polynomial with the original
               endpoint values, key times and in/out tangents
```

The expensive part may be the number of channels/nodes, data access, or
arithmetic; a recognizable formula alone does not establish a performance win.
Historical malformed-tree failures are in
[the scenario investigation](M2_SCENARIO_INVESTIGATION.md); they do not prove a
tree corruption issue in the user's current playtest.

## 4. Camera writers and controller conversion

| Guest entry / source | Proposed label | Confidence | Evidence and limits |
| --- | --- | --- | --- |
| [o0 0x375800](../recomp/config/output_ovl/o0/o0_00375800_0x375800.cpp) | `apply_camera_local_motion_and_target` | Probable | Builds temporary transform, transforms offsets, adds to position vector `0x324138..0x324140`, then writes target vector `0x324144..0x32414C` and calls `0x375920`. Position/target interpretation agrees with existing snapshot tooling. Inputs and all camera modes need recovery. |
| [o0 0x375920](../recomp/config/output_ovl/o0/o0_00375920_0x375920.cpp) | `publish_camera_projection_and_view_parameters` | Probable | Selects width-like 0x200/0x280 value at `0x324128`, computes projection-related values via `0x18F6A0`, and sends parameter ids 0x18/0x16 through `0x1AF780`; calls `0x375A50`. Exact projection matrix convention remains unknown. |
| [o2 0x5BF7B0](../recomp/config/output_ovl/o2/o2_005BF7B0_0x5bf7b0.cpp) | `update_room_camera_transition_candidate` | Probable camera role; transition interpretation provisional | Compares a camera-record identity against cached state near `0x3DDDC8`; smooths a value with division by 6, resolves another record via `0x5BE930`, and writes position/target vectors. Determine whether each branch represents a fixed camera blend, tracking, or another authored camera mode. |
| [o2 0x5BF300](../recomp/config/output_ovl/o2/o2_005BF300_0x5bf300.cpp) | `update_actor_related_camera_candidate` | Probable camera role | Resolves an actor slot from `0x3DDDD4` using actor base/stride, reads camera record state, smooths cached quantities by 1/6, and writes position/target vectors. Exact relationship to cutscene cameras or normal room cameras is not established. |
| [0x1A6090](../recomp/config/output/sub_001A6090_0x1a6090.cpp) | `convert_raw_stick_axis_deadzone` | Confirmed/static transformation; named from call context | Per-axis piecewise thresholds use raw 87/168 and coefficient at `0x241F60`. Historical recovered coefficient was approximately 1.46. Separate from the player's secondary configurable deadzone. |
| [0x1A6480](../recomp/config/output/sub_001A6480_0x1a6480.cpp) | `compute_stick_angle_and_magnitude` | Probable | Two-axis math through numerical helpers, stores halfwords at output +4/+6 and clamps magnitude around 128. Exact angle units/sign convention require checking all input quadrants. |
| [o2 0x6621F0](../recomp/config/output_ovl/o2/o2_006621F0_0x6621f0.cpp) | `map_camera_relative_stick_to_actor_actions` | Probable; threshold historically verified | Uses actor input magnitude +0xF98 with gate 16, camera position/target, and actor yaw to build movement/turning actions. Normal idle and special states can follow different branches. |

Supporting sources:
[input/facing investigation](M2_INTERACTION_FACING.md),
[snapshot camera fields](../tools/ps2_debug/m2_scenario_ram_state.py).
The camera writers were located by their actual stores to the shared vectors;
filenames or an apparent smoothing constant alone were not used to identify them.

## 5. Collision, movement and interaction

| Guest entry / source | Proposed label | Confidence | Evidence and limits |
| --- | --- | --- | --- |
| [o0 0x370C70](../recomp/config/output_ovl/o0/o0_00370C70_0x370c70.cpp) | `point_in_polygon_fan_candidate` | Probable geometry role; mechanics verified | Follow-up corrects the earlier triangle-only label: a0 is vertex array of float pairs at eight-byte stride, a1 query point, a2 vertex count. First sums guest cvt.w.s orientations of consecutive triples via0x370AC0 to select winding. Then classifies fan triangles anchored at vertex0 via0x370B00, accumulates a signed8 score, returns score>0. Count<=2 returns0; no generic convex-polygon or safe edge-equivalence claim. See [overlay math](SYMBOLS_OVERLAY_MATH.md). |
| [o2 0x617000](../recomp/config/output_ovl/o2/o2_00617000_0x617000.cpp) | `query_floor_triangle_list` | Probable | Floor bankB bounds0x616720 and cell list0x6172F0 precede triangle traversal. Passes vertexcount3 to generic polygon fan0x370C70 using worldX/Z. Requires planeYcoefficient>0, selects highest plane height strictly below inputY+100, publishes normal/type/mask and optional matrix. Sample return PC0x617158 belongs here,not a hardware wait. See [collision grid contracts](SYMBOLS_COLLISION_GRID.md). |
| [o2 0x666BB0](../recomp/config/output_ovl/o2/o2_00666BB0_0x666bb0.cpp) | `query_actor_floor_support` | Probable | Calls rotation helper `0x191BC0` twice and floor-query path `0x616F20`; historical movement investigation connects it to actor floor sampling. Probe offsets and all fallback surface cases remain unknown. |
| [0x191BC0](../recomp/config/output/sub_00191BC0_0x191bc0.cpp) | `rotate_vector_xz_in_place` | Confirmed/static X/Z operation; trig labels probable | Preserves original XYZ temporarily, obtains trig pair through `0x1921B0`, writes only X/Z with multiply/accumulate arithmetic. Can be used by collision and movement; it is not itself a floor search. |
| [o2 0x65E3A0](../recomp/config/output_ovl/o2/o2_0065E3A0_0x65e3a0.cpp) | `build_rotated_actor_displacement_candidate` | Probable | Matrix helpers `0x18FDF0/0x18FE60`, angle rotation through `0x370320`, then `0x191300/0x1919D0`. Historical motion investigation associates it with rotated animation displacement. Distinguish extracting displacement from committing actor world position. |
| [o2 0x66CFE0](../recomp/config/output_ovl/o2/o2_0066CFE0_0x66cfe0.cpp) | `actor_pickup_interaction_state_machine` | Probable | Multiple actor substate branches, animation/UI helpers, and pickup-confirmation handler `0x5F49D0`. Historical snapshots identify selected pickup state and subsequent recovery. This is not the dispatcher for every actor action. |
| [o2 0x5F49D0](../recomp/config/output_ovl/o2/o2_005F49D0_0x5f49d0.cpp) | `pickup_confirmation_ui_service` | Probable | UI-type checks, selected-item handling and confirmation/cancel paths. Historical evidence maps actor edge 0x20 to confirm and 0x10 to cancel for this path. Do not generalize those action masks to all menus. |
| [o2 0x5F27B0](../recomp/config/output_ovl/o2/o2_005F27B0_0x5f27b0.cpp) | `insert_item_handle_into_first_empty_inventory_slot` | Confirmed/static insertion; larger inventory contract incomplete | Visits four bytes at actor +0xC84..+0xC87, fills first zero from item table byte `0x3C5632 + item_index*0x3C`, then tail-calls `0x5F2330`. It copies the table's handle, not necessarily the supplied index. Ownership/world removal and UI refresh may be outside this helper. |

Historical support:
[scenario movement/collision investigation](M2_SCENARIO_INVESTIGATION.md) and
[pickup/facing investigation](M2_INTERACTION_FACING.md). Those investigations
also show why a sampled arithmetic PC can coincide with a host suspension;
sampling a collision helper does not prove collision computation caused a stall.

## 6. Guest rendering and submission

| Guest entry / source | Proposed label | Confidence | Evidence and limits |
| --- | --- | --- | --- |
| [0x18CE30](../recomp/config/output/sub_0018CE30_0x18ce30.cpp) | `initialize_double_buffered_dma_packet_manager` | Probable; two-buffer setup explicit | Allocates two packet areas through `0x18DC50`, zeros per-buffer counts, installs/enables a callback via SDK wrappers, and installs an interrupt helper. Historical graphics analysis associates manager and callback with VIF1 DMA. This is initialization, not per-frame geometry production. |
| [0x18D160](../recomp/config/output/sub_0018D160_0x18d160.cpp) | `vif1_dma_completion_service` | Probable callback identity; counter update explicit | On qualifying completion state, decrements selected buffer's count at `0x18D224`; same storage is polled by `0x18D650`. Other branches manage packet chaining/completion. Preserve exact interrupt/ack behavior and queue order. |
| [0x196010](../recomp/config/output/sub_00196010_0x196010.cpp) | `set_render_parameter_by_id` | Probable renderer scope; selector/copies explicit | Byte-sized selector chooses parameter layouts. Ids 0x1A..0x39 copy 64 bytes into scratchpad `0x70003700 + (id-0x1A)*64`; ids 0x3A..0x59 copy 19 words into `0x294340 + (id-0x3A)*76`. Other ids dispatch helpers. Sampled PCs `0x196060/0x1960CC` are these bounded copy loops; neither is an independent entry or infinite wait. Generated file extends beyond this semantic routine. |
| [0x1AF780](../recomp/config/output/sub_001AF780_0x1af780.cpp) | `set_render_parameter_adapter` | Confirmed/static routing | Masks selector to eight bits in the branch delay slot and tail-calls `0x196010`. Camera publication and room setup use this API; exact original engine API name is unknown. |

The route between model traversal, matrix/parameter publication, VU launch,
GIF packet emission, and the host renderer remains only partially mapped.
Existing whole-program VU image hashes and native geometry kernels identify
execution implementations, but do not assign every image an engine-level
purpose. A compiled program count is not a runtime-cost distribution.

## 7. Prerecorded movie request and compressed-ring boundaries

| Guest entry / source | Proposed label | Confidence | Evidence and limits |
| --- | --- | --- | --- |
| [0x147D30](../recomp/config/output/sub_00147D30_0x147d30.cpp) | `mpeg_picture_request_mode_a` | Probable | Resolves inner object from outer +0x40, sets inner request fields including +0xF0 destination/+0xFC macroblock count and clears progress fields, calls `0x148170`. Mode details and asynchronous completion need deeper decoding. |
| [0x147D78](../recomp/config/output/sub_00147D78_0x147d78.cpp) | `mpeg_picture_request_mode_b` | Probable | Similar request fields, different +0xC8 initialization, calls same worker. Generated file includes adjacent variants; keep entry-specific behavior separate. No claim that either mode decodes an in-engine cutscene. |
| [0x170AE8](../recomp/config/output/sub_00170AE8_0x170ae8.cpp) | `initialize_compressed_movie_ring` | Probable | Initializes base/capacity/tag-related fields and creates a semaphore before `0x170B60`. Existing original-boundary observer identifies this as the compressed IPU1/B400 ring initialization. Constructor arguments and alias classes require verification. |
| [0x170D90](../recomp/config/output/sub_00170D90_0x170d90.cpp) | `commit_compressed_ring_bytes_candidate` | Probable | Semaphore-bracketed count update at ring +0x14. Adjacent operations/continuations share its file. Exact committed-byte units, wrap constraints, and argument validation need recovery from callers. |
| [0x171D10](../recomp/config/output/sub_00171D10_0x171d10.cpp) | `service_movie_picture_request` | Probable | Connects compressed submission through `0x171160`, ring state, decoder object work +0xA00 and calls to `0x147D30/0x147D78`; later continuation updates request/result state. Multiple registered continuation PCs are significant and must survive any reconstruction. |

Existing sources:
[picture-boundary observer](../recomp/overrides/reo_gpu_movie_boundary.h),
[continuation observer](../recomp/overrides/movie_join_observer.h).
This is the prerecorded movie path. In-engine cutscenes normally need actor,
animation, camera, scripts and rendering evidence instead; no shared bottleneck
has been demonstrated merely because both appear cinematic.

## 8. Best next targets and remaining gaps

| Goal | Candidate | Evidence needed before changing implementation |
| --- | --- | --- |
| Better slowdown attribution | Scenario dispatcher/active-phase boundary plus script channels | Establish clock writes, phase gates, pause/loading behavior and deduplication across modes; do not simply count function calls. |
| Compact semantic reconstruction | Key interval search and Hermite channel sampler | Exact endpoints, cached-index updates, signed values, tangent scaling, PS2 floating-point behavior, and ABI/resume checks. |
| Explain recurring sampled PCs | Skeleton traversal and render parameter setter | Per-call count/size and parent timings; bounded helper samples may just reflect frequent calls. |
| Investigate in-engine cutscenes | Camera writers + actor pose/script chain | Determine active camera mode, actor update owner and render order in the actual scene. |
| Reduce rendering overhead | Parameter publication, DMA producer/completion and model traversal | Identify redundant operations with dependency/lifetime evidence. Do not skip completion checks or cached-state writes based on guessed redundancy. |

Still unknown: complete main-loop/task graph, every actor/enemy state table,
all collision and event kinds, all camera modes, full model/material formats,
and semantic purposes of all VU images. The first and second notebooks provide
entry points for that work, not a claim that these subsystems are fully decompiled.

Validation for this documentation pass: source links and Markdown whitespace
checked. Runtime behavior, semantic equivalence, performance gains and compile
time gains were not tested, in accordance with the ongoing playtest constraint.

The subsequent [central function index](FUNCTION_INDEX.md) makes these mappings
searchable alongside catalogue entries, calls and references. It preserves the
confidence levels above and provides a ranked list for further static mapping.
