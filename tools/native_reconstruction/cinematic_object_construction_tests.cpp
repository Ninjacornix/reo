#include "game/native/gameplay_world/cinematic_object_construction.hpp"
#include "runtime/assets/virtual_afs.h"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <source_location>
namespace w=reo::native::gameplay_world;
namespace a=reo::native::animation;
namespace s=reo::native::gameplay_scenario;
namespace t=reo::native::transform_math;
std::uint64_t checks{},original_calls{},scenes{},missing_scenes{},objects{},source_constructors{},stream_groups{},source_ports{},refusals{};
std::string location;
constexpr unsigned base=0x600000,descriptor_at=0x700000,node_base=0xd00000;
unsigned current_index{},current_work{},next_material{},next_node{},constructors_in_scene{},path_calls{};
std::array<unsigned,16> payloads{};
std::array<unsigned,3> destination{},request{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error(std::string(at.file_name())+":"+std::to_string(at.line()));}
template<class T>T get(const std::uint8_t* m,unsigned at){return transform_read<T>(m,at);}
template<class T>void put(std::uint8_t* m,unsigned at,T value){transform_write(m,at,value);}
void invoke(std::uint8_t* m,unsigned pc,std::array<unsigned,4> args={}){
    static unsigned depth{};const auto stack=0x1f00000-0x10000*depth++;struct Reset{unsigned& d;~Reset(){--d;}}reset{depth};
    R5900Context c;PS2Runtime runtime;c.pc=pc;for(unsigned i=0;i<4;++i)SET_GPR_U32(&c,4+i,args[i]);SET_GPR_U32(&c,29,stack);SET_GPR_U32(&c,31,0xabcdef);
    original_transform_port(m,&c,&runtime);check(c.pc==0xabcdef&&GPR_U32(&c,29)==stack);
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++original_calls;const auto pc=context->pc,a0=GPR_U32(context,4),a1=GPR_U32(context,5),a2=GPR_U32(context,6),a3=GPR_U32(context,7);
    const auto resource=0xc00000+0x10000*current_index;
    switch(pc){
    case 0x1d13f0:
        current_index=a1&255;current_work=a0+0x70;next_node=next_material=0;check(current_index<16&&a0==base+0x11a0*current_index);++constructors_in_scene;++source_constructors;
        sub_001D13F0_0x1d13f0(memory,context,runtime);return;
#include "original_dispatch.hpp"
    case 0x107c68:check(a0>=base&&a0+0x11a0<=base+16*0x11a0&&a1==0&&a2==0x11a0);std::memset(memory+a0,0,a2);break;
    case 0x5ed900:SET_GPR_U32(context,2,0);break;
    case 0x5ebe30:check(a0==destination[0]&&a1==destination[1]&&a2==destination[2]);break;
    case 0x1d2560:check(a0<16&&a1==get<std::uint16_t>(memory,base+0x11a0*a0+0x1180));break;
    case 0x10a830:{
        check(a2==destination[0]&&a3==request[0]&&GPR_U32(context,8)==request[1]&&GPR_U32(context,9)==97+request[2]);
        const auto result=std::snprintf(reinterpret_cast<char*>(memory+a0),64,reinterpret_cast<char*>(memory+a1),int(a2),int(a3),int(GPR_U32(context,8)),int(GPR_U32(context,9)),std::bit_cast<std::int32_t>(GPR_U32(context,10)));
        check(result>0&&result<64);SET_GPR_U32(context,2,result);++path_calls;break;}
    case 0x1cd1c0:check(a0==0x3000+8*current_index);SET_GPR_U32(context,2,0);break;
    case 0x1af780:break;
    case 0x1b2a70:check(a0==8&&a1==11);SET_GPR_U32(context,2,0x1234+current_index);break;
    case 0x1ce110:case 0x1aaad0:{
        check(a3==3);
        if(pc==0x1ce110)check(a0==current_index&&a1==UINT32_MAX&&a2==current_work);
        else check(a0==0&&a1==current_work&&a2==current_index);
        const auto raw=payloads[current_index],model=get<unsigned>(memory,raw+0x14),skeleton=get<unsigned>(memory,raw+0x24);
        if(model)invoke(memory,0x1d25b0,{current_work,raw+model,0,0});
        if(skeleton)invoke(memory,0x1d2c00,{current_work,raw+skeleton,0,0});
        break;}
    case 0x1b1360:SET_GPR_U32(context,2,++next_material);break;
    case 0x1cd1e0:case 0x1cd250:case 0x1cd2c0:SET_GPR_U32(context,2,0x77);break;
    case 0x18dc50:check(a0>=16&&a0<0x10000&&a1==4);SET_GPR_U32(context,2,resource);break;
    case 0x18dca0:check(a0==resource);SET_GPR_U32(context,2,resource);break;
    case 0x1b10c0:check(a0==resource);break;
    case 0x1b1260:check(next_node<32);SET_GPR_U32(context,2,node_base+0x4000*current_index+400*next_node++);break;
    // Explicit non-object scene owners: no actor groups are projected into
    // this comparison. Their complete construction is qualified separately.
    case 0x5c0920:case 0x6b38d0:case 0x5c0d50:case 0x1bbb10:case 0x67c250:
    case 0x1d4870:case 0x5d7d60:case 0x576f10:case 0x1d1cc0:case 0x1d1e00:
    case 0x1d2520:case 0x1d1220:case 0x1d4130:case 0x5f0dc0:case 0x5f0c00:++source_ports;break;
    default:throw std::runtime_error("undeclared scene construction original call "+std::to_string(pc));
    }
    context->pc=GPR_U32(context,31);
}
w::Profile profile(){w::Profile value;value.layouts.push_back({});return value;}
void compare_scene(std::uint8_t* memory,const s::CutsceneDescriptor& descriptor,const w::PreparedCinematicObjects& prepared,w::World& world,unsigned mode){
    check(descriptor.section(descriptor.camera_selection()).size()<0x100000);std::fill_n(memory+0x38eca0,0x1400,0);std::fill_n(memory+node_base,16*0x4000,0);
    put(memory,0x4badf8,std::int8_t(1));invoke(memory,0x571010,{base,0,0,0});put(memory,0x32440c,0x900000u);memory[0x3243d7]=std::uint8_t(mode);put(memory,0x324200,std::int16_t(0));put(memory,0x38ecb8,std::int16_t(prepared.size()));
    const auto id=descriptor.identity();for(unsigned i=0;i<3;++i){destination[i]=id[i];memory[0x38ecc8+i]=id[i];memory[0x38ecd0+i]=std::uint8_t(request[i]);}
    for(unsigned group=0;group<prepared.size();++group){
        const auto& asset=*prepared.asset(group);payloads[group]=0x1000000+0xc0000*group;check(asset.bytes().size()<0xc0000);std::memcpy(memory+payloads[group],asset.bytes().data(),asset.bytes().size());
        const auto header=descriptor.section(descriptor.object_groups()[group][2]);std::memcpy(memory+descriptor_at+36*group,header.data(),36);put(memory,0x38f7b0+28*group+8,descriptor_at+36*group);
    }
    constructors_in_scene=path_calls=0;invoke(memory,0x5ecf90);check(constructors_in_scene==prepared.size()&&path_calls==2*prepared.size());
    w::CinematicObjectConstruction factory(world);const auto built=factory.create(prepared);check(built.status==w::CinematicObjectStatus::completed&&built.bindings.size()==prepared.size()&&built.constructed==prepared.size()&&!world.busy());
    auto& pool=world.cinematic_objects();
    for(unsigned slot=0;slot<16;++slot){
        const auto value=pool.resolve(pool.identity_at(slot));const auto at=base+0x11a0*slot;check(value&&!value->active&&!value->visible&&!value->phase&&!value->animation_phase);
        check(value->reserved==bool(get<unsigned>(memory,at+0x1198))&&get<std::uint8_t>(memory,at+2)==w::CinematicObject::category);
        check(value->motion==get<unsigned>(memory,at+0x117c)&&value->authored_model==get<unsigned>(memory,at+0x1180)&&value->flags==get<unsigned>(memory,at+0x118c));
        check(std::memcmp(value->part_visibility.data(),memory+at+8,8)==0);
        if(slot<prepared.size()){
            check(built.bindings[slot].object==pool.identity_at(slot)&&value->model_asset==prepared.asset(slot)&&bool(value->model)==bool(value->model_asset->skeleton()));
            check(built.bindings[slot].attachment_scale&&std::memcmp(&*built.bindings[slot].attachment_scale,memory+at+0xb4,12)==0);
            if(value->model)for(unsigned node=0;node<value->model->nodes().size();++node){const auto source=node_base+0x4000*slot+400*node;check(std::memcmp(&value->model->nodes()[node].local,memory+source+0x40,64)==0&&std::memcmp(&value->model_asset->inverse_bind_pose()[node],memory+source+0x80,64)==0);}
            const auto leaf=w::CinematicObjectAssets::model_name({std::uint8_t(request[0]),std::uint8_t(request[1]),std::uint8_t(request[2])},value->authored_model);const auto expected="data\\rom\\model\\demo\\r"+std::string(destination[0]<10?"00":destination[0]<100?"0":"")+std::to_string(destination[0])+"\\"+leaf.substr(0,leaf.size()-4);check(expected==reinterpret_cast<char*>(memory+0x340bf0+64*slot));++objects;
        }else check(!value->model_asset&&!value->model);
    }
    const auto groups=prepared.tracks(built.bindings);check(groups.size()==prepared.size());s::CutsceneObjectTracks tracks(world);check(tracks.install(groups)==s::CutsceneTrackStatus::completed);
    for(unsigned group=0;group<groups.size();++group)for(unsigned stream=0;stream<7;++stream){const auto expected=s::CutsceneActorStream::import(descriptor.section(descriptor.object_groups()[group][stream]));check(groups[group].streams[stream]->size()==expected->size());for(unsigned row=0;row<expected->size();++row)check(std::memcmp(groups[group].streams[stream]->record(row).data(),expected->record(row).data(),36)==0);}
    stream_groups+=groups.size();check(tracks.close()==s::CutsceneTrackStatus::completed);
    if(prepared.size()){const auto before=pool.resolve(pool.identity_at(0));check(factory.create(prepared).status==w::CinematicObjectStatus::unavailable&&pool.resolve(pool.identity_at(0))==before);++refusals;}
    const auto retained=prepared.size()?pool.resolve(pool.identity_at(0)):nullptr;const auto old_id=prepared.size()?pool.identity_at(0):reo::native::gameplay_scene::RecordId{};
    check(pool.initialize()==w::CinematicObjectStatus::completed);if(retained)check(!pool.resolve(old_id)&&retained->model_asset==prepared.asset(0));
    check(world.close()==w::Status::completed&&factory.create(prepared).status==w::CinematicObjectStatus::closed);++scenes;
}
int main(int argc,char** argv)try{
    check(argc==4);const auto old=_mm_getcsr();struct Restore{unsigned old;~Restore(){_mm_setcsr(old);}}restore{old};_mm_setcsr(0x1f80);
    std::vector<std::uint8_t> memory(0x2000000);owned_constants(memory.data());put(memory.data(),0x294e00,t::identity());auto source=std::make_shared<reo::assets::Source>(argv[1]);auto archive=std::make_shared<s::content::ScenarioArchive>(source);w::CinematicObjectAssets assets(archive);
    std::ifstream package(argv[2],std::ios::binary),manifest(argv[3]);check(bool(package)&&bool(manifest));unsigned count{};package.read(reinterpret_cast<char*>(&count),4);check(count==548);
    for(unsigned index=0;index<count;++index){unsigned size{},available{};std::string name;manifest>>request[0]>>request[1]>>request[2]>>available>>name;check(bool(manifest));location=name;package.read(reinterpret_cast<char*>(&size),4);check(size>=40&&size<0x100000);std::vector<std::byte> raw(size);package.read(reinterpret_cast<char*>(raw.data()),size);check(bool(package));const auto descriptor=s::CutsceneDescriptor::import(raw);
        std::shared_ptr<const w::PreparedCinematicObjects> prepared;bool missing{};try{prepared=w::CinematicObjectConstruction::prepare(*descriptor,{std::uint8_t(request[0]),std::uint8_t(request[1]),std::uint8_t(request[2])},assets);}catch(const std::invalid_argument&){missing=true;}
        check(missing==!bool(available));if(missing){++missing_scenes;continue;}check(prepared&&prepared->size()==descriptor->object_groups().size());
        for(unsigned mode:{0u,1u,128u,255u}){w::World world(profile(),std::make_shared<w::Session>());world.paused=1;check(world.cinematic_objects().initialize()==w::CinematicObjectStatus::completed);compare_scene(memory.data(),*descriptor,*prepared,world,mode);}
    }
    std::cout<<"{\"checks\":"<<checks<<",\"scenes\":"<<scenes<<",\"missing_scenes\":"<<missing_scenes<<",\"objects\":"<<objects<<",\"source_constructors\":"<<source_constructors<<",\"stream_groups\":"<<stream_groups<<",\"refusals\":"<<refusals<<",\"non_object_ports\":"<<source_ports<<",\"original_calls\":"<<original_calls<<",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<location<<" "<<e.what()<<'\n';return 1;}
