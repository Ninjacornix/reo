#include "sweep.hpp"
#include "sweep_reference.hpp"
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iterator>
#include <random>
namespace c=reo::native::gameplay_collision;
namespace s=c::sweep;
unsigned checks{},indeterminate{};float maximum_error{};
void check(bool value,const char* reason){++checks;if(!value){std::fprintf(stderr,"sweep check %u failed: %s\n",checks,reason);std::exit(1);}}
std::vector<std::uint8_t>& storage(){static std::vector<std::uint8_t> value(0x800000);return value;}
R5900Context context(std::uint32_t entry){R5900Context c;c.pc=entry;c.g[29].lo=0x7f0000;c.g[31].lo=0x1234;return c;}
void vector_equal(c::Vec3 a,c::Vec3 b,const char* reason){
    const auto axis=[&](float x,float y){const auto error=std::abs(x-y);maximum_error=std::max(maximum_error,error);
        if(!(error<=0.0001f+std::abs(y)*0.00002f))std::fprintf(stderr,"native=%g original=%g\n",double(x),double(y));
        check(error<=0.0001f+std::abs(y)*0.00002f,reason);};axis(a.x,b.x);axis(a.y,b.y);axis(a.z,b.z);
}
void compare(s::Input input,std::span<const s::Triangle> triangles){
    auto& memory=storage();std::fill(memory.begin()+0x743ea0,memory.begin()+0x744220,0);std::fill(memory.begin()+0x7ef000,memory.begin()+0x7f0000,0);
    ref_write(memory.data(),0x73fc30,1.8f);ref_write(memory.data(),0x38b280,0.0010000000474974513f);ref_write(memory.data(),0x1000,input);
    const c::Vec3 marker{12345,23456,34567};ref_write(memory.data(),0x1200,marker);ref_write(memory.data(),0x1210,marker);
    s::Contacts contacts(input);PS2Runtime runtime;
    for(const auto& triangle:triangles){ref_write(memory.data(),0x2000,triangle);auto ctx=context(0x617e70);ctx.g[4].lo=0x1000;ctx.g[5].lo=0x2000;ctx.g[6].lo=0x1200;ctx.g[7].lo=0x1210;
        o2_00617E70_0x617e70(memory.data(),&ctx,&runtime);const auto native=contacts.collect(triangle);check(native==(ctx.g[2].lo!=0),"actual original triangle admission");}
    const auto records=contacts.records();check(records.size()==ref_read<std::uint16_t>(memory.data(),0x743eb0),"original six-contact capacity");
    for(unsigned i=0;i<records.size();++i){const auto& record=records[i];check(unsigned(record.kind)==ref_read<std::uint16_t>(memory.data(),0x743eb8+2*i),"original face/edge kind");check(record.side==ref_read<std::uint16_t>(memory.data(),0x743ec8+2*i),"original plane-side classification");
        vector_equal(record.start,ref_read<c::Vec3>(memory.data(),0x743fa0+12*i),"original query anchor");vector_equal(record.point,ref_read<c::Vec3>(memory.data(),0x743f40+12*i),"original contact point");
        if(record.kind==s::Kind::edge)vector_equal(record.plane_point,ref_read<c::Vec3>(memory.data(),0x743ee0+12*i),"original edge plane anchor");}
    const auto native=contacts.resolve();
    if(native.status!=s::Status::ok){++indeterminate;return;}
    ref_write(memory.data(),0x1300,c::Vec3{});auto ctx=context(0x618680);ctx.g[4].lo=0x1000;ctx.g[5].lo=0x1300;o2_00618680_0x618680(memory.data(),&ctx,&runtime);
    vector_equal(native.correction,ref_read<c::Vec3>(memory.data(),0x1300),"original selected contact correction");
    if(native.selected_count!=memory[0x743ea8]){std::fprintf(stderr,"selected native=%u original=%u contacts=%zu start(%g,%g,%g) end(%g,%g,%g) radius%g\n",unsigned(native.selected_count),unsigned(memory[0x743ea8]),records.size(),double(input.start.x),double(input.start.y),double(input.start.z),double(input.end.x),double(input.end.y),double(input.end.z),double(input.radius));for(unsigned i=0;i<records.size();++i)std::fprintf(stderr,"record%u kind%u side%u point(%g,%g,%g) normal(%g,%g,%g)\n",i,unsigned(records[i].kind),unsigned(records[i].side),double(records[i].point.x),double(records[i].point.y),double(records[i].point.z),double(records[i].triangle.normal.x),double(records[i].triangle.normal.y),double(records[i].triangle.normal.z));}
    check(native.selected_count==memory[0x743ea8],"original selected contact count");
    for(unsigned i=0;i<native.selected_count;++i)check(native.selected[i]==memory[0x744188+i],"original selected contact order");
    if(contacts.reported_point())vector_equal(*contacts.reported_point(),ref_read<c::Vec3>(memory.data(),0x1200),"original optional reported point");else vector_equal(marker,ref_read<c::Vec3>(memory.data(),0x1200),"unwritten hit point remains unclaimed");
}
unsigned owned_queries{},owned_indeterminate{};
std::array<unsigned,4> owned_status{};
std::array<unsigned,4> mask_indeterminate{};
std::ofstream unsupported;
void compare_grid(const char* path){
    std::ifstream file(path,std::ios::binary);std::vector<char> raw((std::istreambuf_iterator<char>(file)),{});
    const auto grid=c::response::Grid::import(std::as_bytes(std::span(raw)));auto& memory=storage();constexpr std::uint32_t base=0x200000;
    std::memcpy(memory.data()+base,raw.data(),raw.size());auto init=context(0x6161e0);init.g[4].lo=base;PS2Runtime runtime;o2_006161E0_0x6161e0(memory.data(),&init,&runtime);
    ref_write(memory.data(),0x73fc30,1.8f);ref_write(memory.data(),0x38b280,0.0010000000474974513f);
    constexpr std::array<float,8> offsets{-1,-1,0,-1,-1,0,0,0};std::memcpy(memory.data()+0x70ef10,offsets.data(),sizeof offsets);
    unsigned triangle_index{};
    for(const auto& t:grid.triangles()){
        const auto index=triangle_index++;
        const c::Vec3 midpoint{((t.vertices[0].x+t.vertices[1].x)+t.vertices[2].x)/3,((t.vertices[0].y+t.vertices[1].y)+t.vertices[2].y)/3,((t.vertices[0].z+t.vertices[1].z)+t.vertices[2].z)/3};
        const c::Vec3 start{midpoint.x+t.normal.x*12.5f,midpoint.y+t.normal.y*12.5f,midpoint.z+t.normal.z*12.5f};
        const c::Vec3 end{start.x+t.normal.x*2,start.y+t.normal.y*2,start.z+t.normal.z*2};const auto input=s::input(start,end,25);
        constexpr std::array<std::uint32_t,4> masks{0xffffffffu,0x1ffffu,0x41ffffu,0x20ffffu};
        for(unsigned profile=0;profile<masks.size();++profile){c::response::Filter filter;filter.include=masks[profile];
        const auto native=s::query(grid,input,filter);++owned_queries;
        if(native.resolution.status!=s::Status::ok){++owned_indeterminate;++owned_status[unsigned(native.resolution.status)];
            ++mask_indeterminate[profile];
            const auto correction=native.resolution.correction;
            check(std::isfinite(correction.x)&&std::isfinite(correction.y)&&std::isfinite(correction.z),"recovered source face yields finite native correction");
            const auto repeated=s::query(grid,input,filter);vector_equal(correction,repeated.resolution.correction,"recovered source face is deterministic");
            check(native.resolution.selected_count<=native.resolution.contact_count,"native recovered selection stays within six owned contacts");
            const std::string source=path;const auto name=source.substr(source.find_last_of("/\\")+1);
            if(unsupported)unsupported<<"{\"asset\":\""<<name<<"\",\"triangle\":"<<index<<",\"status\":"<<unsigned(native.resolution.status)<<",\"start\":["<<start.x<<","<<start.y<<","<<start.z<<"],\"end\":["<<end.x<<","<<end.y<<","<<end.z<<"],\"radius\":25,\"include\":"<<masks[profile]<<",\"exclude\":0,\"contacts\":"<<unsigned(native.resolution.contact_count)<<"}\n";
            continue;}
        ref_write(memory.data(),256,end);ref_write(memory.data(),272,start);const c::Vec3 marker{12345,23456,34567};ref_write(memory.data(),512,marker);ref_write(memory.data(),528,marker);ref_write(memory.data(),544,marker);
        auto ctx=context(0x6177c0);ctx.g[4].lo=256;ctx.g[5].lo=272;ctx.g[6].lo=512;ctx.g[7].lo=528;ctx.g[8].lo=544;ctx.g[9].lo=masks[profile];ctx.f[12]=25;
        o2_006177C0_0x6177c0(memory.data(),&ctx,&runtime);
        check(native.resolution.contact_count==ctx.g[2].lo,"owned grid full-query admitted contact count");
        if(native.inside_grid){vector_equal(native.resolution.correction,ref_read<c::Vec3>(memory.data(),528),"owned grid full-query correction");check(native.resolution.selected_count==memory[0x743ea8],"owned grid selected count");for(unsigned i=0;i<native.resolution.selected_count;++i)check(native.resolution.selected[i]==memory[0x744188+i],"owned grid selected order");}
        else vector_equal(marker,ref_read<c::Vec3>(memory.data(),528),"out-of-grid query preserves correction output");
        }
    }
}
int main(int argc,char** argv){
    if(argc==3)unsupported.open(argv[2]);
    const s::Triangle wall{0x00270000,{{{0,0,0},{0,100,0},{0,0,100}}},{1,0,0},0};
    const s::Triangle floor{0x00270000,{{{0,0,0},{0,0,100},{100,0,0}}},{0,1,0},0};
    const s::Triangle adjacent{0x00270000,{{{0,0,100},{0,100,0},{0,100,100}}},{1,0,0},0};
    for(float x:{-5.0f,-2.0f,-1.0f,0.0f,1.0f,2.0f,5.0f})for(float y:{-3.0f,-1.0f,0.0f,1.0f,30.0f,99.0f,101.0f})for(float end_x:{-1.0f,1.0f,5.0f}){
        const auto input=s::input({x,y,30},{end_x,y,30},2);compare(input,std::span(&wall,1));const std::array mixed{wall,floor,adjacent};compare(input,mixed);}
    const std::array<s::Triangle,7> repeated{wall,wall,wall,wall,wall,wall,wall};compare(s::input({1,20,20},{1,20,20},2),repeated);
    std::mt19937 random(0x617e70);const auto scalar=[&]{return float(int(random()%12000)-1000)/100;};
    const std::array pool{wall,floor,adjacent};
    for(unsigned i=0;i<2500;++i){const c::Vec3 start{scalar(),scalar(),scalar()},end{scalar(),scalar(),scalar()};const float radius=float(random()%1000+1)/100;
        std::array<s::Triangle,6> batch;const unsigned count=1+random()%6;for(unsigned n=0;n<count;++n)batch[n]=pool[random()%pool.size()];compare(s::input(start,end,radius),std::span(batch).first(count));}
    unsigned assets{};
    if(argc>=2){std::ifstream list(argv[1]);std::string path;while(std::getline(list,path)){if(path.empty())continue;compare_grid(path.c_str());++assets;}}
    std::printf("{\"checks\":%u,\"maximum_error\":%.9g,\"indeterminate_original_cases\":%u,\"owned_wall_assets\":%u,\"owned_queries\":%u,\"owned_indeterminate_queries\":%u,\"owned_exclusion_overflow\":%u,\"owned_face_source_indeterminate\":%u,\"mask_indeterminate\":[%u,%u,%u,%u],\"game_launched\":false}\n",checks,double(maximum_error),indeterminate,assets,owned_queries,owned_indeterminate,owned_status[2],owned_status[3],mask_indeterminate[0],mask_indeterminate[1],mask_indeterminate[2],mask_indeterminate[3]);
}
