#pragma once
#include "material_uv.hpp"
#include "scripted_actor.hpp"
#include "npc_actor_state.hpp"
#include "primary_actor_state.hpp"
#include "primary_saved_state.hpp"
#include "humanoid_motion_bindings.hpp"
#include "linked_update_state.hpp"
#include "speech_state.hpp"
#include "secondary_pose_state.hpp"
#include "pose_work_state.hpp"
#include "actor_sound_state.hpp"
#include "head_reaction_state.hpp"
#include "../gameplay_actors/entity.hpp"
#include "../gameplay_actors/reference.hpp"
#include "../gameplay_actors/hit.hpp"
#include "../gameplay_actors/input.hpp"
#include "../gameplay_collision/actors.hpp"
#include "../gameplay_collision/contact_component.hpp"
#include "../gameplay_collision/room_damage.hpp"
#include "../gameplay_scenario/model_reference.hpp"
#include "../gameplay_scenario/auxiliary_room_rows.hpp"
#include "../gameplay_scenario/cutscene_requests.hpp"
#include "../gameplay_scenario/room_actor_assets.hpp"
#include "../gameplay_scenario/npc_descriptors.hpp"
#include "../gameplay_scenario/enemy_descriptors.hpp"
#include "../gameplay_scenario/enemy_routes.hpp"
#include "inventory_state.hpp"
#include "enemy_state.hpp"
#include "actor_placements.hpp"
#include "../gameplay_session/room_variants.hpp"
#include "../gameplay_session/activity.hpp"
#include "../gameplay_navigation/actor_routes.hpp"
#include "../gameplay_ai/execution.hpp"
#include "../gameplay_ai/control_requests.hpp"
#include <array>
#include <memory>
#include <optional>
#include <vector>

namespace reo::native::animation {class Instance;class Constraints;class Playback;class WeaponProgramBank;}
namespace reo::native::gameplay_navigation {class Bank;}
namespace reo::native::gameplay_scenario {class CutscenePlayback;class CutsceneActorTracks;class CutsceneObjectTracks;class CutsceneRosterPreparation;}
namespace reo::native::gameplay_update {class LinkedModelWorkers;class Owner;class ActorReception;}
namespace reo::native::gameplay_application {class ResourceBootstrap;class SessionResources;class SessionStartupEffects;class SessionRooms;class SessionRoomMotions;}
namespace reo::native::gameplay_world {
namespace actors=gameplay_actors;
namespace input=gameplay_actors::input;
struct Position {float x{},y{},z{};};
struct AlignmentTarget {Position position;std::int16_t yaw{};};
// Original actor bytes FAA/FA8/BCE, consumed and written by analog-control
// preparation6621F0. BCE remains a persistent control target independent of
// the optional alignment producer's C4C yaw.
struct AnalogControlState {std::int8_t heading_active{};std::int16_t previous_input_heading{},control_target_heading{};};
// Primary-family C0/C4/C8 and D10. These are independent of the D8/E4
// motion impulses and of the other actor families' pose-work overlay.
struct PrimaryLocomotionState {Position velocity;std::uint8_t marker{};float root_sample_z{};}; //CE4 is5D7BC0's retained node sample.
//67FF80's registration word B34 and sequence bytes DA6/DA7.
struct InteractionRegistrationState {std::uint32_t selection_word{};std::uint8_t sequence{},previous_sequence{};};
//C74/C75/C76 are produced by5C5B50/5C5BD0 and consumed by64F2D0.
//They are distinct from C78/C79's inventory interaction kind/mode.
struct InteractionControlRequest {std::uint8_t pending{},variant{},parameter{};};
struct PeerRequest {std::uint8_t state_high{};actors::ActorReference peer;std::array<std::int16_t,2> parameters{};};
struct InteractionRequest {
    std::uint8_t kind{},parameter{};Position anchor;
    std::uint32_t orientation{};float travel_distance{};std::uint8_t endpoint{};
};
// Source publications at4BAE05/07 and3243E0/E2. The scenario component is
// copied from canonical Session::scenario (3243DA); it is never mirrored.
struct SceneTransitionPublication {
    std::uint8_t kind{},variant{};
    std::uint16_t scenario{},destination{};
};
struct ColorFade {std::uint32_t rgba{},step{},updates_left{};};
struct CollisionShapeTarget {gameplay_collision::Vec3 center;float radius{};};
struct ControlRequest {std::uint8_t kind{};std::uint16_t parameter{};};
struct ProjectileContact {gameplay_collision::Vec3 point,normal;};
// Linked-family C94 belongs to targeting, not the primary inventory bytes at
// the same original layout offsets. Presence requires its actual producer.
struct TargetingState {
    std::uint32_t flags{};
    bool selected_model_point{};
    std::optional<std::uint8_t> model_point{}; // linked-family551, supplied by its actual producer
    std::optional<std::uint8_t> head_model_point{}; // original552, distinct from551
};
struct ActorCollision {
    gameplay_collision::Vec3 local_center,previous_center_offset,displacement;
    gameplay_collision::Vec3 previous_local_center,interpolation_step;
    float radius{};
    float previous_radius{};
    std::uint8_t interpolation_ticks{};
    std::optional<CollisionShapeTarget> interpolation_target;
    bool contact{},pose_ready{};
    std::optional<gameplay_collision::Vec3> point,normal,joint_two_position;
    std::uint16_t route_ticks{};
    gameplay_collision::actors::Basis basis;
    std::optional<gameplay_collision::actors::ShapeDefinition> body_definition;
    std::uint8_t body_priority{},separation_count{};
    actors::EntityId body_peer;
    gameplay_collision::actors::Summary body_summary;
};
class ActorModelAsset;
// One canonical native actor. The health/status/hit fields are inherited once;
// native functions operate on this same object, not mirrored byte records.
struct Actor : actors::Entity,actors::HitActor {
    bool active{},visible{};
    std::uint8_t ai_control{},normalized_marker{};
    // Original signed+C used by contact-style5. Actual full-record clears
    // establish zero; generic Actor construction does not supply this value.
    std::optional<std::int16_t> contact_style_discriminator;
    std::optional<PoseWorkState> pose_work;
    std::optional<ActorSoundState> sound_state; //554/33; actual full-record producer required
    std::optional<std::uint8_t> projectile_variant; //CF2; ordinary-family producer required
    std::optional<gameplay_navigation::ActorRouteState> navigation_route;
    std::optional<gameplay_ai::ExecutionState> ai_execution;
    std::optional<TargetingState> targeting;
    std::optional<SecondaryPoseHistory> secondary_pose_history;
    std::optional<std::uint32_t> secondary_pose_category_override; // FAC; actual producer required
    std::optional<HeadReactionState> head_reaction;
    std::optional<std::uint8_t> surface_transition_flags; // CE2; established by actual record clear
    std::optional<EnemyState> enemy;
    std::optional<ScriptedActorState> scripted;
    std::optional<NpcActorState> npc;
    std::optional<PrimaryActorState> primary_state;
    std::optional<LinkedActorFrameState> linked_frame;
    std::uint8_t character{};
    std::optional<std::uint32_t> gauge_value; // original BAC; unknown until its actual owner/import supplies it
    std::uint16_t terminal_countdown{}; // original C62, distinct from status/hit recovery timers
    std::uint8_t appearance_variant{}; // original BBC; separate from character B98 and model_variant BB4
    // BBD, incremented by5C5A30 and consumed/cleared by64F110/64B060.
    // Adjacent appearance/variant fields do not establish this counter.
    std::optional<std::uint8_t> interaction_request_count;
    std::optional<std::uint8_t> collision_resource_selector; //C82;5AA160 clears,5AB280 selects one
    std::optional<std::uint8_t> scene_contact_request; //C9C; route/query collision gate
    // CB0, authored descriptor+44 byte copied by5C5A30 and published by64F110.
    std::optional<std::uint8_t> interaction_control_selector;
    std::optional<InteractionRegistrationState> interaction_registration;
    std::optional<InteractionControlRequest> interaction_control_request;
    std::optional<std::uint16_t> forward_contact_attempts; //CDE;64E960 held-contact interaction timer
    //5D6A60/5D6ED0 paired-node animation. C50 is also the cinematic
    // command's unsigned total-duration view; keep that source alias once.
    std::optional<std::int16_t> model_offset_frame; //C50
    std::optional<std::uint8_t> model_offset_phase; //C52
    std::optional<std::uint16_t> model_offset_lock; //232
    std::uint8_t motion_subtype{},motion_style{},previous_motion_class{};
    std::uint8_t selected_resource{},secondary_resource{},model_pose_class{};
    std::uint8_t secondary_equipped_resource{}; // C7D; secondary_resource is a distinct audio/model selector
    InventorySlots inventory;
    gameplay_scenario::ModelReference scene_model{128}; // resolved ABB model identity, not an authored remap index
    float motion_rate{1};
    std::uint16_t resource_action{};
    // Shared original D92/DA2..DA5 action notice. DA2 also carries a slot in
    // equipment-selection65E710 and a resource ID in inventory operations.
    std::uint16_t pending_notice{};
    std::uint8_t equipment_notice_slot{};
    std::uint8_t equipment_notice_peer{},equipment_notice_parameter{};
    std::uint8_t equipment_notice_detail{};
    // C78/C79. The request's C7A resource is inherited interaction_slot;
    // C7F is the inherited equipment_slot, not a second requested-item field.
    std::uint8_t interaction_kind{},interaction_mode{},interaction_detail{};
    // Primary actor action/aim state. Unknown until a real producer/import
    // supplies it; these are separate from the selected/equipped item slots.
    std::optional<std::uint8_t> interaction_resource; // C80, descriptor item ID from5F2B70
    std::optional<std::int16_t> aim_pitch_adjustment,aim_target_pitch; // BC8/CD4
    std::optional<std::int16_t> aim_target_yaw,aim_target_roll; // CD6/CD8
    std::optional<std::uint8_t> aim_target_index; // CDC, FF means no selected target
    // Source pointers become canonical identities. A present null identity
    // is a known absent target; a missing optional has no actual producer.
    std::optional<actors::EntityId> weapon_target; // +24, distinct from contact.related +28
    std::optional<actors::EntityId> ai_target; // +1068, selected by offline AI
    // Primary alignment contract C34/C38/C3C and C4C. Other source-state
    // overlays do not establish this target; actual producers/import must.
    std::optional<AlignmentTarget> alignment_target;
    // Present only after a source-qualified full-record clear; generic Actor
    // construction does not establish the original FAA/FA8/BCE bytes.
    std::optional<AnalogControlState> analog_control;
    std::optional<PrimaryLocomotionState> locomotion;
    // C65/C66/C68/C6A. C64's low byte is the inherited transient_contact,
    // including when pending-hit cleanup clears only that byte.
    std::optional<PeerRequest> peer_request;
    SpeechState speech;
    // AB9/ABA, ABC..AD0. AB8 remains inherited transient_action; ABB remains
    // scene_model. The three unused bytes after endpoint are not native state.
    std::optional<InteractionRequest> interaction_request;
    std::optional<std::uint8_t> interaction_subselector; // AD1; actual full-record clear establishes zero
    std::optional<std::int8_t> related_target_state; // D32, shared phase-dependent cached target/state
    // Primary actor CE8/CEC/CF0 color fade. Other source actor families reuse
    // these offsets for unrelated roles; they do not grant this capability.
    std::optional<ColorFade> color_fade;
    std::array<std::uint8_t,2> explicit_resource_pair{}; // authored action pair CAA/CAB
    std::uint16_t linked_model_variant{};
    std::uint16_t gauge_modifier_one{},gauge_modifier_two{}; // BB6/BB8; third BBA view is linked_model_variant
    std::uint8_t gauge_rate_variant{}; // original BBE, distinct from model_variant BB4
    std::uint16_t contact_flags{};
    std::uint16_t action_flags{};
    float surface_blend_weight{},surface_blend_rate{};
    std::int8_t model_correction_skip{}; // Shared source B40: scripted bank/rate mode and paused height-correction skip.
    float model_height_correction{};
    std::uint16_t model_variant{};
    std::uint32_t response_mask{},response_value{};
    std::uint8_t motion_override{},interaction_marker{},room_marker{},movement_enabled{};
    std::uint16_t frame_value_a{},frame_value_b{};
    std::uint8_t transient_marker{},grid{};
    float grid_response{};
    Position position{};
    Position candidate_direction{};
    Position model_scale{1,1,1},local_impulse{},world_impulse{},root_motion_delta{};
    float motion_multiplier{1};
    Position previous_position{};
    std::array<std::int16_t,4> orientation{},previous_orientation{};
    std::uint32_t action_elapsed{};
    Position saved_action_position{};
    std::int16_t saved_action_yaw{};
    float sampled_surface_height{};
    bool sampled_surface_valid{};
    std::uint8_t surface_kind{255},surface_material{255}; // original174/175; material also tags transient lights
    std::uint16_t surface_attributes{};
    Position surface_normal{0,1,0};
    ActorCollision collision;
    ProjectileContact projectile_contact;
    std::optional<std::uint8_t> forward_contact_status; // +540;65F4A0 stores the low byte returned by5795E0
    gameplay_collision::delivery::Component contact;
    std::optional<MaterialUv> material_uv;
    std::shared_ptr<animation::Instance> model;
    std::shared_ptr<const ActorModelAsset> model_asset;
    std::shared_ptr<animation::Constraints> constraints;
    std::shared_ptr<animation::Playback> animation;
    std::array<std::optional<HumanoidMotionAlias>,3> motion_bank_aliases;
    std::shared_ptr<const animation::WeaponProgramBank> weapon_programs;
    ControlRequest control_request;
    // BD0 is inherited response_lock, also used by script/control cleanup.
    // AD4 pending is inherited transient_equipment; ControlRequest owns only
    // the AD5 kind and AD6 parameter.
    input::Frame input;
};
struct Session : actors::HitSession {
    gameplay_session::RoomVariants room_variants;
    std::optional<std::uint16_t> room_variant;
    ActorPlacements actor_placements;
    gameplay_scenario::CutsceneRequests cutscene_requests;
    gameplay_scenario::AuxiliaryScene auxiliary_scene;
    gameplay_scenario::RoomActorAssets room_actor_assets;
    gameplay_scenario::NpcDescriptors npc_descriptors;
    gameplay_scenario::MissingCharacters missing_characters;
    gameplay_scenario::EnemyDescriptors enemy_descriptors;
    gameplay_scenario::EnemyRoutes enemy_routes;
    LinkedUpdateState linked_updates;
    std::uint8_t script_room_parameter{}; // original4B9D17; exact downstream use is unresolved
    gameplay_collision::delivery::RoomContacts room_contacts;
    //3C2748: only the actual wall-grid installation6161E0 establishes zero.
    // Generic sessions retain unknown state until that producer is installed.
    std::optional<std::uint32_t> collision_disabled_mask;
    gameplay_session::Random random{};
    gameplay_session::Options options;
    std::uint8_t previous_primary{},previous_secondary{};
    std::uint8_t inventory_owner{}; // source4BADEE: zero inactive,1..4 primary owner tags
    std::array<std::array<std::uint8_t,8>,4> auxiliary_resources{}; // first four session recovery lists4BAC52; independent of entity lifetime
    std::uint8_t control_notice{};
    std::uint8_t exit_requested{}; //3243D8; shared actor hold producer and outer update consumer
    std::optional<std::uint16_t> scenario;
    std::optional<SceneTransitionPublication> scene_transition_publication;
    std::optional<std::uint16_t> last_scenario_audio; // original316550, written even when a bank request is rejected
    std::uint8_t resource_hide_selected{},resource_hide_others{}; // original4B9D10/11
    std::array<std::uint8_t,2> resource_hide_remaining{}; // original4B9D12/13
    std::uint8_t sound_loading_mode{}; // original324405; only mode2 rejects queued direct bank loads
    // Original3243D7 chooses resident-file versus archive-bundle resource work.
    // It is independent of pause4BADF8. The actual content owner must supply it.
    std::optional<std::uint8_t> asset_loading_mode;
    std::optional<std::uint8_t> setup_gate; //3243D2; actual5EB520/scene-transition producer required
    std::optional<std::uint8_t> scene_stream_stage; //3243FE; actual5EC3A0/load-finalizer producer required
    std::uint8_t gameplay_flags{}; // original4BAE96; use override bit0, contact-mode bit1
    std::int8_t message_phase{}; // original3243FB;1/2 enable the1B0310 message branch, independent of mode
    std::uint16_t actor_message_suppression{}; // original744638; shared selector suppression, not per actor
    // Authored primary population count, source4BAEA0. Unknown is not zero;
    // storage/registration and the active byte remain independent concepts.
    std::optional<std::uint32_t> primary_population;
    // Presence selects the real imported primary-initialization override.
    // Fresh sessions have none; parsing a save does not enable it implicitly.
    std::optional<PrimarySavedActors> primary_initialization_snapshot;
    std::uint8_t single_roster_setup{}; // original4BAE32, set by mode-zero roster initialization
    gameplay_ai::ControlRequests ai_control_requests;
    gameplay_session::ActivityState activity;
    //4BAE8A: imported from actual launch selection37F330 (frontend318B65).
    // Generic construction does not establish the authored difficulty.
    std::optional<std::uint8_t> difficulty;
};
struct Profile {
    std::vector<input::Remap> layouts;
    std::size_t controller_count{4};
    actors::EntityConfig entities;
};
enum class Stage {
    offline_ai,leave_room,prepare_contacts,prepare_authority,update_behavior,
    update_local_motion,update_pose,update_auxiliary_motion,finish_motion,
    refresh_grid_position,finish_actor,publish_notice
};
class World;
class PoseWorkPool;
class DialoguePool;
class LinkedModelPool;
class LinkedActorUpdates;
class NpcActorUpdates;
class CinematicActorFrames;
class CinematicActorReactions;
class PrimaryActorPostprocess;
class AuxiliaryActorPostprocess;
struct PrimaryRecordsInitialized;
class CinematicModelPass;
class CinematicObjectPool;
class CinematicObjectConstruction;
class AuxiliaryActorPool;
class TargetMetricCache;
class PrimaryActorModels;
class ScenePrimaryActorPool;
class Services {
public:
    virtual ~Services()=default;
    virtual void begin_offline_frame(World&)=0;
    virtual void run(Stage,World&,Actor&)=0;
    virtual bool remote_motion(World&,Actor&)=0;
    virtual bool find_grid(World&,Actor&,std::int8_t&)=0;
    virtual void switch_grid(World&,std::int32_t next,std::int32_t previous)=0;
    virtual float grid_response(World&,std::uint8_t)=0;
};
enum class Status {completed,busy,closed,input_unavailable};
struct Result {Status status{Status::completed};std::size_t visited{},updated{};};
class World final {
    std::shared_ptr<Session> session_;
public:
    // World, its Session and borrowed controller spans are simulation-owner
    // thread only. Actor leases may outlive retirement, but must not keep/use a
    // raw World reference after that owner's lifetime ends.
    static constexpr std::size_t primary_capacity=8;
    explicit World(Profile,std::shared_ptr<Session>);
    ~World();
    World(const World&)=delete;
    World& operator=(const World&)=delete;
    actors::EntityCreated spawn_primary(std::size_t,std::unique_ptr<Actor>)noexcept;
    actors::EntityStatus retire_primary(std::size_t)noexcept;
    actors::EntityCreated spawn_linked(std::unique_ptr<Actor>)noexcept;
    actors::EntityStatus retire_linked(const actors::EntityId&)noexcept;
    LinkedModelPool& linked_models();
    AuxiliaryActorPool& auxiliary_actors();
    ScenePrimaryActorPool& scene_primary_actors();
    CinematicObjectPool& cinematic_objects();
    gameplay_navigation::Bank& navigation();
    const gameplay_navigation::Bank* navigation_if_created()const noexcept{return closed_?nullptr:navigation_.get();}
    TargetMetricCache& target_metrics();
    std::shared_ptr<Actor> primary(std::size_t)const noexcept;
    bool actor_roster_ready()const noexcept;
    std::optional<bool> contains_character(std::uint8_t)const noexcept;
    std::shared_ptr<Actor> resolve(const actors::EntityId&)const noexcept;
    std::shared_ptr<Actor> referenced_actor(const actors::ActorReference&)const noexcept;
    actors::EntityId identity_of(const Actor&)const noexcept;
    actors::EntityId identity(std::size_t)const noexcept;
    std::optional<std::size_t> executing_primary()const noexcept{return executing_;}
    Result update_primary(Services&);
    Status close()noexcept;
    Session& session()noexcept{return *session_;}
    const Session& session()const noexcept{return *session_;}
    bool closed()const noexcept{return closed_;}
    bool busy()const noexcept;
    const gameplay_scenario::CutscenePlayback* cinematic_controller()const noexcept{return closed_?nullptr:cutscene_playback_owner_;}
    const HumanoidMotionSource* humanoid_motion_source()const noexcept{return humanoid_motion_source_;}
    bool humanoid_motion_source_closed()const noexcept{return humanoid_motion_source_closed_;}
    // Complete1B0340 predicate over this canonical session and actor state.
    // Callers holding capabilities resolve them in this World before querying.
    bool locally_controlled(const Actor& actor)const noexcept{return actor.category==0&&actor.slot==(mode==0?0:selected_actor);}
    std::span<input::ControllerFrame> controllers()noexcept{return controllers_;}
    std::span<const input::ControllerFrame> controllers()const noexcept{return controllers_;}
    std::span<const input::Remap> layouts()const noexcept{return layouts_;}
    std::array<std::int8_t,8> controller_bindings{-1,-1,-1,-1,-1,-1,-1,-1};
    // Aliases refer to the one canonical native session used by health/hit
    // functions too. No per-callback import/export or shadow session is needed.
    std::uint8_t& mode;
    std::uint8_t& selected_actor;
    std::int8_t& paused;
    bool& filter_nonselected_input;
    std::uint16_t& room;
    std::optional<std::uint16_t>& scenario;
    std::uint8_t selected_frame_marker{};
    std::uint16_t& frame_shared_counter;
private:
    friend class DialoguePool;
    DialoguePool* dialogue_pool_owner_{};
    friend class PoseWorkPool;
    PoseWorkPool* pose_work_owner_{};
    friend class AuxiliaryActorPool;
    friend class ScenePrimaryActorPool;
    actors::EntityStore entities_;
    std::array<actors::EntityId,8> primary_;
    std::unique_ptr<LinkedModelPool> linked_models_;
    LinkedActorUpdates* linked_update_owner_{};
    friend class LinkedActorUpdates;
    gameplay_update::LinkedModelWorkers* linked_model_owner_{};
    friend class gameplay_update::LinkedModelWorkers;
    gameplay_scenario::CutscenePlayback* cutscene_playback_owner_{};
    friend class gameplay_scenario::CutscenePlayback;
    friend class gameplay_application::ResourceBootstrap;
    friend class gameplay_application::SessionResources;
    // Only 5EB520's synchronous 591C50 site authorizes nested bootstrap.
    bool primary_resource_startup_{};
    friend class gameplay_application::SessionStartupEffects;
    friend class gameplay_application::SessionRoomMotions;
    // Scoped to 5EB520's 1D3E90/68C890 synchronous script callers.
    bool primary_script_startup_{};
    bool primary_object_startup_{};
    friend class gameplay_application::SessionRooms;
    friend class gameplay_update::Owner;
    friend class gameplay_update::ActorReception;
    gameplay_scenario::CutsceneActorTracks* cutscene_tracks_owner_{};
    friend class gameplay_scenario::CutsceneActorTracks;
    gameplay_scenario::CutsceneObjectTracks* cutscene_object_tracks_owner_{};
    friend class gameplay_scenario::CutsceneObjectTracks;
    friend class gameplay_scenario::CutsceneRosterPreparation;
    friend class NpcActorConstruction;
    friend class CommonActorFrame;
    friend class NpcActorUpdates;
    NpcActorUpdates* npc_update_owner_{};
    friend class CinematicActorFrames;
    friend class CinematicActorReactions;
    friend class PrimaryActorPostprocess;
    friend class AuxiliaryActorPostprocess;
    friend PrimaryRecordsInitialized initialize_primary_records(World&)noexcept;
    CinematicActorFrames* cinematic_frame_owner_{};
    friend class CinematicModelPass;
    friend class ActorModelPasses;
    friend class CinematicObjectPool;
    friend class CinematicObjectConstruction;
    std::unique_ptr<CinematicObjectPool> cinematic_objects_;
    friend class HumanoidMotionOwner;
    friend class PrimaryActorInitialization;
    friend class PrimaryActorModels;
    PrimaryActorModels* primary_model_owner_{};
    HumanoidMotionSource* humanoid_motion_source_{};
    bool humanoid_motion_source_closed_{};
    std::unique_ptr<AuxiliaryActorPool> auxiliary_actors_;
    std::unique_ptr<ScenePrimaryActorPool> scene_primary_actors_;
    std::unique_ptr<gameplay_navigation::Bank> navigation_;
    std::unique_ptr<TargetMetricCache> target_metrics_;
    std::vector<input::Remap> layouts_;
    std::vector<input::ControllerFrame> controllers_;
    bool updating_{},closed_{};
    std::optional<std::size_t> executing_;
};
} // namespace reo::native::gameplay_world
