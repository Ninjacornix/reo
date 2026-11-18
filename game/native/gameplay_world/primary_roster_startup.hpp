#pragma once
#include "primary_actor_models.hpp"
#include "../gameplay_update/update.hpp"
#include "../gameplay_scenario/scenario_archive.hpp"
namespace reo::native::gameplay_world {
enum class PrimaryStartupStatus {completed,unavailable,busy,closed,no_memory};
// Unported resource/render consumers retain their precise source boundaries.
// No implementation is supplied that treats absent work as successful.
enum class PrimaryStartupWork : std::uint32_t {
    resource_pump=0x18dcb0,
    resident_render_2000=0x1d24f0,render_2500=0x1d2550,
    room_motion_table=0x1d1c50,scenario_render_models=0x1d1030,
    scenario_render_data=0x1d0b70,resident_render_2a00=0x1d24b0,
    scenario_root_motion=0x1d4020,actor_equipment=0x1d3a70,
    actor_secondary_resources=0x1d3ca0,controller_routes=0x1b0ac0,
    scene_resources=0x591c50,scenario_sound=0x6ad5c0,
    scenario_scripts=0x1d3e90,start_scenario_script=0x68c890,
    scenario_navigation=0x1d3f60,scenario_tables=0x5a4f90,
    scenario_resources=0x1d4570,scenario_particles=0x1d49e0,
    resource_2600=0x1cd080,scenario_common_resources=0x1d2050,
    timed_message_resources=0x6dd9a0,scenario_ui=0x6ecac0,
    scenario_63f590=0x63f590
};
class PrimaryStartupEffects {
public:
    virtual ~PrimaryStartupEffects()=default;
    virtual bool bound_to(const World&)const noexcept=0;
    virtual PrimaryStartupStatus voice_archive(std::uint8_t slot,std::uint8_t character)=0; //1BA440, slots0..4
    virtual PrimaryStartupStatus background(std::uint8_t selector)=0; //1AF6A0, not a file wait
    virtual PrimaryStartupStatus initialize_stream_stage()=0; //1B0510
    virtual PrimaryStartupStatus run(PrimaryStartupWork)=0;
    // Observes a completed default-bank publication and its1B2CE0 selector
    // reset. This is a state notification, not an optional resource consumer.
    virtual void motion_defaults_reloaded()noexcept{}
    virtual PrimaryStartupStatus actor_resources(PrimaryStartupWork,const actors::EntityId&)=0;
    //4BADF0[signed4BADF7] and runtime747400[character], supplied by their
    // actual configuration/render producers; unknown inputs stay unknown.
    virtual std::optional<std::int8_t> roster_kind(std::uint8_t choice_row)const noexcept=0;
    virtual std::optional<float> reference_height(std::uint8_t character)const noexcept=0;
};
struct PrimaryStartupContext {
    gameplay_update::Owner& update;
    const ActorAssets& actors;
    const HumanoidMotionAssets& motions;
    const gameplay_scenario::content::ScenarioArchive* scenario_assets{};
    PrimaryStartupEffects* effects{};
    const PrimaryEquipmentContext* equipment{};
};
enum class PrimaryStartupStage {
    entry,voice_archives,background,stream_stage,slot_assignment,common_render,
    actor_models,motion_defaults,roster_rooms,model_tail,actor_resources,
    controller_routes,actor_gauges,scene_resources,scenario_sound,npcs,enemies,
    scripts,navigation,remaining_resources,completed
};
struct PrimaryStartupReport {
    PrimaryStartupStatus status{PrimaryStartupStatus::completed};
    PrimaryStartupStage stage{PrimaryStartupStage::entry};
    std::size_t voice_requests{},slots_assigned{},models_applied{},room_assignments{},gauges_initialized{},resource_calls{};
    actors::EntityId failed{};
    bool model_prefix{};
};
}
