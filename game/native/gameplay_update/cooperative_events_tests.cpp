#include "update.hpp"
#include <iostream>
#include <stdexcept>
namespace u=reo::native::gameplay_update;
namespace e=reo::native::gameplay_events;
namespace s=reo::native::gameplay_scenario;
void check(bool value){if(!value)throw std::runtime_error("Cooperative update-owner binding check");}
// No flag operations are exercised; these callbacks fail if unexpectedly used.
struct Notifications:s::FlagNotifications {
    void changed(const s::ScenarioFlagChange&)noexcept override{std::terminate();}
    void changed(const s::StridedFlagChange&)noexcept override{std::terminate();}
};
int main()try{
    u::world::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<u::world::Session>());Notifications notifications;u::Owner owner(world,notifications);check(owner.open());
    world.room=0x1234;check(owner.clock().restore({0,0,0,0},UINT32_MAX)==u::tasks::Status::completed);
    const auto first=owner.record_event(0xabcd0013,0x12345678,0xabcdef90);check(first.status==e::Status::completed);
    const auto value=owner.cooperative_events().get(first.id);check(value&&value->id==0x13&&value->timestamp==0xa4c478&&value->room==0x1234&&value->first==0x5678&&value->second==0xef90);
    check(owner.clock().commit_update(u::tasks::ClockStep::two)==u::tasks::Status::completed);world.room=7;
    const auto next=owner.record_event(0x14,1,2);const auto after=owner.cooperative_events().get(next.id);check(after&&after->timestamp==0&&after->room==7);
    const auto generic=owner.record_simple_event(0xabcdffff);const auto simple=owner.cooperative_events().get(generic.id);check(simple&&simple->id==65535&&simple->type==1&&simple->priority==9&&simple->room==0);
    check(owner.record_event(0xffff,0,0).status==e::Status::unavailable);const auto snapshot=owner.cooperative_events().snapshot();check(snapshot.size()==3);
    check(owner.close()==u::Status::completed&&!owner.open()&&!owner.cooperative_events().get(first.id));check(owner.record_event(1,0,0).status==e::Status::closed&&owner.record_simple_event(1).status==e::Status::closed&&snapshot.size()==3);
    check(world.close()==u::world::Status::completed);std::cout<<"Cooperative events use the actual update clock/room and joined closure.\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
