#include "game/native/gameplay_world/locomotion_floor.hpp"
#include "game/native/transform_math/transform_math.hpp"
#include <cstdio>
#include <fstream>
#include <vector>
namespace w=reo::native::gameplay_world;
namespace r=reo::native::gameplay_collision::response;
namespace c=reo::native::gameplay_collision;
namespace {
unsigned checks{},cases{},queries{};
const r::Grid* floors{};
std::vector<std::uint8_t> selectors;
void check(bool v){++checks;if(!v)throw std::runtime_error("locomotion floor check "+std::to_string(checks)+" case "+std::to_string(cases));}
void port(std::uint8_t* ram,R5900Context* ctx,PS2Runtime*){
    if(ctx->pc==0x1921b0){const auto trig=reo::native::transform_math::sin_cos(ctx->f[12]);ref_write(ram,GPR_U32(ctx,4),trig.sine);ref_write(ram,GPR_U32(ctx,5),trig.cosine);}
    else if(ctx->pc==0x616f20){const auto selector=std::uint8_t(GPR_U32(ctx,6));selectors.push_back(selector);++queries;const auto result=floors->floor(ref_read<c::Vec3>(ram,GPR_U32(ctx,4)),selector);ram[GPR_U32(ctx,5)]=result.type;ctx->f[0]=result.height;}
    else throw std::runtime_error("Unexpected locomotion floor dependency");
    ctx->pc=GPR_U32(ctx,31);
}
r::Grid grid(unsigned type){
    const r::Triangle triangle{type,{{{0,0,0},{2000,0,0},{0,0,2000}}},{0,1,0},0};
    std::vector<std::byte> raw(112);auto put=[&](unsigned at,unsigned v){std::memcpy(raw.data()+at,&v,4);};
    put(8,2000);put(12,2000);put(16,1);put(20,1);put(32,32);put(36,48);put(40,40);put(48,0);put(52,0xffffffffu);
    std::memcpy(raw.data()+56,&triangle,56);return r::Grid::import(raw);
}
}
PS2Runtime::Fn PS2Runtime::lookupFunction(unsigned at)const{
    if(at==0x191bc0)return sub_00191BC0_0x191bc0;
    if(at==0x1921b0||at==0x616f20)return port;
    throw std::runtime_error("Unexpected locomotion floor lookup "+std::to_string(at));
}
int main(int argc,char** argv)try{
    check(argc==2);std::vector<std::uint8_t> ram(0x800000);std::ifstream owned(argv[1],std::ios::binary);owned.read(reinterpret_cast<char*>(ram.data()+0x570000),1913088);check(bool(owned));
    PS2Runtime runtime;w::Actor actor;
    for(unsigned type:{0u,1u,2u,255u}){const auto value=grid(type);floors=&value;
        for(unsigned yaw=0;yaw<65536;yaw+=127)for(unsigned variant=0;variant<8;++variant){++cases;selectors.clear();
            actor.position={variant&1?500.f:1999.f,variant&2?20.f:-100.f,variant&1?500.f:1999.f};actor.orientation[1]=std::bit_cast<std::int16_t>(std::uint16_t(yaw));actor.root_motion_delta.z=variant&4?-1.f:0.f;
            constexpr unsigned at=0x10000,out=0x20000,done=0x1234;ref_write(ram.data(),at+0x38,actor.position);ref_write(ram.data(),at+0x92,actor.orientation[1]);ref_write(ram.data(),at+0x4ec,actor.root_motion_delta.z);
            R5900Context ctx{};ctx.g[4].lo=at;ctx.g[5].lo=out;ctx.g[29].lo=0x50000;ctx.g[31].lo=done;
            o2_00666BB0_0x666bb0(ram.data(),&ctx,&runtime);const auto result=w::probe_locomotion_floor(actor,value);check(ctx.pc==done);check(ctx.g[2].lo==result.type);check(selectors==std::vector<std::uint8_t>{1,255});
            const auto expected=ref_read<w::Position>(ram.data(),out);check(std::bit_cast<unsigned>(expected.x)==std::bit_cast<unsigned>(result.probe.x));check(std::bit_cast<unsigned>(expected.y)==std::bit_cast<unsigned>(result.probe.y));check(std::bit_cast<unsigned>(expected.z)==std::bit_cast<unsigned>(result.probe.z));
        }
    }
    std::printf("{\"checks\":%u,\"cases\":%u,\"floor_queries\":%u,\"game_run\":false}\n",checks,cases,queries);return 0;
}catch(const std::exception& e){std::fprintf(stderr,"%s\n",e.what());return 1;}
