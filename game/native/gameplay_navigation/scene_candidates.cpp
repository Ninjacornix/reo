#include "scene_candidates.hpp"
#include "../transform_math/transform_math.hpp"
#include <bit>
#include <cmath>
#include <stdexcept>
#include <utility>
namespace reo::native::gameplay_navigation {
SceneCandidates collect_scene_candidates(const gameplay_scene::Records& records,Position actor,Position query,float radius)noexcept{
    namespace collision=gameplay_collision;
    SceneCandidates result;
    const auto point=collision::integer_xz({query.x,query.y,query.z});
    if(!point||!std::isfinite(query.y)||!std::isfinite(radius))return result;
    result.sampled_position=query;
    std::array<std::uint8_t,128> priorities{};
    for(auto node=records.first();node;node=node->next){
        ++result.visited;const auto& record=node->value;if(!record.enabled)continue;
        if(!record.collision)return result;
        const auto& shape=*record.collision;if(shape.busy)continue;
        const auto kind=gameplay_scene::kind(record.body);
        bool geometry{};
        if(kind==0x80||kind==0x81)geometry=collision::overlaps(shape.bounds,*point,radius);
        else if(kind==0x85){
            const auto actual=collision::integer_xz({actor.x,actor.y,actor.z});if(!actual)return result;
            geometry=collision::contains(shape.bounds,*actual);
        }else geometry=collision::contains(shape.bounds,*point);
        if(!geometry||!collision::admits_height(shape.lower,shape.upper,query.y))continue;
        if(result.count==result.records.size())return result;
        priorities[result.count]=record.counter;result.records[result.count++]=node->id;
    }
    // count-1 is deliberately the INNER exclusive bound as well. A sorted
    // prefix does not imply the final element participates in comparisons.
    for(std::size_t i=0;i+1<result.count;++i)for(std::size_t j=i+1;j+1<result.count;++j){
        if(priorities[j]<priorities[i]){std::swap(priorities[i],priorities[j]);std::swap(result.records[i],result.records[j]);}
    }
    result.status=QueryStatus::completed;return result;
}
SceneCandidates collect_actor_scene_candidates(const gameplay_scene::Records& records,Position actor,std::uint8_t motion_class,std::uint16_t yaw,float local_center_z)noexcept{
    auto query=actor;
    if(motion_class!=0x1a){
        if(!std::isfinite(local_center_z))return {};
        try{
            const auto trig=transform_math::sin_cos(std::bit_cast<float>(0x38c90fdbu)*float(yaw));
            const float distance=46.f+local_center_z;
            query.x=actor.x+distance*trig.sine;query.z=actor.z+distance*trig.cosine;
        }catch(const std::domain_error&){return {};}
    }
    return collect_scene_candidates(records,actor,query,50.f);
}
}
