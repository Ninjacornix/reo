#include "game/native/gameplay_world/dialogue_inventory_traits.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>
namespace w=reo::native::gameplay_world;namespace s=reo::native::gameplay_scenario;
namespace {
std::vector<std::uint8_t> memory(0x2000000);std::uint64_t checks{},calls{},cases{},banks{};
void check(bool value){++checks;if(!value)throw std::runtime_error("Inventory trait source comparison case "+std::to_string(cases));}
template<class T>void put(unsigned at,T value){std::memcpy(memory.data()+at,&value,sizeof value);}
unsigned call(unsigned actor,unsigned selector){R5900Context state;PS2Runtime runtime;state.pc=0x5b5350;SET_GPR_U32(&state,4,actor);SET_GPR_U32(&state,5,selector);SET_GPR_U32(&state,29,0x1f00000);SET_GPR_U32(&state,31,0xabcdef);original_transform_port(memory.data(),&state,&runtime);check(state.pc==0xabcdef&&GPR_U32(&state,29)==0x1f00000);return GPR_U32(&state,2);}
void compare_bank(s::ResourceTemplates& templates,unsigned serial){
    ++banks;s::SceneResources resources;w::Actor actor;constexpr unsigned base=0x4a5c30;
    std::memcpy(memory.data()+0x74bb50,templates.state().templates.data(),129*24);
    for(unsigned id=0;id<256;++id){s::SceneDescriptor descriptor;descriptor.active=std::uint8_t(id%5==0?0:id%3==0?255:1);descriptor.template_index=std::uint8_t(id%13==0?255:(id+serial*17)%129);check(bool(resources.load(id,descriptor)));put(0x3c5630+60*id,descriptor.active);put(0x3c5630+60*id+43,descriptor.template_index);}
    for(unsigned character=0;character<256;++character)for(unsigned selector=0;selector<256;++selector){
        actor.character=std::uint8_t(character);put(base+0xb98,actor.character);
        for(unsigned i=0;i<actor.inventory.carried.size();++i)actor.inventory.carried[i]=std::uint8_t(character%7==0?0:character*7+i*37+serial);
        for(unsigned i=0;i<actor.inventory.storage.size();++i)actor.inventory.storage[i]=std::uint8_t(character%11==0?0:character*13+i*19+serial);
        std::memcpy(memory.data()+base+0xc84,actor.inventory.carried.data(),4);std::memcpy(memory.data()+base+0xc88,actor.inventory.storage.data(),32);
        const auto carried=actor.inventory.carried;const auto storage=actor.inventory.storage;const auto full=selector|((character+serial*11)<<8);
        const auto native=w::dialogue_inventory_trait(actor,&resources,&templates,full);const auto original=call(base,full);check(native&&std::uint32_t(*native)==original);check(actor.inventory.carried==carried&&actor.inventory.storage==storage);++cases;
    }
}
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){++calls;switch(context->pc){
#include "original_dispatch.hpp"
default:throw std::runtime_error("Undeclared inventory trait helper");}}
int main(int argc,char** argv)try{
    check(argc==2);owned_constants(memory.data());std::ifstream input(argv[1],std::ios::binary);unsigned count{};input.read(reinterpret_cast<char*>(&count),4);check(input&&count==5);
    for(unsigned i=0;i<count;++i){unsigned size{};input.read(reinterpret_cast<char*>(&size),4);check(size&&size<65536);std::vector<std::byte> bytes(size);input.read(reinterpret_cast<char*>(bytes.data()),size);check(bool(input));s::ResourceTemplates templates;check(templates.load(bytes));compare_bank(templates,i);}
    std::vector<std::byte> controlled(32+129*24);const auto encoded=[&](unsigned at,auto value){std::memcpy(controlled.data()+at,&value,sizeof value);};encoded(0,3u);encoded(4,129u);encoded(16,32u);
    for(unsigned i=0;i<129;++i){encoded(32+24*i,std::uint32_t(i%7==0?1:i%7==1?0xc02:i%7==2?4:i%7==3?0x208:i%7==4?0x10:0xffffffffu));controlled[32+24*i+10]=std::byte(i%3==0?0:i%3==1?1:16);}
    s::ResourceTemplates templates;check(templates.load(controlled));compare_bank(templates,5);
    w::Actor actor;check(w::dialogue_inventory_trait(actor,nullptr,nullptr,255)==false);check(w::dialogue_inventory_trait(actor,nullptr,nullptr,0)==false);
    actor.inventory.storage[0]=1;check(w::dialogue_inventory_trait(actor,nullptr,nullptr,5)==true);actor.inventory.carried[0]=1;check(!w::dialogue_inventory_trait(actor,nullptr,nullptr,0));
    s::SceneResources resources;check(w::dialogue_inventory_trait(actor,&resources,nullptr,0)==false);s::SceneDescriptor active;active.active=1;active.template_index=0;check(bool(resources.load(1,active)));check(!w::dialogue_inventory_trait(actor,&resources,nullptr,0));active.template_index=200;check(bool(resources.load(1,active)));check(!w::dialogue_inventory_trait(actor,&resources,&templates,0));
    std::cout<<"{\"checks\":"<<checks<<",\"complete_original_cases\":"<<cases<<",\"source_calls\":"<<calls<<",\"owned_template_banks\":5,\"controlled_template_banks\":1,\"capability_checks\":7,\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
