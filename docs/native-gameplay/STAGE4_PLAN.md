# Stage 4: native gameplay and scheduling

Status, 2026-11-12. **Stage 4 is incomplete**. Continue through end-to-end
verification with multiple agents. The user is awake and has revoked the prior
sleep request: finish Stage4 and do not put the PC to sleep afterward.

- [Contact styles and actor channels](CONTACT_EFFECTS.md) now supply5DD270,
  571EC0/572030 and actual572290 weapon-pose refresh through the canonical visual
  pool and firing adapter. Both compilers pass65,536 signed selectors,384 channel
  cases and8,648 channel frames, plus5,242,880 policy states.5823E0 pose work and
  complete session/game acceptance remain open.

- [Resource flight effects](RESOURCE_FLIGHT.md) now run the full constructor and
  lifetime through the canonical visual pool, retained room traces, actual audio
  and firing adapter. Both compilers pass32,768 constructors,1,310,720 policy cases
  and12,408 owner frames, including matching nonzero PCM. Existing visual
  regressions pass. Contact/pose families and complete game acceptance remain open.

- [Transient weapon lights](TRANSIENT_WEAPON_LIGHTS.md) now supply the actual
  attack light constructor, both canonical light pools and linked-task lifetime.
  Both compilers pass1,310,720 callback states and77 owner/adapter cases;
  primary-light regressions also pass. Pose/contact effect families and
  complete session/game acceptance remain open.

- [Weapon actions](WEAPON_ACTIONS.md) now compose actual resource depletion,
  inventory removal/compaction, canonical counters, audio and firing preparation.
  Both compilers pass65,536 use/refresh cases and32,768 full firing-order cases,
  including bitwise matrices and changes during callbacks. Reached feedback and
  light/contact/visual constructors still require concrete owners; complete
  frame/session installation and game acceptance remain open.

- [Scene record parameter commands](SCENE_RECORD_PARAMETERS.md) now compose
  opcode166, the actual message queue/receiver, canonical Update message-sink
  adoption and ignored-send outcomes. Both compilers pass full source/queue/VM
  comparisons and thirteen current parent tests. Full script-bank admission
  improves from28/23 to31/26 ordinary/offline banks out of171; no scenario EVB
  is fully admitted. Later startup commands and production installation remain open.
- [Script scenario audio](SCRIPT_SCENARIO_AUDIO.md) now implements opcode73
  through the real native bank owner, cue tables and canonical session/RNG.
  The corrected eight-slot profile passes23,726 complete original command/audio
  cases and11,340 ordinary/offline dispatches per compiler, including mixed PCM.
  Scenario bank assignment, camera publication and installed acceptance remain open.
- [Head reactions](HEAD_REACTION.md) now cover all seven modes, actual target
  selection, constructor state, the5ECBE0 cinematic pass and ordinary head
  selection. Both compilers pass1,205,826 checks, including full cinematic
  passes and target/RNG continuations. Full ordinary postprocessing, the scene
  controller and a coherent native game remain open.
- [Secondary dynamics](SECONDARY_POSE_DYNAMICS.md) now implement the actual
  four owned spring/history profiles, selector, topology publication and
  source-backed constructor zero state. Both compilers pass complete original
  continuation/selector and model API comparisons. This supersedes the older
  body-contact checkpoint's missing-dynamics/reactions limit, while complete
  frame/session ownership and installed acceptance remain open.
- [Ordinary postprocess prerequisites](PRIMARY_ACTOR_POSTPROCESS.md)
  reconstruct the actual scene trigger consumer, surface transitions and
  canonical statistics tail. These use the real shared records, flags, grid,
  channels and statistics owner. The complete outer phase and its reached
  weapon work are still being integrated.

Older entries retain their checkpoint-specific limits; the newer entries above
supersede those limits only for the components they explicitly qualify. The
[integration ownership audit](STAGE4_INTEGRATION_AUDIT.md) still identifies the
missing native session entry and terminal consumers required for completion.

- [Secondary pose body contacts](SECONDARY_POSE_CONTACTS.md) now reproduce
  the capsule math and actual ordinary/high four-joint pass. Both compilers
  pass472,202 focused checks, current World comparisons and five parents.
  Secondary dynamics, reactions, full scene phases and installation remain open.
- [Scenario resource identity](SCENARIO_RESOURCE_INDEX.md) now uses actual
  sixteen-byte key/ordinal tables instead of object AFS display names. Paired
  complete packaged-loader/resolver comparisons pass2,013 actual loads; all
  450 canonical assets, existing archive/owner checks and five parents pass.
  Controlled playback remains1,296/1,356. Actual scene selection/activation,
  remaining refusals and installed acceptance remain open.
- [Scalar prefix playback](SCALAR_PREFIX_PLAYBACK.md) now permits unused trailing
  clip tracks with original binding/sampling/timing parity. Both compilers pass
  playback, World and five-parent regressions. Controlled object playback now
  completes1,296 of1,356 pairs;60 too-few-track pairs and12 missing-model
  descriptor requests remain open. Full scene ownership and installation remain open.
- [Unused curve endpoint tangents](CURVE_ENDPOINT_TANGENTS.md) now preserve
  actual owned cubic/mixed sampling while skipping first-incoming/final-outgoing
  fields that no segment consumes. Paired full-source curve/playback/parent
  checks pass. All affected clip imports succeed; controlled object playback
  completes1,238 pairs.118 cardinality pairs and12 model-request descriptors remain open.
- [Wider animation rotations](WIDE_RADIAN_ANIMATION.md) now admit the original
  nonwrapping signed16 winding range with262,129 new bitwise source comparisons.
  All74 previously refused angle pairs complete; current World/five-parent
  regressions pass.118 cardinality and two nonfinite-clip pairs,12 missing-model
  descriptor requests and full scene/game installation remain open.
- [Object/model/motion composition audit](CINEMATIC_OBJECT_PLAYBACK_AUDIT.md)
  completes1,162 of1,356 controlled authored pairs on both compilers. It exposes
  118 track-cardinality refusals,74 wider-radian cases and two nonfinite-clip
  refusals. Missing-model requests remain in12 descriptors. These are explicit
  integration gates, not a complete scene or installed-game acceptance claim.
- [Cinematic object motion assets](CINEMATIC_OBJECT_MOTION_ASSETS.md) now read
  all52 exact ROM members, preserve prior banks on failures and retain absent
  slots on successful200-stride replacement. Both compilers pass104 loads,
  312 original loader calls and six native fault/retention cases; five parents
  pass. Actual scene bank publication and combined model/clip playback remain open.
- [Cinematic object construction](CINEMATIC_OBJECT_CONSTRUCTION.md) now prepares
  retained assets/streams and reserves/builds through the actual World pool.
  Paired comparisons pass2,144 scene object constructions and2,684 objects with
  stream installation.536 candidate descriptor requests prepare;12 retain55
  unresolved model occurrences. Current World/lifetime/five-parent regressions
  pass. Motion-bank publication, full scene phases and installed acceptance remain open.
- [Cinematic object assets](CINEMATIC_OBJECT_ASSETS.md) now retain actual archive
  definitions, independent instances and distinct inverse bind data. Both
  compilers pass452 imports,450 actual filename reads and1,808 controlled
  original constructions; five parents pass. Cold attachment metadata is now
  qualified for the owned material profile. Actual scene publication,55 unresolved
  descriptor occurrences, full scene lifetime and installed acceptance remain open.
- [Authored cinematic object streams](CUTSCENE_OBJECT_TRACKS.md) now dispatch
  all four command kinds through actual object/actor/model ownership, retain
  typed pose keys and preserve exact media-frame/cursor cadence. Paired cohorts
  pass2,048 ticks and17,451 processed records; all726 owned object groups import
  exactly. Lifetime regressions and five parents pass. Actual construction,
  parent metadata, complete scene phases and native game installation remain open.
- [Cinematic object attachment math](CINEMATIC_OBJECT_ATTACHMENTS.md) now
  preserves actual node views, normalized axes, distinct position/basis state and
  the direct-radian rotation path. Paired comparisons pass262,144 attachments
  over four owned skeletons and all five CMake parents. Actual parent selection,
  object model-work scale metadata, authored streams and installation remain open.
- [Sixteen cinematic objects](CINEMATIC_OBJECTS.md) now own separate typed
  storage/reservations, model playback and unclamped pose interpolation through
  World lifetime. Paired comparisons pass16,384 reservations,67,585 pose cases
  and1,024 model passes; lifetime regressions and five parents pass. The owned
  header audit finds726 valid object groups, maximum11. Actual object loading,
  authored streams, attachment, full scene lifetime and installation remain open.
- [Standalone scalar animation](SCALAR_ANIMATION_PLAYBACK.md) now preserves
  the distinct cinematic-object endpoint, loop, completion and sampling rules.
  Paired comparisons cover2,048 bindings and8,192 updates; channel/topology
  regressions and five CMake parents pass. Object storage/timelines and actual
  scene construction/installation remain open.
- [Cinematic primary model publication](CINEMATIC_MODEL_PUBLICATION.md) now
  implements the actual separate eight-slot pass with current actor bases,
  shared scripted/correction B40 ownership and150 owned correction variants.
  Paired full comparisons pass512 passes and192 command/publication compositions;
  ordinary pose, model-lifetime and five parent regressions pass. Reaction/
  secondary-pose work, category10 objects, full scene entry/exit and installed
  native gameplay acceptance remain open.
- [Shared humanoid motion preparation](HUMANOID_MOTION_ASSETS.md) now reads
  all90 common and eight character-base files, preserves the actual shared
  ordinary/head bank, and reproduces default reload after scene attempts.
  Both compiler919-bank comparisons, actual NPC binding examples and twelve
  parent tests pass. Live publication, remaining scene/action/curve consumers
  and installed native gameplay remain open.
- [Primary appearance assets](PRIMARY_ACTOR_ASSETS.md) now load all46 actual
  P/EP/HP members by exact ROM alias. Paired source comparisons cover327,680
  primary filenames; actual bytes, parts,1,973 skeleton nodes and independent
  instances pass. Primary initialization and scene caller adoption remain open.
- [Default primary initialization and restore](PRIMARY_ACTOR_INITIALIZATION.md)
  now pass paired full original comparisons over32,768 default initializations,
  4,096 restores and65,536 appearance setters, with real primary assets,
  constraints and shared-bank publication. Custom statistics, saved override,
  caller adoption and installed-game acceptance remain open. This audit also
  separates NPC motion-character byte4 from the actual AI-control byteFF0;
  paired current constructor/scene, World, behavior and shared-bank regression
  qualification passes.
- [Custom primary statistics](PRIMARY_CUSTOM_STATISTICS.md) now recover the
  actual initialized o0 table and preserve its terminal fallback. Paired
  comparisons pass468,289 statistic cases,65,536 lookups and4,384 real N/HP
  initialization cases, with all15 parents passing. Saved-state override and
  actual initialization/scene caller ownership remain open.
- [Saved primary initialization override](PRIMARY_SAVED_INITIALIZATION.md) now
  decodes typed actor-start fields from the legacy save section and consumes
  the canonical descriptor/template action query. Paired comparison covers
  every signed health value and action byte, save-codec round trip and all15
  parents. Actual resume enabling, the branch-selector/model lifecycle and
  complete semantic World snapshots remain open.
- [Primary initialization selector](PRIMARY_INITIALIZATION_SELECTOR.md) now
  consumes native Update notification state and the canonical pause byte.
  Paired complete66A750 comparisons cover all65,536 flag pairs and exactly255
  restore selections, with all15 parents passing. Actual model reuse/retirement,
  character-bank release and scene/resume caller adoption remain open.
- [Motion-bank retirement](MOTION_BANK_RETIREMENT.md) now preserves the exact
  release/initial-clear type distinction, supplies known absent-token queries
  and prepares shared character release/reload. Paired bank, live rebinding,
  primary initialization, World, behavior and15-parent regressions pass.
  Actual primary model-cache and instance lifecycle adoption remain open.
- [Playback model replacement](PLAYBACK_MODEL_REPLACEMENT.md) preserves actor
  channels, root history and resource ownership while rebuilding both mutable
  node banks. Both compilers pass72 replacements and264 original continuation
  cases. Actual primary model-cache caller adoption remains open.
- [Primary CPU model cache](PRIMARY_ACTOR_MODELS.md) connects admitted archive
  loading, same-key reuse, shared character-bank retirement, actual instance
  replacement and initialization. Paired focused comparisons cover1,024 cache
  cases with real native assets. Actual scene/resume caller adoption, renderer
  interfaces, generation teardown and installed native gameplay remain open.
- [Assigned primary scene application](PRIMARY_SCENE_MODELS.md) now composes the
  actual cache, appearance reset, room, scale, constraints, visibility and copied
  parameters for kind0 groups. Paired cohorts pass1,196 real-header applications
  with controlled primary bindings. Earlier roster assignment/cloning, cache
  teardown, primary cinematic playback and full scene ownership remain open.
- [Primary model retirement](PRIMARY_MODEL_RETIREMENT.md) now preserves actor
  playback across detached CPU models, compares513 original release cases and
  verifies explicit generation handoff. Current initialization/playback/World
  regressions pass. Complete scene-entry ownership and real partial-family
  bank release remain open; the old1B1DF0 work-buffer port must be corrected.
- [Partial motion-family retirement](MOTION_FAMILY_RELEASE.md) corrects that
  production/fixture omission. Complete1B1DF0 cleanup now precedes default
  restoration; paired bank, all-eight-character and live publication checks pass.
  Complete scene-entry/exit ownership and installed acceptance remain open.
- [CPU scene-entry teardown](PRIMARY_SCENE_ENTRY.md) now composes the four roster
  retirements and actual shared-family release with scoped nested guards. Paired
  cohorts pass385 entry cases and448 direct/whole-entry lifetime guards. Earlier
  assignment needs the [separate temporary actor/object owners](PRIMARY_TEMPORARY_ACTOR_OWNERSHIP.md),
  not a replacement of the canonical roster or an unchecked actor/model copy.
  Full cinematic entry/exit and installed native gameplay remain open.
- [Temporary cinematic player storage](SCENE_PRIMARY_ACTOR_POOL.md) now preserves
  the separate eight-Actor domain, source first-inactive selection and guarded
  generation retirement. Both compiler focused comparisons pass; assignment,
  model-slot handoff, the sixteen objects and full scene playback remain open.
- [Cinematic character reservations](CUTSCENE_ACTOR_RESERVATIONS.md) now preserve
  the separate32-byte requested/assigned sets and signed membership rules.
  Both compiler full-body comparisons and native-only tests pass. Complete
  roster selection/cloning and model handoff remain open.
- [Primary cinematic choice preparation](CUTSCENE_PRIMARY_SELECTION.md) now
  preserves the complete required/optional fallback and roster-preference policy.
  Both compilers pass31,494 source-body comparisons, including all548 owned0950
  raw headers. Cloning, live binding/model handoff and full scene ownership remain open.
- [Independent playback ownership](PLAYBACK_OWNERSHIP_COPIES.md) now preserves
  animation snapshots with separate mutable model banks. Both compilers pass
  1,288 original continuation comparisons,64 isolation cases and256 detached
  copies. Typed Actor cloning, constraint/cache handoff and scene adoption remain open.
- [Typed Actor ownership snapshots](ACTOR_OWNERSHIP_COPIES.md) now preserve native
  value state and independent model/playback/constraint ownership, including old
  constraint models during detachment. Both compilers pass515 Actor copies and
  512 copied original solver continuations. Live scene-specific construction,
  cache-row transfer and complete entry/exit adoption remain open.
- [Cinematic player construction](PRIMARY_SCENE_CONSTRUCTION.md) now composes
  choice validation, independent typed copying, scene resets, generation
  publication and matched main-model retirement. Both compilers pass258 complete
  source comparisons and explicit failure/lifetime checks. Temporary model-cache
  admission, playback, objects and full scene entry/exit remain open.
- The [scene lifetime follow-up](PRIMARY_SCENE_LIFETIME_AUDIT.md) distinguishes
  authored population from filtered scene rosters, preference remapping and stale
  physical entries. Both compilers now explicitly verify167,969 fresh model-pointer
  stores and4,351 restore preservations. Native roster preparation, broader cleanup
  and physical resource handoff remain open.
- The selector now names `eligible_count` explicitly and preserves valid physical
  preferences beyond that count. Both compiler comparisons pass56,686 cases.
  Exit cleanup resets temporary records before slot retirement, reinforcing the
  need for independent resident resource ownership.
- [Eligible roster preparation](CUTSCENE_ROSTER_PREPARATION.md) now preserves
  the actual status/room filters, slot/status metadata, special branch and
  preference remapping. Both compilers pass396,845 original projections and
  365 World-backed comparisons. Complete cleanup, physical resource ownership
  and scene entry/exit adoption remain open.
- [Scene motion-family release](SCENE_MOTION_FAMILY_RELEASE.md) now preserves
  reserved tokens beneath known-zero range headers and publishes the complete
  general/alternate/prepared-character family cleanup. Whole-model playback
  uses its distinct fixed token-table rule through cleanup. Paired bank,
  shared-publication, playback and primary-model comparisons cover this path;
  the remaining5ED340 cleanup and physical resource handoff remain open.
- [Cold humanoid banks](COLD_HUMANOID_BANKS.md) now supply an explicit1B2150
  projection with known-empty unused character banks and a caller-owned default
  gate. Paired complete initializer/default/overlay/cleanup comparisons and live
  publication pass. This grants no unprepared clip data; full scene ownership
  and physical model-resource handoff remain open.
- [Resident primary resources](PRIMARY_RESIDENT_RESOURCES.md) now own physical
  model payloads independently of Actor generations, including failed initializer
  prefixes. Paired cache/scene comparisons and retained-resource lifetime guards
  pass. Explicit scene binding authority, post-reset retirement and return to
  main bindings remain open.
- [Scoped primary scene models](PRIMARY_SCENE_MODEL_SCOPE.md) now compose
  validated temporary fresh initialization, physical cache reuse/rebuild, actor
  reset before selected retirement, and return followed by canonical
  reinitialization. Both compilers pass64 controlled owned-header compositions
  and96 cleanup guards. Extra bank/object cleanup, sparse primary playback,
  temporary restore and full entry/update/exit adoption remain open. The current
  kind3 follow-up also passes772 additional full source applications and48
  scoped cases; selection and the actual scene caller remain separate work.
- [Scene motion table cleanup](SCENE_MOTION_TABLE_RELEASE.md) now preserves
  the exact1600-token prefix and composes represented general/body/face cleanup
  with scoped actor reset and canonical return. Both compiler bank/helper and
  controlled full-wrapper projections pass. Other bank/object/NPC cleanup and
  the real full scene lifecycle remain open.
- [Primary motion routing](PRIMARY_MOTION_ROUTING.md) now owns mutable node track
  IDs per model instance, preserving shared authored skeletons and accessory
  tails. Paired complete helper/configuration/continuation comparisons pass;
  cinematic wrapper adoption and the full primary callback remain open.
- [Actual cinematic primary action dispatch](PRIMARY_CUTSCENE_ACTION.md) now
  consumes the bounded categories0/1 animation wrappers through67BE90, including
  channel resets, three sequenced timers, paired-node offsets and movement.
  Paired original comparisons cover the full signed timer domain and112 actual
  scene-model lifetimes. This corrects an earlier6BA880 generic callback
  experiment and a cue2 mapping error. Production6BA880 is linked-only again.
  Actual primary/NPC traversal, secondary-pose owners, remaining scene objects
  and full installed acceptance remain open.
- [Instance-owned live topology](LIVE_NODE_TOPOLOGY.md) now preserves actual
  Yoko branch detach/reconnect behavior through binding, clearing, sampling,
  paired blending, constraints and pose publication. Both compilers pass the
  coupled original comparisons and current World/model-lifetime regressions.
  Secondary-pose selector/chain ownership and actual scene scheduling remain open.
- [Secondary-pose link restoration](SECONDARY_POSE_LINK_RESTORE.md) now supplies
  the actual61A6A0 table/gate policy and typed61B1A0 recipes. Paired full-body
  comparisons pass with real player and HN54/HN88 inputs and explicit profile2
  limits. Secondary-chain solving and actual temporary/auxiliary traversal remain open.
- [Cinematic actor frames](CINEMATIC_ACTOR_FRAMES.md) now own the specific5ECAE0
  temporary-player/auxiliary traversal, actual link restoration and common-frame
  root/basis work. Both compilers compare callback order and same-pass mutation,
  with explicit behavior ports and failure boundaries. Phase scheduling, actual
  behavior/action dispatch, model publication and secondary chains remain open.
- The [scene NPC loading-mode correction](CUTSCENE_NPC_CONSTRUCTION.md) separates
  asset-loading mode3243D7 from pause4BADF8. Paired current cohorts pass4,384 scene
  cases with independent inputs; the earlier fixture conflated the two and its
  shadow-gate claim is superseded. Unknown loading mode refuses before creation.
- [Shared humanoid motion publication](HUMANOID_MOTION_PUBLICATION.md) adds
  explicit NPC/scripted bank identities, atomic live rebinding, stale-load
  rejection and joined-owner closure. Paired publication, current World,
  behavior, constructor, scene and thirteen-parent checks pass;
  actual scene lifecycle adoption, primary bindings and remaining sparse
  scripted playback remain open.
- [Native NPC updates](NPC_UPDATES.md) now compose the shared callback, actual
  root/pose work, camera and inhibition gates, the ten-slot pool and its actual
  Update worker position. Both compiler World and current owned/parent cohorts
  pass. The actual native behavior composition and all32,768 behavior
  comparisons also pass on both compilers. Actual scene/content/attachment
  providers and game installation remain open.
- The NPC model association has been corrected: the resident auxiliary loader
  uses raw low-byte N/HN identities, independently of primary-character
  substitution. [Asset evidence](NPC_ACTOR_ASSETS.md) covers 233 actual members
  and 262,144 filename comparisons on both compilers. The
  [corrected constructor](NPC_ACTOR_CONSTRUCTION.md) covers 149 identities,
  483 supported constructions and 113 explicit absent-model refusals. Historical
  505-case state checks did not prove the mistaken asset association and are
  superseded for that claim. [NPC scene assignment](CUTSCENE_NPC_CONSTRUCTION.md)
  now passes both compiler comparisons over all548 supported descriptors with
  actual native construction, constraints and track bindings. One11-NPC input
  remains explicitly full under the original ten-slot contract. Actual motion
  owners/callbacks, full scene lifecycle, remaining consumer audit and game
  installation remain open.
- [Native scene scripted construction](CUTSCENE_SCRIPTED_CONSTRUCTION.md) now
  prepares actual header requests and creates all729 kind2 actors across548
  owned0950 scenes through the canonical factory, including seven witnessed
  model-index admissions. Both compiler source/asset compositions, current
  World comparisons and eight parent tests pass. Primary/NPC construction,
  full scene lifecycle and installed native gameplay remain open.
- [Native retained cutscene descriptors](CUTSCENE_DESCRIPTORS.md) now read actual
  named archive members and retain all bounded0950 sections and actor programs.
  Both compiler comparisons cover548 owned files; both actual archive cohorts
  and seven parent tests pass. Actor assignment/construction, other streams,
  legacy formats, scene lifecycle and game installation remain open.
- [Native cutscene actor tracks](CUTSCENE_ACTOR_TRACKS.md) now drive those
  commands through the actual Update owner with exact/halved frame matching,
  one event per stream, terminal handling, checked lifetimes and failure latching.
  Both compiler comparisons, owned chain, phase/scenario regressions and six
  parent tests pass. The [owned descriptor inventory](CUTSCENE_DESCRIPTOR_INVENTORY.md)
  identifies32-group inputs and legacy formats for the next importer work.
  Full scene lifecycle and game installation remain open.
- [Native cutscene actor commands](CUTSCENE_ACTOR_COMMANDS.md) now supply actual
  position, motion, scale, relation and movement requests to the native actor
  chain. Both compiler comparisons, actual asset/worker compositions, full
  scenario regression and six parent tests pass. Stream cadence, descriptor
  import, real speech/facial providers and game installation remain open.
- [Native linked model workers](LINKED_MODEL_WORKERS.md) now adopt the real
  pose pass at its actual Update position, with unique World registration,
  concrete floors/scales, root state and current pass evidence. Both compiler
  owned compositions, original models/order and six parent tests pass.
  Cinematic lifecycle callers and game installation remain open.
- [Native scripted motion assets](SCRIPTED_MOTION_ASSETS.md) now load all89
  mapped body/head members by verified full-path alias ordinal. Both compiler
  cohorts cover actual blocks, constructors, Update callbacks and model poses,
  plus full original loader routing. Six parent tests pass on each compiler.
  Cutscene lifecycle callers and game installation remain open.
- [Native linked actor updates](LINKED_ACTOR_UPDATES.md) now adopt the actual
  shared fifty-node pool, scripted callbacks, post-callback poses, simulation
  clock countdown and canonical expiry publication in Update Owner. Both
  compiler comparisons, owned construction and five parent tests pass.
  Scene lifecycle callers, other callback families and game installation remain open.
- [Native cutscene actor callbacks](CUTSCENE_ACTOR.md) now compose counted
  displacement, scripted motion, root integration and real pose ownership.
  Both compiler comparisons, full scenario regression and five parent tests
  pass. The linked callback pass now adopts them; cinematic lifecycle callers
  and game installation remain open.
- [Native scripted actor motion](SCRIPTED_ACTOR_MOTION.md) now consumes actual
  scene banks and native poses through the canonical linked Actor. Both
  compiler World comparisons, owned construction and five parent tests pass.
  Linked cutscene scheduling and game installation remain open.
- [Whole-model scripted playback](WHOLE_MODEL_PLAYBACK.md) now has native
  configuration, root-motion advancement and full owned/synthetic comparisons
  on both compilers. Caller tracing corrects B44 to blend duration. Actual
  outer cutscene scheduling and game installation remain open.
- [Native scripted actor construction](SCRIPTED_ACTOR_CONSTRUCTION.md) now
  composes prepared models, canonical actor state and material tasks through
  the existing owners. Both compiler comparisons,330 owned constructions and
  five parent tests pass. Scene orchestration and game installation remain open.
- [Native material animation](MATERIAL_ANIMATION.md) now runs the complete
  callback through the actual Update Owner and shared32-entry scheduler.
  Both compiler comparisons and four parent tests pass, including pause,
  capacity, stale actors and closure. Native scripted construction adopts it;
  scene orchestration and game installation remain open.
- [Native actor model binding](ACTOR_MODEL_BINDING.md) publishes prepared
  assets through canonical Actor ownership, with fresh mutable instances and
  generation-safe retirement. Both compiler comparisons and five parent tests
  pass. The [shadow dependency](ACTOR_CONSTRUCTION_RENDER_BOUNDARY.md) is
  rendering work for Step5. Constructor adoption remains open.
- [Native actor model assets](ACTOR_MODEL_ASSETS.md) load406 definition
  combinations from180 owned bundles and produce native skeleton instances.
  Both compiler comparisons and five parent tests pass. One named model is
  absent from owned content. Constructor orchestration remains open.
- [Target model-point selection](TARGET_METRICS.md) now owns the linked551
  index independently of motion style. Both compiler comparisons and four
  parent tests pass, including unknown/out-of-range index refusal. Actual
  model-point construction and game acceptance remain open.
- [Expanded enemy record binding](ENEMY_BINDING.md) now uses the actual shared
  fifty-node pool, canonical status words and Session RNG. Both compiler
  comparisons, parent tests and archive regression pass. Model/resource
  construction, behavior and room orchestration remain open.
- [Enemy priorities and model definitions](ENEMY_INITIALIZATION.md) reproduce
  the owned metadata and use canonical actor status fields. Both compiler
  comparisons and the existing linked-model regression pass. Full enemy
  record binding, construction and room orchestration remain open.
- [Forced actor terminal transition](ACTOR_FORCED_TERMINAL.md) now composes the
  actual native inventory, event, pose and local-player message owners through
  script commands 61 and 62. Both compiler suites and parent tests pass. The
  actual UI close provider, transport and game installation remain open.
- [Native missing-character mapping](SCENARIO_CHARACTER_REMAP.md) connects the
  actual roster, NPCs, room asset rows and enemy records. Placement/channel
  aliases use their canonical owners. Both compiler comparisons, parent worker
  tests and archive regression pass. Live construction remains open.
- [Native enemy spawn records](ENEMY_DESCRIPTORS.md) import the ten owned EMD
  files through canonical RNG, control registrations and bounded initialized
  route metadata. Both compiler comparisons, direct archive loading and parent
  tests pass. Live actor/model construction and room orchestration remain open.
- [Native NPC startup commands](SCENARIO_NPC_COMMANDS.md) enable, disable, place
  and modify the shared descriptors through the real registration owner. Both
  compiler comparisons and the actual Update worker test pass. Enemy ownership,
  alias production and live construction remain open.
- [Native scenario NPC descriptors](SCENARIO_NPC_DESCRIPTORS.md) import all five
  owned NPC files and supply canonical descriptor primitives and startup
  inventory commands. Both compiler comparisons, direct archive loading and
  seven parent integration tests pass. Live construction and model/AI
  preparation remain open.
- [Native launch roster initialization](LAUNCH_ROSTER.md) imports player/AI
  selections through the real Update owner and shared RNG. Both compiler
  comparisons and seven parent integration tests pass. Actor/model creation
  and actual launch caller installation remain open.
- [Native scene transition inputs](SCENARIO_TRANSITION_INPUTS.md) supply the
  cutscene cue collector, placement packet consumer, and room placement
  completion through the canonical Update Owner. Both compiler comparisons
  pass. Scene preparation, media/UI, and installed game acceptance remain open.
- [Room actor asset requests](SCENARIO_ROOM_ACTOR_ASSETS.md) now share one
  Session owner across script updates and descriptor allowance queries.
  Both compiler comparisons pass. Actual descriptor/model loading callers
  still need to adopt it.
- [Direct native scenario archive loading](SCENARIO_ARCHIVE.md) now reads all
  171 owned scenario/room members from the host archive. Both compiler tests
  bind the 51 admitted ordinary/offline room programs through the actual Update
  Owner. Whole-scene construction and game installation remain open.
- [Scenario startup scene state](SCENARIO_SCENE_BOOT.md) supplies the cutscene
  request producer, roster condition, auxiliary room rows and timers through
  the Session and update owners. The original comparisons pass. Actual scene
  playback and the forced terminal effect providers remain open.
- [Scenario actor inventory grants](SCENARIO_ACTOR_INVENTORY.md) use the same
  canonical Actor inventories, resource pool, and inventory compaction as the
  native World. Both compiler comparisons pass. Live startup still needs to
  supply these providers.
- [Native actor placement commands](SCENARIO_ACTOR_PLACEMENTS.md) now write
  the Session placement requests and restore the canonical Actor transforms.
  Both compiler comparisons pass. Runtime packet and room-transition callers
  remain open.
- [Native script setup](SCENARIO_SCRIPT_SETUP.md) binds admitted programs to
  their source channels and runs them through the actual Update Owner.
  A failed admission preserves the previous bindings. The game startup and
  transition callers still need to supply stock content and providers.
- [Stock room script admission](SCENARIO_STOCK_PROGRAMS.md) builds immutable
  native programs from checked stock bytecode. The dual-compiler admission
  probe installs 25 ordinary and 20 offline room programs. One stock room
  script passes 36 comparisons against the original dispatchers with
  controlled providers. All five scenario EVBs and actual game installation
  remain open.
- [Native scenario room counters](SCENARIO_ROOM_COUNTERS.md) now compare the
  complete F2 handler and room-counter reset through the Session owner on both
  compilers. The policy importer uses all five owned scenario EVBs. Runtime
  scenario installation and game acceptance remain open.

The current resource and inventory implementation includes:

- [Native navigation inputs and queries](NAVIGATION_INPUTS.md) now supply all five
  owned SGL inputs and bounded unfiltered nearest/reverse-action queries with
  original comparisons on both compilers. Canonical variant production, mutable
  room/visit/occupancy state, dynamic conditions, route/AI consumers and game
  installation remain open.
- [World navigation and room variants](NAVIGATION_BANK.md) now bind those inputs
  through the sole Session map and ordinary script5A, own mutable occupancy and
  visits, and seal on World closure. Complete original comparisons and current
  full VM suites pass on both compilers. Dynamic conditions, routes/AI and actual
  loading/installation remain open.
- [Navigation conditions and links](NAVIGATION_CONDITIONS.md) now use the same
  actor AI-control field and canonical strided flag bank through the actual
  UpdateOwner. Complete bounded source comparisons and ten parent checks pass
  per compiler. Node edges, route policies and scene/AI execution remain open.
- [Navigation edge admission](NAVIGATION_EDGES.md) now preserves complete819010
  through the actual UpdateOwner, with shared per-graph mutable flag identity.
  Both compilers pass338009 edge comparisons and ten parent tests. Twelve
  controlled contexts reaching the authored r041 ordinal19/count14 reference
  remain an explicit admission gate. Route policies and scene/AI execution stay open.
- [Ranked navigation routes](NAVIGATION_RANKED_ROUTES.md) now preserve both ranked
  root policies and their recursive companions, with41326 original comparisons
  per compiler through the same graph/occupancy/condition owners. The separate
  bounded-cost policy, outer/cross-room dispatch and actor/AI execution remain open.
- [Bounded-cost navigation](NAVIGATION_COST_ROUTES.md) now preserves818B70/818E30
  for completed native searches and uses an explicit work-admission budget.
  Both compilers pass81928 cost comparisons and ten parent tests;3626 sampled
  retail queries exceed the lower4096-edge verification profile and remain open.
  Outer/cross-room dispatch, wider work admission and actor/AI execution are next.
- [Local navigation dispatch](NAVIGATION_LOCAL_DISPATCH.md) now composes817DB0's
  pre-target gate, distinct policy routing, current-variant reads and post-link
  admission through the actual UpdateOwner. Both compilers pass56616 dispatcher
  comparisons and ten parent tests;3412 retail work-budget cells remain open.
  Cross-room traversal and actor destination/AI execution are next.
- [Known-cost link collection](NAVIGATION_LINK_COLLECTION.md) now preserves
  complete8179F0 through canonical actor/flag/visit consumers, with26401 original
  comparisons per compiler and ten parent tests.288 sampled retail contexts need
  an unspecified incoming cost and stay unavailable. Recursive cross-room search,
  initialization policy/evidence and actor destination/AI execution remain open.
- [Cross-room navigation](NAVIGATION_CROSS_ROOM.md) now supplies817470/817820
  through actual canonical actor/flag/visit state, with4732 completed cross-room
  comparisons and ten parent tests per compiler.1115 use the strict profile;
  the separate3617 explicit cost-initialization profiles are documented source
  corrections.189 sampled contexts stay unavailable. Actor route-state/AI,
  broader admission, loading, saves and actual installation remain open.
- [Canonical actor routes/actions](NAVIGATION_ACTOR_ROUTES.md) now supplies
  complete8173D0/816EF0 through the actual World Actor and shared Bank, with16416
  actor comparisons and ten parent tests per compiler. The absent actor
  component and one controlled unknown-cost case refuse explicitly. Initial/
  current-node producers, destination setup, movement/AI, saves and installation
  remain open.
- [Actor destination setup](NAVIGATION_DESTINATION.md) now supplies complete
  816890 through the same actual actor, canonical visit/occupancy/route owners
  and full audited heading/distance chain. Both compilers pass15884 destination
  comparisons and ten parent tests. Initial/current-node production, filtered
  collision queries, remaining AI/movement, saves and installation remain open.
- [Navigation visibility/current-node selection](NAVIGATION_VISIBILITY.md) now
  composes complete filtered queries, real native ordered collision and actor
  policy selection. Both compilers pass6144 policy,480 selection and3408 filtered
  nearest comparisons plus ten parent tests.3334 node profiles use controlled
  empty geometry, not retail room acceptance. The actual Owner publishes the
  audited812540 entry-prefix current node; the rest of that AI caller, scene
  loading, broader admission, saves and installation remain open.
- [Bounded cost graph adoption](NAVIGATION_COST_GRAPH_RESEARCH.md) now supplies
  actual cost/local/Owner consumers, preserving first-direct, low-budget and
  unknown-graph fallback behavior. Both compilers pass63898732 identical checks
  and ten parent tests. All20004 sampled retail cost queries and sampled local
  queries complete within their native work budget.6725 repeated cost/local
  source contexts remain limited and separately identified. Full AI/movement,
  actual loading, semantic saves and native game acceptance remain open.

- [AI scene candidates](NAVIGATION_SCENE_CANDIDATES.md) now supply complete
  reachable actor probing and shared-record collection through the actual Owner.
  Both compilers pass67621991 checks, including7172 collector and131329 actor
  probe comparisons, plus ten parent tests. The source1B4 probe input is canonical
  collision center Z, not radius1B8. Full812540, condition-based lookup, actual
  provider/loading and native gameplay acceptance remain open.

- [Condition-based scene lookup](NAVIGATION_SCENE_LOOKUP.md) now composes both
  complete lookup helpers with native applicability and canonical ordinal3F.
  Both compiler suites pass13825 list/4608 global comparisons and ten parent
  tests. Refreshed full room initialization checks actual base/helper ordinal
  production across166 owned rooms; the existing three strict model-reference
  refusals remain. Full AI goals/actions and native gameplay acceptance stay open.

- [AI execution state](AI_EXECUTION_STATE.md) now supplies complete goal/action
  resets and authored weight-profile selection through actual Actor/Owner state.
  Both compilers pass6629721 original-comparison checks and twelve parent tests.
  The goal-zero gate uses the low halfword, correcting the older low-byte mapping
  wording. Full initialization, observations, goal/action dispatch and actual
  gameplay installation remain open.

- [AI control requests](AI_CONTROL_REQUESTS.md) now supply complete registration,
  lookup and four-byte request publication through the canonical Session and
  actual Actor Owner. Both compilers pass30579888 comparison checks and twelve
  parent tests. Service/acknowledgement/reset, full initialization and native
  gameplay acceptance remain open; queued does not claim delivered.

- [AI control payloads](AI_CONTROL_PAYLOADS.md) now supply the canonical
  frame reset and outbound payload drain. Both compilers match 8,576 original
  packets, and the worker and phase regressions pass. Authority changes,
  real transport, and gameplay acceptance remain open.

- [Control value/ownership reception](AI_CONTROL_RECEIVE.md) now supplies both
  complete bounded receive helpers through the same Session registrations.
  Both compilers pass75024841 comparisons/checks and twelve parent tests. The
  external activity-mode fact is explicit; its complete provider/producer,
  outgoing service/transport and coherent game acceptance remain open.

- [Session activity mode](SESSION_ACTIVITY_MODE.md) now supplies the complete
  main/overlay query through canonical Session fields and the actual receiver.
  Both compilers pass75155916 checks and twelve parent tests; the old1AFE70
  result substitute is removed. Actual mode producers, control service and
  coherent native gameplay acceptance remain open.

- [Actor AI initialization](AI_INITIALIZATION.md) now supplies complete8120C0
  for admitted canonical components, including actual control producers and
  goal/action/profile consumers. Both compilers pass80542165 checks and twelve
  parent tests; registration/queue limits preserve subsequent source resets.
  Actual actor construction, control service, full observations/dispatch and
  coherent native gameplay acceptance remain open. Refreshed full current-source
  VM suites pass19719138 checks/30245 original dispatcher calls per compiler;
  their dependency-list correction and failed standalone links are recorded.

- [AI goal reevaluation](AI_GOAL_REEVALUATION.md) now supplies complete8133D0,
  character7 item selection825CC0 and target-busy823190 through canonical Actor,
  navigation and resource owners. Both compilers pass94095293 checks including
  62722 complete reevaluations and512 alias cases. The later descriptor audit
  corrects the content field to canonical attachment ID and refreshes all AI
  comparisons plus thirteen parent tests. Full observations, reactions/actions,
  construction and game acceptance remain open.

- [AI reaction scheduling](AI_REACTIONS.md) now supplies complete8130D0 through
  canonical execution state and the actual Session RNG. Both compilers pass
  895957 complete reaction comparisons/1014101 identical random draws and twelve
  parent tests. Full observation/timer consumption and game acceptance remain open.

- [AI observation admission](AI_OBSERVATION_GATES.md) now supplies complete
  812EF0/813BD0 through canonical execution state and Session RNG. Both compilers
  pass2887680 admission comparisons,278784 predicate comparisons and twelve
  parent tests. Refreshed full current-source VM suites pass19719138 checks and
  30245 original dispatcher calls per compiler. Full observation/cache production
  and game acceptance remain open.

- [AI observation frame](AI_OBSERVATION_FRAME.md) now executes the admitted
  `0x812540` routine through the native Update Owner. Both compilers pass 4,096
  original profiles, 131,859 checks, and thirteen parent tests. The outer AI
  caller, goal/action dispatch, live content binding, and game acceptance
  remain open.

- [Direct AI goal dispatch](AI_GOAL_DISPATCH.md) connects reevaluation to native
  goals 0, 6, and 14. Both compilers pass 131,841 original comparisons and
  thirteen parent tests. The other callbacks, immediate redispatch, and the
  live outer AI caller remain open.

- [AI steering and turning](AI_STEERING.md) now generate input through the
  existing actor input frame. Both compilers pass 393,220 steering and 65,542
  active-room action comparisons. The navigation heading regression and
  thirteen parent tests pass. Other action families and live callers remain open.

- [Native AI frame](AI_FRAME.md) connects the input reset, observation pass,
  direct goals, and admitted active-room actions in original order. Both
  compilers pass 1,024 full-frame comparisons and all thirteen parent tests.
  Remaining action families, live scheduling, and game acceptance remain open.

- [Off-room AI actions](AI_OFF_ROOM_ACTIONS.md) add motion synthesis, reset
  actions, and request completion phases to the same frame. Both compilers
  pass 196,608 motion and 2,557 dispatch comparisons, plus 100 off-room frames
  in the composed comparison. Waypoint movement and request producers remain open.

- [Off-room waypoint movement](AI_OFF_ROOM_WAYPOINTS.md) now advances ordinary
  travel and arrival through the canonical actor route and Session clock mode.
  Both compilers pass 147,456 timing and 4,096 waypoint-dispatch comparisons.
  Scripted arrival, resource requests, and live acceptance remain open.

- [Active-room default waypoints](AI_ACTIVE_WAYPOINTS.md) now synchronize the
  route action and generate steering through the canonical actor input.
  The composed original comparison covers 120 active-room waypoint frames.
  Condition-specific handlers and live game acceptance remain open.

- [Target-cache scratch audit](TARGET_CACHE_SCRATCH_AUDIT.md) identifies controlled
  source inverse-sort dependence on unwritten scratch. Both compilers agree on
  48 profiles,192 strict runs and192 separate initialization-policy runs. This
  guides explicit native work initialization; it is not an installed fix or a
  confirmed cause of the player's stutter.

- [Native World target metrics](TARGET_METRICS.md) now supply complete admitted
  cache rebuild with an explicit initialized work policy and once-per-row sorts.
  Both compilers pass192 profiles and thirteen parent tests, with75 strict
  original comparisons and192 initialized comparisons. The actual native frame
  worker now rebuilds it before actor updates, with pause and failure checks.
  Complete observation/action execution and game acceptance remain open.

- [Primary construction](RESOURCE_FACTORY.md) from actual NBD poses and ITEM
  templates through the canonical64-model owner.
- [Placed-resource collisions](RESOURCE_COLLISIONS.md) through the shared128
  scene owner and [primary placement](RESOURCE_PLACEMENT.md) through actual
  models, template offsets, session RNG and floor queries.
- [Delayed construction and callbacks](RESOURCE_DELAYED.md), including
  self-replacement, same-pass continuation and the corrected factory insertion
  end. Fresh comparisons cover multi-model list order.
- [Scenario commands](RESOURCE_SCENARIO_ACTIONS.md) bound to actual construction,
  release and deactivation owners, with failure status propagated to the VM.
- [Canonical inventory primitives](INVENTORY_PRIMARY_OWNER.md), including actual
  primary SceneOwners detach/refresh, plus [resource use and content lookup](RESOURCE_USE.md)
  through the same descriptor, actor and model owners.
- [Content replacement and model rebinding](RESOURCE_CONTENT.md), preserving
  untouched instance state and selecting work through its actual descriptor.
- [Compatibility and quantity transfer](RESOURCE_PAIRS.md), including the
  character-specific table and actual model/collision retirement on depletion.
- [Recipe primitive execution](RESOURCE_RECIPES.md), including actual content,
  model and inventory consumers, and the [main owned dispatcher](OWNED_RESOURCE_RECIPES.md)
  with its actual cooperative event consumer.
- [Cooperative event evidence](COOPERATIVE_EVENTS.md), with a bounded native
  pool bound to the actual update clock and room. The owned-recipe producer is
  bound; other event producers and statistics/save consumers remain open.
- [Completion statistics and explicit item events](COMPLETION_STATISTICS.md),
  using all five owned rule groups and the same actual event pool, and
  [automatic completion](AUTOMATIC_COMPLETION.md) through the actual native
  worker/flag/actor/action-choice owners. Other ownership writers, statistics
  counters and game caller installation remain open.
- [Scenario ownership publication](SCENARIO_OWNERSHIP_PUBLICATION.md) through
  actual flag writes and timer callbacks. The admitted local writer is native;
  other writers and actual message queue/transport consumers remain open.
- [Actor health/status messages](ACTOR_STATUS_MESSAGES.md), including actual
  Owner status clearing, phase/authority/suppression and mapped-channel behavior.
  Other message selectors, actual network consumers and game installation remain
  open.
- [Item healing/status core](RESOURCE_HEALTH_EFFECTS.md), including actual actor
  mutations, native status messages and cooperative event publication. The outer
  required UI/device/text consumers and real game callers remain open.
- [Outer item effects](RESOURCE_EFFECTS.md) through those actual healing and
  deployment consumers, including quantity/statistics ordering and real model
  retirement on depletion. Weapon depletion/cost and actual UI/transport
  consumers remain open.
- [Weapon depletion and use cost](RESOURCE_DEPLETION.md) through actual content,
  debris, equipped-resource cue and weapon refresh consumers. The
  [explicit absence/sound-queue correction](WEAPON_WMD_ABSENCE.md) additionally
  admits all eighteen audited stock selectors without WMD files, continuing
  actual sound enqueue through the canonical loader.
- [Outer owned-resource use](OWNED_RESOURCE_USE.md) through those same actual
  cost/depletion and primary/shared-secondary retirement owners. Saved flags,
  quantity rereads and retained actor/inventory references compare; actual actor
  callers and installation remain open.
- [Resource claims and ownership primitives](RESOURCE_OWNERSHIP.md) use those
  same canonical inventory, descriptor, primary/shared-secondary and factory
  owners. Owner assignment and world/owned swaps have complete original
  comparisons; pickup/peer/journal/statistics/transport callers, saved-placement
  producers, extended actors and installation remain open.
- [Actor resource operations](ACTOR_RESOURCE_OPERATIONS.md) are qualified
  through actual quantity/inventory cleanup, release and remap consumers. The
  same work corrects a duplicate native D92 notice field so equipment and item
  producers reach the canonical World publication stage. Higher-level pickup,
  peer/statistics/final delivery consumers and installation remain open.
- [Actor action messages](ACTOR_ACTION_MESSAGES.md) are qualified through
  the update Owner and canonical World notice state, including actual offline
  peer requests. The work also joins the frame and message-suppression views of
  744638. Actual queue/receiver/transport and installation remain open.
- [Interaction and inventory messages](ACTOR_INVENTORY_MESSAGES.md) add the real
  selectors4/10/12/15 through canonical request/pair/inventory state and preserve
  intentional no-message selectors0/13. All eight admitted actor branches share
  one qualified gate/dispatch; remaining selectors, actual producers, transport
  and installation remain open.
- [Actor state and periodic publication](ACTOR_STATE_MESSAGES.md) supplies
  selector2, its actual primary/substate and selected-gauge helpers, and664F60's
  clock/slot gate. The [actual behavior composition](ACTOR_ACTIVITY_PUBLICATION.md)
  now binds World/frame/behavior through the UpdateOwner's same actor identity
  and clock. BAC writers/import, other behavior frontiers, transport and
  installation remain open.
- [Gauge adjustment and threshold events](ACTOR_GAUGE_EFFECTS.md) now supply
  complete660060/667E90/668050 through the actual canonical actor and cooperative
  event pool. The BBA modifier reuses the existing model-variant view. The
  [pending-hit consumer](ACTOR_HIT_GAUGE.md) now binds that owner through actual
  World/frame/behavior and resets the canonical D28 control counter directly.
  Other hit effects, periodic progression, initialization/import and installation
  remain open.
- [Auxiliary resource lists and inventory transfer](RESOURCE_AUXILIARY_LISTS.md)
  now supply5B5F10/5B6180/5B6300 and the actual5F6800 actor caller through the
  canonical Session, descriptors, templates and real model retirement. Terminal
  and periodic-gauge callers, other list producers/consumers, semantic save/load
  and game installation remain open.
- [Terminal countdown and transition](ACTOR_TERMINAL_TIMER.md) now supplies
  complete6687A0 through actual inventory transfer, model retirement, action-pose
  capture and the native behavior stage. A native frame comparison includes later
  action7 publication and rejection. Other terminal/cap transitions, periodic
  progression, initialization/import and installation remain open.
- [Periodic gauge policy](ACTOR_PERIODIC_GAUGE.md) now supplies667420 through
  actual inventory, resource retirement, threshold/cap events, action snapshots
  and its native behavior stage. Both compiler comparisons include timer
  modifiers, callback mutation, actual models and retained failure prefixes.
  UI/recovery/off-room effects remain required consumers; their migration,
  other actions, semantic save/load and installation remain open.
- [Full actor snapshot publication](ACTOR_SNAPSHOT_MESSAGES.md) now supplies
  selector1 through canonical action/aim/resource state and the shared frame
  suppression word. Both compiler comparisons cover callback mutation and
  recursive suppression. Real field producers, remaining selectors, actual
  queue/receiver/transport and installation remain open.
- [Recovery transition and gauge caller](ACTOR_RECOVERY.md) now supplies65FCB0
  through canonical status/full-state messages, inventory/resource retirement,
  health classification, actual animation selection and channel activation. The
  gauge owner can bind it directly. Both compiler comparisons include confirmed
  absent animation banks; loaded-clip recovery, actual UI and game installation
  remain open.
- [Zero-health entry and behavior](ACTOR_ZERO_HEALTH.md) now supplies65FBA0 and
  complete6607D0 through actual inventory/model retirement, action poses and
  full-state publication. The behavior adapter uses that same status core with
  real native effects. Both compiler comparisons include retained delivery
  failures and later action7 publication. Other actions, initialization, actual
  UI/transport, semantic saves and installation remain open.
- [Alignment-target publication](ACTOR_ALIGNMENT_MESSAGES.md) now supplies
  selector6 through a canonical optional target, independently of current pose
  and gauge state. Both compiler comparisons cover raw values, mapping and
  callback mutation. Real target producers, alignment movement, remaining
  selectors, transport and game installation remain open.
- [Contact alignment preparation](ACTOR_CONTACT_ALIGNMENT.md) now supplies
  complete666F50 through canonical contact geometry and the same optional
  target. Native heading math compares against the complete original atan/
  quadrant/turn and separate sine/cosine chain on both compilers. The actual
  UpdateOwner prepares and publishes the result. Other target producers,
  alignment motion, remaining messages, transport and installation remain open.
- [Contact snapshots](ACTOR_CONTACT_SNAPSHOTS.md) now supply selector5 through
  the canonical hit/collision state, finite position conversion and shared
  suppression. Native entity identities replace the embedded guest pointer.
  Both compiler comparisons cover mapped callback mutation and recursive sends;
  messages3/8/9/11, actual consumers/transport and installation remain open.
- [Room-object messages](ACTOR_ROOM_OBJECT_MESSAGES.md) now supply selector9
  through the canonical imported32-record owner shared with geometry and
  scenario commands. Both compiler comparisons cover signed coordinates,
  initialized inactive records and owner replacement during lookup. Incoming
  application, messages3/8/11, transport and installation remain open.
- [Native reception and bounded queue](ACTOR_RECEPTION_AND_QUEUE.md) now apply
  branches4/6/9/10/12/14/15 through actual actor/inventory/room-object state,
  shared pose cleanup and real equipment/resource/model reconciliation. Both
  compiler comparisons include actual UpdateOwner-to-queue-to-receiver delivery,
  retained failures and model exhaustion. External transport, remaining message/
  action/AI branches, semantic saves and installation remain open.
- [Auxiliary actor ownership](AUXILIARY_ACTOR_POOL.md) now supplies the distinct
  ten-actor pool, four attachment reservations and filtered/unfiltered identifier
  lookup in the canonical World. Both compiler comparisons cover reuse/order,
  retirement and coexistence with the fifty-model pool. Actual auxiliary actor
  construction, callbacks/AI/movement, peer binding and installation remain open.
- [Paired actor requests](ACTOR_PEER_MESSAGES.md) now bind selector8 and its
  receiver to that same primary/auxiliary ownership, using portable logical
  references and the existing hit-state byte. Both compiler comparisons include
  actual hit cleanup, missing-target prefixes and queue delivery across Worlds.
  Higher producers, senders3/11, remaining consumers/transport and installation
  remain open.
- [Speech-state messages and peer-map presence](ACTOR_SPEECH_MESSAGES.md) now
  bind selector11 and its receiver to canonical SPK state, actual selected gauge
  and a World-bound inventory-map cache. Partial off-room receipts preserve
  unknown state. Higher speech/text/UI consumers, sender3, other incoming
  branches, external transport and installation remain open.
- [Semantic interaction requests](ACTOR_INTERACTION_REQUESTS.md) now bind
  outgoing/incoming selector3 through the same canonical hit pending byte and
  model reference, preserving the typed anchor/orientation/distance/endpoint.
  All16 outgoing branches have native policy within their capability profiles;
  real producers/consumption, remaining incoming/action/AI/VM branches,
  external transport, semantic saves and game installation remain open.
- [Interaction state selection](ACTOR_INTERACTION_TRANSITIONS.md) now consumes
  the canonical request through64EF10's admitted table branch and the actual
  UpdateOwner, including queued delivery across Worlds. Pending consumption on
  rejection is preserved. The room/network-dependent branch, actual primary
  frame callers and remaining Stage4 consumers/installation remain open.
- [Room control and shared state](ACTOR_ROOM_CONTROL.md) now join actor hold,
  typed room-release publication and the actual outer exit-request consumer.
  Script/control pending bytes reuse the hit owner's sameBD0/AD4 fields,
  correcting earlier duplicate storage. Both compiler VM/hit/scheduler
  compositions qualify these boundaries. Offline off-room reconstruction,
  membership application/transport and remaining Stage4 installation remain open.
- [Actor fades and offline resume](ACTOR_COLOR_FADES.md) now own the actual
  primary color state and World finish-stage consumer, including integer-step
  fades, expiry/wrap behavior and status-rejected offline resume. Successful
  offline scene/navigation reconstruction, remaining higher consumers,
  renderer submission and game installation remain open.
- [Resource deployment](RESOURCE_DEPLOYMENT.md) through actual content, model,
  visual, floor and update owners, including repeated-placement retention and
  the eleven-instance limit. Position messages share canonical publication;
  actual transport and game installation remain open.
- [Direct item consumption and visibility](RESOURCE_CONSUMPTION.md), using the
  actual inventory/model lifecycle and completion-event consumers, and
  [inventory callers/message frontend](RESOURCE_INVENTORY_CALLERS.md) over the
  same owners. Health/status effects, actual transport and game installation
  remain open.

Those components pass both compiler comparisons and parent checks. The
[weapon resource owner](WEAPON_RESOURCE_OWNER.md) also passes both compiler
comparisons with actual ROM/SND assets and background decode/PCM checks.
[Equipment attachment construction](EQUIPMENT_ATTACHMENTS.md) also passes with
actual model/secondary release, canonical weapon refresh and natural full-pool
side effects. [Primary equipment selection](EQUIPMENT_SELECTION.md) also compares
through actual attachment construction and signed action publication, including
full model and sound capacity. Equipment use/recipe/transfer, extended actors, actual
installation and game acceptance remain open; the stage is still incomplete.
The [inventory owner correction](INVENTORY_OWNER_TAG.md) preserves the modal
owner byte rather than collapsing player identities to a boolean. Current
behavior comparisons cover all256 values; the actual inventory UI remains open.
The [resource debris lifetime](RESOURCE_DEBRIS.md) now uses the same168-work
owner, copied native model poses and the actual current resource-factory floor
lease. Paired checks cover physics, fade, retirement, full pools and invalidated
owners. Weapon depletion/cost composition and game installation remain open.
The [resource companions](RESOURCE_COMPANIONS.md) now implement all six bound
factory routes through the actual shared visual/child, model, audio and timed
lighting owners. Both compiler comparisons include full construction, material
fading, action gates and capacity. Unbound or foreign owners still refuse.
Ordinary room-lighting script commands and all166 LIG inputs already have a
native owner. [Temporary-light access](LIGHTING_CAPABILITIES.md) now reuses that
same owner. The [timed resource light](TIMED_LIGHTS.md) now uses that owner and
the actual scheduler and canonical actor floor/material tag. Actual game caller
installation remains open; rendering submission belongs to Stage5.

The [modernization direction](../NATIVE_MODERNIZATION_DIRECTION.md) is
authoritative. Stage 3 closed on source-identified V38; its media/resource owners
are reused. Their temporary guest consumers do not qualify as migrated gameplay.
File #1 US is the selected edition; File #2 requires a separate validation.

| Boundary | Required native result | Current implementation/integration state |
| --- | --- | --- |
| Actor/session ownership | Native entities, player/AI ownership, state transitions, actions, movement, health/status, inventory, spawning and retirement. | Canonical native primary world now owns entity lifetimes and composes native input, behavior orchestration, health/status and pending hits. Shared RNG/options and action snapshots use one session. Individual action/surface/pose providers, inventory, game installation and enemy/auxiliary families remain open. |
| Scenario execution | Native room/scenario flags, event commands and the game's authored script interpreter; preserve all required stock opcodes and event-task behavior. | Native canonical flag banks, offline actor-delta coordinator and partial interpreter/resource lifecycle compare on both compilers. Ordinary/offline tables remain distinct; unsupported required opcodes/providers prevent installation. |
| Collision | Typed room geometry/proxies, broad/narrow queries, floor/contact resolution and actor interaction. | Native room geometry, proxy lifetime, body solver, primary post-move, ordered secondary floor pass and canonical body-queue consumer compare or pass scoped integration checks on both compilers. Full model/pose import, attack delivery and game installation remain gates. |
| Scheduling/timers | Native owner ordering, task lifetime and game clocks at original speed; preserve pause, mutation and same-pass callback rules. | Native worker and outer phase owners compose World, flags, script channels, timers, tasks and gated clock commit. Event selection and status timing share canonical session/clock state. Task factories/payloads, remaining worker/UI/audio/scene effects and game installation remain open. |
| Save/load | Native session snapshots, original save import/codec, durable file ownership and load/resume transitions. | Qualified complete native snapshot/codec and nine-entry guarded adapter, with actual SDK object checks. Temporary legacy state projection remains explicit; live save/reload, durable native ownership and semantic world snapshots remain gates. |
| Input, networking and media consumers | Native input/action frames, world/authority events and direct native resource/audio/movie interfaces. | Qualified independent actor/menu edges, remapping and repeat core. Actual input/network/media callers and platform sampling still require migration. |
| Integration/validation | A coherent native gameplay candidate, representative scenarios/rooms, controls, save/reload, pause/resume, co-op and joined shutdown. | V39 exercises all nine guarded save/session hooks across eight successful background cases, including save/load, corrupt-save dialogs and gameplay options with resumed movement. New native World/Update/scenario components are not yet installed in the game. This is not a coherent native gameplay candidate. |

The [shared scenario-control/collision-proxy pool](SCENARIO_SHARED_PROXY_POOL.md)
is an explicit installation gate: the original 128 records form one identity,
capacity, order and retirement owner. That [shared native owner](SCENARIO_SHARED_PROXY_OWNER.md)
and the [bounded room importer](SCENARIO_ROOM_SCENE_IMPORT.md) now have original
comparisons. The importer admits163 of166 owned rooms under controlled external
poses; three authoredFF rooms remain an explicit modernization/acceptance gate.
Their counter/pointer aliases must not become a native guest-memory model.
The [explicit authored NoModel repair](SCENARIO_AUTHORED_NO_MODEL_REPAIR.md)
admits all166 controlled room inputs when opted in, with measured source
deviations and lease revocation checks. It stays disabled by default and still
requires actual affected-room acceptance and the remaining matrix consumers.
Full room model/resource construction and actual game installation remain open.

Completion requires native ownership and migrated real consumers across every
row, with source/build identities, behavioral comparisons and game acceptance.
An isolated module, hook into a native function, mirrored guest layout, or
generated-body count alone does not close this stage. Callback/provider seams
must identify their remaining owners and be removed as those callers migrate.

The current periodic-effect checkpoint supplies the actual native resource,
material, pose, camera-offset and visual lifetime consumer behind opcode131,
with both compiler comparisons passing. Its [visual contract](PERIODIC_VISUALS.md)
corrects the earlier scalar track field labels; the [scenario command](SCENARIO_PERIODIC_EFFECTS.md)
uses the canonical scheduler/flags/RNG with full ownership checks. These are
qualified components. The game's installed gameplay still remains the V39
guarded save/session checkpoint, with the new World/scenario owners uninstalled.

Further qualified components now include [matrix curve playback](SCENARIO_MATRIX_PLAYBACK.md),
[actor motion selection/playback](ANIMATION_PLAYBACK.md), [resource attachments](ANIMATION_RESOURCE_ATTACHMENTS.md),
the [single World-owned linked model pool](ANIMATION_LINKED_MODELS.md), and
[active constrained attachment composition](ANIMATION_CONSTRAINED_ATTACHMENTS.md).
The [ground fixture correction](ANIMATION_GROUND_FIELD_AUDIT.md) supersedes an
earlier coverage claim; it did not require a production solver change.
Contact effects now use the corrected mask/variant contract and checked canonical
RNG binding, with a generation-checked World/model/room interface. The
[shared effect work and fog owner](EFFECT_WORK_AND_FOG.md) supplies actual general
visual consumers and the fog companion through the same168/256 domains.
These do not close actual animation-event, resource-creation, scene/audio/input,
network, save-owner, stock-script and game-acceptance gates.

Further component checkpoints include [frame crossings and caller timing](ANIMATION_FRAME_EVENTS.md),
[player event schedules](ANIMATION_PLAYER_EVENTS.md), [reached event primitives](ANIMATION_EVENT_PRIMITIVES.md),
[native bank audio routing](AUDIO.md), and [shared water-surface effect work](EFFECT_SURFACE_WORK.md).
The [explicit floor-type correction](FLOOR_EXPLICIT_SURFACE_TYPES.md) restores
specific high-bit surface queries while preserving generic floor filtering.
These have paired source comparisons; they do not establish a fully migrated
scene/resource/input/network/save owner or native game acceptance.
The [A8 scenario effect command](SCENARIO_SURFACE_EFFECTS.md) additionally
compares the current World/scenario/shared effect owners together without
historical source pins. This closes that bounded composition check, not game
installation or the remaining script families.
The [actor/resource animation audio frontends](ANIMATION_AUDIO_FRONTENDS.md)
now supply real canonical bank consumers for their qualified routes, including
exact PCM comparison. The [surface audio route](ANIMATION_SURFACE_AUDIO.md)
also reuses canonical room regions and adds bounded footwear profiles.
The [node/scenario position routes](ANIMATION_NODE_POSITION_AUDIO.md) now also
use canonical scene/model/session state and the actual bank mixer. Actual room
bank/model assignment and the remaining event/resource consumers remain open.
The [scene matrix bank consumer](SCENE_BANK_AUDIO.md) also connects real native
channel playback to the same bank mixer with complete source consumer checks.
The [bounded named bank loader](NAMED_BANK_LOADING.md) now supplies actual
archive reads and off-thread bank preparation for direct SND loads. Combined
enemy/staged banks and real game caller installation remain open.
The [weapon program selector and scalar sampler](WEAPON_PROGRAMS.md) now use
actual owned WMD data and the existing native actor/resource owners. Resource
visual callbacks and loading on weapon changes remain separate work.
The distinct [64-primary-resource model owner](RESOURCE_MODELS.md) now also
preserves allocation, retirement and mutation-sensitive update ordering. Its
actual visual callbacks and resource factory/release composition remain open.

The [resource frame consumers](RESOURCE_FRAMES.md) now supply canonical primary
visibility/retirement and full admitted WMD playback through that 64-model pass.
The primary-only release composition is compared; shared secondary release,
extended owners, room pulses, required rebuild, nonattached pose updates and
the real asset/resource factory remain open. This is a component checkpoint;
the installed game is still V39 and the stage remains incomplete.
The [nonattached pose follow-up](RESOURCE_POSES.md) closes the1904A0 XZY/axis-scale
branch with full turn-domain comparisons and current weapon-frame regression.
The other resource factory and integration gates above remain open.
The [resource periodic-visual follow-up](RESOURCE_PULSES.md) also closes5925C0
through the actual existing168/256 visual owner and canonical RNG. Its complete
source comparison includes natural pool exhaustion; this emits visuals rather
than querying room regions. Secondary retirement, extended actors, required
reconstruction, construction/loading and installed gameplay remain open.
The [shared secondary retirement follow-up](RESOURCE_SECONDARY_RELEASE.md)
closes5B1850/5B1A90 through the actual64-primary and shared128 scene owners,
including self-retirement during a real model pass. Current frame, pulse,
scene-resource and full scenario regressions pass on both compilers.592770's
remaining action is conditional deactivation, not a reconstruction factory.
The [conditional deactivation follow-up](RESOURCE_DEACTIVATION.md) now closes
that592770/591BE0 branch through canonical descriptors, templates and instance
retirement. Active count is a derived table view. Extended actors, actual asset/
resource construction and installed native gameplay acceptance remain open.
The [descriptor allocation follow-up](RESOURCE_DESCRIPTOR_ALLOCATION.md)
closes591AE0/5B42B0 in the canonical table and template owners, with all five
owned item-template sections and the complete signed selector domain compared.
The allocator preserves reserved slot0 and the255-active gate. This supplies
descriptor creation; actual instance/resource factories remain open.
The [static resource asset follow-up](RESOURCE_STATIC_ASSETS.md) imports actual
owned NBD forests into immutable primary part poses, with full signed lookup
comparisons. This removes the need for controlled matrices on admitted roots
when construction adopts it. Two larger-part roots remain explicit unavailable
cells under the current six-part primary contract; the factory is still open.
The [model slot-reuse follow-up](RESOURCE_MODEL_REUSE.md) removes the earlier
unadmitted-reuse gate for valid construction callbacks. Traversal follows the
new occupant's continuation while old model capabilities remain retired.
Actual factory and delayed callback composition remain open.
The [resource correction-matrix fix](RESOURCE_CORRECTION_MATRIX.md) joins the
weapon part5 and attachment correction views to one actual matrix. Current
frame and attachment regressions pass; this fixes native composition before
installation and is not a measured cause of the historical slowdown.

Ordinary game-script bytecode and asset encodings may remain. The new gameplay
core must not execute MIPS, contain a simulated register file or depend on a
guest-addressed RAM model. Renderer/model submission remains an explicit Stage 5
interface; final compatibility/build dependency deletion belongs to Stage 6.

Preserve rules, content, original game speed, saves and co-op. Native state and
ownership can modernize obsolete allocation/scheduling internals; do not turn
unknown original behavior into a guessed successful implementation. Record
unsupported profiles and missing evidence explicitly.
