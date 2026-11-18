#pragma once
#include "../gameplay_session/session.hpp"
#include "../transform_math/transform_math.hpp"
#include <optional>
#include "../gameplay_actors/entity.hpp"
namespace reo::native::gameplay_world {class World;}
namespace reo::native::gameplay_effects {
struct ResourceFlightState {
    std::uint8_t phase{},style{},sticky{};
    bool visible{};
    std::uint16_t effect{};
    std::int16_t lifetime{},cooldown{};
    transform_math::Matrix basis{transform_math::identity()};
    transform_math::Vector position,previous_position,displacement,velocity,acceleration;
    transform_math::Vector scale{1,1,1};
    std::array<float,4> color{1,1,1,1};
    std::array<std::uint16_t,3> angles{};
};
struct FlightHit {transform_math::Vector point;std::uint8_t type{};};
struct FlightTrace {bool available{};std::optional<FlightHit> hit;};
class FlightQueries {
public:
    virtual ~FlightQueries()=default;
    virtual FlightTrace wall(transform_math::Vector start,transform_math::Vector end)=0;
    virtual FlightTrace floor(transform_math::Vector start,transform_math::Vector end)=0;
};
class FlightAudio {
public:
    virtual ~FlightAudio()=default;
    virtual bool bound_to(const gameplay_world::World&)const noexcept=0;
    virtual bool cue(const gameplay_actors::EntityId&,transform_math::Vector)=0;
};
struct ResourceFlightStep {
    bool available{true},retire{};
    std::optional<transform_math::Vector> cue_position;
};
// Complete58E850 state/physics/query/RNG policy. Required sound publication is
// returned at its original position; the runtime must supply the real audio.
ResourceFlightStep advance_resource_flight(ResourceFlightState&,FlightQueries&,gameplay_session::Random&);
struct ResourceFlightProfile {std::uint16_t effect{};std::uint8_t style{};transform_math::Vector offset;};
// Full32-entry owned style map. FF is an authored no-effect result; indices
// outside that bounded profile refuse rather than reading adjacent data.
std::optional<ResourceFlightProfile> resource_flight_profile(std::uint32_t style);
std::optional<ResourceFlightState> prepare_resource_flight(const transform_math::Matrix&,std::uint32_t style);
}
