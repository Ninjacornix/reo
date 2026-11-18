#include "game/native/gameplay_world/surfaces.hpp"
#include "surface_runtime.hpp"
#include <bit>
#include <iostream>
#include <vector>
namespace gw=reo::native::gameplay_world;
namespace c=reo::native::gameplay_collision;
constexpr std::uint32_t base=0x4a5c30;
template<class T>T get(const std::uint8_t* r,std::uint32_t at){return oracle_read<T>(r,at);}
template<class T>void put(std::uint8_t* r,std::uint32_t at,T v){oracle_write<T>(r,at,v);}
void write(std::uint8_t* r,const gw::Actor& a){
    put(r,base+0x38,a.position);put(r,base+0x44,a.previous_position);put(r,base+0x90,a.orientation);put(r,base+0xa0,a.previous_orientation);
    put(r,base+0x170,a.grid_response);r[base+0x174]=a.surface_kind;r[base+0x175]=a.surface_material;put(r,base+0x176,a.surface_attributes);put(r,base+0x178,a.surface_normal);
    put(r,base+0x184,a.sampled_surface_height);r[base+0x188]=a.sampled_surface_valid?1:0;r[base+0x553]=a.movement_enabled;put(r,base+0xba0,a.status);
}
const c::response::Grid* floors;
void o2_00616ED0_0x616ed0(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_00616F20_0x616f20(std::uint8_t*,R5900Context*,PS2Runtime*);
void original_port(std::uint8_t* r,R5900Context* ctx,PS2Runtime* runtime){
    if(ctx->pc==0x616ed0){o2_00616ED0_0x616ed0(r,ctx,runtime);return;}
    if(ctx->pc==0x616f20){o2_00616F20_0x616f20(r,ctx,runtime);return;}
    if(ctx->pc!=0x617000)throw std::runtime_error("Undeclared original surface call");
    const auto result=floors->floor(get<c::Vec3>(r,GPR_U32(ctx,4)),std::uint8_t(GPR_U32(ctx,8)));
    if(GPR_U32(ctx,11)!=0)throw std::runtime_error("Surface query mode ABI");
    put(r,GPR_U32(ctx,5),result.normal);r[GPR_U32(ctx,7)]=result.type;r[GPR_U32(ctx,9)]=result.material;put(r,GPR_U32(ctx,10),result.attributes);
    ctx->f[0]=result.height;ctx->pc=GPR_U32(ctx,31);
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#include "original_surfaces.cpp"
#pragma GCC diagnostic pop
c::response::Grid grid(std::uint32_t flags,float y){
    std::vector<std::uint8_t> bytes(256);
    const auto word=[&](std::uint32_t at,std::uint32_t v){std::memcpy(bytes.data()+at,&v,4);};
    word(8,1000);word(12,1000);word(16,1);word(20,1);word(24,0);word(28,0);word(32,32);word(36,56);word(40,36);word(44,0);word(48,56);word(52,UINT32_MAX);
    const c::response::Triangle first{flags,{{{0,y,0},{1000,y,0},{0,y,1000}}},{0,1,0},-y};
    const c::response::Triangle second{flags,{{{1000,y,0},{1000,y,1000},{0,y,1000}}},{0,1,0},-y};
    std::memcpy(bytes.data()+64,&first,56);std::memcpy(bytes.data()+120,&second,56);
    return c::response::Grid::import(std::as_bytes(std::span(bytes)));
}
int main()try{
    std::vector<std::uint8_t> ram(0x2000000,0xa5),expected(ram);std::uint64_t cases{},special{},rollback{};
    const std::array grids{grid(0x12340903,0),grid(0x56780701,0),grid(0x00800081,0),grid(0x12340903,300)};
    for(std::uint32_t seed=0;seed<16384;++seed){
        floors=&grids[(seed/4)%grids.size()];gw::Actor a;a.position={float((seed*13)%1400),float(int(seed%600)-150),float((seed*23)%1400)};
        a.previous_position={-17,23,-9};a.orientation={1,2,3,4};a.previous_orientation={-1,-2,-3,-4};
        a.grid_response=999;a.surface_kind=7;a.surface_material=9;a.surface_attributes=0x5678;a.surface_normal={1,2,3};
        a.sampled_surface_height=333;a.sampled_surface_valid=seed%2;a.movement_enabled=77;a.status=(seed/16)%256;
        write(ram.data(),a);std::copy(ram.begin()+base,ram.begin()+base+0xc00,expected.begin()+base);
        R5900Context ctx;SET_GPR_U32(&ctx,4,base);SET_GPR_U32(&ctx,29,0x1ff0000);SET_GPR_U32(&ctx,31,0x123456);PS2Runtime rt;rt.port=original_port;
        if(seed%3){ctx.pc=0x666580;o2_00666580_0x666580(ram.data(),&ctx,&rt);gw::sample_surface(a,*floors);}
        ctx.pc=0x666450;SET_GPR_U32(&ctx,4,base);o2_00666450_0x666450(ram.data(),&ctx,&rt);gw::resolve_surface(a,*floors);write(expected.data(),a);
        if(ctx.pc!=0x123456)throw std::runtime_error("Original surface return");
        for(std::uint32_t i=base;i<base+0xc00;++i)if(ram[i]!=expected[i])throw std::runtime_error("Surface mismatch seed "+std::to_string(seed)+" at "+std::to_string(i));
        ++cases;special+=a.surface_kind==3;rollback+=a.position.x==-17;
    }
    if(special==0 || rollback==0)throw std::runtime_error("Surface special/rollback coverage");
    std::cout<<"{\"status\":\"passed\",\"cases\":"<<cases<<",\"special_surfaces\":"<<special<<",\"transform_rollbacks\":"<<rollback<<"}\n";
    return 0;
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
