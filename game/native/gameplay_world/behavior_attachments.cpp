#include "behavior_attachments.hpp"
#include "../animation/model.hpp"
#include <bit>
#include <cmath>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
// Complete owned70B010/70B040 rows: (local Y, frame), with the -1 sentinel.
struct OffsetKey {float y,time;};
constexpr std::array<std::array<OffsetKey,5>,2> profiles{{
    {{{7,0},{6,5},{7,10},{7,150},{0,-1}}},
    {{{std::bit_cast<float>(0x40d33333u),0},{5.5f,5},
      {std::bit_cast<float>(0x40d33333u),10},{std::bit_cast<float>(0x40d33333u),150},{0,-1}}}
}};
float finite(float value){
    if(!std::isfinite(value))throw std::domain_error("Native model offset finite arithmetic required");
    return value;
}
std::int16_t frame_word(float value){
    //5D6BC4's CVT.W.S/unsigned fallback, followed by its low-halfword store.
    // Actual66B500 supplies1; other finite in-range steps retain that order.
    std::uint32_t word;
    if(value>=2147483648.f){
        const float shifted=finite(value-2147483648.f);
        if(double(shifted)>=2147483648.)throw std::domain_error("Native model offset frame overflow");
        word=std::uint32_t(std::int32_t(shifted))|0x80000000u;
    }else{
        if(double(value)<-2147483648.)throw std::domain_error("Native model offset frame underflow");
        word=std::uint32_t(std::int32_t(value));
    }
    return std::bit_cast<std::int16_t>(std::uint16_t(word));
}
animation::Instance& model(Actor& actor){
    if(!actor.model||actor.model->nodes().size()<=26)
        throw std::runtime_error("Native paired-node model unavailable");
    return *actor.model;
}
void first_y(animation::Instance& instance,float y){
    auto point=instance.local_translation(24);point.y=y;instance.local_translation(24,point);
}
void copy_y(animation::Instance& instance){
    auto point=instance.local_translation(26);point.y=instance.local_translation(24).y;
    instance.local_translation(26,point);
}
}
void update_behavior_attachment(World& world,Actor& actor,float step){
    if(actor.model_pose_class||world.paused)return;
    if(!actor.model_offset_lock)throw std::runtime_error("Native model offset lock unavailable");
    if(*actor.model_offset_lock||actor.current<=0)return;
    if(!actor.model_offset_frame||!actor.model_offset_phase||*actor.model_offset_phase>2)
        throw std::runtime_error("Native model offset timing unavailable");
    auto& instance=model(actor);const auto& keys=profiles[actor.motion_style?1:0];
    auto phase=*actor.model_offset_phase;
    const float elapsed=float(std::bit_cast<std::uint16_t>(*actor.model_offset_frame));
    // Keep the source's separate subtract/multiply/divide/add operations.
    const float difference=keys[phase+1].y-keys[phase].y;
    const float numerator=finite(finite(elapsed-keys[phase].time)*difference);
    const float interpolated=finite(numerator/(keys[phase+1].time-keys[phase].time));
    first_y(instance,finite(interpolated+keys[phase].y));copy_y(instance);
    const float increment=finite(step*(world.session().clock_mode?2.f:1.f));
    actor.model_offset_frame=frame_word(finite(elapsed+increment));
    const float next=float(std::bit_cast<std::uint16_t>(*actor.model_offset_frame));
    if(next<keys[phase+1].time)return;
    ++phase;actor.model_offset_phase=phase;
    if(keys[phase+1].time==-1.f){
        actor.model_offset_frame=frame_word(finite(next-keys[phase].time));
        actor.model_offset_phase=0;
    }
}
void update_terminal_attachment(Actor& actor,std::uint32_t selector){
    if(actor.model_pose_class)return;
    auto& instance=model(actor);const auto& keys=profiles[actor.character?1:0];
    const auto mode=std::uint8_t(selector);
    // F5 is model-part visibility1 in the actual F4 array. Ordinary models
    // retain this in PrimaryActorState; independently constructed scripted
    // actor families retain their own part array. Never create a shadow byte.
    const auto visible=[&](std::uint8_t value){
        auto* parts=actor.primary_state?&actor.primary_state->part_visibility:
            actor.scripted?&actor.scripted->part_visibility:nullptr;
        if(!parts||parts->size()<=1)throw std::runtime_error("Native paired-node part visibility unavailable");
        (*parts)[1]=value;
    };
    switch(mode){
    case 0:first_y(instance,keys[0].y);visible(0);break;
    case 1:{
        const float difference=keys[0].y-keys[1].y;
        first_y(instance,finite(keys[1].y+finite(difference/2.f)));
        visible(0);break;
    }
    case 2:first_y(instance,keys[1].y);visible(0);break;
    case 3:first_y(instance,keys[0].y);visible(1);break;
    default:break; // Source still copies node24's current Y into node26.
    }
    copy_y(instance);
}
}
