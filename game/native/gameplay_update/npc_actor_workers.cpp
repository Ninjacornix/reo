#include "npc_actor_workers.hpp"
#include <stdexcept>
namespace reo::native::gameplay_update {
namespace {
const gameplay_collision::response::Grid& require_floors(const std::shared_ptr<const gameplay_collision::response::Grid>& value){
    if(!value)throw std::invalid_argument("Native NPC actor floor owner unavailable");
    return *value;
}
}
NpcActorWorkers::NpcActorWorkers(world::World& world,PhaseServices& remaining,world::Services& behavior,
    std::shared_ptr<const gameplay_collision::response::Grid> floors,const world::Position& camera,
    const std::uint8_t& inhibition,world::NpcAttachmentFrames* attachments):world_(world),remaining_(remaining),floors_(std::move(floors)),pose_(require_floors(floors_)),updates_(world_,behavior,pose_,camera,inhibition,attachments){}
NpcActorWorkers::~NpcActorWorkers(){if(running_)std::terminate();(void)close();}
Status NpcActorWorkers::close()noexcept{
    if(running_||updates_.close()==world::NpcUpdateStatus::busy)return Status::busy;
    closed_=true;last_.reset();return Status::completed;
}
void NpcActorWorkers::verify(Owner& owner)const{
    if(closed_||!owner.open()||&owner.world()!=&world_)throw std::invalid_argument("Native NPC actor worker owner unavailable or foreign");
}
void NpcActorWorkers::run(Worker stage,Owner& owner){
    verify(owner);
    if(stage==Worker::reset_entity_queues)last_.reset();
    if(stage!=Worker::auxiliary_actors){remaining_.run(stage,owner);return;}
    if(running_)throw std::runtime_error("Native NPC actor worker reentry unavailable");
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};last_.reset();
    last_=updates_.run();if(last_->status!=world::NpcUpdateStatus::completed)throw std::runtime_error("Native NPC actor worker unavailable");
}
bool NpcActorWorkers::button(Button value,Owner& owner){verify(owner);return remaining_.button(value,owner);}
bool NpcActorWorkers::transition_request(Owner& owner){verify(owner);return remaining_.transition_request(owner);}
void NpcActorWorkers::effect(PhaseEffect value,Owner& owner,std::uint32_t argument){verify(owner);remaining_.effect(value,owner,argument);}
}
