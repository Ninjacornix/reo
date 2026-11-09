#include "response.hpp"
#include "tools/native_reconstruction/gameplay_collision_oracle/response_reference.hpp"
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iterator>
#include <random>
namespace c=reo::native::gameplay_collision;
namespace r=c::response;
unsigned checks{};float maximum_error{};
const r::Capsule* current_a{};const r::Capsule* current_b{};bool sphere_case{};
void check(bool value,const char* reason){++checks;if(!value){std::fprintf(stderr,"response check %u failed: %s\n",checks,reason);std::exit(1);}}
std::vector<std::uint8_t>& storage(){static std::vector<std::uint8_t> bytes(0x800000);return bytes;}
R5900Context context(std::uint32_t entry){R5900Context ctx;ctx.pc=entry;ctx.g[29].lo=0x7f0000;ctx.g[31].lo=0x1234;return ctx;}
std::optional<c::Contact> original(r::Capsule a,r::Capsule b,bool sphere=false){
    static_assert(sizeof(a)==56);auto& memory=storage();std::memcpy(memory.data()+0x1000,&a,sizeof a);std::memcpy(memory.data()+0x1100,&b,sizeof b);
    const c::Vec3 zero{};ref_write(memory.data(),0x1200,zero);ref_write(memory.data(),0x742e80,0.0010000000474974513f);
    auto ctx=context(sphere?0x6f00d0:0x6f0310);ctx.g[4].lo=0x1000;ctx.g[5].lo=0x1100;ctx.g[6].lo=0x1200;ctx.f[12]=b.radius;PS2Runtime runtime;
    if(sphere)o2_006F00D0_0x6f00d0(memory.data(),&ctx,&runtime);else o2_006F0310_0x6f0310(memory.data(),&ctx,&runtime);
    if(!ctx.g[2].lo)return{};
    return c::Contact{ref_read<c::Vec3>(memory.data(),0x1200)};
}
void compare(const std::optional<c::Contact>& candidate,const std::optional<c::Contact>& reference){
    check(bool(candidate)==bool(reference),"original contact admission");if(!candidate)return;
    const auto a=candidate->correction,b=reference->correction;
    const auto axis=[](float x,float y){if(std::isnan(x)&&std::isnan(y))return;const auto error=std::abs(x-y);maximum_error=std::max(maximum_error,error);
        if(!(error<=0.00025f+std::abs(y)*0.00002f)){std::fprintf(stderr,"axis native=%g reference=%g sphere=%u\n",double(x),double(y),unsigned(sphere_case));if(current_a&&current_b)for(const auto* shape:{current_a,current_b})std::fprintf(stderr,"capsule start(%g,%g,%g) end(%g,%g,%g) radius=%g bound=%g\n",double(shape->start.x),double(shape->start.y),double(shape->start.z),double(shape->end.x),double(shape->end.y),double(shape->end.z),double(shape->radius),double(shape->bound_radius));}
        check(error<=0.00025f+std::abs(y)*0.00002f,"original contact correction vector");};
    axis(a.x,b.x);axis(a.y,b.y);axis(a.z,b.z);
}
r::Floor original_floor(c::Vec3 point,std::span<const r::Triangle> triangles,std::uint8_t required){
    static_assert(sizeof(r::Triangle)==56);auto& memory=storage();memory[64]=1;ref_write(memory.data(),68,0x2000u);
    std::memcpy(memory.data()+256,&point,sizeof point);
    for(unsigned i=0;i<triangles.size();++i){const auto at=0x10000+56*i;std::memcpy(memory.data()+at,&triangles[i],56);ref_write(memory.data(),0x2000+4*i,at);}
    ref_write(memory.data(),0x2000+4*std::uint32_t(triangles.size()),0xffffffffu);
    auto ctx=context(0x617000);ctx.g[4].lo=256;ctx.g[5].lo=512;ctx.g[6].lo=768;ctx.g[7].lo=384;ctx.g[8].lo=required;ctx.g[9].lo=385;ctx.g[10].lo=386;PS2Runtime runtime;
    o2_00617000_0x617000(memory.data(),&ctx,&runtime);
    r::Floor result;result.height=ctx.f[0];result.normal=ref_read<c::Vec3>(memory.data(),512);result.type=memory[384];result.material=memory[385];result.attributes=ref_read<std::uint16_t>(memory.data(),386);return result;
}
bool original_filter(std::uint32_t flags,const r::Filter& filter){
    auto& memory=storage();ref_write(memory.data(),256,flags);ref_write(memory.data(),0x3c2748,filter.disabled);
    for(unsigned i=0;i<16;++i){memory[0x4a3634+96*i]=filter.slots[i].kind;memory[0x4a3621+96*i]=filter.slots[i].state;}
    auto ctx=context(0x617430);ctx.g[4].lo=256;ctx.g[5].lo=filter.include;ctx.g[6].lo=filter.exclude;ctx.g[7].lo=filter.dynamic_kind_gate;PS2Runtime runtime;
    o2_00617430_0x617430(memory.data(),&ctx,&runtime);return ctx.g[2].lo!=0;
}
void imported_asset(const char* path,bool floor){
    std::ifstream input(path,std::ios::binary);std::vector<char> data((std::istreambuf_iterator<char>(input)),{});
    const auto grid=r::Grid::import(std::as_bytes(std::span(data)));auto& memory=storage();constexpr std::uint32_t base=0x200000;
    std::memcpy(memory.data()+base,data.data(),data.size());auto ctx=context(floor?0x616310:0x6161e0);ctx.g[4].lo=base;PS2Runtime runtime;
    if(floor)o2_00616310_0x616310(memory.data(),&ctx,&runtime);else o2_006161E0_0x6161e0(memory.data(),&ctx,&runtime);
    const auto& h=grid.header();const auto directory=ref_read<std::uint32_t>(memory.data(),floor?0x3c2740:0x3c2720);
    for(unsigned x=0;x<h.columns;++x)for(unsigned z=0;z<h.rows;++z){
        const c::Vec3 point{float(h.origin_x)+float(x*h.step_x)+float(h.step_x)/2,0,float(h.origin_z)+float(z*h.step_z)+float(h.step_z)/2};
        const auto native=grid.cell(point);const auto original_list=ref_read<std::uint32_t>(memory.data(),directory+4*(x*h.rows+z));unsigned count{};
        for(;;++count){const auto triangle=ref_read<std::uint32_t>(memory.data(),original_list+4*count);if(triangle==0xffffffffu)break;check(count<native.size(),"original grid list has matching native extent");const auto& expected=grid.triangles()[native[count]];check(std::memcmp(&expected,memory.data()+triangle,56)==0,"owned triangle body matches actual original relocation");}
        check(count==native.size(),"original/native cell counts match");
        if(floor){std::vector<r::Triangle> list;for(auto index:native)list.push_back(grid.triangles()[index]);
            for(float height:{0.0f,1000.0f}){auto probe=point;probe.y=height;const auto candidate=grid.floor(probe),reference=original_floor(probe,list,255);
                check(candidate.height==reference.height&&candidate.type==reference.type&&candidate.material==reference.material&&candidate.attributes==reference.attributes&&candidate.normal.x==reference.normal.x&&candidate.normal.y==reference.normal.y&&candidate.normal.z==reference.normal.z,"owned native floor cell query matches original selection");}
        }
    }
}
int main(int argc,char** argv){
    const std::array axes{c::Vec3{0,0,10},c::Vec3{0,0,-10},c::Vec3{10,0,0},c::Vec3{0,10,0},c::Vec3{0,0,0},c::Vec3{0.001f,0,10}};
    for(auto a:axes)for(auto b:axes)for(c::Vec3 shift:std::array{c::Vec3{},c::Vec3{1,0,0},c::Vec3{0,0,15},c::Vec3{0,0,-15},c::Vec3{5,5,5}}){
        const auto first=r::make_capsule({},a,2),second=r::make_capsule(shift,{shift.x+b.x,shift.y+b.y,shift.z+b.z},3);
        current_a=&first;current_b=&second;sphere_case=false;compare(r::capsules(first,second),original(first,second));sphere_case=true;compare(r::capsule_sphere(first,{shift,3}),original(first,second,true));
    }
    std::mt19937 random(0x6f0310);const auto scalar=[&]{return float(int(random()%20001)-10000)/1000.0f;};const auto point=[&]{return c::Vec3{scalar(),scalar(),scalar()};};
    for(unsigned i=0;i<7000;++i){const auto start_a=point(),end_a=point();const float radius_a=float(random()%500+1)/100;
        const auto start_b=point(),end_b=point();const float radius_b=float(random()%500+1)/100;
        const auto a=r::make_capsule(start_a,end_a,radius_a),b=r::make_capsule(start_b,end_b,radius_b);
        current_a=&a;current_b=&b;sphere_case=false;compare(r::capsules(a,b),original(a,b));sphere_case=true;compare(r::capsule_sphere(a,{b.start,b.radius}),original(a,b,true));}
    for(unsigned i=0;i<5000;++i){r::Filter filter;filter.include=random();filter.exclude=random();filter.disabled=random();filter.dynamic_kind_gate=random()%2;
        for(auto& slot:filter.slots){slot.kind=std::uint8_t(random()%4);slot.state=std::uint8_t(random()%4);}const auto flags=std::uint32_t(random());check(r::admits(flags,filter)==original_filter(flags,filter),"original collision type/flag/dynamic-slot masks");}
    const std::array<r::Triangle,3> triangles{{{0x00420102,{{{0,0,0},{100,0,0},{0,0,100}}},{0,1,0},-20},{0x01010303,{{{0,0,0},{100,0,0},{0,0,100}}},{0,1,0},-40},{0x01010383,{{{0,0,0},{100,0,0},{0,0,100}}},{0,1,0},-60}}};
    for(int x=-1;x<=101;++x)for(float y:{-100.0f,-60.0f,0.0f,100.0f})for(std::uint8_t required:{std::uint8_t(255),std::uint8_t(2),std::uint8_t(3)}){
        const c::Vec3 point{float(x),y,20};const auto native=r::floor_at(point,triangles,required),reference=original_floor(point,triangles,required);
        check(native.height==reference.height&&native.type==reference.type&&native.material==reference.material&&native.attributes==reference.attributes&&native.normal.y==reference.normal.y,"original floor selection and metadata");}
    std::vector<std::byte> raw(176);const auto put=[&](std::size_t at,std::uint32_t value){for(unsigned k=0;k<4;++k)raw[at+k]=std::byte(value>>(8*k));};
    put(8,100);put(12,100);put(16,2);put(20,1);put(32,32);put(36,56);put(40,40);put(44,48);put(48,0);put(52,0xffffffff);put(56,56);put(60,0xffffffff);
    std::memcpy(raw.data()+64,&triangles[0],56);std::memcpy(raw.data()+120,&triangles[1],56);const auto original_bytes=raw;const auto grid=r::Grid::import(raw);
    check(raw==original_bytes&&grid.triangles().size()==2,"immutable native grid directory conversion");check(grid.contains({0,0,0})&&!grid.contains({200,0,0}),"inclusive lower/exclusive upper grid bounds");
    check(grid.cell({10,0,10})[0]==0&&grid.cell({110,0,10})[0]==1,"column-major native cell ownership");check(grid.floor({10,0,10}).height==20,"native floor through immutable cell indices");
    raw.resize(55);bool failed{};try{(void)r::Grid::import(raw);}catch(const std::invalid_argument&){failed=true;}check(failed,"truncated grid rejected before publishing ownership");
    unsigned assets{};
    if(argc==2){std::ifstream list(argv[1]);std::string path;while(std::getline(list,path)){if(path.empty())continue;const auto name=path.substr(path.find_last_of("/\\")+1);imported_asset(path.c_str(),name.front()=='g');++assets;}}
    if(argc==3){imported_asset(argv[1],false);imported_asset(argv[2],true);assets=2;}
    std::printf("{\"checks\":%u,\"owned_grid_assets\":%u,\"maximum_contact_error\":%.9g,\"game_launched\":false,\"declared_numeric_ports\":true}\n",checks,assets,double(maximum_error));
}
