#include "constraint_math.hpp"
#include <cmath>
#include <limits>
#include <stdexcept>

namespace reo::native::animation::constraint_math {
namespace {
float finite(float v){if(!std::isfinite(v))throw std::domain_error("Native model constraint finite FP32 arithmetic required");return v;}
float plus(float a,float b){return finite(a+b);}
float minus(float a,float b){return finite(a-b);}
float times(float a,float b){return finite(a*b);}
Vector cross(Vector a,Vector b){return{minus(times(a.y,b.z),times(a.z,b.y)),minus(times(a.z,b.x),times(a.x,b.z)),minus(times(a.x,b.y),times(a.y,b.x))};}
Vector normalized(Vector v){const float squared=squared_length(v);const float q=squared>0?finite(1.f/std::sqrt(squared)):std::numeric_limits<float>::max();return{times(v.x,q),times(v.y,q),times(v.z,q)};}
void axis(Matrix& m,unsigned i,Vector v){m[i]={v.x,v.y,v.z,0};}
}
Vector add(Vector a,Vector b){return{plus(a.x,b.x),plus(a.y,b.y),plus(a.z,b.z)};}
Vector subtract(Vector a,Vector b){return{minus(a.x,b.x),minus(a.y,b.y),minus(a.z,b.z)};}
float squared_length(Vector v){return plus(plus(times(v.x,v.x),times(v.y,v.y)),times(v.z,v.z));}
float square_root(float v){finite(v);return v==0?0:std::sqrt(v<0?0.f:v);}
Matrix product(const Matrix& left,const Matrix& right){auto result=right;transform_math::concatenate_left(result,left);return result;}
Matrix rotation_x(float angle){
    const auto t=transform_math::sin_cos(angle);auto rotation=transform_math::identity();rotation[1]={0,plus(0,t.cosine),plus(0,t.sine),0};rotation[2]={0,minus(0,t.sine),plus(0,t.cosine),0};
    auto result=transform_math::identity();for(unsigned i=0;i<3;++i){const auto v=transform_math::direction(rotation,{result[i][0],result[i][1],result[i][2]});result[i][0]=v.x;result[i][1]=v.y;result[i][2]=v.z;}return result;
}
Matrix basis_xy(Matrix m,Vector first,Vector auxiliary){
    const auto x=normalized(first),temporary_y=normalized(auxiliary),z=normalized(cross(x,temporary_y));axis(m,0,x);axis(m,1,cross(z,x));axis(m,2,z);m[3][3]=1;return m;
}
Matrix basis_xz(Matrix m,Vector first,Vector auxiliary){
    const auto x=normalized(first),temporary_z=normalized(auxiliary),y=normalized(cross(temporary_z,x));axis(m,0,x);axis(m,1,y);axis(m,2,cross(x,y));m[3][3]=1;return m;
}
Matrix inverse_scaled(const Matrix& source){
    transform_math::require_profile();std::array<float,3> q{};
    for(unsigned i=0;i<3;++i){const float squared=squared_length({source[i][0],source[i][1],source[i][2]});q[i]=squared>0?finite(1.f/std::sqrt(squared)):std::numeric_limits<float>::max();}
    auto result=transform_math::identity();for(unsigned column=0;column<3;++column)for(unsigned lane=0;lane<3;++lane)result[column][lane]=times(q[lane],source[lane][column]);
    const std::array<float,3> negative{minus(0,source[3][0]),minus(0,source[3][1]),minus(0,source[3][2])};
    for(unsigned lane=0;lane<3;++lane)result[3][lane]=plus(plus(times(result[0][lane],negative[0]),times(result[1][lane],negative[1])),times(result[2][lane],negative[2]));
    for(unsigned column=0;column<4;++column)for(unsigned lane=0;lane<3;++lane)result[column][lane]=times(result[column][lane],q[lane]);
    return result;
}
} // namespace reo::native::animation::constraint_math
