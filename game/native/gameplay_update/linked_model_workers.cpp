#include "linked_model_workers.hpp"
#include <stdexcept>
namespace reo::native::gameplay_update {
LinkedModelWorkers::LinkedModelWorkers(world::World& world,PhaseServices& remaining,
    std::shared_ptr<const gameplay_collision::response::Grid> floors):world_(world),remaining_(remaining),floors_(std::move(floors)),root_(world_){
    if(!floors_||world_.closed()||world_.linked_model_owner_)throw std::invalid_argument("Native linked model worker World/floor owner unavailable or already bound");
    world_.linked_model_owner_=this;
}
LinkedModelWorkers::~LinkedModelWorkers(){if(running_)std::terminate();(void)close();}
Status LinkedModelWorkers::close()noexcept{
    if(running_)return Status::busy;
    closed_=true;models_.reset();progress_=LinkedModelProgress::never_run;
    if(world_.linked_model_owner_==this)world_.linked_model_owner_=nullptr;
    return Status::completed;
}
void LinkedModelWorkers::verify(Owner& owner)const{
    if(closed_||!owner.open()||&owner.world()!=&world_)
        throw std::invalid_argument("Native linked model worker owner unavailable or foreign");
}
void LinkedModelWorkers::select_root(world::actors::EntityId id){
    if(closed_||running_||world_.closed())throw std::runtime_error("Native linked model worker closed or running");
    root_.select(std::move(id));
}
void LinkedModelWorkers::run(Worker stage,Owner& owner){
    verify(owner);
    if(stage==Worker::reset_entity_queues){models_.reset();progress_=LinkedModelProgress::never_run;}
    if(stage!=Worker::scenario_model_poses){remaining_.run(stage,owner);return;}
    if(running_)throw std::runtime_error("Native linked model worker reentry unavailable");
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    models_.reset();progress_=LinkedModelProgress::acquiring;
    struct Attempt{LinkedModelProgress& value;~Attempt(){if(value==LinkedModelProgress::acquiring)value=LinkedModelProgress::failed;}}attempt{progress_};
    world::LinkedModelPass pass(world_,world_.linked_models(),root_,scales_,floors_.get());
    models_=pass.run();progress_=LinkedModelProgress::completed;
}
bool LinkedModelWorkers::button(Button value,Owner& owner){verify(owner);return remaining_.button(value,owner);}
bool LinkedModelWorkers::transition_request(Owner& owner){verify(owner);return remaining_.transition_request(owner);}
void LinkedModelWorkers::effect(PhaseEffect value,Owner& owner,std::uint32_t argument){verify(owner);remaining_.effect(value,owner,argument);}
}
