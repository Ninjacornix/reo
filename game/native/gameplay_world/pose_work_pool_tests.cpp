#include "resource_pose_updates.hpp"
#include <fstream>
#include <cstring>
#include <iostream>
#include <source_location>
#include <stdexcept>
namespace g=reo::native::gameplay_world;namespace d=reo::native::gameplay_collision::delivery;namespace s=reo::native::gameplay_scenario;
unsigned checks{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Native pose slots "+std::to_string(at.line()));}
g::Profile profile(){g::Profile value;value.layouts.push_back({});value.entities.capacity=128;return value;}
int main(int argc,char** argv)try{
    check(argc==1||argc==2);g::World world(profile(),std::make_shared<g::Session>());g::PoseWorkPool pool(world);
    bool refused{};try{g::PoseWorkPool duplicate(world);}catch(const std::invalid_argument&){refused=true;}check(refused&&pool.remaining()==64);
    const auto made=pool.allocate();check(made.status==g::PoseWorkStatus::completed);const auto lease=pool.resolve(made.id);check(lease&&lease->pose_work&&!lease->active&&!lease->speech.dialogue_delay&&!lease->speech.display_style);
    lease->pose_work->lifetime=3;check(pool.update().status==g::PoseWorkStatus::unavailable&&lease->pose_work->lifetime==3);
    lease->active=true;lease->pose_work->update_bound=true;
    check(pool.update().status==g::PoseWorkStatus::completed&&lease->visible&&lease->primary==1&&lease->pose_work->lifetime==2);
    check(pool.update().status==g::PoseWorkStatus::completed&&lease->pose_work->lifetime==1);
    check(pool.update().retired==1&&!pool.resolve(made.id)&&!lease->active&&!lease->visible&&pool.remaining()==64);
    const auto reused=pool.allocate();check(reused.status==g::PoseWorkStatus::completed&&reused.id!=made.id&&!world.resolve(made.id));
    check(pool.reset()==g::PoseWorkStatus::completed&&!pool.resolve(reused.id)&&pool.remaining()==64);
    std::array<g::actors::EntityId,64> ids;
    for(auto& id:ids){const auto current=pool.allocate();check(current.status==g::PoseWorkStatus::completed);id=current.id;}
    check(pool.allocate().status==g::PoseWorkStatus::full);check(pool.reset()==g::PoseWorkStatus::completed);for(const auto& id:ids)check(!world.resolve(id));
    if(argc==2){
        std::ifstream input(argv[1],std::ios::binary);const std::vector<char> raw{std::istreambuf_iterator<char>(input),{}};check(!raw.empty());std::vector<std::byte> bytes(raw.size());std::memcpy(bytes.data(),raw.data(),raw.size());const auto catalog=d::Catalog::import(bytes);
        auto actor=std::make_unique<g::Actor>();actor->room=7;const auto parent=world.spawn_primary(0,std::move(actor)).id;check(bool(parent));world.room=7;
        g::ResourceModels models;const auto model=models.create();check(model.status==g::ResourceModelStatus::completed);
        s::SceneResources resources;s::ResourceTemplates templates;std::vector<std::byte> encoded(56);const auto write=[&]<class T>(unsigned at,T value){std::memcpy(encoded.data()+at,&value,sizeof value);};write(0,3u);write(4,1u);write(16,32u);check(templates.load(encoded));
        s::SceneDescriptor descriptor;descriptor.active=1;descriptor.template_index=0;descriptor.primary=model.model;check(bool(resources.load(3,descriptor)));d::Packets packets;g::ResourcePoseWork factory(world,pool,resources,templates,packets,catalog);
        const auto result=factory.create(parent,reo::native::transform_math::identity(),{},0xabcd0003);check(result.status==g::PoseWorkStatus::completed&&result.work&&result.packet&&pool.resolve(result.work)&&packets.size()==1);
        check(pool.reset()==g::PoseWorkStatus::completed&&!world.resolve(result.work));check(packets.acquire(result.packet)&&packets.release(result.packet));
    }
    check(pool.close()==g::PoseWorkStatus::completed);g::PoseWorkPool replacement(world);check(replacement.remaining()==64);check(world.close()==g::Status::completed&&replacement.allocate().status==g::PoseWorkStatus::closed);check(replacement.close()==g::PoseWorkStatus::completed);
    std::cout<<"{\"checks\":"<<checks<<",\"owned_catalog\":"<<(argc==2?"true":"false")<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
