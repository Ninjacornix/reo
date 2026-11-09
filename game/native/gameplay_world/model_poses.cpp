#include "model_poses.hpp"
#include <algorithm>
#include <bit>
#include <cmath>
#include <stdexcept>

namespace reo::native::gameplay_world {
namespace {
struct ScaleEntry {std::uint16_t id;std::uint32_t bits;};
#include "model_scale_profile.inc"
float finite(float v){if(!std::isfinite(v))throw std::domain_error("Native actor model finite profile required");return v;}
auto matrix(const gameplay_collision::actors::Basis& b){return animation::Matrix{{{b.x.x,b.x.y,b.x.z,0},{b.y.x,b.y.y,b.y.z,0},{b.z.x,b.z.y,b.z.z,0},{b.translation.x,b.translation.y,b.translation.z,1}}};}
auto basis(const animation::Matrix& m){
    for(unsigned i=0;i<3;++i)if(m[i][3]!=0)throw std::domain_error("Native collision joint affine basis required");
    if(m[3][3]!=1)throw std::domain_error("Native collision joint affine translation required");
    return gameplay_collision::actors::Basis{{m[0][0],m[0][1],m[0][2]},{m[1][0],m[1][1],m[1][2]},{m[2][0],m[2][1],m[2][2]},{m[3][0],m[3][1],m[3][2]}};
}
}
float File1ModelCorrectionScales::character(std::uint8_t id)const{
    if(id>=player_scale_bits.size())throw std::out_of_range("Native player model scale profile unavailable");
    return std::bit_cast<float>(player_scale_bits[id]);
}
float File1ModelCorrectionScales::variant(std::uint16_t id)const{
    const auto it=std::lower_bound(variant_scale_bits.begin(),variant_scale_bits.end(),id,[](const auto& entry,auto value){return entry.id<value;});
    if(it==variant_scale_bits.end()||it->id!=id)throw std::out_of_range("Native NPC model scale profile unavailable");
    return std::bit_cast<float>(it->bits);
}
void correct_model_height(World& world,Actor& actor,const ModelCorrectionScales& scales){
    if(world.paused!=0&&actor.model_correction_skip==1)return;
    if(!actor.model)throw std::runtime_error("Required canonical native model unavailable");
    const float height=actor.model->world_translation(21).y;
    const float excess=finite(finite(height-actor.position.y)-std::bit_cast<float>(0x423c3333u));
    if(excess<=0)return;
    float gain=0;
    if(actor.category==0||actor.category==1){
        const float base=actor.model_variant?scales.variant(actor.model_variant):scales.character(actor.character);
        gain=finite(actor.model_height_correction*finite(actor.model_scale.y/base));
    }else if(actor.category==2)gain=finite(actor.model_height_correction);
    float amount=finite(finite(excess*gain)/std::bit_cast<float>(0x42876148u));
    if(amount<gain)amount=gain;
    auto local=actor.model->local_translation(1);local.y=amount;actor.model->local_translation(1,local);
}
void rebuild_standard_model(World& world,Actor& actor,ModelPoseKind kind,const ModelCorrectionScales& scales){
    if(!actor.active)return;
    if(!actor.model)throw std::runtime_error("Required canonical native model unavailable");
    actor.collision.basis.translation={actor.position.x,actor.position.y,actor.position.z};
    actor.model->root_scale({actor.model_scale.x,actor.model_scale.y,actor.model_scale.z});
    correct_model_height(world,actor,scales);
    if(kind==ModelPoseKind::primary&&!(actor.contact_flags&0x12)&&world.paused==0)throw std::runtime_error("Required native actor constraint5D6400 owner unavailable");
    actor.model->rebuild(matrix(actor.collision.basis));
    if(actor.model->nodes().size()>2){const auto joint=actor.model->world_translation(2);actor.collision.joint_two_position=gameplay_collision::Vec3{joint.x,joint.y,joint.z};}
    else actor.collision.joint_two_position.reset();
}
std::shared_ptr<const JointPose> WorldModelPoses::retain(const actors::EntityId& id,const Actor& actor){
    auto lease=world_.resolve(id);if(!lease||lease.get()!=&actor||!lease->model)return{};
    auto source=lease->model->retain();if(!source)return{};
    auto result=std::make_shared<JointPose>();result->joints.reserve(source->joints.size());
    for(const auto& joint:source->joints)result->joints.push_back(basis(joint));
    return result;
}
} // namespace reo::native::gameplay_world
