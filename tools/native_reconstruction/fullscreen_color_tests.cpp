#include "game/native/gameplay_scenario/fullscreen_color.hpp"
#include "reference.hpp"
#include "functions.h"
#include <iostream>
#include <vector>
namespace s=reo::native::gameplay_scenario;
std::uint64_t checks{},calls{},cases{},samples{};unsigned current_case{};
void check(bool value){++checks;if(!value)throw std::runtime_error("Fullscreen color comparison case"+std::to_string(current_case));}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;switch(context->pc){
#include "original_dispatch.hpp"
    case 0x107c68:check(GPR_U32(context,4)==0x316600&&GPR_U32(context,5)==0&&GPR_U32(context,6)==24);std::fill_n(memory+0x316600,24,0);context->pc=GPR_U32(context,31);return;
    default:throw std::runtime_error("Unadmitted fullscreen color helper");}
}
std::uint32_t random_word(std::uint32_t& state){state^=state<<13;state^=state>>17;state^=state<<5;return state;}
template<class T>void put(std::vector<std::byte>& bytes,std::size_t at,T value){std::memcpy(bytes.data()+at,&value,sizeof value);}
int main(){
    static_assert(sizeof(s::FullscreenColorState)==24);std::vector<std::uint8_t> memory(0x2000000);PS2Runtime runtime;std::uint32_t random=0x1bbba0;
    const auto invoke=[&](unsigned address,unsigned a0=0){R5900Context context;context.pc=address;SET_GPR_U32(&context,4,a0);SET_GPR_U32(&context,29,0x700000);SET_GPR_U32(&context,31,0xabcdef);original_transform_port(memory.data(),&context,&runtime);check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x700000);};
    s::FullscreenColorState state;s::FullscreenColor color(state);
    for(unsigned index=0;index<131072;++index){
        current_case=index;const auto initial=random_word(random);invoke(0x1bbb10,initial);color.reset(initial);check(std::memcmp(&state,memory.data()+0x316600,sizeof state)==0);
        std::vector<std::byte> raw(33*40);const auto frame=std::uint16_t(random_word(random));const unsigned next=1+index%32;
        for(unsigned record=0;record<33;++record){
            put(raw,record*40+2,std::uint16_t(random_word(random)));put(raw,record*40+4,random_word(random)|4u);
            for(unsigned channel=0;channel<4;++channel)put(raw,record*40+8+channel*2,std::uint16_t(random_word(random)));
        }
        put(raw,2,frame);put(raw,4,index%5?2u:1u);
        if(index%11){put(raw,next*40+4,2u);put(raw,next*40+2,std::uint16_t(index%3==0?65535:index%3==1?frame:frame+1u+index%127));}
        std::memcpy(memory.data()+0x10000,raw.data(),raw.size());auto stream=s::FullscreenColorStream::import(raw);
        invoke(0x1bbb80,0x10000);check(color.bind(stream,0)==s::FullscreenColorStatus::completed);check(bool(color.binding())==bool(transform_read<unsigned>(memory.data(),0x38eb10)));
        const auto current_frame=random_word(random);transform_write(memory.data(),0x38eca8,current_frame);invoke(0x1bbba0);
        stream.reset();raw.clear();raw.shrink_to_fit();check(color.sample(current_frame)==s::FullscreenColorStatus::completed);check(std::memcmp(&state,memory.data()+0x316600,sizeof state)==0);++samples;++cases;
    }
    color.reset(0x12345678u);std::vector<std::byte> short_curve(40);put(short_curve,4,2u);
    check(color.bind(s::FullscreenColorStream::import(short_curve),0)==s::FullscreenColorStatus::completed);
    check(color.sample(0)==s::FullscreenColorStatus::unavailable&&state.rectangle.color==0x12345678u);
    check(color.bind({},0)==s::FullscreenColorStatus::unavailable&&color.binding()==0);
    put(short_curve,4,1u);check(color.bind(s::FullscreenColorStream::import(short_curve),0)==s::FullscreenColorStatus::completed);
    check(color.sample(0)==s::FullscreenColorStatus::unavailable&&state.rectangle.color==0x12345678u);
    short_curve.resize(39);bool refused{};try{(void)s::FullscreenColorStream::import(short_curve);}catch(const std::invalid_argument&){refused=true;}check(refused);
    color.reset(7);check(!color.binding()&&color.sample(0)==s::FullscreenColorStatus::completed&&state.rectangle.color==7);
    std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"samples\":"<<samples<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}
