#include "update.hpp"
#include <iostream>
#include <source_location>
#include <stdexcept>
namespace u=reo::native::gameplay_update;
namespace n=reo::native::gameplay_navigation;
namespace {
unsigned checks{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Navigation Owner composition at "+std::to_string(at.line()));
}
struct Notifications:u::scenario::FlagNotifications {
    bool changed(const u::scenario::ScenarioFlagChange&)noexcept override{std::terminate();}
    bool changed(const u::scenario::StridedFlagChange&)noexcept override{std::terminate();}
};
std::shared_ptr<const n::Asset> asset(){
    std::vector<std::uint8_t> bytes(236);
    const auto put=[&](unsigned at,unsigned value){for(unsigned i=0;i<4;++i)bytes[at+i]=std::uint8_t(value>>(i*8));};
    put(0,0x20030724);put(4,12);put(8,36);put(12,1);bytes[16]=7;
    put(36,1);put(40,7);put(44,52);put(52,80);put(56,120);put(60,1);bytes[64]=1;
    put(136,2);bytes[140]=1;bytes[141]=0;bytes[142]=3;
    bytes[156]=1;bytes[157]=1;bytes[162]=4;
    n::ImportFailure failure;auto parsed=n::Asset::read(bytes,failure);check(bool(parsed));
    return std::make_shared<const n::Asset>(std::move(*parsed));
}
}
int main(){
    try{
        u::world::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<u::world::Session>());
        Notifications notifications;u::Owner owner(world,notifications);const auto id=world.spawn_primary(0,std::make_unique<u::world::Actor>()).id;check(bool(id));
        check(owner.admit_navigation_condition(id,7,0).status==n::QueryStatus::unavailable);
        check(world.session().room_variants.store(7,0)&&world.navigation().bind(asset()));
        auto actor=world.resolve(id);actor->character=7;actor->slot=5;actor->ai_control=0;
        check(owner.applicable_navigation_condition(id,7,0).index==0&&owner.admit_navigation_condition(id,7,0).allowed);
        check(owner.flags().strided(7,3,4,true,false)&&owner.admit_navigation_condition(id,7,0).allowed);
        check(owner.flags().strided(7,3,0,true,false)&&!owner.admit_navigation_condition(id,7,0).allowed);
        check(!owner.admit_navigation_edge(id,7,0,-1).allowed&&owner.admit_navigation_edge(id,8,123,123).allowed);
        auto link=owner.admitted_navigation_link(id,7,0,0);check(link.status==n::QueryStatus::completed&&!link.index);
        check(owner.flags().strided(7,3,0,false,false));link=owner.admitted_navigation_link(id,7,0,0);check(link.status==n::QueryStatus::completed&&link.index==0);
        check(owner.admit_navigation_edge(id,7,0,-1).allowed&&owner.admit_navigation_edge(id,7,1,0).status==n::QueryStatus::unavailable);
        check(owner.applicable_navigation_condition(id,7,1).index==-1&&!owner.admit_navigation_condition(id,7,1).allowed);
        actor->ai_control=255;check(owner.applicable_navigation_condition(id,7,1).index==1&&owner.admit_navigation_condition(id,7,1).allowed);
        actor->active=false;actor->status=0xffffffff;check(owner.applicable_navigation_condition(id,7,1).index==1); // no invented active/status gate
        n::RouteOutput route_output;route_output.cost=1234;
        check(owner.ranked_navigation_route(id,7,0,0,n::RankedPolicy::four_candidates,route_output).selected==0&&route_output.first==0&&route_output.second==0&&route_output.cost==1234);
        check(owner.ranked_navigation_route(id,8,0,0,n::RankedPolicy::first_candidate,route_output).status==n::QueryStatus::unavailable);
        check(owner.bounded_navigation_route(id,7,0,0,route_output,0).selected==0&&route_output.cost==10000);
        check(owner.bounded_navigation_route(id,8,0,0,route_output).status==n::QueryStatus::unavailable);
        check(owner.admit_navigation_condition(id,7,2).status==n::QueryStatus::unavailable&&owner.admit_navigation_condition(id,8,0).status==n::QueryStatus::unavailable);
        check(owner.admitted_navigation_link(id,7,0,1).status==n::QueryStatus::completed&&!owner.admitted_navigation_link(id,7,0,1).index);
        u::world::World foreign({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<u::world::Session>());const auto other=foreign.spawn_primary(0,std::make_unique<u::world::Actor>()).id;
        check(owner.admit_navigation_condition(other,7,0).status==n::QueryStatus::unavailable&&owner.admitted_navigation_link(other,7,0,0).status==n::QueryStatus::unavailable);
        check(world.retire_primary(0)==u::world::actors::EntityStatus::completed&&owner.applicable_navigation_condition(id,7,1).status==n::QueryStatus::unavailable);
        check(world.close()==u::world::Status::completed&&owner.admit_navigation_condition(id,7,0).status==n::QueryStatus::unavailable&&owner.admitted_navigation_link(id,7,0,0).status==n::QueryStatus::unavailable);
        check(owner.close()==u::Status::completed);std::cout<<"{\"checks\":"<<checks<<"}\n";
    }catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
}
