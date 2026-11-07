#pragma once
#include "../movie_counter_clock/clock.hpp"
#include <array>
#include <memory>
#include <optional>

namespace reo::native::movie_selected_clock {
namespace counter=movie_counter_clock;
using Words=counter::Words;
enum class Kind {empty,unavailable,counter,contextual,external,registered};
enum class Operation {selected,cached,external,refresh,tick};
enum class Status {completed,busy,invalid_input};
struct FactsUpdate {
    std::optional<std::uint32_t> actual,pause,buffering_pause,property_47;
};
struct Reply {
    Words words;std::uint32_t status{};
    bool numerator{true},denominator{true},remove_selected_slot{};
    FactsUpdate facts;
};
struct State {
    counter::State counter;
    Words cached{0xFFFFFFFBu,1};
    std::uint32_t selector{},pending{},previous_sample{0xFFFFFFFBu},external_denominator{1};
};
struct Snapshot {
    State state;std::array<Kind,7> slots;
    std::uint32_t guard_depth{},guard_tag{};
    bool external_present{};
};
class Query {
public:
    virtual ~Query()=default;
    // Bounded/serialized/noexcept. No I/O, allocation, nested query/service or
    // owner destruction. Slot replacement is permitted during this call.
    virtual Reply query(State snapshot,Words prior) noexcept=0;
};
class GuardHooks {
public:
    virtual ~GuardHooks()=default;
    virtual void enter(std::uint32_t parameter) noexcept=0;
    virtual void leave(std::uint32_t parameter) noexcept=0;
};
enum class Event {phase_enter,hook_enter,query,phase_leave,hook_leave};
class Probe {
public:
    virtual ~Probe()=default;
    // Optional copied evidence only. Bounded/noexcept/nonreentrant; no I/O or
    // allocation, no snapshot/reference retention except by value.
    virtual void event(Event,const Snapshot&,Words) noexcept=0;
};
struct Config {
    State state;std::uint32_t frequency{48000},guard_depth{},guard_tag{};
    std::uint32_t enter_parameter{0x11223344},leave_parameter{0x55667788};
    std::shared_ptr<GuardHooks> guard;
    std::shared_ptr<Probe> probe;
};
struct Scratch {Words refresh{},external{};};
struct Result {Status status{Status::invalid_input};Words words;std::uint32_t query_status{};bool query_status_defined{};};
// Externally serialized owned context. Scratch is an explicit input because
// selected callbacks may leave original local words untouched.
class Clock final {
public:
    explicit Clock(Config);
    Clock(const Clock&)=delete;Clock& operator=(const Clock&)=delete;
    [[nodiscard]] Status set_callback(std::uint32_t,std::shared_ptr<Query>) noexcept;
    [[nodiscard]] Status set_external(std::shared_ptr<Query>) noexcept;
    [[nodiscard]] Result execute(Operation,Words prior,Scratch) noexcept;
    [[nodiscard]] Snapshot snapshot() const noexcept;
private:
    void emit(Event,Words={}) noexcept;
    void enter() noexcept;
    void leave() noexcept;
    void facts(const FactsUpdate&) noexcept;
    std::uint32_t callback(const std::shared_ptr<Query>&,Words&) noexcept;
    std::uint32_t builtin(counter::Operation,Words&) noexcept;
    std::uint32_t external(Words&,Words scratch) noexcept;
    std::uint32_t selected(Words&,Words external_scratch) noexcept;
    void refresh(Scratch) noexcept;
    Config config_;
    std::array<Kind,7> kinds_{Kind::unavailable,Kind::counter,Kind::empty,Kind::contextual,Kind::empty,Kind::external,Kind::empty};
    std::array<std::shared_ptr<Query>,7> callbacks_;
    std::shared_ptr<Query> external_;
    bool busy_{};
};
}
