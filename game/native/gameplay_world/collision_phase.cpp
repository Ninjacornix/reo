#include "collision_phase.hpp"
namespace reo::native::gameplay_world {
HeightReport update_collision_heights(World& world,const CollisionRoom& room,
    std::span<const std::shared_ptr<Actor>> auxiliary,
    std::span<gameplay_collision::ground::Entry> secondary,
    SecondaryCollisionWalls& secondary_walls){
    HeightReport result;
    // Auxiliary snapshots come from their scene owner, never from reusable
    // primary indices. Reject ambiguous ownership before any geometric write.
    for(std::size_t i=0;i<auxiliary.size();++i){
        if(!auxiliary[i]){result.status=HeightStatus::invalid_roster;return result;}
        for(std::size_t j=0;j<i;++j)if(auxiliary[i].get()==auxiliary[j].get()){
            result.status=HeightStatus::invalid_roster;return result;
        }
        for(std::size_t j=0;j<World::primary_capacity;++j)if(auxiliary[i].get()==world.primary(j).get()){
            result.status=HeightStatus::invalid_roster;return result;
        }
    }
    // Source745D58 is true during both primary-layout passes and false before
    // secondary processing. Copying immutable room views changes no assets.
    auto primary_room=room;primary_room.height_layers=true;
    result.primary=update_primary_collision(world,primary_room);
    if(result.primary.status!=CollisionStatus::completed){result.status=HeightStatus::primary_failure;return result;}
    for(std::size_t i=0;i<auxiliary.size();++i){
        ++result.auxiliary_visited;
        result.last_auxiliary=update_collision(*auxiliary[i],
            {world.room,world.paused!=0,room.objects_enabled,true},primary_room);
        if(result.last_auxiliary.status!=CollisionStatus::completed){
            result.status=HeightStatus::auxiliary_failure;result.failed_auxiliary=i;return result;
        }
    }
    auto secondary_room=room;secondary_room.height_layers=false;
    struct WallAdapter final:gameplay_collision::ground::Walls {
        SecondaryCollisionWalls& owner;const CollisionRoom& room;
        WallAdapter(SecondaryCollisionWalls& o,const CollisionRoom& r):owner(o),room(r){}
        void correct(const actors::EntityId& id,gameplay_collision::ground::View view)override{
            owner.correct(id,view,room);
        }
    } walls(secondary_walls,secondary_room);
    result.secondary=gameplay_collision::ground::update(secondary,room.floors,walls);
    if(result.secondary.unknown_probes)result.status=HeightStatus::unknown_secondary_probe;
    return result;
}
}
