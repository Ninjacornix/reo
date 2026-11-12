#include "model.hpp"
#include "model_math.hpp"
#include <algorithm>
#include <cmath>
#include <cstring>
#include <functional>
#include <stdexcept>

namespace reo::native::animation {
namespace {
template<class T>T read(std::span<const std::byte> bytes,std::size_t at){if(at>bytes.size()||sizeof(T)>bytes.size()-at)throw std::invalid_argument("Truncated native skeleton");T v;std::memcpy(&v,bytes.data()+at,sizeof v);return v;}
float finite(float v){if(!std::isfinite(v))throw std::domain_error("Native model finite profile required");return v;}
Vector translation(const Matrix& m){return{m[3][0],m[3][1],m[3][2]};}
Vector difference(Vector a,Vector b){return{finite(a.x-b.x),finite(a.y-b.y),finite(a.z-b.z)};}
}
std::shared_ptr<const Skeleton> Skeleton::import_raw(std::span<const std::byte> bytes,std::size_t root_ordinal,SkeletonExtent extent){
    if(bytes.size()<12)throw std::invalid_argument("Truncated raw skeleton header");
    const auto count=read<std::uint32_t>(bytes,4);
    const auto length=extent==SkeletonExtent::bounded_records?bytes.size():std::size_t(read<std::uint32_t>(bytes,8));
    if(!count||count>1153||length<12||length>bytes.size())throw std::invalid_argument("Invalid skeleton count/extent");
    bytes=bytes.first(length);std::vector<std::size_t> raw_nodes;std::vector<std::uint32_t> roots;
    std::size_t at=12;
    for(std::size_t i=0;i<count;++i){
        const auto type=read<std::uint32_t>(bytes,at)&255,n=read<std::uint32_t>(bytes,at+4),size=read<std::uint32_t>(bytes,at+8);
        if(size<12||at>length||size>length-at)throw std::invalid_argument("Invalid raw skeleton record extent");
        if(!type){if(!roots.empty()||n>(size-12)/4)throw std::invalid_argument("Invalid raw skeleton root table");for(unsigned j=0;j<n;++j)roots.push_back(read<std::uint32_t>(bytes,at+12+4*j));}
        else{if(size<84)throw std::invalid_argument("Truncated raw skeleton node");raw_nodes.push_back(at+12);}
        at+=size;
    }
    if(at!=length||root_ordinal>=roots.size()||roots[root_ordinal]>=raw_nodes.size())throw std::invalid_argument("Invalid skeleton root selection");
    const auto first=std::size_t(roots[root_ordinal]);std::vector<unsigned char> seen(raw_nodes.size());std::vector<std::size_t> order;
    const auto walk=[&](auto&& self,std::size_t index)->void{
        if(index>=raw_nodes.size()||seen[index])throw std::invalid_argument("Cyclic/shared/out-of-range skeleton link");
        seen[index]=1;order.push_back(index);
        for(unsigned field:{8u,12u}){const auto link=read<std::int32_t>(bytes,raw_nodes[index]+field);if(link!=-1){if(link<0)throw std::invalid_argument("Invalid negative skeleton link");self(self,std::size_t(link));}}
    };walk(walk,first);
    auto skeleton=std::make_shared<Skeleton>();skeleton->nodes_.resize(order.size());
    // Original1A2E00 packs the contiguous source interval, then rebases links
    // by the first raw index. Reject noncontiguous forests rather than silently
    // giving them a different native node/clip ordinal convention.
    for(auto index:order)if(index<first||index-first>=order.size())throw std::invalid_argument("Noncontiguous original skeleton packing profile");
    for(std::size_t i=0;i<order.size();++i){
        const auto source=raw_nodes[first+i];auto& node=skeleton->nodes_[i];node.palette_index=std::int16_t(read<std::uint32_t>(bytes,source));node.track=std::uint16_t(read<std::uint32_t>(bytes,source+0x44));node.static_index=std::int16_t(read<std::uint32_t>(bytes,source+0x40));
        const auto link=[&](unsigned offset)->std::optional<std::size_t>{const auto value=read<std::int32_t>(bytes,source+offset);return value==-1?std::nullopt:std::optional<std::size_t>(std::size_t(value)-first);};node.child=link(8);node.sibling=link(12);
        for(unsigned group=0;group<3;++group)for(unsigned lane=0;lane<3;++lane)node.defaults[group*3+lane]=finite(read<float>(bytes,source+0x10+group*16+lane*4));
    }
    const auto parents=[&](auto&& self,std::size_t i,std::optional<std::size_t> parent)->void{auto& n=skeleton->nodes_[i];n.parent=parent;skeleton->traversal_.push_back(i);if(n.child)self(self,*n.child,i);if(n.sibling)self(self,*n.sibling,parent);};parents(parents,0,{});return skeleton;
}
Instance::Instance(std::shared_ptr<const Skeleton> skeleton):skeleton_(std::move(skeleton)){
    if(!skeleton_||skeleton_->nodes().empty())throw std::invalid_argument("Native model requires owned skeleton");
    nodes_.resize(skeleton_->nodes().size());bindings_.resize(nodes_.size());track_ids_.resize(nodes_.size());for(std::size_t i=0;i<nodes_.size();++i){track_ids_[i]=skeleton_->nodes()[i].track;nodes_[i].parameters=skeleton_->nodes()[i].defaults;nodes_[i].local=unscaled_pose(nodes_[i].parameters);nodes_[i].world=transform_math::identity();}
    links_.reserve(nodes_.size());for(const auto& node:skeleton_->nodes())links_.push_back({node.parent,node.child,node.sibling});
    traversal_.assign(skeleton_->traversal().begin(),skeleton_->traversal().end());
}
void Instance::patch_links(std::span<const NodeLinkPatch> patches){
    if(patches.empty())return;
    auto next=links_;
    for(const auto& patch:patches){
        if(patch.node>=next.size()||(patch.target&&*patch.target>=next.size()))
            throw std::out_of_range("Native model topology node unavailable");
        auto& row=next[patch.node];
        switch(patch.link){
        case NodeLink::parent:row.parent=patch.target;break;
        case NodeLink::child:row.child=patch.target;break;
        case NodeLink::sibling:row.sibling=patch.target;break;
        default:throw std::invalid_argument("Native model topology link kind unavailable");
        }
    }
    std::vector<unsigned char> incoming(next.size()),color(next.size());
    for(const auto& row:next)for(const auto& target:{row.child,row.sibling})
        if(target&&++incoming[*target]>1)throw std::invalid_argument("Native model topology has shared paths");
    const auto validate=[&](auto&& self,std::size_t node)->void{
        if(color[node]==1)throw std::invalid_argument("Native model topology cycle");
        if(color[node]==2)return;
        color[node]=1;
        for(const auto& target:{next[node].child,next[node].sibling})if(target)self(self,*target);
        color[node]=2;
    };
    for(std::size_t node=0;node<next.size();++node)validate(validate,node);
    std::vector<std::size_t> order;order.reserve(next.size());
    const auto walk=[&](auto&& self,std::size_t node,std::optional<std::size_t> parent)->void{
        if(next[node].parent!=parent)throw std::invalid_argument("Native reachable topology parent mismatch");
        order.push_back(node);if(next[node].child)self(self,*next[node].child,node);if(next[node].sibling)self(self,*next[node].sibling,parent);
    };walk(walk,0,{});
    links_.swap(next);traversal_.swap(order);invalidate();
}
void Instance::relabel_prefix(std::size_t count,std::uint16_t track){
    if(count>track_ids_.size())throw std::out_of_range("Native model track prefix extent unavailable");
    std::fill_n(track_ids_.begin(),count,track);
}
void Instance::relabel_prefix(std::span<const std::uint16_t> tracks){
    if(tracks.size()>track_ids_.size())throw std::out_of_range("Native model track layout extent unavailable");
    std::copy(tracks.begin(),tracks.end(),track_ids_.begin());
}
void Instance::bind(std::uint16_t track,std::shared_ptr<const Clip> clip){
    bind_matching(track,std::move(clip),false);
}
void Instance::bind_prefix(std::uint16_t track,std::shared_ptr<const Clip> clip){
    bind_matching(track,std::move(clip),true);
}
void Instance::bind_matching(std::uint16_t track,std::shared_ptr<const Clip> clip,bool allow_trailing){
    if(!clip)throw std::invalid_argument("Native model requires owned motion clip");
    std::size_t count=0;for(auto i:traversal_)count+=track_ids_[i]==track;
    if(!count||clip->tracks().size()<count||(!allow_trailing&&clip->tracks().size()!=count))throw std::invalid_argument("Native motion/model track cardinality mismatch");
    invalidate();std::size_t ordinal=0;for(auto i:traversal_)if(track_ids_[i]==track)bindings_[i]=Binding{clip,ordinal++};
}
void Instance::clear(std::uint16_t track){invalidate();for(auto i:traversal_)if(track_ids_[i]==track)bindings_[i].reset();}
void Instance::sample_node(std::size_t i,float frame){
    auto& node=nodes_[i];node.parameters=skeleton_->nodes()[i].defaults;if(bindings_[i])sample_parameters(bindings_[i]->clip->tracks()[bindings_[i]->track],frame,node.parameters,node.caches);node.local=unscaled_pose(node.parameters);
}
void Instance::sample(std::uint16_t track,float frame){invalidate();bool found=false;for(auto i:traversal_)if(track_ids_[i]==track){sample_node(i,frame);found=true;}if(!found)throw std::invalid_argument("Native animation track absent from skeleton");}
void Instance::sample_all(float frame){invalidate();for(auto i:traversal_)sample_node(i,frame);}
void Instance::root_scale(Vector scale){invalidate();nodes_[0].local=transform_math::scale(scale);}
Vector Instance::local_translation(std::size_t node)const{return translation(nodes_.at(node).local);}
Vector Instance::world_translation(std::size_t node)const{return translation(nodes_.at(node).world);}
void Instance::local_translation(std::size_t node,Vector v){
    auto& local=nodes_.at(node).local;finite(v.x);finite(v.y);finite(v.z);invalidate();local[3][0]=v.x;local[3][1]=v.y;local[3][2]=v.z;
}
Vector Instance::consume_root_translation(){
    if(nodes_.size()<2)throw std::invalid_argument("Native actor root-motion model requires second node");
    invalidate();auto& root=nodes_[1].local;const auto current=translation(root),delta=difference(current,previous_root_translation_);previous_root_translation_=current;root[3][0]=root[3][1]=root[3][2]=0;return delta;
}
Vector Instance::translation_difference(std::size_t node,float start,float end){
    if(node>=nodes_.size()||!bindings_[node])throw std::invalid_argument("Native root difference requires a bound node");
    const auto& binding=*bindings_[node];auto p=skeleton_->nodes()[node].defaults;sample_parameters(binding.clip->tracks()[binding.track],start,p,nodes_[node].caches);const auto a=scaled_pose(p);p=skeleton_->nodes()[node].defaults;sample_parameters(binding.clip->tracks()[binding.track],end,p,nodes_[node].caches);return difference(translation(scaled_pose(p)),translation(a));
}
void Instance::rebuild(const Matrix& parent){
    invalidate();const auto walk=[&](auto&& self,std::size_t i,const Matrix& incoming,Vector scale)->void{auto& n=nodes_[i];n.world=hierarchical_pose(n,incoming,scale);const auto& definition=links_[i];if(definition.child)self(self,*definition.child,n.world,Vector{n.parameters[0],n.parameters[1],n.parameters[2]});if(definition.sibling)self(self,*definition.sibling,incoming,scale);};walk(walk,0,parent,{1,1,1});
    publish_snapshot();
}
void Instance::publish_snapshot(){
    if(revision_==UINT64_MAX)throw std::overflow_error("Native model snapshot revision exhausted");
    auto snapshot=std::make_shared<JointSnapshot>();snapshot->revision=++revision_;snapshot->joints.reserve(nodes_.size());for(const auto& n:nodes_)snapshot->joints.push_back(n.world);snapshot_=std::move(snapshot);
}
void Instance::patch_world_poses(std::span<const JointPosePatch> patches){
    if(!snapshot_)throw std::invalid_argument("Native joint patch requires current published pose");
    for(const auto& patch:patches){
        if(patch.node>=nodes_.size())throw std::out_of_range("Native joint patch index unavailable");
        for(const auto& column:patch.world)for(float value:column)finite(value);
    }
    if(patches.empty())return;
    if(revision_==UINT64_MAX)throw std::overflow_error("Native model snapshot revision exhausted");
    auto prepared=std::make_shared<JointSnapshot>(*snapshot_);prepared->revision=revision_+1;
    for(const auto& patch:patches)prepared->joints[patch.node]=patch.world;
    for(const auto& patch:patches)nodes_[patch.node].world=patch.world;
    ++revision_;snapshot_=std::move(prepared);
}
unsigned advance(FrameRecord& r,float step){
    r.flags&=std::uint8_t(~std::uint8_t(0x60));if(r.flags&0x10)return 0;finite(r.end);finite(step);
    if(r.end==0){r.flags|=0x40;if(r.loop)r.flags|=0x20;return 3;}
    if(!(step<0)){
        r.frame=finite(r.frame+step);const float extra=finite(r.frame-r.end);
        if(!(extra<=0)){if(r.loop){r.frame=finite(r.restart+extra);if(!(r.frame<=r.end))r.frame=r.end;r.flags|=0x20;return 2;}r.frame=r.end;r.flags|=0x40;return 1;}
        if(extra==0){r.flags|=0x40;return 1;}if(!(finite(r.frame+step)<=r.end)){r.flags|=0x40;return 1;}return 0;
    }
    r.frame=finite(r.frame+step);if(r.frame==0){r.frame=r.end;r.flags|=0x40;if(r.loop)r.flags|=0x20;return 1;}
    if(r.frame<0){r.frame=finite(r.end+r.frame);r.flags|=0x40;if(r.loop)r.flags|=0x20;return 2;}return 0;
}
} // namespace reo::native::animation
