#pragma once
#include "geometry.hpp"
#include "work.hpp"
#include "particle_work.hpp"
#include "surface_work.hpp"
#include "resource_companion.hpp"
#include "resource_debris.hpp"
#include "resource_flight.hpp"
#include "actor_contact_channels.hpp"
namespace reo::native::gameplay_world {class ResourceFactory;}
#include "../gameplay_scenario/surface_effects.hpp"
#include "../gameplay_scenario/periodic_effects.hpp"
#include "../gameplay_scenario/fog.hpp"
#include <list>
#include <mutex>
namespace reo::native::gameplay_contact_world {class RoomResources;}
namespace reo::native::gameplay_effects {
struct PieceBinding {std::size_t root{},mesh{};std::uint8_t material{},selector{};};
struct VisualBinding {std::size_t group{};std::vector<PieceBinding> pieces;};
struct PiecePose {
    transform_math::Vector scale{1,1,1},translation;
    std::array<std::int16_t,3> rotation{};
};
class EffectBank {
public:
    static std::shared_ptr<const EffectBank> import(std::span<const std::byte> nbd,std::span<const std::byte> efdata);
    const Geometry& geometry()const noexcept{return *geometry_;}
    const Tracks& tracks()const noexcept{return *tracks_;}
    const MaterialTracks& materials()const noexcept{return *materials_;}
    const VisualBinding* periodic(std::uint16_t descriptor)const noexcept;
    VisualBinding bind(std::uint16_t descriptor,std::int16_t variant)const;
    std::shared_ptr<const Geometry> geometry_owner()const noexcept{return geometry_;}
private:
    EffectBank()=default;
    std::shared_ptr<const Geometry> geometry_;
    std::shared_ptr<const Tracks> tracks_;
    std::shared_ptr<const MaterialTracks> materials_;
    std::array<VisualBinding,3> periodic_;
};
struct PieceOutput {
    std::size_t root{},mesh{};
    std::uint8_t material{};
    bool visible{};
    PiecePose parameters;
    std::array<float,8> material_values{};
    transform_math::Vector parameters208{1,1,1};
    std::uint32_t flags{};
};
struct VisualOutput {
    gameplay_actors::EntityId id;
    std::shared_ptr<const EffectBank> bank;
    bool visible{};
    std::optional<std::uint8_t> category;
    std::vector<PieceOutput> pieces;
    std::optional<ResourceDebrisState> debris;
    std::optional<ResourceFlightState> flight;
    std::optional<ActorContactState> actor_contact;
};
struct EffectFrame {std::uint64_t revision{};std::vector<VisualOutput> visuals;};
enum class VisualStatus {completed,closed,busy,invalid_camera,invalid_profile,no_memory};
struct VisualReport {VisualStatus status{VisualStatus::completed};std::size_t visited{},retired{},pieces{};};
// Canonical native visual/resource owner for the admitted periodic family.
// Simulation calls are serialized; only immutable frame acquisition is shared
// with rendering. A retained frame/visual cannot retarget a recycled native ID.
class PeriodicVisuals final:public gameplay_scenario::PeriodicEmitter,public WorkBackend,public SurfaceVisuals,public gameplay_scenario::SurfaceEffects,public ActorContactBackend {
public:
    explicit PeriodicVisuals(std::shared_ptr<const EffectBank>);
    PeriodicVisuals(std::shared_ptr<const EffectBank>,gameplay_session::Random&);
    PeriodicVisuals(std::shared_ptr<const EffectBank>,gameplay_session::Random&,gameplay_scenario::Fog&);
    ~PeriodicVisuals();
    PeriodicVisuals(const PeriodicVisuals&)=delete;
    PeriodicVisuals& operator=(const PeriodicVisuals&)=delete;
    bool admitted()const noexcept override;
    bool bound_to(const gameplay_session::Random&)const noexcept override;
    bool bound_to(const gameplay_world::World&)const noexcept override;
    // Borrowed room/modulation owners outlive this visual owner and callbacks.
    // The World lease owns canonical actors/session; this creates no shadows.
    bool bind_surfaces(std::shared_ptr<gameplay_world::World>,gameplay_contact_world::RoomResources&,Modulation&,SurfaceProfile)noexcept;
    bool configure_surface(std::uint32_t,const std::array<std::uint32_t,4>&)noexcept override;
    struct SurfaceCreated {WorkStatus status{WorkStatus::unavailable};std::size_t attempted{},created{};std::array<gameplay_actors::EntityId,8> identities;};
    SurfaceCreated create_surface_work()noexcept;
    std::optional<SurfaceState> surface_state(const gameplay_actors::EntityId&)const noexcept;
    bool bind_resource_companions(gameplay_world::World&,gameplay_scenario::SceneResources&,gameplay_world::ResourceModels&,const gameplay_scenario::ResourceTemplates&,ResourceCompanionActions&)noexcept;
    bool companions_bound_to(const gameplay_world::World&,const gameplay_scenario::SceneResources&,const gameplay_world::ResourceModels&,const gameplay_scenario::ResourceTemplates&)const noexcept;
    struct CompanionsCreated {WorkStatus status{WorkStatus::unavailable};std::size_t attempted{},created{};std::array<gameplay_actors::EntityId,2> identities;};
    CompanionsCreated create_resource_companions(const gameplay_actors::EntityId& model,std::int8_t argument)noexcept;
    std::optional<ResourceCompanionState> resource_companion_state(const gameplay_actors::EntityId&)const noexcept;
    // Reuse the actual resource factory's current room floor lease. There is
    // no positive placeholder room/collision provider behind this binding.
    bool bind_resource_debris(gameplay_world::World&,gameplay_world::ResourceModels&,gameplay_world::ResourceFactory&)noexcept;
    bool debris_bound_to(const gameplay_world::World&,const gameplay_world::ResourceModels&,const gameplay_world::ResourceFactory&)const noexcept;
    struct DebrisPiece {WorkStatus status{WorkStatus::unavailable};gameplay_actors::EntityId id;};
    DebrisPiece create_resource_debris_piece(const gameplay_actors::EntityId&,std::uint32_t part,std::uint32_t effect)noexcept;
    CompanionsCreated create_resource_debris(const gameplay_actors::EntityId&)noexcept;
    std::optional<ResourceDebrisState> resource_debris_state(const gameplay_actors::EntityId&)const noexcept;
    bool bind_resource_flights(gameplay_world::World&,gameplay_contact_world::RoomResources&,FlightAudio&)noexcept;
    bool flights_bound_to(const gameplay_world::World&)const noexcept;
    DebrisPiece create_resource_flight(const gameplay_actors::EntityId&,const transform_math::Matrix&,std::uint32_t style)noexcept;
    std::optional<ResourceFlightState> resource_flight_state(const gameplay_actors::EntityId&)const noexcept;
    bool bind_actor_contacts(gameplay_world::World&,ActorContactPoses&)noexcept;
    bool channels_bound_to(const gameplay_world::World&)const noexcept override;
    WorkStatus actor_channel(const gameplay_actors::EntityId&,const std::optional<transform_math::Matrix>&,transform_math::Vector,std::uint32_t,std::uint32_t)override;
    DebrisPiece create_actor_contact(const gameplay_actors::EntityId&,const std::optional<transform_math::Matrix>&,transform_math::Vector,std::uint32_t,std::uint32_t)noexcept;
    std::optional<ActorContactState> actor_contact_state(const gameplay_actors::EntityId&)const noexcept;
    gameplay_scenario::EmissionResult emit(const gameplay_scenario::PeriodicEmission&)noexcept override;
    WorkCreated create(const WorkRequest&)noexcept override;
    std::optional<ParticleSnapshot> particle_state(const gameplay_actors::EntityId&)const noexcept;
    WorkStatus emit_surface(const SurfaceEmission&)noexcept override;
    WorkStatus refresh_companion()noexcept override;
    VisualReport update(transform_math::Vector camera)noexcept;
    VisualReport update_with_view(transform_math::Vector camera,const transform_math::Matrix&)noexcept;
    bool retire(const gameplay_actors::EntityId&)noexcept;
    void close()noexcept;
    std::shared_ptr<const EffectFrame> retain()const noexcept;
    std::size_t size()const noexcept{return entities_.size();}
    std::size_t piece_count()const noexcept{return piece_count_;}
    VisualStatus failure()const noexcept{return failure_;}
private:
    struct Node;
    struct Editing;
    class Edit;
    struct SurfaceRuntime;
    struct CompanionRuntime;
    struct DebrisRuntime;
    struct FlightRuntime;
    struct ChannelRuntime;
    class ChannelOperations;
    class SurfaceSink;
    struct Piece {bool active{};PieceOutput output;};
    gameplay_actors::EntityStore entities_{{168}};
    std::list<gameplay_actors::EntityId> order_;
    std::array<Piece,256> pieces_;
    std::shared_ptr<const EffectBank> bank_;
    gameplay_session::Random* random_{};
    gameplay_scenario::Fog* fog_{};
    std::unique_ptr<SurfaceRuntime> surfaces_;
    std::unique_ptr<CompanionRuntime> companions_;
    std::unique_ptr<DebrisRuntime> debris_;
    std::unique_ptr<FlightRuntime> flights_;
    std::unique_ptr<ChannelRuntime> channels_;
    std::shared_ptr<Editing> editing_;
    mutable std::mutex publication_;
    std::shared_ptr<const EffectFrame> published_;
    std::size_t piece_count_{};
    std::uint64_t revision_{};
    bool closed_{},busy_{};
    VisualStatus failure_{VisualStatus::completed};
    bool retire_node(gameplay_actors::EntityId)noexcept;
    void publish(std::shared_ptr<const EffectFrame>)noexcept;
    VisualReport update_impl(transform_math::Vector,const std::optional<transform_math::Matrix>&)noexcept;
    WorkCreated create_impl(const WorkRequest&,bool internal)noexcept;
    DebrisPiece create_actor_contact_impl(const gameplay_actors::EntityId&,const std::optional<transform_math::Matrix>&,transform_math::Vector,std::uint32_t,std::uint32_t,bool internal)noexcept;
    WorkStatus emit_surface_impl(const SurfaceEmission&,bool internal)noexcept;
    void sample_children(Node&,std::int16_t,transform_math::Vector,const std::optional<transform_math::Matrix>&,VisualReport&);
};
// Complete652CE0/370420/370FE0 finite SDK-profile position policy. No host
// clock or PS2 vector/register state is used by the production implementation.
transform_math::Vector toward_camera(transform_math::Vector position,transform_math::Vector camera,float distance);
}
