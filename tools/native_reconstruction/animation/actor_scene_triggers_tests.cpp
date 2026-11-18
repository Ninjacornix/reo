#include "game/native/gameplay_world/actor_scene_triggers.hpp"
#include "game/native/gameplay_scenario/scene_model_bindings.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <iostream>
#include <source_location>
namespace w=reo::native::gameplay_world;namespace s=reo::native::gameplay_scenario;namespace scene=reo::native::gameplay_scene;
std::uint64_t checks{},calls{},cases{},triggered{},refusals{};unsigned fixture{};
void check(bool condition,std::source_location at=std::source_location::current()){++checks;if(!condition)throw std::runtime_error("Actor scene trigger "+std::to_string(fixture)+" line "+std::to_string(at.line()));}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){++calls;switch(context->pc){
#include "original_dispatch.hpp"
default:throw std::runtime_error("Undeclared trigger source call "+std::to_string(context->pc));}}
void invoke(std::uint8_t* memory){R5900Context c;PS2Runtime runtime;c.pc=0x581870;SET_GPR_U32(&c,4,0x200000);SET_GPR_U32(&c,29,0x1f00000);SET_GPR_U32(&c,31,0xabcdef);original_transform_port(memory,&c,&runtime);check(c.pc==0xabcdef&&GPR_U32(&c,29)==0x1f00000);}
struct Located {scene::RecordId id;unsigned address;};
int main()try{
    _mm_setcsr(0x1f80);std::vector<std::uint8_t> memory(0x2000000);owned_constants(memory.data());
    for(unsigned seed=0;seed<512;++seed){fixture=seed;w::Profile profile;profile.layouts.push_back({});w::World world(profile,std::make_shared<w::Session>());world.mode=std::uint8_t(seed%4);world.selected_actor=std::uint8_t(seed%7);world.room=std::uint16_t(seed%128);auto actor=std::make_unique<w::Actor>();actor->category=std::uint8_t((seed/4)%4);actor->slot=std::uint8_t((seed/3)%7);actor->position={float(int(seed%23)-11)*12.25f,float(int(seed%11)-5)*50.f,float(int(seed%17)-8)*15.5f};actor->auxiliary_status=seed;const auto created=world.spawn_primary(0,std::move(actor));const auto live=world.resolve(created.id);check(bool(live));
        auto records=std::make_shared<scene::Records>();s::SceneControls controls(records);s::SceneModelState model_state;s::RoomModelRemap remap{};s::SceneModels models(model_state,remap);reo::native::gameplay_actors::EntityStore objects;s::SceneModelBindings bindings(models,objects);s::FlagState flags;auto flag_state=flags.snapshot();for(auto& row:flag_state.strided)for(auto& word:row)word=std::uint16_t(seed*717);flags.restore(flag_state);s::SceneMatrixPrograms::State states;for(unsigned i=0;i<16;++i){states[i].contact.gate=std::uint8_t((i+seed)%4);states[i].interaction=std::uint8_t(seed+i*7);}s::SceneMatrixPrograms programs(controls,models,bindings,flags,world.room,states);
        std::vector<Located> located;for(unsigned i=0;i<16;++i){scene::Record parent;parent.authored_id=i;parent.body=s::ControlTypeTwo{};const auto parent_id=records->create(parent);check(bool(parent_id));located.push_back({*parent_id,0x250000+unsigned(located.size())*256});scene::Record helper;helper.body=s::ControlOther{0x85};helper.enabled=std::uint8_t(i%2);helper.source=*parent_id;helper.collision=scene::CollisionShape{{{{-150+int(i)*5,-170},{150+int(i)*5,-170},{150+int(i)*5,170},{-150+int(i)*5,170}}},int(i%3)*50-50,int(i%5)*100-100,1,false,{}};const auto id=records->create(helper);check(bool(id));located.push_back({*id,0x250000+unsigned(located.size())*256});}
        const auto address=[&](const scene::RecordId& id){for(const auto& item:located)if(item.id==id)return item.address;return 0u;};
        transform_write(memory.data(),0x3b5150,std::uint16_t(128-records->size()));transform_write(memory.data(),0x3b5160,address(records->first()->id));transform_write(memory.data(),0x3243dc,world.room);memory[0x3243f2]=world.mode;memory[0x4baded]=world.selected_actor;memory[0x200002]=live->category;memory[0x200003]=live->slot;transform_write(memory.data(),0x200038,live->position);transform_write(memory.data(),0x200ba4,live->auxiliary_status);std::memcpy(memory.data()+0x4b9e20,flag_state.strided.data(),sizeof flag_state.strided);
        for(unsigned i=0;i<16;++i){memory[0x4a3621+96*i]=states[i].contact.gate;memory[0x4a3622+96*i]=states[i].interaction;}
        for(auto node=records->first();node;node=node->next){const auto at=address(node->id);const auto& value=node->value;memory[at+0x30]=scene::kind(value.body);transform_write(memory.data(),at+0x28,node->next?address(node->next->id):0u);transform_write(memory.data(),at+0x34,0u);transform_write(memory.data(),at+0x40,value.source?address(value.source):value.authored_id);if(value.collision){transform_write(memory.data(),at,value.collision->bounds);transform_write(memory.data(),at+0x20,value.collision->lower);transform_write(memory.data(),at+0x24,value.collision->upper);}}
        invoke(memory.data());const auto report=w::update_actor_scene_triggers(world,*live,*records,programs,flags);check(report.status==w::ActorSceneTriggerStatus::completed&&report.visited==32);triggered+=report.triggered;check(live->auxiliary_status==transform_read<unsigned>(memory.data(),0x200ba4));check(std::memcmp(memory.data()+0x4b9e20,flags.snapshot().strided.data(),sizeof flag_state.strided)==0);
        for(unsigned i=0;i<16;++i){check(programs.inspect(i)->interaction==memory[0x4a3622+96*i]);}
        for(const auto& item:located){const auto node=records->acquire(item.id);check(bool(node));const auto expected=transform_read<unsigned>(memory.data(),item.address+0x34);check((node->value.owner==created.id)==(expected==0x200000));}
        if(seed==0){s::FlagState foreign;check(w::update_actor_scene_triggers(world,*live,*records,programs,foreign).status==w::ActorSceneTriggerStatus::unavailable);++refusals;const auto retained=records->acquire(located.back().id);const auto previous=retained->value.owner;check(records->retire(located.back().id)&&retained->value.owner==previous);check(world.retire_primary(0)==w::actors::EntityStatus::completed&&!world.resolve(created.id));check(retained->value.owner==previous);}
        ++cases;
    }
    std::cout<<"{\"checks\":"<<checks<<",\"complete_cases\":"<<cases<<",\"triggered\":"<<triggered<<",\"refusals\":"<<refusals<<",\"source_calls\":"<<calls<<"}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
