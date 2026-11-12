#include "session_rooms.hpp"
#include "../gameplay_effects/resource_flight_queries.hpp"
#include "runtime/assets/virtual_afs.h"
#include <iostream>
#include <source_location>
#include <stdexcept>
#ifdef SESSION_ROOMS_ORIGINAL
#include "tools/native_reconstruction/gameplay_collision_oracle/reference.hpp"
void o2_005DCB60_0x5dcb60(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_005DCB90_0x5dcb90(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_006161E0_0x6161e0(std::uint8_t*,R5900Context*,PS2Runtime*);
#endif
namespace a=reo::native::gameplay_application;
namespace s=reo::native::gameplay_scenario;
namespace c=reo::native::gameplay_collision;
namespace w=reo::native::gameplay_world;
namespace e=reo::native::gameplay_effects;
namespace {
std::size_t checks{},queries{},hits{},rooms{},original_calls{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("SessionRooms check at "+std::to_string(at.line()));
}
struct Notifications final:s::FlagNotifications {
    bool changed(const s::ScenarioFlagChange&)noexcept override{std::terminate();}
    bool changed(const s::StridedFlagChange&)noexcept override{std::terminate();}
};
w::Profile profile(){w::Profile result;result.layouts.push_back({});return result;}
void masks(){
    w::Session session;
    check(!session.collision_disabled_mask);
    check(!a::set_collision_disabled(session,0)&&!a::clear_collision_disabled(session,0));
    check(!session.collision_disabled_mask);
    for(std::uint32_t seed:{0u,0xffffffffu,0x12345678u,0x80000000u,0x55555555u}){
        for(std::uint32_t selector=0;selector<1024;++selector){
            const auto argument=selector%2?selector:0xfffffc00u+selector;
            const auto bit=0x1000u<<((argument+16u)&31u);
            for(bool set:{false,true}){
                session.collision_disabled_mask=seed;
                check(set?a::set_collision_disabled(session,argument):a::clear_collision_disabled(session,argument));
                const auto expected=set?seed|bit:seed&~bit;
                check(*session.collision_disabled_mask==expected);
#ifdef SESSION_ROOMS_ORIGINAL
                static std::vector<std::uint8_t> memory(0x400000);
                ref_write(memory.data(),0x3c2748,seed);
                R5900Context context;context.pc=set?0x5dcb90:0x5dcb60;
                context.g[4].lo=argument;context.g[31].lo=0x1234;PS2Runtime runtime;
                if(set)o2_005DCB90_0x5dcb90(memory.data(),&context,&runtime);
                else o2_005DCB60_0x5dcb60(memory.data(),&context,&runtime);
                check(context.pc==0x1234&&ref_read<std::uint32_t>(memory.data(),0x3c2748)==*session.collision_disabled_mask);
                ++original_calls;
#endif
            }
        }
    }
    a::SessionRooms expired(nullptr);check(!expired.world()&&!expired.retain(73));
    check(expired.status()==a::RoomResourcesStatus::unavailable_session);
}
void owned(const std::filesystem::path& path){
    auto source=std::make_shared<const reo::assets::Source>(path);Notifications notifications;
    for(bool terminal:{false,true}){
        auto host=std::make_shared<a::NativeSession>(source,profile(),notifications);
        a::SessionRooms resources(host),same_owner(host);
        check(resources.world().get()==&host->world());
        check(!resources.retain(73)&&resources.status()==a::RoomResourcesStatus::unavailable_room);
        check(!host->world().session().collision_disabled_mask);
        check(host->install_room({41,73,0})==a::SessionStatus::completed);++rooms;
        check(!host->world().session().collision_disabled_mask);
        check(!resources.retain(72));
        auto room=resources.retain(73);check(bool(room));
        check(resources.status()==a::RoomResourcesStatus::completed);
        auto id=room->identity();check(bool(id)&&room->current(id));
        check(room->room_number()==73&&room->programs().get()==&host->scene_matrices());
        auto lease=host->retain_room(host);check(lease&&lease->world().get()==&host->world());
        check(!host->retain_room({}));
        const auto& geometry=room->geometry();
        check(host->world().session().collision_disabled_mask==0);
#ifdef SESSION_ROOMS_ORIGINAL
        {
            const auto bytes=host->archive().read_resource(41,"w0417300.bin");check(bool(bytes));
            std::vector<std::uint8_t> memory(0x800000);
            for(std::uint32_t seed:{0u,0xffffffffu,0x10000000u,0x80000000u,0x12345678u}){
                std::memcpy(memory.data()+0x10000,bytes->data(),bytes->size());
                ref_write(memory.data(),0x3c2748,seed);
                R5900Context context;context.pc=0x6161e0;context.g[4].lo=0x10000;
                context.g[29].lo=0x7f0000;context.g[31].lo=0x1234;PS2Runtime runtime;
                o2_006161E0_0x6161e0(memory.data(),&context,&runtime);++original_calls;
                check(context.pc==0x1234&&ref_read<std::uint32_t>(memory.data(),0x3c2748)==*host->world().session().collision_disabled_mask);
                const auto& header=geometry.walls.header();
                check(header.step_x==ref_read<std::uint32_t>(memory.data(),0x3c2708)&&header.step_z==ref_read<std::uint32_t>(memory.data(),0x3c270c));
                check(header.columns==ref_read<std::uint32_t>(memory.data(),0x3c2710)&&header.rows==ref_read<std::uint32_t>(memory.data(),0x3c2714));
            }
        }
#endif
        check(geometry.objects.initialized()&&geometry.objects.objects().size()==5);
        check(!geometry.objects_enabled&&!geometry.height_layers&&geometry.dynamic.empty()&&!geometry.objects.grid());
        check(geometry.walls.triangles().size()>0&&geometry.floors.triangles().size()>0);
        auto same=same_owner.retain(73);check(same&&same->identity()==id);
        check(&same->geometry().objects==&geometry.objects&&&same->geometry().walls==&geometry.walls);
        check(a::set_collision_disabled(host->world().session(),0));
        check(room->geometry().filter.disabled==0x10000000u);
        check(resources.retain(73)->geometry().filter.disabled==0x10000000u);
        if(terminal)for(unsigned bit=0;bit<2;++bit)check(host->update().flags().strided(73,bit,2,true,false));
        check(host->step_room_script().status==a::SessionStatus::completed);
        for(unsigned i=0;i<16;++i){const auto channel=host->scene_matrices().inspect(i);check(bool(channel));
            const auto slot=room->geometry().filter.slots[i];
            check(slot.kind==channel->source_type&&slot.state==channel->contact.gate);
        }
        check(a::clear_collision_disabled(host->world().session(),0));
        check(bool(reo::native::gameplay_contact_world::retain(resources.world(),resources)));
        auto flight=std::make_unique<e::RoomFlightQueries>(room);
        // Real owned triangle centroids provide positive floor crossings and
        // finite wall segments through their own planes. Compare the concrete
        // resource consumer to the same canonical imported-grid algorithms.
        const auto wall_filter=[&]{auto value=room->geometry().filter;value.include=0x2ffff;value.exclude=0;return value;}();
        for(unsigned bank=0;bank<2;++bank){const auto triangles=bank?geometry.floors.triangles():geometry.walls.triangles();
            for(std::size_t i=0;i<std::min<std::size_t>(triangles.size(),256);++i){const auto& t=triangles[i];
                const c::Vec3 center{(t.vertices[0].x+t.vertices[1].x+t.vertices[2].x)/3,
                    (t.vertices[0].y+t.vertices[1].y+t.vertices[2].y)/3,
                    (t.vertices[0].z+t.vertices[1].z+t.vertices[2].z)/3};
                const c::Vec3 direction=bank?c::Vec3{0,100,0}:c::Vec3{t.normal.x*100,t.normal.y*100,t.normal.z*100};
                const c::Vec3 start{center.x+direction.x,center.y+direction.y,center.z+direction.z};
                const c::Vec3 end{center.x-direction.x,center.y-direction.y,center.z-direction.z};
                const auto expected=bank?c::trace::floor(geometry.floors,start,end):
                    c::trace::shorten(geometry.walls,start,end,wall_filter,geometry.dynamic);
                const reo::native::transform_math::Vector from{start.x,start.y,start.z},to{end.x,end.y,end.z};
                const auto actual=bank?flight->floor(from,to):flight->wall(from,to);
                check(actual.available&&bool(actual.hit)==bool(expected.hit));
                if(actual.hit){check(actual.hit->point.x==expected.hit->point.x&&actual.hit->point.y==expected.hit->point.y&&actual.hit->point.z==expected.hit->point.z);++hits;}
                ++queries;
            }
        }
        const auto objects=&geometry.objects;const auto wall_count=geometry.walls.triangles().size();
        host->world().room=72;check(!room->current(id)&&!flight->wall({},{ }).available);
        host->world().room=73;check(room->current(id));
        check(host->install_room({41,73,0})==a::SessionStatus::completed);++rooms;
        check(!room->current(id)&&!lease->current());
        check(room->geometry().walls.triangles().size()==wall_count);
        auto replacement=resources.retain(73);check(replacement&&replacement->identity()!=id);
        check(&replacement->geometry().objects==objects&&host->world().session().collision_disabled_mask==0);
        check(!flight->floor({},{ }).available);
        // Matrix leases themselves retain World/Update, even after the room
        // invocation and application caller references are released.
        auto matrices=replacement->programs();std::weak_ptr<a::NativeSession> weak=host;
        host->scene_matrices().close();
        check(!replacement->current(replacement->identity())&&!resources.retain(73));
        check(replacement->geometry().walls.triangles().size()==wall_count);
        check(host->close()==a::SessionStatus::completed);
        check(!replacement->current(replacement->identity())&&replacement->geometry().walls.triangles().size()==wall_count);
        host.reset();lease.reset();room.reset();replacement.reset();same.reset();flight.reset();
        check(!weak.expired()&&bool(matrices));
        matrices.reset();check(weak.expired());
    }
}
}
int main(int argc,char** argv)try{
    masks();check(argc==1||argc==2);
    if(argc==2){const std::string_view value(argv[1]);owned(std::filesystem::path(std::u8string(value.begin(),value.end())));}
    std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"rooms\":"<<rooms<<",\"queries\":"<<queries<<",\"hits\":"<<hits<<",\"original_calls\":"<<original_calls<<",\"game_launched\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
