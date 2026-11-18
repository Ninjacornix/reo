#pragma once
#include "work.hpp"
#include "../gameplay_world/world.hpp"
#include "../gameplay_collision/response.hpp"
#include "../animation/model.hpp"
namespace reo::native::gameplay_effects {
// One native owner of the shared room effect flags and color/intensity values.
// Initialization is explicit: construction alone does not invent room defaults.
struct ModulationState {
    std::uint16_t flags{};
    transform_math::Vector color;
    float intensity{};
};
class Modulation final {
public:
    explicit Modulation(ModulationState);
    const ModulationState& state()const noexcept{return state_;}
    // The corresponding part of the room reset. Other room owners reset their
    // own state; this does not claim to implement the complete room reset.
    void reset()noexcept{state_={};}
    bool configure(std::uint32_t selector,const std::array<std::uint32_t,4>&)noexcept;
private:
    ModulationState state_;
};
struct SurfaceJoint {std::uint32_t joint{};float lower{},upper{};transform_math::Vector scale;};
class SurfaceProfile final {
public:
    static SurfaceProfile import(std::span<const std::byte> records,std::uint8_t first_mask,std::uint8_t second_mask);
    std::span<const SurfaceJoint,11> joints()const noexcept{return joints_;}
    std::uint8_t first_mask()const noexcept{return first_mask_;}
    std::uint8_t second_mask()const noexcept{return second_mask_;}
private:
    std::array<SurfaceJoint,11> joints_{};
    std::uint8_t first_mask_{},second_mask_{};
};
struct SurfaceState {
    std::uint8_t phase{};
    std::array<transform_math::Vector,11> previous{};
    std::array<std::int8_t,11> first{},second{};
};
struct SurfaceEmission {
    WorkRequest work;
    transform_math::Vector scale;
    std::optional<std::int16_t> second_angle;
    std::uint16_t attributes{};
    transform_math::Vector color;
    float intensity{};
};
class SurfaceVisuals {
public:
    virtual ~SurfaceVisuals()=default;
    virtual bool bound_to(const gameplay_session::Random&)const noexcept=0;
    // Must allocate in the actual shared work pool, apply all edits and invoke
    // its real scaled visual consumer. Natural misses remain distinct.
    virtual WorkStatus emit_surface(const SurfaceEmission&)noexcept=0;
};
enum class SurfaceStatus {completed,unavailable};
enum class SurfaceGate {sample,skip,retire};
SurfaceGate prepare_surface(SurfaceState&,const Modulation&,const gameplay_world::Actor&,std::uint16_t current_room)noexcept;
struct SurfaceStep {SurfaceStatus status{SurfaceStatus::completed};bool retire{};std::size_t attempted{},created{};};
// Complete finite surface-joint policy, reading the canonical actor/model and
// actual immutable room floor grid. Earlier effects remain on a later refusal.
SurfaceStep advance_surface(SurfaceState&,const SurfaceProfile&,const Modulation&,
    const gameplay_world::Actor&,std::uint16_t current_room,
    const gameplay_collision::response::Grid&,gameplay_session::Random&,SurfaceVisuals&)noexcept;
}
