#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00190070
// Address: 0x190070 - 0x190098
void sub_00190070_0x190070(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00190070_0x190070");
#endif

    ctx->pc = 0x190070u;

    // 0x190070: 0xc4800030  lwc1        $f0, 0x30($a0)
    ctx->pc = 0x190070u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x190074: 0x460c0000  add.s       $f0, $f0, $f12
    ctx->pc = 0x190074u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[12]);
    // 0x190078: 0xe4800030  swc1        $f0, 0x30($a0)
    ctx->pc = 0x190078u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 48), bits); }
    // 0x19007c: 0xc4800034  lwc1        $f0, 0x34($a0)
    ctx->pc = 0x19007cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 52)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x190080: 0x460d0000  add.s       $f0, $f0, $f13
    ctx->pc = 0x190080u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[13]);
    // 0x190084: 0xe4800034  swc1        $f0, 0x34($a0)
    ctx->pc = 0x190084u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 52), bits); }
    // 0x190088: 0xc4800038  lwc1        $f0, 0x38($a0)
    ctx->pc = 0x190088u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19008c: 0x460e0000  add.s       $f0, $f0, $f14
    ctx->pc = 0x19008cu;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[14]);
    // 0x190090: 0x3e00008  jr          $ra
    ctx->pc = 0x190090u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x190094u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x190090u;
            // 0x190094: 0xe4800038  swc1        $f0, 0x38($a0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 56), bits); }
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x190098u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
