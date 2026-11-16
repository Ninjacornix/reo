#include "trace_reference.hpp"
#include "game/native/gameplay_world/interaction_action.hpp"
#include "game/native/gameplay_world/control_request_flow.hpp"
#include "game/native/transform_math/transform_math.hpp"
#include <cstdio>
#include <fstream>
#include <tuple>

namespace w=reo::native::gameplay_world;
namespace {
constexpr std::uint32_t actor_at=0x10000,finish_pc=0xdeadbeef;
std::vector<std::uint8_t> ram(0x800000);
std::vector<std::uint16_t> contact_codes;
std::size_t contact_index{};
std::int8_t admission_value{1};
bool local_value{true},alignment_value{true},equipment_consume{true};
std::uint32_t equipment_value{};
std::int8_t message_phase{};
std::vector<std::pair<std::uint32_t,std::uint32_t>> guest_calls,native_calls;
unsigned checks{},cases{};
R5900Context context(std::uint32_t pc){R5900Context c{};c.pc=pc;SET_GPR_U32(&c,29,0x30000);SET_GPR_U32(&c,31,finish_pc);return c;}
void check(bool value,const char* what){++checks;if(!value)throw std::runtime_error(std::string("original policy comparison failed: ")+what+" case="+std::to_string(cases));}
}
void original_port(std::uint8_t* memory,R5900Context* c,PS2Runtime*){
    const auto at=c->pc;
    auto record=[&](std::uint32_t arg){guest_calls.emplace_back(at,arg);};
    switch(at){
    case 0x65f4a0:{
        const auto index=contact_index++;
        const auto code=std::uint16_t(index<contact_codes.size()?contact_codes[index]:0);
        const auto actor=GPR_U32(c,4);const std::array<float,3> point{10,20,30},normal{0,0,-1};
        ref_write(memory,actor+0x528,point);ref_write(memory,actor+0x534,normal);memory[actor+0x540]=1;
        SET_GPR_U32(c,2,code);record(GPR_U32(c,5));break;
    }
    case 0x666f50: SET_GPR_U32(c,2,alignment_value);record(GPR_U32(c,5));break;
    case 0x663190: SET_GPR_U32(c,2,0);guest_calls.emplace_back(at,(GPR_U32(c,5)<<8)|GPR_U32(c,6));break;
    case 0x1b0340: SET_GPR_U32(c,2,local_value);break;
    case 0x64ef10: SET_GPR_U32(c,2,0);break;
    case 0x6507f0: SET_GPR_U32(c,2,equipment_value);record(0);break;
    case 0x6506c0: SET_GPR_U32(c,2,equipment_consume);record(GPR_U32(c,5));break;
    case 0x1b0310: SET_GPR_S32(c,2,message_phase);break;
    case 0x6af8b0:case 0x6af9e0: SET_GPR_S32(c,2,admission_value);record(at==0x6af8b0?GPR_U32(c,5):0);break;
    case 0x570080: SET_GPR_U32(c,2,0);record(GPR_U32(c,5));break;
    case 0x667370: record(0);break;
    case 0x67e230: record(GPR_U32(c,5));break;
    case 0x67ff80: record((GPR_U32(c,5)<<8)|GPR_U32(c,6));break;
    case 0x370100: c->f[0]=reo::native::transform_math::sin_cos(reo::native::transform_math::radians(std::uint16_t(GPR_U32(c,4)))).cosine;break;
    case 0x191df0:{const auto a=ref_read<std::array<float,3>>(memory,GPR_U32(c,4)),b=ref_read<std::array<float,3>>(memory,GPR_U32(c,5));c->f[0]=(a[0]*b[0]+a[1]*b[1])+a[2]*b[2];break;}
    default: record(0);SET_GPR_U32(c,2,0);break;
    }
    c->pc=GPR_U32(c,31);
}
namespace {
struct InteractionServices final:w::InteractionActionServices{
    w::Actor& actor;InteractionServices(w::Actor& a):actor(a){}
    w::ForwardContactResult forward_contact(w::World&,w::Actor&,std::uint32_t include,std::uint32_t exclude,float offset)override{
        const auto index=contact_index++;
        const auto code=std::uint16_t(index<contact_codes.size()?contact_codes[index]:0);
        actor.projectile_contact.point={10,20,30};actor.projectile_contact.normal={0,0,-1};actor.forward_contact_status=1;
        native_calls.emplace_back(0x65f4a0,std::bit_cast<std::uint32_t>(offset));
        check(include==0xffffffffu&&exclude==0,"forward probe masks");return{w::ForwardContactStatus::completed,code};
    }
    std::optional<bool> actor_query(w::World&,w::Actor&,std::uint8_t selector,std::uint8_t arg)override{
        native_calls.emplace_back(0x663190,(selector<<8)|arg);return false;
    }
    std::optional<std::int8_t> admit_actor(w::World&,w::Actor&)override{native_calls.emplace_back(0x6af9e0,0);return admission_value;}
    bool prepare_alignment(w::World&,w::Actor&,std::uint32_t limit,float offset)override{
        native_calls.emplace_back(0x666f50,(limit<<8)^std::bit_cast<std::uint32_t>(offset));return alignment_value;
    }
    bool activate(w::World&,w::Actor&)override{native_calls.emplace_back(0x667370,0);return true;}
    bool notify(w::World&,w::Actor&,std::uint8_t selector)override{native_calls.emplace_back(0x67e230,selector);return true;}
    std::optional<bool> consume_request(w::World&,w::Actor&)override{return false;}
};
struct ControlServices final:w::ControlRequestFlowServices{
    std::optional<bool> query_actor(w::World&,w::Actor&,std::uint8_t selector)override{native_calls.emplace_back(0x663190,selector);return false;}
    std::optional<std::uint32_t> prepare_equipment(w::World&,w::Actor&)override{native_calls.emplace_back(0x6507f0,0);return equipment_value;}
    bool consume_equipment(w::World&,w::Actor&,std::uint32_t value)override{native_calls.emplace_back(0x6506c0,value);return equipment_consume;}
    bool activate_action(w::World&,w::Actor&)override{native_calls.emplace_back(0x667370,0);return true;}
    bool notify(w::World&,w::Actor&,std::uint8_t selector)override{native_calls.emplace_back(0x67e230,selector);return true;}
    std::optional<std::int8_t> admit_control(w::World&,w::Actor&,std::uint8_t selector)override{native_calls.emplace_back(0x6af8b0,selector);return admission_value;}
    std::optional<std::int8_t> admit_actor(w::World&,w::Actor&)override{native_calls.emplace_back(0x6af9e0,0);return admission_value;}
    bool publish_control(w::World&,w::Actor&,std::uint8_t selector,std::uint8_t value)override{native_calls.emplace_back(0x67ff80,(selector<<8)|value);return true;}
    bool request_resource(w::World&,w::Actor&,std::uint8_t request)override{native_calls.emplace_back(0x570080,request);return true;}
};
template<class T>void put(unsigned off,T value){ref_write(ram.data(),actor_at+off,value);}
void actor_prefix(const w::Actor& a){
    put(2,a.category);put(3,a.slot);put(8,a.primary);put(9,a.secondary);put(10,a.phase);put(11,a.subphase);
    put(0x38,std::array<float,3>{a.position.x,a.position.y,a.position.z});put(0x92,a.orientation[1]);
    put(0xba0,a.status);put(0x54f,a.motion_class);put(0xb98,a.character);put(0xb9b,a.class_marker);
    put(0x174,a.surface_kind);put(0xf78,a.input.pressed);put(0xf80,a.input.held);
    put(0xab8,a.transient_action);put(0xad4,a.transient_equipment);put(0xff0,a.ai_control);
    put(0xa8,std::array<float,3>{a.candidate_direction.x,a.candidate_direction.y,a.candidate_direction.z});
    put(0x528,std::array<float,3>{a.projectile_contact.point.x,a.projectile_contact.point.y,a.projectile_contact.point.z});
    put(0x534,std::array<float,3>{a.projectile_contact.normal.x,a.projectile_contact.normal.y,a.projectile_contact.normal.z});
    put(0x540,a.forward_contact_status.value_or(0));put(0xcde,a.forward_contact_attempts.value_or(0));
    put(0x544,a.current);put(0xc74,a.interaction_control_request->pending);
    put(0xc75,a.interaction_control_request->variant);put(0xc76,a.interaction_control_request->parameter);
    put(0xc78,a.interaction_kind);put(0xcb0,a.interaction_control_selector.value_or(0));
}
void compare_actor(const w::Actor& a){
    check(ref_read<std::uint8_t>(ram.data(),actor_at+2)==a.category,"category");
    for(const auto [off,value,name]:std::array<std::tuple<unsigned,std::uint8_t,const char*>,4>{{{8,a.primary,"primary"},{9,a.secondary,"secondary"},{10,a.phase,"phase"},{11,a.subphase,"subphase"}}})
        check(ref_read<std::uint8_t>(ram.data(),actor_at+off)==value,name);
    check(ref_read<std::uint32_t>(ram.data(),actor_at+0xba0)==a.status,"status");
    check(ref_read<std::uint16_t>(ram.data(),actor_at+0xcde)==a.forward_contact_attempts.value_or(0),"CDE");
    check(ref_read<std::int16_t>(ram.data(),actor_at+0x544)==a.current,"544");
    check(ref_read<std::uint8_t>(ram.data(),actor_at+0xc74)==a.interaction_control_request->pending,"C74");
    check(ref_read<std::uint8_t>(ram.data(),actor_at+0xc75)==a.interaction_control_request->variant,"C75");
    check(ref_read<std::uint8_t>(ram.data(),actor_at+0xc76)==a.interaction_control_request->parameter,"C76");
}
void run_interaction(w::World& world,unsigned case_id,std::uint16_t first,std::uint16_t second,
                     std::uint8_t pressed,std::uint8_t held,std::uint32_t status,bool align,bool local,std::uint16_t timer){
    ++cases;contact_codes={first,second};contact_index=0;alignment_value=align;local_value=local;guest_calls.clear();native_calls.clear();
    auto made=std::make_unique<w::Actor>();made->slot=0;made->active=true;made->category=0;made->status=status;
    made->primary=7;made->secondary=8;made->phase=9;made->subphase=10;made->class_marker=0;made->surface_kind=0;made->motion_class=0;
    made->input.pressed=pressed;made->input.held=held;made->candidate_direction={0,0,1};made->position={1,2,3};
    made->projectile_contact={{0,0,0},{0,0,-1}};made->forward_contact_attempts=timer;made->forward_contact_status=0;
    const auto id=world.spawn_primary(0,std::move(made)).id;auto actor=world.resolve(id);actor_prefix(*actor);
    auto original=context(0x64e960);SET_GPR_U32(&original,4,actor_at);SET_GPR_U32(&original,29,0x30000);SET_GPR_U32(&original,31,finish_pc);PS2Runtime runtime;
    o2_0064E960_0x64e960(ram.data(),&original,&runtime);check(original.pc==finish_pc,"64E960 return");
    native_calls.clear();contact_index=0;InteractionServices services(*actor);const auto result=w::process_interaction_action(world,*actor,services);
    check(result.status==w::InteractionActionStatus::completed,"64E960 native completion");
    check(result.original_result==(GPR_U32(&original,2)!=0),"64E960 result");compare_actor(*actor);
    world.retire_primary(0);
}
void run_control(w::World& world,unsigned case_id,std::uint32_t status,std::int16_t gate,std::uint8_t kind,
                 std::uint8_t pending,std::uint8_t variant,std::uint8_t parameter,std::uint8_t category,
                 std::uint8_t transient_equipment,std::uint32_t equipment,std::int8_t phase){
    ++cases;contact_index=0;equipment_value=equipment;message_phase=phase;guest_calls.clear();native_calls.clear();
    world.session().message_phase=phase;
    auto made=std::make_unique<w::Actor>();made->slot=0;made->category=category;made->active=true;made->status=status;
    made->primary=7;made->secondary=8;made->phase=9;made->subphase=10;made->current=gate;
    made->interaction_kind=kind;made->transient_equipment=transient_equipment;
    made->interaction_control_request=w::InteractionControlRequest{pending,variant,parameter};made->interaction_control_selector=5;
    const auto id=world.spawn_primary(0,std::move(made)).id;auto actor=world.resolve(id);actor_prefix(*actor);
    auto original=context(0x64f2d0);SET_GPR_U32(&original,4,actor_at);SET_GPR_U32(&original,29,0x30000);SET_GPR_U32(&original,31,finish_pc);PS2Runtime runtime;
    o2_0064F2D0_0x64f2d0(ram.data(),&original,&runtime);check(original.pc==finish_pc,"64F2D0 return");
    native_calls.clear();ControlServices services;const auto result=w::process_control_request(world,*actor,services);
    check(result.status==w::ControlRequestFlowStatus::completed,"64F2D0 native completion");
    if(result.original_result!=(GPR_U32(&original,2)!=0))std::fprintf(stderr,"64F2D0 mismatch seed=%u source=%u native=%u status=%08x gate=%d kind=%u pending=%u category=%u equipment=%u phase=%d\\n",case_id,GPR_U32(&original,2),unsigned(result.original_result),status,int(gate),unsigned(kind),unsigned(pending),unsigned(category),unsigned(equipment),int(phase));
    check(result.original_result==(GPR_U32(&original,2)!=0),"64F2D0 result");compare_actor(*actor);
    world.retire_primary(0);
}
}
void o2_0064E960_0x64e960(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_0064F2D0_0x64f2d0(std::uint8_t*,R5900Context*,PS2Runtime*);
int main(int argc,char** argv)try{
    check(argc==1,"fixture invocation");
    w::Profile profile;profile.layouts.push_back({0x100,0x10,0x20});w::World world(std::move(profile),std::make_shared<w::Session>());world.selected_actor=0;world.mode=1;
    constexpr std::array<std::uint16_t,11> responses{0,2,4,8,0x10,0x20,0x40,0x80,0x100,0x200,0x800};
    for(auto response:responses)
        for(auto pressed:std::array<std::uint8_t,2>{0,0x20})for(bool align:{false,true})run_interaction(world,cases,response,2,pressed,1,0,align,true,7);
    run_interaction(world,cases,2,2,0,1,0,false,true,59);run_interaction(world,cases,2,2,0,1,0,false,true,0);
    run_interaction(world,cases,0x20,2,0x20,1,0x4000,false,true,3);
    for(unsigned seed=0;seed<256;++seed){const auto status=std::array<std::uint32_t,8>{0,8,0x80,0x90,0x100,0x200,0x4000,0x3e8}[seed%8];
        run_control(world,cases,status,seed%3?0:1,std::uint8_t(seed%4),std::uint8_t(seed%2),std::uint8_t(seed%3),std::uint8_t(seed),std::uint8_t(seed%3),std::uint8_t(seed%2),seed%4?0:1,std::int8_t(seed%4));}
    std::printf("{\"checks\":%u,\"cases\":%u,\"full_original_bodies\":2,\"game_run\":false}\n",checks,cases);return 0;
}catch(const std::exception& e){std::fprintf(stderr,"%s\n",e.what());return 1;}
