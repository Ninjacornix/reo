#include "directed.hpp"
#include "trace_reference.hpp"
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iterator>
#include <random>
namespace c=reo::native::gameplay_collision;
namespace s=c::spatial;
namespace d=c::directed;
unsigned checks{},primitive_cases{},scan_cases{},pair_cases{},world_points{},origin_vectors{};float maximum_error{};
std::vector<std::uint8_t> memory(0x800000);
void check(bool value,const char* why){++checks;if(!value){std::fprintf(stderr,"spatial check %u failed: %s\n",checks,why);std::exit(1);}}
R5900Context context(std::uint32_t pc){R5900Context ctx;ctx.pc=pc;ctx.g[29].lo=0x7f0000;ctx.g[31].lo=0x1234;ctx.vu0_vf[0]=_mm_set_ps(1,0,0,0);return ctx;}
void vector_equal(c::Vec3 a,c::Vec3 b,const char* why){for(const auto pair:{std::pair{a.x,b.x},std::pair{a.y,b.y},std::pair{a.z,b.z}}){if(std::isnan(pair.first)&&std::isnan(pair.second))continue;const auto error=std::abs(pair.first-pair.second);maximum_error=std::max(maximum_error,error);if(error>0.001f)std::fprintf(stderr,"native=%g original=%g\n",double(pair.first),double(pair.second));check(error<=0.001f,why);}}
std::uint32_t target_address(unsigned i){return 0x20000+i*0x2000;}
void prepare(const std::vector<s::Target>& targets,const s::Source& source,s::Policy policy){
    std::fill(memory.begin()+0x10000,memory.begin()+0x1f000,0);memory[0x10002]=3;memory[0x10006]=9;ref_write(memory.data(),0x80008,0x10000u);ref_write(memory.data(),0x80014,0x81000u);memory[0x80019]=policy.recipient_mask;memory[0x8100d]=policy.per_actor;memory[0x81006]=1;memory[0x81016]=std::uint8_t(1|(policy.occlusion?0x20:0));memory[0x4bae96]=policy.special_mode?2:0;
    ref_write(memory.data(),0x3c25f8,std::uint16_t(targets.size()));
    for(unsigned i=0;i<targets.size();++i){const auto at=target_address(i);std::fill(memory.begin()+at,memory.begin()+at+0x2000,0);memory[at+2]=targets[i].identity.category;memory[at+6]=targets[i].identity.contact_id;memory[at+0xb98]=targets[i].identity.contact_id;ref_write(memory.data(),at+0xba0,targets[i].movement_flags);ref_write(memory.data(),at+0xc94,targets[i].response_flags);ref_write(memory.data(),at+0x1d8,0x90000+i*0x1000);ref_write(memory.data(),at+0x1dc,0xa0000+i*0x1000);memory[at+0x1e0]=std::uint8_t(targets[i].regions.size());ref_write(memory.data(),0x3c2600+4*i,at);
        for(unsigned j=0;j<targets[i].regions.size();++j){const auto& region=targets[i].regions[j];ref_write(memory.data(),0x90000+i*0x1000+20*j+12,region.radius);ref_write(memory.data(),0xa0000+i*0x1000+12*j,region.center);}if(targets[i].entity==source.related)ref_write(memory.data(),0x10028,at);
    }
}
class Obstacle final:public s::Occlusion{public:bool blocked(c::Vec3,c::Vec3)const override{return spatial_fixture::obstructed;}};

void constants(){ref_write(memory.data(),0x241c88,3.1415927410125732f);ref_write(memory.data(),0x241c90,-3.1415927410125732f);ref_write(memory.data(),0x22fe30,std::array<float,4>{0.000002601886990305502f,-0.00019807413627859205f,0.008333025500178337f,-0.16666656732559204f});}
void primitive(c::Sphere sphere,c::Vec3 origin,c::Vec3 direction,d::Extents extents){
 constants();ref_write(memory.data(),256,origin);ref_write(memory.data(),272,direction);ref_write(memory.data(),288,sphere.center);const c::Vec3 marker{12345,23456,34567};ref_write(memory.data(),304,marker);auto ctx=context(0x6f0fe0);ctx.g[4].lo=288;ctx.g[5].lo=256;ctx.g[6].lo=272;ctx.g[7].lo=304;ctx.f[12]=sphere.radius;ctx.f[13]=extents.first;ctx.f[14]=extents.second;PS2Runtime runtime;o2_006F0FE0_0x6f0fe0(memory.data(),&ctx,&runtime);const auto native=d::contact(sphere,origin,direction,extents);check(bool(native)==bool(ctx.g[2].lo),"original directed volume admission");vector_equal(native?native->value:marker,ref_read<c::Vec3>(memory.data(),304),"original directed point and rejected write preservation");if(native){if(native->space==s::PointSpace::world)++world_points;else ++origin_vectors;}++primitive_cases;
}
void pair(d::Extents extents){constants();const auto angle=std::atan2(extents.second,extents.first);auto ctx=context(0x1921b0);ctx.g[4].lo=512;ctx.g[5].lo=516;ctx.f[12]=angle;PS2Runtime runtime;sub_001921B0_0x1921b0(memory.data(),&ctx,&runtime);const auto native=d::ratios(extents);check(native.first==ref_read<float>(memory.data(),512)&&native.second==ref_read<float>(memory.data(),516),"actual1921B0/18F570pair order and polynomial");++pair_cases;}
void compare(const std::vector<s::Target>& targets,const s::Source& source,s::Policy policy,c::Vec3 start,c::Vec3 end,d::Extents extents){
    prepare(targets,source,policy);spatial_fixture::probe_only=false;ref_write(memory.data(),256,start);ref_write(memory.data(),272,end);ref_write(memory.data(),304,c::Vec3{12345,23456,34567});auto ctx=context(0x57b6f0);ctx.g[4].lo=0x80000;ctx.g[5].lo=256;ctx.g[6].lo=272;ctx.g[7].lo=304;ctx.f[12]=extents.second;ctx.f[13]=extents.first;PS2Runtime runtime;o2_0057B6F0_0x57b6f0(memory.data(),&ctx,&runtime);
    Obstacle obstacle;const auto native=d::scan(targets,source,policy,start,end,extents,&obstacle);check(native.status==s::Status::complete,"declared native spatial class/owner capabilities");check(native.region_hits==ctx.g[2].lo,"original region-hit count/per-actor-first distinction");unsigned deliveries{};for(unsigned i=0;i<targets.size();++i){const auto at=target_address(i);const auto selected=memory[at+0x13f];unsigned matching{};for(const auto& contact:native.deliveries)if(contact.target==targets[i].entity){++matching;check(contact.region==memory[at+0x13e],"original region index/tie selection");vector_equal(contact.point.value,ref_read<c::Vec3>(memory.data(),at+0x120),"original selected region point/vector");check(contact.authored.category==targets[i].identity.category&&contact.authored.contact_id==targets[i].identity.contact_id,"native authored token separate from entity generation");}check(matching==selected,"original selected-target delivery count");deliveries+=matching;}check(deliveries==native.deliveries.size(),"native selected identities belong to the admitted snapshot");check(targets.empty()||native.last_scanned==targets.back().entity,"last-scanned identity retained separately from selected hit");++scan_cases;
}

int main(){
 using namespace reo::native::gameplay_actors;EntityStore entities;const auto source_id=entities.create(std::make_unique<Entity>()).id;std::vector<s::Target> targets(4);for(unsigned i=0;i<4;++i){targets[i].entity=entities.create(std::make_unique<Entity>()).id;targets[i].identity={std::uint8_t(i),std::uint8_t(20+i)};}s::Source source{source_id,{}, {3,9}};const std::array<std::uint8_t,4> masks{1,4,2,8};for(unsigned i=0;i<4;++i)memory[0x708d70+i]=masks[i];
 std::mt19937 random(0x6f0fe0);const auto number=[&]{return float(int(random()%40001)-20000)/100;};for(unsigned i=0;i<18000;++i){const d::Extents extents{float(random()%2001+1)/10,float(random()%2001+1)/10};pair(extents);primitive({{number(),number(),number()},float(random()%1001+1)/10},{number(),number(),number()},{number(),number(),number()},extents);}
 for(unsigned i=0;i<1000;++i){constants();for(auto& target:targets){target.regions.clear();for(unsigned j=0;j<3;++j)target.regions.push_back({{number()/4,number()/4,number()/4},float(random()%50+1)});target.movement_flags=i%2?0x80:0;}source.related=i%3==0?targets[1].entity:EntityId{};s::Policy policy{255,bool(i%2),bool(i%3),bool(i%5==0),masks};spatial_fixture::obstructed=i%11==0;compare(targets,source,policy,{-40,1,3},{1,0,0},{float(i%4+1)*10,float(i%7+1)*10});}
 primitive({{0,0,0},0},{},{1,0,0},{1,1});primitive({{0,0,0},1},{},{},{1,1});primitive({{0,0,0},1},{},{1,0,0},{0,1});check(world_points>10&&origin_vectors>10,"both original world and zero-origin output branches exercised");
 std::printf("{\"checks\":%u,\"primitive_cases\":%u,\"pair_cases\":%u,\"scan_cases\":%u,\"world_points\":%u,\"origin_vectors\":%u,\"maximum_error\":%.9g,\"declared_atan2_port\":true,\"game_launched\":false}\n",checks,primitive_cases,pair_cases,scan_cases,world_points,origin_vectors,double(maximum_error));
}
