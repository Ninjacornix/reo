#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00191530
// Address: 0x191530 - 0x19157c
void sub_00191530_0x191530(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00191530_0x191530");
#endif

    ctx->pc = 0x191530u;

    // 0x191530: 0xc4a00000  lwc1        $f0, 0x0($a1)
    ctx->pc = 0x191530u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191534: 0xe4800000  swc1        $f0, 0x0($a0)
    ctx->pc = 0x191534u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 0), bits); }
    // 0x191538: 0xc4a00004  lwc1        $f0, 0x4($a1)
    ctx->pc = 0x191538u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19153c: 0xe4800004  swc1        $f0, 0x4($a0)
    ctx->pc = 0x19153cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 4), bits); }
    // 0x191540: 0xc4a00008  lwc1        $f0, 0x8($a1)
    ctx->pc = 0x191540u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191544: 0xe4800008  swc1        $f0, 0x8($a0)
    ctx->pc = 0x191544u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 8), bits); }
    // 0x191548: 0xc4a00010  lwc1        $f0, 0x10($a1)
    ctx->pc = 0x191548u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19154c: 0xe4800010  swc1        $f0, 0x10($a0)
    ctx->pc = 0x19154cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 16), bits); }
    // 0x191550: 0xc4a00014  lwc1        $f0, 0x14($a1)
    ctx->pc = 0x191550u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 20)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191554: 0xe4800014  swc1        $f0, 0x14($a0)
    ctx->pc = 0x191554u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 20), bits); }
    // 0x191558: 0xc4a00018  lwc1        $f0, 0x18($a1)
    ctx->pc = 0x191558u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 24)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19155c: 0xe4800018  swc1        $f0, 0x18($a0)
    ctx->pc = 0x19155cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 24), bits); }
    // 0x191560: 0xc4a00020  lwc1        $f0, 0x20($a1)
    ctx->pc = 0x191560u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 32)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191564: 0xe4800020  swc1        $f0, 0x20($a0)
    ctx->pc = 0x191564u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 32), bits); }
    // 0x191568: 0xc4a00024  lwc1        $f0, 0x24($a1)
    ctx->pc = 0x191568u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19156c: 0xe4800024  swc1        $f0, 0x24($a0)
    ctx->pc = 0x19156cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 36), bits); }
    // 0x191570: 0xc4a00028  lwc1        $f0, 0x28($a1)
    ctx->pc = 0x191570u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 40)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191574: 0x3e00008  jr          $ra
    ctx->pc = 0x191574u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x191578u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x191574u;
            // 0x191578: 0xe4800028  swc1        $f0, 0x28($a0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 40), bits); }
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x19157Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
