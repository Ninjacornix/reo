#pragma once
#include "geometry.hpp"
#include "../gameplay_scenario/periodic_effects.hpp"
#include <list>
#include <mutex>
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
    std::vector<PieceOutput> pieces;
};
struct EffectFrame {std::uint64_t revision{};std::vector<VisualOutput> visuals;};
enum class VisualStatus {completed,closed,busy,invalid_camera,invalid_profile,no_memory};
struct VisualReport {VisualStatus status{VisualStatus::completed};std::size_t visited{},retired{},pieces{};};
// Canonical native visual/resource owner for the admitted periodic family.
// Simulation calls are serialized; only immutable frame acquisition is shared
// with rendering. A retained frame/visual cannot retarget a recycled native ID.
class PeriodicVisuals final:public gameplay_scenario::PeriodicEmitter {
public:
    explicit PeriodicVisuals(std::shared_ptr<const EffectBank>);
    ~PeriodicVisuals();
    PeriodicVisuals(const PeriodicVisuals&)=delete;
    PeriodicVisuals& operator=(const PeriodicVisuals&)=delete;
    bool admitted()const noexcept override;
    gameplay_scenario::EmissionResult emit(const gameplay_scenario::PeriodicEmission&)noexcept override;
    VisualReport update(transform_math::Vector camera)noexcept;
    bool retire(const gameplay_actors::EntityId&)noexcept;
    void close()noexcept;
    std::shared_ptr<const EffectFrame> retain()const noexcept;
    std::size_t size()const noexcept{return entities_.size();}
    std::size_t piece_count()const noexcept{return piece_count_;}
    VisualStatus failure()const noexcept{return failure_;}
private:
    struct Node;
    struct Piece {bool active{};PieceOutput output;};
    gameplay_actors::EntityStore entities_{{168}};
    std::list<gameplay_actors::EntityId> order_;
    std::array<Piece,256> pieces_;
    std::shared_ptr<const EffectBank> bank_;
    mutable std::mutex publication_;
    std::shared_ptr<const EffectFrame> published_;
    std::size_t piece_count_{};
    std::uint64_t revision_{};
    bool closed_{},busy_{};
    VisualStatus failure_{VisualStatus::completed};
    bool retire_node(gameplay_actors::EntityId)noexcept;
    void publish(std::shared_ptr<const EffectFrame>)noexcept;
};
// Complete652CE0/370420/370FE0 finite SDK-profile position policy. No host
// clock or PS2 vector/register state is used by the production implementation.
transform_math::Vector toward_camera(transform_math::Vector position,transform_math::Vector camera,float distance);
}
