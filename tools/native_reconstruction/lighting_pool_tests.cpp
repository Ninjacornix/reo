#include "game/native/gameplay_lighting/lights.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_light.hpp"
#include <iostream>
#include <source_location>
#include <string>
namespace l=reo::native::gameplay_lighting;
unsigned checks{},calls{},allocations{},retirements{},resets{},refusals{};
constexpr unsigned base=0x747540,stride=56;
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Lighting pool check "+std::to_string(checks)+" line "+std::to_string(at.line()));}
template<class T>T get(const std::uint8_t* m,unsigned at){return transform_read<T>(m,at);}
template<class T>void put(std::uint8_t* m,unsigned at,T value){transform_write(m,at,value);}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;const auto done=[&](){context->pc=GPR_U32(context,31);};
    switch(context->pc){
    case 0x107c68:{const auto dst=GPR_U32(context,4),n=GPR_U32(context,6);check(dst>=base&&dst<base+64*stride&&n==stride&&(dst-base)%stride==0&&GPR_U32(context,5)==0);std::memset(memory+dst,0,n);SET_GPR_U32(context,2,dst);done();return;}
    case 0x107ab0:{const auto dst=GPR_U32(context,4),src=GPR_U32(context,5),n=GPR_U32(context,6);check(dst>=base+4&&dst<base+64*stride&&(dst-base-4)%stride==0&&src==0x100000&&n==52);std::memcpy(memory+dst,memory+src,n);SET_GPR_U32(context,2,dst);done();return;}
#include "original_dispatch.hpp"
    default:throw std::runtime_error("Unadmitted lighting call "+std::to_string(context->pc));
    }
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#include "original.cpp"
#pragma GCC diagnostic pop
unsigned call(std::uint8_t* memory,unsigned pc,std::array<unsigned,3> args={}){R5900Context context;context.pc=pc;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x100);for(unsigned i=0;i<args.size();++i)SET_GPR_U32(&context,4+i,args[i]);PS2Runtime runtime;original_transform_port(memory,&context,&runtime);check(context.pc==0x100&&GPR_U32(&context,29)==0x1f00000);return GPR_U32(&context,2);}
std::array<std::uint8_t,52> encode(const l::Definition& value){std::array<std::uint8_t,52> bytes{};const auto put=[&](unsigned i,float f){const auto bits=std::bit_cast<std::uint32_t>(f);for(unsigned b=0;b<4;++b)bytes[4*i+b]=std::uint8_t(bits>>(8*b));};for(unsigned i=0;i<4;++i){put(i,value.vector0[i]);put(i+4,value.vector1[i]);}for(unsigned i=0;i<3;++i)put(i+8,value.position[i]);put(11,value.attenuation);put(12,value.parameter);return bytes;}
void compare(l::Pool& owner,std::uint8_t* memory){
    check(owner.size()==memory[0x747538]);const auto frame=owner.snapshot();check(frame.size()==owner.size());
    std::array<const l::FrameEntry*,64> entries{};for(const auto& entry:frame){const auto slot=owner.physical_slot(entry.id);check(slot&&!entries[*slot]);entries[*slot]=&entry;}
    for(unsigned i=0;i<64;++i){const auto raw=base+i*stride;check(bool(entries[i])==bool(memory[raw]));if(entries[i]){const auto& light=entries[i]->value;check(light.active&&light.tag==memory[raw+1]&&light.mode==memory[raw+2]);const auto bytes=encode(light.descriptor);check(std::memcmp(bytes.data(),memory+raw+4,52)==0);}else{for(unsigned b=0;b<56;++b)check(memory[raw+b]==0);}}
}
int main()try{
    std::vector<std::uint8_t> memory(0x2000000);reo::native::gameplay_scenario::Lighting canonical;l::Pool owner(canonical);std::array<l::LightId,64> ids;std::array<std::optional<l::Light>,64> leases;
    check(owner.bound_to(canonical));
    const auto create=[&](unsigned serial){std::array<std::uint8_t,52> bytes=owned_light;for(unsigned i=0;i<13&&serial%4;++i){const auto bits=serial*1664525u+i*1013904223u;for(unsigned b=0;b<4;++b)bytes[4*i+b]=std::uint8_t(bits>>(8*b));}const auto decoded=l::decode_definition(std::as_bytes(std::span(bytes)));check(encode(decoded)==bytes);const bool plain=serial%5==0,has_data=serial%3!=0;std::memcpy(memory.data()+0x100000,bytes.data(),bytes.size());const auto selector=std::uint8_t(serial*17),variant=std::uint8_t(serial*31);const auto original=call(memory.data(),plain?0x6b2fa0:0x6b3090,{plain||!has_data?0u:0x100000u,selector,variant});const auto actual=plain?owner.allocate():owner.create(has_data?std::optional(decoded):std::nullopt,selector,variant);check(bool(original)==bool(actual.id));if(original){const auto slot=owner.physical_slot(actual.id);check(slot&&original==base+*slot*stride&&actual.status==l::Status::completed&&actual.light&&owner.retain(actual.id));ids[*slot]=actual.id;leases[*slot]=actual.light;++allocations;}else check(actual.status==l::Status::full);check(owner.size()==canonical.primary_count());compare(owner,memory.data());};
    for(unsigned cycle=0;cycle<32;++cycle){
        for(unsigned i=0;i<64;++i)create(cycle*128+i);
        check(owner.size()==64);create(cycle*128+64);++refusals;
        const auto saved=owner.snapshot();for(unsigned i=cycle%3;i<64;i+=3){const auto original=call(memory.data(),0x6b3020,{base+i*stride});check(original==1&&owner.retire(ids[i])==l::Status::completed&&!owner.retain(ids[i])&&leases[i]->active);check(call(memory.data(),0x6b3020,{base+i*stride})==0&&owner.retire(ids[i])==l::Status::foreign_or_stale);++retirements;}
        for(const auto& entry:saved){check(entry.value.active);}
        compare(owner,memory.data());
        const auto holes=64-owner.size();for(unsigned i=0;i<holes;++i)create(cycle*128+65+i);
        for(unsigned i=0;i<64;++i){check(call(memory.data(),0x6b3020,{base+i*stride})==1);}
        check(owner.reset()==l::Status::completed);
        for(const auto& lease:leases){check(lease->active);}
        compare(owner,memory.data());++resets;
    }
    check(call(memory.data(),0x6b3020,{0})==0&&owner.retire({})==l::Status::foreign_or_stale);++refusals;
    create(10);reo::native::gameplay_scenario::Lighting other_canonical;l::Pool foreign(other_canonical);const auto other=foreign.allocate();check(other.status==l::Status::completed&&owner.retire(other.id)==l::Status::foreign_or_stale&&!owner.retain(other.id)&&!owner.bound_to(other_canonical));++refusals;compare(owner,memory.data());
    const auto first=ids[0];const auto updated=l::decode_definition(std::as_bytes(std::span(owned_light)));check(owner.replace(first,updated)==l::Status::completed);const auto encoded=encode(updated);std::memcpy(memory.data()+base+4,encoded.data(),encoded.size());compare(owner,memory.data());
    const auto direct=canonical.allocate(nullptr,123,1);check(direct&&*direct==1&&owner.size()==2);const auto direct_id=canonical.handle(*direct);check(direct_id&&owner.retain(*direct_id)&&owner.retain(*direct_id)->tag==123);check(call(memory.data(),0x6b3090,{0,123,1})==base+stride);compare(owner,memory.data());
    check(owner.retire(*direct_id)==l::Status::completed&&call(memory.data(),0x6b3020,{base+stride})==1);const auto reused=canonical.allocate(nullptr,99,0);check(reused&&*reused==1&&!owner.retain(*direct_id)&&!canonical.replace(*direct_id,updated));check(call(memory.data(),0x6b3090,{0,99,0})==base+stride);compare(owner,memory.data());++refusals;
    canonical.reset_work();check(!owner.retain(first)&&!owner.retain(*direct_id)&&owner.size()==0);check(call(memory.data(),0x6b3020,{base})==1&&call(memory.data(),0x6b3020,{base+stride})==1);create(10);check(ids[0]!=first&&!owner.retain(first));++refusals;
    bool rejected{};try{l::decode_definition(std::as_bytes(std::span(owned_light)).first(51));}catch(const std::invalid_argument&){rejected=true;}check(rejected);++refusals;owner.close();check(owner.closed()&&owner.size()==0&&owner.snapshot().empty()&&owner.allocate().status==l::Status::closed&&owner.create(updated,1,2).status==l::Status::closed&&owner.reset()==l::Status::closed&&owner.retire(first)==l::Status::closed&&owner.replace(first,updated)==l::Status::closed);++refusals;
    std::cout<<"{\"checks\":"<<checks<<",\"allocations\":"<<allocations<<",\"retirements\":"<<retirements<<",\"resets\":"<<resets<<",\"refusals\":"<<refusals<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
