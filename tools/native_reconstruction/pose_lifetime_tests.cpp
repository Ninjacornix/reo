#include "game/native/gameplay_effects/pose_lifetime.hpp"
#include "reference.hpp"
#include "functions.h"
#include <iostream>
#include <source_location>
#include <stdexcept>
#include <vector>
namespace e=reo::native::gameplay_effects;
unsigned checks{},cases{},calls{},retirements{},updates{};
bool retired{};std::optional<std::uint8_t> updated;
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Pose lifetime "+std::to_string(at.line()));}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;
    if(context->pc==0x582b80){o2_00582B80_0x582b80(memory,context,runtime);return;}
    check(GPR_U32(context,4)==0x10000&&!updated&&!retired);
    switch(context->pc){
    case 0x582de0:retired=true;break;
    case 0x582df0:updated=0;break;case 0x582e30:updated=1;break;
    case 0x582f30:updated=2;break;case 0x583030:updated=6;break;
    case 0x583c50:updated=9;break;case 0x5840f0:updated=10;break;
    case 0x584160:updated=11;break;case 0x5831e0:updated=12;break;
    case 0x583430:updated=13;break;case 0x583550:updated=14;break;
    case 0x584250:updated=15;break;case 0x5835e0:updated=16;break;
    case 0x583730:updated=17;break;case 0x584500:updated=18;break;
    case 0x583bf0:updated=19;break;case 0x5846c0:updated=20;break;
    case 0x584760:updated=100;break;
    default:throw std::runtime_error("Undeclared pose update consumer "+std::to_string(context->pc));
    }
    context->pc=GPR_U32(context,31);
}
int main()try{
    std::vector<std::uint8_t> memory(0x2000000);
    // All byte kinds and every signed16 duration, including the wrap boundary
    // and negative durations which are not an immediate retirement request.
    for(unsigned kind=0;kind<256;++kind)for(unsigned bits=0;bits<65536;++bits){
        auto lifetime=std::bit_cast<std::int16_t>(std::uint16_t(bits));transform_write(memory.data(),0x10012,lifetime);memory[0x10004]=std::uint8_t(kind);retired=false;updated.reset();
        R5900Context context;PS2Runtime runtime;context.pc=0x582b80;SET_GPR_U32(&context,4,0x10000);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x1234);original_transform_port(memory.data(),&context,&runtime);
        check(context.pc==0x1234&&GPR_U32(&context,29)==0x1f00000);
        const auto step=e::advance_pose_lifetime(lifetime,std::uint8_t(kind));check(lifetime==transform_read<std::int16_t>(memory.data(),0x10012));check(step.retire==retired&&step.update==updated);
        retirements+=step.retire;updates+=bool(step.update);++cases;
    }
    std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"retirements\":"<<retirements<<",\"updates\":"<<updates<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
