#include "npc_actor_workers.hpp"
void check_npc_actor_workers(){
    namespace w=u::world;
    w::World world({{{1,2,4}},1,{32,UINT64_MAX}},std::make_shared<w::Session>());Notifications notifications;u::Owner owner(world,notifications);
    world.mode=1;world.session().scenario=0;owner.state.scripts_enabled=false;
    check(owner.initialize_completion_statistics()==e::StatisticsStatus::completed);
    const auto idle=std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{{std::byte{1},{},{},{},std::byte{0xa},{},{},{}}});
    check(owner.scripts().install(0,idle)==s::Status::completed&&owner.scripts().install(1,idle)==s::Status::completed);
    const auto first=world.auxiliary_actors().allocate(1).id,second=world.auxiliary_actors().allocate(1).id;
    const auto actor=world.resolve(first),hidden=world.resolve(second);
    actor->active=actor->visible=true;actor->category=1;actor->npc.emplace();actor->position={1000,0,0};actor->model_scale={1,1,1};actor->motion_multiplier=1;
    hidden->active=true;hidden->visible=false;hidden->npc.emplace();hidden->collision.pose_ready=true;
    struct Behavior final:EmptyActors {
        u::NpcActorWorkers* workers{};unsigned calls{};bool fail{};
        void run(w::Stage stage,w::World& current,w::Actor& value)override{
            check(stage==w::Stage::update_behavior&&current.busy()&&workers->close()==u::Status::busy&&current.close()==w::Status::busy);
            check(current.auxiliary_actors().reset()==w::AuxiliaryStatus::busy);value.root_motion_delta={1,0,0};++calls;
            if(fail)throw std::runtime_error("fixture required NPC behavior unavailable");
        }
    }behavior;
    struct Remaining final:u::PhaseServices {
        w::World& world;w::actors::EntityId id;std::vector<u::Worker> calls;
        Remaining(w::World& value,w::actors::EntityId actor):world(value),id(actor){}
        void run(u::Worker stage,u::Owner&)override{
            check(stage!=u::Worker::auxiliary_actors);
            if(stage==u::Worker::scenario_actors)check(world.resolve(id)->position.x>=1001);
            calls.push_back(stage);
        }
        bool button(u::Button,u::Owner&)override{return false;}
        bool transition_request(u::Owner&)override{return false;}
        void effect(u::PhaseEffect,u::Owner&,std::uint32_t)override{throw std::runtime_error("unexpected NPC worker phase effect");}
    }remaining(world,first);
    const auto floors=std::make_shared<const reo::native::gameplay_collision::response::Grid>();w::Position camera{};std::uint8_t inhibition{};
    u::NpcActorWorkers workers(world,remaining,behavior,floors,camera,inhibition);behavior.workers=&workers;EmptyActors primary;
    check(owner.run_workers(workers,primary).status==u::Status::completed&&workers.last_actors()&&workers.last_actors()->visited==2&&workers.last_actors()->called==1&&workers.last_actors()->suppressed==1&&behavior.calls==1);
    check(actor->position.x==1001&&actor->collision.pose_ready&&!hidden->collision.pose_ready);
    inhibition=1;check(owner.run_workers(workers,primary).status==u::Status::completed&&workers.last_actors()->called==0&&behavior.calls==1&&!actor->collision.pose_ready);
    inhibition=0;behavior.fail=true;bool failed=false;try{(void)owner.run_workers(workers,primary);}catch(const std::runtime_error&){failed=true;}
    check(failed&&!workers.last_actors()&&!world.busy()&&behavior.calls==2);behavior.fail=false;
    check(owner.run_workers(workers,primary).status==u::Status::completed&&workers.last_actors()->called==1&&actor->position.x==1002);
    world.paused=1;check(owner.run_workers(workers,primary).status==u::Status::completed&&!workers.last_actors()&&behavior.calls==3);world.paused=0;
    w::World foreign({{{1,2,4}},1,{32,UINT64_MAX}},std::make_shared<w::Session>());Notifications other_notifications;u::Owner other(foreign,other_notifications);
    failed=false;try{workers.run(u::Worker::auxiliary_actors,other);}catch(const std::invalid_argument&){failed=true;}check(failed);
    check(workers.close()==u::Status::completed&&owner.close()==u::Status::completed&&world.close()==w::Status::completed);
}
