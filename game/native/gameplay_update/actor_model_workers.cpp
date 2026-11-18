#include "actor_model_workers.hpp"
#include <exception>
#include <stdexcept>
namespace reo::native::gameplay_update {
ActorModelWorkers::ActorModelWorkers(world::World& world,PhaseServices& remaining,
    const world::ModelCorrectionScales& scales,world::WorldResourceAttachments& attachments,
    std::shared_ptr<const gameplay_collision::response::Grid> floors)
    :world_(world),remaining_(remaining),passes_(world,scales,attachments,std::move(floors)){}
ActorModelWorkers::~ActorModelWorkers(){if(running_)std::terminate();}
Status ActorModelWorkers::close()noexcept{
    if(running_||passes_.close()==world::ActorModelPassStatus::busy)return Status::busy;
    closed_=true;primary_.reset();auxiliary_.reset();return Status::completed;
}
void ActorModelWorkers::verify(Owner& owner)const{
    if(closed_||!owner.open()||&owner.world()!=&world_)
        throw std::invalid_argument("Native actor model worker owner closed or foreign");
}
void ActorModelWorkers::run(Worker stage,Owner& owner){
    verify(owner);
    if(stage==Worker::reset_entity_queues){primary_.reset();auxiliary_.reset();}
    if(stage!=Worker::primary_model_poses&&stage!=Worker::auxiliary_model_poses){remaining_.run(stage,owner);return;}
    if(running_)throw std::runtime_error("Native actor model worker reentry unavailable");
    running_=true;struct Reset{bool& flag;~Reset(){flag=false;}}reset{running_};
    auto& result=stage==Worker::primary_model_poses?primary_:auxiliary_;result.reset();
    result=stage==Worker::primary_model_poses?passes_.primary():passes_.auxiliary();
    if(result->status!=world::ActorModelPassStatus::completed)
        throw std::runtime_error("Native actor model frame publication unavailable");
}
bool ActorModelWorkers::button(Button button,Owner& owner){verify(owner);return remaining_.button(button,owner);}
bool ActorModelWorkers::transition_request(Owner& owner){verify(owner);return remaining_.transition_request(owner);}
void ActorModelWorkers::effect(PhaseEffect effect,Owner& owner,std::uint32_t argument){verify(owner);remaining_.effect(effect,owner,argument);}
}
