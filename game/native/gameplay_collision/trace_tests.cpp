#include "trace.hpp"
#include "trace_reference.hpp"
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iterator>
#include <random>
namespace c=reo::native::gameplay_collision;
namespace t=c::trace;
unsigned checks{},assets{},queries{};float maximum_error{};
std::vector<std::uint8_t> memory(0x800000);
void check(bool value,const char* why){++checks;if(!value){std::fprintf(stderr,"trace check %u failed: %s\n",checks,why);std::exit(1);}}
R5900Context context(std::uint32_t pc){R5900Context ctx;ctx.pc=pc;ctx.g[29].lo=0x7f0000;ctx.g[31].lo=0x1234;return ctx;}
void vector_equal(c::Vec3 a,c::Vec3 b,const char* why){for(const auto pair:{std::pair{a.x,b.x},std::pair{a.y,b.y},std::pair{a.z,b.z}}){if(std::isnan(pair.first)&&std::isnan(pair.second))continue;const auto error=std::abs(pair.first-pair.second);maximum_error=std::max(maximum_error,error);if(error>0.001f)std::fprintf(stderr,"native=%g original=%g\n",double(pair.first),double(pair.second));check(error<=0.001f,why);}}
void constants(){ref_write(memory.data(),0x241c80,182.04444885253906f);ref_write(memory.data(),0x241c88,3.1415927410125732f);ref_write(memory.data(),0x73def0,0.0010000000474974513f);ref_write(memory.data(),0x3c2748,0u);}
void primitive(const c::response::Triangle& triangle,c::Vec3 start,c::Vec3 end,std::uint8_t side){
    constants();ref_write(memory.data(),0x1000,triangle);ref_write(memory.data(),0x1100,start);ref_write(memory.data(),0x1110,end);const c::Vec3 marker{12345,23456,34567};ref_write(memory.data(),0x1200,marker);memory[0x1210]=side;auto ctx=context(0x579300);ctx.g[4].lo=0x1000;ctx.g[5].lo=0x1100;ctx.g[6].lo=0x1110;ctx.g[7].lo=0x1200;ctx.g[8].lo=0x1210;PS2Runtime runtime;o2_00579300_0x579300(memory.data(),&ctx,&runtime);
    const auto native=t::triangle(triangle,start,end,side);check(native.hit==bool(ctx.g[2].lo),"original segment triangle admission");vector_equal(native.written_point.value_or(marker),ref_read<c::Vec3>(memory.data(),0x1200),"original rejected/accepted segment point writes");check(native.side.value_or(side)==memory[0x1210],"original early/late side publication");
}
void wrapper(const c::response::Grid& grid,c::Vec3 start,c::Vec3 end,bool floor){
    constants();ref_write(memory.data(),0x743720,0xffffffffu);ref_write(memory.data(),256,start);ref_write(memory.data(),272,end);const c::Vec3 marker{12345,23456,34567};ref_write(memory.data(),512,marker);ref_write(memory.data(),528,marker);ref_write(memory.data(),544,0xffu);PS2Runtime runtime;
    auto ctx=context(floor?0x57d560:0x5795e0);ctx.g[4].lo=256;ctx.g[5].lo=272;ctx.g[6].lo=512;ctx.g[7].lo=528;ctx.g[8].lo=0xffffffffu;ctx.g[9].lo=0;ctx.g[10].lo=544;
    if(floor)o2_0057D560_0x57d560(memory.data(),&ctx,&runtime);else o2_005795E0_0x5795e0(memory.data(),&ctx,&runtime);
    const auto native=floor?t::floor(grid,start,end):t::shorten(grid,start,end,{});check(bool(native.hit)==bool(ctx.g[2].lo),"original ordered list-local/shortened wrapper admission");if(native.hit){vector_equal(native.hit->point,ref_read<c::Vec3>(memory.data(),512),"original sampled wrapper point");vector_equal(native.hit->normal,ref_read<c::Vec3>(memory.data(),528),"original sampled wrapper normal side");check(native.hit->type==(floor?memory[544]:ref_read<std::uint32_t>(memory.data(),544)),"original sampled wrapper type");}
    ctx=context(floor?0x57d630:0x579980);ctx.g[4].lo=256;ctx.g[5].lo=272;ctx.g[6].lo=floor?255:0xffffffffu;ctx.g[7].lo=floor?255:0;ctx.g[8].lo=544;
    if(floor)o2_0057D630_0x57d630(memory.data(),&ctx,&runtime);else o2_00579980_0x579980(memory.data(),&ctx,&runtime);
    const bool any=floor?t::floor_any(grid,start,end):bool(t::any(grid,start,end,{}).hit);check(any==bool(ctx.g[2].lo),"original sampled first-hit/type filter wrapper");
}
void grid(const char* path){
    std::ifstream file(path,std::ios::binary);const std::vector<char> raw{std::istreambuf_iterator<char>(file),{}};check(!raw.empty(),"owned immutable grid fixture");const auto native=c::response::Grid::import(std::as_bytes(std::span(raw)));const auto& h=native.header();const std::string filename=path;const bool floor=filename.substr(filename.find_last_of("/\\")+1).starts_with('g');constexpr unsigned base=0x10000;std::memcpy(memory.data()+base,raw.data(),raw.size());PS2Runtime runtime;auto init=context(floor?0x616310:0x6161e0);init.g[4].lo=base;if(floor)o2_00616310_0x616310(memory.data(),&init,&runtime);else o2_006161E0_0x6161e0(memory.data(),&init,&runtime);
    for(unsigned profile=0;profile<8;++profile){const auto fraction=float(profile+1)/10;const c::Vec3 start{float(h.origin_x)+float(h.step_x)*fraction,100,float(h.origin_z)+float(h.step_z)*(1-fraction)},end{float(h.origin_x)+float(h.step_x)*(float(h.columns)-fraction),100,float(h.origin_z)+float(h.step_z)*(float(h.rows)-fraction)};const auto sampled=t::sample(native,start,end,floor);check(sampled.status!=t::SamplingStatus::capacity&&sampled.status!=t::SamplingStatus::nonprogress,"owned grid sample within original stack budget");
        ref_write(memory.data(),256,start);ref_write(memory.data(),272,end);auto ctx=context(floor?0x57d040:0x579730);ctx.g[4].lo=256;ctx.g[5].lo=272;ctx.g[6].lo=0x2000;if(floor)o2_0057D040_0x57d040(memory.data(),&ctx,&runtime);else o2_00579730_0x579730(memory.data(),&ctx,&runtime);check(sampled.cells.size()==ctx.g[2].lo,"original repeated-cell sampled count");
        const auto table=ref_read<std::uint32_t>(memory.data(),floor?0x3c2740:0x3c2720);for(unsigned i=0;i<sampled.cells.size();++i){const auto index=sampled.cells[i];const auto pointer=ref_read<std::uint32_t>(memory.data(),table+4*(index.column*h.rows+index.row));check(pointer==ref_read<std::uint32_t>(memory.data(),0x2000+4*i),"original sampled grid list order");}
    }
    for(const auto& triangle:native.triangles()){c::Vec3 mid{(triangle.vertices[0].x+triangle.vertices[1].x+triangle.vertices[2].x)/3,(triangle.vertices[0].y+triangle.vertices[1].y+triangle.vertices[2].y)/3,(triangle.vertices[0].z+triangle.vertices[1].z+triangle.vertices[2].z)/3};const c::Vec3 start{mid.x+triangle.normal.x*50,mid.y+triangle.normal.y*50,mid.z+triangle.normal.z*50},end{mid.x-triangle.normal.x*50,mid.y-triangle.normal.y*50,mid.z-triangle.normal.z*50};primitive(triangle,start,end,0);primitive(triangle,end,start,1);wrapper(native,start,end,floor);++queries;}
    ++assets;
}
int main(int argc,char** argv){
    std::mt19937 random(0x579300);for(unsigned i=0;i<1000;++i){const auto number=[&]{return float(int(random()%20001)-10000)/100;};c::response::Triangle triangle{0x10000,{c::Vec3{-100,0,-100},c::Vec3{100,0,-100},c::Vec3{0,0,100}},{0,1,0},0};primitive(triangle,{number(),number(),number()},{number(),number(),number()},std::uint8_t(i%2));}
    check(argc==2,"owned asset manifest argument");std::ifstream manifest(argv[1]);std::string path;while(std::getline(manifest,path))if(!path.empty())grid(path.c_str());check(assets==366,"all stock grid trace fixtures");std::printf("{\"checks\":%u,\"maximum_error\":%.9g,\"owned_assets\":%u,\"owned_triangles\":%u,\"declared_numeric_ports\":true,\"game_launched\":false}\n",checks,double(maximum_error),assets,queries);
}
