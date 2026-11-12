#include "transform_math.hpp"
#include <bit>
#include <cfenv>
#include <cmath>
#include <limits>
#include <stdexcept>

namespace reo::native::transform_math {
namespace {
static_assert(sizeof(float)==4 && std::numeric_limits<float>::is_iec559);
constexpr float value(std::uint32_t bits){return std::bit_cast<float>(bits);}
constexpr float pi=value(0x40490fdb),tau=value(0x40c90fdb),half_pi=value(0x3fc90fdb);
constexpr std::array<float,4> coefficients{value(0x362e9c14),value(0xb94fb21f),value(0x3c08873e),value(0xbe2aaaa4)};
void finite(float x){if(!std::isfinite(x))throw std::domain_error("Native transform finite FP32 profile required");}
float add(float a,float b){const float r=a+b;finite(r);return r;}
float subtract(float a,float b){const float r=a-b;finite(r);return r;}
float multiply(float a,float b){const float r=a*b;finite(r);return r;}
float component(const Matrix& m,unsigned lane,const std::array<float,4>& v){
    float sum=multiply(m[0][lane],v[0]);
    sum=add(sum,multiply(m[1][lane],v[1]));
    sum=add(sum,multiply(m[2][lane],v[2]));
    return add(sum,multiply(m[3][lane],v[3]));
}
void rotate_axes(Matrix& m,const std::array<Vector,3>& rotation){
    auto next=m;
    for(unsigned column=0;column<3;++column){
        const auto& p=m[column];
        next[column][0]=add(add(multiply(rotation[0].x,p[0]),multiply(rotation[1].x,p[1])),multiply(rotation[2].x,p[2]));
        next[column][1]=add(add(multiply(rotation[0].y,p[0]),multiply(rotation[1].y,p[1])),multiply(rotation[2].y,p[2]));
        next[column][2]=add(add(multiply(rotation[0].z,p[0]),multiply(rotation[1].z,p[1])),multiply(rotation[2].z,p[2]));
    }
    m=next;
}
void compose(Matrix& m,Angles angles){
    const auto x=sin_cos(radians(angles[0]));
    rotate_axes(m,{{{1,0,0},{0,add(0,x.cosine),add(0,x.sine)},{0,subtract(0,x.sine),add(0,x.cosine)}}});
    const auto y=sin_cos(radians(angles[1]));
    rotate_axes(m,{{{add(0,y.cosine),0,subtract(0,y.sine)},{0,1,0},{add(0,y.sine),0,add(0,y.cosine)}}});
    const auto z=sin_cos(radians(angles[2]));
    rotate_axes(m,{{{add(0,z.cosine),add(0,z.sine),0},{subtract(0,z.sine),add(0,z.cosine),0},{0,0,1}}});
}
}
void require_profile(){
    if(std::fegetround()!=FE_TONEAREST)throw std::domain_error("Native transform round-to-nearest profile required");
    // Admit gradual underflow without changing thread floating-point controls.
    volatile float minimum=std::numeric_limits<float>::min();
    volatile float half=0.5f;
    const float subnormal=minimum*half;
    volatile float retained=subnormal;
    volatile float one=1.0f;
    const float consumed=retained*one;
    if(std::bit_cast<std::uint32_t>(subnormal)!=0x00400000u ||
       std::bit_cast<std::uint32_t>(consumed)!=0x00400000u)
        throw std::domain_error("Native transform gradual-underflow profile required");
}
Matrix identity()noexcept{return{{{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}}};}
float radians(std::uint16_t turn){
    require_profile();
    float result=multiply(value(0x3bb40000),float(turn));
    result=multiply(pi,result);result=result/180.0f;
    if(!(result<=pi))result=add(result,-tau);
    return result;
}
SinCos sin_cos(float angle){
    require_profile();finite(angle);
    if(angle< -tau || angle>tau)throw std::domain_error("Native transform radian reduction domain exceeded");
    if(angle<= -pi || !(angle<pi)){
        const float quotient=multiply(angle,value(0x3ea2f983));
        const int periods=(static_cast<int>(quotient)+(angle>0?1:0))&~1;
        angle=subtract(angle,multiply(float(periods),pi));
    }
    const bool negative=angle<0;
    const float x=negative?add(half_pi,angle):subtract(half_pi,angle);
    const float x2=multiply(x,x),x4=multiply(x2,x2),x6=multiply(x2,x4),x8=multiply(x4,x4);
    const std::array<float,4> scaled{multiply(coefficients[0],x),multiply(coefficients[1],x),multiply(coefficients[2],x),multiply(coefficients[3],x)};
    float polynomial=multiply(x,1.0f);
    polynomial=add(polynomial,multiply(x2,scaled[3]));
    polynomial=add(polynomial,multiply(x4,scaled[2]));
    polynomial=add(polynomial,multiply(x6,scaled[1]));
    polynomial=add(polynomial,multiply(x8,scaled[0]));
    const float squared=multiply(polynomial,polynomial);
    const float complement=subtract(1.0f,squared);
    const float root=std::sqrt(complement<0?0.0f:complement);
    return{negative?subtract(0,root):add(0,root),add(0,polynomial)};
}
void reset_euler_axes(Matrix& matrix,Angles angles){
    require_profile();auto next=matrix;
    for(unsigned col=0;col<3;++col)for(unsigned lane=0;lane<3;++lane)next[col][lane]=float(col==lane);
    compose(next,angles);matrix=next;
}
void reset_euler_axes_xzy(Matrix& matrix,Angles angles){
    require_profile();auto next=matrix;
    for(unsigned col=0;col<3;++col)for(unsigned lane=0;lane<3;++lane)next[col][lane]=float(col==lane);
    const auto x=sin_cos(radians(angles[0]));
    rotate_axes(next,{{{1,0,0},{0,add(0,x.cosine),add(0,x.sine)},{0,subtract(0,x.sine),add(0,x.cosine)}}});
    const auto z=sin_cos(radians(angles[2]));
    rotate_axes(next,{{{add(0,z.cosine),add(0,z.sine),0},{subtract(0,z.sine),add(0,z.cosine),0},{0,0,1}}});
    const auto y=sin_cos(radians(angles[1]));
    rotate_axes(next,{{{add(0,y.cosine),0,subtract(0,y.sine)},{0,1,0},{add(0,y.sine),0,add(0,y.cosine)}}});
    matrix=next;
}
void compose_euler_axes(Matrix& matrix,Angles angles){
    require_profile();auto next=matrix;compose(next,angles);matrix=next;
}
void compose_euler_radians(Matrix& matrix,Vector angles){
    require_profile();auto next=matrix;
    const auto x=sin_cos(angles.x);
    rotate_axes(next,{{{1,0,0},{0,add(0,x.cosine),add(0,x.sine)},{0,subtract(0,x.sine),add(0,x.cosine)}}});
    const auto y=sin_cos(angles.y);
    rotate_axes(next,{{{add(0,y.cosine),0,subtract(0,y.sine)},{0,1,0},{add(0,y.sine),0,add(0,y.cosine)}}});
    const auto z=sin_cos(angles.z);
    rotate_axes(next,{{{add(0,z.cosine),add(0,z.sine),0},{subtract(0,z.sine),add(0,z.cosine),0},{0,0,1}}});
    matrix=next;
}
Matrix scale(Vector v){
    require_profile();finite(v.x);finite(v.y);finite(v.z);auto m=identity();m[0][0]=add(0,v.x);m[1][1]=add(0,v.y);m[2][2]=add(0,v.z);return m;
}
void concatenate_left(Matrix& destination,const Matrix& left){
    require_profile();const auto old=destination;const auto factor=left;auto next=old;
    for(unsigned column=0;column<4;++column)for(unsigned lane=0;lane<4;++lane)next[column][lane]=component(factor,lane,old[column]);
    destination=next;
}
Vector direction(const Matrix& m,Vector p){
    require_profile();
    const auto lane=[&](unsigned i){return add(add(multiply(m[0][i],p.x),multiply(m[1][i],p.y)),multiply(m[2][i],p.z));};
    return{lane(0),lane(1),lane(2)};
}
} // namespace reo::native::transform_math
