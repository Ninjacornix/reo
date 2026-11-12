#include "game/native/gameplay_world/secondary_pose_links.hpp"
#include "game/native/animation/model.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <fstream>
#include <iostream>
#include <vector>
namespace g=reo::native::gameplay_world;
namespace a=reo::native::animation;
constexpr std::uint32_t actor=0x200000,work=0x210000,nodes=0x100000;
std::uint64_t checks{},original_calls{},selection_cases{},selection_refusals{},model_cases{},model_refusals{},controlled_npc_cases{};
bool capture{};std::vector<std::uint32_t> observed;
void check(bool value,const char* why){++checks;if(!value)throw std::runtime_error(why);}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++original_calls;
    if(context->pc==0x61b1a0&&capture){
        check(GPR_U32(context,4)==work+0x820,"selected original node-array identity");observed.push_back(GPR_U32(context,5));context->pc=GPR_U32(context,31);return;
    }
    if(context->pc==0x61a6a0){o2_0061A6A0_0x61a6a0(memory,context,runtime);return;}
    if(context->pc==0x61b1a0){o2_0061B1A0_0x61b1a0(memory,context,runtime);return;}
    throw std::runtime_error("undeclared secondary link original call");
}
void call(std::uint8_t* memory){
    R5900Context context;context.pc=0x61a6a0;SET_GPR_U32(&context,4,actor);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xabcdef);PS2Runtime runtime;
    original_transform_port(memory,&context,&runtime);check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x1f00000,"complete original selector return and stack");
}
void export_actor(std::uint8_t* memory,const g::Actor& value){
    transform_write(memory,actor,std::uint8_t(value.active));transform_write(memory,actor+1,std::uint8_t(value.visible));transform_write(memory,actor+2,value.category);
    transform_write(memory,actor+0x54a,value.contact_flags);transform_write(memory,actor+0x54d,value.model_pose_class);transform_write(memory,actor+0xb98,value.character);
    transform_write(memory,actor+0xbb4,value.model_variant);transform_write(memory,actor+0xbbc,value.appearance_variant);transform_write(memory,actor+0x34,work);
}
void compare_model(const a::Instance& model,const std::vector<std::uint8_t>& memory){
    for(unsigned i=0;i<model.links().size();++i){
        const auto& row=model.links()[i];for(auto [target,offset]:{std::pair{row.parent,0xc8u},std::pair{row.child,0xd0u},std::pair{row.sibling,0xccu}})
            check((target?nodes+400*unsigned(*target):0u)==transform_read<std::uint32_t>(memory.data(),nodes+400*i+offset),"actual selected restore link output");
    }
}
int main(int argc,char** argv)try{
    check(argc==2,"owned skeleton package required");std::vector<std::uint8_t> memory(0x2000000);owned_constants(memory.data());
    g::Actor value;
    for(bool active:{false,true})for(bool visible:{false,true})for(unsigned flags:{0u,0x40u})
    for(unsigned category:{0u,1u,2u,255u})for(unsigned kind:{0u,1u,2u,255u})
    for(unsigned encoded=0;encoded<226;++encoded)for(unsigned character:{0u,7u,255u})for(unsigned appearance:{0u,1u,255u}){
        value.active=active;value.visible=visible;value.contact_flags=std::uint16_t(flags);value.category=std::uint8_t(category);value.model_pose_class=std::uint8_t(kind);
        value.model_variant=std::uint16_t(encoded==225?65535:encoded);value.character=std::uint8_t(character);value.appearance_variant=std::uint8_t(appearance);
        const auto selected=g::select_secondary_pose_links(value);
        if(!selected.available){check(g::restore_secondary_pose_links(value).status==g::SecondaryPoseLinksStatus::unavailable,"unowned selector indices remain visibly unavailable");++selection_refusals;continue;}
        export_actor(memory.data(),value);capture=true;observed.clear();call(memory.data());capture=false;
        if(selected.profile){check(observed.size()==1&&observed[0]==transform_read<std::uint32_t>(memory.data(),0x70f650+4*unsigned(*selected.profile)),"native selected profile equals full original dispatch");check(g::restore_secondary_pose_links(value).status==g::SecondaryPoseLinksStatus::unavailable,"required selected model cannot become a successful no-op");}
        else check(observed.empty()&&g::restore_secondary_pose_links(value).status==g::SecondaryPoseLinksStatus::unchanged,"original no-work path requires no invented model");
        ++selection_cases;
    }
    std::ifstream input(argv[1],std::ios::binary);std::uint32_t count{};input.read(reinterpret_cast<char*>(&count),4);check(count==4,"actual P07/HP07/HN54/HN88 skeleton inputs");
    for(unsigned asset=0;asset<count;++asset){
        std::uint32_t size{};input.read(reinterpret_cast<char*>(&size),4);check(size&&size<0x40000,"bounded owned skeleton extent");std::vector<std::byte> raw(size);input.read(reinterpret_cast<char*>(raw.data()),size);check(bool(input),"complete owned skeleton read");
        const auto skeleton=a::Skeleton::import_raw(raw);check(skeleton->nodes().size()==std::array<unsigned,4>{43,80,75,75}[asset],"actual owned player/NPC model cardinality");
        for(unsigned test=0;test<32;++test){
            value=g::Actor{};value.model=std::make_shared<a::Instance>(skeleton);value.active=bool(test&1);value.visible=bool(test&2);value.contact_flags=test&4?0x40:0;
            value.category=0;value.character=7;value.appearance_variant=std::uint8_t((test>>3)&1);value.model_pose_class=std::uint8_t(asset!=0);
            if(asset>=2){value.category=1;value.character=5;value.model_variant=std::uint16_t(asset==2?54:88);}
            // Profile2 has no proven stock NPC asset binding in this cohort.
            // Its bounded patch mechanics use an explicitly controlled HP07.
            if(asset==1&&test>=24){value.active=value.visible=true;value.contact_flags=0;value.appearance_variant=0;value.category=1;value.model_variant=199;++controlled_npc_cases;}
            for(unsigned i=0;i<skeleton->nodes().size();++i){
                transform_write(memory.data(),work+0x820+4*i,nodes+400*i);
                const auto& definition=skeleton->nodes()[i];for(auto [link,offset]:{std::pair{definition.parent,0xc8u},std::pair{definition.child,0xd0u},std::pair{definition.sibling,0xccu}})transform_write(memory.data(),nodes+400*i+offset,link?nodes+400*unsigned(*link):0u);
            }
            export_actor(memory.data(),value);
            for(unsigned repetition=0;repetition<2;++repetition){
                const auto selected=g::select_secondary_pose_links(value);const auto result=g::restore_secondary_pose_links(value);call(memory.data());
                check(result.status==(selected.profile?g::SecondaryPoseLinksStatus::restored:g::SecondaryPoseLinksStatus::unchanged)&&result.profile==selected.profile,"actual-model restore status and idempotent repeat");compare_model(*value.model,memory);++model_cases;
            }
            if(asset==0&&test==0){
                value.active=value.visible=true;value.category=1;value.model_pose_class=1;value.model_variant=199;const auto before=std::vector<a::NodeLinks>(value.model->links().begin(),value.model->links().end());
                check(g::restore_secondary_pose_links(value).status==g::SecondaryPoseLinksStatus::unavailable&&std::equal(before.begin(),before.end(),value.model->links().begin()),"insufficient selected model topology refuses atomically");++model_refusals;
            }
        }
    }
    std::cout<<"{\"checks\":"<<checks<<",\"selection_cases\":"<<selection_cases<<",\"selection_refusals\":"<<selection_refusals<<",\"model_cases\":"<<model_cases<<",\"model_refusals\":"<<model_refusals<<",\"controlled_npc_cases\":"<<controlled_npc_cases<<",\"original_calls\":"<<original_calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
