#include "game/native/gameplay_world/projectile_pose_lights.hpp"
#include <fstream>
unsigned projectile_cases{},projectile_frames{},projectile_queries{},projectile_hits{};
const reo::native::gameplay_collision::response::Grid* projectile_floors{};
bool projectile_floor_port(std::uint8_t* memory,R5900Context* context){
    if(context->pc!=0x617000)return false;
    check(projectile_floors&&transient_original_task&&GPR_U32(context,8)==255&&GPR_U32(context,11)==0);
    const auto point=get<reo::native::gameplay_collision::Vec3>(memory,GPR_U32(context,4));
    const auto floor=projectile_floors->floor(point,255);put(memory,GPR_U32(context,9),floor.material);context->f[0]=floor.height;
    ++projectile_queries;if(floor.triangle)++projectile_hits;return true;
}
struct ProjectileRoom final:reo::native::gameplay_contact_world::RoomInvocation {
    using RoomId=reo::native::gameplay_contact_world::RoomId;
    RoomId id;bool live{true};reo::native::gameplay_collision::regions::World regions;reo::native::gameplay_collision::room_objects::Owner objects;
    reo::native::gameplay_world::CollisionRoom collision;
    ProjectileRoom(RoomId key,const reo::native::gameplay_collision::response::Grid& floors):id(key),collision{floors,floors,regions,objects,{},{},false,false}{}
    RoomId identity()const noexcept override{return id;}
    bool current(RoomId key)const noexcept override{return live&&key==id;}
    std::uint16_t room_number()const noexcept override{return 1;}
    const reo::native::gameplay_world::CollisionRoom& geometry()const override{return collision;}
    std::shared_ptr<reo::native::gameplay_scenario::SceneMatrixPrograms> programs()const override{return{};}
};
struct ProjectileRooms final:reo::native::gameplay_contact_world::RoomResources {
    std::shared_ptr<ProjectileRoom> room;
    std::shared_ptr<reo::native::gameplay_contact_world::RoomInvocation> retain(std::uint16_t number)override{return number==1?room:nullptr;}
};
void compare_projectile_lights(std::uint8_t* memory,const char* path){
    namespace c=reo::native::gameplay_collision;namespace w=reo::native::gameplay_world;namespace u=reo::native::gameplay_update;
    namespace s=reo::native::gameplay_scenario;namespace t=reo::native::gameplay_tasks;
    std::ifstream file(path,std::ios::binary);std::vector<char> raw{std::istreambuf_iterator<char>(file),{}};check(!raw.empty());
    const auto floors=c::response::Grid::import(std::as_bytes(std::span(raw)));check(!floors.triangles().empty());projectile_floors=&floors;
    w::Profile profile;profile.layouts.push_back({});w::World world(profile,std::make_shared<w::Session>());TransientNotifications notifications;u::Owner update(world,notifications);s::Lighting lights;l::TransientLights owner(update,lights);
    const auto compare=[&]{check(lights.primary_count()==memory[0x747538]&&lights.auxiliary_count()==memory[0x748340]);for(unsigned i=0;i<64;++i){check(std::memcmp(&lights.primary()[i],memory+0x747540+56*i,sizeof(s::NativeLight))==0);check(std::memcmp(&lights.auxiliary()[i],memory+0x748350+56*i,sizeof(s::NativeLight))==0);}};
    transient_owner_mode=true;
    std::vector<std::array<float,3>> points{{-1000000,1000,-1000000}};
    for(const auto& triangle:floors.triangles()){const auto& v=triangle.vertices;points.push_back({(v[0].x+v[1].x+v[2].x)/3.f,(v[0].y+v[1].y+v[2].y)/3.f+1000,(v[0].z+v[1].z+v[2].z)/3.f});}
    for(unsigned primary:{0u,63u,64u})for(unsigned auxiliary:{0u,63u,64u})for(const auto& point:points){
        lights.reset_work();std::memset(memory+0x747540,0,64*56);std::memset(memory+0x748350,0,64*56);memory[0x747538]=memory[0x748340]=0;
        const auto definition=l::transient_definition(point);put(memory,0x100000,definition);
        for(unsigned i=0;i<primary;++i){call_transient_owner(memory,0x6b3090,{0x100000,17,1});check(bool(lights.allocate(&definition,17,1)));}
        for(unsigned i=0;i<auxiliary;++i){call_transient_owner(memory,0x6b2cc0,{0x100000,19,0});check(bool(lights.allocate_auxiliary(&definition,19)));}
        put(memory,transient_point_at,point);transient_original_task=false;transient_deny_task=false;const auto queried=projectile_queries;
        call_transient_owner(memory,0x6b25b0,{transient_point_at,0,0});check(projectile_queries==queried+1);
        const auto made=owner.create_projectile(point,floors);check(made.status==l::TransientStatus::completed&&made.lights==std::array<bool,2>{primary<64,auxiliary<64});compare();
        unsigned ticks{};while(transient_original_task){check(++ticks<=4);call_transient_owner(memory,0x5d83d0,{transient_task_at});check(update.linked().run(t::Pass::update).status==t::Status::completed);compare();const auto now=owner.snapshot(made.task);check(bool(now)==transient_original_task);if(now)check(now->state.phase==memory[transient_task_at+8]&&now->state.remaining[0]==get<std::int16_t>(memory,transient_task_at+12)&&now->state.remaining[1]==get<std::int16_t>(memory,transient_task_at+14));++projectile_frames;}
        check(update.linked().size()==0&&owner.failure()==l::TransientStatus::completed);++projectile_cases;
    }
    // Original allocation failure reaches neither616F60 nor either light pool.
    lights.reset_work();std::memset(memory+0x747540,0,64*56);std::memset(memory+0x748350,0,64*56);memory[0x747538]=memory[0x748340]=0;
    for(unsigned i=0;i<t::Scheduler::capacity;++i)check(update.linked().create(std::make_shared<TransientIdleTask>()).status==t::Status::completed);
    const auto queried=projectile_queries;transient_deny_task=true;call_transient_owner(memory,0x6b25b0,{transient_point_at,0,0});check(!transient_original_task&&projectile_queries==queried&&owner.create_projectile(points.front(),floors).status==l::TransientStatus::task_full);compare();++projectile_cases;
    check(update.linked().clear()==t::Status::completed);transient_deny_task=false;
    check(owner.create_projectile({NAN,0,0},floors).status==l::TransientStatus::unavailable);++projectile_cases;
    // Concrete room adapter reads the same actual immutable floor graph.
    const auto room_key=world.spawn_primary(0,std::make_unique<w::Actor>()).id;check(bool(room_key));ProjectileRooms rooms;rooms.room=std::make_shared<ProjectileRoom>(reo::native::gameplay_contact_world::RoomId{room_key},floors);world.room=1;
    w::ProjectilePoseLights bridge(update,lights,owner,rooms);check(bridge.bound_to(world)&&bridge.projectile_light({points[1][0],points[1][1],points[1][2]})&&update.linked().size()==1);
    const auto material=floors.floor({points[1][0],points[1][1],points[1][2]},255).material;
    check(lights.primary_count()==1&&lights.auxiliary_count()==1&&lights.primary()[0].tag==material&&lights.auxiliary()[0].tag==material);
    check(!bridge.ground_flare(room_key)&&!bridge.ground_trail(room_key)&&!bridge.forward_visual(room_key)&&!bridge.follower_visual(room_key)&&!bridge.follower_position(room_key,{}));
    rooms.room->live=false;check(!bridge.projectile_light({}));rooms.room->live=true;world.room=2;check(!bridge.projectile_light({}));world.room=1;
    s::Lighting foreign;bool refused{};try{w::ProjectilePoseLights other(update,foreign,owner,rooms);}catch(const std::invalid_argument&){refused=true;}check(refused);
    for(unsigned i=0;i<4;++i){check(update.linked().run(t::Pass::update).status==t::Status::completed);}
    check(update.linked().size()==0&&lights.primary_count()==0&&lights.auxiliary_count()==0);++projectile_cases;
    check(projectile_hits>0&&projectile_hits<projectile_queries);check(owner.close()==l::TransientStatus::completed&&update.close()==u::Status::completed);transient_owner_mode=false;projectile_floors=nullptr;
}
