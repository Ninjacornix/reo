#include "collision_phase.hpp"
#include <iostream>
#include <stdexcept>
namespace g=reo::native::gameplay_world;
namespace c=reo::native::gameplay_collision;
unsigned checks{};
void check(bool value){++checks;if(!value)throw std::runtime_error("Height phase check "+std::to_string(checks));}
std::shared_ptr<g::Actor> auxiliary(float marker){
    auto actor=std::make_shared<g::Actor>();actor->active=true;actor->room=1;actor->collision.pose_ready=true;
    actor->contact_flags=3;actor->collision.local_center={marker,2,3};return actor;
}
struct Walls final:g::SecondaryCollisionWalls {
    g::World& world;std::vector<std::shared_ptr<g::Actor>>& auxiliary;
    unsigned calls{};bool throwing{};
    Walls(g::World& w,std::vector<std::shared_ptr<g::Actor>>& a):world(w),auxiliary(a){}
    void correct(const g::actors::EntityId&,c::ground::View view,const g::CollisionRoom& room)override{
        ++calls;check(!room.height_layers);
        check(world.primary(0)->collision.previous_center_offset.x==11);
        check(auxiliary[0]->collision.previous_center_offset.x==21);
        check(auxiliary[1]->collision.previous_center_offset.x==31);
        view.position.x+=7;
        if(throwing)throw std::runtime_error("Declared secondary wall failure");
    }
};
int main()try{
    g::Profile profile;profile.layouts.resize(1);g::World world(profile,std::make_shared<g::Session>());world.room=1;
    auto actor=std::make_unique<g::Actor>();actor->active=true;actor->room=1;actor->contact_flags=3;
    actor->collision.pose_ready=true;actor->collision.local_center={11,2,3};
    check(world.spawn_primary(0,std::move(actor)).status==g::actors::EntityStatus::completed);
    std::vector<std::shared_ptr<g::Actor>> aux{auxiliary(21),auxiliary(31)};
    g::World secondary_owner(profile,std::make_shared<g::Session>());
    auto secondary=std::make_unique<g::Actor>();secondary->position={2,3,4};
    auto identity=secondary_owner.spawn_primary(0,std::move(secondary)).id;auto s=secondary_owner.primary(0);
    std::uint8_t subtype{};std::uint16_t controls{};c::Vec3 displacement{1,2,3};c::ground::ProbeStates states;
    c::ground::View view{s->position,s->surface_normal,s->grid_response,s->surface_kind,s->surface_material,
        s->surface_attributes,s->auxiliary_status,{s->orientation[0],s->orientation[1],s->orientation[2]}};
    std::array<c::ground::Entry,1> entries{{{identity,view,displacement,controls,subtype,states}}};
    c::response::Grid walls,floors;c::regions::World regions;c::room_objects::Owner objects;
    const g::CollisionRoom room{walls,floors,regions,objects,{},{},false,false};Walls secondary_walls(world,aux);
    auto result=g::update_collision_heights(world,room,aux,entries,secondary_walls);
    check(result.status==g::HeightStatus::completed && result.primary.eligible==1 && result.auxiliary_visited==2);
    check(result.secondary.visited==1 && result.secondary.wall_queries==1 && secondary_walls.calls==1 && s->position.x==9);
    check(!room.height_layers); // The source phase flag is local state, not a changed room asset.
    world.primary(0)->collision.previous_center_offset={99,99,99};
    const std::array<std::shared_ptr<g::Actor>,2> ambiguous{aux[0],aux[0]};
    result=g::update_collision_heights(world,room,ambiguous,entries,secondary_walls);
    check(result.status==g::HeightStatus::invalid_roster && world.primary(0)->collision.previous_center_offset.x==99 && secondary_walls.calls==1);
    const std::array<std::shared_ptr<g::Actor>,1> aliased{world.primary(0)};
    check(g::update_collision_heights(world,room,aliased,entries,secondary_walls).status==g::HeightStatus::invalid_roster);
    world.primary(0)->collision.pose_ready=false;
    result=g::update_collision_heights(world,room,aux,entries,secondary_walls);
    check(result.status==g::HeightStatus::primary_failure && !result.auxiliary_visited && !result.secondary.visited);
    world.primary(0)->collision.pose_ready=true;aux[1]->collision.pose_ready=false;aux[0]->collision.previous_center_offset={99,99,99};
    result=g::update_collision_heights(world,room,aux,entries,secondary_walls);
    check(result.status==g::HeightStatus::auxiliary_failure && result.failed_auxiliary==1 && result.auxiliary_visited==2);
    check(world.primary(0)->collision.previous_center_offset.x==11 && aux[0]->collision.previous_center_offset.x==21 && secondary_walls.calls==1);
    aux[1]->collision.pose_ready=true;controls=0x20;subtype=1;states.kind_one=2;
    result=g::update_collision_heights(world,room,aux,entries,secondary_walls);
    check(result.status==g::HeightStatus::unknown_secondary_probe && result.secondary.unknown_probes==1 && result.secondary.displaced==1);
    check(s->position.x==10 && s->position.z==7 && states.kind_one==2 && secondary_walls.calls==1);
    controls=0;subtype=0;secondary_walls.throwing=true;bool failed{};
    try{g::update_collision_heights(world,room,aux,entries,secondary_walls);}catch(const std::runtime_error&){failed=true;}
    check(failed && s->position.x==17 && secondary_walls.calls==2);
    secondary_walls.throwing=false;
    check(g::update_collision_heights(world,room,aux,entries,secondary_walls).status==g::HeightStatus::completed && s->position.x==24);
    std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
