#include "resource_flight_queries.hpp"
#include "../gameplay_collision/trace.hpp"
namespace reo::native::gameplay_effects {
namespace {
gameplay_collision::Vec3 point(transform_math::Vector value){return{value.x,value.y,value.z};}
FlightTrace result(const gameplay_collision::trace::Result& value){
    using gameplay_collision::trace::SamplingStatus;
    if(value.status==SamplingStatus::capacity||value.status==SamplingStatus::nonprogress)return{};
    if(!value.hit)return{true,{}};
    return{true,FlightHit{{value.hit->point.x,value.hit->point.y,value.hit->point.z},std::uint8_t(value.hit->type)}};
}
}
RoomFlightQueries::RoomFlightQueries(std::shared_ptr<gameplay_contact_world::RoomInvocation> room):room_(std::move(room)),id_(room_?room_->identity():gameplay_contact_world::RoomId{}){}
bool RoomFlightQueries::current()const noexcept{return room_&&id_&&room_->current(id_);}
FlightTrace RoomFlightQueries::wall(transform_math::Vector start,transform_math::Vector end){
    if(!current())return{};
    const auto& geometry=room_->geometry();auto filter=geometry.filter;filter.include=0x2ffff;filter.exclude=0;
    const auto hit=gameplay_collision::trace::shorten(geometry.walls,point(start),point(end),filter,geometry.dynamic);
    return current()?result(hit):FlightTrace{};
}
FlightTrace RoomFlightQueries::floor(transform_math::Vector start,transform_math::Vector end){
    if(!current())return{};
    const auto hit=gameplay_collision::trace::floor(room_->geometry().floors,point(start),point(end));
    return current()?result(hit):FlightTrace{};
}
CurrentRoomFlightQueries::CurrentRoomFlightQueries(gameplay_world::World& world,gameplay_contact_world::RoomResources& rooms):world_(world),rooms_(rooms){}
bool CurrentRoomFlightQueries::prepare(){
    if(world_.closed())return false;
    if(queries_)return room_number_&&*room_number_==world_.room;
    const auto number=world_.room;auto room=rooms_.retain(number);
    if(!room||!room->identity()||!room->current(room->identity())||room->room_number()!=number||world_.room!=number)return false;
    queries_=std::make_unique<RoomFlightQueries>(std::move(room));room_number_=number;return true;
}
FlightTrace CurrentRoomFlightQueries::wall(transform_math::Vector start,transform_math::Vector end){return prepare()?queries_->wall(start,end):FlightTrace{};}
FlightTrace CurrentRoomFlightQueries::floor(transform_math::Vector start,transform_math::Vector end){return prepare()?queries_->floor(start,end):FlightTrace{};}
}
