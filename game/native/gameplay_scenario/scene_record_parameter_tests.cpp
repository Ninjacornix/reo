#include "scene_record_parameters.hpp"
#include "../gameplay_update/actor_message_queue.hpp"
#include "../gameplay_update/update.hpp"
#include "tools/native_reconstruction/gameplay_scenario/scene_record_fields.hpp"
#include <bit>
#include <cstring>
#include <iostream>
#include <source_location>
#include <stdexcept>
#ifdef REO_SCENE_RECORD_PARAMETERS_ORIGINAL
#include "original_fixture.hpp"
#include "original_declarations.hpp"
#endif
namespace scene=reo::native::gameplay_scenario;
namespace update=reo::native::gameplay_update;
namespace world=reo::native::gameplay_world;
namespace {
std::size_t checks{},sender_cases{},adapter_cases{},receiver_cases{},queue_cases{},owner_cases{};
std::string context;
void check(bool value,const std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Scene parameter check "+std::to_string(checks)+" "+context+" at "+std::to_string(at.line()));
}
world::Profile profile(){world::Profile p;p.layouts.push_back({});return p;}
struct Native {
    std::shared_ptr<world::Session> session=std::make_shared<world::Session>();
    world::World world{profile(),session};
};
template<class T>void put(std::uint8_t* bytes,unsigned at,T value){std::memcpy(bytes+at,&value,sizeof value);}
void populate(Native& state,unsigned count,unsigned trial){
    std::vector<std::byte> input(16+96*(count+1));const std::uint32_t header=16;std::memcpy(input.data(),&header,4);
    for(unsigned i=0;i<count;++i){input[16+96*i+0x49]=std::byte{1};input[16+96*i+0x33]=std::byte{255};}
    input[16+96*count+2]=std::byte{255};state.session->scenario=0;
    check(state.session->enemy_descriptors.import(input,*state.session,true,0).status==scene::EnemyImportStatus::completed);
    check(state.session->enemy_descriptors.count()==count);
    for(unsigned i=0;i<256;++i){auto& r=*state.session->enemy_descriptors.record(i);
        r.condition=std::uint8_t(i%7?trial:trial+1u);r.parameter23=std::uint8_t(i%5?trial*3u:trial*3u+1u);
        r.parameter2e=std::uint8_t(~trial);r.actor_slot=std::uint8_t(trial+i);r.target_selector=std::uint8_t(i*3u);r.variant=std::uint8_t(i*7u);
        r.health=std::int16_t(i*97u);r.maximum=std::int16_t(trial*17u);r.position={std::int32_t(trial),-std::int32_t(i),std::int32_t(trial+i)};
    }
}
#ifdef REO_SCENE_RECORD_PARAMETERS_ORIGINAL
std::vector<update::SceneRecordParameterMessage> packets;
void export_records(const Native& n,std::vector<std::uint8_t>& memory){
    std::fill(memory.begin()+0x74f250,memory.begin()+0x755250,0x71);
    for(unsigned i=0;i<256;++i)scene_record_fixture::visit(n.session->enemy_descriptors.records()[i],[&](unsigned offset,auto value){put(memory.data(),0x74f250+96*i+offset,value);});
    memory[0x4bae8e]=n.session->enemy_descriptors.count();memory[0x3243fb]=n.session->message_phase;memory[0x3243f2]=n.world.mode;
}
void compare_records(const Native& n,const std::vector<std::uint8_t>& memory){
    for(unsigned i=0;i<256;++i)scene_record_fixture::visit(n.session->enemy_descriptors.records()[i],[&](unsigned offset,auto value){check(std::memcmp(memory.data()+0x74f250+96*i+offset,&value,sizeof(value))==0);});
    check(memory[0x4bae8e]==n.session->enemy_descriptors.count());
}
void invoke(std::vector<std::uint8_t>& memory,PS2Runtime::Function function,std::array<std::uint32_t,3> arguments){
    R5900Context c;PS2Runtime runtime;for(unsigned i=0;i<3;++i)SET_GPR_U32(&c,4+i,arguments[i]);
    SET_GPR_U32(&c,29,0x7f0000);SET_GPR_U32(&c,31,0xdeadbeef);function(memory.data(),&c,&runtime);check(c.pc==0xdeadbeef);
}
#endif
struct RejectingSink final:update::GameplayMessageSink {
    bool ready{};unsigned calls{};
    bool send(const update::ScenarioOwnerMessage&)noexcept override{return false;}
    bool send(const update::ResourceOperationMessage&)noexcept override{return false;}
    bool send(const update::ResourcePositionMessage&)noexcept override{return false;}
    bool send(const update::ActorStatusMessage&)noexcept override{return false;}
    bool send(const update::SceneRecordParameterMessage&)noexcept override{++calls;return false;}
    bool scene_record_parameters_ready()const noexcept override{return ready;}
};
void boundaries(){
    Native source,target;populate(source,8,9);source.world.mode=0;source.session->message_phase=1;target.session->message_phase=1;
    update::ActorReception receiver(target.world);update::ActorMessageQueue queue(receiver,1);
    check(queue.scene_record_parameters_ready());
    auto result=scene::update_scene_record_parameter(source.world,9,27,17,&queue);
    check(result.status==scene::SceneRecordParameterStatus::completed&&result.ordinal==1&&result.notification_attempted&&result.notification_accepted&&queue.pending()==1);++queue_cases;
    check(target.session->enemy_descriptors.record(1)->parameter2e==0);
    result=scene::update_scene_record_parameter(source.world,9,27,18,&queue);
    check(result.status==scene::SceneRecordParameterStatus::completed&&result.ordinal==1&&result.notification_attempted&&!result.notification_accepted&&source.session->enemy_descriptors.record(1)->parameter2e==18&&queue.pending()==1);++queue_cases;
    auto drained=queue.drain(1);check(drained.status==update::ActorQueueStatus::completed&&drained.consumed==1&&target.session->enemy_descriptors.record(1)->parameter2e==17);++queue_cases;
    RejectingSink rejected;const auto old=source.session->enemy_descriptors.record(1)->parameter2e;
    check(!scene::scene_record_parameters_ready(source.world,nullptr)&&!scene::scene_record_parameters_ready(source.world,&rejected));
    result=scene::update_scene_record_parameter(source.world,9,27,19,&rejected);
    check(result.status==scene::SceneRecordParameterStatus::unavailable&&!rejected.calls&&source.session->enemy_descriptors.record(1)->parameter2e==old);++queue_cases;
    rejected.ready=true;result=scene::update_scene_record_parameter(source.world,9,27,19,&rejected);
    check(result.status==scene::SceneRecordParameterStatus::completed&&!result.notification_accepted&&rejected.calls==1&&source.session->enemy_descriptors.record(1)->parameter2e==19);++queue_cases;
    check(queue.close()==update::ActorQueueStatus::completed&&!queue.scene_record_parameters_ready());
    result=scene::update_scene_record_parameter(source.world,9,27,20,&queue);check(result.status==scene::SceneRecordParameterStatus::unavailable&&source.session->enemy_descriptors.record(1)->parameter2e==19);++queue_cases;
    source.session->message_phase=0;result=scene::update_scene_record_parameter(source.world,9,27,21);
    check(result.status==scene::SceneRecordParameterStatus::completed&&!result.notification_attempted&&source.session->enemy_descriptors.record(1)->parameter2e==21);++queue_cases;
    source.session->message_phase=1;source.world.mode=2;result=scene::update_scene_record_parameter(source.world,9,27,22);
    check(result.status==scene::SceneRecordParameterStatus::completed&&!result.notification_attempted&&source.session->enemy_descriptors.record(1)->parameter2e==22);++queue_cases;
    check(source.world.close()==world::Status::completed&&!scene::scene_record_parameters_ready(source.world,&rejected));++queue_cases;
}
struct NoNotifications final:scene::FlagNotifications {
    bool changed(const scene::ScenarioFlagChange&)noexcept override{std::terminate();}
    bool changed(const scene::StridedFlagChange&)noexcept override{std::terminate();}
};
struct PausedWorkers final:update::Services {
    std::vector<update::Worker> calls;
    void run(update::Worker stage,update::Owner&)override{
        check(stage==update::Worker::reset_entity_queues||stage==update::Worker::armed_request||
              stage==update::Worker::clear_interaction_activity||stage==update::Worker::clear_proxy_work);
        calls.push_back(stage);
    }
};
struct UnusedActors final:world::Services {
    void begin_offline_frame(world::World&)override{std::terminate();}
    void run(world::Stage,world::World&,world::Actor&)override{std::terminate();}
    bool remote_motion(world::World&,world::Actor&)override{std::terminate();}
    bool find_grid(world::World&,world::Actor&,std::int8_t&)override{std::terminate();}
    void switch_grid(world::World&,std::int32_t,std::int32_t)override{std::terminate();}
    float grid_response(world::World&,std::uint8_t)override{std::terminate();}
};
void owner_binding(){
    // A paused update still executes both real script channels. Every unrelated
    // actor service is forbidden, and the four ordered worker ports are explicit.
    Native source,target;populate(source,8,9);source.world.mode=1;source.world.paused=true;
    source.session->message_phase=target.session->message_phase=1;
    update::ActorReception receiver(target.world);update::ActorMessageQueue queue(receiver,8);
    NoNotifications notifications;
    update::Owner owner(source.world,notifications,reo::native::gameplay_events::RuleBook::create({reo::native::gameplay_events::RuleGroup{}},{0}),&queue);
    check(owner.initialize_completion_statistics()==reo::native::gameplay_events::StatisticsStatus::completed);
    const auto bytes=[](std::initializer_list<std::uint32_t> words){
        std::vector<std::byte> out;
        for(auto value:words)for(unsigned i=0;i<4;++i)out.push_back(std::byte((value>>(8*i))&255));
        return out;
    };
    const auto install=[&](unsigned value,bool counter){
        auto active=counter?bytes({1,0x02000110,0,77,0,0x02000166,9,27,value,0xa}):bytes({1,0x02000166,9,27,value,0xa});
        auto program=std::make_shared<const scene::Program>(std::vector{std::move(active),bytes({1,0xa})});
        check(owner.scripts().install(0,program,{0,0})==scene::Status::completed);
        check(owner.scripts().install(1,program,{1,0})==scene::Status::completed);
    };
    PausedWorkers workers;UnusedActors actors;install(31,false);
    check(owner.run_workers(workers,actors).status==update::Status::completed);
    check((workers.calls==std::vector<update::Worker>{update::Worker::reset_entity_queues,update::Worker::armed_request,update::Worker::clear_interaction_activity,update::Worker::clear_proxy_work}));
    check(source.session->enemy_descriptors.record(1)->parameter2e==31&&queue.pending()==1);
    check(queue.drain(8).consumed==1&&target.session->enemy_descriptors.record(1)->parameter2e==31);++owner_cases;
    install(42,true);RejectingSink foreign;foreign.ready=true;scene::Providers providers;providers.messages=&foreign;
    check(owner.run_workers(workers,actors,providers).status==update::Status::script_failure);
    check(owner.scripts().counters()[0]==0&&source.session->enemy_descriptors.record(1)->parameter2e==31&&!queue.pending()&&!foreign.calls);++owner_cases;
    providers.messages=&queue;
    check(owner.run_workers(workers,actors,providers).status==update::Status::completed);
    check(owner.scripts().counters()[0]==77&&source.session->enemy_descriptors.record(1)->parameter2e==42&&queue.pending()==1);
    check(queue.drain(8).consumed==1&&target.session->enemy_descriptors.record(1)->parameter2e==42);++owner_cases;
}
void comparisons(){
#ifdef REO_SCENE_RECORD_PARAMETERS_ORIGINAL
    Native source,target;update::ActorReception receiver(target.world);update::ActorMessageQueue queue(receiver,8);
    std::vector<std::uint8_t> memory(0x800000),remote(0x800000);owned_scene_record_receiver_table(remote.data());
    constexpr std::array<unsigned,7> counts{0,1,2,31,63,128,255};constexpr std::array<std::uint8_t,8> phases{0,1,2,3,127,128,254,255};
    constexpr std::array<std::uint8_t,5> modes{0,1,2,3,255};
    for(unsigned trial=0;trial<2240;++trial){
        context="sender "+std::to_string(trial);const auto count=counts[trial%counts.size()];populate(source,count,trial);
        source.session->message_phase=phases[(trial/7)%phases.size()];source.world.mode=modes[(trial/56)%modes.size()];
        target.session->message_phase=phases[(trial/5)%phases.size()];
        for(unsigned i=0;i<256;++i)target.session->enemy_descriptors.record(i)->parameter2e=std::uint8_t(i);
        export_records(source,memory);export_records(target,remote);packets.clear();
        const std::uint32_t condition=0xabcd0000u|std::uint8_t(trial),parameter=0x12340000u|std::uint8_t(trial*3u),value=0x98760000u|std::uint8_t(trial+17u);
        if(trial&1){for(unsigned i=0;i<3;++i)put(memory.data(),0x10000+4*i,std::array{condition,parameter,value}[i]);invoke(memory,o2_00694470_0x694470,{0x10000,0,0});++adapter_cases;}
        else {invoke(memory,o2_005A8F40_0x5a8f40,{condition,parameter,value});++sender_cases;}
        const auto result=scene::update_scene_record_parameter(source.world,condition,parameter,value,&queue);
        check(result.status==scene::SceneRecordParameterStatus::completed);compare_records(source,memory);
        check(queue.pending()==packets.size()&&result.notification_attempted==!packets.empty());
        for(const auto& p:packets){check(p.route==(source.world.mode==0?update::MessageRoute::mode_zero:update::MessageRoute::mode_one));
            remote[0x10000]=6;remote[0x10001]=6;remote[0x10004]=p.ordinal;remote[0x10005]=p.value;invoke(remote,o2_0067DD40_0x67dd40,{0x10000,0,0});++receiver_cases;}
        const auto drained=queue.drain(8);check(drained.status==update::ActorQueueStatus::completed&&drained.consumed==packets.size()&&!drained.pending);compare_records(target,remote);
    }
    // Reception has the full unsigned-byte index domain and no count/actor/
    // local-echo filters. Test both gates and high-bit phase bytes directly.
    for(unsigned trial=0;trial<8192;++trial){
        context="receiver "+std::to_string(trial);const auto index=std::uint8_t(trial);const auto phase=std::uint8_t((trial>>8)*8u+((trial>>5)&7u));
        target.session->message_phase=phase;export_records(target,remote);remote[0x10000]=6;remote[0x10001]=6;remote[0x10004]=index;remote[0x10005]=std::uint8_t(trial*17u);
        invoke(remote,o2_0067DD40_0x67dd40,{0x10000,0,0});
        check(receiver.receive(update::SceneRecordParameterMessage{update::MessageRoute::mode_one,index,std::uint8_t(trial*17u)},trial&1).status==update::ReceptionStatus::completed);
        compare_records(target,remote);++receiver_cases;
    }
#endif
}
}
#ifdef REO_SCENE_RECORD_PARAMETERS_ORIGINAL
PS2Runtime::Function PS2Runtime::lookupFunction(std::uint32_t at)const{
    switch(at){
#include "original_lookup.hpp"
    case 0x811190:case 0x810870:return +[](std::uint8_t* memory,R5900Context* c,PS2Runtime*){
        const auto p=GPR_U32(c,5);check(GPR_U32(c,4)==5&&GPR_U32(c,6)==0&&GPR_U32(c,7)==4&&memory[p]==6&&memory[p+1]==6);
        packets.push_back({c->pc==0x811190?update::MessageRoute::mode_zero:update::MessageRoute::mode_one,memory[p+4],memory[p+5]});c->pc=GPR_U32(c,31);
    };
    default:throw std::runtime_error("Unexecuted scene record oracle port "+std::to_string(at));
    }
}
#endif
int main()try{
    boundaries();owner_binding();comparisons();
    std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"sender_cases\":"<<sender_cases<<",\"adapter_cases\":"<<adapter_cases<<",\"receiver_cases\":"<<receiver_cases<<",\"queue_cases\":"<<queue_cases<<",\"owner_cases\":"<<owner_cases<<",\"game_launched\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
