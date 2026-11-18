#include "reference.hpp"
#include "functions.h"
#include <iostream>
#include <map>
#include <limits>
#include <vector>
namespace {
constexpr unsigned stack_end=0x1f00000,frame_begin=stack_end-0x9340;
std::vector<std::uint8_t> memory(0x2000000);std::array<bool,0x9340> known;
R5900Context* active_context{};
std::uint64_t unknown_reads{},port_calls{},checks{};
std::map<unsigned,std::uint64_t> unknown_pcs;
void check(bool value){++checks;if(!value)throw std::runtime_error("Cache scratch audit check "+std::to_string(checks));}
template<class T>void put(unsigned at,T value){std::memcpy(memory.data()+at,&value,sizeof(value));}
struct XYZ{float x,y,z;};
XYZ read_position(unsigned at){XYZ result;std::memcpy(&result,memory.data()+at,sizeof result);return result;}
void actor(unsigned at,unsigned index,bool active,unsigned model){
    memory[at]=active?1:0;memory[at+3]=std::uint8_t(index);put(at+0x1e2,std::uint16_t(7));
    put(at+0x38,XYZ{float(100*index),float(10*index),float(300+index*10)});put(at+0x34,model);put(model+0x84c,model+0x900);put(model+0x930,XYZ{float(100*index),float(10*index+50),float(300+index*10)});
}
struct Result{std::vector<std::uint8_t> output;std::uint64_t unknown{};};
Result run(unsigned primary,unsigned auxiliary,unsigned linked,unsigned fill,bool initialized=false){
    std::fill(memory.begin(),memory.end(),0);known.fill(false);unknown_reads=0;active_context=nullptr;
    for(unsigned at=frame_begin;at<stack_end;at+=4){const auto ordinal=(at-frame_begin)/4;const float value=fill==0?-1000000.f:fill==1?1000000.f:fill==2?1000000.f+float(ordinal):-1000000.f-float(ordinal);put(at,value);}
    // Explicit test-only native candidate policy: initialize the two68x68
    // distance work arrays to finite maximum. Other scratch remains untouched.
    if(initialized)for(unsigned relative=0x1b0;relative<0x9230;relative+=4){put(frame_begin+relative,std::numeric_limits<float>::max());for(unsigned i=0;i<4;++i)known[relative+i]=true;}
    std::fill(memory.begin()+0x3b27e0,memory.begin()+0x3b5040,0xa5);
    for(unsigned i=0;i<8;++i)actor(0x4a5c30+0x10e0*i,i,i<primary,0x1000000+0x2000*i);
    for(unsigned i=0;i<10;++i)actor(0x417090+0x1170*i,i,i<auxiliary,0x1040000+0x2000*i);
    for(unsigned i=0;i<50;++i)actor(0x42eb00+0xd90*i,i,i<linked,0x1080000+0x2000*i);
    memory[0x3243f2]=0;
    R5900Context context;PS2Runtime runtime;active_context=&context;context.pc=0x6d6240;SET_GPR_U32(&context,29,stack_end);SET_GPR_U32(&context,31,0x100);original_transform_port(memory.data(),&context,&runtime);
    check(context.pc==0x100&&GPR_U32(&context,29)==stack_end);active_context=nullptr;
    return {{memory.begin()+0x3b27e0,memory.begin()+0x3b5040},unknown_reads};
}
}
void cache_scratch_read(std::uint32_t at,std::size_t size){
    if(!active_context||at>=stack_end||at+size<=frame_begin)return;
    check(at>=frame_begin&&at+size<=stack_end);
    for(unsigned i=0;i<size;++i)if(!known[at-frame_begin+i]){++unknown_reads;++unknown_pcs[active_context->pc];break;}
}
void cache_scratch_write(std::uint32_t at,std::size_t size){
    if(!active_context||at>=stack_end||at+size<=frame_begin)return;
    check(at>=frame_begin&&at+size<=stack_end);for(unsigned i=0;i<size;++i)known[at-frame_begin+i]=true;
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    switch(context->pc){
#include "dispatch.inc"
    case 0x191d10:{const auto a=read_position(GPR_U32(context,4)),b=read_position(GPR_U32(context,5));const float x=a.x-b.x,y=a.y-b.y,z=a.z-b.z;context->f[0]=std::sqrt((x*x+y*y)+z*z);++port_calls;context->pc=GPR_U32(context,31);return;}
    case 0x376e70:case 0x579980:case 0x57d630:SET_GPR_U32(context,2,0);++port_calls;context->pc=GPR_U32(context,31);return;
    default:throw std::runtime_error("Undeclared target cache audit dependency "+std::to_string(context->pc));
    }
}
int main(){
    try{
        unsigned profiles=0,sensitive_profiles=0,unknown_profiles=0,initialized_runs=0;std::uint64_t total_unknown=0;
        constexpr std::array<unsigned,10> ranges{0x3b27e0,0x3b2830,0x3b2880,0x3b2a80,0x3b2c80,0x3b2e10,0x3b2fa0,0x3b3220,0x3b41c0,0x3b4e40};std::array<unsigned,10> changed_profiles{};
        std::cout<<"{\"profiles\":[";bool first=true;
        for(unsigned primary:{0u,1u,3u,8u})for(unsigned auxiliary:{0u,2u,10u})for(unsigned linked:{0u,1u,7u,50u}){
            const auto baseline=run(primary,auxiliary,linked,0);bool sensitive=false,unknown=baseline.unknown!=0;total_unknown+=baseline.unknown;std::array<bool,10> changed{};
            for(unsigned fill=1;fill<4;++fill){const auto other=run(primary,auxiliary,linked,fill);sensitive|=other.output!=baseline.output;unknown|=other.unknown!=0;total_unknown+=other.unknown;
                for(unsigned range=0;range<ranges.size();++range){const auto start=ranges[range]-ranges[0],end=(range+1<ranges.size()?ranges[range+1]:0x3b5040)-ranges[0];changed[range]=changed[range]||!std::equal(baseline.output.begin()+start,baseline.output.begin()+end,other.output.begin()+start);}
            }
            for(unsigned range=0;range<ranges.size();++range)changed_profiles[range]+=changed[range];
            const auto initialized=run(primary,auxiliary,linked,0,true);check(initialized.unknown==0);++initialized_runs;
            if(!unknown)check(initialized.output==baseline.output);
            for(unsigned fill=1;fill<4;++fill){const auto other=run(primary,auxiliary,linked,fill,true);check(other.unknown==0&&other.output==initialized.output);++initialized_runs;}
            ++profiles;sensitive_profiles+=sensitive;unknown_profiles+=unknown;if(!first)std::cout<<',';first=false;
            std::cout<<"{\"primary\":"<<primary<<",\"auxiliary\":"<<auxiliary<<",\"linked\":"<<linked<<",\"scratch_sensitive\":"<<(sensitive?"true":"false")<<",\"unknown_reads_first_fill\":"<<baseline.unknown<<'}';
        }
        check(profiles==48);check(unknown_profiles>0&&sensitive_profiles>0);
        std::cout<<"],\"profile_count\":"<<profiles<<",\"runs\":"<<profiles*4<<",\"initialized_runs\":"<<initialized_runs<<",\"scratch_sensitive_profiles\":"<<sensitive_profiles<<",\"unknown_profiles\":"<<unknown_profiles<<",\"unknown_reads\":"<<total_unknown<<",\"controlled_port_calls\":"<<port_calls<<",\"checks\":"<<checks<<",\"changed_profile_ranges\":{";first=true;
        for(unsigned i=0;i<ranges.size();++i){if(!first)std::cout<<',';first=false;std::cout<<'"'<<ranges[i]<<"\":"<<changed_profiles[i];}
        std::cout<<"},\"unknown_read_pcs\":{";first=true;
        for(auto [pc,count]:unknown_pcs){if(!first)std::cout<<',';first=false;std::cout<<'"'<<pc<<"\":"<<count;}
        std::cout<<"}}\n";
    }catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
}
