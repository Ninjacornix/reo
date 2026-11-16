#include "session_rooms.hpp"
#include "../gameplay_collision/room_geometry.hpp"
#include <cstdio>
#include <map>
#include <stdexcept>
#include <algorithm>

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
    std::optional<std::uint16_t> startup_bytes_scenario;
};
struct SessionRoomGeometry {
    collision::response::Grid walls,floors;
    collision::regions::World regions;
    std::shared_ptr<collision::room_objects::Owner> objects;
    bool ready{};
    SessionRoomGeometry(collision::response::Grid w,collision::response::Grid f,
        collision::regions::World r,std::shared_ptr<collision::room_objects::Owner> o):
        walls(std::move(w)),floors(std::move(f)),regions(std::move(r)),objects(std::move(o)){}
};
namespace {
class Invocation final:public gameplay_contact_world::RoomInvocation {
    std::shared_ptr<NativeSession::RoomLease> lease_;
    std::shared_ptr<SessionRoomGeometry> data_;
    std::shared_ptr<collision::room_objects::Scene> objects_;
    mutable collision::room_geometry::Dynamic dynamic_view_;
    mutable gameplay_world::CollisionRoom geometry_;
public:
    Invocation(std::shared_ptr<NativeSession::RoomLease> lease,std::shared_ptr<SessionRoomGeometry> data):
        lease_(std::move(lease)),data_(std::move(data)),objects_(lease_->object_scene()),
        geometry_{data_->walls,data_->floors,data_->regions,*data_->objects,{},{},false,false}{
        geometry_.filter=filter(lease_->world()->session(),*lease_->programs());
        dynamic_view_=objects_->dynamic();geometry_.dynamic=dynamic_view_.triangles();
        geometry_.objects_enabled=objects_->count()!=0;
    }
    gameplay_contact_world::RoomId identity()const noexcept override{return {lease_->identity()};}
    bool current(gameplay_contact_world::RoomId id)const noexcept override{
        return id==identity()&&lease_->current()&&objects_->open()&&bool(lease_->world()->session().collision_disabled_mask);
    }
    std::uint16_t room_number()const noexcept override{return lease_->room().room;}
    const gameplay_world::CollisionRoom& geometry()const override{
        // Retired data remains readable. Only a current invocation observes the
        // live canonical filter; a retired invocation preserves its last view.
        if(current(identity())){
            geometry_.filter=filter(lease_->world()->session(),*lease_->programs());
            dynamic_view_=objects_->dynamic();geometry_.dynamic=dynamic_view_.triangles();
            geometry_.objects_enabled=objects_->count()!=0;
        }
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
std::shared_ptr<const collision::response::Grid> SessionRooms::retain_floor(std::uint16_t number){
    const auto host=session_.lock();const auto lease=host?host->retain_room(host):nullptr;
    if(!lease||!lease->current()||lease->room().room!=number)return{};
    const auto id=lease->room();const auto identity=std::tuple{id.scenario,id.room,id.variant};
    if(const auto found=floors_.find(identity);found!=floors_.end())
        if(auto retained=found->second.lock())return retained;
    try{
        const auto bytes=host->archive().read_resource(id.scenario,key('g',id));
        if(!bytes)return{};
        auto result=std::make_shared<const collision::response::Grid>(collision::response::Grid::import(*bytes));
        floors_[identity]=result;return result;
    }catch(const std::invalid_argument&){return{};}
}
std::shared_ptr<gameplay_world::World> SessionRooms::world()const noexcept{
    const auto host=session_.lock();return host?std::shared_ptr<gameplay_world::World>(host,&host->world()):nullptr;
}
std::shared_ptr<collision::room_objects::Owner> SessionRooms::objects()const noexcept{
    const auto host=session_.lock();if(!host||!host->open()||!host->room()||!host->room_objects_)return {};
    const auto found=host->room_objects_->scenarios.find(host->room()->scenario);
    return found==host->room_objects_->scenarios.end()?nullptr:found->second;
}
std::optional<RoomObjectStartupBytes> SessionRooms::object_startup_bytes()const noexcept{
    const auto host=session_.lock();const auto owner=objects();
    if(!host||!host->room_objects_||!host->room()||!owner||
       host->room_objects_->startup_bytes_scenario!=host->room()->scenario)return{};
    const auto* row=owner->type(31);if(!row)return{};
    return RoomObjectStartupBytes{std::uint8_t(row->request_threshold),std::uint8_t(row->capacity),row->parameter4};
}
gameplay_scenario::RoomObjectCommands* SessionRooms::script_commands()const noexcept{
    const auto host=session_.lock();const auto owner=objects();
    if(!host||!host->open()||!commands_||!owner||owner.get()!=command_owner_)return nullptr;
    const auto room=host->retain_room(host);if(!room||room->identity()!=command_room_)return nullptr;
    if(command_scene_&&(host->object_instances()!=command_scene_||!command_scene_->open()))return nullptr;
    return commands_.get();
}
bool SessionRooms::initialize_roster_objects()noexcept{
    const auto host=session_.lock();if(!host||!host->open())return false;
    auto& world=host->world();
    if(!world.updating_||!world.primary_object_startup_||!world.scenario||!world.session().asset_loading_mode||
       !*world.session().asset_loading_mode||!host->room()||host->room()->scenario!=*world.scenario)return false;
    auto lease=host->retain_room(host);if(!lease||!lease->current())return false;
    try{
        if(!host->room_objects_)host->room_objects_=std::make_shared<SessionRoomObjects>();
        auto& state=*host->room_objects_;const auto scenario=*world.scenario;
        const auto found=state.scenarios.find(scenario);
        auto previous=found==state.scenarios.end()?std::shared_ptr<collision::room_objects::Owner>{}:found->second;
        const auto* expected=previous.get();
        if(!host->update().roster_room_objects_ready(scenario,expected)||
           !host->reception().roster_room_objects_ready(scenario,expected))return false;
        // Retire the native scene before the source's raw record reset; old
        // invocation leases keep its closed scene and geometry alive.
        commands_.reset();command_owner_=nullptr;command_scene_=nullptr;command_room_={};
        if(!lease->retire_objects())return false;
        if(host->update().replace_roster_room_objects(scenario,{},expected)!=gameplay_update::Status::completed||
           !host->reception().replace_roster_room_objects(scenario,{},expected))return false;
        if(found!=state.scenarios.end())state.scenarios.erase(found);
        auto imported=std::make_shared<collision::room_objects::Owner>();
        state.scenarios.emplace(scenario,imported);
        state.startup_bytes_scenario=scenario; // 6ACF80 cleared the physical type row.
        if(host->update().replace_roster_room_objects(scenario,imported,nullptr)!=gameplay_update::Status::completed||
           !host->reception().replace_roster_room_objects(scenario,imported,nullptr))return false;
        char types[17],placements[17];
        std::snprintf(types,sizeof(types),"obj%03u.dat",unsigned(scenario));
        std::snprintf(placements,sizeof(placements),"r%03u.sto",unsigned(scenario));
        const auto type_bytes=host->archive().read_resource(scenario,types); // 6AD720
        if(type_bytes)*imported=collision::room_objects::Owner::import_types(*type_bytes);
        imported->apply_source_startup_bytes();
        const auto placement_bytes=host->archive().read_resource(scenario,placements); // 6AD610
        if(placement_bytes)imported->import_placements(*placement_bytes);
        else imported->finish_without_placements();
        commands_=std::make_unique<gameplay_scenario::RoomObjectCommands>(*imported);
        command_owner_=imported.get();command_room_=lease->identity();
        return true;
    }catch(...){return false;}
}
std::shared_ptr<gameplay_contact_world::RoomInvocation> SessionRooms::retain(std::uint16_t room){
    status_=RoomResourcesStatus::unavailable_session;
    const auto host=session_.lock();if(!host)return {};
    status_=RoomResourcesStatus::unavailable_room;
    auto lease=host->retain_room(host);if(!lease||lease->room().room!=room)return {};
    const auto bind_objects=[&](const std::shared_ptr<collision::room_objects::Owner>& objects){
        if(host->update().room_objects()==objects.get()&&host->reception().room_objects()==objects.get())return true;
        status_=RoomResourcesStatus::object_binding_refused;
        if(host->update().busy()||host->world().busy())return false;
        if(host->update().bind_room_objects(lease->room().scenario,objects)!=gameplay_update::Status::completed)return false;
        return host->reception().bind_room_objects(lease->room().scenario,objects);
    };
    try{
        auto& cached=lease->geometry_cache();
        if(!cached){
            // Once a resource graph exists, 6AD5C0 is the only producer of
            // scenario objects. A room read cannot silently run it early.
            if(host->resources()){
                const auto owner=objects();
                if(!owner||!owner->initialized()){status_=RoomResourcesStatus::unavailable_object_instances;return {};}
            }
            if(host->update().busy()||host->world().busy()){status_=RoomResourcesStatus::object_binding_refused;return {};}
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
            // Only the constructor's actual model-binding branch needs a
            // loaded pose/part. Explicit shapes and absent grids take their
            // original no-instance paths without a fabricated model service.
            if(lease->directory().section(14))for(const auto& object:objects->objects()){
                const auto& value=*objects->get(object);
                if(value.room!=id.room||!(value.control_flags&1)||(value.control_flags&4)||!(value.control_flags&8))continue;
                const auto* type=objects->type(value.type);const auto asset=host->room_models().asset();
                if(!type||!asset){status_=RoomResourcesStatus::unavailable_object_instances;return {};}
                const auto slot=host->scene_models().resolve(std::uint8_t(type->model_slot));
                if(slot>=asset->parts()||std::none_of(asset->poses().begin(),asset->poses().end(),
                    [&](const auto& pose){return pose.slot==slot;})){
                    status_=RoomResourcesStatus::unavailable_object_instances;return {};
                }
            }
            auto prepared=std::make_shared<SessionRoomGeometry>(std::move(walls),std::move(floors),std::move(regions),objects);
            if(!bind_objects(objects))return {};
            objects->reset_room_grid();
            if(const auto grid=lease->directory().section(14))(void)objects->install_grid(id.room,*grid);
            //6161E0:616250 resets this canonical word at wall installation.
            // A generic Session remains unknown; retaining cached geometry
            // never repeats this producer or overwrites later mask changes.
            host->world().session().collision_disabled_mask=0;
            cached=std::move(prepared);
            const auto initialized=lease->initialize_objects(objects,cached->walls,cached->floors,
                filter(host->world().session(),*lease->programs()));
            cached->ready=initialized.status==collision::room_objects::SceneStatus::complete;
        }
        if(!cached->ready){status_=RoomResourcesStatus::unavailable_object_instances;return {};}
        const auto scene=lease->object_scene();
        if(!scene||!scene->open()){status_=RoomResourcesStatus::unavailable_object_instances;return {};}
        if(!host->world().session().collision_disabled_mask){status_=RoomResourcesStatus::unavailable_geometry;return {};}
        if(!bind_objects(cached->objects))return {};
        if(command_owner_!=cached->objects.get()||command_scene_!=scene.get()||command_room_!=lease->identity()){
            commands_=std::make_unique<gameplay_scenario::RoomObjectCommands>(*cached->objects,scene->lifetime());
            command_owner_=cached->objects.get();command_scene_=scene.get();command_room_=lease->identity();
        }
        auto result=std::make_shared<Invocation>(std::move(lease),cached);
        status_=RoomResourcesStatus::completed;return result;
    }catch(const std::invalid_argument&){status_=RoomResourcesStatus::unavailable_geometry;return {};}
}
}
