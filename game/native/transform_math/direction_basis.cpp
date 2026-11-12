#include "direction_basis.hpp"
#include <cmath>
#include <limits>
namespace reo::native::transform_math {
namespace {
Vector normalize(Vector value){
    const float x=value.x*value.x,y=value.y*value.y,z=value.z*value.z;
    const float xy=x+y,squared=xy+z;
    const float reciprocal=squared>0?1.f/std::sqrt(squared):std::numeric_limits<float>::max();
    return{value.x*reciprocal,value.y*reciprocal,value.z*reciprocal};
}
Vector cross(Vector a,Vector b){return{a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x};}
}
Matrix direction_basis(Vector forward,Vector auxiliary){
    Matrix value{};direction_basis(value,forward,auxiliary);return value;
}
void direction_basis(Matrix& value,Vector forward,Vector auxiliary){
    require_profile();auxiliary=normalize(auxiliary);forward=normalize(forward);
    const auto right=normalize(cross(auxiliary,forward)),up=cross(forward,right);
    value[0]={right.x,right.y,right.z,0};value[1]={up.x,up.y,up.z,0};value[2]={forward.x,forward.y,forward.z,0};value[3][3]=1;
}
Matrix inverse_orthonormal(Matrix value){
    require_profile();const auto previous=value;
    for(unsigned column=0;column<3;++column){
        for(unsigned lane=0;lane<3;++lane)value[column][lane]=0.f+previous[lane][column];
        value[column][3]=previous[column][3]+0.f;
    }
    const auto translated=direction(value,{-previous[3][0],-previous[3][1],-previous[3][2]});
    value[3][0]=translated.x;value[3][1]=translated.y;value[3][2]=translated.z;return value;
}
}
