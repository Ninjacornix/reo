#include "game/native/gameplay_world/pose_presets.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <iostream>
#include <source_location>
namespace g=reo::native::gameplay_world;namespace m=reo::native::transform_math;
unsigned checks{},cases{},calls{},packets{},allocations{};constexpr unsigned work_at=0x20000,owner_at=0x22000,basis_at=0x24000,point_at=0x25000,angles_at=0x26000;
void check(bool value,std::source_location p=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Pose preset "+std::to_string(p.line())+" case "+std::to_string(cases));}
template<class T>T get(const std::uint8_t* p,unsigned at){return transform_read<T>(p,at);}template<class T>void put(std::uint8_t* p,unsigned at,T value){transform_write(p,at,value);}
struct Effects final:g::PresetPosePacket{std::vector<std::int32_t> descriptors;bool accepted{true};bool packet(const g::actors::EntityId&,std::int32_t descriptor)override{descriptors.push_back(descriptor);return accepted;}}effects;
std::vector<std::int32_t> original_descriptors;
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;switch(context->pc){
    case 0x581fe0:check(GPR_U32(context,4)==1);++allocations;SET_GPR_U32(context,2,work_at);break;
    case 0x5da2c0:check(GPR_U32(context,4)==work_at&&GPR_U32(context,6)==1);original_descriptors.push_back(std::int32_t(GPR_U32(context,5)));++packets;break;
#include "original_dispatch.hpp"
    default:throw std::runtime_error("Unadmitted preset helper "+std::to_string(context->pc));
    }context->pc=GPR_U32(context,31);
}
int main()try{
    std::vector<std::uint8_t> ram(0x2000000);auto* memory=ram.data();owned_constants(memory);g::actors::EntityStore identities({2});const auto work_id=identities.create(std::make_unique<g::actors::Entity>()).id,owner_id=identities.create(std::make_unique<g::actors::Entity>()).id;check(bool(work_id)&&bool(owner_id));
    for(bool attach:{false,true})for(unsigned n=0;n<65536;++n){
        g::Actor actor;actor.pose_work.emplace();m::Matrix basis;std::array<std::int16_t,4> angles;const unsigned descriptor=(n%14)|((n*197u)<<8),variant=n*31337u,remaining=n%64;
        for(unsigned c=0;c<4;++c){angles[c]=std::bit_cast<std::int16_t>(std::uint16_t(n*(c+3)));for(unsigned r=0;r<4;++r)basis[c][r]=std::bit_cast<float>(n*314159u+c*37+r*307);}
        const m::Vector point{float(int(n%17)-8)*.25f,float(int(n%19)-9)*.125f,float(int(n%23)-11)*.5f};effects.descriptors.clear();original_descriptors.clear();
        std::memset(memory+work_at,0,0x1f0);put(memory,owner_at+0x1e2,std::uint16_t(n));put(memory,0x3243dc,std::uint16_t(n));put(memory,0x3b55e0,std::int16_t(remaining));put(memory,basis_at,basis);put(memory,point_at,point);put(memory,angles_at,angles);
        R5900Context context;PS2Runtime runtime;context.pc=attach?0x582720:0x5828c0;SET_GPR_U32(&context,4,owner_at);SET_GPR_U32(&context,5,basis_at);SET_GPR_U32(&context,6,point_at);SET_GPR_U32(&context,7,angles_at);SET_GPR_U32(&context,8,descriptor);SET_GPR_U32(&context,9,variant);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x1234);original_transform_port(memory,&context,&runtime);check(context.pc==0x1234&&GPR_U32(&context,29)==0x1f00000);
        check(g::prepare_preset_pose(actor,work_id,owner_id,basis,point,angles,descriptor,variant,remaining,attach,effects));const auto& state=*actor.pose_work;
        check(actor.active==bool(memory[work_at])&&actor.visible==bool(memory[work_at+1])&&actor.category==memory[work_at+2]&&actor.slot==memory[work_at+3]);
        check(state.kind==memory[work_at+4]&&state.variant==memory[work_at+5]&&state.selector==memory[work_at+0x30]&&state.ordinal==memory[work_at+0x31]&&state.lifetime==get<std::int16_t>(memory,work_at+18));
        check(state.update_bound&&get<unsigned>(memory,work_at+0x14)==0x582b80&&get<unsigned>(memory,work_at+0x18)==0x371ef0);
        check(actor.contact.related==owner_id&&state.emitter_owner==owner_id&&get<unsigned>(memory,work_at+0x24)==owner_at&&get<unsigned>(memory,work_at+0x28)==owner_at);
        check(std::memcmp(&actor.position,memory+work_at+0x38,12)==0&&std::memcmp(&state.basis,memory+work_at+0x50,64)==0&&std::memcmp(actor.orientation.data(),memory+work_at+0x90,8)==0&&std::memcmp(&state.velocity,memory+work_at+0xc0,12)==0);
        check(effects.descriptors==original_descriptors);++cases;
    }
    g::Actor rejected;rejected.pose_work.emplace();rejected.pose_work->lifetime=9;effects.accepted=false;check(!g::prepare_preset_pose(rejected,work_id,owner_id,{}, {},{},0,0,63,true,effects)&&rejected.pose_work->lifetime==180&&rejected.pose_work->emitter_owner==owner_id);
    for(unsigned n=14;n<256;++n){g::Actor unknown;unknown.pose_work.emplace();check(!g::prepare_preset_pose(unknown,work_id,owner_id,{}, {},{},n,0,63,true,effects)&&unknown.active&&unknown.category==9&&unknown.slot==n&&!unknown.pose_work->update_bound);}
    std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"allocations\":"<<allocations<<",\"packets\":"<<packets<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
