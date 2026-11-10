#pragma once
#include "speech_state.hpp"
#include "../gameplay_actors/entity.hpp"
#include "../gameplay_actors/reference.hpp"
#include "../gameplay_actors/hit.hpp"
#include "../gameplay_actors/input.hpp"
#include "../gameplay_collision/actors.hpp"
#include "../gameplay_collision/contact_component.hpp"
#include "../gameplay_scenario/model_reference.hpp"
#include "inventory_state.hpp"
#include <array>
#include <memory>
#include <optional>
#include <vector>

namespace reo::native::animation {class Instance;class Constraints;class Playback;class WeaponProgramBank;}
namespace reo::native::gameplay_world {
namespace actors=gameplay_actors;
namespace input=gameplay_actors::input;
struct Position {float x{},y{},z{};};
struct AlignmentTarget {Position position;std::int16_t yaw{};};
struct PeerRequest {std::uint8_t state_high{};actors::ActorReference peer;std::array<std::int16_t,2> parameters{};};
struct InteractionRequest {
    std::uint8_t kind{},parameter{};Position anchor;
    std::uint32_t orientation{};float travel_distance{};std::uint8_t endpoint{};
};
struct CollisionShapeTarget {gameplay_collision::Vec3 center;float radius{};};
struct ControlRequest {std::uint8_t pending{},kind{};std::uint16_t parameter{};};
struct ProjectileContact {gameplay_collision::Vec3 point,normal;};
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
// One canonical native actor. The health/status/hit fields are inherited once;
// native functions operate on this same object, not mirrored byte records.
struct Actor : actors::Entity,actors::HitActor {
    bool active{},visible{};
    std::uint8_t ai_control{},normalized_marker{};
    std::uint8_t character{};
    std::optional<std::uint32_t> gauge_value; // original BAC; unknown until its actual owner/import supplies it
    std::uint16_t terminal_countdown{}; // original C62, distinct from status/hit recovery timers
    std::uint8_t appearance_variant{}; // original BBC; separate from character B98 and model_variant BB4
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
    std::optional<std::uint8_t> aim_target_index; // CDC, FF means no selected target
    // Primary alignment contract C34/C38/C3C and C4C. Other source-state
    // overlays do not establish this target; actual producers/import must.
    std::optional<AlignmentTarget> alignment_target;
    // C65/C66/C68/C6A. C64's low byte is the inherited transient_contact,
    // including when pending-hit cleanup clears only that byte.
    std::optional<PeerRequest> peer_request;
    SpeechState speech;
    // AB9/ABA, ABC..AD0. AB8 remains inherited transient_action; ABB remains
    // scene_model. The three unused bytes after endpoint are not native state.
    std::optional<InteractionRequest> interaction_request;
    std::optional<std::int8_t> related_target_state; // D32, shared phase-dependent cached target/state
    std::array<std::uint8_t,2> explicit_resource_pair{}; // authored action pair CAA/CAB
    std::uint16_t linked_model_variant{};
    std::uint16_t gauge_modifier_one{},gauge_modifier_two{}; // BB6/BB8; third BBA view is linked_model_variant
    std::uint8_t gauge_rate_variant{}; // original BBE, distinct from model_variant BB4
    std::uint16_t contact_flags{};
    std::uint16_t action_flags{};
    float surface_blend_weight{},surface_blend_rate{};
    std::int8_t model_correction_skip{};
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
    gameplay_collision::delivery::Component contact;
    std::shared_ptr<animation::Instance> model;
    std::shared_ptr<animation::Constraints> constraints;
    std::shared_ptr<animation::Playback> animation;
    std::shared_ptr<const animation::WeaponProgramBank> weapon_programs;
    ControlRequest control_request;
    std::uint8_t control_pending{};
    input::Frame input;
};
struct Session : actors::HitSession {
    gameplay_session::Random random{};
    gameplay_session::Options options;
    std::uint8_t previous_primary{},previous_secondary{};
    std::uint8_t inventory_owner{}; // source4BADEE: zero inactive,1..4 primary owner tags
    std::array<std::array<std::uint8_t,8>,4> auxiliary_resources{}; // first four session recovery lists4BAC52; independent of entity lifetime
    std::uint8_t control_notice{};
    std::optional<std::uint16_t> scenario;
    std::optional<std::uint16_t> last_scenario_audio; // original316550, written even when a bank request is rejected
    std::uint8_t resource_hide_selected{},resource_hide_others{}; // original4B9D10/11
    std::uint8_t sound_loading_mode{}; // original324405; only mode2 rejects queued direct bank loads
    std::uint8_t gameplay_flags{}; // original4BAE96; use override bit0, contact-mode bit1
    std::int8_t message_phase{}; // original3243FB;1/2 enable the1B0310 message branch, independent of mode
    std::uint16_t actor_message_suppression{}; // original744638; shared selector suppression, not per actor
    // Authored primary population count, source4BAEA0. Unknown is not zero;
    // storage/registration and the active byte remain independent concepts.
    std::optional<std::uint32_t> primary_population;
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
class LinkedModelPool;
class AuxiliaryActorPool;
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
    std::shared_ptr<Actor> primary(std::size_t)const noexcept;
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
    friend class AuxiliaryActorPool;
    actors::EntityStore entities_;
    std::array<actors::EntityId,8> primary_;
    std::unique_ptr<LinkedModelPool> linked_models_;
    std::unique_ptr<AuxiliaryActorPool> auxiliary_actors_;
    std::vector<input::Remap> layouts_;
    std::vector<input::ControllerFrame> controllers_;
    bool updating_{},closed_{};
    std::optional<std::size_t> executing_;
};
} // namespace reo::native::gameplay_world
