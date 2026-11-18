#include "collision.hpp"
#include "tools/native_reconstruction/gameplay_collision_oracle/reference.hpp"
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iterator>
#include <random>
namespace c=reo::native::gameplay_collision;
unsigned checks{};
void check(bool result,const char* why){++checks;if(!result){std::fprintf(stderr,"collision check %u failed: %s\n",checks,why);std::exit(1);}}
bool original(const c::Quad& quad,c::Point point){
    std::array<std::uint8_t,4096> memory{};R5900Context ctx;PS2Runtime runtime;
    std::memcpy(memory.data()+128,quad.data(),sizeof quad);std::memcpy(memory.data()+256,&point,sizeof point);
    ctx.g[4].lo=128;ctx.g[5].lo=256;ctx.g[6].lo=4;ctx.g[29].lo=4000;ctx.g[31].lo=0x1234;ctx.pc=0x370960;
    o0_00370960_0x370960(memory.data(),&ctx,&runtime);return ctx.g[2].lo!=0;
}
bool original_height(const c::Quad& quad,c::Vec3 point,std::int32_t low,std::int32_t high){
    std::array<std::uint8_t,4096> memory{};R5900Context ctx;PS2Runtime runtime;
    std::memcpy(memory.data()+128,quad.data(),sizeof quad);std::memcpy(memory.data()+160,&low,4);std::memcpy(memory.data()+164,&high,4);std::memcpy(memory.data()+256,&point,sizeof point);
    ctx.g[4].lo=128;ctx.g[5].lo=256;ctx.g[29].lo=4000;ctx.g[31].lo=0x1234;ctx.pc=0x5dc9b0;
    o2_005DC9B0_0x5dc9b0(memory.data(),&ctx,&runtime);return ctx.g[2].lo!=0;
}
bool original_radius(const c::Quad& quad,c::Point point,float radius){
    std::array<std::uint8_t,4096> memory{};R5900Context ctx;PS2Runtime runtime;
    std::memcpy(memory.data()+128,quad.data(),sizeof quad);std::memcpy(memory.data()+256,&point,sizeof point);
    ctx.g[4].lo=128;ctx.g[5].lo=256;ctx.g[6].lo=4;ctx.g[29].lo=4000;ctx.g[31].lo=0x1234;ctx.pc=0x370dd0;ctx.f[12]=radius;
    o0_00370DD0_0x370dd0(memory.data(),&ctx,&runtime);return ctx.g[2].lo!=0;
}
std::optional<unsigned> original_selection(std::span<const c::Proxy> proxies,const c::ActorQuery& q,std::span<const c::ProxyState> states){
    static std::vector<std::uint8_t> memory(0x500000);std::fill(memory.begin(),memory.end(),0);R5900Context ctx;PS2Runtime runtime;
    for(std::size_t i=0;i<proxies.size();++i){const auto& p=proxies[i];const auto at=0x1000+std::uint32_t(i)*256;
        std::memcpy(memory.data()+at,p.bounds.data(),sizeof p.bounds);ref_write(memory.data(),at+0x20,p.lower);ref_write(memory.data(),at+0x24,p.upper);
        ref_write(memory.data(),at+0x28,i?at-256:0u);memory[at+0x30]=p.kind;memory[at+0x31]=p.query_class;memory[at+0x32]=p.priority;memory[at+0x3c]=p.active;memory[at+0x3d]=p.busy;
        ref_write(memory.data(),at+0x40,p.identifier);ref_write(memory.data(),at+0x48,p.content_id);ref_write(memory.data(),at+0x58,p.bypass_slot_guard?2u:0u);
        memory[0x4a3621+0x60*p.identifier]=states[i].slot_idle?0:1;
    }
    ref_write(memory.data(),0x3b5160,proxies.empty()?0u:0x1000+std::uint32_t(proxies.size()-1)*256);
    std::memcpy(memory.data()+0x4000+0x38,&q.position,sizeof q.position);ref_write(memory.data(),0x3c5636,q.selected_content);std::memcpy(memory.data()+256,&q.point,sizeof q.point);
    memory[68]=1;memory[69]=states.empty()||states[0].grid_span_admitted;
    ctx.g[4].lo=256;ctx.g[5].lo=0x4000;ctx.g[6].lo=q.query_class;ctx.f[12]=q.radius;ctx.g[29].lo=0x4f0000;ctx.g[31].lo=0x1234;ctx.pc=0x5dc570;
    o2_005DC570_0x5dc570(memory.data(),&ctx,&runtime);const auto selected=ref_read<std::uint32_t>(memory.data(),64);if(!selected)return{};return(selected-0x1000)/256;
}
int main(int argc,char** argv){
    const c::Quad door{{{9310,12900},{9270,12900},{9270,13000},{9310,13000}}};
    for(int x=9250;x<=9330;++x)for(int z=12880;z<=13020;++z)check(c::contains(door,{x,z})==original(door,{x,z}),"owned door quad including all edges");
    std::mt19937 random(0x651ef);
    for(unsigned i=0;i<25000;++i){
        c::Quad q;for(auto& p:q){p.x=std::bit_cast<std::int32_t>(std::uint32_t(random()));p.z=std::bit_cast<std::int32_t>(std::uint32_t(random()));}
        c::Point p{std::bit_cast<std::int32_t>(std::uint32_t(random())),std::bit_cast<std::int32_t>(std::uint32_t(random()))};
        check(c::contains(q,p)==original(q,p),"full-width original wrap and fan/winding arithmetic");
    }
    for(int y=-205;y<=250;++y){const c::Vec3 p{9290,float(y),12950};check(c::admits_height(25,245,p.y)==original_height(door,p,25,245),"original asymmetric height slack");}
    for(float fraction:{-0.9f,-0.5f,-0.1f,0.1f,0.5f,0.9f})for(int x=9269;x<=9311;++x){
        const c::Vec3 p{float(x)+fraction,20,12950.7f};const auto integer=c::integer_xz(p);
        const bool result=integer&&c::contains(door,*integer)&&c::admits_height(25,245,p.y);
        check(result==original_height(door,p,25,245),"fractional world coordinates truncate at polygon boundary");
    }
    for(int x=9210;x<=9370;++x)for(int z=12840;z<=13060;z+=3)for(float radius:{0.0f,1.0f,25.0f,50.0f})check(c::overlaps(door,{x,z},radius)==original_radius(door,{x,z},radius),"original radius edge/endpoint strictness");
    c::Proxy p;p.bounds=door;p.lower=25;p.upper=245;p.kind=0;p.query_class=4;p.priority=2;
    c::World world(7,{p,p});std::array<c::ProxyState,2> states{};c::ActorQuery query;query.point={9290,20,12950};query.position={9233,20,12964};query.local=true;
    auto selected=world.select(query,states);check(selected&&selected->id.index==1,"priority ties retain first in reverse creation traversal");check(world.get({8,0})==nullptr,"retired room generation refused");
    for(unsigned i=0;i<600;++i){std::vector<c::Proxy> proxies(4,p);std::array<c::ProxyState,4> active{};
        for(unsigned k=0;k<4;++k){auto& v=proxies[k];v.kind=std::array<std::uint8_t,5>{0,2,0x80,0x81,0x85}[random()%5];v.priority=std::uint8_t(random()%6);v.active=random()%4!=0;v.busy=random()%7==0;v.query_class=std::array<std::uint8_t,4>{0,2,4,6}[random()%4];v.identifier=k;v.content_id=0x19e;v.bypass_slot_guard=random()%2;active[k].slot_idle=random()%2;}
        query.point={float(9200+random()%200),float(int(random()%500)-200),float(12850+random()%200)};query.selected_content=0x19e;query.query_class=std::uint8_t(random()%7);
        c::World candidate(99,proxies);const auto native=candidate.select(query,active);const auto reference=original_selection(proxies,query,active);
        check(bool(native)==bool(reference)&&(!native||native->id.index==*reference),"actual original proxy admission/geometry/height/priority selection");
    }
    query.query_class=0;
    query.point={9250,20,12950};check(!world.select(query,states),"kind0 does not gain radius50");
    p.kind=0x80;c::World expanded(8,{p});check(bool(expanded.select(query,std::span(states).first(1))),"radius-enabled proxy has distinct footprint");
    query.point={9290,20,12950};query.position={9200,20,12950};p.kind=0x85;c::World actor_probe(9,{p});check(!actor_probe.select(query,std::span(states).first(1)),"kind85 tests actor position");
    const auto probe=c::forward_probe({9233,20,12964},16384,46);check(std::abs(probe.x-9279)<0.001f&&std::abs(probe.z-12964)<0.001f,"actual first-room forward interaction");
    const auto contact=c::sphere_contact({{0,0,0},2},{{3,0,0},2});check(contact&&contact->correction.x==-1,"sphere penetration direction");check(!c::sphere_contact({{0,0,0},2},{{5,0,0},2}),"sphere miss");
    c::Body a{{1,4,0},{0,4,0},{},1,0},b{{2,4,0},{2,4,0},{},1,0};check(c::separate(a,b,{2,9,0},false,false)&&a.position.x==3&&b.position.x==2&&a.position.y==4,"only moving equal-priority actor separates horizontally");
    if(argc==2){std::ifstream input(argv[1],std::ios::binary);std::vector<char> raw((std::istreambuf_iterator<char>(input)),{});auto imported=c::import_proxy_section(std::as_bytes(std::span(raw)));check(imported.size()==39,"owned room section directory import");unsigned doors{};for(const auto& v:imported)if(v.door){++doors;if(v.door->id==2)check(v.door->destination_room==4&&v.proxy.bounds==door,"owned door2 exact native resource");}check(doors==3,"three owned door descriptors");}
    std::printf("{\"checks\":%u,\"original_body_comparison\":true,\"game_launched\":false}\n",checks);
}
