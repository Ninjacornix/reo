#include "session_rooms.hpp"
#include "../gameplay_collision/room_geometry.hpp"
#include <cstdio>
#include <map>
#include <stdexcept>

namespace reo::native::gameplay_application {
namespace collision=gameplay_collision;
namespace {
std::uint32_t mask_bit(std::uint32_t selector)noexcept{return 0x1000u<<((selector+16u)&31u);}
collision::response::Filter filter(const gameplay_world::Session& session,
    const gameplay_scenario::SceneMatrixPrograms& programs){
    if(!session.collision_disabled_mask)throw std::logic_error("Collision mask producer unavailable");
    collision::response::Filter result;result.disabled=*session.collision_disabled_mask;
    for(unsigned i=0;i<16;++i){const auto channel=programs.inspect(i);
        if(!channel)throw std::logic_error("Collision matrix channel unavailable");
        result.slots[i]={channel->source_type,channel->contact.gate};
    }
    return result;
}
}
bool set_collision_disabled(gameplay_world::Session& session,std::uint32_t selector)noexcept{
    if(!session.collision_disabled_mask)return false;
    *session.collision_disabled_mask|=mask_bit(selector);return true;
}
bool clear_collision_disabled(gameplay_world::Session& session,std::uint32_t selector)noexcept{
    if(!session.collision_disabled_mask)return false;
    *session.collision_disabled_mask&=~mask_bit(selector);return true;
}
struct SessionRoomObjects {
    std::map<std::uint16_t,std::shared_ptr<collision::room_objects::Owner>> scenarios;
};
struct SessionRoomGeometry {
    collision::response::Grid walls,floors;
    collision::regions::World regions;
    std::shared_ptr<collision::room_objects::Owner> objects;
    collision::room_geometry::Dynamic dynamic;
    SessionRoomGeometry(collision::response::Grid w,collision::response::Grid f,
        collision::regions::World r,std::shared_ptr<collision::room_objects::Owner> o):
        walls(std::move(w)),floors(std::move(f)),regions(std::move(r)),objects(std::move(o)){}
};
namespace {
class Invocation final:public gameplay_contact_world::RoomInvocation {
    std::shared_ptr<NativeSession::RoomLease> lease_;
    std::shared_ptr<SessionRoomGeometry> data_;
    mutable gameplay_world::CollisionRoom geometry_;
public:
    Invocation(std::shared_ptr<NativeSession::RoomLease> lease,std::shared_ptr<SessionRoomGeometry> data):
        lease_(std::move(lease)),data_(std::move(data)),
        geometry_{data_->walls,data_->floors,data_->regions,*data_->objects,{},data_->dynamic.triangles(),false,false}{
        geometry_.filter=filter(lease_->world()->session(),*lease_->programs());
    }
    gameplay_contact_world::RoomId identity()const noexcept override{return {lease_->identity()};}
    bool current(gameplay_contact_world::RoomId id)const noexcept override{
        return id==identity()&&lease_->current()&&bool(lease_->world()->session().collision_disabled_mask);
    }
    std::uint16_t room_number()const noexcept override{return lease_->room().room;}
    const gameplay_world::CollisionRoom& geometry()const override{
        // Retired data remains readable. Only a current invocation observes the
        // live canonical filter; a retired invocation preserves its last view.
        if(current(identity()))geometry_.filter=filter(lease_->world()->session(),*lease_->programs());
        return geometry_;
    }
    std::shared_ptr<gameplay_scenario::SceneMatrixPrograms> programs()const override{return lease_->programs();}
};
std::string key(char prefix,gameplay_scenario::content::RoomId room){
    char value[17];const auto count=std::snprintf(value,sizeof(value),"%c%03u%02u%02u.bin",prefix,
        unsigned(room.scenario),unsigned(room.room),unsigned(room.variant));
    if(count<0||std::size_t(count)>=sizeof(value))throw std::invalid_argument("Room key exceeds resource extent");
    return value;
}
}
SessionRooms::SessionRooms(std::shared_ptr<NativeSession> session):session_(std::move(session)){}
std::shared_ptr<gameplay_world::World> SessionRooms::world()const noexcept{
    const auto host=session_.lock();return host?std::shared_ptr<gameplay_world::World>(host,&host->world()):nullptr;
}
std::shared_ptr<gameplay_contact_world::RoomInvocation> SessionRooms::retain(std::uint16_t room){
    status_=RoomResourcesStatus::unavailable_session;
    const auto host=session_.lock();if(!host)return {};
    status_=RoomResourcesStatus::unavailable_room;
    auto lease=host->retain_room(host);if(!lease||lease->room().room!=room)return {};
    try{
        auto& cached=lease->geometry_cache();
        if(!cached){
            status_=RoomResourcesStatus::unavailable_geometry;
            const auto id=lease->room();
            const auto w=host->archive().read_resource(id.scenario,key('w',id));
            const auto g=host->archive().read_resource(id.scenario,key('g',id));
            const auto r=lease->directory().section(16);
            if(!w||!g||!r)return {};
            auto walls=collision::response::Grid::import(*w),floors=collision::response::Grid::import(*g);
            auto regions=collision::regions::World::import(*r);
            if(!host->room_objects_)host->room_objects_=std::make_shared<SessionRoomObjects>();
            auto& objects=host->room_objects_->scenarios[id.scenario];
            if(!objects){
                char types[17],placements[17];
                std::snprintf(types,sizeof(types),"obj%03u.dat",unsigned(id.scenario));
                std::snprintf(placements,sizeof(placements),"r%03u.sto",unsigned(id.scenario));
                const auto type_bytes=host->archive().read_resource(id.scenario,types);
                const auto placement_bytes=host->archive().read_resource(id.scenario,placements);
                if(!type_bytes||!placement_bytes)return {};
                objects=std::make_shared<collision::room_objects::Owner>(collision::room_objects::Owner::import(*type_bytes,*placement_bytes));
            }
            //745D60 counts actual6AD4E0 instances, not imported placements.
            // Until that construction/proxy lifecycle is attached, only an
            // authored room without matching placements has a proved zero.
            for(const auto& object:objects->objects())if(objects->get(object)->room==id.room){
                status_=RoomResourcesStatus::unavailable_object_instances;return {};
            }
            auto prepared=std::make_shared<SessionRoomGeometry>(std::move(walls),std::move(floors),std::move(regions),objects);
            //6161E0:616250 resets this canonical word at wall installation.
            // A generic Session remains unknown; retaining cached geometry
            // never repeats this producer or overwrites later mask changes.
            host->world().session().collision_disabled_mask=0;
            prepared->dynamic=collision::room_geometry::build_dynamic(*objects,id.room,prepared->walls,
                filter(host->world().session(),*lease->programs()));
            if(prepared->dynamic.status!=collision::trace::SamplingStatus::complete){
                status_=RoomResourcesStatus::unsupported_dynamic;return {};
            }
            cached=std::move(prepared);
        }
        if(!host->world().session().collision_disabled_mask){status_=RoomResourcesStatus::unavailable_geometry;return {};}
        auto result=std::make_shared<Invocation>(std::move(lease),cached);
        status_=RoomResourcesStatus::completed;return result;
    }catch(const std::invalid_argument&){status_=RoomResourcesStatus::unavailable_geometry;return {};}
}
}
