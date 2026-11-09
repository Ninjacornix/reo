#include "game/native/gameplay_world/motion.hpp"
#include "runtime.hpp"
#include <algorithm>
#include <bit>
#include <iostream>
#include <vector>
namespace g=reo::native::gameplay_world;
constexpr std::uint32_t base=0x10000,target=0x20000,stack=0x30000,queue=0x3b53c0,count_at=0x3b53b0;
std::uint64_t checks{},snapshot_cases{},shape_cases{},finish_cases{},enqueue_calls{},native_cases{};
void check(bool yes,const char* why){++checks;if(!yes)throw std::runtime_error(why);}
template<class T>T get(const std::uint8_t* p,std::uint32_t at){return oracle_read<T>(p,at);}
template<class T>void put(std::uint8_t* p,std::uint32_t at,T value){oracle_write<T>(p,at,value);}
std::uint32_t random_word(std::uint32_t& state){state^=state<<13;state^=state>>17;state^=state<<5;return state;}
g::Profile profile(){return{{g::input::Remap{0x100,0x20,0x10}},4,{16,UINT64_MAX}};}
struct Entry {std::uint16_t second{},first{};std::uint32_t actor{};bool operator==(const Entry&)const=default;};
static_assert(sizeof(Entry)==8);
struct Ports final:g::MotionServices {
    std::array<Entry,32> records{};std::uint16_t count{};std::uint32_t calls{};g::Actor* expected{};bool reject{};
    void enqueue(g::World&,g::Actor& actor,std::uint16_t one,std::uint16_t two)override{
        check(&actor==expected,"finish provider receives canonical actor identity");++calls;
        if(reject){actor.position.x=97.5f;throw std::runtime_error("required queue owner unavailable");}
        if(count<records.size())records[count++]={two,one,base};
    }
};
g::Actor import_actor(const std::uint8_t* p){
    g::Actor a;a.position=get<g::Position>(p,base+0x38);a.previous_position=get<g::Position>(p,base+0x44);
    a.orientation=get<std::array<std::int16_t,4>>(p,base+0x90);a.previous_orientation=get<std::array<std::int16_t,4>>(p,base+0xa0);
    a.saved_action_position=get<g::Position>(p,base+0xd94);a.saved_action_yaw=get<std::int16_t>(p,base+0xda0);
    a.category=p[base+2];a.slot=p[base+3];a.contact_flags=get<std::uint16_t>(p,base+0x54a);
    auto& c=a.collision;c.local_center=get<reo::native::gameplay_collision::Vec3>(p,base+0x1ac);c.radius=get<float>(p,base+0x1b8);
    c.previous_local_center=get<reo::native::gameplay_collision::Vec3>(p,base+0x1bc);c.previous_radius=get<float>(p,base+0x1c8);
    c.previous_center_offset=get<reo::native::gameplay_collision::Vec3>(p,base+0x1cc);c.interpolation_step=get<reo::native::gameplay_collision::Vec3>(p,base+0xcc8);
    c.interpolation_ticks=p[base+0xcb2];c.interpolation_target=g::CollisionShapeTarget{get<reo::native::gameplay_collision::Vec3>(p,target),get<float>(p,target+12)};
    return a;
}
void export_actor(std::uint8_t* p,const g::Actor& a){
    put(p,base+0x38,a.position);put(p,base+0x44,a.previous_position);put(p,base+0x90,a.orientation);put(p,base+0xa0,a.previous_orientation);
    put(p,base+0xd94,a.saved_action_position);put(p,base+0xda0,a.saved_action_yaw);put(p,base+2,a.category);put(p,base+3,a.slot);put(p,base+0x54a,a.contact_flags);
    const auto& c=a.collision;put(p,base+0x1ac,c.local_center);put(p,base+0x1b8,c.radius);put(p,base+0x1bc,c.previous_local_center);put(p,base+0x1c8,c.previous_radius);
    put(p,base+0x1cc,c.previous_center_offset);put(p,base+0xcc8,c.interpolation_step);put(p,base+0xcb2,c.interpolation_ticks);
}
void o2_00667370_0x667370(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_0065E670_0x65e670(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_0065E5C0_0x65e5c0(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_005DA620_0x5da620(std::uint8_t*,R5900Context*,PS2Runtime*);
void sub_001B02D0_0x1b02d0(std::uint8_t*,R5900Context*,PS2Runtime*);
std::uint32_t original_enqueues{};
void original_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    if(context->pc==0x1b02d0){sub_001B02D0_0x1b02d0(memory,context,runtime);return;}
    // Exact three-word original getter at1B0300..1B030B; other merged entries
    // in its generated source are not executed by this comparison.
    if(context->pc==0x1b0300){SET_GPR_U32(context,2,memory[0x3243f2]);return;}
    if(context->pc==0x5da620){++original_enqueues;o2_005DA620_0x5da620(memory,context,runtime);return;}
    throw std::runtime_error("undeclared original motion provider");
}
#include "original_motion.cpp"

void execute(std::uint8_t* ram,std::uint32_t entry){
    R5900Context context;context.pc=entry;SET_GPR_U32(&context,4,base);SET_GPR_U32(&context,29,stack);SET_GPR_U32(&context,31,0xabcdef);
    PS2Runtime runtime;runtime.port=original_port;
    if(entry==0x667370)o2_00667370_0x667370(ram,&context,&runtime);
    else if(entry==0x65e670)o2_0065E670_0x65e670(ram,&context,&runtime);
    else o2_0065E5C0_0x65e5c0(ram,&context,&runtime);
    check(context.pc==0xabcdef,"original motion returns synchronously");
    if(entry==0x65e5c0)check(GPR_U32(&context,29)==stack,"original finish restores its stack");
}
void compare_actor(const std::uint8_t* actual,const std::uint8_t* expected){check(std::memcmp(actual+base,expected+base,0x10e0)==0,"full actor projection differs from executed original");}
struct FramePorts final:g::Services {
    unsigned delegated{},before{},after{};g::Actor* expected{};
    void begin_offline_frame(g::World&)override{++before;}
    void run(g::Stage,g::World&,g::Actor& actor)override{check(&actor==expected,"frame forwarding retains canonical identity");++delegated;}
    bool remote_motion(g::World&,g::Actor&)override{return false;}
    bool find_grid(g::World&,g::Actor&,std::int8_t&)override{++after;return false;}
    void switch_grid(g::World&,std::int32_t,std::int32_t)override{}
    float grid_response(g::World&,std::uint8_t)override{return 0;}
};
int main()try{
    std::vector<std::uint8_t> actual(0x2000000,0xa5),expected(actual);std::uint32_t random=0x65e670;
    g::World world(profile(),std::make_shared<g::Session>());
    for(unsigned i=0;i<4096;++i){
        for(unsigned n=0;n<0x10e0;n+=4)put(actual.data(),base+n,random_word(random));
        if(i<8)put(actual.data(),base+0x38,std::array<std::uint32_t,3>{0x80000000u,0x7f800001u,0xff800000u});
        std::copy_n(actual.data()+base,0x10e0,expected.data()+base);auto actor=import_actor(actual.data());
        g::save_action_pose(actor);export_actor(actual.data(),actor);execute(expected.data(),0x667370);compare_actor(actual.data(),expected.data());++snapshot_cases;
    }
    for(unsigned ticks=0;ticks<256;++ticks)for(unsigned variant=0;variant<16;++variant){
        for(unsigned n=0;n<0x10e0;n+=4)put(actual.data(),base+n,random_word(random));
        const auto number=[&]{return float(std::int32_t(random_word(random)%8193)-4096)*.125f;};
        put(actual.data(),base+0x1ac,std::array<float,3>{number(),number(),number()});put(actual.data(),base+0xcc8,std::array<float,3>{number(),number(),number()});
        put(actual.data(),target,std::array<float,4>{number(),number(),number(),number()});put(actual.data(),base+0xcb8,target);actual[base+0xcb2]=std::uint8_t(ticks);
        std::copy_n(actual.data()+base,0x10e0,expected.data()+base);std::copy_n(actual.data()+target,16,expected.data()+target);auto actor=import_actor(actual.data());
        check(g::advance_collision_shape(actor)==g::MotionStatus::completed,"admitted immutable interpolation target");export_actor(actual.data(),actor);execute(expected.data(),0x65e670);compare_actor(actual.data(),expected.data());++shape_cases;
    }
    const auto finish_case=[&](std::uint8_t pause,std::uint8_t mode,std::uint8_t category,bool same,bool disabled){
        std::fill_n(actual.data()+base,0x10e0,0xa5);actual[base+2]=category;actual[base+3]=39;
        put(actual.data(),base+0x54a,std::uint16_t(disabled?0x54a7:0x54a3));std::copy_n(actual.data()+base,0x10e0,expected.data()+base);
        expected[0x4badf8]=pause;expected[0x3243f2]=mode;expected[0x4baded]=same?39:40;
        world.paused=std::bit_cast<std::int8_t>(pause);world.mode=mode;world.selected_actor=same?39:40;
        Ports ports;ports.count=std::uint16_t(finish_cases%33);for(auto& record:ports.records)record={0xaaaa,0xbbbb,0xccccdddd};
        put(expected.data(),count_at,ports.count);put(expected.data(),queue,ports.records);auto actor=import_actor(actual.data());ports.expected=&actor;
        original_enqueues=0;g::finish_motion(world,actor,ports);export_actor(actual.data(),actor);execute(expected.data(),0x65e5c0);compare_actor(actual.data(),expected.data());
        check(ports.calls==original_enqueues,"mode/locality/category dispatch matches actual original predicate");check(ports.count==get<std::uint16_t>(expected.data(),count_at),"bounded original work count");
        check(ports.records==get<std::array<Entry,32>>(expected.data(),queue),"actual original tagged work records");enqueue_calls+=ports.calls;++finish_cases;
    };
    for(unsigned p=0;p<256;++p)for(auto mode:{0,1,2,255})for(auto category:{0,1,2,255})for(bool same:{false,true})for(bool disabled:{false,true})finish_case(std::uint8_t(p),std::uint8_t(mode),std::uint8_t(category),same,disabled);
    for(unsigned mode=0;mode<256;++mode)for(bool same:{false,true})finish_case(0,std::uint8_t(mode),0,same,false);
    g::Actor missing;missing.collision.local_center={1,2,3};missing.collision.radius=4;missing.collision.previous_center_offset={90,91,92};missing.collision.interpolation_ticks=1;
    check(g::advance_collision_shape(missing)==g::MotionStatus::shape_target_unavailable,"required target is not silently fabricated");
    check(missing.collision.interpolation_ticks==0 && missing.collision.previous_radius==4 && missing.collision.previous_local_center.x==1 && missing.collision.previous_center_offset.x==90,"missing-target retains ordered snapshot/decrement effects and separate world cache");++native_cases;
    missing.collision.interpolation_ticks=0;check(g::advance_collision_shape(missing)==g::MotionStatus::completed,"zero-counter needs no unused target");missing.collision.interpolation_ticks=2;check(g::advance_collision_shape(missing)==g::MotionStatus::completed,"nonfinal interpolation needs no unused target");++native_cases;
    Ports fail;fail.expected=&missing;fail.reject=true;world.paused=0;world.mode=0;missing.category=0;bool rejected{};
    try{g::finish_motion(world,missing,fail);}catch(const std::runtime_error&){rejected=true;}
    check(rejected && missing.position.x==97.5f,"required provider failure and prior callback effects propagate");++native_cases;
    g::World owned(profile(),std::make_shared<g::Session>());owned.room=7;owned.selected_actor=0;
    auto created=std::make_unique<g::Actor>();created->active=true;created->room=7;created->slot=0;created->collision.interpolation_ticks=2;created->collision.local_center={1,2,3};created->collision.interpolation_step={4,5,6};
    check(owned.spawn_primary(0,std::move(created)).status==g::actors::EntityStatus::completed,"canonical frame actor admitted");auto lease=owned.primary(0);FramePorts frame;frame.expected=lease.get();Ports motion;motion.expected=lease.get();g::MotionFrameServices adapter(frame,motion);
    const auto updated=owned.update_primary(adapter);check(updated.status==g::Status::completed && updated.updated==1,"real World consumes native auxiliary/finish policies");
    check(lease->collision.local_center.x==5 && lease->collision.interpolation_ticks==1 && motion.calls==1 && frame.after==1,"native shape/queue reaches later frame stages");++native_cases;
    lease->collision.interpolation_ticks=1;lease->collision.interpolation_target.reset();const auto before_queue=motion.calls;const auto after_before=frame.after;rejected=false;
    try{(void)owned.update_primary(adapter);}catch(const std::runtime_error&){rejected=true;}
    check(rejected && lease->collision.interpolation_ticks==0 && motion.calls==before_queue && frame.after==after_before,"missing native target stops later frame effects without legacy fallback");++native_cases;
    std::cout<<"{\"checks\":"<<checks<<",\"snapshot_cases\":"<<snapshot_cases<<",\"shape_cases\":"<<shape_cases<<",\"finish_cases\":"<<finish_cases<<",\"enqueue_calls\":"<<enqueue_calls<<",\"native_boundary_cases\":"<<native_cases<<",\"original_body_executed\":true,\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
