#pragma once
#include "status.hpp"
#include <span>

namespace reo::native::gameplay_actors {
struct HitActor : StatusActor {
    std::int32_t damage_word{};
    std::uint16_t progression_amount{};
    std::uint8_t pending_hit{},damage_kind{},response_flags{},notice_flags{};
    std::uint8_t source_kind{},source_slot{},special_kind{},response_lock{};
    std::uint8_t transient_contact{},transient_action{},transient_equipment{};
    std::uint8_t interaction_slot{},equipment_slot{};
};
struct HitSession : StatusSession {bool suppress_hits{};std::uint8_t contact_recorded{},mode{};};
class HitServices : public StatusServices {
public:
    virtual bool locally_controlled(HitActor&,HitSession&)=0;
    virtual std::uint32_t partner_flags(std::uint8_t slot)=0;
    virtual std::uint8_t partner_character(std::uint8_t slot)=0;
    virtual std::uint16_t scene_owner(std::uint8_t slot)=0;
    virtual void event(HitActor&,HitSession&,std::uint32_t kind,std::uint32_t parameter)=0;
    virtual void add_status(HitActor&,HitSession&,std::uint8_t selector)=0;
    virtual void close_inventory(HitActor&,HitSession&)=0;
    virtual void detach_scene(HitActor&,HitSession&,std::uint8_t kind,std::uint8_t slot)=0;
    virtual void release_equipment(HitActor&,HitSession&,std::uint8_t slot)=0;
    virtual void cancel_action(HitActor&,HitSession&)=0;
    virtual void clear_owner_interaction(HitActor&,HitSession&)=0;
    virtual void apply_progression(HitActor&,HitSession&,std::uint16_t amount)=0;
    virtual void refresh_statistics(HitActor&,HitSession&)=0;
    virtual void finish_contact_state(HitActor&,HitSession&)=0;
    virtual void clear_hit_relations(HitActor&,HitSession&)=0;
};
// Response timer amounts are an admitted native content span. Invalid original
// indices are explicitly refused after the preceding consume/notice effects.
void consume_pending_hit(HitActor&,HitSession&,HitServices&,std::span<const std::int16_t> timer_amounts);
} // namespace reo::native::gameplay_actors
