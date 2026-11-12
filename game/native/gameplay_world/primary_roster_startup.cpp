#include "primary_roster_startup.hpp"
#include <cmath>
#include <limits>
#include <new>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
struct StartupFailure {PrimaryStartupStatus status;};
void require(PrimaryStartupStatus status){if(status!=PrimaryStartupStatus::completed)throw StartupFailure{status};}
}
// The enclosing cache owns the existing World guard and nested model/motion
// publication permits throughout actual5EB520 and its roster model phase.
PrimaryStartupReport PrimaryActorModels::start_roster(const PrimaryStartupContext& context)noexcept{
    if(closed_||world_.closed()||!context.update.open())return{PrimaryStartupStatus::closed};
    if(&context.update.world()!=&world_||motions_.closed_)return{PrimaryStartupStatus::unavailable};
    if(running_||world_.busy()||scene_open_)return{PrimaryStartupStatus::busy};
    PrimaryStartupReport report;running_=world_.updating_=true;
    struct Reset{bool& running;bool& world;~Reset(){world=running=false;}}reset{running_,world_.updating_};
    try{
        auto& session=world_.session();session.setup_gate=2;
        //1AC630 only reads its return word, ignored at both caller positions.
        const auto population=[&](){if(!session.primary_population||*session.primary_population>World::primary_capacity)throw StartupFailure{PrimaryStartupStatus::unavailable};return *session.primary_population;};
        const auto actor_at=[&](std::size_t index){const auto actor=world_.primary(index);if(!actor)throw StartupFailure{PrimaryStartupStatus::unavailable};report.failed=world_.identity(index);return actor;};
        const auto effects=[&]() -> PrimaryStartupEffects& {if(!context.effects||!context.effects->bound_to(world_))throw StartupFailure{PrimaryStartupStatus::unavailable};return *context.effects;};
        const auto work=[&](PrimaryStartupWork value){require(effects().run(value));++report.resource_calls;};
        report.stage=PrimaryStartupStage::voice_archives;
        for(std::size_t index=0;index<population();++index){const auto actor=actor_at(index);if(index<5){require(effects().voice_archive(std::uint8_t(index),actor->character));++report.voice_requests;}}
        report.stage=PrimaryStartupStage::background;require(effects().background(0));
        report.stage=PrimaryStartupStage::stream_stage;
        if(!session.scene_stream_stage)throw StartupFailure{PrimaryStartupStatus::unavailable};
        if(!*session.scene_stream_stage){require(effects().background(0));require(effects().initialize_stream_stage());session.scene_stream_stage=1;}
        report.stage=PrimaryStartupStage::slot_assignment;
        for(std::size_t index=0;index<population();++index){actor_at(index)->slot=std::uint8_t(index);++report.slots_assigned;}
        report.stage=PrimaryStartupStage::common_render;
        work(PrimaryStartupWork::resource_pump);
        if(!session.asset_loading_mode)throw StartupFailure{PrimaryStartupStatus::unavailable};
        if(!*session.asset_loading_mode)work(PrimaryStartupWork::resident_render_2000);
        work(PrimaryStartupWork::render_2500);
        work(PrimaryStartupWork::resource_pump);
        report.stage=PrimaryStartupStage::actor_models;
        const auto selected_kind=effects().roster_kind(context.update.action_choices().state().table_row);
        if(!selected_kind||*selected_kind<0||*selected_kind>3)throw StartupFailure{PrimaryStartupStatus::unavailable};
        // Owned70C110 pointers select four16-byte room rows; every authored
        // row element has the same room byte. Network profiles still admit
        // only the source's bounded four entries (kind3 uses character parity).
        constexpr std::array<std::uint16_t,4> rooms{1,1,8,27};
        std::optional<std::size_t> room_entry;
        if(session.message_phase!=1&&session.message_phase!=2)room_entry=0;
        for(std::size_t index=0;index<population();++index){
            report.stage=PrimaryStartupStage::actor_models;const auto actor=actor_at(index);const auto id=report.failed;
            if(!session.asset_loading_mode||!*session.asset_loading_mode)throw StartupFailure{PrimaryStartupStatus::unavailable};
            const auto request=capture(id,false,true);if(!request)throw StartupFailure{PrimaryStartupStatus::unavailable};
            const auto prepared=prepare(*request,context.actors,context.motions);if(!prepared)throw StartupFailure{PrimaryStartupStatus::unavailable};
            const auto applied=apply(*prepared,context.update.state,context.equipment,true);report.model_prefix|=applied.replaced||applied.character_released||applied.initialized;
            if(applied.status!=PrimaryModelStatus::completed)throw StartupFailure{applied.status==PrimaryModelStatus::no_memory?PrimaryStartupStatus::no_memory:PrimaryStartupStatus::unavailable};
            ++report.models_applied;
            if(world_.resolve(id)!=actor)throw StartupFailure{PrimaryStartupStatus::unavailable};
            report.stage=PrimaryStartupStage::roster_rooms;
            const bool submode=session.message_phase==1||session.message_phase==2;
            if(submode)room_entry=*selected_kind==3?std::size_t(actor->character&1):index;
            if(!session.primary_initialization_snapshot){
                // A network-to-ordinary transition can reach the source's
                // uninitialized saved row pointer. Preserve that refusal.
                if(!room_entry||*room_entry>=4)throw StartupFailure{PrimaryStartupStatus::unavailable};
                actor->room=rooms[unsigned(*selected_kind)];++report.room_assignments;
            }
        }
        report.stage=PrimaryStartupStage::motion_defaults;
        work(PrimaryStartupWork::resource_pump);
        const auto previous=motions_.snapshot();if(!previous)throw StartupFailure{PrimaryStartupStatus::unavailable};
        const auto defaults=context.motions.ensure_base(previous);
        if(defaults!=previous){const auto published=motions_.publish_nested(defaults,true);if(published.status!=HumanoidPublicationStatus::completed)throw StartupFailure{published.status==HumanoidPublicationStatus::no_memory?PrimaryStartupStatus::no_memory:PrimaryStartupStatus::unavailable};}
        report.stage=PrimaryStartupStage::model_tail;
        work(PrimaryStartupWork::room_motion_table);work(PrimaryStartupWork::resource_pump);
        work(PrimaryStartupWork::scenario_render_models);work(PrimaryStartupWork::resource_pump);
        if(!session.asset_loading_mode)throw StartupFailure{PrimaryStartupStatus::unavailable};
        if(!*session.asset_loading_mode)work(PrimaryStartupWork::resident_render_2a00);
        work(PrimaryStartupWork::scenario_render_data);
        work(PrimaryStartupWork::resource_pump);
        report.stage=PrimaryStartupStage::actor_resources;
        for(std::size_t index=0;index<population();++index){(void)actor_at(index);const auto id=report.failed;require(effects().actor_resources(PrimaryStartupWork::actor_equipment,id));++report.resource_calls;require(effects().actor_resources(PrimaryStartupWork::actor_secondary_resources,id));++report.resource_calls;}
        report.stage=PrimaryStartupStage::controller_routes;work(PrimaryStartupWork::controller_routes);
        report.stage=PrimaryStartupStage::actor_gauges;
        for(std::size_t index=0;index<population();++index){const auto actor=actor_at(index);if(!actor->active)continue;actor->action_elapsed=actor->control_elapsed=std::numeric_limits<std::uint32_t>::max();const auto height=effects().reference_height(actor->character);if(!height||!std::isfinite(*height))throw StartupFailure{PrimaryStartupStatus::unavailable};actor->model_height_correction=*height;actor->gauge_value=0;actor->gauge_modifier_one=actor->gauge_modifier_two=0;if(world_.mode==0&&context.update.initialize_ai(report.failed).status!=gameplay_ai::Status::completed)throw StartupFailure{PrimaryStartupStatus::unavailable};++report.gauges_initialized;}
        report.stage=PrimaryStartupStage::scene_resources;work(PrimaryStartupWork::scene_resources);
        report.stage=PrimaryStartupStage::scenario_sound;work(PrimaryStartupWork::scenario_sound);
        report.stage=PrimaryStartupStage::npcs;
        if(!context.scenario_assets||!session.scenario)throw StartupFailure{PrimaryStartupStatus::unavailable};
        if(context.update.load_scenario_npcs(*context.scenario_assets,*session.scenario)!=gameplay_update::Status::completed)throw StartupFailure{PrimaryStartupStatus::unavailable};
        report.stage=PrimaryStartupStage::enemies;
        if(context.update.load_scenario_enemies(*context.scenario_assets)!=gameplay_update::Status::completed)throw StartupFailure{PrimaryStartupStatus::unavailable};
        report.stage=PrimaryStartupStage::scripts;work(PrimaryStartupWork::scenario_scripts);work(PrimaryStartupWork::start_scenario_script);
        report.stage=PrimaryStartupStage::navigation;if(world_.mode==0)work(PrimaryStartupWork::scenario_navigation);
        report.stage=PrimaryStartupStage::remaining_resources;
        for(const auto value:{PrimaryStartupWork::scenario_tables,PrimaryStartupWork::scenario_root_motion,
            PrimaryStartupWork::scenario_resources,PrimaryStartupWork::scenario_particles,
            PrimaryStartupWork::resource_2600,PrimaryStartupWork::scenario_common_resources,PrimaryStartupWork::resource_pump,
            PrimaryStartupWork::timed_message_resources,PrimaryStartupWork::scenario_ui,
            PrimaryStartupWork::scenario_63f590})work(value);
        session.setup_gate=0;session.scene_stream_stage=0;report.stage=PrimaryStartupStage::completed;report.failed={};return report;
    }catch(const StartupFailure& failure){report.status=failure.status;return report;}
    catch(const std::bad_alloc&){report.status=PrimaryStartupStatus::no_memory;return report;}
    catch(...){report.status=PrimaryStartupStatus::unavailable;return report;}
}
}
