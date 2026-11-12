#include "game/native/gameplay_scenario/cutscene_light_curves.hpp"
#include "reference.hpp"
#include "functions.h"
#include <iostream>
#include <source_location>
#include <vector>
namespace s=reo::native::gameplay_scenario;
std::uint64_t checks{},calls{},cases{},samples{},mirrors{},floor_calls{};unsigned serial{};std::uint8_t material{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Light curve case "+std::to_string(serial)+" line "+std::to_string(at.line()));}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;switch(context->pc){
#include "original_dispatch.hpp"
    case 0x107ab0:check(GPR_U32(context,6)==52);std::memcpy(memory+GPR_U32(context,4),memory+GPR_U32(context,5),52);context->pc=GPR_U32(context,31);return;
    case 0x617000:check(GPR_U32(context,8)==255&&GPR_U32(context,11)==0);transform_write(memory,GPR_U32(context,9),material);context->f[0]=-999.f;context->pc=GPR_U32(context,31);++floor_calls;return;
    default:throw std::runtime_error("Unadmitted light curve source call "+std::to_string(context->pc));
    }
}
std::uint32_t random_word(std::uint32_t& state){state^=state<<13;state^=state>>17;state^=state<<5;return state;}
float scalar(std::uint32_t& state){return float(std::int32_t(random_word(state)%200001)-100000)/128.f;}
void store_key(std::uint8_t* memory,unsigned at,const s::CutsceneLightKey& key){
    transform_write(memory,at+1,key.enabled);transform_write(memory,at+2,key.frame);transform_write(memory,at+4,key.flags);transform_write(memory,at+6,key.binding);transform_write(memory,at+8,key.point);transform_write(memory,at+20,key.control);transform_write(memory,at+32,key.radius);transform_write(memory,at+36,key.first);transform_write(memory,at+40,key.second);transform_write(memory,at+44,key.extra);
}
int main()try{
    static_assert(sizeof(s::LightDescriptor)==52&&sizeof(s::NativeLight)==56);
    std::vector<std::uint8_t> memory(0x2000000);std::uint32_t random=0x6b3bb0;
    const auto invoke=[&](unsigned address,unsigned a0=0,unsigned a1=0){R5900Context context;PS2Runtime runtime;context.pc=address;SET_GPR_U32(&context,4,a0);SET_GPR_U32(&context,5,a1);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xabcdef);original_transform_port(memory.data(),&context,&runtime);check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x1f00000);};
    for(serial=0;serial<131072;++serial){
        s::CutsceneLightSegment segment;const auto fill=[&](auto& key){key.enabled=std::int8_t(random_word(random));key.flags=std::uint16_t(random_word(random));key.point={scalar(random),scalar(random),scalar(random)};key.control={scalar(random),scalar(random),scalar(random)};key.radius=scalar(random);key.extra=scalar(random);for(unsigned lane=0;lane<3;++lane){key.first[lane]=std::uint8_t(random_word(random));key.second[lane]=std::uint8_t(random_word(random));}};
        fill(segment.current);fill(segment.next);segment.current.frame=std::uint16_t(random_word(random));segment.next.frame=std::array<std::uint16_t,8>{0,1,2,3,65534,65535,segment.current.frame,std::uint16_t(segment.current.frame+200)}[serial%8];segment.current.binding=0;
        material=std::uint8_t(serial);const auto group=serial%32;const auto clock=std::uint8_t(serial%3==0?0:serial%3==1?1:255);std::uint32_t frame=std::array<unsigned,8>{0,1,0xffffffffu,0x80000000u,0x7fffffffu,100,65535,100000}[serial%8];
        s::NativeLight light{1,77,0,85,{}};light.descriptor.position={33,44,55};s::NativeLight auxiliary{1,88,9,99,{}};
        constexpr unsigned primary=0xc00000,mirror=0xc00100,records=0xd00000,end=0xd00100;
        transform_write(memory.data(),primary,light);transform_write(memory.data(),mirror,auxiliary);transform_write(memory.data(),0x747430+4*group,primary);transform_write(memory.data(),0x747420,mirror);transform_write(memory.data(),0x3243cc,clock);
        store_key(memory.data(),records,segment.current);store_key(memory.data(),records+48,segment.next);
        const auto end_enabled=std::int8_t(serial%4?1:0);transform_write(memory.data(),end+1,end_enabled);transform_write(memory.data(),end+6,std::int16_t(serial%2?1:-1));
        invoke(0x6b38d0);for(unsigned slot=0;slot<32;++slot)check(transform_read<std::uint64_t>(memory.data(),0x38eb20+8*slot)==0);
        invoke(0x6b3900,records,group);s::initialize_cutscene_light(light,segment.current,material);
        check(std::memcmp(&light,memory.data()+primary,sizeof light)==0&&transform_read<unsigned>(memory.data(),0x38eb20+8*group)==records);
        invoke(0x6b3900,end,group);check(transform_read<unsigned>(memory.data(),0x38eb24+8*group)==end);
        // Existing W lanes survive every evaluator update, including fixed keys.
        light.descriptor.vector0[3]=scalar(random);light.descriptor.vector1[3]=scalar(random);transform_write(memory.data(),primary,light);
        for(unsigned tick=0;tick<4;++tick){
            material=std::uint8_t(serial+tick);transform_write(memory.data(),0x38eca8,frame);invoke(0x6b3bb0,group);
            const auto copied=s::sample_cutscene_light(light,segment,end_enabled,frame,clock,material);
            if(copied){auxiliary.tag=light.tag;auxiliary.descriptor=*copied;++mirrors;}
            check(std::memcmp(&light,memory.data()+primary,sizeof light)==0);check(std::memcmp(&auxiliary,memory.data()+mirror,sizeof auxiliary)==0);frame+=clock?2u:1u;++samples;
        }
        invoke(0x6b38d0);const auto before=light;invoke(0x6b3bb0,group);check(std::memcmp(&before,memory.data()+primary,sizeof before)==0);++cases;
    }
    std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"samples\":"<<samples<<",\"auxiliary_mirrors\":"<<mirrors<<",\"floor_calls\":"<<floor_calls<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
