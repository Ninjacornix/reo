#include "hit_regions.hpp"
#include "hit_regions_reference.hpp"
#include <cstdio>
#include <cstdlib>
#include <random>
void o2_005DC1B0_0x5dc1b0(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_005DC2A0_0x5dc2a0(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_005DC3A0_0x5dc3a0(std::uint8_t*,R5900Context*,PS2Runtime*);
namespace c=reo::native::gameplay_collision;
namespace h=c::hit_regions;
namespace a=reo::native::gameplay_actors;
unsigned checks{},pose_cases{},queue_cases{};float maximum_error{};
std::vector<std::uint8_t> memory(0x800000);
void check(bool value,const char* why){++checks;if(!value){std::fprintf(stderr,"hit-region check%u failed: %s\n",checks,why);std::exit(1);}}
R5900Context context(std::uint32_t pc){R5900Context ctx;ctx.pc=pc;ctx.g[29].lo=0x7f0000;ctx.g[31].lo=0x1234;ctx.g[4].lo=0x10000;return ctx;}
void equal(c::Vec3 v,c::Vec3 w){for(const auto p:{std::pair{v.x,w.x},std::pair{v.y,w.y},std::pair{v.z,w.z}}){const auto error=std::abs(p.first-p.second);maximum_error=std::max(maximum_error,error);check(error<=0.001f,"unchanged original pose transformed XYZ");}}
void basis(std::uint32_t at,const c::actors::Basis& b){ref_write(memory.data(),at,std::array<float,16>{b.x.x,b.x.y,b.x.z,0,b.y.x,b.y.y,b.y.z,0,b.z.x,b.z.y,b.z.z,0,b.translation.x,b.translation.y,b.translation.z,1});}
void pose(std::optional<std::vector<h::Definition>> definitions,const c::actors::Basis& root,std::span<const c::actors::Basis> joints,h::Transform mode){
    h::Regions regions;regions.set(std::vector<h::Definition>{{{1,2,3},4,0}});check(regions.refresh(h::Transform::actor_basis,root,{})==h::Status::complete,"initial retained sphere");const auto marker=regions.spheres()[0];regions.set(definitions);memory[0x101e0]=1;ref_write(memory.data(),0x101d8,definitions?0x20000u:0u);ref_write(memory.data(),0x101dc,0x30000u);ref_write(memory.data(),0x10034,0x40000u);ref_write(memory.data(),0x30000,marker.center);basis(0x10050,root);
    for(unsigned i=0;i<joints.size();++i){const auto at=0x50000+i*64;basis(at,joints[i]);ref_write(memory.data(),0x40820+i*4,at);}
    if(definitions){for(unsigned i=0;i<definitions->size();++i){const auto& d=(*definitions)[i];ref_write(memory.data(),0x20000+20*i,d.offset);ref_write(memory.data(),0x2000c+20*i,d.radius);ref_write(memory.data(),0x20010+20*i,d.joint);}ref_write(memory.data(),0x2000c+20*definitions->size(),-1.f);
        const auto imported=h::import_definitions(std::as_bytes(std::span(memory).subspan(0x20000,20*definitions->size()+16)));check(imported.size()==definitions->size(),"bounded original20-byte/sentinel parser");}
    auto ctx=context(mode==h::Transform::actor_basis?0x5dc2a0:0x5dc1b0);PS2Runtime runtime;if(mode==h::Transform::actor_basis)o2_005DC2A0_0x5dc2a0(memory.data(),&ctx,&runtime);else o2_005DC1B0_0x5dc1b0(memory.data(),&ctx,&runtime);
    check(regions.refresh(mode,root,joints)==h::Status::complete,"admitted retained native pose");check(regions.spheres().size()==memory[0x101e0],"original null versus immediate sentinel/count");for(unsigned i=0;i<regions.spheres().size();++i)equal(regions.spheres()[i].center,ref_read<c::Vec3>(memory.data(),0x30000+12*i));++pose_cases;
}
int main(){
    std::mt19937 random(0x5dc1b0);const auto number=[&]{return float(int(random()%10001)-5000)/100;};for(unsigned iteration=0;iteration<1500;++iteration){c::actors::Basis root{{number(),number(),number()},{number(),number(),number()},{number(),number(),number()},{number(),number(),number()}};std::array<c::actors::Basis,4> joints;for(auto& b:joints)b={{number(),number(),number()},{number(),number(),number()},{number(),number(),number()},{number(),number(),number()}};std::optional<std::vector<h::Definition>> definitions;if(iteration%11){definitions.emplace();for(unsigned i=0;i<iteration%17;++i)definitions->push_back({{number(),number(),number()},float(i)+0.25f,i%4});}pose(definitions,root,joints,h::Transform::model_joints);pose(definitions,root,joints,h::Transform::actor_basis);}
    a::EntityStore store;const auto id=store.create(std::make_unique<a::Entity>()).id;
    for(unsigned cooldown=0;cooldown<256;++cooldown)for(unsigned initial:{0u,63u,64u})for(bool present:{false,true}){
        h::Queue queue;for(unsigned i=0;i<initial;++i)check(queue.add(id),"source duplicate enrollment order retained");a::HitActor actor;actor.damage_word=1234;actor.progression_amount=234;actor.pending_hit=31;h::ContactState state{std::uint8_t(cooldown),19,93};ref_write(memory.data(),0x10138,1234u);ref_write(memory.data(),0x1014e,std::uint16_t(234));memory[0x1013f]=31;memory[0x1013c]=19;memory[0x10116]=93;memory[0x10032]=std::uint8_t(cooldown);ref_write(memory.data(),0x101d8,present?0x20000u:0u);ref_write(memory.data(),0x3c25f8,std::uint16_t(initial));auto ctx=context(0x5dc3a0);PS2Runtime runtime;o2_005DC3A0_0x5dc3a0(memory.data(),&ctx,&runtime);const bool added=h::prepare_hit(actor,state,id,present,queue);
        check(actor.damage_word==ref_read<std::int32_t>(memory.data(),0x10138)&&actor.progression_amount==ref_read<std::uint16_t>(memory.data(),0x1014e)&&actor.pending_hit==memory[0x1013f]&&state.priority==memory[0x1013c]&&state.serial==memory[0x10116],"canonical HitActor and supplemental fields reset before gate");check(state.cooldown==memory[0x10032],"FF permanent and1-to0 delayed cooldown");check(queue.entries().size()==ref_read<std::uint16_t>(memory.data(),0x3c25f8),"actual64-target queue admission");check(added==(queue.entries().size()!=initial),"explicit enrollment result");if(added)check(queue.entries().back()==id,"native queue owns opaque identity");++queue_cases;
    }
    h::Regions retained;retained.set(std::vector<h::Definition>{{{1,2,3},4,0}});check(retained.refresh(h::Transform::actor_basis,{},{})==h::Status::complete,"initial validation pose");const auto before=retained.spheres()[0].center;check(retained.refresh(h::Transform::model_joints,{},{})==h::Status::missing_joint,"missing joint is explicit capability failure");equal(retained.spheres()[0].center,before);bool rejected{};try{h::import_definitions({});}catch(const std::invalid_argument&){rejected=true;}check(rejected,"truncated sentinel rejected");rejected=false;try{retained.set(std::vector<h::Definition>(256));}catch(const std::invalid_argument&){rejected=true;}check(rejected,"byte count overflow rejected before publication");h::Queue queue;check(!queue.add({}),"invalid native identity rejected");check(queue.add(id),"valid native identity admitted");queue.clear();check(queue.entries().empty(),"caller-controlled queue reset");
    std::printf("{\"checks\":%u,\"pose_cases\":%u,\"queue_cases\":%u,\"maximum_error\":%.9g,\"game_launched\":false}\n",checks,pose_cases,queue_cases,double(maximum_error));
}
