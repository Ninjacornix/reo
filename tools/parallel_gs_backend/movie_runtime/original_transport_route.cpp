#include "original_transport_route.h"
#include "movie_join_observer.h"
void sub_00145D60_0x145d60(uint8_t*,R5900Context*,PS2Runtime*);
void sub_00170D90_0x170d90(uint8_t*,R5900Context*,PS2Runtime*);
void sub_00170DE0_0x170de0(uint8_t*,R5900Context*,PS2Runtime*);
void sub_001719A0_0x1719a0(uint8_t*,R5900Context*,PS2Runtime*);
void sub_001719C8_0x1719c8(uint8_t*,R5900Context*,PS2Runtime*);
void reo_movie_native_170d90(uint8_t*,R5900Context*,PS2Runtime*);
void sub_00170AE8_0x170ae8(uint8_t*,R5900Context*,PS2Runtime*);
void reo_movie_native_170ae8(uint8_t*,R5900Context*,PS2Runtime*);
void sub_00171880_0x171880(uint8_t*,R5900Context*,PS2Runtime*);
void reo_movie_native_171880(uint8_t*,R5900Context*,PS2Runtime*);
void sub_00171920_0x171920(uint8_t*,R5900Context*,PS2Runtime*);
void reo_movie_native_171920(uint8_t*,R5900Context*,PS2Runtime*);
void sub_001570D8_0x1570d8(uint8_t*,R5900Context*,PS2Runtime*);
void reo_movie_native_1570d8(uint8_t*,R5900Context*,PS2Runtime*);
void sub_0016AEA0_0x16aea0(uint8_t*,R5900Context*,PS2Runtime*);
void reo_movie_native_16aea0(uint8_t*,R5900Context*,PS2Runtime*);
namespace reo_gpu_movie_transport {
namespace {
void picture(uint8_t* ram,R5900Context* ctx,PS2Runtime* runtime){
    if(ctx->pc==0x145d60)metadata(runtime,"picture-header",[&]{if(binding.pictureHeader)binding.pictureHeader(binding.headerOwner,*runtime,*ctx,GPR_U32(ctx,4));});
    sub_00145D60_0x145d60(ram,ctx,runtime);
}
}
bool install(PS2Runtime& runtime,reo_gpu_movie::OriginalCompressedLineage& lineage,void* owner,PictureHeader header,RingReset reset){
    if(binding.runtime||!owner||!header||runtime.lookupFunction(0x145d60)!=sub_00145D60_0x145d60)return false;
    if(runtime.lookupFunction(0x171920)!=sub_00171920_0x171920)return false;
    constexpr uint32_t aliases170D90[]{0x170d90,0x170db0,0x170e00,0x170e20,0x170e48};
    // Mid-function entries are registered to the enclosing original function by older generated
    // output, and to the function whose Ghidra range contains them by the local build generator.
    // Both bodies hold the same original instructions; the native replacement takes over each entry.
    for(auto pc:aliases170D90){const auto f=runtime.lookupFunction(pc);if(f!=sub_00170D90_0x170d90&&f!=reo_movie_commit_observed&&!(pc>=0x170de0&&f==sub_00170DE0_0x170de0))return false;}
    constexpr uint32_t aliases170AE8[]{0x170ae8,0x170b3c,0x170b48};
    for(auto pc:aliases170AE8){const auto f=runtime.lookupFunction(pc);if(f!=sub_00170AE8_0x170ae8&&f!=reo_movie_initialize_observed)return false;}
    constexpr uint32_t aliases171880[]{0x171880,0x1718b4,0x1718f4,0x171904,0x171944,0x171978,0x171988,0x1719b4,0x1719dc};
    for(auto pc:aliases171880){const auto f=runtime.lookupFunction(pc);if(f!=sub_00171880_0x171880&&!(pc>=0x171920&&pc<0x1719a0&&f==sub_00171920_0x171920)&&!(pc>=0x1719a0&&pc<0x1719c8&&f==sub_001719A0_0x1719a0)&&!(pc>=0x1719c8&&f==sub_001719C8_0x1719c8))return false;}
    constexpr uint32_t aliases1570D8[]{0x1570d8,0x157390};
    for(auto pc:aliases1570D8){const auto f=runtime.lookupFunction(pc);if(f!=sub_001570D8_0x1570d8)return false;}
    constexpr uint32_t aliases16AEA0[]{0x16aea0,0x16aee8,0x16af28,0x16af3c,0x16af4c,0x16af60,0x16af88};
    for(auto pc:aliases16AEA0)if(runtime.lookupFunction(pc)!=sub_0016AEA0_0x16aea0)return false;
    binding={&runtime,&lineage,owner,header,reset};
    runtime.registerFunction(0x145d60,picture);
    runtime.registerFunction(0x171920,reo_movie_native_171920);
    for(auto pc:aliases170D90)runtime.registerFunction(pc,reo_movie_native_170d90);
    for(auto pc:aliases170AE8)runtime.registerFunction(pc,reo_movie_native_170ae8);
    for(auto pc:aliases171880)runtime.registerFunction(pc,reo_movie_native_171880);
    for(auto pc:aliases1570D8)runtime.registerFunction(pc,reo_movie_native_1570d8);
    for(auto pc:aliases16AEA0)runtime.registerFunction(pc,reo_movie_native_16aea0);
    return true;
}
}
