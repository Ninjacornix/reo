#define SRL32(a,b) (static_cast<std::uint32_t>(a)>>static_cast<unsigned>(b))
#include "game/native/gameplay_world/world.hpp"
#include "runtime.hpp"
#include <algorithm>
#include <bit>
#include <iostream>
#include <string>
#include <vector>
namespace g=reo::native::gameplay_world;
#include "owned_remaps.hpp"
g::Profile fixture_profile(){return {std::vector<g::input::Remap>(owned_remaps.begin(),owned_remaps.end()),4,{16,UINT64_MAX}};}
constexpr std::uint32_t actor_base=0x4a5c30,stride=0x10e0;
template<class T>T get(const std::uint8_t* ram,std::uint32_t at){return oracle_read<T>(ram,at);}
template<class T>void put(std::uint8_t* ram,std::uint32_t at,T value){oracle_write<T>(ram,at,value);}

std::unique_ptr<g::World> read_world(const std::uint8_t* ram){
    auto result=std::make_unique<g::World>(fixture_profile(),std::make_shared<g::Session>());auto& w=*result;w.mode=get<std::uint8_t>(ram,0x3243f2);const auto sub=get<std::int8_t>(ram,0x3243fb);
    w.filter_nonselected_input=sub==1 || sub==2;
    w.paused=get<std::int8_t>(ram,0x4badf8)!=0;w.room=get<std::uint16_t>(ram,0x3243dc);
    w.selected_actor=get<std::uint8_t>(ram,0x4baded);w.selected_frame_marker=get<std::uint8_t>(ram,0x4bae89);w.frame_shared_counter=get<std::uint16_t>(ram,0x744638);
    w.session().options.controller_profile=get<std::uint8_t>(ram,0x3243ec);
    for(std::uint32_t i=0;i<w.controllers().size();++i){auto& c=w.controllers()[i];c.held=get<std::uint32_t>(ram,0x324248+48*i);c.analog=get<std::array<std::int16_t,8>>(ram,0x324260+48*i);}
    w.controller_bindings=get<std::array<std::int8_t,8>>(ram,0x2b8e90);
    for(std::size_t i=0;i<g::World::primary_capacity;++i){auto owned=std::make_unique<g::Actor>();auto& a=*owned;const auto b=actor_base+std::uint32_t(i)*stride;
        a.active=get<std::uint8_t>(ram,b)!=0;a.visible=get<std::uint8_t>(ram,b+1)!=0;a.slot=get<std::uint8_t>(ram,b+3);a.ai_control=get<std::uint8_t>(ram,b+0xff0);a.normalized_marker=get<std::uint8_t>(ram,b+0x32);
        a.room=get<std::uint16_t>(ram,b+0x1e2);a.contact_flags=get<std::uint16_t>(ram,b+0x54a);a.pending_notice=get<std::uint16_t>(ram,b+0xd92);
        a.status=get<std::uint32_t>(ram,b+0xba0);a.auxiliary_status=get<std::uint32_t>(ram,b+0xba4);a.response_mask=get<std::uint32_t>(ram,b+0x190);a.response_value=get<std::uint32_t>(ram,b+0x194);
        a.motion_override=get<std::uint8_t>(ram,b+0xc82);a.interaction_marker=get<std::uint8_t>(ram,b+0xb9e);a.room_marker=get<std::uint8_t>(ram,b+0xc53);a.movement_enabled=get<std::uint8_t>(ram,b+0x553);
        a.frame_value_a=get<std::uint16_t>(ram,b+0xbdc);a.frame_value_b=get<std::uint16_t>(ram,b+0xbde);a.transient_marker=get<std::uint8_t>(ram,b+0x10a9);a.grid=get<std::uint8_t>(ram,b+0xcb0);a.grid_response=get<float>(ram,b+0x170);
        a.position=get<g::Position>(ram,b+0x38);a.input=get<g::input::Frame>(ram,b+0xf78);
        if(w.spawn_primary(i,std::move(owned)).status!=g::actors::EntityStatus::completed)throw std::runtime_error("Fixture primary creation");
    }return result;
}
void write_world(std::uint8_t* ram,const g::World& w){
    put(ram,0x3243f2,w.mode);put<std::uint8_t>(ram,0x3243fb,w.filter_nonselected_input?1:0);put<std::uint8_t>(ram,0x4badf8,w.paused?1:0);put(ram,0x3243dc,w.room);put(ram,0x4baded,w.selected_actor);put(ram,0x4bae89,w.selected_frame_marker);put(ram,0x744638,w.frame_shared_counter);
    put(ram,0x3243ec,w.session().options.controller_profile);
    for(std::uint32_t i=0;i<w.controllers().size();++i){const auto& c=w.controllers()[i];put(ram,0x324248+48*i,c.held);put(ram,0x324260+48*i,c.analog);}
    put(ram,0x2b8e90,w.controller_bindings);
    for(std::size_t i=0;i<g::World::primary_capacity;++i){auto lease=w.primary(i);if(!lease)throw std::runtime_error("Missing fixture primary");const auto& a=*lease;const auto b=actor_base+std::uint32_t(i)*stride;
        put<std::uint8_t>(ram,b,a.active?1:0);put<std::uint8_t>(ram,b+1,a.visible?1:0);put(ram,b+3,a.slot);put(ram,b+0xff0,a.ai_control);put(ram,b+0x32,a.normalized_marker);
        put(ram,b+0x1e2,a.room);put(ram,b+0x54a,a.contact_flags);put(ram,b+0xd92,a.pending_notice);put(ram,b+0xba0,a.status);put(ram,b+0xba4,a.auxiliary_status);put(ram,b+0x190,a.response_mask);put(ram,b+0x194,a.response_value);
        put(ram,b+0xc82,a.motion_override);put(ram,b+0xb9e,a.interaction_marker);put(ram,b+0xc53,a.room_marker);put(ram,b+0x553,a.movement_enabled);put(ram,b+0xbdc,a.frame_value_a);put(ram,b+0xbde,a.frame_value_b);put(ram,b+0x10a9,a.transient_marker);put(ram,b+0xcb0,a.grid);put(ram,b+0x170,a.grid_response);put(ram,b+0x38,a.position);put(ram,b+0xf78,a.input);
    }
}
std::uint32_t index_of(g::World& w,g::Actor& a){for(std::size_t i=0;i<8;++i)if(w.primary(i).get()==&a)return std::uint32_t(i);throw std::runtime_error("Fixture actor identity");}
struct Event {std::uint32_t call,slot,arg{},other{};bool operator==(const Event&)const=default;};
std::uint32_t stage_address(g::Stage stage){
    switch(stage){
    case g::Stage::offline_ai:return 0x812460;case g::Stage::leave_room:return 0x669670;
    case g::Stage::prepare_contacts:return 0x61a6a0;
    case g::Stage::prepare_authority:return 0x669790;case g::Stage::update_behavior:return 0x66b500;
    case g::Stage::update_local_motion:return 0x65e3a0;case g::Stage::update_pose:return 0x65e4a0;
    case g::Stage::update_auxiliary_motion:return 0x65e670;case g::Stage::finish_motion:return 0x65e5c0;
    case g::Stage::refresh_grid_position:return 0x376db0;case g::Stage::finish_actor:return 0x6655f0;
    case g::Stage::publish_notice:return 0x67e230;
    }throw std::runtime_error("stage mapping");
}
struct Ports final:g::Services {
    std::uint32_t seed{},current{};std::vector<Event> events;
    void begin_offline_frame(g::World& w)override{events.push_back({0x8122b0,0});if(seed&8)w.primary(7)->active=true;}
    void action(std::uint32_t call,g::World& w,g::Actor& a){
        current=index_of(w,a);events.push_back({call,current,call==0x67e230?7u:0u});
        if(call==0x61a6a0 && (seed+current)%3==0)a.contact_flags|=2;
        if(call==0x66b500){
            if((seed+current)%5==0)a.auxiliary_status|=0x08000000;
            if(seed%17==0 && current==3)w.mode=std::uint8_t((w.mode+1)%4);
            if(seed%19==0 && current<7)w.primary(current+1)->active=false;
        }
        if(call==0x6655f0 && (seed+current)%2)a.pending_notice=std::uint16_t(current+1);
        if(call==0x67e230)a.pending_notice=0xffff;
    }
    void run(g::Stage stage,g::World& w,g::Actor& a)override{action(stage_address(stage),w,a);}
    bool remote_motion(g::World& w,g::Actor& a)override{current=index_of(w,a);events.push_back({0x6647f0,current});return (seed+current)%3==1;}
    bool find_grid(g::World& w,g::Actor& a,std::int8_t& selected)override{current=index_of(w,a);events.push_back({0x6afd70,current});selected=std::bit_cast<std::int8_t>(std::uint8_t(seed+current*31));return (seed+current)%4<2;}
    void switch_grid(g::World&,std::int32_t next,std::int32_t previous)override{events.push_back({0x6afae0,current,std::uint32_t(next),std::uint32_t(previous)});}
    float grid_response(g::World& w,std::uint8_t selected)override{events.push_back({0x6afe10,current,selected});if(seed&32)w.primary(current)->grid_response=51.25f;return float(std::int32_t(selected)-128)*.125f;}
};
Ports* original_ports{};
void sub_001B0B80_0x1b0b80(std::uint8_t*,R5900Context*,PS2Runtime*);
void original_port(std::uint8_t* ram,R5900Context* ctx,PS2Runtime* runtime){
    const auto call=ctx->pc;
    if(call==0x1b0b80){sub_001B0B80_0x1b0b80(ram,ctx,runtime);return;}
    if(call==0x1b0300){SET_GPR_U32(ctx,2,ram[0x3243f2]);return;}
    if(call==0x1b02d0){SET_GPR_U32(ctx,2,ram[0x3243f2]==0);return;}
    if(call==0x1b0310){const auto m=std::bit_cast<std::int8_t>(ram[0x3243fb]);SET_GPR_U32(ctx,2,m==1||m==2);return;}
    auto snapshot=read_world(ram);auto& w=*snapshot;
    if(call==0x1b02d0){SET_GPR_U32(ctx,2,w.mode==0);return;}
    if(call==0x1b0310){SET_GPR_U32(ctx,2,w.filter_nonselected_input);return;}
    if(call==0x8122b0){original_ports->begin_offline_frame(w);write_world(ram,w);return;}
    const auto pointer=GPR_U32(ctx,16);if(pointer<actor_base || (pointer-actor_base)%stride || (pointer-actor_base)/stride>=8)throw std::runtime_error("original actor pointer");
    const auto slot=(pointer-actor_base)/stride;auto lease=w.primary(slot);auto& a=*lease;original_ports->current=slot;
    if(call==0x107c68){
        if(GPR_U32(ctx,4)!=pointer+0xf78 || GPR_U32(ctx,5)!=0 || GPR_U32(ctx,6)!=48)throw std::runtime_error("original clear domain");
        a.input={}; // Input clear is an operation, not a service trace.
    }else if(call==0x6647f0)SET_GPR_U32(ctx,2,original_ports->remote_motion(w,a));
    else if(call==0x6afd70){std::int8_t selected{};const auto found=original_ports->find_grid(w,a,selected);put(ram,GPR_U32(ctx,4),selected);SET_GPR_U32(ctx,2,found);}
    else if(call==0x6afae0)original_ports->switch_grid(w,std::bit_cast<std::int32_t>(GPR_U32(ctx,4)),std::bit_cast<std::int32_t>(GPR_U32(ctx,5)));
    else if(call==0x6afe10)ctx->f[0]=original_ports->grid_response(w,std::uint8_t(GPR_U32(ctx,4)));
    else original_ports->action(call,w,a);
    write_world(ram,w);
}
#include "original_actor.cpp"

std::uint32_t random_word(std::uint32_t& state){state^=state<<13;state^=state>>17;state^=state<<5;return state;}
int main()try{
    std::vector<std::uint8_t> actual(0x2000000,0xa5),expected(actual);
    for(std::uint32_t i=0;i<owned_remaps.size();++i){
        const auto& m=owned_remaps[i];const auto at=0x2343c0+12*i;
        put(actual.data(),at,m.button_100);put(actual.data(),at+4,m.button_10);put(actual.data(),at+8,m.button_20);
    }
    std::uint64_t cases{},calls{};std::uint32_t random=0x8ac1e37b;
    for(std::uint32_t seed=0;seed<4096;++seed){
        g::World world(fixture_profile(),std::make_shared<g::Session>());world.mode=std::uint8_t(seed%4);world.paused=(seed&4)!=0;world.filter_nonselected_input=(seed&16)!=0;world.room=std::uint16_t(seed%8);world.selected_actor=std::uint8_t((seed>>5)%8);world.selected_frame_marker=0xff;world.frame_shared_counter=0x37;
        for(std::size_t i=0;i<8;++i){auto owned=std::make_unique<g::Actor>();auto& a=*owned;a.active=(random_word(random)&3)!=0;a.visible=(seed+i)%2;a.slot=std::uint8_t(i);a.ai_control=std::uint8_t((seed+i)%2);a.normalized_marker=(seed+i)%3==0?0xff:0x42;a.room=std::uint16_t((seed+i)%8);
            a.contact_flags=0xffff;a.pending_notice=0xfedc;a.status=random_word(random);a.auxiliary_status=random_word(random);a.response_mask=random_word(random);a.response_value=random_word(random);a.motion_override=17;a.interaction_marker=18;a.room_marker=19;a.movement_enabled=20;a.frame_value_a=0x1234;a.frame_value_b=0x5678;a.transient_marker=21;a.grid=std::uint8_t(random_word(random));a.grid_response=float(seed%100)*.25f;a.position={float(i),20,float(seed)};std::array<std::uint32_t,12> words;words.fill(0x12345678u+std::uint32_t(i));a.input=std::bit_cast<g::input::Frame>(words);
            if(world.spawn_primary(i,std::move(owned)).status!=g::actors::EntityStatus::completed)throw std::runtime_error("Primary creation");
        }
        world.session().options.controller_profile=std::uint8_t(seed%6);
        for(auto& c:world.controllers()){c.held=random_word(random);for(auto& value:c.analog)value=std::bit_cast<std::int16_t>(std::uint16_t(random_word(random)));}
        for(std::size_t i=0;i<8;++i)world.controller_bindings[i]=std::int8_t(int((seed+i)%5)-1);
        std::fill(actual.begin()+actor_base,actual.begin()+actor_base+8*stride,0xa5);write_world(actual.data(),world);
        std::copy(actual.begin()+actor_base,actual.begin()+actor_base+8*stride,expected.begin()+actor_base);write_world(expected.data(),world);
        Ports native;native.seed=seed;if(world.update_primary(native).status!=g::Status::completed)throw std::runtime_error("Native world frame failed");write_world(expected.data(),world);
        Ports original;original.seed=seed;original_ports=&original;R5900Context ctx;ctx.r[29][0]=0x1f00000;ctx.r[31][0]=0xdead0000;PS2Runtime runtime;runtime.port=&original_port;
        o2_00669F30_0x669f30(actual.data(),&ctx,&runtime);
        if(ctx.pc!=0xdead0000 || ctx.r[29][0]!=0x1f00000 || native.events!=original.events ||
           !std::equal(actual.begin()+actor_base,actual.begin()+actor_base+8*stride,expected.begin()+actor_base)){
            std::cerr<<"pc="<<ctx.pc<<" native_events="<<native.events.size()<<" original_events="<<original.events.size()<<'\n';
            for(std::size_t j=0;j<std::min(native.events.size(),original.events.size());++j)if(native.events[j]!=original.events[j]){const auto n=native.events[j],o=original.events[j];std::cerr<<"event "<<j<<" native="<<std::hex<<n.call<<','<<n.slot<<','<<n.arg<<','<<n.other<<" original="<<o.call<<','<<o.slot<<','<<o.arg<<','<<o.other<<std::dec<<'\n';break;}
            unsigned shown=0;for(std::uint32_t at=actor_base;at<actor_base+8*stride && shown<16;++at)if(actual[at]!=expected[at]){std::cerr<<"offset="<<std::hex<<(at-actor_base)<<" actual="<<unsigned(actual[at])<<" expected="<<unsigned(expected[at])<<std::dec<<'\n';++shown;}
            throw std::runtime_error("actor differential case "+std::to_string(seed));
        }
        for(const auto at:{0x3243f2u,0x3243fbu,0x4badf8u,0x3243dcu,0x4badedu,0x4bae89u,0x744638u})
            if(get<std::uint8_t>(actual.data(),at)!=get<std::uint8_t>(expected.data(),at))throw std::runtime_error("global differential case "+std::to_string(seed));
        ++cases;calls+=original.events.size();
    }
    std::cout<<"{\"cases\":"<<cases<<",\"ordered_calls\":"<<calls<<",\"original_body_executed\":true,\"game_run\":false}\n";
    return 0;
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
