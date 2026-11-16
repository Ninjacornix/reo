#include "room_camera_records.hpp"
#include "../animation/constraint_math.hpp"
#include <algorithm>
#include <bit>
#include <cmath>
#include <cstring>
#include <limits>
#include <stdexcept>

namespace reo::native::gameplay_scenario {
namespace {
using Vector=transform_math::Vector;
namespace math=animation::constraint_math;
template<class T>T field(std::span<const std::byte> bytes,std::size_t at){
    if(at>bytes.size()||sizeof(T)>bytes.size()-at)throw std::invalid_argument("Truncated room camera section");
    T value;std::memcpy(&value,bytes.data()+at,sizeof value);return value;
}
CameraIntegerPoint integer_point(std::span<const std::byte> bytes,std::size_t at){
    return {field<std::int32_t>(bytes,at),field<std::int32_t>(bytes,at+4),field<std::int32_t>(bytes,at+8)};
}
Vector converted(CameraIntegerPoint value){return {float(value[0]),float(value[1]),float(value[2])};}
Vector float_point(std::span<const std::byte> bytes,std::size_t at){
    return {field<float>(bytes,at),field<float>(bytes,at+4),field<float>(bytes,at+8)};
}
float divide(float numerator,float denominator)noexcept{
    if(denominator!=0.f)return numerator/denominator;
    // SDK scalar DIV.S returns signed finite maximum on a zero divisor.
    const auto sign=(std::bit_cast<std::uint32_t>(numerator)^std::bit_cast<std::uint32_t>(denominator))&0x80000000u;
    return std::bit_cast<float>(0x7f7fffffu|sign);
}
Vector line_projection(Vector first,Vector last,Vector point){
    //371160 preserves this scalar accumulator order. Replacing it with the
    // algebraically equivalent dot(point-first,delta) changes FP32 rounding.
    const auto d=math::subtract(last,first);
    float numerator=first.x*d.x-d.x*point.x;
    numerator=(first.y*d.y+numerator)-d.y*point.y;
    numerator=(first.z*d.z+numerator)-d.z*point.z;
    const float denominator=(-d.x*d.x-d.y*d.y)-d.z*d.z;
    const float t=divide(numerator,denominator);
    return {first.x+d.x*t,first.y+d.y*t,first.z+d.z*t};
}
void prepare_boundary(RoomCameraRecord& record,unsigned mode){
    // Owned70A6B0/70A6C0. Columns1/3 address record-8+12*index,
    // hence indices4..7 name the first four volume vertices again.
    constexpr std::array<std::array<std::uint8_t,16>,2> tables{{
        {0,7,1,6, 0,5,3,6, 1,6,0,7, 3,6,0,5},
        {0,5,3,6, 1,6,0,7, 3,6,0,5, 0,7,1,6}}};
    const auto row=(record.boundary_policy>>(16*mode))&3u;
    const auto planar=[&](unsigned column){
        const auto index=tables[mode][4*row+column]-(column&1?4u:0u);
        const auto& point=record.volume[index];return Vector{float(point[0]),0,float(point[2])};
    };
    const auto a=planar(0),b=planar(1),c=planar(2),d=planar(3);
    auto& output=record.boundaries[mode];output.first=a;output.last=d;
    output.first_normal=math::normalize(math::subtract(c,line_projection(a,b,c)));
    output.last_normal=math::normalize(math::subtract(a,line_projection(c,d,a)));
}
}
std::shared_ptr<const RoomCameraRecords> RoomCameraRecords::import(std::span<const std::byte> bytes){
    const auto count=field<std::uint16_t>(bytes,4);
    if(count>capacity||bytes.size()<8+4u*count)throw std::invalid_argument("Room camera record capacity/table");
    auto result=std::shared_ptr<RoomCameraRecords>(new RoomCameraRecords);
    result->count_=std::uint8_t(count);
    for(unsigned i=0;i<count;++i){
        const auto at=field<std::uint32_t>(bytes,8+4*i);
        const auto type=field<std::uint32_t>(bytes,at);
        if(type==0||type>=10)continue; // Actual loader's type switch leaves a zero slot.
        if(at>bytes.size()||0x130>bytes.size()-at)throw std::invalid_argument("Truncated room camera record");
        const auto input=bytes.subspan(at,0x130);auto& record=result->records_[i];
        record.type=std::uint8_t(type);record.policy=std::uint8_t(field<std::uint32_t>(input,0xf4));
        for(unsigned word=0;word<4;++word)record.parameters[word]=field<std::uint32_t>(input,0xc+4*word);
        record.lens=field<float>(input,0x1c);record.distance=field<float>(input,0x20);
        record.anchor=converted(integer_point(input,0x9c));
        for(unsigned vertex=0;vertex<8;++vertex)record.volume[vertex]=integer_point(input,0x24+12*vertex);
        for(unsigned pair=0;pair<4;++pair)for(unsigned end=0;end<2;++end)
            record.endpoints[pair][end]=integer_point(input,0x84+24*pair+12*end);
        record.boundary_policy=field<std::uint32_t>(input,8);
        for(unsigned mode=0;mode<2;++mode){
            const auto& pair=record.endpoints[mode*3];
            record.endpoint_distance[mode]=math::square_root(math::squared_length(math::subtract(converted(pair[0]),converted(pair[1]))));
            prepare_boundary(record,mode);
        }
        std::copy_n(input.begin()+0xe4,16,record.view_controls.begin());
        record.duration=std::uint8_t(field<std::uint32_t>(input,0xf8));
        record.previous=std::uint8_t(field<std::uint32_t>(input,0xfc));
        record.next=std::uint8_t(field<std::uint32_t>(input,0x100));
        record.interpolation=std::uint8_t(field<std::uint32_t>(input,0x12c));
        record.first_control=float_point(input,0x104);record.last_control=float_point(input,0x110);
        std::copy_n(input.begin()+0x11c,8,record.auxiliary.begin());
        record.extra={field<std::uint32_t>(input,0x124),field<std::uint32_t>(input,0x128)};
    }
    for(unsigned root=0;root<count;++root){
        auto& first=result->records_[root];if(first.type!=8||first.previous!=255)continue;
        first.sequence_time=0;first.sequence_root=std::uint8_t(root);
        std::array<bool,capacity> visited{};visited[root]=true;unsigned previous=root;
        for(auto next=first.next;next!=255;next=result->records_[previous].next){
            if(next>=capacity)throw std::invalid_argument("Room camera sequence outside owned pool");
            auto& child=result->records_[next];
            if(child.type!=8||child.previous!=previous)break;
            if(visited[next])throw std::invalid_argument("Cyclic room camera sequence");
            visited[next]=true;child.sequence_root=std::uint8_t(root);child.sequence_time=float(child.duration);previous=next;
        }
    }
    return result;
}
std::optional<std::uint8_t> RoomCameraRecords::follow(std::uint8_t start,std::uint32_t steps)const noexcept{
    if(start>=capacity)return{};
    for(unsigned remaining=steps&255u;remaining;--remaining){start=records_[start].next;if(start>=capacity)return{};}
    return start;
}
std::optional<float> RoomCameraRecords::boundary_ratio(std::uint8_t record,std::uint8_t boundary,Vector point)const noexcept{
    if(record>=capacity||boundary>=2)return{};
    const auto& value=records_[record].boundaries[boundary];
    const float first=(point.x-value.first.x)*value.first_normal.x+(point.z-value.first.z)*value.first_normal.z;
    const float last=(point.x-value.last.x)*value.last_normal.x+(point.z-value.last.z)*value.last_normal.z;
    return divide(first,first+last);
}
std::optional<bool> RoomCameraRecords::contains(std::uint8_t record,Vector point)const noexcept{
    if(record>=capacity)return{};
    try{
        constexpr std::array<std::array<unsigned,3>,6> faces{{{0,3,1},{0,1,4},{0,4,3},{6,7,5},{6,2,7},{6,5,2}}};
        point.y=point.y+10.f;
        for(const auto& face:faces){
            const auto& volume=records_[record].volume;
            const auto a=converted(volume[face[0]]),b=converted(volume[face[1]]),c=converted(volume[face[2]]);
            const auto first=math::subtract(a,b),second=math::subtract(c,b);
            const auto normal=math::normalize({second.y*first.z-second.z*first.y,
                second.z*first.x-second.x*first.z,second.x*first.y-second.y*first.x});
            if(math::square_root(math::squared_length(normal))==0.f)return false;
            const auto delta=math::subtract(point,a);
            if(!((delta.x*normal.x+delta.y*normal.y)+delta.z*normal.z<=0.f))return false;
        }
        return true;
    }catch(const std::exception&){return{};}
}
}
