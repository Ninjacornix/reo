#include "session_resource_workers.hpp"
#include "native_session.hpp"
#include <stdexcept>
namespace reo::native::gameplay_application {
SessionResourceWorkers::SessionResourceWorkers(NativeSession& session,SessionResources& resources,gameplay_update::PhaseServices& remaining):session_(session),resources_(resources),remaining_(remaining){
    if(!resources_.bound_to(session_)||!resources_.initialized())throw std::invalid_argument("Canonical initialized session resources required");
}
void SessionResourceWorkers::verify(gameplay_update::Owner& owner)const{
    if(&owner!=&session_.update()||!resources_.bound_to(session_))throw std::runtime_error("Foreign or retired session resource worker");
}
void SessionResourceWorkers::run(gameplay_update::Worker worker,gameplay_update::Owner& owner){
    verify(owner);
    if(worker==gameplay_update::Worker::resource_instances||worker==gameplay_update::Worker::scene_pose_tasks){
        if(resources_.run_worker(worker,owner)!=SessionResourceStatus::completed)throw std::runtime_error("Native session resource worker unavailable");
    }else remaining_.run(worker,owner);
}
bool SessionResourceWorkers::button(gameplay_update::Button button,gameplay_update::Owner& owner){verify(owner);return remaining_.button(button,owner);}
bool SessionResourceWorkers::transition_request(gameplay_update::Owner& owner){verify(owner);return remaining_.transition_request(owner);}
void SessionResourceWorkers::effect(gameplay_update::PhaseEffect effect,gameplay_update::Owner& owner,std::uint32_t argument){verify(owner);remaining_.effect(effect,owner,argument);}
}
