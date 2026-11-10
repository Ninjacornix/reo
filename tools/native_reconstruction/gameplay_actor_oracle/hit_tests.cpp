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
    void recover(g::StatusActor&,g::StatusSession&)override{throw std::runtime_error("unreachable pending-hit recovery");}
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
void o2_0065FEB0_0x65feb0(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_0065FF70_0x65ff70(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_00660980_0x660980(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_00666620_0x666620(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_00666D90_0x666d90(std::uint8_t*,R5900Context*,PS2Runtime*);
void sub_001B0340_0x1b0340(std::uint8_t*,R5900Context*,PS2Runtime*);
Ports* original_ports{};
void original_port(std::uint8_t* r,R5900Context* c,PS2Runtime* runtime){
    switch(c->pc){
    case 0x65feb0:o2_0065FEB0_0x65feb0(r,c,runtime);return;
    case 0x65ff70:o2_0065FF70_0x65ff70(r,c,runtime);return;
    case 0x660980:o2_00660980_0x660980(r,c,runtime);return;
    case 0x666620:o2_00666620_0x666620(r,c,runtime);return;
    case 0x666d90:o2_00666D90_0x666d90(r,c,runtime);return;
    case 0x1b0340:sub_001B0340_0x1b0340(r,c,runtime);return;
    case 0x1b02d0:SET_GPR_U32(c,2,r[0x3243f2]==0);c->pc=GPR_U32(c,31);return;
    case 0x107c68:
        if(GPR_U32(c,4)!=base+0xb1c || GPR_U32(c,5)!=0 || GPR_U32(c,6)!=24)throw std::runtime_error("relation clear ABI");
        std::fill(r+base+0xb1c,r+base+0xb34,0);c->pc=GPR_U32(c,31);return;
    default:break;
    }
    auto a=read(r);auto s=read_session(r);auto& p=*original_ports;p.current=&a;
    const auto arg=GPR_U32(c,5),other=GPR_U32(c,6);
    switch(c->pc){
    case 0x1b0310:SET_GPR_U32(c,2,p.authority_filter(s));break;
    case 0x1b0110:SET_GPR_S32(c,2,p.selected_authority(s,std::uint8_t(GPR_U32(c,4))));break;
    case 0x65fab0:p.refresh_class(a,s);break;
    case 0x665ca0:p.feedback(a,s,std::uint8_t(arg));break;
    case 0x67e230:p.publish(a,s,std::uint8_t(arg));break;
    case 0x5f6800:if(arg)throw std::runtime_error("cleanup arg");p.cleanup(a,s);break;
    case 0x667370:p.snapshot(a,s);break;
    case 0x37c060:p.event(a,s,GPR_U32(c,4),arg);break;
    case 0x6606d0:p.add_status(a,s,std::uint8_t(arg));break;
    case 0x5f4fd0:p.close_inventory(a,s);break;
    case 0x67ff80:p.detach_scene(a,s,std::uint8_t(arg),std::uint8_t(other));break;
    case 0x5f5c50:if(arg)throw std::runtime_error("release arg");p.release_equipment(a,s,std::uint8_t(other));break;
    case 0x65e710:p.cancel_action(a,s);break;
    case 0x660060:if(other)throw std::runtime_error("gauge mode");p.apply_progression(a,s,std::uint16_t(arg));break;
    case 0x6df160:p.refresh_statistics(a,s);break;
    case 0x6689e0:p.finish_contact_state(a,s);break;
    default:throw std::runtime_error("undeclared hit port "+std::to_string(c->pc));
    }
    write(r,a);write_session(r,s);c->pc=GPR_U32(c,31);
}
#include "original_hit.cpp"
std::uint32_t next(std::uint32_t& s){s^=s<<13;s^=s>>17;s^=s<<5;return s;}
int main()try{
    std::vector<std::uint8_t> ram(0x2000000,0xa5),expected(ram);std::uint32_t random=0x871dc1a3;std::uint64_t cases{},calls{};
    constexpr std::int16_t amounts[]{500,300,1000};for(std::uint32_t i=0;i<3;++i)put(ram.data(),0x71ada0+2*i,amounts[i]);
    constexpr std::uint8_t motions[]{0,1,0x0b,0x1a,0x27,0x28,0x30,0x31,0xa0};
    constexpr std::uint8_t seconds[]{0,0x0b,0x16,0x24,0x47,0xc5,0xc8};
    constexpr std::uint8_t kinds[]{0,1,9,0x0f,0x10,0x7f,0x80,0xff};
    constexpr std::int16_t health[]{-32768,-1,0,1,2,5,100,32767};
    constexpr std::int32_t damage[]{-65536,-1,0,1,7,32767,32768,65535,65536,INT32_MAX};
    for(std::uint32_t seed=0;seed<131072;++seed){
        g::HitActor a;a.current=health[seed%8];a.maximum=std::int16_t(10+seed%2000);a.status=next(random);if(seed&1)a.status=(seed/2)%512;
        a.auxiliary_status=next(random);a.room=std::uint16_t(seed%3);a.category=std::uint8_t((seed/4)%4);a.slot=std::uint8_t((seed/16)%4);a.class_marker=19;
        a.primary=std::uint8_t((seed/3)%6);a.secondary=seconds[(seed/8)%7];a.phase=29;a.subphase=30;a.motion_class=motions[(seed/4)%9];a.response_class=std::uint8_t(seed%3);
        a.damage_interval_one=13;a.damage_interval_two=14;a.status_duration=15;a.recovery_timer=std::uint16_t(next(random));
        a.damage_word=damage[(seed/7)%10];a.progression_amount=std::uint16_t(seed%3);a.pending_hit=std::uint8_t(seed%7);a.damage_kind=kinds[(seed/2)%8];
        a.response_flags=std::uint8_t(seed/11);a.notice_flags=std::uint8_t(next(random));a.source_kind=std::uint8_t((seed/2)%3);a.source_slot=std::uint8_t((seed/3)%8);
        a.special_kind=std::uint8_t((seed/6)%3);a.response_lock=std::uint8_t((seed/13)%2);a.transient_contact=71;a.transient_action=72;a.transient_equipment=73;
        a.interaction_slot=std::uint8_t((seed/19)%16);a.equipment_slot=std::uint8_t((seed/17)%16);
        g::HitSession s;s.selected_actor=std::uint8_t((seed/4)%4);s.room=std::uint16_t((seed/3)%3);s.authority_filter=seed&16;s.paused=seed%17==0;
        s.suppress_hits=seed%19==0;s.contact_recorded=std::uint8_t(seed%4);s.mode=std::uint8_t(seed%4);s.session_state=0;
        Ports native;native.seed=seed;native.current=&a;native.relations.fill(0x67);
        for(std::uint32_t i=0;i<8;++i){native.partner_status[i]=next(random);native.characters[i]=std::uint8_t(next(random));put(ram.data(),base+0x10e0*i+0xba0,native.partner_status[i]);ram[base+0x10e0*i+0xb98]=native.characters[i];}
        for(std::uint32_t i=0;i<16;++i){native.owners[i]=std::uint16_t((seed+i)%9);put(ram.data(),0x3c5658+60*i,native.owners[i]);}
        a.control_elapsed=0x6789abcd;write(ram.data(),a);write_session(ram.data(),s);std::copy(native.relations.begin(),native.relations.end(),ram.begin()+base+0xb1c);
        Ports original=native;original_ports=&original;g::consume_pending_hit(a,s,native,amounts);
        write(expected.data(),a);write_session(expected.data(),s);std::copy(native.relations.begin(),native.relations.end(),expected.begin()+base+0xb1c);expected[base+0xb98]=native.characters[0];
        PS2Runtime runtime;runtime.port=&original_port;R5900Context ctx;ctx.r[4][0]=base;ctx.r[29][0]=0x1f00000;ctx.r[31][0]=0xdead0000;
        o2_00660AF0_0x660af0(ram.data(),&ctx,&runtime);
        if(native.trace!=original.trace || ctx.pc!=0xdead0000 || ctx.r[29][0]!=0x1f00000 || ram[0x3b84f4]!=expected[0x3b84f4] || !std::equal(ram.begin()+base,ram.begin()+base+0x10e0,expected.begin()+base)){
            std::cerr<<"seed="<<seed<<" native_trace="<<native.trace.size()<<" original_trace="<<original.trace.size()<<'\n';
            for(std::size_t i=0;i<std::min(native.trace.size(),original.trace.size());++i)if(native.trace[i]!=original.trace[i]){std::cerr<<"trace="<<i<<" native="<<native.trace[i]<<" original="<<original.trace[i]<<'\n';break;}
            unsigned shown{};for(std::uint32_t at=base;at<base+0x10e0&&shown<12;++at)if(ram[at]!=expected[at]){std::cerr<<"offset="<<std::hex<<at-base<<" actual="<<unsigned(ram[at])<<" expected="<<unsigned(expected[at])<<std::dec<<'\n';++shown;}
            throw std::runtime_error("pending hit original comparison");
        }
        ++cases;calls+=native.trace.size();
    }
    g::HitActor refused;refused.pending_hit=1;refused.status=0x80;refused.response_class=3;g::HitSession session;Ports p;p.current=&refused;bool invalid{};
    try{g::consume_pending_hit(refused,session,p,amounts);}catch(const std::out_of_range&){invalid=true;}
    if(!invalid || refused.pending_hit || !(refused.notice_flags&1))throw std::runtime_error("unadmitted timer consume policy");
    std::cout<<"{\"cases\":"<<cases<<",\"ordered_trace_words\":"<<calls<<",\"invalid_timer_case\":true,\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
