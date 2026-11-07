#pragma once
#include "../movie_selected_clock/clock.hpp"
#include <cstdint>
#include <memory>
#include <optional>

namespace reo::native::movie_pause {
struct State {
    std::uint32_t actual{4},requested{4},pause{},depth{},pending{},buffering{},episodes{},rate{1};
    std::uint32_t active_counter{},elapsed_counter{0xFFFFFFFFu},external_accumulator{},external_denominator{1};
    bool validation_seen{};
    bool operator==(const State&)const=default;
};
struct Updates {
    std::optional<std::uint32_t> actual,requested,pause,depth,pending,buffering,episodes,rate;
    std::optional<std::uint32_t> active_counter,elapsed_counter,external_accumulator,external_denominator;
};
enum class Kind {command,pause_predicate,resume_predicate,error};
enum class ProviderStatus {completed,failed};
struct Call {Kind kind;std::uint32_t target{},command{},argument{},extra{};};
struct Guard {std::uint32_t depth{},tag{};bool operator==(const Guard&)const=default;};
struct View {State state;Guard guard;};
struct Reply {ProviderStatus provider{ProviderStatus::completed};std::uint32_t status{};Updates updates;};
class Ports {
public:
    virtual ~Ports()=default;
    // Bounded synchronous call. Scripted/actual effects are returned explicitly;
    // no owner destruction, allocation or state mutation through escaped refs.
    virtual Reply call(Call,View)noexcept=0;
};
struct Config {
    State state;std::uint32_t frequency{48000};Guard guard;
    std::shared_ptr<Ports> ports;
    std::shared_ptr<movie_selected_clock::GuardHooks> hooks;
    std::uint32_t enter_parameter{0x11223344},leave_parameter{0x55667788};
};
enum class Operation {pause,nested,forward,buffer,step};
enum class Status {completed,busy,invalid_input,invalid_rate,provider_failure};
struct Result {Status status{Status::invalid_input};std::uint32_t returned{};bool return_defined{};};
struct Snapshot {View view;Status status{Status::completed};};
// Isolated paired pure guard-hook profile, externally serialized. This is not
// an implementation of the global CRI scheduler or complete buffer predicates.
class Controller final {
public:
    explicit Controller(Config);
    Controller(const Controller&)=delete;Controller& operator=(const Controller&)=delete;
    [[nodiscard]] Result execute(Operation,std::uint32_t argument)noexcept;
    [[nodiscard]] Snapshot snapshot()const noexcept{return{{config_.state,config_.guard},status_};}
private:
    void apply(const Updates&)noexcept;
    std::uint32_t invoke(Call)noexcept;
    void enter()noexcept;
    void leave()noexcept;
    void step(std::uint32_t)noexcept;
    std::uint32_t forward(std::uint32_t)noexcept;
    std::uint32_t nested(std::uint32_t)noexcept;
    std::uint32_t pause(std::uint32_t)noexcept;
    std::uint32_t buffer()noexcept;
    [[nodiscard]] bool needs_step(Operation,std::uint32_t)const noexcept;
    Config config_;Status status_{Status::completed};bool busy_{};
};
}
