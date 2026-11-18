#include "dialogue_workers.hpp"
#include <exception>
#include <stdexcept>
namespace reo::native::gameplay_update {
DialogueWorkers::DialogueWorkers(Owner& owner,PhaseServices& remaining,world::DialoguePool& pool,const world::InventoryUi& inventory,
    const world::input::Frame* menu,const std::optional<std::uint32_t>& actions,const scenario::SceneResources* resources,const scenario::ResourceTemplates* templates)
    :owner_(owner),remaining_(remaining),pool_(pool),inventory_(inventory),menu_(menu),menu_actions_(actions),resources_(resources),templates_(templates){
    if(!owner_.open()||!pool_.bound_to(owner_.world())||!inventory_.bound_to(owner_.world()))throw std::invalid_argument("Native dialogue worker requires the same canonical Update, pool and inventory UI");
}
DialogueWorkers::~DialogueWorkers(){if(running_)std::terminate();}
Status DialogueWorkers::close()noexcept{if(running_)return Status::busy;closed_=true;last_.reset();return Status::completed;}
void DialogueWorkers::verify(Owner& owner)const{if(closed_||&owner!=&owner_||!owner.open())throw std::invalid_argument("Native dialogue worker Update owner closed or foreign");}
void DialogueWorkers::run(Worker stage,Owner& owner){
    verify(owner);if(stage==Worker::reset_entity_queues)last_.reset();
    if(stage!=Worker::sequences){remaining_.run(stage,owner);return;}
    if(running_)throw std::runtime_error("Native dialogue worker reentry unavailable");
    running_=true;struct Reset{bool& flag;~Reset(){flag=false;}}reset{running_};
    world::DialogueResponseFrame frame{menu_,menu_actions_,{inventory_.request_blocked(),owner_.world().selected_frame_marker},{&owner_.flags(),resources_,templates_},&owner_};
    last_=pool_.advance_response_prefix(frame);
    if(last_->status!=world::DialogueStatus::completed)throw std::runtime_error("Native dialogue worker reached unavailable response work");
}
bool DialogueWorkers::button(Button value,Owner& owner){verify(owner);return remaining_.button(value,owner);}
bool DialogueWorkers::transition_request(Owner& owner){verify(owner);return remaining_.transition_request(owner);}
void DialogueWorkers::effect(PhaseEffect value,Owner& owner,std::uint32_t argument){verify(owner);remaining_.effect(value,owner,argument);}
}
