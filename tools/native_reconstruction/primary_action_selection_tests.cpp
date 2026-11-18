#include "game/native/gameplay_world/primary_action_selection.hpp"
#include <fstream>
#include <cstdio>
#include <vector>
namespace w=reo::native::gameplay_world;
namespace {
constexpr unsigned actor_at=0x10000,done=0x1234;
unsigned checks{},cases{},entry{},variant{};
std::vector<unsigned> original_calls,native_calls;
bool local{},suppressed{},mutate_category{};
unsigned chosen{},weapon_target{};
void check(bool value){++checks;if(!value)throw std::runtime_error("selection check "+std::to_string(checks)+" case "+std::to_string(cases)+" entry "+std::to_string(entry)+" variant "+std::to_string(variant));}
void original_port(std::uint8_t* ram,R5900Context* c,PS2Runtime*){
    const auto at=c->pc;
    if(at==0x1b0340){SET_GPR_U32(c,2,local);}
    else{
        original_calls.push_back(at);
        if(at==0x6dee20)SET_GPR_U32(c,2,suppressed);
        else if(at==0x65f060){weapon_target=0x14000;SET_GPR_U32(c,2,weapon_target);}
        else if(at==0x586440){original_calls.push_back(GPR_U32(c,5));SET_GPR_U32(c,2,chosen==at);}
        else{
            if(mutate_category)ram[actor_at+2]=1;
            SET_GPR_U32(c,2,chosen==at);
        }
    }
    c->pc=GPR_U32(c,31);
}
struct Services final:w::PrimaryActionSelectionServices {
    unsigned target{};std::uint8_t target_index{31};
    bool dialogue_suppressed()override{native_calls.push_back(0x6dee20);return suppressed;}
    bool call(w::Actor& actor,unsigned at){native_calls.push_back(at);if(mutate_category)actor.category=1;return chosen==at;}
    bool interaction(w::World&,w::Actor& a)override{return call(a,0x64e960);}
    bool request(w::World&,w::Actor& a)override{return call(a,0x64f5f0);}
    bool modal(w::World&,w::Actor& a)override{return call(a,0x64f110);}
    void prepare_weapon_target(w::World&,w::Actor& actor,bool automatic)override{
        if(automatic){native_calls.push_back(0x65f060);target=0x14000;}
        else{target=0;target_index=255;actor.aim_target_index=255;}
    }
    bool reload_available(w::World&,w::Actor&,std::uint8_t resource)override{
        native_calls.insert(native_calls.end(),{0x586440,resource});return chosen==0x586440;
    }
};
template<class T>void compare(const std::vector<std::uint8_t>& ram,unsigned offset,const T& value){check(std::memcmp(ram.data()+actor_at+offset,&value,sizeof value)==0);}
}
PS2Runtime::Fn PS2Runtime::lookupFunction(std::uint32_t at)const{
    switch(at){
#define ORIGINAL(hex) case 0x##hex:return o2_00##hex##_0x##hex;
    // Declarations use upper-case symbol components, so spell the three
    // callbacks that can be indirect in these original bodies explicitly.
    case 0x667370:return o2_00667370_0x667370;
    case 0x1b0340:case 0x6dee20:case 0x64e960:case 0x64f5f0:case 0x64f110:case 0x65f060:case 0x586440:return original_port;
    default:throw std::runtime_error("Unknown selection dependency "+std::to_string(at));
    }
}
int main(int argc,char** argv)try{
    check(argc==2);std::vector<std::uint8_t> ram(0x800000);
    std::ifstream image(argv[1],std::ios::binary);check(bool(image));
    image.read(reinterpret_cast<char*>(ram.data()+0x570000),0x800000-0x570000);check(image.gcount()>0x711890-0x570000);
    w::Profile profile;profile.layouts.push_back({0x100,0x10,0x20});
    w::World world(std::move(profile),std::make_shared<w::Session>());
    w::animation_events::File1Metadata metadata;PS2Runtime runtime;
    auto run=[&](unsigned address,unsigned row,unsigned seed){
        entry=address;variant=seed;++cases;std::fill_n(ram.data()+actor_at,0x1100,0);
        w::Actor actor;actor.primary=7;actor.secondary=8;actor.phase=9;actor.subphase=10;
        actor.category=std::uint8_t((seed>>20)%3);actor.slot=std::uint8_t((seed>>18)%2);
        actor.status=std::array<unsigned,8>{0,8,0x10,0x80,0x2000,0x2080,0x2098,0x10000000}[(seed>>8)%8];
        actor.motion_class=std::uint8_t(seed);actor.class_marker=std::uint8_t((seed>>11)%4);
        actor.character=std::uint8_t((seed>>13)%8);world.selected_actor=std::uint8_t((seed>>19)%2);world.mode=std::uint8_t((seed>>21)%4);
        actor.input.held=(seed>>4)&0xfffu;actor.input.pressed=(seed>>1)&0xfffu;
        if(seed&0x10000u)actor.input.pressed|=0x100000u;
        actor.input.analog[1]=std::int16_t((seed>>7)*0x2000u);
        actor.resource_action=std::uint16_t((seed>>9)%32);actor.selected_resource=std::uint8_t((seed>>12)%3);
        actor.interaction_request_count=13;actor.aim_target_index=31;
        actor.position={10,20,30};actor.orientation[1]=-1257;
        actor.saved_action_position={1,2,3};actor.saved_action_yaw=41;
        auto p=[&]<class T>(unsigned offset,T value){ref_write(ram.data(),actor_at+offset,value);};
        p(2,actor.category);p(3,actor.slot);p(8,actor.primary);p(9,actor.secondary);p(10,actor.phase);p(11,actor.subphase);
        p(0xba0,actor.status);p(0x54f,actor.motion_class);p(0xb9b,actor.class_marker);p(0xb98,actor.character);
        p(0xf78,actor.input.pressed);p(0xf80,actor.input.held);p(0xfa2,actor.input.analog[1]);
        p(0xca8,actor.resource_action);p(0xc7c,actor.selected_resource);p(0xbbd,*actor.interaction_request_count);p(0xcdc,*actor.aim_target_index);
        p(0x38,actor.position);p(0x92,actor.orientation[1]);p(0xd94,actor.saved_action_position);p(0xda0,actor.saved_action_yaw);
        ram[0x4baded]=world.selected_actor;
        local=world.locally_controlled(actor);suppressed=(seed&0x20000)!=0;mutate_category=(seed&0x40000)!=0;
        chosen=std::array<unsigned,5>{0,0x64e960,0x64f5f0,0x64f110,0x586440}[(seed>>14)%5];
        original_calls.clear();native_calls.clear();weapon_target=0;Services services;
        R5900Context c{};c.g[4].lo=actor_at;c.g[5].lo=row;c.g[29].lo=0x30000;c.g[31].lo=done;
        bool result{};const auto& actions=w::locomotion_action_row(std::uint8_t(row));
        switch(address){
        case 0x64e800:o2_0064E800_0x64e800(ram.data(),&c,&runtime);result=w::select_status_action(actor);break;
        case 0x64ffa0:o2_0064FFA0_0x64ffa0(ram.data(),&c,&runtime);result=w::select_character_action(world,actor);break;
        case 0x64e860:o2_0064E860_0x64e860(ram.data(),&c,&runtime);result=w::select_directional_action(actor);break;
        case 0x64dc00:o2_0064DC00_0x64dc00(ram.data(),&c,&runtime);result=w::select_forward_action(actor,actions);break;
        case 0x64dc60:o2_0064DC60_0x64dc60(ram.data(),&c,&runtime);result=w::select_fast_forward_action(actor,actions);break;
        case 0x64dd00:o2_0064DD00_0x64dd00(ram.data(),&c,&runtime);result=w::select_backward_action(actor,actions);break;
        case 0x64ddc0:o2_0064DDC0_0x64ddc0(ram.data(),&c,&runtime);result=w::select_turn_action(actor,actions);break;
        case 0x64e6b0:o2_0064E6B0_0x64e6b0(ram.data(),&c,&runtime);result=w::select_resource_movement(actor,metadata);break;
        case 0x64e5c0:o2_0064E5C0_0x64e5c0(ram.data(),&c,&runtime);result=w::select_weapon_action(world,actor,metadata,services);break;
        case 0x64e770:o2_0064E770_0x64e770(ram.data(),&c,&runtime);result=w::select_reload_action(world,actor,services);break;
        case 0x64b060:o2_0064B060_0x64b060(ram.data(),&c,&runtime);result=w::select_idle_action(world,actor,metadata,services);break;
        default:throw std::runtime_error("fixture entry");
        }
        check(c.pc==done);check(GPR_U32(&c,2)==unsigned(result));check(original_calls==native_calls);
        compare(ram,2,actor.category);compare(ram,8,actor.primary);compare(ram,9,actor.secondary);compare(ram,10,actor.phase);compare(ram,11,actor.subphase);
        compare(ram,0xbbd,*actor.interaction_request_count);compare(ram,0xcdc,*actor.aim_target_index);
        compare(ram,0xd94,actor.saved_action_position);compare(ram,0xda0,actor.saved_action_yaw);compare(ram,0x24,services.target);
    };
    constexpr std::array<unsigned,11> entries{0x64e800,0x64ffa0,0x64e860,0x64dc00,0x64dc60,0x64dd00,0x64ddc0,0x64e6b0,0x64e5c0,0x64e770,0x64b060};
    for(auto address:entries)for(unsigned seed=0;seed<4096;++seed)run(address,seed%4,seed*104729u);
    for(unsigned motion=0;motion<256;++motion)for(unsigned nibble=0;nibble<16;++nibble)
        for(unsigned status=0;status<8;++status)run(0x64ddc0,status%4,motion|(status<<8)|(nibble<<4));
    std::printf("{\"checks\":%u,\"cases\":%u,\"full_original_bodies\":17,\"game_run\":false}\n",checks,cases);
}catch(const std::exception& e){std::fprintf(stderr,"%s\n",e.what());return 1;}
