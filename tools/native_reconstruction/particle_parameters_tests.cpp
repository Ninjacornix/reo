#include "game/native/gameplay_effects/periodic_visuals.hpp"
#include "reference.hpp"
#include "functions.h"
#include <fstream>
#include <iostream>
#include <source_location>
#include <vector>
namespace e=reo::native::gameplay_effects;namespace m=reo::native::transform_math;
unsigned checks{},cases{},calls{},banks{},child_checks{},refusals{};constexpr unsigned work_at=0x20000,policy_at=0x22000,children_at=0x30000;
void check(bool v,std::source_location p=std::source_location::current()){++checks;if(!v)throw std::runtime_error("Particle parameters "+std::to_string(p.line())+" case "+std::to_string(cases));}
template<class T>T get(const std::uint8_t* p,unsigned at){return transform_read<T>(p,at);}
template<class T>void put(std::uint8_t* p,unsigned at,T v){transform_write(p,at,v);}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;switch(context->pc){
#include "original_dispatch.hpp"
    default:throw std::runtime_error("Unadmitted particle parameter helper "+std::to_string(context->pc));
    }
}
void invoke(std::uint8_t* memory,unsigned pc,std::array<unsigned,4> args={}){R5900Context c;PS2Runtime r;c.pc=pc;SET_GPR_U32(&c,29,0x1f00000);SET_GPR_U32(&c,31,0x1234);for(unsigned i=0;i<4;++i)SET_GPR_U32(&c,4+i,args[i]);original_transform_port(memory,&c,&r);check(c.pc==0x1234&&GPR_U32(&c,29)==0x1f00000);}
std::vector<std::vector<std::byte>> corpus(const char* path){std::ifstream in(path,std::ios::binary);unsigned count{};in.read(reinterpret_cast<char*>(&count),4);check(count==12);std::vector<std::vector<std::byte>> out;for(unsigned i=0;i<count;++i){unsigned size{};in.read(reinterpret_cast<char*>(&size),4);check(size&&size<10000000);out.emplace_back(size);in.read(reinterpret_cast<char*>(out.back().data()),size);check(bool(in));}return out;}
int main(int argc,char** argv)try{
    check(argc==2);const auto assets=corpus(argv[1]);std::vector<std::uint8_t> ram(0x2000000);auto* memory=ram.data();
    for(unsigned asset=0;asset<assets.size();asset+=2){
        const auto bank=e::EffectBank::import(assets[asset],assets[asset+1]);reo::native::gameplay_session::Random random;e::PeriodicVisuals visuals(bank,random);const auto made=visuals.create({{},m::Vector{1,2,3},0,36,0,0x1a193,e::WorkUpdate::ordinary});check(made.status==e::WorkStatus::completed&&made.edit&&!visuals.particle_state(made.edit->identity()));const auto particle=std::dynamic_pointer_cast<e::ParticleEdit>(made.edit);check(bool(particle));const auto count=bank->bind(36,0).pieces.size();check(count<=16&&visuals.piece_count()==count);
        std::memset(memory+work_at,0,0x240);invoke(memory,0x652f00,{work_at,0});put(memory,work_at+0x200,0x1a193u);memory[work_at+0x31]=std::uint8_t(count);
        for(unsigned i=0;i<count;++i){const auto at=children_at+0x100*i;put(memory,work_at+0x134+4*i,at);put(memory,at+4,0x1a993u);put(memory,at+12,m::Vector{1,1,1});}
        for(unsigned n=0;n<65536;++n){
            std::array<float,6> policy{n%8==0?1.f:n%8==1?0.f:n%8==2?-2.f:float(n%17)*.125f,n%4==0?0.f:n%4==1?std::bit_cast<float>(0x80000000u):1.f,float(int(n%31)-15)*.25f,float(int(n%37)-18)*.0625f,float(int(n%41)-20)*.125f,float(n%47)*.03125f};
            const auto attributes=std::uint16_t(n*257);check(made.edit->set_attributes(attributes));put(memory,work_at+0x23e,attributes);put(memory,policy_at,policy);const auto delay=std::bit_cast<std::int16_t>(std::uint16_t(n*13));invoke(memory,0x578900,{work_at,n|0xabcd0000u,std::uint32_t(std::int32_t(delay)),policy_at});check(particle->configure_particle(std::uint8_t(n),delay,policy));const auto snapshot=visuals.particle_state(made.edit->identity());check(bool(snapshot));const auto& state=*snapshot;
            check(state.category==memory[work_at+3]&&state.mode==memory[work_at+4]&&state.delay==get<std::int16_t>(memory,work_at+12)&&state.attributes==get<std::uint16_t>(memory,work_at+0x23e)&&state.flags==get<unsigned>(memory,work_at+0x200));check(std::memcmp(&state.scale,memory+work_at+0xb4,12)==0&&std::memcmp(&state.parameters208,memory+work_at+0x208,12)==0&&std::bit_cast<unsigned>(state.opacity)==get<unsigned>(memory,work_at+0x214)&&std::bit_cast<unsigned>(state.feedback_scale)==get<unsigned>(memory,work_at+0xa8));check(state.child_count==count);
            for(unsigned i=0;i<count;++i){const auto at=children_at+0x100*i;check(state.children[i].flags==get<unsigned>(memory,at+4)&&std::memcmp(&state.children[i].parameters,memory+at+12,12)==0);++child_checks;}++cases;
        }
        const auto before=*visuals.particle_state(made.edit->identity());std::array<float,6> invalid{1,0,0,0,0,std::numeric_limits<float>::quiet_NaN()};check(!particle->configure_particle(2,7,invalid));const auto after=*visuals.particle_state(made.edit->identity());check(after.mode==before.mode&&after.delay==before.delay&&after.attributes==before.attributes&&after.flags==before.flags);++refusals;
        const auto old=made.edit->identity();check(visuals.retire(old)&&!visuals.particle_state(old)&&!particle->configure_particle(0,0,{1,0,0,0,0,0}));const auto reused=visuals.create({{},m::Vector{},0,36});check(reused.status==e::WorkStatus::completed&&reused.edit->identity()!=old&&!visuals.particle_state(reused.edit->identity()));++refusals;visuals.close();check(!std::dynamic_pointer_cast<e::ParticleEdit>(reused.edit)->configure_particle(0,0,{1,0,0,0,0,0}));++refusals;++banks;
    }
    std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"banks\":"<<banks<<",\"child_checks\":"<<child_checks<<",\"refusals\":"<<refusals<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
