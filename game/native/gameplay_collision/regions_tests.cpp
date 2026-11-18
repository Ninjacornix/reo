#include "regions.hpp"
#include "trace_reference.hpp"
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iterator>
#include <random>
namespace c=reo::native::gameplay_collision;
namespace r=c::regions;
unsigned checks{},assets{},region_count{},auxiliary_count{},queries{};
std::vector<std::uint8_t> memory(0x800000);
void check(bool value,const char* why){++checks;if(!value){std::fprintf(stderr,"region check %u failed: %s\n",checks,why);std::exit(1);}}
R5900Context context(std::uint32_t pc){R5900Context ctx;ctx.pc=pc;ctx.g[29].lo=0x7f0000;ctx.g[31].lo=0x1234;return ctx;}
std::uint32_t invoke(std::uint32_t pc,std::uint32_t a0=0,std::uint32_t a1=0){auto ctx=context(pc);ctx.g[4].lo=a0;ctx.g[5].lo=a1;PS2Runtime runtime;runtime.lookupFunction(pc)(memory.data(),&ctx,&runtime);return std::uint32_t(ctx.g[2].lo);}
void point(const r::World& world,c::Vec3 point){ref_write(memory.data(),0x1000,point);check(world.select(point)==invoke(0x574680,0x1000),"original highest-priority region selector/tie/default");++queries;}
void section(std::span<const std::byte> bytes){const auto world=r::World::import(bytes);std::memcpy(memory.data()+0x10000,bytes.data(),bytes.size());invoke(0x573de0,0x10000);check(world.regions().size()==memory[0x743108]&&world.auxiliary().size()==memory[0x743100],"original pretested region/auxiliary import counts");
    const auto& defaults=world.defaults();check(defaults.selector==ref_read<std::uint16_t>(memory.data(),0x3c3d70)&&defaults.mode==memory[0x3c3d72]&&defaults.variant==memory[0x3c3d73]&&defaults.flags==ref_read<std::uint32_t>(memory.data(),0x3c3d74)&&defaults.weight==memory[0x3c3d78],"original authored trailer/default flags");check(world.select({})==invoke(0x574680,0),"original null region query default");
    for(unsigned i=0;i<world.regions().size();++i){const auto& region=world.regions()[i];const auto at=0x3c3000+104*i;check(region.priority==memory[at]&&region.flags==memory[at+1]&&region.selector==ref_read<std::uint16_t>(memory.data(),at+2),"original priority/activity/selector narrowing");c::Vec3 center{};
        for(unsigned v=0;v<8;++v){const auto vertex=region.vertices[v],original=ref_read<r::Vertex>(memory.data(),at+4+12*v);check(vertex.x==original.x&&vertex.y==original.y&&vertex.z==original.z,"original eight authored integer vertices");center.x+=float(vertex.x)*0.125f;center.y+=float(vertex.y)*0.125f;center.z+=float(vertex.z)*0.125f;}
        center.y-=10;point(world,center);for(const auto& vertex:region.vertices){const c::Vec3 p{float(vertex.x)+0.25f,float(vertex.y)-10.25f,float(vertex.z)-0.25f};ref_write(memory.data(),0x1000,p);check(r::contains(region,p)==bool(invoke(0x574010,0x1000,at)),"original six ordered normalized region planes");point(world,p);}++region_count;
    }
    for(unsigned i=0;i<world.auxiliary().size();++i){const auto& a=world.auxiliary()[i];const auto at=0x3c3d00+28*i;check(a.active==memory[at]&&a.mode==memory[at+1]&&a.first==ref_read<std::uint16_t>(memory.data(),at+2)&&a.second==ref_read<std::uint16_t>(memory.data(),at+4),"original auxiliary narrow fields");const auto v=ref_read<c::Vec3>(memory.data(),at+8);check(a.position.x==v.x&&a.position.y==v.y&&a.position.z==v.z,"original auxiliary float positions");++auxiliary_count;}
}
void zero_categories(){
    for(const auto counts:{std::pair{0u,0u},std::pair{0u,1u},std::pair{1u,0u}}){const auto table=8+4*(counts.first+counts.second);std::vector<std::byte> bytes(table+counts.first*104+counts.second*28+20);const auto word=[&](unsigned at,std::uint32_t value){std::memcpy(bytes.data()+at,&value,4);};word(0,counts.first);word(4,counts.second);if(counts.first||counts.second){word(8,table);word(table,1);word(table+counts.first*104+counts.second*28,123);}section(bytes);if(!counts.first)check(memory[0x3c3000]==0,"zero region count performs no first body");if(!counts.second)check(memory[0x3c3d00]==0,"zero auxiliary count performs no first body");}
}
int main(int argc,char** argv){check(argc==2,"owned RDT region manifest argument");std::ifstream manifest(argv[1]);std::string path;while(std::getline(manifest,path)){if(path.empty())continue;std::ifstream file(path,std::ios::binary);const std::vector<char> raw{std::istreambuf_iterator<char>(file),{}};check(!raw.empty(),"owned section10 fixture");section(std::as_bytes(std::span(raw)));++assets;}zero_categories();check(assets>150,"complete owned authored-region asset corpus");std::printf("{\"checks\":%u,\"owned_assets\":%u,\"regions\":%u,\"auxiliary\":%u,\"queries\":%u,\"zero_categories_verified\":true,\"game_launched\":false}\n",checks,assets,region_count,auxiliary_count,queries);}
