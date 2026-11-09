#include "model_math.hpp"
#include <cmath>
#include <stdexcept>

namespace reo::native::animation {
namespace {
float finite(float v){if(!std::isfinite(v))throw std::domain_error("Native model pose finite arithmetic required");return v;}
float add(float a,float b){return finite(a+b);}
float mul(float a,float b){return finite(a*b);}
void rotate(Matrix& m,const std::array<Vector,3>& r){
    auto next=m;
    for(unsigned i=0;i<3;++i)for(unsigned lane=0;lane<3;++lane){const float a=lane==0?r[0].x:lane==1?r[0].y:r[0].z,b=lane==0?r[1].x:lane==1?r[1].y:r[1].z,c=lane==0?r[2].x:lane==1?r[2].y:r[2].z;next[i][lane]=add(add(mul(a,m[i][0]),mul(b,m[i][1])),mul(c,m[i][2]));}
    m=next;
}
void euler(Matrix& m,const Parameters& p){
    const auto x=transform_math::sin_cos(p[3]);rotate(m,{{{1,0,0},{0,add(0,x.cosine),add(0,x.sine)},{0,finite(0-x.sine),add(0,x.cosine)}}});
    const auto y=transform_math::sin_cos(p[4]);rotate(m,{{{add(0,y.cosine),0,finite(0-y.sine)},{0,1,0},{add(0,y.sine),0,add(0,y.cosine)}}});
    const auto z=transform_math::sin_cos(p[5]);rotate(m,{{{add(0,z.cosine),add(0,z.sine),0},{finite(0-z.sine),add(0,z.cosine),0},{0,0,1}}});
}
void translation(Matrix& m,const Parameters& p){for(unsigned i=0;i<3;++i)m[3][i]=finite(p[6+i]);}
}
Matrix unscaled_pose(const Parameters& p){auto m=transform_math::identity();euler(m,p);translation(m,p);return m;}
Matrix scaled_pose(const Parameters& p){auto m=transform_math::scale({p[0],p[1],p[2]});euler(m,p);translation(m,p);return m;}
Matrix hierarchical_pose(const NodePose& node,const Matrix& parent,Vector scale){
    auto result=transform_math::scale({node.parameters[0],node.parameters[1],node.parameters[2]});
    //1913E0 composes onlyXYZbasis, with three ordered terms; no fourth zero
    //term or local translation is introduced into these axes.
    for(unsigned i=0;i<3;++i){const auto v=transform_math::direction(node.local,{result[i][0],result[i][1],result[i][2]});result[i][0]=v.x;result[i][1]=v.y;result[i][2]=v.z;}
    auto compensation=transform_math::identity();compensation[0][0]=finite(1.f/scale.x);compensation[1][1]=finite(1.f/scale.y);compensation[2][2]=finite(1.f/scale.z);
    for(unsigned i=0;i<3;++i)compensation[3][i]=finite(node.local[3][i]);
    transform_math::concatenate_left(result,compensation);transform_math::concatenate_left(result,parent);return result;
}
} // namespace reo::native::animation
