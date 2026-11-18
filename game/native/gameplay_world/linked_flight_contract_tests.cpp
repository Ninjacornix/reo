#include "linked_flight_effects.hpp"
#include "pose_weapon_effects.hpp"
#include <iostream>
#include <source_location>
#include <stdexcept>
namespace g=reo::native::gameplay_world;namespace s=reo::native::gameplay_scenario;namespace l=reo::native::gameplay_lighting;namespace t=reo::native::gameplay_tasks;namespace d=reo::native::gameplay_collision::delivery;namespace a=reo::native::gameplay_audio;
unsigned checks{};void check(bool v,std::source_location p=std::source_location::current()){++checks;if(!v)throw std::runtime_error("Native linked flight "+std::to_string(p.line()));}
struct Rooms final:reo::native::gameplay_contact_world::RoomResources {unsigned reads{};std::shared_ptr<reo::native::gameplay_contact_world::RoomInvocation> retain(std::uint16_t)override{++reads;return{};}};
int main()try{
    g::Profile profile;profile.layouts.push_back({});profile.entities.capacity=256;auto session=std::make_shared<g::Session>();g::World world(profile,session);g::PoseWorkPool pool(world);s::SceneResources resources;s::ResourceTemplates templates;d::Catalog catalog;d::Packets packets;g::ResourcePoseWork poses(world,pool,resources,templates,packets,catalog);
    const auto parent=world.spawn_primary(0,std::make_unique<g::Actor>()).id;check(bool(parent));auto parent_actor=world.resolve(parent);parent_actor->category=0;
    s::Lighting lighting;l::Pool lights(lighting);t::Scheduler tasks;l::TimedLights timed(world,tasks,lights);auto engine=std::make_shared<reo::native::audio_banks::v2::Session>();a::Owner audio(engine,session->random);a::SpatialContext spatial;g::PackedActorAudio frontend(world,audio,spatial);Rooms rooms;g::ResourceLinkedFlightEffects effects(world,rooms,poses,timed,frontend,packets,catalog);g::LinkedResourceFlight updates(world,pool,resources,effects);
    check(effects.bound_to(world)&&updates.bound_to(world)&&!effects.floor({})&&rooms.reads==1);check(frontend.sound({},7)&&!frontend.last_result());check(!effects.packet({},0x69));
    g::PoseWeaponEffects weapons(world,poses);check(weapons.bound_to(world));check(weapons.pose_work(parent,{}, {},0));check(!weapons.transient_light(parent,{})&&!weapons.flight(parent,{},0)&&!weapons.contact_style(parent,{}, {},0));
    const auto made=pool.allocate();check(made.status==g::PoseWorkStatus::completed);const auto actor=pool.resolve(made.id);actor->active=true;actor->category=9;actor->slot=3;actor->pose_work->update_bound=true;actor->pose_work->kind=9;actor->pose_work->lifetime=-1;
    // Known absence stops this specific work; it requires no floor/audio/light
    // capabilities and does not turn missing room data into a successful query.
    check(updates.update(pool,made.id,9)&&actor->primary==255&&(actor->auxiliary_status&1)&&actor->pose_work->lifetime==1&&rooms.reads==1);
    check(pool.update(&updates).retired==1&&!pool.resolve(made.id));
    const auto prefix=poses.attach(parent,0x169,0x114,0,nullptr,nullptr,0x10002);check(prefix.status==g::PoseWorkStatus::unavailable&&prefix.work&&!prefix.packet);const auto allocated=pool.resolve(prefix.work);check(allocated&&allocated->slot==0x69&&allocated->pose_work->kind==20&&allocated->pose_work->lifetime==2&&allocated->pose_work->basis==reo::native::transform_math::Matrix{}&&packets.size()==0);check(pool.reset()==g::PoseWorkStatus::completed);
    // A separate actual6B2760 task must survive its parent's retirement.
    const auto light=timed.create_ungated(parent,{1,2,3});check(light.status==l::TimedStatus::completed&&lights.size()==1&&tasks.size()==1);check(world.retire_primary(0)==g::actors::EntityStatus::completed);unsigned ticks{};while(tasks.size()&&ticks++<80)check(tasks.run(t::Pass::update).status==t::Status::completed);check(ticks>20&&ticks<80&&lights.size()==0&&timed.failure()==l::TimedStatus::completed);
    check(!effects.light(parent,{})&&!effects.burst(parent,{}));packets.close();check(!effects.bound_to(world)&&!updates.bound_to(world));check(pool.close()==g::PoseWorkStatus::completed);
    std::cout<<"{\"checks\":"<<checks<<",\"game_run\":false,\"device_opened\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
