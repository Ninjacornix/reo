#include "cross_room.hpp"
#include <algorithm>
#include <bit>
namespace reo::native::gameplay_navigation {
namespace {
std::int32_t paired(const CrossRoomLink& link)noexcept{
    return std::bit_cast<std::int16_t>(std::uint16_t(std::uint16_t(link.operands[6])|std::uint16_t(link.operands[7])<<8));
}
struct Search {
    const Bank& bank;ActorFacts actor;std::uint32_t status;const RoomFlags& flags;CrossRoomProfile profile;
    CrossRoomResult result;
    bool valid_link(std::int32_t id)const noexcept{return id>=0&&std::size_t(id)<bank.asset()->links().size();}
    CollectionResult collect(std::uint32_t room,std::int32_t node,std::span<const std::uint8_t> visits,
        bool reverse,bool omit,std::optional<float> known={})noexcept{
        if(result.calls==profile.maximum_calls){result.failure=CrossRoomFailure::work_budget;return {};}
        ++result.calls;
        if(room>=flags.size()){result.failure=CrossRoomFailure::state;return {};}
        const auto variant=bank.current_variant(room);if(!variant){result.failure=CrossRoomFailure::state;return {};}
        const auto collected=collect_links(bank,room,*variant,node,actor,status,flags[room],visits,
            {reverse,omit,profile.initialize_collection_cost?std::optional<float>{0.f}:known,16});
        if(collected.status!=QueryStatus::completed){result.failure=CrossRoomFailure::collection;result.collection_failure=collected.failure;}
        return collected;
    }
    bool adjacent(std::uint32_t a,std::uint32_t b)const noexcept{
        const auto asset=bank.asset();return asset->adjacency()[a+b*asset->links().size()]==1;
    }
    std::optional<std::int32_t> recurse(std::int32_t entry,std::int32_t destination,
        std::span<std::uint8_t> visits,std::size_t depth)noexcept{
        result.depth=std::max(result.depth,depth);
        if(depth>profile.maximum_depth||depth>128){result.failure=CrossRoomFailure::depth_budget;return {};}
        if(!valid_link(entry)||!valid_link(destination)){result.failure=CrossRoomFailure::state;return {};}
        const auto asset=bank.asset();const auto& link=asset->links()[std::size_t(entry)];
        const auto collected=collect(std::uint32_t(std::int32_t(link.room)),link.node,visits,false,true);
        if(collected.status!=QueryStatus::completed)return {};
        for(std::size_t i=0;i<collected.count;++i){
            const auto candidate=collected.candidates[i].link;
            if(candidate!=entry&&paired(asset->links()[candidate])==destination)return std::int32_t(i);
        }
        for(const auto& candidate:collected.values())visits[candidate.link]=1;
        std::int32_t selected=-1;
        for(const auto& candidate:collected.values()){
            if(candidate.link==entry||!adjacent(candidate.link,std::uint32_t(destination)))continue;
            const auto nested=recurse(paired(asset->links()[candidate.link]),destination,visits,depth+1);
            if(!nested)return {};
            // Deliberately no early success: a later failed branch overwrites it.
            selected=*nested;
        }
        return selected;
    }
    CrossRoomResult finish(std::int32_t selected)noexcept{
        result.status=QueryStatus::completed;result.selected=selected;result.failure=CrossRoomFailure::none;return result;
    }
};
}
CrossRoomResult search_link_path(const Bank& bank,ActorFacts actor,std::uint32_t status,const RoomFlags& flags,
    std::int32_t entry,std::int32_t destination,std::span<std::uint8_t> visits,CrossRoomProfile profile)noexcept{
    Search search{bank,actor,status,flags,profile,{}};
    if(!bank.asset()||visits.size()!=bank.asset()->links().size())return search.result;
    const auto selected=search.recurse(entry,destination,visits,1);
    return selected?search.finish(*selected):search.result;
}
CrossRoomResult cross_room_route(Bank& bank,ActorFacts actor,std::uint32_t status,const RoomFlags& flags,
    std::uint32_t source_room,std::uint32_t destination_room,std::int32_t source_node,std::int32_t destination_node,
    CrossRoomOutput& output,CrossRoomProfile profile)noexcept{
    Search search{bank,actor,status,flags,profile,{}};
    if(status&0x88)return search.finish(-1);
    const auto asset=bank.asset();const auto visits=bank.visits(actor.slot);
    if(!asset||visits.size()!=asset->links().size())return search.result;
    const auto source=search.collect(source_room,source_node,visits,false,false);
    if(source.status!=QueryStatus::completed)return search.result;
    if(!source.count)return search.finish(-1);
    const auto target=search.collect(destination_room,destination_node,visits,true,true,source.last_cost);
    if(target.status!=QueryStatus::completed)return search.result;
    if(!target.count)return search.finish(-1);
    std::int32_t selected=-1;
    for(std::size_t i=0;i<source.count&&selected==-1;++i){
        const auto& link=asset->links()[source.candidates[i].link];
        if(std::bit_cast<std::int8_t>(link.operands[0])!=std::int64_t(destination_room))continue;
        for(const auto& candidate:target.values())if(paired(link)==candidate.link){selected=std::int32_t(i);break;}
    }
    for(std::size_t i=0;i<source.count&&selected==-1;++i)for(const auto& destination:target.values()){
        const auto id=source.candidates[i].link;if(!search.adjacent(id,destination.link))continue;
        std::array<std::uint8_t,256> scratch;std::copy(visits.begin(),visits.end(),scratch.begin());
        auto mask=std::span(scratch).first(visits.size());for(const auto& candidate:source.values())mask[candidate.link]=1;
        const auto nested=search.recurse(paired(asset->links()[id]),destination.link,mask,1);
        if(!nested)return search.result;
        if(*nested!=-1){selected=std::int32_t(i);break;}
    }
    output.link=-1;
    if(selected==-1)return search.finish(-1);
    const auto& candidate=source.candidates[std::size_t(selected)];output.link=std::int16_t(candidate.link);
    output.route=*candidate.projection;
    if(output.route.first==asset->links()[candidate.link].node){
        for(const auto& link:source.values())bank.visit(actor.slot,link.link,1);
    }
    return search.finish(output.route.first);
}
}
