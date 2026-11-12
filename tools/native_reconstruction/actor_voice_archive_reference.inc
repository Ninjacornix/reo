#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
namespace {
std::vector<std::uint8_t> memory(0x2000000);
const s::ActorVoiceArchiveAssets* original_assets{};
unsigned original_slot{},original_character{},original_opens{},original_poll{};
std::string text_at(unsigned at){check(at<memory.size());const auto begin=memory.begin()+at,end=std::find(begin,memory.end(),0);check(end!=memory.end()&&end-begin<512);return std::string(begin,end);}
void copied(unsigned destination,const std::string& value){check(destination<memory.size()&&value.size()+1<=memory.size()-destination);std::memcpy(memory.data()+destination,value.c_str(),value.size()+1);}
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++source_calls;const auto first=GPR_U32(context,4),second=GPR_U32(context,5);
    switch(context->pc){
#include "original_dispatch.hpp"
    case 0x10a830:{const auto format=text_at(second);check(format=="vo001%02d.afs");std::array<char,64> value{};const auto length=std::snprintf(value.data(),value.size(),format.c_str(),int(GPR_U32(context,6)));check(length>0&&length<int(value.size()));copied(first,value.data());SET_GPR_U32(context,2,unsigned(length));break;}
    case 0x10afc0:copied(first,text_at(second));SET_GPR_U32(context,2,first);break;
    case 0x10cda8:{auto value=text_at(first);for(auto& character:value)if(character>='a'&&character<='z')character=char(character-32);copied(first,value);SET_GPR_U32(context,2,first);break;}
    case 0x10b158:SET_GPR_U32(context,2,unsigned(text_at(first).size()));break;
    case 0x10ae78:SET_GPR_S32(context,2,text_at(first).compare(text_at(second)));break;
    case 0x128738:
        check(first==original_slot+5&&second==3&&GPR_U32(context,6)==401+original_character&&GPR_U32(context,7)==0x1000000+0x10c0*original_slot);
        check(original_assets&&original_character<8&&original_assets->archive(original_character)->count()==1000);++original_opens;original_poll=0;break;
    case 0x128b18:check(first==original_slot+5);++source_polls;SET_GPR_U32(context,2,++original_poll<3?original_poll:3);break;
    default:throw std::runtime_error("Undeclared actor archive source helper "+std::to_string(context->pc));
    }
    context->pc=GPR_U32(context,31);
}
void source_initialize(const s::ActorVoiceArchiveAssets& assets){
    original_assets=&assets;owned_constants(memory.data());const unsigned scratch=0x1000000;std::memcpy(memory.data()+0x324468,&scratch,4);
    for(unsigned i=0;i<8;++i)memory[0x4bae71+i]=std::uint8_t(41+i);
}
void source_call(unsigned entry){
    const std::array<std::uint8_t,3> guard{memory[0x4bae76],memory[0x4bae77],memory[0x4bae78]};R5900Context context;PS2Runtime runtime;context.pc=entry;SET_GPR_U32(&context,4,original_slot);SET_GPR_U32(&context,5,original_character);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xabcdef);original_opens=0;original_transform_port(memory.data(),&context,&runtime);
    check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x1f00000);
    check(std::memcmp(memory.data()+0x4bae76,guard.data(),3)==0);++source_cases;
}
void source_activate(s::StreamInstances&,unsigned slot,unsigned character){
    original_slot=slot;original_character=character;source_call(0x1ba440);check(original_opens==unsigned(slot<5&&character<8));
}
void source_clear(s::StreamInstances&){source_call(0x1ba330);}
void source_compare(s::StreamInstances& backend){for(unsigned i=0;i<5;++i){const auto value=backend.actor_archive_marker(std::uint8_t(i));check(value.status==s::StreamStatus::completed&&value.value==memory[0x4bae71+i]);}}
