#include "transient_lights.hpp"
#include "../gameplay_update/update.hpp"
#include "../gameplay_collision/response.hpp"
#include <iostream>
#include <stdexcept>
namespace n=reo::native;
unsigned checks{};
void check(bool value){++checks;if(!value)throw std::runtime_error("Native projectile light contract");}
struct Notifications final:n::gameplay_scenario::FlagNotifications {
    bool changed(const n::gameplay_scenario::ScenarioFlagChange&)noexcept override{std::terminate();}
    bool changed(const n::gameplay_scenario::StridedFlagChange&)noexcept override{std::terminate();}
};
struct Idle final:n::gameplay_tasks::Task {void update(n::gameplay_tasks::Scheduler&,const n::gameplay_tasks::Handle&)noexcept override{}};
int main()try{
    namespace l=n::gameplay_lighting;namespace t=n::gameplay_tasks;
    n::gameplay_world::Profile profile;profile.layouts.push_back({});n::gameplay_world::World world(profile,std::make_shared<n::gameplay_world::Session>());Notifications flags;n::gameplay_update::Owner update(world,flags);n::gameplay_scenario::Lighting lights;l::TransientLights owner(update,lights);
    const n::gameplay_collision::response::Grid missing_floor;const auto made=owner.create_projectile({1,2,3},missing_floor);
    check(made.status==l::TransientStatus::completed&&made.lights==std::array<bool,2>{true,true});const auto saved=owner.snapshot(made.task);
    check(saved&&saved->lights[0]&&saved->lights[1]&&saved->lights[0]->tag==255&&saved->lights[1]->tag==255);
    check(saved->lights[0]->descriptor.position==std::array<float,3>{1,2,3});
    for(unsigned i=0;i<4;++i){check(update.linked().run(t::Pass::update).status==t::Status::completed);}
    check(!owner.snapshot(made.task)&&lights.primary_count()==0&&lights.auxiliary_count()==0&&update.linked().size()==0);
    check(saved->lights[0]->active&&saved->lights[1]->active);
    for(unsigned i=0;i<t::Scheduler::capacity;++i){check(update.linked().create(std::make_shared<Idle>()).status==t::Status::completed);}
    check(owner.create_projectile({},missing_floor).status==l::TransientStatus::task_full&&lights.primary_count()==0&&lights.auxiliary_count()==0);
    check(update.linked().clear()==t::Status::completed&&owner.close()==l::TransientStatus::completed);
    check(owner.create_projectile({},missing_floor).status==l::TransientStatus::closed&&update.close()==n::gameplay_update::Status::completed);
    std::cout<<"{\"checks\":"<<checks<<",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
