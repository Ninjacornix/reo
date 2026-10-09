#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00198AD0
// Address: 0x198ad0 - 0x198af0
void sub_00198AD0_0x198ad0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00198AD0_0x198ad0");
#endif

    ctx->pc = 0x198ad0u;

    // 0x198ad0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x198ad0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x198ad4: 0xc420fd5c  lwc1        $f0, -0x2A4($at)
    ctx->pc = 0x198ad4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966620)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x198ad8: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x198ad8u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x198adc: 0x46006301  sub.s       $f12, $f12, $f0
    ctx->pc = 0x198adcu;
    ctx->f[12] = FPU_SUB_S(ctx->f[12], ctx->f[0]);
    // 0x198ae0: 0x3e00008  jr          $ra
    ctx->pc = 0x198AE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x198AE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198AE0u;
            // 0x198ae4: 0x46006006  mov.s       $f0, $f12 (Delay Slot)
        ctx->f[0] = FPU_MOV_S(ctx->f[12]);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x198AE8u;
    // 0x198ae8: 0x0  nop
    ctx->pc = 0x198ae8u;
    // NOP
    // 0x198aec: 0x0  nop
    ctx->pc = 0x198aecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
