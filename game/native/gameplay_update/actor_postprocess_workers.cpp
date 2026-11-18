#include "actor_postprocess_workers.hpp"
#include <exception>
#include <stdexcept>
namespace reo::native::gameplay_update {
ActorPostprocessWorkers::ActorPostprocessWorkers(Owner& owner,PhaseServices& remaining,
    gameplay_scene::Records& records,scenario::SceneMatrixPrograms& programs,
    std::shared_ptr<const gameplay_collision::response::Grid> floors,world::ActorWeaponActions* weapons)
    :owner_(owner),remaining_(remaining),floors_(std::move(floors)),
     pass_(owner.world(),records,programs,owner.flags(),owner.completion_statistics(),floors_.get(),weapons),
     auxiliary_(owner.world(),records,programs,owner.flags(),floors_.get(),weapons){
    if(!owner.open()||!programs.bound_to_records(records,owner.flags(),owner.world().room))
        throw std::invalid_argument("Native actor postprocess requires canonical Update/scene ownership");
}
ActorPostprocessWorkers::~ActorPostprocessWorkers(){if(running_)std::terminate();}
Status ActorPostprocessWorkers::close()noexcept{
    if(running_)return Status::busy;
    closed_=true;result_.reset();auxiliary_result_.reset();return Status::completed;
}
void ActorPostprocessWorkers::verify(Owner& owner)const{
    if(closed_||&owner!=&owner_||!owner.open())
        throw std::invalid_argument("Native actor postprocess Update owner closed or foreign");
}
void ActorPostprocessWorkers::run(Worker stage,Owner& owner){
    verify(owner);
    if(stage==Worker::reset_entity_queues){result_.reset();auxiliary_result_.reset();}
    if(stage!=Worker::primary_actor_postprocess&&stage!=Worker::auxiliary_actor_postprocess){remaining_.run(stage,owner);return;}
    if(running_)throw std::runtime_error("Native actor postprocess worker reentry unavailable");
    running_=true;struct Reset{bool& flag;~Reset(){flag=false;}}reset{running_};
    if(stage==Worker::primary_actor_postprocess){
        result_=pass_.run();
        if(result_->status!=world::PrimaryPostprocessStatus::completed)
            throw std::runtime_error("Native primary actor postprocess reached work unavailable");
    }else{
        auxiliary_result_=auxiliary_.run();
        if(auxiliary_result_->status!=world::AuxiliaryPostprocessStatus::completed)
            throw std::runtime_error("Native auxiliary actor postprocess reached work unavailable");
    }
}
bool ActorPostprocessWorkers::button(Button value,Owner& owner){verify(owner);return remaining_.button(value,owner);}
bool ActorPostprocessWorkers::transition_request(Owner& owner){verify(owner);return remaining_.transition_request(owner);}
void ActorPostprocessWorkers::effect(PhaseEffect value,Owner& owner,std::uint32_t argument){verify(owner);remaining_.effect(value,owner,argument);}
}
