#include "game/native/gameplay_world/behavior.hpp"
#include "hit_fixture.hpp"
#include <algorithm>
#include <string>
namespace gw=reo::native::gameplay_world;

gw::Actor read_actor(const std::uint8_t* r){
    gw::Actor a;static_cast<g::HitActor&>(a)=read(r);
    a.position=get<gw::Position>(r,base+0x38);a.previous_position=get<gw::Position>(r,base+0x44);
    a.orientation=get<std::array<std::int16_t,4>>(r,base+0x90);a.previous_orientation=get<std::array<std::int16_t,4>>(r,base+0xa0);
    a.saved_action_position=get<gw::Position>(r,base+0xd94);a.saved_action_yaw=get<std::int16_t>(r,base+0xda0);
    a.action_elapsed=get<std::uint32_t>(r,base+0xd2c);a.control_elapsed=get<std::uint32_t>(r,base+0xd28);return a;
}
void write_actor(std::uint8_t* r,const gw::Actor& a){
    write(r,a);put(r,base+0x38,a.position);put(r,base+0x44,a.previous_position);
    put(r,base+0x90,a.orientation);put(r,base+0xa0,a.previous_orientation);
    put(r,base+0xd94,a.saved_action_position);put(r,base+0xda0,a.saved_action_yaw);
    put(r,base+0xd2c,a.action_elapsed);put(r,base+0xd28,a.control_elapsed);
}
void read_world(std::uint8_t* r,gw::World& w){
    static_cast<g::HitSession&>(w.session())=read_session(r);
    w.session().previous_primary=r[0x744648];w.session().previous_secondary=r[0x744640];
    w.session().inventory_owner=r[0x4badee];
    w.session().random.restore({get<std::uint16_t>(r,0x234ba8),get<std::uint16_t>(r,0x234baa),r[0x234bac]});
}
void write_world(std::uint8_t* r,const gw::World& w){
    const auto& s=w.session();write_session(r,s);r[0x744648]=s.previous_primary;r[0x744640]=s.previous_secondary;r[0x4badee]=s.inventory_owner;
    const auto rng=s.random.state();put(r,0x234ba8,rng.primary);put(r,0x234baa,rng.secondary);r[0x234bac]=rng.observed;
}
struct BehaviorPorts final:gw::BehaviorServices {
    Ports core;
    // Independent original-address mapping, not shared with the native switch.
    void run(gw::BehaviorStage stage,gw::World& w,gw::Actor& a)override{
        constexpr std::uint32_t calls[]{0x666580,0x666450,0x5f4f00,0x667420,0x668740,0x6687a0,0x64ae50,0x6621f0,0x64f7b0,0x64f110,0x664f60,0x5d6a60,0x5d6ed0};
        const auto at=calls[static_cast<std::size_t>(stage)];core.log(at,a);
        if(stage==gw::BehaviorStage::sample_surface)a.position.y+=float(core.seed%8);
        if(stage==gw::BehaviorStage::resolve_surface){a.position.x-=1;a.orientation[1]=std::int16_t(core.seed);}
        if(stage==gw::BehaviorStage::prepare_inventory && core.seed%7==0)a.primary=3;
        if(stage==gw::BehaviorStage::progression && core.seed%11==0)a.category=1;
        if(stage==gw::BehaviorStage::interaction && core.seed%13==0)w.session().authority_filter=!w.session().authority_filter;
        if(stage==gw::BehaviorStage::terminal_timer && core.seed%17==0)a.category=0;
        if(stage==gw::BehaviorStage::cooperation && core.seed%19==0)w.session().inventory_owner=std::uint8_t(1+core.seed%4);
        if(stage==gw::BehaviorStage::consume_control_request)a.secondary=7;
        if(stage==gw::BehaviorStage::update_attachment && core.seed%3==0)a.status^=0x80;
    }
    void dispatch(gw::ActionPass pass,std::uint8_t index,gw::World& w,gw::Actor& a)override{
        if(index>12)throw std::runtime_error("Unsupported fixture action");
        core.log(pass==gw::ActionPass::primary?0x100:0x200,a,index);
        if(pass==gw::ActionPass::primary){
            if(core.seed%3==0)a.primary=std::uint8_t((a.primary+1)%6);
            if(core.seed%5==0)a.secondary=std::uint8_t(a.secondary+1);
            if(core.seed%7==0)a.phase=0xff;
            if(core.seed%11==0)w.session().previous_primary=9;
        }else{a.auxiliary_status^=0x100400;if(core.seed%5==0)a.response_lock=1;}
    }
    bool suppress_action_notice(gw::World&,gw::Actor& a,std::uint8_t previous,std::uint8_t secondary)override{
        core.log(0x6651f0,a,previous,secondary);return core.seed%2;
    }
    bool authority_filter(g::HealthSession& arg0)override{return core.authority_filter(arg0);}
    std::int32_t selected_authority(g::HealthSession& arg0,std::uint8_t arg1)override{return core.selected_authority(arg0,arg1);}
    void refresh_class(g::HealthState& arg0,g::HealthSession& arg1)override{core.refresh_class(arg0,arg1);}
    void feedback(g::StatusActor& arg0,g::StatusSession& arg1,std::uint8_t arg2)override{core.feedback(arg0,arg1,arg2);}
    void publish(g::StatusActor& arg0,g::StatusSession& arg1,std::uint8_t arg2)override{core.publish(arg0,arg1,arg2);}
    void cleanup(g::StatusActor& arg0,g::StatusSession& arg1)override{core.cleanup(arg0,arg1);}
    void recover(g::StatusActor& arg0,g::StatusSession& arg1)override{core.recover(arg0,arg1);}
    void snapshot(g::StatusActor& arg0,g::StatusSession& arg1)override{core.snapshot(arg0,arg1);}
    bool locally_controlled(g::HitActor& arg0,g::HitSession& arg1)override{return core.locally_controlled(arg0,arg1);}
    std::uint32_t partner_flags(std::uint8_t arg0)override{return core.partner_flags(arg0);}
    std::uint8_t partner_character(std::uint8_t arg0)override{return core.partner_character(arg0);}
    std::uint16_t scene_owner(std::uint8_t arg0)override{return core.scene_owner(arg0);}
    void event(g::HitActor& arg0,g::HitSession& arg1,std::uint32_t arg2,std::uint32_t arg3)override{core.event(arg0,arg1,arg2,arg3);}
    void add_status(g::HitActor& arg0,g::HitSession& arg1,std::uint8_t arg2)override{core.add_status(arg0,arg1,arg2);}
    void close_inventory(g::HitActor& arg0,g::HitSession& arg1)override{core.close_inventory(arg0,arg1);}
    void detach_scene(g::HitActor& arg0,g::HitSession& arg1,std::uint8_t arg2,std::uint8_t arg3)override{core.detach_scene(arg0,arg1,arg2,arg3);}
    void release_equipment(g::HitActor& arg0,g::HitSession& arg1,std::uint8_t arg2)override{core.release_equipment(arg0,arg1,arg2);}
    void cancel_action(g::HitActor& arg0,g::HitSession& arg1)override{core.cancel_action(arg0,arg1);}
    void clear_owner_interaction(g::HitActor& arg0,g::HitSession& arg1)override{core.clear_owner_interaction(arg0,arg1);}
    void apply_progression(g::HitActor& arg0,g::HitSession& arg1,std::uint16_t arg2)override{core.apply_progression(arg0,arg1,arg2);}
    void refresh_statistics(g::HitActor& arg0,g::HitSession& arg1)override{core.refresh_statistics(arg0,arg1);}
    void finish_contact_state(g::HitActor& arg0,g::HitSession& arg1)override{core.finish_contact_state(arg0,arg1);}
    void clear_hit_relations(g::HitActor& arg0,g::HitSession& arg1)override{core.clear_hit_relations(arg0,arg1);}
};

void o2_00666D60_0x666d60(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_00666DB0_0x666db0(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_00667370_0x667370(std::uint8_t*,R5900Context*,PS2Runtime*);
void sub_001B0310_0x1b0310(std::uint8_t*,R5900Context*,PS2Runtime*);
BehaviorPorts* original_ports{};gw::World* reference_world{};
constexpr std::int16_t timer_amounts[]{500,300,1000};
void original_port(std::uint8_t* r,R5900Context* c,PS2Runtime* runtime){
    switch(c->pc){
    case 0x666d60:o2_00666D60_0x666d60(r,c,runtime);return;
    case 0x666db0:o2_00666DB0_0x666db0(r,c,runtime);return;
    case 0x667370:o2_00667370_0x667370(r,c,runtime);return;
    case 0x1b0310:sub_001B0310_0x1b0310(r,c,runtime);return;
    default:break;
    }
    auto a=read_actor(r);auto& w=*reference_world;read_world(r,w);auto& p=*original_ports;p.core.current=&a;
    const auto at=c->pc;bool found=false;
    constexpr std::uint32_t calls[]{0x666580,0x666450,0x5f4f00,0x667420,0x668740,0x6687a0,0x64ae50,0x6621f0,0x64f7b0,0x64f110,0x664f60,0x5d6a60,0x5d6ed0};
    for(std::size_t i=0;i<std::size(calls);++i)if(at==calls[i]){
        if(at==0x5d6a60 && c->f[12]!=1)throw std::runtime_error("Attachment scale ABI");
        if(at==0x5d6ed0 && GPR_U32(c,5)!=3)throw std::runtime_error("Terminal attachment ABI");
        p.run(gw::BehaviorStage(i),w,a);found=true;break;
    }
    if(!found)switch(at){
    case 0x660310:g::tick_status(a,w.session(),p,w.session().random);break;
    case 0x6607d0:g::select_zero_health_action(a,w.session(),p);break;
    case 0x660af0:g::consume_pending_hit(a,w.session(),p,timer_amounts);break;
    case 0x1b0340:SET_GPR_U32(c,2,p.locally_controlled(a,w.session()));break;
    case 0x6651f0:SET_GPR_U32(c,2,p.suppress_action_notice(w,a,std::uint8_t(GPR_U32(c,5)),std::uint8_t(GPR_U32(c,6))));break;
    case 0x67e230:p.publish(a,w.session(),std::uint8_t(GPR_U32(c,5)));break;
    case 0x100000:case 0x200000:p.dispatch(at==0x100000?gw::ActionPass::primary:gw::ActionPass::secondary,a.primary,w,a);break;
    default:throw std::runtime_error("Undeclared original behavior port "+std::to_string(at));
    }
    write_actor(r,a);write_world(r,w);c->pc=GPR_U32(c,31);
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#include "original_behavior.cpp"
#pragma GCC diagnostic pop
std::uint32_t next(std::uint32_t& s){s^=s<<13;s^=s>>17;s^=s<<5;return s;}
struct FramePorts final:gw::Services {
    unsigned forwarded{},behavior_forwarded{};
    void begin_offline_frame(gw::World&)override{++forwarded;}
    void run(gw::Stage stage,gw::World&,gw::Actor&)override{++forwarded;if(stage==gw::Stage::update_behavior)++behavior_forwarded;}
    bool remote_motion(gw::World&,gw::Actor&)override{++forwarded;return false;}
    bool find_grid(gw::World&,gw::Actor&,std::int8_t&)override{++forwarded;return false;}
    void switch_grid(gw::World&,std::int32_t,std::int32_t)override{++forwarded;}
    float grid_response(gw::World&,std::uint8_t)override{++forwarded;return 0;}
};
int main()try{
    std::vector<std::uint8_t> ram(0x2000000,0xa5),expected(ram);std::uint32_t random=0x917dc1a3;std::uint64_t cases{},trace_words{};
    gw::Profile profile;profile.layouts.resize(1);
    gw::World w(profile,std::make_shared<gw::Session>()),reference(profile,std::make_shared<gw::Session>());reference_world=&reference;
    // Dispatch destinations are declared providers: distinct fake targets let
    // us verify which table/pass is used without claiming action-body coverage.
    for(unsigned i=0;i<16;++i){put(ram.data(),0x712bd0+4*i,0x100000u);put(ram.data(),0x712c10+4*i,0x200000u);}
    for(std::uint32_t seed=0;seed<32768;++seed){
        gw::Actor a;a.current=std::int16_t(100+seed%1000);a.maximum=2000;a.status=next(random)&~std::uint32_t(0x1b);
        a.auxiliary_status=next(random);a.room=std::uint16_t(seed%3);a.category=std::uint8_t((seed/4)%4);a.slot=std::uint8_t((seed/16)%4);
        a.primary=std::uint8_t((seed/3)%6);a.secondary=std::uint8_t(seed%256);a.phase=seed%5?std::uint8_t(seed):0xff;
        a.subphase=19;a.motion_class=0;a.response_lock=std::uint8_t(seed%2);a.pending_hit=0;
        a.position={float(seed%100),float(seed%40),float(seed%50)};a.previous_position={-1,-2,-3};
        a.saved_action_position={-13,-14,-15};a.saved_action_yaw=-300;
        a.orientation={1,2,3,4};a.previous_orientation={-1,-2,-3,-4};
        a.action_elapsed=seed%5?seed:UINT32_MAX;a.control_elapsed=seed%7?UINT32_MAX-1:UINT32_MAX;
        auto& s=w.session();s=gw::Session{};s.mode=std::uint8_t(seed%3);s.room=std::uint16_t((seed/8)%3);
        s.selected_actor=std::uint8_t((seed/7)%4);s.authority_filter=seed%2;s.paused=seed%7==0;s.clock_mode=std::uint8_t(seed%2);
        s.inventory_owner=std::uint8_t(seed/3);s.previous_primary=17;s.previous_secondary=18;s.random.restore({std::uint16_t(seed),23,17});
        write_actor(ram.data(),a);write_world(ram.data(),w);std::copy(ram.begin()+base,ram.begin()+base+0x10e0,expected.begin()+base);
        // Reset the bounded observed ranges, retaining guard bytes elsewhere.
        std::copy(ram.begin()+0x234ba0,ram.begin()+0x234bb0,expected.begin()+0x234ba0);
        std::copy(ram.begin()+0x324000,ram.begin()+0x324500,expected.begin()+0x324000);
        std::copy(ram.begin()+0x4bad00,ram.begin()+0x4baf00,expected.begin()+0x4bad00);
        std::copy(ram.begin()+0x744600,ram.begin()+0x744700,expected.begin()+0x744600);
        BehaviorPorts native,original;native.core.seed=original.core.seed=seed;native.core.current=&a;original_ports=&original;
        R5900Context ctx;ctx.pc=0x66b500;SET_GPR_U32(&ctx,4,base);SET_GPR_U32(&ctx,29,0x1ff0000);SET_GPR_U32(&ctx,31,0x123456);PS2Runtime rt;rt.port=original_port;
        o2_0066B500_0x66b500(ram.data(),&ctx,&rt);
        gw::update_behavior(w,a,native,timer_amounts);write_actor(expected.data(),a);write_world(expected.data(),w);
        if(ctx.pc!=0x123456 || native.core.trace!=original.core.trace)throw std::runtime_error("Behavior trace/return seed "+std::to_string(seed));
        for(auto [begin,count]:{std::pair{base,0x10e0u},{0x234ba0u,0x10u},{0x324000u,0x500u},{0x4bad00u,0x200u},{0x744600u,0x100u}})
            for(std::uint32_t i=begin;i<begin+count;++i)if(ram[i]!=expected[i])throw std::runtime_error("Behavior state seed "+std::to_string(seed)+" at "+std::to_string(i));
        ++cases;trace_words+=native.core.trace.size();
    }
    gw::World composed(profile,std::make_shared<gw::Session>());composed.mode=1;
    auto owned=std::make_unique<gw::Actor>();owned->active=true;owned->category=0;owned->primary=1;owned->current=owned->maximum=100;
    if(composed.spawn_primary(0,std::move(owned)).status!=g::EntityStatus::completed)throw std::runtime_error("Composition actor creation");
    auto actor=composed.primary(0);BehaviorPorts behavior;behavior.core.current=actor.get();behavior.core.seed=23;FramePorts frame;
    const reo::native::gameplay_collision::response::Grid floors{};
    gw::BehaviorFrameServices composed_ports(frame,behavior,floors,timer_amounts);
    const auto result=composed.update_primary(composed_ports);
    if(result.status!=gw::Status::completed || result.updated!=1 || frame.behavior_forwarded || frame.forwarded!=9 || actor->action_elapsed!=1 || actor->control_elapsed!=1 || behavior.core.trace.empty())
        throw std::runtime_error("Native frame/behavior composition");
    std::cout<<"{\"status\":\"passed\",\"cases\":"<<cases<<",\"trace_words\":"<<trace_words<<"}\n";
    return 0;
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
