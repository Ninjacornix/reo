#include "update.hpp"
#include "../gameplay_scenario/scene_controls.hpp"
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
    put(36,1);put(40,7);put(44,52);put(52,80);put(56,120);put(60,1);bytes[64]=1;bytes[20]=7;
    put(136,2);bytes[140]=1;bytes[141]=0;bytes[142]=3;
    bytes[156]=1;bytes[157]=1;bytes[162]=4;
    n::ImportFailure failure;auto parsed=n::Asset::read(bytes,failure);check(bool(parsed));
    return std::make_shared<const n::Asset>(std::move(*parsed));
}
reo::native::gameplay_collision::response::Grid empty_walls(){
    std::vector<std::uint8_t> bytes(52);const auto put=[&](unsigned at,unsigned value){for(unsigned i=0;i<4;++i)bytes[at+i]=std::uint8_t(value>>(8*i));};
    put(8,1000);put(12,1000);put(16,1);put(20,1);put(32,32);put(36,44);put(40,36);put(44,0xffffffff);
    return reo::native::gameplay_collision::response::Grid::import(std::as_bytes(std::span(bytes)));
}
std::shared_ptr<const n::Asset> chain_asset(bool malformed_unused){
    constexpr unsigned count=8,node_base=44,tail=node_base+64*count+4*count*count,directory=tail+8;
    std::vector<std::uint8_t> bytes(directory+64);
    const auto put=[&](unsigned at,unsigned value){for(unsigned i=0;i<4;++i)bytes[at+i]=std::uint8_t(value>>(8*i));};
    put(0,0x20030724);put(4,12);put(8,16);put(16,1);bytes[20]=7;put(24,32);
    put(32,tail-32);put(36,directory-32);put(40,count);
    for(unsigned node=0;node<count;++node){
        const auto at=node_base+64*node;bytes[at]=1;put(at+16,0xffffffff);
        for(unsigned slot=0;slot<4;++slot){bytes[at+20+slot]=255;bytes[at+36+2*slot]=1;}
        if(node+1<count){bytes[at+1]=1;bytes[at+20]=std::uint8_t(node+1);}
    }
    for(unsigned at=node_base+64*count;at<tail;++at)bytes[at]=255;
    if(malformed_unused)bytes[node_base+64*7+20]=127;
    n::ImportFailure failure;auto parsed=n::Asset::read(bytes,failure);check(bool(parsed));
    return std::make_shared<const n::Asset>(std::move(*parsed));
}
void graph_owner_contracts(){
    u::world::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<u::world::Session>());
    Notifications notifications;u::Owner owner(world,notifications);
    const auto id=world.spawn_primary(0,std::make_unique<u::world::Actor>()).id;check(bool(id));
    check(world.session().room_variants.store(7,0)&&world.navigation().bind(chain_asset(false)));
    n::RouteOutput output{-22,-23,{1,2,3},{4,5,6},1234};
    const auto graph=owner.bounded_navigation_route(id,7,0,7,output,4096);
    check(graph.status==n::QueryStatus::completed&&graph.used_graph_solver&&graph.selected==1&&output.first==1&&output.second==2&&output.cost==7);
    check(graph.considered_edges<=4096&&graph.graph_vertex_scans<=2*8*8&&graph.graph_admission_checks==4*8);
    std::int16_t link=314;const auto local=owner.local_navigation_route(id,7,0,7,2,output,link,4096);
    check(local.status==n::QueryStatus::completed&&local.used_graph_solver&&local.considered_edges==graph.considered_edges&&local.graph_vertex_scans==graph.graph_vertex_scans&&link==-1&&output.cost==7);
    output={-22,-23,{1,2,3},{4,5,6},1234};const auto limited=owner.bounded_navigation_route(id,7,0,7,output,13);
    check(limited.status==n::QueryStatus::unavailable&&limited.budget_exhausted&&!limited.used_graph_solver&&limited.considered_edges==13&&output.first==-22&&output.second==-23&&output.cost==1234);
    check(world.navigation().bind(chain_asset(true)));const auto fallback=owner.bounded_navigation_route(id,7,0,7,output,4096);
    check(fallback.status==n::QueryStatus::completed&&!fallback.used_graph_solver&&fallback.graph_admission_checks>0&&fallback.considered_edges<=4096&&fallback.selected==1&&output.second==2&&output.cost==7);
    check(owner.close()==u::Status::completed&&world.close()==u::world::Status::completed);
}
void scene_owner_contracts(){
    u::world::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<u::world::Session>());
    Notifications notifications;u::Owner owner(world,notifications);
    const auto id=world.spawn_primary(0,std::make_unique<u::world::Actor>()).id;check(bool(id));
    auto actor=world.resolve(id);actor->collision.local_center.z=54;actor->collision.radius=999;
    auto records=std::make_shared<reo::native::gameplay_scene::Records>();u::scenario::SceneControls controls(records);
    const auto scene_id=controls.append({42,1,u::scenario::ControlTypeOne{},7});check(bool(scene_id));
    auto record=records->acquire(*scene_id);record->value.collision.emplace();auto& shape=*record->value.collision;
    shape.bounds={{{-10,90},{10,90},{10,110},{-10,110}}};shape.lower=-1;shape.upper=1;records->touch();
    auto result=owner.collect_actor_scene_candidates(id,*records);
    check(result.status==n::QueryStatus::completed&&result.count==1&&result.records[0]==*scene_id&&result.sampled_position.z==100);
    actor->collision.radius=0;check(owner.collect_actor_scene_candidates(id,*records).count==1);
    actor->collision.local_center.z=-46;check(owner.collect_actor_scene_candidates(id,*records).count==0);
    actor->collision.local_center.z=54;actor->motion_class=0x1a;check(owner.collect_actor_scene_candidates(id,*records).count==0);actor->motion_class=0;
    check(controls.apply(u::scenario::ControlCommand::disable_one,{42},nullptr).matched==1&&owner.collect_actor_scene_candidates(id,*records).count==0);
    check(controls.apply(u::scenario::ControlCommand::enable_one,{42},nullptr).matched==1&&owner.collect_actor_scene_candidates(id,*records).records[0]==*scene_id);
    actor->room=7;actor->character=7;actor->slot=5;actor->ai_control=0;
    check(world.session().room_variants.store(7,0)&&world.navigation().bind(asset()));
    actor->ai_control=1;record->value.condition_ordinal=2;records->touch();
    check(owner.find_scene_navigation_condition(id,1,*records).record==*scene_id&&owner.find_scene_navigation_condition(id,1,*records,&result).record==*scene_id);
    actor->ai_control=0;check(!owner.find_scene_navigation_condition(id,1,*records).record);
    record->value.condition_ordinal=0;record->value.enabled=0;shape.busy=true;records->touch();
    check(owner.find_scene_navigation_condition(id,1,*records).record==*scene_id);
    actor->room=8;check(owner.find_scene_navigation_condition(id,0,*records).status==n::QueryStatus::unavailable);actor->room=7;
    check(controls.erase(*scene_id)==u::scenario::ControlStatus::completed&&!records->acquire(result.records[0]));
    check(owner.find_scene_navigation_condition(id,0,*records,&result).status==n::QueryStatus::unavailable);
    check(owner.collect_actor_scene_candidates(id,*records).count==0);
    check(world.retire_primary(0)==u::world::actors::EntityStatus::completed&&owner.collect_actor_scene_candidates(id,*records).status==n::QueryStatus::unavailable);
    check(owner.close()==u::Status::completed&&world.close()==u::world::Status::completed);
}
}
int main(){
    try{
        graph_owner_contracts();
        scene_owner_contracts();
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
        route_output.cost=1234;std::int16_t route_link=314;
        check(owner.local_navigation_route(id,7,0,0,2,route_output,route_link,0).selected==0&&route_output.cost==1234&&route_link==0);
        check(world.session().room_variants.store(7,1));route_link=314;
        check(owner.local_navigation_route(id,7,0,0,0,route_output,route_link).selected==0&&route_link==-1&&world.navigation().room(7));
        check(world.session().room_variants.store(7,0));
        actor->slot=0;const auto unknown_collection=owner.collect_navigation_links(id,7,0);check(unknown_collection.status==n::QueryStatus::unavailable&&unknown_collection.failure==n::CollectionFailure::unknown_cost);
        const auto known_collection=owner.collect_navigation_links(id,7,0,{false,false,0.f,16});check(known_collection.status==n::QueryStatus::completed&&known_collection.count==1&&known_collection.candidates[0].link==0&&known_collection.candidates[0].cost==0);
        check(world.navigation().visit(0,0,1));check(owner.collect_navigation_links(id,7,0).count==0);check(world.navigation().visit(0,0,0));
        n::CrossRoomOutput cross_output{{-22,-23,{1,2,3},{4,5,6}},314};actor->status=0;
        const auto unknown_cross=owner.cross_room_navigation_route(id,7,7,0,0,cross_output);check(unknown_cross.collection_failure==n::CollectionFailure::unknown_cost&&cross_output.link==314);
        const auto corrected_cross=owner.cross_room_navigation_route(id,7,7,0,0,cross_output,{true,4096,128});check(corrected_cross.status==n::QueryStatus::completed&&corrected_cross.selected==0&&cross_output.link==0&&world.navigation().visits(0)[0]==1);
        actor->slot=5;actor->status=0x80;check(owner.cross_room_navigation_route(id,200,201,-1,-1,cross_output).selected==-1);actor->status=0;
        check(owner.refresh_actor_navigation(id,true).status==n::QueryStatus::unavailable);
        const auto walls=empty_walls();const n::VisibilityRoom visibility{walls,{},{}};
        check(owner.refresh_current_navigation_node(id,visibility).status==n::QueryStatus::unavailable);
        actor->room=7;actor->navigation_route.emplace();auto& navigation=*actor->navigation_route;
        navigation.destination_room=7;navigation.final_position={9,8,7};navigation.previous_action=654;
        check(owner.refresh_actor_navigation(id,true).selected==0&&navigation.output.route.first_position.x==9&&navigation.output.route.second_position.y==8&&navigation.last_current_node==0&&navigation.action==0&&navigation.previous_action==654);
        check((*world.navigation().occupancy(7,0)&32)!=0);
        actor->slot=0;check(owner.begin_actor_navigation(id,{12,13,14},7).selected==0&&navigation.final_position.y==13&&navigation.output.route.second_position.z==14&&navigation.output.route.first==navigation.destination_node&&navigation.output.route.second==navigation.destination_node);
        navigation.current_node=-42;check(owner.refresh_current_navigation_node(id,visibility).node==0&&navigation.current_node==0);
        navigation.selection_mode=1;actor->position.x=-10;check(owner.refresh_current_navigation_node(id,visibility).node==0&&navigation.current_node==0);actor->position.x=0;navigation.selection_mode=0;
        check(owner.admit_navigation_condition(id,7,2).status==n::QueryStatus::unavailable&&owner.admit_navigation_condition(id,8,0).status==n::QueryStatus::unavailable);
        check(owner.admitted_navigation_link(id,7,0,1).status==n::QueryStatus::completed&&!owner.admitted_navigation_link(id,7,0,1).index);
        u::world::World foreign({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<u::world::Session>());const auto other=foreign.spawn_primary(0,std::make_unique<u::world::Actor>()).id;
        check(owner.admit_navigation_condition(other,7,0).status==n::QueryStatus::unavailable&&owner.admitted_navigation_link(other,7,0,0).status==n::QueryStatus::unavailable);
        check(owner.refresh_current_navigation_node(other,visibility).status==n::QueryStatus::unavailable);
        check(world.retire_primary(0)==u::world::actors::EntityStatus::completed&&owner.applicable_navigation_condition(id,7,1).status==n::QueryStatus::unavailable);
        check(world.close()==u::world::Status::completed&&owner.admit_navigation_condition(id,7,0).status==n::QueryStatus::unavailable&&owner.admitted_navigation_link(id,7,0,0).status==n::QueryStatus::unavailable);
        check(owner.refresh_current_navigation_node(id,visibility).status==n::QueryStatus::unavailable);
        check(owner.close()==u::Status::completed);std::cout<<"{\"checks\":"<<checks<<"}\n";
    }catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
}
