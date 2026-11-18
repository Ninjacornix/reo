#include "reference.hpp"
#include "functions.h"
#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <vector>
#ifdef REO_COMPARE_NATIVE
#include "game/native/gameplay_presentation/session_presentation.hpp"
#endif

using Matrix=std::array<std::array<float,4>,4>;
static std::vector<Matrix> submitted;
static std::vector<std::uint32_t> draws;
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    switch(context->pc){
    case 0x18fdf0: return sub_0018FDF0_0x18fdf0(memory,context,runtime);
    case 0x1900e0: return sub_001900E0_0x1900e0(memory,context,runtime);
    case 0x191380: return sub_00191380_0x191380(memory,context,runtime);
    case 0x1919d0: return sub_001919D0_0x1919d0(memory,context,runtime);
    case 0x191280: return sub_00191280_0x191280(memory,context,runtime);
    case 0x1af780:
        if(GPR_U32(context,4)>=0x1a&&GPR_U32(context,4)<0x20)
            submitted.push_back(transform_read<Matrix>(memory,GPR_U32(context,5)));
        break;
    case 0x18c170: draws.push_back(GPR_U32(context,4)); break;
    case 0x3751b0: break;
    default: throw std::runtime_error("unexpected original resource draw callee");
    }
    context->pc=GPR_U32(context,31);
}
int main()try{
    std::vector<std::uint8_t> memory(0x2000000);constexpr unsigned object=0x10000;
    std::size_t checks{};unsigned calls{};
    for(unsigned count=0;count<=6;++count)for(unsigned trial=0;trial<16;++trial){
        std::fill(memory.begin(),memory.end(),0);submitted.clear();draws.clear();
        const unsigned root=trial%3;
        Matrix identity{};identity[0][0]=identity[1][1]=identity[2][2]=identity[3][3]=1;
        transform_write(memory.data(),0x294e00,identity);
        Matrix pose{};pose[0]={0,1,0,0};pose[1]={-1,0,0,0};pose[2]={0,0,1,0};pose[3]={0,0,0,1};
        transform_write(memory.data(),object+0x1c0,pose);
        const float pivot=float(trial)*0.25f;transform_write(memory.data(),object+0x218,pivot);
        const std::array<float,3> position{float(trial),float(-int(trial)),float(trial*2)};
        transform_write(memory.data(),object+0x200,position);
        transform_write(memory.data(),object+0x242,std::uint16_t(root));transform_write(memory.data(),0x3dbb14+2*root,std::uint16_t(count));
        transform_write(memory.data(),0x3c9a38,std::uint32_t(0x20000));
        for(unsigned i=0;i<3;++i)transform_write(memory.data(),0x20000+152*i,std::uint32_t(0x30000+16*i));
        for(unsigned i=0;i<count;++i){Matrix local{};local[0]={1,0,0,0};local[1]={0,1,0,0};local[2]={0,0,1,0};local[3]={float(i+1),float(i*2),float(-int(i)),1};
            Matrix bind{};bind[0]={1,0,0,0};bind[1]={0,1,0,0};bind[2]={0,0,1,0};bind[3]={float(i)+float(trial)*0.125f,0,0,1};
            transform_write(memory.data(),object+0x40+64*i,local);transform_write(memory.data(),0x3d2a50+384*root+64*i,bind);
        }
        R5900Context context;PS2Runtime runtime;SET_GPR_U32(&context,29,0x1fff000);SET_GPR_U32(&context,31,0x1000);SET_GPR_U32(&context,4,object);context.pc=0x3724f0;
        o0_003724F0_0x3724f0(memory.data(),&context,&runtime);
        if(context.pc!=0x1000||submitted.size()!=count||draws!=std::vector<std::uint32_t>{0x30000+16*root})throw std::runtime_error("resource draw call sequence or root selection differs");
        for(unsigned i=0;i<count;++i){const auto& m=submitted[i];
            const std::array<float,3> expected{position[0]-float(i*2),position[1]+float(i+1)-pivot+float(i)+float(trial)*0.125f,position[2]-float(i)};
            for(unsigned lane=0;lane<3;++lane)if(m[3][lane]!=expected[lane])throw std::runtime_error("resource draw transform differs");
            if(m[0][0]!=0||m[0][1]!=1||m[1][0]!=-1||m[1][1]!=0||m[2][2]!=1)throw std::runtime_error("resource draw basis differs");
            checks+=8;
        }
#ifdef REO_COMPARE_NATIVE
        if(count){
            auto parts=std::make_shared<reo::native::gameplay_world::ResourcePartPoses>();parts->count=1;
            parts->poses[0]=reo::native::transform_math::identity();parts->poses[0][3][0]=-float(trial)*0.125f;
            reo::native::gameplay_world::ResourceModel native(reo::native::transform_math::identity(),pose,
                {position[0],position[1],position[2]},0);
            native.base_parts=parts;native.parts[0]=transform_read<Matrix>(memory.data(),object+0x40);native.pulse_distance=pivot;
            const auto matrix=reo::native::gameplay_presentation::resource_model_matrix(native);
            for(unsigned column=0;column<4;++column)for(unsigned row=0;row<4;++row){
                if(!std::isfinite(matrix[column][row])||std::abs(matrix[column][row]-submitted[0][column][row])>0.0001f)
                    throw std::runtime_error("native matrix differs: count="+std::to_string(count)+" trial="+std::to_string(trial)+
                        " column="+std::to_string(column)+" row="+std::to_string(row)+" native="+std::to_string(matrix[column][row])+
                        " original="+std::to_string(submitted[0][column][row]));
                ++checks;
            }
        }
#endif
        ++calls;++checks;
    }
    std::fill(memory.begin(),memory.end(),0);submitted.clear();draws.clear();
    transform_write(memory.data(),object+0x242,std::uint16_t(65535));
    R5900Context skipped;PS2Runtime runtime;SET_GPR_U32(&skipped,29,0x1fff000);SET_GPR_U32(&skipped,31,0x1000);SET_GPR_U32(&skipped,4,object);skipped.pc=0x3724f0;
    o0_003724F0_0x3724f0(memory.data(),&skipped,&runtime);
    if(skipped.pc!=0x1000||!submitted.empty()||!draws.empty())throw std::runtime_error("missing root must not submit");
    ++calls;++checks;
    std::cout<<"{\"calls\":"<<calls<<",\"checks\":"<<checks<<",\"profile\":\"finite controlled rigid matrices\",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
