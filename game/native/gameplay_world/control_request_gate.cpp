#include "control_request_gate.hpp"

namespace reo::native::gameplay_world {
ControlRequestResult dispatch_control_request(World& world,Actor& actor,
    ControlRequestDispatcher& dispatcher){
    if(world.closed())return{};
    const auto id=world.identity_of(actor);
    const auto actor_lease=id?world.resolve(id):nullptr;
    if(!id||!actor_lease||actor_lease.get()!=&actor)
        return{ControlRequestStatus::invalid_actor,false};

    //64F600 tests category first. Only category zero reaches F78 bit20;
    //other actor categories continue through the1B0340 false path intoF2D0.
    if(actor.category==0&&!(actor.input.held&0x20u))
        return{ControlRequestStatus::completed,false};

    //64F624 calls1B0340 for every actor. A local primary with the source's
    //held bit8000 is suppressed only while global inventory owner4BADEE is0.
    if(world.locally_controlled(actor)&&(actor.input.held&0x8000u)&&
       world.session().inventory_owner==0)
        return{ControlRequestStatus::completed,false};

    const auto result=dispatcher.dispatch(world,actor);
    if(!result)return{};
    return{ControlRequestStatus::completed,*result};
}
}
