#include "game/native/gameplay_update/update.hpp"
#include "reference.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include "functions.h"
namespace s=reo::native::gameplay_scenario;
namespace w=reo::native::gameplay_world;
namespace t=reo::native::gameplay_tasks;
namespace u=reo::native::gameplay_update;
std::uint64_t checks{},cases{},calls{},passes{},presentations{},registrations{},retirements{};
std::vector<s::TimerHudGlyph> sprites;
unsigned setup_calls{},restores{};
std::string trial_context;
void check(bool v,const char* m){++checks;if(!v)throw std::runtime_error(m);}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;
    switch(context->pc){
    case 0x107c68:std::memset(memory+GPR_U32(context,4),GPR_U32(context,5),GPR_U32(context,6));SET_GPR_U32(context,2,GPR_U32(context,4));break;
    case 0x1afa00:check(GPR_U32(context,4)==0x5ba530,"actual presentation registration");++registrations;break;
    case 0x1afa70:check(GPR_U32(context,4)==0x5ba530,"actual presentation retirement");++retirements;break;
    case 0x1cd250:check(GPR_U32(context,4)==0x2500,"HUD texture");SET_GPR_U32(context,2,0x12340000);++setup_calls;break;
    case 0x1af780:if(GPR_U32(context,4)==0x6c){if(GPR_U32(context,5))++setup_calls;else ++restores;}else{check(GPR_U32(context,4)==4&&GPR_U32(context,5)==0x12340000,"texture binding");++setup_calls;}break;
    case 0x1af1e0:check(GPR_U32(context,4)==4&&GPR_U32(context,5)==5,"blend");++setup_calls;break;
    case 0x19d720:check(GPR_U32(context,4)==1&&transform_read<std::uint32_t>(memory,GPR_U32(context,5))==0x12340000,"texture translation");++setup_calls;break;
    case 0x1af230:check(GPR_U32(context,4)==0,"primitive mode");++setup_calls;break;
    case 0x1ab860:sprites.push_back(transform_read<s::TimerHudGlyph>(memory,GPR_U32(context,4)));break;
#include "original_dispatch.hpp"
    default:throw std::runtime_error("Undeclared scenario event call "+std::to_string(context->pc));
    }
    context->pc=GPR_U32(context,31);
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#include "original.cpp"
#pragma GCC diagnostic pop
struct Notifications:s::FlagNotifications{
    bool changed(const s::ScenarioFlagChange&)noexcept override{std::terminate();}
    bool changed(const s::StridedFlagChange&)noexcept override{std::terminate();}
};
w::Profile profile(){w::Profile p;p.layouts.push_back({});return p;}
constexpr std::uint32_t base=0x3b64d0,stride=272,payload=0x100000;
void call(std::vector<std::uint8_t>& memory,std::uint32_t address,std::uint32_t a0=0){
    R5900Context context;PS2Runtime runtime;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x123456);SET_GPR_U32(&context,4,a0);context.pc=address;
    original_transform_port(memory.data(),&context,&runtime);check(context.pc==0x123456,"whole original callback returned");
}
template<class T>void put(std::array<std::uint8_t,stride>& record,unsigned at,T value){std::memcpy(record.data()+at,&value,sizeof value);}
void compare(u::Owner& owner,const std::vector<std::uint8_t>& memory){
    for(unsigned bank=0;bank<3;++bank)for(unsigned slot=0;slot<10;++slot){
        std::array<std::uint8_t,stride> record{};const auto state=owner.scenario_events().inspect(bank,slot);
        if(state){const auto view=owner.events().slot(bank,slot);check(view&&view->enabled,"owned active task");
            put(record,0,std::uint8_t(1));put(record,1,state->slot);put(record,2,state->kind);put(record,3,state->render_style);put(record,4,state->phase);put(record,5,state->pulse.falling);
            put(record,0xc,state->pulse.value);put(record,0xe,state->pulse.delta);put(record,0x1c,bank?0x5baed0u:0x5ba470u);
            for(unsigned i=0;i<5;++i)put(record,0x60+4*i,state->arguments[i]);
            put(record,0x100,state->owner_selector);
        }
        if(std::memcmp(record.data(),memory.data()+base+stride*(bank*10+slot),stride)){
            for(unsigned i=0;i<stride;++i)if(record[i]!=memory[base+stride*(bank*10+slot)+i])
                throw std::runtime_error(trial_context+" whole event mismatch bank "+std::to_string(bank)+" slot "+std::to_string(slot)+" offset "+std::to_string(i)+" native "+std::to_string(record[i])+" original "+std::to_string(memory[base+stride*(bank*10+slot)+i]));
        }
        check(true,"all272 bytes of all30 canonical records");
    }
    check(owner.world().selected_actor==memory[0x4baded],"canonical selection preserved/reset");
}
void flag(u::Owner& owner,std::vector<std::uint8_t>& memory,unsigned id,bool enabled){
    check(owner.flags().write(s::FlagBank::local_primary,id,enabled),"canonical local-primary flag write");
    check(owner.flags().write(s::FlagBank::scenario,id,!enabled),"distinct shared scenario flag");
    const auto& flags=owner.flags().snapshot();std::memcpy(memory.data()+0x4b9c00,flags.shared.scenario.data(),64);
    for(unsigned bank=0;bank<3;++bank)std::memcpy(memory.data()+0x4b9a80+64*bank,flags.primary[bank].data(),64);
}
void command(u::Owner& owner,std::vector<std::uint8_t>& memory,unsigned kind,unsigned slot,std::array<std::uint32_t,5> args){
    trial_context+=" command";
    transform_write(memory.data(),payload,kind);transform_write(memory.data(),payload+4,slot);for(unsigned i=0;i<5;++i)transform_write(memory.data(),payload+8+4*i,args[i]);
    check(owner.scenario_events().command(kind,slot,args)==s::ScenarioEventStatus::completed,"native complete D1 command");call(memory,0x691010,payload);compare(owner,memory);
}
void update(u::Owner& owner,std::vector<std::uint8_t>& memory){
    trial_context+=" update";
    auto selection=t::OwnerSelection::borrow(owner.world().selected_actor);check(owner.events().run(owner.world().mode==0?t::EventMode::owner_banks:t::EventMode::shared_bank,selection).status==t::Status::completed,"canonical event pass");
    call(memory,0x5b91b0);compare(owner,memory);check(owner.scenario_events().failure()==s::ScenarioEventStatus::completed,"no hidden task failure");++passes;
}
void present(u::Owner& owner,std::vector<std::uint8_t>& memory){
    trial_context+=" present";
    sprites.clear();setup_calls=restores=0;const auto native=owner.scenario_events().present_timer_hud();check(native.status==s::ScenarioEventStatus::completed,"presentation status");
    const bool requested=transform_read<std::uint32_t>(memory.data(),0x3b64bc)!=0;
    if(requested){call(memory,0x5ba530);check(native.frame.has_value(),"registered native frame");const auto& frame=*native.frame;
        check(setup_calls==6&&frame.count==sprites.size()&&frame.restore==(restores==1),"complete renderer setup/restore policy");
        check(frame.acknowledge==!transform_read<std::uint32_t>(memory.data(),0x3b64bc),"presentation acknowledgement");
        for(unsigned i=0;i<frame.count;++i)check(frame.glyphs[i]==sprites[i],"exact20-byte sprite");
    }else check(!native.frame,"no pending presentation");
    compare(owner,memory);++presentations;
}
void cohort(std::vector<std::uint8_t>& memory,unsigned mode,unsigned selected,unsigned slot){
    trial_context="mode="+std::to_string(mode)+" selected="+std::to_string(selected)+" slot="+std::to_string(slot);
    std::memset(memory.data()+base,0,30*stride);std::memset(memory.data()+0x3b64b0,0,24);std::memset(memory.data()+0x4b9a80,0,64);
    memory[0x3243f2]=std::uint8_t(mode);memory[0x4baded]=std::uint8_t(selected);memory[0x4badee]=1;
    Notifications notifications;w::World world(profile(),std::make_shared<w::Session>());world.mode=std::uint8_t(mode);world.selected_actor=std::uint8_t(selected);world.session().inventory_owner=1;u::Owner owner(world,notifications);
    for(unsigned i=0;i<8;++i){const auto value=std::int16_t(i==7?-32768:5399-i*631);check(owner.timers().arm(i,value,{})==t::Status::completed,"canonical timer arm");transform_write(memory.data(),0x4bad88+2*i,value);}
    flag(owner,memory,42,true);std::array<std::uint32_t,5> args{slot%8,255,42,43,44};command(owner,memory,6,slot,args);
    auto changed=args;changed[0]=7;changed[2]=511;command(owner,memory,6,slot,changed); // occupied source record returns before mutation.
    update(owner,memory);present(owner,memory);
    world.session().inventory_owner=0;memory[0x4badee]=0;update(owner,memory);present(owner,memory);present(owner,memory);
    flag(owner,memory,43,true);update(owner,memory);present(owner,memory);present(owner,memory); // hidden selector returns without ack.
    flag(owner,memory,44,true);for(unsigned i=0;i<20;++i){update(owner,memory);present(owner,memory);}
    flag(owner,memory,42,false);update(owner,memory);present(owner,memory);
    // Two live records compete for the actual sole slot1 registration.
    world.selected_actor=0;memory[0x4baded]=0;flag(owner,memory,42,true);flag(owner,memory,43,false);flag(owner,memory,44,false);
    command(owner,memory,6,0,args);auto second=args;second[2]=45;second[0]=7;flag(owner,memory,45,true);command(owner,memory,6,9,second);update(owner,memory);present(owner,memory);
    flag(owner,memory,42,false);update(owner,memory);present(owner,memory);flag(owner,memory,45,false);update(owner,memory);present(owner,memory);
    for(unsigned bank=0;bank<3;++bank)for(unsigned index=0;index<10;++index)if(memory[base+stride*(bank*10+index)])call(memory,0x5b93b0,base+stride*(bank*10+index));
    check(owner.scenario_events().close()==s::ScenarioEventStatus::completed,"explicit event retirement");compare(owner,memory);check(!owner.scenario_events().ready(),"closed admission");++cases;
}
int main(int argc,char** argv)try{
    check(argc==2,"owned tables required");std::ifstream input(argv[1],std::ios::binary);std::array<std::uint8_t,176> constants{};input.read(reinterpret_cast<char*>(constants.data()),constants.size());check(bool(input),"complete original callback and glyph tables");
    std::vector<std::uint8_t> memory(0x2000000);std::memcpy(memory.data()+0x70a180,constants.data(),constants.size());sprites.reserve(8);
    for(auto mode:{0u,1u,2u,255u})for(auto selected:{0u,1u,2u,3u,7u,255u})for(auto slot:{0u,4u,7u,9u})cohort(memory,mode,selected,slot);
    check(!s::ScenarioEvents::admits(0,0,{})&&!s::ScenarioEvents::admits(6,10,{})&&!s::ScenarioEvents::admits(6,0,{0xffffffffu,0,0,0,0}),"unsupported callback/slot/read profile refuses");
    std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"passes\":"<<passes<<",\"presentations\":"<<presentations<<",\"registrations\":"<<registrations<<",\"retirements\":"<<retirements<<",\"original_calls\":"<<calls<<",\"game_launched\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
