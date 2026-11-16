#include "trace_reference.hpp"
#include <array>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iterator>
#include <vector>

using Point=std::array<float,3>;
struct Capture { bool seen{}; std::uint32_t function{},a0{},a1{},a2{}; float radius{}; Point point{}; } capture;
std::uint8_t memory[0x500000]{};
void check(bool condition,const char* message){if(!condition){std::fprintf(stderr,"actor query oracle: %s\n",message);std::exit(1);}}
void query_capture(std::uint8_t* ram,R5900Context* ctx,PS2Runtime*){
    capture.seen=true;capture.function=ctx->pc;capture.a0=GPR_U32(ctx,4);capture.a1=GPR_U32(ctx,5);capture.a2=GPR_U32(ctx,6);capture.radius=ctx->f[12];
    capture.point=ref_read<Point>(ram,capture.a0);
}
void sine_port(std::uint8_t*,R5900Context* ctx,PS2Runtime*){ctx->f[0]=std::sin(ctx->f[12]);ctx->pc=GPR_U32(ctx,31);}
void cosine_port(std::uint8_t*,R5900Context* ctx,PS2Runtime*){ctx->f[0]=std::cos(ctx->f[12]);ctx->pc=GPR_U32(ctx,31);}
int main(int argc,char** argv){
    check(argc==2,"missing owned overlay image");std::ifstream source(argv[1],std::ios::binary);std::vector<char> image((std::istreambuf_iterator<char>(source)),{});check(image.size()==sizeof(memory),"overlay image extent");std::memcpy(memory,image.data(),image.size());
    constexpr std::uint32_t actor=0x10000;
    const Point position{13.25f,27.5f,-49.75f};
    const float height=17.25f;
    std::memcpy(memory+actor+0x38,&position[0],4);std::memcpy(memory+actor+0x3c,&position[1],4);std::memcpy(memory+actor+0x40,&position[2],4);
    std::memcpy(memory+actor+0x1b4,&height,4);ref_write(memory,actor+0x92,std::int16_t(0x2456));memory[actor+0xcb0]=0x6d;
    PS2Runtime runtime;R5900Context ctx{};ctx.g[29].lo=0x1f0000;ctx.g[31].lo=0xabcdef;
    std::array<Capture,4> observed{};
    for(std::uint32_t selector=0;selector<5;++selector){
        std::fprintf(stderr,"selector %u\n",selector);std::fflush(stderr);
        capture={};ctx={};ctx.pc=0x663190;ctx.g[4].lo=actor;ctx.g[5].lo=selector;ctx.g[6].lo=7;ctx.g[29].lo=0x1f0000;ctx.g[31].lo=0xabcdef;
        o2_00663190_0x663190(memory,&ctx,&runtime);
        if(selector<=3)check(capture.seen,"selector did not invoke a spatial consumer");else check(!capture.seen,"unsupported selector invoked a consumer");
        if(selector==0){check(capture.function==0x5dc570&&capture.a1==actor&&capture.a2==7&&capture.radius==50.0f,"selector0 ABI");check(capture.point==position,"selector0 point");}
        if(selector==1){check(capture.function==0x5dc570&&capture.a1==actor&&capture.a2==7&&capture.radius==50.0f,"selector1 ABI");}
        if(selector==2){check(capture.function==0x5dca90&&capture.a1==actor&&capture.a2==0x6d,"selector2 ABI");}
        if(selector==3){check(capture.function==0x5dc570&&capture.a1==actor&&capture.a2==7&&capture.radius==60.0f,"selector3 ABI");}
        if(selector<4)observed[selector]=capture;
    }
    std::printf("{\"selectors\":5,\"spatial_calls\":4,\"full_original_body\":true,\"queries\":[");
    for(unsigned i=0;i<observed.size();++i){const auto& q=observed[i];if(i)std::printf(",");std::printf("{\"selector\":%u,\"target\":%u,\"a1\":%u,\"a2\":%u,\"radius\":%.9g,\"point\":[%.9g,%.9g,%.9g]}",i,q.function,q.a1,q.a2,double(q.radius),double(q.point[0]),double(q.point[1]),double(q.point[2]));}
    std::printf("],\"game_launched\":false}\n");
}
