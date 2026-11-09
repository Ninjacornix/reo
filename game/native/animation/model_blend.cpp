#include "model_blend.hpp"
#include "constraint_math.hpp"
#include <cmath>
#include <stdexcept>
namespace reo::native::animation {
namespace {
float finite(float value){if(!std::isfinite(value))throw std::domain_error("Native pose blend finite FP32 profile required");return value;}
float weighted(float a,float b,float x,float y){const float first=finite(a*x),second=finite(b*y);return finite(first+second);}
}
std::shared_ptr<Instance> PoseBlend::create_sibling(const Instance& source){return std::make_shared<Instance>(source.skeleton_);}
void PoseBlend::capture_pose(Instance& destination,const Instance& source,std::uint16_t track){
    if(destination.skeleton_!=source.skeleton_||source.nodes_.size()>255)throw std::invalid_argument("Native flat pose capture requires corresponding bounded model banks");
    destination.invalidate();for(std::size_t i=0;i<source.nodes_.size();++i)if(source.skeleton_->nodes()[i].track==track){destination.nodes_[i].local=source.nodes_[i].local;for(unsigned c=0;c<3;++c)destination.nodes_[i].parameters[c]=source.nodes_[i].parameters[c];}
}
void PoseBlend::capture_links(Instance& destination,const Instance& source,std::uint16_t track){
    if(destination.skeleton_!=source.skeleton_||source.nodes_.size()>255)throw std::invalid_argument("Native binding capture requires corresponding bounded model banks");
    destination.invalidate();for(std::size_t i=0;i<source.nodes_.size();++i)if(source.skeleton_->nodes()[i].track==track){destination.bindings_[i]=source.bindings_[i];destination.nodes_[i].caches=source.nodes_[i].caches;}
}
Matrix PoseBlend::matrix(const Matrix& primary,const Matrix& secondary,float p,float s){
    transform_math::require_profile();finite(p);finite(s);Vector x,y,translation;
    x={weighted(primary[0][0],secondary[0][0],p,s),weighted(primary[0][1],secondary[0][1],p,s),weighted(primary[0][2],secondary[0][2],p,s)};
    y={weighted(primary[1][0],secondary[1][0],p,s),weighted(primary[1][1],secondary[1][1],p,s),weighted(primary[1][2],secondary[1][2],p,s)};
    translation={weighted(primary[3][0],secondary[3][0],p,s),weighted(primary[3][1],secondary[3][1],p,s),weighted(primary[3][2],secondary[3][2],p,s)};
    auto result=transform_math::identity();result[3]={translation.x,translation.y,translation.z,1};return constraint_math::basis_xy(result,x,y);
}
void PoseBlend::blend(Instance& destination,const Instance& source,std::uint16_t track,float p,float s){
    if(destination.skeleton_!=source.skeleton_)throw std::invalid_argument("Native blend requires corresponding owned model banks");
    finite(p);finite(s);
    std::optional<std::size_t> root;for(auto i:destination.skeleton_->traversal())if(destination.skeleton_->nodes()[i].track==track){root=i;break;}if(!root)throw std::invalid_argument("Native blend track absent from model");
    destination.invalidate();const auto walk=[&](auto&& self,std::size_t i,bool siblings)->void{const auto& definition=destination.skeleton_->nodes()[i];if(definition.track==track){auto& output=destination.nodes_[i];const auto& input=source.nodes_[i];for(unsigned c=0;c<3;++c)output.parameters[c]=weighted(output.parameters[c],input.parameters[c],p,s);output.local=matrix(output.local,input.local,p,s);}if(definition.child)self(self,*definition.child,true);if(siblings&&definition.sibling)self(self,*definition.sibling,true);};walk(walk,*root,false);
}
} // namespace reo::native::animation
