#include "room_return_points.hpp"
#include <algorithm>
#include <bit>
#include <cmath>
#include <cstring>
#include <stdexcept>
namespace reo::native::gameplay_scenario {
namespace {
template<class T>T read(std::span<const std::byte> data,std::size_t at){
    if(at>data.size()||sizeof(T)>data.size()-at)throw std::invalid_argument("Native RTP field outside asset");
    T value;std::memcpy(&value,data.data()+at,sizeof value);return value;
}
std::int8_t byte(std::uint32_t value){return std::bit_cast<std::int8_t>(std::uint8_t(value));}
bool finite(transform_math::Vector p){return std::isfinite(p.x)&&std::isfinite(p.y)&&std::isfinite(p.z);}
std::optional<std::uint16_t> key(std::uint32_t room,const gameplay_session::RoomVariants& variants){
    const auto signed_room=byte(room);if(signed_room<0)return{};
    const auto variant=variants.get(std::uint8_t(signed_room));if(!variant)return{};
    return std::uint16_t((std::uint16_t(std::uint8_t(signed_room))<<8)|*variant);
}
float distance(transform_math::Vector a,transform_math::Vector b){
    const float x=a.x-b.x,y=a.y-b.y,z=a.z-b.z;
    const float xx=x*x,yy=y*y,zz=z*z;
    const float xy=xx+yy,total=xy+zz;
    if(!std::isfinite(total))throw std::invalid_argument("Native RTP finite distance required");
    return 0.f+std::sqrt(total); //191D10 ordered VU sum, sqrt, then add vf0.x
}
}
std::shared_ptr<const RoomReturnPoints> RoomReturnPoints::import(std::span<const std::byte> data){
    if(data.size()>0xc000)throw std::invalid_argument("Native RTP exceeds its source allocation");
    const auto count=read<std::uint32_t>(data,0);
    if(count>(data.size()-4)/4)throw std::invalid_argument("Native RTP room table unavailable");
    auto result=std::make_shared<RoomReturnPoints>();result->rooms_.reserve(count);
    const auto payload=std::size_t(4)+4*count;
    for(std::size_t index=0;index<count;++index){
        ReturnPointRoom room;room.key=read<std::uint16_t>(data,4+2*index);
        const auto start=payload+read<std::uint16_t>(data,4+2*count+2*index);
        const auto points=read<std::uint32_t>(data,start),groups=read<std::uint32_t>(data,start+4);
        if(points>data.size()/4||groups>data.size()/4||std::uint64_t(points)+groups>(data.size()-std::min(start+8,data.size()))/4)
            throw std::invalid_argument("Native RTP record offsets unavailable");
        for(std::size_t i=0;i<points;++i){
            const auto offset=read<std::uint32_t>(data,start+8+4*i);
            const auto value=read<transform_math::Vector>(data,start+std::size_t(offset));
            if(!finite(value))throw std::invalid_argument("Native RTP finite point required");
            room.points.push_back(value);
        }
        for(std::size_t i=0;i<groups;++i){
            const auto offset=read<std::uint32_t>(data,start+8+4*(std::size_t(points)+i));
            const auto at=start+std::size_t(offset);
            ReturnPointGroup group;group.kind=read<std::int8_t>(data,at);group.mode=read<std::int8_t>(data,at+1);
            const auto total=read<std::int8_t>(data,at+2);
            if(total<0)throw std::invalid_argument("Native RTP negative group size");
            for(unsigned j=0;j<unsigned(total);++j){
                const auto point=read<std::int8_t>(data,at+3+j);
                if(point<0||std::uint32_t(point)>=points)throw std::invalid_argument("Native RTP group point unavailable");
                group.indices.push_back(point);
            }
            room.groups.push_back(std::move(group));
        }
        result->rooms_.push_back(std::move(room));
    }
    return result;
}
const ReturnPointRoom* RoomReturnPoints::find(std::uint16_t room_key)const noexcept{
    const auto found=std::find_if(rooms_.begin(),rooms_.end(),[&](const auto& row){return row.key==room_key;});
    return found==rooms_.end()?nullptr:&*found;
}
std::optional<ReturnPointResult> RoomReturnPoints::point(std::uint32_t room,std::uint32_t mode,
    std::uint32_t kind,std::uint32_t index,const gameplay_session::RoomVariants& variants,gameplay_session::Random& random)const{
    if(rooms_.empty())return ReturnPointResult{};
    const auto room_key=key(room,variants);if(!room_key)return{};
    const auto row=find(*room_key);if(!row||row->points.empty()||row->groups.empty())return ReturnPointResult{};
    const auto selected=std::find_if(row->groups.begin(),row->groups.end(),[&](const auto& group){return group.kind==byte(kind)&&(group.mode==byte(mode)||byte(mode)==-1);});
    if(selected==row->groups.end()||selected->indices.empty())return ReturnPointResult{};
    const auto ordinal=byte(index);if(ordinal<0||std::size_t(ordinal)>=selected->indices.size())return{};
    auto position=row->points[std::size_t(selected->indices[std::size_t(ordinal)])];
    transform_math::require_profile();
    const auto turn=random.request(1);const auto radius=random.request(1)%71u;
    const auto trig=transform_math::sin_cos(std::bit_cast<float>(0x38c90fdbu)*float(turn));
    const float x=float(radius)*trig.sine,z=float(radius)*trig.cosine;
    position.x=position.x+x;position.z=position.z+z;
    return ReturnPointResult{std::int8_t(std::size_t(ordinal)+1==selected->indices.size()),position};
}
std::optional<std::int8_t> RoomReturnPoints::nearest(transform_math::Vector position,std::uint32_t room,
    std::uint32_t mode,std::uint32_t kind,const gameplay_session::RoomVariants& variants)const{
    if(rooms_.empty())return std::int8_t(-1);
    const auto room_key=key(room,variants);if(!room_key)return{};
    const auto row=find(*room_key);if(!row||row->points.empty()||row->groups.empty())return std::int8_t(-1);
    const auto selected=std::find_if(row->groups.begin(),row->groups.end(),[&](const auto& group){return group.mode==byte(mode)&&(group.kind==byte(kind)||byte(room)==byte(kind));});
    if(selected==row->groups.end()||selected->indices.empty())return std::int8_t(-1);
    if(!finite(position))return{};
    transform_math::require_profile();float best{};std::int8_t closest{};
    for(std::size_t index=0;index<selected->indices.size();++index){
        const auto value=distance(position,row->points[std::size_t(selected->indices[index])]);
        if(!index||value<best){best=value;closest=std::int8_t(index);}
    }
    return closest;
}
}
