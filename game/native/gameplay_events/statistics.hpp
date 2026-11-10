#pragma once
#include "events.hpp"
#include <functional>
#include <span>
namespace reo::native::gameplay_events {
struct Rule {
    std::uint8_t first_kind{},second_kind{};
    std::uint16_t first_argument{},second_argument{},event{},points{};
};
struct RuleGroup {std::vector<Rule> automatic,explicit_ids;};
// Immutable native metadata; original addresses and FF sentinels are absent.
class RuleBook final {
public:
    static std::shared_ptr<const RuleBook> file1();
    static std::shared_ptr<const RuleBook> create(std::vector<RuleGroup>,std::vector<std::int8_t> mapping);
    std::optional<std::reference_wrapper<const RuleGroup>> scenario(std::uint16_t)const noexcept;
private:
    std::vector<RuleGroup> groups_;std::vector<std::int8_t> mapping_;
};
struct CompletionState {
    std::array<std::uint32_t,2> completed{};
    std::uint32_t points{};
    std::uint8_t unique_available{};
    std::array<std::uint8_t,64> automatic_seen{},explicit_seen{};
    bool initialized{};
};
enum class StatisticsStatus {completed,unavailable,event_unavailable};
struct Recorded {StatisticsStatus status{StatisticsStatus::completed};unsigned matched{},recorded{},dropped{};};
// Owns the event-completion part of scenario statistics. Other gameplay counter
// consumers are separate work; no opaque232-byte guest-layout stats mirror.
class Statistics final {
public:
    explicit Statistics(std::shared_ptr<const RuleBook> = RuleBook::file1());
    const CompletionState& state()const noexcept{return state_;}
    void restore(CompletionState state)noexcept{state_=state;}
    // Reconstructed37B990 completion/seen initialization and actual pool reset.
    // Other counters in that original232-byte block are not claimed here.
    StatisticsStatus initialize(std::uint16_t scenario,Events&);
    // Complete admitted37BBC0/37C470 explicit path; the caller owns any local
    // actor gate. Source1B02D0's ignored pure return creates no native effect.
    Recorded explicit_id(std::uint16_t scenario,std::uint32_t content,Events&,std::uint32_t update_counter);
private:
    std::shared_ptr<const RuleBook> rules_;
    CompletionState state_;
    void complete(const Rule&)noexcept;
};
}
