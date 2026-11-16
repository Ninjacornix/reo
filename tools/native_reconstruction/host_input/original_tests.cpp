#include "reference.hpp"
#include "functions.hpp"
#include "game/native/gameplay_actors/host_input.hpp"
#include <array>
#include <fstream>
#include <iostream>
#include <vector>

namespace {
using reo::native::gameplay_actors::input::AnalogPad;
std::uint64_t checks{},calls{};std::vector<std::uint8_t> memory(0x2000000);
void check(bool value){++checks;if(!value)throw std::runtime_error("original input fixture mismatch");}
template<class T>T get(unsigned at){return transform_read<T>(memory.data(),at);}
template<class T>void put(unsigned at,T value){transform_write(memory.data(),at,value);}
void load_elf(const char* path){
    std::ifstream file(path,std::ios::binary);if(!file)throw std::runtime_error("missing owned ELF");
    std::vector<std::uint8_t> bytes((std::istreambuf_iterator<char>(file)),{});
    const auto word=[&](unsigned at){std::uint32_t x;std::memcpy(&x,bytes.data()+at,4);return x;};
    const auto half=[&](unsigned at){std::uint16_t x;std::memcpy(&x,bytes.data()+at,2);return x;};
    const auto offset=word(28);for(unsigned i=0;i<half(44);++i){const auto at=offset+i*half(42);if(word(at)!=1)continue;
        const auto source=word(at+4),dest=word(at+8),size=word(at+16);
        check(source<=bytes.size()&&size<=bytes.size()-source&&dest<=memory.size()&&size<=memory.size()-dest);
        std::memcpy(memory.data()+dest,bytes.data()+source,size);
    }
}
void invoke(unsigned address){R5900Context context;PS2Runtime runtime;context.pc=address;
    SET_GPR_U32(&context,29,0x700000);SET_GPR_U32(&context,31,0x1000);
    original_transform_port(memory.data(),&context,&runtime);check(context.pc==0x1000);
}
void seed(){
    put(0x2affa8,0x2aff30u);put(0x2affac,0x2aff30u);std::fill_n(memory.data()+0x2aff30,120,0);
    std::memcpy(memory.data()+0x2b0900,memory.data()+0x231050,128);
    put(0x2b0a02,std::uint16_t(1));put(0x2b0a04,std::uint16_t(1));
    memory[0x2b0a10]=1;memory[0x2b0a30]=1;memory[0x2b0a31]=0x73;put(0x2b0a32,std::uint16_t(1));memory[0x3241f0]=1;
}
void compare(const AnalogPad& pad){
    memory[0x2b09e0]=0;put(0x2b09e2,std::uint16_t((pad.buttons<<8)|(pad.buttons>>8)));
    memory[0x2b09e4]=pad.right_x;memory[0x2b09e5]=pad.right_y;
    memory[0x2b09e6]=pad.left_x;memory[0x2b09e7]=pad.left_y;
    invoke(0x1a1b60);invoke(0x1b06f0);
    const auto native=reo::native::gameplay_actors::input::normalize_analog_pad(pad);
    if(native.held!=get<std::uint32_t>(0x324248)){
        std::cerr<<"buttons "<<std::hex<<pad.buttons<<" native "<<native.held<<" original "<<get<std::uint32_t>(0x324248)<<" raw "<<get<std::uint32_t>(0x2b0a38)<<" record "<<get<std::uint32_t>(0x2aff38)<<" state "<<unsigned(memory[0x2aff30])<<'/'<<get<std::uint16_t>(0x2aff32)<<" sample "<<get<std::uint16_t>(0x2b09e2)<<" map "<<get<std::uint32_t>(0x2b0970)<<std::dec<<'\n';check(false);
    }
    ++checks;
    for(unsigned i=0;i<8;++i){const auto expected=get<std::int16_t>(0x324260+2*i);
        if(native.analog[i]!=expected){std::cerr<<"axis "<<i<<" input "<<unsigned(pad.left_x)<<','<<unsigned(pad.left_y)<<' '<<unsigned(pad.right_x)<<','<<unsigned(pad.right_y)<<" native "<<native.analog[i]<<" original "<<expected<<" radians "<<std::hex<<get<std::uint32_t>(0x2aff54)<<' '<<get<std::uint32_t>(0x2aff60)<<std::dec<<'\n';check(false);}++checks;
    }
}
void routes(){
    // Exact cold offline controller count is one, and all skipped paths must
    // preserve the existing routing bytes. Actor record 1 is deliberately
    // active to check that an inactive record 0 does not scan ahead.
    for(unsigned present=0;present<2;++present)for(unsigned code:{0u,1u,0x8000u})
    for(unsigned active=0;active<2;++active)for(unsigned slot:{0u,3u,7u}){
        seed();memory[0x2aff30]=std::uint8_t(present);put(0x2aff32,std::uint16_t(code));
        std::fill_n(memory.data()+0x2b8e90,8,0x5a);memory[0x4a5c30]=std::uint8_t(active);
        memory[0x4a5c33]=std::uint8_t(slot);memory[0x4a6d10]=1;memory[0x4a6d13]=1;
        invoke(0x1b0ac0);
        for(unsigned i=0;i<8;++i)check(memory[0x2b8e90+i]==(present&&code==1&&active&&i==slot?0:0x5a));
    }
}
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;switch(context->pc){
#include "dispatch.hpp"
    case 0x1a6760:context->pc=GPR_U32(context,31);return; // OS pad already supplied.
    case 0x1a1970:{const auto at=GPR_U32(context,6);for(unsigned i=0;i<12;++i)memory[at+i]=0;context->pc=GPR_U32(context,31);return;}
    default:throw std::runtime_error("unadmitted input original dependency "+std::to_string(context->pc));
    }
}
int main(int argc,char** argv)try{
    check(argc==2);load_elf(argv[1]);routes();seed();AnalogPad pad;
    for(unsigned b=0;b<16;++b){pad.buttons=std::uint16_t(0xffffu^(1u<<b));compare(pad);}
    pad.buttons=0xffff;
    for(unsigned x=0;x<256;++x)for(unsigned y=0;y<256;++y){
        pad.left_x=std::uint8_t(x);pad.left_y=std::uint8_t(y);
        pad.right_x=std::uint8_t(255-x);pad.right_y=std::uint8_t(255-y);compare(pad);
    }
    std::cout<<"{\"checks\":"<<checks<<",\"original_calls\":"<<calls<<",\"axis_pairs\":65536,\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
