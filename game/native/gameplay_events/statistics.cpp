#include "statistics.hpp"
#include <bit>
#include <stdexcept>
namespace reo::native::gameplay_events {
std::shared_ptr<const RuleBook> RuleBook::create(std::vector<RuleGroup> groups,std::vector<std::int8_t> mapping){
    if(groups.size()>128||mapping.size()>65536)throw std::out_of_range("Native event rule catalogue extent unavailable");
    for(const auto& group:groups)for(const auto* list:{&group.automatic,&group.explicit_ids}){
        if(list->size()>64)throw std::out_of_range("Native scenario event seen capacity exceeded");
        for(const auto& rule:*list)if(rule.first_kind==255||rule.event>=64)throw std::out_of_range("Native event rule sentinel/bitset profile unavailable");
    }
    for(const auto index:mapping)if(index>=0&&std::size_t(index)>=groups.size())throw std::out_of_range("Native scenario event group unavailable");
    auto result=std::make_shared<RuleBook>();result->groups_=std::move(groups);result->mapping_=std::move(mapping);return result;
}
std::shared_ptr<const RuleBook> RuleBook::file1(){
    static const auto book=[](){
#include "scenario_event_rules.inc"
        return create(groups,mapping);
    }();return book;
}
std::optional<std::reference_wrapper<const RuleGroup>> RuleBook::scenario(std::uint16_t id)const noexcept{
    if(id>=mapping_.size()||mapping_[id]<0)return{};
    const auto index=std::size_t(mapping_[id]);if(index>=groups_.size())return{};
    return std::cref(groups_[index]);
}
Statistics::Statistics(std::shared_ptr<const RuleBook> rules):rules_(std::move(rules)){
    if(!rules_)throw std::invalid_argument("Native scenario event rule owner missing");
}
StatisticsStatus Statistics::initialize(std::uint16_t scenario,Events& events){
    const auto group=rules_->scenario(scenario);if(!group||!events.open())return StatisticsStatus::unavailable;
    state_={};if(events.reset()!=Status::completed)return StatisticsStatus::event_unavailable;
    std::array<std::uint32_t,2> seen{};
    for(const auto* list:{&group->get().automatic,&group->get().explicit_ids})for(const auto& rule:*list){const auto mask=1u<<(rule.event&31u);auto& word=seen[rule.event/32];if(!(word&mask)){word|=mask;++state_.unique_available;}}
    state_.initialized=true;return StatisticsStatus::completed;
}
void Statistics::complete(const Rule& rule)noexcept{state_.completed[rule.event/32]|=1u<<(rule.event&31u);state_.points+=rule.points;}
Recorded Statistics::explicit_id(std::uint16_t scenario,std::uint32_t full_content,Events& events,std::uint32_t counter){
    const auto group=rules_->scenario(scenario);if(!state_.initialized||!group||!events.open())return{StatisticsStatus::unavailable};
    const auto content=std::uint16_t(full_content);Recorded result;const auto& list=group->get().explicit_ids;
    for(unsigned i=0;i<list.size();++i){const auto& rule=list[i];if(state_.explicit_seen[i]||rule.first_kind!=1||rule.first_argument!=content)continue;
        complete(rule);state_.explicit_seen[i]=1;++result.matched;const auto recorded=events.simple(rule.event,counter);
        if(recorded.status==Status::completed)++result.recorded;
        else if(recorded.status==Status::full)++result.dropped;
        else{result.status=StatisticsStatus::event_unavailable;return result;}
    }
    return result;
}
}
