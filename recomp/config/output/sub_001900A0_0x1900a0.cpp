#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001900A0
// Address: 0x1900a0 - 0x1900d4
void sub_001900A0_0x1900a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001900A0_0x1900a0");
#endif

    ctx->pc = 0x1900a0u;

    // 0x1900a0: 0xc4810030  lwc1        $f1, 0x30($a0)
    ctx->pc = 0x1900a0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1900a4: 0xc4a00000  lwc1        $f0, 0x0($a1)
    ctx->pc = 0x1900a4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1900a8: 0x46000800  add.s       $f0, $f1, $f0
    ctx->pc = 0x1900a8u;
    ctx->f[0] = FPU_ADD_S(ctx->f[1], ctx->f[0]);
    // 0x1900ac: 0xe4800030  swc1        $f0, 0x30($a0)
    ctx->pc = 0x1900acu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 48), bits); }
    // 0x1900b0: 0xc4a10004  lwc1        $f1, 0x4($a1)
    ctx->pc = 0x1900b0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1900b4: 0xc4800034  lwc1        $f0, 0x34($a0)
    ctx->pc = 0x1900b4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 52)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1900b8: 0x46010000  add.s       $f0, $f0, $f1
    ctx->pc = 0x1900b8u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[1]);
    // 0x1900bc: 0xe4800034  swc1        $f0, 0x34($a0)
    ctx->pc = 0x1900bcu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 52), bits); }
    // 0x1900c0: 0xc4a10008  lwc1        $f1, 0x8($a1)
    ctx->pc = 0x1900c0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1900c4: 0xc4800038  lwc1        $f0, 0x38($a0)
    ctx->pc = 0x1900c4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1900c8: 0x46010000  add.s       $f0, $f0, $f1
    ctx->pc = 0x1900c8u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[1]);
    // 0x1900cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1900CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1900D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1900CCu;
            // 0x1900d0: 0xe4800038  swc1        $f0, 0x38($a0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 56), bits); }
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1900D4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
