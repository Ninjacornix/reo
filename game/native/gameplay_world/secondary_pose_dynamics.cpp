#include "secondary_pose_dynamics.hpp"
#include "secondary_pose_contacts.hpp"
#include "../animation/model.hpp"
#include "../animation/constraint_math.hpp"
#include "../transform_math/heading.hpp"
#include <bit>
#include <cmath>
#include <new>
namespace reo::native::gameplay_world {
namespace {
using animation::Vector;using animation::Matrix;using animation::NodeLink;using animation::NodeLinkPatch;
namespace m=animation::constraint_math;namespace t=transform_math;
#include "secondary_pose_link_profiles.inc"
template<std::size_t N>SecondaryPoseSelection selected(const std::array<std::uint8_t,N>& table,std::size_t index,bool contacts=false){
    if(index>=N)return{false,contacts,{}};
    return{true,contacts,table[index]==255?std::optional<std::uint8_t>{}:table[index]};
}
Vector position(const Matrix& matrix){return{matrix[3][0],matrix[3][1],matrix[3][2]};}
Vector scale(Vector v,float f){return{v.x*f,v.y*f,v.z*f};}
Vector cross(Vector a,Vector b){return{a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x};}
float dot(Vector a,Vector b){return(a.x*b.x+a.y*b.y)+a.z*b.z;}
Matrix rotation(float z,float x){
    const auto trig=t::sin_cos(z);auto rz=t::identity();rz[0]={0+trig.cosine,0+trig.sine,0,0};rz[1]={0-trig.sine,0+trig.cosine,0,0};
    auto result=t::identity();const auto rx=m::rotation_x(x);
    for(unsigned i=0;i<3;++i){auto v=t::direction(rz,{result[i][0],result[i][1],result[i][2]});v=t::direction(rx,v);result[i][0]=v.x;result[i][1]=v.y;result[i][2]=v.z;}
    return result;
}
}
SecondaryPoseSelection select_secondary_pose_dynamics(const Actor& actor,std::int16_t mode,std::int8_t paused)noexcept{
    if(!actor.active||!actor.visible||(actor.contact_flags&0x40))return{};
    auto category=actor.category;
    if(mode==1&&!paused){
        if(!actor.secondary_pose_category_override)return{false,false,{}};
        const auto value=*actor.secondary_pose_category_override;
        if(value!=0&&value!=1&&value!=3&&value!=4)return{};
        category=0;
    }
    if(category==0){
        if(actor.model_variant)return selected(ordinary_variant_secondary_links,actor.character);
        if(actor.model_pose_class==1)return selected(high_character_secondary_links,actor.character,true);
        auto result=selected(ordinary_character_secondary_links,actor.character,true);
        if(actor.appearance_variant)result.profile.reset();
        return result;
    }
    if(category==1)return actor.model_pose_class==1?selected(high_variant_secondary_links,actor.model_variant):selected(ordinary_variant_secondary_links,actor.model_variant);
    return{};
}
void reset_secondary_pose_history(Actor& actor)noexcept{actor.secondary_pose_history=SecondaryPoseHistory{};}
SecondaryPoseStatus apply_secondary_pose_dynamics(Actor& actor,std::uint8_t profile)noexcept{
    if(profile>3||!actor.secondary_pose_history||!actor.model||!actor.model->retain())return SecondaryPoseStatus::unavailable;
    constexpr std::array<unsigned,4> first{36,73,75,73};const auto start=first[profile];
    const auto nodes=actor.model->nodes();if(nodes.size()<=start+1||nodes.size()<=21)return SecondaryPoseStatus::unavailable;
    try{
        const Matrix root=nodes[21].world;auto parent=root;auto history=*actor.secondary_pose_history;
        const auto normal=t::direction(nodes[10].world,profile==3?Vector{0,std::bit_cast<float>(0x3e99999au),-1}:Vector{0,std::bit_cast<float>(0xbe99999au),-1});
        const auto preferred=m::add(Vector{0,-1,0},t::direction(root,{0,-.5f,0}));
        std::array<animation::LocalPosePatch,2> patches;
        for(unsigned joint=0;joint<2;++joint){
            const auto index=start+joint;const auto& node=nodes[index];
            if(joint){const auto predecessor=actor.model->links()[index].parent;if(!predecessor)return SecondaryPoseStatus::unavailable;const auto& prior=patches[0];parent=m::product(parent,*predecessor==prior.node?prior.local:nodes[*predecessor].local);}
            const auto rest=m::add(position(parent),t::direction(parent,position(node.local)));
            auto force=m::add(t::direction(node.world,{0,-10,0}),scale(m::subtract(position(node.world),rest),1.5f));
            auto tangent=m::normalize(cross(cross(force,preferred),force));tangent=scale(tangent,dot(tangent,preferred));
            auto& displacement=history.displacement[joint];displacement=m::add(displacement,tangent);force=m::add(force,displacement);
            auto tip=m::add(rest,force);const auto inverse=m::inverse_scaled(parent);
            //6F0F30 projects toward the normal whenever the one-sided gap
            // is positive or lies within the admitted per-joint thickness.
            const auto unit=m::normalize(normal);const float gap=dot(unit,m::subtract(position(root),tip));const float radius=joint?13.f:8.f;
            if(!(gap<=0)||-gap<=radius)tip=m::add(tip,scale(unit,gap+radius));
            const auto direction=m::normalize(t::direction(inverse,m::subtract(rest,tip)));
            const float x=t::quadrant_angle(direction.z,direction.y);const float z=t::quadrant_angle(-direction.x,m::square_root(direction.y*direction.y+direction.z*direction.z));
            auto local=node.local;const auto axes=rotation(z,x);for(unsigned column=0;column<3;++column)for(unsigned lane=0;lane<3;++lane)local[column][lane]=axes[column][lane];
            patches[joint]={index,local};displacement=scale(displacement,std::bit_cast<float>(0x3f4ccccdu));
        }
        actor.model->patch_local_poses_and_rebuild(patches,start,root);actor.secondary_pose_history=history;return SecondaryPoseStatus::applied;
    }catch(const std::bad_alloc&){return SecondaryPoseStatus::no_memory;}catch(...){return SecondaryPoseStatus::unavailable;}
}
SecondaryPoseStatus update_secondary_pose(Actor& actor,std::int16_t mode,std::int8_t paused)noexcept{
    const auto selection=select_secondary_pose_dynamics(actor,mode,paused);if(!selection.available)return SecondaryPoseStatus::unavailable;
    bool applied{};
    if(selection.contacts){const auto status=apply_secondary_pose_contacts(actor);if(status==SecondaryPoseContactsStatus::unavailable)return SecondaryPoseStatus::unavailable;if(status==SecondaryPoseContactsStatus::no_memory)return SecondaryPoseStatus::no_memory;applied=status==SecondaryPoseContactsStatus::applied;}
    if(!selection.profile)return applied?SecondaryPoseStatus::applied:SecondaryPoseStatus::unchanged;
    const auto status=apply_secondary_pose_dynamics(actor,*selection.profile);if(status!=SecondaryPoseStatus::applied)return status;
    try{
        std::array<NodeLinkPatch,2> links{};std::size_t count=1;
        switch(*selection.profile){case 0:links={{{21,NodeLink::child,36},{36,NodeLink::sibling,22}}};count=2;break;case 1:links[0]={62,NodeLink::sibling,73};break;case 2:links[0]={64,NodeLink::sibling,75};break;case 3:links[0]={62,NodeLink::sibling,73};break;default:return SecondaryPoseStatus::unavailable;}
        actor.model->patch_links_preserving_world(std::span<const NodeLinkPatch>(links.data(),count));return SecondaryPoseStatus::applied;
    }catch(const std::bad_alloc&){return SecondaryPoseStatus::no_memory;}catch(...){return SecondaryPoseStatus::unavailable;}
}
}
