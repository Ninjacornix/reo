#include "surface_orientation_math.hpp"
#include <bit>
#include <cmath>
#include <limits>
#include <stdexcept>

namespace reo::native::gameplay_world::surface_math {
namespace {
constexpr float value(std::uint32_t v){return std::bit_cast<float>(v);}
float finite(float v){if(!std::isfinite(v))throw std::domain_error("Native surface orientation finite FP32 arithmetic required");return v;}
float mul(float a,float b){return finite(a*b);}
float add(float a,float b){return finite(a+b);}
float sub(float a,float b){return finite(a-b);}
Vector normalize(Vector v){
    const float squared=dot(v,v);
    // The admitted SDK131 vrsqrt path uses max finite for a zero divisor.
    // Preserve that profile, including zero/parallel vectors; no invented axis.
    const float q=squared>0?finite(1.0f/std::sqrt(squared)):std::numeric_limits<float>::max();
    return{mul(v.x,q),mul(v.y,q),mul(v.z,q)};
}
Vector axis(const Matrix& m,unsigned i){return{m[i][0],m[i][1],m[i][2]};}
void store(Matrix& m,unsigned i,Vector v){m[i][0]=v.x;m[i][1]=v.y;m[i][2]=v.z;}
}
Vector rotate_probe(Vector v,std::uint16_t turn){
    const float angle=mul(value(0x40c90fdb),float(turn))/65536.0f;
    const auto trig=transform_math::sin_cos(angle);
    return{add(mul(trig.cosine,v.x),mul(trig.sine,v.z)),v.y,
           add(mul(-trig.sine,v.x),mul(trig.cosine,v.z))};
}
float turn_cosine(std::uint16_t turn){
    // Original 370100 -> 1921A0 -> 18F470. The latter evaluates the same
    // owned cosine polynomial as 18F570, without requesting the sine result.
    return transform_math::sin_cos(mul(value(0x38c90fdb),float(turn))).cosine;
}
Vector cross(Vector a,Vector b){return{sub(mul(a.y,b.z),mul(a.z,b.y)),sub(mul(a.z,b.x),mul(a.x,b.z)),sub(mul(a.x,b.y),mul(a.y,b.x))};}
float dot(Vector a,Vector b){return add(add(mul(a.x,b.x),mul(a.y,b.y)),mul(a.z,b.z));}
Matrix normal_basis(Vector normal,Vector heading){
    transform_math::require_profile();
    const auto forward=normalize(heading),up=normalize(normal);
    const auto right=normalize(cross(up,forward));
    auto m=transform_math::identity();store(m,0,right);store(m,1,up);store(m,2,cross(right,up));return m;
}
Matrix blend_basis(const Matrix& old,const Matrix& next,float a,float b){
    transform_math::require_profile();
    const auto blended=[&](unsigned i){const auto x=axis(old,i),y=axis(next,i);return Vector{add(mul(x.x,a),mul(y.x,b)),add(mul(x.y,a),mul(y.y,b)),add(mul(x.z,a),mul(y.z,b))};};
    const auto x=normalize(blended(0)),temporary_y=normalize(blended(1));
    const auto z=normalize(cross(x,temporary_y)),y=cross(z,x);
    auto m=transform_math::identity();store(m,0,x);store(m,1,y);store(m,2,z);store(m,3,blended(3));return m;
}
} // namespace reo::native::gameplay_world::surface_math
