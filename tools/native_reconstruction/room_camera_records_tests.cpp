#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include "game/native/gameplay_scenario/room_camera_records.hpp"
#include "game/native/gameplay_scenario/sequence_control.hpp"
#include <fstream>
#include <iostream>
#include <source_location>
#include <vector>

namespace s=reo::native::gameplay_scenario;
using Vector=reo::native::transform_math::Vector;
namespace {
std::size_t checks{},calls{},owned{},records{},synthetic{},refusals{},ratios{},links{};
std::string current;
constexpr std::uint32_t base=0x3dddb0,input=0x1000000,returned=0x1000;
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error(current+": camera check at "+std::to_string(at.line()));
}
template<class T>void put(std::vector<std::byte>& data,std::size_t at,T value){
    check(at+sizeof value<=data.size());std::memcpy(data.data()+at,&value,sizeof value);
}
template<class T>T read(const std::vector<std::uint8_t>& memory,std::uint32_t at){return transform_read<T>(memory.data(),at);}
void compare_float(float actual,const std::vector<std::uint8_t>& memory,std::uint32_t at){
    check(std::bit_cast<std::uint32_t>(actual)==read<std::uint32_t>(memory,at));
}
void compare_vector(Vector value,const std::vector<std::uint8_t>& memory,std::uint32_t at){
    compare_float(value.x,memory,at);compare_float(value.y,memory,at+4);compare_float(value.z,memory,at+8);
}
R5900Context context(){R5900Context result;SET_GPR_U32(&result,29,0x1f00000);SET_GPR_U32(&result,31,returned);return result;}
void run(std::vector<std::uint8_t>& memory,R5900Context& ctx,std::uint32_t address){
    PS2Runtime runtime;ctx.pc=address;original_transform_port(memory.data(),&ctx,&runtime);++calls;check(ctx.pc==returned);
}
void compare(std::span<const std::byte> bytes,std::uint8_t actor){
    auto native=s::RoomCameraRecords::import(bytes);s::SequenceControl owner;
    s::SequenceControlState dirty;dirty.active.fill(1);dirty.count=32;dirty.selection=99;dirty.phase=5;
    dirty.fraction=13;dirty.selection_changed=1;check(owner.restore(dirty));
    owner.install_camera_records(native,actor);
    std::vector<std::uint8_t> memory(0x2000000);owned_constants(memory.data());
    std::memset(memory.data()+base,0xa5,0x3334);std::memcpy(memory.data()+input,bytes.data(),bytes.size());
    transform_write(memory.data(),0x4baded,actor);
    auto ctx=context();SET_GPR_U32(&ctx,4,input);SET_GPR_U32(&ctx,5,bytes.size());run(memory,ctx,0x5be3e0);
    const auto state=owner.snapshot();
    check(state.initialized==read<std::uint8_t>(memory,base));check(state.count==read<std::int8_t>(memory,base+1));
    check(state.restart_byte==read<std::uint8_t>(memory,base+2));check(state.condition_id==read<std::uint8_t>(memory,base+3));
    check(state.selection_changed==read<std::uint8_t>(memory,base+4));check(state.selection==read<std::uint16_t>(memory,base+6));
    check(state.actor==read<std::uint8_t>(memory,base+0x24));compare_float(state.distance,memory,base+0x28);
    check(state.phase==0&&state.selected_id==0&&state.mode==0&&state.progress==0&&state.fraction==0);
    check(state.parameter_a==0&&state.parameter_b==0&&owner.camera_records()==native);
    for(unsigned i=0;i<32;++i){
        const auto& r=native->records()[i];const auto at=base+0x34+0x198*i;
        current+="/"+std::to_string(i);
        check(state.active[i]==read<std::uint8_t>(memory,at));check(r.type==read<std::uint8_t>(memory,at+1));
        check(r.policy==read<std::uint8_t>(memory,at+3));
        for(unsigned n=0;n<4;++n)check(r.parameters[n]==read<std::uint32_t>(memory,at+4+4*n));
        compare_float(r.lens,memory,at+0x14);compare_float(r.distance,memory,at+0x18);compare_vector(r.anchor,memory,at+0x1c);
        for(unsigned n=0;n<8;++n)for(unsigned k=0;k<3;++k)check(r.volume[n][k]==read<std::int32_t>(memory,at+0x28+12*n+4*k));
        for(unsigned n=0;n<4;++n)for(unsigned e=0;e<2;++e)for(unsigned k=0;k<3;++k)
            check(r.endpoints[n][e][k]==read<std::int32_t>(memory,at+0x88+24*n+12*e+4*k));
        for(unsigned n=0;n<2;++n){
            compare_float(r.endpoint_distance[n],memory,at+0xe8+4*n);
            const auto& b=r.boundaries[n];compare_vector(b.first,memory,at+0xf4+24*n);compare_vector(b.last,memory,at+0x100+24*n);
            compare_vector(b.first_normal,memory,at+0x124+24*n);compare_vector(b.last_normal,memory,at+0x130+24*n);
        }
        check(r.boundary_policy==read<std::uint32_t>(memory,at+0xf0));
        check(std::memcmp(r.view_controls.data(),memory.data()+at+0x154,16)==0);
        check(r.duration==read<std::uint8_t>(memory,at+0x164));check(r.previous==read<std::uint8_t>(memory,at+0x165));
        check(r.next==read<std::uint8_t>(memory,at+0x166));check(r.interpolation==read<std::uint8_t>(memory,at+0x167));
        compare_vector(r.first_control,memory,at+0x168);compare_vector(r.last_control,memory,at+0x174);compare_float(r.sequence_time,memory,at+0x180);
        check(read<std::uint32_t>(memory,at+0x184)==(r.sequence_root?base+0x34+0x198u*(*r.sequence_root):0));
        check(std::memcmp(r.auxiliary.data(),memory.data()+at+0x188,8)==0);
        for(unsigned n=0;n<2;++n)check(r.extra[n]==read<std::uint32_t>(memory,at+0x190+4*n));
        if(r.type){
            for(const auto point:{Vector{},r.anchor,Vector{371.25f,-600,-919.5f}})for(unsigned mode=0;mode<2;++mode){
                transform_write(memory.data(),0x4a5c30+0x10e0u*actor+0x38,point.x);
                transform_write(memory.data(),0x4a5c30+0x10e0u*actor+0x40,point.z);
                ctx=context();SET_GPR_U32(&ctx,4,at);SET_GPR_U32(&ctx,5,mode);run(memory,ctx,0x5c07c0);
                const auto actual=native->boundary_ratio(std::uint8_t(i),std::uint8_t(mode),point);check(bool(actual));
                check(std::bit_cast<std::uint32_t>(*actual)==std::bit_cast<std::uint32_t>(ctx.f[0]));++ratios;
            }
            ++records;
        }
        for(const auto steps:{0u,1u,2u,255u,256u,257u})if(const auto result=native->follow(std::uint8_t(i),steps)){
            ctx=context();SET_GPR_U32(&ctx,4,at);SET_GPR_U32(&ctx,5,steps);run(memory,ctx,0x5be930);
            check(GPR_U32(&ctx,2)==base+0x34+0x198u*(*result));++links;
        }
        current.erase(current.rfind('/'));
    }
    owner.enable_all();for(unsigned i=0;i<32;++i)check(owner.snapshot().active[i]==(i<native->count()));
    check(owner.select(31,19)&&owner.snapshot().phase==4&&owner.snapshot().selection==19);
    check(owner.cancel_if_selected(31)&&owner.snapshot().active[31]==0&&owner.snapshot().selection==0);
    const auto retained=owner.camera_records();owner.install_camera_records({},0);check(owner.camera_records()==retained);
    check(!native->follow(32,0)&&!native->boundary_ratio(32,0,{})&&!native->boundary_ratio(0,2,{}));
}
std::vector<std::byte> generated(unsigned seed,unsigned count){
    std::vector<std::byte> data(8+count*4+count*0x130);put(data,4,std::uint16_t(count));
    std::uint32_t rng=seed+1;const auto next=[&](){rng=rng*1664525u+1013904223u;return rng;};
    for(unsigned i=0;i<count;++i){
        const auto at=8+4*count+0x130*i;put(data,8+4*i,std::uint32_t(at));
        for(unsigned j=0;j<0x130;j+=4)put(data,at+j,next());
        put(data,at,std::uint32_t((i+seed)%11));put(data,at+8,std::uint32_t((seed&3)|(((seed>>2)&3)<<16)));
        for(unsigned j=0x24;j<0xe4;j+=4)put(data,at+j,std::int32_t(seed%4==0?0:std::int32_t(next()%200001)-100000));
        put(data,at+0x1c,45.f);put(data,at+0x20,80.f);
        put(data,at+0xfc,0xffu);put(data,at+0x100,0xffu);
        for(unsigned j=0x104;j<0x11c;j+=4)put(data,at+j,float(std::int32_t(next()%200001)-100000));
    }
    // A real multi-record sequence, followed by an explicitly mismatching child.
    if(count>=6)for(unsigned i=0;i<5;++i){const auto at=8+4*count+0x130*i;
        put(data,at,8u);put(data,at+0xfc,i==0?255u:i-1);put(data,at+0x100,i+1);
        put(data,at+0xf8,std::uint32_t(17+13*i));
    }
    return data;
}
void malformed(){
    const auto refused=[](const std::vector<std::byte>& bytes){bool failure=false;try{(void)s::RoomCameraRecords::import(bytes);}catch(const std::logic_error&){failure=true;}check(failure);++refusals;};
    refused({});auto data=generated(2,1);auto bad=data;bad.resize(7);refused(bad);
    bad=data;put(bad,4,std::uint16_t(33));refused(bad);
    bad=data;put(bad,8,0xfffffffcu);refused(bad);
    bad=data;bad.pop_back();refused(bad);
    bad=data;put(bad,12,8u);put(bad,12+0xfc,255u);put(bad,12+0x100,32u);refused(bad);
    // A reached zero slot inside the allocation terminates the source chain.
    put(bad,12+0x100,31u);auto valid=s::RoomCameraRecords::import(bad);check(valid->records()[0].sequence_root==0);
    check(valid->follow(0,1)==31&&valid->follow(0,256)==0);
    put(bad,12+0x100,255u);valid=s::RoomCameraRecords::import(bad);check(!valid->follow(0,1));
}
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    switch(context->pc){
#include "original_dispatch.hpp"
    case 0x107ab0:case 0x107c68:{
        const auto destination=GPR_U32(context,4),source=GPR_U32(context,5),size=GPR_U32(context,6);
        if(destination>0x2000000||size>0x2000000-destination)throw std::runtime_error("Original memory destination");
        if(context->pc==0x107ab0){if(source>0x2000000||size>0x2000000-source)throw std::runtime_error("Original memory source");std::memcpy(memory+destination,memory+source,size);}
        else std::memset(memory+destination,int(source&255),size);
        SET_GPR_U32(context,2,destination);context->pc=GPR_U32(context,31);return;
    }
    default:throw std::runtime_error("Unexpected original room camera dependency "+std::to_string(context->pc));
    }
}
int main(int argc,char** argv)try{
    check(argc==2);std::ifstream stream(argv[1],std::ios::binary);check(bool(stream));std::uint32_t count{};stream.read(reinterpret_cast<char*>(&count),4);check(count==166);
    for(unsigned i=0;i<count;++i){std::uint32_t size{};stream.read(reinterpret_cast<char*>(&size),4);check(size<0x100000&&size>=8);std::vector<std::byte> bytes(size);stream.read(reinterpret_cast<char*>(bytes.data()),size);check(bool(stream));current="owned-"+std::to_string(i);compare(bytes,std::uint8_t(i%4));++owned;}
    for(unsigned i=0;i<64;++i){current="generated-"+std::to_string(i);compare(generated(i,i%3?32:0),std::uint8_t(i%4));++synthetic;}
    current="malformed";malformed();
    std::cout<<"{\"checks\":"<<checks<<",\"original_calls\":"<<calls<<",\"owned_sections\":"<<owned<<",\"records\":"<<records<<",\"synthetic\":"<<synthetic<<",\"refusals\":"<<refusals<<",\"ratios\":"<<ratios<<",\"links\":"<<links<<"}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
