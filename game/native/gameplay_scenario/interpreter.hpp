#pragma once
#include "game/native/gameplay_tasks/tasks.hpp"
#include <array>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <optional>
#include <span>
#include <vector>

namespace reo::native::gameplay_scenario {
class FlagState;
class SceneResources;
class SceneEffects;
class SceneOwners;
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
    std::optional<Record> record(Position)const noexcept;
    std::size_t blocks()const noexcept{return blocks_.size();}
    static std::uint32_t record_bytes(std::uint32_t header)noexcept;
    bool unsupported()const noexcept{return unsupported_;}
    bool needs_flags()const noexcept{return flags_;}
    bool needs_timers()const noexcept{return timers_;}
    bool needs_actor_events()const noexcept{return actor_events_;}
    bool needs_signals()const noexcept{return signals_;}
    bool needs_scene_resources()const noexcept{return scene_resources_;}
    DispatchProfile profile()const noexcept{return profile_;}
private:
    std::vector<std::vector<std::byte>> blocks_;
    std::vector<std::vector<std::uint32_t>> boundaries_;
    bool unsupported_{},flags_{},timers_{},actor_events_{},signals_{},scene_resources_{};
    DispatchProfile profile_{};
};
struct Channel {
    std::shared_ptr<const Program> program;
    Position current,saved;
    std::uint32_t countdown{},block_index{},condition{};
};
struct ActorEvent {std::uint8_t active{},kind{};std::uint16_t value{};};
enum class FlagBank { scenario,local_primary,local_auxiliary,secondary,bounded_byte,bounded_halfword };
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
    SceneResources* scene_resources{};SceneEffects* scene_effects{};SceneOwners* scene_owners{};};
struct TickContext {bool enabled{true};bool alternate_mode{};std::uint8_t selected_actor{};std::uint16_t current_room{};};
struct OfflineDispatch {std::uint32_t actor_category{},room_relation{};std::uint16_t actor_room{};};
struct TickResult {Status status{Status::completed};std::size_t operations{};Position position;std::uint32_t opcode{};};
struct OpcodeCoverage {bool native_algorithm{};bool flags_required{},timers_required{},signals_required{},scene_resources_required{};};
class Interpreter {
public:
    static constexpr std::size_t channel_count=6;
    Status install(std::size_t,std::shared_ptr<const Program>,Position entry={0,0})noexcept;
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
