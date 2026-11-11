#include "owned_resource_recipes.hpp"
#include "resource_consumption.hpp"
#include "resource_health_effects.hpp"
#include "resource_deployment.hpp"
#include "resource_effects.hpp"
#include "../gameplay_update/update.hpp"
#include "actor_forced_terminal.hpp"
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <functional>
namespace g=reo::native::gameplay_world;
namespace u=reo::native::gameplay_update;
namespace s=reo::native::gameplay_scenario;
namespace e=reo::native::gameplay_events;
unsigned checks{};
void check(bool value){++checks;if(!value)throw std::runtime_error("Owned recipe composition check "+std::to_string(checks));}
template<class T>void put(std::span<std::byte> bytes,unsigned at,T value){std::memcpy(bytes.data()+at,&value,sizeof value);}
struct Notifications:s::FlagNotifications {bool changed(const s::ScenarioFlagChange&)noexcept override{std::terminate();}bool changed(const s::StridedFlagChange&)noexcept override{std::terminate();}};
struct Messages:u::GameplayMessageSink {
    std::function<bool(const u::ResourceOperationMessage&)> callback;
    bool send(const u::ScenarioOwnerMessage&)noexcept override{return false;}
    std::function<bool(const u::ResourcePositionMessage&)> position_callback;
    bool send(const u::ResourcePositionMessage& value)noexcept override{return position_callback&&position_callback(value);}
    bool send(const u::ActorStatusMessage&)noexcept override{return false;}
    bool send(const u::ResourceOperationMessage& value)noexcept override{return callback&&callback(value);}
};
int main()try{
    auto session=std::make_shared<g::Session>();g::World world({{g::input::Remap{1,2,4}},1,{16,UINT64_MAX}},session);Notifications notifications;Messages messages;u::Owner update(world,notifications,e::RuleBook::file1(),&messages);world.room=7;check(update.clock().restore({},123)==u::tasks::Status::completed);
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
    contents.replace_direct(4,10100);item=*resources.get(*resources.slot(4));item.parameter=1;check(resources.replace(*resources.slot(4),item)==s::SceneStatus::completed);world.resolve(id)->inventory.carried[0]=4;session->message_phase=1;unsigned sent{};
    messages.callback=[&](const u::ResourceOperationMessage& value){++sent;check(value.route==u::MessageRoute::mode_zero&&value.resource==4&&value.actor==0&&value.operation==1);check(!second.model->current()&&models.available()==64&&!resources.get(*resources.slot(4))->active&&world.resolve(id)->inventory.carried[0]==0);return true;};
    consumption.consume_carried_content(id,10100);check(sent==1&&update.completion_statistics().state().points==20);
    put(encoded,32,std::uint32_t(0x40200));check(templates.load(encoded));item=*resources.get(*resources.slot(3));item.active=1;item.parameter=2;item.primary.reset();item.secondary.reset();check(resources.replace(*resources.slot(3),item)==s::SceneStatus::completed);world.resolve(id)->inventory.carried[0]=3;
    messages.callback=[](const u::ResourceOperationMessage&){return false;};bool message_failed{};try{consumption.use_carried_content(id,10100);}catch(const std::runtime_error&){message_failed=true;}check(message_failed&&resources.get(*resources.slot(3))->parameter==2&&world.resolve(id)->inventory.carried[0]==3);
    message_failed=false;try{consumption.consume_carried_content(id,10100);}catch(const std::runtime_error&){message_failed=true;}check(message_failed&&resources.get(*resources.slot(3))->parameter==1&&world.resolve(id)->inventory.carried[0]==3);
    message_failed=false;try{consumption.destroy_content(id,10100);}catch(const std::runtime_error&){message_failed=true;}check(message_failed&&resources.get(*resources.slot(3))->active&&world.resolve(id)->inventory.carried[0]==3);
    session->message_phase=0;put(encoded,32+10,std::uint16_t(0x13));check(templates.load(encoded));item=*resources.get(*resources.slot(3));item.attachment_id=300;item.template_index=0;check(resources.replace(*resources.slot(3),item)==s::SceneStatus::completed);const auto live=world.resolve(id);live->current=5;live->maximum=100;live->status=1;live->auxiliary_status=0;g::ResourceHealthEffects healing(primitives,update);
    const auto healed=healing.apply(3,id);check(healed.status==g::ResourceHealthStatus::completed&&healed.value==1&&live->current==100&&live->status==0&&live->auxiliary_status==0x20);const auto health_events=update.cooperative_events().snapshot();check(health_events.size()==2&&health_events.back().value.id==3&&health_events.back().value.first==300&&health_events.back().value.timestamp==123&&health_events.back().value.room==7);
    item=*resources.get(*resources.slot(3));item.attachment_id=312;check(resources.replace(*resources.slot(3),item)==s::SceneStatus::completed);session->inventory_owner=3;const auto unavailable=healing.apply(3,id);check(unavailable.status==g::ResourceHealthStatus::ui_unavailable&&(live->auxiliary_status&0x1000u)&&session->inventory_owner==0&&update.cooperative_events().snapshot().size()==2);
    // A successful outer effect consumes once and retires actual models on
    // depletion, while retaining inventory references as5B2080 does.
    put(encoded,32,std::uint32_t(0x40004));put(encoded,32+10,std::uint16_t(1));put(encoded,32+18,std::uint16_t(300));check(templates.load(encoded));item=*resources.get(*resources.slot(3));item.active=1;item.ownership_tag=1;item.parameter=1;item.attachment_id=300;item.template_index=0;const auto healing_model=factory.create(300);check(healing_model.status==g::ResourceModelStatus::completed);healing_model.model->resource_slot=3;item.primary=healing_model.model;check(resources.replace(*resources.slot(3),item)==s::SceneStatus::completed);live->status=live->auxiliary_status=0;live->current=0;live->maximum=100;live->inventory.carried[0]=3;g::ResourceEffects effects(primitives,update);const auto used=effects.apply(0xabcd0003,id);check(used.status==g::ResourceEffectStatus::completed&&used.value==2&&live->current==100&&!resources.get(*resources.slot(3))->active&&!healing_model.model->current()&&models.available()==64&&live->inventory.carried[0]==3&&effects.last_record()->status==e::StatisticsStatus::completed);
    // Deployment uses these same descriptor/model/update owners. An off-room
    // conversion needs no visual consumer; a reached missing consumer refuses
    // after the descriptor prefix. Actual full capacity is a completed effect.
    g::ResourceDeployment deployment(primitives,update);item=*resources.get(*resources.slot(4));item.active=1;item.instance_index=4;item.attachment_id=0x3201;item.template_index=1;item.primary.reset();item.secondary.reset();item.ownership_tag=1;item.parameter=17;item.flags=0x800;check(resources.replace(*resources.slot(4),item)==s::SceneStatus::completed);live->room=8;live->position={12,-3,37};
    check(deployment.place(id,4,live->position).status==g::ResourceModelStatus::completed);auto placed=*resources.get(*resources.slot(4));check(placed.attachment_id==0x3200&&placed.room==8&&placed.ownership_tag==0&&placed.position.x==12&&placed.position.y==-1&&placed.flags==0x200000&&!placed.primary);
    live->room=7;check(resources.replace(*resources.slot(4),item)==s::SceneStatus::completed);session->message_phase=1;messages.position_callback=[&](const u::ResourcePositionMessage& value){check(value.resource==4&&value.actor==0&&value.operation==3&&value.position.y==-3);return true;};
    check(deployment.effect(4,id).status==g::ResourceModelStatus::unavailable);placed=*resources.get(*resources.slot(4));check(placed.attachment_id==0x3200&&placed.room==7&&placed.ownership_tag==0&&!placed.primary&&models.available()==64);
    session->message_phase=0;for(unsigned i=0;i<64;++i)check(models.create().status==g::ResourceModelStatus::completed);check(resources.replace(*resources.slot(4),item)==s::SceneStatus::completed);const auto full_deployment=deployment.effect(4,id);check(full_deployment.status==g::ResourceModelStatus::completed&&full_deployment.value==4&&models.available()==0&&!resources.get(*resources.slot(4))->primary&&resources.get(*resources.slot(4))->parameter==17);put(encoded,56,std::uint32_t(8));check(templates.load(encoded));check(resources.replace(*resources.slot(4),item)==s::SceneStatus::completed);const auto full_effect=effects.apply(4,id);check(full_effect.status==g::ResourceEffectStatus::completed&&full_effect.value==2&&resources.get(*resources.slot(4))->parameter==17&&models.available()==0);while(auto current=models.head())check(models.retire(current)==g::ResourceModelStatus::completed);
    struct Ui final:g::RecoveryUi {
        g::World& world;unsigned calls{};
        explicit Ui(g::World& source):world(source){}
        bool bound_to(const g::World& source)const noexcept override{return &source==&world;}
        bool close()override{++calls;check(world.session().inventory_owner==0&&world.session().cutscene_requests.limit_override);return true;}
    } ui(world);
    g::ActorResourceOperations actor_operations(primitives);
    g::ActorForcedTerminal terminal(update,actor_operations,ui);
    world.mode=1;world.selected_actor=0;session->message_phase=0;session->inventory_owner=1;
    live->current=100;live->status=0;live->auxiliary_status=0;live->inventory={};
    live->primary=1;live->secondary=2;live->phase=3;live->subphase=4;live->motion_class=9;
    terminal.force(1);
    check(ui.calls==1&&live->current==100&&live->status==0&&live->primary==1&&live->secondary==2&&
          live->phase==3&&live->subphase==4&&live->motion_class==9&&(live->auxiliary_status&0x02000000u));
    terminal.force(0);
    check(ui.calls==2&&live->current==0&&live->primary==4&&live->secondary==7&&
          live->phase==0&&live->subphase==0&&live->motion_class==0xa0);
    check(update.cooperative_events().snapshot().back().value.id==0x26);
    std::vector<std::byte> forced_script(16);
    put(std::span(forced_script),0,1u);
    put(std::span(forced_script),4,0x01000061u);
    put(std::span(forced_script),8,1u);
    put(std::span(forced_script),12,0xau);
    s::Interpreter interpreter;
    check(interpreter.install(0,std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{forced_script}))==s::Status::completed);
    s::Providers providers;providers.world=&world;providers.forced_terminal=&terminal;
    live->current=80;
    check(interpreter.tick(0,{},providers).status==s::Status::yielded&&ui.calls==3&&live->current==80);
    std::vector<std::byte> scene_script(40);
    put(std::span(scene_script),0,1u);
    put(std::span(scene_script),4,0x03000062u);
    put(std::span(scene_script),8,1u);
    put(std::span(scene_script),12,12u);
    put(std::span(scene_script),16,13u);
    put(std::span(scene_script),36,0xau);
    live->status=0;
    check(interpreter.install(0,std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{scene_script}))==s::Status::completed);
    check(interpreter.tick(0,{},providers).status==s::Status::yielded&&ui.calls==4&&world.paused==1&&live->current==0);
    const auto queued=update.take_cutscene_requests();
    check(queued&&queued->current.area==12&&queued->current.scene==13);
    g::World other({{g::input::Remap{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<g::Session>());u::Owner other_update(other,notifications);bool refused{};try{g::OwnedResourceRecipes wrong(primitives,other_update);}catch(const std::invalid_argument&){refused=true;}check(refused);
    check(!terminal.apply(other,0));
    check(world.retire_primary(0)==g::actors::EntityStatus::completed);refused=false;try{recipes.publish(0xf,0x136,42,id);}catch(const std::runtime_error&){refused=true;}check(refused);check(update.close()==u::Status::completed);refused=false;try{recipes.apply(3,4);}catch(const std::runtime_error&){refused=true;}check(refused);check(world.close()==g::Status::completed);
    std::cout<<checks<<" owned recipe model/event/update composition checks passed.\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
