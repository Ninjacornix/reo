#include "edges.hpp"
namespace reo::native::gameplay_navigation {
AdmissionResult admit_edge(const Bank& bank,std::uint32_t room,std::int32_t source,std::int32_t destination,
    ActorFacts actor,std::uint32_t actor_status,std::optional<std::uint16_t> room_flags)noexcept{
    if(source==destination)return {QueryStatus::completed,true};
    const auto graph=bank.room(room);if(!graph||source<0||std::size_t(source)>=graph->nodes().size())return {};
    const auto& node=graph->nodes()[std::size_t(source)];bool condition=destination==-1;
    if(!condition){
        std::optional<std::size_t> slot;
        for(std::size_t i=0;i<4;++i)if(node.neighbors[i]==destination){slot=i;break;}
        if(!slot)return {QueryStatus::completed,false};
        const auto action=node.actions[*slot]&0xff;
        if(action>=1&&action<=13){
            if(actor_status&0x88u)return {QueryStatus::completed,false};
            condition=true;
        }
        if(action!=10){
            const auto flags=bank.edge_flags(room);const auto packed=node.packed_conditions[*slot];
            for(std::size_t i=0;i<4;++i){
                const auto code=(packed>>(8*i))&0xff;
                if(code<1||code>3)continue;
                if(!flags)return {};
                if((code==2&&(*flags)[i])||(code!=2&&!(*flags)[i]))return {QueryStatus::completed,false};
            }
        }
    }
    if(condition&&node.condition!=-1)return admit_condition(*graph,node.condition,actor,room_flags);
    return {QueryStatus::completed,true};
}
}
