#pragma once
#include "game/native/gameplay_tasks/tasks.hpp"
#include <array>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <optional>
#include <span>
#include <vector>
namespace reo::native::gameplay_world { class World; }

namespace reo::native::gameplay_scenario {
class FlagState;
class SceneResources;
class SceneEffects;
class SceneOwners;
class SessionCounters;
class SequenceControl;
class Lighting;
class SceneChannels;
class SceneControls;
class ControlEffects;
class StreamChannels;
class StreamBackend;
class SavedControlRecords;
class ActionChoices;
class SceneModels;
class RoomObjectCommands;
class PeriodicEffects;
class SurfaceEffects;
class ResourceTemplates;
class ForcedActorTerminal;
class ScriptAudio;
enum class DispatchProfile { ordinary,offline_actor };
enum class Status { completed,yielded,disabled,invalid_channel,invalid_program,invalid_record,unsupported_opcode,
    provider_unavailable,alternate_mode_unavailable,budget_exhausted,busy };
struct Position {
    std::uint32_t block{UINT32_MAX},offset{};
    friend bool operator==(const Position&,const Position&)=default;
};
struct Record {std::uint32_t opcode{},bytes{};std::span<const std::byte> payload;};
// Immutable original content bytes in bounded blocks. Pointer relocation and
// original resource-file parsing belong to the admitted content importer.
class Program {
public:
    explicit Program(std::vector<std::vector<std::byte>> blocks,DispatchProfile=DispatchProfile::ordinary);
    static Program from_script_blocks(std::vector<std::vector<std::byte>>,DispatchProfile);
    std::optional<Record> record(Position)const noexcept;
    std::size_t blocks()const noexcept{return blocks_.size();}
    static std::uint32_t record_bytes(std::uint32_t header)noexcept;
    bool unsupported()const noexcept{return unsupported_;}
    bool needs_flags()const noexcept{return flags_;}
    bool needs_timers()const noexcept{return timers_;}
    bool needs_actor_events()const noexcept{return actor_events_;}
    bool needs_signals()const noexcept{return signals_;}
    bool needs_scene_resources()const noexcept{return scene_resources_;}
    bool needs_session_counters()const noexcept{return session_counters_;}
    bool needs_sequences()const noexcept{return sequences_;}
    bool needs_lighting()const noexcept{return lighting_;}
    bool needs_scene_channels()const noexcept{return scene_channels_;}
    bool needs_scene_controls()const noexcept{return scene_controls_;}
    bool needs_streams()const noexcept{return streams_;}
    bool needs_saved_controls()const noexcept{return saved_controls_;}
    bool needs_world()const noexcept{return world_;}
    bool needs_selected_actor()const noexcept{return selected_actor_;}
    bool needs_action_choices()const noexcept{return action_choices_;}
    bool needs_models()const noexcept{return models_;}
    bool needs_scenario()const noexcept{return scenario_;}
    bool needs_canonical_flags()const noexcept{return canonical_flags_;}
    bool needs_room_objects()const noexcept{return room_objects_;}
    bool needs_room_object_lifetime()const noexcept{return room_object_lifetime_;}
    bool needs_room_object_queries()const noexcept{return room_object_queries_;}
    bool needs_periodic_effects()const noexcept{return periodic_effects_;}
    bool needs_surface_effects()const noexcept{return surface_effects_;}
    bool needs_forced_terminal()const noexcept{return forced_terminal_;}
    bool needs_script_audio()const noexcept{return script_audio_;}
    bool admits_script_audio(const ScriptAudio*,const gameplay_world::World*)const noexcept;
    bool needs_scenario_counter_policy()const noexcept{return scenario_counter_policy_;}
    bool admits_room_counters(const gameplay_world::World*)const noexcept;
    bool admits_inventory_grants(const gameplay_world::World*,const SceneResources*,const ResourceTemplates*)const noexcept;
    bool admits_actor_roster(const gameplay_world::World*)const noexcept;
    bool admits_character_remap(const gameplay_world::World*)const noexcept;
    std::span<const std::uint8_t> adjusted_models()const noexcept{return adjusted_models_;}
    std::span<const std::uint8_t> visibility_models()const noexcept{return visibility_models_;}
    DispatchProfile profile()const noexcept{return profile_;}
private:
    Program(std::vector<std::vector<std::byte>>,DispatchProfile,bool allow_missing_blocks);
    std::vector<std::vector<std::byte>> blocks_;
    std::vector<std::vector<std::uint32_t>> boundaries_;
    bool unsupported_{},flags_{},timers_{},actor_events_{},signals_{},scene_resources_{},session_counters_{},sequences_{},lighting_{},scene_channels_{},scene_controls_{},streams_{},saved_controls_{},world_{},selected_actor_{},action_choices_{},models_{},scenario_{},canonical_flags_{},room_objects_{},room_object_lifetime_{},room_object_queries_{},periodic_effects_{};
    std::vector<std::uint8_t> adjusted_models_;
    std::vector<std::uint8_t> visibility_models_;
    bool surface_effects_{};
    bool room_counters_{},scenario_counter_policy_{};
    bool low_actor_population_{},full_actor_population_{},actor_roster_{},npc_inventory_grants_{};
    bool forced_terminal_{};
    bool character_remap_{};
    bool script_audio_{};
    struct AudioRequest {std::uint32_t event{},mode{},actor{};};
    std::vector<AudioRequest> audio_requests_;
    DispatchProfile profile_{};
};
struct Channel {
    std::shared_ptr<const Program> program;
    Position current,saved;
    std::uint32_t countdown{},block_index{},condition{};
};
struct ChannelReplacement {
    std::size_t channel{};
    std::shared_ptr<const Program> program;
    std::optional<Position> entry;
};
struct ActorEvent {std::uint8_t active{},kind{};std::uint16_t value{};};
enum class FlagBank { scenario,local_primary,local_auxiliary,secondary,bounded_byte,bounded_halfword,scene_record_eligibility };
enum class NotifyOwner { selected_actor_plus_one,zero };
class Flags {
public:
    virtual ~Flags()=default;
    virtual std::optional<bool> get(FlagBank,std::uint32_t)const noexcept=0;
    virtual bool write(FlagBank,std::uint32_t,bool)noexcept=0;
    // Preserve raw notification value as well as the local Boolean bit write.
    virtual bool scenario(std::uint32_t,std::uint8_t,NotifyOwner,std::uint8_t actor_owner)noexcept=0;
    virtual bool strided(std::uint32_t record,std::uint32_t bit,std::uint8_t slot,bool set,bool notify)noexcept=0;
    virtual std::optional<bool> test_strided(std::uint32_t,std::uint32_t,std::uint8_t)const noexcept{return{};}
};
struct SignalMessage {std::uint32_t id{};std::uint8_t value{};std::uint32_t parameter{};};
class Signals {
public:
    virtual ~Signals()=default;
    virtual bool send(const SignalMessage&)noexcept=0;
    virtual std::optional<std::int32_t> query(std::uint32_t id)noexcept=0;
};
struct Providers {Flags* flags{};gameplay_tasks::FlagTimers* timers{};Signals* signals{};FlagState* canonical_flags{};
    SceneResources* scene_resources{};SceneEffects* scene_effects{};SceneOwners* scene_owners{};SessionCounters* session_counters{};SequenceControl* sequences{};Lighting* lighting{};SceneChannels* scene_channels{};SceneControls* scene_controls{};ControlEffects* control_effects{};StreamChannels* streams{};StreamBackend* stream_backend{};SavedControlRecords* saved_controls{};gameplay_world::World* world{};ActionChoices* action_choices{};SceneModels* models{};RoomObjectCommands* room_objects{};PeriodicEffects* periodic_effects{};SurfaceEffects* surface_effects{};const ResourceTemplates* resource_templates{};ForcedActorTerminal* forced_terminal{};ScriptAudio* script_audio{};};
struct TickContext {bool enabled{true};bool alternate_mode{};std::uint8_t selected_actor{};std::uint16_t current_room{};
    // Caller-provided actual SDK/audio service tick, distinct from task passes
    // or the simulation clock. Never inferred from host elapsed time.
    std::optional<std::uint32_t> stream_tick{};};
struct OfflineDispatch {std::uint32_t actor_category{},room_relation{};std::uint16_t actor_room{};};
struct TickResult {Status status{Status::completed};std::size_t operations{};Position position;std::uint32_t opcode{};};
struct OpcodeCoverage {bool native_algorithm{};bool flags_required{},timers_required{},signals_required{},scene_resources_required{},session_counters_required{},sequences_required{},lighting_required{},scene_channels_required{},scene_controls_required{},streams_required{},saved_controls_required{},world_required{},selected_actor_required{},action_choices_required{},models_required{},scenario_required{},canonical_flags_required{},room_objects_required{},room_object_lifetime_required{},room_object_queries_required{},periodic_effects_required{},surface_effects_required{},script_audio_required{};};
class Interpreter {
public:
    static constexpr std::size_t channel_count=6;
    Status install(std::size_t,std::shared_ptr<const Program>,Position entry={0,0})noexcept;
    // Validate every change before replacing or clearing any channel.
    Status replace_channels(std::span<const ChannelReplacement>)noexcept;
    Status restore_channel(std::size_t,const Channel&)noexcept;
    TickResult tick(std::size_t,const TickContext&,Providers={},std::size_t maximum_operations=4096)noexcept;
    TickResult tick_offline_channel(std::size_t,const TickContext&,OfflineDispatch,Providers,std::size_t maximum_operations=4096)noexcept;
    const std::array<Channel,channel_count>& channels()const noexcept{return channels_;}
    const std::array<std::array<ActorEvent,4>,4>& actor_events()const noexcept{return events_;}
    const std::array<std::uint32_t,4>& counters()const noexcept{return counters_;}
    Status restore_counters(const std::array<std::uint32_t,4>&)noexcept;
    std::uint8_t selected_channel()const noexcept{return selected_;}
    static std::array<OpcodeCoverage,432> coverage(DispatchProfile=DispatchProfile::ordinary)noexcept;
private:
    TickResult execute(std::size_t,const TickContext&,Providers,std::size_t,const OfflineDispatch*)noexcept;
    std::array<Channel,channel_count> channels_;
    std::array<std::array<ActorEvent,4>,4> events_{};
    std::array<std::uint32_t,4> counters_{};
    std::uint8_t selected_{};
    bool running_{};
};
} // namespace reo::native::gameplay_scenario
