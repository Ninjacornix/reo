#include "resource_flight.hpp"
#include "../animation/constraint_math.hpp"
#include "../transform_math/heading.hpp"
#include <bit>
#include <cmath>
#include <stdexcept>
namespace reo::native::gameplay_effects {
namespace {
constexpr float f(std::uint32_t value){return std::bit_cast<float>(value);}
float finite(float value){if(!std::isfinite(value))throw std::domain_error("Native resource flight finite arithmetic required");return value;}
std::int16_t decrement(std::int16_t value){return std::bit_cast<std::int16_t>(std::uint16_t(std::uint16_t(value)-1u));}
using animation::constraint_math::add;
using animation::constraint_math::subtract;
#include "resource_flight_profile.inc"
}
std::optional<ResourceFlightProfile> resource_flight_profile(std::uint32_t style){
    if(style>=flight_styles.size())throw std::out_of_range("Native resource flight style profile unavailable");
    const auto mapped=flight_styles[style];if(mapped==255)return{};
    if(mapped>=flight_profiles.size())throw std::out_of_range("Native mapped resource flight profile unavailable");
    return flight_profiles[mapped];
}
std::optional<ResourceFlightState> prepare_resource_flight(const transform_math::Matrix& input,std::uint32_t style){
    const auto profile=resource_flight_profile(style);if(!profile)return{};
    const auto axis=transform_math::direction(input,{0,1,0});
    const auto angle=transform_math::quadrant_angle(axis.z,axis.x);
    float degrees=finite(finite(180.f*angle)/f(0x40490fdb));if(degrees<0)degrees=finite(degrees+360.f);
    const float turns=finite(f(0x43360b61)*degrees);
    if(!(turns>=0&&turns<65537.f))throw std::domain_error("Native flight matrix bearing conversion unavailable");
    const auto yaw=std::uint16_t(0x10000u-std::uint16_t(std::uint32_t(turns)));
    ResourceFlightState state;state.style=profile->style;state.effect=profile->effect;
    transform_math::reset_euler_axes(state.basis,{0,yaw,0});
    const auto origin=add({input[3][0],input[3][1],input[3][2]},transform_math::direction(input,profile->offset));
    state.basis[3][0]=origin.x;state.basis[3][1]=origin.y;state.basis[3][2]=origin.z;
    return state;
}
ResourceFlightStep advance_resource_flight(ResourceFlightState& state,FlightQueries& queries,gameplay_session::Random& random){
    if(state.phase==2)return{true,true,{}};
    if(state.phase!=0&&state.phase!=1)return{};
    if(state.phase==0){
        if(state.style>=flight_profiles.size())return{false,false,{}};
        state.phase=1;state.visible=true;state.lifetime=45;state.cooldown=0;state.sticky=0;
        state.position=flight_profiles[state.style].offset;state.previous_position={};state.displacement={};
        state.scale={1,1,1};state.color={1,1,1,1};state.angles={};
        state.velocity={2,3,0};state.acceleration={0,-.5f,0};
        if(state.effect==0x14)state.velocity.x=finite(state.velocity.x*3.f);
        if(state.effect==0x16)state.velocity.x=finite(state.velocity.x*2.f);
    }
    state.lifetime=decrement(state.lifetime);
    if(state.lifetime<0){++state.phase;return{};}
    if(state.cooldown){state.cooldown=decrement(state.cooldown);if(state.cooldown<0)state.cooldown=0;}
    state.displacement.x=finite(state.displacement.x+state.velocity.x);state.velocity.x=finite(state.velocity.x+state.acceleration.x);
    state.displacement.y=finite(state.displacement.y+state.velocity.y);state.velocity.y=finite(state.velocity.y+state.acceleration.y);
    state.previous_position=state.position;state.position=transform_math::direction(state.basis,state.displacement);
    state.angles[0]=std::uint16_t(state.angles[0]+0x2000u);
    const transform_math::Vector origin{state.basis[3][0],state.basis[3][1],state.basis[3][2]};
    bool hit{};std::optional<transform_math::Vector> hit_point;
    const auto wall=queries.wall(add(state.previous_position,origin),add(state.position,origin));
    if(!wall.available)return{false,false,{}};
    if(wall.hit){hit=true;hit_point=wall.hit->point;state.position=subtract(wall.hit->point,state.position);state.velocity.x=-state.velocity.x;}
    const auto endpoint=add(state.position,origin);
    //1900E0 reuses the first query's output storage for the base translation
    // before57D560. A floor miss therefore leaves the cue point at this origin.
    hit_point=origin;
    const auto floor=queries.floor(add(state.previous_position,origin),endpoint);
    if(!floor.available)return{false,false,{}};
    if(floor.hit){
        hit_point=floor.hit->point;
        if(floor.hit->type==0x81)state.sticky=1;
        else{
            state.position=add(state.position,subtract(endpoint,floor.hit->point));
            const auto turns=random.request(1);state.velocity.x=transform_math::sin_cos(f(0x38c90fdb)*float(turns)).sine;
            state.acceleration.x=0;state.velocity.y=3;state.acceleration.y=-.5f;hit=true;
        }
    }
    ResourceFlightStep result;
    if(hit&&state.cooldown==0){state.cooldown=4;if(!state.sticky)result.cue_position=hit_point;}
    return result;
}
}
