#pragma once
#include "../adxt_phased_player/player.hpp"
#include <memory>
#include <span>

namespace reo::native::adxt_control_session {
namespace player=adxt_phased_player;
namespace output=adxt_output_session;
enum class Status { completed,pending,closed,busy,invalid_key,invalid_indices,occupied,
    capacity,order_required,unsupported_profile,allocation_failure,provider_refused,fault };
struct Identity;
class Key final {
public:Key()=default;
private:
    friend class Session;
    std::weak_ptr<const Identity> identity_;
    std::uint64_t generation_{};std::uint32_t slot_{};
};
struct Indices {std::uint32_t decoder{},stream{},rna{},transfer{},host_gain_key{};};
struct Config {output::Config output;player::clock::Shared clock;};
struct Open {Status status{Status::fault};Key key;};
struct Observation {Status status{Status::invalid_key};player::Snapshot evidence;};
struct Retirement {Status status{Status::invalid_key};player::Snapshot evidence;bool source_joined{};};
struct ClockResult {Status status{Status::invalid_key};player::ClockResult value;};
struct ClockControl {Status status{Status::invalid_key};player::ClockControl value;};
struct Snapshot {
    output::Snapshot output;
    player::clock::Shared clock_state;
    std::uint32_t records{},retiring{},service_busy{};
    std::uint64_t group_visits{},dtx_scans{},discard_diagnostics{};
    bool closing{},joined{},order_required{},guard_fault{};
};
class Session final {
public:
    Session(Config,std::shared_ptr<audio_output::CallbackSlot>,std::shared_ptr<audio_output::Provider>);
    explicit Session(Config);
    ~Session();
    Session(const Session&)=delete;Session& operator=(const Session&)=delete;
    [[nodiscard]] Status start()noexcept;
    [[nodiscard]] Open open(player::Config,std::shared_ptr<const resources::ByteView>,Indices)noexcept;
    [[nodiscard]] Status set_order(std::span<const Key>)noexcept;
    [[nodiscard]] Status service(std::uint32_t original_tick)noexcept;
    [[nodiscard]] Observation inspect(const Key&)const noexcept;
    [[nodiscard]] Snapshot snapshot()const noexcept;
    [[nodiscard]] std::shared_ptr<output::Submix> submix()const noexcept;
    [[nodiscard]] Status gain(const Key&,float)noexcept;
    [[nodiscard]] Status volume(const Key&,std::uint32_t)noexcept;
    [[nodiscard]] Status attenuation(const Key&,std::uint32_t requested_word)noexcept;
    [[nodiscard]] ClockResult estimate(const Key&,std::uint32_t original_tick)noexcept;
    [[nodiscard]] ClockResult centiseconds(const Key&,std::uint32_t original_tick)noexcept;
    [[nodiscard]] ClockControl pause(const Key&,std::int32_t,std::uint32_t original_tick)noexcept;
    [[nodiscard]] ClockControl discard_rebase(const Key&,std::uint32_t original_tick)noexcept;
    [[nodiscard]] Status set_time_base(const Key&,std::uint32_t)noexcept;
    [[nodiscard]] Status set_loop_enabled(const Key&,bool)noexcept;
    [[nodiscard]] Retirement retire(const Key&)noexcept;
    [[nodiscard]] Status request_stop()noexcept;
    [[nodiscard]] Status join()noexcept;
private:
    struct State;std::unique_ptr<State> state_;
    [[nodiscard]] bool valid(const Key&,bool retiring=false)const noexcept;
    [[nodiscard]] Retirement retire_slot(std::uint32_t)noexcept;
};
} // namespace reo::native::adxt_control_session
