#include "secondary_pose_contacts.hpp"
#include "../animation/model.hpp"
#include "../animation/secondary_pose_math.hpp"
#include <bit>
#include <new>
namespace reo::native::gameplay_world {
SecondaryPoseContactsStatus apply_secondary_pose_contacts(Actor& actor)noexcept{
    if(actor.character!=7||actor.appearance_variant||actor.model_variant)return SecondaryPoseContactsStatus::unchanged;
    if(!actor.model||!actor.model->retain())return SecondaryPoseContactsStatus::unavailable;
    const auto nodes=actor.model->nodes();const unsigned target=actor.model_pose_class==1?76:39;
    if(nodes.size()<=target+3)return SecondaryPoseContactsStatus::unavailable;
    try{
        namespace m=animation::constraint_math;
        using animation::Vector;
        const auto position=[](const animation::Matrix& matrix){return Vector{matrix[3][0],matrix[3][1],matrix[3][2]};};
        const auto scaled=[](Vector value,float scale){return Vector{value.x*scale,value.y*scale,value.z*scale};};
        constexpr std::array<unsigned,4> anchors{4,5,7,8};
        constexpr std::array<Vector,2> offsets{{{0,std::bit_cast<float>(0xc129999au),10.5f},{0,std::bit_cast<float>(0xc1fb3333u),10.5f}}};
        std::array<Vector,4> points;
        std::array<animation::PoseCapsule,2> capsules;
        for(unsigned side=0;side<2;++side){
            const auto& first=nodes[anchors[2*side]].world;
            for(unsigned row=0;row<2;++row)points[2*side+row]=m::add(transform_math::direction(first,offsets[row]),position(first));
            capsules[side]=animation::prepare_pose_capsule(position(first),position(nodes[anchors[2*side+1]].world),10.5f);
        }
        std::array<animation::JointPosePatch,4> patches;
        for(unsigned row=0;row<2;++row){
            const auto direction=m::normalize(m::subtract(points[row+2],points[row]));
            for(unsigned side=0;side<2;++side){
                const auto ordinal=2*side+row;const auto source=anchors[2*side];const auto offset=scaled(direction,std::bit_cast<float>(side?0xc08ccccdu:0x408ccccdu));
                auto corrected=m::add(offset,points[ordinal]);Vector contact;
                if(animation::constrain_pose_point(corrected,1,capsules[side],contact))corrected=contact;
                auto matrix=nodes[source].world;matrix[3][0]=corrected.x;matrix[3][1]=corrected.y;matrix[3][2]=corrected.z;
                patches[ordinal]={target+ordinal,matrix};
            }
        }
        actor.model->patch_world_poses(patches);return SecondaryPoseContactsStatus::applied;
    }catch(const std::bad_alloc&){return SecondaryPoseContactsStatus::no_memory;}
    catch(...){return SecondaryPoseContactsStatus::unavailable;}
}
}
