#include "constraints.hpp"
#include "constraint_math.hpp"
#include <algorithm>
#include <bit>
#include <cmath>
#include <stdexcept>

namespace reo::native::animation {
namespace {
namespace m=constraint_math;
float finite(float v){if(!std::isfinite(v))throw std::domain_error("Native two-link constraint finite arithmetic required");return v;}
Vector translation(const Matrix& v){return{v[3][0],v[3][1],v[3][2]};}
Vector axis(const Matrix& v,unsigned i){return{v[i][0],v[i][1],v[i][2]};}
void translation(Matrix& v,Vector p){v[3][0]=p.x;v[3][1]=p.y;v[3][2]=p.z;}
Vector scale(const NodePose& p){return{p.parameters[0],p.parameters[1],p.parameters[2]};}
Vector baseline_translation(const NodeDefinition& p){return{p.defaults[6],p.defaults[7],p.defaults[8]};}
}
Constraints::Constraints(std::shared_ptr<Instance> model):model_(std::move(model)){
    if(!model_)throw std::invalid_argument("Native constraints require their exact owned model");
    bindings_.resize(model_->nodes_.size());
}
bool Constraints::any_enabled()const noexcept{return std::any_of(contexts_.begin(),contexts_.end(),[](const auto& c){return c.enabled!=0;});}
std::shared_ptr<Constraints> Constraints::replacement(std::shared_ptr<Instance> model)const{
    for(unsigned i=2;i<context_count;++i)if(contexts_[i].enabled)throw std::invalid_argument("Additional active constraint recreation requires its original creator");
    auto next=std::make_shared<Constraints>(std::move(model));next->contexts_=contexts_;next->floor_heights_=floor_heights_;return next;
}
std::shared_ptr<Constraints> Constraints::clone_for_model(std::shared_ptr<Instance> model)const{
    if(!model||&model->skeleton()!=&model_->skeleton())throw std::invalid_argument("Native constraint copy requires the same authored topology");
    auto next=std::make_shared<Constraints>(std::move(model));
    next->contexts_=contexts_;next->bindings_=bindings_;next->floor_heights_=floor_heights_;return next;
}
void Constraints::reference(std::size_t index,Vector v){finite(v.x);finite(v.y);finite(v.z);contexts_.at(index).reference=v;}
void Constraints::target(std::size_t index,Vector v){finite(v.x);finite(v.y);finite(v.z);contexts_.at(index).target=v;}
void Constraints::floor_height(std::size_t index,float value){floor_heights_.at(index)=finite(value);}
void Constraints::invalidate_pose()noexcept{model_->invalidate();}
void Constraints::create(std::size_t index,std::uint16_t mode,std::size_t first,std::size_t middle,std::size_t last,Vector input_scale,float twist,Vector auxiliary){
    if(index>=context_count||first>=bindings_.size()||middle>=bindings_.size()||last>=bindings_.size()||first==middle||first==last||middle==last)throw std::invalid_argument("Native constraint context/node topology outside admitted profile");
    if(mode!=1&&mode!=2)throw std::invalid_argument("Native constraint auxiliary mode has no defined original source vector");
    auto frame=transform_math::scale(input_scale);std::array<Matrix,3> frames;const std::array ids{first,middle,last};
    for(unsigned i=0;i<3;++i){const auto delta=transform_math::direction(frame,baseline_translation(model_->skeleton_->nodes()[ids[i]]));translation(frame,m::add(delta,translation(frame)));frames[i]=frame;}
    auto orientation=m::basis_xy(frame,m::subtract(translation(frames[2]),translation(frames[0])),auxiliary);
    orientation=m::product(orientation,m::rotation_x(-twist));
    const auto third_axis=axis(orientation,2);
    const auto first_delta=m::subtract(translation(frames[1]),translation(frames[0]));
    const auto first_length=m::square_root(m::squared_length(first_delta));
    const auto first_basis=m::basis_xz(frames[0],first_delta,third_axis);
    const auto relative_first=m::product(m::inverse_scaled(first_basis),frames[0]);
    const auto second_delta=m::subtract(translation(frames[2]),translation(frames[1]));
    const auto second_length=m::square_root(m::squared_length(second_delta));
    const auto second_basis=m::basis_xz(frames[1],second_delta,third_axis);
    const auto relative_second=m::product(m::inverse_scaled(second_basis),frames[1]);
    auto& context=contexts_[index];context.relative_first=relative_first;context.relative_second=relative_second;context.mode=mode;context.enabled=1;context.reference=auxiliary;context.twist=twist;context.first_node=first;context.second_node=middle;context.first_length=first_length;context.second_length=second_length;context.bend=0;
    // The source constructor does not initialize targetAC; preserve its prior
    // value until the real ground consumer supplies the sampled endpoint.
    bindings_[first]={ConstraintCallback::two_link,index};bindings_[middle]={ConstraintCallback::already_solved,index};bindings_[last]={ConstraintCallback::standard,index};
}
void Constraints::initialize_mirrored(std::int8_t paused,Vector input_scale){
    if(paused!=0)return;
    create(0,2,7,8,9,input_scale,std::bit_cast<float>(0xbfc90fdcu),{1,0,0});
    create(1,2,4,5,6,input_scale,std::bit_cast<float>(0x3fc90fdcu),{-1,0,0});
}
void Constraints::solve(std::size_t context_index,std::size_t node_index,const Matrix& parent){
    auto& context=contexts_[context_index];auto& node=model_->nodes_[node_index];const auto parent_index=model_->links_[node_index].parent;
    if(!parent_index)throw std::invalid_argument("Two-link source callback requires a current parent node");
    const auto bend=m::rotation_x(context.bend);
    node.world=hierarchical_pose(node,parent,scale(model_->nodes_[*parent_index]));
    const auto target_delta=m::subtract(context.target,translation(node.world));
    Vector auxiliary;
    if(context.mode==1)auxiliary=transform_math::direction(parent,context.reference);
    else if(context.mode==2)auxiliary=m::subtract(context.reference,translation(node.world));
    else throw std::invalid_argument("Unsupported original uninitialized constraint auxiliary vector");
    auto target=m::basis_xy(node.world,target_delta,auxiliary);
    target=m::product(target,m::rotation_x(context.twist));
    const float distance_squared=m::squared_length(target_delta),distance=m::square_root(distance_squared);
    const float first=context.first_length,second=context.second_length;
    const float first_squared=finite(first*first),second_squared=finite(second*second);
    if(!(distance<finite(first+second))){
        const auto straight=m::product(target,bend);
        model_->nodes_[context.first_node].world=m::product(straight,context.relative_first);
        auto& second_world=model_->nodes_[context.second_node].world;second_world=m::product(straight,context.relative_second);
        for(unsigned lane=0;lane<3;++lane)second_world[3][lane]=finite(second_world[3][lane]+finite(target[0][lane]*first));
        return;
    }
    const float cosine_a=finite(finite(finite(first_squared+distance_squared)-second_squared)/finite(finite(2.f*distance)*first));
    const float sine_a=cosine_a==1?0:m::square_root(finite(1.f-finite(cosine_a*cosine_a)));
    auto rotation=transform_math::identity();rotation[0][0]=cosine_a;rotation[0][1]=sine_a;rotation[1][0]=-sine_a;rotation[1][1]=cosine_a;
    const auto first_frame=m::product(target,rotation);
    model_->nodes_[context.first_node].world=m::product(m::product(first_frame,bend),context.relative_first);
    const float cosine_b=finite(finite(finite(second_squared+first_squared)-distance_squared)/finite(finite(2.f*first)*second));
    const float sine_b=cosine_b==1?0:m::square_root(finite(1.f-finite(cosine_b*cosine_b)));
    rotation[0][0]=-cosine_b;rotation[0][1]=-sine_b;rotation[1][0]=sine_b;rotation[1][1]=-cosine_b;rotation[3]={first,0,0,1};
    const auto second_frame=m::product(first_frame,rotation);
    model_->nodes_[context.second_node].world=m::product(m::product(second_frame,bend),context.relative_second);
}
void Constraints::rebuild(const Matrix& parent){
    model_->invalidate();
    const auto walk=[&](auto&& self,std::size_t index,const Matrix& incoming,Vector incoming_scale)->void{
        auto staged=incoming_scale;const auto binding=bindings_[index];
        if(binding.callback!=ConstraintCallback::none&&contexts_[binding.context].enabled){
            if(binding.callback==ConstraintCallback::standard){model_->nodes_[index].world=hierarchical_pose(model_->nodes_[index],incoming,incoming_scale);staged=scale(model_->nodes_[index]);}
            else if(binding.callback==ConstraintCallback::two_link)solve(binding.context,index,incoming);
            // already_solved is the source's actual empty middle-node callback.
        }
        const auto& definition=model_->links_[index];
        if(definition.child)self(self,*definition.child,model_->nodes_[index].world,staged);
        if(definition.sibling)self(self,*definition.sibling,incoming,incoming_scale);
    };walk(walk,0,parent,{1,1,1});model_->publish_snapshot();
}
} // namespace reo::native::animation
