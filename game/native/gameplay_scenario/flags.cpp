#include "flags.hpp"

namespace reo::native::gameplay_scenario {
FlagWords* FlagState::words(FlagBank bank)noexcept {
    switch(bank){case FlagBank::scenario:return &state_.shared.scenario;case FlagBank::secondary:return &state_.shared.secondary;
    case FlagBank::local_primary:return &state_.primary[0];case FlagBank::local_auxiliary:return &state_.auxiliary[0];default:return nullptr;}
}
const FlagWords* FlagState::words(FlagBank bank)const noexcept{return const_cast<FlagState*>(this)->words(bank);}
std::optional<bool> FlagState::get(FlagBank bank,std::uint32_t id)const noexcept {
    if(const auto* values=words(bank)){if(id>=512)return{};return bool((*values)[id/32]&(1u<<(id&31)));}
    if(bank==FlagBank::bounded_byte){if(id>=128)return{};return bool(state_.bounded_bytes[id/8]&(1u<<(id&7)));}
    if(bank==FlagBank::bounded_halfword){if(id>=16)return{};return bool(state_.bounded_halfword&(1u<<id));}
    return{};
}
bool FlagState::write(FlagBank bank,std::uint32_t id,bool set)noexcept {
    if(auto* values=words(bank)){
        if(id>=512)return false;
        auto& word=(*values)[id/32];const auto mask=1u<<(id&31);word=set?word|mask:word&~mask;return true;
    }
    if(bank==FlagBank::bounded_byte){
        if(id>=128)return false;
        auto& value=state_.bounded_bytes[id/8];const auto mask=std::uint8_t(1u<<(id&7));value=set?std::uint8_t(value|mask):std::uint8_t(value&~mask);return true;
    }
    if(bank==FlagBank::bounded_halfword){
        if(id>=16)return false;
        const auto mask=std::uint16_t(1u<<id);auto& value=state_.bounded_halfword;value=set?std::uint16_t(value|mask):std::uint16_t(value&~mask);return true;
    }
    return false;
}
bool FlagState::scenario(std::uint32_t id,std::uint8_t value,NotifyOwner route,std::uint8_t actor_owner)noexcept {
    if(!notifications_||id>=512)return false;
    write(FlagBank::scenario,id,value!=0);notifications_->changed(ScenarioFlagChange{id,value,actor_owner,route});return true;
}
bool FlagState::strided(std::uint32_t record,std::uint32_t bit,std::uint8_t slot,bool set,bool notify)noexcept {
    if(record>=state_.strided.size()||slot>=6||(notify&&!notifications_))return false;
    const auto mask=std::uint16_t(1u<<(bit&31));auto& value=state_.strided[record][slot];
    value=set?std::uint16_t(value|mask):std::uint16_t(value&~mask);
    if(notify)notifications_->changed(StridedFlagChange{record,bit,slot,set});
    return true;
}
bool FlagState::actor_flag(ActorFlagFamily family,ActorFlagSelection selected,std::uint32_t id,bool set)noexcept {
    if(id>=512||(!selected.all_three&&selected.bank>3))return false;
    const auto update=[&](FlagWords& values){auto& word=values[id/32];const auto mask=1u<<(id&31);word=set?word|mask:word&~mask;};
    auto& actors=family==ActorFlagFamily::primary?state_.primary:state_.auxiliary;
    if(selected.all_three){for(auto& bank:actors)update(bank);}
    else if(selected.bank<3)update(actors[selected.bank]);
    // Original category4 (script class3) crosses the three-owner bank extent:
    // primary aliases auxiliary0, auxiliary aliases scenario. It is not an
    // invented fourth party member or an independent fourth storage bank.
    else update(family==ActorFlagFamily::primary?state_.auxiliary[0]:state_.shared.scenario);
    return true;
}
} // namespace reo::native::gameplay_scenario
