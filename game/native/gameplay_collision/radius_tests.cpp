#include "radius.hpp"
#include "trace_reference.hpp"
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iterator>
namespace c=reo::native::gameplay_collision;
namespace r=c::radius;
unsigned checks{},assets{},list_cases{},wrapper_cases{},undefined_cases{};float maximum_error{};
std::vector<std::uint8_t> memory(0x800000);
void check(bool value,const char* why){++checks;if(!value){std::fprintf(stderr,"radius check%u failed: %s\n",checks,why);std::exit(1);}}
R5900Context context(std::uint32_t pc){R5900Context ctx;ctx.pc=pc;ctx.g[29].lo=0x7f0000;ctx.g[31].lo=0x1234;return ctx;}
void equal(c::Vec3 a,c::Vec3 b){for(const auto p:{std::pair{a.x,b.x},std::pair{a.y,b.y},std::pair{a.z,b.z}}){if(std::isnan(p.first)&&std::isnan(p.second))continue;const auto error=std::abs(p.first-p.second);maximum_error=std::max(maximum_error,error);if(error>0.001f)std::fprintf(stderr,"native%g original%g\n",double(p.first),double(p.second));check(error<=0.001f,"original selected point/normal/scratch writes");}}
void constants(){ref_write(memory.data(),0x241c80,182.04444885253906f);ref_write(memory.data(),0x241c88,3.1415927410125732f);ref_write(memory.data(),0x73def0,0.0010000000474974513f);ref_write(memory.data(),0x3c2748,0u);const std::array<float,8> table{-1,-1,0,-1,-1,0,0,0};ref_write(memory.data(),0x70ef10,table);}
void compare_list(std::span<const c::response::Triangle> triangles,c::Vec3 start,c::Vec3 end,float radius){
    constants();std::vector<std::uint32_t> ids;for(unsigned i=0;i<triangles.size();++i){ref_write(memory.data(),0x1000+i*4,0x2000+i*56);ref_write(memory.data(),0x2000+i*56,triangles[i]);ids.push_back(i);}ref_write(memory.data(),0x1000+4*triangles.size(),0xffffffffu);ref_write(memory.data(),256,start);ref_write(memory.data(),272,end);const c::Vec3 marker{12345,23456,34567};ref_write(memory.data(),0x7efff0,marker);ref_write(memory.data(),512,marker);ref_write(memory.data(),528,marker);ref_write(memory.data(),544,0x12345678u);auto ctx=context(0x57d960);ctx.g[4].lo=0x1000;ctx.g[5].lo=256;ctx.g[6].lo=272;ctx.g[7].lo=512;ctx.g[8].lo=528;ctx.g[9].lo=0xffffffffu;ctx.g[10].lo=0;ctx.g[11].lo=544;ctx.f[12]=radius;PS2Runtime runtime;o2_0057D960_0x57d960(memory.data(),&ctx,&runtime);
    const auto native=r::list(triangles,ids,start,end,radius,{},marker);check(native.status==r::Status::complete,"declared initial scratch defines original comparison");check(native.contacts==ctx.g[2].lo,"original list radius admission/count");if(native.hit){equal(native.hit->point,ref_read<c::Vec3>(memory.data(),512));equal(native.hit->normal,ref_read<c::Vec3>(memory.data(),528));check(native.hit->type==ref_read<std::uint32_t>(memory.data(),544),"original radius material/type");}else{equal(marker,ref_read<c::Vec3>(memory.data(),512));check(ref_read<std::uint32_t>(memory.data(),544)==255,"radius no-hit resets type only");}equal(*native.scratch,ref_read<c::Vec3>(memory.data(),0x7efff0));++list_cases;
}
void wrapper(const c::response::Grid& grid,c::Vec3 start,c::Vec3 end,float radius){
    constants();ref_write(memory.data(),0x743720,0xffffffffu);ref_write(memory.data(),256,start);ref_write(memory.data(),272,end);const c::Vec3 marker{12345,23456,34567};ref_write(memory.data(),0x7efb00,marker);ref_write(memory.data(),512,marker);ref_write(memory.data(),528,marker);ref_write(memory.data(),544,255u);auto ctx=context(0x57dc70);ctx.g[4].lo=256;ctx.g[5].lo=272;ctx.g[6].lo=512;ctx.g[7].lo=528;ctx.g[8].lo=0xffffffffu;ctx.g[9].lo=0;ctx.g[10].lo=544;ctx.f[12]=radius;PS2Runtime runtime;o2_0057DC70_0x57dc70(memory.data(),&ctx,&runtime);const auto native=r::query(grid,start,end,radius,{});check(bool(native.contacts)==bool(ctx.g[2].lo),"original wrapper first successful list admission");if(native.status==r::Status::uninitialized_point){++undefined_cases;check(!native.hit,"undefined original scratch not fabricated");}else if(native.hit){equal(native.hit->point,ref_read<c::Vec3>(memory.data(),512));equal(native.hit->normal,ref_read<c::Vec3>(memory.data(),528));check(native.hit->type==ref_read<std::uint32_t>(memory.data(),544),"original wrapper selected type");}++wrapper_cases;
}
void grid(const char* path){
    std::ifstream f(path,std::ios::binary);const std::vector<char> raw{std::istreambuf_iterator<char>(f),{}};check(!raw.empty(),"owned grid bytes");const auto native=c::response::Grid::import(std::as_bytes(std::span(raw)));std::memcpy(memory.data()+0x10000,raw.data(),raw.size());PS2Runtime runtime;auto init=context(0x6161e0);init.g[4].lo=0x10000;o2_006161E0_0x6161e0(memory.data(),&init,&runtime);
    for(const auto& t:native.triangles()){
        const c::Vec3 mid{(t.vertices[0].x+t.vertices[1].x+t.vertices[2].x)/3,(t.vertices[0].y+t.vertices[1].y+t.vertices[2].y)/3,(t.vertices[0].z+t.vertices[1].z+t.vertices[2].z)/3};const c::Vec3 start{mid.x+t.normal.x*50,mid.y+t.normal.y*50,mid.z+t.normal.z*50},end{mid.x-t.normal.x*5,mid.y-t.normal.y*5,mid.z-t.normal.z*5};compare_list(std::span(&t,1),start,end,20);compare_list(std::span(&t,1),end,end,20);wrapper(native,start,end,20);
    }++assets;
}
int main(int argc,char** argv){
    const c::response::Triangle triangle{0x10000,{c::Vec3{-10,0,-10},c::Vec3{10,0,-10},c::Vec3{0,0,10}},{0,1,0},0};const std::array<std::uint32_t,1> ids{0};const auto unknown=r::list(std::span(&triangle,1),ids,{0,-1,10},{0,-1,10},2,{});check(unknown.contacts==1&&unknown.status==r::Status::uninitialized_point&&!unknown.hit,"source edge-only backface point was never initialized");compare_list(std::span(&triangle,1),{0,-1,10},{0,-1,10},2);
    check(argc==2,"owned assets manifest");std::ifstream manifest(argv[1]);std::string path;while(std::getline(manifest,path))if(!path.empty())grid(path.c_str());check(assets==366,"all owned wall/floor grids admitted as radius geometry");std::printf("{\"checks\":%u,\"assets\":%u,\"list_cases\":%u,\"wrapper_cases\":%u,\"undefined_cases\":%u,\"maximum_error\":%.9g,\"game_launched\":false}\n",checks,assets,list_cases,wrapper_cases,undefined_cases,double(maximum_error));
}
