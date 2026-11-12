#include "primary_roster_startup.hpp"
#include "primary_actor_records.hpp"
#include "runtime/assets/virtual_afs.h"
#include <bit>
#include <cstring>
#include <iostream>
#include <source_location>
#include <stdexcept>
namespace w=reo::native::gameplay_world;
namespace u=reo::native::gameplay_update;
namespace s=reo::native::gameplay_scenario;
namespace e=reo::native::gameplay_events;
std::uint64_t checks{},cases{},models{},guards{},refusals{},source_cases{},source_calls{},source_prefixes{},lifetimes{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Primary startup check "+std::to_string(at.line()));}
struct Notifications final:s::FlagNotifications {
    bool changed(const s::ScenarioFlagChange&)noexcept override{return true;}
    bool changed(const s::StridedFlagChange&)noexcept override{return true;}
};
struct Event {unsigned at{},first{},second{};friend bool operator==(const Event&,const Event&)=default;};
struct Effects final:w::PrimaryStartupEffects {
    w::World& world;w::PrimaryActorModels& model_owner;w::HumanoidMotionOwner& motion_owner;
    const w::PrimaryStartupContext* context{};std::vector<Event> calls;
    std::size_t fail_at=~std::size_t{};std::int8_t kind{};bool known_kind=true,known_height=true;
    explicit Effects(w::World& value,w::PrimaryActorModels& model,w::HumanoidMotionOwner& motion):world(value),model_owner(model),motion_owner(motion){}
    bool bound_to(const w::World& value)const noexcept override{return &value==&world;}
    w::PrimaryStartupStatus append(Event event){
        check(world.busy()&&world.close()==w::Status::busy&&model_owner.close()==w::PrimaryModelStatus::busy&&motion_owner.close()==w::HumanoidPublicationStatus::busy);
        check(context&&model_owner.start_roster(*context).status==w::PrimaryStartupStatus::busy);++guards;
        calls.push_back(event);return calls.size()-1==fail_at?w::PrimaryStartupStatus::unavailable:w::PrimaryStartupStatus::completed;
    }
    w::PrimaryStartupStatus voice_archive(std::uint8_t slot,std::uint8_t character)override{return append({0x1ba440,slot,character});}
    w::PrimaryStartupStatus background(std::uint8_t selector)override{return append({0x1af6a0,selector,0});}
    w::PrimaryStartupStatus initialize_stream_stage()override{return append({0x1b0510,0,0});}
    w::PrimaryStartupStatus run(w::PrimaryStartupWork work)override{return append({unsigned(work),0,0});}
    w::PrimaryStartupStatus actor_resources(w::PrimaryStartupWork work,const w::actors::EntityId& id)override{
        const auto actor=world.resolve(id);check(bool(actor));return append({unsigned(work),actor->slot,0});
    }
    std::optional<std::int8_t> roster_kind(std::uint8_t)const noexcept override{return known_kind?std::optional(kind):std::nullopt;}
    std::optional<float> reference_height(std::uint8_t character)const noexcept override{return known_height?std::optional(float(character)*1.25f-3.f):std::nullopt;}
};
struct Fixture {
    static w::Profile profile(){w::Profile value;value.layouts.push_back({});return value;}
    w::World world{profile(),std::make_shared<w::Session>()};Notifications notifications;
    u::Owner update{world,notifications,e::RuleBook::create({e::RuleGroup{}},{0})};
    w::HumanoidMotionOwner motion_owner{world};w::PrimaryActorModels model_owner{world,motion_owner};
    Effects effects{world,model_owner,motion_owner};
    Fixture(){check(w::initialize_primary_records(world).status==w::PrimaryRecordsStatus::completed);world.mode=1;world.session().scenario=1;world.session().asset_loading_mode=1;world.session().scene_stream_stage=0;world.session().primary_population=0;}
};
#ifdef REO_PRIMARY_STARTUP_ORIGINAL
#include "primary_startup_reference.inc"
#else
void begin_source(Fixture&){}
void compare_source(Fixture&,unsigned,const w::PrimaryStartupReport&,const std::vector<Event>&){}
#endif
void basic(const w::ActorAssets& assets,const w::HumanoidMotionAssets& motions){
    Fixture fixture;w::PrimaryStartupContext context{fixture.update,assets,motions};
    auto& world=fixture.world;world.session().setup_gate=17;
    auto result=fixture.model_owner.start_roster(context);check(result.status==w::PrimaryStartupStatus::unavailable&&result.stage==w::PrimaryStartupStage::background&&world.session().setup_gate==2&&!world.busy());++refusals;
    fixture.effects.context=&context;context.effects=&fixture.effects;
    world.session().scene_stream_stage.reset();fixture.effects.calls.clear();result=fixture.model_owner.start_roster(context);check(result.status==w::PrimaryStartupStatus::unavailable&&result.stage==w::PrimaryStartupStage::stream_stage&&fixture.effects.calls==std::vector<Event>{{0x1af6a0,0,0}});++refusals;
    check(fixture.model_owner.close()==w::PrimaryModelStatus::completed);world.session().setup_gate=17;result=fixture.model_owner.start_roster(context);check(result.status==w::PrimaryStartupStatus::closed&&world.session().setup_gate==17);++refusals;
}
void owned(const char* archive){
    auto source=std::make_shared<reo::assets::Source>(archive);w::ActorAssets assets(source);w::HumanoidMotionAssets motions(source);s::content::ScenarioArchive scenarios(source);
    basic(assets,motions);
    std::size_t failure_count{};
    for(unsigned seed=0;seed<36;++seed){
        Fixture fixture;auto& world=fixture.world;auto& session=world.session();
        const unsigned population=seed%9;session.primary_population=std::uint8_t(population);world.mode=std::uint8_t(seed&1);session.scene_stream_stage=std::uint8_t((seed/2)&1);session.message_phase=std::int8_t((seed/3)%3);fixture.effects.kind=std::int8_t((seed/9)%4);
        if(seed%5==0)session.primary_initialization_snapshot.emplace();
        check(fixture.motion_owner.publish(w::HumanoidMotionAssets::initial_banks(false)).status==w::HumanoidPublicationStatus::completed);
        for(unsigned i=0;i<8;++i){const auto actor=world.primary(i);check(actor->slot==0&&actor->ai_execution&&!actor->ai_execution->weight_profile&&actor->navigation_route->output.link==0);actor->character=std::uint8_t((seed+i)%8);actor->room=73;actor->gauge_value=123;actor->gauge_modifier_one=31;actor->gauge_modifier_two=37;actor->linked_model_variant=9;actor->action_elapsed=47;actor->control_elapsed=53;actor->ai_control=std::uint8_t((seed+i)%2);}
        w::PrimaryStartupContext context{fixture.update,assets,motions,&scenarios,&fixture.effects};fixture.effects.context=&context;
        begin_source(fixture);
        const auto result=fixture.model_owner.start_roster(context);check(!world.busy());
        const bool bounded=session.primary_initialization_snapshot||(session.message_phase!=1&&session.message_phase!=2)||fixture.effects.kind==3||population<=4;
        if(!bounded){check(result.status==w::PrimaryStartupStatus::unavailable&&result.stage==w::PrimaryStartupStage::roster_rooms&&result.models_applied==5&&session.setup_gate==2);++refusals;}
        else{check(result.status==w::PrimaryStartupStatus::completed&&result.stage==w::PrimaryStartupStage::completed&&session.setup_gate==0&&session.scene_stream_stage==0&&result.models_applied==population&&result.gauges_initialized==population);++cases;}
        for(unsigned i=0;i<8;++i){const auto actor=world.primary(i);check(actor->slot==(i<population?i:0));if(i<result.models_applied){check(actor->active&&actor->model&&actor->model_asset&&actor->animation&&actor->animation->model()==actor->model&&fixture.model_owner.key(i).character==actor->character);++models;}else check(!actor->model&&!actor->active);if(result.status==w::PrimaryStartupStatus::completed&&i<population){check(actor->action_elapsed==~0u&&actor->control_elapsed==~0u&&actor->gauge_value==0&&actor->gauge_modifier_one==0&&actor->gauge_modifier_two==0&&actor->linked_model_variant==9&&actor->model_height_correction==float(actor->character)*1.25f-3.f);if(world.mode==0&&actor->ai_control)check(actor->ai_execution->periodic_counter==60&&actor->ai_execution->forced_priority==-1&&actor->ai_execution->weight_profile==0&&actor->navigation_route->selection_mode==255);}}
        if(seed==1)failure_count=fixture.effects.calls.size();
        compare_source(fixture,seed,result,fixture.effects.calls);
        const auto banks=fixture.motion_owner.snapshot();if(result.status==w::PrimaryStartupStatus::completed)check(banks->base_loaded());
        const auto retained=world.primary(0);const auto id=world.identity(0);const auto model=retained->model;check(fixture.model_owner.close()==w::PrimaryModelStatus::completed&&fixture.motion_owner.close()==w::HumanoidPublicationStatus::completed&&fixture.update.close()==u::Status::completed&&world.close()==w::Status::completed);check(!world.resolve(id)&&retained->model==model);++lifetimes;
    }
    // Fail each reached external operation against the same real bootstrap,
    // then prove retries retain live IDs/models and can finish.
    for(std::size_t stop=0;stop<failure_count;++stop){
        Fixture fixture;fixture.world.session().primary_population=1;fixture.world.primary(0)->character=3;
        check(fixture.motion_owner.publish(w::HumanoidMotionAssets::initial_banks(false)).status==w::HumanoidPublicationStatus::completed);
        w::PrimaryStartupContext context{fixture.update,assets,motions,&scenarios,&fixture.effects};fixture.effects.context=&context;fixture.effects.fail_at=stop;
        const auto id=fixture.world.identity(0);begin_source(fixture);
        const auto first=fixture.model_owner.start_roster(context);
        check(first.status==w::PrimaryStartupStatus::unavailable&&fixture.world.session().setup_gate==2&&!fixture.world.busy());++refusals;
        compare_source(fixture,0,first,fixture.effects.calls);
        fixture.effects.fail_at=~std::size_t{};fixture.effects.calls.clear();begin_source(fixture);
        const auto second=fixture.model_owner.start_roster(context);
        check(second.status==w::PrimaryStartupStatus::completed&&fixture.world.identity(0)==id&&fixture.world.resolve(id)->model&&!fixture.world.busy());
        compare_source(fixture,0,second,fixture.effects.calls);
    }
    for(unsigned profile=0;profile<5;++profile){
        Fixture fixture;auto& session=fixture.world.session();session.primary_population=1;
        auto actor=fixture.world.primary(0);actor->gauge_value=7;actor->gauge_modifier_one=8;
        check(fixture.motion_owner.publish(w::HumanoidMotionAssets::initial_banks(false)).status==w::HumanoidPublicationStatus::completed);
        w::PrimaryStartupContext context{fixture.update,assets,motions,&scenarios,&fixture.effects};fixture.effects.context=&context;
        if(profile==0)session.asset_loading_mode.reset();
        if(profile==1)session.asset_loading_mode=0;
        if(profile==2)fixture.effects.known_kind=false;
        if(profile==3)fixture.effects.known_height=false;
        if(profile==4)session.primary_population.reset();
        const auto result=fixture.model_owner.start_roster(context);
        check(result.status==w::PrimaryStartupStatus::unavailable&&session.setup_gate==2&&!fixture.world.busy());++refusals;
        if(profile==3)check(result.stage==w::PrimaryStartupStage::actor_gauges&&actor->action_elapsed==~0u&&actor->control_elapsed==~0u&&actor->gauge_value==7&&actor->gauge_modifier_one==8&&actor->model);
        if(profile==1)check(result.stage==w::PrimaryStartupStage::actor_models&&result.slots_assigned==1&&fixture.effects.calls[5].at==0x1d24f0&&!actor->model);
        if(profile==4)check(result.stage==w::PrimaryStartupStage::voice_archives&&fixture.effects.calls.empty());
    }
}
int main(int argc,char** argv)try{check(argc==2);owned(argv[1]);std::cout<<"{\"checks\":"<<checks<<",\"complete_native_startups\":"<<cases<<",\"model_applications\":"<<models<<",\"guard_checks\":"<<guards<<",\"refusals\":"<<refusals<<",\"complete_original_cases\":"<<source_cases<<",\"source_prefixes\":"<<source_prefixes<<",\"source_calls\":"<<source_calls<<",\"lifetimes\":"<<lifetimes<<",\"game_run\":false}\n";}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
