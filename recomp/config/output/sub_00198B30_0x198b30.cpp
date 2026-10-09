#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00198B30
// Address: 0x198b30 - 0x198b60
void sub_00198B30_0x198b30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00198B30_0x198b30");
#endif

    ctx->pc = 0x198b30u;

    // 0x198b30: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x198b30u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x198b34: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x198b34u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x198b38: 0x44821000  mtc1        $v0, $f2
    ctx->pc = 0x198b38u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x198b3c: 0xc420f9f4  lwc1        $f0, -0x60C($at)
    ctx->pc = 0x198b3cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x198b40: 0x46026301  sub.s       $f12, $f12, $f2
    ctx->pc = 0x198b40u;
    ctx->f[12] = FPU_SUB_S(ctx->f[12], ctx->f[2]);
    // 0x198b44: 0x3c02bf00  lui         $v0, 0xBF00
    ctx->pc = 0x198b44u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)48896 << 16));
    // 0x198b48: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x198b48u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x198b4c: 0x0  nop
    ctx->pc = 0x198b4cu;
    // NOP
    // 0x198b50: 0x46016302  mul.s       $f12, $f12, $f1
    ctx->pc = 0x198b50u;
    ctx->f[12] = FPU_MUL_S(ctx->f[12], ctx->f[1]);
    // 0x198b54: 0x46006302  mul.s       $f12, $f12, $f0
    ctx->pc = 0x198b54u;
    ctx->f[12] = FPU_MUL_S(ctx->f[12], ctx->f[0]);
    // 0x198b58: 0x3e00008  jr          $ra
    ctx->pc = 0x198B58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x198B5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198B58u;
            // 0x198b5c: 0x46006006  mov.s       $f0, $f12 (Delay Slot)
        ctx->f[0] = FPU_MOV_S(ctx->f[12]);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x198B60u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
