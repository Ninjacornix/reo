#include "game/native/gameplay_world/secondary_pose_dynamics.hpp"
#include "game/native/gameplay_world/actor_initial_state.hpp"
#include "game/native/animation/model.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <fstream>
#include <iostream>
#include <limits>
#include <source_location>
namespace a=reo::native::animation;namespace w=reo::native::gameplay_world;namespace t=reo::native::transform_math;
std::uint64_t checks{},calls{},cases{},selector_cases{},refusals{},lifetimes{},model_api_cases{},gates{};unsigned profile_case{},step_case{};
void check(bool condition,std::source_location at=std::source_location::current()){++checks;if(!condition)throw std::runtime_error("Dynamics profile "+std::to_string(profile_case)+" step "+std::to_string(step_case)+" line "+std::to_string(at.line()));}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){++calls;switch(context->pc){
#include "original_dispatch.hpp"
default:throw std::runtime_error("Undeclared dynamics source call "+std::to_string(context->pc));}}
void invoke(std::uint8_t* memory,unsigned pc,unsigned first,unsigned second=0,a::Vector incoming={1,1,1}){R5900Context c;PS2Runtime r;c.pc=pc;c.f[12]=incoming.x;c.f[13]=incoming.y;c.f[14]=incoming.z;SET_GPR_U32(&c,4,first);SET_GPR_U32(&c,5,second);SET_GPR_U32(&c,29,0x1f00000);SET_GPR_U32(&c,31,0xabcdef);original_transform_port(memory,&c,&r);check(c.pc==0xabcdef&&GPR_U32(&c,29)==0x1f00000);}
constexpr unsigned actor=0x200000,work=0x210000,nodes=0x300000;
template<class T>void put(std::uint8_t* memory,unsigned at,const T& value){transform_write(memory,at,value);}
void project(std::uint8_t* memory,const w::Actor& value){
    put(memory,actor,std::uint8_t(value.active));put(memory,actor+1,std::uint8_t(value.visible));put(memory,actor+2,value.category);put(memory,actor+0x54a,value.contact_flags);put(memory,actor+0x54d,value.model_pose_class);put(memory,actor+0xb98,value.character);put(memory,actor+0xbb4,value.model_variant);put(memory,actor+0xbbc,value.appearance_variant);put(memory,actor+0x34,work);put(memory,actor+0xfac,value.secondary_pose_category_override.value_or(0));
    for(unsigned i=0;i<2;++i)put(memory,actor+0xe58+36*i,value.secondary_pose_history->displacement[i]);
    for(unsigned i=0;i<value.model->nodes().size();++i){const auto& row=value.model->nodes()[i];const auto& link=value.model->links()[i];const auto at=nodes+400*i;put(memory,work+0x820+4*i,at);put(memory,at,row.world);put(memory,at+0x40,row.local);put(memory,at+0x104,row.parameters);put(memory,at+0x15c,row.caches);put(memory,at+0xc8,unsigned(link.parent?nodes+400*(*link.parent):0u));put(memory,at+0xd0,unsigned(link.child?nodes+400*(*link.child):0u));put(memory,at+0xcc,unsigned(link.sibling?nodes+400*(*link.sibling):0u));}
}
void compare(std::uint8_t* memory,const w::Actor& value){
    for(unsigned i=0;i<2;++i){const auto expected=transform_read<a::Vector>(memory,actor+0xe58+36*i);const auto actual=value.secondary_pose_history->displacement[i];if(std::memcmp(&expected,&actual,12))std::cerr<<"history "<<i<<" native "<<actual.x<<","<<actual.y<<","<<actual.z<<" source "<<expected.x<<","<<expected.y<<","<<expected.z<<"\n";check(std::memcmp(&expected,&actual,12)==0);
}
    for(unsigned i=0;i<value.model->nodes().size();++i){const auto& row=value.model->nodes()[i];const auto& link=value.model->links()[i];const auto at=nodes+400*i;
        if(std::memcmp(memory+at,&row.world,64)||std::memcmp(memory+at+0x40,&row.local,64)){std::cerr<<"node "<<i<<"\n";for(unsigned c=0;c<4;++c)for(unsigned l=0;l<4;++l){const float expected=transform_read<float>(memory,at+0x40+16*c+4*l);if(std::bit_cast<unsigned>(expected)!=std::bit_cast<unsigned>(row.local[c][l]))std::cerr<<" local "<<c<<','<<l<<" native "<<row.local[c][l]<<" source "<<expected<<"\n";}}
        check(std::memcmp(memory+at,&row.world,64)==0);
        check(std::memcmp(memory+at+0x40,&row.local,64)==0);
        check(std::memcmp(memory+at+0x104,row.parameters.data(),sizeof row.parameters)==0);
        check(std::memcmp(memory+at+0x15c,row.caches.data(),sizeof row.caches)==0);
        check(transform_read<unsigned>(memory,at+0xc8)==(link.parent?nodes+400*(*link.parent):0u));check(transform_read<unsigned>(memory,at+0xcc)==(link.sibling?nodes+400*(*link.sibling):0u));check(transform_read<unsigned>(memory,at+0xd0)==(link.child?nodes+400*(*link.child):0u));}
}
int main(int argc,char** argv)try{
    check(argc==2);_mm_setcsr(0x1f80);std::vector<std::uint8_t> memory(0x2000000);owned_constants(memory.data());put(memory.data(),0x294e00,t::identity());std::ifstream input(argv[1],std::ios::binary);unsigned count{};input.read(reinterpret_cast<char*>(&count),4);check(count==2);std::array<std::shared_ptr<const a::Skeleton>,2> skeletons;
    for(auto& skeleton:skeletons){unsigned size{};input.read(reinterpret_cast<char*>(&size),4);std::vector<std::byte> bytes(size);input.read(reinterpret_cast<char*>(bytes.data()),size);check(bool(input));skeleton=a::Skeleton::import_raw(bytes);}
    for(unsigned profile=0;profile<4;++profile)for(unsigned fixture=0;fixture<32;++fixture){profile_case=profile;w::Actor value;value.active=value.visible=true;value.character=7;value.model_pose_class=std::uint8_t(profile!=0);value.model=std::make_shared<a::Instance>(skeletons[profile!=0]);w::reset_secondary_pose_history(value);
        auto parent=t::identity();t::reset_euler_axes(parent,{std::uint16_t(fixture*1723),std::uint16_t(fixture*277),std::uint16_t(fixture*913)});parent[3]={float(fixture)*-3,float(fixture%7)*2,float(fixture%5)*-4,1};value.model->root_scale({1+float(fixture%3)*.25f,1+float(fixture%5)*.125f,1+float(fixture%7)*.125f});value.model->rebuild(parent);
        value.secondary_pose_history->displacement={{{float(fixture%3),-float(fixture%4),float(fixture%7)*.5f},{-float(fixture%5),float(fixture%3)*.25f,float(fixture%4)}}};project(memory.data(),value);
        for(unsigned step=0;step<12;++step){step_case=step;const auto previous=value.model->retain();const auto joints=previous->joints;invoke(memory.data(),0x61aaa0,actor,profile);check(w::apply_secondary_pose_dynamics(value,std::uint8_t(profile))==w::SecondaryPoseStatus::applied);compare(memory.data(),value);check(previous->joints==joints&&value.model->retain()!=previous);++lifetimes;++cases;}
    }
    for(int mode:{-32768,-1,0,1,2,257,32767})for(unsigned paused:{0u,1u})for(unsigned category:{0u,1u,2u})for(unsigned cls:{0u,1u})for(unsigned variant:{0u,53u,197u,207u,216u})for(unsigned character:{0u,7u,207u})for(unsigned override_value:{0u,1u,2u,3u,4u,255u,4294967295u}){
        w::Actor value;value.active=value.visible=true;value.category=std::uint8_t(category);value.character=std::uint8_t(character);value.model_pose_class=std::uint8_t(cls);value.model_variant=std::uint16_t(variant);value.secondary_pose_category_override=override_value;value.model=std::make_shared<a::Instance>(skeletons[cls]);w::reset_secondary_pose_history(value);value.model->rebuild(t::identity());project(memory.data(),value);put(memory.data(),0x324200,std::int16_t(mode));put(memory.data(),0x4badf8,std::uint8_t(paused));
        const auto selection=w::select_secondary_pose_dynamics(value,std::int16_t(mode),std::int8_t(paused));
        if(!selection.available||(selection.profile&&((*selection.profile>0&&!cls)||(*selection.profile==0&&cls))))continue;
        invoke(memory.data(),0x61a820,actor);const auto status=w::update_secondary_pose(value,std::int16_t(mode),std::int8_t(paused));if(status!=w::SecondaryPoseStatus::applied&&status!=w::SecondaryPoseStatus::unchanged)std::cerr<<"selector mode "<<mode<<" pause "<<paused<<" category "<<category<<" cls "<<cls<<" variant "<<variant<<" char "<<character<<" override "<<override_value<<" profile "<<unsigned(selection.profile.value_or(255))<<"\n";check(status==w::SecondaryPoseStatus::applied||status==w::SecondaryPoseStatus::unchanged);compare(memory.data(),value);check(bool(value.model->retain()));++selector_cases;
    }
    // Exercise the generic native publication API against the complete193260
    // body, including a root-sibling cut and arbitrary incoming parent scales.
    for(unsigned asset=0;asset<2;++asset)for(unsigned fixture=0;fixture<32;++fixture)for(bool siblings:{false,true})for(a::Vector incoming:{a::Vector{1,1,1},a::Vector{.75f,1.5f,2.25f}}){
        w::Actor value;value.model=std::make_shared<a::Instance>(skeletons[asset]);w::reset_secondary_pose_history(value);auto parent=t::identity();t::reset_euler_axes(parent,{std::uint16_t(fixture*1237),std::uint16_t(fixture*431),std::uint16_t(fixture*103)});parent[3]={float(fixture),float(fixture%7),-float(fixture%3),1};value.model->root_scale({1.5f,.75f,2.25f});value.model->rebuild(parent);project(memory.data(),value);
        constexpr unsigned root=21;auto local=value.model->nodes()[root].local;t::reset_euler_axes(local,{std::uint16_t(fixture*777),std::uint16_t(fixture*443),std::uint16_t(fixture*237)});put(memory.data(),nodes+400*root+0x40,local);const auto before=value.model->retain();const auto retained=before->joints;const auto old_sibling=transform_read<unsigned>(memory.data(),nodes+400*root+0xcc);if(!siblings)put(memory.data(),nodes+400*root+0xcc,0u);const auto base=value.model->nodes()[20].world;put(memory.data(),0x220000,base);invoke(memory.data(),0x193260,nodes+400*root,0x220000,incoming);put(memory.data(),nodes+400*root+0xcc,old_sibling);
        value.model->patch_local_poses_and_rebuild(std::array<a::LocalPosePatch,1>{{{root,local}}},root,base,siblings,incoming);compare(memory.data(),value);check(before->joints==retained&&value.model->retain()!=before);++model_api_cases;
    }
    // Original initializer61A620 establishes real zero history; unused record
    // suffixes retain their prior bytes rather than becoming invented state.
    std::fill_n(memory.data()+actor+0xe58,288,0x55);invoke(memory.data(),0x61a620,actor);for(unsigned chain=0;chain<4;++chain)for(unsigned joint=0;joint<2;++joint){const unsigned at=actor+0xe58+72*chain+36*joint;for(unsigned lane=0;lane<36;++lane)check(memory[at+lane]==(lane<12?0:0x55));}
    for(unsigned active:{0u,1u})for(unsigned visible:{0u,1u})for(unsigned flags:{0u,0x40u})for(unsigned appearance:{0u,1u}){
        w::Actor value;value.active=active;value.visible=visible;value.contact_flags=std::uint16_t(flags);value.appearance_variant=std::uint8_t(appearance);value.character=7;value.model=std::make_shared<a::Instance>(skeletons[0]);value.model->rebuild(t::identity());w::reset_secondary_pose_history(value);project(memory.data(),value);put(memory.data(),0x324200,std::int16_t(0));put(memory.data(),0x4badf8,std::uint8_t(1));invoke(memory.data(),0x61a820,actor);const auto result=w::update_secondary_pose(value,0,1);check(result==w::SecondaryPoseStatus::unchanged||result==w::SecondaryPoseStatus::applied);compare(memory.data(),value);++gates;
    }
    w::Actor missing;missing.active=missing.visible=true;check(!w::select_secondary_pose_dynamics(missing,1,0).available);check(w::apply_secondary_pose_dynamics(missing,0)==w::SecondaryPoseStatus::unavailable);++refusals;
    w::Actor cleared;check(!cleared.secondary_pose_history&&!cleared.secondary_pose_category_override);w::initialize_cleared_actor_defaults(cleared);check(cleared.secondary_pose_category_override==0&&cleared.secondary_pose_history.has_value());for(const auto& v:cleared.secondary_pose_history->displacement)check(v.x==0&&v.y==0&&v.z==0);
    auto model=std::make_shared<a::Instance>(skeletons[0]);model->rebuild(t::identity());const auto snapshot=model->retain();const auto before=std::vector<a::NodePose>(model->nodes().begin(),model->nodes().end());auto invalid=t::identity();invalid[0][0]=std::numeric_limits<float>::infinity();bool caught{};try{model->patch_local_poses_and_rebuild(std::array<a::LocalPosePatch,1>{{{21,invalid}}},21,t::identity());}catch(const std::domain_error&){caught=true;}check(caught&&model->retain()==snapshot&&std::memcmp(before.data(),model->nodes().data(),before.size()*sizeof(a::NodePose))==0);++refusals;
    caught=false;try{model->patch_local_poses(std::array<a::LocalPosePatch,2>{{{21,t::identity()},{model->nodes().size(),t::identity()}}});}catch(const std::out_of_range&){caught=true;}check(caught&&model->retain()==snapshot&&std::memcmp(before.data(),model->nodes().data(),before.size()*sizeof(a::NodePose))==0);++refusals;
    caught=false;try{model->patch_local_poses_and_rebuild({},21,t::identity(),true,{0,1,1});}catch(const std::domain_error&){caught=true;}check(caught&&model->retain()==snapshot&&std::memcmp(before.data(),model->nodes().data(),before.size()*sizeof(a::NodePose))==0);++refusals;
    auto changed=before[21].local;changed[3][0]+=3;model->patch_local_poses(std::array<a::LocalPosePatch,1>{{{21,changed}}});check(!model->retain()&&model->nodes()[21].world==before[21].world&&model->nodes()[21].parameters==before[21].parameters&&model->nodes()[21].caches==before[21].caches);++model_api_cases;
    std::cout<<"{\"checks\":"<<checks<<",\"complete_dynamics_cases\":"<<cases<<",\"complete_selector_cases\":"<<selector_cases<<",\"snapshot_lifetimes\":"<<lifetimes<<",\"refusals\":"<<refusals<<",\"source_calls\":"<<calls<<",\"model_api_cases\":"<<model_api_cases<<",\"gate_cases\":"<<gates<<",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
