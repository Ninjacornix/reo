#include "game/native/animation/facial_curves.hpp"
#include "reference.hpp"
#include "functions.h"
#include <fstream>
#include <iostream>
#include <source_location>
namespace a=reo::native::animation;
std::uint64_t checks{},calls{},updates{},samples{},retirements{},owned_updates{},batch_cases{};unsigned serial{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Facial curve case "+std::to_string(serial)+" line "+std::to_string(at.line()));
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;switch(context->pc){
#include "original_dispatch.hpp"
    default:throw std::runtime_error("Unadmitted facial curve source call "+std::to_string(context->pc));
    }
}
void invoke(std::uint8_t* memory){R5900Context context;PS2Runtime runtime;context.pc=0x67c6d0;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xabcdef);original_transform_port(memory,&context,&runtime);check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x1f00000);}
std::uint32_t random_word(std::uint32_t& value){value^=value<<13;value^=value>>17;value^=value<<5;return value;}
template<class T>void put(std::vector<std::byte>& bytes,unsigned offset,T value){std::memcpy(bytes.data()+offset,&value,sizeof value);}
int main(int argc,char** argv)try{
    check(argc==2);std::vector<std::uint8_t> memory(0x2000000);std::uint32_t random=0x67c6d0;
    const auto project=[&](const std::array<a::FacialCursor,8>& states,const std::vector<std::byte>& bytes){
        std::memcpy(memory.data()+0x400000,bytes.data(),bytes.size());
        for(unsigned slot=0;slot<8;++slot){const auto at=0x7448b0+32*slot;const auto& state=states[slot];std::fill_n(memory.data()+at,32,0);memory[at]=state.active;transform_write(memory.data(),at+4,state.active?0x1000000u+slot*0x1000:0u);transform_write(memory.data(),at+28,state.frame);
            for(unsigned channel=0;channel<5;++channel){const auto offset=transform_read<unsigned>(reinterpret_cast<const std::uint8_t*>(bytes.data()),channel*4);transform_write(memory.data(),at+8+4*channel,0x400000u+offset+unsigned(state.positions[channel])*8u);}
            transform_write(memory.data(),0x1000000+slot*0x1000+0x34,0x1100000u+slot*0x1000);transform_write(memory.data(),0x1100000+slot*0x1000,0x1200000u);transform_write(memory.data(),0x1100000+slot*0x1000+0x816,std::uint16_t(0));
        }
    };
    const auto compare=[&](std::array<a::FacialCursor,8>& states,const a::FacialCurves& curves,const std::vector<std::byte>& bytes){
        invoke(memory.data());std::optional<a::FacialWeights> expected;bool stopped=false;
        for(auto& state:states){if(!state.active)continue;const auto result=a::advance_facial_curves(state,curves);++updates;if(result.stop_batch){check(!result.weights);stopped=true;++retirements;break;}check(bool(result.weights));expected=result.weights;++samples;}
        for(unsigned slot=0;slot<8;++slot){const auto at=0x7448b0+32*slot;const auto& state=states[slot];check(bool(memory[at])==state.active&&transform_read<unsigned>(memory.data(),at+28)==state.frame);check(transform_read<unsigned>(memory.data(),at+4)==(state.active?0x1000000u+slot*0x1000:0u));
            for(unsigned channel=0;channel<5;++channel){const auto offset=transform_read<unsigned>(reinterpret_cast<const std::uint8_t*>(bytes.data()),channel*4);check(transform_read<unsigned>(memory.data(),at+8+4*channel)==0x400000u+offset+unsigned(state.positions[channel])*8u);}
        }
        if(expected&&!stopped)check(std::memcmp(expected->data(),memory.data()+0x1efffe0,24)==0);
    };
    for(serial=0;serial<65536;++serial){
        std::vector<std::byte> bytes(32);for(unsigned channel=0;channel<5;++channel){put(bytes,4*channel,unsigned(bytes.size()));const auto count=2u+random_word(random)%8;int time=int(random_word(random)%4);
            for(unsigned key=0;key<count;++key){const auto at=unsigned(bytes.size());bytes.resize(bytes.size()+8);put(bytes,at,time);put(bytes,at+4,float(int(random_word(random)%2001)-1000)/8.f);time+=1+int(random_word(random)%17);}
            const auto at=unsigned(bytes.size());bytes.resize(bytes.size()+8);put(bytes,at,std::int32_t(-1));put(bytes,at+4,0.f);
        }
        const auto curves=a::FacialCurves::import(bytes);std::array<a::FacialCursor,8> states;const auto active=random_word(random)&255u;
        for(unsigned slot=0;slot<8;++slot){states[slot].active=(active>>slot)&1u;states[slot].frame=serial%7==0?0xfffffffeu:serial%11==0?0x7ffffffeu:random_word(random)%128;for(unsigned channel=0;channel<5;++channel)states[slot].positions[channel]=random_word(random)%(curves->channel(channel).size()-1);}
        project(states,bytes);compare(states,*curves,bytes);++batch_cases;
    }
    std::ifstream corpus(argv[1],std::ios::binary);unsigned count{};corpus.read(reinterpret_cast<char*>(&count),4);check(corpus&&count==33);
    for(unsigned asset=0;asset<count;++asset){
        unsigned length{};corpus.read(reinterpret_cast<char*>(&length),4);check(corpus&&length>=20&&length<=65536);std::vector<std::byte> bytes(length);corpus.read(reinterpret_cast<char*>(bytes.data()),length);check(bool(corpus));const auto curves=a::FacialCurves::import(bytes);
        std::array<a::FacialCursor,8> states;for(auto& state:states)state.active=false;states[asset%8].active=true;project(states,bytes);
        for(unsigned tick=0;states[asset%8].active;++tick){serial=100000+asset;check(tick<65536);compare(states,*curves,bytes);++owned_updates;}
        compare(states,*curves,bytes);
    }
    std::cout<<"{\"checks\":"<<checks<<",\"batch_cases\":"<<batch_cases<<",\"updates\":"<<updates<<",\"samples\":"<<samples<<",\"retirements\":"<<retirements<<",\"owned_assets\":"<<count<<",\"owned_updates\":"<<owned_updates<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
