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
    if(asset!=asset_)for(const auto& graph:asset->graphs())edge_flags.push_back(graph.initial_edge_flags());
    asset_=std::move(asset);visits_=std::move(visits);graph_edge_flags_=std::move(edge_flags);selected_=selection;occupancy_={};bound_=true;return true;
}
void Bank::clear_rooms()noexcept{selected_={};occupancy_={};bound_=false;}
void Bank::close()noexcept{closed_=true;clear_rooms();visits_.clear();graph_edge_flags_.clear();asset_.reset();}
const RoomGraph* Bank::room(std::uint32_t index)const noexcept{
    if(!bound()||index>=selected_.size()||!selected_[index])return nullptr;
    return &asset_->graphs()[*selected_[index]];
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
    if(!bound()||actor>=4)return {};
    return std::span<const std::uint8_t>(visits_).subspan(actor*asset_->links().size(),asset_->links().size());
}
bool Bank::visit(std::uint32_t actor,std::uint32_t link,std::uint8_t value)noexcept{
    if(!bound()||actor>=4||link>=asset_->links().size())return false;
    visits_[actor*asset_->links().size()+link]=value;return true;
}
bool Bank::clear_actor_visits(std::uint32_t actor)noexcept{
    if(!bound()||actor>=4)return false;
    const auto count=asset_->links().size();std::fill_n(visits_.begin()+actor*count,count,0);
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
