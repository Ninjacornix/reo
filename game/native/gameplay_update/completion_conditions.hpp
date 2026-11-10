#pragma once
#include "../gameplay_events/statistics.hpp"
#include "../gameplay_world/world.hpp"
#include "../gameplay_scenario/flags.hpp"
#include "../gameplay_scenario/action_choices.hpp"
namespace reo::native::gameplay_update {
// Borrow the authoritative owners. No copied condition state or guest addresses.
class CompletionConditions final {
public:
    CompletionConditions(const gameplay_world::World& world,const gameplay_scenario::FlagState& flags,const gameplay_scenario::ActionChoices& choices):world_(world),flags_(flags),choices_(choices){}
    std::optional<bool> operator()(const gameplay_events::Rule& rule,std::uint32_t kind)const noexcept{
        if(world_.closed())return{};
        const auto first=rule.first_argument,second=rule.second_argument;
        const auto owner=[&](std::uint16_t index)->std::optional<bool>{
            const auto& tags=flags_.snapshot().scenario_owners;if(index>=tags.size())return{};
            return unsigned(tags[index])==unsigned(world_.selected_actor)+1u;
        };
        const auto both=[](std::optional<bool> a,auto next)->std::optional<bool>{if(!a||!*a)return a;return next();};
        const auto either=[](std::optional<bool> a,auto next)->std::optional<bool>{if(!a||*a)return a;return next();};
        using B=gameplay_scenario::FlagBank;
        switch(std::uint8_t(kind)){
        case 0:return true;
        case 2:return owner(first);
        case 3:return flags_.get(B::scenario,first);
        case 4:return flags_.get(B::local_primary,first);
        case 5:return flags_.get(B::bounded_byte,first);
        case 6:return flags_.snapshot().bounded_halfword==first;
        case 7:return both(owner(first),[&]{return owner(second);});
        case 11:return choices_.state().table_row==3;
        case 12:return either(owner(first),[&]{return owner(second);});
        case 13:return both(flags_.get(B::local_primary,first),[&]{return flags_.get(B::local_primary,second);});
        case 14:return both(flags_.get(B::scenario,first),[&]{return flags_.get(B::scenario,second);});
        case 15:{
            if(world_.selected_actor>=4)return{};
            const auto actor=world_.primary(world_.selected_actor);
            return actor&&actor->active&&!(actor->status&0x5e0u)&&!(actor->status&0x80u);
        }
        default:return false;
        }
    }
private:
    const gameplay_world::World& world_;const gameplay_scenario::FlagState& flags_;const gameplay_scenario::ActionChoices& choices_;
};
}
