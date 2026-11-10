#include "navigation.hpp"
#include <algorithm>
#include <bit>
#include <cmath>

namespace reo::native::gameplay_navigation {
namespace {
struct Invalid {ImportError reason;std::size_t offset;};
struct Reader {
    std::span<const std::uint8_t> data;
    std::size_t origin{};
    void check(std::size_t at,std::size_t n)const{
        if(at>data.size()||n>data.size()-at)throw Invalid{ImportError::layout,origin+at};
    }
    std::uint16_t u16(std::size_t at)const{check(at,2);return std::uint16_t(data[at])|std::uint16_t(data[at+1])<<8;}
    std::uint32_t u32(std::size_t at)const{check(at,4);return std::uint32_t(u16(at))|std::uint32_t(u16(at+2))<<16;}
    std::int32_t i32(std::size_t at)const{return std::bit_cast<std::int32_t>(u32(at));}
    float real(std::size_t at)const{return std::bit_cast<float>(u32(at));}
    void budget(std::size_t value,std::size_t maximum,std::size_t at)const{if(value>maximum)throw Invalid{ImportError::budget,at};}
};
bool finite(Position p)noexcept{return std::isfinite(p.x)&&std::isfinite(p.y)&&std::isfinite(p.z);}
}
std::span<const std::uint8_t> RoomGraph::condition_directory_entry(std::size_t index)const noexcept{
    if(index>=directory_entries_.size()||!directory_entries_[index])return {};
    const auto start=directory_entries_[index];auto end=encoding_.size();
    for(auto other:directory_entries_)if(other>start&&other<end)end=other;
    return std::span<const std::uint8_t>(encoding_).subspan(start,end-start);
}
std::optional<Asset> Asset::read(std::span<const std::uint8_t> bytes,ImportFailure& failure){
    failure={};
    try{
        if(bytes.size()<12||bytes.size()>4*1024*1024)throw Invalid{ImportError::size,0};
        Reader input{bytes};
        if(input.u32(0)!=0x20030724)throw Invalid{ImportError::version,0};
        const auto a=std::size_t(input.u32(4)),b=std::size_t(input.u32(8));
        if(a<12||(a&3)||(b&3))throw Invalid{ImportError::layout,4};
        const auto count=std::size_t(input.u32(a));input.budget(count,256,a);
        const auto matrix=a+4+12*count,matrix_size=count*count;
        const auto visits=matrix+((matrix_size+3)&~std::size_t(3));
        input.check(a,4+12*count+((matrix_size+3)&~std::size_t(3))+4*count);
        if(visits+4*count!=b)throw Invalid{ImportError::layout,8};
        Asset asset;
        for(std::size_t i=0;i<count;++i){
            const auto at=a+4+12*i;CrossRoomLink link;
            link.room=std::bit_cast<std::int8_t>(bytes[at]);link.variant=std::bit_cast<std::int8_t>(bytes[at+1]);
            link.node=std::bit_cast<std::int8_t>(bytes[at+2]);link.condition=std::bit_cast<std::int8_t>(bytes[at+3]);
            std::copy_n(bytes.begin()+at+4,8,link.operands.begin());asset.links_.push_back(link);
        }
        asset.adjacency_.assign(bytes.begin()+matrix,bytes.begin()+matrix+matrix_size);
        asset.initial_visit_masks_.assign(bytes.begin()+visits,bytes.begin()+visits+4*count);
        const auto rooms=std::size_t(input.u32(b));input.budget(rooms,512,b);input.check(b+4,12*rooms);
        const auto descriptor_end=b+4+12*rooms;
        std::vector<std::uint32_t> offsets;
        for(std::size_t i=0;i<rooms;++i){
            const auto at=b+4+12*i,offset=std::size_t(input.u32(at+4));
            if(offset<descriptor_end||(offset&3)||offset>=bytes.size())throw Invalid{ImportError::layout,at+4};
            offsets.push_back(std::uint32_t(offset));
        }
        std::sort(offsets.begin(),offsets.end());offsets.erase(std::unique(offsets.begin(),offsets.end()),offsets.end());
        for(std::size_t index=0;index<offsets.size();++index){
            const auto start=std::size_t(offsets[index]),end=index+1<offsets.size()?std::size_t(offsets[index+1]):bytes.size();
            Reader room{bytes.subspan(start,end-start),start};RoomGraph graph;graph.source_offset_=std::uint32_t(start);
            const auto tail=std::size_t(room.u32(0)),directory=std::size_t(room.u32(4)),nodes=std::size_t(room.u32(8));
            room.budget(nodes,128,start+8);
            if(tail!=12+64*nodes+4*nodes*nodes)throw Invalid{ImportError::layout,start};
            room.check(12,64*nodes+4*nodes*nodes);room.check(tail,8);
            const auto conditions=std::size_t(room.u32(tail+4));room.budget(conditions,4096,start+tail+4);
            if(directory!=tail+8+16*conditions)throw Invalid{ImportError::layout,start+4};
            room.check(tail+8,16*conditions+64);
            for(std::size_t n=0;n<nodes;++n){
                const auto at=12+64*n;Node node;node.active=room.data[at];node.neighbor_count=std::bit_cast<std::int8_t>(room.data[at+1]);
                if(node.neighbor_count>4)throw Invalid{ImportError::layout,start+at+1};
                node.group=room.u16(at+2);node.position={room.real(at+4),room.real(at+8),room.real(at+12)};
                if(!finite(node.position))throw Invalid{ImportError::coordinates,start+at+4};
                node.condition=room.i32(at+16);
                for(std::size_t edge=0;edge<4;++edge){node.neighbors[edge]=std::bit_cast<std::int8_t>(room.data[at+20+edge]);node.actions[edge]=room.u16(at+24+2*edge);}
                graph.nodes_.push_back(node);
            }
            for(std::size_t i=0;i<nodes*nodes;++i){RouteCandidates candidates;std::copy_n(room.data.begin()+12+64*nodes+4*i,4,candidates.begin());graph.routes_.push_back(candidates);}
            for(std::size_t i=0;i<conditions;++i){Condition condition;std::copy_n(room.data.begin()+tail+8+16*i,16,condition.begin());graph.conditions_.push_back(condition);}
            for(std::size_t i=0;i<16;++i){
                const auto relative=std::size_t(room.u32(directory+4*i));
                if(relative){if(relative<64)throw Invalid{ImportError::layout,start+directory+4*i};room.check(directory,relative);room.check(directory+relative,1);graph.directory_entries_[i]=directory+relative;}
            }
            graph.encoding_.assign(room.data.begin(),room.data.end());asset.graphs_.push_back(std::move(graph));
        }
        for(std::size_t i=0;i<rooms;++i){
            const auto at=b+4+12*i;const auto offset=input.u32(at+4);
            asset.descriptors_.push_back({std::bit_cast<std::int16_t>(input.u16(at)),std::bit_cast<std::int16_t>(input.u16(at+2)),input.u32(at+8),std::size_t(std::lower_bound(offsets.begin(),offsets.end(),offset)-offsets.begin())});
        }
        return asset;
    }catch(const Invalid& invalid){failure={invalid.reason,invalid.offset};return std::nullopt;}
}
const RoomGraph* Asset::find_room(std::int32_t room,std::int32_t variant)const noexcept{
    const RoomGraph* found=nullptr;
    for(const auto& descriptor:descriptors_)if(descriptor.room==room&&descriptor.variant==variant)found=&graphs_[descriptor.graph];
    return found;
}
NodeResult nearest_node(const RoomGraph& graph,Position query,std::int8_t group)noexcept{
    if(!finite(query))return {};
    bool found=false;float best{};std::int8_t selected=-1;
    for(std::size_t i=0;i<graph.nodes().size();++i){
        const auto& node=graph.nodes()[i];if(!node.active||(group>=0&&node.group!=std::uint16_t(group)))continue;
        const float x=node.position.x-query.x,y=node.position.y-query.y,z=node.position.z-query.z;
        const float xx=x*x,yy=y*y,zz=z*z,sum=xx+yy,total=sum+zz;
        if(!std::isfinite(total))return {};
        const float distance=std::sqrt(total);
        if(!found||distance<best){best=distance;selected=std::int8_t(i);found=true;}
    }
    return found?NodeResult{QueryStatus::completed,selected}:NodeResult{};
}
ActionResult reverse_edge_action(const RoomGraph& graph,std::int32_t index)noexcept{
    const auto nodes=graph.nodes();
    if(index<0||std::size_t(index)>=nodes.size())return {};
    const auto& node=nodes[std::size_t(index)];
    if(node.neighbor_count<=0)return {QueryStatus::completed,-1};
    for(std::int32_t i=0;i<node.neighbor_count;++i){
        const auto neighbor=node.neighbors[std::size_t(i)];
        if(neighbor<0||std::size_t(neighbor)>=nodes.size())return {};
        const auto& reverse=nodes[std::size_t(neighbor)];std::int32_t action=-1;
        for(std::int32_t j=0;j<reverse.neighbor_count;++j){
            if(reverse.neighbors[std::size_t(j)]!=index)continue;
            const auto word=reverse.actions[std::size_t(j)];
            switch(word&0xff){
            case 4:case 5:case 8:case 9:action=word;break;
            case 11:case 12:return {QueryStatus::completed,11};
            default:break;
            }
        }
        if(action!=-1)return {QueryStatus::completed,action};
    }
    if(node.condition==-1)return {QueryStatus::completed,-1};
    if(node.condition<0||std::size_t(node.condition)>=graph.conditions().size())return {};
    const auto& condition=graph.conditions()[std::size_t(node.condition)];
    if(condition[1]==0)return {QueryStatus::completed,4};
    if(condition[1]==1)return {QueryStatus::completed,5};
    if(condition[1]==6){if(condition[3]==4)return {QueryStatus::completed,8};if(condition[3]==5)return {QueryStatus::completed,9};}
    return {QueryStatus::completed,-1};
}
}
