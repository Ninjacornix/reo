#include "projectile_pose_lights.hpp"
#include "../gameplay_update/update.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
ProjectilePoseLights::ProjectilePoseLights(gameplay_update::Owner& update,gameplay_scenario::Lighting& lights,gameplay_lighting::TransientLights& transient,gameplay_contact_world::RoomResources& rooms,PoseProjectileActions* remaining)
    :update_(update),lights_(lights),transient_(transient),rooms_(rooms),remaining_(remaining){if(!bound_to(update.world()))throw std::invalid_argument("Native projectile light owners unavailable");}
bool ProjectilePoseLights::bound_to(const World& world)const noexcept{return &update_.world()==&world&&update_.open()&&transient_.bound_to(update_,lights_)&&(!remaining_||remaining_->bound_to(world));}
bool ProjectilePoseLights::projectile_light(transform_math::Vector point){
    auto& world=update_.world();if(!bound_to(world))return false;
    const auto number=world.room;const auto room=rooms_.retain(number);const auto id=room?room->identity():gameplay_contact_world::RoomId{};
    if(!room||!id||room->room_number()!=number||!room->current(id)||world.room!=number)return false;
    const auto made=transient_.create_projectile({point.x,point.y,point.z},room->geometry().floors);
    return room->current(id)&&world.room==number&&(made.status==gameplay_lighting::TransientStatus::completed||made.status==gameplay_lighting::TransientStatus::task_full);
}
bool ProjectilePoseLights::ground_flare(const actors::EntityId& id){return bound_to(update_.world())&&remaining_&&remaining_->ground_flare(id);}
bool ProjectilePoseLights::ground_trail(const actors::EntityId& id){return bound_to(update_.world())&&remaining_&&remaining_->ground_trail(id);}
bool ProjectilePoseLights::forward_visual(const actors::EntityId& id){return bound_to(update_.world())&&remaining_&&remaining_->forward_visual(id);}
bool ProjectilePoseLights::follower_position(const actors::EntityId& id,transform_math::Vector point){return bound_to(update_.world())&&remaining_&&remaining_->follower_position(id,point);}
std::optional<actors::EntityId> ProjectilePoseLights::follower_visual(const actors::EntityId& id){return bound_to(update_.world())&&remaining_?remaining_->follower_visual(id):std::nullopt;}
}
