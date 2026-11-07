#pragma once
#include "../adxt_control_session/control_session.hpp"
#include <optional>

namespace reo::native::adxt_instances {
namespace control=adxt_control_session;
enum class Status {completed,pending,closed,busy,invalid_key,invalid_input,occupied,capacity,order_required,unsupported_profile,provider_refused,fault};
struct Identity;
class Key final {
public:Key()=default;
private:friend class Instances;std::weak_ptr<const Identity> owner_;std::uint32_t slot_{};std::uint64_t generation_{};
};
struct Construction {std::uint32_t channels{1};control::Indices indices;};
struct Open {Status status{Status::fault};Key key{};};
struct Source {control::player::Config player;std::shared_ptr<const resources::ByteView> input;};
enum class Phase {idle,active,retiring,destroying,fault};
struct Observation {
    Status status{Status::invalid_key};Phase phase{Phase::idle};bool replacement_pending{};
    std::uint64_t starts{},completed_stops{};
    std::optional<control::player::Snapshot> source;
};
struct Snapshot {control::Snapshot session;std::uint32_t instances{},pending{},retiring{};bool closing{},order_required{};};
// Stable public instance lifetime over replaceable, generation-scoped native
// source players. Sole owner of its canonical Session; no underlying Key or
// mutable player/source/clock/output alias escapes. One serialized controller.
class Instances final {
public:
    Instances(control::Config,std::shared_ptr<audio_output::CallbackSlot>,std::shared_ptr<audio_output::Provider>);
    ~Instances();
    Instances(const Instances&)=delete;Instances& operator=(const Instances&)=delete;
    [[nodiscard]] Status start_output()noexcept;
    [[nodiscard]] Open create(Construction)noexcept;
    // Accepted replacement retains at most one unopened source. A newer start
    // supersedes that unopened request; old active resources must retire first.
    [[nodiscard]] Status start(const Key&,Source)noexcept;
    [[nodiscard]] Status stop(const Key&)noexcept;
    [[nodiscard]] Status destroy(const Key&)noexcept;
    // Exact permutation of ALL constructed instance keys, including idle ones.
    // Only active sources enter the session's actual mixer permutation.
    [[nodiscard]] Status set_order(std::span<const Key>)noexcept;
    [[nodiscard]] Status service(std::uint32_t original_tick)noexcept;
    [[nodiscard]] Observation inspect(const Key&)const noexcept;
    [[nodiscard]] Snapshot snapshot()const noexcept;
    [[nodiscard]] Status gain(const Key&,float)noexcept;
    [[nodiscard]] Status pause(const Key&,std::int32_t,std::uint32_t original_tick)noexcept;
    [[nodiscard]] control::ClockResult estimate(const Key&,std::uint32_t original_tick)noexcept;
    [[nodiscard]] Status request_stop()noexcept;
    [[nodiscard]] Status join()noexcept;
private:
    struct State;std::unique_ptr<State> state_;
    bool valid(const Key&,bool destroying=false)const noexcept;
    Status retire(std::uint32_t)noexcept;
    Status open(std::uint32_t)noexcept;
    Status publish_order()noexcept;
    void release(std::uint32_t)noexcept;
};
} // namespace reo::native::adxt_instances
