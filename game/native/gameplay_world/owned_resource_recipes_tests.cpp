#include "owned_resource_recipes.hpp"
#include "resource_consumption.hpp"
#include "../gameplay_update/update.hpp"
#include <cstring>
#include <iostream>
#include <stdexcept>
namespace g=reo::native::gameplay_world;
namespace u=reo::native::gameplay_update;
namespace s=reo::native::gameplay_scenario;
namespace e=reo::native::gameplay_events;
unsigned checks{};
void check(bool value){++checks;if(!value)throw std::runtime_error("Owned recipe composition check "+std::to_string(checks));}
template<class T>void put(std::span<std::byte> bytes,unsigned at,T value){std::memcpy(bytes.data()+at,&value,sizeof value);}
struct Notifications:s::FlagNotifications {bool changed(const s::ScenarioFlagChange&)noexcept override{std::terminate();}bool changed(const s::StridedFlagChange&)noexcept override{std::terminate();}};
int main()try{
    auto session=std::make_shared<g::Session>();g::World world({{g::input::Remap{1,2,4}},1,{16,UINT64_MAX}},session);Notifications notifications;u::Owner update(world,notifications);world.room=7;check(update.clock().restore({},123)==u::tasks::Status::completed);
    auto actor=std::make_unique<g::Actor>();actor->character=3;const auto id=world.spawn_primary(0,std::move(actor)).id;check(bool(id));
    std::array<std::byte,12> forest{};put(forest,8,12u);const auto assets=g::ResourceStaticAssets::import_forest(forest);
    std::array<std::byte,32+2*24+6> encoded{};put(encoded,0,3u);put(encoded,4,2u);put(encoded,8,3u);put(encoded,16,32u);put(encoded,28,80u);put(encoded,32+4,std::int16_t(0));put(encoded,32+6,std::int16_t(1));put(encoded,32+8,std::int16_t(10));put(encoded,32+18,std::uint16_t(0x195));put(encoded,56+18,std::uint16_t(42));put(encoded,80,std::int16_t(42));put(encoded,82,std::int16_t(0x136));put(encoded,84,std::int16_t(0xf));
    s::ResourceTemplates templates;check(templates.load(encoded));s::SceneResources resources;g::ResourceModels models;g::ResourceFrames frames(world,resources,models,nullptr,{},&templates);g::ResourceFactory factory(models,frames,templates,assets);g::ResourceContents contents(world,resources,templates,frames,factory);g::ResourcePairs pairs(world,resources,templates,frames);g::WorldInventory inventory(world,resources,templates,frames);g::ResourceRecipes primitives(pairs,contents,inventory);g::OwnedResourceRecipes recipes(primitives,update);
    s::SceneDescriptor a,b;a.active=b.active=1;a.instance_index=3;b.instance_index=4;a.ownership_tag=b.ownership_tag=1;a.attachment_id=0x195;b.attachment_id=42;a.template_index=0;b.template_index=1;a.parameter=3;b.parameter=7;const auto first=factory.create(0x195),second=factory.create(42);check(first.status==g::ResourceModelStatus::completed&&second.status==g::ResourceModelStatus::completed);first.model->resource_slot=3;second.model->resource_slot=4;a.primary=first.model;b.primary=second.model;check(bool(resources.load(3,a))&&bool(resources.load(4,b)));
    check(recipes.apply(0xabcd0003,0x12340004)==1&&models.available()==62&&first.model->current()&&second.model->current());const auto changed=resources.get(*resources.slot(4));check(changed&&changed->attachment_id==0x136&&changed->parameter==7&&second.model->content_id==0x136);
    const auto events=update.cooperative_events().snapshot();check(events.size()==1&&events[0].value.id==0x13&&events[0].value.first==42&&events[0].value.second==0&&events[0].value.timestamp==123&&events[0].value.room==7&&recipes.last_event()==e::Status::completed);
    check(recipes.apply(3,4)==0&&!recipes.last_event()&&update.cooperative_events().snapshot().size()==1);
    contents.replace_direct(4,42);check(update.cooperative_events().reset()==e::Status::completed);for(unsigned i=0;i<128;++i)check(update.record_simple_event(i).status==e::Status::completed);check(recipes.apply(3,4)==1&&recipes.last_event()==e::Status::full&&update.cooperative_events().snapshot().size()==128);
    // Consume through the same actual inventory, primary model and completion
    // owners, without replacing their consumers with test callbacks.
    session->scenario=0;check(update.initialize_completion_statistics()==e::StatisticsStatus::completed);
    put(encoded,32,std::uint32_t(0x40000));put(encoded,32+18,std::uint16_t(10100));check(templates.load(encoded));
    contents.replace_direct(3,10100);auto item=*resources.get(*resources.slot(3));item.parameter=1;check(resources.replace(*resources.slot(3),item)==s::SceneStatus::completed);
    world.resolve(id)->inventory.carried[0]=3;g::ResourceConsumption consumption(primitives,update);
    check(consumption.consume_or_transform(id,3)==1);check(!resources.get(*resources.slot(3))->active&&!first.model->current()&&world.resolve(id)->inventory.carried[0]==0);
    check(consumption.last_record()&&consumption.last_record()->matched==1&&consumption.last_record()->recorded==1&&update.completion_statistics().state().points==20);
    check(update.cooperative_events().snapshot().size()==1&&update.cooperative_events().snapshot()[0].value.id==1&&update.cooperative_events().snapshot()[0].value.timestamp==123);
    g::World other({{g::input::Remap{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<g::Session>());u::Owner other_update(other,notifications);bool refused{};try{g::OwnedResourceRecipes wrong(primitives,other_update);}catch(const std::invalid_argument&){refused=true;}check(refused);
    check(world.retire_primary(0)==g::actors::EntityStatus::completed);refused=false;try{recipes.publish(0xf,0x136,42,id);}catch(const std::runtime_error&){refused=true;}check(refused);check(update.close()==u::Status::completed);refused=false;try{recipes.apply(3,4);}catch(const std::runtime_error&){refused=true;}check(refused);check(world.close()==g::Status::completed);
    std::cout<<checks<<" owned recipe model/event/update composition checks passed.\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
