#include "scene_primary_actors.hpp"
#include "auxiliary_actors.hpp"
#include "actor_assets.hpp"
#include "../animation/playback.hpp"
#include "runtime/assets/virtual_afs.h"
#include <cstring>
#include <iostream>
#include <source_location>
#include <stdexcept>
namespace g=reo::native::gameplay_world;
namespace {
std::uint64_t checks{},original_cases{},guard_checks{},capacity_cases{},model_refusals{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error(std::string("Scene primary check ")+at.file_name()+":"+std::to_string(at.line()));
}
g::Profile profile(unsigned capacity=1024){g::Profile p;p.layouts.push_back({});p.entities.capacity=capacity;return p;}
}
#ifdef REO_SCENE_PRIMARY_ORIGINAL
#include "scene_primary_reference.hpp"
namespace {
std::vector<std::uint8_t> memory(0x2000000);
constexpr unsigned base=0xb1f000;
unsigned clears{},objects{};
void invoke(unsigned at){
    R5900Context c;PS2Runtime runtime;c.pc=at;SET_GPR_U32(&c,29,0x1f00000);SET_GPR_U32(&c,31,0xabcdef);
    if(at==0x5f1290)o2_005F1290_0x5f1290(memory.data(),&c,&runtime);
    else o2_005F1330_0x5f1330(memory.data(),&c,&runtime);
    check(c.pc==0xabcdef&&GPR_U32(&c,29)==0x1f00000);
}
void compare_masks(g::World& world,g::ScenePrimaryActorPool& pool){
    transform_write(memory.data(),0x32440c,0x800000u);clears=objects=0;invoke(0x5f1290);
    check(clears==9&&objects==1&&transform_read<unsigned>(memory.data(),0x38edd0)==base);
    for(unsigned i=0;i<8;++i){
        const auto actor=world.resolve(pool.identity_at(i));check(actor&&!actor->active&&!actor->visible&&actor->category==0&&actor->slot==i);
        check(actor->motion_rate==0&&actor->model_scale.x==0&&actor->model_scale.y==0&&actor->model_scale.z==0&&actor->motion_multiplier==0);
        check(!actor->model&&!actor->animation&&!actor->constraints&&!actor->primary_state&&!actor->scripted);
        check(actor->secondary_pose_category_override==0&&actor->secondary_pose_history.has_value());
        for(const auto& v:actor->secondary_pose_history->displacement)check(v.x==0&&v.y==0&&v.z==0);
        for(unsigned byte=0;byte<0x10e0;++byte)check(memory[base+i*0x10e0+byte]==(byte==3?i:0));
    }
    for(unsigned encoding:{1u,2u,128u,255u})for(unsigned mask=0;mask<256;++mask){
        for(unsigned i=0;i<8;++i){auto actor=world.resolve(pool.identity_at(i));actor->active=bool(mask&(1u<<i));actor->slot=77;memory[base+i*0x10e0]=actor->active?std::uint8_t(encoding):0;memory[base+i*0x10e0+3]=77;}
        const auto result=pool.find_inactive();R5900Context c;PS2Runtime runtime;c.pc=0x5f1330;SET_GPR_U32(&c,31,0xabcdef);
        o2_005F1330_0x5f1330(memory.data(),&c,&runtime);check(c.pc==0xabcdef);
        const auto found=GPR_U32(&c,2);check(bool(result.id)==bool(found));
        check(result.status==(found?g::ScenePrimaryStatus::completed:g::ScenePrimaryStatus::full));
        if(found){const auto index=(found-base)/0x10e0;check(result.slot==index&&result.id==pool.identity_at(index));check(pool.find_inactive().id==result.id&&!world.resolve(result.id)->active);}
        for(unsigned i=0;i<8;++i)check(world.resolve(pool.identity_at(i))->slot==memory[base+i*0x10e0+3]);
        ++original_cases;
    }
    transform_write(memory.data(),0x38edd0,0u);R5900Context c;PS2Runtime runtime;SET_GPR_U32(&c,31,0xabcdef);o2_005F1330_0x5f1330(memory.data(),&c,&runtime);check(GPR_U32(&c,2)==0);++original_cases;
}
}
void original_transform_port(std::uint8_t* m,R5900Context* c,PS2Runtime*){
    if(c->pc==0x107c68){const auto at=GPR_U32(c,4),size=GPR_U32(c,6);check(GPR_U32(c,5)==0&&at<0x2000000&&size<=0x2000000-at);std::memset(m+at,0,size);SET_GPR_U32(c,2,at);++clears;}
    else if(c->pc==0x571010){check(GPR_U32(c,4)==base+8*0x10e0);++objects;}
    else throw std::runtime_error("Undeclared scene primary source port");
    c->pc=GPR_U32(c,31);
}
#endif
namespace {
void lifecycle(){
    g::World world(profile(),std::make_shared<g::Session>());auto& pool=world.scene_primary_actors();
    check(!pool.initialized()&&!pool.identity_at(0)&&pool.find_inactive().status==g::ScenePrimaryStatus::uninitialized);
    const auto main=world.spawn_primary(0,std::make_unique<g::Actor>()).id;const auto auxiliary=world.auxiliary_actors().allocate(0).id;
    check(!world.resolve(main)->secondary_pose_history&&!world.resolve(main)->secondary_pose_category_override);
    check(world.resolve(auxiliary)->secondary_pose_history.has_value()&&world.resolve(auxiliary)->secondary_pose_category_override==0);
    check(pool.initialize()==g::ScenePrimaryStatus::completed&&pool.initialized()&&!pool.identity_at(8));
    check(!pool.physical_slot(main)&&!pool.physical_slot(auxiliary)&&world.identity(0)==main);
    g::World foreign(profile(),std::make_shared<g::Session>());check(foreign.scene_primary_actors().initialize()==g::ScenePrimaryStatus::completed);
    check(!pool.physical_slot(foreign.scene_primary_actors().identity_at(0)));
    for(unsigned i=0;i<8;++i){const auto id=pool.identity_at(i);check(world.resolve(id)&&pool.physical_slot(id)==i&&id!=main&&id!=auxiliary);check(world.retire_linked(id)==g::actors::EntityStatus::invalid);}
#ifdef REO_SCENE_PRIMARY_ORIGINAL
    compare_masks(world,pool);
#endif
    const auto old_id=pool.identity_at(0);auto old=world.resolve(old_id);old->character=42;old->secondary_pose_category_override=43;old->secondary_pose_history->displacement[1]={1,2,3};
    check(pool.initialize()==g::ScenePrimaryStatus::completed&&!world.resolve(old_id)&&old->character==42&&pool.identity_at(0)!=old_id&&!pool.physical_slot(old_id));
    check(world.resolve(pool.identity_at(0))->secondary_pose_category_override==0&&world.resolve(pool.identity_at(0))->secondary_pose_history->displacement[1].x==0&&old->secondary_pose_category_override==43&&old->secondary_pose_history->displacement[1].x==1);
    // An asset lease can have external ownership callbacks. They must observe
    // the complete new pool while recursive mutation is refused.
    for(unsigned repetition=0;repetition<32;++repetition){
        const auto id=pool.identity_at(0);auto token=std::shared_ptr<int>(new int(1),[&,id](int* p){
            delete p;check(world.busy()&&pool.busy()&&!world.resolve(id)&&pool.identity_at(0)!=id);
            check(pool.initialize()==g::ScenePrimaryStatus::busy&&pool.find_inactive().status==g::ScenePrimaryStatus::busy&&pool.close()==g::ScenePrimaryStatus::busy&&world.close()==g::Status::busy);++guard_checks;
        });
        world.resolve(id)->model_asset=std::shared_ptr<const g::ActorModelAsset>(token,nullptr);
        // Release the test's token before reset; only the old Actor owns it.
        token.reset();
        check(pool.initialize()==g::ScenePrimaryStatus::completed);
    }
    check(world.resolve(main)&&world.resolve(auxiliary)&&world.identity(0)==main);
    const auto last=pool.identity_at(0);check(world.close()==g::Status::completed&&!world.resolve(last)&&!pool.identity_at(0));
    check(pool.initialize()==g::ScenePrimaryStatus::closed&&pool.find_inactive().status==g::ScenePrimaryStatus::closed&&pool.close()==g::ScenePrimaryStatus::completed);
}
void capacity(){
    for(unsigned limit=1;limit<=23;++limit){
        g::World world(profile(limit),std::make_shared<g::Session>());auto& pool=world.scene_primary_actors();const auto first=pool.initialize();
        if(limit<8){check(first==g::ScenePrimaryStatus::entity_capacity&&!pool.initialized()&&!pool.identity_at(0));const auto id=world.spawn_primary(0,std::make_unique<g::Actor>()).id;check(bool(id));}
        else{check(first==g::ScenePrimaryStatus::completed);std::array<g::actors::EntityId,8> before;for(unsigned i=0;i<8;++i){before[i]=pool.identity_at(i);world.resolve(before[i])->character=std::uint8_t(i+20);}
            const auto reset=pool.initialize();check(reset==(limit<16?g::ScenePrimaryStatus::entity_capacity:g::ScenePrimaryStatus::completed));
            for(unsigned i=0;i<8;++i)if(limit<16)check(pool.identity_at(i)==before[i]&&world.resolve(before[i])->character==i+20);else check(pool.identity_at(i)!=before[i]&&!world.resolve(before[i]));
        }++capacity_cases;
    }
}
void close_lifetime(){
    for(bool whole_world:{false,true}){
        g::World world(profile(),std::make_shared<g::Session>());auto& pool=world.scene_primary_actors();check(pool.initialize()==g::ScenePrimaryStatus::completed);
        const auto id=pool.identity_at(0);auto token=std::shared_ptr<int>(new int(1),[&,id](int* p){
            delete p;check(world.busy()&&pool.busy()&&!world.resolve(id)&&!pool.identity_at(0));
            check(pool.initialize()==g::ScenePrimaryStatus::closed&&pool.find_inactive().status==g::ScenePrimaryStatus::closed&&pool.close()==g::ScenePrimaryStatus::completed&&world.close()==g::Status::busy);++guard_checks;
        });
        world.resolve(id)->model_asset=std::shared_ptr<const g::ActorModelAsset>(token,nullptr);token.reset();
        if(whole_world)check(world.close()==g::Status::completed);else check(pool.close()==g::ScenePrimaryStatus::completed);
        check(!pool.identity_at(0)&&!world.resolve(id)&&!world.busy());
    }
}
void owned(const char* archive){
    auto source=std::make_shared<reo::assets::Source>(archive);g::ActorAssets assets(source);const auto asset=assets.read_primary(0,0,0);check(asset&&asset->skeleton());
    g::World world(profile(),std::make_shared<g::Session>());auto& pool=world.scene_primary_actors();check(pool.initialize()==g::ScenePrimaryStatus::completed);
    const auto id=pool.identity_at(3);check(g::bind_actor_model_asset(world,id,asset));const auto actor=world.resolve(id);const auto old_model=actor->model;
    check(pool.initialize()==g::ScenePrimaryStatus::model_in_use&&pool.close()==g::ScenePrimaryStatus::model_in_use&&pool.identity_at(3)==id&&actor->model==old_model);model_refusals+=2;
    actor->model.reset();check(pool.initialize()==g::ScenePrimaryStatus::model_in_use);++model_refusals;
    actor->animation.reset();check(pool.initialize()==g::ScenePrimaryStatus::completed&&!world.resolve(id)&&bool(old_model));
    check(g::bind_actor_model_asset(world,pool.identity_at(0),asset));check(world.close()==g::Status::completed&&!pool.identity_at(0));
}
}
int main(int argc,char** argv){try{lifecycle();capacity();close_lifetime();if(argc==2)owned(argv[1]);std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"original_cases\":"<<original_cases<<",\"guard_checks\":"<<guard_checks<<",\"capacity_cases\":"<<capacity_cases<<",\"model_refusals\":"<<model_refusals<<",\"game_run\":false}\n";return 0;}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}}
