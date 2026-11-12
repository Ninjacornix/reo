#include "inherited_trail.hpp"
#include <bit>
#include <stdexcept>
namespace reo::native::gameplay_effects {
namespace {
std::int16_t add(std::int16_t a,int b){return std::bit_cast<std::int16_t>(std::uint16_t(std::uint32_t(std::uint16_t(a))+std::uint32_t(b)));}
InheritedTrailStep move(InheritedTrailState& s,const InheritedTrailMotion& motion,InheritedTrailOperations& op){
    auto basis=transform_math::identity();
    if(motion.kind!=0x12)transform_math::reset_euler_axes(basis,{std::uint16_t(s.angles[0]),std::uint16_t(s.angles[1]),std::uint16_t(s.angles[2])});
    const auto velocity=transform_math::direction(basis,s.velocity);
    s.position={s.position.x+velocity.x,s.position.y+velocity.y,s.position.z+velocity.z};
    s.velocity.y=s.velocity.y+s.acceleration.y;s.velocity.z=s.velocity.z+s.acceleration.z;s.previous_position=s.position;
    const auto floor=op.floor(s.position);if(!floor)return{false};
    float height=*floor;
    if(s.parent_type==0x13){
        // The first latch still tests the sampled floor. Only a previously
        // latched work reloads target.Y at578BEC on a subsequent invocation.
        if(s.latched)height=s.target.y;
        else if(motion.primary==3){s.latched=1;s.motion_variant=motion.variant;s.target=motion.position;}
    }
    if(s.position.y<=height){
        s.phase=3;s.position.y=height;s.visible=false;
        if(s.parent_type==0x1d){
            if(s.ordinal==0){WorkRequest q;q.position=s.position;q.effect=0x7c;q.variant=1;const auto made=op.impact(q);if(made.status==WorkStatus::unavailable)return{false};if(!op.contact_burst(s.position))return{false};}
        }else if(s.parent_type==0xa||s.parent_type==7){
            if(s.ordinal==0){
                WorkRequest q;q.position=s.position;q.effect=0x87;q.update=WorkUpdate::scaled;const auto made=op.impact(q);
                if(made.status==WorkStatus::unavailable)return{false};
                if(made.status==WorkStatus::completed){
                    if(!made.edit)return{false};
                    const bool seven=s.parent_type==7;
                    const auto tint=seven?transform_math::Vector{std::bit_cast<float>(0x3f19999au),std::bit_cast<float>(0x3f19999au),std::bit_cast<float>(0x3ee66666u)}:transform_math::Vector{std::bit_cast<float>(0x3f733333u),1,std::bit_cast<float>(0x3f333333u)};
                    // The source writes the old trail's A8/23E, while scale
                    // belongs to the newly constructed impact work.
                    s.feedback_scale=seven?std::bit_cast<float>(0x3f4ccccdu):1.f;
                    if(!op.configure_impact(made,tint,s.scale))return{false};
                    s.attributes=0x104;
                }
            }
        }else if(s.parent_type==0x13&&s.motion_variant!=1){if(!op.contact_cue(s.position))return{false};}
        return{};
    }
    if(s.remaining>=0){
        if(!op.sample(s))return{false};
        s.remaining=add(s.remaining,-2);s.age=add(s.age,2);
    }
    return{};
}
}
InheritedTrailStep advance_inherited_trail(InheritedTrailState& s,const InheritedTrailMotion& motion,InheritedTrailOperations& operations,gameplay_session::Random& random){
    if(s.phase>3)return{false};
    if(s.phase==3)return{true,true};
    if(s.phase==0){
        s.phase=1;s.latched=0;s.motion_variant=0;s.visible=false;
        const float decay=std::bit_cast<float>(0x3e4ccccdu)*float(s.ordinal);
        const float factor=1.f-decay;s.feedback_scale=s.feedback_scale*factor;
        s.rotation_offset=std::bit_cast<std::int16_t>(random.request(1));
    }
    if(s.phase==1){s.delay=add(s.delay,-1);if(s.delay>=0)return{};s.phase=2;s.visible=true;}
    return move(s,motion,operations);
}
}
