#include "collision.hpp"
namespace reo::native::gameplay_world {
collision::postmove::View collision_view(Actor& a)noexcept{
    auto& c=a.collision;
    return{{a.position,a.previous_position,c.local_center,c.previous_center_offset,c.radius,
            a.response_mask,a.response_value,a.category==2,c.contact,c.point,c.normal},
        c.displacement,c.joint_two_position,a.grid_response,a.sampled_surface_height,
        a.status,a.auxiliary_status,a.contact_flags,a.room,c.route_ticks,a.surface_attributes,
        a.motion_class,a.surface_kind,a.surface_material,a.active,a.movement_enabled};
}
CollisionResult update_collision(Actor& a,collision::postmove::Context context,const CollisionRoom& room){
    CollisionResult result;
    if(a.active && (context.ignore_room || a.room==context.room) && !a.collision.pose_ready){
        result.status=CollisionStatus::pose_unavailable;return result;
    }
    result.policy=collision::postmove::update(collision_view(a),context,a.collision.basis,
        room.walls,room.floors,room.regions,room.objects,room.filter,room.dynamic);
    if(result.policy.missing_joint || result.policy.footprint_status!=collision::footprint::Status::complete ||
       (result.policy.wall_status!=collision::sweep::Status::ok && result.policy.wall_status!=collision::sweep::Status::source_face_recovered))
        result.status=CollisionStatus::geometry_unavailable;
    return result;
}
CollisionPass update_primary_collision(World& world,const CollisionRoom& room){
    CollisionPass pass;
    for(std::size_t i=0;i<World::primary_capacity;++i){
        auto actor=world.primary(i);if(!actor)continue;++pass.visited;
        const auto step=update_collision(*actor,{world.room,world.paused,room.objects_enabled,room.height_layers},room);
        pass.last=step.policy;pass.eligible+=step.policy.eligible;
        pass.source_face_recoveries+=step.policy.wall_status==collision::sweep::Status::source_face_recovered;
        if(step.status!=CollisionStatus::completed){pass.status=step.status;pass.failed_actor=world.identity(i);return pass;}
    }
    return pass;
}
}
