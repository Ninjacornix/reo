#include "pose_arcs.hpp"
#include "pose_cloud.hpp"
#include "pose_motion.hpp"
#include "pose_trail_effects.hpp"
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
    check(argc==1||argc==5);auto session=std::make_shared<g::Session>();g::World world(profile(),session);g::PoseWorkPool pool(world);Quantum quantum(world);g::PoseMotionUpdates motions(world,pool,&quantum);Rooms rooms;g::RoomPoseArcs arcs(world,pool,rooms,nullptr,&motions);world.room=7;
    auto id=work(pool,19);auto actor=pool.resolve(id);actor->position.z=30;actor->pose_work->timer=INT16_MIN;check(pool.update(&arcs).status==g::PoseWorkStatus::completed&&actor->primary==1&&actor->position.z==-370);check(pool.update(&arcs).status==g::PoseWorkStatus::completed&&actor->pose_work->timer==INT16_MAX);actor->contact.serial=1;check(pool.update(&arcs).status==g::PoseWorkStatus::completed&&actor->pose_work->timer==INT16_MAX);check(pool.reset()==g::PoseWorkStatus::completed);
    id=work(pool,11);actor=pool.resolve(id);actor->pose_work->timer=17;check(pool.update(&arcs).status==g::PoseWorkStatus::unavailable&&actor->primary==1&&actor->visible&&actor->pose_work->timer==17&&actor->pose_work->lifetime==999);check(pool.reset()==g::PoseWorkStatus::completed);
    quantum.value=2;id=work(pool,11);actor=pool.resolve(id);check(pool.update(&arcs).status==g::PoseWorkStatus::completed&&actor->pose_work->timer==89);actor->response_class=1;check(pool.update(&arcs).status==g::PoseWorkStatus::completed&&!pool.resolve(id)&&pool.remaining()==64);
    id=work(pool,13);actor=pool.resolve(id);actor->sampled_surface_height=73;check(pool.update(&arcs).status==g::PoseWorkStatus::completed&&rooms.reads==0);check(pool.update(&arcs).status==g::PoseWorkStatus::unavailable&&rooms.reads==1&&actor->primary==1&&actor->sampled_surface_height==73);check(pool.reset()==g::PoseWorkStatus::completed);
    id=work(pool,16);actor=pool.resolve(id);check(pool.update(&arcs).status==g::PoseWorkStatus::unavailable&&actor->primary==1&&rooms.reads==1);check(pool.reset()==g::PoseWorkStatus::completed);
    if(argc==5){
        const auto catalog=d::Catalog::import(bytes(argv[1]));const auto assets=corpus(argv[2]);const auto walls=bytes(argv[3]),floors=bytes(argv[4]);
        for(unsigned asset=0;asset<assets.size();asset+=2){
            auto owned_session=std::make_shared<g::Session>();g::World owned_world(profile(),owned_session);owned_world.room=7;g::PoseWorkPool owned_pool(owned_world);const auto parent=owned_world.spawn_primary(0,std::make_unique<g::Actor>()).id;check(bool(parent));owned_world.resolve(parent)->primary=2;owned_world.resolve(parent)->secondary=11;
            s::Lighting lighting;l::Pool light_pool(lighting);t::Scheduler tasks;l::TimedLights timed(owned_world,tasks,light_pool);const auto bank=e::EffectBank::import(assets[asset],assets[asset+1]);e::PeriodicVisuals visuals(bank,owned_session->random);g::PoseCloudUpdates clouds(owned_world,owned_pool,visuals,timed);s::SceneResources resources;s::ResourceTemplates templates;d::Packets packets;g::ResourcePoseWork poses(owned_world,owned_pool,resources,templates,packets,catalog);
            const reo::native::transform_math::Vector point{1,2,3};const auto made=poses.attach(parent,0x6a,20,0,nullptr,&point,2);check(made.status==g::PoseWorkStatus::completed);bool admitted=true;if(bank->geometry().resolve(0x55)){try{(void)bank->bind(0x55,0);}catch(const std::invalid_argument&){admitted=false;}}
            if(!admitted){check(owned_pool.update(&clouds).status==g::PoseWorkStatus::unavailable&&owned_pool.resolve(made.work)->primary==1&&tasks.size()==0);check(owned_pool.reset()==g::PoseWorkStatus::completed);++profile_refusals;}
            else{for(unsigned frame=0;frame<76;++frame){check(owned_pool.update(&clouds).status==g::PoseWorkStatus::completed);check(visuals.update({0,1,0}).status==e::VisualStatus::completed);check(tasks.run(t::Pass::update).status==t::Status::completed);++cloud_frames;}check(!owned_pool.resolve(made.work)&&owned_pool.remaining()==64&&tasks.size()==0&&light_pool.size()==0);}
            Rooms real_rooms;real_rooms.room=std::make_shared<Room>(c::response::Grid::import(walls),c::response::Grid::import(floors));g::RoomPoseArcs real_arcs(owned_world,owned_pool,real_rooms);std::optional<c::Vec3> origin;
            for(const auto& triangle:real_rooms.room->floors.triangles()){
                if((triangle.flags&0x80)||triangle.normal.y<=0)continue;
                const c::Vec3 p{(triangle.vertices[0].x+triangle.vertices[1].x+triangle.vertices[2].x)/3.f,(triangle.vertices[0].y+triangle.vertices[1].y+triangle.vertices[2].y)/3.f+5,(triangle.vertices[0].z+triangle.vertices[1].z+triangle.vertices[2].z)/3.f};
                if(real_rooms.room->floors.floor(p).triangle){origin=p;break;}
            }
            check(bool(origin));
            e::PeriodicVisuals trail_visuals(bank,owned_session->random);g::MappedPoseTrailEffects trails(owned_world,trail_visuals,real_rooms);
            const auto moving=owned_world.spawn_primary(1,std::make_unique<g::Actor>()).id;check(bool(moving));owned_world.resolve(moving)->position={origin->x,origin->y,origin->z};
            owned_world.resolve(parent)->slot=0;check(trails.emit(parent,{},0)&&trail_visuals.size()==0);owned_world.resolve(parent)->slot=7;
            check(!trails.emit(parent,moving,1)&&trail_visuals.size()==0);check(trails.emit(parent,moving,0));
            check(trail_visuals.update({0,1,0}).status==e::VisualStatus::completed);const auto trail_frame=trail_visuals.retain();check(bool(trail_frame));
            for(const auto& visual:trail_frame->visuals){const auto state=trail_visuals.particle_state(visual.id);check(state&&state->category==13&&state->mode==0);}
            trail_visuals.close();check(!trails.bound_to(owned_world));
            const auto floor=real_rooms.room->floors.floor(*origin);const auto arc_id=work(owned_pool,13);auto arc=owned_pool.resolve(arc_id);arc->primary=1;arc->position={origin->x,floor.height-.5f,origin->z};check(owned_pool.update(&real_arcs).status==g::PoseWorkStatus::completed&&!owned_pool.resolve(arc_id)&&arc->sampled_surface_height==floor.height&&arc->position.y==floor.height);
            const auto stale_id=work(owned_pool,13);arc=owned_pool.resolve(stale_id);arc->primary=1;check(real_rooms.room->ids.retire(real_rooms.room->id.entity)==g::actors::EntityStatus::completed);check(owned_pool.update(&real_arcs).status==g::PoseWorkStatus::unavailable&&owned_pool.resolve(stale_id));check(owned_pool.reset()==g::PoseWorkStatus::completed);++banks;++room_cases;
        }check(banks==6&&profile_refusals==1&&cloud_frames==380&&room_cases==6);
    }
    check(pool.close()==g::PoseWorkStatus::completed&&!arcs.bound_to(world));std::cout<<"{\"checks\":"<<checks<<",\"owned_banks\":"<<banks<<",\"cloud_frames\":"<<cloud_frames<<",\"room_cases\":"<<room_cases<<",\"profile_refusals\":"<<profile_refusals<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
