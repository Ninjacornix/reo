#pragma once
#include "cutscene_actor_reservations.hpp"
#include "cutscene_descriptor.hpp"
#include <cstring>
#include <optional>
#include <stdexcept>
namespace reo::native::gameplay_scenario {
struct CutscenePrimaryHeader {bool enabled{};std::int16_t kind{},character{},encoded_class{};};
struct CutscenePrimaryHeaders {
    std::array<CutscenePrimaryHeader,32> groups{};std::uint8_t count{};
    std::span<const CutscenePrimaryHeader> view()const noexcept{return{groups.data(),count};}
};
inline CutscenePrimaryHeaders cutscene_primary_headers(const CutsceneDescriptor& descriptor){
    if(descriptor.actor_groups().size()>32)throw std::invalid_argument("Too many native cinematic actor groups");
    CutscenePrimaryHeaders result;result.count=std::uint8_t(descriptor.actor_groups().size());
    for(unsigned i=0;i<result.count;++i){
        const auto bytes=descriptor.section(descriptor.actor_groups()[i][7]);
        if(bytes.size()<36)throw std::invalid_argument("Native cinematic primary header unavailable");
        std::uint16_t enabled;auto& header=result.groups[i];std::memcpy(&enabled,bytes.data()+2,2);header.enabled=enabled!=65535;
        std::memcpy(&header.kind,bytes.data()+4,2);std::memcpy(&header.character,bytes.data()+6,2);std::memcpy(&header.encoded_class,bytes.data()+10,2);
    }
    return result;
}
enum class CutscenePrimarySelectionStatus {completed,invalid_count,invalid_preference,full};
// Capture all eight physical character entries, even beyond population: the
// construction routine searches all eight while fallback searches population.
struct CutscenePrimaryRoster {std::array<std::uint8_t,8> characters{};std::uint8_t population{};};
struct CutscenePrimaryChoice {std::uint8_t group{},temporary_slot{},character{},model_class{};std::optional<std::uint8_t> cloned_roster_slot;friend bool operator==(const CutscenePrimaryChoice&,const CutscenePrimaryChoice&)=default;};
struct CutscenePrimarySelection {
    CutscenePrimarySelectionStatus status{CutscenePrimarySelectionStatus::completed};
    CutsceneActorReservations reservations;
    CutscenePrimaryRoster roster;
    bool reservations_reset{};
    std::array<CutscenePrimaryChoice,8> choices{};std::uint8_t count{};
    std::optional<std::uint8_t> failed_group;
    std::span<const CutscenePrimaryChoice> selected()const noexcept{return{choices.data(),count};}
};
// Pure5F0DC0 choice preparation. It never binds a live Actor or transfers a
// model. The actual scene owner must validate/publish that separate lifecycle.
// preferred_roster_one_based is the source scene preference, not World.selected_actor.
inline CutscenePrimarySelection select_cutscene_primaries(std::span<const CutscenePrimaryHeader> headers,
    const CutscenePrimaryRoster& roster,std::uint32_t preferred_roster_one_based,
    std::array<bool,8> occupied={},const CutsceneActorReservations& previous={})noexcept{
    CutscenePrimarySelection result;result.reservations=previous;result.roster=roster;
    if(headers.size()>32||roster.population>8){result.status=CutscenePrimarySelectionStatus::invalid_count;return result;}
    bool relevant{},fallback_ready=true;std::array<std::uint8_t,32> requested{};unsigned requested_count{};
    for(const auto& h:headers){
        if(!h.enabled)continue;
        if(h.kind==0){relevant=true;requested[requested_count++]=std::uint8_t(h.character);}
        if(h.kind==3){relevant=true;if(h.character==0)fallback_ready=false;}
    }
    if(!relevant)return result;
    (void)result.reservations.initialize(std::span(requested).first(requested_count));result.reservations_reset=true;
    for(unsigned group=0;group<headers.size();++group){
        const auto& h=headers[group];if(!h.enabled||(h.kind!=0&&h.kind!=3))continue;
        std::optional<std::uint8_t> character;
        if(h.kind==0)character=std::uint8_t(h.character);
        else{
            if(h.character==0){
                if(preferred_roster_one_based>roster.population){result.status=CutscenePrimarySelectionStatus::invalid_preference;result.failed_group=std::uint8_t(group);return result;}
                if(preferred_roster_one_based){const auto preferred=result.roster.characters[preferred_roster_one_based-1];if(!result.reservations.contains(preferred))character=preferred;}
            }else if(!fallback_ready||roster.population<unsigned(result.count)+1)continue;
            if(!character)for(const auto candidate:std::span(result.roster.characters).first(roster.population))if(!result.reservations.contains(candidate)){character=candidate;break;}
        }
        if(!character)continue;
        unsigned slot{};while(slot<occupied.size()&&occupied[slot])++slot;
        if(slot==occupied.size()){result.status=CutscenePrimarySelectionStatus::full;result.failed_group=std::uint8_t(group);return result;}
        occupied[slot]=true;
        std::optional<std::uint8_t> cloned;
        for(unsigned i=0;i<8;++i)if(result.roster.characters[i]==*character){cloned=std::uint8_t(i);break;}
        const auto model_class=std::uint8_t(h.encoded_class^1);
        result.choices[result.count++]={std::uint8_t(group),std::uint8_t(slot),*character,model_class,cloned};
        if(cloned&&model_class==1)result.roster.characters[*cloned]=255;
        (void)result.reservations.reserve(*character);
        if(h.kind==3)fallback_ready=true;
    }
    return result;
}
}
