#include "game/native/gameplay_scenario/room_model_assets.hpp"
#include "game/native/gameplay_application/room_models.hpp"
#include "reference.hpp"
#include <fstream>
#include <iostream>
#include <vector>
namespace a=reo::native::animation;
namespace s=reo::native::gameplay_scenario;
namespace t=reo::native::transform_math;
#include "owned_constants.hpp"
#include "functions.h"
std::uint64_t checks{},calls{},allocations{},releases{},asset_cases{},root_cases{},pose_cases{};
constexpr std::uint32_t raw_at=0x700000,work_at=0x600000,context_at=0x49ef50,current_at=0x49fa10,saved_at=0x4a3c20;
std::vector<std::uint32_t> handles;
std::uint64_t renderer_calls{},bank_cases{},cache_hits{},restorations{};
std::uint32_t pending_model_size{};
std::uint32_t pending_room_key{};
unsigned invoke_depth{};
void check(bool yes,const std::string& why){++checks;if(!yes)throw std::runtime_error(why);}
template<class T>T get(const std::uint8_t* p,std::uint32_t at){return transform_read<T>(p,at);}
template<class T>void put(std::uint8_t* p,std::uint32_t at,T value){transform_write(p,at,value);}
R5900Context invoke(std::uint8_t* memory,std::uint32_t at,std::uint32_t p0=0,std::uint32_t p1=0,std::uint32_t p2=0,std::uint32_t p3=0){
    ++invoke_depth;struct Exit{~Exit(){--invoke_depth;}}exit;check(invoke_depth<16,"bounded independent oracle call stacks");
    R5900Context context{};PS2Runtime runtime;SET_GPR_U32(&context,4,p0);SET_GPR_U32(&context,5,p1);SET_GPR_U32(&context,6,p2);SET_GPR_U32(&context,7,p3);
    SET_GPR_U32(&context,29,0x1e00000-0x10000*invoke_depth);SET_GPR_U32(&context,31,0x123456);context.pc=at;
    original_transform_port(memory,&context,&runtime);check(context.pc==0x123456,"complete original room bank caller returns");return context;
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;
    switch(context->pc){
    case 0x107c68:{std::memset(memory+GPR_U32(context,4),int(GPR_U32(context,5)),GPR_U32(context,6));context->pc=GPR_U32(context,31);return;}
    case 0x5be980:++renderer_calls;context->pc=GPR_U32(context,31);return; // Camera reset outside this bank projection.
    case 0x1b1820:case 0x1cd080:case 0x18dcb0:case 0x1d1f50:case 0x1d0c80:case 0x1d25a0:case 0x1cd1c0:
        ++renderer_calls;context->pc=GPR_U32(context,31);return;
    case 0x1b2a70:
        check(GPR_U32(context,4)==128&&GPR_U32(context,5)==6,"actual128-slot renderer resource request");
        ++renderer_calls;SET_GPR_U32(context,2,0x1234);context->pc=GPR_U32(context,31);return;
    case 0x1ce110:{
        check(GPR_U32(context,4)==pending_room_key&&GPR_U32(context,5)==0xffffffffu&&GPR_U32(context,6)==context_at&&GPR_U32(context,7)==2&&pending_model_size,"actual static model provider request");
        const auto parts=invoke(memory,0x1a31b0,0x1000000);put(memory,context_at+0x812,std::uint16_t(GPR_U32(&parts,2)));
        (void)invoke(memory,0x1cdfe0,0x1800,context_at,raw_at);++renderer_calls;context->pc=GPR_U32(context,31);return;
    }
    case 0x18dc50:{
        check(GPR_U32(context,5)==4&&GPR_U32(context,4)<=0x10000,"actual bounded SDK packed-skeleton allocation");
        handles.push_back(0x800000+std::uint32_t(handles.size())*0x10000);
        SET_GPR_U32(context,2,std::uint32_t(handles.size()));++allocations;context->pc=GPR_U32(context,31);return;
    }
    case 0x18dca0:{
        const auto handle=GPR_U32(context,4);check(handle&&handle<=handles.size()&&handles[handle-1],"actual live SDK packed-skeleton lookup");
        SET_GPR_U32(context,2,handles[handle-1]);context->pc=GPR_U32(context,31);return;
    }
    case 0x18dc90:{
        const auto handle=GPR_U32(context,4);check(handle&&handle<=handles.size()&&handles[handle-1],"actual SDK packed-skeleton release");
        handles[handle-1]=0;++releases;context->pc=GPR_U32(context,31);return;
    }
#include "original_dispatch.hpp"
    default:throw std::runtime_error("Undeclared room-model original helper "+std::to_string(context->pc));
    }
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#include "original_models.cpp"
#pragma GCC diagnostic pop
std::vector<std::byte> load(const std::string& path){std::ifstream source(path,std::ios::binary|std::ios::ate);check(bool(source),"owned room bundle available");const auto size=source.tellg();check(size>0&&size<0x2000000,"owned room bundle bounded");std::vector<std::byte> bytes(static_cast<std::size_t>(size));source.seekg(0);source.read(reinterpret_cast<char*>(bytes.data()),size);check(bool(source),"complete owned room bundle");return bytes;}
void run(const std::string& name){
    const auto bytes=std::make_shared<const std::vector<std::byte>>(load(name));const auto asset=s::RoomModelAsset::import(name,bytes);
    std::vector<std::uint8_t> memory(0x2000000);owned_constants(memory.data());handles.clear();
    std::fill_n(memory.data()+current_at,128*64,std::uint8_t(0x42));std::fill_n(memory.data()+saved_at,128*64,std::uint8_t(0x53));
    std::fill_n(memory.data()+0x49eef4,24,std::uint8_t(0xa5));std::fill_n(memory.data()+0x4a1a10,48,std::uint8_t(0xa5));
    std::fill_n(memory.data()+0x4a1a40,24*12,std::uint8_t(0xa5));
    for(unsigned i=0;i<128;++i)put(memory.data(),0x5697d0+4*i,std::uint32_t(-1));
    put(memory.data(),0x32440c,std::uint32_t(work_at-0x200000));put(memory.data(),0x294e00,t::identity());
    const auto offset=get<std::uint32_t>(reinterpret_cast<const std::uint8_t*>(bytes->data()),0x24),size=get<std::uint32_t>(reinterpret_cast<const std::uint8_t*>(bytes->data()),0x28);
    std::memcpy(memory.data()+raw_at,bytes->data()+offset,size);
    const auto model_offset=get<std::uint32_t>(reinterpret_cast<const std::uint8_t*>(bytes->data()),0x14),model_size=get<std::uint32_t>(reinterpret_cast<const std::uint8_t*>(bytes->data()),0x18);
    std::memcpy(memory.data()+0x1000000,bytes->data()+model_offset,model_size);
    R5900Context parts_context{};PS2Runtime parts_runtime;SET_GPR_U32(&parts_context,4,0x1000000);SET_GPR_U32(&parts_context,29,0x1f00000);SET_GPR_U32(&parts_context,31,0x123456);parts_context.pc=0x1a31b0;
    original_transform_port(memory.data(),&parts_context,&parts_runtime);check(GPR_U32(&parts_context,2)==asset->parts(),"actual original loaded physical part count");
    R5900Context context{};PS2Runtime runtime;SET_GPR_U32(&context,4,context_at);SET_GPR_U32(&context,5,raw_at);SET_GPR_U32(&context,6,current_at);SET_GPR_U32(&context,7,saved_at);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x123456);context.pc=0x1d2cb0;
    original_transform_port(memory.data(),&context,&runtime);check(context.pc==0x123456,"complete original room-model producer returns");
    check(get<std::uint16_t>(memory.data(),context_at+0x816)==asset->nodes(),"original complete node count");
    check(memory[0x49eef3]==asset->groups().size(),"original root group count");check(get<std::uint32_t>(memory.data(),context_at+0x80c)==0,"original temporary handle cleared");
    std::array<a::Matrix,128> expected_current,expected_saved;std::memset(expected_current.data(),0x42,sizeof expected_current);std::memset(expected_saved.data(),0x53,sizeof expected_saved);
    for(const auto& pose:asset->poses()){expected_current[pose.slot]=pose.matrix;expected_saved[pose.slot]=pose.matrix;++pose_cases;}
    for(unsigned i=0;i<128;++i){check(std::memcmp(&expected_current[i],memory.data()+current_at+64*i,64)==0,"original current pose slot "+std::to_string(i));check(std::memcmp(&expected_saved[i],memory.data()+saved_at+64*i,64)==0,"original saved pose slot "+std::to_string(i));}
    for(unsigned i=0;i<24;++i){
        const bool defined=i<asset->groups().size();const auto* group=defined?&asset->groups()[i]:nullptr;
        check(memory[0x49eef4+i]==(group?group->models:0xa5),"original group model count");
        check(memory[0x4a1a10+i]==(group?group->first_model:0xa5),"original group first model mapping");
        check(memory[0x4a1a28+i]==(group&&group->control?*group->control:0xa5),"original group control byte "+name+" group "+std::to_string(i)+" actual "+std::to_string(memory[0x4a1a28+i])+" native "+std::to_string(group&&group->control?*group->control:0xa5));
        if(group){check(std::memcmp(&group->origin,memory.data()+0x4a1a40+12*i,12)==0,"original first-node group origin");++root_cases;}
    }
    check(allocations==releases,"all actual SDK allocations released");for(auto pointer:handles)check(!pointer,"all SDK handles retired");
    ++asset_cases;
}
void banks(const std::vector<std::string>& names){
    namespace app=reo::native::gameplay_application;
    app::RoomModels owner;s::RoomModelRemap map;for(unsigned i=0;i<32;++i)map[i]=std::uint8_t(i);
    s::SceneModels models(owner.cold_state(),map);check(owner.current({255,255,255})&&!owner.asset(),"actual coldFF cache sentinel");
    check(!owner.commit({41,73,0},{}),"missing immutable model capability refuses");
    std::vector<std::uint8_t> memory(0x2000000);owned_constants(memory.data());handles.clear();
    std::fill_n(memory.data()+0x49eef0,0x6d40,std::uint8_t(0xa5));
    (void)invoke(memory.data(),0x107c68,0x49eef0,0,0x6d40); // Actual5EAEB0 clear call's projection.
    (void)invoke(memory.data(),0x107c68,0x7434b0,255,20); // Actual5EB078..088 cache initialization.
    for(unsigned i=0;i<128;++i)put(memory.data(),0x5697d0+4*i,std::uint32_t(-1));
    put(memory.data(),0x32440c,std::uint32_t(work_at-0x200000));put(memory.data(),0x294e00,t::identity());
    (void)invoke(memory.data(),0x5d7d60);
    const auto compare=[&]{
        for(unsigned i=0;i<128;++i){
            check(std::memcmp(&models.state().poses[i],memory.data()+current_at+64*i,64)==0,"persistent current pose "+std::to_string(i));
            check(std::memcmp(&owner.saved()[i],memory.data()+saved_at+64*i,64)==0,"persistent saved pose "+std::to_string(i));
            check(models.state().styles[i]==get<std::uint32_t>(memory.data(),0x49f810+4*i),"persistent source style");
            check(models.state().visibility[i]==memory[0x49f790+i],"persistent source visibility");
        }
        for(unsigned i=0;i<24;++i){const auto& g=owner.groups()[i];
            check(g.first_model==memory[0x4a1a10+i]&&g.models==memory[0x49eef4+i]&&g.control==memory[0x4a1a28+i],"persistent canonical group bytes");
            check(std::memcmp(&g.origin,memory.data()+0x4a1a40+12*i,12)==0,"persistent canonical group origin");
        }
    };compare();
    const std::array<s::content::RoomId,3> ids{{{41,73,0},{1,1,0},{2,32,0}}};
    for(unsigned step=0;step<6;++step){
        const unsigned index=step%3;const auto bytes=std::make_shared<const std::vector<std::byte>>(load(names[index]));
        const auto asset=s::RoomModelAsset::import(names[index],bytes);const auto* raw=reinterpret_cast<const std::uint8_t*>(bytes->data());
        const auto skeleton_offset=get<std::uint32_t>(raw,0x24),skeleton_size=get<std::uint32_t>(raw,0x28),model_offset=get<std::uint32_t>(raw,0x14);
        pending_model_size=get<std::uint32_t>(raw,0x18);std::memcpy(memory.data()+raw_at,bytes->data()+skeleton_offset,skeleton_size);std::memcpy(memory.data()+0x1000000,bytes->data()+model_offset,pending_model_size);
        const auto next=owner.prepare(ids[index],*asset,models.state());models=s::SceneModels(next,map);check(owner.commit(ids[index],asset),"owned model bank commit");
        pending_room_key=std::uint32_t(ids[index].scenario)<<16|std::uint32_t(ids[index].room)<<8|ids[index].variant;
        (void)invoke(memory.data(),0x5ebe30,ids[index].scenario,ids[index].room,ids[index].variant);compare();++bank_cases;
        auto live=*models.pose(0);live[3][0]+=float(step+1);check(models.pose(0,live)==s::ModelStatus::completed,"live pose update");put(memory.data(),current_at,live);
        check(models.style(0,step)==s::ModelStatus::completed,"live style update");put(memory.data(),0x49f810,std::uint32_t(step));
        const auto before_renderer=renderer_calls;
        const auto cached=owner.prepare(ids[index],*asset,models.state());models=s::SceneModels(cached,map);check(owner.commit(ids[index],asset),"cached model bank commit");
        check(owner.current({std::uint16_t(ids[index].scenario+256),std::uint16_t(ids[index].room+256),std::uint16_t(ids[index].variant+256)}),"native cache uses the actual low bytes");
        (void)invoke(memory.data(),0x5ebe30,ids[index].scenario+256,ids[index].room+256,ids[index].variant+256);
        check(renderer_calls==before_renderer,"actual byte-cache hit makes no provider call");compare();++cache_hits;
        owner.restore_poses_and_styles(models);(void)invoke(memory.data(),0x5d7d60);compare();++restorations;
    }
}
int main(int argc,char** argv)try{
    check(argc==2,"owned room model manifest required");const auto old=_mm_getcsr();struct Reset{unsigned old;~Reset(){_mm_setcsr(old);}}reset{old};_mm_setcsr(0x1f80);
    std::vector<std::string> names;std::ifstream manifest(argv[1]);std::string line;while(std::getline(manifest,line))if(!line.empty()){run(line);names.push_back(line);}
    banks(names);
    check(asset_cases==3&&root_cases==4&&pose_cases>200,"owned single/multiple-root profile exercised");
    std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"assets\":"<<asset_cases<<",\"groups\":"<<root_cases<<",\"poses\":"<<pose_cases<<",\"bank_cases\":"<<bank_cases<<",\"cache_hits\":"<<cache_hits<<",\"restorations\":"<<restorations<<",\"original_calls\":"<<calls<<",\"allocations\":"<<allocations<<",\"game_launched\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
