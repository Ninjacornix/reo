#include "resource_companion_actions.hpp"
#include "periodic_visuals.hpp"
#include "../gameplay_world/resource_models.hpp"
#include <iostream>
#include <stdexcept>
namespace e=reo::native::gameplay_effects;
namespace g=reo::native::gameplay_world;
namespace s=reo::native::gameplay_scenario;
namespace l=reo::native::gameplay_lighting;
namespace t=reo::native::gameplay_tasks;
namespace a=reo::native::gameplay_audio;
unsigned checks{};
void check(bool value){if(!value)throw std::runtime_error("Native companion ownership check "+std::to_string(checks));++checks;}
int main()try{
    auto session=std::make_shared<g::Session>();g::World world({{g::input::Remap{1,2,4}},1,{16,UINT64_MAX}},session);
    s::SceneResources resources;s::ResourceTemplates templates;g::ResourceModels models;
    auto actor=std::make_unique<g::Actor>();actor->primary=2;actor->secondary=11;actor->surface_material=19;const auto id=world.spawn_primary(0,std::move(actor)).id;check(bool(id));
    auto engine=std::make_shared<reo::native::audio_banks::v2::Session>();a::Owner audio(engine,session->random);a::SpatialContext spatial;spatial.world_to_screen=reo::native::transform_math::identity();g::animation_events::BasicAudio frontend(world,audio,spatial,resources,templates);
    s::Lighting lighting;l::Pool lights(lighting);t::Scheduler tasks;l::TimedLights timed(world,tasks,lights);e::NativeResourceCompanionActions actions(world,resources,models,templates,frontend,timed);
    check(actions.bound_to(world,resources,models,templates));s::SceneResources foreign;check(!actions.bound_to(world,foreign,models,templates));
    bool rejected{};try{e::PeriodicVisuals invalid{std::shared_ptr<const e::EffectBank>{}};}catch(const std::invalid_argument&){rejected=true;}check(rejected);
    check(actions.light(id,{1,2,3})&&actions.last_light()&&actions.last_light()->status==l::TimedStatus::completed);const auto first=*actions.last_light();const auto value=lights.retain(first.light);check(value&&value->tag==19&&value->descriptor.position==std::array<float,3>{1,2,3});
    check(tasks.run(t::Pass::update).called==1);world.resolve(id)->primary=0;check(tasks.run(t::Pass::update).called==1&&tasks.size()==0&&lights.size()==0);
    world.resolve(id)->primary=2;for(unsigned i=0;i<64;++i){check(lighting.allocate(nullptr,0,1).has_value());}
    check(actions.light(id,{})&&actions.last_light()->status==l::TimedStatus::light_full&&tasks.size()==0&&lights.size()==64);
    check(!actions.cue({},20));check(world.close()==g::Status::completed&&!actions.bound_to(world,resources,models,templates)&&!actions.light(id,{}));
    std::cout<<checks<<" native resource companion ownership checks passed\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
