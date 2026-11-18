#include "game/native/gameplay_world/secondary_pose_contacts.hpp"
#include "game/native/animation/model.hpp"
#include <fstream>
namespace w=reo::native::gameplay_world;
std::uint64_t contact_gates{},contact_models{},contact_refusals{},joint_patches{};
void contacts_tests(std::uint8_t* memory,const char* path){
    constexpr unsigned actor=0x200000,work=0x210000,nodes=0x300000;
    const auto export_actor=[&](const w::Actor& value){
        transform_write(memory,actor+0xb98,value.character);transform_write(memory,actor+0xbbc,value.appearance_variant);transform_write(memory,actor+0xbb4,value.model_variant);transform_write(memory,actor+0x54d,value.model_pose_class);transform_write(memory,actor+0x34,work);
    };
    for(unsigned character:{0u,7u,255u})for(unsigned appearance:{0u,1u,255u})for(unsigned variant:{0u,1u,65535u}){
        if(character==7&&appearance==0&&variant==0)continue;
        w::Actor value;value.character=std::uint8_t(character);value.appearance_variant=std::uint8_t(appearance);value.model_variant=std::uint16_t(variant);export_actor(value);
        check(w::apply_secondary_pose_contacts(value)==w::SecondaryPoseContactsStatus::unchanged);invoke(memory,0x61b920,actor,0);++contact_gates;
    }
    std::ifstream input(path,std::ios::binary);check(bool(input));unsigned count{};input.read(reinterpret_cast<char*>(&count),4);check(count==2);
    for(unsigned asset=0;asset<count;++asset){
        unsigned size{};input.read(reinterpret_cast<char*>(&size),4);check(size&&size<0x100000);std::vector<std::byte> bytes(size);input.read(reinterpret_cast<char*>(bytes.data()),size);check(bool(input));const auto skeleton=a::Skeleton::import_raw(bytes);check(skeleton->nodes().size()==(asset?80u:43u));
        for(unsigned test=0;test<128;++test){
            w::Actor value;value.character=7;value.model_pose_class=std::uint8_t(asset);value.model=std::make_shared<a::Instance>(skeleton);
            auto parent=reo::native::transform_math::identity();reo::native::transform_math::compose_euler_axes(parent,{std::uint16_t(test*1237),std::uint16_t(test*719),std::uint16_t(test*2719)});parent[3]={float(test)-17.f,float(test%11)*.25f,float(test%9)*-3.f,1};
            value.model->root_scale({1+float(test%3)*.125f,1+float(test%5)*.125f,1+float(test%7)*.125f});value.model->rebuild(parent);
            const auto before=value.model->retain();const auto old_joints=before->joints;const auto local=std::vector<a::NodePose>(value.model->nodes().begin(),value.model->nodes().end());export_actor(value);
            for(unsigned n=0;n<skeleton->nodes().size();++n){transform_write(memory,work+0x820+4*n,nodes+400*n);std::memcpy(memory+nodes+400*n,&value.model->nodes()[n].world,64);}
            invoke(memory,0x61b920,actor,0);check(w::apply_secondary_pose_contacts(value)==w::SecondaryPoseContactsStatus::applied);
            const auto after=value.model->retain();check(after&&after!=before&&after->revision==before->revision+1&&before->joints==old_joints);
            for(unsigned n=0;n<skeleton->nodes().size();++n){
                check(std::memcmp(&value.model->nodes()[n].world,memory+nodes+400*n,64)==0);
                check(after->joints[n]==value.model->nodes()[n].world&&value.model->nodes()[n].parameters==local[n].parameters&&value.model->nodes()[n].local==local[n].local);
            }
            ++contact_models;joint_patches+=4;
            if(test==0){
                const auto retained=after;const std::array<a::JointPosePatch,1> bad{{{skeleton->nodes().size(),parent}}};bool caught{};try{value.model->patch_world_poses(bad);}catch(const std::out_of_range&){caught=true;}check(caught&&value.model->retain()==retained);++contact_refusals;
                auto invalid=parent;invalid[0][0]=std::numeric_limits<float>::infinity();caught=false;try{value.model->patch_world_poses(std::array<a::JointPosePatch,1>{{{0,invalid}}});}catch(const std::domain_error&){caught=true;}check(caught&&value.model->retain()==retained);++contact_refusals;
                value.model->patch_world_poses({});check(value.model->retain()==retained);
                value.model->local_translation(0,{});check(!value.model->retain()&&w::apply_secondary_pose_contacts(value)==w::SecondaryPoseContactsStatus::unavailable);++contact_refusals;
            }
        }
        if(!asset){w::Actor small;small.character=7;small.model_pose_class=1;small.model=std::make_shared<a::Instance>(skeleton);small.model->rebuild(reo::native::transform_math::identity());const auto retained=small.model->retain();check(w::apply_secondary_pose_contacts(small)==w::SecondaryPoseContactsStatus::unavailable&&small.model->retain()==retained);++contact_refusals;}
    }
    w::Actor absent;absent.character=7;check(w::apply_secondary_pose_contacts(absent)==w::SecondaryPoseContactsStatus::unavailable);++contact_refusals;
}
