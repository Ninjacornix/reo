#include "interaction_registration.hpp"

namespace reo::native::gameplay_world {
InteractionRegistrationStatus register_interaction(World& world,Actor& actor,
    std::uint8_t control_selector,InteractionRegistrationPublication& publication) {
    return register_interaction(world,actor,3,control_selector,publication);
}
InteractionRegistrationStatus register_interaction(World& world,Actor& actor,
    std::uint8_t selector,std::uint8_t control_selector,InteractionRegistrationPublication& publication) {
    if(world.closed())return InteractionRegistrationStatus::unavailable;
    const auto id=world.identity_of(actor);
    if(!id||world.resolve(id).get()!=&actor||!actor.interaction_registration)
        return InteractionRegistrationStatus::unavailable;

    auto& registration=*actor.interaction_registration;
    // 67FFA0..67FFAC zero the full original B34 word on every invocation.
    registration.selection_word=0;

    // 67FFB0 calls1B0310: only the actual message phase values1/2 admit the
    // selected-actor message branch. The offline fallback writes literal1
    // (a1 assigned at67FFB8), not a2/control_selector, for selectors1/3/5.
    const auto phase=world.session().message_phase;
    if(phase!=1&&phase!=2){
        if(selector==1||selector==3||selector==5)registration.selection_word=1;
        return InteractionRegistrationStatus::completed;
    }
    if(actor.category!=0||actor.slot!=world.selected_actor||!control_selector)
        return InteractionRegistrationStatus::completed;

    if(selector<1||selector>6)return InteractionRegistrationStatus::unavailable;
    //740790 maps odd selectors to the incrementing entries. Even selectors
    //reuse DA6 and do not write DA7. Only selectors3/5 initialize payload yaw.
    if(selector&1u){
        registration.sequence=std::uint8_t(registration.sequence+1u);
        registration.previous_sequence=registration.sequence;
    }
    if(world.mode!=0&&world.mode!=1)return InteractionRegistrationStatus::completed;
    const auto yaw=actor.orientation[1];
    InteractionRegistrationMessage message;
    message.selector=selector;
    message.control_selector=control_selector;
    message.room=std::uint8_t(actor.room);
    message.sequence=registration.sequence;
    if(selector==3||selector==5)message.yaw_high=std::uint8_t((std::int32_t(yaw)>>8)&0xff);
    return publication.publish(world,actor,message)?InteractionRegistrationStatus::completed:
        InteractionRegistrationStatus::unavailable;
}
} // namespace reo::native::gameplay_world
