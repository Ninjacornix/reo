#include "reo_movie_game_addresses.h"
#include "original_transport_route.h"
#include "movie_join_observer.h"
void REO_MS_145D60(uint8_t*,R5900Context*,PS2Runtime*);
void REO_MS_170D90(uint8_t*,R5900Context*,PS2Runtime*);
void REO_MS_170DE0(uint8_t*,R5900Context*,PS2Runtime*);
void REO_MS_1719A0(uint8_t*,R5900Context*,PS2Runtime*);
void REO_MS_1719C8(uint8_t*,R5900Context*,PS2Runtime*);
void reo_movie_native_170d90(uint8_t*,R5900Context*,PS2Runtime*);
void REO_MS_170AE8(uint8_t*,R5900Context*,PS2Runtime*);
void reo_movie_native_170ae8(uint8_t*,R5900Context*,PS2Runtime*);
void REO_MS_171880(uint8_t*,R5900Context*,PS2Runtime*);
void reo_movie_native_171880(uint8_t*,R5900Context*,PS2Runtime*);
void REO_MS_171920(uint8_t*,R5900Context*,PS2Runtime*);
void reo_movie_native_171920(uint8_t*,R5900Context*,PS2Runtime*);
void REO_MS_1570D8(uint8_t*,R5900Context*,PS2Runtime*);
void reo_movie_native_1570d8(uint8_t*,R5900Context*,PS2Runtime*);
void REO_MS_16AEA0(uint8_t*,R5900Context*,PS2Runtime*);
void reo_movie_native_16aea0(uint8_t*,R5900Context*,PS2Runtime*);
namespace reo_gpu_movie_transport {
namespace {
void picture(uint8_t* ram,R5900Context* ctx,PS2Runtime* runtime){
    if(ctx->pc==REO_MA(0x145d60))metadata(runtime,"picture-header",[&]{if(binding.pictureHeader)binding.pictureHeader(binding.headerOwner,*runtime,*ctx,GPR_U32(ctx,4));});
    REO_MS_145D60(ram,ctx,runtime);
}
}
bool install(PS2Runtime& runtime,reo_gpu_movie::OriginalCompressedLineage& lineage,void* owner,PictureHeader header,RingReset reset){
    if(binding.runtime||!owner||!header||runtime.lookupFunction(REO_MA(0x145d60))!=REO_MS_145D60)return false;
    if(runtime.lookupFunction(REO_MA(0x171920))!=REO_MS_171920)return false;
    constexpr uint32_t aliases170D90[]{REO_MA(0x170d90),REO_MA(0x170db0),REO_MA(0x170e00),REO_MA(0x170e20),REO_MA(0x170e48)};
    // Mid-function entries are registered to the enclosing original function by older generated
    // output, and to the function whose Ghidra range contains them by the local build generator.
    // Both bodies hold the same original instructions; the native replacement takes over each entry.
    for(auto pc:aliases170D90){const auto f=runtime.lookupFunction(pc);if(f!=REO_MS_170D90&&f!=reo_movie_commit_observed&&!(pc>=REO_MA(0x170de0)&&f==REO_MS_170DE0))return false;}
    constexpr uint32_t aliases170AE8[]{REO_MA(0x170ae8),REO_MA(0x170b3c),REO_MA(0x170b48)};
    for(auto pc:aliases170AE8){const auto f=runtime.lookupFunction(pc);if(f!=REO_MS_170AE8&&f!=reo_movie_initialize_observed)return false;}
    constexpr uint32_t aliases171880[]{REO_MA(0x171880),REO_MA(0x1718b4),REO_MA(0x1718f4),REO_MA(0x171904),REO_MA(0x171944),REO_MA(0x171978),REO_MA(0x171988),REO_MA(0x1719b4),REO_MA(0x1719dc)};
    for(auto pc:aliases171880){const auto f=runtime.lookupFunction(pc);if(f!=REO_MS_171880&&!(pc>=REO_MA(0x171920)&&pc<REO_MA(0x1719a0)&&f==REO_MS_171920)&&!(pc>=REO_MA(0x1719a0)&&pc<REO_MA(0x1719c8)&&f==REO_MS_1719A0)&&!(pc>=REO_MA(0x1719c8)&&f==REO_MS_1719C8))return false;}
    constexpr uint32_t aliases1570D8[]{REO_MA(0x1570d8),REO_MA(0x157390)};
    for(auto pc:aliases1570D8){const auto f=runtime.lookupFunction(pc);if(f!=REO_MS_1570D8)return false;}
    constexpr uint32_t aliases16AEA0[]{REO_MA(0x16aea0),REO_MA(0x16aee8),REO_MA(0x16af28),REO_MA(0x16af3c),REO_MA(0x16af4c),REO_MA(0x16af60),REO_MA(0x16af88)};
    for(auto pc:aliases16AEA0)if(runtime.lookupFunction(pc)!=REO_MS_16AEA0)return false;
    binding={&runtime,&lineage,owner,header,reset};
    runtime.registerFunction(REO_MA(0x145d60),picture);
    runtime.registerFunction(REO_MA(0x171920),reo_movie_native_171920);
    for(auto pc:aliases170D90)runtime.registerFunction(pc,reo_movie_native_170d90);
    for(auto pc:aliases170AE8)runtime.registerFunction(pc,reo_movie_native_170ae8);
    for(auto pc:aliases171880)runtime.registerFunction(pc,reo_movie_native_171880);
    for(auto pc:aliases1570D8)runtime.registerFunction(pc,reo_movie_native_1570d8);
    for(auto pc:aliases16AEA0)runtime.registerFunction(pc,reo_movie_native_16aea0);
    return true;
}
}
