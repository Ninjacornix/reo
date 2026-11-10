// Frozen declared hit/status provider fixture, derived from hit_tests.cpp.
#pragma once
#include "game/native/gameplay_actors/hit.hpp"
#include "status_runtime.hpp"
#include <bit>
#include <iostream>
#include <vector>
namespace g=reo::native::gameplay_actors;
namespace gs=reo::native::gameplay_session;
constexpr std::uint32_t base=0x4a5c30;
template<class T>T get(const std::uint8_t* r,std::uint32_t at){return oracle_read<T>(r,at);}
template<class T>void put(std::uint8_t* r,std::uint32_t at,T v){oracle_write(r,at,v);}
g::HitActor read(const std::uint8_t* r){
    g::HitActor a;a.current=get<std::int16_t>(r,base+0x544);a.maximum=get<std::int16_t>(r,base+0x546);
    a.control_elapsed=get<std::uint32_t>(r,base+0xd28);a.status=get<std::uint32_t>(r,base+0xba0);a.auxiliary_status=get<std::uint32_t>(r,base+0xba4);
    a.room=get<std::uint16_t>(r,base+0x1e2);a.category=r[base+2];a.slot=r[base+3];a.class_marker=r[base+0xb9b];
    a.primary=r[base+8];a.secondary=r[base+9];a.phase=r[base+10];a.subphase=r[base+11];
    a.motion_class=r[base+0x54f];a.response_class=r[base+0x140];
    a.damage_interval_one=get<std::uint16_t>(r,base+0xc60);a.damage_interval_two=get<std::uint16_t>(r,base+0xc58);
    a.status_duration=get<std::uint16_t>(r,base+0xc5a);a.recovery_timer=get<std::uint16_t>(r,base+0xc5e);
    a.damage_word=get<std::int32_t>(r,base+0x138);a.progression_amount=get<std::uint16_t>(r,base+0x14e);
    a.pending_hit=r[base+0x13f];a.damage_kind=r[base+0x13d];a.response_flags=r[base+0x143];a.notice_flags=r[base+0x115];
    a.source_kind=r[base+0x148];a.source_slot=r[base+0x149];a.special_kind=r[base+0x150];a.response_lock=r[base+0xbd0];
    a.transient_contact=r[base+0xc64];a.transient_action=r[base+0xab8];a.transient_equipment=r[base+0xad4];
    a.interaction_slot=r[base+0xc7a];a.equipment_slot=r[base+0xc7f];return a;
}
void write(std::uint8_t* r,const g::HitActor& a){
    put(r,base+0xd28,a.control_elapsed);put(r,base+0x544,a.current);put(r,base+0x546,a.maximum);put(r,base+0xba0,a.status);put(r,base+0xba4,a.auxiliary_status);
    put(r,base+0x1e2,a.room);r[base+2]=a.category;r[base+3]=a.slot;r[base+0xb9b]=a.class_marker;
    r[base+8]=a.primary;r[base+9]=a.secondary;r[base+10]=a.phase;r[base+11]=a.subphase;
    r[base+0x54f]=a.motion_class;r[base+0x140]=a.response_class;
    put(r,base+0xc60,a.damage_interval_one);put(r,base+0xc58,a.damage_interval_two);put(r,base+0xc5a,a.status_duration);put(r,base+0xc5e,a.recovery_timer);
    put(r,base+0x138,a.damage_word);put(r,base+0x14e,a.progression_amount);
    r[base+0x13f]=a.pending_hit;r[base+0x13d]=a.damage_kind;r[base+0x143]=a.response_flags;r[base+0x115]=a.notice_flags;
    r[base+0x148]=a.source_kind;r[base+0x149]=a.source_slot;r[base+0x150]=a.special_kind;r[base+0xbd0]=a.response_lock;
    r[base+0xc64]=a.transient_contact;r[base+0xab8]=a.transient_action;r[base+0xad4]=a.transient_equipment;
    r[base+0xc7a]=a.interaction_slot;r[base+0xc7f]=a.equipment_slot;
}
g::HitSession read_session(const std::uint8_t* r){
    g::HitSession s;const auto mode=std::bit_cast<std::int8_t>(r[0x3243fb]);
    s.selected_actor=r[0x4baded];s.room=get<std::uint16_t>(r,0x3243dc);s.authority_filter=mode==1||mode==2;
    s.paused=r[0x4badf8]!=0;s.clock_mode=r[0x3243cc];s.feedback_phase=r[0x4bae02];s.feedback_suppressed=r[0x4bae03];s.session_state=get<std::int16_t>(r,0x324200);s.suppress_hits=r[0x4bae8d]!=0;s.contact_recorded=r[0x3b84f4];s.mode=r[0x3243f2];return s;
}
void write_session(std::uint8_t* r,const g::HitSession& s){
    r[0x4baded]=s.selected_actor;put(r,0x3243dc,s.room);r[0x3243fb]=s.authority_filter?1:0;
    r[0x4badf8]=s.paused?1:0;r[0x3243cc]=s.clock_mode;r[0x4bae02]=s.feedback_phase;r[0x4bae03]=s.feedback_suppressed;put(r,0x324200,s.session_state);r[0x4bae8d]=s.suppress_hits?1:0;r[0x3b84f4]=s.contact_recorded;r[0x3243f2]=s.mode;
}
struct Ports final:g::HitServices {
    std::uint32_t seed{};std::vector<std::uint32_t> trace;
    g::HitActor* current{};
    std::array<std::uint32_t,8> partner_status{};
    std::array<std::uint8_t,8> characters{};
    std::array<std::uint16_t,16> owners{};
    std::array<std::uint8_t,24> relations{};
    void log(std::uint32_t call,const g::StatusActor& a,std::uint32_t arg=0,std::uint32_t other=0){
        trace.insert(trace.end(),{call,arg,other,a.status,std::uint32_t(a.current),a.primary,a.secondary,a.phase,a.subphase});
    }
    bool authority_filter(g::HealthSession& s)override{trace.push_back(0x1b0310);return s.authority_filter;}
    std::int32_t selected_authority(g::HealthSession&,std::uint8_t selected)override{trace.insert(trace.end(),{0x1b0110,selected});return seed%3==0?0:seed%3==1?1:-1;}
    void refresh_class(g::HealthState& a,g::HealthSession&)override{trace.insert(trace.end(),{0x65fab0,a.status});a.class_marker=std::uint8_t(a.current);}
    void feedback(g::StatusActor& state,g::StatusSession&,std::uint8_t kind)override{
        auto& a=static_cast<g::HitActor&>(state);log(0x665ca0,a,kind);
        if(seed&8)a.damage_word=-2;
        if(seed&16)a.damage_kind=0x84;
    }
    void publish(g::StatusActor& state,g::StatusSession&,std::uint8_t kind)override{
        auto& a=static_cast<g::HitActor&>(state);log(0x67e230,a,kind);
        if(seed&16)a.status^=0x10000000;
        if(seed&32)a.notice_flags&=~std::uint8_t(1);
    }
    void cleanup(g::StatusActor& a,g::StatusSession&)override{log(0x5f6800,a);if(seed&8)a.motion_class=0x28;}
    void recover(g::StatusActor& a,g::StatusSession&)override{log(0x65fc10,a);a.current=1;}
    void snapshot(g::StatusActor& a,g::StatusSession&)override{log(0x667370,a);if(seed&64)a.phase=19;}
    bool locally_controlled(g::HitActor& a,g::HitSession& s)override{return a.category==0 && a.slot==(s.mode==0?0:s.selected_actor);}
    std::uint32_t partner_flags(std::uint8_t slot)override{if(slot>=4)throw std::runtime_error("masked partner slot");return slot?partner_status[slot]:current->status;}
    std::uint8_t partner_character(std::uint8_t slot)override{if(slot>=characters.size())throw std::runtime_error("full partner slot");return characters[slot];}
    std::uint16_t scene_owner(std::uint8_t slot)override{if(slot>=owners.size())throw std::runtime_error("scene slot");return owners[slot];}
    void event(g::HitActor& a,g::HitSession&,std::uint32_t kind,std::uint32_t parameter)override{log(0x37c060,a,kind,parameter);}
    void add_status(g::HitActor& a,g::HitSession&,std::uint8_t code)override{log(0x6606d0,a,code);a.status|=code==1?1:2;if(seed&64)a.status|=0x400000;}
    void close_inventory(g::HitActor& a,g::HitSession&)override{log(0x5f4fd0,a);if(seed&128)a.primary=1;}
    void detach_scene(g::HitActor& a,g::HitSession&,std::uint8_t kind,std::uint8_t slot)override{log(0x67ff80,a,kind,slot);if(seed&16)a.equipment_slot=std::uint8_t((a.equipment_slot+1)%16);}
    void release_equipment(g::HitActor& a,g::HitSession&,std::uint8_t slot)override{log(0x5f5c50,a,0,slot);if(seed&32)a.progression_amount=7;}
    void cancel_action(g::HitActor& a,g::HitSession&)override{log(0x65e710,a);if(seed&64)a.motion_class=0x28;}
    void apply_progression(g::HitActor& a,g::HitSession&,std::uint16_t amount)override{log(0x660060,a,amount);if(seed&128)a.status|=0x800000;}
    void refresh_statistics(g::HitActor& a,g::HitSession&)override{log(0x6df160,a);}
    void finish_contact_state(g::HitActor& a,g::HitSession&)override{log(0x6689e0,a);if(seed&256)a.response_flags^=1;}
    void clear_hit_relations(g::HitActor&,g::HitSession&)override{relations.fill(0);}
};
