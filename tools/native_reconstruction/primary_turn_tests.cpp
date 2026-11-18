#include "game/native/gameplay_world/primary_turn.hpp"
#include "game/native/animation/model.hpp"
#include <fstream>
#include <cstdio>
#include <vector>
namespace w=reo::native::gameplay_world;
namespace a=reo::native::animation;
namespace {
constexpr unsigned actor_at=0x10000,done=0x1234;
unsigned checks{},cases{},variant{},entry{};
std::vector<unsigned> original_events,native_events;
void check(bool value){++checks;if(!value)throw std::runtime_error("turn check "+std::to_string(checks)+" case "+std::to_string(cases)+" entry "+std::to_string(entry)+" variant "+std::to_string(variant));}
void port(std::uint8_t* ram,R5900Context* c,PS2Runtime*){
    original_events.push_back(c->pc);
    switch(c->pc){
    case 0x5d4cf0:
        original_events.insert(original_events.end(),{GPR_U32(c,5),std::bit_cast<unsigned>(c->f[12]),std::bit_cast<unsigned>(c->f[13])});
        ref_write(ram,actor_at+0x520,std::int16_t(GPR_U32(c,5)));break;
    case 0x58c300:original_events.push_back(std::bit_cast<unsigned>(c->f[12]));ref_write(ram,actor_at+0x4e4,w::Position{13,14,15});SET_GPR_U32(c,2,0);break;
    case 0x58c7b0:case 0x58c7f0:break;
    case 0x5d4a10:original_events.insert(original_events.end(),{GPR_U32(c,5),GPR_U32(c,6)});c->f[0]=3.25f;break;
    default:throw std::runtime_error("Unknown turn boundary");
    }
    c->pc=GPR_U32(c,31);
}
struct Animation final:w::ActionAnimation {
    void select(w::Actor& actor,unsigned motion,float first,float blend)override{native_events.insert(native_events.end(),{0x5d4cf0,motion,std::bit_cast<unsigned>(first),std::bit_cast<unsigned>(blend)});actor.animation->motion=std::int16_t(motion);}
    void activate(w::Actor&)override{native_events.push_back(0x58c7b0);}
    void or_flags(w::Actor&)override{native_events.push_back(0x58c7f0);}
    float first_frame(w::Actor&,unsigned motion,std::uint16_t track)override{native_events.insert(native_events.end(),{0x5d4a10,motion,track});return 3.25f;}
    std::int8_t tick(w::Actor& actor,float step)override{native_events.insert(native_events.end(),{0x58c300,std::bit_cast<unsigned>(step)});actor.root_motion_delta={13,14,15};return 0;}
};
template<class T>void compare(const std::vector<std::uint8_t>& ram,unsigned offset,const T& value){check(std::memcmp(ram.data()+actor_at+offset,&value,sizeof value)==0);}
}
PS2Runtime::Fn PS2Runtime::lookupFunction(unsigned at)const{
    switch(at){
    case 0x1920a0:return sub_001920A0_0x1920a0;
    case 0x5d4cf0:case 0x58c300:case 0x58c7b0:case 0x58c7f0:case 0x5d4a10:return port;
    default:throw std::runtime_error("Unknown turn dependency "+std::to_string(at));
    }
}
int main(int argc,char** argv)try{
    check(argc==2);std::vector<std::uint8_t> ram(0x800000);
    std::ifstream image(argv[1],std::ios::binary);check(bool(image));image.read(reinterpret_cast<char*>(ram.data()+0x570000),0x800000-0x570000);
    check(image.gcount()>0x740640-0x570000);
    std::vector<std::byte> skeleton(112);
    auto put=[&]<class T>(unsigned at,T value){std::memcpy(skeleton.data()+at,&value,sizeof value);};
    put(4,2u);put(8,112u);put(16,1u);put(20,16u);put(28,1u);put(32,1u);put(36,84u);put(48,-1);put(52,-1);
    const auto definition=a::Skeleton::import_raw(skeleton);
    w::Profile profile;profile.layouts.push_back({0x100,0x10,0x20});w::World world(std::move(profile),std::make_shared<w::Session>());
    PS2Runtime runtime;Animation animation;
    auto run=[&](unsigned seed,bool action){
        ++cases;variant=seed;entry=action?0x66bb10:0x65f580;std::fill_n(ram.data()+actor_at,0x1100,0);
        w::Actor actor;actor.primary_state=w::PrimaryActorState{};
        actor.primary_state->initialization_marker=(seed&0x80000000u)?1:0;
        actor.motion_class=std::uint8_t(seed);actor.class_marker=std::uint8_t((seed>>8)%4);
        actor.status=std::array<unsigned,8>{0,8,0x10,0x20,0x80,0x2000,0x2080,0x2020}[(seed>>10)%8];
        actor.resource_action=std::uint16_t((seed>>13)%64);actor.character=std::uint8_t((seed>>19)%8);
        actor.motion_rate=std::array<float,5>{-1,0,.3f,1,1.2f}[(seed>>22)%5];
        world.session().clock_mode=std::uint8_t((seed>>25)%2);
        actor.primary=1;actor.secondary=std::uint8_t((seed>>15)%16);actor.phase=std::uint8_t(seed>>16);actor.subphase=44;
        actor.orientation[1]=std::bit_cast<std::int16_t>(std::uint16_t(seed));
        actor.analog_control=w::AnalogControlState{0,0,std::bit_cast<std::int16_t>(std::uint16_t(seed>>8))};
        actor.auxiliary_status=std::array<unsigned,4>{0,4,0x80,0x84}[(seed>>23)%4];actor.action_flags=0xa5a5;
        actor.locomotion=w::PrimaryLocomotionState{{3,4,5},99};actor.root_motion_delta={7,8,9};
        actor.position={10,20,30};actor.saved_action_position={1,2,3};actor.saved_action_yaw=-777;
        actor.model=std::make_shared<a::Instance>(definition);actor.animation=std::make_shared<a::Playback>(actor.model);
        actor.animation->motion=std::array<std::int16_t,3>{0x2001,0x2003,0x2004}[(seed>>5)%3];
        auto& timing=actor.animation->channel(a::ModelBank::primary,0).timing;timing.frame=float((seed>>7)%20);timing.restart=10;
        auto p=[&]<class T>(unsigned offset,T value){ref_write(ram.data(),actor_at+offset,value);};
        p(0xd90,actor.primary_state->initialization_marker);p(0xb9b,actor.class_marker);p(0xb98,actor.character);p(0xba0,actor.status);p(0x54f,actor.motion_class);
        p(0xca8,actor.resource_action);p(0xba8,actor.motion_rate);ram[0x3243cc]=world.session().clock_mode;
        p(8,actor.primary);p(9,actor.secondary);p(10,actor.phase);p(11,actor.subphase);p(0x92,actor.orientation[1]);p(0xbce,actor.analog_control->control_target_heading);
        p(0xba4,actor.auxiliary_status);p(0x548,actor.action_flags);p(0xd10,actor.locomotion->marker);p(0x4e4,actor.root_motion_delta);
        p(0x38,actor.position);p(0xd94,actor.saved_action_position);p(0xda0,actor.saved_action_yaw);p(0x520,actor.animation->motion);p(0x1e4,timing.frame);p(0x1ec,timing.restart);
        original_events.clear();native_events.clear();R5900Context c{};c.g[4].lo=actor_at;c.g[29].lo=0x30000;c.g[31].lo=done;
        if(action){
            o2_0066BB10_0x66bb10(ram.data(),&c,&runtime);w::update_turn_action(world,actor,animation);
            if(original_events!=native_events){
                std::fprintf(stderr,"original events:");for(auto value:original_events)std::fprintf(stderr," %x",value);
                std::fprintf(stderr,"\nnative events:");for(auto value:native_events)std::fprintf(stderr," %x",value);
                std::fprintf(stderr,"\n");
            }
            check(original_events==native_events);
            compare(ram,8,actor.primary);compare(ram,9,actor.secondary);compare(ram,10,actor.phase);compare(ram,11,actor.subphase);
            compare(ram,0x54f,actor.motion_class);compare(ram,0x92,actor.orientation[1]);compare(ram,0xba4,actor.auxiliary_status);
            compare(ram,0xba8,actor.motion_rate);compare(ram,0x548,actor.action_flags);compare(ram,0xd10,actor.locomotion->marker);
            compare(ram,0x4e4,actor.root_motion_delta);compare(ram,0xd94,actor.saved_action_position);compare(ram,0xda0,actor.saved_action_yaw);compare(ram,0x520,actor.animation->motion);
        }else{
            o2_0065F580_0x65f580(ram.data(),&c,&runtime);
            const auto actual=w::primary_turn_step(world,actor);check(GPR_S32(&c,2)==actual);
        }
        check(c.pc==done);
    };
    for(unsigned seed=0;seed<16384;++seed)run(seed*104729u,false);
    for(unsigned seed=0;seed<8192;++seed)run(seed*104729u,true);
    for(unsigned phase=0;phase<256;++phase)run((phase<<16)|0x2001,true);
    std::printf("{\"checks\":%u,\"cases\":%u,\"game_run\":false}\n",checks,cases);
}catch(const std::exception& e){std::fprintf(stderr,"%s\n",e.what());return 1;}
