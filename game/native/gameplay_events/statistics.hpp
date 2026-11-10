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
    // Both condition kinds receive the same whole rule. In particular the
    // second evaluation does not automatically select second_argument.
    template<class Conditions> Recorded automatic(std::uint16_t scenario,const Conditions& conditions,Events& events,std::uint32_t counter){
        const auto group=rules_->scenario(scenario);
        if(!state_.initialized||!group||!events.open())return{StatisticsStatus::unavailable};
        Recorded result;const auto& list=group->get().automatic;
        for(unsigned i=0;i<list.size();++i){
            if(state_.automatic_seen[i])continue;
            const auto& rule=list[i];const auto first=conditions(rule,rule.first_kind);
            if(!first){result.status=StatisticsStatus::unavailable;return result;}
            if(!*first)continue;
            const auto second=conditions(rule,rule.second_kind);
            if(!second){result.status=StatisticsStatus::unavailable;return result;}
            if(!*second)continue;
            complete(rule);state_.automatic_seen[i]=1;++result.matched;
            const auto recorded=events.simple(rule.event,counter);
            if(recorded.status==Status::completed)++result.recorded;
            else if(recorded.status==Status::full)++result.dropped;
            else{result.status=StatisticsStatus::event_unavailable;return result;}
        }
        return result;
    }
private:
    std::shared_ptr<const RuleBook> rules_;
    CompletionState state_;
    void complete(const Rule&)noexcept;
};
}
