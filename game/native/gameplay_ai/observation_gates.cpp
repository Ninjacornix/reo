#include "observation_gates.hpp"
#include "../gameplay_world/world.hpp"
#include "../gameplay_session/session.hpp"
#include <bit>
namespace reo::native::gameplay_ai {
namespace {
#include "observation_policies.inc"
}
bool observation_blocked(const gameplay_world::Actor& actor)noexcept{
    const auto motion=actor.motion_class;
    const bool eligible=motion<=5||(motion>=0x21&&motion<=0x24)||(motion>=0x2d&&motion<=0x2f)||motion==0x3b;
    return !eligible||(actor.auxiliary_status&0x04030000u)||(actor.status&0x200u);
}
ObservationAdmitted admit_reference_reaction(gameplay_world::Actor& actor,const gameplay_world::Actor* reference,std::uint32_t mode,gameplay_session::Random& random)noexcept{
    if(!actor.ai_execution)return {};
    auto& state=*actor.ai_execution;
    if(mode&&(actor.room==state.room_memo||state.room_reaction_gate))return {Status::completed,false,0};
    if(actor.character>=reference_chances.size())return {};
    float chance;
    if(!mode){
        if(!reference||!reference->ai_execution)return {};
        chance=float(reference_chances[actor.character]);
        if(reference->ai_execution->weight_mode)chance*=reference_weight_factor;
        if(state.weight_mode)chance*=self_weight_factor;
    }else chance=float(room_chances[actor.character]);
    const auto threshold=int(chance); // finite positive authored range <=117
    if(threshold>=100)return {Status::completed,true,0};
    bool admitted=false;std::uint8_t draws=0;
    if(chance>0){const auto word=random.request(1);draws=1;admitted=word!=0&&word%100<=threshold;}
    if(mode&&!admitted)state.room_memo=actor.room;
    return {Status::completed,admitted,draws};
}
}
