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
Vector PoseBlend::root_reference(const Instance& model)noexcept{return model.previous_root_translation_;}
void PoseBlend::root_reference(Instance& model,Vector value){finite(value.x);finite(value.y);finite(value.z);model.invalidate();model.previous_root_translation_=value;}
void PoseBlend::bind_all(Instance& model,std::shared_ptr<const Clip> clip){
    if(!clip||clip->tracks().size()!=model.traversal_.size())throw std::invalid_argument("Native whole-model motion cardinality mismatch");
    model.invalidate();std::size_t ordinal{};for(auto i:model.traversal_)model.bindings_[i]=Instance::Binding{clip,ordinal++};
}
void PoseBlend::capture_pose(Instance& destination,const Instance& source,std::uint16_t track){
    if(destination.skeleton_!=source.skeleton_||source.nodes_.size()>255)throw std::invalid_argument("Native flat pose capture requires corresponding bounded model banks");
    destination.invalidate();for(std::size_t i=0;i<source.nodes_.size();++i)if(source.track_ids_[i]==track){destination.nodes_[i].local=source.nodes_[i].local;for(unsigned c=0;c<3;++c)destination.nodes_[i].parameters[c]=source.nodes_[i].parameters[c];}
}
void PoseBlend::capture_links(Instance& destination,const Instance& source,std::uint16_t track){
    if(destination.skeleton_!=source.skeleton_||source.nodes_.size()>255)throw std::invalid_argument("Native binding capture requires corresponding bounded model banks");
    destination.invalidate();for(std::size_t i=0;i<source.nodes_.size();++i)if(source.track_ids_[i]==track){destination.bindings_[i]=source.bindings_[i];destination.nodes_[i].caches=source.nodes_[i].caches;}
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
    const auto root=[&](const Instance& model)->std::size_t{
        for(auto i:model.traversal_)if(model.track_ids_[i]==track)return i;
        throw std::invalid_argument("Native blend track absent from model");
    };
    const auto first=root(destination),second=root(source);
    //192710 walks both banks' links together. Corresponding nodes need not
    // have the same physical index after runtime topology changes.
    const auto walk=[&](bool apply){
        auto i=first,j=second;
        const auto required=[](const std::optional<std::size_t>& value){if(!value)throw std::invalid_argument("Native paired blend path unavailable");return *value;};
        for(;;){
            if(apply&&destination.track_ids_[i]==track){auto& output=destination.nodes_[i];const auto& input=source.nodes_[j];for(unsigned c=0;c<3;++c)output.parameters[c]=weighted(output.parameters[c],input.parameters[c],p,s);output.local=matrix(output.local,input.local,p,s);}
            if(destination.links_[i].child){i=*destination.links_[i].child;j=required(source.links_[j].child);continue;}
            if(i==first)return;
            if(destination.links_[i].sibling){i=*destination.links_[i].sibling;j=required(source.links_[j].sibling);continue;}
            // After ascending,192710 skips an unmatched ancestor sibling's
            // entire subtree. Direct leaf siblings take the ordinary path.
            for(;;){
                if(destination.links_[i].sibling){
                    i=*destination.links_[i].sibling;j=required(source.links_[j].sibling);
                    if(destination.track_ids_[i]==track)break;
                }else{
                    i=required(destination.links_[i].parent);j=required(source.links_[j].parent);
                    if(i==first)return;
                }
            }
        }
    };
    walk(false);destination.invalidate();walk(true);
}
} // namespace reo::native::animation
