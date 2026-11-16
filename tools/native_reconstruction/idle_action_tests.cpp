#include "game/native/gameplay_world/idle_action.hpp"
#include "game/native/animation/model.hpp"
#include <cstdio>
#include <vector>
namespace w=reo::native::gameplay_world;
namespace a=reo::native::animation;
namespace {
constexpr std::uint32_t actor_at=0x10000,done=0x1234;
unsigned checks{},cases{},calls{};std::int8_t tick_result{};bool mutate_tick{};
std::vector<std::uint32_t> original_events,native_events;
void check(bool value){++checks;if(!value)throw std::runtime_error("idle check "+std::to_string(checks)+" case "+std::to_string(cases));}
void original_port(std::uint8_t* ram,R5900Context* c,PS2Runtime*){
    ++calls;check(GPR_U32(c,4)==actor_at);
    original_events.push_back(c->pc);
    switch(c->pc){
    case 0x5d4cf0:
        original_events.insert(original_events.end(),{GPR_U32(c,5),std::bit_cast<std::uint32_t>(c->f[12]),std::bit_cast<std::uint32_t>(c->f[13])});
        ref_write(ram,actor_at+0x520,std::int16_t(0x2001));break;
    case 0x58c7b0:break;
    case 0x58c300:
        original_events.push_back(std::bit_cast<std::uint32_t>(c->f[12]));
        if(mutate_tick){ram[actor_at+10]=5;ref_write(ram,actor_at+0x520,std::int16_t(0x2001));}
        SET_GPR_S32(c,2,tick_result);break;
    default:throw std::runtime_error("Undeclared original idle boundary");
    }
    c->pc=GPR_U32(c,31);
}
struct Animation final:w::ActionAnimation {
    void select(w::Actor& actor,std::uint32_t motion,float initial,float blend)override{
        native_events.insert(native_events.end(),{0x5d4cf0,motion,std::bit_cast<std::uint32_t>(initial),std::bit_cast<std::uint32_t>(blend)});
        actor.animation->motion=0x2001;
    }
    void activate(w::Actor&)override{native_events.push_back(0x58c7b0);}
    std::int8_t tick(w::Actor& actor,float step)override{
        native_events.insert(native_events.end(),{0x58c300,std::bit_cast<std::uint32_t>(step)});
        if(mutate_tick){actor.phase=5;actor.animation->motion=0x2001;}
        return tick_result;
    }
};
template<class T>void compare(const std::vector<std::uint8_t>& ram,unsigned offset,const T& value){check(std::memcmp(ram.data()+actor_at+offset,&value,sizeof value)==0);}
}
PS2Runtime::Fn PS2Runtime::lookupFunction(std::uint32_t address)const{
    switch(address){
    case 0x6673c0:return o2_006673C0_0x6673c0;
    case 0x64f690:return o2_0064F690_0x64f690;
    case 0x65fab0:return o2_0065FAB0_0x65fab0;
    case 0x667370:return o2_00667370_0x667370;
    case 0x6673a0:return o2_006673A0_0x6673a0;
    case 0x5d4cf0:case 0x58c7b0:case 0x58c300:return original_port;
    default:throw std::runtime_error("Unknown original idle dependency "+std::to_string(address));
    }
}
int main()try{
    std::vector<std::uint8_t> ram(0x800000);
    std::vector<std::byte> skeleton(112);
    auto put=[&]<class T>(unsigned at,T value){std::memcpy(skeleton.data()+at,&value,sizeof value);};
    put(4,2u);put(8,112u);put(16,1u);put(20,16u);put(28,1u);put(32,1u);put(36,84u);put(48,-1);put(52,-1);
    const auto definition=a::Skeleton::import_raw(skeleton);
    ref_write(ram.data(),0x71b030,50.f);ref_write(ram.data(),0x71b034,25.f);
    ref_write(ram.data(),0x712c50,0x66b990u);
    Animation animation;PS2Runtime runtime;
    auto run=[&](unsigned phase,unsigned variant){
        ++cases;std::fill_n(ram.data()+actor_at,0x1100,0);
        w::Actor actor;actor.category=0;actor.primary=1;actor.secondary=0;actor.phase=std::uint8_t(phase);actor.subphase=43;
        actor.status=std::array<unsigned,4>{0,2,8,0x80}[variant%4]|0x200;
        actor.current=std::array<std::int16_t,8>{-1,0,24,25,49,50,99,100}[(variant/4)%8];actor.maximum=100;
        actor.class_marker=17;actor.previous_motion_class=std::uint8_t((variant/32)%5);
        actor.action_flags=0xa5a5;actor.contact_flags=0x40;actor.motion_class=0xaa;
        actor.auxiliary_status=std::array<unsigned,4>{0,4,0x80,0x84}[(variant/160)%4]|0x30000000;
        actor.locomotion=w::PrimaryLocomotionState{{3,4,5},99};actor.motion_rate=.5f;
        actor.saved_action_position={5,6,7};actor.saved_action_yaw=-123;actor.position={10,20,30};actor.orientation[1]=1257;
        actor.model=std::make_shared<a::Instance>(definition);actor.animation=std::make_shared<a::Playback>(actor.model);actor.animation->motion=(variant&1)?0x2001:0x2040;
        auto p=[&]<class T>(unsigned at,const T& value){ref_write(ram.data(),actor_at+at,value);};
        p(2,actor.category);p(8,actor.primary);p(9,actor.secondary);p(10,actor.phase);p(11,actor.subphase);
        p(0xba0,actor.status);p(0xba4,actor.auxiliary_status);p(0x544,actor.current);p(0x546,actor.maximum);p(0xb9b,actor.class_marker);p(0xb9c,actor.previous_motion_class);
        p(0x548,actor.action_flags);p(0x54a,actor.contact_flags);p(0x54f,actor.motion_class);p(0xc0,actor.locomotion->velocity);p(0xd10,actor.locomotion->marker);
        p(0xba8,actor.motion_rate);p(0xd94,actor.saved_action_position);p(0xda0,actor.saved_action_yaw);p(0x38,actor.position);p(0x92,actor.orientation[1]);p(0x520,actor.animation->motion);
        tick_result=std::array<std::int8_t,4>{-1,0,1,2}[(variant/640)%4];mutate_tick=(variant&0x1000)!=0;
        original_events.clear();native_events.clear();R5900Context c{};c.g[4].lo=actor_at;c.g[29].lo=0x30000;c.g[31].lo=done;
        o2_0066B960_0x66b960(ram.data(),&c,&runtime);check(c.pc==done);
        actor.status&=~0x200u;w::update_idle_action(actor,animation);check(original_events==native_events);
        compare(ram,8,actor.primary);compare(ram,9,actor.secondary);compare(ram,10,actor.phase);compare(ram,11,actor.subphase);
        compare(ram,0xba0,actor.status);compare(ram,0xba4,actor.auxiliary_status);compare(ram,0xb9b,actor.class_marker);compare(ram,0xb9c,actor.previous_motion_class);
        compare(ram,0x548,actor.action_flags);compare(ram,0x54a,actor.contact_flags);compare(ram,0x54f,actor.motion_class);compare(ram,0xc0,actor.locomotion->velocity);compare(ram,0xd10,actor.locomotion->marker);
        compare(ram,0xba8,actor.motion_rate);compare(ram,0xd94,actor.saved_action_position);compare(ram,0xda0,actor.saved_action_yaw);compare(ram,0x520,actor.animation->motion);
    };
    for(unsigned phase=0;phase<256;++phase)for(unsigned variant:{0u,100u,512u,2000u})run(phase,variant);
    for(unsigned phase:{0u,1u,10u,11u,255u})for(unsigned variant=0;variant<2560;++variant)run(phase,variant);
    for(unsigned variant=0;variant<2560;++variant)run(10,variant|0x1000);
    std::printf("{\"checks\":%u,\"cases\":%u,\"animation_boundary_calls\":%u,\"game_run\":false}\n",checks,cases,calls);
}catch(const std::exception& e){std::fprintf(stderr,"%s\n",e.what());return 1;}
