#include "pose_cloud.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
PoseCloudUpdates::PoseCloudUpdates(World& world,PoseWorkPool& pool,gameplay_effects::WorkBackend& visuals,
    gameplay_lighting::TimedLights& lights,PoseWorkUpdates* remaining)
    :world_(world),pool_(pool),visuals_(visuals),lights_(lights),remaining_(remaining){
    if(!bound_to(world))throw std::invalid_argument("Native pose cloud owners unavailable");
}
bool PoseCloudUpdates::bound_to(const World& world)const noexcept{
    return &world==&world_&&pool_.bound_to(world)&&visuals_.admitted()&&visuals_.bound_to(world_.session().random)&&lights_.bound_to(world)&&(!remaining_||remaining_->bound_to(world));
}
bool PoseCloudUpdates::visual(transform_math::Vector point){
    gameplay_effects::WorkRequest request;request.position=point;
    //6525D0 forwards a2 to child enablement and t0 to group variation.
    // The authored7123F5 value is a mask; the source t0 here is zero.
    request.effect=0x55;request.child_mask=0xc0;request.variant=0;
    const auto made=visuals_.create(request);return made.status==gameplay_effects::WorkStatus::completed||made.status==gameplay_effects::WorkStatus::pool_full||made.status==gameplay_effects::WorkStatus::resource_missing;
}
bool PoseCloudUpdates::light(const actors::EntityId& parent,transform_math::Vector point){
    const auto made=lights_.create(parent,{point.x,point.y,point.z});return made.status==gameplay_lighting::TimedStatus::completed||made.status==gameplay_lighting::TimedStatus::skipped||made.status==gameplay_lighting::TimedStatus::task_full;
}
bool PoseCloudUpdates::update(PoseWorkPool& pool,const actors::EntityId& id,std::uint8_t kind){
    if(&pool!=&pool_||!bound_to(world_))return false;
    if(kind!=20)return remaining_&&remaining_->update(pool,id,kind);
    const auto actor=pool.resolve(id);if(!actor)return false;
    const auto step=advance_pose_cloud(*actor,*this);
    return step==PoseCloudStep::completed||(step==PoseCloudStep::retire&&pool.retire(id,true)==PoseWorkStatus::completed);
}
}
