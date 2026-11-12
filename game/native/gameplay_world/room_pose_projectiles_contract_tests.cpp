#include "room_pose_projectiles.hpp"
#include "pose_arcs.hpp"
#include "pose_cloud.hpp"
#include "pose_motion.hpp"
#include "pose_trail_effects.hpp"
#include "inherited_pose_trails.hpp"
#include "linked_pose_timing.hpp"
#include "linked_updates.hpp"
#include "pose_parent_flight.hpp"
#include "pose_timed_projectile.hpp"
#include "pose_presets.hpp"
#include "resource_pose_work.hpp"
#include "../gameplay_effects/periodic_visuals.hpp"
#include <fstream>
#include <cstring>
#include <iostream>
#include <source_location>
#include <stdexcept>
namespace g=reo::native::gameplay_world;namespace c=reo::native::gameplay_collision;namespace r=reo::native::gameplay_contact_world;namespace s=reo::native::gameplay_scenario;namespace l=reo::native::gameplay_lighting;namespace t=reo::native::gameplay_tasks;namespace e=reo::native::gameplay_effects;namespace d=c::delivery;
unsigned checks{},banks{},cloud_frames{},room_cases{},profile_refusals{};
void check(bool value,std::source_location p=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Native pose callbacks "+std::to_string(p.line()));}
g::Profile profile(){g::Profile p;p.layouts.push_back({});p.entities.capacity=256;return p;}
g::actors::EntityId work(g::PoseWorkPool& pool,unsigned kind){const auto made=pool.allocate();check(made.status==g::PoseWorkStatus::completed);const auto actor=pool.resolve(made.id);check(actor&&actor->pose_work);actor->active=true;actor->pose_work->update_bound=true;actor->pose_work->kind=std::uint8_t(kind);actor->pose_work->lifetime=1000;return made.id;}
struct Quantum final:g::PoseTimingQuantum {g::World& world;std::optional<std::uint8_t> value;explicit Quantum(g::World& w):world(w){}bool bound_to(const g::World& w)const noexcept override{return &w==&world;}std::optional<std::uint8_t> read()const noexcept override{return value;}};
struct Room final:r::RoomInvocation {
    g::actors::EntityStore ids{{1}};r::RoomId id{ids.create(std::make_unique<g::actors::Entity>()).id};c::response::Grid walls,floors;c::regions::World regions;c::room_objects::Owner objects;g::CollisionRoom view;
    Room(c::response::Grid w,c::response::Grid f):walls(std::move(w)),floors(std::move(f)),view{walls,floors,regions,objects,{},{},false,false}{}
    r::RoomId identity()const noexcept override{return id;}bool current(r::RoomId value)const noexcept override{return value==id&&bool(ids.acquire(value.entity));}std::uint16_t room_number()const noexcept override{return 7;}const g::CollisionRoom& geometry()const override{return view;}std::shared_ptr<s::SceneMatrixPrograms> programs()const override{throw std::runtime_error("Pose floors do not consume matrix programs");}
};
struct Rooms final:r::RoomResources {std::shared_ptr<Room> room;unsigned reads{};std::shared_ptr<r::RoomInvocation> retain(std::uint16_t number)override{++reads;return number==7?room:nullptr;}};
std::vector<std::byte> bytes(const char* path){std::ifstream input(path,std::ios::binary);const std::vector<char> raw{std::istreambuf_iterator<char>(input),{}};check(!raw.empty());std::vector<std::byte> out(raw.size());std::memcpy(out.data(),raw.data(),raw.size());return out;}
std::vector<std::vector<std::byte>> corpus(const char* path){std::ifstream input(path,std::ios::binary);unsigned count{};input.read(reinterpret_cast<char*>(&count),4);check(count==12);std::vector<std::vector<std::byte>> out;for(unsigned i=0;i<count;++i){unsigned size{};input.read(reinterpret_cast<char*>(&size),4);check(size&&size<10000000);out.emplace_back(size);input.read(reinterpret_cast<char*>(out.back().data()),size);check(bool(input));}return out;}
int main(int argc,char** argv)try{
    check(argc==1||argc==5);
    if(argc==5){
        const auto catalog=d::Catalog::import(bytes(argv[1]));const auto assets=corpus(argv[2]);const auto walls=bytes(argv[3]),floors=bytes(argv[4]);
        for(unsigned asset=0;asset<assets.size();asset+=2){
            auto session=std::make_shared<g::Session>();auto world=std::make_shared<g::World>(profile(),session);world->room=7;g::PoseWorkPool pool(*world);d::Packets packets;
            const auto parent=world->spawn_primary(0,std::make_unique<g::Actor>()).id;check(bool(parent));const auto parent_actor=world->resolve(parent);parent_actor->room=7;parent_actor->slot=7;
            Rooms rooms;rooms.room=std::make_shared<Room>(c::response::Grid::import(walls),c::response::Grid::import(floors));std::optional<c::Vec3> origin;
            for(const auto& triangle:rooms.room->floors.triangles()){
                if((triangle.flags&0x80)||triangle.normal.y<=0)continue;
                const c::Vec3 p{(triangle.vertices[0].x+triangle.vertices[1].x+triangle.vertices[2].x)/3.f,(triangle.vertices[0].y+triangle.vertices[1].y+triangle.vertices[2].y)/3.f+5,(triangle.vertices[0].z+triangle.vertices[1].z+triangle.vertices[2].z)/3.f};
                if(rooms.room->floors.floor(p).triangle){origin=p;break;}
            }
            check(bool(origin));const auto surface=rooms.room->floors.floor(*origin);const auto basis=reo::native::transform_math::identity();
            const auto bank=e::EffectBank::import(assets[asset],assets[asset+1]);e::PeriodicVisuals visuals(bank,session->random);g::InheritedPoseTrailEffects inherited(world,visuals,rooms);g::MappedPoseTrailEffects mapped(*world,visuals,rooms,&inherited);
            g::PresetPoseWork presets(*world,pool,packets,catalog);g::RoomPoseProjectiles callbacks(*world,pool,rooms,packets,catalog,&presets,&mapped);
            // Actual cleared24 is a known no-emission branch for both ground
            // attachments. Collision still requires1B9310 and retires first.
            auto id=work(pool,6);auto actor=pool.resolve(id);actor->contact.related=parent;actor->position={origin->x,origin->y,origin->z};const auto floor_reads=rooms.reads;
            check(pool.update(&callbacks).status==g::PoseWorkStatus::completed&&actor->primary==1&&actor->visible&&actor->pose_work->velocity.y==-2&&actor->sampled_surface_height==surface.height&&rooms.reads==floor_reads+1);
            actor->position.y=surface.height-.5f;check(pool.update(&callbacks).status==g::PoseWorkStatus::unavailable&&!pool.resolve(id)&&!actor->active&&!actor->visible&&actor->primary==2&&(actor->auxiliary_status&1)&&rooms.reads==floor_reads+1&&pool.remaining()==64);
            // Non-null source24 cannot silently skip missing attachment owners.
            const auto made=presets.create(parent,basis,{origin->x,origin->y,origin->z},{},0,0);check(made.status==g::PoseWorkStatus::completed);actor=pool.resolve(made.work);
            check(pool.update(&callbacks).status==g::PoseWorkStatus::unavailable&&actor->primary==1&&actor->visible&&actor->sampled_surface_height==surface.height&&pool.resolve(made.work));check(pool.reset()==g::PoseWorkStatus::completed);
            // Source5DEF90 is a required reached capability atphase0.
            id=work(pool,15);actor=pool.resolve(id);actor->position={1,2,3};check(pool.update(&callbacks).status==g::PoseWorkStatus::unavailable&&actor->primary==1&&actor->pose_work->timer==60&&actor->pose_work->travel_speed==50&&actor->previous_position.x==1);check(pool.reset()==g::PoseWorkStatus::completed);
            // Expiry is deferred to the next callback; the actual canonical
            // pose pool retires and clears visibility on that callback.
            id=work(pool,15);actor=pool.resolve(id);actor->primary=1;actor->visible=true;actor->pose_work->basis=basis;actor->pose_work->travel_speed=50;actor->pose_work->timer=1;actor->position={1,2,3};
            check(pool.update(&callbacks).status==g::PoseWorkStatus::completed&&actor->primary==3&&actor->position.z==53&&actor->previous_position.z==3&&pool.resolve(id));check(pool.update(&callbacks).status==g::PoseWorkStatus::completed&&!pool.resolve(id)&&!actor->visible);
            // Recipient checks gate sound only. Serial3 suppresses audio,
            // while variant22 still binds the actual bank0 descriptor100.
            id=work(pool,15);actor=pool.resolve(id);actor->primary=1;actor->pose_work->basis=basis;actor->pose_work->timer=10;actor->pose_work->variant=22;actor->contact.serial=3;actor->auxiliary_status=1;
            check(pool.update(&callbacks).status==g::PoseWorkStatus::completed&&actor->primary==2&&!(actor->auxiliary_status&1));check(pool.update(&callbacks).status==g::PoseWorkStatus::completed&&actor->primary==3&&(actor->auxiliary_status&1));check(pool.update(&callbacks).status==g::PoseWorkStatus::completed&&!pool.resolve(id));
            // Variant20 writes its contact prefix before missing6B25B0 light.
            id=work(pool,15);actor=pool.resolve(id);actor->primary=1;actor->pose_work->basis=basis;actor->pose_work->timer=10;actor->pose_work->variant=20;actor->contact.serial=3;
            check(pool.update(&callbacks).status==g::PoseWorkStatus::unavailable&&actor->primary==2&&pool.resolve(id));check(pool.reset()==g::PoseWorkStatus::completed);
            // No fabricated58DA20 allocation or follower position owner.
            id=work(pool,100);actor=pool.resolve(id);actor->visible=true;check(pool.update(&callbacks).status==g::PoseWorkStatus::unavailable&&actor->primary==1&&!actor->visible&&!actor->pose_work->follower_visual&&actor->pose_work->timer==0);actor->position={origin->x,origin->y,origin->z};
            check(pool.update(&callbacks).status==g::PoseWorkStatus::unavailable&&actor->position.y==actor->sampled_surface_height&&actor->pose_work->timer==0&&pool.resolve(id));check(pool.reset()==g::PoseWorkStatus::completed);
            // Complete kind12 initial flight through real room/packet/trails.
            id=work(pool,12);actor=pool.resolve(id);actor->contact.related=parent;actor->pose_work->emitter_owner=parent;actor->pose_work->basis=basis;actor->position={origin->x,origin->y+100,origin->z};
            for(unsigned frame=0;frame<8;++frame){check(pool.update(&callbacks).status==g::PoseWorkStatus::completed);check(visuals.update({0,1,0}).status==e::VisualStatus::completed);}
            check(pool.resolve(id)&&actor->primary==1&&actor->pose_work->velocity.y<15);check(pool.reset()==g::PoseWorkStatus::completed);
            id=work(pool,12);actor=pool.resolve(id);actor->primary=1;actor->contact.related=parent;actor->position={origin->x,surface.height-.5f,origin->z};actor->pose_work->velocity={};actor->pose_work->acceleration={};
            check(pool.update(&callbacks).status==g::PoseWorkStatus::unavailable&&pool.resolve(id)&&actor->primary==2&&actor->position.y==surface.height&&!(actor->auxiliary_status&1)&&pool.remaining()==63);check(pool.reset()==g::PoseWorkStatus::completed);
            const auto unbound=presets.create(parent,basis,{}, {},14,0);check(unbound.status==g::PoseWorkStatus::unavailable&&pool.resolve(unbound.work)&&pool.remaining()==63&&!pool.resolve(unbound.work)->pose_work->update_bound);check(pool.reset()==g::PoseWorkStatus::completed);
            const auto packetless=presets.create(parent,basis,{}, {},1,0,false);check(packetless.status==g::PoseWorkStatus::completed&&pool.resolve(packetless.work)->pose_work->kind==5);check(pool.reset()==g::PoseWorkStatus::completed);
            id=work(pool,6);actor=pool.resolve(id);actor->position={origin->x,origin->y,origin->z};check(rooms.room->ids.retire(rooms.room->id.entity)==g::actors::EntityStatus::completed);check(pool.update(&callbacks).status==g::PoseWorkStatus::unavailable&&actor->primary==1&&actor->pose_work->velocity.y==-2);check(pool.reset()==g::PoseWorkStatus::completed);
            check(pool.close()==g::PoseWorkStatus::completed&&!callbacks.bound_to(*world));visuals.close();++banks;
        }
    }
    std::cout<<"{\"checks\":"<<checks<<",\"owned_banks\":"<<banks<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
