#include "game/native/gameplay_world/analog_control.hpp"
#include "game/native/gameplay_world/actor_initial_state.hpp"
#include "game/native/gameplay_world/target_metrics.hpp"
#include "game/native/gameplay_collision/room_objects.hpp"
#include "game/native/gameplay_scenario/camera_curves.hpp"
#include "game/native/transform_math/heading.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <algorithm>
#include <array>
#include <bit>
#include <cstdint>
#include <iostream>
#include <fstream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

namespace w=reo::native::gameplay_world;
namespace c=reo::native::gameplay_collision;
namespace t=reo::native::transform_math;
constexpr std::uint32_t actor_at=0x4a5c30,ret=0xabcdefu,stack=0x1f00000u;
std::vector<std::uint8_t> ram(0x2000000);
std::uint64_t cases{},unchanged_prefixes{},head_target_calls{};
std::uint64_t frame_mismatches{},status_mismatches{},state_mismatches{},latch_mismatches{};
bool original_only{};
constexpr std::array<std::uint16_t,10> primary_table{0xff00,0x0100,0xc800,0x3800,0xb000,0x5000,0x8800,0x7800,0x8000,0x8000};
constexpr std::array<std::uint16_t,10> secondary_table{0xfd00,0x0300,0xc800,0x3800,0xb000,0x5000,0x8800,0x7800,0x8000,0x8000};
void check(bool value,const std::string& message){if(!value)throw std::runtime_error(message);}
void compare(bool value,std::uint64_t& counter,const std::string& message){if(!value){++counter;std::cerr<<"mismatch "<<message<<'\n';}}
void load_owned_elf(const char* path){
    std::ifstream input(path,std::ios::binary);check(bool(input),"open pinned MAIN PT_LOAD image");
    const auto read_u32=[&](){std::array<std::uint8_t,4>b{};input.read(reinterpret_cast<char*>(b.data()),4);check(bool(input),"read MAIN PT_LOAD header");return std::uint32_t(b[0])|(std::uint32_t(b[1])<<8)|(std::uint32_t(b[2])<<16)|(std::uint32_t(b[3])<<24);};
    const auto count=read_u32();for(std::uint32_t i=0;i<count;++i){const auto address=read_u32(),size=read_u32();check(std::uint64_t(address)+size<=ram.size(),"MAIN PT_LOAD range");input.read(reinterpret_cast<char*>(ram.data()+address),size);check(bool(input),"read MAIN PT_LOAD data");}
}
template<class T>T get(std::uint32_t at){return transform_read<T>(ram.data(),at);}
template<class T>void put(std::uint32_t at,T value){transform_write(ram.data(),at,value);}
void write_frame(std::uint32_t at,const reo::native::gameplay_actors::input::Frame& f){
    put(at,f.pressed);put(at+4,f.released);put(at+8,f.held);
    for(unsigned i=0;i<3;++i)put(at+12+4*i,f.history[i]);
    put(at+24,f.repeat);put(at+28,f.repeat_timer);
    for(unsigned i=0;i<8;++i)put(at+32+2*i,f.analog[i]);
}
reo::native::gameplay_actors::input::Frame read_frame(std::uint32_t at){
    reo::native::gameplay_actors::input::Frame f;
    f.pressed=get<std::uint32_t>(at);f.released=get<std::uint32_t>(at+4);f.held=get<std::uint32_t>(at+8);
    for(unsigned i=0;i<3;++i)f.history[i]=get<std::uint32_t>(at+12+4*i);
    f.repeat=get<std::uint32_t>(at+24);f.repeat_timer=get<std::int32_t>(at+28);
    for(unsigned i=0;i<8;++i)f.analog[i]=get<std::int16_t>(at+32+2*i);
    return f;
}
void original_transform_port(std::uint8_t*,R5900Context*,PS2Runtime*);
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#include "original.cpp"
#pragma GCC diagnostic pop
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    switch(context->pc){
#include "original_dispatch.hpp"
    default:throw std::runtime_error("unexpected analog original dependency "+std::to_string(context->pc));
    }
}
R5900Context call_original(){
    R5900Context c;c.pc=0x6621f0;SET_GPR_U32(&c,4,actor_at);SET_GPR_U32(&c,29,stack);SET_GPR_U32(&c,31,ret);
    PS2Runtime runtime;original_transform_port(ram.data(),&c,&runtime);
    check(c.pc==ret&&GPR_U32(&c,29)==stack,"original 6621F0 return/stack");return c;
}
std::uint16_t original_direction_turn(t::Vector eye,t::Vector aim){
    put(0x1a00000,eye);put(0x1a00100,aim);
    R5900Context c;c.pc=0x376e70;SET_GPR_U32(&c,4,0x1a00000);SET_GPR_U32(&c,5,0x1a00100);SET_GPR_U32(&c,29,stack);SET_GPR_U32(&c,31,ret);
    PS2Runtime runtime;original_transform_port(ram.data(),&c,&runtime);
    check(c.pc==ret&&GPR_U32(&c,29)==stack,"original 376E70 return/stack");return std::uint16_t(GPR_U32(&c,2));
}
void original_suppression(bool& value){
    R5900Context c;c.pc=0x6dee20;SET_GPR_U32(&c,29,stack);SET_GPR_U32(&c,31,ret);
    PS2Runtime runtime;original_transform_port(ram.data(),&c,&runtime);
    check(c.pc==ret&&GPR_U32(&c,29)==stack,"original 6DEE20 return/stack");value=GPR_U32(&c,2)!=0;
}
void project_actor(const w::Actor& a){
    ram[actor_at+2]=a.category;ram[actor_at+3]=a.slot;
    put(actor_at+0x54f,a.motion_class);ram[actor_at+0xb98]=a.character;put(actor_at+0x92,a.orientation[1]);
    put(actor_at+0xba0,a.status);ram[actor_at+0xbd0]=a.response_lock;ram[actor_at+0xff0]=a.ai_control;
    if(a.analog_control){ram[actor_at+0xfaa]=std::uint8_t(a.analog_control->heading_active);put(actor_at+0xfa8,a.analog_control->previous_input_heading);put(actor_at+0xbce,a.analog_control->control_target_heading);}
    write_frame(actor_at+0xf78,a.input);
}
void case_run(std::uint32_t seed,std::int16_t magnitude,std::int16_t input_heading,
              std::uint32_t actor_status,std::uint8_t motion,std::uint8_t character,
              std::uint8_t response_lock,std::uint8_t request_blocked,
              std::uint8_t ai,std::uint8_t latch,std::uint8_t inventory_owner){
    // The source bodies only touch this actor record, their stack frames, and
    // the listed globals. Clear those regions instead of memset'ing 32 MiB
    // for every profile.
    std::fill_n(ram.begin()+actor_at,0x1000,std::uint8_t(0xa5));
    std::fill_n(ram.begin()+stack-0x1000,0x1000,std::uint8_t(0xa5));
    for (auto address : {0x4bae8du,0x4baeedu,0x3243f2u,0x4badedu,0x4baeeeu,
                         0x4badeeu,0x4bae33u,0x755ec4u,0x324138u,0x324144u,
                         0x3dddb4u}) ram[address]=0;
    // State globals read by the complete original helpers.
    ram[0x4bae8d]=request_blocked;ram[0x4baeed]=0;ram[0x3243f2]=0;
    ram[0x4baded]=0;ram[0x4baeee]=0;ram[0x4badee]=inventory_owner;
    ram[0x4bae33]=std::uint8_t(seed&1);ram[0x755ec4]=std::uint8_t((seed>>1)&1);
    const t::Vector eye{float(int(seed%19)-9),float(seed%5),float(int(seed%13)-6)};
    const t::Vector aim{eye.x+float(int(seed%11)-5),eye.y+float(seed%7),eye.z+float(int(seed%17)-8)};
    put(0x324138,eye);put(0x324144,aim);ram[0x3dddb4]=latch;

    w::Profile profile;profile.layouts.push_back({});profile.controller_count=1;
    auto session=std::make_shared<w::Session>();session->inventory_owner=inventory_owner;
    w::World world(profile,session);auto actor=std::make_unique<w::Actor>();w::initialize_cleared_actor_defaults(*actor);
    actor->category=0;actor->slot=0;actor->motion_class=motion;actor->character=character;actor->response_lock=response_lock;actor->ai_control=ai;
    actor->status=actor_status;actor->orientation[1]=std::bit_cast<std::int16_t>(std::uint16_t((seed*1543u)^0x8011u));
    actor->input.pressed=seed*0x12345u;actor->input.released=seed*0x9182u;actor->input.held=(seed*0x51e7u)&~0xfu;
    if(seed&1)actor->input.held|=2u;
    actor->input.history={seed*0x7781u,seed*0x143u,seed*0x9841u};actor->input.repeat=seed*0x17u;actor->input.repeat_timer=std::int32_t(seed^0x7ff0u);
    actor->input.analog[0]=magnitude;actor->input.analog[1]=input_heading;
    for(unsigned i=2;i<8;++i)actor->input.analog[i]=std::bit_cast<std::int16_t>(std::uint16_t(seed*std::uint32_t(i+17)));
    auto created=world.spawn_primary(0,std::move(actor));check(created.status==reo::native::gameplay_actors::EntityStatus::completed,"native actor create");
    auto native_actor=world.primary(0);check(bool(native_actor),"native primary lookup");
    project_actor(*native_actor);
    // 65F0C0's production owner requires a published metric frame. Model an
    // inactive, self-only source record so the complete selector admits an
    // empty candidate set without inventing a target.
    native_actor->active=false;world.mode=1;
    std::vector<std::byte> raw_grid(48);
    const auto grid_word=[&](unsigned at,std::uint32_t value){std::memcpy(raw_grid.data()+at,&value,4);};
    grid_word(8,10000);grid_word(12,10000);grid_word(16,1);grid_word(20,1);
    grid_word(32,32);grid_word(36,40);grid_word(40,36);grid_word(44,0xffffffffu);
    const auto empty_grid=c::response::Grid::import(raw_grid);
    const auto metric_result=world.target_metrics().rebuild({empty_grid,empty_grid,{}, {}});
    check(metric_result.status==w::TargetMetricStatus::completed&&world.target_metrics().state(),"empty complete target metric fixture");
    const auto before_frame=read_frame(actor_at+0xf78);const auto before_status=get<std::uint32_t>(actor_at+0xba0);
    const auto before_state=std::array<std::uint32_t,3>{ram[actor_at+0xfaa],get<std::uint16_t>(actor_at+0xfa8),get<std::uint16_t>(actor_at+0xbce)};
    call_original();
    if(original_only){++cases;return;}
    const auto expected_frame=read_frame(actor_at+0xf78);const auto expected_status=get<std::uint32_t>(actor_at+0xba0);
    const auto expected_state=std::array<std::uint32_t,3>{ram[actor_at+0xfaa],get<std::uint16_t>(actor_at+0xfa8),get<std::uint16_t>(actor_at+0xbce)};
    bool suppressed{};if(world.locally_controlled(*native_actor)&&inventory_owner==0)original_suppression(suppressed);
    auto& ui_block=request_blocked;
    std::uint8_t native_latch=latch;
    const auto result=w::update_analog_control(world,*native_actor,eye,aim,native_latch,ui_block,
        world.locally_controlled(*native_actor)&&inventory_owner==0?std::optional<bool>(suppressed):std::nullopt);
    check(result==w::AnalogControlStatus::completed,"native analog available");
    const auto& state=*native_actor->analog_control;
    const auto actual_frame=native_actor->input;
    const auto actual_state=std::array<std::uint32_t,3>{std::uint8_t(state.heading_active),std::uint16_t(state.previous_input_heading),std::uint16_t(state.control_target_heading)};
    if(actual_frame!=expected_frame)std::cerr<<"frame expected="<<std::hex<<expected_frame.pressed<<"/"<<expected_frame.released<<"/"<<expected_frame.held<<" actual="<<actual_frame.pressed<<"/"<<actual_frame.released<<"/"<<actual_frame.held<<std::dec<<"\n";
    compare(actual_frame==expected_frame,frame_mismatches,"6621F0 input frame mismatch seed="+std::to_string(seed));
    compare(native_actor->status==expected_status,status_mismatches,"6621F0 actor status mismatch seed="+std::to_string(seed));
    compare(actual_state==expected_state,state_mismatches,"6621F0 FAA/FA8/BCE mismatch seed="+std::to_string(seed));
    compare(native_latch==ram[0x3dddb4],latch_mismatches,"6621F0 camera latch mismatch seed="+std::to_string(seed));
    if(magnitude<16&&(actor_status&0x80u)&&!(before_frame.held&2u)&&!response_lock&&!request_blocked){
        compare(actual_frame==before_frame,frame_mismatches,"held&2 early return altered input frame");
        compare(native_actor->status==(before_status&~0x2000u),status_mismatches,"held&2 early return prefix status");
        ++unchanged_prefixes;
    }
    ++cases;
}
int main(int argc,char**argv){try{
    check(argc>=2&&argc<=3,"pinned MAIN PT_LOAD image path required");
    load_owned_elf(argv[1]);
    original_only=argc==3&&std::string(argv[2])=="--original-only";
    owned_constants(ram.data());
    std::uint32_t seed=1;
    for(auto magnitude:{std::int16_t(-1),std::int16_t(0),std::int16_t(15),std::int16_t(16),std::int16_t(127),std::int16_t(4096),std::int16_t(32767)})
    for(auto status:{0u,0x80u,0x2000u,0x2080u})
    for(auto motion:{std::uint8_t(2),std::uint8_t(0x15),std::uint8_t(0x16),std::uint8_t(0x1a),std::uint8_t(0x27),std::uint8_t(0x31),std::uint8_t(0x41),std::uint8_t(0x80),std::uint8_t(0xb0)})
    for(auto latch:{std::uint8_t(0),std::uint8_t(1)}){
        const auto current=seed++;
        case_run(current,magnitude,std::bit_cast<std::int16_t>(std::uint16_t(current*0x1e37u)),status,motion,motion==0x41?1:std::uint8_t(current%3),std::uint8_t(current%2),std::uint8_t((current>>1)%2),std::uint8_t((current>>2)%2),latch,std::uint8_t((current>>3)%2));
    }
    for(auto status:{0u,0x80u,0x2080u})
        case_run(seed++,16,std::int16_t(0),status,2,1,0,0,0,1,0);
    std::cout<<"{\"cases\":"<<cases<<",\"held2_early_returns\":"<<unchanged_prefixes<<",\"head_target_calls\":"<<head_target_calls<<",\"frame_mismatches\":"<<frame_mismatches<<",\"status_mismatches\":"<<status_mismatches<<",\"state_mismatches\":"<<state_mismatches<<",\"latch_mismatches\":"<<latch_mismatches<<",\"complete_original_body_runs\":"<<cases<<",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}}
