#include "game/native/gameplay_update/update.hpp"
#include "game/native/gameplay_effects/periodic_visuals.hpp"
#include "original_fixture.hpp"
#include "original_declarations.inc"
#include <fstream>
#include <iostream>
#include <source_location>
#include <tuple>
namespace s=reo::native::gameplay_scenario;
namespace w=reo::native::gameplay_world;
namespace u=reo::native::gameplay_update;
namespace e=reo::native::gameplay_effects;
namespace t=reo::native::gameplay_tasks;
namespace {
std::size_t checks{},constructors{},callbacks{},impact_cases{},refusals{};
std::array<bool,22> puzzle_rows{};
std::string context;
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("D0 check "+std::to_string(at.line())+" "+context);
}
using Notice=std::tuple<std::uint32_t,std::uint32_t,std::uint32_t>;
std::vector<Notice> original_notices;
struct Notices:s::FlagNotifications{
    std::vector<Notice> values;
    bool changed(const s::ScenarioFlagChange& v)noexcept override{values.emplace_back(v.id,v.value,v.actor_owner);return true;}
    bool changed(const s::StridedFlagChange&)noexcept override{std::terminate();}
};
std::vector<std::uint32_t> original_effects;
unsigned remaining{},created{};
void put(std::vector<std::byte>& bytes,std::uint32_t value){for(unsigned i=0;i<4;++i)bytes.push_back(std::byte((value>>(8*i))&255));}
std::shared_ptr<const s::Program> program(unsigned kind,unsigned slot,const std::array<std::uint32_t,5>& args,bool offline,bool prefix=false){
    std::vector<std::byte> bytes;put(bytes,1);
    if(prefix){put(bytes,0x02000110);put(bytes,0);put(bytes,77);put(bytes,0);}
    put(bytes,0x030000d0);put(bytes,kind);put(bytes,slot);for(auto arg:args)put(bytes,arg);put(bytes,0xa);
    return std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{bytes},offline?s::DispatchProfile::offline_actor:s::DispatchProfile::ordinary);
}
void call(std::vector<std::uint8_t>& memory,unsigned pc,unsigned arg){
    R5900Context c;PS2Runtime r;c.pc=pc;SET_GPR_U32(&c,4,arg);SET_GPR_U32(&c,29,0x800000);SET_GPR_U32(&c,31,0x100);
    original_transform_port(memory.data(),&c,&r);check(c.pc==0x100);
}
void export_flags(std::vector<std::uint8_t>& m,const s::FlagStateSnapshot& flags){
    std::memcpy(m.data()+0x4b9c00,flags.shared.scenario.data(),64);std::memcpy(m.data()+0x4b9c40,flags.shared.secondary.data(),64);
    std::memcpy(m.data()+0x4b9a80,flags.primary.data(),192);std::memcpy(m.data()+0x4b9b40,flags.auxiliary.data(),192);
    std::memcpy(m.data()+0x4baa50,flags.scenario_owners.data(),512);
}
void compare_flags(const std::vector<std::uint8_t>& m,const s::FlagStateSnapshot& flags){
    check(std::memcmp(m.data()+0x4b9c00,flags.shared.scenario.data(),64)==0);check(std::memcmp(m.data()+0x4b9c40,flags.shared.secondary.data(),64)==0);
    check(std::memcmp(m.data()+0x4b9a80,flags.primary.data(),192)==0);check(std::memcmp(m.data()+0x4b9b40,flags.auxiliary.data(),192)==0);
    check(std::memcmp(m.data()+0x4baa50,flags.scenario_owners.data(),512)==0);
}
void compare_tasks(u::Owner& owner,const std::vector<std::uint8_t>& m){
    for(unsigned bank=0;bank<3;++bank)for(unsigned slot=0;slot<10;++slot){
        std::array<std::uint8_t,272> expected{};const auto state=owner.scenario_events().inspect(std::uint8_t(bank),std::uint8_t(slot));
        if(state){expected[0]=1;expected[1]=state->slot;expected[2]=state->kind;expected[0x100]=state->owner_selector;
            const auto callback=*state->scenario==2?0x5a0ba0u:*state->scenario==35?0x5b69a0u:0x6fabf0u;
            std::memcpy(expected.data()+0x1c,&callback,4);std::memcpy(expected.data()+0x60,state->arguments.data(),20);
        }
        const auto* actual=m.data()+0x3b64d0+272*(bank*10+slot);
        for(unsigned i=0;i<272;++i)if(expected[i]!=actual[i])throw std::runtime_error("D0 record bank="+std::to_string(bank)+" slot="+std::to_string(slot)+" byte="+std::to_string(i)+" native="+std::to_string(expected[i])+" original="+std::to_string(actual[i])+" "+context);
        check(true);
    }
}
}
void original_transform_port(std::uint8_t* m,R5900Context* c,PS2Runtime* r){
    switch(c->pc){
#include "original_lookup.inc"
    case 0x107c68:check(GPR_U32(c,5)==0&&GPR_U32(c,6)==272);std::memset(m+GPR_U32(c,4),0,272);SET_GPR_U32(c,2,GPR_U32(c,4));break;
    case 0x6525c0:case 0x6525d0:{
        const auto effect=GPR_U32(c,7);check(effect==40||effect==41||effect==42);original_effects.push_back(effect);
        const auto point=transform_read<reo::native::transform_math::Vector>(m,GPR_U32(c,5));check(point.x==4400&&point.y==-3600&&point.z==8729);
        check(GPR_U32(c,9)==0x1a193);check(GPR_U32(c,6)==(effect==42?0u:0xffffffffu));
        const auto address=remaining?0x600000u+0x300u*created++:0u;if(remaining)--remaining;
        SET_GPR_U32(c,2,address);break;
    }
    default:throw std::runtime_error("Unexecuted D0 dependency "+std::to_string(c->pc));
    }
    c->pc=GPR_U32(c,31);
}
int main(int argc,char** argv)try{
    check(argc==2);std::ifstream source(argv[1],std::ios::binary);std::uint32_t count{};source.read(reinterpret_cast<char*>(&count),4);check(count==12);
    const auto member=[&](){std::uint32_t size{};source.read(reinterpret_cast<char*>(&size),4);check(size>0&&size<0x200000);std::vector<std::byte> bytes(size);source.read(reinterpret_cast<char*>(bytes.data()),size);check(bool(source));return bytes;};
    std::vector<std::shared_ptr<const e::EffectBank>> banks;
    for(unsigned i=0;i<6;++i){const auto nbd=member(),data=member();banks.push_back(e::EffectBank::import(nbd,data));}
    std::vector<std::uint8_t> memory(0x900000);
    for(unsigned scenario:{2u,35u,41u})for(unsigned kind:scenario==35?std::vector{11u,19u}:std::vector{scenario==2?15u:9u})
    for(unsigned mode:{0u,1u,2u})for(unsigned selected=0;selected<4;++selected)for(unsigned trial=0;trial<24;++trial){
        context="scenario="+std::to_string(scenario)+" kind="+std::to_string(kind)+" mode="+std::to_string(mode)+" selected="+std::to_string(selected)+" trial="+std::to_string(trial);
        w::Profile profile;profile.layouts.push_back({});w::World world(profile,std::make_shared<w::Session>());world.mode=std::uint8_t(mode);world.selected_actor=std::uint8_t(selected);world.scenario=std::uint16_t(scenario);
        Notices notices;u::Owner owner(world,notices);
        std::fill(memory.begin(),memory.end(),0);original_constants(memory.data());memory[0x3243f2]=std::uint8_t(mode);memory[0x4baded]=std::uint8_t(selected);transform_write(memory.data(),0x3243da,std::uint16_t(scenario));
        for(unsigned i=0;i<8;++i){auto actor=std::make_unique<w::Actor>();actor->slot=std::uint8_t(i);actor->active=(trial+i)%5!=0;
            actor->status=std::array{0u,8u,0x20u,0x80u,0x5e0u}[((trial/4)+i)%5];actor->motion_style=std::uint8_t(trial*13+i);
            actor->room=std::array{20u,23u,24u,27u,28u,30u,19u,26u}[(trial+i)%8];const auto at=0x4a5c30+i*0x10e0;
            memory[at]=actor->active?0x80:0;memory[at+0xb99]=actor->motion_style;transform_write(memory.data(),at+0xba0,actor->status);transform_write(memory.data(),at+0x1e2,actor->room);
            check(world.spawn_primary(i,std::move(actor)).status==reo::native::gameplay_actors::EntityStatus::completed);
        }
        s::FlagStateSnapshot flags;
        for(unsigned i=0;i<16;++i){flags.shared.scenario[i]=0x13579bdfu^(trial*0x12345u+i);flags.shared.secondary[i]=0x98765432u+i;
            for(unsigned j=0;j<3;++j){flags.primary[j][i]=0x2468ace0u+trial+j+i;flags.auxiliary[j][i]=0x12345678u+trial+j+i;}}
        flags.shared.scenario[2]&=~(1u<<15);if(trial%7==0)flags.shared.scenario[2]|=1u<<15;
        for(unsigned i=0;i<512;++i)flags.scenario_owners[i]=std::uint8_t(trial+i);
        owner.flags().restore(flags);export_flags(memory,flags);
        world.session().random.restore({std::uint16_t(trial*2731),std::uint16_t(trial*65),std::uint8_t(trial)});
        if(scenario==2&&!(mode==0&&selected))puzzle_rows[world.session().random.state().secondary%22]=true;
        transform_write(memory.data(),0x3244b0,world.session().random.state().primary);transform_write(memory.data(),0x3244b8,world.session().random.state().secondary);memory[0x2b8de8]=std::uint8_t(trial);
        e::PeriodicVisuals visuals(banks[trial%6],world.session().random);check(owner.scenario_events().bind_effect_work(&visuals)==s::ScenarioEventStatus::completed);
        const unsigned holes=kind==11?std::array{0u,1u,2u,168u}[trial%4]:168u;
        if(kind==11)for(unsigned i=holes;i<168;++i){e::WorkRequest request;request.effect=40;request.position=reo::native::transform_math::Vector{};check(visuals.create(request).status==e::WorkStatus::completed);}
        const auto before_size=visuals.size();remaining=holes;created=0;original_effects.clear();original_notices.clear();
        const auto slot=kind==11?1u:kind==19?2u:kind==15?0u:6u;
        std::array<std::uint32_t,5> args=kind==19?std::array{trial%3==0?24u:19u,131u,132u,26u,15u}:std::array<std::uint32_t,5>{};
        transform_write(memory.data(),0x10000,kind|0xabcd0000u);transform_write(memory.data(),0x10004,slot|0xefab0000u);std::memcpy(memory.data()+0x10008,args.data(),20);
        call(memory,0x690ef0,0x10000);++constructors;
        check(owner.scripts().install(0,program(kind|0xabcd0000u,slot|0xefab0000u,args,mode==0))==s::Status::completed);
        check(owner.step_script(0).status==u::Status::completed);compare_tasks(owner,memory);
        // Occupied slots preserve the initial task and argument values.
        call(memory,0x690ef0,0x10000);check(owner.scenario_events().scenario_command(kind,slot,args)==s::ScenarioEventStatus::completed);compare_tasks(owner,memory);
        if(owner.events().size())check(owner.scenario_events().bind_effect_work(nullptr)==s::ScenarioEventStatus::busy);
        const auto bank=mode==0?selected:0u;
        if(bank<3){const auto event=0x3b64d0+272*(bank*10+slot);
            const auto callback=transform_read<std::uint32_t>(memory.data(),event+0x1c);call(memory,callback,event);++callbacks;}
        auto selection=t::OwnerSelection::borrow(world.selected_actor);check(owner.events().run(mode==0?t::EventMode::owner_banks:t::EventMode::shared_bank,selection).status==t::Status::completed);
        check(owner.scenario_events().failure()==s::ScenarioEventStatus::completed);compare_tasks(owner,memory);compare_flags(memory,owner.flags().snapshot());
        check(notices.values==original_notices);
        const auto random=world.session().random.state();check(random.primary==transform_read<std::uint16_t>(memory.data(),0x3244b0)&&random.secondary==transform_read<std::uint16_t>(memory.data(),0x3244b8));
        if(kind==11){check(visuals.size()==before_size+created);check(original_effects.size()==(mode==0&&selected?0u:3u));++impact_cases;}
        check(owner.scenario_events().close()==s::ScenarioEventStatus::completed);
    }
    for(bool covered:puzzle_rows)check(covered);
    {
        w::Profile profile;profile.layouts.push_back({});w::World world(profile,std::make_shared<w::Session>());world.mode=1;world.scenario=35;Notices notices;u::Owner owner(world,notices);
        check(owner.scripts().install(0,program(11,1,{},false,true))==s::Status::completed);
        check(owner.step_script(0).status==u::Status::script_failure&&owner.scripts().counters()[0]==0&&owner.events().size()==0);++refusals;
        check(program(11,1,{},false)->needs_scenario());
        // Source owner-bank alternates only retire and never touch effect work.
        for(unsigned selected:{1u,2u}){
            world.mode=0;world.selected_actor=std::uint8_t(selected);
            check(owner.scenario_events().scenario_ready(11,1,{}));
            check(owner.scripts().install(0,program(11,1,{},true))==s::Status::completed);
            check(owner.step_script(0).status==u::Status::completed&&owner.events().size()==1);
            auto selection=t::OwnerSelection::borrow(world.selected_actor);
            check(owner.events().run(t::EventMode::owner_banks,selection).status==t::Status::completed&&owner.events().size()==0);
            check(owner.scenario_events().failure()==s::ScenarioEventStatus::completed);
        }
        world.mode=1;world.selected_actor=0;
        e::PeriodicVisuals foreign(banks[0]);check(owner.scenario_events().bind_effect_work(&foreign)==s::ScenarioEventStatus::unavailable_owner);++refusals;
        world.scenario=41;check(owner.scenario_events().scenario_command(15,0,{})==s::ScenarioEventStatus::unavailable_owner);++refusals;
        for(const auto args:std::array<std::array<std::uint32_t,5>,3>{{{{19,0,512,26,15}},{{19,0,132,512,15}},{{19,0,132,26,512}}}}){bool failed=false;
            try{program(19,2,args,false);}catch(const std::invalid_argument&){failed=true;}check(failed);++refusals;}
    }
    std::cout<<"{\"checks\":"<<checks<<",\"constructors\":"<<constructors<<",\"callbacks\":"<<callbacks<<",\"real_impact_cases\":"<<impact_cases<<",\"refusals\":"<<refusals<<",\"game_launched\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
