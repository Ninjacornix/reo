#include "bank.hpp"
#include <algorithm>
namespace reo::native::gameplay_navigation {
bool Bank::bind(std::shared_ptr<const Asset> asset){
    if(closed_||!asset)return false;
    std::array<std::optional<std::size_t>,128> selection{};
    for(const auto& descriptor:asset->descriptors()){
        if(descriptor.room<0||std::size_t(descriptor.room)>=selection.size())return false;
        if(descriptor.variant<0||descriptor.variant>255)continue;
        const auto variant=variants_.get(std::uint32_t(descriptor.room));if(!variant)return false;
        if(*variant==descriptor.variant)selection[std::size_t(descriptor.room)]=descriptor.graph;
    }
    // Prepare before mutating current state; a host allocation failure leaves
    // the previous binding intact and propagates to the caller's load boundary.
    auto visits=asset==asset_?visits_:std::vector<std::uint8_t>(asset->initial_visit_masks().begin(),asset->initial_visit_masks().end());
    auto edge_flags=asset==asset_?graph_edge_flags_:std::vector<std::array<std::uint8_t,4>>{};
    auto policies=asset==asset_?descriptor_policies_:std::vector<std::uint32_t>{};
    auto graphs=asset==asset_?graph_runtime_:std::vector<RoomGraph>(asset->graphs().begin(),asset->graphs().end());
    if(asset!=asset_)for(const auto& graph:asset->graphs())edge_flags.push_back(graph.initial_edge_flags());
    if(asset!=asset_)for(const auto& descriptor:asset->descriptors())policies.push_back(descriptor.extra);
    if(asset!=asset_)header_byte_=0x24; // Asset::read admits version20030724 only.
    asset_=std::move(asset);visits_=std::move(visits);graph_edge_flags_=std::move(edge_flags);descriptor_policies_=std::move(policies);graph_runtime_=std::move(graphs);selected_=selection;occupancy_={};bound_=true;cold_empty_=false;runtime_views_ready_=true;room_views_known_=true;return true;
}
bool Bank::initialize_cold_empty()noexcept{
    if(closed_||asset_||bound_||cold_empty_)return false;
    clear_rooms();header_byte_=0;cold_empty_=true;return true;
}
bool Bank::refresh_rooms_mode_two()noexcept{
    if(!refresh_source_ready())return false;
    clear_rooms(); //815E30, before descriptor and variant reads.
    if(!asset_){runtime_views_ready_=true;return true;}
    bound_=true;
    for(const auto& descriptor:asset_->descriptors()){
        if(descriptor.room<0||std::size_t(descriptor.room)>=selected_.size())return false;
        if(descriptor.variant<0||descriptor.variant>255)continue;
        const auto variant=variants_.get(std::uint32_t(descriptor.room));if(!variant)return false;
        if(*variant==descriptor.variant)selected_[std::size_t(descriptor.room)]=descriptor.graph;
    }
    runtime_views_ready_=true;return true;
}
void Bank::clear_rooms()noexcept{selected_={};occupancy_={};bound_=false;runtime_views_ready_=false;room_views_known_=true;}
void Bank::close()noexcept{closed_=true;clear_rooms();visits_.clear();graph_edge_flags_.clear();descriptor_policies_.clear();graph_runtime_.clear();asset_.reset();header_byte_=0;}
std::optional<std::uint32_t> Bank::descriptor_policy(std::int32_t room,std::int32_t variant)const noexcept{
    if(closed_||!asset_)return{};
    const auto descriptors=asset_->descriptors();
    for(std::size_t i=0;i<descriptors.size();++i)if(descriptors[i].room==room&&descriptors[i].variant==variant)return descriptor_policies_[i];
    return{};
}
bool Bank::descriptor_policy(std::int32_t room,std::int32_t variant,std::uint32_t policy)noexcept{
    if(closed_||!asset_)return false;
    const auto descriptors=asset_->descriptors();
    for(std::size_t i=0;i<descriptors.size();++i)if(descriptors[i].room==room&&descriptors[i].variant==variant){descriptor_policies_[i]=policy;return true;}
    return false;
}
const RoomGraph* Bank::room(std::uint32_t index)const noexcept{
    if(!bound()||index>=selected_.size()||!selected_[index])return nullptr;
    return &graph_runtime_[*selected_[index]];
}
std::optional<std::size_t> Bank::condition_count(std::uint32_t index)const noexcept{
    if(closed_||!room_views_known_||index>=selected_.size())return{};
    const auto graph=room(index);return graph?graph->conditions().size():0;
}
bool Bank::condition_active(std::uint32_t index,std::size_t condition,std::uint8_t active)noexcept{
    if(closed_||!room_views_known_||index>=selected_.size()||!selected_[index])return false;
    auto& graph=graph_runtime_[*selected_[index]];
    if(condition>=graph.conditions_.size()||graph.condition_base_+16*condition>=graph.encoding_.size())return false;
    graph.conditions_[condition][0]=active;graph.encoding_[graph.condition_base_+16*condition]=active;return true;
}
std::optional<std::uint8_t> Bank::occupancy(std::uint32_t room,std::uint32_t node)const noexcept{
    if(!bound()||room>=occupancy_.size()||node>=occupancy_[0].size())return {};
    return occupancy_[room][node];
}
bool Bank::occupancy(std::uint32_t room,std::uint32_t node,std::uint8_t value)noexcept{
    if(!bound()||room>=occupancy_.size()||node>=occupancy_[0].size())return false;
    occupancy_[room][node]=value;return true;
}
std::span<const std::uint8_t> Bank::visits(std::uint32_t actor)const noexcept{
    if(!bound()||!runtime_views_ready_||actor>=4)return {};
    return std::span<const std::uint8_t>(visits_).subspan(actor*asset_->links().size(),asset_->links().size());
}
bool Bank::visit(std::uint32_t actor,std::uint32_t link,std::uint8_t value)noexcept{
    if(!bound()||!runtime_views_ready_||actor>=4||link>=asset_->links().size())return false;
    visits_[actor*asset_->links().size()+link]=value;return true;
}
bool Bank::clear_actor_visits(std::uint32_t actor)noexcept{
    if(!refresh_source_ready()||actor>=4)return false;
    //8194F0's visit loop uses the published count, which is zero after815E30.
    // It still clears the actor's occupancy bit across all128room rows.
    if(runtime_views_ready_&&asset_){const auto count=asset_->links().size();std::fill_n(visits_.begin()+actor*count,count,0);}
    const auto mask=std::uint8_t(~(1u<<actor));
    for(auto& room:occupancy_)for(auto& node:room)node&=mask;
    return true;
}
std::optional<std::array<std::uint8_t,4>> Bank::edge_flags(std::uint32_t room)const noexcept{
    if(!bound()||room>=selected_.size()||!selected_[room])return {};
    return graph_edge_flags_[*selected_[room]];
}
bool Bank::edge_flags(std::uint32_t room,std::array<std::uint8_t,4> value)noexcept{
    if(!bound()||room>=selected_.size()||!selected_[room])return false;
    graph_edge_flags_[*selected_[room]]=value;return true;
}
}
