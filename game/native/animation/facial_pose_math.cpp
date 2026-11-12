#include "facial_pose_math.hpp"
#include <cmath>
#include <stdexcept>
namespace reo::native::animation {
namespace {
using transform_math::Matrix;
using transform_math::Vector;
float finite(float value){
    if(!std::isfinite(value))throw std::domain_error("Native facial finite numeric profile required");
    return value;
}
Vector normalize(Vector value){
    const auto x=finite(value.x*value.x),y=finite(value.y*value.y),z=finite(value.z*value.z);
    const auto length=std::sqrt(finite(z+finite(y+x)));
    if(length==0)return{};
    return{finite(value.x/length),finite(value.y/length),finite(value.z/length)};
}
Vector cross(Vector first,Vector second){
    return{finite(first.y*second.z-second.y*first.z),
           finite(first.z*second.x-second.z*first.x),
           finite(first.x*second.y-second.x*first.y)};
}
float weighted(const FacialMatrices& matrices,const FacialWeights& weights,unsigned row,unsigned lane){
    for(unsigned index=0;index<6;++index)finite(matrices[index][row][lane]);
    // Preserve the accumulator's initial pair and subsequent additions. In
    // particular there is no extra initial +0 or fused multiply/add.
    const auto first=weights[0]*matrices[0][row][lane];
    const auto second=weights[1]*matrices[1][row][lane];
    const auto pair=row==0&&lane==0?finite(second+first):finite(first+second);
    const auto third=finite(weights[2]*matrices[2][row][lane]+pair);
    const auto fourth=finite(third+weights[3]*matrices[3][row][lane]);
    const auto fifth=finite(weights[4]*matrices[4][row][lane]+fourth);
    return finite(fifth+weights[5]*matrices[5][row][lane]);
}
}
transform_math::Matrix facial_basis(transform_math::Vector first,transform_math::Vector second,
    transform_math::Vector translation){
    transform_math::require_profile();
    first=normalize(first);second=normalize(second);const auto third=normalize(cross(first,second));
    second=cross(third,first);auto result=transform_math::identity();
    result[0]={first.x,first.y,first.z,0};result[1]={second.x,second.y,second.z,0};
    result[2]={third.x,third.y,third.z,0};
    result[3]={translation.x,translation.y,translation.z,1};
    return result;
}
transform_math::Matrix blend_facial_pose(const FacialMatrices& matrices,const FacialWeights& weights){
    transform_math::require_profile();for(const auto weight:weights)finite(weight);
    const auto direction=[&](unsigned row){return transform_math::Vector{
        weighted(matrices,weights,row,0),weighted(matrices,weights,row,1),weighted(matrices,weights,row,2)};};
    return facial_basis(direction(0),direction(1),direction(3));
}
} // namespace reo::native::animation
