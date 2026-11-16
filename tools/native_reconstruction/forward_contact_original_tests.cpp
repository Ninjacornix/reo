#include "trace_reference.hpp"
#include "game/native/gameplay_world/forward_contact.hpp"
#include <array>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iterator>

namespace c=reo::native::gameplay_collision;
namespace w=reo::native::gameplay_world;
namespace {
std::vector<std::uint8_t> rdram(0x800000),initial;
unsigned checks{};
unsigned hits{},misses{};
void check(bool value,const char* message){++checks;if(!value){std::fprintf(stderr,"forward-contact check %u failed: %s\n",checks,message);std::exit(1);}}
void word(std::vector<std::byte>& bytes,std::size_t at,std::uint32_t value){for(unsigned i=0;i<4;++i)bytes[at+i]=std::byte(value>>(8*i));}
std::vector<std::byte> raw_grid(bool empty=false){
    std::vector<std::byte> bytes(344);
    word(bytes,8,1000);word(bytes,12,1000);word(bytes,16,1);word(bytes,20,1);
    word(bytes,24,0);word(bytes,28,0);word(bytes,32,32);word(bytes,36,56);
    word(bytes,40,56);
    for(unsigned i=0;i<4;++i)word(bytes,64+4*i,empty?0xffffffffu:56+56*i);
    word(bytes,80,0xffffffffu);
    const std::array<std::array<c::Vec3,3>,4> vertices{{
        {{{0,-500,540},{1000,-500,540},{500,500,540}}},
        {{{0,-500,460},{1000,-500,460},{500,500,460}}},
        {{{540,-500,0},{540,-500,1000},{540,500,500}}},
        {{{460,-500,0},{460,-500,1000},{460,500,500}}}
    }};
    for(unsigned i=0;i<4;++i){
        const auto at=120+56*i;word(bytes,at,0x00010001u);
        std::memcpy(bytes.data()+at+4,vertices[i].data(),sizeof(vertices[i]));
        const c::Vec3 normal=i<2?c::Vec3{0,0,i==0?-1.f:1.f}:c::Vec3{i==2?-1.f:1.f,0,0};
        std::memcpy(bytes.data()+at+40,&normal,sizeof(normal));
        word(bytes,at+52,std::bit_cast<std::uint32_t>(i==0?540.f:i==1?-460.f:i==2?540.f:-460.f));
    }
    return bytes;
}
void equal(float a,float b,const char* message){const auto ok=(std::isnan(a)&&std::isnan(b))||std::abs(a-b)<=0.002f;if(!ok)std::fprintf(stderr,"%s native=%.9g original=%.9g diff=%.9g\n",message,a,b,a-b);check(ok,message);}
void compare_case(const c::response::Grid& grid,std::span<const std::byte> bytes,
                  std::uint16_t yaw,float offset,std::uint32_t include,std::uint32_t exclude,
                  c::Vec3 start={500,20,500}){
    rdram=initial;
    constexpr std::uint32_t grid_address=0x300000,actor_address=0x500000;
    std::memcpy(rdram.data()+grid_address,bytes.data(),bytes.size());
    ref_write(rdram.data(),0x743720,0xffffffffu);ref_write(rdram.data(),0x3c2748,0u);
    auto init=context(0x6161e0);init.g[4].lo=grid_address;PS2Runtime runtime;
    o2_006161E0_0x6161e0(rdram.data(),&init,&runtime);
    const c::Vec3 marker{12345,23456,34567},normal_marker{34567,45678,56789};
    ref_write(rdram.data(),actor_address+0x38,start);ref_write(rdram.data(),actor_address+0x92,yaw);
    ref_write(rdram.data(),actor_address+0x528,marker);ref_write(rdram.data(),actor_address+0x534,normal_marker);
    rdram[actor_address+0x540]=0xa5;
    auto call=context(0x65f4a0);call.g[4].lo=actor_address;call.g[5].lo=include;call.g[6].lo=exclude;call.f[12]=offset;
    o2_0065F4A0_0x65f4a0(rdram.data(),&call,&runtime);
    const auto source_point=ref_read<c::Vec3>(rdram.data(),actor_address+0x528);
    const auto source_normal=ref_read<c::Vec3>(rdram.data(),actor_address+0x534);
    const auto source_status=rdram[actor_address+0x540];
    if(source_point.x!=marker.x||source_point.y!=marker.y||source_point.z!=marker.z)++hits;else ++misses;

    w::Actor actor;actor.position={start.x,start.y,start.z};actor.orientation[1]=std::bit_cast<std::int16_t>(yaw);
    actor.projectile_contact={marker,normal_marker};actor.forward_contact_status=0xa5;
    const auto native=w::probe_forward_contact(actor,grid,include,exclude,offset);
    check(native.status==w::ForwardContactStatus::completed,"native 65F4A0 accepts complete grid trace");
    check(native.original_result==std::uint16_t(call.g[2].lo),"65F4A0 low-halfword query result from original5795E0");
    check(actor.forward_contact_status&&*actor.forward_contact_status==source_status,"65F4A0 stores actual5795E0 return byte at+540");
    equal(actor.projectile_contact.point.x,source_point.x,"65F4A0 +528 X");
    equal(actor.projectile_contact.point.y,source_point.y,"65F4A0 +52C Y");
    equal(actor.projectile_contact.point.z,source_point.z,"65F4A0 +530 Z");
    equal(actor.projectile_contact.normal.x,source_normal.x,"65F4A0 +534 X");
    equal(actor.projectile_contact.normal.y,source_normal.y,"65F4A0 +538 Y");
    equal(actor.projectile_contact.normal.z,source_normal.z,"65F4A0 +53C Z");
    ++checks;
}
}
int main(int argc,char** argv){
    check(argc==2,"full PT_LOAD plus overlay-memory image argument");
    std::ifstream input(argv[1],std::ios::binary);initial={std::istreambuf_iterator<char>(input),{}};
    check(initial.size()==rdram.size(),"pinned original memory image has RDRAM extent");
    const auto bytes=raw_grid();const auto grid=c::response::Grid::import(bytes);
    for(const auto yaw:std::array<std::uint16_t,6>{0,16384,32768,49152,65535,12345})
        for(const float offset:std::array{-75.f,-55.f,10.f,55.f,75.f})
            for(const auto masks:std::array<std::pair<std::uint32_t,std::uint32_t>,4>{{{0,0},{0xffffffffu,0},{0x1ffffu,0},{0xffffffffu,0xffffffffu}}})
                compare_case(grid,bytes,yaw,offset,masks.first,masks.second);
    const auto empty_bytes=raw_grid(true);const auto empty_grid=c::response::Grid::import(empty_bytes);
    for(const auto yaw:std::array<std::uint16_t,6>{0,16384,32768,49152,65535,12345})
        compare_case(empty_grid,empty_bytes,yaw,55.f,0,0);
    // The owned 579730 collector returns its accumulated count when the
    // sample first leaves the grid. Exercise rays whose end and start are
    // outside the 1x1 grid through the complete 65F4A0 original body.
    compare_case(empty_grid,empty_bytes,0,2000.f,0,0);
    compare_case(empty_grid,empty_bytes,0,2000.f,0,0,{-500,20,500});

    // Keep a focused native check proving that a left-grid sample still
    // processes the final dynamic list and can report its hit.
    c::response::Triangle dynamic_triangle{};
    dynamic_triangle.vertices={c::Vec3{0,-100,1500},c::Vec3{1000,-100,1500},c::Vec3{500,100,1500}};
    dynamic_triangle.normal={0,0,-1};dynamic_triangle.plane_d=1500.f;dynamic_triangle.flags=0x00010001u;
    c::response::Filter dynamic_filter;dynamic_filter.include=0xffffffffu;
    const auto dynamic_result=c::trace::shorten(empty_grid,{500,20,500},{500,30,2500},dynamic_filter,
                                                 std::span<const c::response::Triangle>(&dynamic_triangle,1));
    check(dynamic_result.status==c::trace::SamplingStatus::left_grid,"dynamic query records normal grid-boundary termination");
    check(dynamic_result.hit.has_value(),"dynamic list is tested after left-grid cell collection");
    check(hits&&misses,"exercise both source hit and miss return paths");
    std::printf("{\"checks\":%u,\"hits\":%u,\"misses\":%u,\"original_bodies\":[\"65F4A0\",\"6161E0\",\"616CC0\",\"617430\",\"6175C0\",\"619A50\",\"579140\",\"579300\",\"5795E0\",\"579730\",\"3700C0\",\"370100\",\"370AC0\",\"370B00\",\"370C70\",\"370FE0\",\"191EF0\"],\"math_ports\":[\"192100 acos\",\"192190 sin\",\"1921A0 cos\"],\"game_launched\":false}\n",checks,hits,misses);
}
