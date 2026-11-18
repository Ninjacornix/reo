#include "pose_motion.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
PoseMotionUpdates::PoseMotionUpdates(World& world,PoseWorkPool& pool,PoseTimingQuantum* quantum,PoseWorkUpdates* remaining)
    :world_(world),pool_(pool),quantum_(quantum),remaining_(remaining){if(!bound_to(world))throw std::invalid_argument("Native pose motion owners unavailable");}
bool PoseMotionUpdates::bound_to(const World& world)const noexcept{return &world==&world_&&pool_.bound_to(world)&&(!quantum_||quantum_->bound_to(world))&&(!remaining_||remaining_->bound_to(world));}
bool PoseMotionUpdates::update(PoseWorkPool& pool,const actors::EntityId& id,std::uint8_t kind){
    if(&pool!=&pool_||!bound_to(world_))return false;
    if(kind!=11&&kind!=19)return remaining_&&remaining_->update(pool,id,kind);
    const auto actor=pool.resolve(id);if(!actor)return false;
    const auto quantum=kind==11&&actor->primary==0&&quantum_?quantum_->read():std::nullopt;
    if(pool.resolve(id)!=actor)return false;
    const auto step=advance_pose_motion(*actor,kind,quantum);
    return step==PoseMotionStep::completed||(step==PoseMotionStep::retire&&pool.retire(id,true)==PoseWorkStatus::completed);
}
}
